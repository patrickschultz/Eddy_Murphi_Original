/******************************
  Program "dpnew.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "dpnew"
#define BITS_IN_WORLD 21
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Phil_ID: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Phil_ID& val) { return mu__byte::operator=((int) val); };
  mu_1_Phil_ID (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_Phil_ID (void): mu__byte(0, 2, 2) {};
  mu_1_Phil_ID (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_Phil_ID mu_1_Phil_ID_undefined_var;

class mu_1_side: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_side& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_side& val)
  {
    if (val.defined())
      return ( s << mu_1_side::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_side (char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu_1_side (void): mu__byte(1, 2, 2) {};
  mu_1_side (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -1]; };
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
      cout << name << ":" << values[ value() -1] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_side::values[] = {"left","right",NULL };

/*** end of enum declaration ***/
mu_1_side mu_1_side_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 3] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(3, 6, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(3, 6, 3) {};
  mu_1__type_0 (int val): mu__byte(3, 6, 3, "Parameter or function result.", 0)
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

char *mu_1__type_0::values[] = {"think","take","eat","release",NULL };

/*** end of enum declaration ***/
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
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
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
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
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

array[i].set_self_ar(n,"left", i * 2 + os);i++;
array[i].set_self_ar(n,"right", i * 2 + os);i++;
  }
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_Status;
  mu_1__type_1 mu_Got_Forks;
  mu_1__type_2 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_2 ( void ) {};

  virtual ~mu_1__type_2(); 
friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = CompareWeight(a.mu_Status, b.mu_Status);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Got_Forks, b.mu_Got_Forks);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = Compare(a.mu_Status, b.mu_Status);
    if (w!=0) return w;
    w = Compare(a.mu_Got_Forks, b.mu_Got_Forks);
    if (w!=0) return w;
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
    mu_Status.MultisetSort();
    mu_Got_Forks.MultisetSort();
  }
  void print_statistic()
  {
    mu_Status.print_statistic();
    mu_Got_Forks.print_statistic();
  }
  void clear() {
    mu_Status.clear();
    mu_Got_Forks.clear();
 };
  void undefine() {
    mu_Status.undefine();
    mu_Got_Forks.undefine();
 };
  void reset() {
    mu_Status.reset();
    mu_Got_Forks.reset();
 };
  void print() {
    mu_Status.print();
    mu_Got_Forks.print();
  };
  void print_diff(state *prevstate) {
    mu_Status.print_diff(prevstate);
    mu_Got_Forks.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Status.to_state(thestate);
    mu_Got_Forks.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_2& operator= (const mu_1__type_2& from) {
    mu_Status.value(from.mu_Status.value());
    mu_Got_Forks = from.mu_Got_Forks;
    return *this;
  };
};

  void mu_1__type_2::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self(char *n, int os)
{
  name = n;
  mu_Status.set_self_2(name, ".Status", os + 0 );
  mu_Got_Forks.set_self_2(name, ".Got_Forks", os + 3 );
}

mu_1__type_2::~mu_1__type_2()
{
}

