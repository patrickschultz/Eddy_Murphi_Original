/******************************
  Program "dp4.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "dp4"
#define BITS_IN_WORLD 20
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_ind_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ind_t& val) { return mu__byte::operator=((int) val); };
  mu_1_ind_t (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_ind_t (void): mu__byte(0, 3, 3) {};
  mu_1_ind_t (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu_1_ind_t mu_1_ind_t_undefined_var;

class mu_1_label_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_label_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_label_t& val)
  {
    if (val.defined())
      return ( s << mu_1_label_t::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_label_t (char *name, int os): mu__byte(1, 4, 3, name, os) {};
  mu_1_label_t (void): mu__byte(1, 4, 3) {};
  mu_1_label_t (int val): mu__byte(1, 4, 3, "Parameter or function result.", 0)
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

char *mu_1_label_t::values[] = {"think","take","eat","release",NULL };

/*** end of enum declaration ***/
mu_1_label_t mu_1_label_t_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_label_t array[ 4 ];
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
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
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
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
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
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__byte::operator=((int) val); };
  mu_1__type_1 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 2, 2) {};
  mu_1__type_1 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2
{
 public:
  mu_1__type_1 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_2 (char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
  mu_1__type_1& operator[] (int index) /* const */
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
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
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
  char* s;
  name = n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

const int mu_N = 4;
const int mu_think = 1;
const int mu_take = 2;
const int mu_eat = 3;
const int mu_release = 4;
/*** Variable declaration ***/
mu_1__type_0 mu_label("label",0);

/*** Variable declaration ***/
mu_1__type_2 mu_forksAvail("forksAvail",12);

mu_1_ind_t mu_Left(const mu_1_ind_t& mu_i)
{
if ( (mu_i) == (0) )
{
return 3;
}
else
{
return (mu_i) - (1);
}
  Error.Error("The end of function Left reached without returning values.");
};
/*** end function declaration ***/

mu_1_ind_t mu_Right(const mu_1_ind_t& mu_i)
{
if ( (mu_i) == (3) )
{
return 0;
}
else
{
return (mu_i) + (1);
}
  Error.Error("The end of function Right reached without returning values.");
};
/*** end function declaration ***/

void mu_Goto(const mu_1_ind_t& mu_p, const mu_1_label_t& mu_lab)
{
if (mu_lab.isundefined())
  mu_label[mu_p].undefine();
else
  mu_label[mu_p] = mu_lab;
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_label.clear();
  mu_forksAvail.clear();
}
void world_class::undefine()
{
  mu_label.undefine();
  mu_forksAvail.undefine();
}
void world_class::reset()
{
  mu_label.reset();
  mu_forksAvail.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_label.print();
  mu_forksAvail.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_label.print_statistic();
  mu_forksAvail.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_label.print_diff(prevstate);
    mu_forksAvail.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_label.to_state( newstate );
  mu_forksAvail.to_state( newstate );
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
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Release, p:%s", mu_p.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  return (mu_lp) == (mu_release);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 4 )
      {
        if ( ( TRUE  ) ) {
  mu_1_label_t& mu_lp = mu_label[mu_p];
              if ((mu_lp) == (mu_release)) {
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
    mu_p.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
mu_forksAvail[mu_Left( mu_p )] = (mu_forksAvail[mu_Left( mu_p )]) + (1);
mu_forksAvail[mu_Right( mu_p )] = (mu_forksAvail[mu_Right( mu_p )]) + (1);
mu_Goto ( mu_p, mu_think );
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
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Finish eating, p:%s", mu_p.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  return (mu_lp) == (mu_eat);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 8 )
      {
        if ( ( TRUE  ) ) {
  mu_1_label_t& mu_lp = mu_label[mu_p];
              if ((mu_lp) == (mu_eat)) {
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
    mu_p.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
mu_Goto ( mu_p, mu_release );
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
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Continue eating, p:%s", mu_p.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  return (mu_lp) == (mu_eat);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
  mu_1_label_t& mu_lp = mu_label[mu_p];
              if ((mu_lp) == (mu_eat)) {
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
    mu_p.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
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
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Try to take forks, p:%s", mu_p.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  mu_1__type_1& mu_fap = mu_forksAvail[mu_p];
  return (mu_lp) == (mu_take);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 16 )
      {
        if ( ( TRUE  ) ) {
  mu_1_label_t& mu_lp = mu_label[mu_p];
  mu_1__type_1& mu_fap = mu_forksAvail[mu_p];
              if ((mu_lp) == (mu_take)) {
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
    mu_p.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  mu_1__type_1& mu_fap = mu_forksAvail[mu_p];
if ( (mu_fap) == (2) )
{
mu_forksAvail[mu_Left( mu_p )] = (mu_forksAvail[mu_Left( mu_p )]) - (1);
mu_forksAvail[mu_Right( mu_p )] = (mu_forksAvail[mu_Right( mu_p )]) - (1);
mu_Goto ( mu_p, mu_eat );
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
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Done thinking, p:%s", mu_p.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  return (mu_lp) == (mu_think);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20 )
      {
        if ( ( TRUE  ) ) {
  mu_1_label_t& mu_lp = mu_label[mu_p];
              if ((mu_lp) == (mu_think)) {
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
    mu_p.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
mu_Goto ( mu_p, mu_take );
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
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Continue thinking, p:%s", mu_p.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
  return (mu_lp) == (mu_think);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20;
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 24 )
      {
        if ( ( TRUE  ) ) {
  mu_1_label_t& mu_lp = mu_label[mu_p];
              if ((mu_lp) == (mu_think)) {
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
    mu_p.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_ind_t mu_p;
    mu_p.value((r % 4) + 0);
    r = r / 4;
  mu_1_label_t& mu_lp = mu_label[mu_p];
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
for(int mu_p = 0; mu_p <= 3; mu_p++) {
mu_forksAvail[mu_p] = 2;
mu_Goto ( mu_p, mu_think );
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
int mu__invariant_3() // Invariant "Invariant 0"
{
bool mu__quant4; 
mu__quant4 = TRUE;
{
for(int mu_p = 0; mu_p <= 3; mu_p++) {
bool mu__boolexpr5;
  if (!((mu_label[mu_p]) == (mu_eat))) mu__boolexpr5 = TRUE ;
  else {
  mu__boolexpr5 = ((mu_forksAvail[mu_p]) == (2)) ; 
}
if ( !(mu__boolexpr5) )
  { mu__quant4 = FALSE; break; }
};
};
return mu__quant4;
};

bool mu__condition_6() // Condition for Rule "Invariant 0"
{
  return mu__invariant_3( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invariant 0", &mu__condition_6, NULL, FALSE},
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
label:NoScalarset
forksAvail:NoScalarset
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
        mu_label.MultisetSort();
        mu_forksAvail.MultisetSort();
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
void mu_1_ind_t::Permute(PermSet& Perm, int i) {};
void mu_1_ind_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ind_t::Canonicalize(PermSet& Perm) {};
void mu_1_ind_t::SimpleLimit(PermSet& Perm) {};
void mu_1_ind_t::ArrayLimit(PermSet& Perm) {};
void mu_1_ind_t::Limit(PermSet& Perm) {};
void mu_1_ind_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
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
  for (j=0; j<4; j++)
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
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm){};
void mu_1__type_2::SimpleLimit(PermSet& Perm){}
void mu_1__type_2::ArrayLimit(PermSet& Perm) {}
void mu_1__type_2::Limit(PermSet& Perm){}
void mu_1__type_2::MultisetLimit(PermSet& Perm)
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
              
              mu_label.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_label.MultisetSort();
              mu_forksAvail.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_forksAvail.MultisetSort();
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

          mu_label.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_label.MultisetSort();
          mu_forksAvail.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_forksAvail.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_label.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_label.MultisetSort();
              mu_forksAvail.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_forksAvail.MultisetSort();
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
      mu_label.MultisetSort();
      mu_forksAvail.MultisetSort();
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
        mu_label.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_label.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_forksAvail.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_forksAvail.MultisetSort();
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
