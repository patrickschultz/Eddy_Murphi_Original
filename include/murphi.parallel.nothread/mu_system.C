/* -*- C++ -*-
 * mu_system.C
 * @(#) procedure for anaylsing the system 
 *      to be simulated or verified
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
 * Original Author: C. Norris Ip 
 * Created: 19 Oct 94
 *
 * Update:
 *
 */ 

/************************************************************/
/* StateManager */
/************************************************************/
StateManager::StateManager(bool createqueue, unsigned long NumStates)
: NumStates(NumStates),
  statesCurrentLevel(0), statesNextLevel(0), currentLevel(0),
  pno(1.0)
{
  if (createqueue) 
    { 
      queue = new state_queue((unsigned long) 
	  							(args->fracqsize.value * NumStates) );
    }
  else 
    { 
      queue = new state_stack((unsigned long) 
	  							(args->fracqsize.value * NumStates) );
    }
  the_states = new state_set(NumStates);
}

StateManager::~StateManager()
{
  if (queue != NULL) delete queue;
  if (the_states != NULL) delete the_states;
}

bool StateManager::Add(state * s)   // changes for PMu
{
  if ( !the_states->simple_was_present(s) )
    {
      if ( args->trace_all.value ) Reporter->print_trace_all();

      statesNextLevel++;
      queue->enqueue(s);
      if (IAmMaster()) Reporter->print_progress();
      return TRUE;
    }
  else
    return FALSE;
}

// input state is not normalized, not checked for safety violation
// normalized within was_present and then violation checked
bool StateManager::Add(state *s, bool valid)
{
	if (!the_states->was_present(s, valid))
	{
		if (!Properties->CheckInvariants())
		{
			curstate = s;
#ifdef HASHC
			if (args->trace_file.value)
				NumCurState = TraceFile->numLast();
#endif
			cout << "Invariant \""
				<< Properties->LastInvariantName()
				<< "\" failure found by node " << MyNode 
				<< " at (bounded) BFS depth "
				<< GetCurrentLevel() << ".\n";
			cout << StateSet->NumElts() 
				<< " states explored, " << Rules->NumRulesFired()
				<< " rules fired in " << SecondsSinceStart()
				<< "s.\n";
			cout.flush();
			Error.Deadlocked("Invariant \"%s\" failed",
				Properties->LastInvariantName());
		}
		if (args->trace_all.value) Reporter->print_trace_all();
		
		statesNextLevel++;
		queue->enqueue(s);
		// if (IAmMaster())
			Reporter->print_progress();
		return TRUE;
	}
	return FALSE;
}

bool StateManager::QueueIsEmpty()
{
  return queue->isempty();
}

state * StateManager::QueueTop()
{
  return queue->top();
}

state * StateManager::QueueDequeue()
{
  return queue->dequeue();
}

unsigned short StateManager::NextRuleToTry()
{
  return queue->NextRuleToTry();
}

void StateManager::NextRuleToTry(unsigned short r)
{
  queue->NextRuleToTry(r);
}

// -------------------------------------------------------------------------
// Uli: added omission probability calculation & printing

#ifdef HASHC

#include <math.h>

double StateManager::harmonic(double n)
// return harmonic number H_n
{
  return (n<1) ? 0 :
                 log(n) + 0.577215665 + 1/(2*n) - 1/(12*n*n);
}

void StateManager::CheckLevel()
// check if we are done with the level currently expanded
{
  static double p = 1.0;    // current bound on state omission probability
  static double l = pow(2, double(args->num_bits.value));   // l=2^b
  static double k = -1;       // sum of the number of states - 1
  static double m = NumStates;   // size of the state table

  if (--statesCurrentLevel <= 0)
  // all the states of the current level have been expanded
  {
    // proceed to next level
    statesCurrentLevel = statesNextLevel;
    statesNextLevel = 0;

    // check if there are states in the following level
    if (statesCurrentLevel!=0)
    {
      currentLevel++;

      // calculate p_k with equation (2) from FORTE/PSTV paper for
      // the following level
      k += statesCurrentLevel;
      double pk = 1 - 2/l * (harmonic(m+1) - harmonic(m-k))
                  + ((2*m)+k*(m-k)) / (m*l*(m-k+1));
      pno *= pk;
    }
  }
}

void StateManager::PrintProb()
{
  // calculate Pr(not even one omission) with equation (12) from CHARME
  //  paper
  double l = pow(2,double(args->num_bits.value));
  double m = NumStates;
  double n = the_states->NumElts();
  double exp = (m+1) * (harmonic(m+1) - harmonic(m-n+1)) - n;
  double pNO = pow(1-1/l, (m+1) * (harmonic(m+1) - harmonic(m-n+1)) - n);

  // print omission probabilities
  cout.precision(6);
  cout << "Omission Probabilities (caused by Hash Compaction):\n\n"
       << "\tPr[even one omitted state]    <= " << 1-pNO << "\n";
  if (args->main_alg.mode == argmain_alg::Verify_bfs)
    cout << "\tPr[even one undetected error] <= " << 1-pno << "\n"
         << "\tDiameter of reachability graph: " 
           << currentLevel-1 << "\n\n";   
           // remark: startstates had incremented the currentLevel counter
  else
    cout << "\n";
}

#endif

// -------------------------------------------------------------------------

void StateManager::print_capacity()
{
  if (  args->main_alg.mode == argmain_alg::Verify_dfs 
	|| args->main_alg.mode == argmain_alg::Verify_bfs)
    {
      cout << "\nMemory usage:\n\n";
      cout << "\t* The size of each state is " << BITS_IN_WORLD << " bits "
	   << "(rounded up to " << BLOCKS_IN_WORLD << " bytes).\n";
      the_states->print_capacity();
      queue->print_capacity();
    }
}

void StateManager::print_all_states()
{
  the_states->print();
}

unsigned long StateManager::NumElts()
{ 
  return the_states->NumElts();
}

void StateManager::AddNumElts(unsigned long a)   // PMu
{
  the_states->AddNumElts(a);
} 

unsigned long StateManager::QueueNumElts()
{ 
  return queue->NumElts();
}

// reset the hash table and the queue
void StateManager::Reset()
{
	while( !queue->isempty() )
		delete queue->dequeue();
	the_states->clear_state_set();
	statesCurrentLevel = 0L; 
	statesNextLevel = 0L; 
	currentLevel = 0L;
  	pno	= 1.0;
	return;
}

void StateManager::print_trace_aux(StatePtr p)   // changes by Uli
{
  state original;
  char *s;
  
  if (p.isStart())
    {
      // this is a startstate
      // expand it into global variable `theworld`
      // StateCopy(workingstate, s);   // Uli: workingstate is set in 
                                       //      StateName()
      
      // output startstate
      cout << "Startstate "
 	   << (s=StartState->StateName(p))
 	   << " fired.\n";
      delete[] s;   // Uli: avoid memory leak
      theworld.print();
      cout << "----------\n\n";
    }
  else
    {
      // print the prefix
      print_trace_aux(p.previous());
      
      // print the next state, which should be equivalent to state s
      // and set theworld to that state.
      // FALSE: no need to print full state
      Rules->print_world_to_state(p, FALSE);
    }
}

void StateManager::print_trace(StatePtr p)
{
  // print the prefix 
  if (p.isStart())
    {
      print_trace_aux(p);
    }
  else
    {
      print_trace_aux(p.previous());
      
      // print the next state, which should be equivalent to state s
      // and set theworld to that state.
      // TRUE: print full state please;
      Rules->print_world_to_state(p, TRUE);
    }
}


/************************************************************/
/* StartStateManager */
/************************************************************/
StartStateManager::StartStateManager()
{
  generator = new StartStateGenerator;
}

