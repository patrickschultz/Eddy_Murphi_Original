/* -*- C++ -*-
 * mu_epilog.inc
 * @(#) The driver for Murphi verifiers.
 *
 * Copyright (C) 1992 - 1999 by the Board of Trustees of
 * Leland Stanford Junior University.
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
 * Original Author: Ralph Melton
 * 
 * Update:
 *
 * C. Norris Ip
 * Subject: Breakdown into files
 * First modified : 14 Jan 93
 * Last modified : 23 March 93
 *
 * C. Norris Ip 
 * Subject: symmetry syntax
 * First version: Jan 14, 93 -- June 11, 93
 * Transfer to Liveness Version:
 * First modified: November 8, 93
 *
 * G. Della Penna
 * Subject: Integration of Cache and Disk algorithms
 * Final Version: January 10, 2003
 *
 * I. Melatti
 * Subject: Integration of probability based algorithm
 * Final Version: June 13, 2003
 *
 */

#ifndef DSTRB_ONLY

/****************************************
  header that depend on constants
  which is generated in the middle of the compiled program:
  RULES_IN_WORLD
  ****************************************/
#include "mu_util_dep.h"

/****************************************
  supporting routines
  ****************************************/
#ifdef HASHC
#if defined(PARALLEL)
#include "murphi.parallel/mu_hash.C"
#else
#include "mu_hash.C"
#endif
#endif

#if defined(PARALLEL)
#include "murphi.parallel/mu_util.C"
#else
#include "mu_util.C"
#endif

#if defined(CACHED_MURPHI)
#include "murphi.cache/mu_io.C"
#else
#if defined(PARALLEL)
#include "murphi.parallel/mu_io.C"
#else
#include "mu_io.C"
#endif
#endif

#include "mu_sym.C"

#if defined(CACHED_MURPHI)
#include "murphi.cache/mu_state.C"
#include "murphi.cache/mu_system.C"
#else
#if defined(PARALLEL)
#include "murphi.parallel/mu_state.C"
#include "murphi.parallel/mu_system.C"
#else
#include "mu_state.C"
#include "mu_system.C"
#endif
#endif

/****************************************
  main routines
  ****************************************/
#if defined(PARALLEL)
#include "murphi.parallel/mu_verifier.C"
#else
#include "mu_verifier.C"
#endif

/* IM<b> */
#if defined(PARALLEL)
#include "murphi.parallel/mu_mutexes.C"
#include "murphi.parallel/mu_parallel.C"
#include "murphi.parallel/mu_buffqueue.C"
#ifdef SPLITFILE
#include "murphi.parallel/splitFile.C"
#endif
#endif
/* IM<e> */

/****************************************
  Old Log:
  1) 3 Dec 93 Norris Ip: 
  add #include "mu_sym.C"
  2) 8 March 94 Norris Ip:
  merge with the latest rel2.6
****************************************/

/********************
  $Log: mu_epilog.inc,v $
  Revision 1.2  1999/01/29 07:49:10  uli
  bugfixes

  Revision 1.4  1996/08/07 18:54:33  ip
  last bug fix on NextRule/SetNextEnabledRule has a bug; fixed this turn

  Revision 1.3  1996/08/07 01:00:18  ip
  Fixed bug on what_rule setting during guard evaluation; otherwise, bad diagnoistic message on undefine error on guard

  Revision 1.2  1996/08/07 00:15:26  ip
  fixed while code generation bug

  Revision 1.1  1996/08/07 00:14:46  ip
  Initial revision

********************/

#else
/* Hemanth's code */
/****************************************
  header that depend on constants
  which is generated in the middle of the compiled program:
  RULES_IN_WORLD
  ****************************************/
#include "murphi.parallel.nothread/mu_util_dep.h"

/****************************************
  supporting routines
  ****************************************/
#ifdef HASHC
#include "murphi.parallel.nothread/mu_hash.C"
#endif
#include "murphi.parallel.nothread/mu_util.C"
#include "murphi.parallel.nothread/mu_io.C"
#include "murphi.parallel.nothread/mu_state.C"
#include "murphi.parallel.nothread/mu_par.C"
#include "murphi.parallel.nothread/mu_system.C"
#include "murphi.parallel.nothread/mu_sym.C"


/****************************************
  main routines
  ****************************************/
#include "murphi.parallel.nothread/mu_verifier.C"
#endif
