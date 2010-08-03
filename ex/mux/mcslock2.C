/******************************
  Program "mcslock2.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "mcslock2"
#define BITS_IN_WORLD 70
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

  mu_1_pid (char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_pid (void): mu__byte(1, 3, 2) {};
  mu_1_pid (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
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
  { "pid_1","pid_2","pid_3",NULL };

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
      return ( s << mu_1_label_t::values[ int(val) - 4] );
    else return ( s << "Undefined" );
  };

  mu_1_label_t (char *name, int os): mu__byte(4, 16, 4, name, os) {};
  mu_1_label_t (void): mu__byte(4, 16, 4) {};
  mu_1_label_t (int val): mu__byte(4, 16, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -4]; };
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
      cout << name << ":" << values[ value() -4] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_label_t::values[] = {"L0","L1","L2","L3","L4","L5","L6","L7","L8","L9","L10","L11","L12",NULL };

/*** end of enum declaration ***/
mu_1_label_t mu_1_label_t_undefined_var;

class mu_1_ptqnode
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_0_boolean mu_nil;
  mu_1_pid mu_p;
  mu_1_ptqnode ( char *n, int os ) { set_self(n,os); };
  mu_1_ptqnode ( void ) {};

  virtual ~mu_1_ptqnode(); 
friend int CompareWeight(mu_1_ptqnode& a, mu_1_ptqnode& b)
  {
    int w;
    w = CompareWeight(a.mu_nil, b.mu_nil);
    if (w!=0) return w;
    w = CompareWeight(a.mu_p, b.mu_p);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ptqnode& a, mu_1_ptqnode& b)
  {
    int w;
    w = Compare(a.mu_nil, b.mu_nil);
    if (w!=0) return w;
    w = Compare(a.mu_p, b.mu_p);
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
    mu_nil.MultisetSort();
    mu_p.MultisetSort();
  }
  void print_statistic()
  {
    mu_nil.print_statistic();
    mu_p.print_statistic();
  }
  void clear() {
    mu_nil.clear();
    mu_p.clear();
 };
  void undefine() {
    mu_nil.undefine();
    mu_p.undefine();
 };
  void reset() {
    mu_nil.reset();
    mu_p.reset();
 };
  void print() {
    mu_nil.print();
    mu_p.print();
  };
  void print_diff(state *prevstate) {
    mu_nil.print_diff(prevstate);
    mu_p.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_nil.to_state(thestate);
    mu_p.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ptqnode& operator= (const mu_1_ptqnode& from) {
    mu_nil.value(from.mu_nil.value());
    mu_p.value(from.mu_p.value());
    return *this;
  };
};

  void mu_1_ptqnode::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ptqnode::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ptqnode::set_self(char *n, int os)
{
  name = n;
  mu_nil.set_self_2(name, ".nil", os + 0 );
  mu_p.set_self_2(name, ".p", os + 2 );
}

mu_1_ptqnode::~mu_1_ptqnode()
{
}

/*** end record declaration ***/
mu_1_ptqnode mu_1_ptqnode_undefined_var;

class mu_1_qnode
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_ptqnode mu_next;
  mu_0_boolean mu_locked;
  mu_1_qnode ( char *n, int os ) { set_self(n,os); };
  mu_1_qnode ( void ) {};

  virtual ~mu_1_qnode(); 
friend int CompareWeight(mu_1_qnode& a, mu_1_qnode& b)
  {
    int w;
    w = CompareWeight(a.mu_next, b.mu_next);
    if (w!=0) return w;
    w = CompareWeight(a.mu_locked, b.mu_locked);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_qnode& a, mu_1_qnode& b)
  {
    int w;
    w = Compare(a.mu_next, b.mu_next);
    if (w!=0) return w;
    w = Compare(a.mu_locked, b.mu_locked);
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
    mu_next.MultisetSort();
    mu_locked.MultisetSort();
  }
  void print_statistic()
  {
    mu_next.print_statistic();
    mu_locked.print_statistic();
  }
  void clear() {
    mu_next.clear();
    mu_locked.clear();
 };
  void undefine() {
    mu_next.undefine();
    mu_locked.undefine();
 };
  void reset() {
    mu_next.reset();
    mu_locked.reset();
 };
  void print() {
    mu_next.print();
    mu_locked.print();
  };
  void print_diff(state *prevstate) {
    mu_next.print_diff(prevstate);
    mu_locked.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_next.to_state(thestate);
    mu_locked.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_qnode& operator= (const mu_1_qnode& from) {
    mu_next = from.mu_next;
    mu_locked.value(from.mu_locked.value());
    return *this;
  };
};

  void mu_1_qnode::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_qnode::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_qnode::set_self(char *n, int os)
{
  name = n;
  mu_next.set_self_2(name, ".next", os + 0 );
  mu_locked.set_self_2(name, ".locked", os + 4 );
}

