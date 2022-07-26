

typedef struct lua_State lua_State;
typedef double lua_Number;

typedef LUA_INTEGER lua_Integer;

typedef unsigned LUA_INTEGER lua_Unsigned;

typedef ptrdiff_t lua_KContext;

typedef int (*lua_CFunction)(lua_State *L);

typedef int (*lua_KFunction)(lua_State *L, int status, lua_KContext ctx);

typedef const char *(*lua_Reader)(lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer)(lua_State *L, const void *p, size_t sz, void *ud);

typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);

typedef void (*lua_WarnFunction)(void *ud, const char *msg, int tocont);
extern const char lua_ident[];

extern lua_State *(lua_newstate) (lua_Alloc f, void *ud);
extern void(lua_close)(lua_State *L);
extern lua_State *(lua_newthread) (lua_State *L);
extern int(lua_resetthread)(lua_State *L);

extern lua_CFunction(lua_atpanic)(lua_State *L, lua_CFunction panicf);

extern lua_Number(lua_version)(lua_State *L);

extern int(lua_absindex)(lua_State *L, int idx);
extern int(lua_gettop)(lua_State *L);
extern void(lua_settop)(lua_State *L, int idx);
extern void(lua_pushvalue)(lua_State *L, int idx);
extern void(lua_rotate)(lua_State *L, int idx, int n);
extern void(lua_copy)(lua_State *L, int fromidx, int toidx);
extern int(lua_checkstack)(lua_State *L, int n);

extern void(lua_xmove)(lua_State *from, lua_State *to, int n);

extern int(lua_isnumber)(lua_State *L, int idx);
extern int(lua_isstring)(lua_State *L, int idx);
extern int(lua_iscfunction)(lua_State *L, int idx);
extern int(lua_isinteger)(lua_State *L, int idx);
extern int(lua_isuserdata)(lua_State *L, int idx);
extern int(lua_type)(lua_State *L, int idx);
extern const char *(lua_typename) (lua_State *L, int tp);

extern lua_Number(lua_tonumberx)(lua_State *L, int idx, int *isnum);
extern lua_Integer(lua_tointegerx)(lua_State *L, int idx, int *isnum);
extern int(lua_toboolean)(lua_State *L, int idx);
extern const char *(lua_tolstring) (lua_State *L, int idx, size_t *len);
extern lua_Unsigned(lua_rawlen)(lua_State *L, int idx);
extern lua_CFunction(lua_tocfunction)(lua_State *L, int idx);
extern void *(lua_touserdata) (lua_State *L, int idx);
extern lua_State *(lua_tothread) (lua_State *L, int idx);
extern const void *(lua_topointer) (lua_State *L, int idx);
extern void(lua_arith)(lua_State *L, int op);

extern int(lua_rawequal)(lua_State *L, int idx1, int idx2);
extern int(lua_compare)(lua_State *L, int idx1, int idx2, int op);

extern void(lua_pushnil)(lua_State *L);
extern void(lua_pushnumber)(lua_State *L, lua_Number n);
extern void(lua_pushinteger)(lua_State *L, lua_Integer n);
extern const char *(lua_pushlstring) (lua_State *L, const char *s, size_t len);
extern const char *(lua_pushstring) (lua_State *L, const char *s);
extern const char *(lua_pushvfstring) (lua_State *L, const char *fmt, va_list argp);
extern const char *(lua_pushfstring) (lua_State *L, const char *fmt, ...);
extern void(lua_pushcclosure)(lua_State *L, lua_CFunction fn, int n);
extern void(lua_pushboolean)(lua_State *L, int b);
extern void(lua_pushlightuserdata)(lua_State *L, void *p);
extern int(lua_pushthread)(lua_State *L);

extern int(lua_getglobal)(lua_State *L, const char *name);
extern int(lua_gettable)(lua_State *L, int idx);
extern int(lua_getfield)(lua_State *L, int idx, const char *k);
extern int(lua_geti)(lua_State *L, int idx, lua_Integer n);
extern int(lua_rawget)(lua_State *L, int idx);
extern int(lua_rawgeti)(lua_State *L, int idx, lua_Integer n);
extern int(lua_rawgetp)(lua_State *L, int idx, const void *p);

extern void(lua_createtable)(lua_State *L, int narr, int nrec);
extern void *(lua_newuserdatauv) (lua_State *L, size_t sz, int nuvalue);
extern int(lua_getmetatable)(lua_State *L, int objindex);
extern int(lua_getiuservalue)(lua_State *L, int idx, int n);

extern void(lua_setglobal)(lua_State *L, const char *name);
extern void(lua_settable)(lua_State *L, int idx);
extern void(lua_setfield)(lua_State *L, int idx, const char *k);
extern void(lua_seti)(lua_State *L, int idx, lua_Integer n);
extern void(lua_rawset)(lua_State *L, int idx);
extern void(lua_rawseti)(lua_State *L, int idx, lua_Integer n);
extern void(lua_rawsetp)(lua_State *L, int idx, const void *p);
extern int(lua_setmetatable)(lua_State *L, int objindex);
extern int(lua_setiuservalue)(lua_State *L, int idx, int n);

extern void(lua_callk)(lua_State *L, int nargs, int nresults, lua_KContext ctx, lua_KFunction k);

extern int(lua_pcallk)(lua_State *L, int nargs, int nresults, int errfunc, lua_KContext ctx,
					   lua_KFunction k);

extern int(lua_load)(lua_State *L, lua_Reader reader, void *dt, const char *chunkname,
					 const char *mode);

extern int(lua_dump)(lua_State *L, lua_Writer writer, void *data, int strip);

extern int(lua_yieldk)(lua_State *L, int nresults, lua_KContext ctx, lua_KFunction k);
extern int(lua_resume)(lua_State *L, lua_State *from, int narg, int *nres);
extern int(lua_status)(lua_State *L);
extern int(lua_isyieldable)(lua_State *L);

extern void(lua_setwarnf)(lua_State *L, lua_WarnFunction f, void *ud);
extern void(lua_warning)(lua_State *L, const char *msg, int tocont);
extern int(lua_gc)(lua_State *L, int what, ...);

extern int(lua_error)(lua_State *L);

extern int(lua_next)(lua_State *L, int idx);

extern void(lua_concat)(lua_State *L, int n);
extern void(lua_len)(lua_State *L, int idx);

extern size_t(lua_stringtonumber)(lua_State *L, const char *s);

extern lua_Alloc(lua_getallocf)(lua_State *L, void **ud);
extern void(lua_setallocf)(lua_State *L, lua_Alloc f, void *ud);

extern void(lua_toclose)(lua_State *L, int idx);
typedef struct lua_Debug lua_Debug;

typedef void (*lua_Hook)(lua_State *L, lua_Debug *ar);

extern int(lua_getstack)(lua_State *L, int level, lua_Debug *ar);
extern int(lua_getinfo)(lua_State *L, const char *what, lua_Debug *ar);
extern const char *(lua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_getupvalue) (lua_State *L, int funcindex, int n);
extern const char *(lua_setupvalue) (lua_State *L, int funcindex, int n);

extern void *(lua_upvalueid) (lua_State *L, int fidx, int n);
extern void(lua_upvaluejoin)(lua_State *L, int fidx1, int n1, int fidx2, int n2);

extern void(lua_sethook)(lua_State *L, lua_Hook func, int mask, int count);
extern lua_Hook(lua_gethook)(lua_State *L);
extern int(lua_gethookmask)(lua_State *L);
extern int(lua_gethookcount)(lua_State *L);

extern int(lua_setcstacklimit)(lua_State *L, unsigned int limit);

struct lua_Debug
{
	int event;
	const char *name;
	const char *namewhat;
	const char *what;
	const char *source;
	size_t srclen;
	int currentline;
	int linedefined;
	int lastlinedefined;
	unsigned char nups;
	unsigned char nparams;
	char isvararg;
	char istailcall;
	unsigned short ftransfer;
	unsigned short ntransfer;
	char short_src[60];

	struct CallInfo *i_ci;
};

typedef unsigned long lu_mem;
typedef long l_mem;

typedef unsigned char lu_byte;
typedef signed char ls_byte;
typedef double l_uacNumber;
typedef LUA_INTEGER l_uacInt;
typedef unsigned long l_uint32;

typedef l_uint32 Instruction;
typedef union Value
{
	struct GCObject *gc;
	void *p;
	lua_CFunction f;
	lua_Integer i;
	lua_Number n;
} Value;
typedef struct TValue
{
	Value value_;
	lu_byte tt_;
} TValue;
typedef union StackValue
{
	TValue val;
} StackValue;

typedef StackValue *StkId;
typedef struct GCObject
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
} GCObject;
typedef struct TString
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte extra;
	lu_byte shrlen;
	unsigned int hash;
	union
	{
		size_t lnglen;
		struct TString *hnext;
	} u;
	char contents[1];
} TString;
typedef union UValue
{
	TValue uv;
	lua_Number n;
	double u;
	void *s;
	lua_Integer i;
	long l;
} UValue;

typedef struct Udata
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	unsigned short nuvalue;
	size_t len;
	struct Table *metatable;
	GCObject *gclist;
	UValue uv[1];
} Udata;
typedef struct Udata0
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	unsigned short nuvalue;
	size_t len;
	struct Table *metatable;
	union
	{
		lua_Number n;
		double u;
		void *s;
		lua_Integer i;
		long l;
	} bindata;
} Udata0;
typedef struct Upvaldesc
{
	TString *name;
	lu_byte instack;
	lu_byte idx;
	lu_byte kind;
} Upvaldesc;

typedef struct LocVar
{
	TString *varname;
	int startpc;
	int endpc;
} LocVar;
typedef struct AbsLineInfo
{
	int pc;
	int line;
} AbsLineInfo;

typedef struct Proto
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte numparams;
	lu_byte is_vararg;
	lu_byte maxstacksize;
	int sizeupvalues;
	int sizek;
	int sizecode;
	int sizelineinfo;
	int sizep;
	int sizelocvars;
	int sizeabslineinfo;
	int linedefined;
	int lastlinedefined;
	TValue *k;
	Instruction *code;
	struct Proto **p;
	Upvaldesc *upvalues;
	ls_byte *lineinfo;
	AbsLineInfo *abslineinfo;
	LocVar *locvars;
	TString *source;
	GCObject *gclist;
} Proto;
typedef struct UpVal
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte tbc;
	TValue *v;
	union
	{
		struct
		{
			struct UpVal *next;
			struct UpVal **previous;
		} open;
		TValue value;
	} u;
} UpVal;

typedef struct CClosure
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte nupvalues;
	GCObject *gclist;
	lua_CFunction f;
	TValue upvalue[1];
} CClosure;

typedef struct LClosure
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte nupvalues;
	GCObject *gclist;
	struct Proto *p;
	UpVal *upvals[1];
} LClosure;

typedef union Closure
{
	CClosure c;
	LClosure l;
} Closure;
typedef union Node
{
	struct NodeKey
	{
		Value value_;
		lu_byte tt_;
		lu_byte key_tt;
		int next;
		Value key_val;
	} u;
	TValue i_val;
} Node;
typedef struct Table
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte flags;
	lu_byte lsizenode;
	unsigned int alimit;
	TValue *array;
	Node *node;
	Node *lastfree;
	struct Table *metatable;
	GCObject *gclist;
} Table;
__attribute__((visibility("internal"))) extern int luaO_utf8esc(char *buff, unsigned long x);
__attribute__((visibility("internal"))) extern int luaO_ceillog2(unsigned int x);
__attribute__((visibility("internal"))) extern int
luaO_rawarith(lua_State *L, int op, const TValue *p1, const TValue *p2, TValue *res);
__attribute__((visibility("internal"))) extern void
luaO_arith(lua_State *L, int op, const TValue *p1, const TValue *p2, StkId res);
__attribute__((visibility("internal"))) extern size_t luaO_str2num(const char *s, TValue *o);
__attribute__((visibility("internal"))) extern int luaO_hexavalue(int c);
__attribute__((visibility("internal"))) extern void luaO_tostring(lua_State *L, TValue *obj);
__attribute__((visibility("internal"))) extern const char *
luaO_pushvfstring(lua_State *L, const char *fmt, va_list argp);
__attribute__((visibility("internal"))) extern const char *luaO_pushfstring(lua_State *L,
																			const char *fmt, ...);