state * 
StartStateManager::RandomStartState()
{
  what_startstate = (unsigned short)(random.next() % numstartstates); 
  return StartState();
}

// without any argument, the states generated are sent to their owning
// processors
void 
StartStateManager::AllStartStates()
{
  state *nextstate = NULL;

  for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
    {
      nextstate = StartState();   // nextstate points to internal data at theworld.getstate()
      (void) SendState(nextstate, FALSE);   // PMu
    }
}

// in this version of AllStartStates, we don't send the state across
// to its owning processor. Instead we add it to the StateManager passed
// as argument.
void 
StartStateManager::AllStartStates(StateManager *sm)
{
  state *nextstate = NULL;

  for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
    {
      nextstate = StartState();   
	  				// nextstate points to internal data at theworld.getstate()
      (void) sm->Add(nextstate, FALSE);  
    }
}

state * 
StartStateManager::NextStartState()
{
  static unsigned short next_startstate=0;
  if (next_startstate >= numstartstates) return NULL;
  what_startstate = next_startstate++;
  return StartState();
}

state * 
StartStateManager::StartState()
{
  state *next_state = NULL;
  
  category = STARTSTATE;

  // preparation
  theworld.reset();
  
  // fire state rule
  generator->Code(what_startstate);
  
  // print verbose message
  if (args->verbose.value) Reporter->print_fire_startstate();
  
  // Uli: invariant check moved
  
  // Uli: mark as startstate
  workingstate->previous.clear();

  return workingstate;
}

char * 
StartStateManager::LastStateName()
{
  return generator->Name(what_startstate);
}

char * 
StartStateManager::StateName(StatePtr p)
{
  state * nextstate;

  if (!p.isStart()) Error.Notrace("Internal: Cannot find startstate name for non startstate");
  for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
    {
      nextstate = StartState();                  // nextstate points to internal data at theworld.getstate()
      if (p.compare(nextstate))
	return LastStateName();
    }

  Error.Notrace("Internal: Cannot find startstate name for funny startstate");
  return NULL;
}

/************************************************************/
/* RuleManager */
/************************************************************/
RuleManager::RuleManager() : rules_fired(0)
{
  NumTimesFired = new unsigned long [RULES_IN_WORLD];
  generator = new NextStateGenerator;

  // initialize check timesfired
  for (int i=0; i<RULES_IN_WORLD; i++)  
    NumTimesFired[i]=0;
  #ifdef DEBUG
  cout << MyNode << ": random no. value for next state generation = "
  		<< random.getValue() << endl; cout.flush();
  #endif
};

RuleManager::~RuleManager()
{
  delete[ OLD_GPP(RULES_IN_WORLD) ] NumTimesFired;
}

void 
RuleManager::ResetRuleNum()
{
  what_rule = 0;
}

void 
RuleManager::SetRuleNum(unsigned short r)
{
  what_rule = r;
}

state * 
RuleManager::SeqNextState()
{
  state * ret;

  what_rule = StateSet->NextRuleToTry();

  generator->SetNextEnabledRule(what_rule);

  if ( what_rule<numrules )
    {
      ret = NextState();
      StateSet->NextRuleToTry(what_rule+1);
      return ret;
    }
  else
    return NULL;
}

// doesn't do Normalization, checks for Invariant violation
state * 
RuleManager::RandomNextState()
{ 
  
  unsigned short PickARule;
  setofrules rulesleft;
  static state *originalstate = new state;  // for checking deadlock
  
  // save original state
  StateCopy(originalstate,workingstate);
  
  // setup set of rules to be checked
  rulesleft.includeall();
  
  // nondeterministically fire rules until a different state is obtained
  // or no rule available
  category = CONDITION;
  
  while (StateCmp(originalstate,workingstate)==0 && rulesleft.size()!=0 )
    {
      PickARule = random.next() % rulesleft.size();
      what_rule = rulesleft.getnthrule(PickARule);
      if ( generator->Condition(what_rule) )
		{
		  category = RULE;
		  generator->Code(what_rule);
		}
    }    
  
  // write unnormalized random next state
  if (args->trace_file.value)
	TraceFile->writeState(workingstate);
  // move this outside RandomNextState, to accomodate writing to diff files
  // change Heuristic1 accordingly
	
  // if deadlock occurs
  if (!args->no_deadlock.value && StateCmp(originalstate,workingstate)==0)
    {
      cout << "\nStatus:\n\n";
      cout << "\t" << MyNode << ": " << rules_fired << 
	  		" rules fired in simulation in "
			<< (SecondsSinceStart() - user_input_time) << "s.\n";
      Error.Notrace("Deadlocked state found.");
    }
  
  rules_fired++;
  
  // print verbose message
  if (args->verbose.value & !args->full_trace.value) Reporter->print_fire_rule_diff( originalstate );
  if (args->verbose.value & args->full_trace.value) Reporter->print_fire_rule();
  
  if (!Properties->CheckInvariants())
    {
      cout << "\nStatus:\n\n";
      cout << "\t" << MyNode << ": " << rules_fired 
	  		<< " rules fired in simulation in "
	   << (SecondsSinceStart() - user_input_time) << "s.\n";
	   cout << "\t" << MyNode << ": Invariant " << 
	   				Properties->LastInvariantName() << " failed.\n";
		cout.flush();
      Error.Notrace("Invariant %s failed.", Properties->LastInvariantName() );
    }
  
  // progress report
  if ( !args->verbose.value && rules_fired % args->progress_count.value == 0 )
    {
      cout << "\t" << MyNode << ": " << rules_fired << 
	  		" rules fired in simulation in "
	   << (SecondsSinceStart() - user_input_time) << "s.\n";
    }
  return workingstate;
}

bool 
RuleManager::AllNextStates() 
{
  setofrules * fire;

  // get set of rules to fire
  fire = EnabledTransition();
  
  // generate the set of next states
  return AllNextStates(fire);
}      

bool 
RuleManager::AllNextStates(StateManager *sm) 
{
  setofrules * fire;

  // get set of rules to fire
  fire = EnabledTransition();
  
  // generate the set of next states
  return AllNextStates(sm, fire);
}

/****************************************
  Generate set of transitions to be made:
  setofrules transitionset_enabled()
  -- future extension
  -- setofrules transitionset_sleepset_rr(sleepset s)
  -- setofrules transitionset_gode_dl(setofrules rs)
  ****************************************/
setofrules *  
RuleManager::EnabledTransition()
{
  static setofrules ret;

  ret.removeall();
  
  // record what kind of analysis is currently carried out
  category = CONDITION;

  // get enabled
  for ( what_rule=0; what_rule<numrules; what_rule++)
    {
      generator->SetNextEnabledRule(what_rule);
      if ( what_rule<numrules )
	ret.add(what_rule);
    }
  return &ret;
} 

/****************************************
  The BFS verification supporting routines:
  void generate_startstateset()
  bool generate_nextstateset_standard(setofrules fire)
  -- future extension
  -- bool generate_nextstateset_sym() 
  -- bool generate_nextstateset_gode_dl() 
  -- bool generate_nextstateset_sleepset_rr(setofrules fire, sleepset cursleepset)
  -- bool generate_nextstateset_gode_sleepset_dl(sleepset cursleepset)
  ****************************************/

// Uli: corrected a memory-leak, improved performance
bool
RuleManager::AllNextStates(setofrules * fire)
{
  // this will unconditionally fire rule in "fire"
  // please make sure the conditions are true for the rules in "fire"
  // before calling this function.

  static state * originalstate = new state;   // buffer for workingstate
  state * nextstate;
  bool deadlocked_so_far = TRUE;

  StateCopy(originalstate, workingstate);   // make copy of workingstate
  
  for ( what_rule=0; what_rule<numrules; what_rule++)
    {
      if (fire->in(what_rule) )
	{
	  nextstate = NextState();
	  if ( StateCmp(curstate,nextstate)!=0 ) {
            deadlocked_so_far = FALSE;
	    (void) SendState(nextstate, TRUE);   // PMu
	    StateCopy(workingstate, originalstate);   // restore workingstate
          }
	} 
    }
  return deadlocked_so_far;
}

