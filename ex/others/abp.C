/******************************
  Program "abp.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Aug  1 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "abp"
#define BITS_IN_WORLD 26
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_PacketType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_PacketType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_PacketType& val)
  {
    if (val.defined())
      return ( s << mu_1_PacketType::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_PacketType (char *name, int os): mu__byte(1, 4, 3, name, os) {};
  mu_1_PacketType (void): mu__byte(1, 4, 3) {};
  mu_1_PacketType (int val): mu__byte(1, 4, 3, "Parameter or function result.", 0)
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

char *mu_1_PacketType::values[] = {"EMPTY","PACKET","ACK","CORRUPT",NULL };

/*** end of enum declaration ***/
mu_1_PacketType mu_1_PacketType_undefined_var;

class mu_1_ValueType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ValueType& val) { return mu__byte::operator=((int) val); };
  mu_1_ValueType (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1_ValueType (void): mu__byte(0, 1, 2) {};
  mu_1_ValueType (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu_1_ValueType mu_1_ValueType_undefined_var;

class mu_1_PacketRecord
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_PacketType mu_Status;
  mu_1_ValueType mu_Value;
  mu_1_ValueType mu_SeqNo;
  mu_1_PacketRecord ( char *n, int os ) { set_self(n,os); };
  mu_1_PacketRecord ( void ) {};

  virtual ~mu_1_PacketRecord(); 
friend int CompareWeight(mu_1_PacketRecord& a, mu_1_PacketRecord& b)
  {
    int w;
    w = CompareWeight(a.mu_Status, b.mu_Status);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Value, b.mu_Value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_SeqNo, b.mu_SeqNo);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_PacketRecord& a, mu_1_PacketRecord& b)
  {
    int w;
    w = Compare(a.mu_Status, b.mu_Status);
    if (w!=0) return w;
    w = Compare(a.mu_Value, b.mu_Value);
    if (w!=0) return w;
    w = Compare(a.mu_SeqNo, b.mu_SeqNo);
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
    mu_Value.MultisetSort();
    mu_SeqNo.MultisetSort();
  }
  void print_statistic()
  {
    mu_Status.print_statistic();
    mu_Value.print_statistic();
    mu_SeqNo.print_statistic();
  }
  void clear() {
    mu_Status.clear();
    mu_Value.clear();
    mu_SeqNo.clear();
 };
  void undefine() {
    mu_Status.undefine();
    mu_Value.undefine();
    mu_SeqNo.undefine();
 };
  void reset() {
    mu_Status.reset();
    mu_Value.reset();
    mu_SeqNo.reset();
 };
  void print() {
    mu_Status.print();
    mu_Value.print();
    mu_SeqNo.print();
  };
  void print_diff(state *prevstate) {
    mu_Status.print_diff(prevstate);
    mu_Value.print_diff(prevstate);
    mu_SeqNo.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Status.to_state(thestate);
    mu_Value.to_state(thestate);
    mu_SeqNo.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_PacketRecord& operator= (const mu_1_PacketRecord& from) {
    mu_Status.value(from.mu_Status.value());
    mu_Value.value(from.mu_Value.value());
    mu_SeqNo.value(from.mu_SeqNo.value());
    return *this;
  };
};

  void mu_1_PacketRecord::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_PacketRecord::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_PacketRecord::set_self(char *n, int os)
{
  name = n;
  mu_Status.set_self_2(name, ".Status", os + 0 );
  mu_Value.set_self_2(name, ".Value", os + 3 );
  mu_SeqNo.set_self_2(name, ".SeqNo", os + 5 );
}

mu_1_PacketRecord::~mu_1_PacketRecord()
{
}

/*** end record declaration ***/
mu_1_PacketRecord mu_1_PacketRecord_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 1, 2) {};
  mu_1__type_0 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu_1__type_0 mu_1__type_0_undefined_var;

const int mu_EMPTY = 1;
const int mu_PACKET = 2;
const int mu_ACK = 3;
const int mu_CORRUPT = 4;
/*** Variable declaration ***/
mu_1_PacketRecord mu_X2RChannel("X2RChannel",0);

/*** Variable declaration ***/
mu_1_PacketRecord mu_R2XChannel("R2XChannel",7);

/*** Variable declaration ***/
mu_1_ValueType mu_Value("Value",14);

/*** Variable declaration ***/
mu_1_ValueType mu_OldValue("OldValue",16);

/*** Variable declaration ***/
mu_1__type_0 mu_SentOne("SentOne",18);

/*** Variable declaration ***/
mu_1_ValueType mu_ReceivedValue("ReceivedValue",20);

/*** Variable declaration ***/
mu_1_ValueType mu_XSeqNo("XSeqNo",22);

/*** Variable declaration ***/
mu_1_ValueType mu_RSeqNo("RSeqNo",24);

