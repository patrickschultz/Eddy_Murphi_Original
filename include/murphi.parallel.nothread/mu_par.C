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

/*
 * Modified for MPI: Hemanthkumar Sivaraj
 * Created Date: 3 Oct '01
 *
 */

// ---------------------------------------------------------------------------
// routines for parallel Murphi
// ---------------------------------------------------------------------------


// define tags for various message types

#define TAG_STATE	10	// refers to a message containing a state
#define TAG_REQUEST_CHECK_QUEUE 11	// request from master to check queue
				   // in Terminated()
#define TAG_REPLY_CHECK_QUEUE 12	// reply from slave to master for the above
				 // request

#define TAG_REQUEST_CONTINUE  13	// master requesting slaves to continue
				 // processing since termination was not reached

#define TAG_REQUEST_TERMINATE 14	// master requests slaves to terminate
#define TAG_REPLY_TERMINATE   15	// slave replied to master for above request

#define TAG_REQUEST_ERROR_TERM  16	// to find out the leader in the leader
#define TAG_REPLY_ERROR_TERM    17	// election algo

#define TAG_REQUEST_REPORT	18	// once error is found and the leader
				    // is chosen, the leader asks for report
#define TAG_REPLY_REPORT	19
#define TAG_REQUEST_END_ERROR_TERM  20
#define TAG_REQUEST_REMOTE_READ   21
#define TAG_REPLY_REMOTE_READ	22

// heuristic algo related tags
#define TAG_RANDOM_STATE_HEURISTIC1		23
#define TAG_ALL_STATES_SENT				24
#define TAG_SEND_FINAL_RESULT			25
#define TAG_TOTAL_UNIQUE_STATES			26
#define TAG_NUM_INITIAL_RW				27
#define	TAG_INITIAL_RW_STATE			28
#define TAG_FINAL_RW_INTERVAL			29
#define TAG_TOTAL_FINAL_RW_STEPS		30
#define TAG_RANDOM_STATE_HEURISTIC2		31
#define TAG_SEND_SLAVE_CONTINUE			32

void mesg_poll ();

// ---------------------------------------------------------------------------
// variables

enum
{ MASTER = 0 };
static int MyNode;		// virtual node number of myself
static int NumNodes;		// number of nodes
static volatile int NumSent;	// number of messages sent
static volatile int NumNetworkMessagesSent;
							// number of messages *actually* sent on the network
static volatile int NumReceived;	// number of messages received
static volatile bool StopSend;	// stop sending
// static Timer* IdleTimer = new Timer; // idle time 
static unsigned long Counter; /* counts how many calls to Terminated have taken
                                place since the last call to IdleTimeStarts */

static volatile int InHandlerFlag = FALSE;	// true when in am handler
static volatile int ErrorTermMin;	// for leader election in error termination

static volatile int terminated_done;	// for synchronization; incremented by
					// ReplyTerminate and RequestTerminate
					// and ReplyCheckQueue (?)
					// reset by Terminated
					// used by Terminated
static volatile int terminated_work;	// remaining work (in network or queues)
static volatile int StartErrorTermination_done = 0;

// we maintain a circular buffer of states for the Isend's

#define NO_OUTSTANDING_SENDS_PER_NODE	500
static state **statebuffer;
static int *head_of_buffer;
static MPI_Request **requests;	/* initially, all MPI_REQUEST_NULL, then can
                                  only be changed by the call to MPI_Issend */


static MPI_Status status;	// generic struct to get status, later on
			   // might have to have array of structs
static MPI_Request *dummy_requests;

static int errcode;
static char errbuffer[MPI_MAX_ERROR_STRING];
static int errbufflen;

// variables for heuristic1
static int num_response_recvd = 0;
static bool send_final_result = FALSE;
static unsigned long total_unique_states = 0UL;
static bool slave_continue = FALSE;

static void initFlowControl ();
static void endFlowControl ();

// ---------------------------------------------------------------------------
// initialization and clean up

/* FIRST CALLED FUNCTION */
void
ParallelInit (int *argc, char ***argv)
{
  int i;
  MPI_Init (argc, argv);

  MPI_Comm_rank (MPI_COMM_WORLD, &MyNode);	// get my virtual node number
  MPI_Comm_size (MPI_COMM_WORLD, &NumNodes);	// get total number of nodes

  ErrorTermMin = NumNodes;	// init has to be done before the first barrier

  if (sizeof (NodeId) == 1 && NumNodes > 256)
    Error.Notrace ("Internal: current NodeId type only allows 256 nodes.");

#ifdef DEBUG
  cout << "Node " << MyNode << " done calling MPI_Init()" << "\n";
  cout.flush ();
  MPI_Errhandler_set (MPI_COMM_WORLD, MPI_ERRORS_RETURN);
#endif

  initFlowControl ();

  dummy_requests = (MPI_Request *) malloc (NumNodes * sizeof (MPI_Request));
  if (!dummy_requests) {
    fprintf (stderr,
	     "Unable to allocate memory for dummy buffer or requests \n");
    MPI_Finalize ();

    exit (1);
  }

  for (i = 0; i < NumNodes; i++)
    dummy_requests[i] = MPI_REQUEST_NULL;

  MPI_Barrier (MPI_COMM_WORLD);

}

/* as stated in the comment at the bottom, this function (and the handling of
statebuffer, request and head_of_buffer) allows to bound to
NO_OUTSTANDING_SENDS_PER_NODE the number of not completed msgs between the
current node and the others */
static void
initFlowControl ()
{
  int i, j;
  statebuffer = new state *[NumNodes - 1];
  requests = new MPI_Request *[NumNodes - 1];
  head_of_buffer = new int[NumNodes - 1];

  if (!statebuffer || !requests || !head_of_buffer) {
    fprintf (stderr, "Unable to allocate memory for statebuffer, requests\n");
    MPI_Finalize ();
    exit (1);
  }

  for (i = 0; i < (NumNodes - 1); i++) {
    statebuffer[i] = new state[NO_OUTSTANDING_SENDS_PER_NODE];
    requests[i] = new MPI_Request[NO_OUTSTANDING_SENDS_PER_NODE];
    if (!statebuffer[i] || !requests[i]) {
      fprintf (stderr,
	       "Unable to allocate memory for statebuffer[i], requests[i]\n");
      MPI_Finalize ();
      exit (1);
    }
  }
  for (i = 0; i < (NumNodes - 1); i++) {
    for (j = 0; j < NO_OUTSTANDING_SENDS_PER_NODE; j++)
      requests[i][j] = MPI_REQUEST_NULL;
    head_of_buffer[i] = 0;
  }
  return;
}