bool
RuleManager::AllNextStates(StateManager *sm, setofrules * fire)
{
  // this will unconditionally fire rule in "fire"
  // please make sure the conditions are true for the rules in "fire"
  // before calling this function.

  static state * originalstate = new state;   // buffer for workingstate
  state * nextstate;
  bool deadlocked_so_far = TRUE;

  StateCopy(originalstate, workingstate);   // make copy of workingstate
  
  for ( what_rule=0; what_rule<numrules; what_rule++)
    {
      if (fire->in(what_rule) )
	 {
	  nextstate = NextState();
	  if ( StateCmp(curstate,nextstate)!=0 ) {
            deadlocked_so_far = FALSE;
			// curstate points to a state whose hashkeys have been computed
			// nextstate == workingstate
	    (void) sm->Add(nextstate, TRUE);  
	    StateCopy(workingstate, originalstate);   // restore workingstate
          }
	 } 
    }
  return deadlocked_so_far;
}

// the following global variables have been set:
// theworld, curstate and what_rule
state * 
RuleManager::NextState()
{
  
  category = RULE;

  // fire rule
  generator->Code(what_rule);
  rules_fired++;
  
  // update timesfired record
  NumTimesFired[what_rule]++;
  
  // print verbose message
  if (args->verbose.value) Reporter->print_fire_rule();
  
  // Uli: invariant check moved
//  if (!Properties->CheckInvariants())
//    {
//      Error.Error("Invariant \"%s\" failed.",Properties->LastInvariantName());
//    }
  
  // get next state
#ifdef HASHC
  if (args->trace_file.value)
    workingstate->previous.set(NumCurState,GetMyNode());
  else
#endif
    workingstate->previous.set(curstate,GetMyNode());
  return workingstate;
}

void 
RuleManager::print_world_to_state(StatePtr p, bool fullstate)
{
  state original;
  state nextstate;
  char *s;

  // save last state
  StateCopy(&original, workingstate);
  
  // generate next state
  for ( what_rule=0; what_rule<numrules; what_rule++)
    {
      category = CONDITION;
      if (generator->Condition(what_rule))
 	{
	  category = RULE;
	  generator->Code(what_rule);
	  StateCopy(&nextstate, workingstate);

	  if (StateEquivalent(&nextstate, p))
	    {
	      // output the name of the rule and the last state in full
	      cout << "Rule "
		   // << rules[ what_rule ].name
		   << (s=generator->Name(what_rule))
		   << " fired.\n";
              delete[] s;   // Uli: avoid memory leak
	      if (fullstate)
		cout << "The last state of the trace (in full) is:\n";
	      if (args->full_trace.value || fullstate) 
		theworld.print();
	      else
		theworld.print_diff( &original );
	      cout << "----------\n\n";
	      return;
	    }
	  else
	      StateCopy(workingstate, &original);
 	}
    }
  Error.Notrace("Internal Error:print_world_to_state().");
}

char * 
RuleManager::LastRuleName()
{
  return generator->Name(what_rule);
}

unsigned long RuleManager::NumRulesFired()
{
  return rules_fired;
}

void RuleManager::AddNumRulesFired(unsigned long a)   // PMu
{
  rules_fired+=a;
}

void 
RuleManager::print_rules_information()
{
  bool exist = FALSE;

  if (args->print_rule.value)
    {
      
      cout << "Rules Information:\n\n";
      for (int i=0; i<RULES_IN_WORLD; i++)  
	cout << "\tFired " << NumTimesFired[i] << " times\t- Rule \""
	     << generator->Name(i)
	     << "\"\n";
    }
  else
    {
      for (int i=0; i<RULES_IN_WORLD && !exist; i++)  
	if (NumTimesFired[i]==0)
	  exist = TRUE;
      if (exist)
	cout << "Analysis of State Space:\n\n"
	     << "\tThere are rules that are never fired.\n"
	     << "\tIf you are running with symmetry, this may be why.  Otherwise,\n"
	     << "\tplease run this program with \"-pr\" for the rules information.\n";
    }
}
  
/************************************************************/
/* PropertyManager */
/************************************************************/
PropertyManager::PropertyManager()
{
}

bool 
PropertyManager::CheckInvariants()
{
  category = INVARIANT;
  for ( what_invariant = 0; what_invariant < numinvariants; what_invariant++ )
    {
      if ( !( *invariants[ what_invariant ].condition )() )
        /* Uh oh, invariant blown. */
        {
	  return FALSE;
        }
    }
  return TRUE;
}

char * 
PropertyManager::LastInvariantName()
{
  return invariants[what_invariant].name;
}

/************************************************************/
/* SymmetryManager */
/************************************************************/
SymmetryManager::SymmetryManager()
{
}

/************************************************************/
/* POManager */
/************************************************************/
POManager::POManager()
{
}

/************************************************************/
/* AlgorithmManager */
/************************************************************/
AlgorithmManager::AlgorithmManager()   // changes for PMu
{
  // why exists? (Norris)
  // oldnh = set_new_handler(&err_new_handler);

  // create managers
  StartState = new StartStateManager;
  Rules = new RuleManager;
  Properties = new PropertyManager;
  Symmetry = new SymmetryManager;
  PO = new POManager;
  Reporter = new ReportManager;

#ifdef HASHC
  h3 = new hash_function(BLOCKS_IN_WORLD);
#endif

  Reporter->CheckConsistentVersion();
  if (IAmMaster()) {
    if (args->main_alg.mode!=argmain_alg::Nothing)
      Reporter->print_header();
    Reporter->print_algorithm();
  }

  switch( args->main_alg.mode )
    {
    case argmain_alg::Verify_bfs:
      StateSet = new StateManager(TRUE, NumStatesGivenBytes( args->mem.value ));
      if (IAmMaster())
        StateSet->print_capacity();
      break;
    case argmain_alg::Verify_dfs:
      StateSet = new StateManager(FALSE, NumStatesGivenBytes( args->mem.value ));
      StateSet->print_capacity();
      break;
    case argmain_alg::Simulate:
      StateSet = NULL;
      break;
	case argmain_alg::Heuristic1:
	  // allocate space for the ht only if we are sending states
	  // to the owning processors
	  if (args->send_rw.value)
	  {
	  	rw_ht = new state_set(NumStatesGivenBytes( args->mem.value ));
		if (!rw_ht)
		{
		  	fprintf(stderr, "Node %d: Heuristic1, Error allocating space for \
							the hash table", MyNode);
			MPI_Finalize();
			exit(1);
		}
	  }
	  break;
	case argmain_alg::Heuristic2:
	  // allocate HT and queue
	  StateSet = new StateManager(TRUE, NumStatesGivenBytes(args->mem.value));
	  if (!StateSet)
	  {
	  	fprintf(stderr, "Node %d: Heuristic2, Error allocating space for \
							StateSet", MyNode);
		MPI_Finalize();
		exit(1);
	  }
	  if(IAmMaster())
	  	StateSet->print_capacity();
		
	 // allocate space for Bounded BFS HT only if RW states are going to
	 // be transmitted
	 if (args->send_rw.value)
	 {
	 	BoundedStateSet = new StateManager(TRUE, 
						NumStatesGivenBytes(args->bounded_mem.value));
		if (!BoundedStateSet)
		{
			fprintf(stderr, "Node %d: Heuristic2, Error allocating space for \
									BoundedStateSet", MyNode);
			MPI_Finalize();
			exit(1);
		}
		if(IAmMaster())
			BoundedStateSet->print_capacity();
	 }
	  break;
	case argmain_alg::Heuristic3:
		// allocate HT and queue
		StateSet = new StateManager(TRUE,
								NumStatesGivenBytes(args->mem.value));
		if (!StateSet)
		{
			fprintf(stderr, "Node %d: Heuristic3, Error allocating space for \
									StateSet", MyNode);
			MPI_Finalize();
			exit(1);
		}
		if(IAmMaster())
			StateSet->print_capacity();
	  break;
	case argmain_alg::Heuristic4:
	  // allocate HT and queue
	  StateSet = new StateManager(TRUE, NumStatesGivenBytes(args->mem.value));
	  if (!StateSet)
	  {
	  	fprintf(stderr, "Node %d: Heuristic4, Error allocating space for \
							StateSet", MyNode);
		MPI_Finalize();
		exit(1);
	  }
	  if(IAmMaster())
	  	StateSet->print_capacity();
		
	 // allocate space for Bounded BFS HT only if RW states are going to
 	 // be transmitted
	 if (args->send_rw.value)
	 {
	 	BoundedStateSet = new StateManager(TRUE, 
						NumStatesGivenBytes(args->bounded_mem.value));
		if (!BoundedStateSet)
		{
			fprintf(stderr, "Node %d: Heuristic4, Error allocating space for \
									BoundedStateSet", MyNode);
			MPI_Finalize();
			exit(1);
		}
		if(IAmMaster())
			BoundedStateSet->print_capacity();
		// allocate space for frontier array
		max_elts_frontier_array = (unsigned long) (args->fracfrontsize.value
									* NumStatesGivenBytes(args->mem.value));
		frontier_array = new state*[max_elts_frontier_array];
		if (!frontier_array)
		{
			fprintf(stderr, "Node %d: Heuristic4, Error allocating space for \
									frontier_array", MyNode);
			MPI_Finalize();
			exit(1);
		}
		for(int i = 0; i < max_elts_frontier_array; i++)
			frontier_array[i] = NULL; 
		num_elts_frontier_array = 0UL;
	 }
	  break;
    default:
      break;
    }

  if (IAmMaster())
    Reporter->print_warning();

  signal(SIGFPE, &catch_div_by_zero);

};

