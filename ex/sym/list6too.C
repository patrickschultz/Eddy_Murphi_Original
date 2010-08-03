/******************************
  Program "list6too.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "list6too"
#define BITS_IN_WORLD 141
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_HeadCell: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_HeadCell& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_HeadCell& val)
    {
      if (val.defined())
        return ( s << mu_1_HeadCell::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_HeadCell (char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_HeadCell (void): mu__byte(1, 1, 1) {};
  mu_1_HeadCell (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_HeadCell& a, mu_1_HeadCell& b)
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
char *mu_1_HeadCell::values[] =
  { "HeadCell_1",NULL };

/*** end scalarset declaration ***/
mu_1_HeadCell mu_1_HeadCell_undefined_var;

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

  mu_1_RestCells (char *name, int os): mu__byte(2, 4, 2, name, os) {};
  mu_1_RestCells (void): mu__byte(2, 4, 2) {};
  mu_1_RestCells (int val): mu__byte(2, 4, 2, "Parameter or function result.", 0)
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
  { "RestCells_1","RestCells_2","RestCells_3",NULL };

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
  mu_1_CellPtr (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_CellPtr (void): mu__byte(0, 3, 3) {};
  mu_1_CellPtr (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int value() const
  {
    int val = mu__byte::value();
    // val == -1 if value undefined
    // we can return it since no enum/scalarsetid will have value -1
    if (val == -1) return -1;
    if (val <= 0) return val+1;
    if (val <= 3) return val+1;
  }
  inline int value(int val)
  {
    if (val == -1) { undefine(); return -1; }
    if ((val >= 1) && (val <= 1)) return (mu__byte::value(val-1)+1);
    if ((val >= 2) && (val <= 4)) return (mu__byte::value(val-1)+1);
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
char *mu_1_CellPtr::values[] = {"HeadCell_1","RestCells_1","RestCells_2","RestCells_3",NULL };

/*** end union declaration ***/
mu_1_CellPtr mu_1_CellPtr_undefined_var;

class mu_1_NetIndex: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_NetIndex& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_NetIndex& val)
    {
      if (val.defined())
        return ( s << mu_1_NetIndex::values[ int(val) - 5 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_NetIndex (char *name, int os): mu__byte(5, 11, 3, name, os) {};
  mu_1_NetIndex (void): mu__byte(5, 11, 3) {};
  mu_1_NetIndex (int val): mu__byte(5, 11, 3, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -5]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 5] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_NetIndex& a, mu_1_NetIndex& b)
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
char *mu_1_NetIndex::values[] =
  { "NetIndex_1","NetIndex_2","NetIndex_3","NetIndex_4","NetIndex_5","NetIndex_6","NetIndex_7",NULL };

/*** end scalarset declaration ***/
mu_1_NetIndex mu_1_NetIndex_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 12] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(12, 15, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(12, 15, 3) {};
  mu_1__type_0 (int val): mu__byte(12, 15, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -12]; };
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
      cout << name << ":" << values[ value() -12] << '\n';
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
      return ( s << mu_1_Message_Type::values[ int(val) - 16] );
    else return ( s << "Undefined" );
  };

  mu_1_Message_Type (char *name, int os): mu__byte(16, 21, 3, name, os) {};
  mu_1_Message_Type (void): mu__byte(16, 21, 3) {};
  mu_1_Message_Type (int val): mu__byte(16, 21, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -16]; };
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
      cout << name << ":" << values[ value() -16] << '\n';
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
  mu_1_Cell array[ 4 ];
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
    if ( ( index >= 2 ) && ( index <= 4 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 4; i++)
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
    for (int i=0; i<4; i++) {
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
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
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
array[i].set_self_ar(n,"HeadCell_1", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_1", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_2", i * 8 + os);i++;
array[i].set_self_ar(n,"RestCells_3", i * 8 + os);i++;
}
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__byte::operator=((int) val); };
  mu_1__type_2 (char *name, int os): mu__byte(0, 7, 4, name, os) {};
  mu_1__type_2 (void): mu__byte(0, 7, 4) {};
  mu_1__type_2 (int val): mu__byte(0, 7, 4, "Parameter or function result.", 0)
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
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_Message array[ 7 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 5 ) && ( index <= 11 ) )
      return array[ index - 5 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: NetIndex is internally represented from 11 to 5.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 5 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 7; i++)
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
    for (int i=0; i<7; i++) {
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
    for (int i=0; i<7; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<7; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 7; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 7; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 7; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 7; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 7; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 7; i++)
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
array[i].set_self_ar(n,"NetIndex_1", i * 15 + os);i++;
array[i].set_self_ar(n,"NetIndex_2", i * 15 + os);i++;
array[i].set_self_ar(n,"NetIndex_3", i * 15 + os);i++;
array[i].set_self_ar(n,"NetIndex_4", i * 15 + os);i++;
array[i].set_self_ar(n,"NetIndex_5", i * 15 + os);i++;
array[i].set_self_ar(n,"NetIndex_6", i * 15 + os);i++;
array[i].set_self_ar(n,"NetIndex_7", i * 15 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_2 mu_Count;
  mu_1__type_3 mu_Ar;
  mu_1__type_4 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_4 ( void ) {};

  virtual ~mu_1__type_4(); 
friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    w = CompareWeight(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Ar, b.mu_Ar);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    w = Compare(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = Compare(a.mu_Ar, b.mu_Ar);
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
    mu_Count.MultisetSort();
    mu_Ar.MultisetSort();
  }
  void print_statistic()
  {
    mu_Count.print_statistic();
    mu_Ar.print_statistic();
  }
  void clear() {
    mu_Count.clear();
    mu_Ar.clear();
 };
  void undefine() {
    mu_Count.undefine();
    mu_Ar.undefine();
 };
  void reset() {
    mu_Count.reset();
    mu_Ar.reset();
 };
  void print() {
    mu_Count.print();
    mu_Ar.print();
  };
  void print_diff(state *prevstate) {
    mu_Count.print_diff(prevstate);
    mu_Ar.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Count.to_state(thestate);
    mu_Ar.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_4& operator= (const mu_1__type_4& from) {
    mu_Count.value(from.mu_Count.value());
    mu_Ar = from.mu_Ar;
    return *this;
  };
};

  void mu_1__type_4::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self(char *n, int os)
{
  name = n;
  mu_Count.set_self_2(name, ".Count", os + 0 );
  mu_Ar.set_self_2(name, ".Ar", os + 4 );
}

mu_1__type_4::~mu_1__type_4()
{
}

/*** end record declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

const int mu_CellCount = 4;
const int mu_NetMax = 7;
const int mu_HeadCell_1 = 1;
const int mu_RestCells_1 = 2;
const int mu_RestCells_2 = 3;
const int mu_RestCells_3 = 4;
const int mu_NetIndex_1 = 5;
const int mu_NetIndex_2 = 6;
const int mu_NetIndex_3 = 7;
const int mu_NetIndex_4 = 8;
const int mu_NetIndex_5 = 9;
const int mu_NetIndex_6 = 10;
const int mu_NetIndex_7 = 11;
const int mu_Normal = 12;
const int mu_Wait_Head = 13;
const int mu_Wait_Pred = 14;
const int mu_Wait_Del_Ack = 15;
const int mu_Add = 16;
const int mu_Head = 17;
const int mu_Delete = 18;
const int mu_Pred = 19;
const int mu_ChNext = 20;
const int mu_Del_Ack = 21;
/*** Variable declaration ***/
mu_1__type_1 mu_Cells("Cells",0);

/*** Variable declaration ***/
mu_1__type_4 mu_Net("Net",32);

void mu_Send(const mu_1_Message_Type& mu_t, const mu_1_NetIndex& mu_i, const mu_1_CellPtr& mu_Dst, const mu_1_CellPtr& mu_Src, const mu_1_CellPtr& mu_New, const mu_1_CellPtr& mu_Old)
{
if ( (mu_Net.mu_Count) == (mu_NetMax) )
{
Error.Error("Error: Network is full");
}
else
{
if (mu_t.isundefined())
  mu_Net.mu_Ar[mu_i].mu_MType.undefine();
else
  mu_Net.mu_Ar[mu_i].mu_MType = mu_t;
if (mu_Src.isundefined())
  mu_Net.mu_Ar[mu_i].mu_Source.undefine();
else
  mu_Net.mu_Ar[mu_i].mu_Source = mu_Src;
if (mu_Dst.isundefined())
  mu_Net.mu_Ar[mu_i].mu_Destination.undefine();
else
  mu_Net.mu_Ar[mu_i].mu_Destination = mu_Dst;
if ( mu_New.isundefined() )
{
mu_Net.mu_Ar[mu_i].mu_New.undefine();
}
else
{
if (mu_New.isundefined())
  mu_Net.mu_Ar[mu_i].mu_New.undefine();
else
  mu_Net.mu_Ar[mu_i].mu_New = mu_New;
}
if ( mu_Old.isundefined() )
{
mu_Net.mu_Ar[mu_i].mu_Old.undefine();
}
else
{
if (mu_Old.isundefined())
  mu_Net.mu_Ar[mu_i].mu_Old.undefine();
else
  mu_Net.mu_Ar[mu_i].mu_Old = mu_Old;
}
mu_Net.mu_Count = (mu_Net.mu_Count) + (1);
}
};
/*** end procedure declaration ***/

void mu_Consume_Message(const mu_1_NetIndex& mu_i)
{
mu_Net.mu_Ar[mu_i].undefine();
mu_Net.mu_Count = (mu_Net.mu_Count) - (1);
};
/*** end procedure declaration ***/

void mu_Send_Add(const mu_1_NetIndex& mu_i, const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s)
{
/*** Variable declaration ***/
mu_1_CellPtr mu_UNDEF("UNDEF",0);

mu_Send ( mu_Add, mu_i, mu_d, mu_s, mu_UNDEF, mu_UNDEF );
};
/*** end procedure declaration ***/

void mu_Send_Head(const mu_1_NetIndex& mu_i, const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s, const mu_1_CellPtr& mu_c)
{
/*** Variable declaration ***/
mu_1_CellPtr mu_UNDEF("UNDEF",0);

mu_Send ( mu_Head, mu_i, mu_d, mu_s, mu_c, mu_UNDEF );
};
/*** end procedure declaration ***/

void mu_Send_Pred(const mu_1_NetIndex& mu_i, const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s)
{
/*** Variable declaration ***/
mu_1_CellPtr mu_UNDEF("UNDEF",0);

mu_Send ( mu_Pred, mu_i, mu_d, mu_s, mu_UNDEF, mu_UNDEF );
};
/*** end procedure declaration ***/

void mu_Send_ChNext(const mu_1_NetIndex& mu_i, const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s, const mu_1_CellPtr& mu_old, const mu_1_CellPtr& mu_new)
{
mu_Send ( mu_ChNext, mu_i, mu_d, mu_s, mu_new, mu_old );
};
/*** end procedure declaration ***/

void mu_Send_Del_Ack(const mu_1_NetIndex& mu_i, const mu_1_CellPtr& mu_d, const mu_1_CellPtr& mu_s)
{
/*** Variable declaration ***/
mu_1_CellPtr mu_UNDEF("UNDEF",0);

mu_Send ( mu_Del_Ack, mu_i, mu_d, mu_s, mu_UNDEF, mu_UNDEF );
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
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("Del_Ack messages for any cell, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
bool mu__boolexpr5;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Del_Ack)) ; 
}
  return mu__boolexpr5;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    while (what_rule < 7 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr6;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Del_Ack)) ; 
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
    mu_i.value((r % 7) + 5);
    r = r / 7;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
{
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_i];
  mu_1_Cell& mu_me = mu_Cells[mu_msg.mu_Destination];
