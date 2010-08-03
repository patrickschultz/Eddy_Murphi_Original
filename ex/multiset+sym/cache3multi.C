/******************************
  Program "cache3multi.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "cache3multi"
#define BITS_IN_WORLD 205
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Home: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Home& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Home& val)
    {
      if (val.defined())
        return ( s << mu_1_Home::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Home (char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_Home (void): mu__byte(1, 1, 1) {};
  mu_1_Home (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Home& a, mu_1_Home& b)
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
char *mu_1_Home::values[] =
  { "Home_1",NULL };

/*** end scalarset declaration ***/
mu_1_Home mu_1_Home_undefined_var;

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
        return ( s << mu_1_Proc::values[ int(val) - 2 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Proc (char *name, int os): mu__byte(2, 6, 3, name, os) {};
  mu_1_Proc (void): mu__byte(2, 6, 3) {};
  mu_1_Proc (int val): mu__byte(2, 6, 3, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -2]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 2] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
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
char *mu_1_Proc::values[] =
  { "Proc_1","Proc_2","Proc_3","Proc_4","Proc_5",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
        return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (char *name, int os): mu__byte(0, 5, 3, name, os) {};
  mu_1_Node (void): mu__byte(0, 5, 3) {};
  mu_1_Node (int val): mu__byte(0, 5, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int value() const
  {
    int val = mu__byte::value();
    // val == -1 if value undefined
    // we can return it since no enum/scalarsetid will have value -1
    if (val == -1) return -1;
    if (val <= 0) return val+1;
    if (val <= 5) return val+1;
  }
  inline int value(int val)
  {
    if (val == -1) { undefine(); return -1; }
    if ((val >= 1) && (val <= 1)) return (mu__byte::value(val-1)+1);
    if ((val >= 2) && (val <= 6)) return (mu__byte::value(val-1)+1);
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
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
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
char *mu_1_Node::values[] = {"Home_1","Proc_1","Proc_2","Proc_3","Proc_4","Proc_5",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_Address: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Address& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Address& val)
    {
      if (val.defined())
        return ( s << mu_1_Address::values[ int(val) - 7 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Address (char *name, int os): mu__byte(7, 7, 1, name, os) {};
  mu_1_Address (void): mu__byte(7, 7, 1) {};
  mu_1_Address (int val): mu__byte(7, 7, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -7]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 7] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Address& a, mu_1_Address& b)
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
char *mu_1_Address::values[] =
  { "Address_1",NULL };

/*** end scalarset declaration ***/
mu_1_Address mu_1_Address_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Value& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Value& val)
    {
      if (val.defined())
        return ( s << mu_1_Value::values[ int(val) - 8 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Value (char *name, int os): mu__byte(8, 9, 2, name, os) {};
  mu_1_Value (void): mu__byte(8, 9, 2) {};
  mu_1_Value (int val): mu__byte(8, 9, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -8]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 8] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Value& a, mu_1_Value& b)
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
char *mu_1_Value::values[] =
  { "Value_1","Value_2",NULL };

/*** end scalarset declaration ***/
mu_1_Value mu_1_Value_undefined_var;

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

  mu_1_Message_Type (char *name, int os): mu__byte(10, 24, 4, name, os) {};
  mu_1_Message_Type (void): mu__byte(10, 24, 4) {};
  mu_1_Message_Type (int val): mu__byte(10, 24, 4, "Parameter or function result.", 0)
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

char *mu_1_Message_Type::values[] = {"Cache_Read","Cache_Read_Ex","Cache_Promote","Uncache","Write_Back","Update","Data","Invalidate","Uncache_Ack","Write_Back_Ack","Inv_Ack","Fw_Cache_R","Fw_Cache_R_Ex","Ack_Fw_Cache_Ex","Cache_Promote_Ack",NULL };

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
  mu_1_Node mu_Source;
  mu_1_Node mu_Destination;
  mu_1_Node mu_Aux;
  mu_1_Address mu_Address;
  mu_1_Value mu_Value;
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
    w = CompareWeight(a.mu_Aux, b.mu_Aux);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Address, b.mu_Address);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Value, b.mu_Value);
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
    w = Compare(a.mu_Aux, b.mu_Aux);
    if (w!=0) return w;
    w = Compare(a.mu_Address, b.mu_Address);
    if (w!=0) return w;
    w = Compare(a.mu_Value, b.mu_Value);
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
    mu_Aux.MultisetSort();
    mu_Address.MultisetSort();
    mu_Value.MultisetSort();
  }
  void print_statistic()
  {
    mu_MType.print_statistic();
    mu_Source.print_statistic();
    mu_Destination.print_statistic();
    mu_Aux.print_statistic();
    mu_Address.print_statistic();
    mu_Value.print_statistic();
  }
  void clear() {
    mu_MType.clear();
    mu_Source.clear();
    mu_Destination.clear();
    mu_Aux.clear();
    mu_Address.clear();
    mu_Value.clear();
 };
  void undefine() {
    mu_MType.undefine();
    mu_Source.undefine();
    mu_Destination.undefine();
    mu_Aux.undefine();
    mu_Address.undefine();
    mu_Value.undefine();
 };
  void reset() {
    mu_MType.reset();
    mu_Source.reset();
    mu_Destination.reset();
    mu_Aux.reset();
    mu_Address.reset();
    mu_Value.reset();
 };
  void print() {
    mu_MType.print();
    mu_Source.print();
    mu_Destination.print();
    mu_Aux.print();
    mu_Address.print();
    mu_Value.print();
  };
  void print_diff(state *prevstate) {
    mu_MType.print_diff(prevstate);
    mu_Source.print_diff(prevstate);
    mu_Destination.print_diff(prevstate);
    mu_Aux.print_diff(prevstate);
    mu_Address.print_diff(prevstate);
    mu_Value.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_MType.to_state(thestate);
    mu_Source.to_state(thestate);
    mu_Destination.to_state(thestate);
    mu_Aux.to_state(thestate);
    mu_Address.to_state(thestate);
    mu_Value.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_MType.value(from.mu_MType.value());
    mu_Source.value(from.mu_Source.value());
    mu_Destination.value(from.mu_Destination.value());
    mu_Aux.value(from.mu_Aux.value());
    mu_Address.value(from.mu_Address.value());
    mu_Value.value(from.mu_Value.value());
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
  mu_Source.set_self_2(name, ".Source", os + 4 );
  mu_Destination.set_self_2(name, ".Destination", os + 7 );
  mu_Aux.set_self_2(name, ".Aux", os + 10 );
  mu_Address.set_self_2(name, ".Address", os + 13 );
  mu_Value.set_self_2(name, ".Value", os + 14 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_Value array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_0 (char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_Value& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 7 ) && ( index <= 7 ) )
      return array[ index - 7 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Address is internally represented from 7 to 7.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 7 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
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
array[i].set_self_ar(n,"Address_1", i * 2 + os);i++;
}
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_1& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_1& val)
  {
    if (val.defined())
      return ( s << mu_1__type_1::values[ int(val) - 25] );
    else return ( s << "Undefined" );
  };

  mu_1__type_1 (char *name, int os): mu__byte(25, 30, 3, name, os) {};
  mu_1__type_1 (void): mu__byte(25, 30, 3) {};
  mu_1__type_1 (int val): mu__byte(25, 30, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -25]; };
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
      cout << name << ":" << values[ value() -25] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_1::values[] = {"Inv","Shared_Remote","Master_Remote","Wait_Inv","Wait_Update","Wait_WB",NULL };

/*** end of enum declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__byte::operator=((int) val); };
  mu_1__type_2 (char *name, int os): mu__byte(0, 5, 3, name, os) {};
  mu_1__type_2 (void): mu__byte(0, 5, 3) {};
  mu_1__type_2 (int val): mu__byte(0, 5, 3, "Parameter or function result.", 0)
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

class mu__subrange_12: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_12& val) { return mu__byte::operator=((int) val); };
  mu__subrange_12 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_12 (void): mu__byte(0, 4, 3) {};
  mu__subrange_12 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_12 mu__subrange_12_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_Proc array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_Proc& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 4 ) )
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
    for (int i = 0; i < 5; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
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
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_4& val) { return mu__byte::operator=((int) val); };
  mu_1__type_4 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1__type_4 (void): mu__byte(0, 4, 3) {};
  mu_1__type_4 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_1 mu_State;
  mu_1__type_2 mu_Shared_Count;
  mu_1__type_3 mu_Entries;
  mu_1__type_4 mu_Inv_Count;
  mu_1__type_5 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_5 ( void ) {};

  virtual ~mu_1__type_5(); 
friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Shared_Count, b.mu_Shared_Count);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Entries, b.mu_Entries);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Inv_Count, b.mu_Inv_Count);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_Shared_Count, b.mu_Shared_Count);
    if (w!=0) return w;
    w = Compare(a.mu_Entries, b.mu_Entries);
    if (w!=0) return w;
    w = Compare(a.mu_Inv_Count, b.mu_Inv_Count);
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
    mu_State.MultisetSort();
    mu_Shared_Count.MultisetSort();
    mu_Entries.MultisetSort();
    mu_Inv_Count.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_Shared_Count.print_statistic();
    mu_Entries.print_statistic();
    mu_Inv_Count.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_Shared_Count.clear();
    mu_Entries.clear();
    mu_Inv_Count.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_Shared_Count.undefine();
    mu_Entries.undefine();
    mu_Inv_Count.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_Shared_Count.reset();
    mu_Entries.reset();
    mu_Inv_Count.reset();
 };
  void print() {
    mu_State.print();
    mu_Shared_Count.print();
    mu_Entries.print();
    mu_Inv_Count.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_Shared_Count.print_diff(prevstate);
    mu_Entries.print_diff(prevstate);
    mu_Inv_Count.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_Shared_Count.to_state(thestate);
    mu_Entries.to_state(thestate);
    mu_Inv_Count.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_5& operator= (const mu_1__type_5& from) {
    mu_State.value(from.mu_State.value());
    mu_Shared_Count.value(from.mu_Shared_Count.value());
    mu_Entries = from.mu_Entries;
    mu_Inv_Count.value(from.mu_Inv_Count.value());
    return *this;
  };
};

  void mu_1__type_5::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_Shared_Count.set_self_2(name, ".Shared_Count", os + 3 );
  mu_Entries.set_self_2(name, ".Entries", os + 6 );
  mu_Inv_Count.set_self_2(name, ".Inv_Count", os + 21 );
}

mu_1__type_5::~mu_1__type_5()
{
}

/*** end record declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1__type_5 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_6 (char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1__type_5& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 7 ) && ( index <= 7 ) )
      return array[ index - 7 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Address is internally represented from 7 to 7.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 7 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Address_1", i * 24 + os);i++;
}
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_Mem;
  mu_1__type_6 mu_Dir;
  mu_1_HomeState ( char *n, int os ) { set_self(n,os); };
  mu_1_HomeState ( void ) {};

  virtual ~mu_1_HomeState(); 
friend int CompareWeight(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = CompareWeight(a.mu_Mem, b.mu_Mem);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Dir, b.mu_Dir);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = Compare(a.mu_Mem, b.mu_Mem);
    if (w!=0) return w;
    w = Compare(a.mu_Dir, b.mu_Dir);
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
    mu_Mem.MultisetSort();
    mu_Dir.MultisetSort();
  }
  void print_statistic()
  {
    mu_Mem.print_statistic();
    mu_Dir.print_statistic();
  }
  void clear() {
    mu_Mem.clear();
    mu_Dir.clear();
 };
  void undefine() {
    mu_Mem.undefine();
    mu_Dir.undefine();
 };
  void reset() {
    mu_Mem.reset();
    mu_Dir.reset();
 };
  void print() {
    mu_Mem.print();
    mu_Dir.print();
  };
  void print_diff(state *prevstate) {
    mu_Mem.print_diff(prevstate);
    mu_Dir.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Mem.to_state(thestate);
    mu_Dir.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_HomeState& operator= (const mu_1_HomeState& from) {
    mu_Mem = from.mu_Mem;
    mu_Dir = from.mu_Dir;
    return *this;
  };
};

  void mu_1_HomeState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_HomeState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_HomeState::set_self(char *n, int os)
{
  name = n;
  mu_Mem.set_self_2(name, ".Mem", os + 0 );
  mu_Dir.set_self_2(name, ".Dir", os + 2 );
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_7: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_7& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_7& val)
  {
    if (val.defined())
      return ( s << mu_1__type_7::values[ int(val) - 31] );
    else return ( s << "Undefined" );
  };

  mu_1__type_7 (char *name, int os): mu__byte(31, 33, 2, name, os) {};
  mu_1__type_7 (void): mu__byte(31, 33, 2) {};
  mu_1__type_7 (int val): mu__byte(31, 33, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -31]; };
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
      cout << name << ":" << values[ value() -31] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_7::values[] = {"I","S","M",NULL };

/*** end of enum declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_7 mu_State;
  mu_1_Value mu_Value;
  mu_1__type_8 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_8 ( void ) {};

  virtual ~mu_1__type_8(); 
friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Value, b.mu_Value);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_Value, b.mu_Value);
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
    mu_State.MultisetSort();
    mu_Value.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_Value.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_Value.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_Value.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_Value.reset();
 };
  void print() {
    mu_State.print();
    mu_Value.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_Value.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_Value.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_8& operator= (const mu_1__type_8& from) {
    mu_State.value(from.mu_State.value());
    mu_Value.value(from.mu_Value.value());
    return *this;
  };
};

  void mu_1__type_8::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_8::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_8::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_Value.set_self_2(name, ".Value", os + 2 );
}

mu_1__type_8::~mu_1__type_8()
{
}

/*** end record declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9
{
 public:
  mu_1__type_8 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_9 (char *n, int os) { set_self(n, os); };
  mu_1__type_9 ( void ) {};
  virtual ~mu_1__type_9 ();
  mu_1__type_8& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 7 ) && ( index <= 7 ) )
      return array[ index - 7 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Address is internally represented from 7 to 7.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 7 ];
#endif
  };
  mu_1__type_9& operator= (const mu_1__type_9& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_9::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_9::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_9::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Address_1", i * 4 + os);i++;
}
mu_1__type_9::~mu_1__type_9()
{
}
/*** end array declaration ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10
{
 public:
  mu_1__type_9 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_10 (char *n, int os) { set_self(n, os); };
  mu_1__type_10 ( void ) {};
  virtual ~mu_1__type_10 ();
  mu_1__type_9& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_10& operator= (const mu_1__type_10& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_10::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_10::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_10::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 4 + os);i++;
}
mu_1__type_10::~mu_1__type_10()
{
}
/*** end array declaration ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu_1__type_11: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_11& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_11& val)
  {
    if (val.defined())
      return ( s << mu_1__type_11::values[ int(val) - 34] );
    else return ( s << "Undefined" );
  };

  mu_1__type_11 (char *name, int os): mu__byte(34, 39, 3, name, os) {};
  mu_1__type_11 (void): mu__byte(34, 39, 3) {};
  mu_1__type_11 (int val): mu__byte(34, 39, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -34]; };
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
      cout << name << ":" << values[ value() -34] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_11::values[] = {"NOP","CR_Pend","CRE_Pend","CP_Pend","WB_Pend","Uncache_Pend",NULL };

/*** end of enum declaration ***/
mu_1__type_11 mu_1__type_11_undefined_var;

class mu_1__type_12
{
 public:
  mu_1__type_11 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_12 (char *n, int os) { set_self(n, os); };
  mu_1__type_12 ( void ) {};
  virtual ~mu_1__type_12 ();
  mu_1__type_11& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 7 ) && ( index <= 7 ) )
      return array[ index - 7 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Address is internally represented from 7 to 7.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 7 ];