/* This is exactly the algorithm in Fig. 1 of the paper */
void 
AlgorithmManager::verify_bfs()   // changes for PMu
{
  // Use Global Variables: what_rule, curstate, theworld, queue, the_states
  setofrules fire;  // set of rule to be fired
  bool deadlocked;  // boolean for checking deadlock

  // print verbose message
  if (args->verbose.value) Reporter->print_verbose_header();

  theworld.to_state(NULL); // trick : marks variables in world

  cout.flush();
  MPI_Barrier(MPI_COMM_WORLD);

  // Generate all start state
  if (IAmMaster()) {
    StartState->AllStartStates();
    IdleTimeStart();	/* simply reset the counter for the number of
	                   calls to Terminated()*/
	#ifdef DEBUG
	cout << "start states have been sent\n"; cout.flush();
	#endif
  }

  StateSet->CheckLevel();/* logically, should be inside the previous if */
    // search state space
  do
  {
    if ( !StateSet->QueueIsEmpty() )
    {
      // please make sure that global variable curstate does not change 
      // throughout the iteration 
      curstate = StateSet->QueueTop();
      NumCurState++;
      StateCopy(workingstate, curstate);
      // Uli: invariant check moved here
      if (!Properties->CheckInvariants()) {
	        Error.Deadlocked("Invariant \"%s\" failed on BFS level %d",
							Properties->LastInvariantName(),
							StateSet->GetCurrentLevel());
      }
      if (args->verbose.value) Reporter->print_curstate();
      deadlocked = Rules->AllNextStates();
      if ( deadlocked && !args->no_deadlock.value )
		Error.Deadlocked("Deadlocked state found.");
      StateSet->QueueDequeue();
      // omission probability calculation
      StateSet->CheckLevel();
      delete curstate;
      if (IAmMaster() && StateSet->QueueIsEmpty())   // queue just became empty
        IdleTimeStart();	/* simply reset the counter for the number of
	                           calls to Terminated()*/
    }
    // terminate if error occurred
    IfErrorTerminate();
  } while (!Terminated());/* the slaves executes this first, and the first thing
                           is to poll messages */
  if (IAmMaster())
    Reporter->print_final_report();
}

/****************************************
  The DFS verification routine:
  void verify_dfs()
  -- not changed yet 
  ****************************************/

void 
AlgorithmManager::verify_dfs()
{
  // use global variables: what_rule, curstate, theworld, queue, the_states
  state *nextstate;
  bool deadlocked_so_far = TRUE;
 
  Error.Notrace("Internal: Parallel Murphi only supports bfs.");
 
  // print verbose message
  if (args->verbose.value) Reporter->print_verbose_header();

  theworld.to_state(NULL); // trick : marks variables in world

  // for each startstate start a DFS search
  while ((curstate = StartState->NextStartState()) != NULL)
    {
      (void) StateSet->Add(curstate/*, FALSE*/);

      while ( !StateSet->QueueIsEmpty() )
 	{
 	  // get the last state from the stack
	  curstate = StateSet->QueueTop();
	  StateCopy(workingstate, curstate);
	    
 	  // l) method:
 	  // get a different next state by incrementing what_rule
 	  // until a rule is enabled and the new state is different from the
 	  // old state or all the rules are exhausted
 	  // 2) setting of varibles
 	  // what_rule is set by previous iteration
 	  // curstate is set at the beginning of the iteration
 	  // theworld is set at the beginning of the iteration
 	  
 	  // get next rule that is enabled and fire it
          // set global variable what_rule
	
 	  nextstate = Rules->SeqNextState();

 	  if ( nextstate!=NULL )
	    {
	      if ( StateCmp(curstate,nextstate)!=0 )
	      {
	        // curstate state does not deadlock
	        deadlocked_so_far = FALSE;

	        // check if the next state has been searched or not
	        if (StateSet->Add(nextstate/*, TRUE*/))
		{
 		  // curstate state does not deadlock, but the next state might
 		  deadlocked_so_far = TRUE;
 		}
 	        else
 		{
 		  // a rule has been fired and the next state has been searched
 		  // ==> check next rule
 		  if (args->verbose.value) 
 		    cout << "This state has been examined, try another rule.\n";
 		}
              }
              else
                if (args->verbose.value)
                  cout << "This state has been examined, try another rule.\n";
 	    }
 	  else
 	    {
	      // check deadlock
	      if ( deadlocked_so_far && !args->no_deadlock.value )
		{
		  if (args->verbose.value) Reporter->print_dfs_deadlock();
		  Error.Deadlocked("Deadlocked state found.");
		}
	      
	      // remove explored state
 	      (void) StateSet->QueueDequeue();

 	      // print verbose message
 	      if (args->verbose.value) Reporter->print_retrack();
 	      
 	      // previous state does not deadlock, as it gives the state just removed
 	      deadlocked_so_far = FALSE;
 	      
#ifdef HASHC
	      delete curstate;
#endif
 	    } // if
 	} // while
 
       // print verbose message
       if (args->verbose.value)
 	cout << "------------------------------\n"
 	     << "Finished working on one statestate.\n"
 	     << "------------------------------\n";
     } // for
  Reporter->print_final_report();
}

/****************************************
  The simulation main routine:
  void simulate()
  ****************************************/