mu_1_qnode::~mu_1_qnode()
{
}

/*** end record declaration ***/
mu_1_qnode mu_1_qnode_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_label_t array[ 3 ];
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
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: pid is internally represented from 3 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 3; i++)
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
array[i].set_self_ar(n,"pid_1", i * 4 + os);i++;
array[i].set_self_ar(n,"pid_2", i * 4 + os);i++;
array[i].set_self_ar(n,"pid_3", i * 4 + os);i++;
}
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1
{
 public:
  mu_1_qnode array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1_qnode& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: pid is internally represented from 3 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
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
array[i].set_self_ar(n,"pid_1", i * 6 + os);i++;
array[i].set_self_ar(n,"pid_2", i * 6 + os);i++;
array[i].set_self_ar(n,"pid_3", i * 6 + os);i++;
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
  mu_1_ptqnode mu_pred;
  mu_1_ptqnode mu_tail;
  mu_1_ptqnode mu_usuper;
  mu_1__type_2 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_2 ( void ) {};

  virtual ~mu_1__type_2(); 
friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = CompareWeight(a.mu_pred, b.mu_pred);
    if (w!=0) return w;
    w = CompareWeight(a.mu_tail, b.mu_tail);
    if (w!=0) return w;
    w = CompareWeight(a.mu_usuper, b.mu_usuper);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = Compare(a.mu_pred, b.mu_pred);
    if (w!=0) return w;
    w = Compare(a.mu_tail, b.mu_tail);
    if (w!=0) return w;
    w = Compare(a.mu_usuper, b.mu_usuper);
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
    mu_pred.MultisetSort();
    mu_tail.MultisetSort();
    mu_usuper.MultisetSort();
  }
  void print_statistic()
  {
    mu_pred.print_statistic();
    mu_tail.print_statistic();
    mu_usuper.print_statistic();
  }
  void clear() {
    mu_pred.clear();
    mu_tail.clear();
    mu_usuper.clear();
 };
  void undefine() {
    mu_pred.undefine();
    mu_tail.undefine();
    mu_usuper.undefine();
 };
  void reset() {
    mu_pred.reset();
    mu_tail.reset();
    mu_usuper.reset();
 };
  void print() {
    mu_pred.print();
    mu_tail.print();
    mu_usuper.print();
  };
  void print_diff(state *prevstate) {
    mu_pred.print_diff(prevstate);
    mu_tail.print_diff(prevstate);
    mu_usuper.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_pred.to_state(thestate);
    mu_tail.to_state(thestate);
    mu_usuper.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_2& operator= (const mu_1__type_2& from) {
    mu_pred = from.mu_pred;
    mu_tail = from.mu_tail;
    mu_usuper = from.mu_usuper;
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
  mu_pred.set_self_2(name, ".pred", os + 0 );
  mu_tail.set_self_2(name, ".tail", os + 4 );
  mu_usuper.set_self_2(name, ".usuper", os + 8 );
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
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: pid is internally represented from 3 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
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
    int i=0;
    name = n;
array[i].set_self_ar(n,"pid_1", i * 12 + os);i++;
array[i].set_self_ar(n,"pid_2", i * 12 + os);i++;
array[i].set_self_ar(n,"pid_3", i * 12 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

const int mu_N = 3;
const int mu_pid_1 = 1;
const int mu_pid_2 = 2;
const int mu_pid_3 = 3;
const int mu_L0 = 4;
const int mu_L1 = 5;
const int mu_L2 = 6;
const int mu_L3 = 7;
const int mu_L4 = 8;
const int mu_L5 = 9;
const int mu_L6 = 10;
const int mu_L7 = 11;
const int mu_L8 = 12;
const int mu_L9 = 13;
const int mu_L10 = 14;
const int mu_L11 = 15;
const int mu_L12 = 16;
/*** Variable declaration ***/
mu_1__type_0 mu_P("P",0);

/*** Variable declaration ***/
mu_1__type_1 mu_R("R",12);

/*** Variable declaration ***/
mu_1__type_3 mu_local("local",30);

/*** Variable declaration ***/
mu_1_ptqnode mu_L("L",66);

void mu_setNextNil(const mu_1_pid& mu_i)
{
mu_R[mu_i].mu_next.mu_nil = mu_true;
mu_R[mu_i].mu_next.mu_p.undefine();
};
/*** end procedure declaration ***/

void mu_setNext(const mu_1_pid& mu_i, const mu_1_pid& mu_n)
{
mu_R[mu_i].mu_next.mu_nil = mu_false;
if (mu_n.isundefined())
  mu_R[mu_i].mu_next.mu_p.undefine();
else
  mu_R[mu_i].mu_next.mu_p = mu_n;
};
/*** end procedure declaration ***/

void mu_setPredNil(const mu_1_pid& mu_i)
{
mu_local[mu_i].mu_pred.mu_nil = mu_true;
mu_local[mu_i].mu_pred.mu_p.undefine();
};
/*** end procedure declaration ***/

void mu_setPred(const mu_1_pid& mu_i, const mu_1_pid& mu_n)
{
mu_local[mu_i].mu_pred.mu_nil = mu_false;
if (mu_n.isundefined())
  mu_local[mu_i].mu_pred.mu_p.undefine();
else
  mu_local[mu_i].mu_pred.mu_p = mu_n;
};
/*** end procedure declaration ***/

void mu_setTailNil(const mu_1_pid& mu_i)
{
mu_local[mu_i].mu_tail.mu_nil = mu_true;
mu_local[mu_i].mu_tail.mu_p.undefine();
};
/*** end procedure declaration ***/

void mu_setTail(const mu_1_pid& mu_i, const mu_1_pid& mu_n)
{
mu_local[mu_i].mu_tail.mu_nil = mu_false;
if (mu_n.isundefined())
  mu_local[mu_i].mu_tail.mu_p.undefine();
else
  mu_local[mu_i].mu_tail.mu_p = mu_n;
};
/*** end procedure declaration ***/

void mu_setUsuperNil(const mu_1_pid& mu_i)
{
mu_local[mu_i].mu_usuper.mu_nil = mu_true;
mu_local[mu_i].mu_usuper.mu_p.undefine();
};
/*** end procedure declaration ***/

void mu_setUsuper(const mu_1_pid& mu_i, const mu_1_pid& mu_n)
{
mu_local[mu_i].mu_usuper.mu_nil = mu_false;
if (mu_n.isundefined())
  mu_local[mu_i].mu_usuper.mu_p.undefine();
else
  mu_local[mu_i].mu_usuper.mu_p = mu_n;
};
/*** end procedure declaration ***/

void mu_setLockNil()
{
mu_L.mu_nil = mu_true;
mu_L.mu_p.undefine();
};
/*** end procedure declaration ***/

void mu_setLock(const mu_1_pid& mu_i)
{
mu_L.mu_nil = mu_false;
if (mu_i.isundefined())
  mu_L.mu_p.undefine();
else
  mu_L.mu_p = mu_i;
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_P.clear();
  mu_R.clear();
  mu_local.clear();
  mu_L.clear();
}
void world_class::undefine()
{
  mu_P.undefine();
  mu_R.undefine();
  mu_local.undefine();
  mu_L.undefine();
}
void world_class::reset()
{
  mu_P.reset();
  mu_R.reset();
  mu_local.reset();
  mu_L.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_P.print();
  mu_R.print();
  mu_local.print();
  mu_L.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_P.print_statistic();
  mu_R.print_statistic();
  mu_local.print_statistic();
  mu_L.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_P.print_diff(prevstate);
    mu_R.print_diff(prevstate);
    mu_local.print_diff(prevstate);
    mu_L.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_P.to_state( newstate );
  mu_R.to_state( newstate );
  mu_local.to_state( newstate );
  mu_L.to_state( newstate );
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute assign Inextlocked false, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L12);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 3 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L12)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
mu_R[mu_R[mu_i].mu_next.mu_p].mu_locked = mu_false;
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute if usuper neq nil then assign usupernext Inext, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L11);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 6 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L11)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( !(mu_local[mu_i].mu_usuper.mu_nil) )
{
mu_R[mu_local[mu_i].mu_usuper.mu_p].mu_next = mu_R[mu_i].mu_next;
}
else
{
mu_R[mu_R[mu_i].mu_next.mu_p].mu_locked = mu_false;
}
mu_P[mu_i] = mu_L0;
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
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute repeat while Inext nil, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L10);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 6;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 9 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L10)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( !(mu_R[mu_i].mu_next.mu_nil) )
{
mu_P[mu_i] = mu_L11;
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute assign usuper FandS L tail, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L9);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 9;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L9)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
/*** Variable declaration ***/
mu_1_ptqnode mu_murphilocal("murphilocal",0);