/*** end record declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1__type_2 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1__type_2& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 7 + os);
    delete[] s;
  }
};
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

const int mu_N = 3;
const int mu_option = 1;
const int mu_left = 1;
const int mu_right = 2;
const int mu_think = 3;
const int mu_take = 4;
const int mu_eat = 5;
const int mu_release = 6;
/*** Variable declaration ***/
mu_1__type_3 mu_Philosophers("Philosophers",0);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_Philosophers.clear();
}
void world_class::undefine()
{
  mu_Philosophers.undefine();
}
void world_class::reset()
{
  mu_Philosophers.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Philosophers.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Philosophers.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_Philosophers.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_Philosophers.to_state( newstate );
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
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("start thinking, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr4;
  if (!((mu_p.mu_Status) == (mu_release))) mu__boolexpr4 = FALSE ;
  else {
bool mu__quant5; 
mu__quant5 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !((mu_p.mu_Got_Forks[mu_s]) == (mu_false)) )
  { mu__quant5 = FALSE; break; }
};
};
  mu__boolexpr4 = (mu__quant5) ; 
}
  return mu__boolexpr4;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr6;
  if (!((mu_p.mu_Status) == (mu_release))) mu__boolexpr6 = FALSE ;
  else {
bool mu__quant7; 
mu__quant7 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !((mu_p.mu_Got_Forks[mu_s]) == (mu_false)) )
  { mu__quant7 = FALSE; break; }
};
};
  mu__boolexpr6 = (mu__quant7) ; 
}
              if (mu__boolexpr6) {
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
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Status = mu_think;
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
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("release right fork, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
  return (mu_p.mu_Status) == (mu_release);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 6 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
              if ((mu_p.mu_Status) == (mu_release)) {
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
    r = what_rule - 3;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Got_Forks[mu_right] = mu_false;
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
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("release left fork, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
  return (mu_p.mu_Status) == (mu_release);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 6;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 9 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
              if ((mu_p.mu_Status) == (mu_release)) {
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
    r = what_rule - 6;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Got_Forks[mu_left] = mu_false;
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
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("finished eating, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
  return (mu_p.mu_Status) == (mu_eat);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 9;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
              if ((mu_p.mu_Status) == (mu_eat)) {
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
    r = what_rule - 9;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Status = mu_release;
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
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("take both fork, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr8;
bool mu__boolexpr9;
  if (!(0)) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_p.mu_Status) == (mu_take)) ; 
}
  if (!(mu__boolexpr9)) mu__boolexpr8 = FALSE ;
  else {
bool mu__quant10; 
mu__quant10 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !(!(mu_p.mu_Got_Forks[mu_s])) )
  { mu__quant10 = FALSE; break; }
};
};
  mu__boolexpr8 = (mu__quant10) ; 
}
  return mu__boolexpr8;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 15 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr11;
bool mu__boolexpr12;
  if (!(0)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_p.mu_Status) == (mu_take)) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
bool mu__quant13; 
mu__quant13 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !(!(mu_p.mu_Got_Forks[mu_s])) )
  { mu__quant13 = FALSE; break; }
};
};
  mu__boolexpr11 = (mu__quant13) ; 
}
              if (mu__boolexpr11) {
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
    r = what_rule - 12;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr14;
  if (!(!(mu_Philosophers[((mu_ID) == (0)) ? (2) : ((mu_ID) - (1))].mu_Got_Forks[mu_left]))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = (!(mu_Philosophers[((mu_ID) == (2)) ? (0) : ((mu_ID) + (1))].mu_Got_Forks[mu_right])) ; 
}
if ( mu__boolexpr14 )
{
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
mu_p.mu_Got_Forks[mu_s] = mu_true;
};
};
mu_p.mu_Status = mu_eat;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("start eating if got both forks, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr15;
  if (!(1)) mu__boolexpr15 = FALSE ;
  else {
bool mu__quant16; 
mu__quant16 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !(mu_p.mu_Got_Forks[mu_s]) )
  { mu__quant16 = FALSE; break; }
};
};
  mu__boolexpr15 = (mu__quant16) ; 
}
  return mu__boolexpr15;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 15;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 18 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr17;
  if (!(1)) mu__boolexpr17 = FALSE ;
  else {
bool mu__quant18; 
mu__quant18 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !(mu_p.mu_Got_Forks[mu_s]) )
  { mu__quant18 = FALSE; break; }
};
};
  mu__boolexpr17 = (mu__quant18) ; 
}
              if (mu__boolexpr17) {
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
    r = what_rule - 15;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Status = mu_eat;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("take right fork, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr19;
bool mu__boolexpr20;
  if (!(1)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_p.mu_Status) == (mu_take)) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_p.mu_Got_Forks[mu_right]) == (mu_false)) ; 
}
  return mu__boolexpr19;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 18;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 21 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr21;