void 
AlgorithmManager::simulate()
{
  // progress report must be printed out so as to make sense 
  // otherwise, if there is no bug, the program just run on for ever
  // without any message.
   
  theworld.to_state(NULL); // trick : marks variables in world

  // print verbose message
  if (args->verbose.value) Reporter->print_verbose_header();

  Reporter->StartSimulation();

  // GetRandomStartState will choose a Startstate randomly
  curstate = StartState->RandomStartState();

  
  
  // simulate
  while(1)
    {
      // SimulateRandomRule always executes a rule that leads to
      // a different state.
      curstate = Rules->RandomNextState();
    }
}

// If we want to use the canonical form of s after normalization, then
// first copy s to workingstate, point s to workingstate and then call 
// this function. This is because Normalize() modifies the state pointed 
// to by workingstate.
static void normalize (state *s)
{
	if (args->symmetry_reduction.value)
		s->Normalize();
	if (args->multiset_reduction.value
		  && !args->symmetry_reduction.value)
		s->MultisetSort();
	return;
}

void
AlgorithmManager::heuristic1()
{
	// pure n RWs, each starting from a random state
	int steps_so_far = 0;
	int interval_counter = 0;
	state *buffer = new state;
	
	theworld.to_state(NULL); // trick: marks the variables in world

	if(args->verbose.value) Reporter->print_verbose_header();

    curstate = StartState->RandomStartState();

	// write unnormalized state
	if (args->trace_file.value)
		TraceFile->writeState(workingstate);
		
	if (!Properties->CheckInvariants())
	{
		Error.Deadlocked("Invariant \"%s\" failed.",
				Properties->LastInvariantName());
	}
	if (!args->send_rw.value)
	{
		// we still need to do normalization
		normalize(workingstate);
//   StoreStateFile(curstate);
// maybe this is not required, we can use the TraceFile->write() functions
// when we add it to the hash table (when simple_was_present() is called)

	}
	else
	{
		// curstate == workingstate
		// workingstate normalized within SendState
		SendState(curstate, FALSE);
// store state in file within sendstate
		interval_counter = (interval_counter+1)%
							args->send_rw_interval.value;
	}
	
	while (steps_so_far < args->total_initial_rw_steps.value)
	{
		if (!args->send_rw.value)
		{
			curstate = Rules->RandomNextState();
			// we still need to do normalization
			normalize(workingstate);
//   StoreStateFile(curstate);
		}
		else
		{
			if (interval_counter == 0)
			{
				StateCopy(buffer,workingstate);
				Rules->RandomNextState();
				// now next state generated, unnormalized and invariant checked
				
				// point curstate to previous state, 
				// so we can use it for diff hashing
				curstate = buffer;
				// temp_cur == workingstate
				// workingstate normalized within SendState
				SendState(workingstate, TRUE);
// store state in file within sendstate
			}
			else
			{
				Rules->RandomNextState();
				// now next state generated, unnormalized and invariant checked

				// we still need to do normalization
				normalize(workingstate);
//   StoreStateFile(workingstate);
				
				if (interval_counter == (args->send_rw_interval.value - 1))
					h3->hash(workingstate, FALSE);
				// when we see that we are going to reach the interval boundary
				// we need to compute the hash value of the state generated,
				// (of course, without using diff hashing) so that in the next 
				// step when we execute the if part of the condition, the 
				// calculated hash value will be used for diff hashing
			}
			interval_counter = (interval_counter+1)%
								args->send_rw_interval.value;
		}
		steps_so_far++;
		
	    // terminate if error occurred
	    IfErrorTerminate();
	}
	// the random walks have been completed
	// collect the results and print them out
	PrintFinalResult_Heuristic1();
	// might need to add a barrier here so that the slaves wait for the
	// master to printout the results before calling MPI_Finalize()
	return;
}

void doInitialBfs()
{
	cout << MyNode << ": Starting Initial BFS of depth "
		<< args->init_bfs_depth.value << ".\n";
	cout.flush();
	
	// do initial BFS

	if (args->verbose.value) Reporter->print_verbose_header();
	cout.flush();

	bool deadlocked;
	
	StartState->AllStartStates(StateSet);
#ifdef HASHC
	StateSet->CheckLevel();
#endif
	while(StateSet->GetCurrentLevel() <= args->init_bfs_depth.value)
	{
		if (StateSet->QueueIsEmpty())
		{
			cout << "Initial BFS queue should not be empty.\n";
			cout << "Try choosing some other initial depth for BFS.\n";
			ParallelTerminate(1);
		}
		curstate = StateSet->QueueTop();
		NumCurState++;	// this is for error trail generation
		StateCopy(workingstate, curstate);

		if (!Properties->CheckInvariants()) {
			cout << MyNode << ": Invariant failed in Initial BFS after "
					<< SecondsSinceStart() << "s.\n"; 
			cout.flush();
        	Error.Deadlocked("Invariant \"%s\" failed on initial BFS level %d",
								Properties->LastInvariantName(),
								StateSet->GetCurrentLevel());
      	}

		if (args->verbose.value) Reporter->print_curstate();

		deadlocked = Rules->AllNextStates(StateSet);

		if (deadlocked && !args->no_deadlock.value)
		{
			cout << "Deadlocked state found by node " << MyNode 
				<< " after " << SecondsSinceStart() << "s.\n";
			cout.flush();
			Error.Deadlocked ("Deadlocked state found.");
		}

		StateSet->QueueDequeue();
#ifdef HASHC
		StateSet->CheckLevel();
		delete curstate;
#endif
	} // end while

	cout << MyNode << ": Finished Initial BFS.\n";
	cout.flush();
	return;
}

// the frontier states are in the queue
void distributeBfsFrontier()
{
	// Are the states in the queue here normalized, checked for violation etc?
	int states_in_queue = StateSet->QueueNumElts();
	cout << "Number of states in queue: " 
		<< states_in_queue << ".\n";
	if (states_in_queue >= NumNodes)
	{
		// some processors will have to do more than one RWs
		int num_rw_each_proc = states_in_queue/NumNodes;
		int residue = states_in_queue % NumNodes;
		
		// we spread the residual states among the slave nodes (since master
		// does some other stuff as well and hence need not take on one more
		// RW)
		
		int temp_num_rw;
		for (int i = 0; i < NumNodes; i++)
		{
			if ( i != MASTER )
			{
				if (residue != 0)
				{
					temp_num_rw = num_rw_each_proc + 1;
					residue--;
				}
				else
				{
					temp_num_rw = num_rw_each_proc;
				}
				cout << "Node " << i << " gets " << temp_num_rw 
						<< " states.\n";
				MPI_Send(&temp_num_rw, 1, MPI_INT, i, TAG_NUM_INITIAL_RW,
										MPI_COMM_WORLD);
			}
		}
		// we have sent to all slaves the number of rw start states
		// we now have to send the start states to them
		residue = states_in_queue % NumNodes;
			
		// this is for the master
		num_random_walks = num_rw_each_proc;
		rw_fronts = new state*[num_random_walks];
		size_rw_fronts = num_random_walks;
		if (!rw_fronts)
		{
			cout << MyNode 
					<< ": Unable to allocate memory for RW fronts.\n";
			ParallelTerminate(1);
		}

		int j;
		state *ts;
		for(int i = 0; i < NumNodes; i++)
		{
			if (i != MASTER)
			{
				for (j = 0; j < num_rw_each_proc; j++)
				{
					ts = StateSet->QueueDequeue();
					MPI_Send((char *)ts, sizeof(state), MPI_CHAR, i, 
								TAG_INITIAL_RW_STATE, MPI_COMM_WORLD);
					delete ts;
				}
				if ( residue != 0 )
				{
					ts = StateSet->QueueDequeue();
					MPI_Send((char *)ts, sizeof(state), MPI_CHAR, i, 
								TAG_INITIAL_RW_STATE, MPI_COMM_WORLD);
					delete ts;
					residue--;
				}
			}
			else // for master
			{
				for (j = 0; j < num_rw_each_proc; j++)
					rw_fronts[j] = StateSet->QueueDequeue();
					// don't delete them
			}
		}
	}
	else 	// states_in_queue < NumNodes
	{
		// some processors will have to start RW from the same 
		// start state
		// Generally this case won't happen
		int num_procs_per_state = NumNodes/states_in_queue;
		int residue = NumNodes % states_in_queue;

		int temp_num_rw = 1;
		for (int i = 0; i < NumNodes; i++)
		{
			// everyone gets exactly one RW start state
			if ( i != MASTER)
				MPI_Send(&temp_num_rw, 1, MPI_INT, i, TAG_NUM_INITIAL_RW,
									MPI_COMM_WORLD);
		}
		// for master
		num_random_walks = 1;
		rw_fronts = new state*[num_random_walks];
		size_rw_fronts = num_random_walks;
		if (!rw_fronts)
		{
			cout << MyNode 
					<< ": Unable to allocate memory for RW fronts.\n";
			ParallelTerminate(1);
		}
		int j, k =0;
		state *ts;
		for (int i = 0; i < states_in_queue; i++)
		{
			ts = StateSet->QueueDequeue();
			for (j = 0; j < num_procs_per_state; j++)
			{
				if ( k != MASTER)
				{
					MPI_Send((char *)ts, sizeof(char), MPI_CHAR, k, 
						TAG_INITIAL_RW_STATE, MPI_COMM_WORLD);
				}
				else
				{
					rw_fronts[0] = new state;
					StateCopy(rw_fronts[0], ts);
				}
				k++;
			}
			if (residue != 0)
			{
				if ( (NumNodes-residue) != MASTER )
				{
					MPI_Send((char *)ts, sizeof(state), MPI_CHAR, NumNodes-residue,
								TAG_INITIAL_RW_STATE, MPI_COMM_WORLD);
				}
				else
				{
					rw_fronts[0] = new state;
					StateCopy(rw_fronts[0], ts);
				}
				residue--;
			}
			delete ts;
		}

	}
	
	// for master
	start_initial_rw = TRUE;

	return;
}

