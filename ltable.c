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
static const Node dummynode_ = {{{NULL}, ((0) | ((1) << 4)), ((0) | ((0) << 4)), 0, {NULL}}};

static const TValue absentkey = {{NULL}, ((0) | ((2) << 4))};
static int l_hashfloat(lua_Number n)
{
	int i;
	lua_Integer ni;
	n = frexp(n, &i) * -((lua_Number) ((INT_MIN)));
	if (!((n) >= (double) (LUA_MININTEGER) && (n) < -(double) (LUA_MININTEGER) &&
		  (*(&ni) = (LUA_INTEGER) (n), 1)))
	{
		((void) 0);
		return 0;
	}
	else
	{
		unsigned int u = ((unsigned int) ((i))) + ((unsigned int) ((ni)));
		return ((int) ((u <= ((unsigned int) ((INT_MAX))) ? u : ~u)));
	}
}
static Node *mainposition(const Table *t, int ktt, const Value *kvl)
{
	switch (((ktt) &0x3F))
	{
	case ((3) | ((0) << 4)):
		return ((&(t)->node[(((((int) ((((((*kvl).i))) & ((((1 << ((t)->lsizenode)))) - 1)))))))]));
	case ((3) | ((1) << 4)):
		return ((&(t)->node[((l_hashfloat(((*kvl).n))) % ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	case ((4) | ((0) << 4)):
		return ((&(t)->node[(((((int) (((((((&((((union GCUnion *) (((*kvl).gc))))->ts))))->hash)) &
										((((1 << ((t)->lsizenode)))) - 1)))))))]));
	case ((4) | ((1) << 4)):
		return ((&(t)->node[(
			((((int) ((((luaS_hashlongstr(((&((((union GCUnion *) (((*kvl).gc))))->ts)))))) &
					   ((((1 << ((t)->lsizenode)))) - 1)))))))]));
	case ((1) | ((0) << 4)):
		return ((&(t)->node[(((((int) ((((0)) & ((((1 << ((t)->lsizenode)))) - 1)))))))]));
	case ((1) | ((1) << 4)):
		return ((&(t)->node[(((((int) ((((1)) & ((((1 << ((t)->lsizenode)))) - 1)))))))]));
	case ((2) | ((0) << 4)):
		return ((&(t)->node[((((unsigned int) ((size_t) (((*kvl).p)) & UINT_MAX))) %
							 ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	case ((6) | ((1) << 4)):
		return ((&(t)->node[((((unsigned int) ((size_t) (((*kvl).f)) & UINT_MAX))) %
							 ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	default:
		return ((&(t)->node[((((unsigned int) ((size_t) (((*kvl).gc)) & UINT_MAX))) %
							 ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	}
}

static Node *mainpositionTV(const Table *t, const TValue *key)
{
	return mainposition(t, ((key)->tt_), (&((key)->value_)));
}
static int equalkey(const TValue *k1, const Node *n2, int deadok)
{
	if ((((k1)->tt_) != ((n2)->u.key_tt)) &&
		!(deadok && (((n2)->u.key_tt) == (9 + 2)) && (((k1)->tt_) & (1 << 6))))
		return 0;
	switch (((n2)->u.key_tt))
	{
	case ((0) | ((0) << 4)):
	case ((1) | ((0) << 4)):
	case ((1) | ((1) << 4)):
		return 1;
	case ((3) | ((0) << 4)):
		return ((((k1)->value_).i) == (((n2)->u.key_val).i));
	case ((3) | ((1) << 4)):
		return (((((k1)->value_).n)) == (((((n2)->u.key_val)).n)));
	case ((2) | ((0) << 4)):
		return (((k1)->value_).p) == ((((n2)->u.key_val)).p);
	case ((6) | ((1) << 4)):
		return (((k1)->value_).f) == ((((n2)->u.key_val)).f);
	case ((((4) | ((1) << 4))) | (1 << 6)):
		return luaS_eqlngstr(((&((((union GCUnion *) ((((k1)->value_).gc))))->ts))),
							 ((&((((union GCUnion *) ((((n2)->u.key_val).gc))))->ts))));
	default:
		return (((k1)->value_).gc) == ((((n2)->u.key_val)).gc);
	}
}
__attribute__((visibility("internal"))) extern unsigned int luaH_realasize(const Table *t)
{
	if (((!((t)->flags & (1 << 7))) || ((((t)->alimit) & (((t)->alimit) - 1)) == 0)))
		return t->alimit;
	else
	{
		unsigned int size = t->alimit;

		size |= (size >> 1);
		size |= (size >> 2);
		size |= (size >> 4);
		size |= (size >> 8);
		size |= (size >> 16);

		size++;
		((void) 0);
		return size;
	}
}

static int ispow2realasize(const Table *t)
{
	return (!(!((t)->flags & (1 << 7))) || (((t->alimit) & ((t->alimit) - 1)) == 0));
}

static unsigned int setlimittosize(Table *t)
{
	t->alimit = luaH_realasize(t);
	((t)->flags &= ((lu_byte) ((~(1 << 7)))));
	return t->alimit;
}
static const TValue *getgeneric(Table *t, const TValue *key, int deadok)
{
	Node *n = mainpositionTV(t, key);
	for (;;)
	{
		if (equalkey(key, n, deadok))
			return (&(n)->i_val);
		else
		{
			int nx = ((n)->u.next);
			if (nx == 0)
				return &absentkey;
			n += nx;
		}
	}
}

static unsigned int arrayindex(lua_Integer k)
{
	if (((lua_Unsigned) (k)) - 1u <
		((((size_t) ((1u << ((int) ((sizeof(int) * CHAR_BIT - 1)))))) <=
		  ((size_t) (~(size_t) 0)) / sizeof(TValue))
			 ? (1u << ((int) ((sizeof(int) * CHAR_BIT - 1))))
			 : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(TValue)))))))
		return ((unsigned int) ((k)));
	else
		return 0;
}

static unsigned int findindex(lua_State *L, Table *t, TValue *key, unsigned int asize)
{
	unsigned int i;
	if ((((((((key))->tt_)) & 0x0F)) == (0)))
		return 0;
	i = ((((key))->tt_) == (((3) | ((0) << 4)))) ? arrayindex((((key)->value_).i)) : 0;
	if (i - 1u < asize)
		return i;
	else
	{
		const TValue *n = getgeneric(t, key, 1);
		if ((__builtin_expect(((((((n))->tt_) == (((0) | ((2) << 4))))) != 0), 0)))
			luaG_runerror(L, "invalid key to 'next'");
		i = ((int) ((((Node *) ((n))) - (&(t)->node[0]))));

		return (i + 1) + asize;
	}
}

int luaH_next(lua_State *L, Table *t, StkId key)
{
	unsigned int asize = luaH_realasize(t);
	unsigned int i = findindex(L, t, (&(key)->val), asize);
	for (; i < asize; i++)
	{
		if (!(((((((&t->array[i]))->tt_)) & 0x0F)) == (0)))
		{
			{
				TValue *io = ((&(key)->val));
				((io)->value_).i = (i + 1);
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			{
				TValue *io1 = ((&(key + 1)->val));
				const TValue *io2 = (&t->array[i]);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			return 1;
		}
	}
	for (i -= asize; ((int) ((i))) < ((1 << ((t)->lsizenode))); i++)
	{
		if (!((((((((&((&(t)->node[i]))->i_val)))->tt_)) & 0x0F)) == (0)))
		{
			Node *n = (&(t)->node[i]);
			{
				TValue *io_ = ((&(key)->val));
				const Node *n_ = (n);
				io_->value_ = n_->u.key_val;
				io_->tt_ = n_->u.key_tt;
				((void) L, ((void) 0));
			};
			{
				TValue *io1 = ((&(key + 1)->val));
				const TValue *io2 = ((&(n)->i_val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			return 1;
		}
	}
	return 0;
}

static void freehash(lua_State *L, Table *t)
{
	if (!((t)->lastfree == NULL))
		luaM_free_(L, (t->node), (((size_t) ((((1 << ((t)->lsizenode))))))) * sizeof(*(t->node)));
}
static unsigned int computesizes(unsigned int nums[], unsigned int *pna)
{
	int i;
	unsigned int twotoi;
	unsigned int a = 0;
	unsigned int na = 0;
	unsigned int optimal = 0;

	for (i = 0, twotoi = 1; twotoi > 0 && *pna > twotoi / 2; i++, twotoi *= 2)
	{
		a += nums[i];
		if (a > twotoi / 2)
		{
			optimal = twotoi;
			na = a;
		}
	}
	((void) 0);
	*pna = na;
	return optimal;
}

static int countint(lua_Integer key, unsigned int *nums)
{
	unsigned int k = arrayindex(key);
	if (k != 0)
	{
		nums[luaO_ceillog2(k)]++;
		return 1;
	}
	else
		return 0;
}

static unsigned int numusearray(const Table *t, unsigned int *nums)
{
	int lg;
	unsigned int ttlg;
	unsigned int ause = 0;
	unsigned int i = 1;
	unsigned int asize = (t->alimit);

	for (lg = 0, ttlg = 1; lg <= ((int) ((sizeof(int) * CHAR_BIT - 1))); lg++, ttlg *= 2)
	{
		unsigned int lc = 0;
		unsigned int lim = ttlg;
		if (lim > asize)
		{
			lim = asize;
			if (i > lim)
				break;
		}

		for (; i <= lim; i++)
		{
			if (!(((((((&t->array[i - 1]))->tt_)) & 0x0F)) == (0)))
				lc++;
		}
		nums[lg] += lc;
		ause += lc;
	}
	return ause;
}

static int numusehash(const Table *t, unsigned int *nums, unsigned int *pna)
{
	int totaluse = 0;
	int ause = 0;
	int i = ((1 << ((t)->lsizenode)));
	while (i--)
	{
		Node *n = &t->node[i];
		if (!((((((((&(n)->i_val)))->tt_)) & 0x0F)) == (0)))
		{
			if ((((n)->u.key_tt) == ((3) | ((0) << 4))))
				ause += countint((((n)->u.key_val).i), nums);
			totaluse++;
		}
	}
	*pna += ause;
	return totaluse;
}
static void setnodevector(lua_State *L, Table *t, unsigned int size)
{
	if (size == 0)
	{
		t->node = ((Node *) ((&dummynode_)));
		t->lsizenode = 0;
		t->lastfree = NULL;
	}
	else
	{
		int i;
		int lsize = luaO_ceillog2(size);
		if (lsize > (((int) ((sizeof(int) * CHAR_BIT - 1))) - 1) ||
			(1u << lsize) > ((((size_t) ((1u << (((int) ((sizeof(int) * CHAR_BIT - 1))) - 1)))) <=
							  ((size_t) (~(size_t) 0)) / sizeof(Node))
								 ? (1u << (((int) ((sizeof(int) * CHAR_BIT - 1))) - 1))
								 : ((unsigned int) (((((size_t) (~(size_t) 0)) / sizeof(Node)))))))
			luaG_runerror(L, "table overflow");
		size = (1 << (lsize));
		t->node = ((Node *) (luaM_malloc_(L, (size) * sizeof(Node), 0)));
		for (i = 0; i < (int) size; i++)
		{
			Node *n = (&(t)->node[i]);
			((n)->u.next) = 0;
			(((n)->u.key_tt) = 0);
			(((&(n)->i_val))->tt_ = (((0) | ((1) << 4))));
		}
		t->lsizenode = ((lu_byte) ((lsize)));
		t->lastfree = (&(t)->node[size]);
	}
}

static void reinsert(lua_State *L, Table *ot, Table *t)
{
	int j;
	int size = ((1 << ((ot)->lsizenode)));
	for (j = 0; j < size; j++)
	{
		Node *old = (&(ot)->node[j]);
		if (!((((((((&(old)->i_val)))->tt_)) & 0x0F)) == (0)))
		{

			TValue k;
			{
				TValue *io_ = (&k);
				const Node *n_ = (old);
				io_->value_ = n_->u.key_val;
				io_->tt_ = n_->u.key_tt;
				((void) L, ((void) 0));
			};
			{
				TValue *io1 = (luaH_set(L, t, &k));
				const TValue *io2 = ((&(old)->i_val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
		}
	}
}

static void exchangehashpart(Table *t1, Table *t2)
{
	lu_byte lsizenode = t1->lsizenode;
	Node *node = t1->node;
	Node *lastfree = t1->lastfree;
	t1->lsizenode = t2->lsizenode;
	t1->node = t2->node;
	t1->lastfree = t2->lastfree;
	t2->lsizenode = lsizenode;
	t2->node = node;
	t2->lastfree = lastfree;
}
void luaH_resize(lua_State *L, Table *t, unsigned int newasize, unsigned int nhsize)
{
	unsigned int i;
	Table newt;
	unsigned int oldasize = setlimittosize(t);
	TValue *newarray;

	setnodevector(L, &newt, nhsize);
	if (newasize < oldasize)
	{
		t->alimit = newasize;
		exchangehashpart(t, &newt);

		for (i = newasize; i < oldasize; i++)
		{
			if (!(((((((&t->array[i]))->tt_)) & 0x0F)) == (0)))
				luaH_setint(L, t, i + 1, &t->array[i]);
		}
		t->alimit = oldasize;
		exchangehashpart(t, &newt);
	}

	newarray = (((TValue *) (luaM_realloc_(L, t->array, ((size_t) ((oldasize))) * sizeof(TValue),
										   ((size_t) ((newasize))) * sizeof(TValue)))));
	if ((__builtin_expect(((newarray == NULL && newasize > 0) != 0), 0)))
	{
		freehash(L, &newt);
		luaD_throw(L, 4);
	}

	exchangehashpart(t, &newt);
	t->array = newarray;
	t->alimit = newasize;
	for (i = oldasize; i < newasize; i++)
		((&t->array[i])->tt_ = (((0) | ((1) << 4))));

	reinsert(L, &newt, t);
	freehash(L, &newt);
}

void luaH_resizearray(lua_State *L, Table *t, unsigned int nasize)
{
	int nsize = (((t)->lastfree == NULL) ? 0 : ((1 << ((t)->lsizenode))));
	luaH_resize(L, t, nasize, nsize);
}

static void rehash(lua_State *L, Table *t, const TValue *ek)
{
	unsigned int asize;
	unsigned int na;
	unsigned int nums[((int) ((sizeof(int) * CHAR_BIT - 1))) + 1];
	int i;
	int totaluse;
	for (i = 0; i <= ((int) ((sizeof(int) * CHAR_BIT - 1))); i++)
		nums[i] = 0;
	setlimittosize(t);
	na = numusearray(t, nums);
	totaluse = na;
	totaluse += numusehash(t, nums, &na);

	if (((((ek))->tt_) == (((3) | ((0) << 4)))))
		na += countint((((ek)->value_).i), nums);
	totaluse++;

	asize = computesizes(nums, &na);

	luaH_resize(L, t, asize, totaluse - na);
}
Table *luaH_new(lua_State *L)
{
	GCObject *o = luaC_newobj(L, ((5) | ((0) << 4)), sizeof(Table));
	Table *t = (&((((union GCUnion *) ((o))))->h));
	t->metatable = NULL;
	t->flags = ((lu_byte) (((~(~0u << (TM_EQ + 1))))));
	t->array = NULL;
	t->alimit = 0;
	setnodevector(L, t, 0);
	return t;
}

void luaH_free(lua_State *L, Table *t)
{
	freehash(L, t);
	luaM_free_(L, (t->array), (luaH_realasize(t)) * sizeof(*(t->array)));
	luaM_free_(L, (t), sizeof(*(t)));
}

static Node *getfreepos(Table *t)
{
	if (!((t)->lastfree == NULL))
	{
		while (t->lastfree > t->node)
		{
			t->lastfree--;
			if ((((t->lastfree)->u.key_tt) == 0))
				return t->lastfree;
		}
	}
	return NULL;
}
TValue *luaH_newkey(lua_State *L, Table *t, const TValue *key)
{
	Node *mp;
	TValue aux;
	if ((__builtin_expect((((((((((key))->tt_)) & 0x0F)) == (0))) != 0), 0)))
		luaG_runerror(L, "table index is nil");
	else if (((((key))->tt_) == (((3) | ((1) << 4)))))
	{
		lua_Number f = (((key)->value_).n);
		lua_Integer k;
		if (luaV_flttointeger(f, &k, F2Ieq))
		{
			{
				TValue *io = (&aux);
				((io)->value_).i = (k);
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			key = &aux;
		}
		else if ((__builtin_expect((((!(((f)) == ((f))))) != 0), 0)))
			luaG_runerror(L, "table index is NaN");
	}
	mp = mainpositionTV(t, key);
	if (!((((((((&(mp)->i_val)))->tt_)) & 0x0F)) == (0)) || ((t)->lastfree == NULL))
	{
		Node *othern;
		Node *f = getfreepos(t);
		if (f == NULL)
		{
			rehash(L, t, key);

			return luaH_set(L, t, key);
		}
		((void) 0);
		othern = mainposition(t, ((mp)->u.key_tt), &((mp)->u.key_val));
		if (othern != mp)
		{

			while (othern + ((othern)->u.next) != mp)
				othern += ((othern)->u.next);
			((othern)->u.next) = ((int) ((f - othern)));
			*f = *mp;
			if (((mp)->u.next) != 0)
			{
				((f)->u.next) += ((int) ((mp - f)));
				((mp)->u.next) = 0;
			}
			(((&(mp)->i_val))->tt_ = (((0) | ((1) << 4))));
		}
		else
		{

			if (((mp)->u.next) != 0)
				((f)->u.next) = ((int) (((mp + ((mp)->u.next)) - f)));
			else
				((void) 0);
			((mp)->u.next) = ((int) ((f - mp)));
			mp = f;
		}
	}
	{
		Node *n_ = (mp);
		const TValue *io_ = (key);
		n_->u.key_val = io_->value_;
		n_->u.key_tt = io_->tt_;
		((void) L, ((void) 0));
	};
	(((((key)->tt_) & (1 << 6)) &&
	  ((((&(((union GCUnion *) ((t)))->gc)))->marked) & ((1 << (5)))) &&
	  ((((((key)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
		 ? luaC_barrierback_(L, (&(((union GCUnion *) ((t)))->gc)))
		 : ((void) ((0))));
	((void) 0);
	return (&(mp)->i_val);
}
const TValue *luaH_getint(Table *t, lua_Integer key)
{
	if (((lua_Unsigned) (key)) - 1u < t->alimit)
		return &t->array[key - 1];
	else if (!((!((t)->flags & (1 << 7))) || ((((t)->alimit) & (((t)->alimit) - 1)) == 0)) &&
			 (((lua_Unsigned) (key)) == t->alimit + 1 ||
			  ((lua_Unsigned) (key)) - 1u < luaH_realasize(t)))
	{
		t->alimit = ((unsigned int) ((key)));
		return &t->array[key - 1];
	}
	else
	{
		Node *n = ((&(t)->node[(((((int) ((((key)) & ((((1 << ((t)->lsizenode)))) - 1)))))))]));
		for (;;)
		{
			if ((((n)->u.key_tt) == ((3) | ((0) << 4))) && (((n)->u.key_val).i) == key)
				return (&(n)->i_val);
			else
			{
				int nx = ((n)->u.next);
				if (nx == 0)
					break;
				n += nx;
			}
		}
		return &absentkey;
	}
}

const TValue *luaH_getshortstr(Table *t, TString *key)
{
	Node *n = ((&(t)->node[(((((int) (((((key)->hash)) & ((((1 << ((t)->lsizenode)))) - 1)))))))]));
	((void) 0);
	for (;;)
	{
		if ((((n)->u.key_tt) == ((((4) | ((0) << 4))) | (1 << 6))) &&
			((((&((((union GCUnion *) ((((n)->u.key_val).gc))))->ts)))) == (key)))
			return (&(n)->i_val);
		else
		{
			int nx = ((n)->u.next);
			if (nx == 0)
				return &absentkey;
			n += nx;
		}
	}
}

const TValue *luaH_getstr(Table *t, TString *key)
{
	if (key->tt == ((4) | ((0) << 4)))
		return luaH_getshortstr(t, key);
	else
	{
		TValue ko;
		{
			TValue *io = (&ko);
			TString *x_ = (key);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) ((lua_State *) (NULL)), ((void) 0));
		};
		return getgeneric(t, &ko, 0);
	}
}

const TValue *luaH_get(Table *t, const TValue *key)
{
	switch (((((key)->tt_)) & 0x3F))
	{
	case ((4) | ((0) << 4)):
		return luaH_getshortstr(t, ((&((((union GCUnion *) ((((key)->value_).gc))))->ts))));
	case ((3) | ((0) << 4)):
		return luaH_getint(t, (((key)->value_).i));
	case ((0) | ((0) << 4)):
		return &absentkey;
	case ((3) | ((1) << 4)):
	{
		lua_Integer k;
		if (luaV_flttointeger((((key)->value_).n), &k, F2Ieq))
			return luaH_getint(t, k);
	}
	default:
		return getgeneric(t, key, 0);
	}
}

TValue *luaH_set(lua_State *L, Table *t, const TValue *key)
{
	const TValue *p = luaH_get(t, key);
	if (!((((p))->tt_) == (((0) | ((2) << 4)))))
		return ((TValue *) (p));
	else
		return luaH_newkey(L, t, key);
}

void luaH_setint(lua_State *L, Table *t, lua_Integer key, TValue *value)
{
	const TValue *p = luaH_getint(t, key);
	TValue *cell;
	if (!((((p))->tt_) == (((0) | ((2) << 4)))))
		cell = ((TValue *) (p));
	else
	{
		TValue k;
		{
			TValue *io = (&k);
			((io)->value_).i = (key);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		cell = luaH_newkey(L, t, &k);
	}
	{
		TValue *io1 = (cell);
		const TValue *io2 = (value);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
}
static lua_Unsigned hash_search(Table *t, lua_Unsigned j)
{
	lua_Unsigned i;
	if (j == 0)
		j++;
	do
	{
		i = j;
		if (j <= ((lua_Unsigned) (LUA_MAXINTEGER)) / 2)
			j *= 2;
		else
		{
			j = LUA_MAXINTEGER;
			if ((((((((luaH_getint(t, j)))->tt_)) & 0x0F)) == (0)))
				break;
			else
				return j;
		}
	} while (!(((((((luaH_getint(t, j)))->tt_)) & 0x0F)) == (0)));

	while (j - i > 1u)
	{
		lua_Unsigned m = (i + j) / 2;
		if ((((((((luaH_getint(t, m)))->tt_)) & 0x0F)) == (0)))
			j = m;
		else
			i = m;
	}
	return i;
}

static unsigned int binsearch(const TValue *array, unsigned int i, unsigned int j)
{
	while (j - i > 1u)
	{
		unsigned int m = (i + j) / 2;
		if ((((((((&array[m - 1]))->tt_)) & 0x0F)) == (0)))
			j = m;
		else
			i = m;
	}
	return i;
}
lua_Unsigned luaH_getn(Table *t)
{
	unsigned int limit = t->alimit;
	if (limit > 0 && (((((((&t->array[limit - 1]))->tt_)) & 0x0F)) == (0)))
	{

		if (limit >= 2 && !(((((((&t->array[limit - 2]))->tt_)) & 0x0F)) == (0)))
		{

			if (ispow2realasize(t) && !(((limit - 1) & ((limit - 1) - 1)) == 0))
			{
				t->alimit = limit - 1;
				((t)->flags |= (1 << 7));
			}
			return limit - 1;
		}
		else
		{
			unsigned int boundary = binsearch(t->array, 0, limit);

			if (ispow2realasize(t) && boundary > luaH_realasize(t) / 2)
			{
				t->alimit = boundary;
				((t)->flags |= (1 << 7));
			}
			return boundary;
		}
	}

	if (!((!((t)->flags & (1 << 7))) || ((((t)->alimit) & (((t)->alimit) - 1)) == 0)))
	{

		if ((((((((&t->array[limit]))->tt_)) & 0x0F)) == (0)))
			return limit;

		limit = luaH_realasize(t);
		if ((((((((&t->array[limit - 1]))->tt_)) & 0x0F)) == (0)))
		{

			unsigned int boundary = binsearch(t->array, t->alimit, limit);
			t->alimit = boundary;
			return boundary;
		}
	}

	((void) 0);

	if (((t)->lastfree == NULL) ||
		(((((((luaH_getint(t, ((lua_Integer) (limit + 1)))))->tt_)) & 0x0F)) == (0)))
		return limit;
	else
		return hash_search(t, limit);
}