#endif
  };
  mu_1__type_12& operator= (const mu_1__type_12& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_12& a, mu_1__type_12& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_12& a, mu_1__type_12& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_12::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_12::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_12::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Address_1", i * 3 + os);i++;
}
mu_1__type_12::~mu_1__type_12()
{
}
/*** end array declaration ***/
mu_1__type_12 mu_1__type_12_undefined_var;

class mu_1__type_13
{
 public:
  mu_1__type_12 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_13 (char *n, int os) { set_self(n, os); };
  mu_1__type_13 ( void ) {};
  virtual ~mu_1__type_13 ();
  mu_1__type_12& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_13& operator= (const mu_1__type_13& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_13& a, mu_1__type_13& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_13& a, mu_1__type_13& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_13::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_13::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_13::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 3 + os);i++;
}
mu_1__type_13::~mu_1__type_13()
{
}
/*** end array declaration ***/
mu_1__type_13 mu_1__type_13_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_10 mu_Cache;
  mu_1__type_13 mu_PMMState;
  mu_1_ProcState ( char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_Cache, b.mu_Cache);
    if (w!=0) return w;
    w = CompareWeight(a.mu_PMMState, b.mu_PMMState);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_Cache, b.mu_Cache);
    if (w!=0) return w;
    w = Compare(a.mu_PMMState, b.mu_PMMState);
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
    mu_Cache.MultisetSort();
    mu_PMMState.MultisetSort();
  }
  void print_statistic()
  {
    mu_Cache.print_statistic();
    mu_PMMState.print_statistic();
  }
  void clear() {
    mu_Cache.clear();
    mu_PMMState.clear();
 };
  void undefine() {
    mu_Cache.undefine();
    mu_PMMState.undefine();
 };
  void reset() {
    mu_Cache.reset();
    mu_PMMState.reset();
 };
  void print() {
    mu_Cache.print();
    mu_PMMState.print();
  };
  void print_diff(state *prevstate) {
    mu_Cache.print_diff(prevstate);
    mu_PMMState.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Cache.to_state(thestate);
    mu_PMMState.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_Cache = from.mu_Cache;
    mu_PMMState = from.mu_PMMState;
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(char *n, int os)
{
  name = n;
  mu_Cache.set_self_2(name, ".Cache", os + 0 );
  mu_PMMState.set_self_2(name, ".PMMState", os + 4 );
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_14_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_14_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_14_id () : mu__byte(0,7,0) {};
  mu_1__type_14_id (int val) : mu__byte(0,7,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_14
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
  mu_1__type_14 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_14 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_14 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 7) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_14& operator= (const mu_1__type_14& from)
  {
    for (int i = 0; i < 8; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_14& a, mu_1__type_14& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_14& a, mu_1__type_14& b)
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

   inline bool in(const mu_1__type_14_id& id)
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
  void multisetremove(const mu_1__type_14_id &id)
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

  void mu_1__type_14::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_14::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_14::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 8; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 16 + os);
  k = os + i * 16;
  for(i = 0; i < 8; i++)
    valid[i].set_self("", i * 2 + k);
};
mu_1__type_14::~mu_1__type_14()
{
}
/*** end multiset declaration ***/
mu_1__type_14 mu_1__type_14_undefined_var;

class mu_1__type_15
{
 public:
  mu_1_HomeState array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_15 (char *n, int os) { set_self(n, os); };
  mu_1__type_15 ( void ) {};
  virtual ~mu_1__type_15 ();
  mu_1_HomeState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_15& operator= (const mu_1__type_15& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_15& a, mu_1__type_15& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_15& a, mu_1__type_15& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_15::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_15::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_15::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 26 + os);i++;
}
mu_1__type_15::~mu_1__type_15()
{
}
/*** end array declaration ***/
mu_1__type_15 mu_1__type_15_undefined_var;

class mu_1__type_16
{
 public:
  mu_1_ProcState array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_16 (char *n, int os) { set_self(n, os); };
  mu_1__type_16 ( void ) {};
  virtual ~mu_1__type_16 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 2 ) && ( index <= 6 ) )
      return array[ index - 2 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Proc is internally represented from 6 to 2.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 2 ];
