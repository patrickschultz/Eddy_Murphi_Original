/******************************
  Program "newlist6.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "newlist6"
#define BITS_IN_WORLD 176
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_HeadCells: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_HeadCells& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_HeadCells& val)
  {
    if (val.defined())
      return ( s << mu_1_HeadCells::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_HeadCells (char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_HeadCells (void): mu__byte(1, 1, 1) {};
  mu_1_HeadCells (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
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

char *mu_1_HeadCells::values[] = {"HeadCell",NULL };

/*** end of enum declaration ***/
mu_1_HeadCells mu_1_HeadCells_undefined_var;

class mu_1_RestCells: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_RestCells& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_RestCells& val)
    {
      if (val.defined())
        return ( s << mu_1_RestCells::values[ int(val) - 2 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_RestCells (char *name, int os): mu__byte(2, 5, 3, name, os) {};
  mu_1_RestCells (void): mu__byte(2, 5, 3) {};
  mu_1_RestCells (int val): mu__byte(2, 5, 3, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -2]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 2] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_RestCells& a, mu_1_RestCells& b)
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
char *mu_1_RestCells::values[] =
  { "RestCells_1","RestCells_2","RestCells_3","RestCells_4",NULL };

/*** end scalarset declaration ***/
mu_1_RestCells mu_1_RestCells_undefined_var;

class mu_1_CellPtr: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_CellPtr& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_CellPtr& val)
    {
      if (val.defined())
        return ( s << mu_1_CellPtr::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_CellPtr (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_CellPtr (void): mu__byte(0, 4, 3) {};
  mu_1_CellPtr (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int value() const
  {
    int val = mu__byte::value();
    // val == -1 if value undefined
    // we can return it since no enum/scalarsetid will have value -1
    if (val == -1) return -1;
    if (val <= 0) return val+1;
    if (val <= 4) return val+1;
  }
  inline int value(int val)
  {
    if (val == -1) { undefine(); return -1; }
    if ((val >= 1) && (val <= 1)) return (mu__byte::value(val-1)+1);
    if ((val >= 2) && (val <= 5)) return (mu__byte::value(val-1)+1);
  }
  inline int indexvalue() const
  {
    return mu__byte::value();
  };
  inline int unionassign(int val)
  {
    return mu__byte::value(val);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_CellPtr& a, mu_1_CellPtr& b)
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
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_CellPtr::values[] = {"HeadCell","RestCells_1","RestCells_2","RestCells_3","RestCells_4",NULL };

/*** end union declaration ***/
mu_1_CellPtr mu_1_CellPtr_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 6] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(6, 9, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(6, 9, 3) {};
  mu_1__type_0 (int val): mu__byte(6, 9, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -6]; };
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
      cout << name << ":" << values[ value() -6] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_0::values[] = {"Normal","Wait_Head","Wait_Pred","Wait_Del_Ack",NULL };

/*** end of enum declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1_Cell
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_CellPtr mu_Next;
  mu_1__type_0 mu_State;
  mu_0_boolean mu_IsInList;
  mu_1_Cell ( char *n, int os ) { set_self(n,os); };
  mu_1_Cell ( void ) {};

  virtual ~mu_1_Cell(); 
friend int CompareWeight(mu_1_Cell& a, mu_1_Cell& b)
  {
    int w;
    w = CompareWeight(a.mu_Next, b.mu_Next);
    if (w!=0) return w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_IsInList, b.mu_IsInList);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Cell& a, mu_1_Cell& b)
  {
    int w;
    w = Compare(a.mu_Next, b.mu_Next);
    if (w!=0) return w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_IsInList, b.mu_IsInList);
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
    mu_Next.MultisetSort();
    mu_State.MultisetSort();
    mu_IsInList.MultisetSort();
  }
  void print_statistic()
  {
    mu_Next.print_statistic();
    mu_State.print_statistic();
    mu_IsInList.print_statistic();
  }
  void clear() {
    mu_Next.clear();
    mu_State.clear();
    mu_IsInList.clear();
 };
  void undefine() {
    mu_Next.undefine();
    mu_State.undefine();
    mu_IsInList.undefine();
 };
  void reset() {
    mu_Next.reset();
    mu_State.reset();
    mu_IsInList.reset();
 };
  void print() {
    mu_Next.print();
    mu_State.print();
    mu_IsInList.print();
  };
  void print_diff(state *prevstate) {
    mu_Next.print_diff(prevstate);
    mu_State.print_diff(prevstate);
    mu_IsInList.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Next.to_state(thestate);
    mu_State.to_state(thestate);
    mu_IsInList.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Cell& operator= (const mu_1_Cell& from) {
    mu_Next.value(from.mu_Next.value());
    mu_State.value(from.mu_State.value());
    mu_IsInList.value(from.mu_IsInList.value());
    return *this;
  };
};

  void mu_1_Cell::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Cell::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Cell::set_self(char *n, int os)
{
  name = n;
  mu_Next.set_self_2(name, ".Next", os + 0 );
  mu_State.set_self_2(name, ".State", os + 3 );
  mu_IsInList.set_self_2(name, ".IsInList", os + 6 );
}

mu_1_Cell::~mu_1_Cell()
{
}

/*** end record declaration ***/
mu_1_Cell mu_1_Cell_undefined_var;

class mu_1_Message_Type: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Message_Type& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Message_Type& val)
  {
    if (val.defined())
      return ( s << mu_1_Message_Type::values[ int(val) - 10] );
    else return ( s << "Undefined" );
  };

  mu_1_Message_Type (char *name, int os): mu__byte(10, 15, 3, name, os) {};
  mu_1_Message_Type (void): mu__byte(10, 15, 3) {};
  mu_1_Message_Type (int val): mu__byte(10, 15, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -10]; };
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
      cout << name << ":" << values[ value() -10] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Message_Type::values[] = {"Add","Head","Delete","Pred","ChNext","Del_Ack",NULL };

/*** end of enum declaration ***/
mu_1_Message_Type mu_1_Message_Type_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_Message_Type mu_MType;
  mu_1_CellPtr mu_Source;
  mu_1_CellPtr mu_Destination;
  mu_1_CellPtr mu_Old;
  mu_1_CellPtr mu_New;
  mu_1_Message ( char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_MType, b.mu_MType);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Source, b.mu_Source);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Destination, b.mu_Destination);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Old, b.mu_Old);
    if (w!=0) return w;
    w = CompareWeight(a.mu_New, b.mu_New);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_MType, b.mu_MType);
    if (w!=0) return w;
    w = Compare(a.mu_Source, b.mu_Source);
    if (w!=0) return w;
    w = Compare(a.mu_Destination, b.mu_Destination);
    if (w!=0) return w;
    w = Compare(a.mu_Old, b.mu_Old);
    if (w!=0) return w;
    w = Compare(a.mu_New, b.mu_New);
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
    mu_MType.MultisetSort();
    mu_Source.MultisetSort();
    mu_Destination.MultisetSort();
    mu_Old.MultisetSort();
    mu_New.MultisetSort();
  }
  void print_statistic()
  {
    mu_MType.print_statistic();
    mu_Source.print_statistic();
    mu_Destination.print_statistic();
    mu_Old.print_statistic();
    mu_New.print_statistic();
  }
  void clear() {
    mu_MType.clear();
    mu_Source.clear();
    mu_Destination.clear();
    mu_Old.clear();
    mu_New.clear();
 };
  void undefine() {
    mu_MType.undefine();
    mu_Source.undefine();
    mu_Destination.undefine();
    mu_Old.undefine();
    mu_New.undefine();
 };
  void reset() {
    mu_MType.reset();
    mu_Source.reset();
    mu_Destination.reset();
    mu_Old.reset();
    mu_New.reset();
 };
  void print() {
    mu_MType.print();
    mu_Source.print();
    mu_Destination.print();
    mu_Old.print();
    mu_New.print();
  };
  void print_diff(state *prevstate) {
    mu_MType.print_diff(prevstate);
    mu_Source.print_diff(prevstate);
    mu_Destination.print_diff(prevstate);
    mu_Old.print_diff(prevstate);
    mu_New.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_MType.to_state(thestate);
    mu_Source.to_state(thestate);
    mu_Destination.to_state(thestate);
    mu_Old.to_state(thestate);
    mu_New.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_MType.value(from.mu_MType.value());
    mu_Source.value(from.mu_Source.value());
    mu_Destination.value(from.mu_Destination.value());
    mu_Old.value(from.mu_Old.value());
    mu_New.value(from.mu_New.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(char *n, int os)
{
  name = n;
  mu_MType.set_self_2(name, ".MType", os + 0 );
  mu_Source.set_self_2(name, ".Source", os + 3 );
  mu_Destination.set_self_2(name, ".Destination", os + 6 );
  mu_Old.set_self_2(name, ".Old", os + 9 );
  mu_New.set_self_2(name, ".New", os + 12 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_1
{
 public:
  mu_1_Cell array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1_Cell& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 5; i++)
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
    for (int i=0; i<5; i++) {
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
    for (int i=0; i<5; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<5; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 5; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 5; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 5; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 5; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 5; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 5; i++)
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
array[i].set_self_ar(n,"HeadCell", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_1", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_2", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_3", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_4", i * 8 + os);i++;
}
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_2_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_2_id () : mu__byte(0,7,0) {};
  mu_1__type_2_id (int val) : mu__byte(0,7,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_2
{
 public:
  mu_1_Message array[ 8 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 8 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_2 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_2 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_2 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 7) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 8; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<8; i++) {
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
  void clear() { for (int i = 0; i < 8; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 8; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 8; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 8; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 8; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_2_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 8; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 8; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 8) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 8; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_2_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 8; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 8; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 8; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
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
void mu_1__type_2::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 8; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 15 + os);
  k = os + i * 15;
  for(i = 0; i < 8; i++)
    valid[i].set_self("", i * 2 + k);
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end multiset declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

const int mu_CellCount = 5;
const int mu_NetMax = 8;
const int mu_HeadCell = 1;
const int mu_RestCells_1 = 2;
const int mu_RestCells_2 = 3;
const int mu_RestCells_3 = 4;
const int mu_RestCells_4 = 5;
const int mu_Normal = 6;
const int mu_Wait_Head = 7;
const int mu_Wait_Pred = 8;
const int mu_Wait_Del_Ack = 9;
const int mu_Add = 10;
const int mu_Head = 11;
const int mu_Delete = 12;
const int mu_Pred = 13;
const int mu_ChNext = 14;
const int mu_Del_Ack = 15;
/*** Variable declaration ***/
mu_1__type_1 mu_Cells("Cells",0);

/*** Variable declaration ***/
mu_1__type_2 mu_Net("Net",40);

void mu_Send(const mu_1_Message_Type& mu_t, const mu_1_CellPtr& mu_Dst, const mu_1_CellPtr& mu_Src, const mu_1_CellPtr& mu_New, const mu_1_CellPtr& mu_Old)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_t.isundefined())
  mu_msg.mu_MType.undefine();
else
  mu_msg.mu_MType = mu_t;
if (mu_Src.isundefined())
  mu_msg.mu_Source.undefine();
else
  mu_msg.mu_Source = mu_Src;
if (mu_Dst.isundefined())
  mu_msg.mu_Destination.undefine();
else
  mu_msg.mu_Destination = mu_Dst;
if (mu_New.isundefined())
  mu_msg.mu_New.undefine();
else
  mu_msg.mu_New = mu_New;
if (mu_Old.isundefined())
  mu_msg.mu_Old.undefine();
else
  mu_msg.mu_Old = mu_Old;
mu_Net.multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_Send_Add(const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s)
{
mu_Send ( mu_Add, mu_d, mu_s, mu_1_CellPtr_undefined_var, mu_1_CellPtr_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Head(const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s, const mu_1_CellPtr& mu_c)
{
mu_Send ( mu_Head, mu_d, mu_s, mu_c, mu_1_CellPtr_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Pred(const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s)
{
mu_Send ( mu_Pred, mu_d, mu_s, mu_1_CellPtr_undefined_var, mu_1_CellPtr_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_ChNext(const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s, const mu_1_CellPtr& mu_old, const mu_1_CellPtr& mu_new)
{
mu_Send ( mu_ChNext, mu_d, mu_s, mu_new, mu_old );
};
/*** end procedure declaration ***/

void mu_Send_Del_Ack(const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s)
{
mu_Send ( mu_Del_Ack, mu_d, mu_s, mu_1_CellPtr_undefined_var, mu_1_CellPtr_undefined_var );
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_Cells.clear();
  mu_Net.clear();
}
void world_class::undefine()
{
  mu_Cells.undefine();
  mu_Net.undefine();
}
void world_class::reset()
{
  mu_Cells.reset();
  mu_Net.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Cells.print();
  mu_Net.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Cells.print_statistic();
  mu_Net.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_Cells.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_Cells.to_state( newstate );
  mu_Net.to_state( newstate );
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
    static mu_1__type_2_id mu_msg_id;
    mu_msg_id.value((r % 8) + 0);
    r = r / 8;
    return tsprintf("Rule 2, msg_id:%s", mu_msg_id.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_2_id mu_msg_id;
    mu_msg_id.value((r % 8) + 0);
    r = r / 8;
  if (!mu_Net.in(mu_msg_id)) { return FALSE; }
  return mu_true;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1__type_2_id mu_msg_id;
    mu_msg_id.value((r % 8) + 0);
    r = r / 8;
    while (what_rule < 8 && mu_msg_id.value()<8 )
      {
        if ( ( TRUE  ) ) {
              if (mu_true) {
                if ( ( TRUE && mu_Net.in(mu_msg_id) ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 8;
        }
        else
          what_rule += 8;
    r = what_rule - 0;
    mu_msg_id.value((r % 8) + 0);
    r = r / 8;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_2_id mu_msg_id;
    mu_msg_id.value((r % 8) + 0);
    r = r / 8;
{
  mu_1_CellPtr& mu_n = mu_Net[mu_msg_id].mu_Destination;
  mu_1_Cell& mu_me = mu_Cells[mu_Net[mu_msg_id].mu_Destination];
switch ((int) mu_Net[mu_msg_id].mu_MType) {
case mu_Add:
if ( (mu_me.mu_State) == (mu_Normal) )
{
mu_Send_Head ( mu_Net[mu_msg_id].mu_Source, (int)mu_HeadCell, mu_me.mu_Next );
mu_me.mu_Next = mu_Net[mu_msg_id].mu_Source;
mu_Net.multisetremove(mu_msg_id);
}
break;
case mu_Delete:
break;
case mu_Head:
if ( !((mu_me.mu_State) == (mu_Wait_Head)) ) Error.Error("Assertion failed: newlist6.m, line 170.");
mu_me.mu_Next = mu_Net[mu_msg_id].mu_New;
mu_me.mu_IsInList = mu_true;
mu_me.mu_State = mu_Normal;
mu_Net.multisetremove(mu_msg_id);
break;
case mu_Pred:
switch ((int) mu_me.mu_State) {
case mu_Normal:
mu_Send_Pred ( mu_me.mu_Next, mu_n );
mu_Net.multisetremove(mu_msg_id);
break;
case mu_Wait_Pred:
mu_me.mu_State = mu_Wait_Del_Ack;
mu_Send_ChNext ( mu_Net[mu_msg_id].mu_Source, mu_n, mu_n, mu_me.mu_Next );
mu_Net.multisetremove(mu_msg_id);
break;
case mu_Wait_Head:
break;
default:
Error.Error("Error: Got Pred in funny state");
break;
}
break;
case mu_ChNext:
bool mu__boolexpr3;
  if ((mu_me.mu_State) == (mu_Normal)) mu__boolexpr3 = TRUE ;
  else {
  mu__boolexpr3 = ((mu_me.mu_State) == (mu_Wait_Pred)) ; 
}
if ( mu__boolexpr3 )
{
if ( (mu_me.mu_Next) != (mu_Net[mu_msg_id].mu_Old) )
{
mu_Send_ChNext ( mu_Cells[mu_n].mu_Next, mu_n, mu_Net[mu_msg_id].mu_Old, mu_Net[mu_msg_id].mu_New );
}
else
{
mu_me.mu_Next = mu_Net[mu_msg_id].mu_New;
mu_Send_Del_Ack ( mu_Net[mu_msg_id].mu_Old, mu_n );
mu_Send_Pred ( mu_Net[mu_msg_id].mu_New, mu_n );
}
mu_Net.multisetremove(mu_msg_id);
}
break;
case mu_Del_Ack:
if ( (mu_me.mu_State) == (mu_Wait_Del_Ack) )
{
mu_me.mu_State = mu_Normal;
mu_me.mu_Next = mu_Net[mu_msg_id].mu_Destination;
mu_me.mu_IsInList = mu_false;
mu_Net.multisetremove(mu_msg_id);
}
else
{
Error.Error("Error: Got unexpected Del_Ack");
}
break;
}
}
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
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
    return tsprintf("Rule 1, c:%s", mu_c.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
bool mu__boolexpr4;
bool mu__boolexpr5;
  if (!((mu_Cells[mu_c].mu_State) == (mu_Normal))) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = (mu_Cells[mu_c].mu_IsInList) ; 
}
  if (!(mu__boolexpr5)) mu__boolexpr4 = FALSE ;
  else {
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr6 = 0;
  {
  mu_1__type_2_id mu_j;
  for (mu_j = 0; ; mu_j=mu_j+1)
    {
      if (mu_Net.valid[(int)mu_j].value())
        {
          if ( mu_true ) mu__intexpr6++;
        }
      if (mu_j == 8-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
  mu__boolexpr4 = ((mu__intexpr6) < (5)) ; 
}
  return mu__boolexpr4;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr7;
bool mu__boolexpr8;
  if (!((mu_Cells[mu_c].mu_State) == (mu_Normal))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = (mu_Cells[mu_c].mu_IsInList) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr9 = 0;
  {
  mu_1__type_2_id mu_j;
  for (mu_j = 0; ; mu_j=mu_j+1)
    {
      if (mu_Net.valid[(int)mu_j].value())
        {
          if ( mu_true ) mu__intexpr9++;
        }
      if (mu_j == 8-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
  mu__boolexpr7 = ((mu__intexpr9) < (5)) ; 
}
              if (mu__boolexpr7) {
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
    mu_c.value((r % 4) + 2);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
mu_Cells[mu_c].mu_State = mu_Wait_Pred;
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
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
    return tsprintf("Rule 0, c:%s", mu_c.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
bool mu__boolexpr10;
bool mu__boolexpr11;
  if (!((mu_Cells[mu_c].mu_State) == (mu_Normal))) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = (!(mu_Cells[mu_c].mu_IsInList)) ; 
}
  if (!(mu__boolexpr11)) mu__boolexpr10 = FALSE ;
  else {
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr12 = 0;
  {
  mu_1__type_2_id mu_j;
  for (mu_j = 0; ; mu_j=mu_j+1)
    {
      if (mu_Net.valid[(int)mu_j].value())
        {
          if ( mu_true ) mu__intexpr12++;
        }
      if (mu_j == 8-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
  mu__boolexpr10 = ((mu__intexpr12) < (5)) ; 
}
  return mu__boolexpr10;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
    while (what_rule < 16 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr13;
bool mu__boolexpr14;
  if (!((mu_Cells[mu_c].mu_State) == (mu_Normal))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = (!(mu_Cells[mu_c].mu_IsInList)) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_2_id mu_j;
  for (mu_j = 0; ; mu_j=mu_j+1)
    {
      if (mu_Net.valid[(int)mu_j].value())
        {
          if ( mu_true ) mu__intexpr15++;
        }
      if (mu_j == 8-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
  mu__boolexpr13 = ((mu__intexpr15) < (5)) ; 
}
              if (mu__boolexpr13) {
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
    mu_c.value((r % 4) + 2);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_RestCells mu_c;
    mu_c.value((r % 4) + 2);
    r = r / 4;
mu_Send_Add ( (int)mu_HeadCell, (int)mu_c );
mu_Cells[mu_c].mu_State = mu_Wait_Head;
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<8)
    { R0.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<12)
    { R1.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<16)
    { R2.NextRule(what_rule);
      if (what_rule<16) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=7) return R0.Condition(r-0);
  if (r>=8 && r<=11) return R1.Condition(r-8);
  if (r>=12 && r<=15) return R2.Condition(r-12);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=7) { R0.Code(r-0); return; } 
  if (r>=8 && r<=11) { R1.Code(r-8); return; } 
  if (r>=12 && r<=15) { R2.Code(r-12); return; } 
}
int Priority(unsigned short r)
{
  if (r<=7) { return R0.Priority(); } 
  if (r>=8 && r<=11) { return R1.Priority(); } 
  if (r>=12 && r<=15) { return R2.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=7) return R0.Name(r-0);
  if (r>=8 && r<=11) return R1.Name(r-8);
  if (r>=12 && r<=15) return R2.Name(r-12);
  return NULL;
}
};
const unsigned numrules = 16;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 16


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
for(int mu_c = 1; mu_c <= 5; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 5 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
mu_Cells[mu_c].mu_Next = mu_c;
mu_Cells[mu_c].mu_State = mu_Normal;
mu_Cells[mu_c].mu_IsInList = mu_false;
};
};
mu_Cells[mu_HeadCell].mu_IsInList = mu_true;
mu_Net.undefine();
/*** end multisetremove 0 declaration ***/
  mu_1__type_2_id mu__idexpr16;
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) { mu__idexpr16 = mu_i; mu_Net.multisetremove(mu__idexpr16); };
        }
      if (mu_i == 8-1) break;
    }
/*** end multisetremove 0 declaration ***/
mu_Send_Pred ( mu_Cells[mu_HeadCell].mu_Next, (int)mu_HeadCell );
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
int mu__invariant_17() // Invariant "Dead cells point to themselves"
{
bool mu__quant18; 
mu__quant18 = TRUE;
{
for(int mu_c = 1; mu_c <= 5; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 5 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
bool mu__boolexpr19;
bool mu__boolexpr20;
  if (!(!(mu_Cells[mu_c].mu_IsInList))) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_Cells[mu_c].mu_State) == (mu_Normal)) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = TRUE ;
  else {
  mu__boolexpr19 = ((mu_Cells[mu_c].mu_Next) == (mu_c)) ; 
}
if ( !(mu__boolexpr19) )
  { mu__quant18 = FALSE; break; }
};
};
return mu__quant18;
};

bool mu__condition_21() // Condition for Rule "Dead cells point to themselves"
{
  return mu__invariant_17( );
}

/**** end rule declaration ****/

int mu__invariant_22() // Invariant "Next is in list"
{
bool mu__boolexpr23;
bool mu__quant24; 
mu__quant24 = TRUE;
{
for(int mu_c = 1; mu_c <= 5; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 5 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
if ( !((mu_Cells[mu_c].mu_State) == (mu_Normal)) )
  { mu__quant24 = FALSE; break; }
};
};
  if (!(mu__quant24)) mu__boolexpr23 = TRUE ;
  else {
bool mu__quant25; 
mu__quant25 = TRUE;
{
for(int mu_c = 1; mu_c <= 5; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 5 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
bool mu__boolexpr26;
  if (!(mu_Cells[mu_c].mu_IsInList)) mu__boolexpr26 = TRUE ;
  else {
  mu__boolexpr26 = (mu_Cells[mu_Cells[mu_c].mu_Next].mu_IsInList) ; 
}
if ( !(mu__boolexpr26) )
  { mu__quant25 = FALSE; break; }
};
};
  mu__boolexpr23 = (mu__quant25) ; 
}
return mu__boolexpr23;
};

bool mu__condition_27() // Condition for Rule "Next is in list"
{
  return mu__invariant_22( );
}

/**** end rule declaration ****/

int mu__invariant_28() // Invariant "Prev is in list"
{
bool mu__boolexpr29;
bool mu__quant30; 
mu__quant30 = TRUE;
{
for(int mu_c = 1; mu_c <= 5; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 5 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
if ( !((mu_Cells[mu_c].mu_State) == (mu_Normal)) )
  { mu__quant30 = FALSE; break; }
};
};
  if (!(mu__quant30)) mu__boolexpr29 = TRUE ;
  else {
bool mu__quant31; 
mu__quant31 = TRUE;
{
for(int mu_c = 1; mu_c <= 5; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 5 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
bool mu__boolexpr32;
  if (!(mu_Cells[mu_c].mu_IsInList)) mu__boolexpr32 = TRUE ;
  else {
bool mu__quant33; 
mu__quant33 = FALSE;
{
for(int mu_p = 1; mu_p <= 5; mu_p++)
  if (( ( mu_p >= 2 ) && ( mu_p <= 5 ) )|| ( ( mu_p >= 1 ) && ( mu_p <= 1 ) )) {
bool mu__boolexpr34;
bool mu__boolexpr35;
  if (!((mu_Cells[mu_p].mu_Next) == (mu_c))) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = (mu_Cells[mu_p].mu_IsInList) ; 
}
  if (!(mu__boolexpr35)) mu__boolexpr34 = FALSE ;
  else {
bool mu__quant36; 
mu__quant36 = TRUE;
{
for(int mu_q = 1; mu_q <= 5; mu_q++)
  if (( ( mu_q >= 2 ) && ( mu_q <= 5 ) )|| ( ( mu_q >= 1 ) && ( mu_q <= 1 ) )) {
bool mu__boolexpr37;
  if (!((mu_Cells[mu_q].mu_Next) == (mu_c))) mu__boolexpr37 = TRUE ;
  else {
  mu__boolexpr37 = ((mu_p) == (mu_q)) ; 
}
if ( !(mu__boolexpr37) )
  { mu__quant36 = FALSE; break; }
};
};
  mu__boolexpr34 = (mu__quant36) ; 
}
if ( (mu__boolexpr34) )
  { mu__quant33 = TRUE; break; }
};
};
  mu__boolexpr32 = (mu__quant33) ; 
}
if ( !(mu__boolexpr32) )
  { mu__quant31 = FALSE; break; }
};
};
  mu__boolexpr29 = (mu__quant31) ; 
}
return mu__boolexpr29;
};

bool mu__condition_38() // Condition for Rule "Prev is in list"
{
  return mu__invariant_28( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Prev is in list", &mu__condition_38, NULL, FALSE},
{"Next is in list", &mu__condition_27, NULL, FALSE},
{"Dead cells point to themselves", &mu__condition_21, NULL, FALSE},
};
const unsigned short numinvariants = 3;

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
Cells:ScalarsetArrayOfScalarset
Net:Complex
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
  int class_mu_1_RestCells[4];
  int undefined_class_mu_1_RestCells;// has the highest class number

  void Print_class_mu_1_RestCells();
  bool OnlyOneRemain_mu_1_RestCells;
  bool MTO_class_mu_1_RestCells()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_RestCells)
      return FALSE;
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (i!=j && class_mu_1_RestCells[i]== class_mu_1_RestCells[j])
	    return TRUE;
    OnlyOneRemain_mu_1_RestCells = TRUE;
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
  int * in_mu_1_RestCells;
  typedef int arr_mu_1_RestCells[4];
  arr_mu_1_RestCells * perm_mu_1_RestCells;
  arr_mu_1_RestCells * revperm_mu_1_RestCells;

  int size_mu_1_RestCells[4];
  bool reversed_sorted_mu_1_RestCells(int start, int end);
  void reverse_reversed_mu_1_RestCells(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_RestCells* perm, int size, mu_1_RestCells k);
  void GenPerm0(mu_1_RestCells* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_RestCells()
{
  cout << "class_mu_1_RestCells:\t";
  for (int i=0; i<4; i++)
    cout << class_mu_1_RestCells[i];
  cout << " " << undefined_class_mu_1_RestCells << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (i!=j && class_mu_1_RestCells[i]== class_mu_1_RestCells[j])
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
    mu_1_RestCells Perm0[4];

  /********************
   declaration of class variables
  ********************/
  in = new bool[24];
 in_mu_1_RestCells = new int[24];
 perm_mu_1_RestCells = new arr_mu_1_RestCells[24];
 revperm_mu_1_RestCells = new arr_mu_1_RestCells[24];

    // Set perm and revperm
    count = 0;
    for (i=2; i<=5; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=24)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<24; i++)
      for (j=2; j<=5; j++)
        for (k=2; k<=5; k++)
          if (revperm_mu_1_RestCells[i][k-2]==j)   // k - base 
            perm_mu_1_RestCells[i][j-2]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_RestCells = 0;
    size = 24;
    count = 24;
    for (i=0; i<24; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_RestCells[i] = i_mu_1_RestCells;
      i_mu_1_RestCells += carry;
      if (i_mu_1_RestCells >= 24) { i_mu_1_RestCells = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_RestCells = new int[1];
 perm_mu_1_RestCells = new arr_mu_1_RestCells[1];
 revperm_mu_1_RestCells = new arr_mu_1_RestCells[1];
  in[0] = TRUE;
    in_mu_1_RestCells[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<4; i++)
    class_mu_1_RestCells[i]=0;
  undefined_class_mu_1_RestCells=0;
  OnlyOneRemain_mu_1_RestCells = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<24; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_RestCells[4];
  int size_mu_1_RestCells[4];
  bool should_be_in_mu_1_RestCells[24];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_RestCells; j++) // class number
    {
      class_size = 0;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  class_size++;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  {
	    size_mu_1_RestCells[k] = class_size;
	    start_mu_1_RestCells[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<24; i++) // set up
    should_be_in_mu_1_RestCells[i] = TRUE;
  for (i=0; i<24; i++) // to be in or not to be
    for (k=0; k<4; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_RestCells[i][k]-2 >=start_mu_1_RestCells[k] 
	     && perm_mu_1_RestCells[i][k]-2 < start_mu_1_RestCells[k] + size_mu_1_RestCells[k]) )
  	    {
	      should_be_in_mu_1_RestCells[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<24; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_RestCells[in_mu_1_RestCells[i]]) in[i] = FALSE;
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
  for (j=0; j<=undefined_class_mu_1_RestCells; j++) // class number
    {
      class_size = 0;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  class_size++;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  {
	    size_mu_1_RestCells[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_RestCells; j++) // class number
    {
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_RestCells[k]==j)
	      revperm_mu_1_RestCells[0][start++] = k+2;
    }
  for (j=0; j<4; j++)
    for (k=0; k<4; k++)
      if (revperm_mu_1_RestCells[0][k]==j+2)
        perm_mu_1_RestCells[0][j]=k+2;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_RestCells* Perm, int size, mu_1_RestCells k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_RestCells* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=4)
    {
      for (i=2; i<=5; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=2; i<=5; i++)
        revperm_mu_1_RestCells[count][i-2]=Perm[i-2].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_RestCells(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_RestCells[0][i]<revperm_mu_1_RestCells[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_RestCells(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_RestCells[0][j];
      revperm_mu_1_RestCells[0][j] = revperm_mu_1_RestCells[0][i];
      revperm_mu_1_RestCells[0][i] = temp;
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
  for (start = 0; start < 4; )
    {
      end = start-1+size_mu_1_RestCells[revperm_mu_1_RestCells[0][start]-2];
      if (reversed_sorted_mu_1_RestCells(start,end))
	       {
	  reverse_reversed_mu_1_RestCells(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_RestCells(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_RestCells[0][j]<revperm_mu_1_RestCells[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_RestCells[0][j];
			  revperm_mu_1_RestCells[0][j] = revperm_mu_1_RestCells[0][k];
			  revperm_mu_1_RestCells[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_RestCells(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<4; j++)
    for (k=0; k<4; k++)
      if (revperm_mu_1_RestCells[0][k]==j+2)   // k - base 
	perm_mu_1_RestCells[0][j]=k+2; // j - base 
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
        mu_Cells.MultisetSort();
        mu_Net.MultisetSort();
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
void mu_1_HeadCells::Permute(PermSet& Perm, int i) {};
void mu_1_HeadCells::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_HeadCells::Canonicalize(PermSet& Perm) {};
void mu_1_HeadCells::SimpleLimit(PermSet& Perm) {};
void mu_1_HeadCells::ArrayLimit(PermSet& Perm) {};
void mu_1_HeadCells::Limit(PermSet& Perm) {};
void mu_1_HeadCells::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_RestCells::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_RestCells[Perm.in_mu_1_RestCells[i]][value()-2]); // value - base
};
void mu_1_RestCells::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_RestCells[value()-2]==Perm.undefined_class_mu_1_RestCells) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<4; i++)
          if (Perm.class_mu_1_RestCells[i] == Perm.undefined_class_mu_1_RestCells && i!=value()-2)
            Perm.class_mu_1_RestCells[i]++;
        value(2 + Perm.undefined_class_mu_1_RestCells++);
      }
    else 
      {
        value(Perm.class_mu_1_RestCells[value()-2]+2);
      }
}
void mu_1_RestCells::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_RestCells::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_RestCells[value()-2]==Perm.undefined_class_mu_1_RestCells) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<4; i++)
          if (Perm.class_mu_1_RestCells[i] == Perm.undefined_class_mu_1_RestCells && i!=value()-2)
            Perm.class_mu_1_RestCells[i]++;
        Perm.undefined_class_mu_1_RestCells++;
      }
}
void mu_1_RestCells::ArrayLimit(PermSet& Perm) {}
void mu_1_RestCells::Limit(PermSet& Perm) {}
void mu_1_RestCells::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_CellPtr::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 5 ) )
      value(Perm.perm_mu_1_RestCells[Perm.in_mu_1_RestCells[i]][value()-2]+(0)); // value - base
  }
}
void mu_1_CellPtr::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 5 ) )
      {
        if (Perm.class_mu_1_RestCells[value()-2]==Perm.undefined_class_mu_1_RestCells) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<4; i++)
              if (Perm.class_mu_1_RestCells[i] == Perm.undefined_class_mu_1_RestCells && i!=value()-2)
                Perm.class_mu_1_RestCells[i]++;
            value(2 + Perm.undefined_class_mu_1_RestCells++);
          }
        else 
          {
            value(Perm.class_mu_1_RestCells[value()-2]+2);
          }
      }
  }
}
void mu_1_CellPtr::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_CellPtr::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 5 ) )
      if (Perm.class_mu_1_RestCells[value()-2]==Perm.undefined_class_mu_1_RestCells) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<4; i++)
            if (Perm.class_mu_1_RestCells[i] == Perm.undefined_class_mu_1_RestCells && i!=value()-2)
              Perm.class_mu_1_RestCells[i]++;
          Perm.undefined_class_mu_1_RestCells++;
        }
  }
}
void mu_1_CellPtr::ArrayLimit(PermSet& Perm) {}
void mu_1_CellPtr::Limit(PermSet& Perm) {}
void mu_1_CellPtr::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Cell::Permute(PermSet& Perm, int i)
{
  mu_Next.Permute(Perm,i);
};
void mu_1_Cell::SimpleCanonicalize(PermSet& Perm)
{
  mu_Next.SimpleCanonicalize(Perm);
};
void mu_1_Cell::Canonicalize(PermSet& Perm)
{
};
void mu_1_Cell::SimpleLimit(PermSet& Perm)
{
  mu_Next.SimpleLimit(Perm);
};
void mu_1_Cell::ArrayLimit(PermSet& Perm){}
void mu_1_Cell::Limit(PermSet& Perm)
{
};
void mu_1_Cell::MultisetLimit(PermSet& Perm)
{
};
void mu_1_Message_Type::Permute(PermSet& Perm, int i) {};
void mu_1_Message_Type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Message_Type::Canonicalize(PermSet& Perm) {};
void mu_1_Message_Type::SimpleLimit(PermSet& Perm) {};
void mu_1_Message_Type::ArrayLimit(PermSet& Perm) {};
void mu_1_Message_Type::Limit(PermSet& Perm) {};
void mu_1_Message_Type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_Source.Permute(Perm,i);
  mu_Destination.Permute(Perm,i);
  mu_Old.Permute(Perm,i);
  mu_New.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_Source.SimpleCanonicalize(Perm);
  mu_Destination.SimpleCanonicalize(Perm);
  mu_Old.SimpleCanonicalize(Perm);
  mu_New.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_Source.SimpleLimit(Perm);
  mu_Destination.SimpleLimit(Perm);
  mu_Old.SimpleLimit(Perm);
  mu_New.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_RestCells[Perm.in_mu_1_RestCells[i]][j-2]];
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1_Cell value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_RestCells;
  bool pos_mu_1_RestCells[4][4];
  bool goodset_mu_1_RestCells[4];
  // sorting mu_1_RestCells
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_RestCells())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          pos_mu_1_RestCells[i][j]=FALSE;
      count_mu_1_RestCells = 0;
      for (i=0; i<4; i++)
        {
          for (j=0; j<count_mu_1_RestCells; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_RestCells[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_RestCells; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<4; z++)
                        pos_mu_1_RestCells[k][z] = pos_mu_1_RestCells[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<4; z++)
                    pos_mu_1_RestCells[j][z] = FALSE;
                  pos_mu_1_RestCells[j][i] = TRUE;
                  count_mu_1_RestCells++;
                  break;
                }
            }
          if (j==count_mu_1_RestCells)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<4; z++)
                pos_mu_1_RestCells[j][z] = FALSE;
              pos_mu_1_RestCells[j][i] = TRUE;
              count_mu_1_RestCells++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells>1)
    {
      // limit
      for (j=0; j<4; j++) // class priority
        {
          for (i=0; i<count_mu_1_RestCells; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_RestCells[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_RestCells[i][k] && Perm.class_mu_1_RestCells[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_RestCells[k] = TRUE;
                    pos_mu_1_RestCells[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( Perm.class_mu_1_RestCells[k] == j && !goodset_mu_1_RestCells[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<4; k++)
                        if (Perm.class_mu_1_RestCells[k]>j
                            || ( Perm.class_mu_1_RestCells[k] == j && !goodset_mu_1_RestCells[k] ) )
                          Perm.class_mu_1_RestCells[k]++;
                      Perm.undefined_class_mu_1_RestCells++;
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
  static mu_1_Cell value[5];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_RestCells, oldcount_mu_1_RestCells;
  bool pos_mu_1_RestCells[4][4];
  bool goodset_mu_1_RestCells[4];
  // initializing pos array
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      pos_mu_1_RestCells[i][j]=FALSE;
  count_mu_1_RestCells = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<4; i++)
       if (Perm.class_mu_1_RestCells[i] == count_mu_1_RestCells)
         {
           pos_mu_1_RestCells[count_mu_1_RestCells][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_RestCells++;
      else break;
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<4; k++) // step through class
        if ((*this)[k+2].mu_Next.isundefined()
            ||(*this)[k+2].mu_Next!=k+2)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_RestCells; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_RestCells[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_RestCells[i][k] 
                    && !(*this)[k+2].mu_Next.isundefined()
                    && (*this)[k+2].mu_Next==k+2)
                  {
                    exists = TRUE;
                    goodset_mu_1_RestCells[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( pos_mu_1_RestCells[i][k] && !goodset_mu_1_RestCells[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_RestCells; j>i; j--)
                        for (k=0; k<4; k++)
                          pos_mu_1_RestCells[j][k] = pos_mu_1_RestCells[j-1][k];
                      for (k=0; k<4; k++)
                        {
                          if (pos_mu_1_RestCells[i][k] && !goodset_mu_1_RestCells[k])
                            pos_mu_1_RestCells[i][k] = FALSE;
                          if (pos_mu_1_RestCells[i+1][k] && goodset_mu_1_RestCells[k])
                            pos_mu_1_RestCells[i+1][k] = FALSE;
                        }
                      count_mu_1_RestCells++; i++;
                    }
                }
            }
        }
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4);
  while ( while_guard )
    {
      oldcount_mu_1_RestCells = count_mu_1_RestCells;

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<4; k++) // step through class
            if (!(*this)[k+2].mu_Next.isundefined()
                &&(*this)[k+2].mu_Next!=k+2
                &&(*this)[k+2].mu_Next>=2
                &&(*this)[k+2].mu_Next<=5)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_RestCells; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_RestCells; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<4; k++) // step through class
                        goodset_mu_1_RestCells[k] = FALSE;
                      for (k=0; k<4; k++) // step through class
                        if (pos_mu_1_RestCells[i][k] 
                            && !(*this)[k+2].mu_Next.isundefined()
                            && (*this)[k+2].mu_Next!=k+2
                            && (*this)[k+2].mu_Next>=2
                            && (*this)[k+2].mu_Next<=5
                            && pos_mu_1_RestCells[j][(*this)[k+2].mu_Next-2])
                          {
                            exists = TRUE;
                            goodset_mu_1_RestCells[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<4; k++)
                            if ( pos_mu_1_RestCells[i][k] && !goodset_mu_1_RestCells[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_RestCells; j>i; j--)
                                for (k=0; k<4; k++)
                                  pos_mu_1_RestCells[j][k] = pos_mu_1_RestCells[j-1][k];
                              for (k=0; k<4; k++)
                                {
                                  if (pos_mu_1_RestCells[i][k] && !goodset_mu_1_RestCells[k])
                                    pos_mu_1_RestCells[i][k] = FALSE;
                                  if (pos_mu_1_RestCells[i+1][k] && goodset_mu_1_RestCells[k])
                                    pos_mu_1_RestCells[i+1][k] = FALSE;                  
                                }
                              count_mu_1_RestCells++;
                            }
                        }
                    }
                }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_RestCells!=count_mu_1_RestCells);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_RestCells<4;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_RestCells())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          if (pos_mu_1_RestCells[i][j])
            Perm.class_mu_1_RestCells[j] = i;
      Perm.undefined_class_mu_1_RestCells=0;
      for (j=0; j<4; j++)
        if (Perm.class_mu_1_RestCells[j]>Perm.undefined_class_mu_1_RestCells)
          Perm.undefined_class_mu_1_RestCells=Perm.class_mu_1_RestCells[j];
    }
}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<8; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[8];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_RestCells, oldcount_mu_1_RestCells;
  bool pos_mu_1_RestCells[4][4];
  bool goodset_mu_1_RestCells[4];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[8][8];
  bool goodset_multisetindex[8];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 8; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 8; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 8; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      pos_mu_1_RestCells[i][j]=FALSE;
  count_mu_1_RestCells = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<4; i++)
       if (Perm.class_mu_1_RestCells[i] == count_mu_1_RestCells)
         {
           pos_mu_1_RestCells[count_mu_1_RestCells][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_RestCells++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_RestCells = count_mu_1_RestCells;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_Source.isundefined())
                && (*this)[k].mu_Source>=2
                && (*this)[k].mu_Source<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<4; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Source.isundefined()
                          && (*this)[k].mu_Source>=2
                          && (*this)[k].mu_Source<=5
                          && pos_mu_1_RestCells[j][(*this)[k].mu_Source-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k].mu_Source-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<4; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<4; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<4; k++)
                              {
                                if (pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j][k] = FALSE;
                                if (pos_mu_1_RestCells[j+1][k] && goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j+1][k] = FALSE;
                              }
                            count_mu_1_RestCells++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_Destination.isundefined())
                && (*this)[k].mu_Destination>=2
                && (*this)[k].mu_Destination<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<4; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Destination.isundefined()
                          && (*this)[k].mu_Destination>=2
                          && (*this)[k].mu_Destination<=5
                          && pos_mu_1_RestCells[j][(*this)[k].mu_Destination-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k].mu_Destination-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<4; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<4; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<4; k++)
                              {
                                if (pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j][k] = FALSE;
                                if (pos_mu_1_RestCells[j+1][k] && goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j+1][k] = FALSE;
                              }
                            count_mu_1_RestCells++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_Old.isundefined())
                && (*this)[k].mu_Old>=2
                && (*this)[k].mu_Old<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<4; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Old.isundefined()
                          && (*this)[k].mu_Old>=2
                          && (*this)[k].mu_Old<=5
                          && pos_mu_1_RestCells[j][(*this)[k].mu_Old-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k].mu_Old-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<4; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<4; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<4; k++)
                              {
                                if (pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j][k] = FALSE;
                                if (pos_mu_1_RestCells[j+1][k] && goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j+1][k] = FALSE;
                              }
                            count_mu_1_RestCells++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<4) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_New.isundefined())
                && (*this)[k].mu_New>=2
                && (*this)[k].mu_New<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<4; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_New.isundefined()
                          && (*this)[k].mu_New>=2
                          && (*this)[k].mu_New<=5
                          && pos_mu_1_RestCells[j][(*this)[k].mu_New-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k].mu_New-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<4; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<4; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<4; k++)
                              {
                                if (pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j][k] = FALSE;
                                if (pos_mu_1_RestCells[j+1][k] && goodset_mu_1_RestCells[k])
                                  pos_mu_1_RestCells[j+1][k] = FALSE;
                              }
                            count_mu_1_RestCells++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_RestCells!=count_mu_1_RestCells);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_RestCells<4;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_RestCells())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          if (pos_mu_1_RestCells[i][j])
            Perm.class_mu_1_RestCells[j] = i;
      Perm.undefined_class_mu_1_RestCells=0;
      for (j=0; j<4; j++)
        if (Perm.class_mu_1_RestCells[j]>Perm.undefined_class_mu_1_RestCells)
          Perm.undefined_class_mu_1_RestCells=Perm.class_mu_1_RestCells[j];
    }
  }
}

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
              
              mu_Cells.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Cells.MultisetSort();
              mu_Net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
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

          mu_Cells.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Cells.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Cells.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Cells.MultisetSort();
              mu_Net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
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
      mu_Cells.MultisetSort();
      mu_Net.MultisetSort();
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
        mu_Cells.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Cells.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
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

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Cells.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Cells.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
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

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_Cells.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Cells.MultisetSort();
  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_Cells.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Cells.MultisetSort();
      mu_Net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Net.MultisetSort();
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

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_Cells.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Cells.MultisetSort();

  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