bool mu__boolexpr22;
  if (!(1)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_p.mu_Status) == (mu_take)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_p.mu_Got_Forks[mu_right]) == (mu_false)) ; 
}
              if (mu__boolexpr21) {
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
    r = what_rule - 18;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
if ( !(mu_Philosophers[((mu_ID) == (0)) ? (2) : ((mu_ID) - (1))].mu_Got_Forks[mu_left]) )
{
mu_p.mu_Got_Forks[mu_right] = mu_true;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("take left fork, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr23;
bool mu__boolexpr24;
  if (!(1)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_p.mu_Status) == (mu_take)) ; 
}
  if (!(mu__boolexpr24)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_p.mu_Got_Forks[mu_left]) == (mu_false)) ; 
}
  return mu__boolexpr23;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 24 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr25;
bool mu__boolexpr26;
  if (!(1)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_p.mu_Status) == (mu_take)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_p.mu_Got_Forks[mu_left]) == (mu_false)) ; 
}
              if (mu__boolexpr25) {
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
    r = what_rule - 21;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
if ( !(mu_Philosophers[((mu_ID) == (2)) ? (0) : ((mu_ID) + (1))].mu_Got_Forks[mu_right]) )
{
mu_p.mu_Got_Forks[mu_left] = mu_true;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("stop thinking and sit if ok, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr27;
bool mu__boolexpr28;
  if (!(0)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_p.mu_Status) == (mu_think)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
bool mu__quant29; 
mu__quant29 = FALSE;
{
for(int mu_ID1 = 0; mu_ID1 <= 2; mu_ID1++) {
bool mu__boolexpr30;
  if (!((mu_ID1) != (mu_ID))) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_Philosophers[mu_ID1].mu_Status) == (mu_think)) ; 
}
if ( (mu__boolexpr30) )
  { mu__quant29 = TRUE; break; }
};
};
  mu__boolexpr27 = (mu__quant29) ; 
}
  return mu__boolexpr27;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 24;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 27 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr31;
bool mu__boolexpr32;
  if (!(0)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_p.mu_Status) == (mu_think)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
