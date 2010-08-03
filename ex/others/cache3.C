/******************************
  Program "cache3.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "cache3"
#define BITS_IN_WORLD 87
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
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Home& val) { return mu__byte::operator=((int) val); };
  mu_1_Home (char *name, int os): mu__byte(0, 0, 1, name, os) {};
  mu_1_Home (void): mu__byte(0, 0, 1) {};
  mu_1_Home (int val): mu__byte(0, 0, 1, "Parameter or function result.", 0)
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
mu_1_Home mu_1_Home_undefined_var;

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Proc& val) { return mu__byte::operator=((int) val); };
  mu_1_Proc (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1_Proc (void): mu__byte(0, 1, 2) {};
  mu_1_Proc (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Node& val) { return mu__byte::operator=((int) val); };
  mu_1_Node (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1_Node (void): mu__byte(0, 1, 2) {};
  mu_1_Node (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu_1_Node mu_1_Node_undefined_var;

class mu_1_Address: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Address& val) { return mu__byte::operator=((int) val); };
  mu_1_Address (char *name, int os): mu__byte(0, 0, 1, name, os) {};
  mu_1_Address (void): mu__byte(0, 0, 1) {};
  mu_1_Address (int val): mu__byte(0, 0, 1, "Parameter or function result.", 0)
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
mu_1_Address mu_1_Address_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Value& val) { return mu__byte::operator=((int) val); };
  mu_1_Value (char *name, int os): mu__byte(0, 0, 1, name, os) {};
  mu_1_Value (void): mu__byte(0, 0, 1) {};
  mu_1_Value (int val): mu__byte(0, 0, 1, "Parameter or function result.", 0)
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
      return ( s << mu_1_Message_Type::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_Message_Type (char *name, int os): mu__byte(1, 15, 4, name, os) {};
  mu_1_Message_Type (void): mu__byte(1, 15, 4) {};
  mu_1_Message_Type (int val): mu__byte(1, 15, 4, "Parameter or function result.", 0)
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
  mu_Destination.set_self_2(name, ".Destination", os + 6 );
  mu_Aux.set_self_2(name, ".Aux", os + 8 );
  mu_Address.set_self_2(name, ".Address", os + 10 );
  mu_Value.set_self_2(name, ".Value", os + 11 );
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
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 1 + os);
    delete[] s;
  }
};
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
      return ( s << mu_1__type_1::values[ int(val) - 16] );
    else return ( s << "Undefined" );
  };

  mu_1__type_1 (char *name, int os): mu__byte(16, 21, 3, name, os) {};
  mu_1__type_1 (void): mu__byte(16, 21, 3) {};
  mu_1__type_1 (int val): mu__byte(16, 21, 3, "Parameter or function result.", 0)
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

char *mu_1__type_1::values[] = {"Inv","Shared_Remote","Master_Remote","Wait_Inv","Wait_Update","Wait_WB",NULL };

/*** end of enum declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__byte::operator=((int) val); };
  mu_1__type_2 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_2 (void): mu__byte(0, 2, 2) {};
  mu_1__type_2 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_12 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_12 (void): mu__byte(0, 1, 2) {};
  mu__subrange_12 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
  mu_1_Proc array[ 2 ];
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
    if ( ( index >= 0 ) && ( index <= 1 ) )
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
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
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
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
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
  mu_1__type_1 mu_State;
  mu_1__type_2 mu_Shared_Count;
  mu_1__type_3 mu_Entries;
  mu_1_Proc mu_Inv_Count;
  mu_1__type_4 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_4 ( void ) {};

  virtual ~mu_1__type_4(); 
friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
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
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
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
  mu_1__type_4& operator= (const mu_1__type_4& from) {
    mu_State.value(from.mu_State.value());
    mu_Shared_Count.value(from.mu_Shared_Count.value());
    mu_Entries = from.mu_Entries;
    mu_Inv_Count.value(from.mu_Inv_Count.value());
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
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_Shared_Count.set_self_2(name, ".Shared_Count", os + 3 );
  mu_Entries.set_self_2(name, ".Entries", os + 5 );
  mu_Inv_Count.set_self_2(name, ".Inv_Count", os + 9 );
}

mu_1__type_4::~mu_1__type_4()
{
}

/*** end record declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1__type_4 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1__type_4& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
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
void mu_1__type_5::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 11 + os);
    delete[] s;
  }
};
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_Mem;
  mu_1__type_5 mu_Dir;
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
  mu_Dir.set_self_2(name, ".Dir", os + 1 );
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_6: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_6& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_6& val)
  {
    if (val.defined())
      return ( s << mu_1__type_6::values[ int(val) - 22] );
    else return ( s << "Undefined" );
  };

  mu_1__type_6 (char *name, int os): mu__byte(22, 24, 2, name, os) {};
  mu_1__type_6 (void): mu__byte(22, 24, 2) {};
  mu_1__type_6 (int val): mu__byte(22, 24, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -22]; };
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
      cout << name << ":" << values[ value() -22] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_6::values[] = {"I","S","M",NULL };

/*** end of enum declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_6 mu_State;
  mu_1_Value mu_Value;
  mu_1__type_7 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_7 ( void ) {};

  virtual ~mu_1__type_7(); 
friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Value, b.mu_Value);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
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
  mu_1__type_7& operator= (const mu_1__type_7& from) {
    mu_State.value(from.mu_State.value());
    mu_Value.value(from.mu_Value.value());
    return *this;
  };
};

  void mu_1__type_7::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_Value.set_self_2(name, ".Value", os + 2 );
}

mu_1__type_7::~mu_1__type_7()
{
}

/*** end record declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8
{
 public:
  mu_1__type_7 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_8 (char *n, int os) { set_self(n, os); };
  mu_1__type_8 ( void ) {};
  virtual ~mu_1__type_8 ();
  mu_1__type_7& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
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
void mu_1__type_8::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_8::~mu_1__type_8()
{
}
/*** end array declaration ***/
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
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_9::~mu_1__type_9()
{
}
/*** end array declaration ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_10& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_10& val)
  {
    if (val.defined())
      return ( s << mu_1__type_10::values[ int(val) - 25] );
    else return ( s << "Undefined" );
  };

  mu_1__type_10 (char *name, int os): mu__byte(25, 30, 3, name, os) {};
  mu_1__type_10 (void): mu__byte(25, 30, 3) {};
  mu_1__type_10 (int val): mu__byte(25, 30, 3, "Parameter or function result.", 0)
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

char *mu_1__type_10::values[] = {"NOP","CR_Pend","CRE_Pend","CP_Pend","WB_Pend","Uncache_Pend",NULL };

/*** end of enum declaration ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu_1__type_11
{
 public:
  mu_1__type_10 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_11 (char *n, int os) { set_self(n, os); };
  mu_1__type_11 ( void ) {};
  virtual ~mu_1__type_11 ();
  mu_1__type_10& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  mu_1__type_11& operator= (const mu_1__type_11& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_11& a, mu_1__type_11& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_11& a, mu_1__type_11& b)
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

  void mu_1__type_11::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_11::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_11::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_11::~mu_1__type_11()
{
}
/*** end array declaration ***/
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
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  mu_1__type_12& operator= (const mu_1__type_12& from)
  {
      array[0] = from.array[0];
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
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_12::~mu_1__type_12()
{
}
/*** end array declaration ***/
mu_1__type_12 mu_1__type_12_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_9 mu_Cache;
  mu_1__type_12 mu_PMMState;
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
  mu_PMMState.set_self_2(name, ".PMMState", os + 3 );
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_13
{
 public:
  mu_1_HomeState array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_13 (char *n, int os) { set_self(n, os); };
  mu_1__type_13 ( void ) {};
  virtual ~mu_1__type_13 ();
  mu_1_HomeState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 0 ) )
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
  char* s;
  name = n;
  for(int i = 0; i < 1; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 12 + os);
    delete[] s;
  }
};
mu_1__type_13::~mu_1__type_13()
{
}
/*** end array declaration ***/
mu_1__type_13 mu_1__type_13_undefined_var;