void mu_SendPacket(mu_1_PacketRecord& mu_Channel, const mu_1_PacketType& mu_Status, const mu_1_ValueType& mu_Value, const mu_1_ValueType& mu_SeqNo)
{
if (mu_Status.isundefined())
  mu_Channel.mu_Status.undefine();
else
  mu_Channel.mu_Status = mu_Status;
if (mu_Value.isundefined())
  mu_Channel.mu_Value.undefine();
else
  mu_Channel.mu_Value = mu_Value;
if (mu_SeqNo.isundefined())
  mu_Channel.mu_SeqNo.undefine();
else
  mu_Channel.mu_SeqNo = mu_SeqNo;
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_X2RChannel.clear();
  mu_R2XChannel.clear();
  mu_Value.clear();
  mu_OldValue.clear();
  mu_SentOne.clear();
  mu_ReceivedValue.clear();
  mu_XSeqNo.clear();
  mu_RSeqNo.clear();
}
void world_class::undefine()
{
  mu_X2RChannel.undefine();
  mu_R2XChannel.undefine();
  mu_Value.undefine();
  mu_OldValue.undefine();
  mu_SentOne.undefine();
  mu_ReceivedValue.undefine();
  mu_XSeqNo.undefine();
  mu_RSeqNo.undefine();
}
void world_class::reset()
{
  mu_X2RChannel.reset();
  mu_R2XChannel.reset();
  mu_Value.reset();
  mu_OldValue.reset();
  mu_SentOne.reset();
  mu_ReceivedValue.reset();
  mu_XSeqNo.reset();
  mu_RSeqNo.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_X2RChannel.print();
  mu_R2XChannel.print();
  mu_Value.print();
  mu_OldValue.print();
  mu_SentOne.print();
  mu_ReceivedValue.print();
  mu_XSeqNo.print();
  mu_RSeqNo.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_X2RChannel.print_statistic();
  mu_R2XChannel.print_statistic();
  mu_Value.print_statistic();
  mu_OldValue.print_statistic();
  mu_SentOne.print_statistic();
  mu_ReceivedValue.print_statistic();
  mu_XSeqNo.print_statistic();
  mu_RSeqNo.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_X2RChannel.print_diff(prevstate);
    mu_R2XChannel.print_diff(prevstate);
    mu_Value.print_diff(prevstate);
    mu_OldValue.print_diff(prevstate);
    mu_SentOne.print_diff(prevstate);
    mu_ReceivedValue.print_diff(prevstate);
    mu_XSeqNo.print_diff(prevstate);
    mu_RSeqNo.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_X2RChannel.to_state( newstate );
  mu_R2XChannel.to_state( newstate );
  mu_Value.to_state( newstate );
  mu_OldValue.to_state( newstate );
  mu_SentOne.to_state( newstate );
  mu_ReceivedValue.to_state( newstate );
  mu_XSeqNo.to_state( newstate );
  mu_RSeqNo.to_state( newstate );
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
    return tsprintf("Corrupt R2XChannel");
  }
  bool Condition(unsigned r)
  {
bool mu__boolexpr1;
  if (!((mu_R2XChannel.mu_Status) != (mu_EMPTY))) mu__boolexpr1 = FALSE ;
  else {
  mu__boolexpr1 = ((mu_R2XChannel.mu_Status) != (mu_CORRUPT)) ; 
}
  return mu__boolexpr1;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    while (what_rule < 1 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr2;
  if (!((mu_R2XChannel.mu_Status) != (mu_EMPTY))) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = ((mu_R2XChannel.mu_Status) != (mu_CORRUPT)) ; 
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
    }
  }

  void Code(unsigned r)
  {
mu_R2XChannel.clear();
mu_R2XChannel.mu_Status = mu_CORRUPT;
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
    return tsprintf("Corrupt X2RChannel");
  }
  bool Condition(unsigned r)
  {
bool mu__boolexpr3;
  if (!((mu_X2RChannel.mu_Status) != (mu_EMPTY))) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_X2RChannel.mu_Status) != (mu_CORRUPT)) ; 
}
  return mu__boolexpr3;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1;
    while (what_rule < 2 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr4;
  if (!((mu_X2RChannel.mu_Status) != (mu_EMPTY))) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = ((mu_X2RChannel.mu_Status) != (mu_CORRUPT)) ; 
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
    r = what_rule - 1;
    }
  }

  void Code(unsigned r)
  {
mu_X2RChannel.clear();
mu_X2RChannel.mu_Status = mu_CORRUPT;
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
    return tsprintf("Receiver");
  }
  bool Condition(unsigned r)
  {
  return (mu_X2RChannel.mu_Status) != (mu_EMPTY);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2;
    while (what_rule < 3 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_X2RChannel.mu_Status) != (mu_EMPTY)) {
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
    }
  }

  void Code(unsigned r)
  {
switch ((int) mu_X2RChannel.mu_Status) {
case mu_CORRUPT:
mu_SendPacket ( mu_R2XChannel, mu_ACK, 0, mu_RSeqNo );
break;
case mu_PACKET:
if ( (mu_X2RChannel.mu_SeqNo) == (mu_RSeqNo) )
{
mu_RSeqNo = ((mu_RSeqNo) == (1)) ? (0) : (1);
mu_SendPacket ( mu_R2XChannel, mu_ACK, 0, mu_RSeqNo );
bool mu__boolexpr5;
  if (!((mu_X2RChannel.mu_Value) == (1))) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_ReceivedValue) == (1)) ; 
}
if ( mu__boolexpr5 )
{
Error.Error("Error: Receiver has received 2 packets with value 1\n");
}
if ( (mu_X2RChannel.mu_Value) == (1) )
{
mu_ReceivedValue = 1;
}
}
else
{
mu_SendPacket ( mu_R2XChannel, mu_ACK, 0, mu_RSeqNo );
}
break;
default:
Error.Error("Error: Invalid Packet Type received at the Receiver\n");
break;
}
mu_X2RChannel.clear();
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
    return tsprintf("Transmitter");
  }
  bool Condition(unsigned r)
  {
  return (mu_R2XChannel.mu_Status) != (mu_EMPTY);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3;
    while (what_rule < 4 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_R2XChannel.mu_Status) != (mu_EMPTY)) {
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
    }
  }

  void Code(unsigned r)
  {
switch ((int) mu_R2XChannel.mu_Status) {
case mu_CORRUPT:
mu_SendPacket ( mu_X2RChannel, mu_PACKET, mu_OldValue, mu_XSeqNo );
break;
case mu_ACK:
if ( (mu_R2XChannel.mu_SeqNo) != (mu_XSeqNo) )
{
mu_XSeqNo = ((mu_XSeqNo) == (1)) ? (0) : (1);
if ( (mu_SentOne) == (1) )
{
mu_Value = 0;
}
if (mu_Value.isundefined())
  mu_OldValue.undefine();
else
  mu_OldValue = mu_Value;
mu_SendPacket ( mu_X2RChannel, mu_PACKET, mu_Value, mu_XSeqNo );
if ( (mu_Value) == (1) )
{
mu_SentOne = 1;
}
}
else
{
mu_SendPacket ( mu_X2RChannel, mu_PACKET, mu_OldValue, mu_XSeqNo );
}
break;
default:
Error.Error("Error: Invalid Packet Type received at the Transmitter\n");
break;
}
mu_R2XChannel.clear();
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
    return tsprintf("Generate Value 1 to send");
  }
  bool Condition(unsigned r)
  {
bool mu__boolexpr6;
  if (!((mu_R2XChannel.mu_Status) != (mu_EMPTY))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_SentOne) == (0)) ; 
}
  return mu__boolexpr6;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    while (what_rule < 5 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr7;
  if (!((mu_R2XChannel.mu_Status) != (mu_EMPTY))) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_SentOne) == (0)) ; 
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
    r = what_rule - 4;
    }
  }

  void Code(unsigned r)
  {
mu_Value = 1;
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
    return tsprintf("Generate Value 0 to send");
  }
  bool Condition(unsigned r)
  {
  return (mu_R2XChannel.mu_Status) != (mu_EMPTY);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5;
    while (what_rule < 6 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_R2XChannel.mu_Status) != (mu_EMPTY)) {
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
    }
  }

  void Code(unsigned r)
  {
mu_Value = 0;
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
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<2)
    { R1.NextRule(what_rule);
      if (what_rule<2) return; }
  if (what_rule>=2 && what_rule<3)
    { R2.NextRule(what_rule);
      if (what_rule<3) return; }
  if (what_rule>=3 && what_rule<4)
    { R3.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<5)
    { R4.NextRule(what_rule);
      if (what_rule<5) return; }
  if (what_rule>=5 && what_rule<6)
    { R5.NextRule(what_rule);
      if (what_rule<6) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
  if (r>=3 && r<=3) return R3.Condition(r-3);
  if (r>=4 && r<=4) return R4.Condition(r-4);
  if (r>=5 && r<=5) return R5.Condition(r-5);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code(r-3); return; } 
  if (r>=4 && r<=4) { R4.Code(r-4); return; } 
  if (r>=5 && r<=5) { R5.Code(r-5); return; } 
}
int Priority(unsigned short r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
  if (r>=3 && r<=3) { return R3.Priority(); } 
  if (r>=4 && r<=4) { return R4.Priority(); } 
  if (r>=5 && r<=5) { return R5.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  if (r>=3 && r<=3) return R3.Name(r-3);
  if (r>=4 && r<=4) return R4.Name(r-4);
  if (r>=5 && r<=5) return R5.Name(r-5);
  return NULL;
}
};
const unsigned numrules = 6;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 6


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
mu_Value = 0;
mu_OldValue = 0;
mu_SentOne = 0;
mu_XSeqNo = 1;
mu_RSeqNo = 0;
mu_X2RChannel.clear();
mu_R2XChannel.clear();
mu_R2XChannel.mu_Status = mu_ACK;
mu_R2XChannel.mu_Value = 0;
mu_R2XChannel.mu_SeqNo = 0;
mu_ReceivedValue = 0;
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
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

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
XSeqNo:NoScalarset
SentOne:NoScalarset
OldValue:NoScalarset
R2XChannel:NoScalarset
X2RChannel:NoScalarset
Value:NoScalarset
ReceivedValue:NoScalarset
RSeqNo:NoScalarset
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
        mu_XSeqNo.MultisetSort();
        mu_SentOne.MultisetSort();
        mu_OldValue.MultisetSort();
        mu_R2XChannel.MultisetSort();
        mu_X2RChannel.MultisetSort();
        mu_Value.MultisetSort();
        mu_ReceivedValue.MultisetSort();
        mu_RSeqNo.MultisetSort();
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
void mu_1_PacketType::Permute(PermSet& Perm, int i) {};
void mu_1_PacketType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_PacketType::Canonicalize(PermSet& Perm) {};
void mu_1_PacketType::SimpleLimit(PermSet& Perm) {};
void mu_1_PacketType::ArrayLimit(PermSet& Perm) {};
void mu_1_PacketType::Limit(PermSet& Perm) {};
void mu_1_PacketType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_ValueType::Permute(PermSet& Perm, int i) {};
void mu_1_ValueType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ValueType::Canonicalize(PermSet& Perm) {};
void mu_1_ValueType::SimpleLimit(PermSet& Perm) {};
void mu_1_ValueType::ArrayLimit(PermSet& Perm) {};
void mu_1_ValueType::Limit(PermSet& Perm) {};
void mu_1_ValueType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_PacketRecord::Permute(PermSet& Perm, int i)
{
};
void mu_1_PacketRecord::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_PacketRecord::Canonicalize(PermSet& Perm)
{
};
void mu_1_PacketRecord::SimpleLimit(PermSet& Perm){}
void mu_1_PacketRecord::ArrayLimit(PermSet& Perm){}
void mu_1_PacketRecord::Limit(PermSet& Perm)
{
};
void mu_1_PacketRecord::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
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
              
              mu_XSeqNo.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_XSeqNo.MultisetSort();
              mu_SentOne.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_SentOne.MultisetSort();
              mu_OldValue.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_OldValue.MultisetSort();
              mu_R2XChannel.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_R2XChannel.MultisetSort();
              mu_X2RChannel.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_X2RChannel.MultisetSort();
              mu_Value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Value.MultisetSort();
              mu_ReceivedValue.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ReceivedValue.MultisetSort();
              mu_RSeqNo.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_RSeqNo.MultisetSort();
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

          mu_XSeqNo.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_XSeqNo.MultisetSort();
          mu_SentOne.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_SentOne.MultisetSort();
          mu_OldValue.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_OldValue.MultisetSort();
          mu_R2XChannel.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_R2XChannel.MultisetSort();
          mu_X2RChannel.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_X2RChannel.MultisetSort();
          mu_Value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Value.MultisetSort();
          mu_ReceivedValue.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ReceivedValue.MultisetSort();
          mu_RSeqNo.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_RSeqNo.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_XSeqNo.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_XSeqNo.MultisetSort();
              mu_SentOne.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_SentOne.MultisetSort();
              mu_OldValue.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_OldValue.MultisetSort();
              mu_R2XChannel.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_R2XChannel.MultisetSort();
              mu_X2RChannel.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_X2RChannel.MultisetSort();
              mu_Value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Value.MultisetSort();
              mu_ReceivedValue.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ReceivedValue.MultisetSort();
              mu_RSeqNo.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_RSeqNo.MultisetSort();
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
      mu_XSeqNo.MultisetSort();
      mu_SentOne.MultisetSort();
      mu_OldValue.MultisetSort();
      mu_R2XChannel.MultisetSort();
      mu_X2RChannel.MultisetSort();
      mu_Value.MultisetSort();
      mu_ReceivedValue.MultisetSort();
      mu_RSeqNo.MultisetSort();
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
        mu_XSeqNo.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_XSeqNo.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_SentOne.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_SentOne.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_OldValue.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_OldValue.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_R2XChannel.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_R2XChannel.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_X2RChannel.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_X2RChannel.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ReceivedValue.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ReceivedValue.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_RSeqNo.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_RSeqNo.MultisetSort();
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