bool mu__quant33; 
mu__quant33 = FALSE;
{
for(int mu_ID1 = 0; mu_ID1 <= 2; mu_ID1++) {
bool mu__boolexpr34;
  if (!((mu_ID1) != (mu_ID))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_Philosophers[mu_ID1].mu_Status) == (mu_think)) ; 
}
if ( (mu__boolexpr34) )
  { mu__quant33 = TRUE; break; }
};
};
  mu__boolexpr31 = (mu__quant33) ; 
}
              if (mu__boolexpr31) {
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
    r = what_rule - 24;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Status = mu_take;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("stop thinking and sit, ID:%s", mu_ID.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr35;
  if (!(1)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_p.mu_Status) == (mu_think)) ; 
}
  return mu__boolexpr35;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 27;
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 30 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
bool mu__boolexpr36;
  if (!(1)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_p.mu_Status) == (mu_think)) ; 
}
              if (mu__boolexpr36) {
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
    r = what_rule - 27;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Phil_ID mu_ID;
    mu_ID.value((r % 3) + 0);
    r = r / 3;
  mu_1__type_2& mu_p = mu_Philosophers[mu_ID];
mu_p.mu_Status = mu_take;
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
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<3)
    { R0.NextRule(what_rule);
      if (what_rule<3) return; }
  if (what_rule>=3 && what_rule<6)
    { R1.NextRule(what_rule);
      if (what_rule<6) return; }
  if (what_rule>=6 && what_rule<9)
    { R2.NextRule(what_rule);
      if (what_rule<9) return; }
  if (what_rule>=9 && what_rule<12)
    { R3.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<15)
    { R4.NextRule(what_rule);
      if (what_rule<15) return; }
  if (what_rule>=15 && what_rule<18)
    { R5.NextRule(what_rule);
      if (what_rule<18) return; }
  if (what_rule>=18 && what_rule<21)
    { R6.NextRule(what_rule);
      if (what_rule<21) return; }
  if (what_rule>=21 && what_rule<24)
    { R7.NextRule(what_rule);
      if (what_rule<24) return; }
  if (what_rule>=24 && what_rule<27)
    { R8.NextRule(what_rule);
      if (what_rule<27) return; }
  if (what_rule>=27 && what_rule<30)
    { R9.NextRule(what_rule);
      if (what_rule<30) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=2) return R0.Condition(r-0);
  if (r>=3 && r<=5) return R1.Condition(r-3);
  if (r>=6 && r<=8) return R2.Condition(r-6);
  if (r>=9 && r<=11) return R3.Condition(r-9);
  if (r>=12 && r<=14) return R4.Condition(r-12);
  if (r>=15 && r<=17) return R5.Condition(r-15);
  if (r>=18 && r<=20) return R6.Condition(r-18);
  if (r>=21 && r<=23) return R7.Condition(r-21);
  if (r>=24 && r<=26) return R8.Condition(r-24);
  if (r>=27 && r<=29) return R9.Condition(r-27);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=2) { R0.Code(r-0); return; } 
  if (r>=3 && r<=5) { R1.Code(r-3); return; } 
  if (r>=6 && r<=8) { R2.Code(r-6); return; } 
  if (r>=9 && r<=11) { R3.Code(r-9); return; } 
  if (r>=12 && r<=14) { R4.Code(r-12); return; } 
  if (r>=15 && r<=17) { R5.Code(r-15); return; } 
  if (r>=18 && r<=20) { R6.Code(r-18); return; } 
  if (r>=21 && r<=23) { R7.Code(r-21); return; } 
  if (r>=24 && r<=26) { R8.Code(r-24); return; } 
  if (r>=27 && r<=29) { R9.Code(r-27); return; } 
}
int Priority(unsigned short r)
{
  if (r<=2) { return R0.Priority(); } 
  if (r>=3 && r<=5) { return R1.Priority(); } 
  if (r>=6 && r<=8) { return R2.Priority(); } 
  if (r>=9 && r<=11) { return R3.Priority(); } 
  if (r>=12 && r<=14) { return R4.Priority(); } 
  if (r>=15 && r<=17) { return R5.Priority(); } 
  if (r>=18 && r<=20) { return R6.Priority(); } 
  if (r>=21 && r<=23) { return R7.Priority(); } 
  if (r>=24 && r<=26) { return R8.Priority(); } 
  if (r>=27 && r<=29) { return R9.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=2) return R0.Name(r-0);
  if (r>=3 && r<=5) return R1.Name(r-3);
  if (r>=6 && r<=8) return R2.Name(r-6);
  if (r>=9 && r<=11) return R3.Name(r-9);
  if (r>=12 && r<=14) return R4.Name(r-12);
  if (r>=15 && r<=17) return R5.Name(r-15);
  if (r>=18 && r<=20) return R6.Name(r-18);
  if (r>=21 && r<=23) return R7.Name(r-21);
  if (r>=24 && r<=26) return R8.Name(r-24);
  if (r>=27 && r<=29) return R9.Name(r-27);
  return NULL;
}
};
const unsigned numrules = 30;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 30


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_ID = 0; mu_ID <= 2; mu_ID++) {
mu_Philosophers[mu_ID].mu_Status = mu_think;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
mu_Philosophers[mu_ID].mu_Got_Forks[mu_s] = mu_false;
};
};
};
};
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
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_37() // Invariant "A fork is used by upto one philosophers only"
{
bool mu__boolexpr38;
bool mu__quant39; 
mu__quant39 = TRUE;
{
for(int mu_ID = 0; mu_ID <= 2; mu_ID++) {
bool mu__boolexpr40;
  if (!(mu_Philosophers[mu_ID].mu_Got_Forks[mu_left])) mu__boolexpr40 = TRUE ;
  else {
  mu__boolexpr40 = (!(mu_Philosophers[((mu_ID) == (2)) ? (0) : ((mu_ID) + (1))].mu_Got_Forks[mu_right])) ; 
}
if ( !(mu__boolexpr40) )
  { mu__quant39 = FALSE; break; }
};
};
  if (!(mu__quant39)) mu__boolexpr38 = FALSE ;
  else {
bool mu__quant41; 
mu__quant41 = TRUE;
{
for(int mu_ID = 0; mu_ID <= 2; mu_ID++) {
bool mu__boolexpr42;
  if (!(mu_Philosophers[mu_ID].mu_Got_Forks[mu_right])) mu__boolexpr42 = TRUE ;
  else {
  mu__boolexpr42 = (!(mu_Philosophers[((mu_ID) == (0)) ? (2) : ((mu_ID) - (1))].mu_Got_Forks[mu_left])) ; 
}
if ( !(mu__boolexpr42) )
  { mu__quant41 = FALSE; break; }
};
};
  mu__boolexpr38 = (mu__quant41) ; 
}
return mu__boolexpr38;
};

