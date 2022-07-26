

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

__attribute__((visibility("internal"))) extern LClosure *luaU_undump(lua_State *L, ZIO *Z,
																	 const char *name);

__attribute__((visibility("internal"))) extern int luaU_dump(lua_State *L, const Proto *f,
															 lua_Writer w, void *data, int strip);
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

const char lua_ident[] = "$LuaVersion: "
						 "Lua "
						 "5"
						 "."
						 "4"
						 "."
						 "2"
						 "  Copyright (C) 1994-2020 Lua.org, PUC-Rio"
						 " $"
						 "$LuaAuthors: "
						 "R. Ierusalimschy, L. H. de Figueiredo, W. Celes"
						 " $";
static TValue *index2value(lua_State *L, int idx)
{
	CallInfo *ci = L->ci;
	if (idx > 0)
	{
		StkId o = ci->func + idx;
		((void) L, ((void) 0));
		if (o >= L->top)
			return &(L->l_G)->nilvalue;
		else
			return (&(o)->val);
	}
	else if (!((idx) <= (-15000 - 1000)))
	{
		((void) L, ((void) 0));
		return (&(L->top + idx)->val);
	}
	else if (idx == (-15000 - 1000))
		return &(L->l_G)->l_registry;
	else
	{
		idx = (-15000 - 1000) - idx;
		((void) L, ((void) 0));
		if ((((((&(ci->func)->val)))->tt_) == (((6) | ((1) << 4)))))
			return &(L->l_G)->nilvalue;
		else
		{
			CClosure *func =
				((&((((union GCUnion *) (((((&(ci->func)->val))->value_).gc))))->cl.c)));
			return (idx <= func->nupvalues) ? &func->upvalue[idx - 1] : &(L->l_G)->nilvalue;
		}
	}
}

static StkId index2stack(lua_State *L, int idx)
{
	CallInfo *ci = L->ci;
	if (idx > 0)
	{
		StkId o = ci->func + idx;
		((void) L, ((void) 0));
		return o;
	}
	else
	{
		((void) L, ((void) 0));
		((void) L, ((void) 0));
		return L->top + idx;
	}
}

extern int lua_checkstack(lua_State *L, int n)
{
	int res;
	CallInfo *ci;
	((void) 0);
	ci = L->ci;
	((void) L, ((void) 0));
	if (L->stack_last - L->top > n)
		res = 1;
	else
	{
		int inuse = ((int) ((L->top - L->stack))) + 5;
		if (inuse > 15000 - n)
			res = 0;
		else
			res = luaD_growstack(L, n, 0);
	}
	if (res && ci->top < L->top + n)
		ci->top = L->top + n;
	((void) 0);
	return res;
}

extern void lua_xmove(lua_State *from, lua_State *to, int n)
{
	int i;
	if (from == to)
		return;
	((void) 0);
	((void) from, ((void) 0));
	((void) from, ((void) 0));
	((void) from, ((void) 0));
	from->top -= n;
	for (i = 0; i < n; i++)
	{
		{
			TValue *io1 = ((&(to->top)->val));
			const TValue *io2 = ((&(from->top + i)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) to, ((void) 0));
			((void) 0);
		};
		to->top++;
	}
	((void) 0);
}

extern lua_CFunction lua_atpanic(lua_State *L, lua_CFunction panicf)
{
	lua_CFunction old;
	((void) 0);
	old = (L->l_G)->panic;
	(L->l_G)->panic = panicf;
	((void) 0);
	return old;
}

extern lua_Number lua_version(lua_State *L)
{
	((void) (L));
	return 504;
}
extern int lua_absindex(lua_State *L, int idx)
{
	return (idx > 0 || ((idx) <= (-15000 - 1000))) ? idx : ((int) ((L->top - L->ci->func))) + idx;
}

extern int lua_gettop(lua_State *L)
{
	return ((int) ((L->top - (L->ci->func + 1))));
}