if ( (mu_me.mu_State) == (mu_Wait_Del_Ack) )
{
mu_me.mu_State = mu_Normal;
mu_me.mu_Next = mu_msg.mu_Destination;
mu_me.mu_IsInList = mu_false;
mu_Consume_Message ( mu_i );
}
else
{
Error.Error("Error: Got unexpected Del_Ack");
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
    static mu_1_NetIndex mu_j2;
    mu_j2.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_j1;
    mu_j1.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("ChNext messages for any cells, j2:%s, j1:%s, i:%s", mu_j2.Name(), mu_j1.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NetIndex mu_j2;
    mu_j2.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_j1;
    mu_j1.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
bool mu__boolexpr7;
bool mu__boolexpr8;
bool mu__boolexpr9;
bool mu__boolexpr10;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_ChNext)) ; 
}
  if (!(mu__boolexpr10)) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_j1) != (mu_j2)) ; 
}
  if (!(mu__boolexpr9)) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = (mu_Net.mu_Ar[mu_j1].mu_MType.isundefined()) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = (mu_Net.mu_Ar[mu_j2].mu_MType.isundefined()) ; 
}
  return mu__boolexpr7;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 7;
    static mu_1_NetIndex mu_j2;
    mu_j2.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_j1;
    mu_j1.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    while (what_rule < 350 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr11;
bool mu__boolexpr12;
bool mu__boolexpr13;
bool mu__boolexpr14;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_ChNext)) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_j1) != (mu_j2)) ; 
}
  if (!(mu__boolexpr13)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = (mu_Net.mu_Ar[mu_j1].mu_MType.isundefined()) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = (mu_Net.mu_Ar[mu_j2].mu_MType.isundefined()) ; 
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
    r = what_rule - 7;
    mu_j2.value((r % 7) + 5);
    r = r / 7;
    mu_j1.value((r % 7) + 5);
    r = r / 7;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NetIndex mu_j2;
    mu_j2.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_j1;
    mu_j1.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
{
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_i];
  mu_1_CellPtr& mu_n = mu_msg.mu_Destination;
  mu_1_Cell& mu_me = mu_Cells[mu_msg.mu_Destination];
bool mu__boolexpr15;
  if ((mu_me.mu_State) == (mu_Normal)) mu__boolexpr15 = TRUE ;
  else {
  mu__boolexpr15 = ((mu_me.mu_State) == (mu_Wait_Pred)) ; 
}
if ( mu__boolexpr15 )
{
if ( (mu_me.mu_Next) != (mu_msg.mu_Old) )
{
mu_Send_ChNext ( mu_j1, mu_Cells[mu_n].mu_Next, mu_n, mu_msg.mu_Old, mu_msg.mu_New );
mu_Consume_Message ( mu_i );
}
else
{
mu_me.mu_Next = mu_msg.mu_New;
mu_Send_Del_Ack ( mu_j1, mu_msg.mu_Old, mu_n );
mu_Send_Pred ( mu_j2, mu_msg.mu_New, mu_n );
mu_Consume_Message ( mu_i );
}
}
}
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
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("Pred messages for remote cells, j:%s, i:%s", mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
bool mu__boolexpr16;
bool mu__boolexpr17;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Pred)) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = (mu_Net.mu_Ar[mu_j].mu_MType.isundefined()) ; 
}
  return mu__boolexpr16;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 350;
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    while (what_rule < 399 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr18;
bool mu__boolexpr19;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Pred)) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = (mu_Net.mu_Ar[mu_j].mu_MType.isundefined()) ; 
}
              if (mu__boolexpr18) {
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
    r = what_rule - 350;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
{
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_i];
  mu_1_CellPtr& mu_n = mu_msg.mu_Destination;
  mu_1_Cell& mu_me = mu_Cells[mu_msg.mu_Destination];
switch ((int) mu_me.mu_State) {
case mu_Normal:
mu_Send_Pred ( mu_j, mu_me.mu_Next, mu_n );
mu_Consume_Message ( mu_i );
break;
case mu_Wait_Pred:
mu_me.mu_State = mu_Wait_Del_Ack;
mu_Send_ChNext ( mu_j, mu_msg.mu_Source, mu_n, mu_n, mu_me.mu_Next );
mu_Consume_Message ( mu_i );
break;
case mu_Wait_Head:
break;
default:
Error.Error("Error: Got Pred in funny state");
break;
}
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
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("Head messages for remote cells, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
bool mu__boolexpr20;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Head)) ; 
}
  return mu__boolexpr20;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 399;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    while (what_rule < 406 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr21;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Head)) ; 
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
    r = what_rule - 399;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
{
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_i];
  mu_1_Cell& mu_me = mu_Cells[mu_msg.mu_Destination];
