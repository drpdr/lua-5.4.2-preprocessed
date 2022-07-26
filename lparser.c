

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
__attribute__((visibility("internal"))) extern Proto *luaF_newproto(lua_State *L);
__attribute__((visibility("internal"))) extern CClosure *luaF_newCclosure(lua_State *L,
																		  int nupvals);
__attribute__((visibility("internal"))) extern LClosure *luaF_newLclosure(lua_State *L,
																		  int nupvals);
__attribute__((visibility("internal"))) extern void luaF_initupvals(lua_State *L, LClosure *cl);
__attribute__((visibility("internal"))) extern UpVal *luaF_findupval(lua_State *L, StkId level);
__attribute__((visibility("internal"))) extern void luaF_newtbcupval(lua_State *L, StkId level);
__attribute__((visibility("internal"))) extern int luaF_close(lua_State *L, StkId level,
															  int status);
__attribute__((visibility("internal"))) extern void luaF_unlinkupval(UpVal *uv);
__attribute__((visibility("internal"))) extern void luaF_freeproto(lua_State *L, Proto *f);
__attribute__((visibility("internal"))) extern const char *
luaF_getlocalname(const Proto *func, int local_number, int pc);

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
typedef struct BlockCnt
{
	struct BlockCnt *previous;
	int firstlabel;
	int firstgoto;
	lu_byte nactvar;
	lu_byte upval;
	lu_byte isloop;
	lu_byte insidetbc;
} BlockCnt;

static void statement(LexState *ls);
static void expr(LexState *ls, expdesc *v);

static void __attribute__((noreturn)) error_expected(LexState *ls, int token)
{
	luaX_syntaxerror(ls, luaO_pushfstring(ls->L, "%s expected", luaX_token2str(ls, token)));
}

static void __attribute__((noreturn)) errorlimit(FuncState *fs, int limit, const char *what)
{
	lua_State *L = fs->ls->L;
	const char *msg;
	int line = fs->f->linedefined;
	const char *where =
		(line == 0) ? "main function" : luaO_pushfstring(L, "function at line %d", line);
	msg = luaO_pushfstring(L, "too many %s (limit is %d) in %s", what, limit, where);
	luaX_syntaxerror(fs->ls, msg);
}

static void checklimit(FuncState *fs, int v, int l, const char *what)
{
	if (v > l)
		errorlimit(fs, l, what);
}

static int testnext(LexState *ls, int c)
{
	if (ls->t.token == c)
	{
		luaX_next(ls);
		return 1;
	}
	else
		return 0;
}

static void check(LexState *ls, int c)
{
	if (ls->t.token != c)
		error_expected(ls, c);
}

static void checknext(LexState *ls, int c)
{
	check(ls, c);
	luaX_next(ls);
}
static void check_match(LexState *ls, int what, int who, int where)
{
	if ((__builtin_expect(((!testnext(ls, what)) != 0), 0)))
	{
		if (where == ls->linenumber)
			error_expected(ls, what);
		else
		{
			luaX_syntaxerror(ls, luaO_pushfstring(ls->L, "%s expected (to close %s at line %d)",
												  luaX_token2str(ls, what), luaX_token2str(ls, who),
												  where));
		}
	}
}

static TString *str_checkname(LexState *ls)
{
	TString *ts;
	check(ls, TK_NAME);
	ts = ls->t.seminfo.ts;
	luaX_next(ls);
	return ts;
}

static void init_exp(expdesc *e, expkind k, int i)
{
	e->f = e->t = (-1);
	e->k = k;
	e->u.info = i;
}

static void codestring(expdesc *e, TString *s)
{
	e->f = e->t = (-1);
	e->k = VKSTR;
	e->u.strval = s;
}

static void codename(LexState *ls, expdesc *e)
{
	codestring(e, str_checkname(ls));
}

static int registerlocalvar(LexState *ls, FuncState *fs, TString *varname)
{
	Proto *f = fs->f;
	int oldsize = f->sizelocvars;
	((f->locvars) = ((LocVar *) (luaM_growaux_(
		 ls->L, f->locvars, fs->ndebugvars, &(f->sizelocvars), sizeof(LocVar),
		 ((((size_t) ((SHRT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(LocVar))
			  ? (SHRT_MAX)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(LocVar)))))),
		 "local variables"))));

	while (oldsize < f->sizelocvars)
		f->locvars[oldsize++].varname = NULL;
	f->locvars[fs->ndebugvars].varname = varname;
	f->locvars[fs->ndebugvars].startpc = fs->pc;
	(((((f)->marked) & ((1 << (5)))) && (((varname)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(ls->L, (&(((union GCUnion *) ((f)))->gc)),
						 (&(((union GCUnion *) ((varname)))->gc)))
		 : ((void) ((0))));
	return fs->ndebugvars++;
}

static int new_localvar(LexState *ls, TString *name)
{
	lua_State *L = ls->L;
	FuncState *fs = ls->fs;
	Dyndata *dyd = ls->dyd;
	Vardesc *var;
	checklimit(fs, dyd->actvar.n + 1 - fs->firstlocal, 200, "local variables");
	((dyd->actvar.arr) = ((Vardesc *) (luaM_growaux_(
		 L, dyd->actvar.arr, dyd->actvar.n + 1, &(dyd->actvar.size), sizeof(Vardesc),
		 ((((size_t) ((USHRT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(Vardesc))
			  ? (USHRT_MAX)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(Vardesc)))))),
		 "local variables"))));

	var = &dyd->actvar.arr[dyd->actvar.n++];
	var->vd.kind = 0;
	var->vd.name = name;
	return dyd->actvar.n - 1 - fs->firstlocal;
}
static Vardesc *getlocalvardesc(FuncState *fs, int vidx)
{
	return &fs->ls->dyd->actvar.arr[fs->firstlocal + vidx];
}
static int stacklevel(FuncState *fs, int nvar)
{
	while (nvar-- > 0)
	{
		Vardesc *vd = getlocalvardesc(fs, nvar);
		if (vd->vd.kind != 3)
			return vd->vd.sidx + 1;
	}
	return 0;
}

int luaY_nvarstack(FuncState *fs)
{
	return stacklevel(fs, fs->nactvar);
}

static LocVar *localdebuginfo(FuncState *fs, int vidx)
{
	Vardesc *vd = getlocalvardesc(fs, vidx);
	if (vd->vd.kind == 3)
		return NULL;
	else
	{
		int idx = vd->vd.pidx;
		((void) 0);
		return &fs->f->locvars[idx];
	}
}

static void init_var(FuncState *fs, expdesc *e, int vidx)
{
	e->f = e->t = (-1);
	e->k = VLOCAL;
	e->u.var.vidx = vidx;
	e->u.var.sidx = getlocalvardesc(fs, vidx)->vd.sidx;
}

static void check_readonly(LexState *ls, expdesc *e)
{
	FuncState *fs = ls->fs;
	TString *varname = NULL;
	switch (e->k)
	{
	case VCONST:
	{
		varname = ls->dyd->actvar.arr[e->u.info].vd.name;
		break;
	}
	case VLOCAL:
	{
		Vardesc *vardesc = getlocalvardesc(fs, e->u.var.vidx);
		if (vardesc->vd.kind != 0)
			varname = vardesc->vd.name;
		break;
	}
	case VUPVAL:
	{
		Upvaldesc *up = &fs->f->upvalues[e->u.info];
		if (up->kind != 0)
			varname = up->name;
		break;
	}
	default:
		return;
	}
	if (varname)
	{
		const char *msg = luaO_pushfstring(ls->L, "attempt to assign to const variable '%s'",
										   ((varname)->contents));
		luaK_semerror(ls, msg);
	}
}

static void adjustlocalvars(LexState *ls, int nvars)
{
	FuncState *fs = ls->fs;
	int stklevel = luaY_nvarstack(fs);
	int i;
	for (i = 0; i < nvars; i++)
	{
		int vidx = fs->nactvar++;
		Vardesc *var = getlocalvardesc(fs, vidx);
		var->vd.sidx = stklevel++;
		var->vd.pidx = registerlocalvar(ls, fs, var->vd.name);
	}
}

static void removevars(FuncState *fs, int tolevel)
{
	fs->ls->dyd->actvar.n -= (fs->nactvar - tolevel);
	while (fs->nactvar > tolevel)
	{
		LocVar *var = localdebuginfo(fs, --fs->nactvar);
		if (var)
			var->endpc = fs->pc;
	}
}

static int searchupvalue(FuncState *fs, TString *name)
{
	int i;
	Upvaldesc *up = fs->f->upvalues;
	for (i = 0; i < fs->nups; i++)
	{
		if (((up[i].name) == (name)))
			return i;
	}
	return -1;
}

static Upvaldesc *allocupvalue(FuncState *fs)
{
	Proto *f = fs->f;
	int oldsize = f->sizeupvalues;
	checklimit(fs, fs->nups + 1, 255, "upvalues");
	((f->upvalues) = ((Upvaldesc *) (luaM_growaux_(
		 fs->ls->L, f->upvalues, fs->nups, &(f->sizeupvalues), sizeof(Upvaldesc),
		 ((((size_t) ((255))) <= ((size_t) (~(size_t) 0)) / sizeof(Upvaldesc))
			  ? (255)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(Upvaldesc)))))),
		 "upvalues"))));

	while (oldsize < f->sizeupvalues)
		f->upvalues[oldsize++].name = NULL;
	return &f->upvalues[fs->nups++];
}