// do Bounded BFS with s as the start state
// after the call to this function, BoundedStateSet queue has the
// frontier states of the Bounded BFS.
// Retains the value of curstate and workingstate before it was called.
// We assume that the BoundedStateSet is reset before this function is called.
void boundedBfs(state *s)
{
	static state *temp_workingstate = new state;
	static state *temp_curstate = NULL;
	
	StateCopy(temp_workingstate, workingstate);
	temp_curstate = curstate;

	bool deadlocked;
	
	StateCopy(workingstate, s);
	s = workingstate;
	BoundedStateSet->Add(s, FALSE);
#ifdef HASHC
	BoundedStateSet->CheckLevel();
#endif
	while (BoundedStateSet->GetCurrentLevel() <= args->bounded_bfs_depth.value)
	{
		if (BoundedStateSet->QueueIsEmpty())
		{
			// cout << MyNode << ": Bounded BFS queue should not be empty.\n";
			#ifdef DEBUG
			cout << MyNode << ": Bounded BFS queue is empty.\n";
			#endif 
			// cout << MyNode << ": Try choosing some other depth for bounded BFS.\n";
			// ParallelTerminate(1);
			break;
		}
		curstate = BoundedStateSet->QueueTop();
		StateCopy(workingstate, curstate);
		deadlocked = Rules->AllNextStates(BoundedStateSet);
		if (deadlocked && !args->no_deadlock.value)
		{
			cout << "Deadlocked state found by node "
					<< MyNode << " in bounded BFS.\n";
			Error.Deadlocked ("Deadlocked state found.");
		}

		BoundedStateSet->QueueDequeue();
#ifdef HASHC
		BoundedStateSet->CheckLevel();
		delete curstate;
#endif
	}
	
	//restore the values
	curstate = temp_curstate;
	StateCopy(workingstate, temp_workingstate);

	return;
}

// returns true if a bounded BFS was done, otherwise false
// the return value is used to decide whether to reset the 
// BoundedStateSet or not
static bool checkDoBoundedBfs()
{
	static int bounded_bfs_interval_counter = 0;
	
	if (!StateSet->QueueIsEmpty())
	{
		if ( bounded_bfs_interval_counter == 0 )
		{
			// do bounded BFS with the top of the queue as the 
			// start state
			boundedBfs(StateSet->QueueTop());
			delete StateSet->QueueDequeue();
			bounded_bfs_interval_counter = 
							1 % args->bounded_bfs_interval.value;
			return TRUE;
		}
		else
		{
			int num_states_needed = 
					args->bounded_bfs_interval.value -
						bounded_bfs_interval_counter;
			if (StateSet->QueueNumElts() > num_states_needed)
			{
				// there are enough states in the queue to
				// do atleast one bounded BFS
				for(int v = 0; v < num_states_needed; v++)
					delete StateSet->QueueDequeue();
				// do bounded BFS from the top of the queue
				// as the start state
				boundedBfs(StateSet->QueueTop());
				delete StateSet->QueueDequeue();
				bounded_bfs_interval_counter = 
							1 % args->bounded_bfs_interval.value;
				return TRUE;
			}
			else
			{
				int numelts = StateSet->QueueNumElts();
				for (int v = 0; v < numelts; v++)
					delete StateSet->QueueDequeue();
				bounded_bfs_interval_counter = 
					(bounded_bfs_interval_counter + numelts) % 
							args->bounded_bfs_interval.value;
			 	// here the queue must be empty
				return FALSE;
			}
		}
	}
	return FALSE;
}

static void doRwBoundedBfs()
{
	int steps_so_far;
	int interval_counter = 0;
	state *buffer = new state;
	int num_steps_random_walk; // number of steps of each random walk 

	num_steps_random_walk =
				args->total_initial_rw_steps.value/num_random_walks;
	
	#ifdef DEBUG
	cout << MyNode << ": No. of random walks = " << num_random_walks << "\n";
	cout << MyNode << ": No. of steps/rw = " << num_steps_random_walk << "\n";
	cout << MyNode << ": Bounded BFS depth = " << 
						args->bounded_bfs_depth.value << "\n";
	cout << MyNode << ": Bounded BFS interval = " << 
						args->bounded_bfs_interval.value << "\n";
	#endif
	
	if(!args->send_rw.value)
	{
		for(int l = 0; l < num_random_walks; l++)
		{
			StateCopy(workingstate, rw_fronts[l]);
			curstate = workingstate;
			steps_so_far = 0;
			while (steps_so_far < num_steps_random_walk)
			{
				curstate = Rules->RandomNextState();
				// next state generated is unnormalized and invariant checked
				normalize(workingstate);
				steps_so_far++;
				
				mesg_poll();
				// we won't get state messages but we could 
				// get error termination messages
				IfErrorTerminate();
			}
			delete rw_fronts[l];
			rw_fronts[l] = NULL; // this will help in ParallelTerminate
		}
	}
	else // send_rw is true
	{
		for(int l = 0; l < num_random_walks; l++)
		{
			// are these rw_fronts[l] hashed?
			// I guess, they are normalized, hashed and checked for violation
			StateCopy(workingstate, rw_fronts[l]);
			curstate = workingstate;
			steps_so_far = 0;
			while (steps_so_far < num_steps_random_walk)
			{
				if (interval_counter == 0)
				{
					StateCopy(buffer,workingstate);
					Rules->RandomNextState();
					// now next state generated, unnormalized and invariant checked
					
					// point curstate to previous state, 
					// so we can use it for diff hashing
					curstate = buffer;
					// temp_cur == workingstate
					// workingstate normalized within SendState
					SendState(workingstate, TRUE);
				}
				else
				{
					Rules->RandomNextState();
					// now next state generated, unnormalized and invariant checked
					
					// we still need to do normalization
					normalize(workingstate);

					if(interval_counter == (args->send_rw_interval.value - 1))
						h3->hash(workingstate,FALSE);
					// see comment in heuristic1
				}
				interval_counter = (interval_counter+1)%
									args->send_rw_interval.value;

				// now check if we have to do bounded BFS
				if (checkDoBoundedBfs())
				{
					// we don't need the frontier states of the bounded bfs
					// so clear the structures
					BoundedStateSet->Reset();
				}
				steps_so_far++;

				// mesg_poll();
				IfErrorTerminate();
				// we check for error term after every RW step and possibly 
				// a bounded BFS 
			}
			delete rw_fronts[l];
			rw_fronts[l] = NULL;
		}
	}
	
	return;
}