#endif
  };
  mu_1__type_16& operator= (const mu_1__type_16& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_16& a, mu_1__type_16& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_16& a, mu_1__type_16& b)
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

  void mu_1__type_16::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_16::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_16::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Proc_1", i * 7 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 7 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 7 + os);i++;
array[i].set_self_ar(n,"Proc_4", i * 7 + os);i++;
array[i].set_self_ar(n,"Proc_5", i * 7 + os);i++;
}
mu_1__type_16::~mu_1__type_16()
{
}
/*** end array declaration ***/
mu_1__type_16 mu_1__type_16_undefined_var;

class mu__subrange_30: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_30& val) { return mu__byte::operator=((int) val); };
  mu__subrange_30 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_30 (void): mu__byte(0, 4, 3) {};
  mu__subrange_30 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_30 mu__subrange_30_undefined_var;

class mu__subrange_38: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_38& val) { return mu__byte::operator=((int) val); };
  mu__subrange_38 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_38 (void): mu__byte(0, 4, 3) {};
  mu__subrange_38 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_38 mu__subrange_38_undefined_var;

class mu__subrange_39: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_39& val) { return mu__byte::operator=((int) val); };
  mu__subrange_39 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_39 (void): mu__byte(0, 4, 3) {};
  mu__subrange_39 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_39 mu__subrange_39_undefined_var;

class mu__subrange_40: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_40& val) { return mu__byte::operator=((int) val); };
  mu__subrange_40 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_40 (void): mu__byte(0, 4, 3) {};
  mu__subrange_40 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_40 mu__subrange_40_undefined_var;

class mu__subrange_41: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_41& val) { return mu__byte::operator=((int) val); };
  mu__subrange_41 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_41 (void): mu__byte(0, 4, 3) {};
  mu__subrange_41 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_41 mu__subrange_41_undefined_var;

const int mu_HomeCount = 1;
const int mu_ProcCount = 5;
const int mu_AddressCount = 1;
const int mu_ValueCount = 2;
const int mu_DirMax = 5;
const int mu_NetMax = 8;
const int mu_Home_1 = 1;
const int mu_Proc_1 = 2;
const int mu_Proc_2 = 3;
const int mu_Proc_3 = 4;
const int mu_Proc_4 = 5;
const int mu_Proc_5 = 6;
const int mu_Address_1 = 7;
const int mu_Value_1 = 8;
const int mu_Value_2 = 9;
const int mu_Cache_Read = 10;
const int mu_Cache_Read_Ex = 11;
const int mu_Cache_Promote = 12;
const int mu_Uncache = 13;
const int mu_Write_Back = 14;
const int mu_Update = 15;
const int mu_Data = 16;
const int mu_Invalidate = 17;
const int mu_Uncache_Ack = 18;
const int mu_Write_Back_Ack = 19;
const int mu_Inv_Ack = 20;
const int mu_Fw_Cache_R = 21;
const int mu_Fw_Cache_R_Ex = 22;
const int mu_Ack_Fw_Cache_Ex = 23;
const int mu_Cache_Promote_Ack = 24;
const int mu_Inv = 25;
const int mu_Shared_Remote = 26;
const int mu_Master_Remote = 27;
const int mu_Wait_Inv = 28;
const int mu_Wait_Update = 29;
const int mu_Wait_WB = 30;
const int mu_I = 31;
const int mu_S = 32;
const int mu_M = 33;
const int mu_NOP = 34;
const int mu_CR_Pend = 35;
const int mu_CRE_Pend = 36;
const int mu_CP_Pend = 37;
const int mu_WB_Pend = 38;
const int mu_Uncache_Pend = 39;
/*** Variable declaration ***/
mu_1__type_14 mu_Net("Net",0);

/*** Variable declaration ***/
mu_1__type_15 mu_Homes("Homes",144);

/*** Variable declaration ***/
mu_1__type_16 mu_Procs("Procs",170);

void mu_Send(const mu_1_Message_Type& mu_M, const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Aux, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Val)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

/*** begin multisetcount 0 declaration ***/
  int mu__intexpr17 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr17++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr17) < (mu_NetMax)) ) Error.Error("Assertion failed: Too many messages");
if (mu_M.isundefined())
  mu_msg.mu_MType.undefine();
else
  mu_msg.mu_MType = mu_M;
if (mu_Src.isundefined())
  mu_msg.mu_Source.undefine();
else
  mu_msg.mu_Source = mu_Src;
if (mu_Dst.isundefined())
  mu_msg.mu_Destination.undefine();
else
  mu_msg.mu_Destination = mu_Dst;
if (mu_Aux.isundefined())
  mu_msg.mu_Aux.undefine();
else
  mu_msg.mu_Aux = mu_Aux;
if (mu_Addr.isundefined())
  mu_msg.mu_Address.undefine();
else
  mu_msg.mu_Address = mu_Addr;
if (mu_Val.isundefined())
  mu_msg.mu_Value.undefine();
else
  mu_msg.mu_Value = mu_Val;
mu_Net.multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_Send_Cache_Read(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Read, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Cache_Read_Ex(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Read_Ex, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Uncache(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Uncache, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Uncache_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Uncache_Ack, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Data(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Home, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Val)
{
mu_Send ( mu_Data, mu_Dst, mu_Src, mu_Home, mu_Addr, mu_Val );
};
/*** end procedure declaration ***/

void mu_Send_Fw_Cache_R(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Loc, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Fw_Cache_R, mu_Dst, mu_Src, mu_Loc, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Fw_Cache_R_Ex(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Loc, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Fw_Cache_R_Ex, mu_Dst, mu_Src, mu_Loc, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Ack_Fw_Cache_Ex(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Ack_Fw_Cache_Ex, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Invalidate(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Invalidate, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Inv_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Inv_Ack, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Write_Back(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Data)
{
mu_Send ( mu_Write_Back, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_Data );
};
/*** end procedure declaration ***/

void mu_Send_Update(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Data)
{
mu_Send ( mu_Update, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_Data );
};
/*** end procedure declaration ***/

void mu_Send_Cache_Promote(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Promote, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Cache_Promote_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Promote_Ack, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_Send_Write_Back_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Write_Back_Ack, mu_Dst, mu_Src, mu_1_Node_undefined_var, mu_Addr, mu_1_Value_undefined_var );
};
/*** end procedure declaration ***/

void mu_add_dir_entry(const mu_1_Node& mu_h, const mu_1_Address& mu_a, const mu_1_Node& mu_n)
{
if ( (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) == (mu_DirMax) )
{
Error.Error("Error: Directory overflow");
}
if (mu_n.isundefined())
  mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count].undefine();
else
  mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count] = mu_n;
mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count = (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) + (1);
};
/*** end procedure declaration ***/

void mu_remove_dir_entry(const mu_1_Node& mu_h, const mu_1_Address& mu_a, const mu_1_Node& mu_n)
{
if ( (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) == (0) )
{
Error.Error("Error: Cannot remove from empty directory");
}
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr18;
  if (!((mu_i) < (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count))) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_i]) == (mu_n)) ; 
}
if ( mu__boolexpr18 )
{
mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_i] = mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[(mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) - (1)];
mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[(mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) - (1)].undefine();
mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count = (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) - (1);
}
};
};
if ( (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) == (0) )
{
mu_Homes[mu_h].mu_Dir[mu_a].mu_State = mu_Inv;
}
};
/*** end procedure declaration ***/

void mu_Handle_Inv_Ack(const mu_1_Node& mu_n, const mu_1_Address& mu_addr)
{
if ( (mu_Homes[mu_n].mu_Dir[mu_addr].mu_Inv_Count) == (0) )
{
Error.Error("Error: Bad invalidation count");
}
mu_Homes[mu_n].mu_Dir[mu_addr].mu_Inv_Count = (mu_Homes[mu_n].mu_Dir[mu_addr].mu_Inv_Count) - (1);
if ( (mu_Homes[mu_n].mu_Dir[mu_addr].mu_Inv_Count) == (0) )
{
if ( (mu_Homes[mu_n].mu_Dir[mu_addr].mu_State) != (mu_Wait_Inv) )
{
Error.Error("Error: Should be in Wait Inv state");
}
mu_Homes[mu_n].mu_Dir[mu_addr].mu_State = mu_Master_Remote;
}
};
/*** end procedure declaration ***/

void mu_Handle_Uncache_Ack(const mu_1_Node& mu_n, const mu_1_Node& mu_home, const mu_1_Address& mu_addr)
{
if ( (mu_Procs[mu_n].mu_PMMState[mu_home][mu_addr]) != (mu_Uncache_Pend) )
{
Error.Error("Error: PMM state not Uncache_Pend");
}
mu_Procs[mu_n].mu_PMMState[mu_home][mu_addr] = mu_NOP;
mu_Procs[mu_n].mu_Cache[mu_home][mu_addr].mu_State = mu_I;
mu_Procs[mu_n].mu_Cache[mu_home][mu_addr].mu_Value.undefine();
};
/*** end procedure declaration ***/