class mu_1__type_14
{
 public:
  mu_1_ProcState array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_14 (char *n, int os) { set_self(n, os); };
  mu_1__type_14 ( void ) {};
  virtual ~mu_1__type_14 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
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
  mu_1__type_14& operator= (const mu_1__type_14& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_14& a, mu_1__type_14& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_14& a, mu_1__type_14& b)
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
  char* s;
  name = n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 6 + os);
    delete[] s;
  }
};
mu_1__type_14::~mu_1__type_14()
{
}
/*** end array declaration ***/
mu_1__type_14 mu_1__type_14_undefined_var;

class mu_1__type_15: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_15& val) { return mu__byte::operator=((int) val); };
  mu_1__type_15 (char *name, int os): mu__byte(0, 5, 3, name, os) {};
  mu_1__type_15 (void): mu__byte(0, 5, 3) {};
  mu_1__type_15 (int val): mu__byte(0, 5, 3, "Parameter or function result.", 0)
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
mu_1__type_15 mu_1__type_15_undefined_var;

class mu__subrange_28: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_28& val) { return mu__byte::operator=((int) val); };
  mu__subrange_28 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_28 (void): mu__byte(0, 4, 3) {};
  mu__subrange_28 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_28 mu__subrange_28_undefined_var;

class mu_1__type_16
{
 public:
  mu_1_Message array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_16 (char *n, int os) { set_self(n, os); };
  mu_1__type_16 ( void ) {};
  virtual ~mu_1__type_16 ();
  mu_1_Message& operator[] (int index) /* const */
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
  mu_1__type_16& operator= (const mu_1__type_16& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_16& a, mu_1__type_16& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
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
  char* s;
  name = n;
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 12 + os);
    delete[] s;
  }
};
mu_1__type_16::~mu_1__type_16()
{
}
/*** end array declaration ***/
mu_1__type_16 mu_1__type_16_undefined_var;

class mu_1__type_17
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_15 mu_Count;
  mu_1__type_16 mu_Ar;
  mu_1__type_17 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_17 ( void ) {};

  virtual ~mu_1__type_17(); 
friend int CompareWeight(mu_1__type_17& a, mu_1__type_17& b)
  {
    int w;
    w = CompareWeight(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Ar, b.mu_Ar);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_17& a, mu_1__type_17& b)
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
  mu_1__type_17& operator= (const mu_1__type_17& from) {
    mu_Count.value(from.mu_Count.value());
    mu_Ar = from.mu_Ar;
    return *this;
  };
};

  void mu_1__type_17::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_17::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_17::set_self(char *n, int os)
{
  name = n;
  mu_Count.set_self_2(name, ".Count", os + 0 );
  mu_Ar.set_self_2(name, ".Ar", os + 3 );
}

mu_1__type_17::~mu_1__type_17()
{
}

/*** end record declaration ***/
mu_1__type_17 mu_1__type_17_undefined_var;

class mu_1__type_18: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_18& val) { return mu__byte::operator=((int) val); };
  mu_1__type_18 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1__type_18 (void): mu__byte(0, 4, 3) {};
  mu_1__type_18 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu_1__type_18 mu_1__type_18_undefined_var;

class mu__subrange_32: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_32& val) { return mu__byte::operator=((int) val); };
  mu__subrange_32 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_32 (void): mu__byte(0, 3, 3) {};
  mu__subrange_32 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_32 mu__subrange_32_undefined_var;

class mu__subrange_33: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_33& val) { return mu__byte::operator=((int) val); };
  mu__subrange_33 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_33 (void): mu__byte(0, 1, 2) {};
  mu__subrange_33 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu__subrange_33 mu__subrange_33_undefined_var;

class mu__subrange_34: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_34& val) { return mu__byte::operator=((int) val); };
  mu__subrange_34 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_34 (void): mu__byte(0, 4, 3) {};
  mu__subrange_34 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_34 mu__subrange_34_undefined_var;

class mu__subrange_35: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_35& val) { return mu__byte::operator=((int) val); };
  mu__subrange_35 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_35 (void): mu__byte(0, 4, 3) {};
  mu__subrange_35 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_35 mu__subrange_35_undefined_var;

class mu__subrange_36: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_36& val) { return mu__byte::operator=((int) val); };
  mu__subrange_36 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_36 (void): mu__byte(0, 1, 2) {};
  mu__subrange_36 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu__subrange_36 mu__subrange_36_undefined_var;

class mu__subrange_37: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_37& val) { return mu__byte::operator=((int) val); };
  mu__subrange_37 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_37 (void): mu__byte(0, 1, 2) {};
  mu__subrange_37 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu__subrange_37 mu__subrange_37_undefined_var;

class mu__subrange_38: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_38& val) { return mu__byte::operator=((int) val); };
  mu__subrange_38 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_38 (void): mu__byte(0, 1, 2) {};
  mu__subrange_38 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
  mu__subrange_40 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_40 (void): mu__byte(0, 1, 2) {};
  mu__subrange_40 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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

class mu__subrange_42: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_42& val) { return mu__byte::operator=((int) val); };
  mu__subrange_42 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_42 (void): mu__byte(0, 4, 3) {};
  mu__subrange_42 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_42 mu__subrange_42_undefined_var;

