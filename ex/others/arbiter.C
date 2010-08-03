/******************************
  Program "arbiter.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "arbiter"
#define BITS_IN_WORLD 62
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu__subrange_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_2& val) { return mu__byte::operator=((int) val); };
  mu__subrange_2 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_2 (void): mu__byte(0, 3, 3) {};
  mu__subrange_2 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_2 mu__subrange_2_undefined_var;

class mu_1_reg
{
 public:
  mu_0_boolean array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1_reg (char *n, int os) { set_self(n, os); };
  mu_1_reg ( void ) {};
  virtual ~mu_1_reg ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 3 ) )
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
  mu_1_reg& operator= (const mu_1_reg& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_reg& a, mu_1_reg& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_reg& a, mu_1_reg& b)
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

  void mu_1_reg::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_reg::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_reg::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1_reg::~mu_1_reg()
{
}
/*** end array declaration ***/
mu_1_reg mu_1_reg_undefined_var;

class mu__subrange_4: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_4& val) { return mu__byte::operator=((int) val); };
  mu__subrange_4 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_4 (void): mu__byte(0, 4, 3) {};
  mu__subrange_4 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_4 mu__subrange_4_undefined_var;

class mu_1__type_0
{
 public:
  mu_0_boolean array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_0 (char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_0_boolean& operator[] (int index) /* const */
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
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 5; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
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
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu__subrange_6: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_6& val) { return mu__byte::operator=((int) val); };
  mu__subrange_6 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_6 (void): mu__byte(0, 3, 3) {};
  mu__subrange_6 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_6 mu__subrange_6_undefined_var;

class mu__subrange_7: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_7& val) { return mu__byte::operator=((int) val); };
  mu__subrange_7 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_7 (void): mu__byte(0, 3, 3) {};
  mu__subrange_7 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_7 mu__subrange_7_undefined_var;

class mu__subrange_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_8& val) { return mu__byte::operator=((int) val); };
  mu__subrange_8 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_8 (void): mu__byte(0, 3, 3) {};
  mu__subrange_8 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_8 mu__subrange_8_undefined_var;

class mu__subrange_9: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_9& val) { return mu__byte::operator=((int) val); };
  mu__subrange_9 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_9 (void): mu__byte(0, 3, 3) {};
  mu__subrange_9 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_9 mu__subrange_9_undefined_var;

class mu__subrange_10: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_10& val) { return mu__byte::operator=((int) val); };
  mu__subrange_10 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_10 (void): mu__byte(0, 3, 3) {};
  mu__subrange_10 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_10 mu__subrange_10_undefined_var;

class mu__subrange_11: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_11& val) { return mu__byte::operator=((int) val); };
  mu__subrange_11 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_11 (void): mu__byte(0, 3, 3) {};
  mu__subrange_11 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_11 mu__subrange_11_undefined_var;

const int mu_n = 4;
/*** Variable declaration ***/
mu_1_reg mu_req("req",0);

/*** Variable declaration ***/
mu_1_reg mu_use("use",8);

/*** Variable declaration ***/
mu_1_reg mu_grant("grant",16);

/*** Variable declaration ***/
mu_1__type_0 mu_tk("tk",24);

/*** Variable declaration ***/
mu_1_reg mu_flop("flop",34);

/*** Variable declaration ***/
mu_1_reg mu_ntk("ntk",42);

/*** Variable declaration ***/
mu_0_boolean mu_Req_b("Req_b",50);

/*** Variable declaration ***/
mu_0_boolean mu_Use_b("Use_b",52);

/*** Variable declaration ***/
mu_1_reg mu_p_req("p_req",54);