void
AlgorithmManager::heuristic2()
{
	// initial BFS, RW from frontier nodes
	theworld.to_state(NULL); // trick: marks the variables in world
	
	if (IAmMaster())
	{
		doInitialBfs();
		distributeBfsFrontier();
		#ifdef DEBUG
		cout << MyNode << ": Distributed initial BFS frontier states\n";
		#endif
		// reset HT and queue
		if ( !StateSet->QueueIsEmpty() )
		{
			cout << "Master: State queue must be empty here, some problem.\n";
			ParallelTerminate(1);
		}
		// clear up the hash table and queue of the master
		StateSet->Reset();
	}
	while(!start_initial_rw)
	{
		IfErrorTerminate(); 
		// this is to detect if an error has occurred in the Master
		// in the initial BFS phase
		mesg_poll();
	}
	// everyone has received their respective frontier states
	// the frontier states are already normalized and checked for
	// violations
	doRwBoundedBfs();
	PrintFinalResult_Heuristic2();
	return;
}

// rw_fronts is assumed to have num_walks entries
static void doRw(int num_walks, int total_steps /*, bool primorsec*/)
// another parameter to specify primary or secondary RW?
{
	int steps_so_far;
	int interval_counter = 0;
	state *buffer = new state;
	int num_steps_random_walk; // number of steps of each random walk 

	num_steps_random_walk =	total_steps/num_walks;
	
	if(!args->send_rw.value)
	{
		for(int l = 0; l < num_walks; l++)
		{
			StateCopy(workingstate, rw_fronts[l]);
			curstate = workingstate;
			// write this state too to the Trace File?
			steps_so_far = 0;
			while (steps_so_far < num_steps_random_walk)
			{
				curstate = Rules->RandomNextState();
				// next state generated is unnormalized and invariant checked

				// write to TraceFile (prim[l] or sec?)
				
				normalize(workingstate);
				steps_so_far++;

				mesg_poll();
				IfErrorTerminate();
			}
			delete rw_fronts[l];
			rw_fronts[l] = NULL;
			// if sec RW, rewind the sec trace file
		}
	}
	else // send_rw is true
	{
		for(int l = 0; l < num_walks; l++)
		{
			// the frontier states are already normalized (so we can do
			// diff hashing from them) and checked for violations.
			StateCopy(workingstate, rw_fronts[l]);
			curstate = workingstate;
			// write to TraceFile (prim[l] or sec?)
			steps_so_far = 0;
			while (steps_so_far < num_steps_random_walk)
			{
				if (interval_counter == 0)
				{
					StateCopy(buffer,workingstate);
					// move writing state to trace file out of RandomNextState
					// so we can write to various types of files 
					Rules->RandomNextState();

					// Add parent node information: which node,
					// which primary RW # if it is a primary RW
									
					// now next state generated, unnormalized and invariant checked
					
					// point curstate to previous state, 
					// so we can use it for diff hashing
					curstate = buffer;
					// temp_cur == workingstate
					// workingstate normalized within SendState
					SendState(workingstate, TRUE);
				}
				else
				{
					Rules->RandomNextState();
					// now next state generated, unnormalized and invariant checked

					// we still need to do normalization
					normalize(workingstate);
					if(interval_counter == (args->send_rw_interval.value-1))
						h3->hash(workingstate,FALSE);
				}
				
				// write to TraceFile (prim[l] or sec?)

				interval_counter = (interval_counter+1)% 
										args->send_rw_interval.value;
										
				steps_so_far++;

				// mesg_poll();
				IfErrorTerminate();
			}
			delete rw_fronts[l];
			rw_fronts[l] = NULL;
			// rewind sec trace file if that is the case
		}
	}

	delete buffer;
	
	return;
}

static void reconstructRwFronts()
{
	delete [] rw_fronts;
	rw_fronts = new state*[num_final_random_walks];
	size_rw_fronts = num_final_random_walks;
	if (!rw_fronts)
	{
		cout << MyNode 
				<< ": Unable to allocate memory for final RW fronts.\n";
		ParallelTerminate(1);
	}
	int j;
	rw_fronts[0] = StateSet->QueueDequeue();
	for(int i = 1; i < num_final_random_walks; i++)
	{
		for(j = 1; j < final_rw_interval; j++)
			delete StateSet->QueueDequeue();
		rw_fronts[i] = StateSet->QueueDequeue();
	}
	while(!StateSet->QueueIsEmpty())
		delete StateSet->QueueDequeue();
	return;
}

void
AlgorithmManager::heuristic3()
{
	// initial BFS, RW from frontier nodes
	theworld.to_state(NULL); // trick: marks the variables in world

	if (IAmMaster())
	{
		doInitialBfs();
		distributeBfsFrontier();
		#ifdef DEBUG
		cout << MyNode << ": Distributed initial BFS frontier states\n";
		#endif
		// reset HT and queue
		if ( !StateSet->QueueIsEmpty())
		{
			cout << "Master: State queue must be empty here, some problem.\n";
			ParallelTerminate(1);
		}
		StateSet->Reset();
	}
	while(!start_initial_rw)
	{
		IfErrorTerminate();
		mesg_poll();
	}
	// allocate new Primary TraceFiles
	// hard code dir path to be "/tmp" for now here
	// /tmp/protname.trace.p#
	
	doRw(num_random_walks, args->total_initial_rw_steps.value);
	SynchronizeMasterSlave();
	IfErrorTerminateNoSynchronize();

	if(!args->send_rw.value)
	{
		// no states were sent across, so we can't do the second set of RWs
		// If we use this option in Heuristic3, then we this heuristic 
		// translates to doing an initial BFS and then RWs from the frontier
		// states.
		PrintFinalResult_Heuristic2();
		return;
	}
	if (IAmMaster())
	{	
		double before_input = SecondsSinceStart();
		// first receive messages from all slaves till there are no more
		// messages from slave to master
		
		// now get info from user
		cout << "Finished initial RW\n";
		cout << "Total number of states in queue of master: "
				<< StateSet->QueueNumElts() << ".\n";
		// for now, only giving the master's total states in the queue
		// later give the average total states in the queue among all nodes
		cout << "Please enter the interval between the states from which\n"
				<< "you would like to start the final Rw.\n";
		scanf("%d", &final_rw_interval);
		num_final_random_walks = StateSet->QueueNumElts()/final_rw_interval;
		cout << "Number of final random walks: " << num_final_random_walks
							<< ".\n";
		cout << "Please enter the total number of steps for the final Rw.\n";
		scanf("%d", &total_final_rw_steps);

		user_input_time = SecondsSinceStart() - before_input;

		// construct rw_fronts for master
		reconstructRwFronts();
		
		for(int i = 0; i < NumNodes; i++)
		{
			if ( i != MASTER )
			{
				MPI_Send(&final_rw_interval, 1, MPI_INT, i, 
						TAG_FINAL_RW_INTERVAL, MPI_COMM_WORLD);
				MPI_Send(&total_final_rw_steps, 1, MPI_INT, i, 
						TAG_TOTAL_FINAL_RW_STEPS, MPI_COMM_WORLD);
			}
		}
		
	}
	else
	{
		double before_input = SecondsSinceStart();
		while(!start_final_rw)
			mesg_poll();
		user_input_time = SecondsSinceStart() - before_input;
		// now slave has received value for final_rw_interval
		num_final_random_walks = StateSet->QueueNumElts()/
											final_rw_interval;	
		reconstructRwFronts();
	}
	
	// allocate new Secondary TraceFile
	// hard code dir path to be "/tmp" for now here
	// /tmp/protname.trace.s

	doRw(num_final_random_walks, total_final_rw_steps);
	PrintFinalResult_Heuristic2();
	return;
}