void mu_Handle_Write_Back_Ack(const mu_1_Node& mu_n, const mu_1_Node& mu_home, const mu_1_Address& mu_addr)
{
if ( (mu_Procs[mu_n].mu_PMMState[mu_home][mu_addr]) != (mu_WB_Pend) )
{
Error.Error("Error: PMM state not WB_Pend");
}
mu_Procs[mu_n].mu_PMMState[mu_home][mu_addr] = mu_NOP;
mu_Procs[mu_n].mu_Cache[mu_home][mu_addr].mu_State = mu_I;
mu_Procs[mu_n].mu_Cache[mu_home][mu_addr].mu_Value.undefine();
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_Net.clear();
  mu_Homes.clear();
  mu_Procs.clear();
}
void world_class::undefine()
{
  mu_Net.undefine();
  mu_Homes.undefine();
  mu_Procs.undefine();
}
void world_class::reset()
{
  mu_Net.reset();
  mu_Homes.reset();
  mu_Procs.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Net.print();
  mu_Homes.print();
  mu_Procs.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Net.print_statistic();
  mu_Homes.print_statistic();
  mu_Procs.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_Net.print_diff(prevstate);
    mu_Homes.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_Net.to_state( newstate );
  mu_Homes.to_state( newstate );
  mu_Procs.to_state( newstate );
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
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
    return tsprintf("Rule 7, M_Index:%s", mu_M_Index.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
  if (!mu_Net.in(mu_M_Index)) { return FALSE; }
  return (mu_Net[mu_M_Index].mu_Destination>=1 && mu_Net[mu_M_Index].mu_Destination<=1);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
    while (what_rule < 8 && mu_M_Index.value()<8 )
      {
        if ( ( TRUE && mu_Net.in(mu_M_Index) ) ) {
              if ((mu_Net[mu_M_Index].mu_Destination>=1 && mu_Net[mu_M_Index].mu_Destination<=1)) {
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
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
{
  mu_1_Message& mu_msg = mu_Net[mu_M_Index];
{
  mu_1_Node& mu_n = mu_msg.mu_Destination;
{
  mu_1_HomeState& mu_me = mu_Homes[mu_n];
switch ((int) mu_msg.mu_MType) {
case mu_Cache_Read:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Inv:
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Shared_Remote;
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 1;
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0] = mu_msg.mu_Source;
mu_Send_Data ( mu_msg.mu_Source, mu_n, mu_n, mu_msg.mu_Address, mu_me.mu_Mem[mu_msg.mu_Address] );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Shared_Remote:
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Send_Data ( mu_msg.mu_Source, mu_n, mu_n, mu_msg.mu_Address, mu_me.mu_Mem[mu_msg.mu_Address] );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Master_Remote:
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Update;
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 1;
mu_Send_Fw_Cache_R ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0], mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Update;
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_Inv:
break;
case mu_Wait_WB:
break;
case mu_Wait_Update:
break;
default:
Error.Error("Error: Cache_Read received in funny Dir state");
break;
}
break;
case mu_Cache_Read_Ex:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Inv:
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Master_Remote;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Send_Data ( mu_msg.mu_Source, mu_n, mu_n, mu_msg.mu_Address, mu_me.mu_Mem[mu_msg.mu_Address] );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Shared_Remote:
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
if ( (mu_i) < (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count) )
{
mu_Send_Invalidate ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[mu_i], mu_n, mu_msg.mu_Address );
}
};
};
mu_me.mu_Dir[mu_msg.mu_Address].mu_Inv_Count = mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count;
mu_Send_Data ( mu_msg.mu_Source, mu_n, mu_n, mu_msg.mu_Address, mu_me.mu_Mem[mu_msg.mu_Address] );
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries.undefine();
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 0;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Inv;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Master_Remote:
mu_Send_Fw_Cache_R_Ex ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0], mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries.undefine();
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 0;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_WB;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_Inv:
break;
case mu_Wait_WB:
break;
case mu_Wait_Update:
break;
default:
Error.Error("Error: Cache_Read_Ex received in funny Dir state");
break;
}
break;
case mu_Cache_Promote:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Inv:
Error.Error("Error: Home in Inv state on Cache_Promote");
break;
case mu_Shared_Remote:
if ( (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count) == (1) )
{
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Master_Remote;
}
else
{
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr19;
  if (!((mu_i) < (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[mu_i]) != (mu_msg.mu_Source)) ; 
}
if ( mu__boolexpr19 )
{
mu_Send_Invalidate ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[mu_i], mu_n, mu_msg.mu_Address );
}
};
};
mu_me.mu_Dir[mu_msg.mu_Address].mu_Inv_Count = (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count) - (1);
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries.undefine();
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 0;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Inv;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
}
mu_Send_Cache_Promote_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_Inv:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Master_Remote:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_Update:
break;
default:
Error.Error("Error: Cache_Promote received in funny Dir state");
break;
}
break;
case mu_Write_Back:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Master_Remote:
mu_me.mu_Mem[mu_msg.mu_Address] = mu_msg.mu_Value;
mu_remove_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Send_Write_Back_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_WB:
if ( (mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0]) != (mu_msg.mu_Source) )
{
mu_me.mu_Mem[mu_msg.mu_Address] = mu_msg.mu_Value;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Master_Remote;
mu_Net.multisetremove(mu_M_Index);
}
break;
case mu_Wait_Update:
mu_me.mu_Mem[mu_msg.mu_Address] = mu_msg.mu_Value;
mu_remove_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Shared_Remote;
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_Inv:
if ( (mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0]) != (mu_msg.mu_Source) )
{
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
}
break;
default:
Error.Error("Error: Writeback received in funny Dir state");
break;
}
break;
case mu_Update:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Wait_Update:
mu_me.mu_Mem[mu_msg.mu_Address] = mu_msg.mu_Value;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Shared_Remote;
mu_Net.multisetremove(mu_M_Index);
break;
default:
Error.Error("Error: Update received in funny Dir state");
break;
}
break;
case mu_Uncache:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Wait_Inv:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Wait_Update:
break;
default:
bool mu__boolexpr20;
  if ((mu_me.mu_Dir[mu_msg.mu_Address].mu_State) == (mu_Shared_Remote)) mu__boolexpr20 = TRUE ;
  else {
  mu__boolexpr20 = ((mu_me.mu_Dir[mu_msg.mu_Address].mu_State) == (mu_Wait_Update)) ; 
}
if ( mu__boolexpr20 )
{
mu_remove_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Send_Uncache_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
}
else
{
Error.Error("Error: Uncache received in funny Dir state");
}
break;
}
break;
case mu_Ack_Fw_Cache_Ex:
switch ((int) mu_me.mu_Dir[mu_msg.mu_Address].mu_State) {
case mu_Wait_WB:
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Master_Remote;
mu_Net.multisetremove(mu_M_Index);
break;
default:
Error.Error("Error: Ack_Fw_Cache_Ex received in funny Dir state");
break;
}
break;
case mu_Inv_Ack:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
}
}
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
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
    return tsprintf("Rule 6, M_Index:%s", mu_M_Index.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
  if (!mu_Net.in(mu_M_Index)) { return FALSE; }
  return (mu_Net[mu_M_Index].mu_Destination>=2 && mu_Net[mu_M_Index].mu_Destination<=6);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
    while (what_rule < 16 && mu_M_Index.value()<8 )
      {
        if ( ( TRUE && mu_Net.in(mu_M_Index) ) ) {
              if ((mu_Net[mu_M_Index].mu_Destination>=2 && mu_Net[mu_M_Index].mu_Destination<=6)) {
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
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_14_id mu_M_Index;
    mu_M_Index.value((r % 8) + 0);
    r = r / 8;
{
  mu_1_Message& mu_msg = mu_Net[mu_M_Index];
{
  mu_1_Node& mu_n = mu_msg.mu_Destination;
{
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
switch ((int) mu_msg.mu_MType) {
case mu_Data:
switch ((int) mu_me.mu_PMMState[mu_msg.mu_Aux][mu_msg.mu_Address]) {
case mu_CR_Pend:
mu_me.mu_PMMState[mu_msg.mu_Aux][mu_msg.mu_Address] = mu_NOP;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_State = mu_S;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_Value = mu_msg.mu_Value;
mu_Net.multisetremove(mu_M_Index);
break;
case mu_CRE_Pend:
mu_me.mu_PMMState[mu_msg.mu_Aux][mu_msg.mu_Address] = mu_NOP;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_State = mu_M;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_Value = mu_msg.mu_Value;
mu_Net.multisetremove(mu_M_Index);
break;
default:
Error.Error("Error: Data received in funny PMMState");
break;
}
break;
case mu_Invalidate:
bool mu__boolexpr21;
  if ((mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State) == (mu_S)) mu__boolexpr21 = TRUE ;
  else {
  mu__boolexpr21 = ((mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State) == (mu_I)) ; 
}
if ( mu__boolexpr21 )
{
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State = mu_I;
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value.undefine();
switch ((int) mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) {
case mu_NOP:
mu_Send_Inv_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_CR_Pend:
break;
case mu_CRE_Pend:
mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address] = mu_NOP;
mu_Net.multisetremove(mu_M_Index);
break;
case mu_CP_Pend:
mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address] = mu_NOP;
mu_Net.multisetremove(mu_M_Index);
break;
case mu_Uncache_Pend:
mu_Handle_Uncache_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
default:
Error.Error("Error: Got Invalidate with funny PMM state");
break;
}
}
else
{
Error.Error("Error: Invalidate message when in M state");
}
break;
case mu_Fw_Cache_R:
switch ((int) mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) {
case mu_NOP:
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State = mu_S;
mu_Send_Data ( mu_msg.mu_Aux, mu_n, mu_msg.mu_Source, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_Send_Update ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_CRE_Pend:
break;
case mu_CP_Pend:
break;
case mu_WB_Pend:
mu_Send_Data ( mu_msg.mu_Aux, mu_n, mu_msg.mu_Source, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_Handle_Write_Back_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
default:
Error.Error("Error: Fw_Cache_R received with funny PMMState");
break;
}
break;
case mu_Fw_Cache_R_Ex:
switch ((int) mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) {
case mu_NOP:
if ( (mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State) != (mu_M) )
{
Error.Error("Error: Fw_Cache_R_Ex received, but Cache not M");
}
mu_Send_Data ( mu_msg.mu_Aux, mu_n, mu_msg.mu_Source, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State = mu_I;
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value.undefine();
mu_Send_Ack_Fw_Cache_Ex ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_WB_Pend:
mu_Send_Data ( mu_msg.mu_Aux, mu_n, mu_msg.mu_Source, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_Handle_Write_Back_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
break;
case mu_CP_Pend:
break;
case mu_CRE_Pend:
break;
default:
Error.Error("Error: Fw_Cache_R_Ex received in funny PMMState");
break;
}
break;
case mu_Cache_Promote_Ack:
if ( (mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) == (mu_CP_Pend) )
{
mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address] = mu_NOP;
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State = mu_M;
mu_Net.multisetremove(mu_M_Index);
}
else
{
Error.Error("Error: Cache_Promote_Ack when PMMstate not CP_Pend");
}
break;
case mu_Uncache_Ack:
if ( (mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) == (mu_Uncache_Pend) )
{
mu_Handle_Uncache_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
}
else
{
Error.Error("Error: Uncache_Ack received in funny PMMState");
}
break;
case mu_Write_Back_Ack:
if ( (mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) == (mu_WB_Pend) )
{
mu_Handle_Write_Back_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Net.multisetremove(mu_M_Index);
}
else
{
Error.Error("Error: Write_Back_Ack when PMMState not WB_Pend");
}
break;
}
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
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 8);
    r = r / 2;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    return tsprintf("Rule 5, v:%s, a:%s, h:%s, n:%s", mu_v.Name(), mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 8);
    r = r / 2;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr22;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  return mu__boolexpr22;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 8);
    r = r / 2;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    while (what_rule < 26 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr23;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
              if (mu__boolexpr23) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 2;
        }
        else
          what_rule += 2;
    r = what_rule - 16;
    mu_v.value((r % 2) + 8);
    r = r / 2;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 8);
    r = r / 2;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
mu_me.mu_Cache[mu_h][mu_a].mu_Value = mu_v;
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
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    return tsprintf("Rule 4, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr24;
bool mu__boolexpr25;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr25)) mu__boolexpr24 = FALSE ;
  else {
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr26 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr26++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
  mu__boolexpr24 = ((mu__intexpr26) <= (2)) ; 
}
  return mu__boolexpr24;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 26;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    while (what_rule < 31 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr27;
bool mu__boolexpr28;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr29 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr29++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
  mu__boolexpr27 = ((mu__intexpr29) <= (2)) ; 
}
              if (mu__boolexpr27) {
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
    r = what_rule - 26;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
mu_me.mu_PMMState[mu_h][mu_a] = mu_WB_Pend;
mu_Send_Write_Back ( (int)mu_h, (int)mu_n, mu_a, mu_me.mu_Cache[mu_h][mu_a].mu_Value );
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
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    return tsprintf("Rule 3, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr30;
bool mu__boolexpr31;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr32 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr32++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
  mu__boolexpr30 = ((mu__intexpr32) <= (2)) ; 
}
  return mu__boolexpr30;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 31;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    while (what_rule < 36 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr35 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr35++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
  mu__boolexpr33 = ((mu__intexpr35) <= (2)) ; 
}
              if (mu__boolexpr33) {
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
    r = what_rule - 31;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
mu_me.mu_PMMState[mu_h][mu_a] = mu_Uncache_Pend;
mu_Send_Uncache ( (int)mu_h, (int)mu_n, mu_a );
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
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    return tsprintf("Rule 2, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr36;
bool mu__boolexpr37;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr38 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr38++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr36 = ((mu__intexpr38) <= (2)) ; 
}
  return mu__boolexpr36;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 36;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    while (what_rule < 41 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr39;
bool mu__boolexpr40;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr41 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr41++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr39 = ((mu__intexpr41) <= (2)) ; 
}
              if (mu__boolexpr39) {
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
    mu_a.value((r % 1) + 7);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
mu_me.mu_PMMState[mu_h][mu_a] = mu_CP_Pend;
mu_Send_Cache_Promote ( (int)mu_h, (int)mu_n, mu_a );
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
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    return tsprintf("Rule 1, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr42;
bool mu__boolexpr43;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr44 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr44++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
  mu__boolexpr42 = ((mu__intexpr44) <= (2)) ; 
}
  return mu__boolexpr42;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 41;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    while (what_rule < 46 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr45;
bool mu__boolexpr46;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr47 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr47++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
  mu__boolexpr45 = ((mu__intexpr47) <= (2)) ; 
}
              if (mu__boolexpr45) {
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
    r = what_rule - 41;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
mu_me.mu_PMMState[mu_h][mu_a] = mu_CRE_Pend;
mu_Send_Cache_Read_Ex ( (int)mu_h, (int)mu_n, mu_a );
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
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    return tsprintf("Rule 0, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr48;
bool mu__boolexpr49;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr50 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr50++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
  mu__boolexpr48 = ((mu__intexpr50) <= (2)) ; 
}
  return mu__boolexpr48;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 46;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    while (what_rule < 51 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr53 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr53++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
  mu__boolexpr51 = ((mu__intexpr53) <= (2)) ; 
}
              if (mu__boolexpr51) {
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
    r = what_rule - 46;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.value((r % 5) + 2);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 7);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 5) + 2);
    r = r / 5;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
mu_me.mu_PMMState[mu_h][mu_a] = mu_CR_Pend;
mu_Send_Cache_Read ( (int)mu_h, (int)mu_n, mu_a );
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
  if (what_rule<8)
    { R0.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<16)
    { R1.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<26)
    { R2.NextRule(what_rule);
      if (what_rule<26) return; }
  if (what_rule>=26 && what_rule<31)
    { R3.NextRule(what_rule);
      if (what_rule<31) return; }
  if (what_rule>=31 && what_rule<36)
    { R4.NextRule(what_rule);
      if (what_rule<36) return; }
  if (what_rule>=36 && what_rule<41)
    { R5.NextRule(what_rule);
      if (what_rule<41) return; }
  if (what_rule>=41 && what_rule<46)
    { R6.NextRule(what_rule);
      if (what_rule<46) return; }
  if (what_rule>=46 && what_rule<51)
    { R7.NextRule(what_rule);
      if (what_rule<51) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=7) return R0.Condition(r-0);
  if (r>=8 && r<=15) return R1.Condition(r-8);
  if (r>=16 && r<=25) return R2.Condition(r-16);
  if (r>=26 && r<=30) return R3.Condition(r-26);
  if (r>=31 && r<=35) return R4.Condition(r-31);
  if (r>=36 && r<=40) return R5.Condition(r-36);
  if (r>=41 && r<=45) return R6.Condition(r-41);
  if (r>=46 && r<=50) return R7.Condition(r-46);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=7) { R0.Code(r-0); return; } 
  if (r>=8 && r<=15) { R1.Code(r-8); return; } 
  if (r>=16 && r<=25) { R2.Code(r-16); return; } 
  if (r>=26 && r<=30) { R3.Code(r-26); return; } 
  if (r>=31 && r<=35) { R4.Code(r-31); return; } 
  if (r>=36 && r<=40) { R5.Code(r-36); return; } 
  if (r>=41 && r<=45) { R6.Code(r-41); return; } 
  if (r>=46 && r<=50) { R7.Code(r-46); return; } 
}
int Priority(unsigned short r)
{
  if (r<=7) { return R0.Priority(); } 
  if (r>=8 && r<=15) { return R1.Priority(); } 
  if (r>=16 && r<=25) { return R2.Priority(); } 
  if (r>=26 && r<=30) { return R3.Priority(); } 
  if (r>=31 && r<=35) { return R4.Priority(); } 
  if (r>=36 && r<=40) { return R5.Priority(); } 
  if (r>=41 && r<=45) { return R6.Priority(); } 
  if (r>=46 && r<=50) { return R7.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=7) return R0.Name(r-0);
  if (r>=8 && r<=15) return R1.Name(r-8);
  if (r>=16 && r<=25) return R2.Name(r-16);
  if (r>=26 && r<=30) return R3.Name(r-26);
  if (r>=31 && r<=35) return R4.Name(r-31);
  if (r>=36 && r<=40) return R5.Name(r-36);
  if (r>=41 && r<=45) return R6.Name(r-41);
  if (r>=46 && r<=50) return R7.Name(r-46);
  return NULL;
}
};
const unsigned numrules = 51;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 51


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 8);
    r = r / 2;
    return tsprintf("Startstate 0, v:%s", mu_v.Name());
  }
  void Code(unsigned short r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 8);
    r = r / 2;
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
{
for(int mu_a = 7; mu_a <= 7; mu_a++) {
mu_Homes[mu_h].mu_Mem[mu_a] = mu_v;
mu_Homes[mu_h].mu_Dir[mu_a].mu_State = mu_Inv;
mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count = 0;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_i].undefine();
};
};
mu_Homes[mu_h].mu_Dir[mu_a].mu_Inv_Count = 0;
};
};
};
};
{
for(int mu_l = 2; mu_l <= 6; mu_l++) {
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
{
for(int mu_a = 7; mu_a <= 7; mu_a++) {
mu_Procs[mu_l].mu_Cache[mu_h][mu_a].mu_State = mu_I;
mu_Procs[mu_l].mu_Cache[mu_h][mu_a].mu_Value.undefine();
mu_Procs[mu_l].mu_PMMState[mu_h][mu_a] = mu_NOP;
};
};
};
};
};
};
mu_Net.undefine();
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
int mu__invariant_54() // Invariant "Coherency in Data"
{
bool mu__quant55; 
mu__quant55 = TRUE;
{
for(int mu_n1 = 2; mu_n1 <= 6; mu_n1++) {
bool mu__quant56; 
mu__quant56 = TRUE;
{
for(int mu_home = 1; mu_home <= 1; mu_home++) {
bool mu__quant57; 
mu__quant57 = TRUE;
{
for(int mu_addr = 7; mu_addr <= 7; mu_addr++) {
bool mu__boolexpr58;
bool mu__boolexpr59;
bool mu__boolexpr60;
  if (!((mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_State) == (mu_S))) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_Value) != (mu_Homes[mu_home].mu_Mem[mu_addr])) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_Procs[mu_n1].mu_PMMState[mu_home][mu_addr]) != (mu_Uncache_Pend)) ; 
}
  if (!(mu__boolexpr59)) mu__boolexpr58 = FALSE ;
  else {
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr61 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
bool mu__boolexpr62;
bool mu__boolexpr63;
bool mu__boolexpr64;
bool mu__boolexpr65;
  if (!((mu_Net[mu_i].mu_MType) == (mu_Invalidate))) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_Net[mu_i].mu_Source) == (mu_home)) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_Net[mu_i].mu_Destination) == (mu_n1)) ; 
}
  if (mu__boolexpr64) mu__boolexpr63 = TRUE ;
  else {
bool mu__boolexpr66;
bool mu__boolexpr67;
  if (!((mu_Net[mu_i].mu_MType) == (mu_Update))) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_Net[mu_i].mu_Destination) == (mu_home)) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_Net[mu_i].mu_Value) == (mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_Value)) ; 
}
  mu__boolexpr63 = (mu__boolexpr66) ; 
}
  if (mu__boolexpr63) mu__boolexpr62 = TRUE ;
  else {
bool mu__boolexpr68;
bool mu__boolexpr69;
  if (!((mu_Net[mu_i].mu_MType) == (mu_Write_Back))) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_Net[mu_i].mu_Destination) == (mu_home)) ; 
}
  if (!(mu__boolexpr69)) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = ((mu_Net[mu_i].mu_Value) == (mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_Value)) ; 
}
  mu__boolexpr62 = (mu__boolexpr68) ; 
}
          if ( mu__boolexpr62 ) mu__intexpr61++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
  mu__boolexpr58 = ((mu__intexpr61) == (0)) ; 
}
if ( !(!(mu__boolexpr58)) )
  { mu__quant57 = FALSE; break; }
};
};
if ( !(mu__quant57) )
  { mu__quant56 = FALSE; break; }
};
};
if ( !(mu__quant56) )
  { mu__quant55 = FALSE; break; }
};
};
return mu__quant55;
};

