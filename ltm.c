

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

static const char udatatypename[] = "userdata";

const char *const luaT_typenames_[((9 + 1) + 2)] = {
	"no value", "nil",		"boolean",	   udatatypename, "number",	 "string",
	"table",	"function", udatatypename, "thread",	  "upvalue", "proto"};

void luaT_init(lua_State *L)
{
	static const char *const luaT_eventname[] = {
		"__index", "__newindex", "__gc",   "__mode", "__len", "__eq",	"__add",
		"__sub",   "__mul",		 "__mod",  "__pow",	 "__div", "__idiv", "__band",
		"__bor",   "__bxor",	 "__shl",  "__shr",	 "__unm", "__bnot", "__lt",
		"__le",	   "__concat",	 "__call", "__close"};
	int i;
	for (i = 0; i < TM_N; i++)
	{
		(L->l_G)->tmname[i] = luaS_new(L, luaT_eventname[i]);
		luaC_fix(L, (&(((union GCUnion *) (((L->l_G)->tmname[i])))->gc)));
	}
}

const TValue *luaT_gettm(Table *events, TMS event, TString *ename)
{
	const TValue *tm = luaH_getshortstr(events, ename);
	((void) 0);
	if ((((((((tm))->tt_)) & 0x0F)) == (0)))
	{
		events->flags |= ((lu_byte) ((1u << event)));
		return NULL;
	}
	else
		return tm;
}

const TValue *luaT_gettmbyobj(lua_State *L, const TValue *o, TMS event)
{
	Table *mt;
	switch ((((((o)->tt_)) & 0x0F)))
	{
	case 5:
		mt = ((&((((union GCUnion *) ((((o)->value_).gc))))->h)))->metatable;
		break;
	case 7:
		mt = ((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->metatable;
		break;
	default:
		mt = (L->l_G)->mt[(((((o)->tt_)) & 0x0F))];
	}
	return (mt ? luaH_getshortstr(mt, (L->l_G)->tmname[event]) : &(L->l_G)->nilvalue);
}

const char *luaT_objtypename(lua_State *L, const TValue *o)
{
	Table *mt;
	if ((((((o))->tt_) == (((((5) | ((0) << 4))) | (1 << 6)))) &&
		 (mt = ((&((((union GCUnion *) ((((o)->value_).gc))))->h)))->metatable) != NULL) ||
		(((((o))->tt_) == (((((7) | ((0) << 4))) | (1 << 6)))) &&
		 (mt = ((&((((union GCUnion *) ((((o)->value_).gc))))->u)))->metatable) != NULL))
	{
		const TValue *name = luaH_getshortstr(mt, luaS_new(L, "__name"));
		if ((((((((name))->tt_)) & 0x0F)) == (4)))
			return ((((&((((union GCUnion *) ((((name)->value_).gc))))->ts))))->contents);
	}
	return luaT_typenames_[((((((o)->tt_)) & 0x0F))) + 1];
}

void luaT_callTM(lua_State *L, const TValue *f, const TValue *p1, const TValue *p2,
				 const TValue *p3)
{
	StkId func = L->top;
	{
		TValue *io1 = ((&(func)->val));
		const TValue *io2 = (f);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(func + 1)->val));
		const TValue *io2 = (p1);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(func + 2)->val));
		const TValue *io2 = (p2);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(func + 3)->val));
		const TValue *io2 = (p3);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	L->top = func + 4;

	if ((!((L->ci)->callstatus & ((1 << 1) | (1 << 3)))))
		luaD_call(L, func, 0);
	else
		luaD_callnoyield(L, func, 0);
}