if ( !((mu_me.mu_State) == (mu_Wait_Head)) ) Error.Error("Assertion failed: list6too.m, line 222.");
mu_me.mu_Next = mu_msg.mu_New;
mu_me.mu_IsInList = mu_true;
mu_me.mu_State = mu_Normal;
mu_Consume_Message ( mu_i );
}
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
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("Delete messages for home node, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
bool mu__boolexpr22;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Delete)) ; 
}
  return mu__boolexpr22;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 406;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    while (what_rule < 413 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr23;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Delete)) ; 
}
              if (mu__boolexpr23) {
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
    r = what_rule - 406;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
mu_Consume_Message ( mu_i );
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
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("Add messages for home node, headptr:%s, j:%s, i:%s", mu_headptr.Name(), mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
bool mu__boolexpr24;
bool mu__boolexpr25;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Add)) ; 
}
  if (!(mu__boolexpr25)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = (mu_Net.mu_Ar[mu_j].mu_MType.isundefined()) ; 
}
  return mu__boolexpr24;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 413;
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    while (what_rule < 462 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr26;
bool mu__boolexpr27;
  if (!(!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined()))) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Add)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = (mu_Net.mu_Ar[mu_j].mu_MType.isundefined()) ; 
}
              if (mu__boolexpr26) {
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
    r = what_rule - 413;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_j;
    mu_j.value((r % 7) + 5);
    r = r / 7;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
{
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_i];
  mu_1_Cell& mu_me = mu_Cells[mu_msg.mu_Destination];
if ( (mu_me.mu_State) == (mu_Normal) )
{
mu_Send_Head ( mu_j, mu_msg.mu_Source, (int)mu_headptr, mu_me.mu_Next );
mu_me.mu_Next = mu_msg.mu_Source;
mu_Consume_Message ( mu_i );
}
}
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
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
    return tsprintf("Rule 1, c:%s", mu_c.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
bool mu__boolexpr28;
bool mu__boolexpr29;
  if (!((mu_Cells[mu_c].mu_State) == (mu_Normal))) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = (mu_Cells[mu_c].mu_IsInList) ; 
}
  if (!(mu__boolexpr29)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_Net.mu_Count) < (4)) ; 
}
  return mu__boolexpr28;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 462;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
    while (what_rule < 465 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr30;
bool mu__boolexpr31;
  if (!((mu_Cells[mu_c].mu_State) == (mu_Normal))) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = (mu_Cells[mu_c].mu_IsInList) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_Net.mu_Count) < (4)) ; 
}
              if (mu__boolexpr30) {
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
    r = what_rule - 462;
    mu_c.value((r % 3) + 2);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
mu_Cells[mu_c].mu_State = mu_Wait_Pred;
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
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
    return tsprintf("Rule 0, headptr:%s, i:%s, c:%s", mu_headptr.Name(), mu_i.Name(), mu_c.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined())) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_Cells[mu_c].mu_State) == (mu_Normal)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = (!(mu_Cells[mu_c].mu_IsInList)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_Net.mu_Count) < (4)) ; 
}
  return mu__boolexpr32;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 465;
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
    while (what_rule < 486 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr35;
bool mu__boolexpr36;
bool mu__boolexpr37;
  if (!(mu_Net.mu_Ar[mu_i].mu_MType.isundefined())) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_Cells[mu_c].mu_State) == (mu_Normal)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = (!(mu_Cells[mu_c].mu_IsInList)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_Net.mu_Count) < (4)) ; 
}
              if (mu__boolexpr35) {
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
    r = what_rule - 465;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    mu_c.value((r % 3) + 2);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    static mu_1_RestCells mu_c;
    mu_c.value((r % 3) + 2);
    r = r / 3;
mu_Send_Add ( mu_i, (int)mu_headptr, (int)mu_c );
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
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<7)
    { R0.NextRule(what_rule);
      if (what_rule<7) return; }
  if (what_rule>=7 && what_rule<350)
    { R1.NextRule(what_rule);
      if (what_rule<350) return; }
  if (what_rule>=350 && what_rule<399)
    { R2.NextRule(what_rule);
      if (what_rule<399) return; }
  if (what_rule>=399 && what_rule<406)
    { R3.NextRule(what_rule);
      if (what_rule<406) return; }
  if (what_rule>=406 && what_rule<413)
    { R4.NextRule(what_rule);
      if (what_rule<413) return; }
  if (what_rule>=413 && what_rule<462)
    { R5.NextRule(what_rule);
      if (what_rule<462) return; }
  if (what_rule>=462 && what_rule<465)
    { R6.NextRule(what_rule);
      if (what_rule<465) return; }
  if (what_rule>=465 && what_rule<486)
    { R7.NextRule(what_rule);
      if (what_rule<486) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=6) return R0.Condition(r-0);
  if (r>=7 && r<=349) return R1.Condition(r-7);
  if (r>=350 && r<=398) return R2.Condition(r-350);
  if (r>=399 && r<=405) return R3.Condition(r-399);
  if (r>=406 && r<=412) return R4.Condition(r-406);
  if (r>=413 && r<=461) return R5.Condition(r-413);
  if (r>=462 && r<=464) return R6.Condition(r-462);
  if (r>=465 && r<=485) return R7.Condition(r-465);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=6) { R0.Code(r-0); return; } 
  if (r>=7 && r<=349) { R1.Code(r-7); return; } 
  if (r>=350 && r<=398) { R2.Code(r-350); return; } 
  if (r>=399 && r<=405) { R3.Code(r-399); return; } 
  if (r>=406 && r<=412) { R4.Code(r-406); return; } 
  if (r>=413 && r<=461) { R5.Code(r-413); return; } 
  if (r>=462 && r<=464) { R6.Code(r-462); return; } 
  if (r>=465 && r<=485) { R7.Code(r-465); return; } 
}
int Priority(unsigned short r)
{
  if (r<=6) { return R0.Priority(); } 
  if (r>=7 && r<=349) { return R1.Priority(); } 
  if (r>=350 && r<=398) { return R2.Priority(); } 
  if (r>=399 && r<=405) { return R3.Priority(); } 
  if (r>=406 && r<=412) { return R4.Priority(); } 
  if (r>=413 && r<=461) { return R5.Priority(); } 
  if (r>=462 && r<=464) { return R6.Priority(); } 
  if (r>=465 && r<=485) { return R7.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=6) return R0.Name(r-0);
  if (r>=7 && r<=349) return R1.Name(r-7);
  if (r>=350 && r<=398) return R2.Name(r-350);
  if (r>=399 && r<=405) return R3.Name(r-399);
  if (r>=406 && r<=412) return R4.Name(r-406);
  if (r>=413 && r<=461) return R5.Name(r-413);
  if (r>=462 && r<=464) return R6.Name(r-462);
  if (r>=465 && r<=485) return R7.Name(r-465);
  return NULL;
}
};
const unsigned numrules = 486;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 486


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
    return tsprintf("Startstate 0, headptr:%s, i:%s", mu_headptr.Name(), mu_i.Name());
  }
  void Code(unsigned short r)
  {
    static mu_1_HeadCell mu_headptr;
    mu_headptr.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NetIndex mu_i;
    mu_i.value((r % 7) + 5);
    r = r / 7;
{
for(int mu_c = 1; mu_c <= 4; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 4 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
mu_Cells[mu_c].mu_Next = mu_c;
mu_Cells[mu_c].mu_State = mu_Normal;
mu_Cells[mu_c].mu_IsInList = mu_false;
};
};
mu_Cells[mu_headptr].mu_IsInList = mu_true;
mu_Net.undefine();
mu_Net.mu_Count = 0;
mu_Send_Pred ( mu_i, mu_Cells[mu_headptr].mu_Next, (int)mu_headptr );
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
  if (r<=6) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=6) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 7;