const int mu_HomeCount = 1;
const int mu_ProcCount = 2;
const int mu_AddressCount = 1;
const int mu_ValueCount = 1;
const int mu_DirMax = 2;
const int mu_NetMax = 5;
const int mu_Cache_Read = 1;
const int mu_Cache_Read_Ex = 2;
const int mu_Cache_Promote = 3;
const int mu_Uncache = 4;
const int mu_Write_Back = 5;
const int mu_Update = 6;
const int mu_Data = 7;
const int mu_Invalidate = 8;
const int mu_Uncache_Ack = 9;
const int mu_Write_Back_Ack = 10;
const int mu_Inv_Ack = 11;
const int mu_Fw_Cache_R = 12;
const int mu_Fw_Cache_R_Ex = 13;
const int mu_Ack_Fw_Cache_Ex = 14;
const int mu_Cache_Promote_Ack = 15;
const int mu_Inv = 16;
const int mu_Shared_Remote = 17;
const int mu_Master_Remote = 18;
const int mu_Wait_Inv = 19;
const int mu_Wait_Update = 20;
const int mu_Wait_WB = 21;
const int mu_I = 22;
const int mu_S = 23;
const int mu_M = 24;
const int mu_NOP = 25;
const int mu_CR_Pend = 26;
const int mu_CRE_Pend = 27;
const int mu_CP_Pend = 28;
const int mu_WB_Pend = 29;
const int mu_Uncache_Pend = 30;
/*** Variable declaration ***/
mu_1__type_13 mu_Homes("Homes",0);

/*** Variable declaration ***/
mu_1__type_14 mu_Procs("Procs",12);

/*** Variable declaration ***/
mu_1__type_17 mu_Net("Net",24);

void mu_Send(const mu_1_Message_Type& mu_t, const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Loc, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Val)
{
if ( (mu_Net.mu_Count) == (mu_NetMax) )
{
Error.Error("Error: Network is full");
}
else
{
if (mu_t.isundefined())
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_MType.undefine();
else
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_MType = mu_t;
if (mu_Src.isundefined())
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Source.undefine();
else
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Source = mu_Src;
if (mu_Dst.isundefined())
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Destination.undefine();
else
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Destination = mu_Dst;
if (mu_Loc.isundefined())
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Aux.undefine();
else
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Aux = mu_Loc;
if (mu_Addr.isundefined())
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Address.undefine();
else
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Address = mu_Addr;
if (mu_Val.isundefined())
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Value.undefine();
else
  mu_Net.mu_Ar[mu_Net.mu_Count].mu_Value = mu_Val;
mu_Net.mu_Count = (mu_Net.mu_Count) + (1);
}
};
/*** end procedure declaration ***/

void mu_Consume_Message(const mu_1__type_18& mu_M_Index)
{
if ( (mu_M_Index) >= (mu_Net.mu_Count) )
{
Error.Error("Error: Invalid Message Index");
}
else
{
{
for(int mu_i = 0; mu_i <= 3; mu_i++) {
if ( (mu_i) >= (mu_M_Index) )
{
mu_Net.mu_Ar[mu_i] = mu_Net.mu_Ar[(mu_i) + (1)];
}
};
};
mu_Net.mu_Ar[(mu_Net.mu_Count) - (1)].mu_MType = mu_Cache_Read;
mu_Net.mu_Ar[(mu_Net.mu_Count) - (1)].mu_Source = 0;
mu_Net.mu_Ar[(mu_Net.mu_Count) - (1)].mu_Destination = 0;
mu_Net.mu_Ar[(mu_Net.mu_Count) - (1)].mu_Aux = 0;
mu_Net.mu_Ar[(mu_Net.mu_Count) - (1)].mu_Address = 0;
mu_Net.mu_Ar[(mu_Net.mu_Count) - (1)].mu_Value = 0;
}
mu_Net.mu_Count = (mu_Net.mu_Count) - (1);
};
/*** end procedure declaration ***/