void luaT_callTMres(lua_State *L, const TValue *f, const TValue *p1, const TValue *p2, StkId res)
{
	ptrdiff_t result = ((char *) (res) - (char *) L->stack);
	StkId func = L->top;
	{
		TValue *io1 = ((&(func)->val));
		const TValue *io2 = (f);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(func + 1)->val));
		const TValue *io2 = (p1);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(func + 2)->val));
		const TValue *io2 = (p2);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	L->top += 3;

	if ((!((L->ci)->callstatus & ((1 << 1) | (1 << 3)))))
		luaD_call(L, func, 1);
	else
		luaD_callnoyield(L, func, 1);
	res = ((StkId) ((char *) L->stack + (result)));
	{
		TValue *io1 = ((&(res)->val));
		const TValue *io2 = ((&(--L->top)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
}

static int callbinTM(lua_State *L, const TValue *p1, const TValue *p2, StkId res, TMS event)
{
	const TValue *tm = luaT_gettmbyobj(L, p1, event);
	if ((((((((tm))->tt_)) & 0x0F)) == (0)))
		tm = luaT_gettmbyobj(L, p2, event);
	if ((((((((tm))->tt_)) & 0x0F)) == (0)))
		return 0;
	luaT_callTMres(L, tm, p1, p2, res);
	return 1;
}

void luaT_trybinTM(lua_State *L, const TValue *p1, const TValue *p2, StkId res, TMS event)
{
	if (!callbinTM(L, p1, p2, res, event))
	{
		switch (event)
		{
		case TM_BAND:
		case TM_BOR:
		case TM_BXOR:
		case TM_SHL:
		case TM_SHR:
		case TM_BNOT:
		{
			if ((((((((p1))->tt_)) & 0x0F)) == (3)) && (((((((p2))->tt_)) & 0x0F)) == (3)))
				luaG_tointerror(L, p1, p2);
			else
				luaG_opinterror(L, p1, p2, "perform bitwise operation on");
		}

		default:
			luaG_opinterror(L, p1, p2, "perform arithmetic on");
		}
	}
}

void luaT_tryconcatTM(lua_State *L)
{
	StkId top = L->top;
	if (!callbinTM(L, (&(top - 2)->val), (&(top - 1)->val), top - 2, TM_CONCAT))
		luaG_concaterror(L, (&(top - 2)->val), (&(top - 1)->val));
}

void luaT_trybinassocTM(lua_State *L, const TValue *p1, const TValue *p2, int flip, StkId res,
						TMS event)
{
	if (flip)
		luaT_trybinTM(L, p2, p1, res, event);
	else
		luaT_trybinTM(L, p1, p2, res, event);
}

void luaT_trybiniTM(lua_State *L, const TValue *p1, lua_Integer i2, int flip, StkId res, TMS event)
{
	TValue aux;
	{
		TValue *io = (&aux);
		((io)->value_).i = (i2);
		((io)->tt_ = (((3) | ((0) << 4))));
	};
	luaT_trybinassocTM(L, p1, &aux, flip, res, event);
}
int luaT_callorderTM(lua_State *L, const TValue *p1, const TValue *p2, TMS event)
{
	if (callbinTM(L, p1, p2, L->top, event))
		return !((((((&(L->top)->val)))->tt_) == (((1) | ((0) << 4)))) ||
				 ((((((((&(L->top)->val)))->tt_)) & 0x0F)) == (0)));
	luaG_ordererror(L, p1, p2);
	return 0;
}

int luaT_callorderiTM(lua_State *L, const TValue *p1, int v2, int flip, int isfloat, TMS event)
{
	TValue aux;
	const TValue *p2;
	if (isfloat)
	{
		{
			TValue *io = (&aux);
			((io)->value_).n = (((lua_Number) ((v2))));
			((io)->tt_ = (((3) | ((1) << 4))));
		};
	}
	else
	{
		TValue *io = (&aux);
		((io)->value_).i = (v2);
		((io)->tt_ = (((3) | ((0) << 4))));
	};
	if (flip)
	{
		p2 = p1;
		p1 = &aux;
	}
	else
		p2 = &aux;
	return luaT_callorderTM(L, p1, p2, event);
}

void luaT_adjustvarargs(lua_State *L, int nfixparams, CallInfo *ci, const Proto *p)
{
	int i;
	int actual = ((int) ((L->top - ci->func))) - 1;
	int nextra = actual - nfixparams;
	ci->u.l.nextraargs = nextra;
	if (L->stack_last - L->top <= (p->maxstacksize + 1))
	{
		(void) 0;
		luaD_growstack(L, p->maxstacksize + 1, 1);
		(void) 0;
	}
	else
	{
		((void) 0);
	};

	{
		TValue *io1 = ((&(L->top++)->val));
		const TValue *io2 = ((&(ci->func)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};

	for (i = 1; i <= nfixparams; i++)
	{
		{
			TValue *io1 = ((&(L->top++)->val));
			const TValue *io2 = ((&(ci->func + i)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		(((&(ci->func + i)->val))->tt_ = (((0) | ((0) << 4))));
	}
	ci->func += actual + 1;
	ci->top += actual + 1;
	((void) 0);
}

void luaT_getvarargs(lua_State *L, CallInfo *ci, StkId where, int wanted)
{
	int i;
	int nextra = ci->u.l.nextraargs;
	if (wanted < 0)
	{
		wanted = nextra;
		if (L->stack_last - L->top <= (nextra))
		{
			ptrdiff_t t__ = ((char *) (where) - (char *) L->stack);
			{
				if ((L->l_G)->GCdebt > 0)
				{
					(void) 0;
					luaC_step(L);
					(void) 0;
				};
				((void) 0);
			};
			luaD_growstack(L, nextra, 1);
			where = ((StkId) ((char *) L->stack + (t__)));
		}
		else
		{
			((void) 0);
		};
		L->top = where + nextra;
	}
	for (i = 0; i < wanted && i < nextra; i++)
	{
		TValue *io1 = ((&(where + i)->val));
		const TValue *io2 = ((&(ci->func - nextra + i)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	for (; i < wanted; i++)
		(((&(where + i)->val))->tt_ = (((0) | ((0) << 4))));
}