__attribute__((visibility("internal"))) extern void luaO_chunkid(char *out, const char *source,
																 size_t srclen);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaM_toobig(lua_State *L);

__attribute__((visibility("internal"))) extern void *luaM_realloc_(lua_State *L, void *block,
																   size_t oldsize, size_t size);
__attribute__((visibility("internal"))) extern void *luaM_saferealloc_(lua_State *L, void *block,
																	   size_t oldsize, size_t size);
__attribute__((visibility("internal"))) extern void luaM_free_(lua_State *L, void *block,
															   size_t osize);
__attribute__((visibility("internal"))) extern void *luaM_growaux_(lua_State *L, void *block,
																   int nelems, int *size,
																   int size_elem, int limit,
																   const char *what);
__attribute__((visibility("internal"))) extern void *
luaM_shrinkvector_(lua_State *L, void *block, int *nelem, int final_n, int size_elem);
__attribute__((visibility("internal"))) extern void *luaM_malloc_(lua_State *L, size_t size,
																  int tag);

typedef struct Zio ZIO;

typedef struct Mbuffer
{
	char *buffer;
	size_t n;
	size_t buffsize;
} Mbuffer;
__attribute__((visibility("internal"))) extern void luaZ_init(lua_State *L, ZIO *z,
															  lua_Reader reader, void *data);
__attribute__((visibility("internal"))) extern size_t luaZ_read(ZIO *z, void *b, size_t n);

struct Zio
{
	size_t n;
	const char *p;
	lua_Reader reader;
	void *data;
	lua_State *L;
};

__attribute__((visibility("internal"))) extern int luaZ_fill(ZIO *z);
enum RESERVED
{

	TK_AND = (UCHAR_MAX + 1),
	TK_BREAK,
	TK_DO,
	TK_ELSE,
	TK_ELSEIF,
	TK_END,
	TK_FALSE,
	TK_FOR,
	TK_FUNCTION,
	TK_GOTO,
	TK_IF,
	TK_IN,
	TK_LOCAL,
	TK_NIL,
	TK_NOT,
	TK_OR,
	TK_REPEAT,
	TK_RETURN,
	TK_THEN,
	TK_TRUE,
	TK_UNTIL,
	TK_WHILE,

	TK_IDIV,
	TK_CONCAT,
	TK_DOTS,
	TK_EQ,
	TK_GE,
	TK_LE,
	TK_NE,
	TK_SHL,
	TK_SHR,
	TK_DBCOLON,
	TK_EOS,
	TK_FLT,
	TK_INT,
	TK_NAME,
	TK_STRING
};

typedef union
{
	lua_Number r;
	lua_Integer i;
	TString *ts;
} SemInfo;

typedef struct Token
{
	int token;
	SemInfo seminfo;
} Token;

typedef struct LexState
{
	int current;
	int linenumber;
	int lastline;
	Token t;
	Token lookahead;
	struct FuncState *fs;
	struct lua_State *L;
	ZIO *z;
	Mbuffer *buff;
	Table *h;
	struct Dyndata *dyd;
	TString *source;
	TString *envn;
} LexState;

__attribute__((visibility("internal"))) extern void luaX_init(lua_State *L);
__attribute__((visibility("internal"))) extern void
luaX_setinput(lua_State *L, LexState *ls, ZIO *z, TString *source, int firstchar);
__attribute__((visibility("internal"))) extern TString *luaX_newstring(LexState *ls,
																	   const char *str, size_t l);
__attribute__((visibility("internal"))) extern void luaX_next(LexState *ls);
__attribute__((visibility("internal"))) extern int luaX_lookahead(LexState *ls);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaX_syntaxerror(LexState *ls, const char *s);
__attribute__((visibility("internal"))) extern const char *luaX_token2str(LexState *ls, int token);

__attribute__((visibility("internal"))) extern unsigned char custom_lislalpha(int c);
__attribute__((visibility("internal"))) extern int custom_lislalnum(int c);
__attribute__((visibility("internal"))) extern int custom_lisdigit(int c);
__attribute__((visibility("internal"))) extern int mask2(int B);
__attribute__((visibility("internal"))) extern int testprop2(int c, int p);

enum OpMode
{
	iABC,
	iABx,
	iAsBx,
	iAx,
	isJ
};
typedef enum
{

	OP_MOVE,
	OP_LOADI,
	OP_LOADF,
	OP_LOADK,
	OP_LOADKX,
	OP_LOADFALSE,
	OP_LFALSESKIP,
	OP_LOADTRUE,
	OP_LOADNIL,
	OP_GETUPVAL,
	OP_SETUPVAL,

	OP_GETTABUP,
	OP_GETTABLE,
	OP_GETI,
	OP_GETFIELD,

	OP_SETTABUP,
	OP_SETTABLE,
	OP_SETI,
	OP_SETFIELD,

	OP_NEWTABLE,

	OP_SELF,

	OP_ADDI,

	OP_ADDK,
	OP_SUBK,
	OP_MULK,
	OP_MODK,
	OP_POWK,
	OP_DIVK,
	OP_IDIVK,

	OP_BANDK,
	OP_BORK,
	OP_BXORK,

	OP_SHRI,
	OP_SHLI,

	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_MOD,
	OP_POW,
	OP_DIV,
	OP_IDIV,

	OP_BAND,
	OP_BOR,
	OP_BXOR,
	OP_SHL,
	OP_SHR,

	OP_MMBIN,
	OP_MMBINI,
	OP_MMBINK,

	OP_UNM,
	OP_BNOT,
	OP_NOT,
	OP_LEN,

	OP_CONCAT,

	OP_CLOSE,
	OP_TBC,
	OP_JMP,
	OP_EQ,
	OP_LT,
	OP_LE,

	OP_EQK,
	OP_EQI,
	OP_LTI,
	OP_LEI,
	OP_GTI,
	OP_GEI,

	OP_TEST,
	OP_TESTSET,

	OP_CALL,
	OP_TAILCALL,

	OP_RETURN,
	OP_RETURN0,
	OP_RETURN1,

	OP_FORLOOP,
	OP_FORPREP,

	OP_TFORPREP,
	OP_TFORCALL,
	OP_TFORLOOP,

	OP_SETLIST,

	OP_CLOSURE,

	OP_VARARG,

	OP_VARARGPREP,

	OP_EXTRAARG
} OpCode;
__attribute__((
	visibility("internal"))) extern const lu_byte luaP_opmodes[((int) (OP_EXTRAARG) + 1)];
typedef enum
{
	VVOID,

	VNIL,
	VTRUE,
	VFALSE,
	VK,
	VKFLT,
	VKINT,
	VKSTR,

	VNONRELOC,

	VLOCAL,

	VUPVAL,
	VCONST,

	VINDEXED,

	VINDEXUP,

	VINDEXI,

	VINDEXSTR,

	VJMP,

	VRELOC,

	VCALL,
	VVARARG
} expkind;

typedef struct expdesc
{
	expkind k;
	union
	{
		lua_Integer ival;
		lua_Number nval;
		TString *strval;
		int info;
		struct
		{
			short idx;
			lu_byte t;
		} ind;
		struct
		{
			lu_byte sidx;
			unsigned short vidx;
		} var;
	} u;
	int t;
	int f;
} expdesc;
typedef union Vardesc
{
	struct
	{
		Value value_;
		lu_byte tt_;
		lu_byte kind;
		lu_byte sidx;
		short pidx;
		TString *name;
	} vd;
	TValue k;
} Vardesc;

typedef struct Labeldesc
{
	TString *name;
	int pc;
	int line;
	lu_byte nactvar;
	lu_byte close;
} Labeldesc;

typedef struct Labellist
{
	Labeldesc *arr;
	int n;
	int size;
} Labellist;

typedef struct Dyndata
{
	struct
	{
		Vardesc *arr;
		int n;
		int size;
	} actvar;
	Labellist gt;
	Labellist label;
} Dyndata;

struct BlockCnt;

typedef struct FuncState
{
	Proto *f;
	struct FuncState *prev;
	struct LexState *ls;
	struct BlockCnt *bl;
	int pc;
	int lasttarget;
	int previousline;
	int nk;
	int np;
	int nabslineinfo;
	int firstlocal;
	int firstlabel;
	short ndebugvars;
	lu_byte nactvar;
	lu_byte nups;
	lu_byte freereg;
	lu_byte iwthabs;
	lu_byte needclose;
} FuncState;

__attribute__((visibility("internal"))) extern int luaY_nvarstack(FuncState *fs);
__attribute__((visibility("internal"))) extern LClosure *
luaY_parser(lua_State *L, ZIO *z, Mbuffer *buff, Dyndata *dyd, const char *name, int firstchar);
typedef enum BinOpr
{

	OPR_ADD,
	OPR_SUB,
	OPR_MUL,
	OPR_MOD,
	OPR_POW,
	OPR_DIV,
	OPR_IDIV,

	OPR_BAND,
	OPR_BOR,
	OPR_BXOR,
	OPR_SHL,
	OPR_SHR,

	OPR_CONCAT,

	OPR_EQ,
	OPR_LT,
	OPR_LE,
	OPR_NE,
	OPR_GT,
	OPR_GE,

	OPR_AND,
	OPR_OR,
	OPR_NOBINOPR
} BinOpr;
typedef enum UnOpr
{
	OPR_MINUS,
	OPR_BNOT,
	OPR_NOT,
	OPR_LEN,
	OPR_NOUNOPR
} UnOpr;
__attribute__((visibility("internal"))) extern int luaK_code(FuncState *fs, Instruction i);
__attribute__((visibility("internal"))) extern int luaK_codeABx(FuncState *fs, OpCode o, int A,
																unsigned int Bx);
__attribute__((visibility("internal"))) extern int luaK_codeAsBx(FuncState *fs, OpCode o, int A,
																 int Bx);
__attribute__((visibility("internal"))) extern int luaK_codeABCk(FuncState *fs, OpCode o, int A,
																 int B, int C, int k);
__attribute__((visibility("internal"))) extern int luaK_isKint(expdesc *e);
__attribute__((visibility("internal"))) extern int luaK_exp2const(FuncState *fs, const expdesc *e,
																  TValue *v);