/********************
  Invariant records
 ********************/
int mu__invariant_38() // Invariant "Dead cells point to themselves"
{
bool mu__quant39; 
mu__quant39 = TRUE;
{
for(int mu_c = 1; mu_c <= 4; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 4 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
bool mu__boolexpr40;
bool mu__boolexpr41;
  if (!(!(mu_Cells[mu_c].mu_IsInList))) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_Cells[mu_c].mu_State) == (mu_Normal)) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = TRUE ;
  else {
  mu__boolexpr40 = ((mu_Cells[mu_c].mu_Next) == (mu_c)) ; 
}
if ( !(mu__boolexpr40) )
  { mu__quant39 = FALSE; break; }
};
};
return mu__quant39;
};

bool mu__condition_42() // Condition for Rule "Dead cells point to themselves"
{
  return mu__invariant_38( );
}

/**** end rule declaration ****/

int mu__invariant_43() // Invariant "Next is in list"
{
bool mu__boolexpr44;
bool mu__quant45; 
mu__quant45 = TRUE;
{
for(int mu_c = 1; mu_c <= 4; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 4 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
if ( !((mu_Cells[mu_c].mu_State) == (mu_Normal)) )
  { mu__quant45 = FALSE; break; }
};
};
  if (!(mu__quant45)) mu__boolexpr44 = TRUE ;
  else {
bool mu__quant46; 
mu__quant46 = TRUE;
{
for(int mu_c = 1; mu_c <= 4; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 4 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
bool mu__boolexpr47;
  if (!(mu_Cells[mu_c].mu_IsInList)) mu__boolexpr47 = TRUE ;
  else {
  mu__boolexpr47 = (mu_Cells[mu_Cells[mu_c].mu_Next].mu_IsInList) ; 
}
if ( !(mu__boolexpr47) )
  { mu__quant46 = FALSE; break; }
};
};
  mu__boolexpr44 = (mu__quant46) ; 
}
return mu__boolexpr44;
};

bool mu__condition_48() // Condition for Rule "Next is in list"
{
  return mu__invariant_43( );
}

/**** end rule declaration ****/

int mu__invariant_49() // Invariant "Prev is in list"
{
bool mu__boolexpr50;
bool mu__quant51; 
mu__quant51 = TRUE;
{
for(int mu_c = 1; mu_c <= 4; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 4 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
if ( !((mu_Cells[mu_c].mu_State) == (mu_Normal)) )
  { mu__quant51 = FALSE; break; }
};
};
  if (!(mu__quant51)) mu__boolexpr50 = TRUE ;
  else {
bool mu__quant52; 
mu__quant52 = TRUE;
{
for(int mu_c = 1; mu_c <= 4; mu_c++)
  if (( ( mu_c >= 2 ) && ( mu_c <= 4 ) )|| ( ( mu_c >= 1 ) && ( mu_c <= 1 ) )) {
bool mu__boolexpr53;
  if (!(mu_Cells[mu_c].mu_IsInList)) mu__boolexpr53 = TRUE ;
  else {
bool mu__quant54; 
mu__quant54 = FALSE;
{
for(int mu_p = 1; mu_p <= 4; mu_p++)
  if (( ( mu_p >= 2 ) && ( mu_p <= 4 ) )|| ( ( mu_p >= 1 ) && ( mu_p <= 1 ) )) {
bool mu__boolexpr55;
bool mu__boolexpr56;
  if (!((mu_Cells[mu_p].mu_Next) == (mu_c))) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = (mu_Cells[mu_p].mu_IsInList) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
bool mu__quant57; 
mu__quant57 = TRUE;
{
for(int mu_q = 1; mu_q <= 4; mu_q++)
  if (( ( mu_q >= 2 ) && ( mu_q <= 4 ) )|| ( ( mu_q >= 1 ) && ( mu_q <= 1 ) )) {
bool mu__boolexpr58;
  if (!((mu_Cells[mu_q].mu_Next) == (mu_c))) mu__boolexpr58 = TRUE ;
  else {
  mu__boolexpr58 = ((mu_p) == (mu_q)) ; 
}
if ( !(mu__boolexpr58) )
  { mu__quant57 = FALSE; break; }
};
};
  mu__boolexpr55 = (mu__quant57) ; 
}
if ( (mu__boolexpr55) )
  { mu__quant54 = TRUE; break; }
};
};
  mu__boolexpr53 = (mu__quant54) ; 
}
if ( !(mu__boolexpr53) )
  { mu__quant52 = FALSE; break; }
};
};
  mu__boolexpr50 = (mu__quant52) ; 
}
return mu__boolexpr50;
};