void mu_Send_Cache_Read(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Read, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Cache_Read_Ex(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Read_Ex, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Uncache(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Uncache, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Uncache_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Uncache_Ack, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Data(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Home, const mu_1_Address& mu_addr, const mu_1_Value& mu_val)
{
mu_Send ( mu_Data, mu_Dst, mu_Src, mu_Home, mu_addr, mu_val );
};
/*** end procedure declaration ***/

void mu_Send_Fw_Cache_R(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Loc, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Fw_Cache_R, mu_Dst, mu_Src, mu_Loc, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Fw_Cache_R_Ex(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Node& mu_Loc, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Fw_Cache_R_Ex, mu_Dst, mu_Src, mu_Loc, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Ack_Fw_Cache_Ex(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Ack_Fw_Cache_Ex, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Invalidate(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Invalidate, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Inv_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Inv_Ack, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Write_Back(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Data)
{
mu_Send ( mu_Write_Back, mu_Dst, mu_Src, 0, mu_Addr, mu_Data );
};
/*** end procedure declaration ***/

void mu_Send_Update(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr, const mu_1_Value& mu_Data)
{
mu_Send ( mu_Update, mu_Dst, mu_Src, 0, mu_Addr, mu_Data );
};
/*** end procedure declaration ***/

void mu_Send_Cache_Promote(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Promote, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Cache_Promote_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Cache_Promote_Ack, mu_Dst, mu_Src, 0, mu_Addr, 0 );
};
/*** end procedure declaration ***/

void mu_Send_Write_Back_Ack(const mu_1_Node& mu_Dst, const mu_1_Node& mu_Src, const mu_1_Address& mu_Addr)
{
mu_Send ( mu_Write_Back_Ack, mu_Dst, mu_Src, 0, mu_Addr, 0 );
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
for(int mu_i = 0; mu_i <= 1; mu_i++) {
bool mu__boolexpr19;
  if (!((mu_i) < (mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_i]) == (mu_n)) ; 
}
if ( mu__boolexpr19 )
{
mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_i] = mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[(mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) - (1)];
mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[(mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count) - (1)] = 0;
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
Error.Error("Error: Should be in RE state");
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
mu_Procs[mu_n].mu_Cache[mu_home][mu_addr].mu_Value = 0;
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
mu_Procs[mu_n].mu_Cache[mu_home][mu_addr].mu_Value = 0;
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_Homes.clear();
  mu_Procs.clear();
  mu_Net.clear();
}
void world_class::undefine()
{
  mu_Homes.undefine();
  mu_Procs.undefine();
  mu_Net.undefine();
}
void world_class::reset()
{
  mu_Homes.reset();
  mu_Procs.reset();
  mu_Net.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Homes.print();
  mu_Procs.print();
  mu_Net.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Homes.print_statistic();
  mu_Procs.print_statistic();
  mu_Net.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_Homes.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_Homes.to_state( newstate );
  mu_Procs.to_state( newstate );
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
    static mu__subrange_35 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
    return tsprintf("Rule 7, M_Index:%s", mu_M_Index.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_35 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_M_Index];
  mu_1_Node& mu_n = mu_msg.mu_Destination;
bool mu__boolexpr20;
  if (!((mu_M_Index) < (mu_Net.mu_Count))) mu__boolexpr20 = FALSE ;
  else {
bool mu__boolexpr21;
bool mu__boolexpr22;
bool mu__boolexpr23;
bool mu__boolexpr24;
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
  if ((mu_msg.mu_MType) == (mu_Cache_Read)) mu__boolexpr27 = TRUE ;
  else {
  mu__boolexpr27 = ((mu_msg.mu_MType) == (mu_Cache_Read_Ex)) ; 
}
  if (mu__boolexpr27) mu__boolexpr26 = TRUE ;
  else {
  mu__boolexpr26 = ((mu_msg.mu_MType) == (mu_Cache_Promote)) ; 
}
  if (mu__boolexpr26) mu__boolexpr25 = TRUE ;
  else {
  mu__boolexpr25 = ((mu_msg.mu_MType) == (mu_Write_Back)) ; 
}
  if (mu__boolexpr25) mu__boolexpr24 = TRUE ;
  else {
  mu__boolexpr24 = ((mu_msg.mu_MType) == (mu_Update)) ; 
}
  if (mu__boolexpr24) mu__boolexpr23 = TRUE ;
  else {
  mu__boolexpr23 = ((mu_msg.mu_MType) == (mu_Uncache)) ; 
}
  if (mu__boolexpr23) mu__boolexpr22 = TRUE ;
  else {
  mu__boolexpr22 = ((mu_msg.mu_MType) == (mu_Ack_Fw_Cache_Ex)) ; 
}
  if (mu__boolexpr22) mu__boolexpr21 = TRUE ;
  else {
  mu__boolexpr21 = ((mu_msg.mu_MType) == (mu_Inv_Ack)) ; 
}
  mu__boolexpr20 = (mu__boolexpr21) ; 
}
  return mu__boolexpr20;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_35 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
    while (what_rule < 5 )
      {
        if ( ( TRUE  ) ) {
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_M_Index];
  mu_1_Node& mu_n = mu_msg.mu_Destination;
bool mu__boolexpr28;
  if (!((mu_M_Index) < (mu_Net.mu_Count))) mu__boolexpr28 = FALSE ;
  else {
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
bool mu__boolexpr35;
  if ((mu_msg.mu_MType) == (mu_Cache_Read)) mu__boolexpr35 = TRUE ;
  else {
  mu__boolexpr35 = ((mu_msg.mu_MType) == (mu_Cache_Read_Ex)) ; 
}
  if (mu__boolexpr35) mu__boolexpr34 = TRUE ;
  else {
  mu__boolexpr34 = ((mu_msg.mu_MType) == (mu_Cache_Promote)) ; 
}
  if (mu__boolexpr34) mu__boolexpr33 = TRUE ;
  else {
  mu__boolexpr33 = ((mu_msg.mu_MType) == (mu_Write_Back)) ; 
}
  if (mu__boolexpr33) mu__boolexpr32 = TRUE ;
  else {
  mu__boolexpr32 = ((mu_msg.mu_MType) == (mu_Update)) ; 
}
  if (mu__boolexpr32) mu__boolexpr31 = TRUE ;
  else {
  mu__boolexpr31 = ((mu_msg.mu_MType) == (mu_Uncache)) ; 
}
  if (mu__boolexpr31) mu__boolexpr30 = TRUE ;
  else {
  mu__boolexpr30 = ((mu_msg.mu_MType) == (mu_Ack_Fw_Cache_Ex)) ; 
}
  if (mu__boolexpr30) mu__boolexpr29 = TRUE ;
  else {
  mu__boolexpr29 = ((mu_msg.mu_MType) == (mu_Inv_Ack)) ; 
}
  mu__boolexpr28 = (mu__boolexpr29) ; 
}
              if (mu__boolexpr28) {
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
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_35 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_M_Index];
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
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Shared_Remote:
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Send_Data ( mu_msg.mu_Source, mu_n, mu_n, mu_msg.mu_Address, mu_me.mu_Mem[mu_msg.mu_Address] );
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Master_Remote:
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Update;
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 1;
mu_Send_Fw_Cache_R ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0], mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Update;
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Shared_Remote:
{
for(int mu_i = 0; mu_i <= 1; mu_i++) {
if ( (mu_i) < (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count) )
{
mu_Send_Invalidate ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[mu_i], mu_n, mu_msg.mu_Address );
}
};
};
mu_me.mu_Dir[mu_msg.mu_Address].mu_Inv_Count = mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count;
mu_Send_Data ( mu_msg.mu_Source, mu_n, mu_n, mu_msg.mu_Address, mu_me.mu_Mem[mu_msg.mu_Address] );
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries.clear();
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 0;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Inv;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Master_Remote:
mu_Send_Fw_Cache_R_Ex ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0], mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries.clear();
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 0;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_WB;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Consume_Message ( (int)mu_M_Index );
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
for(int mu_i = 0; mu_i <= 1; mu_i++) {
bool mu__boolexpr36;
  if (!((mu_i) < (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count))) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[mu_i]) != (mu_msg.mu_Source)) ; 
}
if ( mu__boolexpr36 )
{
mu_Send_Invalidate ( (int)mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[mu_i], mu_n, mu_msg.mu_Address );
}
};
};
mu_me.mu_Dir[mu_msg.mu_Address].mu_Inv_Count = (mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count) - (1);
mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries.clear();
mu_me.mu_Dir[mu_msg.mu_Address].mu_Shared_Count = 0;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Wait_Inv;
mu_add_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
}
mu_Send_Cache_Promote_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Wait_Inv:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Master_Remote:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Wait_WB:
if ( (mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0]) != (mu_msg.mu_Source) )
{
mu_me.mu_Mem[mu_msg.mu_Address] = mu_msg.mu_Value;
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Master_Remote;
mu_Consume_Message ( (int)mu_M_Index );
}
break;
case mu_Wait_Update:
mu_me.mu_Mem[mu_msg.mu_Address] = mu_msg.mu_Value;
mu_remove_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_me.mu_Dir[mu_msg.mu_Address].mu_State = mu_Shared_Remote;
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Wait_Inv:
if ( (mu_me.mu_Dir[mu_msg.mu_Address].mu_Entries[0]) != (mu_msg.mu_Source) )
{
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Wait_Update:
break;
default:
bool mu__boolexpr37;
  if ((mu_me.mu_Dir[mu_msg.mu_Address].mu_State) == (mu_Shared_Remote)) mu__boolexpr37 = TRUE ;
  else {
  mu__boolexpr37 = ((mu_me.mu_Dir[mu_msg.mu_Address].mu_State) == (mu_Wait_Update)) ; 
}
if ( mu__boolexpr37 )
{
mu_remove_dir_entry ( mu_n, mu_msg.mu_Address, mu_msg.mu_Source );
mu_Send_Uncache_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
break;
default:
Error.Error("Error: Ack_Fw_Cache_Ex received in funny Dir state");
break;
}
break;
case mu_Inv_Ack:
mu_Handle_Inv_Ack ( mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
    static mu__subrange_34 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
    return tsprintf("Rule 6, M_Index:%s", mu_M_Index.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_34 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_M_Index];
  mu_1_Node& mu_n = mu_msg.mu_Destination;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
  return (mu_M_Index) < (mu_Net.mu_Count);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5;
    static mu__subrange_34 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
    while (what_rule < 10 )
      {
        if ( ( TRUE  ) ) {
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_M_Index];
  mu_1_Node& mu_n = mu_msg.mu_Destination;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
              if ((mu_M_Index) < (mu_Net.mu_Count)) {
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
    r = what_rule - 5;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_34 mu_M_Index;
    mu_M_Index.value((r % 5) + 0);
    r = r / 5;
  mu_1_Message& mu_msg = mu_Net.mu_Ar[mu_M_Index];
  mu_1_Node& mu_n = mu_msg.mu_Destination;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
switch ((int) mu_msg.mu_MType) {
case mu_Data:
switch ((int) mu_me.mu_PMMState[mu_msg.mu_Aux][mu_msg.mu_Address]) {
case mu_CR_Pend:
mu_me.mu_PMMState[mu_msg.mu_Aux][mu_msg.mu_Address] = mu_NOP;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_State = mu_S;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_Value = mu_msg.mu_Value;
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_CRE_Pend:
mu_me.mu_PMMState[mu_msg.mu_Aux][mu_msg.mu_Address] = mu_NOP;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_State = mu_M;
mu_me.mu_Cache[mu_msg.mu_Aux][mu_msg.mu_Address].mu_Value = mu_msg.mu_Value;
mu_Consume_Message ( (int)mu_M_Index );
break;
default:
Error.Error("Error: Data received in funny PMMState");
break;
}
break;
case mu_Invalidate:
bool mu__boolexpr38;
  if ((mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State) == (mu_S)) mu__boolexpr38 = TRUE ;
  else {
  mu__boolexpr38 = ((mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State) == (mu_I)) ; 
}
if ( mu__boolexpr38 )
{
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_State = mu_I;
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value = 0;
switch ((int) mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address]) {
case mu_NOP:
mu_Send_Inv_Ack ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_CR_Pend:
break;
case mu_CRE_Pend:
mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address] = mu_NOP;
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_CP_Pend:
mu_me.mu_PMMState[mu_msg.mu_Source][mu_msg.mu_Address] = mu_NOP;
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_Uncache_Pend:
mu_Handle_Uncache_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_CRE_Pend:
break;
case mu_CP_Pend:
break;
case mu_WB_Pend:
mu_Send_Data ( mu_msg.mu_Aux, mu_n, mu_msg.mu_Source, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_Handle_Write_Back_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value = 0;
mu_Send_Ack_Fw_Cache_Ex ( mu_msg.mu_Source, mu_n, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
break;
case mu_WB_Pend:
mu_Send_Data ( mu_msg.mu_Aux, mu_n, mu_msg.mu_Source, mu_msg.mu_Address, mu_me.mu_Cache[mu_msg.mu_Source][mu_msg.mu_Address].mu_Value );
mu_Handle_Write_Back_Ack ( mu_n, mu_msg.mu_Source, mu_msg.mu_Address );
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
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
mu_Consume_Message ( (int)mu_M_Index );
}
else
{
Error.Error("Error: Write_Back_Ack when PMMState not WB_Pend");
}
break;
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
    mu_v.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Rule 5, v:%s, a:%s, h:%s, n:%s", mu_v.Name(), mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr39;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  return mu__boolexpr39;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 10;
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr40;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
              if (mu__boolexpr40) {
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
    mu_v.value((r % 1) + 0);
    r = r / 1;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Rule 4, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr41;
bool mu__boolexpr42;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_Net.mu_Count) <= (2)) ; 
}
  return mu__boolexpr41;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 14 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr43;
bool mu__boolexpr44;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_M))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_Net.mu_Count) <= (2)) ; 
}
              if (mu__boolexpr43) {
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Rule 3, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr45;
bool mu__boolexpr46;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_Net.mu_Count) <= (2)) ; 
}
  return mu__boolexpr45;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 14;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 16 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr47;