mu_murphilocal = mu_local[mu_i].mu_tail;
if ( mu_L.mu_nil )
{
mu_setUsuperNil ( mu_i );
}
else
{
mu_setUsuper ( mu_i, mu_L.mu_p );
}
if ( mu_murphilocal.mu_nil )
{
Error.Error("Error: tail cannot be nil at this point.");
mu_setLockNil (  );
}
else
{
mu_setLock ( mu_murphilocal.mu_p );
}
mu_P[mu_i] = mu_L10;
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute if tail eq I, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L8);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 15 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L8)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( (mu_local[mu_i].mu_tail.mu_p) == (mu_i) )
{
mu_P[mu_i] = mu_L0;
}
else
{
mu_P[mu_i] = mu_L9;
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
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute assign oldtail FandS L nil, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L7);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 15;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 18 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L7)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( mu_L.mu_nil )
{
mu_setTailNil ( mu_i );
}
else
{
mu_setTail ( mu_i, mu_L.mu_p );
}
mu_setLockNil (  );
mu_P[mu_i] = mu_L8;
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
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute crit and if Inext nil, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L6);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 18;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 21 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L6)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( mu_R[mu_i].mu_next.mu_nil )
{
mu_P[mu_i] = mu_L7;
}
else
{
mu_P[mu_i] = mu_L12;
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
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute repeat while Ilocked, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L5);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 24 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L5)) {
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
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( !(mu_R[mu_i].mu_locked) )
{
mu_P[mu_i] = mu_L6;
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
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute assign prednext I, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L4);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 24;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 27 )
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
    r = what_rule - 24;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