extern void lua_settop(lua_State *L, int idx)
{
	CallInfo *ci;
	StkId func;
	ptrdiff_t diff;
	((void) 0);
	ci = L->ci;
	func = ci->func;
	if (idx >= 0)
	{
		((void) L, ((void) 0));
		diff = ((func + 1) + idx) - L->top;
		for (; diff > 0; diff--)
			(((&(L->top++)->val))->tt_ = (((0) | ((0) << 4))));
	}
	else
	{
		((void) L, ((void) 0));
		diff = idx + 1;
	}
	if (diff < 0 && ((ci->nresults) < (-1)))
		luaF_close(L, L->top + diff, 0);
	L->top += diff;
	((void) 0);
}
static void reverse(lua_State *L, StkId from, StkId to)
{
	for (; from < to; from++, to--)
	{
		TValue temp;
		{
			TValue *io1 = (&temp);
			const TValue *io2 = ((&(from)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		{
			TValue *io1 = ((&(from)->val));
			const TValue *io2 = ((&(to)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		{
			TValue *io1 = ((&(to)->val));
			const TValue *io2 = (&temp);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
	}
}

extern void lua_rotate(lua_State *L, int idx, int n)
{
	StkId p, t, m;
	((void) 0);
	t = L->top - 1;
	p = index2stack(L, idx);
	((void) L, ((void) 0));
	m = (n >= 0 ? t - n : p - n - 1);
	reverse(L, p, m);
	reverse(L, m + 1, t);
	reverse(L, p, t);
	((void) 0);
}

extern void lua_copy(lua_State *L, int fromidx, int toidx)
{
	TValue *fr, *to;
	((void) 0);
	fr = index2value(L, fromidx);
	to = index2value(L, toidx);
	((void) L, ((void) 0));
	{
		TValue *io1 = (to);
		const TValue *io2 = (fr);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	if (((toidx) < (-15000 - 1000)))
		(((((fr)->tt_) & (1 << 6)) &&
		  (((((&((((union GCUnion *) (((((&(L->ci->func)->val))->value_).gc))))->cl.c))))->marked) &
		   ((1 << (5)))) &&
		  ((((((fr)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
			 ? luaC_barrier_(L,
							 (&(((union GCUnion *) ((((&(
									 (((union GCUnion *) (((((&(L->ci->func)->val))->value_).gc))))
										 ->cl.c))))))
									->gc)),
							 (((fr)->value_).gc))
			 : ((void) ((0))));

	((void) 0);
}

extern void lua_pushvalue(lua_State *L, int idx)
{
	((void) 0);
	{
		TValue *io1 = ((&(L->top)->val));
		const TValue *io2 = (index2value(L, idx));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}
extern int lua_type(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return ((!(((((((o))->tt_)) & 0x0F)) == (0)) || o != &(L->l_G)->nilvalue)
				? (((((o)->tt_)) & 0x0F))
				: (-1));
}

extern const char *lua_typename(lua_State *L, int t)
{
	((void) (L));
	((void) L, ((void) 0));
	return luaT_typenames_[(t) + 1];
}

extern int lua_iscfunction(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return (((((o))->tt_) == (((6) | ((1) << 4)))) ||
			(((((o))->tt_) == (((((6) | ((2) << 4))) | (1 << 6))))));
}

extern int lua_isinteger(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return ((((o))->tt_) == (((3) | ((0) << 4))));
}

extern int lua_isnumber(lua_State *L, int idx)
{
	lua_Number n;
	const TValue *o = index2value(L, idx);
	return (((((o))->tt_) == (((3) | ((1) << 4)))) ? (*(&n) = (((o)->value_).n), 1)
												   : luaV_tonumber_(o, &n));
}

extern int lua_isstring(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return ((((((((o))->tt_)) & 0x0F)) == (4)) || (((((((o))->tt_)) & 0x0F)) == (3)));
}

extern int lua_isuserdata(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return (((((o))->tt_) == (((((7) | ((0) << 4))) | (1 << 6)))) ||
			((((o))->tt_) == (((2) | ((0) << 4)))));
}

extern int lua_rawequal(lua_State *L, int index1, int index2)
{
	const TValue *o1 = index2value(L, index1);
	const TValue *o2 = index2value(L, index2);
	return ((!(((((((o1))->tt_)) & 0x0F)) == (0)) || o1 != &(L->l_G)->nilvalue) &&
			(!(((((((o2))->tt_)) & 0x0F)) == (0)) || o2 != &(L->l_G)->nilvalue))
			   ? luaV_equalobj(NULL, o1, o2)
			   : 0;
}

extern void lua_arith(lua_State *L, int op)
{
	((void) 0);
	if (op != 12 && op != 13)
		((void) L, ((void) 0));
	else
	{
		((void) L, ((void) 0));
		{
			TValue *io1 = ((&(L->top)->val));
			const TValue *io2 = ((&(L->top - 1)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
	}

	luaO_arith(L, op, (&(L->top - 2)->val), (&(L->top - 1)->val), L->top - 2);
	L->top--;
	((void) 0);
}

extern int lua_compare(lua_State *L, int index1, int index2, int op)
{
	const TValue *o1;
	const TValue *o2;
	int i = 0;
	((void) 0);
	o1 = index2value(L, index1);
	o2 = index2value(L, index2);
	if ((!(((((((o1))->tt_)) & 0x0F)) == (0)) || o1 != &(L->l_G)->nilvalue) &&
		(!(((((((o2))->tt_)) & 0x0F)) == (0)) || o2 != &(L->l_G)->nilvalue))
	{
		switch (op)
		{
		case 0:
			i = luaV_equalobj(L, o1, o2);
			break;
		case 1:
			i = luaV_lessthan(L, o1, o2);
			break;
		case 2:
			i = luaV_lessequal(L, o1, o2);
			break;
		default:
			((void) L, ((void) 0));
		}
	}
	((void) 0);
	return i;
}

extern size_t lua_stringtonumber(lua_State *L, const char *s)
{
	size_t sz = luaO_str2num(s, (&(L->top)->val));
	if (sz != 0)
	{
		L->top++;
		((void) L, ((void) 0));
	};
	return sz;
}

extern lua_Number lua_tonumberx(lua_State *L, int idx, int *pisnum)
{
	lua_Number n = 0;
	const TValue *o = index2value(L, idx);
	int isnum = (((((o))->tt_) == (((3) | ((1) << 4)))) ? (*(&n) = (((o)->value_).n), 1)
														: luaV_tonumber_(o, &n));
	if (pisnum)
		*pisnum = isnum;
	return n;
}

extern lua_Integer lua_tointegerx(lua_State *L, int idx, int *pisnum)
{
	lua_Integer res = 0;
	const TValue *o = index2value(L, idx);
	int isnum = (((((o))->tt_) == (((3) | ((0) << 4)))) ? (*(&res) = (((o)->value_).i), 1)
														: luaV_tointeger(o, &res, F2Ieq));
	if (pisnum)
		*pisnum = isnum;
	return res;
}

extern int lua_toboolean(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return !(((((o))->tt_) == (((1) | ((0) << 4)))) || (((((((o))->tt_)) & 0x0F)) == (0)));
}

extern const char *lua_tolstring(lua_State *L, int idx, size_t *len)
{
	TValue *o;
	((void) 0);
	o = index2value(L, idx);
	if (!(((((((o))->tt_)) & 0x0F)) == (4)))
	{
		if (!(((((((o))->tt_)) & 0x0F)) == (3)))
		{
			if (len != NULL)
				*len = 0;
			((void) 0);
			return NULL;
		}
		luaO_tostring(L, o);
		{
			if ((L->l_G)->GCdebt > 0)
			{
				(void) 0;
				luaC_step(L);
				(void) 0;
			};
			((void) 0);
		};
		o = index2value(L, idx);
	}
	if (len != NULL)
		*len = ((((&((((union GCUnion *) ((((o)->value_).gc))))->ts))))->tt == ((4) | ((0) << 4))
					? (((&((((union GCUnion *) ((((o)->value_).gc))))->ts))))->shrlen
					: (((&((((union GCUnion *) ((((o)->value_).gc))))->ts))))->u.lnglen);
	((void) 0);
	return ((((&((((union GCUnion *) ((((o)->value_).gc))))->ts))))->contents);
}

extern lua_Unsigned lua_rawlen(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	switch (((((o)->tt_)) & 0x3F))
	{
	case ((4) | ((0) << 4)):
		return ((&((((union GCUnion *) ((((o)->value_).gc))))->ts)))->shrlen;
	case ((4) | ((1) << 4)):
		return ((&((((union GCUnion *) ((((o)->value_).gc))))->ts)))->u.lnglen;
	case ((7) | ((0) << 4)):
		return ((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->len;
	case ((5) | ((0) << 4)):
		return luaH_getn(((&((((union GCUnion *) ((((o)->value_).gc))))->h))));
	default:
		return 0;
	}
}

extern lua_CFunction lua_tocfunction(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	if (((((o))->tt_) == (((6) | ((1) << 4)))))
		return (((o)->value_).f);
	else if (((((o))->tt_) == (((((6) | ((2) << 4))) | (1 << 6)))))
		return ((&((((union GCUnion *) ((((o)->value_).gc))))->cl.c)))->f;
	else
		return NULL;
}

static void *touserdata(const TValue *o)
{
	switch ((((((o)->tt_)) & 0x0F)))
	{
	case 7:
		return (((char *) ((((&((((union GCUnion *) ((((o)->value_).gc))))->u)))))) +
				(((((&((((union GCUnion *) ((((o)->value_).gc))))->u))))->nuvalue) == 0
					 ? offsetof(Udata0, bindata)
					 : offsetof(Udata, uv) +
						   (sizeof(UValue) *
							((((&((((union GCUnion *) ((((o)->value_).gc))))->u))))->nuvalue))));
	case 2:
		return (((o)->value_).p);
	default:
		return NULL;
	}
}

extern void *lua_touserdata(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return touserdata(o);
}

extern lua_State *lua_tothread(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	return (!((((o))->tt_) == (((((8) | ((0) << 4))) | (1 << 6)))))
			   ? NULL
			   : ((&((((union GCUnion *) ((((o)->value_).gc))))->th)));
}
extern const void *lua_topointer(lua_State *L, int idx)
{
	const TValue *o = index2value(L, idx);
	switch (((((o)->tt_)) & 0x3F))
	{
	case ((6) | ((1) << 4)):
		return ((void *) ((((size_t) (((((o)->value_).f)))))));
	case ((7) | ((0) << 4)):
	case ((2) | ((0) << 4)):
		return touserdata(o);
	default:
	{
		if ((((o)->tt_) & (1 << 6)))
			return (((o)->value_).gc);
		else
			return NULL;
	}
	}
}
extern void lua_pushnil(lua_State *L)
{
	((void) 0);
	(((&(L->top)->val))->tt_ = (((0) | ((0) << 4))));
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}

extern void lua_pushnumber(lua_State *L, lua_Number n)
{
	((void) 0);
	{
		TValue *io = ((&(L->top)->val));
		((io)->value_).n = (n);
		((io)->tt_ = (((3) | ((1) << 4))));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}

extern void lua_pushinteger(lua_State *L, lua_Integer n)
{
	((void) 0);
	{
		TValue *io = ((&(L->top)->val));
		((io)->value_).i = (n);
		((io)->tt_ = (((3) | ((0) << 4))));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}

extern const char *lua_pushlstring(lua_State *L, const char *s, size_t len)
{
	TString *ts;
	((void) 0);
	ts = (len == 0) ? luaS_new(L, "") : luaS_newlstr(L, s, len);
	{
		TValue *io = ((&(L->top)->val));
		TString *x_ = (ts);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void) L, ((void) 0));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
	return ((ts)->contents);
}

extern const char *lua_pushstring(lua_State *L, const char *s)
{
	((void) 0);
	if (s == NULL)
		(((&(L->top)->val))->tt_ = (((0) | ((0) << 4))));
	else
	{
		TString *ts;
		ts = luaS_new(L, s);
		{
			TValue *io = ((&(L->top)->val));
			TString *x_ = (ts);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) L, ((void) 0));
		};
		s = ((ts)->contents);
	}
	{
		L->top++;
		((void) L, ((void) 0));
	};
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
	return s;
}

extern const char *lua_pushvfstring(lua_State *L, const char *fmt, va_list argp)
{
	const char *ret;
	((void) 0);
	ret = luaO_pushvfstring(L, fmt, argp);
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
	return ret;
}

extern const char *lua_pushfstring(lua_State *L, const char *fmt, ...)
{
	const char *ret;
	va_list argp;
	((void) 0);
	va_start(argp, fmt);
	ret = luaO_pushvfstring(L, fmt, argp);
	va_end(argp);
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
	return ret;
}

extern void lua_pushcclosure(lua_State *L, lua_CFunction fn, int n)
{
	((void) 0);
	if (n == 0)
	{
		{
			TValue *io = ((&(L->top)->val));
			((io)->value_).f = (fn);
			((io)->tt_ = (((6) | ((1) << 4))));
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
	}
	else
	{
		CClosure *cl;
		((void) L, ((void) 0));
		((void) L, ((void) 0));
		cl = luaF_newCclosure(L, n);
		cl->f = fn;
		L->top -= n;
		while (n--)
		{
			{
				TValue *io1 = (&cl->upvalue[n]);
				const TValue *io2 = ((&(L->top + n)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};

			((void) 0);
		}
		{
			TValue *io = ((&(L->top)->val));
			CClosure *x_ = (cl);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((((6) | ((2) << 4))) | (1 << 6))));
			((void) L, ((void) 0));
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
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
	((void) 0);
}

extern void lua_pushboolean(lua_State *L, int b)
{
	((void) 0);
	if (b)
		(((&(L->top)->val))->tt_ = (((1) | ((1) << 4))));
	else
		(((&(L->top)->val))->tt_ = (((1) | ((0) << 4))));
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}

extern void lua_pushlightuserdata(lua_State *L, void *p)
{
	((void) 0);
	{
		TValue *io = ((&(L->top)->val));
		((io)->value_).p = (p);
		((io)->tt_ = (((2) | ((0) << 4))));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}

extern int lua_pushthread(lua_State *L)
{
	((void) 0);
	{
		TValue *io = ((&(L->top)->val));
		lua_State *x_ = (L);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((8) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
	return ((L->l_G)->mainthread == L);
}
static int auxgetstr(lua_State *L, const TValue *t, const char *k)
{
	const TValue *slot;
	TString *str = luaS_new(L, k);
	if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
			 ? (slot = NULL, 0)
			 : (slot = luaH_getstr(((&((((union GCUnion *) ((((t)->value_).gc))))->h))), str),
				!(((((((slot))->tt_)) & 0x0F)) == (0)))))
	{
		{
			TValue *io1 = ((&(L->top)->val));
			const TValue *io2 = (slot);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
	}
	else
	{
		{
			TValue *io = ((&(L->top)->val));
			TString *x_ = (str);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) L, ((void) 0));
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
		luaV_finishget(L, t, (&(L->top - 1)->val), L->top - 1, slot);
	}
	((void) 0);
	return ((((((&(L->top - 1)->val))->tt_)) & 0x0F));
}

extern int lua_getglobal(lua_State *L, const char *name)
{
	Table *reg;
	((void) 0);
	reg = ((&((((union GCUnion *) ((((&(L->l_G)->l_registry)->value_).gc))))->h)));
	return auxgetstr(L, luaH_getint(reg, 2), name);
}

extern int lua_gettable(lua_State *L, int idx)
{
	const TValue *slot;
	TValue *t;
	((void) 0);
	t = index2value(L, idx);
	if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
			 ? (slot = NULL, 0)
			 : (slot = luaH_get(((&((((union GCUnion *) ((((t)->value_).gc))))->h))),
								(&(L->top - 1)->val)),
				!(((((((slot))->tt_)) & 0x0F)) == (0)))))
	{
		{
			TValue *io1 = ((&(L->top - 1)->val));
			const TValue *io2 = (slot);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
	}
	else
		luaV_finishget(L, t, (&(L->top - 1)->val), L->top - 1, slot);
	((void) 0);
	return ((((((&(L->top - 1)->val))->tt_)) & 0x0F));
}

extern int lua_getfield(lua_State *L, int idx, const char *k)
{
	((void) 0);
	return auxgetstr(L, index2value(L, idx), k);
}

extern int lua_geti(lua_State *L, int idx, lua_Integer n)
{
	TValue *t;
	const TValue *slot;
	((void) 0);
	t = index2value(L, idx);
	if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
			 ? (slot = NULL, 0)
			 : (slot = (((lua_Unsigned) (n)) - 1u <
						((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->alimit)
						   ? &((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->array[n - 1]
						   : luaH_getint(((&((((union GCUnion *) ((((t)->value_).gc))))->h))), n),
				!(((((((slot))->tt_)) & 0x0F)) == (0)))))
	{
		{
			TValue *io1 = ((&(L->top)->val));
			const TValue *io2 = (slot);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
	}
	else
	{
		TValue aux;
		{
			TValue *io = (&aux);
			((io)->value_).i = (n);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		luaV_finishget(L, t, &aux, L->top, slot);
	}
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
	return ((((((&(L->top - 1)->val))->tt_)) & 0x0F));
}

static int finishrawget(lua_State *L, const TValue *val)
{
	if ((((((((val))->tt_)) & 0x0F)) == (0)))
		(((&(L->top)->val))->tt_ = (((0) | ((0) << 4))));
	else
	{
		TValue *io1 = ((&(L->top)->val));
		const TValue *io2 = (val);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
	return ((((((&(L->top - 1)->val))->tt_)) & 0x0F));
}

static Table *gettable(lua_State *L, int idx)
{
	TValue *t = index2value(L, idx);
	((void) L, ((void) 0));
	return ((&((((union GCUnion *) ((((t)->value_).gc))))->h)));
}

extern int lua_rawget(lua_State *L, int idx)
{
	Table *t;
	const TValue *val;
	((void) 0);
	((void) L, ((void) 0));
	t = gettable(L, idx);
	val = luaH_get(t, (&(L->top - 1)->val));
	L->top--;
	return finishrawget(L, val);
}

extern int lua_rawgeti(lua_State *L, int idx, lua_Integer n)
{
	Table *t;
	((void) 0);
	t = gettable(L, idx);
	return finishrawget(L, luaH_getint(t, n));
}

extern int lua_rawgetp(lua_State *L, int idx, const void *p)
{
	Table *t;
	TValue k;
	((void) 0);
	t = gettable(L, idx);
	{
		TValue *io = (&k);
		((io)->value_).p = (((void *) ((p))));
		((io)->tt_ = (((2) | ((0) << 4))));
	};
	return finishrawget(L, luaH_get(t, &k));
}

extern void lua_createtable(lua_State *L, int narray, int nrec)
{
	Table *t;
	((void) 0);
	t = luaH_new(L);
	{
		TValue *io = ((&(L->top)->val));
		Table *x_ = (t);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	if (narray > 0 || nrec > 0)
		luaH_resize(L, t, narray, nrec);
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
}

extern int lua_getmetatable(lua_State *L, int objindex)
{
	const TValue *obj;
	Table *mt;
	int res = 0;
	((void) 0);
	obj = index2value(L, objindex);
	switch ((((((obj)->tt_)) & 0x0F)))
	{
	case 5:
		mt = ((&((((union GCUnion *) ((((obj)->value_).gc))))->h)))->metatable;
		break;
	case 7:
		mt = ((&((((union GCUnion *) ((((obj)->value_).gc))))->u)))->metatable;
		break;
	default:
		mt = (L->l_G)->mt[(((((obj)->tt_)) & 0x0F))];
		break;
	}
	if (mt != NULL)
	{
		{
			TValue *io = ((&(L->top)->val));
			Table *x_ = (mt);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
			((void) L, ((void) 0));
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
		res = 1;
	}
	((void) 0);
	return res;
}

extern int lua_getiuservalue(lua_State *L, int idx, int n)
{
	TValue *o;
	int t;
	((void) 0);
	o = index2value(L, idx);
	((void) L, ((void) 0));
	if (n <= 0 || n > ((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->nuvalue)
	{
		(((&(L->top)->val))->tt_ = (((0) | ((0) << 4))));
		t = (-1);
	}
	else
	{
		{
			TValue *io1 = ((&(L->top)->val));
			const TValue *io2 =
				(&((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->uv[n - 1].uv);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		t = ((((((&(L->top)->val))->tt_)) & 0x0F));
	}
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
	return t;
}
static void auxsetstr(lua_State *L, const TValue *t, const char *k)
{
	const TValue *slot;
	TString *str = luaS_new(L, k);
	((void) L, ((void) 0));
	if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
			 ? (slot = NULL, 0)
			 : (slot = luaH_getstr(((&((((union GCUnion *) ((((t)->value_).gc))))->h))), str),
				!(((((((slot))->tt_)) & 0x0F)) == (0)))))
	{
		{
			{
				TValue *io1 = (((TValue *) (slot)));
				const TValue *io2 = ((&(L->top - 1)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			((((((&(L->top - 1)->val))->tt_) & (1 << 6)) &&
			  ((((((t)->value_).gc))->marked) & ((1 << (5)))) &&
			  (((((((&(L->top - 1)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrierback_(L, (((t)->value_).gc))
				 : ((void) ((0))));
		};
		L->top--;
	}
	else
	{
		{
			TValue *io = ((&(L->top)->val));
			TString *x_ = (str);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) L, ((void) 0));
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
		luaV_finishset(L, t, (&(L->top - 1)->val), (&(L->top - 2)->val), slot);
		L->top -= 2;
	}
	((void) 0);
}

extern void lua_setglobal(lua_State *L, const char *name)
{
	Table *reg;
	((void) 0);
	reg = ((&((((union GCUnion *) ((((&(L->l_G)->l_registry)->value_).gc))))->h)));
	auxsetstr(L, luaH_getint(reg, 2), name);
}

extern void lua_settable(lua_State *L, int idx)
{
	TValue *t;
	const TValue *slot;
	((void) 0);
	((void) L, ((void) 0));
	t = index2value(L, idx);
	if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
			 ? (slot = NULL, 0)
			 : (slot = luaH_get(((&((((union GCUnion *) ((((t)->value_).gc))))->h))),
								(&(L->top - 2)->val)),
				!(((((((slot))->tt_)) & 0x0F)) == (0)))))
	{
		{
			{
				TValue *io1 = (((TValue *) (slot)));
				const TValue *io2 = ((&(L->top - 1)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			((((((&(L->top - 1)->val))->tt_) & (1 << 6)) &&
			  ((((((t)->value_).gc))->marked) & ((1 << (5)))) &&
			  (((((((&(L->top - 1)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrierback_(L, (((t)->value_).gc))
				 : ((void) ((0))));
		};
	}
	else
		luaV_finishset(L, t, (&(L->top - 2)->val), (&(L->top - 1)->val), slot);
	L->top -= 2;
	((void) 0);
}

extern void lua_setfield(lua_State *L, int idx, const char *k)
{
	((void) 0);
	auxsetstr(L, index2value(L, idx), k);
}

extern void lua_seti(lua_State *L, int idx, lua_Integer n)
{
	TValue *t;
	const TValue *slot;
	((void) 0);
	((void) L, ((void) 0));
	t = index2value(L, idx);
	if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
			 ? (slot = NULL, 0)
			 : (slot = (((lua_Unsigned) (n)) - 1u <
						((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->alimit)
						   ? &((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->array[n - 1]
						   : luaH_getint(((&((((union GCUnion *) ((((t)->value_).gc))))->h))), n),
				!(((((((slot))->tt_)) & 0x0F)) == (0)))))
	{
		{
			{
				TValue *io1 = (((TValue *) (slot)));
				const TValue *io2 = ((&(L->top - 1)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			((((((&(L->top - 1)->val))->tt_) & (1 << 6)) &&
			  ((((((t)->value_).gc))->marked) & ((1 << (5)))) &&
			  (((((((&(L->top - 1)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrierback_(L, (((t)->value_).gc))
				 : ((void) ((0))));
		};
	}
	else
	{
		TValue aux;
		{
			TValue *io = (&aux);
			((io)->value_).i = (n);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		luaV_finishset(L, t, &aux, (&(L->top - 1)->val), slot);
	}
	L->top--;
	((void) 0);
}

static void aux_rawset(lua_State *L, int idx, TValue *key, int n)
{
	Table *t;
	TValue *slot;
	((void) 0);
	((void) L, ((void) 0));
	t = gettable(L, idx);
	slot = luaH_set(L, t, key);
	{
		TValue *io1 = (slot);
		const TValue *io2 = ((&(L->top - 1)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	((t)->flags &= ~(~(~0u << (TM_EQ + 1))));
	((((((&(L->top - 1)->val))->tt_) & (1 << 6)) &&
	  ((((&(((union GCUnion *) ((t)))->gc)))->marked) & ((1 << (5)))) &&
	  (((((((&(L->top - 1)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrierback_(L, (&(((union GCUnion *) ((t)))->gc)))
		 : ((void) ((0))));
	L->top -= n;
	((void) 0);
}

extern void lua_rawset(lua_State *L, int idx)
{
	aux_rawset(L, idx, (&(L->top - 2)->val), 2);
}

extern void lua_rawsetp(lua_State *L, int idx, const void *p)
{
	TValue k;
	{
		TValue *io = (&k);
		((io)->value_).p = (((void *) ((p))));
		((io)->tt_ = (((2) | ((0) << 4))));
	};
	aux_rawset(L, idx, &k, 1);
}

extern void lua_rawseti(lua_State *L, int idx, lua_Integer n)
{
	Table *t;
	((void) 0);
	((void) L, ((void) 0));
	t = gettable(L, idx);
	luaH_setint(L, t, n, (&(L->top - 1)->val));
	((((((&(L->top - 1)->val))->tt_) & (1 << 6)) &&
	  ((((&(((union GCUnion *) ((t)))->gc)))->marked) & ((1 << (5)))) &&
	  (((((((&(L->top - 1)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrierback_(L, (&(((union GCUnion *) ((t)))->gc)))
		 : ((void) ((0))));
	L->top--;
	((void) 0);
}

extern int lua_setmetatable(lua_State *L, int objindex)
{
	TValue *obj;
	Table *mt;
	((void) 0);
	((void) L, ((void) 0));
	obj = index2value(L, objindex);
	if (((((((((&(L->top - 1)->val)))->tt_)) & 0x0F)) == (0)))
		mt = NULL;
	else
	{
		((void) L, ((void) 0));
		mt = ((&((((union GCUnion *) (((((&(L->top - 1)->val))->value_).gc))))->h)));
	}
	switch ((((((obj)->tt_)) & 0x0F)))
	{
	case 5:
	{
		((&((((union GCUnion *) ((((obj)->value_).gc))))->h)))->metatable = mt;
		if (mt)
		{
			((((((((obj)->value_).gc))->marked) & ((1 << (5)))) &&
			  (((mt)->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrier_(L, (&(((union GCUnion *) (((((obj)->value_).gc))))->gc)),
								 (&(((union GCUnion *) ((mt)))->gc)))
				 : ((void) ((0))));
			luaC_checkfinalizer(L, (((obj)->value_).gc), mt);
		}
		break;
	}
	case 7:
	{
		((&((((union GCUnion *) ((((obj)->value_).gc))))->u)))->metatable = mt;
		if (mt)
		{
			(((((((&((((union GCUnion *) ((((obj)->value_).gc))))->u))))->marked) & ((1 << (5)))) &&
			  (((mt)->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrier_(L,
								 (&(((union GCUnion *) ((
										 ((&((((union GCUnion *) ((((obj)->value_).gc))))->u))))))
										->gc)),
								 (&(((union GCUnion *) ((mt)))->gc)))
				 : ((void) ((0))));
			luaC_checkfinalizer(L, (((obj)->value_).gc), mt);
		}
		break;
	}
	default:
	{
		(L->l_G)->mt[(((((obj)->tt_)) & 0x0F))] = mt;
		break;
	}
	}
	L->top--;
	((void) 0);
	return 1;
}

extern int lua_setiuservalue(lua_State *L, int idx, int n)
{
	TValue *o;
	int res;
	((void) 0);
	((void) L, ((void) 0));
	o = index2value(L, idx);
	((void) L, ((void) 0));
	if (!(((unsigned int) ((n))) - 1u <
		  ((unsigned int) ((((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->nuvalue)))))
		res = 0;
	else
	{
		{
			TValue *io1 = (&((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->uv[n - 1].uv);
			const TValue *io2 = ((&(L->top - 1)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		((((((&(L->top - 1)->val))->tt_) & (1 << 6)) &&
		  ((((((o)->value_).gc))->marked) & ((1 << (5)))) &&
		  (((((((&(L->top - 1)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
			 ? luaC_barrierback_(L, (((o)->value_).gc))
			 : ((void) ((0))));
		res = 1;
	}
	L->top--;
	((void) 0);
	return res;
}
extern void lua_callk(lua_State *L, int nargs, int nresults, lua_KContext ctx, lua_KFunction k)
{
	StkId func;
	((void) 0);
	((void) L, ((void) 0));

	((void) L, ((void) 0));
	((void) L, ((void) 0));
	((void) L, ((void) 0));
	func = L->top - (nargs + 1);
	if (k != NULL && (((L)->nCcalls & 0xffff0000) == 0))
	{
		L->ci->u.c.k = k;
		L->ci->u.c.ctx = ctx;
		luaD_call(L, func, nresults);
	}
	else
		luaD_callnoyield(L, func, nresults);
	{
		if ((nresults) <= (-1) && L->ci->top < L->top)
			L->ci->top = L->top;
	};
	((void) 0);
}

struct CallS
{
	StkId func;
	int nresults;
};

static void f_call(lua_State *L, void *ud)
{
	struct CallS *c = ((struct CallS *) (ud));
	luaD_callnoyield(L, c->func, c->nresults);
}

extern int lua_pcallk(lua_State *L, int nargs, int nresults, int errfunc, lua_KContext ctx,
					  lua_KFunction k)
{
	struct CallS c;
	int status;
	ptrdiff_t func;
	((void) 0);
	((void) L, ((void) 0));

	((void) L, ((void) 0));
	((void) L, ((void) 0));
	((void) L, ((void) 0));
	if (errfunc == 0)
		func = 0;
	else
	{
		StkId o = index2stack(L, errfunc);
		((void) L, ((void) 0));
		func = ((char *) (o) - (char *) L->stack);
	}
	c.func = L->top - (nargs + 1);
	if (k == NULL || !(((L)->nCcalls & 0xffff0000) == 0))
	{
		c.nresults = nresults;
		status = luaD_pcall(L, f_call, &c, ((char *) (c.func) - (char *) L->stack), func);
	}
	else
	{
		CallInfo *ci = L->ci;
		ci->u.c.k = k;
		ci->u.c.ctx = ctx;

		ci->u2.funcidx = ((int) ((((char *) (c.func) - (char *) L->stack))));
		ci->u.c.old_errfunc = L->errfunc;
		L->errfunc = func;
		((ci->callstatus) = ((ci->callstatus) & ~(1 << 0)) | (L->allowhook));
		ci->callstatus |= (1 << 4);
		luaD_call(L, c.func, nresults);
		ci->callstatus &= ~(1 << 4);
		L->errfunc = ci->u.c.old_errfunc;
		status = 0;
	}
	{
		if ((nresults) <= (-1) && L->ci->top < L->top)
			L->ci->top = L->top;
	};
	((void) 0);
	return status;
}

extern int lua_load(lua_State *L, lua_Reader reader, void *data, const char *chunkname,
					const char *mode)
{
	ZIO z;
	int status;
	((void) 0);
	if (!chunkname)
		chunkname = "?";
	luaZ_init(L, &z, reader, data);
	status = luaD_protectedparser(L, &z, chunkname, mode);
	if (status == 0)
	{
		LClosure *f = ((&((((union GCUnion *) (((((&(L->top - 1)->val))->value_).gc))))->cl.l)));
		if (f->nupvalues >= 1)
		{

			Table *reg = ((&((((union GCUnion *) ((((&(L->l_G)->l_registry)->value_).gc))))->h)));
			const TValue *gt = luaH_getint(reg, 2);

			{
				TValue *io1 = (f->upvals[0]->v);
				const TValue *io2 = (gt);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			(((((gt)->tt_) & (1 << 6)) && (((f->upvals[0])->marked) & ((1 << (5)))) &&
			  ((((((gt)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrier_(L, (&(((union GCUnion *) ((f->upvals[0])))->gc)),
								 (((gt)->value_).gc))
				 : ((void) ((0))));
		}
	}
	((void) 0);
	return status;
}

extern int lua_dump(lua_State *L, lua_Writer writer, void *data, int strip)
{
	int status;
	TValue *o;
	((void) 0);
	((void) L, ((void) 0));
	o = (&(L->top - 1)->val);
	if (((((o))->tt_) == (((((6) | ((0) << 4))) | (1 << 6)))))
		status = luaU_dump(L, (((&((((union GCUnion *) ((((o)->value_).gc))))->cl.l)))->p), writer,
						   data, strip);
	else
		status = 1;
	((void) 0);
	return status;
}

extern int lua_status(lua_State *L)
{
	return L->status;
}

extern int lua_gc(lua_State *L, int what, ...)
{
	va_list argp;
	int res = 0;
	global_State *g;
	((void) 0);
	g = (L->l_G);
	va_start(argp, what);
	switch (what)
	{
	case 0:
	{
		g->gcrunning = 0;
		break;
	}
	case 1:
	{
		luaE_setdebt(g, 0);
		g->gcrunning = 1;
		break;
	}
	case 2:
	{
		luaC_fullgc(L, 0);
		break;
	}
	case 3:
	{

		res = ((int) ((((lu_mem) ((g)->totalbytes + (g)->GCdebt)) >> 10)));
		break;
	}
	case 4:
	{
		res = ((int) ((((lu_mem) ((g)->totalbytes + (g)->GCdebt)) & 0x3ff)));
		break;
	}
	case 5:
	{
		int data = va_arg(argp, int);
		l_mem debt = 1;
		lu_byte oldrunning = g->gcrunning;
		g->gcrunning = 1;
		if (data == 0)
		{
			luaE_setdebt(g, 0);
			luaC_step(L);
		}
		else
		{
			debt = ((l_mem) (data)) * 1024 + g->GCdebt;
			luaE_setdebt(g, debt);
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
		g->gcrunning = oldrunning;
		if (debt > 0 && g->gcstate == 8)
			res = 1;
		break;
	}
	case 6:
	{
		int data = va_arg(argp, int);
		res = ((g->gcpause) * 4);
		((g->gcpause) = (data) / 4);
		break;
	}
	case 7:
	{
		int data = va_arg(argp, int);
		res = ((g->gcstepmul) * 4);
		((g->gcstepmul) = (data) / 4);
		break;
	}
	case 9:
	{
		res = g->gcrunning;
		break;
	}
	case 10:
	{
		int minormul = va_arg(argp, int);
		int majormul = va_arg(argp, int);
		res = (g->gckind == 1 || g->lastatomic != 0) ? 10 : 11;
		if (minormul != 0)
			g->genminormul = minormul;
		if (majormul != 0)
			((g->genmajormul) = (majormul) / 4);
		luaC_changemode(L, 1);
		break;
	}
	case 11:
	{
		int pause = va_arg(argp, int);
		int stepmul = va_arg(argp, int);
		int stepsize = va_arg(argp, int);
		res = (g->gckind == 1 || g->lastatomic != 0) ? 10 : 11;
		if (pause != 0)
			((g->gcpause) = (pause) / 4);
		if (stepmul != 0)
			((g->gcstepmul) = (stepmul) / 4);
		if (stepsize != 0)
			g->gcstepsize = stepsize;
		luaC_changemode(L, 0);
		break;
	}
	default:
		res = -1;
	}
	va_end(argp);
	((void) 0);
	return res;
}
extern int lua_error(lua_State *L)
{
	TValue *errobj;
	((void) 0);
	errobj = (&(L->top - 1)->val);
	((void) L, ((void) 0));

	if (((((errobj))->tt_) == (((((4) | ((0) << 4))) | (1 << 6)))) &&
		((((&((((union GCUnion *) ((((errobj)->value_).gc))))->ts)))) == ((L->l_G)->memerrmsg)))
		luaD_throw(L, 4);
	else
		luaG_errormsg(L);

	return 0;
}

extern int lua_next(lua_State *L, int idx)
{
	Table *t;
	int more;
	((void) 0);
	((void) L, ((void) 0));
	t = gettable(L, idx);
	more = luaH_next(L, t, L->top - 1);
	if (more)
	{
		{
			L->top++;
			((void) L, ((void) 0));
		};
	}
	else
		L->top -= 1;
	((void) 0);
	return more;
}

extern void lua_toclose(lua_State *L, int idx)
{
	int nresults;
	StkId o;
	((void) 0);
	o = index2stack(L, idx);
	nresults = L->ci->nresults;
	((void) L, ((void) 0));

	luaF_newtbcupval(L, o);
	if (!((nresults) < (-1)))
		L->ci->nresults = (-(nresults) -3);
	((void) 0);
	((void) 0);
}

extern void lua_concat(lua_State *L, int n)
{
	((void) 0);
	((void) L, ((void) 0));
	if (n > 0)
		luaV_concat(L, n);
	else
	{
		{
			TValue *io = ((&(L->top)->val));
			TString *x_ = (luaS_newlstr(L, "", 0));
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) L, ((void) 0));
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
	}
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
}

extern void lua_len(lua_State *L, int idx)
{
	TValue *t;
	((void) 0);
	t = index2value(L, idx);
	luaV_objlen(L, L->top, t);
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
}

extern lua_Alloc lua_getallocf(lua_State *L, void **ud)
{
	lua_Alloc f;
	((void) 0);
	if (ud)
		*ud = (L->l_G)->ud;
	f = (L->l_G)->frealloc;
	((void) 0);
	return f;
}

extern void lua_setallocf(lua_State *L, lua_Alloc f, void *ud)
{
	((void) 0);
	(L->l_G)->ud = ud;
	(L->l_G)->frealloc = f;
	((void) 0);
}

void lua_setwarnf(lua_State *L, lua_WarnFunction f, void *ud)
{
	((void) 0);
	(L->l_G)->ud_warn = ud;
	(L->l_G)->warnf = f;
	((void) 0);
}

void lua_warning(lua_State *L, const char *msg, int tocont)
{
	((void) 0);
	luaE_warning(L, msg, tocont);
	((void) 0);
}

extern void *lua_newuserdatauv(lua_State *L, size_t size, int nuvalue)
{
	Udata *u;
	((void) 0);
	((void) L, ((void) 0));
	u = luaS_newudata(L, size, nuvalue);
	{
		TValue *io = ((&(L->top)->val));
		Udata *x_ = (u);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((7) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};
	((void) 0);
	return (((char *) ((u))) + (((u)->nuvalue) == 0
									? offsetof(Udata0, bindata)
									: offsetof(Udata, uv) + (sizeof(UValue) * ((u)->nuvalue))));
}

static const char *aux_upvalue(TValue *fi, int n, TValue **val, GCObject **owner)
{
	switch (((((fi)->tt_)) & 0x3F))
	{
	case ((6) | ((2) << 4)):
	{
		CClosure *f = ((&((((union GCUnion *) ((((fi)->value_).gc))))->cl.c)));
		if (!(((unsigned int) ((n))) - 1u < ((unsigned int) ((f->nupvalues)))))
			return NULL;
		*val = &f->upvalue[n - 1];
		if (owner)
			*owner = (&(((union GCUnion *) ((f)))->gc));
		return "";
	}
	case ((6) | ((0) << 4)):
	{
		LClosure *f = ((&((((union GCUnion *) ((((fi)->value_).gc))))->cl.l)));
		TString *name;
		Proto *p = f->p;
		if (!(((unsigned int) ((n))) - 1u < ((unsigned int) ((p->sizeupvalues)))))
			return NULL;
		*val = f->upvals[n - 1]->v;
		if (owner)
			*owner = (&(((union GCUnion *) ((f->upvals[n - 1])))->gc));
		name = p->upvalues[n - 1].name;
		return (name == NULL) ? "(no name)" : ((name)->contents);
	}
	default:
		return NULL;
	}
}

extern const char *lua_getupvalue(lua_State *L, int funcindex, int n)
{
	const char *name;
	TValue *val = NULL;
	((void) 0);
	name = aux_upvalue(index2value(L, funcindex), n, &val, NULL);
	if (name)
	{
		{
			TValue *io1 = ((&(L->top)->val));
			const TValue *io2 = (val);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		{
			L->top++;
			((void) L, ((void) 0));
		};
	}
	((void) 0);
	return name;
}

extern const char *lua_setupvalue(lua_State *L, int funcindex, int n)
{
	const char *name;
	TValue *val = NULL;
	GCObject *owner = NULL;
	TValue *fi;
	((void) 0);
	fi = index2value(L, funcindex);
	((void) L, ((void) 0));
	name = aux_upvalue(fi, n, &val, &owner);
	if (name)
	{
		L->top--;
		{
			TValue *io1 = (val);
			const TValue *io2 = ((&(L->top)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		(((((val)->tt_) & (1 << 6)) && (((owner)->marked) & ((1 << (5)))) &&
		  ((((((val)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
			 ? luaC_barrier_(L, (&(((union GCUnion *) ((owner)))->gc)), (((val)->value_).gc))
			 : ((void) ((0))));
	}
	((void) 0);
	return name;
}

static UpVal **getupvalref(lua_State *L, int fidx, int n, LClosure **pf)
{
	static const UpVal *const nullup = NULL;
	LClosure *f;
	TValue *fi = index2value(L, fidx);
	((void) L, ((void) 0));
	f = ((&((((union GCUnion *) ((((fi)->value_).gc))))->cl.l)));
	if (pf)
		*pf = f;
	if (1 <= n && n <= f->p->sizeupvalues)
		return &f->upvals[n - 1];
	else
		return (UpVal **) &nullup;
}

extern void *lua_upvalueid(lua_State *L, int fidx, int n)
{
	TValue *fi = index2value(L, fidx);
	switch (((((fi)->tt_)) & 0x3F))
	{
	case ((6) | ((0) << 4)):
	{
		return *getupvalref(L, fidx, n, NULL);
	}
	case ((6) | ((2) << 4)):
	{
		CClosure *f = ((&((((union GCUnion *) ((((fi)->value_).gc))))->cl.c)));
		if (1 <= n && n <= f->nupvalues)
			return &f->upvalue[n - 1];
	}
	case ((6) | ((1) << 4)):
		return NULL;
	default:
	{
		((void) L, ((void) 0));
		return NULL;
	}
	}
}

extern void lua_upvaluejoin(lua_State *L, int fidx1, int n1, int fidx2, int n2)
{
	LClosure *f1;
	UpVal **up1 = getupvalref(L, fidx1, n1, &f1);
	UpVal **up2 = getupvalref(L, fidx2, n2, NULL);
	((void) L, ((void) 0));
	*up1 = *up2;
	(((((f1)->marked) & ((1 << (5)))) && (((*up1)->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrier_(L, (&(((union GCUnion *) ((f1)))->gc)),
						 (&(((union GCUnion *) ((*up1)))->gc)))
		 : ((void) ((0))));
}