bool mu__condition_43() // Condition for Rule "A fork is used by upto one philosophers only"
{
  return mu__invariant_37( );
}

/**** end rule declaration ****/

int mu__invariant_44() // Invariant "All eating philosophers have both forks available."
{
bool mu__quant45; 
mu__quant45 = TRUE;
{
for(int mu_ID = 0; mu_ID <= 2; mu_ID++) {
bool mu__boolexpr46;
  if (!((mu_Philosophers[mu_ID].mu_Status) == (mu_eat))) mu__boolexpr46 = TRUE ;
  else {
bool mu__quant47; 
mu__quant47 = TRUE;
{
for(int mu_s = 1; mu_s <= 2; mu_s++) {
if ( !(mu_Philosophers[mu_ID].mu_Got_Forks[mu_s]) )
  { mu__quant47 = FALSE; break; }
};
};
  mu__boolexpr46 = (mu__quant47) ; 
}
if ( !(mu__boolexpr46) )
  { mu__quant45 = FALSE; break; }
};
};
return mu__quant45;
};

bool mu__condition_48() // Condition for Rule "All eating philosophers have both forks available."
{
  return mu__invariant_44( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"All eating philosophers have both forks available.", &mu__condition_48, NULL, FALSE},
{"A fork is used by upto one philosophers only", &mu__condition_43, NULL, FALSE},
};
const unsigned short numinvariants = 2;

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
Philosophers:NoScalarset
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
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
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
  Presentation = Explicit;
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
if (!nexted) return FALSE;
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
        mu_Philosophers.MultisetSort();
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
void mu_1_Phil_ID::Permute(PermSet& Perm, int i) {};
void mu_1_Phil_ID::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Phil_ID::Canonicalize(PermSet& Perm) {};
void mu_1_Phil_ID::SimpleLimit(PermSet& Perm) {};
void mu_1_Phil_ID::ArrayLimit(PermSet& Perm) {};
void mu_1_Phil_ID::Limit(PermSet& Perm) {};
void mu_1_Phil_ID::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_side::Permute(PermSet& Perm, int i) {};
void mu_1_side::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_side::Canonicalize(PermSet& Perm) {};
void mu_1_side::SimpleLimit(PermSet& Perm) {};
void mu_1_side::ArrayLimit(PermSet& Perm) {};
void mu_1_side::Limit(PermSet& Perm) {};
void mu_1_side::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm) {}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_2::SimpleLimit(PermSet& Perm){}
void mu_1__type_2::ArrayLimit(PermSet& Perm){}
void mu_1__type_2::Limit(PermSet& Perm)
{
};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
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
              
              mu_Philosophers.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Philosophers.MultisetSort();
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

          mu_Philosophers.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Philosophers.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Philosophers.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Philosophers.MultisetSort();
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
      mu_Philosophers.MultisetSort();
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
        mu_Philosophers.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Philosophers.MultisetSort();
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

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