mu_setNext ( mu_local[mu_i].mu_pred.mu_p, mu_i );
mu_P[mu_i] = mu_L5;
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
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute assign Ilocked true, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L3);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 27;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 30 )
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
    r = what_rule - 27;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
mu_R[mu_i].mu_locked = mu_true;
mu_P[mu_i] = mu_L4;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute if pred nil, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L2);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 30;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 33 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_P[mu_i]) == (mu_L2)) {
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
    r = what_rule - 30;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( mu_local[mu_i].mu_pred.mu_nil )
{
mu_P[mu_i] = mu_L6;
}
else
{
mu_P[mu_i] = mu_L3;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase11 ********************/
class RuleBase11
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute assign pred FandS L I, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L1);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 33;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 36 )
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
    r = what_rule - 33;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
if ( mu_L.mu_nil )
{
mu_setPredNil ( mu_i );
}
else
{
mu_setPred ( mu_i, mu_L.mu_p );
}
mu_setLock ( mu_i );
mu_P[mu_i] = mu_L2;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase12 ********************/
class RuleBase12
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("execute non crit and assign next nil, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
  return (mu_P[mu_i]) == (mu_L0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 36;
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 39 )
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
    r = what_rule - 36;
    mu_i.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_pid mu_i;
    mu_i.value((r % 3) + 1);
    r = r / 3;
mu_setNextNil ( mu_i );
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
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
  RuleBase10 R10;
  RuleBase11 R11;
  RuleBase12 R12;
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
  if (what_rule>=30 && what_rule<33)
    { R10.NextRule(what_rule);
      if (what_rule<33) return; }
  if (what_rule>=33 && what_rule<36)
    { R11.NextRule(what_rule);
      if (what_rule<36) return; }
  if (what_rule>=36 && what_rule<39)
    { R12.NextRule(what_rule);
      if (what_rule<39) return; }
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
  if (r>=30 && r<=32) return R10.Condition(r-30);
  if (r>=33 && r<=35) return R11.Condition(r-33);
  if (r>=36 && r<=38) return R12.Condition(r-36);
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
  if (r>=30 && r<=32) { R10.Code(r-30); return; } 
  if (r>=33 && r<=35) { R11.Code(r-33); return; } 
  if (r>=36 && r<=38) { R12.Code(r-36); return; } 
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
  if (r>=30 && r<=32) { return R10.Priority(); } 
  if (r>=33 && r<=35) { return R11.Priority(); } 
  if (r>=36 && r<=38) { return R12.Priority(); } 
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
  if (r>=30 && r<=32) return R10.Name(r-30);
  if (r>=33 && r<=35) return R11.Name(r-33);
  if (r>=36 && r<=38) return R12.Name(r-36);
  return NULL;
}
};
const unsigned numrules = 39;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 39


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
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_P[mu_i] = mu_L0;
mu_setNextNil ( mu_i );
mu_R[mu_i].mu_locked = mu_false;
mu_setPredNil ( mu_i );
mu_setTailNil ( mu_i );
mu_setUsuperNil ( mu_i );
};
};
mu_setLockNil (  );
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
int mu__invariant_4() // Invariant "Invariant 0"
{
bool mu__quant5; 
mu__quant5 = FALSE;
{
for(int mu_i1 = 1; mu_i1 <= 3; mu_i1++) {
bool mu__quant6; 
mu__quant6 = FALSE;
{
for(int mu_i2 = 1; mu_i2 <= 3; mu_i2++) {
bool mu__boolexpr7;
bool mu__boolexpr8;
  if (!((mu_i1) != (mu_i2))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_P[mu_i1]) == (mu_L6)) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_P[mu_i2]) == (mu_L6)) ; 
}
if ( (mu__boolexpr7) )
  { mu__quant6 = TRUE; break; }
};
};
if ( (mu__quant6) )
  { mu__quant5 = TRUE; break; }
};
};
return !(mu__quant5);
};

