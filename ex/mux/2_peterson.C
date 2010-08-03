/******************************
  Program "2_peterson.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "2_peterson"
#define BITS_IN_WORLD 12
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_pid: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_pid& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_pid& val)
    {
      if (val.defined())
        return ( s << mu_1_pid::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_pid (char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu_1_pid (void): mu__byte(1, 2, 2) {};
  mu_1_pid (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_pid& a, mu_1_pid& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_pid::values[] =
  { "pid_1","pid_2",NULL };

/*** end scalarset declaration ***/
mu_1_pid mu_1_pid_undefined_var;

class mu_1_label_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_label_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_label_t& val)
  {
    if (val.defined())
      return ( s << mu_1_label_t::values[ int(val) - 3] );
    else return ( s << "Undefined" );
  };

  mu_1_label_t (char *name, int os): mu__byte(3, 7, 3, name, os) {};
  mu_1_label_t (void): mu__byte(3, 7, 3) {};
  mu_1_label_t (int val): mu__byte(3, 7, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -3]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -3] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_label_t::values[] = {"L0","L1","L2","L3","L4",NULL };

/*** end of enum declaration ***/
mu_1_label_t mu_1_label_t_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_label_t array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_0 (char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_label_t& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 2 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: pid is internally represented from 2 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_0::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"pid_1", i * 3 + os);i++;
array[i].set_self_ar(n,"pid_2", i * 3 + os);i++;
}
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1
{
 public:
  mu_0_boolean array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 2 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: pid is internally represented from 2 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_1::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"pid_1", i * 2 + os);i++;
array[i].set_self_ar(n,"pid_2", i * 2 + os);i++;
}
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

const int mu_N = 2;
const int mu_pid_1 = 1;
const int mu_pid_2 = 2;
const int mu_L0 = 3;
const int mu_L1 = 4;
const int mu_L2 = 5;
const int mu_L3 = 6;
const int mu_L4 = 7;
/*** Variable declaration ***/
mu_1__type_0 mu_P("P",0);

/*** Variable declaration ***/
mu_1__type_1 mu_Q("Q",6);

/*** Variable declaration ***/
mu_1_pid mu_turn("turn",10);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_P.clear();
  mu_Q.clear();
  mu_turn.clear();
}
void world_class::undefine()
{
  mu_P.undefine();
  mu_Q.undefine();
  mu_turn.undefine();
}
void world_class::reset()
{
  mu_P.reset();
  mu_Q.reset();
  mu_turn.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_P.print();
  mu_Q.print();
  mu_turn.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_P.print_statistic();
  mu_Q.print_statistic();
  mu_turn.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_P.print_diff(prevstate);
    mu_Q.print_diff(prevstate);
    mu_turn.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_P.to_state( newstate );
  mu_Q.to_state( newstate );
  mu_turn.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("execute assign Qi false, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
  return (mu_P[mu_i]) == (mu_L4);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 2 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L4)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 0;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
mu_Q[mu_i] = mu_false;
mu_P[mu_i] = mu_L0;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("execute critical section, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
  return (mu_P[mu_i]) == (mu_L3);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 4 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L3)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 2;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
mu_P[mu_i] = mu_L4;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_j;
    mu_j.value((r % 2) + 1);
    r = r / 2;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("execute wait until, j:%s, i:%s", mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_j;
    mu_j.value((r % 2) + 1);
    r = r / 2;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
bool mu__boolexpr2;
  if (!((mu_P[mu_i]) == (mu_L2))) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = ((mu_j) != (mu_i)) ; 
}
  return mu__boolexpr2;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu_1_pid mu_j;
    mu_j.value((r % 2) + 1);
    r = r / 2;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 8 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr3;
  if (!((mu_P[mu_i]) == (mu_L2))) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_j) != (mu_i)) ; 
}
              if (mu__boolexpr3) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 4;
    mu_j.value((r % 2) + 1);
    r = r / 2;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_j;
    mu_j.value((r % 2) + 1);
    r = r / 2;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
