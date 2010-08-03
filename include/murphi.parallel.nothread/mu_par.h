/* -*- C++ -*-
 * mu_par.C
 * @(#) routines for parallel Murphi
 *
 * Copyright (C) 1992, 1993, 1994, 1995, 1996 by the Board of Trustees
 * of Leland Stanford Junior University.
 *
 * License to use, copy, modify, sell and/or distribute this software
 * and its documentation any purpose is hereby granted without royalty,
 * subject to the following terms and conditions:
 *
 * 1.  The above copyright notice and this permission notice must
 * appear in all copies of the software and related documentation.
 *
 * 2.  The name of Stanford University may not be used in advertising or
 * publicity pertaining to distribution of the software without the
 * specific, prior written permission of Stanford.
 *
 * 3.  This software may not be called "Murphi" if it has been modified
 * in any way, without the specific prior written permission of David L.
 * Dill.
 *
 * 4.  THE SOFTWARE IS PROVIDED "AS-IS" AND STANFORD MAKES NO
 * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, BY WAY OF EXAMPLE,
 * BUT NOT LIMITATION.  STANFORD MAKES NO REPRESENTATIONS OR WARRANTIES
 * OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE
 * USE OF THE SOFTWARE WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS
 * TRADEMARKS OR OTHER RIGHTS. STANFORD SHALL NOT BE LIABLE FOR ANY
 * LIABILITY OR DAMAGES WITH RESPECT TO ANY CLAIM BY LICENSEE OR ANY
 * THIRD PARTY ON ACCOUNT OF, OR ARISING FROM THE LICENSE, OR ANY
 * SUBLICENSE OR USE OF THE SOFTWARE OR ANY SERVICE OR SUPPORT.
 *
 * LICENSEE shall indemnify, hold harmless and defend STANFORD and its
 * trustees, officers, employees, students and agents against any and all
 * claims arising out of the exercise of any rights under this Agreement,
 * including, without limiting the generality of the foregoing, against
 * any damages, losses or liabilities whatsoever with respect to death or
 * injury to person or damage to property arising from or out of the
 * possession, use, or operation of Software or Licensed Program(s) by
 * LICENSEE or its customers.
 *
 * Read the file "license" distributed with these sources, or call
 * Murphi with the -l switch for additional information.
 *
 */

/* 
 * Original Author: Ulrich Stern
 * Created Date: 9 Nov 96
 *
 */ 

extern "C" {
}
#include "mpi.h"
#include <unistd.h>

#if 0
// ---------------------------------------------------------------------------
// Timer
// ---------------------------------------------------------------------------

// remark: this timer is not very accurate, but pretty portable

class Timer
{
  struct tms begin;
  struct tms end;
  double ticksPerSec;

public:
  Timer() {
    ticksPerSec = (double)(sysconf(_SC_CLK_TCK));
  };

  void reset()
  {
    times(&begin);
  };

  double sec()
  {
    times(&end);

    return ( ((double)end.tms_utime - begin.tms_utime) +
             ((double)end.tms_stime - begin.tms_stime) ) / ticksPerSec;
  };
};
#endif
 
// ---------------------------------------------------------------------------
// routines for parallel Murphi
// ---------------------------------------------------------------------------

// types

// remark: change NodeId type if you are running on more than 256 nodes
typedef unsigned char NodeId;

struct ReadBuffer {           // buffer for read in trace info file
  unsigned long predNumber;
  int           predNode;
  unsigned long c1;
  unsigned long c2;
};

// initialization and clean up
extern void ParallelInit(int *argc, char ***argv);
extern void ParallelTerminate(int exitCode);

// support routines
extern void IdleTimeStart();
extern bool IAmMaster();
extern int GetNumNodes();
extern int GetMyNode();

// common seed for random numbers
extern unsigned long CommonSeed(unsigned long seed);

// send and receive states
extern void SendState(state* s, bool valid);

// termination detection
extern int Terminated();

// error termination
extern void StartErrorTermination();
extern void EndErrorTermination(int exitCode);
extern void IfErrorTerminate();
extern void IfErrorTerminateNoSynchronize();

// remote read
extern ReadBuffer* RemoteRead(unsigned long number, NodeId node);

extern void SynchronizeMasterSlave();

// final summary functions
extern void PrintFinalResult_Heuristic1();
extern void PrintFinalResult_Heuristic2();