__attribute__((visibility("internal"))) extern void luaK_fixline(FuncState *fs, int line);
__attribute__((visibility("internal"))) extern void luaK_nil(FuncState *fs, int from, int n);
__attribute__((visibility("internal"))) extern void luaK_reserveregs(FuncState *fs, int n);
__attribute__((visibility("internal"))) extern void luaK_checkstack(FuncState *fs, int n);
__attribute__((visibility("internal"))) extern void luaK_int(FuncState *fs, int reg, lua_Integer n);
__attribute__((visibility("internal"))) extern void luaK_dischargevars(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern int luaK_exp2anyreg(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_exp2anyregup(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_exp2nextreg(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_exp2val(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern int luaK_exp2RK(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_self(FuncState *fs, expdesc *e,
															  expdesc *key);
__attribute__((visibility("internal"))) extern void luaK_indexed(FuncState *fs, expdesc *t,
																 expdesc *k);
__attribute__((visibility("internal"))) extern void luaK_goiftrue(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_goiffalse(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_storevar(FuncState *fs, expdesc *var,
																  expdesc *e);
__attribute__((visibility("internal"))) extern void luaK_setreturns(FuncState *fs, expdesc *e,
																	int nresults);
__attribute__((visibility("internal"))) extern void luaK_setoneret(FuncState *fs, expdesc *e);
__attribute__((visibility("internal"))) extern int luaK_jump(FuncState *fs);
__attribute__((visibility("internal"))) extern void luaK_ret(FuncState *fs, int first, int nret);
__attribute__((visibility("internal"))) extern void luaK_patchlist(FuncState *fs, int list,
																   int target);
__attribute__((visibility("internal"))) extern void luaK_patchtohere(FuncState *fs, int list);
__attribute__((visibility("internal"))) extern void luaK_concat(FuncState *fs, int *l1, int l2);
__attribute__((visibility("internal"))) extern int luaK_getlabel(FuncState *fs);
__attribute__((visibility("internal"))) extern void luaK_prefix(FuncState *fs, UnOpr op, expdesc *v,
																int line);
__attribute__((visibility("internal"))) extern void luaK_infix(FuncState *fs, BinOpr op,
															   expdesc *v);
__attribute__((visibility("internal"))) extern void luaK_posfix(FuncState *fs, BinOpr op,
																expdesc *v1, expdesc *v2, int line);
__attribute__((visibility("internal"))) extern void luaK_settablesize(FuncState *fs, int pc, int ra,
																	  int asize, int hsize);
__attribute__((visibility("internal"))) extern void luaK_setlist(FuncState *fs, int base,
																 int nelems, int tostore);
__attribute__((visibility("internal"))) extern void luaK_finish(FuncState *fs);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaK_semerror(LexState *ls, const char *msg);
typedef enum
{
	TM_INDEX,
	TM_NEWINDEX,
	TM_GC,
	TM_MODE,
	TM_LEN,
	TM_EQ,
	TM_ADD,
	TM_SUB,
	TM_MUL,
	TM_MOD,
	TM_POW,
	TM_DIV,
	TM_IDIV,
	TM_BAND,
	TM_BOR,
	TM_BXOR,
	TM_SHL,
	TM_SHR,
	TM_UNM,
	TM_BNOT,
	TM_LT,
	TM_LE,
	TM_CONCAT,
	TM_CALL,
	TM_CLOSE,
	TM_N
} TMS;
__attribute__((visibility("internal"))) extern const char *const luaT_typenames_[((9 + 1) + 2)];

__attribute__((visibility("internal"))) extern const char *luaT_objtypename(lua_State *L,
																			const TValue *o);

__attribute__((visibility("internal"))) extern const TValue *luaT_gettm(Table *events, TMS event,
																		TString *ename);
__attribute__((visibility("internal"))) extern const TValue *
luaT_gettmbyobj(lua_State *L, const TValue *o, TMS event);
__attribute__((visibility("internal"))) extern void luaT_init(lua_State *L);

__attribute__((visibility("internal"))) extern void
luaT_callTM(lua_State *L, const TValue *f, const TValue *p1, const TValue *p2, const TValue *p3);
__attribute__((visibility("internal"))) extern void
luaT_callTMres(lua_State *L, const TValue *f, const TValue *p1, const TValue *p2, StkId p3);
__attribute__((visibility("internal"))) extern void
luaT_trybinTM(lua_State *L, const TValue *p1, const TValue *p2, StkId res, TMS event);
__attribute__((visibility("internal"))) extern void luaT_tryconcatTM(lua_State *L);
__attribute__((visibility("internal"))) extern void
luaT_trybinassocTM(lua_State *L, const TValue *p1, const TValue *p2, int inv, StkId res, TMS event);
__attribute__((visibility("internal"))) extern void
luaT_trybiniTM(lua_State *L, const TValue *p1, lua_Integer i2, int inv, StkId res, TMS event);
__attribute__((visibility("internal"))) extern int luaT_callorderTM(lua_State *L, const TValue *p1,
																	const TValue *p2, TMS event);
__attribute__((visibility("internal"))) extern int
luaT_callorderiTM(lua_State *L, const TValue *p1, int v2, int inv, int isfloat, TMS event);

__attribute__((visibility("internal"))) extern void
luaT_adjustvarargs(lua_State *L, int nfixparams, struct CallInfo *ci, const Proto *p);
__attribute__((visibility("internal"))) extern void
luaT_getvarargs(lua_State *L, struct CallInfo *ci, StkId where, int wanted);
struct lua_longjmp;
typedef struct stringtable
{
	TString **hash;
	int nuse;
	int size;
} stringtable;

typedef struct CallInfo
{
	StkId func;
	StkId top;
	struct CallInfo *previous, *next;
	union
	{
		struct
		{
			const Instruction *savedpc;
			volatile sig_atomic_t trap;
			int nextraargs;
		} l;
		struct
		{
			lua_KFunction k;
			ptrdiff_t old_errfunc;
			lua_KContext ctx;
		} c;
	} u;
	union
	{
		int funcidx;
		int nyield;
		struct
		{
			unsigned short ftransfer;
			unsigned short ntransfer;
		} transferinfo;
	} u2;
	short nresults;
	unsigned short callstatus;
} CallInfo;
typedef struct global_State
{
	lua_Alloc frealloc;
	void *ud;
	l_mem totalbytes;
	l_mem GCdebt;
	lu_mem GCestimate;
	lu_mem lastatomic;
	stringtable strt;
	TValue l_registry;
	TValue nilvalue;
	unsigned int seed;
	lu_byte currentwhite;
	lu_byte gcstate;
	lu_byte gckind;
	lu_byte genminormul;
	lu_byte genmajormul;
	lu_byte gcrunning;
	lu_byte gcemergency;
	lu_byte gcpause;
	lu_byte gcstepmul;
	lu_byte gcstepsize;
	GCObject *allgc;
	GCObject **sweepgc;
	GCObject *finobj;
	GCObject *gray;
	GCObject *grayagain;
	GCObject *weak;
	GCObject *ephemeron;
	GCObject *allweak;
	GCObject *tobefnz;
	GCObject *fixedgc;

	GCObject *survival;
	GCObject *old1;
	GCObject *reallyold;
	GCObject *firstold1;
	GCObject *finobjsur;
	GCObject *finobjold1;
	GCObject *finobjrold;
	struct lua_State *twups;
	lua_CFunction panic;
	struct lua_State *mainthread;
	TString *memerrmsg;
	TString *tmname[TM_N];
	struct Table *mt[9];
	TString *strcache[53][2];
	lua_WarnFunction warnf;
	void *ud_warn;
} global_State;

struct lua_State
{
	struct GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte status;
	lu_byte allowhook;
	unsigned short nci;
	StkId top;
	global_State *l_G;
	CallInfo *ci;
	StkId stack_last;
	StkId stack;
	UpVal *openupval;
	GCObject *gclist;
	struct lua_State *twups;
	struct lua_longjmp *errorJmp;
	CallInfo base_ci;
	volatile lua_Hook hook;
	ptrdiff_t errfunc;
	l_uint32 nCcalls;
	int oldpc;
	int basehookcount;
	int hookcount;
	volatile sig_atomic_t hookmask;
};
union GCUnion
{
	GCObject gc;
	struct TString ts;
	struct Udata u;
	union Closure cl;
	struct Table h;
	struct Proto p;
	struct lua_State th;
	struct UpVal upv;
};
__attribute__((visibility("internal"))) extern void luaE_setdebt(global_State *g, l_mem debt);
__attribute__((visibility("internal"))) extern void luaE_freethread(lua_State *L, lua_State *L1);
__attribute__((visibility("internal"))) extern CallInfo *luaE_extendCI(lua_State *L);
__attribute__((visibility("internal"))) extern void luaE_freeCI(lua_State *L);
__attribute__((visibility("internal"))) extern void luaE_shrinkCI(lua_State *L);
__attribute__((visibility("internal"))) extern void luaE_checkcstack(lua_State *L);
__attribute__((visibility("internal"))) extern void luaE_incCstack(lua_State *L);
__attribute__((visibility("internal"))) extern void luaE_warning(lua_State *L, const char *msg,
																 int tocont);
__attribute__((visibility("internal"))) extern void luaE_warnerror(lua_State *L, const char *where);
__attribute__((visibility("internal"))) extern int luaG_getfuncline(const Proto *f, int pc);
__attribute__((visibility("internal"))) extern const char *
luaG_findlocal(lua_State *L, CallInfo *ci, int n, StkId *pos);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_typeerror(lua_State *L, const TValue *o, const char *opname);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_forerror(lua_State *L, const TValue *o, const char *what);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_concaterror(lua_State *L, const TValue *p1, const TValue *p2);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_opinterror(lua_State *L, const TValue *p1, const TValue *p2, const char *msg);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_tointerror(lua_State *L, const TValue *p1, const TValue *p2);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_ordererror(lua_State *L, const TValue *p1, const TValue *p2);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_runerror(lua_State *L, const char *fmt, ...);
__attribute__((visibility("internal"))) extern const char *
luaG_addinfo(lua_State *L, const char *msg, TString *src, int line);
__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaG_errormsg(lua_State *L);
__attribute__((visibility("internal"))) extern int luaG_traceexec(lua_State *L,
																  const Instruction *pc);
typedef void (*Pfunc)(lua_State *L, void *ud);

__attribute__((visibility("internal"))) extern void luaD_seterrorobj(lua_State *L, int errcode,
																	 StkId oldtop);
__attribute__((visibility("internal"))) extern int
luaD_protectedparser(lua_State *L, ZIO *z, const char *name, const char *mode);
__attribute__((visibility("internal"))) extern void luaD_hook(lua_State *L, int event, int line,
															  int fTransfer, int nTransfer);
__attribute__((visibility("internal"))) extern void luaD_hookcall(lua_State *L, CallInfo *ci);
__attribute__((visibility("internal"))) extern void luaD_pretailcall(lua_State *L, CallInfo *ci,
																	 StkId func, int n);
__attribute__((visibility("internal"))) extern CallInfo *luaD_precall(lua_State *L, StkId func,
																	  int nResults);
__attribute__((visibility("internal"))) extern void luaD_call(lua_State *L, StkId func,
															  int nResults);
__attribute__((visibility("internal"))) extern void luaD_callnoyield(lua_State *L, StkId func,
																	 int nResults);
__attribute__((visibility("internal"))) extern void luaD_tryfuncTM(lua_State *L, StkId func);
__attribute__((visibility("internal"))) extern int luaD_pcall(lua_State *L, Pfunc func, void *u,
															  ptrdiff_t oldtop, ptrdiff_t ef);
__attribute__((visibility("internal"))) extern void luaD_poscall(lua_State *L, CallInfo *ci,
																 int nres);
__attribute__((visibility("internal"))) extern int luaD_reallocstack(lua_State *L, int newsize,
																	 int raiseerror);
__attribute__((visibility("internal"))) extern int luaD_growstack(lua_State *L, int n,
																  int raiseerror);
__attribute__((visibility("internal"))) extern void luaD_shrinkstack(lua_State *L);
__attribute__((visibility("internal"))) extern void luaD_inctop(lua_State *L);

__attribute__((visibility("internal"))) extern void __attribute__((noreturn))
luaD_throw(lua_State *L, int errcode);
__attribute__((visibility("internal"))) extern int luaD_rawrunprotected(lua_State *L, Pfunc f,
																		void *ud);
__attribute__((visibility("internal"))) extern void luaC_fix(lua_State *L, GCObject *o);
__attribute__((visibility("internal"))) extern void luaC_freeallobjects(lua_State *L);
__attribute__((visibility("internal"))) extern void luaC_step(lua_State *L);
__attribute__((visibility("internal"))) extern void luaC_runtilstate(lua_State *L, int statesmask);
__attribute__((visibility("internal"))) extern void luaC_fullgc(lua_State *L, int isemergency);
__attribute__((visibility("internal"))) extern GCObject *luaC_newobj(lua_State *L, int tt,
																	 size_t sz);
__attribute__((visibility("internal"))) extern void luaC_barrier_(lua_State *L, GCObject *o,
																  GCObject *v);
__attribute__((visibility("internal"))) extern void luaC_barrierback_(lua_State *L, GCObject *o);
__attribute__((visibility("internal"))) extern void luaC_checkfinalizer(lua_State *L, GCObject *o,
																		Table *mt);
__attribute__((visibility("internal"))) extern void luaC_changemode(lua_State *L, int newmode);

__attribute__((visibility("internal"))) extern unsigned int luaS_hash(const char *str, size_t l,
																	  unsigned int seed);
__attribute__((visibility("internal"))) extern unsigned int luaS_hashlongstr(TString *ts);
__attribute__((visibility("internal"))) extern int luaS_eqlngstr(TString *a, TString *b);
__attribute__((visibility("internal"))) extern void luaS_resize(lua_State *L, int newsize);
__attribute__((visibility("internal"))) extern void luaS_clearcache(global_State *g);
__attribute__((visibility("internal"))) extern void luaS_init(lua_State *L);
__attribute__((visibility("internal"))) extern void luaS_remove(lua_State *L, TString *ts);
__attribute__((visibility("internal"))) extern Udata *luaS_newudata(lua_State *L, size_t s,
																	int nuvalue);
__attribute__((visibility("internal"))) extern TString *luaS_newlstr(lua_State *L, const char *str,
																	 size_t l);
__attribute__((visibility("internal"))) extern TString *luaS_new(lua_State *L, const char *str);
__attribute__((visibility("internal"))) extern TString *luaS_createlngstrobj(lua_State *L,
																			 size_t l);
__attribute__((visibility("internal"))) extern const TValue *luaH_getint(Table *t, lua_Integer key);
__attribute__((visibility("internal"))) extern void luaH_setint(lua_State *L, Table *t,
																lua_Integer key, TValue *value);
__attribute__((visibility("internal"))) extern const TValue *luaH_getshortstr(Table *t,
																			  TString *key);
__attribute__((visibility("internal"))) extern const TValue *luaH_getstr(Table *t, TString *key);
__attribute__((visibility("internal"))) extern const TValue *luaH_get(Table *t, const TValue *key);
__attribute__((visibility("internal"))) extern TValue *luaH_newkey(lua_State *L, Table *t,
																   const TValue *key);
__attribute__((visibility("internal"))) extern TValue *luaH_set(lua_State *L, Table *t,
																const TValue *key);
__attribute__((visibility("internal"))) extern Table *luaH_new(lua_State *L);
__attribute__((visibility("internal"))) extern void
luaH_resize(lua_State *L, Table *t, unsigned int nasize, unsigned int nhsize);
__attribute__((visibility("internal"))) extern void luaH_resizearray(lua_State *L, Table *t,
																	 unsigned int nasize);
__attribute__((visibility("internal"))) extern void luaH_free(lua_State *L, Table *t);
__attribute__((visibility("internal"))) extern int luaH_next(lua_State *L, Table *t, StkId key);
__attribute__((visibility("internal"))) extern lua_Unsigned luaH_getn(Table *t);
__attribute__((visibility("internal"))) extern unsigned int luaH_realasize(const Table *t);
typedef enum
{
	F2Ieq,
	F2Ifloor,
	F2Iceil
} F2Imod;
__attribute__((visibility("internal"))) extern int luaV_equalobj(lua_State *L, const TValue *t1,
																 const TValue *t2);
__attribute__((visibility("internal"))) extern int luaV_lessthan(lua_State *L, const TValue *l,
																 const TValue *r);
__attribute__((visibility("internal"))) extern int luaV_lessequal(lua_State *L, const TValue *l,
																  const TValue *r);
__attribute__((visibility("internal"))) extern int luaV_tonumber_(const TValue *obj, lua_Number *n);
__attribute__((visibility("internal"))) extern int luaV_tointeger(const TValue *obj, lua_Integer *p,
																  F2Imod mode);
__attribute__((visibility("internal"))) extern int luaV_tointegerns(const TValue *obj,
																	lua_Integer *p, F2Imod mode);
__attribute__((visibility("internal"))) extern int luaV_flttointeger(lua_Number n, lua_Integer *p,
																	 F2Imod mode);
__attribute__((visibility("internal"))) extern void
luaV_finishget(lua_State *L, const TValue *t, TValue *key, StkId val, const TValue *slot);
__attribute__((visibility("internal"))) extern void
luaV_finishset(lua_State *L, const TValue *t, TValue *key, TValue *val, const TValue *slot);
__attribute__((visibility("internal"))) extern void luaV_finishOp(lua_State *L);
__attribute__((visibility("internal"))) extern void luaV_execute(lua_State *L, CallInfo *ci);
__attribute__((visibility("internal"))) extern void luaV_concat(lua_State *L, int total);
__attribute__((visibility("internal"))) extern lua_Integer luaV_idiv(lua_State *L, lua_Integer x,
																	 lua_Integer y);
__attribute__((visibility("internal"))) extern lua_Integer luaV_mod(lua_State *L, lua_Integer x,
																	lua_Integer y);
__attribute__((visibility("internal"))) extern lua_Number luaV_modf(lua_State *L, lua_Number x,
																	lua_Number y);
__attribute__((visibility("internal"))) extern lua_Integer luaV_shiftl(lua_Integer x,
																	   lua_Integer y);
__attribute__((visibility("internal"))) extern void luaV_objlen(lua_State *L, StkId ra,
																const TValue *rb);
static int codesJ(FuncState *fs, OpCode o, int sj, int k);

void __attribute__((noreturn)) luaK_semerror(LexState *ls, const char *msg)
{
	ls->t.token = 0;
	luaX_syntaxerror(ls, msg);
}

static int tonumeral(const expdesc *e, TValue *v)
{
	if (((e)->t != (e)->f))
		return 0;
	switch (e->k)
	{
	case VKINT:
		if (v)
		{
			TValue *io = (v);
			((io)->value_).i = (e->u.ival);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		return 1;
	case VKFLT:
		if (v)
		{
			TValue *io = (v);
			((io)->value_).n = (e->u.nval);
			((io)->tt_ = (((3) | ((1) << 4))));
		};
		return 1;
	default:
		return 0;
	}
}

static TValue *const2val(FuncState *fs, const expdesc *e)
{
	((void) 0);
	return &fs->ls->dyd->actvar.arr[e->u.info].k;
}

int luaK_exp2const(FuncState *fs, const expdesc *e, TValue *v)
{
	if (((e)->t != (e)->f))
		return 0;
	switch (e->k)
	{
	case VFALSE:
		((v)->tt_ = (((1) | ((0) << 4))));
		return 1;
	case VTRUE:
		((v)->tt_ = (((1) | ((1) << 4))));
		return 1;
	case VNIL:
		((v)->tt_ = (((0) | ((0) << 4))));
		return 1;
	case VKSTR:
	{
		{
			TValue *io = (v);
			TString *x_ = (e->u.strval);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) fs->ls->L, ((void) 0));
		};
		return 1;
	}
	case VCONST:
	{
		{
			TValue *io1 = (v);
			const TValue *io2 = (const2val(fs, e));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) fs->ls->L, ((void) 0));
			((void) 0);
		};
		return 1;
	}
	default:
		return tonumeral(e, v);
	}
}
static Instruction *previousinstruction(FuncState *fs)
{
	static const Instruction invalidinstruction = ~(Instruction) 0;
	if (fs->pc > fs->lasttarget)
		return &fs->f->code[fs->pc - 1];
	else
		return ((Instruction *) (&invalidinstruction));
}
void luaK_nil(FuncState *fs, int from, int n)
{
	int l = from + n - 1;
	Instruction *previous = previousinstruction(fs);
	if ((((OpCode) (((*previous) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))) == OP_LOADNIL)
	{
		int pfrom =
			(((int) ((((*previous) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0))))));
		int pl = pfrom + ((((int) ((((*previous) >> ((((0 + 7) + 8) + 1))) &
									((~((~(Instruction) 0) << (8))) << (0)))))));
		if ((pfrom <= from && from <= pl + 1) || (from <= pfrom && pfrom <= l + 1))
		{
			if (pfrom < from)
				from = pfrom;
			if (pl > l)
				l = pl;
			((*previous) = (((*previous) & (~((~((~(Instruction) 0) << (8))) << ((0 + 7))))) |
							((((Instruction) (from)) << (0 + 7)) &
							 ((~((~(Instruction) 0) << (8))) << ((0 + 7))))));
			((*previous) =
				 (((*previous) & (~((~((~(Instruction) 0) << (8))) << ((((0 + 7) + 8) + 1))))) |
				  ((((Instruction) (l - from)) << (((0 + 7) + 8) + 1)) &
				   ((~((~(Instruction) 0) << (8))) << ((((0 + 7) + 8) + 1))))));
			return;
		}
	}
	luaK_codeABCk(fs, OP_LOADNIL, from, n - 1, 0, 0);
}

static int getjump(FuncState *fs, int pc)
{
	int offset = ((((int) ((((fs->f->code[pc]) >> ((0 + 7))) &
							((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
				  (INT_MAX >> 1));
	if (offset == (-1))
		return (-1);
	else
		return (pc + 1) + offset;
}

static void fixjump(FuncState *fs, int pc, int dest)
{
	Instruction *jmp = &fs->f->code[pc];
	int offset = dest - (pc + 1);
	((void) 0);
	if (!(-(INT_MAX >> 1) <= offset && offset <= INT_MAX - (INT_MAX >> 1)))
		luaX_syntaxerror(fs->ls, "control structure too long");
	((void) 0);
	((*jmp) = (((*jmp) & (~((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << ((0 + 7))))) |
			   ((((Instruction) (((unsigned int) (((offset) + (INT_MAX >> 1)))))) << (0 + 7)) &
				((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << ((0 + 7))))));
}

void luaK_concat(FuncState *fs, int *l1, int l2)
{
	if (l2 == (-1))
		return;
	else if (*l1 == (-1))
		*l1 = l2;
	else
	{
		int list = *l1;
		int next;
		while ((next = getjump(fs, list)) != (-1))
			list = next;
		fixjump(fs, list, l2);
	}
}

int luaK_jump(FuncState *fs)
{
	return codesJ(fs, OP_JMP, (-1), 0);
}

void luaK_ret(FuncState *fs, int first, int nret)
{
	OpCode op;
	switch (nret)
	{
	case 0:
		op = OP_RETURN0;
		break;
	case 1:
		op = OP_RETURN1;
		break;
	default:
		op = OP_RETURN;
		break;
	}
	luaK_codeABCk(fs, op, first, nret + 1, 0, 0);
}

static int condjump(FuncState *fs, OpCode op, int A, int B, int C, int k)
{
	luaK_codeABCk(fs, op, A, B, C, k);
	return luaK_jump(fs);
}

int luaK_getlabel(FuncState *fs)
{
	fs->lasttarget = fs->pc;
	return fs->pc;
}

static Instruction *getjumpcontrol(FuncState *fs, int pc)
{
	Instruction *pi = &fs->f->code[pc];
	if (pc >= 1 &&
		(luaP_opmodes[(((OpCode) (((*(pi - 1)) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))] &
		 (1 << 4)))
		return pi - 1;
	else
		return pi;
}
static int patchtestreg(FuncState *fs, int node, int reg)
{
	Instruction *i = getjumpcontrol(fs, node);
	if ((((OpCode) (((*i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))) != OP_TESTSET)
		return 0;
	if (reg != ((1 << 8) - 1) && reg != ((((int) ((((*i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0))))))))
		((*i) = (((*i) & (~((~((~(Instruction) 0) << (8))) << ((0 + 7))))) |
				 ((((Instruction) (reg)) << (0 + 7)) &
				  ((~((~(Instruction) 0) << (8))) << ((0 + 7))))));
	else
	{

		*i = ((((Instruction) (OP_TEST)) << 0) |
			  (((Instruction) (((((int) ((((*i) >> ((((0 + 7) + 8) + 1))) &
										  ((~((~(Instruction) 0) << (8))) << (0)))))))))
			   << (0 + 7)) |
			  (((Instruction) (0)) << (((0 + 7) + 8) + 1)) |
			  (((Instruction) (0)) << ((((0 + 7) + 8) + 1) + 8)) |
			  (((Instruction) (((((
				   int) ((((*i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0)))))))))
			   << ((0 + 7) + 8)));
	}
	return 1;
}

static void removevalues(FuncState *fs, int list)
{
	for (; list != (-1); list = getjump(fs, list))
		patchtestreg(fs, list, ((1 << 8) - 1));
}

static void patchlistaux(FuncState *fs, int list, int vtarget, int reg, int dtarget)
{
	while (list != (-1))
	{
		int next = getjump(fs, list);
		if (patchtestreg(fs, list, reg))
			fixjump(fs, list, vtarget);
		else
			fixjump(fs, list, dtarget);
		list = next;
	}
}

void luaK_patchlist(FuncState *fs, int list, int target)
{
	((void) 0);
	patchlistaux(fs, list, target, ((1 << 8) - 1), target);
}

void luaK_patchtohere(FuncState *fs, int list)
{
	int hr = luaK_getlabel(fs);
	luaK_patchlist(fs, list, hr);
}
static void savelineinfo(FuncState *fs, Proto *f, int line)
{
	int linedif = line - fs->previousline;
	int pc = fs->pc - 1;
	if (abs(linedif) >= 0x80 || fs->iwthabs++ > 120)
	{
		((f->abslineinfo) = ((AbsLineInfo *) (luaM_growaux_(
			 fs->ls->L, f->abslineinfo, fs->nabslineinfo, &(f->sizeabslineinfo),
			 sizeof(AbsLineInfo),
			 ((((size_t) ((INT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(AbsLineInfo))
				  ? (INT_MAX)
				  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(AbsLineInfo)))))),
			 "lines"))));

		f->abslineinfo[fs->nabslineinfo].pc = pc;
		f->abslineinfo[fs->nabslineinfo++].line = line;
		linedif = (-0x80);
		fs->iwthabs = 0;
	}
	((f->lineinfo) = ((ls_byte *) (luaM_growaux_(
		 fs->ls->L, f->lineinfo, pc, &(f->sizelineinfo), sizeof(ls_byte),
		 ((((size_t) ((INT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(ls_byte))
			  ? (INT_MAX)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(ls_byte)))))),
		 "opcodes"))));

	f->lineinfo[pc] = linedif;
	fs->previousline = line;
}
static void removelastlineinfo(FuncState *fs)
{
	Proto *f = fs->f;
	int pc = fs->pc - 1;
	if (f->lineinfo[pc] != (-0x80))
	{
		fs->previousline -= f->lineinfo[pc];
		fs->iwthabs--;
	}
	else
	{
		((void) 0);
		fs->nabslineinfo--;
		fs->iwthabs = 120 + 1;
	}
}

static void removelastinstruction(FuncState *fs)
{
	removelastlineinfo(fs);
	fs->pc--;
}

int luaK_code(FuncState *fs, Instruction i)
{
	Proto *f = fs->f;

	((f->code) = ((Instruction *) (luaM_growaux_(
		 fs->ls->L, f->code, fs->pc, &(f->sizecode), sizeof(Instruction),
		 ((((size_t) ((INT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(Instruction))
			  ? (INT_MAX)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(Instruction)))))),
		 "opcodes"))));

	f->code[fs->pc++] = i;
	savelineinfo(fs, f, fs->ls->lastline);
	return fs->pc - 1;
}

int luaK_codeABCk(FuncState *fs, OpCode o, int a, int b, int c, int k)
{
	((void) 0);
	((void) 0);

	return luaK_code(fs, ((((Instruction) (o)) << 0) | (((Instruction) (a)) << (0 + 7)) |
						  (((Instruction) (b)) << (((0 + 7) + 8) + 1)) |
						  (((Instruction) (c)) << ((((0 + 7) + 8) + 1) + 8)) |
						  (((Instruction) (k)) << ((0 + 7) + 8))));
}

int luaK_codeABx(FuncState *fs, OpCode o, int a, unsigned int bc)
{
	((void) 0);
	((void) 0);
	return luaK_code(fs, ((((Instruction) (o)) << 0) | (((Instruction) (a)) << (0 + 7)) |
						  (((Instruction) (bc)) << ((0 + 7) + 8))));
}

int luaK_codeAsBx(FuncState *fs, OpCode o, int a, int bc)
{
	unsigned int b = bc + (INT_MAX >> 1);
	((void) 0);
	((void) 0);
	return luaK_code(fs, ((((Instruction) (o)) << 0) | (((Instruction) (a)) << (0 + 7)) |
						  (((Instruction) (b)) << ((0 + 7) + 8))));
}

static int codesJ(FuncState *fs, OpCode o, int sj, int k)
{
	unsigned int j = sj + (INT_MAX >> 1);
	((void) 0);
	((void) 0);
	return luaK_code(fs, ((((Instruction) (o)) << 0) | (((Instruction) (j)) << (0 + 7)) |
						  (((Instruction) (k)) << ((0 + 7) + 8))));
}

static int codeextraarg(FuncState *fs, int a)
{
	((void) 0);
	return luaK_code(fs, ((((Instruction) (OP_EXTRAARG)) << 0) | (((Instruction) (a)) << (0 + 7))));
}

static int luaK_codek(FuncState *fs, int reg, int k)
{
	if (k <= INT_MAX)
		return luaK_codeABx(fs, OP_LOADK, reg, k);
	else
	{
		int p = luaK_codeABx(fs, OP_LOADKX, reg, 0);
		codeextraarg(fs, k);
		return p;
	}
}

void luaK_checkstack(FuncState *fs, int n)
{
	int newstack = fs->freereg + n;
	if (newstack > fs->f->maxstacksize)
	{
		if (newstack >= 255)
			luaX_syntaxerror(fs->ls, "function or expression needs too many registers");
		fs->f->maxstacksize = ((lu_byte) ((newstack)));
	}
}

void luaK_reserveregs(FuncState *fs, int n)
{
	luaK_checkstack(fs, n);
	fs->freereg += n;
}

static void freereg(FuncState *fs, int reg)
{
	if (reg >= luaY_nvarstack(fs))
	{
		fs->freereg--;
		((void) 0);
	}
}

static void freeregs(FuncState *fs, int r1, int r2)
{
	if (r1 > r2)
	{
		freereg(fs, r1);
		freereg(fs, r2);
	}
	else
	{
		freereg(fs, r2);
		freereg(fs, r1);
	}
}

static void freeexp(FuncState *fs, expdesc *e)
{
	if (e->k == VNONRELOC)
		freereg(fs, e->u.info);
}

static void freeexps(FuncState *fs, expdesc *e1, expdesc *e2)
{
	int r1 = (e1->k == VNONRELOC) ? e1->u.info : -1;
	int r2 = (e2->k == VNONRELOC) ? e2->u.info : -1;
	freeregs(fs, r1, r2);
}
static int addk(FuncState *fs, TValue *key, TValue *v)
{
	lua_State *L = fs->ls->L;
	Proto *f = fs->f;
	TValue *idx = luaH_set(L, fs->ls->h, key);
	int k, oldsize;
	if (((((idx))->tt_) == (((3) | ((0) << 4)))))
	{
		k = ((int) (((((idx)->value_).i))));

		if (k < fs->nk && ((((&f->k[k])->tt_)) & 0x3F) == ((((v)->tt_)) & 0x3F) &&
			luaV_equalobj(NULL, &f->k[k], v))
			return k;
	}

	oldsize = f->sizek;
	k = fs->nk;

	{
		TValue *io = (idx);
		((io)->value_).i = (k);
		((io)->tt_ = (((3) | ((0) << 4))));
	};
	((f->k) = ((TValue *) (luaM_growaux_(
		 L, f->k, k, &(f->sizek), sizeof(TValue),
		 ((((size_t) ((INT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(TValue))
			  ? (INT_MAX)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(TValue)))))),
		 "constants"))));
	while (oldsize < f->sizek)
		((&f->k[oldsize++])->tt_ = (((0) | ((0) << 4))));
	{
		TValue *io1 = (&f->k[k]);
		const TValue *io2 = (v);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	fs->nk++;
	(((((v)->tt_) & (1 << 6)) && (((f)->marked) & ((1 << (5)))) &&
	  ((((((v)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(L, (&(((union GCUnion *) ((f)))->gc)), (((v)->value_).gc))
		 : ((void) ((0))));
	return k;
}

static int stringK(FuncState *fs, TString *s)
{
	TValue o;
	{
		TValue *io = (&o);
		TString *x_ = (s);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void) fs->ls->L, ((void) 0));
	};
	return addk(fs, &o, &o);
}
static int luaK_intK(FuncState *fs, lua_Integer n)
{
	TValue k, o;
	{
		TValue *io = (&k);
		((io)->value_).p = (((void *) ((((size_t) ((n)))))));
		((io)->tt_ = (((2) | ((0) << 4))));
	};
	{
		TValue *io = (&o);
		((io)->value_).i = (n);
		((io)->tt_ = (((3) | ((0) << 4))));
	};
	return addk(fs, &k, &o);
}

static int luaK_numberK(FuncState *fs, lua_Number r)
{
	TValue o;
	{
		TValue *io = (&o);
		((io)->value_).n = (r);
		((io)->tt_ = (((3) | ((1) << 4))));
	};
	return addk(fs, &o, &o);
}

static int boolF(FuncState *fs)
{
	TValue o;
	((&o)->tt_ = (((1) | ((0) << 4))));
	return addk(fs, &o, &o);
}

static int boolT(FuncState *fs)
{
	TValue o;
	((&o)->tt_ = (((1) | ((1) << 4))));
	return addk(fs, &o, &o);
}

static int nilK(FuncState *fs)
{
	TValue k, v;
	((&v)->tt_ = (((0) | ((0) << 4))));

	{
		TValue *io = (&k);
		Table *x_ = (fs->ls->h);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
		((void) fs->ls->L, ((void) 0));
	};
	return addk(fs, &k, &v);
}

static int fitsC(lua_Integer i)
{
	return (((lua_Unsigned) (i)) + (((1 << 8) - 1) >> 1) <= ((unsigned int) ((((1 << 8) - 1)))));
}

static int fitsBx(lua_Integer i)
{
	return (-(INT_MAX >> 1) <= i && i <= INT_MAX - (INT_MAX >> 1));
}

void luaK_int(FuncState *fs, int reg, lua_Integer i)
{
	if (fitsBx(i))
		luaK_codeAsBx(fs, OP_LOADI, reg, ((int) ((i))));
	else
		luaK_codek(fs, reg, luaK_intK(fs, i));
}

static void luaK_float(FuncState *fs, int reg, lua_Number f)
{
	lua_Integer fi;
	if (luaV_flttointeger(f, &fi, F2Ieq) && fitsBx(fi))
		luaK_codeAsBx(fs, OP_LOADF, reg, ((int) ((fi))));
	else
		luaK_codek(fs, reg, luaK_numberK(fs, f));
}

static void const2exp(TValue *v, expdesc *e)
{
	switch (((((v)->tt_)) & 0x3F))
	{
	case ((3) | ((0) << 4)):
		e->k = VKINT;
		e->u.ival = (((v)->value_).i);
		break;
	case ((3) | ((1) << 4)):
		e->k = VKFLT;
		e->u.nval = (((v)->value_).n);
		break;
	case ((1) | ((0) << 4)):
		e->k = VFALSE;
		break;
	case ((1) | ((1) << 4)):
		e->k = VTRUE;
		break;
	case ((0) | ((0) << 4)):
		e->k = VNIL;
		break;
	case ((4) | ((0) << 4)):
	case ((4) | ((1) << 4)):
		e->k = VKSTR;
		e->u.strval = ((&((((union GCUnion *) ((((v)->value_).gc))))->ts)));
		break;
	default:
		((void) 0);
	}
}

void luaK_setreturns(FuncState *fs, expdesc *e, int nresults)
{
	Instruction *pc = &((fs)->f->code[(e)->u.info]);
	if (e->k == VCALL)
		((*pc) = (((*pc) & (~((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))) |
				  ((((Instruction) (nresults + 1)) << ((((0 + 7) + 8) + 1) + 8)) &
				   ((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))));
	else
	{
		((void) 0);
		((*pc) = (((*pc) & (~((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))) |
				  ((((Instruction) (nresults + 1)) << ((((0 + 7) + 8) + 1) + 8)) &
				   ((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))));
		((*pc) = (((*pc) & (~((~((~(Instruction) 0) << (8))) << ((0 + 7))))) |
				  ((((Instruction) (fs->freereg)) << (0 + 7)) &
				   ((~((~(Instruction) 0) << (8))) << ((0 + 7))))));
		luaK_reserveregs(fs, 1);
	}
}

static void str2K(FuncState *fs, expdesc *e)
{
	((void) 0);
	e->u.info = stringK(fs, e->u.strval);
	e->k = VK;
}
void luaK_setoneret(FuncState *fs, expdesc *e)
{
	if (e->k == VCALL)
	{

		((void) 0);
		e->k = VNONRELOC;
		e->u.info = (((int) ((((((fs)->f->code[(e)->u.info])) >> ((0 + 7))) &
							  ((~((~(Instruction) 0) << (8))) << (0))))));
	}
	else if (e->k == VVARARG)
	{
		((((fs)->f->code[(e)->u.info])) =
			 (((((fs)->f->code[(e)->u.info])) &
			   (~((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))) |
			  ((((Instruction) (2)) << ((((0 + 7) + 8) + 1) + 8)) &
			   ((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))));
		e->k = VRELOC;
	}
}

void luaK_dischargevars(FuncState *fs, expdesc *e)
{
	switch (e->k)
	{
	case VCONST:
	{
		const2exp(const2val(fs, e), e);
		break;
	}
	case VLOCAL:
	{
		e->u.info = e->u.var.sidx;
		e->k = VNONRELOC;
		break;
	}
	case VUPVAL:
	{
		e->u.info = luaK_codeABCk(fs, OP_GETUPVAL, 0, e->u.info, 0, 0);
		e->k = VRELOC;
		break;
	}
	case VINDEXUP:
	{
		e->u.info = luaK_codeABCk(fs, OP_GETTABUP, 0, e->u.ind.t, e->u.ind.idx, 0);
		e->k = VRELOC;
		break;
	}
	case VINDEXI:
	{
		freereg(fs, e->u.ind.t);
		e->u.info = luaK_codeABCk(fs, OP_GETI, 0, e->u.ind.t, e->u.ind.idx, 0);
		e->k = VRELOC;
		break;
	}
	case VINDEXSTR:
	{
		freereg(fs, e->u.ind.t);
		e->u.info = luaK_codeABCk(fs, OP_GETFIELD, 0, e->u.ind.t, e->u.ind.idx, 0);
		e->k = VRELOC;
		break;
	}
	case VINDEXED:
	{
		freeregs(fs, e->u.ind.t, e->u.ind.idx);
		e->u.info = luaK_codeABCk(fs, OP_GETTABLE, 0, e->u.ind.t, e->u.ind.idx, 0);
		e->k = VRELOC;
		break;
	}
	case VVARARG:
	case VCALL:
	{
		luaK_setoneret(fs, e);
		break;
	}
	default:
		break;
	}
}

static void discharge2reg(FuncState *fs, expdesc *e, int reg)
{
	luaK_dischargevars(fs, e);
	switch (e->k)
	{
	case VNIL:
	{
		luaK_nil(fs, reg, 1);
		break;
	}
	case VFALSE:
	{
		luaK_codeABCk(fs, OP_LOADFALSE, reg, 0, 0, 0);
		break;
	}
	case VTRUE:
	{
		luaK_codeABCk(fs, OP_LOADTRUE, reg, 0, 0, 0);
		break;
	}
	case VKSTR:
	{
		str2K(fs, e);
	}
	case VK:
	{
		luaK_codek(fs, reg, e->u.info);
		break;
	}
	case VKFLT:
	{
		luaK_float(fs, reg, e->u.nval);
		break;
	}
	case VKINT:
	{
		luaK_int(fs, reg, e->u.ival);
		break;
	}
	case VRELOC:
	{
		Instruction *pc = &((fs)->f->code[(e)->u.info]);
		((*pc) = (((*pc) & (~((~((~(Instruction) 0) << (8))) << ((0 + 7))))) |
				  ((((Instruction) (reg)) << (0 + 7)) &
				   ((~((~(Instruction) 0) << (8))) << ((0 + 7))))));
		break;
	}
	case VNONRELOC:
	{
		if (reg != e->u.info)
			luaK_codeABCk(fs, OP_MOVE, reg, e->u.info, 0, 0);
		break;
	}
	default:
	{
		((void) 0);
		return;
	}
	}
	e->u.info = reg;
	e->k = VNONRELOC;
}

static void discharge2anyreg(FuncState *fs, expdesc *e)
{
	if (e->k != VNONRELOC)
	{
		luaK_reserveregs(fs, 1);
		discharge2reg(fs, e, fs->freereg - 1);
	}
}

static int code_loadbool(FuncState *fs, int A, OpCode op)
{
	luaK_getlabel(fs);
	return luaK_codeABCk(fs, op, A, 0, 0, 0);
}

static int need_value(FuncState *fs, int list)
{
	for (; list != (-1); list = getjump(fs, list))
	{
		Instruction i = *getjumpcontrol(fs, list);
		if ((((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))) != OP_TESTSET)
			return 1;
	}
	return 0;
}
static void exp2reg(FuncState *fs, expdesc *e, int reg)
{
	discharge2reg(fs, e, reg);
	if (e->k == VJMP)
		luaK_concat(fs, &e->t, e->u.info);
	if (((e)->t != (e)->f))
	{
		int final;
		int p_f = (-1);
		int p_t = (-1);
		if (need_value(fs, e->t) || need_value(fs, e->f))
		{
			int fj = (e->k == VJMP) ? (-1) : luaK_jump(fs);
			p_f = code_loadbool(fs, reg, OP_LFALSESKIP);
			p_t = code_loadbool(fs, reg, OP_LOADTRUE);

			luaK_patchtohere(fs, fj);
		}
		final = luaK_getlabel(fs);
		patchlistaux(fs, e->f, final, reg, p_f);
		patchlistaux(fs, e->t, final, reg, p_t);
	}
	e->f = e->t = (-1);
	e->u.info = reg;
	e->k = VNONRELOC;
}

void luaK_exp2nextreg(FuncState *fs, expdesc *e)
{
	luaK_dischargevars(fs, e);
	freeexp(fs, e);
	luaK_reserveregs(fs, 1);
	exp2reg(fs, e, fs->freereg - 1);
}

int luaK_exp2anyreg(FuncState *fs, expdesc *e)
{
	luaK_dischargevars(fs, e);
	if (e->k == VNONRELOC)
	{
		if (!((e)->t != (e)->f))
			return e->u.info;
		if (e->u.info >= luaY_nvarstack(fs))
		{
			exp2reg(fs, e, e->u.info);
			return e->u.info;
		}
	}
	luaK_exp2nextreg(fs, e);
	return e->u.info;
}

void luaK_exp2anyregup(FuncState *fs, expdesc *e)
{
	if (e->k != VUPVAL || ((e)->t != (e)->f))
		luaK_exp2anyreg(fs, e);
}

void luaK_exp2val(FuncState *fs, expdesc *e)
{
	if (((e)->t != (e)->f))
		luaK_exp2anyreg(fs, e);
	else
		luaK_dischargevars(fs, e);
}

static int luaK_exp2K(FuncState *fs, expdesc *e)
{
	if (!((e)->t != (e)->f))
	{
		int info;
		switch (e->k)
		{
		case VTRUE:
			info = boolT(fs);
			break;
		case VFALSE:
			info = boolF(fs);
			break;
		case VNIL:
			info = nilK(fs);
			break;
		case VKINT:
			info = luaK_intK(fs, e->u.ival);
			break;
		case VKFLT:
			info = luaK_numberK(fs, e->u.nval);
			break;
		case VKSTR:
			info = stringK(fs, e->u.strval);
			break;
		case VK:
			info = e->u.info;
			break;
		default:
			return 0;
		}
		if (info <= ((1 << 8) - 1))
		{
			e->k = VK;
			e->u.info = info;
			return 1;
		}
	}

	return 0;
}
int luaK_exp2RK(FuncState *fs, expdesc *e)
{
	if (luaK_exp2K(fs, e))
		return 1;
	else
	{
		luaK_exp2anyreg(fs, e);
		return 0;
	}
}

static void codeABRK(FuncState *fs, OpCode o, int a, int b, expdesc *ec)
{
	int k = luaK_exp2RK(fs, ec);
	luaK_codeABCk(fs, o, a, b, ec->u.info, k);
}

void luaK_storevar(FuncState *fs, expdesc *var, expdesc *ex)
{
	switch (var->k)
	{
	case VLOCAL:
	{
		freeexp(fs, ex);
		exp2reg(fs, ex, var->u.var.sidx);
		return;
	}
	case VUPVAL:
	{
		int e = luaK_exp2anyreg(fs, ex);
		luaK_codeABCk(fs, OP_SETUPVAL, e, var->u.info, 0, 0);
		break;
	}
	case VINDEXUP:
	{
		codeABRK(fs, OP_SETTABUP, var->u.ind.t, var->u.ind.idx, ex);
		break;
	}
	case VINDEXI:
	{
		codeABRK(fs, OP_SETI, var->u.ind.t, var->u.ind.idx, ex);
		break;
	}
	case VINDEXSTR:
	{
		codeABRK(fs, OP_SETFIELD, var->u.ind.t, var->u.ind.idx, ex);
		break;
	}
	case VINDEXED:
	{
		codeABRK(fs, OP_SETTABLE, var->u.ind.t, var->u.ind.idx, ex);
		break;
	}
	default:
		((void) 0);
	}
	freeexp(fs, ex);
}

void luaK_self(FuncState *fs, expdesc *e, expdesc *key)
{
	int ereg;
	luaK_exp2anyreg(fs, e);
	ereg = e->u.info;
	freeexp(fs, e);
	e->u.info = fs->freereg;
	e->k = VNONRELOC;
	luaK_reserveregs(fs, 2);
	codeABRK(fs, OP_SELF, e->u.info, ereg, key);
	freeexp(fs, key);
}

static void negatecondition(FuncState *fs, expdesc *e)
{
	Instruction *pc = getjumpcontrol(fs, e->u.info);
	((void) 0);

	((*pc) = (((*pc) & (~((~((~(Instruction) 0) << (1))) << (((0 + 7) + 8))))) |
			  ((((Instruction) ((((((int) ((((*pc) >> (((0 + 7) + 8))) &
											((~((~(Instruction) 0) << (1))) << (0))))))) ^
								 1)))
				<< ((0 + 7) + 8)) &
			   ((~((~(Instruction) 0) << (1))) << (((0 + 7) + 8))))));
}
static int jumponcond(FuncState *fs, expdesc *e, int cond)
{
	if (e->k == VRELOC)
	{
		Instruction ie = ((fs)->f->code[(e)->u.info]);
		if ((((OpCode) (((ie) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))) == OP_NOT)
		{
			removelastinstruction(fs);
			return condjump(fs, OP_TEST,
							((((int) ((((ie) >> ((((0 + 7) + 8) + 1))) &
									   ((~((~(Instruction) 0) << (8))) << (0))))))),
							0, 0, !cond);
		}
	}
	discharge2anyreg(fs, e);
	freeexp(fs, e);
	return condjump(fs, OP_TESTSET, ((1 << 8) - 1), e->u.info, 0, cond);
}

void luaK_goiftrue(FuncState *fs, expdesc *e)
{
	int pc;
	luaK_dischargevars(fs, e);
	switch (e->k)
	{
	case VJMP:
	{
		negatecondition(fs, e);
		pc = e->u.info;
		break;
	}
	case VK:
	case VKFLT:
	case VKINT:
	case VKSTR:
	case VTRUE:
	{
		pc = (-1);
		break;
	}
	default:
	{
		pc = jumponcond(fs, e, 0);
		break;
	}
	}
	luaK_concat(fs, &e->f, pc);
	luaK_patchtohere(fs, e->t);
	e->t = (-1);
}

void luaK_goiffalse(FuncState *fs, expdesc *e)
{
	int pc;
	luaK_dischargevars(fs, e);
	switch (e->k)
	{
	case VJMP:
	{
		pc = e->u.info;
		break;
	}
	case VNIL:
	case VFALSE:
	{
		pc = (-1);
		break;
	}
	default:
	{
		pc = jumponcond(fs, e, 1);
		break;
	}
	}
	luaK_concat(fs, &e->t, pc);
	luaK_patchtohere(fs, e->f);
	e->f = (-1);
}

static void codenot(FuncState *fs, expdesc *e)
{
	switch (e->k)
	{
	case VNIL:
	case VFALSE:
	{
		e->k = VTRUE;
		break;
	}
	case VK:
	case VKFLT:
	case VKINT:
	case VKSTR:
	case VTRUE:
	{
		e->k = VFALSE;
		break;
	}
	case VJMP:
	{
		negatecondition(fs, e);
		break;
	}
	case VRELOC:
	case VNONRELOC:
	{
		discharge2anyreg(fs, e);
		freeexp(fs, e);
		e->u.info = luaK_codeABCk(fs, OP_NOT, 0, e->u.info, 0, 0);
		e->k = VRELOC;
		break;
	}
	default:
		((void) 0);
	}

	{
		int temp = e->f;
		e->f = e->t;
		e->t = temp;
	}
	removevalues(fs, e->f);
	removevalues(fs, e->t);
}

static int isKstr(FuncState *fs, expdesc *e)
{
	return (e->k == VK && !((e)->t != (e)->f) && e->u.info <= ((1 << 8) - 1) &&
			((((&fs->f->k[e->u.info]))->tt_) == (((((4) | ((0) << 4))) | (1 << 6)))));
}

int luaK_isKint(expdesc *e)
{
	return (e->k == VKINT && !((e)->t != (e)->f));
}

static int isCint(expdesc *e)
{
	return luaK_isKint(e) && (((lua_Unsigned) (e->u.ival)) <= ((lua_Unsigned) (((1 << 8) - 1))));
}

static int isSCint(expdesc *e)
{
	return luaK_isKint(e) && fitsC(e->u.ival);
}

static int isSCnumber(expdesc *e, int *pi, int *isfloat)
{
	lua_Integer i;
	if (e->k == VKINT)
		i = e->u.ival;
	else if (e->k == VKFLT && luaV_flttointeger(e->u.nval, &i, F2Ieq))
		*isfloat = 1;
	else
		return 0;
	if (!((e)->t != (e)->f) && fitsC(i))
	{
		*pi = ((((int) ((i)))) + (((1 << 8) - 1) >> 1));
		return 1;
	}
	else
		return 0;
}
void luaK_indexed(FuncState *fs, expdesc *t, expdesc *k)
{
	if (k->k == VKSTR)
		str2K(fs, k);
	((void) 0);

	if (t->k == VUPVAL && !isKstr(fs, k))
		luaK_exp2anyreg(fs, t);
	if (t->k == VUPVAL)
	{
		t->u.ind.t = t->u.info;
		t->u.ind.idx = k->u.info;
		t->k = VINDEXUP;
	}
	else
	{

		t->u.ind.t = (t->k == VLOCAL) ? t->u.var.sidx : t->u.info;
		if (isKstr(fs, k))
		{
			t->u.ind.idx = k->u.info;
			t->k = VINDEXSTR;
		}
		else if (isCint(k))
		{
			t->u.ind.idx = ((int) ((k->u.ival)));
			t->k = VINDEXI;
		}
		else
		{
			t->u.ind.idx = luaK_exp2anyreg(fs, k);
			t->k = VINDEXED;
		}
	}
}

static int validop(int op, TValue *v1, TValue *v2)
{
	switch (op)
	{
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 13:
	{
		lua_Integer i;
		return ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i) = (((v1)->value_).i), 1)
														 : luaV_tointegerns(v1, &i, F2Ieq)) &&
				(((((v2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i) = (((v2)->value_).i), 1)
														 : luaV_tointegerns(v2, &i, F2Ieq)));
	}
	case 5:
	case 6:
	case 3:
		return (((((((v2))->tt_) == (((3) | ((0) << 4)))) ? ((lua_Number) (((((v2)->value_).i))))
														  : (((v2)->value_).n))) != 0);
	default:
		return 1;
	}
}

static int constfolding(FuncState *fs, int op, expdesc *e1, const expdesc *e2)
{
	TValue v1, v2, res;
	if (!tonumeral(e1, &v1) || !tonumeral(e2, &v2) || !validop(op, &v1, &v2))
		return 0;
	luaO_rawarith(fs->ls->L, op, &v1, &v2, &res);
	if (((((&res))->tt_) == (((3) | ((0) << 4)))))
	{
		e1->k = VKINT;
		e1->u.ival = (((&res)->value_).i);
	}
	else
	{
		lua_Number n = (((&res)->value_).n);
		if ((!(((n)) == ((n)))) || n == 0)
			return 0;
		e1->k = VKFLT;
		e1->u.nval = n;
	}
	return 1;
}

static void codeunexpval(FuncState *fs, OpCode op, expdesc *e, int line)
{
	int r = luaK_exp2anyreg(fs, e);
	freeexp(fs, e);
	e->u.info = luaK_codeABCk(fs, op, 0, r, 0, 0);
	e->k = VRELOC;
	luaK_fixline(fs, line);
}
static void finishbinexpval(FuncState *fs, expdesc *e1, expdesc *e2, OpCode op, int v2, int flip,
							int line, OpCode mmop, TMS event)
{
	int v1 = luaK_exp2anyreg(fs, e1);
	int pc = luaK_codeABCk(fs, op, 0, v1, v2, 0);
	freeexps(fs, e1, e2);
	e1->u.info = pc;
	e1->k = VRELOC;
	luaK_fixline(fs, line);
	luaK_codeABCk(fs, mmop, v1, v2, event, flip);
	luaK_fixline(fs, line);
}

static void codebinexpval(FuncState *fs, OpCode op, expdesc *e1, expdesc *e2, int line)
{
	int v2 = luaK_exp2anyreg(fs, e2);
	((void) 0);
	finishbinexpval(fs, e1, e2, op, v2, 0, line, OP_MMBIN, ((TMS) ((op - OP_ADD) + TM_ADD)));
}

static void codebini(FuncState *fs, OpCode op, expdesc *e1, expdesc *e2, int flip, int line,
					 TMS event)
{
	int v2 = ((((int) ((e2->u.ival)))) + (((1 << 8) - 1) >> 1));
	((void) 0);
	finishbinexpval(fs, e1, e2, op, v2, flip, line, OP_MMBINI, event);
}

static int finishbinexpneg(FuncState *fs, expdesc *e1, expdesc *e2, OpCode op, int line, TMS event)
{
	if (!luaK_isKint(e2))
		return 0;
	else
	{
		lua_Integer i2 = e2->u.ival;
		if (!(fitsC(i2) && fitsC(-i2)))
			return 0;
		else
		{
			int v2 = ((int) ((i2)));
			finishbinexpval(fs, e1, e2, op, ((-v2) + (((1 << 8) - 1) >> 1)), 0, line, OP_MMBINI,
							event);

			((fs->f->code[fs->pc - 1]) =
				 (((fs->f->code[fs->pc - 1]) &
				   (~((~((~(Instruction) 0) << (8))) << ((((0 + 7) + 8) + 1))))) |
				  ((((Instruction) (((v2) + (((1 << 8) - 1) >> 1)))) << (((0 + 7) + 8) + 1)) &
				   ((~((~(Instruction) 0) << (8))) << ((((0 + 7) + 8) + 1))))));
			return 1;
		}
	}
}

static void swapexps(expdesc *e1, expdesc *e2)
{
	expdesc temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

static void codearith(FuncState *fs, BinOpr opr, expdesc *e1, expdesc *e2, int flip, int line)
{
	TMS event = ((TMS) (opr + TM_ADD));
	if (tonumeral(e2, NULL) && luaK_exp2K(fs, e2))
	{
		int v2 = e2->u.info;
		OpCode op = ((OpCode) (opr + OP_ADDK));
		finishbinexpval(fs, e1, e2, op, v2, flip, line, OP_MMBINK, event);
	}
	else
	{
		OpCode op = ((OpCode) (opr + OP_ADD));
		if (flip)
			swapexps(e1, e2);
		codebinexpval(fs, op, e1, e2, line);
	}
}

static void codecommutative(FuncState *fs, BinOpr op, expdesc *e1, expdesc *e2, int line)
{
	int flip = 0;
	if (tonumeral(e1, NULL))
	{
		swapexps(e1, e2);
		flip = 1;
	}
	if (op == OPR_ADD && isSCint(e2))
		codebini(fs, ((OpCode) (OP_ADDI)), e1, e2, flip, line, TM_ADD);
	else
		codearith(fs, op, e1, e2, flip, line);
}

static void codebitwise(FuncState *fs, BinOpr opr, expdesc *e1, expdesc *e2, int line)
{
	int flip = 0;
	int v2;
	OpCode op;
	if (e1->k == VKINT && luaK_exp2RK(fs, e1))
	{
		swapexps(e1, e2);
		flip = 1;
	}
	else if (!(e2->k == VKINT && luaK_exp2RK(fs, e2)))
	{
		op = ((OpCode) (opr + OP_ADD));
		codebinexpval(fs, op, e1, e2, line);
		return;
	}
	v2 = e2->u.info;
	op = ((OpCode) (opr + OP_ADDK));
	((void) 0);
	finishbinexpval(fs, e1, e2, op, v2, flip, line, OP_MMBINK, ((TMS) (opr + TM_ADD)));
}

static void codeorder(FuncState *fs, OpCode op, expdesc *e1, expdesc *e2)
{
	int r1, r2;
	int im;
	int isfloat = 0;
	if (isSCnumber(e2, &im, &isfloat))
	{

		r1 = luaK_exp2anyreg(fs, e1);
		r2 = im;
		op = ((OpCode) ((op - OP_LT) + OP_LTI));
	}
	else if (isSCnumber(e1, &im, &isfloat))
	{

		r1 = luaK_exp2anyreg(fs, e2);
		r2 = im;
		op = (op == OP_LT) ? OP_GTI : OP_GEI;
	}
	else
	{
		r1 = luaK_exp2anyreg(fs, e1);
		r2 = luaK_exp2anyreg(fs, e2);
	}
	freeexps(fs, e1, e2);
	e1->u.info = condjump(fs, op, r1, r2, isfloat, 1);
	e1->k = VJMP;
}

static void codeeq(FuncState *fs, BinOpr opr, expdesc *e1, expdesc *e2)
{
	int r1, r2;
	int im;
	int isfloat = 0;
	OpCode op;
	if (e1->k != VNONRELOC)
	{
		((void) 0);
		swapexps(e1, e2);
	}
	r1 = luaK_exp2anyreg(fs, e1);
	if (isSCnumber(e2, &im, &isfloat))
	{
		op = OP_EQI;
		r2 = im;
	}
	else if (luaK_exp2RK(fs, e2))
	{
		op = OP_EQK;
		r2 = e2->u.info;
	}
	else
	{
		op = OP_EQ;
		r2 = luaK_exp2anyreg(fs, e2);
	}
	freeexps(fs, e1, e2);
	e1->u.info = condjump(fs, op, r1, r2, isfloat, (opr == OPR_EQ));
	e1->k = VJMP;
}

void luaK_prefix(FuncState *fs, UnOpr op, expdesc *e, int line)
{
	static const expdesc ef = {VKINT, {0}, (-1), (-1)};
	luaK_dischargevars(fs, e);
	switch (op)
	{
	case OPR_MINUS:
	case OPR_BNOT:
		if (constfolding(fs, op + 12, e, &ef))
			break;

	case OPR_LEN:
		codeunexpval(fs, ((OpCode) (op + OP_UNM)), e, line);
		break;
	case OPR_NOT:
		codenot(fs, e);
		break;
	default:
		((void) 0);
	}
}

void luaK_infix(FuncState *fs, BinOpr op, expdesc *v)
{
	luaK_dischargevars(fs, v);
	switch (op)
	{
	case OPR_AND:
	{
		luaK_goiftrue(fs, v);
		break;
	}
	case OPR_OR:
	{
		luaK_goiffalse(fs, v);
		break;
	}
	case OPR_CONCAT:
	{
		luaK_exp2nextreg(fs, v);
		break;
	}
	case OPR_ADD:
	case OPR_SUB:
	case OPR_MUL:
	case OPR_DIV:
	case OPR_IDIV:
	case OPR_MOD:
	case OPR_POW:
	case OPR_BAND:
	case OPR_BOR:
	case OPR_BXOR:
	case OPR_SHL:
	case OPR_SHR:
	{
		if (!tonumeral(v, NULL))
			luaK_exp2anyreg(fs, v);

		break;
	}
	case OPR_EQ:
	case OPR_NE:
	{
		if (!tonumeral(v, NULL))
			luaK_exp2RK(fs, v);

		break;
	}
	case OPR_LT:
	case OPR_LE:
	case OPR_GT:
	case OPR_GE:
	{
		int dummy, dummy2;
		if (!isSCnumber(v, &dummy, &dummy2))
			luaK_exp2anyreg(fs, v);

		break;
	}
	default:
		((void) 0);
	}
}

static void codeconcat(FuncState *fs, expdesc *e1, expdesc *e2, int line)
{
	Instruction *ie2 = previousinstruction(fs);
	if ((((OpCode) (((*ie2) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))) == OP_CONCAT)
	{
		int n = ((((
			int) ((((*ie2) >> ((((0 + 7) + 8) + 1))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
		((void) 0);
		freeexp(fs, e2);
		((*ie2) = (((*ie2) & (~((~((~(Instruction) 0) << (8))) << ((0 + 7))))) |
				   ((((Instruction) (e1->u.info)) << (0 + 7)) &
					((~((~(Instruction) 0) << (8))) << ((0 + 7))))));
		((*ie2) = (((*ie2) & (~((~((~(Instruction) 0) << (8))) << ((((0 + 7) + 8) + 1))))) |
				   ((((Instruction) (n + 1)) << (((0 + 7) + 8) + 1)) &
					((~((~(Instruction) 0) << (8))) << ((((0 + 7) + 8) + 1))))));
	}
	else
	{
		luaK_codeABCk(fs, OP_CONCAT, e1->u.info, 2, 0, 0);
		freeexp(fs, e2);
		luaK_fixline(fs, line);
	}
}

void luaK_posfix(FuncState *fs, BinOpr opr, expdesc *e1, expdesc *e2, int line)
{
	luaK_dischargevars(fs, e2);
	if (((opr) <= OPR_SHR) && constfolding(fs, opr + 0, e1, e2))
		return;
	switch (opr)
	{
	case OPR_AND:
	{
		((void) 0);
		luaK_concat(fs, &e2->f, e1->f);
		*e1 = *e2;
		break;
	}
	case OPR_OR:
	{
		((void) 0);
		luaK_concat(fs, &e2->t, e1->t);
		*e1 = *e2;
		break;
	}
	case OPR_CONCAT:
	{
		luaK_exp2nextreg(fs, e2);
		codeconcat(fs, e1, e2, line);
		break;
	}
	case OPR_ADD:
	case OPR_MUL:
	{
		codecommutative(fs, opr, e1, e2, line);
		break;
	}
	case OPR_SUB:
	{
		if (finishbinexpneg(fs, e1, e2, OP_ADDI, line, TM_SUB))
			break;
	}
	case OPR_DIV:
	case OPR_IDIV:
	case OPR_MOD:
	case OPR_POW:
	{
		codearith(fs, opr, e1, e2, 0, line);
		break;
	}
	case OPR_BAND:
	case OPR_BOR:
	case OPR_BXOR:
	{
		codebitwise(fs, opr, e1, e2, line);
		break;
	}
	case OPR_SHL:
	{
		if (isSCint(e1))
		{
			swapexps(e1, e2);
			codebini(fs, OP_SHLI, e1, e2, 1, line, TM_SHL);
		}
		else if (finishbinexpneg(fs, e1, e2, OP_SHRI, line, TM_SHL))
		{
			;
		}
		else
			codebinexpval(fs, OP_SHL, e1, e2, line);
		break;
	}
	case OPR_SHR:
	{
		if (isSCint(e2))
			codebini(fs, OP_SHRI, e1, e2, 0, line, TM_SHR);
		else
			codebinexpval(fs, OP_SHR, e1, e2, line);
		break;
	}
	case OPR_EQ:
	case OPR_NE:
	{
		codeeq(fs, opr, e1, e2);
		break;
	}
	case OPR_LT:
	case OPR_LE:
	{
		OpCode op = ((OpCode) ((opr - OPR_EQ) + OP_EQ));
		codeorder(fs, op, e1, e2);
		break;
	}
	case OPR_GT:
	case OPR_GE:
	{

		OpCode op = ((OpCode) ((opr - OPR_NE) + OP_EQ));
		swapexps(e1, e2);
		codeorder(fs, op, e1, e2);
		break;
	}
	default:
		((void) 0);
	}
}

void luaK_fixline(FuncState *fs, int line)
{
	removelastlineinfo(fs);
	savelineinfo(fs, fs->f, line);
}

void luaK_settablesize(FuncState *fs, int pc, int ra, int asize, int hsize)
{
	Instruction *inst = &fs->f->code[pc];
	int rb = (hsize != 0) ? luaO_ceillog2(hsize) + 1 : 0;
	int extra = asize / (((1 << 8) - 1) + 1);
	int rc = asize % (((1 << 8) - 1) + 1);
	int k = (extra > 0);
	*inst = ((((Instruction) (OP_NEWTABLE)) << 0) | (((Instruction) (ra)) << (0 + 7)) |
			 (((Instruction) (rb)) << (((0 + 7) + 8) + 1)) |
			 (((Instruction) (rc)) << ((((0 + 7) + 8) + 1) + 8)) |
			 (((Instruction) (k)) << ((0 + 7) + 8)));
	*(inst + 1) = ((((Instruction) (OP_EXTRAARG)) << 0) | (((Instruction) (extra)) << (0 + 7)));
}
void luaK_setlist(FuncState *fs, int base, int nelems, int tostore)
{
	((void) 0);
	if (tostore == (-1))
		tostore = 0;
	if (nelems <= ((1 << 8) - 1))
		luaK_codeABCk(fs, OP_SETLIST, base, tostore, nelems, 0);
	else
	{
		int extra = nelems / (((1 << 8) - 1) + 1);
		nelems %= (((1 << 8) - 1) + 1);
		luaK_codeABCk(fs, OP_SETLIST, base, tostore, nelems, 1);
		codeextraarg(fs, extra);
	}
	fs->freereg = base + 1;
}

static int finaltarget(Instruction *code, int i)
{
	int count;
	for (count = 0; count < 100; count++)
	{
		Instruction pc = code[i];
		if ((((OpCode) (((pc) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))) != OP_JMP)
			break;
		else
			i += ((((int) ((((pc) >> ((0 + 7))) &
							((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
				  (INT_MAX >> 1)) +
				 1;
	}
	return i;
}

void luaK_finish(FuncState *fs)
{
	int i;
	Proto *p = fs->f;
	for (i = 0; i < fs->pc; i++)
	{
		Instruction *pc = &p->code[i];
		((void) 0);
		switch ((((OpCode) (((*pc) >> 0) & ((~((~(Instruction) 0) << (7))) << (0))))))
		{
		case OP_RETURN0:
		case OP_RETURN1:
		{
			if (!(fs->needclose || p->is_vararg))
				break;

			((*pc) =
				 (((*pc) & (~((~((~(Instruction) 0) << (7))) << (0)))) |
				  ((((Instruction) (OP_RETURN)) << 0) & ((~((~(Instruction) 0) << (7))) << (0)))));
		}
		case OP_RETURN:
		case OP_TAILCALL:
		{
			if (fs->needclose)
				((*pc) = (((*pc) & (~((~((~(Instruction) 0) << (1))) << (((0 + 7) + 8))))) |
						  ((((Instruction) (1)) << ((0 + 7) + 8)) &
						   ((~((~(Instruction) 0) << (1))) << (((0 + 7) + 8))))));
			if (p->is_vararg)
				((*pc) =
					 (((*pc) & (~((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))) |
					  ((((Instruction) (p->numparams + 1)) << ((((0 + 7) + 8) + 1) + 8)) &
					   ((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))));
			break;
		}
		case OP_JMP:
		{
			int target = finaltarget(p->code, i);
			fixjump(fs, i, target);
			break;
		}
		default:
			break;
		}
	}
}