bool mu__condition_70() // Condition for Rule "Coherency in Data"
{
  return mu__invariant_54( );
}

/**** end rule declaration ****/

int mu__invariant_71() // Invariant "Mutual Exclusion on Dirty Data"
{
bool mu__quant72; 
mu__quant72 = TRUE;
{
for(int mu_n1 = 2; mu_n1 <= 6; mu_n1++) {
bool mu__quant73; 
mu__quant73 = TRUE;
{
for(int mu_n2 = 2; mu_n2 <= 6; mu_n2++) {
bool mu__quant74; 
mu__quant74 = TRUE;
{
for(int mu_home = 1; mu_home <= 1; mu_home++) {
bool mu__quant75; 
mu__quant75 = TRUE;
{
for(int mu_addr = 7; mu_addr <= 7; mu_addr++) {
bool mu__boolexpr76;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr76 = TRUE ;
  else {
bool mu__boolexpr77;
bool mu__boolexpr78;
  if (!((mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_State) == (mu_M))) mu__boolexpr78 = FALSE ;
  else {
  mu__boolexpr78 = ((mu_Procs[mu_n1].mu_PMMState[mu_home][mu_addr]) != (mu_WB_Pend)) ; 
}
  if (!(mu__boolexpr78)) mu__boolexpr77 = FALSE ;
  else {
bool mu__boolexpr79;
bool mu__boolexpr80;
  if (!((mu_Procs[mu_n2].mu_Cache[mu_home][mu_addr].mu_State) == (mu_M))) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_Procs[mu_n2].mu_PMMState[mu_home][mu_addr]) != (mu_WB_Pend)) ; 
}
  if (mu__boolexpr80) mu__boolexpr79 = TRUE ;
  else {
bool mu__boolexpr81;
bool mu__boolexpr82;
  if (!((mu_Procs[mu_n2].mu_Cache[mu_home][mu_addr].mu_State) == (mu_S))) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = ((mu_Procs[mu_n2].mu_PMMState[mu_home][mu_addr]) != (mu_Uncache_Pend)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr83 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net.valid[(int)mu_i].value())
        {
bool mu__boolexpr84;
bool mu__boolexpr85;
  if (!((mu_Net[mu_i].mu_MType) == (mu_Invalidate))) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = ((mu_Net[mu_i].mu_Source) == (mu_home)) ; 
}
  if (!(mu__boolexpr85)) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = ((mu_Net[mu_i].mu_Destination) == (mu_n2)) ; 
}
          if ( mu__boolexpr84 ) mu__intexpr83++;
        }
      if (mu_i == 8-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
  mu__boolexpr81 = ((mu__intexpr83) == (0)) ; 
}
  mu__boolexpr79 = (mu__boolexpr81) ; 
}
  mu__boolexpr77 = (mu__boolexpr79) ; 
}
  mu__boolexpr76 = (!(mu__boolexpr77)) ; 
}
if ( !(mu__boolexpr76) )
  { mu__quant75 = FALSE; break; }
};
};
if ( !(mu__quant75) )
  { mu__quant74 = FALSE; break; }
};
};
if ( !(mu__quant74) )
  { mu__quant73 = FALSE; break; }
};
};
if ( !(mu__quant73) )
  { mu__quant72 = FALSE; break; }
};
};
return mu__quant72;
};