static int newupvalue(FuncState *fs, TString *name, expdesc *v)
{
	Upvaldesc *up = allocupvalue(fs);
	FuncState *prev = fs->prev;
	if (v->k == VLOCAL)
	{
		up->instack = 1;
		up->idx = v->u.var.sidx;
		up->kind = getlocalvardesc(prev, v->u.var.vidx)->vd.kind;
		((void) 0);
	}
	else
	{
		up->instack = 0;
		up->idx = ((lu_byte) ((v->u.info)));
		up->kind = prev->f->upvalues[v->u.info].kind;
		((void) 0);
	}
	up->name = name;
	(((((fs->f)->marked) & ((1 << (5)))) && (((name)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(fs->ls->L, (&(((union GCUnion *) ((fs->f)))->gc)),
						 (&(((union GCUnion *) ((name)))->gc)))
		 : ((void) ((0))));
	return fs->nups - 1;
}

static int searchvar(FuncState *fs, TString *n, expdesc *var)
{
	int i;
	for (i = ((int) ((fs->nactvar))) - 1; i >= 0; i--)
	{
		Vardesc *vd = getlocalvardesc(fs, i);
		if (((n) == (vd->vd.name)))
		{
			if (vd->vd.kind == 3)
				init_exp(var, VCONST, fs->firstlocal + i);
			else
				init_var(fs, var, i);
			return var->k;
		}
	}
	return -1;
}

static void markupval(FuncState *fs, int level)
{
	BlockCnt *bl = fs->bl;
	while (bl->nactvar > level)
		bl = bl->previous;
	bl->upval = 1;
	fs->needclose = 1;
}

static void singlevaraux(FuncState *fs, TString *n, expdesc *var, int base)
{
	if (fs == NULL)
		init_exp(var, VVOID, 0);
	else
	{
		int v = searchvar(fs, n, var);
		if (v >= 0)
		{
			if (v == VLOCAL && !base)
				markupval(fs, var->u.var.vidx);
		}
		else
		{
			int idx = searchupvalue(fs, n);
			if (idx < 0)
			{
				singlevaraux(fs->prev, n, var, 0);
				if (var->k == VLOCAL || var->k == VUPVAL)
					idx = newupvalue(fs, n, var);
				else
					return;
			}
			init_exp(var, VUPVAL, idx);
		}
	}
}

static void singlevar(LexState *ls, expdesc *var)
{
	TString *varname = str_checkname(ls);
	FuncState *fs = ls->fs;
	singlevaraux(fs, varname, var, 1);
	if (var->k == VVOID)
	{
		expdesc key;
		singlevaraux(fs, ls->envn, var, 1);
		((void) 0);
		codestring(&key, varname);
		luaK_indexed(fs, var, &key);
	}
}

static void adjust_assign(LexState *ls, int nvars, int nexps, expdesc *e)
{
	FuncState *fs = ls->fs;
	int needed = nvars - nexps;
	if (((e->k) == VCALL || (e->k) == VVARARG))
	{
		int extra = needed + 1;
		if (extra < 0)
			extra = 0;
		luaK_setreturns(fs, e, extra);
	}
	else
	{
		if (e->k != VVOID)
			luaK_exp2nextreg(fs, e);
		if (needed > 0)
			luaK_nil(fs, fs->freereg, needed);
	}
	if (needed > 0)
		luaK_reserveregs(fs, needed);
	else
		fs->freereg += needed;
}
static void __attribute__((noreturn)) jumpscopeerror(LexState *ls, Labeldesc *gt)
{
	const char *varname = ((getlocalvardesc(ls->fs, gt->nactvar)->vd.name)->contents);
	const char *msg = "<goto %s> at line %d jumps into the scope of local '%s'";
	msg = luaO_pushfstring(ls->L, msg, ((gt->name)->contents), gt->line, varname);
	luaK_semerror(ls, msg);
}

static void solvegoto(LexState *ls, int g, Labeldesc *label)
{
	int i;
	Labellist *gl = &ls->dyd->gt;
	Labeldesc *gt = &gl->arr[g];
	((void) 0);
	if ((__builtin_expect(((gt->nactvar < label->nactvar) != 0), 0)))
		jumpscopeerror(ls, gt);
	luaK_patchlist(ls->fs, gt->pc, label->pc);
	for (i = g; i < gl->n - 1; i++)
		gl->arr[i] = gl->arr[i + 1];
	gl->n--;
}

static Labeldesc *findlabel(LexState *ls, TString *name)
{
	int i;
	Dyndata *dyd = ls->dyd;

	for (i = ls->fs->firstlabel; i < dyd->label.n; i++)
	{
		Labeldesc *lb = &dyd->label.arr[i];
		if (((lb->name) == (name)))
			return lb;
	}
	return NULL;
}

static int newlabelentry(LexState *ls, Labellist *l, TString *name, int line, int pc)
{
	int n = l->n;
	((l->arr) = ((Labeldesc *) (luaM_growaux_(
		 ls->L, l->arr, n, &(l->size), sizeof(Labeldesc),
		 ((((size_t) ((SHRT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(Labeldesc))
			  ? (SHRT_MAX)
			  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(Labeldesc)))))),
		 "labels/gotos"))));

	l->arr[n].name = name;
	l->arr[n].line = line;
	l->arr[n].nactvar = ls->fs->nactvar;
	l->arr[n].close = 0;
	l->arr[n].pc = pc;
	l->n = n + 1;
	return n;
}

static int newgotoentry(LexState *ls, TString *name, int line, int pc)
{
	return newlabelentry(ls, &ls->dyd->gt, name, line, pc);
}

static int solvegotos(LexState *ls, Labeldesc *lb)
{
	Labellist *gl = &ls->dyd->gt;
	int i = ls->fs->bl->firstgoto;
	int needsclose = 0;
	while (i < gl->n)
	{
		if (((gl->arr[i].name) == (lb->name)))
		{
			needsclose |= gl->arr[i].close;
			solvegoto(ls, i, lb);
		}
		else
			i++;
	}
	return needsclose;
}
static int createlabel(LexState *ls, TString *name, int line, int last)
{
	FuncState *fs = ls->fs;
	Labellist *ll = &ls->dyd->label;
	int l = newlabelentry(ls, ll, name, line, luaK_getlabel(fs));
	if (last)
	{

		ll->arr[l].nactvar = fs->bl->nactvar;
	}
	if (solvegotos(ls, &ll->arr[l]))
	{
		luaK_codeABCk(fs, OP_CLOSE, luaY_nvarstack(fs), 0, 0, 0);
		return 1;
	}
	return 0;
}

static void movegotosout(FuncState *fs, BlockCnt *bl)
{
	int i;
	Labellist *gl = &fs->ls->dyd->gt;

	for (i = bl->firstgoto; i < gl->n; i++)
	{
		Labeldesc *gt = &gl->arr[i];

		if (stacklevel(fs, gt->nactvar) > stacklevel(fs, bl->nactvar))
			gt->close |= bl->upval;
		gt->nactvar = bl->nactvar;
	}
}

static void enterblock(FuncState *fs, BlockCnt *bl, lu_byte isloop)
{
	bl->isloop = isloop;
	bl->nactvar = fs->nactvar;
	bl->firstlabel = fs->ls->dyd->label.n;
	bl->firstgoto = fs->ls->dyd->gt.n;
	bl->upval = 0;
	bl->insidetbc = (fs->bl != NULL && fs->bl->insidetbc);
	bl->previous = fs->bl;
	fs->bl = bl;
	((void) 0);
}

static void __attribute__((noreturn)) undefgoto(LexState *ls, Labeldesc *gt)
{
	const char *msg;
	if (((gt->name) == ((luaS_newlstr(ls->L,
									  ""
									  "break",
									  (sizeof("break") / sizeof(char)) - 1)))))
	{
		msg = "break outside loop at line %d";
		msg = luaO_pushfstring(ls->L, msg, gt->line);
	}
	else
	{
		msg = "no visible label '%s' for <goto> at line %d";
		msg = luaO_pushfstring(ls->L, msg, ((gt->name)->contents), gt->line);
	}
	luaK_semerror(ls, msg);
}

static void leaveblock(FuncState *fs)
{
	BlockCnt *bl = fs->bl;
	LexState *ls = fs->ls;
	int hasclose = 0;
	int stklevel = stacklevel(fs, bl->nactvar);
	if (bl->isloop)
		hasclose = createlabel(ls,
							   (luaS_newlstr(ls->L,
											 ""
											 "break",
											 (sizeof("break") / sizeof(char)) - 1)),
							   0, 0);
	if (!hasclose && bl->previous && bl->upval)
		luaK_codeABCk(fs, OP_CLOSE, stklevel, 0, 0, 0);
	fs->bl = bl->previous;
	removevars(fs, bl->nactvar);
	((void) 0);
	fs->freereg = stklevel;
	ls->dyd->label.n = bl->firstlabel;
	if (bl->previous)
		movegotosout(fs, bl);
	else
	{
		if (bl->firstgoto < ls->dyd->gt.n)
			undefgoto(ls, &ls->dyd->gt.arr[bl->firstgoto]);
	}
}

static Proto *addprototype(LexState *ls)
{
	Proto *clp;
	lua_State *L = ls->L;
	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	if (fs->np >= f->sizep)
	{
		int oldsize = f->sizep;
		((f->p) = ((Proto **) (luaM_growaux_(
			 L, f->p, fs->np, &(f->sizep), sizeof(Proto *),
			 ((((size_t) ((INT_MAX))) <= ((size_t) (~(size_t) 0)) / sizeof(Proto *))
				  ? (INT_MAX)
				  : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(Proto *)))))),
			 "functions"))));
		while (oldsize < f->sizep)
			f->p[oldsize++] = NULL;
	}
	f->p[fs->np++] = clp = luaF_newproto(L);
	(((((f)->marked) & ((1 << (5)))) && (((clp)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(L, (&(((union GCUnion *) ((f)))->gc)),
						 (&(((union GCUnion *) ((clp)))->gc)))
		 : ((void) ((0))));
	return clp;
}
static void codeclosure(LexState *ls, expdesc *v)
{
	FuncState *fs = ls->fs->prev;
	init_exp(v, VRELOC, luaK_codeABx(fs, OP_CLOSURE, 0, fs->np - 1));
	luaK_exp2nextreg(fs, v);
}

static void open_func(LexState *ls, FuncState *fs, BlockCnt *bl)
{
	Proto *f = fs->f;
	fs->prev = ls->fs;
	fs->ls = ls;
	ls->fs = fs;
	fs->pc = 0;
	fs->previousline = f->linedefined;
	fs->iwthabs = 0;
	fs->lasttarget = 0;
	fs->freereg = 0;
	fs->nk = 0;
	fs->nabslineinfo = 0;
	fs->np = 0;
	fs->nups = 0;
	fs->ndebugvars = 0;
	fs->nactvar = 0;
	fs->needclose = 0;
	fs->firstlocal = ls->dyd->actvar.n;
	fs->firstlabel = ls->dyd->label.n;
	fs->bl = NULL;
	f->source = ls->source;
	(((((f)->marked) & ((1 << (5)))) && (((f->source)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(ls->L, (&(((union GCUnion *) ((f)))->gc)),
						 (&(((union GCUnion *) ((f->source)))->gc)))
		 : ((void) ((0))));
	f->maxstacksize = 2;
	enterblock(fs, bl, 0);
}

static void close_func(LexState *ls)
{
	lua_State *L = ls->L;
	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	luaK_ret(fs, luaY_nvarstack(fs), 0);
	leaveblock(fs);
	((void) 0);
	luaK_finish(fs);
	((f->code) = ((Instruction *) (luaM_shrinkvector_(L, f->code, &(f->sizecode), fs->pc,
													  sizeof(Instruction)))));
	((f->lineinfo) = ((ls_byte *) (luaM_shrinkvector_(L, f->lineinfo, &(f->sizelineinfo), fs->pc,
													  sizeof(ls_byte)))));
	((f->abslineinfo) = ((AbsLineInfo *) (luaM_shrinkvector_(
		 L, f->abslineinfo, &(f->sizeabslineinfo), fs->nabslineinfo, sizeof(AbsLineInfo)))));

	((f->k) = ((TValue *) (luaM_shrinkvector_(L, f->k, &(f->sizek), fs->nk, sizeof(TValue)))));
	((f->p) = ((Proto **) (luaM_shrinkvector_(L, f->p, &(f->sizep), fs->np, sizeof(Proto *)))));
	((f->locvars) = ((LocVar *) (luaM_shrinkvector_(L, f->locvars, &(f->sizelocvars),
													fs->ndebugvars, sizeof(LocVar)))));
	((f->upvalues) = ((Upvaldesc *) (luaM_shrinkvector_(L, f->upvalues, &(f->sizeupvalues),
														fs->nups, sizeof(Upvaldesc)))));
	ls->fs = fs->prev;
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
}
static int block_follow(LexState *ls, int withuntil)
{
	switch (ls->t.token)
	{
	case TK_ELSE:
	case TK_ELSEIF:
	case TK_END:
	case TK_EOS:
		return 1;
	case TK_UNTIL:
		return withuntil;
	default:
		return 0;
	}
}

static void statlist(LexState *ls)
{

	while (!block_follow(ls, 1))
	{
		if (ls->t.token == TK_RETURN)
		{
			statement(ls);
			return;
		}
		statement(ls);
	}
}

static void fieldsel(LexState *ls, expdesc *v)
{

	FuncState *fs = ls->fs;
	expdesc key;
	luaK_exp2anyregup(fs, v);
	luaX_next(ls);
	codename(ls, &key);
	luaK_indexed(fs, v, &key);
}

static void yindex(LexState *ls, expdesc *v)
{

	luaX_next(ls);
	expr(ls, v);
	luaK_exp2val(ls->fs, v);
	checknext(ls, ']');
}
typedef struct ConsControl
{
	expdesc v;
	expdesc *t;
	int nh;
	int na;
	int tostore;
} ConsControl;

static void recfield(LexState *ls, ConsControl *cc)
{

	FuncState *fs = ls->fs;
	int reg = ls->fs->freereg;
	expdesc tab, key, val;
	if (ls->t.token == TK_NAME)
	{
		checklimit(fs, cc->nh, INT_MAX, "items in a constructor");
		codename(ls, &key);
	}
	else
		yindex(ls, &key);
	cc->nh++;
	checknext(ls, '=');
	tab = *cc->t;
	luaK_indexed(fs, &tab, &key);
	expr(ls, &val);
	luaK_storevar(fs, &tab, &val);
	fs->freereg = reg;
}

static void closelistfield(FuncState *fs, ConsControl *cc)
{
	if (cc->v.k == VVOID)
		return;
	luaK_exp2nextreg(fs, &cc->v);
	cc->v.k = VVOID;
	if (cc->tostore == 50)
	{
		luaK_setlist(fs, cc->t->u.info, cc->na, cc->tostore);
		cc->na += cc->tostore;
		cc->tostore = 0;
	}
}

static void lastlistfield(FuncState *fs, ConsControl *cc)
{
	if (cc->tostore == 0)
		return;
	if (((cc->v.k) == VCALL || (cc->v.k) == VVARARG))
	{
		luaK_setreturns(fs, &cc->v, (-1));
		luaK_setlist(fs, cc->t->u.info, cc->na, (-1));
		cc->na--;
	}
	else
	{
		if (cc->v.k != VVOID)
			luaK_exp2nextreg(fs, &cc->v);
		luaK_setlist(fs, cc->t->u.info, cc->na, cc->tostore);
	}
	cc->na += cc->tostore;
}

static void listfield(LexState *ls, ConsControl *cc)
{

	expr(ls, &cc->v);
	cc->tostore++;
}

static void field(LexState *ls, ConsControl *cc)
{

	switch (ls->t.token)
	{
	case TK_NAME:
	{
		if (luaX_lookahead(ls) != '=')
			listfield(ls, cc);
		else
			recfield(ls, cc);
		break;
	}
	case '[':
	{
		recfield(ls, cc);
		break;
	}
	default:
	{
		listfield(ls, cc);
		break;
	}
	}
}

static void constructor(LexState *ls, expdesc *t)
{

	FuncState *fs = ls->fs;
	int line = ls->linenumber;
	int pc = luaK_codeABCk(fs, OP_NEWTABLE, 0, 0, 0, 0);
	ConsControl cc;
	luaK_code(fs, 0);
	cc.na = cc.nh = cc.tostore = 0;
	cc.t = t;
	init_exp(t, VNONRELOC, fs->freereg);
	luaK_reserveregs(fs, 1);
	init_exp(&cc.v, VVOID, 0);
	checknext(ls, '{');
	do
	{
		((void) 0);
		if (ls->t.token == '}')
			break;
		closelistfield(fs, &cc);
		field(ls, &cc);
	} while (testnext(ls, ',') || testnext(ls, ';'));
	check_match(ls, '}', '{', line);
	lastlistfield(fs, &cc);
	luaK_settablesize(fs, pc, t->u.info, cc.na, cc.nh);
}

static void setvararg(FuncState *fs, int nparams)
{
	fs->f->is_vararg = 1;
	luaK_codeABCk(fs, OP_VARARGPREP, nparams, 0, 0, 0);
}

static void parlist(LexState *ls)
{

	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	int nparams = 0;
	int isvararg = 0;
	if (ls->t.token != ')')
	{
		do
		{
			switch (ls->t.token)
			{
			case TK_NAME:
			{
				new_localvar(ls, str_checkname(ls));
				nparams++;
				break;
			}
			case TK_DOTS:
			{
				luaX_next(ls);
				isvararg = 1;
				break;
			}
			default:
				luaX_syntaxerror(ls, "<name> or '...' expected");
			}
		} while (!isvararg && testnext(ls, ','));
	}
	adjustlocalvars(ls, nparams);
	f->numparams = ((lu_byte) ((fs->nactvar)));
	if (isvararg)
		setvararg(fs, f->numparams);
	luaK_reserveregs(fs, fs->nactvar);
}

static void body(LexState *ls, expdesc *e, int ismethod, int line)
{

	FuncState new_fs;
	BlockCnt bl;
	new_fs.f = addprototype(ls);
	new_fs.f->linedefined = line;
	open_func(ls, &new_fs, &bl);
	checknext(ls, '(');
	if (ismethod)
	{
		new_localvar(ls, luaX_newstring(ls,
										""
										"self",
										(sizeof("self") / sizeof(char)) - 1));
		;
		adjustlocalvars(ls, 1);
	}
	parlist(ls);
	checknext(ls, ')');
	statlist(ls);
	new_fs.f->lastlinedefined = ls->linenumber;
	check_match(ls, TK_END, TK_FUNCTION, line);
	codeclosure(ls, e);
	close_func(ls);
}

static int explist(LexState *ls, expdesc *v)
{

	int n = 1;
	expr(ls, v);
	while (testnext(ls, ','))
	{
		luaK_exp2nextreg(ls->fs, v);
		expr(ls, v);
		n++;
	}
	return n;
}

static void funcargs(LexState *ls, expdesc *f, int line)
{
	FuncState *fs = ls->fs;
	expdesc args;
	int base, nparams;
	switch (ls->t.token)
	{
	case '(':
	{
		luaX_next(ls);
		if (ls->t.token == ')')
			args.k = VVOID;
		else
		{
			explist(ls, &args);
			if (((args.k) == VCALL || (args.k) == VVARARG))
				luaK_setreturns(fs, &args, (-1));
		}
		check_match(ls, ')', '(', line);
		break;
	}
	case '{':
	{
		constructor(ls, &args);
		break;
	}
	case TK_STRING:
	{
		codestring(&args, ls->t.seminfo.ts);
		luaX_next(ls);
		break;
	}
	default:
	{
		luaX_syntaxerror(ls, "function arguments expected");
	}
	}
	((void) 0);
	base = f->u.info;
	if (((args.k) == VCALL || (args.k) == VVARARG))
		nparams = (-1);
	else
	{
		if (args.k != VVOID)
			luaK_exp2nextreg(fs, &args);
		nparams = fs->freereg - (base + 1);
	}
	init_exp(f, VCALL, luaK_codeABCk(fs, OP_CALL, base, nparams + 1, 2, 0));
	luaK_fixline(fs, line);
	fs->freereg = base + 1;
}
static void primaryexp(LexState *ls, expdesc *v)
{

	switch (ls->t.token)
	{
	case '(':
	{
		int line = ls->linenumber;
		luaX_next(ls);
		expr(ls, v);
		check_match(ls, ')', '(', line);
		luaK_dischargevars(ls->fs, v);
		return;
	}
	case TK_NAME:
	{
		singlevar(ls, v);
		return;
	}
	default:
	{
		luaX_syntaxerror(ls, "unexpected symbol");
	}
	}
}

static void suffixedexp(LexState *ls, expdesc *v)
{

	FuncState *fs = ls->fs;
	int line = ls->linenumber;
	primaryexp(ls, v);
	for (;;)
	{
		switch (ls->t.token)
		{
		case '.':
		{
			fieldsel(ls, v);
			break;
		}
		case '[':
		{
			expdesc key;
			luaK_exp2anyregup(fs, v);
			yindex(ls, &key);
			luaK_indexed(fs, v, &key);
			break;
		}
		case ':':
		{
			expdesc key;
			luaX_next(ls);
			codename(ls, &key);
			luaK_self(fs, v, &key);
			funcargs(ls, v, line);
			break;
		}
		case '(':
		case TK_STRING:
		case '{':
		{
			luaK_exp2nextreg(fs, v);
			funcargs(ls, v, line);
			break;
		}
		default:
			return;
		}
	}
}

static void simpleexp(LexState *ls, expdesc *v)
{

	switch (ls->t.token)
	{
	case TK_FLT:
	{
		init_exp(v, VKFLT, 0);
		v->u.nval = ls->t.seminfo.r;
		break;
	}
	case TK_INT:
	{
		init_exp(v, VKINT, 0);
		v->u.ival = ls->t.seminfo.i;
		break;
	}
	case TK_STRING:
	{
		codestring(v, ls->t.seminfo.ts);
		break;
	}
	case TK_NIL:
	{
		init_exp(v, VNIL, 0);
		break;
	}
	case TK_TRUE:
	{
		init_exp(v, VTRUE, 0);
		break;
	}
	case TK_FALSE:
	{
		init_exp(v, VFALSE, 0);
		break;
	}
	case TK_DOTS:
	{
		FuncState *fs = ls->fs;
		{
			if (!(fs->f->is_vararg))
				luaX_syntaxerror(ls, "cannot use '...' outside a vararg function");
		};

		init_exp(v, VVARARG, luaK_codeABCk(fs, OP_VARARG, 0, 0, 1, 0));
		break;
	}
	case '{':
	{
		constructor(ls, v);
		return;
	}
	case TK_FUNCTION:
	{
		luaX_next(ls);
		body(ls, v, 0, ls->linenumber);
		return;
	}
	default:
	{
		suffixedexp(ls, v);
		return;
	}
	}
	luaX_next(ls);
}

static UnOpr getunopr(int op)
{
	switch (op)
	{
	case TK_NOT:
		return OPR_NOT;
	case '-':
		return OPR_MINUS;
	case '~':
		return OPR_BNOT;
	case '#':
		return OPR_LEN;
	default:
		return OPR_NOUNOPR;
	}
}

static BinOpr getbinopr(int op)
{
	switch (op)
	{
	case '+':
		return OPR_ADD;
	case '-':
		return OPR_SUB;
	case '*':
		return OPR_MUL;
	case '%':
		return OPR_MOD;
	case '^':
		return OPR_POW;
	case '/':
		return OPR_DIV;
	case TK_IDIV:
		return OPR_IDIV;
	case '&':
		return OPR_BAND;
	case '|':
		return OPR_BOR;
	case '~':
		return OPR_BXOR;
	case TK_SHL:
		return OPR_SHL;
	case TK_SHR:
		return OPR_SHR;
	case TK_CONCAT:
		return OPR_CONCAT;
	case TK_NE:
		return OPR_NE;
	case TK_EQ:
		return OPR_EQ;
	case '<':
		return OPR_LT;
	case TK_LE:
		return OPR_LE;
	case '>':
		return OPR_GT;
	case TK_GE:
		return OPR_GE;
	case TK_AND:
		return OPR_AND;
	case TK_OR:
		return OPR_OR;
	default:
		return OPR_NOBINOPR;
	}
}

static const struct
{
	lu_byte left;
	lu_byte right;
} priority[] = {{10, 10}, {10, 10}, {11, 11}, {11, 11}, {14, 13}, {11, 11}, {11, 11},
				{6, 6},	  {4, 4},	{5, 5},	  {7, 7},	{7, 7},	  {9, 8},	{3, 3},
				{3, 3},	  {3, 3},	{3, 3},	  {3, 3},	{3, 3},	  {2, 2},	{1, 1}};
static BinOpr subexpr(LexState *ls, expdesc *v, int limit)
{
	BinOpr op;
	UnOpr uop;
	luaE_incCstack(ls->L);
	uop = getunopr(ls->t.token);
	if (uop != OPR_NOUNOPR)
	{
		int line = ls->linenumber;
		luaX_next(ls);
		subexpr(ls, v, 12);
		luaK_prefix(ls->fs, uop, v, line);
	}
	else
		simpleexp(ls, v);

	op = getbinopr(ls->t.token);
	while (op != OPR_NOBINOPR && priority[op].left > limit)
	{
		expdesc v2;
		BinOpr nextop;
		int line = ls->linenumber;
		luaX_next(ls);
		luaK_infix(ls->fs, op, v);

		nextop = subexpr(ls, &v2, priority[op].right);
		luaK_posfix(ls->fs, op, v, &v2, line);
		op = nextop;
	}
	((ls)->L->nCcalls--);
	return op;
}

static void expr(LexState *ls, expdesc *v)
{
	subexpr(ls, v, 0);
}
static void block(LexState *ls)
{

	FuncState *fs = ls->fs;
	BlockCnt bl;
	enterblock(fs, &bl, 0);
	statlist(ls);
	leaveblock(fs);
}

struct LHS_assign
{
	struct LHS_assign *prev;
	expdesc v;
};
static void check_conflict(LexState *ls, struct LHS_assign *lh, expdesc *v)
{
	FuncState *fs = ls->fs;
	int extra = fs->freereg;
	int conflict = 0;
	for (; lh; lh = lh->prev)
	{
		if ((VINDEXED <= (lh->v.k) && (lh->v.k) <= VINDEXSTR))
		{
			if (lh->v.k == VINDEXUP)
			{
				if (v->k == VUPVAL && lh->v.u.ind.t == v->u.info)
				{
					conflict = 1;
					lh->v.k = VINDEXSTR;
					lh->v.u.ind.t = extra;
				}
			}
			else
			{
				if (v->k == VLOCAL && lh->v.u.ind.t == v->u.var.sidx)
				{
					conflict = 1;
					lh->v.u.ind.t = extra;
				}

				if (lh->v.k == VINDEXED && v->k == VLOCAL && lh->v.u.ind.idx == v->u.var.sidx)
				{
					conflict = 1;
					lh->v.u.ind.idx = extra;
				}
			}
		}
	}
	if (conflict)
	{

		if (v->k == VLOCAL)
			luaK_codeABCk(fs, OP_MOVE, extra, v->u.var.sidx, 0, 0);
		else
			luaK_codeABCk(fs, OP_GETUPVAL, extra, v->u.info, 0, 0);
		luaK_reserveregs(fs, 1);
	}
}
static void restassign(LexState *ls, struct LHS_assign *lh, int nvars)
{
	expdesc e;
	{
		if (!((VLOCAL <= (lh->v.k) && (lh->v.k) <= VINDEXSTR)))
			luaX_syntaxerror(ls, "syntax error");
	};
	check_readonly(ls, &lh->v);
	if (testnext(ls, ','))
	{
		struct LHS_assign nv;
		nv.prev = lh;
		suffixedexp(ls, &nv.v);
		if (!(VINDEXED <= (nv.v.k) && (nv.v.k) <= VINDEXSTR))
			check_conflict(ls, lh, &nv.v);
		luaE_incCstack(ls->L);
		restassign(ls, &nv, nvars + 1);
		((ls)->L->nCcalls--);
	}
	else
	{
		int nexps;
		checknext(ls, '=');
		nexps = explist(ls, &e);
		if (nexps != nvars)
			adjust_assign(ls, nvars, nexps, &e);
		else
		{
			luaK_setoneret(ls->fs, &e);
			luaK_storevar(ls->fs, &lh->v, &e);
			return;
		}
	}
	init_exp(&e, VNONRELOC, ls->fs->freereg - 1);
	luaK_storevar(ls->fs, &lh->v, &e);
}

static int cond(LexState *ls)
{

	expdesc v;
	expr(ls, &v);
	if (v.k == VNIL)
		v.k = VFALSE;
	luaK_goiftrue(ls->fs, &v);
	return v.f;
}

static void gotostat(LexState *ls)
{
	FuncState *fs = ls->fs;
	int line = ls->linenumber;
	TString *name = str_checkname(ls);
	Labeldesc *lb = findlabel(ls, name);
	if (lb == NULL)

		newgotoentry(ls, name, line, luaK_jump(fs));
	else
	{

		int lblevel = stacklevel(fs, lb->nactvar);
		if (luaY_nvarstack(fs) > lblevel)
			luaK_codeABCk(fs, OP_CLOSE, lblevel, 0, 0, 0);

		luaK_patchlist(fs, luaK_jump(fs), lb->pc);
	}
}

static void breakstat(LexState *ls)
{
	int line = ls->linenumber;
	luaX_next(ls);
	newgotoentry(ls,
				 (luaS_newlstr(ls->L,
							   ""
							   "break",
							   (sizeof("break") / sizeof(char)) - 1)),
				 line, luaK_jump(ls->fs));
}

static void checkrepeated(LexState *ls, TString *name)
{
	Labeldesc *lb = findlabel(ls, name);
	if ((__builtin_expect(((lb != NULL) != 0), 0)))
	{
		const char *msg = "label '%s' already defined on line %d";
		msg = luaO_pushfstring(ls->L, msg, ((name)->contents), lb->line);
		luaK_semerror(ls, msg);
	}
}

static void labelstat(LexState *ls, TString *name, int line)
{

	checknext(ls, TK_DBCOLON);
	while (ls->t.token == ';' || ls->t.token == TK_DBCOLON)
		statement(ls);
	checkrepeated(ls, name);
	createlabel(ls, name, line, block_follow(ls, 0));
}

static void whilestat(LexState *ls, int line)
{

	FuncState *fs = ls->fs;
	int whileinit;
	int condexit;
	BlockCnt bl;
	luaX_next(ls);
	whileinit = luaK_getlabel(fs);
	condexit = cond(ls);
	enterblock(fs, &bl, 1);
	checknext(ls, TK_DO);
	block(ls);
	luaK_patchlist(fs, luaK_jump(fs), whileinit);
	check_match(ls, TK_END, TK_WHILE, line);
	leaveblock(fs);
	luaK_patchtohere(fs, condexit);
}

static void repeatstat(LexState *ls, int line)
{

	int condexit;
	FuncState *fs = ls->fs;
	int repeat_init = luaK_getlabel(fs);
	BlockCnt bl1, bl2;
	enterblock(fs, &bl1, 1);
	enterblock(fs, &bl2, 0);
	luaX_next(ls);
	statlist(ls);
	check_match(ls, TK_UNTIL, TK_REPEAT, line);
	condexit = cond(ls);
	leaveblock(fs);
	if (bl2.upval)
	{
		int exit = luaK_jump(fs);
		luaK_patchtohere(fs, condexit);
		luaK_codeABCk(fs, OP_CLOSE, stacklevel(fs, bl2.nactvar), 0, 0, 0);
		condexit = luaK_jump(fs);
		luaK_patchtohere(fs, exit);
	}
	luaK_patchlist(fs, condexit, repeat_init);
	leaveblock(fs);
}

static void exp1(LexState *ls)
{
	expdesc e;
	expr(ls, &e);
	luaK_exp2nextreg(ls->fs, &e);
	((void) 0);
}

static void fixforjump(FuncState *fs, int pc, int dest, int back)
{
	Instruction *jmp = &fs->f->code[pc];
	int offset = dest - (pc + 1);
	if (back)
		offset = -offset;
	if ((__builtin_expect(((offset > INT_MAX) != 0), 0)))
		luaX_syntaxerror(fs->ls, "control structure too long");
	((*jmp) = (((*jmp) & (~((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (((0 + 7) + 8))))) |
			   ((((Instruction) (offset)) << ((0 + 7) + 8)) &
				((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (((0 + 7) + 8))))));
}

static void forbody(LexState *ls, int base, int line, int nvars, int isgen)
{

	static const OpCode forprep[2] = {OP_FORPREP, OP_TFORPREP};
	static const OpCode forloop[2] = {OP_FORLOOP, OP_TFORLOOP};
	BlockCnt bl;
	FuncState *fs = ls->fs;
	int prep, endfor;
	checknext(ls, TK_DO);
	prep = luaK_codeABx(fs, forprep[isgen], base, 0);
	enterblock(fs, &bl, 0);
	adjustlocalvars(ls, nvars);
	luaK_reserveregs(fs, nvars);
	block(ls);
	leaveblock(fs);
	fixforjump(fs, prep, luaK_getlabel(fs), 0);
	if (isgen)
	{
		luaK_codeABCk(fs, OP_TFORCALL, base, 0, nvars, 0);
		luaK_fixline(fs, line);
	}
	endfor = luaK_codeABx(fs, forloop[isgen], base, 0);
	fixforjump(fs, endfor, prep + 1, 1);
	luaK_fixline(fs, line);
}

static void fornum(LexState *ls, TString *varname, int line)
{

	FuncState *fs = ls->fs;
	int base = fs->freereg;
	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;
	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;
	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;
	new_localvar(ls, varname);
	checknext(ls, '=');
	exp1(ls);
	checknext(ls, ',');
	exp1(ls);
	if (testnext(ls, ','))
		exp1(ls);
	else
	{
		luaK_int(fs, fs->freereg, 1);
		luaK_reserveregs(fs, 1);
	}
	adjustlocalvars(ls, 3);
	forbody(ls, base, line, 1, 0);
}

static void forlist(LexState *ls, TString *indexname)
{

	FuncState *fs = ls->fs;
	expdesc e;
	int nvars = 5;
	int line;
	int base = fs->freereg;

	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;
	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;
	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;
	new_localvar(ls, luaX_newstring(ls,
									""
									"(for state)",
									(sizeof("(for state)") / sizeof(char)) - 1));
	;

	new_localvar(ls, indexname);
	while (testnext(ls, ','))
	{
		new_localvar(ls, str_checkname(ls));
		nvars++;
	}
	checknext(ls, TK_IN);
	line = ls->linenumber;
	adjust_assign(ls, 4, explist(ls, &e), &e);
	adjustlocalvars(ls, 4);
	markupval(fs, fs->nactvar);
	luaK_checkstack(fs, 3);
	forbody(ls, base, line, nvars - 4, 1);
}

static void forstat(LexState *ls, int line)
{

	FuncState *fs = ls->fs;
	TString *varname;
	BlockCnt bl;
	enterblock(fs, &bl, 1);
	luaX_next(ls);
	varname = str_checkname(ls);
	switch (ls->t.token)
	{
	case '=':
		fornum(ls, varname, line);
		break;
	case ',':
	case TK_IN:
		forlist(ls, varname);
		break;
	default:
		luaX_syntaxerror(ls, "'=' or 'in' expected");
	}
	check_match(ls, TK_END, TK_FOR, line);
	leaveblock(fs);
}

static void test_then_block(LexState *ls, int *escapelist)
{

	BlockCnt bl;
	FuncState *fs = ls->fs;
	expdesc v;
	int jf;
	luaX_next(ls);
	expr(ls, &v);
	checknext(ls, TK_THEN);
	if (ls->t.token == TK_BREAK)
	{
		int line = ls->linenumber;
		luaK_goiffalse(ls->fs, &v);
		luaX_next(ls);
		enterblock(fs, &bl, 0);
		newgotoentry(ls,
					 (luaS_newlstr(ls->L,
								   ""
								   "break",
								   (sizeof("break") / sizeof(char)) - 1)),
					 line, v.t);
		while (testnext(ls, ';'))
		{
		}
		if (block_follow(ls, 0))
		{
			leaveblock(fs);
			return;
		}
		else
			jf = luaK_jump(fs);
	}
	else
	{
		luaK_goiftrue(ls->fs, &v);
		enterblock(fs, &bl, 0);
		jf = v.f;
	}
	statlist(ls);
	leaveblock(fs);
	if (ls->t.token == TK_ELSE || ls->t.token == TK_ELSEIF)
		luaK_concat(fs, escapelist, luaK_jump(fs));
	luaK_patchtohere(fs, jf);
}

static void ifstat(LexState *ls, int line)
{

	FuncState *fs = ls->fs;
	int escapelist = (-1);
	test_then_block(ls, &escapelist);
	while (ls->t.token == TK_ELSEIF)
		test_then_block(ls, &escapelist);
	if (testnext(ls, TK_ELSE))
		block(ls);
	check_match(ls, TK_END, TK_IF, line);
	luaK_patchtohere(fs, escapelist);
}

static void localfunc(LexState *ls)
{
	expdesc b;
	FuncState *fs = ls->fs;
	int fvar = fs->nactvar;
	new_localvar(ls, str_checkname(ls));
	adjustlocalvars(ls, 1);
	body(ls, &b, 0, ls->linenumber);

	localdebuginfo(fs, fvar)->startpc = fs->pc;
}

static int getlocalattribute(LexState *ls)
{

	if (testnext(ls, '<'))
	{
		const char *attr = ((str_checkname(ls))->contents);
		checknext(ls, '>');
		if (strcmp(attr, "const") == 0)
			return 1;
		else if (strcmp(attr, "close") == 0)
			return 2;
		else
			luaK_semerror(ls, luaO_pushfstring(ls->L, "unknown attribute '%s'", attr));
	}
	return 0;
}

static void checktoclose(LexState *ls, int level)
{
	if (level != -1)
	{
		FuncState *fs = ls->fs;
		markupval(fs, level + 1);
		fs->bl->insidetbc = 1;
		luaK_codeABCk(fs, OP_TBC, stacklevel(fs, level), 0, 0, 0);
	}
}

static void localstat(LexState *ls)
{

	FuncState *fs = ls->fs;
	int toclose = -1;
	Vardesc *var;
	int vidx, kind;
	int nvars = 0;
	int nexps;
	expdesc e;
	do
	{
		vidx = new_localvar(ls, str_checkname(ls));
		kind = getlocalattribute(ls);
		getlocalvardesc(fs, vidx)->vd.kind = kind;
		if (kind == 2)
		{
			if (toclose != -1)
				luaK_semerror(ls, "multiple to-be-closed variables in local list");
			toclose = fs->nactvar + nvars;
		}
		nvars++;
	} while (testnext(ls, ','));
	if (testnext(ls, '='))
		nexps = explist(ls, &e);
	else
	{
		e.k = VVOID;
		nexps = 0;
	}
	var = getlocalvardesc(fs, vidx);
	if (nvars == nexps && var->vd.kind == 1 && luaK_exp2const(fs, &e, &var->k))
	{
		var->vd.kind = 3;
		adjustlocalvars(ls, nvars - 1);
		fs->nactvar++;
	}
	else
	{
		adjust_assign(ls, nvars, nexps, &e);
		adjustlocalvars(ls, nvars);
	}
	checktoclose(ls, toclose);
}

static int funcname(LexState *ls, expdesc *v)
{

	int ismethod = 0;
	singlevar(ls, v);
	while (ls->t.token == '.')
		fieldsel(ls, v);
	if (ls->t.token == ':')
	{
		ismethod = 1;
		fieldsel(ls, v);
	}
	return ismethod;
}

static void funcstat(LexState *ls, int line)
{

	int ismethod;
	expdesc v, b;
	luaX_next(ls);
	ismethod = funcname(ls, &v);
	body(ls, &b, ismethod, line);
	luaK_storevar(ls->fs, &v, &b);
	luaK_fixline(ls->fs, line);
}

static void exprstat(LexState *ls)
{

	FuncState *fs = ls->fs;
	struct LHS_assign v;
	suffixedexp(ls, &v.v);
	if (ls->t.token == '=' || ls->t.token == ',')
	{
		v.prev = NULL;
		restassign(ls, &v, 1);
	}
	else
	{
		Instruction *inst;
		{
			if (!(v.v.k == VCALL))
				luaX_syntaxerror(ls, "syntax error");
		};
		inst = &((fs)->f->code[(&v.v)->u.info]);
		((*inst) = (((*inst) & (~((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))) |
					((((Instruction) (1)) << ((((0 + 7) + 8) + 1) + 8)) &
					 ((~((~(Instruction) 0) << (8))) << (((((0 + 7) + 8) + 1) + 8))))));
	}
}

static void retstat(LexState *ls)
{

	FuncState *fs = ls->fs;
	expdesc e;
	int nret;
	int first = luaY_nvarstack(fs);
	if (block_follow(ls, 1) || ls->t.token == ';')
		nret = 0;
	else
	{
		nret = explist(ls, &e);
		if (((e.k) == VCALL || (e.k) == VVARARG))
		{
			luaK_setreturns(fs, &e, (-1));
			if (e.k == VCALL && nret == 1 && !fs->bl->insidetbc)
			{
				((((fs)->f->code[(&e)->u.info])) = (((((fs)->f->code[(&e)->u.info])) &
													 (~((~((~(Instruction) 0) << (7))) << (0)))) |
													((((Instruction) (OP_TAILCALL)) << 0) &
													 ((~((~(Instruction) 0) << (7))) << (0)))));
				((void) 0);
			}
			nret = (-1);
		}
		else
		{
			if (nret == 1)
				first = luaK_exp2anyreg(fs, &e);
			else
			{
				luaK_exp2nextreg(fs, &e);
				((void) 0);
			}
		}
	}
	luaK_ret(fs, first, nret);
	testnext(ls, ';');
}

static void statement(LexState *ls)
{
	int line = ls->linenumber;
	luaE_incCstack(ls->L);
	switch (ls->t.token)
	{
	case ';':
	{
		luaX_next(ls);
		break;
	}
	case TK_IF:
	{
		ifstat(ls, line);
		break;
	}
	case TK_WHILE:
	{
		whilestat(ls, line);
		break;
	}
	case TK_DO:
	{
		luaX_next(ls);
		block(ls);
		check_match(ls, TK_END, TK_DO, line);
		break;
	}
	case TK_FOR:
	{
		forstat(ls, line);
		break;
	}
	case TK_REPEAT:
	{
		repeatstat(ls, line);
		break;
	}
	case TK_FUNCTION:
	{
		funcstat(ls, line);
		break;
	}
	case TK_LOCAL:
	{
		luaX_next(ls);
		if (testnext(ls, TK_FUNCTION))
			localfunc(ls);
		else
			localstat(ls);
		break;
	}
	case TK_DBCOLON:
	{
		luaX_next(ls);
		labelstat(ls, str_checkname(ls), line);
		break;
	}
	case TK_RETURN:
	{
		luaX_next(ls);
		retstat(ls);
		break;
	}
	case TK_BREAK:
	{
		breakstat(ls);
		break;
	}
	case TK_GOTO:
	{
		luaX_next(ls);
		gotostat(ls);
		break;
	}
	default:
	{
		exprstat(ls);
		break;
	}
	}
	((void) 0);

	ls->fs->freereg = luaY_nvarstack(ls->fs);
	((ls)->L->nCcalls--);
}
static void mainfunc(LexState *ls, FuncState *fs)
{
	BlockCnt bl;
	Upvaldesc *env;
	open_func(ls, fs, &bl);
	setvararg(fs, 0);
	env = allocupvalue(fs);
	env->instack = 1;
	env->idx = 0;
	env->kind = 0;
	env->name = ls->envn;
	(((((fs->f)->marked) & ((1 << (5)))) && (((env->name)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(ls->L, (&(((union GCUnion *) ((fs->f)))->gc)),
						 (&(((union GCUnion *) ((env->name)))->gc)))
		 : ((void) ((0))));
	luaX_next(ls);
	statlist(ls);
	check(ls, TK_EOS);
	close_func(ls);
}

LClosure *luaY_parser(lua_State *L, ZIO *z, Mbuffer *buff, Dyndata *dyd, const char *name,
					  int firstchar)
{
	LexState lexstate;
	FuncState funcstate;
	LClosure *cl = luaF_newLclosure(L, 1);
	{
		TValue *io = ((&(L->top)->val));
		LClosure *x_ = (cl);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((6) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	luaD_inctop(L);
	lexstate.h = luaH_new(L);
	{
		TValue *io = ((&(L->top)->val));
		Table *x_ = (lexstate.h);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	luaD_inctop(L);
	funcstate.f = cl->p = luaF_newproto(L);
	(((((cl)->marked) & ((1 << (5)))) && (((cl->p)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(L, (&(((union GCUnion *) ((cl)))->gc)),
						 (&(((union GCUnion *) ((cl->p)))->gc)))
		 : ((void) ((0))));
	funcstate.f->source = luaS_new(L, name);
	(((((funcstate.f)->marked) & ((1 << (5)))) &&
	  (((funcstate.f->source)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(L, (&(((union GCUnion *) ((funcstate.f)))->gc)),
						 (&(((union GCUnion *) ((funcstate.f->source)))->gc)))
		 : ((void) ((0))));
	lexstate.buff = buff;
	lexstate.dyd = dyd;
	dyd->actvar.n = dyd->gt.n = dyd->label.n = 0;
	luaX_setinput(L, &lexstate, z, funcstate.f->source, firstchar);
	mainfunc(&lexstate, &funcstate);
	((void) 0);

	((void) 0);
	L->top--;
	return cl;
}