bool mu__boolexpr48;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr48)) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_Net.mu_Count) <= (2)) ; 
}
              if (mu__boolexpr47) {
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
    r = what_rule - 14;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Rule 2, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr49;
bool mu__boolexpr50;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_Net.mu_Count) <= (2)) ; 
}
  return mu__boolexpr49;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 18 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_S))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_Net.mu_Count) <= (2)) ; 
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
    r = what_rule - 16;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Rule 1, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr53;
bool mu__boolexpr54;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_Net.mu_Count) <= (2)) ; 
}
  return mu__boolexpr53;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 18;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 20 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr55;
bool mu__boolexpr56;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_Net.mu_Count) <= (2)) ; 
}
              if (mu__boolexpr55) {
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
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
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Rule 0, a:%s, h:%s, n:%s", mu_a.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr57;
bool mu__boolexpr58;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_Net.mu_Count) <= (2)) ; 
}
  return mu__boolexpr57;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20;
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 22 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_me = mu_Procs[mu_n];
bool mu__boolexpr59;
bool mu__boolexpr60;
  if (!((mu_me.mu_Cache[mu_h][mu_a].mu_State) == (mu_I))) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_me.mu_PMMState[mu_h][mu_a]) == (mu_NOP)) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_Net.mu_Count) <= (2)) ; 
}
              if (mu__boolexpr59) {
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
    r = what_rule - 20;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_a;
    mu_a.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 0);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
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
  if (what_rule<5)
    { R0.NextRule(what_rule);
      if (what_rule<5) return; }
  if (what_rule>=5 && what_rule<10)
    { R1.NextRule(what_rule);
      if (what_rule<10) return; }
  if (what_rule>=10 && what_rule<12)
    { R2.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<14)
    { R3.NextRule(what_rule);
      if (what_rule<14) return; }
  if (what_rule>=14 && what_rule<16)
    { R4.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<18)
    { R5.NextRule(what_rule);
      if (what_rule<18) return; }
  if (what_rule>=18 && what_rule<20)
    { R6.NextRule(what_rule);
      if (what_rule<20) return; }
  if (what_rule>=20 && what_rule<22)
    { R7.NextRule(what_rule);
      if (what_rule<22) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=4) return R0.Condition(r-0);
  if (r>=5 && r<=9) return R1.Condition(r-5);
  if (r>=10 && r<=11) return R2.Condition(r-10);
  if (r>=12 && r<=13) return R3.Condition(r-12);
  if (r>=14 && r<=15) return R4.Condition(r-14);
  if (r>=16 && r<=17) return R5.Condition(r-16);
  if (r>=18 && r<=19) return R6.Condition(r-18);
  if (r>=20 && r<=21) return R7.Condition(r-20);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=4) { R0.Code(r-0); return; } 
  if (r>=5 && r<=9) { R1.Code(r-5); return; } 
  if (r>=10 && r<=11) { R2.Code(r-10); return; } 
  if (r>=12 && r<=13) { R3.Code(r-12); return; } 
  if (r>=14 && r<=15) { R4.Code(r-14); return; } 
  if (r>=16 && r<=17) { R5.Code(r-16); return; } 
  if (r>=18 && r<=19) { R6.Code(r-18); return; } 
  if (r>=20 && r<=21) { R7.Code(r-20); return; } 
}
int Priority(unsigned short r)
{
  if (r<=4) { return R0.Priority(); } 
  if (r>=5 && r<=9) { return R1.Priority(); } 
  if (r>=10 && r<=11) { return R2.Priority(); } 
  if (r>=12 && r<=13) { return R3.Priority(); } 
  if (r>=14 && r<=15) { return R4.Priority(); } 
  if (r>=16 && r<=17) { return R5.Priority(); } 
  if (r>=18 && r<=19) { return R6.Priority(); } 
  if (r>=20 && r<=21) { return R7.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=4) return R0.Name(r-0);
  if (r>=5 && r<=9) return R1.Name(r-5);
  if (r>=10 && r<=11) return R2.Name(r-10);
  if (r>=12 && r<=13) return R3.Name(r-12);
  if (r>=14 && r<=15) return R4.Name(r-14);
  if (r>=16 && r<=17) return R5.Name(r-16);
  if (r>=18 && r<=19) return R6.Name(r-18);
  if (r>=20 && r<=21) return R7.Name(r-20);
  return NULL;
}
};
const unsigned numrules = 22;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 22


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
    mu_v.value((r % 1) + 0);
    r = r / 1;
    return tsprintf("Startstate 0, v:%s", mu_v.Name());
  }
  void Code(unsigned short r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 0);
    r = r / 1;
{
for(int mu_h = 0; mu_h <= 0; mu_h++) {
{
for(int mu_a = 0; mu_a <= 0; mu_a++) {
mu_Homes[mu_h].mu_Mem[mu_a] = mu_v;
mu_Homes[mu_h].mu_Dir[mu_a].mu_State = mu_Inv;
mu_Homes[mu_h].mu_Dir[mu_a].mu_Shared_Count = 0;
{
for(int mu_i = 0; mu_i <= 1; mu_i++) {
mu_Homes[mu_h].mu_Dir[mu_a].mu_Entries[mu_i] = 0;
};
};
mu_Homes[mu_h].mu_Dir[mu_a].mu_Inv_Count = 0;
};
};
};
};
{
for(int mu_l = 0; mu_l <= 1; mu_l++) {
{
for(int mu_h = 0; mu_h <= 0; mu_h++) {
{
for(int mu_a = 0; mu_a <= 0; mu_a++) {
mu_Procs[mu_l].mu_Cache[mu_h][mu_a].mu_State = mu_I;
mu_Procs[mu_l].mu_Cache[mu_h][mu_a].mu_Value = mu_v;
mu_Procs[mu_l].mu_PMMState[mu_h][mu_a] = mu_NOP;
};
};
};
};
};
};
mu_Net.mu_Count = 0;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
mu_Net.mu_Ar.clear();
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
int mu__invariant_61() // Invariant "Invariant 2"
{
bool mu__quant62; 
mu__quant62 = TRUE;
{
for(int mu_n1 = 0; mu_n1 <= 1; mu_n1++) {
bool mu__quant63; 
mu__quant63 = TRUE;
{
for(int mu_home = 0; mu_home <= 0; mu_home++) {
bool mu__quant64; 
mu__quant64 = TRUE;
{
for(int mu_addr = 0; mu_addr <= 0; mu_addr++) {
bool mu__boolexpr65;
bool mu__boolexpr66;
bool mu__boolexpr67;
  if (!((mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_State) == (mu_S))) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_Value) != (mu_Homes[mu_home].mu_Mem[mu_addr])) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_Procs[mu_n1].mu_PMMState[mu_home][mu_addr]) != (mu_Uncache_Pend)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
bool mu__quant68; 
mu__quant68 = FALSE;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr69;
  if (!((mu_i) < (mu_Net.mu_Count))) mu__boolexpr69 = FALSE ;
  else {
bool mu__boolexpr70;
bool mu__boolexpr71;
bool mu__boolexpr72;
bool mu__boolexpr73;
  if (!((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Invalidate))) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_Net.mu_Ar[mu_i].mu_Source) == (mu_home)) ; 
}
  if (!(mu__boolexpr73)) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_Net.mu_Ar[mu_i].mu_Destination) == (mu_n1)) ; 
}
  if (mu__boolexpr72) mu__boolexpr71 = TRUE ;
  else {
bool mu__boolexpr74;
bool mu__boolexpr75;
  if (!((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Update))) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_Net.mu_Ar[mu_i].mu_Destination) == (mu_home)) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = ((mu_Net.mu_Ar[mu_i].mu_Value) == (mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_Value)) ; 
}
  mu__boolexpr71 = (mu__boolexpr74) ; 
}
  if (mu__boolexpr71) mu__boolexpr70 = TRUE ;
  else {
bool mu__boolexpr76;
bool mu__boolexpr77;
  if (!((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Write_Back))) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = ((mu_Net.mu_Ar[mu_i].mu_Destination) == (mu_home)) ; 
}
  if (!(mu__boolexpr77)) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = ((mu_Net.mu_Ar[mu_i].mu_Value) == (mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_Value)) ; 
}
  mu__boolexpr70 = (mu__boolexpr76) ; 
}
  mu__boolexpr69 = (mu__boolexpr70) ; 
}
if ( (mu__boolexpr69) )
  { mu__quant68 = TRUE; break; }
};
};
  mu__boolexpr65 = (!(mu__quant68)) ; 
}
if ( !(!(mu__boolexpr65)) )
  { mu__quant64 = FALSE; break; }
};
};
if ( !(mu__quant64) )
  { mu__quant63 = FALSE; break; }
};
};
if ( !(mu__quant63) )
  { mu__quant62 = FALSE; break; }
};
};
return mu__quant62;
};