static void doRwBoundedBfsFrontier()
{
	int steps_so_far;
	int interval_counter = 0;
	state *buffer = new state;
	int num_steps_random_walk; // number of steps of each random walk 

	num_steps_random_walk =
				args->total_initial_rw_steps.value/num_random_walks;
	
	if(!args->send_rw.value)
	{
		for(int l = 0; l < num_random_walks; l++)
		{
			StateCopy(workingstate, rw_fronts[l]);
			curstate = workingstate;
			steps_so_far = 0;
			while (steps_so_far < num_steps_random_walk)
			{
				curstate = Rules->RandomNextState();
				// next state generated is unnormalized and invariant checked
				normalize(workingstate);
				steps_so_far++;

				mesg_poll();
				IfErrorTerminate();
			}
			delete rw_fronts[l];
			rw_fronts[l] = NULL;
		}
	}
	else // send_rw is true
	{
		for(int l = 0; l < num_random_walks; l++)
		{
			StateCopy(workingstate, rw_fronts[l]);
			curstate = workingstate;
			steps_so_far = 0;
			while (steps_so_far < num_steps_random_walk)
			{
				if (interval_counter == 0)
				{
					StateCopy(buffer,workingstate);
					Rules->RandomNextState();
					// now next state generated, unnormalized and invariant checked

					// point curstate to previous state, 
					// so we can use it for diff hashing
					curstate = buffer;
					// temp_cur == workingstate
					// workingstate normalized within SendState
					SendState(workingstate, TRUE);
				}
				else
				{
					Rules->RandomNextState();
					// now next state generated, unnormalized and invariant checked

					// we still need to do normalization
					normalize(workingstate);
					if(interval_counter == (args->send_rw_interval.value-1))
						h3->hash(workingstate,FALSE);

				}
				interval_counter = (interval_counter+1)%
									args->send_rw_interval.value;

				// now check if we have to do bounded BFS
				if (checkDoBoundedBfs())
				{
					// before resetting the BoundedStateSet, copy the 
					// frontier states to the frontier array
					while(!BoundedStateSet->QueueIsEmpty())
					{
						if (num_elts_frontier_array < max_elts_frontier_array)
							frontier_array[num_elts_frontier_array++]
									= BoundedStateSet->QueueDequeue();
						else
						{
							cout << "Node: " << MyNode << 
									", frontier array has become full.\n";
							cout << "Increase the fracfrontsize parameter.\n";
							while(!BoundedStateSet->QueueIsEmpty())
								delete BoundedStateSet->QueueDequeue();
						}
					}
					BoundedStateSet->Reset();
				}
				steps_so_far++;

				// mesg_poll();
				IfErrorTerminate();
			}
			delete rw_fronts[l];
			rw_fronts[l] = NULL;
		}
	}
	return;
}

static void reconstructRwFrontsFrontier()
{
	delete [] rw_fronts;
	rw_fronts = new state*[num_final_random_walks];
	size_rw_fronts = num_final_random_walks;
	if (!rw_fronts)
	{
		cout << MyNode 
				<< ": Unable to allocate memory for final RW fronts.\n";
		ParallelTerminate(1);
	}
	int j;
	unsigned long curr = 0UL;
	rw_fronts[0] = frontier_array[curr++];
	for(int i = 1; i < num_final_random_walks; i++)
	{
		for(j = 1; j < final_rw_interval; j++)
		{
			delete frontier_array[curr++];
			frontier_array[curr-1] = NULL; // used in ParallelTerminate
		}
		rw_fronts[i] = frontier_array[curr++];
	}
	while(curr < max_elts_frontier_array)
	{
		delete frontier_array[curr++];
		frontier_array[curr-1] = NULL;
	}
	
	return;
}

void
AlgorithmManager::heuristic4()
{
	// initial BFS, RW from frontier nodes
	theworld.to_state(NULL); // trick: marks the variables in world
	
	if (IAmMaster())
	{
		doInitialBfs();
		distributeBfsFrontier();
		// reset HT and queue
		if ( !StateSet->QueueIsEmpty() )
		{
			cout << "Master: State queue must be empty here, some problem.\n";
			ParallelTerminate(1);
		}
		// clear up the hash table and queue of the master
		StateSet->Reset();
	}
	while(!start_initial_rw)
	{
		IfErrorTerminate();
		mesg_poll();
	}
	// everyone has received their respective frontier states
	// the frontier states are already normalized and checked for
	// violations
	doRwBoundedBfsFrontier();
	SynchronizeMasterSlave();
	IfErrorTerminateNoSynchronize();
  	if(!args->send_rw.value)
	{
		// no states were sent across, so we can't do the second set of RWs
		// Heuristic 4 now reduces to Heuristic 2.
		PrintFinalResult_Heuristic2();
		return;
	}
	if (IAmMaster())
	{	
		double begin_input = SecondsSinceStart();
		// get info from user
		cout << "Finished initial RW\n";
		cout << "Total number of frontier states in master: "
				<< num_elts_frontier_array << ".\n";
		// for now, only giving the master's frontier states
		// later give the average frontier states among all nodes
		cout << "Please enter the interval between the states from which\n"
				<< "you would like to start the final Rw.\n";
		scanf("%d", &final_rw_interval);
		num_final_random_walks = num_elts_frontier_array/final_rw_interval;
		cout << "Number of final random walks: " << num_final_random_walks
							<< ".\n";
		cout << "Please enter the total number of steps for the final Rw.\n";
		scanf("%d", &total_final_rw_steps);
		
		user_input_time = SecondsSinceStart() - begin_input;
		
		// construct rw_fronts for master
		reconstructRwFrontsFrontier();
		
		for(int i = 0; i < NumNodes; i++)
		{
			if ( i != MASTER )
			{
				MPI_Send(&final_rw_interval, 1, MPI_INT, i, 
						TAG_FINAL_RW_INTERVAL, MPI_COMM_WORLD);
				MPI_Send(&total_final_rw_steps, 1, MPI_INT, i, 
						TAG_TOTAL_FINAL_RW_STEPS, MPI_COMM_WORLD);
			}
		}
		
	}
	else
	{
		double begin_input = SecondsSinceStart();
		while(!start_final_rw)
			mesg_poll();
		user_input_time = SecondsSinceStart() - begin_input;
		// here value of final_rw_interval has been received by slave
		num_final_random_walks = num_elts_frontier_array/final_rw_interval;
		reconstructRwFrontsFrontier();
	}

	doRw(num_final_random_walks, total_final_rw_steps);	
	PrintFinalResult_Heuristic2();
	return;
}

/********************
  $Log: mu_system.C,v $
  Revision 1.4  1996/08/07 18:54:33  ip
  last bug fix on NextRule/SetNextEnabledRule has a bug; fixed this turn

  Revision 1.3  1996/08/07 01:07:55  ip
  Fixed bug on what_rule setting during guard evaluation; otherwise, bad diagnoistic message on undefine error on guard

  Revision 1.2  1996/08/07 00:15:26  ip
  fixed while code generation bug

  Revision 1.1  1996/08/07 00:14:46  ip
  Initial revision

********************/