bool mu__condition_59() // Condition for Rule "Prev is in list"
{
  return mu__invariant_49( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Prev is in list", &mu__condition_59, NULL, FALSE},
{"Next is in list", &mu__condition_48, NULL, FALSE},
{"Dead cells point to themselves", &mu__condition_42, NULL, FALSE},
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
Net:ScalarsetArrayOfScalarset
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
  int class_mu_1_NetIndex[7];
  int undefined_class_mu_1_NetIndex;// has the highest class number

  void Print_class_mu_1_NetIndex();
  bool OnlyOneRemain_mu_1_NetIndex;
  bool MTO_class_mu_1_NetIndex()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_NetIndex)
      return FALSE;
    for (i=0; i<7; i++)
      for (j=0; j<7; j++)
        if (i!=j && class_mu_1_NetIndex[i]== class_mu_1_NetIndex[j])
	    return TRUE;
    OnlyOneRemain_mu_1_NetIndex = TRUE;
    return FALSE;
  }
  int class_mu_1_RestCells[3];
  int undefined_class_mu_1_RestCells;// has the highest class number

  void Print_class_mu_1_RestCells();
  bool OnlyOneRemain_mu_1_RestCells;
  bool MTO_class_mu_1_RestCells()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_RestCells)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
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
  int * in_mu_1_NetIndex;
  typedef int arr_mu_1_NetIndex[7];
  arr_mu_1_NetIndex * perm_mu_1_NetIndex;
  arr_mu_1_NetIndex * revperm_mu_1_NetIndex;

  int size_mu_1_NetIndex[7];
  bool reversed_sorted_mu_1_NetIndex(int start, int end);
  void reverse_reversed_mu_1_NetIndex(int start, int end);

  int * in_mu_1_RestCells;
  typedef int arr_mu_1_RestCells[3];
  arr_mu_1_RestCells * perm_mu_1_RestCells;
  arr_mu_1_RestCells * revperm_mu_1_RestCells;

  int size_mu_1_RestCells[3];
  bool reversed_sorted_mu_1_RestCells(int start, int end);
  void reverse_reversed_mu_1_RestCells(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_NetIndex* perm, int size, mu_1_NetIndex k);
  void GenPerm0(mu_1_NetIndex* perm, int size, unsigned long& index);

  bool ok1(mu_1_RestCells* perm, int size, mu_1_RestCells k);
  void GenPerm1(mu_1_RestCells* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_NetIndex()
{
  cout << "class_mu_1_NetIndex:\t";
  for (int i=0; i<7; i++)
    cout << class_mu_1_NetIndex[i];
  cout << " " << undefined_class_mu_1_NetIndex << "\n";
}
void PermSet::Print_class_mu_1_RestCells()
{
  cout << "class_mu_1_RestCells:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_RestCells[i];
  cout << " " << undefined_class_mu_1_RestCells << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<7; i++)
      for (j=0; j<7; j++)
        if (i!=j && class_mu_1_NetIndex[i]== class_mu_1_NetIndex[j])
	    return TRUE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
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
    mu_1_NetIndex Perm0[7];
    mu_1_RestCells Perm1[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[30240];
 in_mu_1_NetIndex = new int[30240];
 perm_mu_1_NetIndex = new arr_mu_1_NetIndex[5040];
 revperm_mu_1_NetIndex = new arr_mu_1_NetIndex[5040];
 in_mu_1_RestCells = new int[30240];
 perm_mu_1_RestCells = new arr_mu_1_RestCells[6];
 revperm_mu_1_RestCells = new arr_mu_1_RestCells[6];

    // Set perm and revperm
    count = 0;
    for (i=5; i<=11; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=5040)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<5040; i++)
      for (j=5; j<=11; j++)
        for (k=5; k<=11; k++)
          if (revperm_mu_1_NetIndex[i][k-5]==j)   // k - base 
            perm_mu_1_NetIndex[i][j-5]=k; // j - base 
    count = 0;
    for (i=2; i<=4; i++)
      {
        Perm1[0].value(i);
        GenPerm1(Perm1, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=2; j<=4; j++)
        for (k=2; k<=4; k++)
          if (revperm_mu_1_RestCells[i][k-2]==j)   // k - base 
            perm_mu_1_RestCells[i][j-2]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_NetIndex = 0;
    int i_mu_1_RestCells = 0;
    size = 30240;
    count = 30240;
    for (i=0; i<30240; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_NetIndex[i] = i_mu_1_NetIndex;
      i_mu_1_NetIndex += carry;
      if (i_mu_1_NetIndex >= 5040) { i_mu_1_NetIndex = 0; carry = 1; } 
      else { carry = 0; } 
      in_mu_1_RestCells[i] = i_mu_1_RestCells;
      i_mu_1_RestCells += carry;
      if (i_mu_1_RestCells >= 6) { i_mu_1_RestCells = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_NetIndex = new int[1];
 perm_mu_1_NetIndex = new arr_mu_1_NetIndex[1];
 revperm_mu_1_NetIndex = new arr_mu_1_NetIndex[1];
 in_mu_1_RestCells = new int[1];
 perm_mu_1_RestCells = new arr_mu_1_RestCells[1];
 revperm_mu_1_RestCells = new arr_mu_1_RestCells[1];
  in[0] = TRUE;
    in_mu_1_NetIndex[0] = 0;
    in_mu_1_RestCells[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<7; i++)
    class_mu_1_NetIndex[i]=0;
  undefined_class_mu_1_NetIndex=0;
  OnlyOneRemain_mu_1_NetIndex = FALSE;
  for (i=0; i<3; i++)
    class_mu_1_RestCells[i]=0;
  undefined_class_mu_1_RestCells=0;
  OnlyOneRemain_mu_1_RestCells = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<30240; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_NetIndex[7];
  int size_mu_1_NetIndex[7];
  bool should_be_in_mu_1_NetIndex[5040];
  int start_mu_1_RestCells[3];
  int size_mu_1_RestCells[3];
  bool should_be_in_mu_1_RestCells[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NetIndex; j++) // class number
    {
      class_size = 0;
      for (k=0; k<7; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NetIndex[k]==j)
	  class_size++;
      for (k=0; k<7; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NetIndex[k]==j)
	  {
	    size_mu_1_NetIndex[k] = class_size;
	    start_mu_1_NetIndex[k] = start;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_RestCells; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  {
	    size_mu_1_RestCells[k] = class_size;
	    start_mu_1_RestCells[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<5040; i++) // set up
    should_be_in_mu_1_NetIndex[i] = TRUE;
  for (i=0; i<5040; i++) // to be in or not to be
    for (k=0; k<7; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_NetIndex[i][k]-5 >=start_mu_1_NetIndex[k] 
	     && perm_mu_1_NetIndex[i][k]-5 < start_mu_1_NetIndex[k] + size_mu_1_NetIndex[k]) )
  	    {
	      should_be_in_mu_1_NetIndex[i] = FALSE;
	      break;
	    }
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_RestCells[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_RestCells[i][k]-2 >=start_mu_1_RestCells[k] 
	     && perm_mu_1_RestCells[i][k]-2 < start_mu_1_RestCells[k] + size_mu_1_RestCells[k]) )
  	    {
	      should_be_in_mu_1_RestCells[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<30240; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_NetIndex[in_mu_1_NetIndex[i]]) in[i] = FALSE;
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
  for (j=0; j<=undefined_class_mu_1_NetIndex; j++) // class number
    {
      class_size = 0;
      for (k=0; k<7; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NetIndex[k]==j)
	  class_size++;
      for (k=0; k<7; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NetIndex[k]==j)
	  {
	    size_mu_1_NetIndex[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_RestCells; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_RestCells[k]==j)
	  {
	    size_mu_1_RestCells[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NetIndex; j++) // class number
    {
      for (k=0; k<7; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_NetIndex[k]==j)
	      revperm_mu_1_NetIndex[0][start++] = k+5;
    }
  for (j=0; j<7; j++)
    for (k=0; k<7; k++)
      if (revperm_mu_1_NetIndex[0][k]==j+5)
        perm_mu_1_NetIndex[0][j]=k+5;
  start = 0;
  for (j=0; j<=undefined_class_mu_1_RestCells; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_RestCells[k]==j)
	      revperm_mu_1_RestCells[0][start++] = k+2;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_RestCells[0][k]==j+2)
        perm_mu_1_RestCells[0][j]=k+2;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_NetIndex* Perm, int size, mu_1_NetIndex k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_NetIndex* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=7)
    {
      for (i=5; i<=11; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=5; i<=11; i++)
        revperm_mu_1_NetIndex[count][i-5]=Perm[i-5].value();// i - base
      count++;
    }
}
bool PermSet::ok1(mu_1_RestCells* Perm, int size, mu_1_RestCells k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm1(mu_1_RestCells* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=2; i<=4; i++)
        if(ok1(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm1(Perm, size+1, count);
          }
    }
  else
    {
      for (i=2; i<=4; i++)
        revperm_mu_1_RestCells[count][i-2]=Perm[i-2].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_NetIndex(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_NetIndex[0][i]<revperm_mu_1_NetIndex[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_NetIndex(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_NetIndex[0][j];
      revperm_mu_1_NetIndex[0][j] = revperm_mu_1_NetIndex[0][i];
      revperm_mu_1_NetIndex[0][i] = temp;
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
  for (start = 0; start < 7; )
    {
      end = start-1+size_mu_1_NetIndex[revperm_mu_1_NetIndex[0][start]-5];
      if (reversed_sorted_mu_1_NetIndex(start,end))
	       {
	  reverse_reversed_mu_1_NetIndex(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_NetIndex(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_NetIndex[0][j]<revperm_mu_1_NetIndex[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_NetIndex[0][j];
			  revperm_mu_1_NetIndex[0][j] = revperm_mu_1_NetIndex[0][k];
			  revperm_mu_1_NetIndex[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_NetIndex(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) {
  for (start = 0; start < 3; )
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
}
if (!nexted) return FALSE;
  for (j=0; j<7; j++)
    for (k=0; k<7; k++)
      if (revperm_mu_1_NetIndex[0][k]==j+5)   // k - base 
	perm_mu_1_NetIndex[0][j]=k+5; // j - base 
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
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
void mu_1_HeadCell::Permute(PermSet& Perm, int i) {}
void mu_1_HeadCell::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_HeadCell::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_HeadCell::SimpleLimit(PermSet& Perm) {}
void mu_1_HeadCell::ArrayLimit(PermSet& Perm) {}
void mu_1_HeadCell::Limit(PermSet& Perm) {}
void mu_1_HeadCell::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
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
        for (i=0; i<3; i++)
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
        for (i=0; i<3; i++)
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
    if ( ( value() >= 2 ) && ( value() <= 4 ) )
      value(Perm.perm_mu_1_RestCells[Perm.in_mu_1_RestCells[i]][value()-2]+(0)); // value - base
  }
}
void mu_1_CellPtr::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 4 ) )
      {
        if (Perm.class_mu_1_RestCells[value()-2]==Perm.undefined_class_mu_1_RestCells) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
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
    if ( ( value() >= 2 ) && ( value() <= 4 ) )
      if (Perm.class_mu_1_RestCells[value()-2]==Perm.undefined_class_mu_1_RestCells) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
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
void mu_1_NetIndex::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_NetIndex[Perm.in_mu_1_NetIndex[i]][value()-5]); // value - base
};
void mu_1_NetIndex::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_NetIndex[value()-5]==Perm.undefined_class_mu_1_NetIndex) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<7; i++)
          if (Perm.class_mu_1_NetIndex[i] == Perm.undefined_class_mu_1_NetIndex && i!=value()-5)
            Perm.class_mu_1_NetIndex[i]++;
        value(5 + Perm.undefined_class_mu_1_NetIndex++);
      }
    else 
      {
        value(Perm.class_mu_1_NetIndex[value()-5]+5);
      }
}
void mu_1_NetIndex::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_NetIndex::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_NetIndex[value()-5]==Perm.undefined_class_mu_1_NetIndex) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<7; i++)
          if (Perm.class_mu_1_NetIndex[i] == Perm.undefined_class_mu_1_NetIndex && i!=value()-5)
            Perm.class_mu_1_NetIndex[i]++;
        Perm.undefined_class_mu_1_NetIndex++;
      }
}
void mu_1_NetIndex::ArrayLimit(PermSet& Perm) {}
void mu_1_NetIndex::Limit(PermSet& Perm) {}
void mu_1_NetIndex::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
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
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=4; j++)
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
  static mu_1_Cell value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_RestCells;
  bool pos_mu_1_RestCells[3][3];
  bool goodset_mu_1_RestCells[3];
  // sorting mu_1_RestCells
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_RestCells())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_RestCells[i][j]=FALSE;
      count_mu_1_RestCells = 0;
      for (i=0; i<3; i++)
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
                      for (z=0; z<3; z++)
                        pos_mu_1_RestCells[k][z] = pos_mu_1_RestCells[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<3; z++)
                    pos_mu_1_RestCells[j][z] = FALSE;
                  pos_mu_1_RestCells[j][i] = TRUE;
                  count_mu_1_RestCells++;
                  break;
                }
            }
          if (j==count_mu_1_RestCells)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<3; z++)
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
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_RestCells; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_RestCells[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_RestCells[i][k] && Perm.class_mu_1_RestCells[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_RestCells[k] = TRUE;
                    pos_mu_1_RestCells[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_RestCells[k] == j && !goodset_mu_1_RestCells[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
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
  static mu_1_Cell value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_RestCells, oldcount_mu_1_RestCells;
  bool pos_mu_1_RestCells[3][3];
  bool goodset_mu_1_RestCells[3];
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_RestCells[i][j]=FALSE;
  count_mu_1_RestCells = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
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
  if (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
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
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_RestCells[k] = FALSE;
              for (k=0; k<3; k++) // step through class
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
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_RestCells[i][k] && !goodset_mu_1_RestCells[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_RestCells; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_RestCells[j][k] = pos_mu_1_RestCells[j-1][k];
                      for (k=0; k<3; k++)
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
  while_guard = while_guard || (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3);
  while ( while_guard )
    {
      oldcount_mu_1_RestCells = count_mu_1_RestCells;

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+2].mu_Next.isundefined()
                &&(*this)[k+2].mu_Next!=k+2
                &&(*this)[k+2].mu_Next>=2
                &&(*this)[k+2].mu_Next<=4)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_RestCells; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_RestCells; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_RestCells[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_RestCells[i][k] 
                            && !(*this)[k+2].mu_Next.isundefined()
                            && (*this)[k+2].mu_Next!=k+2
                            && (*this)[k+2].mu_Next>=2
                            && (*this)[k+2].mu_Next<=4
                            && pos_mu_1_RestCells[j][(*this)[k+2].mu_Next-2])
                          {
                            exists = TRUE;
                            goodset_mu_1_RestCells[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_RestCells[i][k] && !goodset_mu_1_RestCells[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_RestCells; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_RestCells[j][k] = pos_mu_1_RestCells[j-1][k];
                              for (k=0; k<3; k++)
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
      while_guard = while_guard || count_mu_1_RestCells<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_RestCells())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_RestCells[i][j])
            Perm.class_mu_1_RestCells[j] = i;
      Perm.undefined_class_mu_1_RestCells=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_RestCells[j]>Perm.undefined_class_mu_1_RestCells)
          Perm.undefined_class_mu_1_RestCells=Perm.class_mu_1_RestCells[j];
    }
}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<7; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=5; j<=11; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_NetIndex[Perm.in_mu_1_NetIndex[i]][j-5]];};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_NetIndex;
  int compare;
  static mu_1_Message value[7];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_NetIndex[7];
  bool pos_mu_1_NetIndex[7][7];
  // sorting mu_1_NetIndex
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NetIndex())
    {
      for (i=0; i<7; i++)
        for (j=0; j<7; j++)
          pos_mu_1_NetIndex[i][j]=FALSE;
      count_mu_1_NetIndex = 0;
      for (i=0; i<7; i++)
        {
          for (j=0; j<count_mu_1_NetIndex; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+5]);
              if (compare==0)
                {
                  pos_mu_1_NetIndex[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_NetIndex; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<7; z++)
                        pos_mu_1_NetIndex[k][z] = pos_mu_1_NetIndex[k-1][z];
                    }
                  value[j] = (*this)[i+5];
                  for (z=0; z<7; z++)
                    pos_mu_1_NetIndex[j][z] = FALSE;
                  pos_mu_1_NetIndex[j][i] = TRUE;
                  count_mu_1_NetIndex++;
                  break;
                }
            }
          if (j==count_mu_1_NetIndex)
            {
              value[j] = (*this)[i+5];
              for (z=0; z<7; z++)
                pos_mu_1_NetIndex[j][z] = FALSE;
              pos_mu_1_NetIndex[j][i] = TRUE;
              count_mu_1_NetIndex++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NetIndex() && count_mu_1_NetIndex>1)
    {
      // limit
      for (j=0; j<7; j++) // class priority
        {
          for (i=0; i<count_mu_1_NetIndex; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<7; k++) // step through class
                goodset_mu_1_NetIndex[k] = FALSE;
              for (k=0; k<7; k++) // step through class
                if (pos_mu_1_NetIndex[i][k] && Perm.class_mu_1_NetIndex[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_NetIndex[k] = TRUE;
                    pos_mu_1_NetIndex[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<7; k++)
                    if ( Perm.class_mu_1_NetIndex[k] == j && !goodset_mu_1_NetIndex[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<7; k++)
                        if (Perm.class_mu_1_NetIndex[k]>j
                            || ( Perm.class_mu_1_NetIndex[k] == j && !goodset_mu_1_NetIndex[k] ) )
                          Perm.class_mu_1_NetIndex[k]++;
                      Perm.undefined_class_mu_1_NetIndex++;
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
  static mu_1_Message value[7];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_NetIndex, oldcount_mu_1_NetIndex;
  bool pos_mu_1_NetIndex[7][7];
  bool goodset_mu_1_NetIndex[7];
  int count_mu_1_RestCells, oldcount_mu_1_RestCells;
  bool pos_mu_1_RestCells[3][3];
  bool goodset_mu_1_RestCells[3];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<7; i++)
    for (j=0; j<7; j++)
      pos_mu_1_NetIndex[i][j]=FALSE;
  count_mu_1_NetIndex = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<7; i++)
       if (Perm.class_mu_1_NetIndex[i] == count_mu_1_NetIndex)
         {
           pos_mu_1_NetIndex[count_mu_1_NetIndex][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_NetIndex++;
      else break;
    }
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_RestCells[i][j]=FALSE;
  count_mu_1_RestCells = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_RestCells[i] == count_mu_1_RestCells)
         {
           pos_mu_1_RestCells[count_mu_1_RestCells][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_RestCells++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_NetIndex() && count_mu_1_NetIndex<7);
  while_guard = while_guard || (Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3);
  while ( while_guard )
    {
      oldcount_mu_1_NetIndex = count_mu_1_NetIndex;
      oldcount_mu_1_RestCells = count_mu_1_RestCells;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_NetIndex() && count_mu_1_NetIndex<7)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<7; k++) // step through class
            if ((*this)[k+5].mu_Source.isundefined()
                ||(*this)[k+5].mu_Source<2
                ||(*this)[k+5].mu_Source>4)
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_NetIndex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<7; k++) // initialize goodset
                      goodset_mu_1_NetIndex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<7; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_NetIndex[i][k] 
                          && !(*this)[k+5].mu_Source.isundefined()
                          && (*this)[k+5].mu_Source>=2
                          && (*this)[k+5].mu_Source<=4
                          && pos_mu_1_RestCells[j][(*this)[k+5].mu_Source-2])
                        {
                          exists = TRUE;
                          goodset_mu_1_NetIndex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k+5].mu_Source-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<7; k++)
                          if ( pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_NetIndex; z>i; z--)
                              for (k=0; k<7; k++)
                                pos_mu_1_NetIndex[z][k] = pos_mu_1_NetIndex[z-1][k];
                            // split pos
                            for (k=0; k<7; k++)
                              {
                                if (pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i][k] = FALSE;
                                if (pos_mu_1_NetIndex[i+1][k] && goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i+1][k] = FALSE;
                              }
                            count_mu_1_NetIndex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
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
      if ( (Perm.MTO_class_mu_1_NetIndex() && count_mu_1_NetIndex<7)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<7; k++) // step through class
            if ((*this)[k+5].mu_Destination.isundefined()
                ||(*this)[k+5].mu_Destination<2
                ||(*this)[k+5].mu_Destination>4)
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_NetIndex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<7; k++) // initialize goodset
                      goodset_mu_1_NetIndex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<7; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_NetIndex[i][k] 
                          && !(*this)[k+5].mu_Destination.isundefined()
                          && (*this)[k+5].mu_Destination>=2
                          && (*this)[k+5].mu_Destination<=4
                          && pos_mu_1_RestCells[j][(*this)[k+5].mu_Destination-2])
                        {
                          exists = TRUE;
                          goodset_mu_1_NetIndex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k+5].mu_Destination-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<7; k++)
                          if ( pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_NetIndex; z>i; z--)
                              for (k=0; k<7; k++)
                                pos_mu_1_NetIndex[z][k] = pos_mu_1_NetIndex[z-1][k];
                            // split pos
                            for (k=0; k<7; k++)
                              {
                                if (pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i][k] = FALSE;
                                if (pos_mu_1_NetIndex[i+1][k] && goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i+1][k] = FALSE;
                              }
                            count_mu_1_NetIndex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
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
      if ( (Perm.MTO_class_mu_1_NetIndex() && count_mu_1_NetIndex<7)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<7; k++) // step through class
            if ((*this)[k+5].mu_Old.isundefined()
                ||(*this)[k+5].mu_Old<2
                ||(*this)[k+5].mu_Old>4)
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_NetIndex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<7; k++) // initialize goodset
                      goodset_mu_1_NetIndex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<7; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_NetIndex[i][k] 
                          && !(*this)[k+5].mu_Old.isundefined()
                          && (*this)[k+5].mu_Old>=2
                          && (*this)[k+5].mu_Old<=4
                          && pos_mu_1_RestCells[j][(*this)[k+5].mu_Old-2])
                        {
                          exists = TRUE;
                          goodset_mu_1_NetIndex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k+5].mu_Old-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<7; k++)
                          if ( pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_NetIndex; z>i; z--)
                              for (k=0; k<7; k++)
                                pos_mu_1_NetIndex[z][k] = pos_mu_1_NetIndex[z-1][k];
                            // split pos
                            for (k=0; k<7; k++)
                              {
                                if (pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i][k] = FALSE;
                                if (pos_mu_1_NetIndex[i+1][k] && goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i+1][k] = FALSE;
                              }
                            count_mu_1_NetIndex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
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
      if ( (Perm.MTO_class_mu_1_NetIndex() && count_mu_1_NetIndex<7)
           || ( Perm.MTO_class_mu_1_RestCells() && count_mu_1_RestCells<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<7; k++) // step through class
            if ((*this)[k+5].mu_New.isundefined()
                ||(*this)[k+5].mu_New<2
                ||(*this)[k+5].mu_New>4)
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_NetIndex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_RestCells; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<7; k++) // initialize goodset
                      goodset_mu_1_NetIndex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_RestCells[k] = FALSE;
                    for (k=0; k<7; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_NetIndex[i][k] 
                          && !(*this)[k+5].mu_New.isundefined()
                          && (*this)[k+5].mu_New>=2
                          && (*this)[k+5].mu_New<=4
                          && pos_mu_1_RestCells[j][(*this)[k+5].mu_New-2])
                        {
                          exists = TRUE;
                          goodset_mu_1_NetIndex[k] = TRUE;
                          goodset_mu_1_RestCells[(*this)[k+5].mu_New-2] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<7; k++)
                          if ( pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_NetIndex; z>i; z--)
                              for (k=0; k<7; k++)
                                pos_mu_1_NetIndex[z][k] = pos_mu_1_NetIndex[z-1][k];
                            // split pos
                            for (k=0; k<7; k++)
                              {
                                if (pos_mu_1_NetIndex[i][k] && !goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i][k] = FALSE;
                                if (pos_mu_1_NetIndex[i+1][k] && goodset_mu_1_NetIndex[k])
                                  pos_mu_1_NetIndex[i+1][k] = FALSE;
                              }
                            count_mu_1_NetIndex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_RestCells[j][k] && !goodset_mu_1_RestCells[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_RestCells; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_RestCells[z][k] = pos_mu_1_RestCells[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
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
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_NetIndex!=count_mu_1_NetIndex);
      while_guard = while_guard || (oldcount_mu_1_RestCells!=count_mu_1_RestCells);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_NetIndex<7;
      while_guard = while_guard || count_mu_1_RestCells<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_NetIndex())
    {
      for (i=0; i<7; i++)
        for (j=0; j<7; j++)
          if (pos_mu_1_NetIndex[i][j])
            Perm.class_mu_1_NetIndex[j] = i;
      Perm.undefined_class_mu_1_NetIndex=0;
      for (j=0; j<7; j++)
        if (Perm.class_mu_1_NetIndex[j]>Perm.undefined_class_mu_1_NetIndex)
          Perm.undefined_class_mu_1_NetIndex=Perm.class_mu_1_NetIndex[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_RestCells())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_RestCells[i][j])
            Perm.class_mu_1_RestCells[j] = i;
      Perm.undefined_class_mu_1_RestCells=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_RestCells[j]>Perm.undefined_class_mu_1_RestCells)
          Perm.undefined_class_mu_1_RestCells=Perm.class_mu_1_RestCells[j];
    }
}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  mu_Ar.Permute(Perm,i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm)
{
  mu_Ar.ArrayLimit(Perm);
};
void mu_1__type_4::Limit(PermSet& Perm)
{
  mu_Ar.Limit(Perm);
};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
};

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
    mu_Net.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.Limit(Perm);
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
    mu_Net.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.Limit(Perm);
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
    mu_Net.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Cells.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.Limit(Perm);
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