static void
endFlowControl ()
{

  int i, j;
  for (i = 0; i < (NumNodes - 1); i++) {
    delete[]statebuffer[i];
    delete[]requests[i];
  }
  delete[]statebuffer;
  delete[]requests;
  delete[]head_of_buffer;

  return;
}

void
ParallelTerminate (int exitCode)
{
#ifdef DEBUG
  cout << MyNode << ": ParallelTerminate called.\n";
  cout.flush ();
#endif

  // some cleanup
  cout.flush ();
#ifdef HASHC
  if (TraceFile != NULL)
    delete TraceFile;

  if (StateSet != NULL)
    while (!StateSet->QueueIsEmpty ())
      delete StateSet->QueueDequeue ();

  if (BoundedStateSet != NULL)
    while (!BoundedStateSet->QueueIsEmpty ())
      delete BoundedStateSet->QueueDequeue ();

  if (rw_fronts != NULL) {
    for (int i = 0; i < size_rw_fronts; i++)
      if (rw_fronts[i] != NULL)
	delete rw_fronts[i];
    delete rw_fronts;
  }
  if (frontier_array != NULL)
    delete frontier_array;
#endif

  endFlowControl ();
  // free (dummy_buffer);
  free (dummy_requests);

  MPI_Finalize ();
  // exit code 1 or greater than 128 will cause abrupt termination
  // beware of this call, manual says that at most we can call return
  // after MPI_Finalize(). 
  exit (exitCode);
}


// ---------------------------------------------------------------------------
// support routines

// start idle time timer
void
IdleTimeStart ()
{
  Counter = 0;
  //IdleTimer->reset();
}

// check if master
bool
IAmMaster ()
{
  return (MyNode == MASTER);
}

// return total number of nodes
int
GetNumNodes ()
{
  return NumNodes;
}

// return my node number
int
GetMyNode ()
{
  return MyNode;
}


// ---------------------------------------------------------------------------
// common seed for random numbers

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// return common seed

unsigned long
CommonSeed (unsigned long seed)
{
  unsigned long returnSeed;

  // we lose some overlap of communication and computation here

  returnSeed = seed;
  MPI_Bcast (&returnSeed, 1, MPI_UNSIGNED_LONG, MASTER, MPI_COMM_WORLD);

#ifdef DEBUG
  cout << "Node " << MyNode << ": seed " << returnSeed << " selected.\n";
  cout.flush ();
#endif

  return returnSeed;
}



// ---------------------------------------------------------------------------
// send and receive states