bool mu__condition_9() // Condition for Rule "Invariant 0"
{
  return mu__invariant_4( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invariant 0", &mu__condition_9, NULL, FALSE},
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
L:ScalarsetVariable
P:ScalarsetArrayOfFree
local:ScalarsetArrayOfScalarset
R:ScalarsetArrayOfScalarset
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
  int class_mu_1_pid[3];
  int undefined_class_mu_1_pid;// has the highest class number

  void Print_class_mu_1_pid();
  bool OnlyOneRemain_mu_1_pid;
  bool MTO_class_mu_1_pid()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_pid)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
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
  typedef int arr_mu_1_pid[3];
  arr_mu_1_pid * perm_mu_1_pid;
  arr_mu_1_pid * revperm_mu_1_pid;

  int size_mu_1_pid[3];
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
  for (int i=0; i<3; i++)
    cout << class_mu_1_pid[i];
  cout << " " << undefined_class_mu_1_pid << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
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
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_pid Perm0[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[6];
 in_mu_1_pid = new int[6];
 perm_mu_1_pid = new arr_mu_1_pid[6];
 revperm_mu_1_pid = new arr_mu_1_pid[6];

    // Set perm and revperm
    count = 0;
    for (i=1; i<=3; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=1; j<=3; j++)
        for (k=1; k<=3; k++)
          if (revperm_mu_1_pid[i][k-1]==j)   // k - base 
            perm_mu_1_pid[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_pid = 0;
    size = 6;
    count = 6;
    for (i=0; i<6; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_pid[i] = i_mu_1_pid;
      i_mu_1_pid += carry;
      if (i_mu_1_pid >= 6) { i_mu_1_pid = 0; carry = 1; } 
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
  for (i=0; i<3; i++)
    class_mu_1_pid[i]=0;
  undefined_class_mu_1_pid=0;
  OnlyOneRemain_mu_1_pid = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<6; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_pid[3];
  int size_mu_1_pid[3];
  bool should_be_in_mu_1_pid[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_pid; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  {
	    size_mu_1_pid[k] = class_size;
	    start_mu_1_pid[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_pid[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_pid[i][k]-1 >=start_mu_1_pid[k] 
	     && perm_mu_1_pid[i][k]-1 < start_mu_1_pid[k] + size_mu_1_pid[k]) )
  	    {
	      should_be_in_mu_1_pid[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<6; i++)
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
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_pid[k]==j)
	  {
	    size_mu_1_pid[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_pid; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_pid[k]==j)
	      revperm_mu_1_pid[0][start++] = k+1;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
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
  if (size!=3)
    {
      for (i=1; i<=3; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=3; i++)
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
  for (start = 0; start < 3; )
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
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
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
        mu_L.MultisetSort();
        mu_P.MultisetSort();
        mu_local.MultisetSort();
        mu_R.MultisetSort();
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
        for (i=0; i<3; i++)
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
        for (i=0; i<3; i++)
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
void mu_1_ptqnode::Permute(PermSet& Perm, int i)
{
  mu_p.Permute(Perm,i);
};
void mu_1_ptqnode::SimpleCanonicalize(PermSet& Perm)
{
  mu_p.SimpleCanonicalize(Perm);
};
void mu_1_ptqnode::Canonicalize(PermSet& Perm)
{
};
void mu_1_ptqnode::SimpleLimit(PermSet& Perm)
{
  mu_p.SimpleLimit(Perm);
};
void mu_1_ptqnode::ArrayLimit(PermSet& Perm){}
void mu_1_ptqnode::Limit(PermSet& Perm)
{
};
void mu_1_ptqnode::MultisetLimit(PermSet& Perm)
{
};
void mu_1_qnode::Permute(PermSet& Perm, int i)
{
  mu_next.Permute(Perm,i);
};
void mu_1_qnode::SimpleCanonicalize(PermSet& Perm)
{
  mu_next.SimpleCanonicalize(Perm);
};
void mu_1_qnode::Canonicalize(PermSet& Perm)
{
};
void mu_1_qnode::SimpleLimit(PermSet& Perm)
{
  mu_next.SimpleLimit(Perm);
};
void mu_1_qnode::ArrayLimit(PermSet& Perm){}
void mu_1_qnode::Limit(PermSet& Perm)
{
};
void mu_1_qnode::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
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
  static mu_1_label_t value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[3];
  bool pos_mu_1_pid[3][3];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_pid[3];
  int start_mu_1_pid[3];
  // canonicalization
  static mu_1__type_0 temp;
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<3; i++)
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
                      for (z=0; z<3; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j].value((*this)[i+1].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
                value[j].value((*this)[i+1].value());
              for (z=0; z<3; z++)
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
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
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
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_pid[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_pid[k]==j)
              {
                size_mu_1_pid[k] = class_size;
                start_mu_1_pid[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
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
      for (j=0; j<3; j++)
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
  static mu_1_label_t value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[3];
  bool pos_mu_1_pid[3][3];
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<3; i++)
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
                      for (z=0; z<3; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j].value((*this)[i+1].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
                value[j].value((*this)[i+1].value());
              for (z=0; z<3; z++)
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
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
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
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_pid[Perm.in_mu_1_pid[i]][j-1]];};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_pid;
  int compare;
  static mu_1_qnode value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[3];
  bool pos_mu_1_pid[3][3];
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<3; i++)
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
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
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
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
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
void mu_1__type_1::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_qnode value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_pid, oldcount_mu_1_pid;
  bool pos_mu_1_pid[3][3];
  bool goodset_mu_1_pid[3];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_pid[i][j]=FALSE;
  count_mu_1_pid = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_pid[i] == count_mu_1_pid)
         {
           pos_mu_1_pid[count_mu_1_pid][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_pid++;
      else break;
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_next.mu_p.isundefined()
            ||(*this)[k+1].mu_next.mu_p!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] 
                    && !(*this)[k+1].mu_next.mu_p.isundefined()
                    && (*this)[k+1].mu_next.mu_p==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_pid; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                            pos_mu_1_pid[i][k] = FALSE;
                          if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                            pos_mu_1_pid[i+1][k] = FALSE;
                        }
                      count_mu_1_pid++; i++;
                    }
                }
            }
        }
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3);
  while ( while_guard )
    {
      oldcount_mu_1_pid = count_mu_1_pid;

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_next.mu_p.isundefined()
                &&(*this)[k+1].mu_next.mu_p!=k+1)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_pid; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_pid; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_pid[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_pid[i][k] 
                            && !(*this)[k+1].mu_next.mu_p.isundefined()
                            && (*this)[k+1].mu_next.mu_p!=k+1
                            && pos_mu_1_pid[j][(*this)[k+1].mu_next.mu_p-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_pid[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_pid; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i][k] = FALSE;
                                  if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i+1][k] = FALSE;                  
                                }
                              count_mu_1_pid++;
                            }
                        }
                    }
                }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_pid!=count_mu_1_pid);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_pid<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_pid[i][j])
            Perm.class_mu_1_pid[j] = i;
      Perm.undefined_class_mu_1_pid=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_pid[j]>Perm.undefined_class_mu_1_pid)
          Perm.undefined_class_mu_1_pid=Perm.class_mu_1_pid[j];
    }
}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  mu_pred.Permute(Perm,i);
  mu_tail.Permute(Perm,i);
  mu_usuper.Permute(Perm,i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{
  mu_pred.SimpleCanonicalize(Perm);
  mu_tail.SimpleCanonicalize(Perm);
  mu_usuper.SimpleCanonicalize(Perm);
};
void mu_1__type_2::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{
  mu_pred.SimpleLimit(Perm);
  mu_tail.SimpleLimit(Perm);
  mu_usuper.SimpleLimit(Perm);
};
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
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_pid[Perm.in_mu_1_pid[i]][j-1]];};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_pid;
  int compare;
  static mu_1__type_2 value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_pid[3];
  bool pos_mu_1_pid[3][3];
  // sorting mu_1_pid
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_pid[i][j]=FALSE;
      count_mu_1_pid = 0;
      for (i=0; i<3; i++)
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
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_pid[k][z] = pos_mu_1_pid[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_pid[j][z] = FALSE;
                  pos_mu_1_pid[j][i] = TRUE;
                  count_mu_1_pid++;
                  break;
                }
            }
          if (j==count_mu_1_pid)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
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
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] && Perm.class_mu_1_pid[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                    pos_mu_1_pid[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_pid[k] == j && !goodset_mu_1_pid[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
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
void mu_1__type_3::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_2 value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_pid, oldcount_mu_1_pid;
  bool pos_mu_1_pid[3][3];
  bool goodset_mu_1_pid[3];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_pid[i][j]=FALSE;
  count_mu_1_pid = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_pid[i] == count_mu_1_pid)
         {
           pos_mu_1_pid[count_mu_1_pid][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_pid++;
      else break;
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_pred.mu_p.isundefined()
            ||(*this)[k+1].mu_pred.mu_p!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] 
                    && !(*this)[k+1].mu_pred.mu_p.isundefined()
                    && (*this)[k+1].mu_pred.mu_p==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_pid; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                            pos_mu_1_pid[i][k] = FALSE;
                          if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                            pos_mu_1_pid[i+1][k] = FALSE;
                        }
                      count_mu_1_pid++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_tail.mu_p.isundefined()
            ||(*this)[k+1].mu_tail.mu_p!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] 
                    && !(*this)[k+1].mu_tail.mu_p.isundefined()
                    && (*this)[k+1].mu_tail.mu_p==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_pid; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                            pos_mu_1_pid[i][k] = FALSE;
                          if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                            pos_mu_1_pid[i+1][k] = FALSE;
                        }
                      count_mu_1_pid++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_usuper.mu_p.isundefined()
            ||(*this)[k+1].mu_usuper.mu_p!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_pid; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_pid[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_pid[i][k] 
                    && !(*this)[k+1].mu_usuper.mu_p.isundefined()
                    && (*this)[k+1].mu_usuper.mu_p==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_pid[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_pid; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                            pos_mu_1_pid[i][k] = FALSE;
                          if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                            pos_mu_1_pid[i+1][k] = FALSE;
                        }
                      count_mu_1_pid++; i++;
                    }
                }
            }
        }
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3);
  while ( while_guard )
    {
      oldcount_mu_1_pid = count_mu_1_pid;

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_pred.mu_p.isundefined()
                &&(*this)[k+1].mu_pred.mu_p!=k+1)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_pid; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_pid; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_pid[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_pid[i][k] 
                            && !(*this)[k+1].mu_pred.mu_p.isundefined()
                            && (*this)[k+1].mu_pred.mu_p!=k+1
                            && pos_mu_1_pid[j][(*this)[k+1].mu_pred.mu_p-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_pid[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_pid; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i][k] = FALSE;
                                  if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i+1][k] = FALSE;                  
                                }
                              count_mu_1_pid++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_tail.mu_p.isundefined()
                &&(*this)[k+1].mu_tail.mu_p!=k+1)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_pid; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_pid; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_pid[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_pid[i][k] 
                            && !(*this)[k+1].mu_tail.mu_p.isundefined()
                            && (*this)[k+1].mu_tail.mu_p!=k+1
                            && pos_mu_1_pid[j][(*this)[k+1].mu_tail.mu_p-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_pid[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_pid; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i][k] = FALSE;
                                  if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i+1][k] = FALSE;                  
                                }
                              count_mu_1_pid++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_pid() && count_mu_1_pid<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_usuper.mu_p.isundefined()
                &&(*this)[k+1].mu_usuper.mu_p!=k+1)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_pid; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_pid; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_pid[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_pid[i][k] 
                            && !(*this)[k+1].mu_usuper.mu_p.isundefined()
                            && (*this)[k+1].mu_usuper.mu_p!=k+1
                            && pos_mu_1_pid[j][(*this)[k+1].mu_usuper.mu_p-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_pid[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_pid; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_pid[j][k] = pos_mu_1_pid[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_pid[i][k] && !goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i][k] = FALSE;
                                  if (pos_mu_1_pid[i+1][k] && goodset_mu_1_pid[k])
                                    pos_mu_1_pid[i+1][k] = FALSE;                  
                                }
                              count_mu_1_pid++;
                            }
                        }
                    }
                }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_pid!=count_mu_1_pid);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_pid<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_pid())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_pid[i][j])
            Perm.class_mu_1_pid[j] = i;
      Perm.undefined_class_mu_1_pid=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_pid[j]>Perm.undefined_class_mu_1_pid)
          Perm.undefined_class_mu_1_pid=Perm.class_mu_1_pid[j];
    }
}
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
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_L.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_L.MultisetSort();
              mu_P.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_P.MultisetSort();
              mu_local.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_local.MultisetSort();
              mu_R.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_R.MultisetSort();
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

          mu_L.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_L.MultisetSort();
          mu_P.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_P.MultisetSort();
          mu_local.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_local.MultisetSort();
          mu_R.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_R.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_L.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_L.MultisetSort();
              mu_P.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_P.MultisetSort();
              mu_local.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_local.MultisetSort();
              mu_R.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_R.MultisetSort();
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
      mu_L.MultisetSort();
      mu_P.MultisetSort();
      mu_local.MultisetSort();
      mu_R.MultisetSort();
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
        mu_L.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_L.MultisetSort();
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

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_local.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_local.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_R.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_R.MultisetSort();
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

  mu_L.SimpleCanonicalize(Perm);

  mu_P.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_local.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_R.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_local.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_R.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_local.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_local.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_R.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_R.MultisetSort();
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
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_L.SimpleCanonicalize(Perm);

  mu_P.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_local.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_R.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_local.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_R.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_local.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_local.MultisetSort();
  mu_R.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_R.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_local.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_local.MultisetSort();
      mu_R.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_R.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

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

  mu_L.SimpleCanonicalize(Perm);

  mu_P.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_local.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_R.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_local.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_R.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_local.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_local.MultisetSort();

  mu_R.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_R.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