bool mu__boolexpr4;
  if (!(mu_Q[mu_j])) mu__boolexpr4 = TRUE ;
  else {
  mu__boolexpr4 = ((mu_turn) == (mu_j)) ; 
}
if ( mu__boolexpr4 )
{
mu_P[mu_i] = mu_L3;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("execute assign turn i, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
  return (mu_P[mu_i]) == (mu_L1);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 10 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L1)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 8;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
mu_turn = mu_i;
mu_P[mu_i] = mu_L2;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("execute assign Qi true, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
  return (mu_P[mu_i]) == (mu_L0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 10;
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L0)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 10;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
mu_Q[mu_i] = mu_true;
mu_P[mu_i] = mu_L1;
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<2)
    { R0.NextRule(what_rule);
      if (what_rule<2) return; }
  if (what_rule>=2 && what_rule<4)
    { R1.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<8)
    { R2.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<10)
    { R3.NextRule(what_rule);
      if (what_rule<10) return; }
  if (what_rule>=10 && what_rule<12)
    { R4.NextRule(what_rule);
      if (what_rule<12) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=1) return R0.Condition(r-0);
  if (r>=2 && r<=3) return R1.Condition(r-2);
  if (r>=4 && r<=7) return R2.Condition(r-4);
  if (r>=8 && r<=9) return R3.Condition(r-8);
  if (r>=10 && r<=11) return R4.Condition(r-10);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=1) { R0.Code(r-0); return; } 
  if (r>=2 && r<=3) { R1.Code(r-2); return; } 
  if (r>=4 && r<=7) { R2.Code(r-4); return; } 
  if (r>=8 && r<=9) { R3.Code(r-8); return; } 
  if (r>=10 && r<=11) { R4.Code(r-10); return; } 
}
int Priority(unsigned short r)
{
  if (r<=1) { return R0.Priority(); } 
  if (r>=2 && r<=3) { return R1.Priority(); } 
  if (r>=4 && r<=7) { return R2.Priority(); } 
  if (r>=8 && r<=9) { return R3.Priority(); } 
  if (r>=10 && r<=11) { return R4.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=1) return R0.Name(r-0);
  if (r>=2 && r<=3) return R1.Name(r-2);
  if (r>=4 && r<=7) return R2.Name(r-4);
  if (r>=8 && r<=9) return R3.Name(r-8);
  if (r>=10 && r<=11) return R4.Name(r-10);
  return NULL;
}
};
const unsigned numrules = 12;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 12


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("Startstate 0, i:%s", mu_i.Name());
  }
  void Code(unsigned short r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 2) + 1);
    r = r / 2;
{
for(int mu_k = 1; mu_k <= 2; mu_k++) {
mu_P[mu_k] = mu_L0;
mu_Q[mu_k] = mu_false;
};
};
mu_turn = mu_i;
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=1) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=1) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 2;

/********************
  Invariant records
 ********************/
int mu__invariant_5() // Invariant "mutual exclusion"
{
bool mu__quant6; 
mu__quant6 = FALSE;
{
for(int mu_i1 = 1; mu_i1 <= 2; mu_i1++) {
bool mu__quant7; 
mu__quant7 = FALSE;
{
for(int mu_i2 = 1; mu_i2 <= 2; mu_i2++) {
bool mu__boolexpr8;
bool mu__boolexpr9;
  if (!((mu_i1) != (mu_i2))) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_P[mu_i1]) == (mu_L3)) ; 
}
  if (!(mu__boolexpr9)) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_P[mu_i2]) == (mu_L3)) ; 
}
if ( (mu__boolexpr8) )
  { mu__quant7 = TRUE; break; }
};
};
if ( (mu__quant7) )
  { mu__quant6 = TRUE; break; }
};
};
return !(mu__quant6);
};