void
StatePrint (state * s, char *p)
{
  cout << p << ": ";
  cout << setbase (16) << (s->hashkeys[0]) << " ";
  cout << setbase (16) << (s->hashkeys[1]) << " ";
  cout << setbase (16) << (s->hashkeys[2]) << ".\n";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// receive (message handler)

// remark: when returning from this handler, buffer p must have been copied

static void
Receive_bfs (state * p)
{
  InHandlerFlag = TRUE;		// needed since errors might occur in this handler

  //StatePrint(p, "received");
  NumReceived++;
  StateSet->Add (p);

  InHandlerFlag = FALSE;
}

static void
Receive_heuristic1 (state * p)
{
  InHandlerFlag = TRUE;

  NumReceived++;
  // if p is not present in the HT, then p (after being added to the HT)
  // now point to a new copy of the state, which we don't need
  if (!rw_ht->simple_was_present (p))
    delete p;

  InHandlerFlag = FALSE;
}

static void
Receive_heuristic2 (state * p)
{
  InHandlerFlag = TRUE;

  NumReceived++;
  StateSet->Add (p);
  // should we delete p if Add was successful thus denoting that p 
  // wasn't there in the hash table previously. In that case, does
  // p point to a new copy of the state?
  // Yes, but that copy is added to the queue within StateSet and hence
  // should not be deleted.
  InHandlerFlag = FALSE;
}

static void
ReceiveNumInitialRw (int num)
{
  num_random_walks = num;
  rw_fronts = new state *[num_random_walks];
  if (!rw_fronts) {
    cout << MyNode << ": Unable to allocate memory for rw fronts.\n";
    ParallelTerminate (1);
  }
  return;
}

static void
ReceiveInitialRwState (state * s)
{
  static int got = 0;
  copy_state (s);
  rw_fronts[got++] = s;
  if (got == num_random_walks)
    start_initial_rw = TRUE;
  // is there possibility of race contition/deadlock here?
  return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// send

enum
{ CACHE_SIZE = 1000 };

// send state to the "owning" node
void
SendState (state * s, bool valid)
{
  // might have to dynamically allocate oldK if we are going to have 
  // various kinds of send state functions
  static unsigned long oldK[CACHE_SIZE][3];
  static int sendCount = 0;
  static unsigned long *key;
  static int to, to_index;
  static int send_completed;

  static bool is_tag_set = FALSE;
  static int tag = -1;		// some undefined value

  // Important: s must be == workingstate
  // do the normalization first
  if (args->symmetry_reduction.value)
    s->Normalize ();
  if (args->multiset_reduction.value && !args->symmetry_reduction.value)
    s->MultisetSort ();

// StoreStateFile(s);

  // calculate hashkey and destination
  // if valid is TRUE, then curstate must point to a state whose hashkey
  // has been already computed, to be used in differential hashing
  key = h3->hash (s, valid);
  to = key[0] % NumNodes;


  // only send if not in key cache "oldK"
  int i = key[1] % CACHE_SIZE;
  if (key[0] != oldK[i][0]
      || key[1] != oldK[i][1]
      || key[2] != oldK[i][2]) {
    // copy the hashkey into state and set old key
    oldK[i][0] = key[0];
    oldK[i][1] = key[1];
    oldK[i][2] = key[2];

    // check if allowed to send
    while (StopSend)		/* implicitly initialized to FALSE (see paper) */
    /* as in the paper, it is true when the master suspects the computation to
    be over */
      mesg_poll ();

    NumSent++;

    // send the state including the hashkeys to "owner"
    if (to == MyNode) {
      /* the current node is the destination node, just execute function without
      sending anything */
      switch (args->main_alg.mode) {
      case argmain_alg::Heuristic1:
	Receive_heuristic1 (s);
	break;
      case argmain_alg::Heuristic2:
	Receive_heuristic2 (s);
	break;
      case argmain_alg::Heuristic3:
	Receive_heuristic2 (s);
	break;
      case argmain_alg::Heuristic4:
	Receive_heuristic2 (s);
	break;
      case argmain_alg::Verify_bfs:
	Receive_bfs (s);
	break;
      default:
	cout << "Wrong algorithm type\n";
	ParallelTerminate (1);
	break;
      }
    }
    else {
      NumNetworkMessagesSent++;
      /* computes to_index, which is used to point in local structures storing
      info about the other nodes - so it does not need to consider the node 
      itself */
      if (to > MyNode)
	to_index = to - 1;
      else
	to_index = to;

      /* should check if the last send operation has been correctly completed */
      while (1) {
	MPI_Test (&requests[to_index][head_of_buffer[to_index]],
		  &send_completed, &status);
	if (!send_completed)	// potential overflow problem
	{
	  // cout << "Node: " << MyNode << ": ";
	  // cout << "first send request still not completed\n";
	  // cout.flush();
	  mesg_poll ();
	}
	else
	  break;
      }

      StateCopy (&statebuffer[to_index][head_of_buffer[to_index]], s);

      // requests[head_of_buffer] was the earliest send request
      // started and hence we expect it to finish the earliest,
      // not necessary in general, but in fast networks mostly this 
      // will happen.
      // If the value of the request is MPI_REQUEST_NULL, it should 
      // return immediately, else it will wait for the send to get over.
      // check the status here.  

#ifdef DEBUG
      if (requests[to_index][head_of_buffer[to_index]] != MPI_REQUEST_NULL) {
	cout << "some problem with waiting for pending send. \n";
	cout.flush ();
      }
#endif

      // set the appropriate tag
      // we do this so that we set the tag to be used only once and then
      // for all subsequent calls only the outer check is needed.
      // The other case would be to do a switch on the algo type and determine
      // the tag to be used everytime this function is called, which would be
      // more expensive.
      // This depends on the fact that if SendState() is called the first time
      // for a particular algo, it will be called all subsequent times for the
      // same algo (and hence we use the same tag for sending the state)
      if (is_tag_set == FALSE) {
	if (args->main_alg.mode == argmain_alg::Heuristic1) {
	  is_tag_set = TRUE;
	  tag = TAG_RANDOM_STATE_HEURISTIC1;
	}
	if (args->main_alg.mode == argmain_alg::Heuristic2) {
	  is_tag_set = TRUE;
	  tag = TAG_RANDOM_STATE_HEURISTIC2;
	}
	if (args->main_alg.mode == argmain_alg::Heuristic3) {
	  is_tag_set = TRUE;
	  tag = TAG_RANDOM_STATE_HEURISTIC2;
	}
	if (args->main_alg.mode == argmain_alg::Heuristic4) {
	  is_tag_set = TRUE;
	  tag = TAG_RANDOM_STATE_HEURISTIC2;
	}
	else if (args->main_alg.mode == argmain_alg::Verify_bfs) {
	  is_tag_set = TRUE;
	  tag = TAG_STATE;
	}
      }

      /* nonblocking synchronous (!) send; as stated at the end of this file,
      using MPI_Issend is needed to have MPI_Test return true iff the
      destination node has effectively received the message. This is payed with
      some inefficiency (http://www.pdc.kth.se/~pek/benchmarks/skampi-lxl-8/node113.html) */
      //now use the tag that was assigned in the previous step to send the state.
      errcode = MPI_Issend ((char
			     *) (&statebuffer[to_index][head_of_buffer
							[to_index]]),
			    sizeof (state), MPI_CHAR, to, tag, MPI_COMM_WORLD,
			    &requests[to_index][head_of_buffer[to_index]]);
      if (errcode != MPI_SUCCESS) {
	MPI_Error_string (errcode, errbuffer, &errbufflen);
	puts (errbuffer);
	MPI_Abort (MPI_COMM_WORLD, errcode);
      }
      head_of_buffer[to_index] = (head_of_buffer[to_index] + 1) %
	NO_OUTSTANDING_SENDS_PER_NODE;

    }				// end else (state is for someone else)

  }				// end if (state was not in cache)
  mesg_poll (); /* useless when called from AllStartStates, at least for
                 the first call */
}


// ---------------------------------------------------------------------------
// termination detection

// handle replies from slaves
static void
ReplyTerminate (unsigned long s, unsigned long t)
{
  terminated_done++;
  StateSet->AddNumElts (s);
  Rules->AddNumRulesFired (t);
}

// slave reacts to termination request
/* response to TAG_REQUEST_TERMINATE */
static void
RequestTerminate (int src)
{
  static unsigned long a[2];

  terminated_done++;		// so that the main loop will know that we have reached
  // termination
  a[0] = StateSet->NumElts ();
  a[1] = Rules->NumRulesFired ();

  MPI_Send (a, 2, MPI_UNSIGNED_LONG, src, TAG_REPLY_TERMINATE,
	    MPI_COMM_WORLD);
  mesg_poll ();
}

// handle replies from slaves
static void
ReplyCheckQueue (int work)
{
  terminated_done++;
  terminated_work += work;
}

// slave reacts to check queue request
/* response to TAG_REQUEST_CHECK_QUEUE */
static void
RequestCheckQueue (int src)
{
  int work;
  static MPI_Request dummy_request;

  StopSend = TRUE;		// disallow sending newly generated states
  work = int (NumSent - NumReceived + (StateSet->QueueIsEmpty ()? 0 : 1));
  MPI_Isend (&work, 1, MPI_INT, src, TAG_REPLY_CHECK_QUEUE, MPI_COMM_WORLD,
	     &dummy_request);
  mesg_poll ();
}

// slave reacts to continue request
static void
RequestContinue ()
{				/* eventually called only in mesg_poll */
  StopSend = FALSE;		// allow sending newly generated states again
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// check termination

/* A slave calling this simply polls messages and increments counter */
int
Terminated ()
{
  // poll network
  mesg_poll ();

  Counter++;

  // master initiates termination detection
  if (MyNode == MASTER) {
    if (!StateSet->QueueIsEmpty ()) {
      IdleTimeStart ();
    }
    else if (Counter > 50000)
      // IdleTimer->sec() > .1)   // nothing received for .1s
    {
      // send check queue message to all slaves
      for (int i = 0; i < NumNodes; i++) {
	if (i != MASTER)
	  MPI_Isend (MPI_BOTTOM, 0, MPI_INT, i, TAG_REQUEST_CHECK_QUEUE,
		     MPI_COMM_WORLD, &dummy_requests[i]);
	mesg_poll ();
      }
      // wait for replies
      while (terminated_done < NumNodes - 1)
	mesg_poll ();

      terminated_work +=
	int (NumSent - NumReceived + (StateSet->QueueIsEmpty ()? 0 : 1));

      // check if there is work left
      if (terminated_work > 0) {
#ifdef DEBUG
	cout << "\nSending continue message\n";
	cout.flush ();
#endif

	for (int i = 0; i < NumNodes; i++) {
	  if (i != MASTER)
	    MPI_Isend (MPI_BOTTOM, 0, MPI_INT, i, TAG_REQUEST_CONTINUE,
		       MPI_COMM_WORLD, &dummy_requests[i]);
	  mesg_poll ();
	}

	terminated_done = terminated_work = 0;
	IdleTimeStart ();
      }
      else {
#ifdef DEBUG
	cout << "\nSending terminate message\n";
	cout.flush ();
#endif

	// send terminate message to all slaves
	terminated_done = 1;
	for (int i = 0; i < NumNodes; i++) {
	  if (i != MASTER)
	    MPI_Isend (MPI_BOTTOM, 0, MPI_INT, i, TAG_REQUEST_TERMINATE,
		       MPI_COMM_WORLD, &dummy_requests[i]);
	  mesg_poll ();
	}

	// wait for all responses,
	// they also increment the state and transition counters
	while (terminated_done < NumNodes)
	  mesg_poll ();
      }
    }
  }				// check timer and maybe finish program

  return terminated_done;
  // This will either return 0 or NumNodes that corresponds to non-termination
  // or termination, respectively.
}


// ---------------------------------------------------------------------------
// error termination

static volatile int ErrorTermFlag = FALSE;	// true during error termination


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// messages handlers

// handle replies from non-error nodes
static void
ReplyErrorTerm ()
{
  StartErrorTermination_done++;
}

// non-error nodes react to error termination request
static void
RequestErrorTerm (int src)
{
  static MPI_Request dummy_request;

  ErrorTermFlag = TRUE;
  if (src < ErrorTermMin)
    ErrorTermMin = src;

  MPI_Isend (MPI_BOTTOM, 0, MPI_INT, src, TAG_REPLY_ERROR_TERM,
	     MPI_COMM_WORLD, &dummy_request);
  mesg_poll ();
}

// end of error termination in non-error nodes
static void
RequestEndErrorTerm ()
{
  ErrorTermFlag = FALSE;
}

// gather the reports from non-error nodes
static void
ReplyReport (unsigned long s, unsigned long t, unsigned long nummesgsent)
{
  StartErrorTermination_done++;
  if (args->main_alg.mode == argmain_alg::Heuristic1) {
    if (rw_ht != NULL) {
      rw_ht->AddNumElts (s);
    }
    Rules->AddNumRulesFired (t);
  }
  else if (StateSet != NULL) {
    StateSet->AddNumElts (s);
    Rules->AddNumRulesFired (t);
  }
  TotalNetworkMessagesExchanged += nummesgsent;
}

// non-error nodes react to report request
static void
RequestReport (int src)
{
  static unsigned long a[3];
  static MPI_Request dummy_request;

  if (args->main_alg.mode == argmain_alg::Heuristic1) {
    if (rw_ht != NULL) {
      a[0] = rw_ht->NumElts ();
    }
    a[1] = Rules->NumRulesFired ();
  }
  else if (StateSet != NULL) {
    a[0] = StateSet->NumElts ();
    a[1] = Rules->NumRulesFired ();
  }
  else {
    a[0] = a[1] = 0;
  }
  a[2] = NumNetworkMessagesSent;
  MPI_Isend (a, 3, MPI_UNSIGNED_LONG, src, TAG_REPLY_REPORT,
	     MPI_COMM_WORLD, &dummy_request);

  mesg_poll ();
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// start error termination

void
StartErrorTermination ()
{
  static bool firstCall = TRUE;

  if (firstCall && !InHandlerFlag)	// might be called more than once
  {				// and from within am handler
    firstCall = FALSE;

    //TraceFile->print(MyNode);

    // send request error termination message to all other nodes
    for (int i = 0; i < NumNodes; i++)
      if (i != MyNode) {
	MPI_Isend (MPI_BOTTOM, 0, MPI_INT, i, TAG_REQUEST_ERROR_TERM,
		   MPI_COMM_WORLD, &dummy_requests[i]);
	mesg_poll ();
      }

    while (StartErrorTermination_done < NumNodes - 1)
      mesg_poll ();

    // after this barrier, minimum is found
    // MPI_Barrier(MPI_COMM_WORLD);
    SynchronizeMasterSlave ();

    if (ErrorTermMin < MyNode) {
      // somebody else has also found an error and is in charge

      // wait for error termination to finish
      while (ErrorTermFlag)
	mesg_poll ();

      ParallelTerminate (2);
    }
    else {
      // I am in charge of the error

      // get the number of explored states
      StartErrorTermination_done = 0;
      for (int i = 0; i < NumNodes; i++)
	if (i != MyNode) {
	  MPI_Isend (MPI_BOTTOM, 0, MPI_INT, i, TAG_REQUEST_REPORT,
		     MPI_COMM_WORLD, &dummy_requests[i]);
	  mesg_poll ();
	}

      while (StartErrorTermination_done < NumNodes - 1)
	mesg_poll ();
      TotalNetworkMessagesExchanged += NumNetworkMessagesSent;

#ifdef DEBUG
      cout << "node " << MyNode << ": in charge of error\n";
      cout.flush ();
#endif
    }
  }
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// end error termination

void
EndErrorTermination (int exitCode)
{
  if (InHandlerFlag)		// call from within am handler
  {
    ParallelTerminate (1);	// exit-code 1 causes all processes to terminate
    //  immediately
  }
  else {
    // send request end error termination message to all other nodes
    for (int i = 0; i < NumNodes; i++)
      if (i != MyNode) {
	MPI_Isend (MPI_BOTTOM, 0, MPI_INT, i, TAG_REQUEST_END_ERROR_TERM,
		   MPI_COMM_WORLD, &dummy_requests[i]);
	mesg_poll ();
      }

#ifdef DEBUG
    cout << "node " << MyNode << ": ended error term\n";
    cout.flush ();
#endif

    ParallelTerminate (exitCode);
  }
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// check error termination

void
IfErrorTerminate ()
{
  // static bool firstcall = TRUE;
  if (ErrorTermFlag) {
    /*
       // This is needed since IfErrorTerminate() is also called from
       // within SynchronizeMasterSlave(). Without this, we could have
       // an infinite loop of calls.
       if (!firstcall)
       return;
       firstcall = FALSE;
     */

    //TraceFile->print(MyNode);

    // this barrier is "initiated" in StartErrorTermination()
    // MPI_Barrier(MPI_COMM_WORLD);
    SynchronizeMasterSlave ();

#ifdef DEBUG
    cout << "node " << MyNode << ": waiting for error term to finish\n";
    cout.flush ();
#endif

    // wait for error termination to finish
    while (ErrorTermFlag)
      mesg_poll ();

#ifdef DEBUG
    cout << "node " << MyNode << ": error term finished\n";
    cout.flush ();
#endif

    ParallelTerminate (2);
  }
}

void
IfErrorTerminateNoSynchronize ()
{
  // static bool firstcall = TRUE;
  if (ErrorTermFlag) {
    /*
       // This is needed since IfErrorTerminate() is also called from
       // within SynchronizeMasterSlave(). Without this, we could have
       // an infinite loop of calls.
       if (!firstcall)
       return;
       firstcall = FALSE;
     */

    //TraceFile->print(MyNode);

#ifdef DEBUG
    cout << "node " << MyNode << ": waiting for error term to finish\n";
    cout.flush ();
#endif

    // wait for error termination to finish
    while (ErrorTermFlag)
      mesg_poll ();

#ifdef DEBUG
    cout << "node " << MyNode << ": error term finished\n";
    cout.flush ();
#endif

    ParallelTerminate (2);
  }
}

// ---------------------------------------------------------------------------
// remote read

static volatile ReadBuffer RdBuffer;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// messages handlers

// buffer received data
static void
ReplyRemoteRead (int src, unsigned long number, int node,
		 unsigned long c1, unsigned long c2)
{
//  cout << "node " << MyNode << ": received data from node " << src 
//       << ".\n"; cout.flush();

  RdBuffer.predNumber = number;
  RdBuffer.predNode = node;
  RdBuffer.c1 = c1;
  RdBuffer.c2 = c2;
}

// serve remote read request
static void
RequestRemoteRead (int src, unsigned long number)
{
  ReadBuffer *bp;

//  cout << "node " << MyNode << ": serving read request for no. " << number
//       << ".\n"; cout.flush();

  bp = TraceFile->readLocal (number);

//  cout << "c1,c2: " << setbase(16) << (bp->c1) << "," << setbase(16) << (bp->c2) << "\n";
//  cout.flush();

  MPI_Send ((char *) bp, sizeof (ReadBuffer), MPI_CHAR, src,
	    TAG_REPLY_REMOTE_READ, MPI_COMM_WORLD);
  mesg_poll ();
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// remote read

ReadBuffer *
RemoteRead (unsigned long number, NodeId node)
{
  RdBuffer.predNode = -2;	// to check for message arrival

  MPI_Send (&number, 1, MPI_UNSIGNED_LONG, node,
	    TAG_REQUEST_REMOTE_READ, MPI_COMM_WORLD);
  mesg_poll ();

  while (RdBuffer.predNode == -2)
    mesg_poll ();

  return (ReadBuffer *) & RdBuffer;
}

// This function synchronizes the master and the slaves. At the end of this 
// function, all messages sent would have been received.

void
SynchronizeMasterSlave ()
{
  int i, j;
  int send_completed;
  MPI_Request dummy_request;

  /*
     if (!args->send_rw.value)
     return;
     // In this case, we synchronize to receive the error termination message
   */

  /* num_response_recvd = 0; */

  // Shouldn't do the above here, leads to a deadlock situation.
  // Slave might finish its processing heuristic_i main code, then come into
  // this function, and send "sent all states" message upon which 
  // num_response_recvd will be incremented at the Master. Master might still 
  // be doing its heuristic_i main code, then when the master enters this
  // function, the above statement will reset num_response_recvd back to 0,
  // thus losing count of the messages received from slaves till then. This
  // leads to a deadlock. Master waiting till it gets (NumNodes-1) messages
  // which will never happen, and slave waiting for a "send final result"
  // message from Master which won't happen.

  // first check to see that all messages sent by you have been received
  // while still receiving incoming messages
  i = 0;
  j = 0;
  while (1) {
    mesg_poll ();
    // IfErrorTerminate();
    for (; i < (NumNodes - 1); i++, j = 0) {
      for (; j < NO_OUTSTANDING_SENDS_PER_NODE; j++) {
	MPI_Test (&requests[i][j], &send_completed, &status);
	if (!send_completed)	// this mesg not yet recvd
	  break;		// out of inner for loop
      }
      if (j < NO_OUTSTANDING_SENDS_PER_NODE)
	break;			// out of the outer for loop to do a mesg poll
    }
    if (i == (NumNodes - 1))	// we are done
      break;			// out of the while loop
  }
  // now all sent states of this proc have been received


  if (IAmMaster ()) {
    // Master might still have to receive some states from other nodes
    while (num_response_recvd < (NumNodes - 1)) {
      mesg_poll ();
      // IfErrorTerminate();
    }
    // Now all states have been received
#ifdef DEBUG
    cout << MyNode << ": No. messages sent = " << NumSent << endl;
    cout << MyNode << ": No. of actual n/w messages sent = "
      << NumNetworkMessagesSent << endl;
    cout << MyNode << ": No. messages recvd = " << NumReceived << endl;
#endif
#ifdef DEBUG
    cout << MyNode << ": Got \"all states sent\" from " << (NumNodes - 1)
      << " other nodes\n";
    cout.flush ();
#endif

    num_response_recvd = 0;

    for (int k = 0; k < NumNodes; k++) {
      if (k != MASTER) {
	// the slaves are waiting in a buzy loop, so synch send is ok
	MPI_Send (MPI_BOTTOM, 0, MPI_INT, k, TAG_SEND_SLAVE_CONTINUE,
		  MPI_COMM_WORLD);
      }
    }
#ifdef DEBUG
    cout << MyNode << ": Sent \"slave continue\" to slaves\n";
    cout.flush ();
#endif
  }
  else				// slave part
  {
    // slave might still have to receive some states from others, so
    // use a non-blocking send to master.
    // then send done to master     
    MPI_Isend (MPI_BOTTOM, 0, MPI_INT, MASTER, TAG_ALL_STATES_SENT,
	       MPI_COMM_WORLD, &dummy_request);
#ifdef DEBUG
    cout << MyNode << ": Slave sent \"all states sent\" mesg\n";
    cout.flush ();
#endif

    while (!slave_continue) {
      mesg_poll ();
      // IfErrorTerminate();
    }
    slave_continue = FALSE;
    // now slave might have received the final set of states from others
#ifdef DEBUG
    cout << MyNode << ": No. messages sent = " << NumSent << endl;
    cout << MyNode << ": No. of actual n/w messages sent = "
      << NumNetworkMessagesSent << endl;
    cout << MyNode << ": No. messages recvd = " << NumReceived << endl;
#endif
  }
  // now there are no messages in transit, all messages sent have been
  // received.
  return;
}

// Printing Final results

void
PrintFinalResult_Heuristic1 ()
{
  SynchronizeMasterSlave ();
  // IfErrorTerminate();
  IfErrorTerminateNoSynchronize ();

  if (!args->send_rw.value) {
    if (IAmMaster ()) {
      cout << "\nNumber of processors: " << NumNodes;
      cout << "\nNumber of rules fired per processor: "
	<< args->total_initial_rw_steps.value;
      cout << "\nSince no state generated by the RWs was sent over to the \
				owning processors, we can't give the unique states \
				statistic\n";
    }
    return;
  }

  if (IAmMaster ()) {
    for (int k = 0; k < NumNodes; k++) {
      if (k != MASTER) {
	// the slaves are waiting in a buzy loop, so synch send is ok
	MPI_Send (MPI_BOTTOM, 0, MPI_INT, k, TAG_SEND_FINAL_RESULT,
		  MPI_COMM_WORLD);
      }
    }

#ifdef DEBUG
    cout << MyNode << ": Sent \"send final result\" to slaves\n";
    cout.flush ();
#endif

    // now get final results
    while (num_response_recvd < (NumNodes - 1))
      mesg_poll ();
    // final results obtained from all slaves
    // add master's ht size
    total_unique_states += rw_ht->NumElts ();

    // master prints out results    
    cout << "\nNumber of processors: " << NumNodes;
    cout << "\nNumber of rules fired per processor: "
      << args->total_initial_rw_steps.value;
    cout << "\nInterval of RW states sent: " << args->send_rw_interval.value;
    if (args->send_rw_interval.value != 1)
      cout << "\nSince every RW state was not sent to its owning \
					processor, the total unique states information would not \
					be accurate";
    cout << "\nTotal number of unique states visited: "
      << total_unique_states << "\n";
  }
  else				// slave part
  {
    unsigned long unique_states_visited;
    while (!send_final_result)
      mesg_poll ();
    // Master must be waiting in a buzy loop to get this
    unique_states_visited = rw_ht->NumElts ();
    MPI_Send (&unique_states_visited, 1, MPI_UNSIGNED_LONG, MASTER,
	      TAG_TOTAL_UNIQUE_STATES, MPI_COMM_WORLD);
#ifdef DEBUG
    cout << MyNode << ": Sent final result to master\n";
    cout.flush ();
#endif
  }
  return;
}

#if 0
void
PrintFinalResult_Heuristic2 ()
{
  int i, j;
  int send_completed;
  MPI_Status status;
  MPI_Request dummy_request;

  if (!args->send_rw.value) {
    if (IAmMaster ()) {
      cout << "\nNumber of processors: " << NumNodes;
      cout << "\nNumber of rules fired per processor: "
	<< args->total_initial_rw_steps.value;
      cout << "\nSince no state generated by the RWs was sent over to the \
				owning processors, we can't give the unique states \
				statistic\n";
    }
    return;
  }

  // first check to see that all messages sent by you have been received
  // while still receiving incoming messages
  i = 0;
  j = 0;
  while (1) {
    mesg_poll ();
    for (; i < (NumNodes - 1); i++, j = 0) {
      for (; j < NO_OUTSTANDING_SENDS_PER_NODE; j++) {
	MPI_Test (&requests[i][j], &send_completed, &status);
	if (!send_completed)	// this mesg not yet recvd
	  break;		// out of inner for loop
      }
      if (j < NO_OUTSTANDING_SENDS_PER_NODE)
	break;			// out of the outer for loop to do a mesg poll
    }
    if (i == (NumNodes - 1))	// we are done
      break;			// out of the while loop
  }
  // now all sent states of this proc have been received

#ifdef DEBUG
  cout << MyNode << ": No. messages recvd = " << NumReceived << endl;
  cout << MyNode << ": No. messages sent = " << NumSent << endl;
  cout.flush ();
#endif

  if (IAmMaster ()) {
    // Master might still have to receive some states from other nodes
    while (num_response_recvd < (NumNodes - 1))
      mesg_poll ();
    // Now all states have been received
#ifdef DEBUG
    cout << MyNode << ": Final No. messages recvd = " << NumReceived << endl;
#endif
#ifdef DEBUG
    cout << MyNode << ": Got \"all states sent\" from " << (NumNodes - 1)
      << " other nodes\n";
    cout.flush ();
#endif

    num_response_recvd = 0;

    for (int k = 0; k < NumNodes; k++) {
      if (k != MASTER) {
	// the slaves are waiting in a buzy loop, so synch send is ok
	MPI_Send (MPI_BOTTOM, 0, MPI_INT, k, TAG_SEND_FINAL_RESULT,
		  MPI_COMM_WORLD);
      }
    }

#ifdef DEBUG
    cout << MyNode << ": Sent \"send final result\" to slaves\n";
    cout.flush ();
#endif

    // now get final results
    while (num_response_recvd < (NumNodes - 1))
      mesg_poll ();
    // final results obtained from all slaves
    // add master's ht size
    total_unique_states += StateSet->NumElts ();

    // master prints out results    
    cout << "\nNumber of processors: " << NumNodes;
    cout << "\nNumber of rules fired per processor: "
      << args->total_initial_rw_steps.value;
    cout << "\nInterval of RW states sent: " << args->send_rw_interval.value;
    if (args->send_rw_interval.value != 1)
      cout << "\nSince every RW state was not sent to its owning \
					processor, the total unique states information would not \
					be accurate";
    cout << "\nTotal number of unique states visited: "
      << total_unique_states << "\n";
  }
  else				// slave part
  {
    unsigned long unique_states_visited;
    // slave might still have to receive some states from others, so
    // use a non-blocking send to master.
    // then send done to master     
    MPI_Isend (MPI_BOTTOM, 0, MPI_INT, MASTER, TAG_ALL_STATES_SENT,
	       MPI_COMM_WORLD, &dummy_request);
#ifdef DEBUG
    cout << MyNode << ": Slave sent \"all states sent\" mesg\n";
    cout.flush ();
#endif

    while (!send_final_result)
      mesg_poll ();
    // now slave might have received the final set of states from others
#ifdef DEBUG
    cout << MyNode << ": Final No. messages recvd = " << NumReceived << endl;
#endif
    // Master must be waiting in a buzy loop to get this
    unique_states_visited = StateSet->NumElts ();
    MPI_Send (&unique_states_visited, 1, MPI_UNSIGNED_LONG, MASTER,
	      TAG_TOTAL_UNIQUE_STATES, MPI_COMM_WORLD);
#ifdef DEBUG
    cout << MyNode << ": Send final result to master\n";
    cout.flush ();
#endif
  }
  return;
}
#endif

void
PrintFinalResult_Heuristic2 ()
{
  SynchronizeMasterSlave ();
  // IfErrorTerminate();
  IfErrorTerminateNoSynchronize ();

  if (!args->send_rw.value) {
    if (IAmMaster ()) {
      cout << "\nNumber of processors: " << NumNodes;
      cout << "\nNumber of rules fired per processor: "
	<< args->total_initial_rw_steps.value;
      cout << "\nSince no state generated by the RWs was sent over to the \
				owning processors, we can't give the unique states \
				statistic\n";
    }
    return;
  }

  if (IAmMaster ()) {
    for (int k = 0; k < NumNodes; k++) {
      if (k != MASTER) {
	// the slaves are waiting in a buzy loop, so synch send is ok
	MPI_Send (MPI_BOTTOM, 0, MPI_INT, k, TAG_SEND_FINAL_RESULT,
		  MPI_COMM_WORLD);
      }
    }

#ifdef DEBUG
    cout << MyNode << ": Sent \"send final result\" to slaves\n";
    cout.flush ();
#endif

    // now get final results
    while (num_response_recvd < (NumNodes - 1))
      mesg_poll ();
    // final results obtained from all slaves
    // add master's ht size
    total_unique_states += StateSet->NumElts ();

    // master prints out results    
    cout << "\nNumber of processors: " << NumNodes;
    cout << "\nNumber of rules fired per processor: "
      << args->total_initial_rw_steps.value;
    cout << "\nInterval of RW states sent: " << args->send_rw_interval.value;
    if (args->send_rw_interval.value != 1)
      cout << "\nSince every RW state was not sent to its owning "
	"processor, the total unique states information would not "
	"be accurate";
    cout << "\nTotal number of unique states visited: "
      << total_unique_states << "\n";
  }
  else				// slave part
  {
    unsigned long unique_states_visited;

    while (!send_final_result)
      mesg_poll ();
    // Master must be waiting in a buzy loop to get this
    unique_states_visited = StateSet->NumElts ();
    MPI_Send (&unique_states_visited, 1, MPI_UNSIGNED_LONG, MASTER,
	      TAG_TOTAL_UNIQUE_STATES, MPI_COMM_WORLD);
#ifdef DEBUG
    cout << MyNode << ": Sent final result to master\n";
    cout.flush ();
#endif
  }
  return;
}

void
mesg_poll ()
{
  static MPI_Status status;
  static int source;
  static int tag;
  static int flag;
  static state s;
  static int work;
  static unsigned long number;
  static unsigned long a[2];
  static ReadBuffer b;
  static int nextnode = MyNode;
  int i;
  static int temp_int;

  MPI_Iprobe (MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &flag, &status);

  if (IAmMaster ()) {
    while (flag) {
      source = status.MPI_SOURCE;
      //  source = nextnode;
      tag = status.MPI_TAG;
      switch (tag) {
      case TAG_RANDOM_STATE_HEURISTIC1:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR,
		  source, TAG_RANDOM_STATE_HEURISTIC1, MPI_COMM_WORLD,
		  &status);
	Receive_heuristic1 (&s);
	break;
      case TAG_RANDOM_STATE_HEURISTIC2:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR,
		  source, TAG_RANDOM_STATE_HEURISTIC2, MPI_COMM_WORLD,
		  &status);
	Receive_heuristic2 (&s);
	break;
      case TAG_ALL_STATES_SENT:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source, TAG_ALL_STATES_SENT,
		  MPI_COMM_WORLD, &status);
	num_response_recvd++;
	break;
      case TAG_TOTAL_UNIQUE_STATES:
	MPI_Recv (&number, 1, MPI_UNSIGNED_LONG, source,
		  TAG_TOTAL_UNIQUE_STATES, MPI_COMM_WORLD, &status);
	total_unique_states += number;
	num_response_recvd++;
	break;
      case TAG_STATE:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR,
		  source, TAG_STATE, MPI_COMM_WORLD, &status);
	Receive_bfs (&s);
	break;
      case TAG_REPLY_CHECK_QUEUE:
	MPI_Recv (&work, 1, MPI_INT, source,
		  TAG_REPLY_CHECK_QUEUE, MPI_COMM_WORLD, &status);
	ReplyCheckQueue (work);
	break;
      case TAG_REPLY_TERMINATE:
	MPI_Recv (a, 2, MPI_UNSIGNED_LONG, source,
		  TAG_REPLY_TERMINATE, MPI_COMM_WORLD, &status);
	ReplyTerminate (a[0], a[1]);
	break;
      case TAG_REQUEST_ERROR_TERM:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_ERROR_TERM, MPI_COMM_WORLD, &status);
	RequestErrorTerm (source);
	break;
      case TAG_REPLY_ERROR_TERM:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REPLY_ERROR_TERM, MPI_COMM_WORLD, &status);
	ReplyErrorTerm ();
	break;
      case TAG_REQUEST_REPORT:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_REPORT, MPI_COMM_WORLD, &status);
	RequestReport (source);
	break;
      case TAG_REPLY_REPORT:
	MPI_Recv (a, 3, MPI_UNSIGNED_LONG, source,
		  TAG_REPLY_REPORT, MPI_COMM_WORLD, &status);
	ReplyReport (a[0], a[1], a[2]);
	break;
      case TAG_REQUEST_END_ERROR_TERM:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_END_ERROR_TERM, MPI_COMM_WORLD, &status);
	RequestEndErrorTerm ();
	break;
      case TAG_REQUEST_REMOTE_READ:
	MPI_Recv (&number, 1, MPI_UNSIGNED_LONG, source,
		  TAG_REQUEST_REMOTE_READ, MPI_COMM_WORLD, &status);
	RequestRemoteRead (source, number);
	break;
      case TAG_REPLY_REMOTE_READ:
	MPI_Recv ((char *) &b, sizeof (ReadBuffer), MPI_CHAR, source,
		  TAG_REPLY_REMOTE_READ, MPI_COMM_WORLD, &status);
	ReplyRemoteRead (source, b.predNumber, b.predNode, b.c1, b.c2);
	break;

      default:
	cout << "Unrecognized message type"; cout.flush();
	int tmptmptmp = 1;
	while (tmptmptmp);
	Error.Notrace ("Unrecognized message type");
      }

      MPI_Iprobe (MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,
		  &flag, &status);
    }				// end while

  }
  else				// I am not master
  {

    while (flag) {
      source = status.MPI_SOURCE;
      //  source = nextnode;
      tag = status.MPI_TAG;
      switch (tag) {
      case TAG_RANDOM_STATE_HEURISTIC1:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR,
		  source, TAG_RANDOM_STATE_HEURISTIC1, MPI_COMM_WORLD,
		  &status);
	Receive_heuristic1 (&s);
	break;
      case TAG_RANDOM_STATE_HEURISTIC2:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR,
		  source, TAG_RANDOM_STATE_HEURISTIC2, MPI_COMM_WORLD,
		  &status);
	Receive_heuristic2 (&s);
	break;
      case TAG_SEND_FINAL_RESULT:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source, TAG_SEND_FINAL_RESULT,
		  MPI_COMM_WORLD, &status);
	send_final_result = TRUE;
	break;
      case TAG_SEND_SLAVE_CONTINUE:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source, TAG_SEND_SLAVE_CONTINUE,
		  MPI_COMM_WORLD, &status);
	slave_continue = TRUE;
	break;
      case TAG_NUM_INITIAL_RW:
	MPI_Recv (&temp_int, 1, MPI_INT, source, TAG_NUM_INITIAL_RW,
		  MPI_COMM_WORLD, &status);
	ReceiveNumInitialRw (temp_int);
	break;
      case TAG_INITIAL_RW_STATE:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR, source,
		  TAG_INITIAL_RW_STATE, MPI_COMM_WORLD, &status);
	ReceiveInitialRwState (&s);
	break;
      case TAG_FINAL_RW_INTERVAL:
	MPI_Recv (&temp_int, 1, MPI_INT, source, TAG_FINAL_RW_INTERVAL,
		  MPI_COMM_WORLD, &status);
	final_rw_interval = temp_int;
	// num_final_random_walks = StateSet->QueueNumElts()/
	//                                                              final_rw_interval;
	break;
      case TAG_TOTAL_FINAL_RW_STEPS:
	MPI_Recv (&temp_int, 1, MPI_INT, source, TAG_TOTAL_FINAL_RW_STEPS,
		  MPI_COMM_WORLD, &status);
	total_final_rw_steps = temp_int;
	start_final_rw = true;
	break;
      case TAG_STATE:
	MPI_Recv ((char *) &s, sizeof (state), MPI_CHAR,
		  source, TAG_STATE, MPI_COMM_WORLD, &status);
	Receive_bfs (&s);
	break;
      case TAG_REQUEST_CHECK_QUEUE:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_CHECK_QUEUE, MPI_COMM_WORLD, &status);
	RequestCheckQueue (source);
	break;
      case TAG_REQUEST_CONTINUE:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_CONTINUE, MPI_COMM_WORLD, &status);
	RequestContinue ();
	break;
      case TAG_REQUEST_TERMINATE:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_TERMINATE, MPI_COMM_WORLD, &status);
	RequestTerminate (source);
	break;
      case TAG_REQUEST_ERROR_TERM:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_ERROR_TERM, MPI_COMM_WORLD, &status);
	RequestErrorTerm (source);
	break;
      case TAG_REPLY_ERROR_TERM:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REPLY_ERROR_TERM, MPI_COMM_WORLD, &status);
	ReplyErrorTerm ();
	break;
      case TAG_REQUEST_REPORT:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_REPORT, MPI_COMM_WORLD, &status);
	RequestReport (source);
	break;
      case TAG_REPLY_REPORT:
	MPI_Recv (a, 3, MPI_UNSIGNED_LONG, source,
		  TAG_REPLY_REPORT, MPI_COMM_WORLD, &status);
	ReplyReport (a[0], a[1], a[2]);
	break;
      case TAG_REQUEST_END_ERROR_TERM:
	MPI_Recv (MPI_BOTTOM, 0, MPI_INT, source,
		  TAG_REQUEST_END_ERROR_TERM, MPI_COMM_WORLD, &status);
	RequestEndErrorTerm ();
	break;
      case TAG_REQUEST_REMOTE_READ:
	MPI_Recv (&number, 1, MPI_UNSIGNED_LONG, source,
		  TAG_REQUEST_REMOTE_READ, MPI_COMM_WORLD, &status);
	RequestRemoteRead (source, number);
	break;
      case TAG_REPLY_REMOTE_READ:
	MPI_Recv ((char *) &b, sizeof (ReadBuffer), MPI_CHAR, source,
		  TAG_REPLY_REMOTE_READ, MPI_COMM_WORLD, &status);
	ReplyRemoteRead (source, b.predNumber, b.predNode, b.c1, b.c2);
	break;

      default:
	cout << "Unrecognized message type";cout.flush();
	int tmptmptmp = 1;
	while (tmptmptmp);
	Error.Notrace ("Unrecognized message type");
      }
      MPI_Iprobe (MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,
		  &flag, &status);

    }				// end while   
  }				// end else
}

/*
	The first version uses Blocking Send MPI calls. This is 
	unsafe. If two processes send messages to each other at 
	the _same_ time, then they will block. Should remove this 
	"unsafeness".
	Post Isend as soon as the data to be sent is available, and 
	complete send just before the send buffer is to be reused. The 
	rationale is to start communication as soon as possible and end
	as late as possible.
	
	Oct 23 - Changed the blocking send calls to non-blocking calls
		 added suitable buffers to enable this.

	May 16 	- Added flow control such that a node will not send more than
				NO_OUTSTANDING_SENDS_PER_NODE states to another node
			- Changed MPI_Isend call to send state to MPI_Isend. With 
			  MPI_Isend, even if the state hadn't been received by the 
			  receiver node, the call to MPI_Test will still return TRUE.
			  With MPI_Issend, the MPI_Test call will return TRUE only if
			  the state was actually received by the receiver.
			- Made changes to the receiver such that it will receive from
			  all other nodes in a round-robin fashion.
			- Inserted another call to IdleTimeStart() in Terminated()
*/