bool mu__condition_86() // Condition for Rule "Mutual Exclusion on Dirty Data"
{
  return mu__invariant_71( );
}

/**** end rule declaration ****/

int mu__invariant_87() // Invariant "Unused Dir Entries Undefined"
{
bool mu__quant88; 
mu__quant88 = TRUE;
{
for(int mu_n = 1; mu_n <= 1; mu_n++) {
bool mu__quant89; 
mu__quant89 = TRUE;
{
for(int mu_a = 7; mu_a <= 7; mu_a++) {
bool mu__boolexpr90;
bool mu__boolexpr91;
  if (!((mu_Homes[mu_n].mu_Dir[mu_a].mu_State) == (mu_Inv))) mu__boolexpr91 = TRUE ;
  else {
  mu__boolexpr91 = ((mu_Homes[mu_n].mu_Dir[mu_a].mu_Shared_Count) == (0)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
bool mu__quant92; 
mu__quant92 = TRUE;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr93;
  if (!((mu_i) >= (mu_Homes[mu_n].mu_Dir[mu_a].mu_Shared_Count))) mu__boolexpr93 = TRUE ;
  else {
  mu__boolexpr93 = (mu_Homes[mu_n].mu_Dir[mu_a].mu_Entries[mu_i].isundefined()) ; 
}
if ( !(mu__boolexpr93) )
  { mu__quant92 = FALSE; break; }
};
};
  mu__boolexpr90 = (mu__quant92) ; 
}
if ( !(mu__boolexpr90) )
  { mu__quant89 = FALSE; break; }
};
};
if ( !(mu__quant89) )
  { mu__quant88 = FALSE; break; }
};
};
return mu__quant88;
};