bool mu__condition_78() // Condition for Rule "Invariant 2"
{
  return mu__invariant_61( );
}

/**** end rule declaration ****/

int mu__invariant_79() // Invariant "Invariant 1"
{
bool mu__quant80; 
mu__quant80 = TRUE;
{
for(int mu_n1 = 0; mu_n1 <= 1; mu_n1++) {
bool mu__quant81; 
mu__quant81 = TRUE;
{
for(int mu_n2 = 0; mu_n2 <= 1; mu_n2++) {
bool mu__quant82; 
mu__quant82 = TRUE;
{
for(int mu_home = 0; mu_home <= 0; mu_home++) {
bool mu__quant83; 
mu__quant83 = TRUE;
{
for(int mu_addr = 0; mu_addr <= 0; mu_addr++) {
bool mu__boolexpr84;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr84 = TRUE ;
  else {
bool mu__boolexpr85;
bool mu__boolexpr86;
  if (!((mu_Procs[mu_n1].mu_Cache[mu_home][mu_addr].mu_State) == (mu_M))) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_Procs[mu_n1].mu_PMMState[mu_home][mu_addr]) != (mu_WB_Pend)) ; 
}
  if (!(mu__boolexpr86)) mu__boolexpr85 = FALSE ;
  else {
bool mu__boolexpr87;
bool mu__boolexpr88;
  if (!((mu_Procs[mu_n2].mu_Cache[mu_home][mu_addr].mu_State) == (mu_M))) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = ((mu_Procs[mu_n2].mu_PMMState[mu_home][mu_addr]) != (mu_WB_Pend)) ; 
}
  if (mu__boolexpr88) mu__boolexpr87 = TRUE ;
  else {
bool mu__boolexpr89;
bool mu__boolexpr90;
  if (!((mu_Procs[mu_n2].mu_Cache[mu_home][mu_addr].mu_State) == (mu_S))) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_Procs[mu_n2].mu_PMMState[mu_home][mu_addr]) != (mu_Uncache_Pend)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = FALSE ;
  else {
bool mu__quant91; 
mu__quant91 = FALSE;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
  if (!((mu_i) < (mu_Net.mu_Count))) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_Net.mu_Ar[mu_i].mu_MType) == (mu_Invalidate)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = ((mu_Net.mu_Ar[mu_i].mu_Source) == (mu_home)) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = ((mu_Net.mu_Ar[mu_i].mu_Destination) == (mu_n2)) ; 
}
if ( (mu__boolexpr92) )
  { mu__quant91 = TRUE; break; }
};
};
  mu__boolexpr89 = (!(mu__quant91)) ; 
}
  mu__boolexpr87 = (mu__boolexpr89) ; 
}
  mu__boolexpr85 = (mu__boolexpr87) ; 
}
  mu__boolexpr84 = (!(mu__boolexpr85)) ; 
}
if ( !(mu__boolexpr84) )
  { mu__quant83 = FALSE; break; }
};
};
if ( !(mu__quant83) )
  { mu__quant82 = FALSE; break; }
};
};
if ( !(mu__quant82) )
  { mu__quant81 = FALSE; break; }
};
};
if ( !(mu__quant81) )
  { mu__quant80 = FALSE; break; }
};
};
return mu__quant80;
};