bool mu__condition_10() // Condition for Rule "mutual exclusion"
{
  return mu__invariant_5( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"mutual exclusion", &mu__condition_10, NULL, FALSE},
};
const unsigned short numinvariants = 1;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
turn:ScalarsetVariable
Q:ScalarsetArrayOfFree
P:ScalarsetArrayOfFree
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_pid[2];
  int undefined_class_mu_1_pid;// has the highest class number

  void Print_class_mu_1_pid();
  bool OnlyOneRemain_mu_1_pid;
  bool MTO_class_mu_1_pid()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_pid)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_pid[i]== class_mu_1_pid[j])
	    return TRUE;
    OnlyOneRemain_mu_1_pid = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_pid;
  typedef int arr_mu_1_pid[2];
  arr_mu_1_pid * perm_mu_1_pid;
  arr_mu_1_pid * revperm_mu_1_pid;

  int size_mu_1_pid[2];
  bool reversed_sorted_mu_1_pid(int start, int end);
  void reverse_reversed_mu_1_pid(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_pid* perm, int size, mu_1_pid k);
  void GenPerm0(mu_1_pid* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_pid()
{
  cout << "class_mu_1_pid:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_pid[i];
  cout << " " << undefined_class_mu_1_pid << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_pid[i]== class_mu_1_pid[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
    mu_1_pid Perm0[2];

  /********************
   declaration of class variables
  ********************/
  in = new bool[2];
 in_mu_1_pid = new int[2];
 perm_mu_1_pid = new arr_mu_1_pid[2];
 revperm_mu_1_pid = new arr_mu_1_pid[2];

    // Set perm and revperm
    count = 0;
    for (i=1; i<=2; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=1; j<=2; j++)
        for (k=1; k<=2; k++)
          if (revperm_mu_1_pid[i][k-1]==j)   // k - base 
            perm_mu_1_pid[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_pid = 0;
    size = 2;
    count = 2;
    for (i=0; i<2; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_pid[i] = i_mu_1_pid;
      i_mu_1_pid += carry;
      if (i_mu_1_pid >= 2) { i_mu_1_pid = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_pid = new int[1];
 perm_mu_1_pid = new arr_mu_1_pid[1];
 revperm_mu_1_pid = new arr_mu_1_pid[1];
  in[0] = TRUE;
    in_mu_1_pid[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_pid[i]=0;
  undefined_class_mu_1_pid=0;
  OnlyOneRemain_mu_1_pid = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<2; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_pid[2];
  int size_mu_1_pid[2];
  bool should_be_in_mu_1_pid[2];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_pid; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  {
	    size_mu_1_pid[k] = class_size;
	    start_mu_1_pid[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_pid[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_pid[i][k]-1 >=start_mu_1_pid[k] 
	     && perm_mu_1_pid[i][k]-1 < start_mu_1_pid[k] + size_mu_1_pid[k]) )
  	    {
	      should_be_in_mu_1_pid[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<2; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_pid[in_mu_1_pid[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_pid; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  {
	    size_mu_1_pid[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_pid; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_pid[k]==j)
	      revperm_mu_1_pid[0][start++] = k+1;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_pid[0][k]==j+1)
        perm_mu_1_pid[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_pid* Perm, int size, mu_1_pid k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_pid* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=1; i<=2; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=2; i++)
        revperm_mu_1_pid[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_pid(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_pid[0][i]<revperm_mu_1_pid[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_pid(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_pid[0][j];
      revperm_mu_1_pid[0][j] = revperm_mu_1_pid[0][i];
      revperm_mu_1_pid[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 2; )
    {
      end = start-1+size_mu_1_pid[revperm_mu_1_pid[0][start]-1];
      if (reversed_sorted_mu_1_pid(start,end))
	       {
	  reverse_reversed_mu_1_pid(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_pid(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_pid[0][j]<revperm_mu_1_pid[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_pid[0][j];
			  revperm_mu_1_pid[0][j] = revperm_mu_1_pid[0][k];
			  revperm_mu_1_pid[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_pid(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_pid[0][k]==j+1)   // k - base 
	perm_mu_1_pid[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_turn.MultisetSort();
        mu_Q.MultisetSort();
        mu_P.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_pid::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_pid[Perm.in_mu_1_pid[i]][value()-1]); // value - base
};
void mu_1_pid::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_pid[value()-1]==Perm.undefined_class_mu_1_pid) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_pid[i] == Perm.undefined_class_mu_1_pid && i!=value()-1)
            Perm.class_mu_1_pid[i]++;
        value(1 + Perm.undefined_class_mu_1_pid++);
      }
    else 
      {
        value(Perm.class_mu_1_pid[value()-1]+1);
      }
}
void mu_1_pid::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_pid::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_pid[value()-1]==Perm.undefined_class_mu_1_pid) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_pid[i] == Perm.undefined_class_mu_1_pid && i!=value()-1)
            Perm.class_mu_1_pid[i]++;
        Perm.undefined_class_mu_1_pid++;
      }
}
void mu_1_pid::ArrayLimit(PermSet& Perm) {}
void mu_1_pid::Limit(PermSet& Perm) {}
void mu_1_pid::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_label_t::Permute(PermSet& Perm, int i) {};
void mu_1_label_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_label_t::Canonicalize(PermSet& Perm) {};
void mu_1_label_t::SimpleLimit(PermSet& Perm) {};
void mu_1_label_t::ArrayLimit(PermSet& Perm) {};
void mu_1_label_t::Limit(PermSet& Perm) {};
void mu_1_label_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=2; j++)
     (*this)[j].value(temp[Perm.revperm_mu_1_pid[Perm.in_mu_1_pid[i]][j-1]].value());};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_pid;
  int compare;
  static mu_1_label_t value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[2];
  bool pos_mu_1_pid[2][2];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_pid[2];
  int start_mu_1_pid[2];
  // canonicalization
  static mu_1__type_0 temp;
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_pid; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_pid[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_pid; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j].value((*this)[i+1].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
                value[j].value((*this)[i+1].value());
              for (z=0; z<2; z++)
                pos_mu_1_pid[j][z] = FALSE;
              pos_mu_1_pid[j][i] = TRUE;
              count_mu_1_pid++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_pid[k]>j
                            || ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) )
                          Perm.class_mu_1_pid[k]++;
                      Perm.undefined_class_mu_1_pid++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_pid())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_pid; j++) // class number
        {
          class_size = 0;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_pid[k]==j)
              class_size++;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_pid[k]==j)
              {
                size_mu_1_pid[k] = class_size;
                start_mu_1_pid[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
         if (i >=start_mu_1_pid[j] 
             && i < start_mu_1_pid[j] + size_mu_1_pid[j])
           {
             array[i+0].value(temp[j+1].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<2; j++)
        array[Perm.class_mu_1_pid[j]+0].value(temp[j+1].value());
    }
}
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_pid;
  int compare;
  static mu_1_label_t value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[2];
  bool pos_mu_1_pid[2][2];
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_pid; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_pid[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_pid; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j].value((*this)[i+1].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
                value[j].value((*this)[i+1].value());
              for (z=0; z<2; z++)
                pos_mu_1_pid[j][z] = FALSE;
              pos_mu_1_pid[j][i] = TRUE;
              count_mu_1_pid++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_pid[k]>j
                            || ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) )
                          Perm.class_mu_1_pid[k]++;
                      Perm.undefined_class_mu_1_pid++;
                    }
                }
            }
        }
    }
}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=2; j++)
     (*this)[j].value(temp[Perm.revperm_mu_1_pid[Perm.in_mu_1_pid[i]][j-1]].value());};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_pid;
  int compare;
  static mu_0_boolean value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[2];
  bool pos_mu_1_pid[2][2];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_pid[2];
  int start_mu_1_pid[2];
  // canonicalization
  static mu_1__type_1 temp;
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_pid; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_pid[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_pid; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j].value((*this)[i+1].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
                value[j].value((*this)[i+1].value());
              for (z=0; z<2; z++)
                pos_mu_1_pid[j][z] = FALSE;
              pos_mu_1_pid[j][i] = TRUE;
              count_mu_1_pid++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_pid[k]>j
                            || ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) )
                          Perm.class_mu_1_pid[k]++;
                      Perm.undefined_class_mu_1_pid++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_pid())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_pid; j++) // class number
        {
          class_size = 0;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_pid[k]==j)
              class_size++;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_pid[k]==j)
              {
                size_mu_1_pid[k] = class_size;
                start_mu_1_pid[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
         if (i >=start_mu_1_pid[j] 
             && i < start_mu_1_pid[j] + size_mu_1_pid[j])
           {
             array[i+0].value(temp[j+1].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<2; j++)
        array[Perm.class_mu_1_pid[j]+0].value(temp[j+1].value());
    }
}
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_pid;
  int compare;
  static mu_0_boolean value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[2];
  bool pos_mu_1_pid[2][2];
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_pid; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_pid[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_pid; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<2; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j].value((*this)[i+1].value());
                  for (z=0; z<2; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
                value[j].value((*this)[i+1].value());
              for (z=0; z<2; z++)
                pos_mu_1_pid[j][z] = FALSE;
              pos_mu_1_pid[j][i] = TRUE;
              count_mu_1_pid++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_pid[k]>j
                            || ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) )
                          Perm.class_mu_1_pid[k]++;
                      Perm.undefined_class_mu_1_pid++;
                    }
                }
            }
        }
    }
}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_turn.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_turn.MultisetSort();
              mu_Q.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Q.MultisetSort();
              mu_P.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_P.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_turn.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_turn.MultisetSort();
          mu_Q.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Q.MultisetSort();
          mu_P.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_P.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_turn.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_turn.MultisetSort();
              mu_Q.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Q.MultisetSort();
              mu_P.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_P.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_turn.MultisetSort();
      mu_Q.MultisetSort();
      mu_P.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_turn.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_turn.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Q.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Q.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_P.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_P.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_turn.SimpleCanonicalize(Perm);

  mu_Q.Canonicalize(Perm);

  mu_P.Canonicalize(Perm);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_turn.SimpleCanonicalize(Perm);

  mu_Q.Canonicalize(Perm);

  mu_P.Canonicalize(Perm);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_turn.SimpleCanonicalize(Perm);

  mu_Q.Canonicalize(Perm);

  mu_P.Canonicalize(Perm);

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