bool mu__condition_94() // Condition for Rule "Unused Dir Entries Undefined"
{
  return mu__invariant_87( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Unused Dir Entries Undefined", &mu__condition_94, NULL, FALSE},
{"Mutual Exclusion on Dirty Data", &mu__condition_86, NULL, FALSE},
{"Coherency in Data", &mu__condition_70, NULL, FALSE},
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
Homes:ScalarsetVariable
Procs:ScalarsetArrayOfScalarset
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
  int class_mu_1_Value[2];
  int undefined_class_mu_1_Value;// has the highest class number

  void Print_class_mu_1_Value();
  bool OnlyOneRemain_mu_1_Value;
  bool MTO_class_mu_1_Value()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Value)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Value = TRUE;
    return FALSE;
  }
  int class_mu_1_Proc[5];
  int undefined_class_mu_1_Proc;// has the highest class number

  void Print_class_mu_1_Proc();
  bool OnlyOneRemain_mu_1_Proc;
  bool MTO_class_mu_1_Proc()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Proc)
      return FALSE;
    for (i=0; i<5; i++)
      for (j=0; j<5; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Proc = TRUE;
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
  int * in_mu_1_Value;
  typedef int arr_mu_1_Value[2];
  arr_mu_1_Value * perm_mu_1_Value;
  arr_mu_1_Value * revperm_mu_1_Value;

  int size_mu_1_Value[2];
  bool reversed_sorted_mu_1_Value(int start, int end);
  void reverse_reversed_mu_1_Value(int start, int end);

  int * in_mu_1_Proc;
  typedef int arr_mu_1_Proc[5];
  arr_mu_1_Proc * perm_mu_1_Proc;
  arr_mu_1_Proc * revperm_mu_1_Proc;

  int size_mu_1_Proc[5];
  bool reversed_sorted_mu_1_Proc(int start, int end);
  void reverse_reversed_mu_1_Proc(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Value* perm, int size, mu_1_Value k);
  void GenPerm0(mu_1_Value* perm, int size, unsigned long& index);

  bool ok1(mu_1_Proc* perm, int size, mu_1_Proc k);
  void GenPerm1(mu_1_Proc* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Value()
{
  cout << "class_mu_1_Value:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_Value[i];
  cout << " " << undefined_class_mu_1_Value << "\n";
}
void PermSet::Print_class_mu_1_Proc()
{
  cout << "class_mu_1_Proc:\t";
  for (int i=0; i<5; i++)
    cout << class_mu_1_Proc[i];
  cout << " " << undefined_class_mu_1_Proc << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    for (i=0; i<5; i++)
      for (j=0; j<5; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
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
    mu_1_Value Perm0[2];
    mu_1_Proc Perm1[5];

  /********************
   declaration of class variables
  ********************/
  in = new bool[240];
 in_mu_1_Value = new int[240];
 perm_mu_1_Value = new arr_mu_1_Value[2];
 revperm_mu_1_Value = new arr_mu_1_Value[2];
 in_mu_1_Proc = new int[240];
 perm_mu_1_Proc = new arr_mu_1_Proc[120];
 revperm_mu_1_Proc = new arr_mu_1_Proc[120];

    // Set perm and revperm
    count = 0;
    for (i=8; i<=9; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=8; j<=9; j++)
        for (k=8; k<=9; k++)
          if (revperm_mu_1_Value[i][k-8]==j)   // k - base 
            perm_mu_1_Value[i][j-8]=k; // j - base 
    count = 0;
    for (i=2; i<=6; i++)
      {
        Perm1[0].value(i);
        GenPerm1(Perm1, 1, count);
      }
    if (count!=120)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<120; i++)
      for (j=2; j<=6; j++)
        for (k=2; k<=6; k++)
          if (revperm_mu_1_Proc[i][k-2]==j)   // k - base 
            perm_mu_1_Proc[i][j-2]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Value = 0;
    int i_mu_1_Proc = 0;
    size = 240;
    count = 240;
    for (i=0; i<240; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Value[i] = i_mu_1_Value;
      i_mu_1_Value += carry;
      if (i_mu_1_Value >= 2) { i_mu_1_Value = 0; carry = 1; } 
      else { carry = 0; } 
      in_mu_1_Proc[i] = i_mu_1_Proc;
      i_mu_1_Proc += carry;
      if (i_mu_1_Proc >= 120) { i_mu_1_Proc = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Value = new int[1];
 perm_mu_1_Value = new arr_mu_1_Value[1];
 revperm_mu_1_Value = new arr_mu_1_Value[1];
 in_mu_1_Proc = new int[1];
 perm_mu_1_Proc = new arr_mu_1_Proc[1];
 revperm_mu_1_Proc = new arr_mu_1_Proc[1];
  in[0] = TRUE;
    in_mu_1_Value[0] = 0;
    in_mu_1_Proc[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_Value[i]=0;
  undefined_class_mu_1_Value=0;
  OnlyOneRemain_mu_1_Value = FALSE;
  for (i=0; i<5; i++)
    class_mu_1_Proc[i]=0;
  undefined_class_mu_1_Proc=0;
  OnlyOneRemain_mu_1_Proc = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<240; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Value[2];
  int size_mu_1_Value[2];
  bool should_be_in_mu_1_Value[2];
  int start_mu_1_Proc[5];
  int size_mu_1_Proc[5];
  bool should_be_in_mu_1_Proc[120];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	    start_mu_1_Value[k] = start;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<5; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<5; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	    start_mu_1_Proc[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_Value[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Value[i][k]-8 >=start_mu_1_Value[k] 
	     && perm_mu_1_Value[i][k]-8 < start_mu_1_Value[k] + size_mu_1_Value[k]) )
  	    {
	      should_be_in_mu_1_Value[i] = FALSE;
	      break;
	    }
  for (i=0; i<120; i++) // set up
    should_be_in_mu_1_Proc[i] = TRUE;
  for (i=0; i<120; i++) // to be in or not to be
    for (k=0; k<5; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Proc[i][k]-2 >=start_mu_1_Proc[k] 
	     && perm_mu_1_Proc[i][k]-2 < start_mu_1_Proc[k] + size_mu_1_Proc[k]) )
  	    {
	      should_be_in_mu_1_Proc[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<240; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Value[in_mu_1_Value[i]]) in[i] = FALSE;
      if (in[i] && !should_be_in_mu_1_Proc[in_mu_1_Proc[i]]) in[i] = FALSE;
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
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<5; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<5; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Value[k]==j)
	      revperm_mu_1_Value[0][start++] = k+8;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Value[0][k]==j+8)
        perm_mu_1_Value[0][j]=k+8;
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      for (k=0; k<5; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Proc[k]==j)
	      revperm_mu_1_Proc[0][start++] = k+2;
    }
  for (j=0; j<5; j++)
    for (k=0; k<5; k++)
      if (revperm_mu_1_Proc[0][k]==j+2)
        perm_mu_1_Proc[0][j]=k+2;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Value* Perm, int size, mu_1_Value k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Value* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=8; i<=9; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=8; i<=9; i++)
        revperm_mu_1_Value[count][i-8]=Perm[i-8].value();// i - base
      count++;
    }
}
bool PermSet::ok1(mu_1_Proc* Perm, int size, mu_1_Proc k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm1(mu_1_Proc* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=5)
    {
      for (i=2; i<=6; i++)
        if(ok1(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm1(Perm, size+1, count);
          }
    }
  else
    {
      for (i=2; i<=6; i++)
        revperm_mu_1_Proc[count][i-2]=Perm[i-2].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Value(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Value[0][i]<revperm_mu_1_Value[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Value(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Value[0][j];
      revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][i];
      revperm_mu_1_Value[0][i] = temp;
    }
}
bool PermSet::reversed_sorted_mu_1_Proc(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Proc[0][i]<revperm_mu_1_Proc[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Proc(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Proc[0][j];
      revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][i];
      revperm_mu_1_Proc[0][i] = temp;
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
      end = start-1+size_mu_1_Value[revperm_mu_1_Value[0][start]-8];
      if (reversed_sorted_mu_1_Value(start,end))
	       {
	  reverse_reversed_mu_1_Value(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Value(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Value[0][j]<revperm_mu_1_Value[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Value[0][j];
			  revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][k];
			  revperm_mu_1_Value[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Value(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) {
  for (start = 0; start < 5; )
    {
      end = start-1+size_mu_1_Proc[revperm_mu_1_Proc[0][start]-2];
      if (reversed_sorted_mu_1_Proc(start,end))
	       {
	  reverse_reversed_mu_1_Proc(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Proc(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Proc[0][j]<revperm_mu_1_Proc[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Proc[0][j];
			  revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][k];
			  revperm_mu_1_Proc[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Proc(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
}
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Value[0][k]==j+8)   // k - base 
	perm_mu_1_Value[0][j]=k+8; // j - base 
  for (j=0; j<5; j++)
    for (k=0; k<5; k++)
      if (revperm_mu_1_Proc[0][k]==j+2)   // k - base 
	perm_mu_1_Proc[0][j]=k+2; // j - base 
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
        mu_Homes.MultisetSort();
        mu_Procs.MultisetSort();
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
void mu_1_Home::Permute(PermSet& Perm, int i) {}
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_Home::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Home::SimpleLimit(PermSet& Perm) {}
void mu_1_Home::ArrayLimit(PermSet& Perm) {}
void mu_1_Home::Limit(PermSet& Perm) {}
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-2]); // value - base
};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-2]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<5; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-2)
            Perm.class_mu_1_Proc[i]++;
        value(2 + Perm.undefined_class_mu_1_Proc++);
      }
    else 
      {
        value(Perm.class_mu_1_Proc[value()-2]+2);
      }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-2]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<5; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-2)
            Perm.class_mu_1_Proc[i]++;
        Perm.undefined_class_mu_1_Proc++;
      }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 6 ) )
      value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-2]+(0)); // value - base
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 6 ) )
      {
        if (Perm.class_mu_1_Proc[value()-2]==Perm.undefined_class_mu_1_Proc) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<5; i++)
              if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-2)
                Perm.class_mu_1_Proc[i]++;
            value(2 + Perm.undefined_class_mu_1_Proc++);
          }
        else 
          {
            value(Perm.class_mu_1_Proc[value()-2]+2);
          }
      }
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 6 ) )
      if (Perm.class_mu_1_Proc[value()-2]==Perm.undefined_class_mu_1_Proc) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<5; i++)
            if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-2)
              Perm.class_mu_1_Proc[i]++;
          Perm.undefined_class_mu_1_Proc++;
        }
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_Address::Permute(PermSet& Perm, int i) {}
void mu_1_Address::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_Address::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Address::SimpleLimit(PermSet& Perm) {}
void mu_1_Address::ArrayLimit(PermSet& Perm) {}
void mu_1_Address::Limit(PermSet& Perm) {}
void mu_1_Address::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Value[Perm.in_mu_1_Value[i]][value()-8]); // value - base
};
void mu_1_Value::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-8]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-8)
            Perm.class_mu_1_Value[i]++;
        value(8 + Perm.undefined_class_mu_1_Value++);
      }
    else 
      {
        value(Perm.class_mu_1_Value[value()-8]+8);
      }
}
void mu_1_Value::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Value::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-8]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-8)
            Perm.class_mu_1_Value[i]++;
        Perm.undefined_class_mu_1_Value++;
      }
}
void mu_1_Value::ArrayLimit(PermSet& Perm) {}
void mu_1_Value::Limit(PermSet& Perm) {}
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
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
  mu_Aux.Permute(Perm,i);
  mu_Value.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_Source.SimpleCanonicalize(Perm);
  mu_Destination.SimpleCanonicalize(Perm);
  mu_Aux.SimpleCanonicalize(Perm);
  mu_Value.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_Source.SimpleLimit(Perm);
  mu_Destination.SimpleLimit(Perm);
  mu_Aux.SimpleLimit(Perm);
  mu_Value.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_0::ArrayLimit(PermSet& Perm) {}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_12::Permute(PermSet& Perm, int i) {};