bool mu__condition_95() // Condition for Rule "Invariant 1"
{
  return mu__invariant_79( );
}

/**** end rule declaration ****/

int mu__invariant_96() // Invariant "Invariant 0"
{
bool mu__quant97; 
mu__quant97 = TRUE;
{
for(int mu_n = 0; mu_n <= 0; mu_n++) {
bool mu__quant98; 
mu__quant98 = TRUE;
{
for(int mu_a = 0; mu_a <= 0; mu_a++) {
bool mu__boolexpr99;
bool mu__boolexpr100;
  if (!((mu_Homes[mu_n].mu_Dir[mu_a].mu_State) == (mu_Inv))) mu__boolexpr100 = TRUE ;
  else {
  mu__boolexpr100 = ((mu_Homes[mu_n].mu_Dir[mu_a].mu_Shared_Count) == (0)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
bool mu__quant101; 
mu__quant101 = TRUE;
{
for(int mu_i = 0; mu_i <= 1; mu_i++) {
bool mu__boolexpr102;
  if (!((mu_i) >= (mu_Homes[mu_n].mu_Dir[mu_a].mu_Shared_Count))) mu__boolexpr102 = TRUE ;
  else {
  mu__boolexpr102 = ((mu_Homes[mu_n].mu_Dir[mu_a].mu_Entries[mu_i]) == (0)) ; 
}
if ( !(mu__boolexpr102) )
  { mu__quant101 = FALSE; break; }
};
};
  mu__boolexpr99 = (mu__quant101) ; 
}
if ( !(mu__boolexpr99) )
  { mu__quant98 = FALSE; break; }
};
};
if ( !(mu__quant98) )
  { mu__quant97 = FALSE; break; }
};
};
return mu__quant97;
};

bool mu__condition_103() // Condition for Rule "Invariant 0"
{
  return mu__invariant_96( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invariant 0", &mu__condition_103, NULL, FALSE},
{"Invariant 1", &mu__condition_95, NULL, FALSE},
{"Invariant 2", &mu__condition_78, NULL, FALSE},
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
Homes:NoScalarset
Procs:NoScalarset
Net:NoScalarset
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
void mu_1_Home::Permute(PermSet& Perm, int i) {};
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Home::Canonicalize(PermSet& Perm) {};
void mu_1_Home::SimpleLimit(PermSet& Perm) {};
void mu_1_Home::ArrayLimit(PermSet& Perm) {};
void mu_1_Home::Limit(PermSet& Perm) {};
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Proc::Permute(PermSet& Perm, int i) {};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Proc::Canonicalize(PermSet& Perm) {};
void mu_1_Proc::SimpleLimit(PermSet& Perm) {};
void mu_1_Proc::ArrayLimit(PermSet& Perm) {};
void mu_1_Proc::Limit(PermSet& Perm) {};
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i) {};
void mu_1_Node::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Node::Canonicalize(PermSet& Perm) {};
void mu_1_Node::SimpleLimit(PermSet& Perm) {};
void mu_1_Node::ArrayLimit(PermSet& Perm) {};
void mu_1_Node::Limit(PermSet& Perm) {};
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Address::Permute(PermSet& Perm, int i) {};
void mu_1_Address::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Address::Canonicalize(PermSet& Perm) {};
void mu_1_Address::SimpleLimit(PermSet& Perm) {};
void mu_1_Address::ArrayLimit(PermSet& Perm) {};
void mu_1_Address::Limit(PermSet& Perm) {};
void mu_1_Address::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i) {};
void mu_1_Value::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Value::Canonicalize(PermSet& Perm) {};
void mu_1_Value::SimpleLimit(PermSet& Perm) {};
void mu_1_Value::ArrayLimit(PermSet& Perm) {};
void mu_1_Value::Limit(PermSet& Perm) {};
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
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
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm){}
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
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
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
  for (j=0; j<2; j++)
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
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm){}
void mu_1__type_4::Limit(PermSet& Perm)
{
};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm) {}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm){}
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_6::Permute(PermSet& Perm, int i) {};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_6::Canonicalize(PermSet& Perm) {};
void mu_1__type_6::SimpleLimit(PermSet& Perm) {};
void mu_1__type_6::ArrayLimit(PermSet& Perm) {};
void mu_1__type_6::Limit(PermSet& Perm) {};
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_7::SimpleLimit(PermSet& Perm){}
void mu_1__type_7::ArrayLimit(PermSet& Perm){}
void mu_1__type_7::Limit(PermSet& Perm)
{
};
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_8::Canonicalize(PermSet& Perm){};
void mu_1__type_8::SimpleLimit(PermSet& Perm){}
void mu_1__type_8::ArrayLimit(PermSet& Perm) {}
void mu_1__type_8::Limit(PermSet& Perm){}
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_9::Permute(PermSet& Perm, int i)
{
  static mu_1__type_9 temp("Permute_mu_1__type_9",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_9::Canonicalize(PermSet& Perm){};
void mu_1__type_9::SimpleLimit(PermSet& Perm){}
void mu_1__type_9::ArrayLimit(PermSet& Perm) {}
void mu_1__type_9::Limit(PermSet& Perm){}
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i) {};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_10::Canonicalize(PermSet& Perm) {};
void mu_1__type_10::SimpleLimit(PermSet& Perm) {};
void mu_1__type_10::ArrayLimit(PermSet& Perm) {};
void mu_1__type_10::Limit(PermSet& Perm) {};
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_11::Permute(PermSet& Perm, int i)
{
  static mu_1__type_11 temp("Permute_mu_1__type_11",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_11::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_11::Canonicalize(PermSet& Perm){};
void mu_1__type_11::SimpleLimit(PermSet& Perm){}
void mu_1__type_11::ArrayLimit(PermSet& Perm) {}
void mu_1__type_11::Limit(PermSet& Perm){}
void mu_1__type_11::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
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
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm){}
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
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
void mu_1__type_14::Permute(PermSet& Perm, int i)
{
  static mu_1__type_14 temp("Permute_mu_1__type_14",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_14::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_14::Canonicalize(PermSet& Perm){};
void mu_1__type_14::SimpleLimit(PermSet& Perm){}
void mu_1__type_14::ArrayLimit(PermSet& Perm) {}
void mu_1__type_14::Limit(PermSet& Perm){}
void mu_1__type_14::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_15::Permute(PermSet& Perm, int i) {};
void mu_1__type_15::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_15::Canonicalize(PermSet& Perm) {};
void mu_1__type_15::SimpleLimit(PermSet& Perm) {};
void mu_1__type_15::ArrayLimit(PermSet& Perm) {};
void mu_1__type_15::Limit(PermSet& Perm) {};
void mu_1__type_15::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_28::Permute(PermSet& Perm, int i) {};
void mu__subrange_28::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_28::Canonicalize(PermSet& Perm) {};
void mu__subrange_28::SimpleLimit(PermSet& Perm) {};
void mu__subrange_28::ArrayLimit(PermSet& Perm) {};
void mu__subrange_28::Limit(PermSet& Perm) {};
void mu__subrange_28::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_16::Permute(PermSet& Perm, int i)
{
  static mu_1__type_16 temp("Permute_mu_1__type_16",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_16::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_16::Canonicalize(PermSet& Perm){};
void mu_1__type_16::SimpleLimit(PermSet& Perm){}
void mu_1__type_16::ArrayLimit(PermSet& Perm) {}
void mu_1__type_16::Limit(PermSet& Perm){}
void mu_1__type_16::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_17::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_17::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_17::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_17::SimpleLimit(PermSet& Perm){}
void mu_1__type_17::ArrayLimit(PermSet& Perm){}
void mu_1__type_17::Limit(PermSet& Perm)
{
};
void mu_1__type_17::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_18::Permute(PermSet& Perm, int i) {};
void mu_1__type_18::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_18::Canonicalize(PermSet& Perm) {};
void mu_1__type_18::SimpleLimit(PermSet& Perm) {};
void mu_1__type_18::ArrayLimit(PermSet& Perm) {};
void mu_1__type_18::Limit(PermSet& Perm) {};
void mu_1__type_18::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_32::Permute(PermSet& Perm, int i) {};
void mu__subrange_32::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_32::Canonicalize(PermSet& Perm) {};
void mu__subrange_32::SimpleLimit(PermSet& Perm) {};
void mu__subrange_32::ArrayLimit(PermSet& Perm) {};
void mu__subrange_32::Limit(PermSet& Perm) {};
void mu__subrange_32::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_33::Permute(PermSet& Perm, int i) {};
void mu__subrange_33::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_33::Canonicalize(PermSet& Perm) {};
void mu__subrange_33::SimpleLimit(PermSet& Perm) {};
void mu__subrange_33::ArrayLimit(PermSet& Perm) {};
void mu__subrange_33::Limit(PermSet& Perm) {};
void mu__subrange_33::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_34::Permute(PermSet& Perm, int i) {};
void mu__subrange_34::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_34::Canonicalize(PermSet& Perm) {};
void mu__subrange_34::SimpleLimit(PermSet& Perm) {};
void mu__subrange_34::ArrayLimit(PermSet& Perm) {};
void mu__subrange_34::Limit(PermSet& Perm) {};
void mu__subrange_34::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_35::Permute(PermSet& Perm, int i) {};
void mu__subrange_35::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_35::Canonicalize(PermSet& Perm) {};
void mu__subrange_35::SimpleLimit(PermSet& Perm) {};
void mu__subrange_35::ArrayLimit(PermSet& Perm) {};
void mu__subrange_35::Limit(PermSet& Perm) {};
void mu__subrange_35::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_36::Permute(PermSet& Perm, int i) {};
void mu__subrange_36::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_36::Canonicalize(PermSet& Perm) {};
void mu__subrange_36::SimpleLimit(PermSet& Perm) {};
void mu__subrange_36::ArrayLimit(PermSet& Perm) {};
void mu__subrange_36::Limit(PermSet& Perm) {};
void mu__subrange_36::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_37::Permute(PermSet& Perm, int i) {};
void mu__subrange_37::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_37::Canonicalize(PermSet& Perm) {};
void mu__subrange_37::SimpleLimit(PermSet& Perm) {};
void mu__subrange_37::ArrayLimit(PermSet& Perm) {};
void mu__subrange_37::Limit(PermSet& Perm) {};
void mu__subrange_37::MultisetLimit(PermSet& Perm)
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
void mu__subrange_42::Permute(PermSet& Perm, int i) {};
void mu__subrange_42::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_42::Canonicalize(PermSet& Perm) {};
void mu__subrange_42::SimpleLimit(PermSet& Perm) {};
void mu__subrange_42::ArrayLimit(PermSet& Perm) {};
void mu__subrange_42::Limit(PermSet& Perm) {};
void mu__subrange_42::MultisetLimit(PermSet& Perm)
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
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
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