void mu_NewToken()
{
mu_tk[0] = mu_true;
{
for(int mu_v = 0; mu_v <= 3; mu_v++) {
mu_p_req[mu_v] = mu_req[mu_v];
};
};
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_req.clear();
  mu_use.clear();
  mu_grant.clear();
  mu_tk.clear();
  mu_flop.clear();
  mu_ntk.clear();
  mu_Req_b.clear();
  mu_Use_b.clear();
  mu_p_req.clear();
}
void world_class::undefine()
{
  mu_req.undefine();
  mu_use.undefine();
  mu_grant.undefine();
  mu_tk.undefine();
  mu_flop.undefine();
  mu_ntk.undefine();
  mu_Req_b.undefine();
  mu_Use_b.undefine();
  mu_p_req.undefine();
}
void world_class::reset()
{
  mu_req.reset();
  mu_use.reset();
  mu_grant.reset();
  mu_tk.reset();
  mu_flop.reset();
  mu_ntk.reset();
  mu_Req_b.reset();
  mu_Use_b.reset();
  mu_p_req.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_req.print();
  mu_use.print();
  mu_grant.print();
  mu_tk.print();
  mu_flop.print();
  mu_ntk.print();
  mu_Req_b.print();
  mu_Use_b.print();
  mu_p_req.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_req.print_statistic();
  mu_use.print_statistic();
  mu_grant.print_statistic();
  mu_tk.print_statistic();
  mu_flop.print_statistic();
  mu_ntk.print_statistic();
  mu_Req_b.print_statistic();
  mu_Use_b.print_statistic();
  mu_p_req.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_req.print_diff(prevstate);
    mu_use.print_diff(prevstate);
    mu_grant.print_diff(prevstate);
    mu_tk.print_diff(prevstate);
    mu_flop.print_diff(prevstate);
    mu_ntk.print_diff(prevstate);
    mu_Req_b.print_diff(prevstate);
    mu_Use_b.print_diff(prevstate);
    mu_p_req.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_req.to_state( newstate );
  mu_use.to_state( newstate );
  mu_grant.to_state( newstate );
  mu_tk.to_state( newstate );
  mu_flop.to_state( newstate );
  mu_ntk.to_state( newstate );
  mu_Req_b.to_state( newstate );
  mu_Use_b.to_state( newstate );
  mu_p_req.to_state( newstate );
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
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("token passing, u:%s", mu_u.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1;
  if (!(mu_ntk[mu_u])) mu__boolexpr1 = FALSE ;
  else {
  mu__boolexpr1 = (!(mu_flop[mu_u])) ; 
}
  return mu__boolexpr1;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 4 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr2;
  if (!(mu_ntk[mu_u])) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = (!(mu_flop[mu_u])) ; 
}
              if (mu__boolexpr2) {
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
    mu_u.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
mu_tk[(mu_u) + (1)] = mu_true;
mu_ntk[mu_u] = mu_false;
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
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("access granting, u:%s", mu_u.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr3;
  if (!(mu_ntk[mu_u])) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = (mu_flop[mu_u]) ; 
}
  return mu__boolexpr3;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 8 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr4;
  if (!(mu_ntk[mu_u])) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = (mu_flop[mu_u]) ; 
}
              if (mu__boolexpr4) {
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
    mu_u.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
mu_grant[mu_u] = mu_true;
mu_ntk[mu_u] = mu_false;
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
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("D-flip-flop, u:%s", mu_u.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
  return mu_tk[mu_u];
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
              if (mu_tk[mu_u]) {
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
    mu_u.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_10 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
mu_flop[mu_u] = mu_req[mu_u];
mu_tk[mu_u] = mu_false;
mu_ntk[mu_u] = mu_true;
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
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("end using, u:%s", mu_u.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
  return mu_use[mu_u];
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 16 )
      {
        if ( ( TRUE  ) ) {
              if (mu_use[mu_u]) {
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
    mu_u.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
mu_use[mu_u] = mu_false;
bool mu__quant5; 
mu__quant5 = FALSE;
{
for(int mu_v = 0; mu_v <= 3; mu_v++) {
if ( (mu_use[mu_v]) )
  { mu__quant5 = TRUE; break; }
};
};
mu_Use_b = mu__quant5;
if ( !(!(mu_Use_b)) ) Error.Error("Assertion failed: arbiter.m, line 78.");
bool mu__boolexpr6;
  if (!(!(mu_Req_b))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = (!(mu_Use_b)) ; 
}
if ( mu__boolexpr6 )
{
mu_tk[0] = mu_true;
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
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("start using, u:%s", mu_u.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
  return mu_grant[mu_u];
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20 )
      {
        if ( ( TRUE  ) ) {
              if (mu_grant[mu_u]) {
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
    mu_u.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
if ( !(!(mu_Use_b)) ) Error.Error("Assertion failed: arbiter.m, line 66.");
if ( !(mu_req[mu_u]) ) Error.Error("Assertion failed: arbiter.m, line 70.");
mu_use[mu_u] = mu_true;
mu_req[mu_u] = mu_false;
mu_Use_b = mu_true;
mu_grant[mu_u] = mu_false;
bool mu__quant7; 
mu__quant7 = FALSE;
{
for(int mu_v = 0; mu_v <= 3; mu_v++) {
if ( (mu_req[mu_v]) )
  { mu__quant7 = TRUE; break; }
};
};
mu_Req_b = mu__quant7;
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
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("start requesting, u:%s", mu_u.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr8;
  if (!(!(mu_req[mu_u]))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = (!(mu_use[mu_u])) ; 
}
  return mu__boolexpr8;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20;
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 24 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr9;
  if (!(!(mu_req[mu_u]))) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = (!(mu_use[mu_u])) ; 
}
              if (mu__boolexpr9) {
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
    mu_u.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_7 mu_u;
    mu_u.value((r % 4) + 0);
    r = r / 4;
mu_req[mu_u] = mu_true;
bool mu__boolexpr10;
  if (!(!(mu_Req_b))) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = (!(mu_Use_b)) ; 
}
if ( mu__boolexpr10 )
{
mu_NewToken (  );
}
mu_Req_b = mu_true;
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
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<4)
    { R0.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<8)
    { R1.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<12)
    { R2.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<16)
    { R3.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<20)
    { R4.NextRule(what_rule);
      if (what_rule<20) return; }
  if (what_rule>=20 && what_rule<24)
    { R5.NextRule(what_rule);
      if (what_rule<24) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=3) return R0.Condition(r-0);
  if (r>=4 && r<=7) return R1.Condition(r-4);
  if (r>=8 && r<=11) return R2.Condition(r-8);
  if (r>=12 && r<=15) return R3.Condition(r-12);
  if (r>=16 && r<=19) return R4.Condition(r-16);
  if (r>=20 && r<=23) return R5.Condition(r-20);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=3) { R0.Code(r-0); return; } 
  if (r>=4 && r<=7) { R1.Code(r-4); return; } 
  if (r>=8 && r<=11) { R2.Code(r-8); return; } 
  if (r>=12 && r<=15) { R3.Code(r-12); return; } 
  if (r>=16 && r<=19) { R4.Code(r-16); return; } 
  if (r>=20 && r<=23) { R5.Code(r-20); return; } 
}
int Priority(unsigned short r)
{
  if (r<=3) { return R0.Priority(); } 
  if (r>=4 && r<=7) { return R1.Priority(); } 
  if (r>=8 && r<=11) { return R2.Priority(); } 
  if (r>=12 && r<=15) { return R3.Priority(); } 
  if (r>=16 && r<=19) { return R4.Priority(); } 
  if (r>=20 && r<=23) { return R5.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=3) return R0.Name(r-0);
  if (r>=4 && r<=7) return R1.Name(r-4);
  if (r>=8 && r<=11) return R2.Name(r-8);
  if (r>=12 && r<=15) return R3.Name(r-12);
  if (r>=16 && r<=19) return R4.Name(r-16);
  if (r>=20 && r<=23) return R5.Name(r-20);
  return NULL;
}
};
const unsigned numrules = 24;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 24


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
for(int mu_u = 0; mu_u <= 3; mu_u++) {
mu_req[mu_u] = mu_false;
mu_use[mu_u] = mu_false;
mu_grant[mu_u] = mu_false;
mu_flop[mu_u] = mu_false;
mu_tk[mu_u] = mu_false;
mu_ntk[mu_u] = mu_false;
mu_p_req[mu_u] = mu_false;
};
};
mu_Req_b = mu_false;
mu_Use_b = mu_false;
mu_tk[mu_n] = mu_false;
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
int mu__invariant_11() // Invariant " no token lost "
{
return (mu_tk[mu_n]) == (mu_false);
};

bool mu__condition_12() // Condition for Rule " no token lost "
{
  return mu__invariant_11( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{" no token lost ", &mu__condition_12, NULL, FALSE},
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
Use_b:NoScalarset
ntk:NoScalarset
tk:NoScalarset
grant:NoScalarset
req:NoScalarset
use:NoScalarset
flop:NoScalarset
Req_b:NoScalarset
p_req:NoScalarset
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
        mu_Use_b.MultisetSort();
        mu_ntk.MultisetSort();
        mu_tk.MultisetSort();
        mu_grant.MultisetSort();
        mu_req.MultisetSort();
        mu_use.MultisetSort();
        mu_flop.MultisetSort();
        mu_Req_b.MultisetSort();
        mu_p_req.MultisetSort();
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
void mu__subrange_2::Permute(PermSet& Perm, int i) {};
void mu__subrange_2::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_2::Canonicalize(PermSet& Perm) {};
void mu__subrange_2::SimpleLimit(PermSet& Perm) {};
void mu__subrange_2::ArrayLimit(PermSet& Perm) {};
void mu__subrange_2::Limit(PermSet& Perm) {};
void mu__subrange_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_reg::Permute(PermSet& Perm, int i)
{
  static mu_1_reg temp("Permute_mu_1_reg",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1_reg::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_reg::Canonicalize(PermSet& Perm){};
void mu_1_reg::SimpleLimit(PermSet& Perm){}
void mu_1_reg::ArrayLimit(PermSet& Perm) {}
void mu_1_reg::Limit(PermSet& Perm){}
void mu_1_reg::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu__subrange_4::Permute(PermSet& Perm, int i) {};
void mu__subrange_4::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_4::Canonicalize(PermSet& Perm) {};
void mu__subrange_4::SimpleLimit(PermSet& Perm) {};
void mu__subrange_4::ArrayLimit(PermSet& Perm) {};
void mu__subrange_4::Limit(PermSet& Perm) {};
void mu__subrange_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<5; j++)
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
void mu__subrange_6::Permute(PermSet& Perm, int i) {};
void mu__subrange_6::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_6::Canonicalize(PermSet& Perm) {};
void mu__subrange_6::SimpleLimit(PermSet& Perm) {};
void mu__subrange_6::ArrayLimit(PermSet& Perm) {};
void mu__subrange_6::Limit(PermSet& Perm) {};
void mu__subrange_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_7::Permute(PermSet& Perm, int i) {};
void mu__subrange_7::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_7::Canonicalize(PermSet& Perm) {};
void mu__subrange_7::SimpleLimit(PermSet& Perm) {};
void mu__subrange_7::ArrayLimit(PermSet& Perm) {};
void mu__subrange_7::Limit(PermSet& Perm) {};
void mu__subrange_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_8::Permute(PermSet& Perm, int i) {};
void mu__subrange_8::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_8::Canonicalize(PermSet& Perm) {};
void mu__subrange_8::SimpleLimit(PermSet& Perm) {};
void mu__subrange_8::ArrayLimit(PermSet& Perm) {};
void mu__subrange_8::Limit(PermSet& Perm) {};
void mu__subrange_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_9::Permute(PermSet& Perm, int i) {};
void mu__subrange_9::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_9::Canonicalize(PermSet& Perm) {};
void mu__subrange_9::SimpleLimit(PermSet& Perm) {};
void mu__subrange_9::ArrayLimit(PermSet& Perm) {};
void mu__subrange_9::Limit(PermSet& Perm) {};
void mu__subrange_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_10::Permute(PermSet& Perm, int i) {};
void mu__subrange_10::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_10::Canonicalize(PermSet& Perm) {};
void mu__subrange_10::SimpleLimit(PermSet& Perm) {};
void mu__subrange_10::ArrayLimit(PermSet& Perm) {};
void mu__subrange_10::Limit(PermSet& Perm) {};
void mu__subrange_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_11::Permute(PermSet& Perm, int i) {};
void mu__subrange_11::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_11::Canonicalize(PermSet& Perm) {};
void mu__subrange_11::SimpleLimit(PermSet& Perm) {};
void mu__subrange_11::ArrayLimit(PermSet& Perm) {};
void mu__subrange_11::Limit(PermSet& Perm) {};
void mu__subrange_11::MultisetLimit(PermSet& Perm)
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
              
              mu_Use_b.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Use_b.MultisetSort();
              mu_ntk.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ntk.MultisetSort();
              mu_tk.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_tk.MultisetSort();
              mu_grant.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_grant.MultisetSort();
              mu_req.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_req.MultisetSort();
              mu_use.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_use.MultisetSort();
              mu_flop.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_flop.MultisetSort();
              mu_Req_b.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Req_b.MultisetSort();
              mu_p_req.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_p_req.MultisetSort();
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

          mu_Use_b.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Use_b.MultisetSort();
          mu_ntk.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ntk.MultisetSort();
          mu_tk.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_tk.MultisetSort();
          mu_grant.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_grant.MultisetSort();
          mu_req.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_req.MultisetSort();
          mu_use.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_use.MultisetSort();
          mu_flop.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_flop.MultisetSort();
          mu_Req_b.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Req_b.MultisetSort();
          mu_p_req.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_p_req.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Use_b.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Use_b.MultisetSort();
              mu_ntk.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ntk.MultisetSort();
              mu_tk.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_tk.MultisetSort();
              mu_grant.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_grant.MultisetSort();
              mu_req.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_req.MultisetSort();
              mu_use.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_use.MultisetSort();
              mu_flop.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_flop.MultisetSort();
              mu_Req_b.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Req_b.MultisetSort();
              mu_p_req.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_p_req.MultisetSort();
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
      mu_Use_b.MultisetSort();
      mu_ntk.MultisetSort();
      mu_tk.MultisetSort();
      mu_grant.MultisetSort();
      mu_req.MultisetSort();
      mu_use.MultisetSort();
      mu_flop.MultisetSort();
      mu_Req_b.MultisetSort();
      mu_p_req.MultisetSort();
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
        mu_Use_b.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Use_b.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ntk.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ntk.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_tk.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_tk.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_grant.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_grant.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_req.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_use.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_use.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_flop.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_flop.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Req_b.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Req_b.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_p_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_p_req.MultisetSort();
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