void mu__subrange_12::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_12::Canonicalize(PermSet& Perm) {};
void mu__subrange_12::SimpleLimit(PermSet& Perm) {};
void mu__subrange_12::ArrayLimit(PermSet& Perm) {};
void mu__subrange_12::Limit(PermSet& Perm) {};
void mu__subrange_12::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<5; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<5; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i) {};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_4::Canonicalize(PermSet& Perm) {};
void mu_1__type_4::SimpleLimit(PermSet& Perm) {};
void mu_1__type_4::ArrayLimit(PermSet& Perm) {};
void mu_1__type_4::Limit(PermSet& Perm) {};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  mu_Entries.Permute(Perm,i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{
  mu_Entries.SimpleCanonicalize(Perm);
};
void mu_1__type_5::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_5::SimpleLimit(PermSet& Perm)
{
  mu_Entries.SimpleLimit(Perm);
};
void mu_1__type_5::ArrayLimit(PermSet& Perm){}
void mu_1__type_5::Limit(PermSet& Perm)
{
};
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_6::ArrayLimit(PermSet& Perm) {}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
  mu_Mem.Permute(Perm,i);
  mu_Dir.Permute(Perm,i);
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{
  mu_Mem.SimpleCanonicalize(Perm);
  mu_Dir.SimpleCanonicalize(Perm);
};
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm)
{
  mu_Mem.SimpleLimit(Perm);
  mu_Dir.SimpleLimit(Perm);
};
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_7::Permute(PermSet& Perm, int i) {};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_7::Canonicalize(PermSet& Perm) {};
void mu_1__type_7::SimpleLimit(PermSet& Perm) {};
void mu_1__type_7::ArrayLimit(PermSet& Perm) {};
void mu_1__type_7::Limit(PermSet& Perm) {};
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  mu_Value.Permute(Perm,i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{
  mu_Value.SimpleCanonicalize(Perm);
};
void mu_1__type_8::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_8::SimpleLimit(PermSet& Perm)
{
  mu_Value.SimpleLimit(Perm);
};
void mu_1__type_8::ArrayLimit(PermSet& Perm){}
void mu_1__type_8::Limit(PermSet& Perm)
{
};
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_9::Permute(PermSet& Perm, int i)
{
  static mu_1__type_9 temp("Permute_mu_1__type_9",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_9::Canonicalize(PermSet& Perm){};
void mu_1__type_9::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_9::ArrayLimit(PermSet& Perm) {}
void mu_1__type_9::Limit(PermSet& Perm){}
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i)
{
  static mu_1__type_10 temp("Permute_mu_1__type_10",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_10::Canonicalize(PermSet& Perm){};
void mu_1__type_10::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_10::ArrayLimit(PermSet& Perm) {}
void mu_1__type_10::Limit(PermSet& Perm){}
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_11::Permute(PermSet& Perm, int i) {};
void mu_1__type_11::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_11::Canonicalize(PermSet& Perm) {};
void mu_1__type_11::SimpleLimit(PermSet& Perm) {};
void mu_1__type_11::ArrayLimit(PermSet& Perm) {};
void mu_1__type_11::Limit(PermSet& Perm) {};
void mu_1__type_11::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_12::Permute(PermSet& Perm, int i)
{
  static mu_1__type_12 temp("Permute_mu_1__type_12",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_12::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_12::Canonicalize(PermSet& Perm){};
void mu_1__type_12::SimpleLimit(PermSet& Perm){}
void mu_1__type_12::ArrayLimit(PermSet& Perm) {}
void mu_1__type_12::Limit(PermSet& Perm){}
void mu_1__type_12::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_13::Permute(PermSet& Perm, int i)
{
  static mu_1__type_13 temp("Permute_mu_1__type_13",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_13::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_13::Canonicalize(PermSet& Perm){};
void mu_1__type_13::SimpleLimit(PermSet& Perm){}
void mu_1__type_13::ArrayLimit(PermSet& Perm) {}
void mu_1__type_13::Limit(PermSet& Perm){}
void mu_1__type_13::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
  mu_Cache.Permute(Perm,i);
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{
  mu_Cache.SimpleCanonicalize(Perm);
};
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm)
{
  mu_Cache.SimpleLimit(Perm);
};
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_14::Permute(PermSet& Perm, int i)
{
  static mu_1__type_14 temp("Permute_mu_1__type_14",-1);
  int j;
  for (j=0; j<8; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_14::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_14::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::MultisetLimit(PermSet& Perm)
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
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[2][2];
  bool goodset_mu_1_Value[2];
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[5][5];
  bool goodset_mu_1_Proc[5];
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
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }
  // initializing pos array
  for (i=0; i<5; i++)
    for (j=0; j<5; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<5; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<5);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Value = count_mu_1_Value;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<5) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_Source.isundefined())
                && (*this)[k].mu_Source>=2
                && (*this)[k].mu_Source<=6)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<5; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Source.isundefined()
                          && (*this)[k].mu_Source>=2
                          && (*this)[k].mu_Source<=6
                          && pos_mu_1_Proc[j][(*this)[k].mu_Source-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_Source-2] = TRUE;
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
                        for (k=0; k<5; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<5; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<5; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<5) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_Destination.isundefined())
                && (*this)[k].mu_Destination>=2
                && (*this)[k].mu_Destination<=6)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<5; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Destination.isundefined()
                          && (*this)[k].mu_Destination>=2
                          && (*this)[k].mu_Destination<=6
                          && pos_mu_1_Proc[j][(*this)[k].mu_Destination-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_Destination-2] = TRUE;
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
                        for (k=0; k<5; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<5; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<5; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<5) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_Aux.isundefined())
                && (*this)[k].mu_Aux>=2
                && (*this)[k].mu_Aux<=6)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<5; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Aux.isundefined()
                          && (*this)[k].mu_Aux>=2
                          && (*this)[k].mu_Aux<=6
                          && pos_mu_1_Proc[j][(*this)[k].mu_Aux-2])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_Aux-2] = TRUE;
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
                        for (k=0; k<5; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<5; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<5; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_Value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_Value.isundefined()
                          && pos_mu_1_Value[j][(*this)[k].mu_Value-8])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k].mu_Value-8] = TRUE;
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
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Value<2;
      while_guard = while_guard || count_mu_1_Proc<5;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<5; i++)
        for (j=0; j<5; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<5; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1__type_15::Permute(PermSet& Perm, int i)
{
  static mu_1__type_15 temp("Permute_mu_1__type_15",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_15::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_15::Canonicalize(PermSet& Perm){};
void mu_1__type_15::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_15::ArrayLimit(PermSet& Perm) {}
void mu_1__type_15::Limit(PermSet& Perm){}
void mu_1__type_15::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_16::Permute(PermSet& Perm, int i)
{
  static mu_1__type_16 temp("Permute_mu_1__type_16",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=6; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-2]];};
void mu_1__type_16::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_16::Canonicalize(PermSet& Perm){};
void mu_1__type_16::SimpleLimit(PermSet& Perm){}
void mu_1__type_16::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[5];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[5];
  bool pos_mu_1_Proc[5][5];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<5; i++)
        for (j=0; j<5; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<5; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<5; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<5; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<5; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<5; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<5; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<5; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<5; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<5; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_16::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_ProcState value[5];
  // limit
  bool exists;
  bool split;
  int i0,i1;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[5][5];
  bool goodset_mu_1_Proc[5];
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[2][2];
  bool goodset_mu_1_Value[2];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<5; i++)
    for (j=0; j<5; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<5; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<5);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2);
  while ( while_guard )
    {
      oldcount_mu_1_Proc = count_mu_1_Proc;
      oldcount_mu_1_Value = count_mu_1_Value;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<5)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<5; k++) // step through class
            if ((*this)[k+2].mu_Cache[mu_Home_1][mu_Address_1].mu_Value.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<5; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<5; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+2].mu_Cache[mu_Home_1][mu_Address_1].mu_Value.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+2].mu_Cache[mu_Home_1][mu_Address_1].mu_Value-8])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+2].mu_Cache[mu_Home_1][mu_Address_1].mu_Value-8] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<5; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<5; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<5; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Proc<5;
      while_guard = while_guard || count_mu_1_Value<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<5; i++)
        for (j=0; j<5; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<5; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
}
void mu_1__type_16::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu__subrange_30::Permute(PermSet& Perm, int i) {};
void mu__subrange_30::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_30::Canonicalize(PermSet& Perm) {};
void mu__subrange_30::SimpleLimit(PermSet& Perm) {};
void mu__subrange_30::ArrayLimit(PermSet& Perm) {};
void mu__subrange_30::Limit(PermSet& Perm) {};
void mu__subrange_30::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_38::Permute(PermSet& Perm, int i) {};
void mu__subrange_38::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_38::Canonicalize(PermSet& Perm) {};
void mu__subrange_38::SimpleLimit(PermSet& Perm) {};
void mu__subrange_38::ArrayLimit(PermSet& Perm) {};
void mu__subrange_38::Limit(PermSet& Perm) {};
void mu__subrange_38::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_39::Permute(PermSet& Perm, int i) {};
void mu__subrange_39::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_39::Canonicalize(PermSet& Perm) {};
void mu__subrange_39::SimpleLimit(PermSet& Perm) {};
void mu__subrange_39::ArrayLimit(PermSet& Perm) {};
void mu__subrange_39::Limit(PermSet& Perm) {};
void mu__subrange_39::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_40::Permute(PermSet& Perm, int i) {};
void mu__subrange_40::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_40::Canonicalize(PermSet& Perm) {};
void mu__subrange_40::SimpleLimit(PermSet& Perm) {};
void mu__subrange_40::ArrayLimit(PermSet& Perm) {};
void mu__subrange_40::Limit(PermSet& Perm) {};
void mu__subrange_40::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_41::Permute(PermSet& Perm, int i) {};
void mu__subrange_41::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_41::Canonicalize(PermSet& Perm) {};
void mu__subrange_41::SimpleLimit(PermSet& Perm) {};
void mu__subrange_41::ArrayLimit(PermSet& Perm) {};
void mu__subrange_41::Limit(PermSet& Perm) {};
void mu__subrange_41::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

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
              
              mu_Homes.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Homes.MultisetSort();
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
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

          mu_Homes.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Homes.MultisetSort();
          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Homes.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Homes.MultisetSort();
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
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
      mu_Homes.MultisetSort();
      mu_Procs.MultisetSort();
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
        mu_Homes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Homes.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
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

  mu_Homes.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
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

  mu_Homes.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Net.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();
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
      mu_Procs.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Procs.MultisetSort();
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

  mu_Homes.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();

  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
