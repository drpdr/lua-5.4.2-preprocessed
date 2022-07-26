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
__attribute__((visibility("internal"))) extern const lu_byte luai_ctype_[UCHAR_MAX + 2];
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

int luaO_ceillog2(unsigned int x)
{
	static const lu_byte log_2[256] = {
		0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	int l = 0;
	x--;
	while (x >= 256)
	{
		l += 8;
		x >>= 8;
	}
	return l + log_2[x];
}

static lua_Integer intarith(lua_State *L, int op, lua_Integer v1, lua_Integer v2)
{
	switch (op)
	{
	case 0:
		return ((lua_Integer) (((lua_Unsigned) (v1)) + ((lua_Unsigned) (v2))));
	case 1:
		return ((lua_Integer) (((lua_Unsigned) (v1)) - ((lua_Unsigned) (v2))));
	case 2:
		return ((lua_Integer) (((lua_Unsigned) (v1)) * ((lua_Unsigned) (v2))));
	case 3:
		return luaV_mod(L, v1, v2);
	case 6:
		return luaV_idiv(L, v1, v2);
	case 7:
		return ((lua_Integer) (((lua_Unsigned) (v1)) & ((lua_Unsigned) (v2))));
	case 8:
		return ((lua_Integer) (((lua_Unsigned) (v1)) | ((lua_Unsigned) (v2))));
	case 9:
		return ((lua_Integer) (((lua_Unsigned) (v1)) ^ ((lua_Unsigned) (v2))));
	case 10:
		return luaV_shiftl(v1, v2);
	case 11:
		return luaV_shiftl(v1, -v2);
	case 12:
		return ((lua_Integer) (((lua_Unsigned) (0)) - ((lua_Unsigned) (v1))));
	case 13:
		return ((lua_Integer) (((lua_Unsigned) (~((lua_Unsigned) (0)))) ^ ((lua_Unsigned) (v1))));
	default:
		((void) 0);
		return 0;
	}
}

static lua_Number numarith(lua_State *L, int op, lua_Number v1, lua_Number v2)
{
	switch (op)
	{
	case 0:
		return ((v1) + (v2));
	case 1:
		return ((v1) - (v2));
	case 2:
		return ((v1) * (v2));
	case 5:
		return ((v1) / (v2));
	case 4:
		return ((void) L, (v2 == 2) ? (v1) * (v1) : pow(v1, v2));
	case 6:
		return ((void) L, (floor(((v1) / (v2)))));
	case 12:
		return (-(v1));
	case 3:
		return luaV_modf(L, v1, v2);
	default:
		((void) 0);
		return 0;
	}
}

int luaO_rawarith(lua_State *L, int op, const TValue *p1, const TValue *p2, TValue *res)
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
		lua_Integer i1;
		lua_Integer i2;
		if ((((((p1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((p1)->value_).i), 1)
													 : luaV_tointegerns(p1, &i1, F2Ieq)) &&
			(((((p2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((p2)->value_).i), 1)
													 : luaV_tointegerns(p2, &i2, F2Ieq)))
		{
			{
				TValue *io = (res);
				((io)->value_).i = (intarith(L, op, i1, i2));
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			return 1;
		}
		else
			return 0;
	}
	case 5:
	case 4:
	{
		lua_Number n1;
		lua_Number n2;
		if ((((((p1))->tt_) == (((3) | ((1) << 4))))
				 ? ((n1) = (((p1)->value_).n), 1)
				 : (((((p1))->tt_) == (((3) | ((0) << 4))))
						? ((n1) = ((lua_Number) (((((p1)->value_).i)))), 1)
						: 0)) &&
			(((((p2))->tt_) == (((3) | ((1) << 4))))
				 ? ((n2) = (((p2)->value_).n), 1)
				 : (((((p2))->tt_) == (((3) | ((0) << 4))))
						? ((n2) = ((lua_Number) (((((p2)->value_).i)))), 1)
						: 0)))
		{
			{
				TValue *io = (res);
				((io)->value_).n = (numarith(L, op, n1, n2));
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			return 1;
		}
		else
			return 0;
	}
	default:
	{
		lua_Number n1;
		lua_Number n2;
		if (((((p1))->tt_) == (((3) | ((0) << 4)))) && ((((p2))->tt_) == (((3) | ((0) << 4)))))
		{
			{
				TValue *io = (res);
				((io)->value_).i = (intarith(L, op, (((p1)->value_).i), (((p2)->value_).i)));
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			return 1;
		}
		else if ((((((p1))->tt_) == (((3) | ((1) << 4))))
					  ? ((n1) = (((p1)->value_).n), 1)
					  : (((((p1))->tt_) == (((3) | ((0) << 4))))
							 ? ((n1) = ((lua_Number) (((((p1)->value_).i)))), 1)
							 : 0)) &&
				 (((((p2))->tt_) == (((3) | ((1) << 4))))
					  ? ((n2) = (((p2)->value_).n), 1)
					  : (((((p2))->tt_) == (((3) | ((0) << 4))))
							 ? ((n2) = ((lua_Number) (((((p2)->value_).i)))), 1)
							 : 0)))
		{
			{
				TValue *io = (res);
				((io)->value_).n = (numarith(L, op, n1, n2));
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			return 1;
		}
		else
			return 0;
	}
	}
}

void luaO_arith(lua_State *L, int op, const TValue *p1, const TValue *p2, StkId res)
{
	if (!luaO_rawarith(L, op, p1, p2, (&(res)->val)))
	{

		luaT_trybinTM(L, p1, p2, res, ((TMS) ((op - 0) + TM_ADD)));
	}
}

int luaO_hexavalue(int c)
{
	if ((luai_ctype_[(c) + 1] & ((1 << (1)))))
		return c - '0';
	else
		return (((c) | ('A' ^ 'a')) - 'a') + 10;
}

static int isneg(const char **s)
{
	if (**s == '-')
	{
		(*s)++;
		return 1;
	}
	else if (**s == '+')
		(*s)++;
	return 0;
}
static const char *l_str2dloc(const char *s, lua_Number *result, int mode)
{
	char *endptr;
	*result = (mode == 'x') ? strtod((s), (&endptr)) : strtod((s), (&endptr));
	if (endptr == s)
		return NULL;
	while ((luai_ctype_[(((unsigned char) ((*endptr)))) + 1] & ((1 << (3)))))
		endptr++;
	return (*endptr == '\0') ? endptr : NULL;
}
static const char *l_str2d(const char *s, lua_Number *result)
{
	const char *endptr;
	const char *pmode = strpbrk(s, ".xXnN");
	int mode = pmode ? ((((unsigned char) ((*pmode)))) | ('A' ^ 'a')) : 0;
	if (mode == 'n')
		return NULL;
	endptr = l_str2dloc(s, result, mode);
	if (endptr == NULL)
	{
		char buff[200 + 1];
		const char *pdot = strchr(s, '.');
		if (pdot == NULL || strlen(s) > 200)
			return NULL;
		strcpy(buff, s);
		buff[pdot - s] = (localeconv()->decimal_point[0]);
		endptr = l_str2dloc(buff, result, mode);
		if (endptr != NULL)
			endptr = s + (endptr - buff);
	}
	return endptr;
}

static const char *l_str2int(const char *s, lua_Integer *result)
{
	lua_Unsigned a = 0;
	int empty = 1;
	int neg;
	while ((luai_ctype_[(((unsigned char) ((*s)))) + 1] & ((1 << (3)))))
		s++;
	neg = isneg(&s);
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		s += 2;
		for (; (luai_ctype_[(((unsigned char) ((*s)))) + 1] & ((1 << (4)))); s++)
		{
			a = a * 16 + luaO_hexavalue(*s);
			empty = 0;
		}
	}
	else
	{
		for (; (luai_ctype_[(((unsigned char) ((*s)))) + 1] & ((1 << (1)))); s++)
		{
			int d = *s - '0';
			if (a >= ((lua_Unsigned) (LUA_MAXINTEGER / 10)) &&
				(a > ((lua_Unsigned) (LUA_MAXINTEGER / 10)) ||
				 d > ((int) ((LUA_MAXINTEGER % 10))) + neg))
				return NULL;
			a = a * 10 + d;
			empty = 0;
		}
	}
	while ((luai_ctype_[(((unsigned char) ((*s)))) + 1] & ((1 << (3)))))
		s++;
	if (empty || *s != '\0')
		return NULL;
	else
	{
		*result = ((lua_Integer) ((neg) ? 0u - a : a));
		return s;
	}
}

size_t luaO_str2num(const char *s, TValue *o)
{
	lua_Integer i;
	lua_Number n;
	const char *e;
	if ((e = l_str2int(s, &i)) != NULL)
	{
		{
			TValue *io = (o);
			((io)->value_).i = (i);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
	}
	else if ((e = l_str2d(s, &n)) != NULL)
	{
		{
			TValue *io = (o);
			((io)->value_).n = (n);
			((io)->tt_ = (((3) | ((1) << 4))));
		};
	}
	else
		return 0;
	return (e - s) + 1;
}

int luaO_utf8esc(char *buff, unsigned long x)
{
	int n = 1;
	((void) 0);
	if (x < 0x80)
		buff[8 - 1] = ((char) ((x)));
	else
	{
		unsigned int mfb = 0x3f;
		do
		{
			buff[8 - (n++)] = ((char) ((0x80 | (x & 0x3f))));
			x >>= 6;
			mfb >>= 1;
		} while (x > mfb);
		buff[8 - n] = ((char) (((~mfb << 1) | x)));
	}
	return n;
}
static int tostringbuff(TValue *obj, char *buff)
{
	int len;
	((void) 0);
	if (((((obj))->tt_) == (((3) | ((0) << 4)))))
		len = snprintf((buff), 44, "%" LUA_INTEGER_FRMLEN "d", (LUA_INTEGER) ((((obj)->value_).i)));
	else
	{
		len = snprintf((buff), 44, "%.14g", (double) ((((obj)->value_).n)));
		if (buff[strspn(buff, "-0123456789")] == '\0')
		{
			buff[len++] = (localeconv()->decimal_point[0]);
			buff[len++] = '0';
		}
	}
	return len;
}

void luaO_tostring(lua_State *L, TValue *obj)
{
	char buff[44];
	int len = tostringbuff(obj, buff);
	{
		TValue *io = (obj);
		TString *x_ = (luaS_newlstr(L, buff, len));
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void) L, ((void) 0));
	};
}
typedef struct BuffFS
{
	lua_State *L;
	int pushed;
	int blen;
	char space[200];
} BuffFS;

static void pushstr(BuffFS *buff, const char *str, size_t l)
{
	lua_State *L = buff->L;
	{
		TValue *io = ((&(L->top)->val));
		TString *x_ = (luaS_newlstr(L, str, l));
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void) L, ((void) 0));
	};
	L->top++;
	buff->pushed++;
	luaV_concat(L, buff->pushed);
	buff->pushed = 1;
}

static void clearbuff(BuffFS *buff)
{
	pushstr(buff, buff->space, buff->blen);
	buff->blen = 0;
}

static char *getbuff(BuffFS *buff, int sz)
{
	((void) 0);
	((void) 0);
	if (sz > 200 - buff->blen)
		clearbuff(buff);
	return buff->space + buff->blen;
}
static void addstr2buff(BuffFS *buff, const char *str, size_t slen)
{
	if (slen <= 200)
	{
		char *bf = getbuff(buff, ((int) ((slen))));
		memcpy(bf, str, slen);
		((buff)->blen += (((int) ((slen)))));
	}
	else
	{
		clearbuff(buff);
		pushstr(buff, str, slen);
	}
}

static void addnum2buff(BuffFS *buff, TValue *num)
{
	char *numbuff = getbuff(buff, 44);
	int len = tostringbuff(num, numbuff);
	((buff)->blen += (len));
}

const char *luaO_pushvfstring(lua_State *L, const char *fmt, va_list argp)
{
	BuffFS buff;
	const char *e;
	buff.pushed = buff.blen = 0;
	buff.L = L;
	while ((e = strchr(fmt, '%')) != NULL)
	{
		addstr2buff(&buff, fmt, e - fmt);
		switch (*(e + 1))
		{
		case 's':
		{
			const char *s = va_arg(argp, char *);
			if (s == NULL)
				s = "(null)";
			addstr2buff(&buff, s, strlen(s));
			break;
		}
		case 'c':
		{
			char c = ((unsigned char) ((va_arg(argp, int))));
			addstr2buff(&buff, &c, sizeof(char));
			break;
		}
		case 'd':
		{
			TValue num;
			{
				TValue *io = (&num);
				((io)->value_).i = (va_arg(argp, int));
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			addnum2buff(&buff, &num);
			break;
		}
		case 'I':
		{
			TValue num;
			{
				TValue *io = (&num);
				((io)->value_).i = (((lua_Integer) (va_arg(argp, l_uacInt))));
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			addnum2buff(&buff, &num);
			break;
		}
		case 'f':
		{
			TValue num;
			{
				TValue *io = (&num);
				((io)->value_).n = (((lua_Number) ((va_arg(argp, l_uacNumber)))));
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			addnum2buff(&buff, &num);
			break;
		}
		case 'p':
		{
			const int sz = 3 * sizeof(void *) + 8;
			char *bf = getbuff(&buff, sz);
			void *p = va_arg(argp, void *);
			int len = snprintf(bf, sz, "%p", p);
			((&buff)->blen += (len));
			break;
		}
		case 'U':
		{
			char bf[8];
			int len = luaO_utf8esc(bf, va_arg(argp, long));
			addstr2buff(&buff, bf + 8 - len, len);
			break;
		}
		case '%':
		{
			addstr2buff(&buff, "%", 1);
			break;
		}
		default:
		{
			luaG_runerror(L, "invalid option '%%%c' to 'lua_pushfstring'", *(e + 1));
		}
		}
		fmt = e + 2;
	}
	addstr2buff(&buff, fmt, strlen(fmt));
	clearbuff(&buff);
	((void) 0);
	return ((((&((((union GCUnion *) (((((&(L->top - 1)->val))->value_).gc))))->ts))))->contents);
}

const char *luaO_pushfstring(lua_State *L, const char *fmt, ...)
{
	const char *msg;
	va_list argp;
	va_start(argp, fmt);
	msg = luaO_pushvfstring(L, fmt, argp);
	va_end(argp);
	return msg;
}
void luaO_chunkid(char *out, const char *source, size_t srclen)
{
	size_t bufflen = 60;
	if (*source == '=')
	{
		if (srclen <= bufflen)
			memcpy(out, source + 1, srclen * sizeof(char));
		else
		{
			(memcpy(out, source + 1, (bufflen - 1) * sizeof(char)), out += (bufflen - 1));
			*out = '\0';
		}
	}
	else if (*source == '@')
	{
		if (srclen <= bufflen)
			memcpy(out, source + 1, srclen * sizeof(char));
		else
		{
			(memcpy(out, "...", ((sizeof("...") / sizeof(char) - 1)) * sizeof(char)),
			 out += ((sizeof("...") / sizeof(char) - 1)));
			bufflen -= (sizeof("...") / sizeof(char) - 1);
			memcpy(out, source + 1 + srclen - bufflen, bufflen * sizeof(char));
		}
	}
	else
	{
		const char *nl = strchr(source, '\n');
		(memcpy(out, "[string \"", ((sizeof("[string \"") / sizeof(char) - 1)) * sizeof(char)),
		 out += ((sizeof("[string \"") / sizeof(char) - 1)));
		bufflen -= (sizeof("[string \""
						   "..."
						   "\"]") /
						sizeof(char) -
					1) +
				   1;
		if (srclen < bufflen && nl == NULL)
		{
			(memcpy(out, source, (srclen) * sizeof(char)), out += (srclen));
		}
		else
		{
			if (nl != NULL)
				srclen = nl - source;
			if (srclen > bufflen)
				srclen = bufflen;
			(memcpy(out, source, (srclen) * sizeof(char)), out += (srclen));
			(memcpy(out, "...", ((sizeof("...") / sizeof(char) - 1)) * sizeof(char)),
			 out += ((sizeof("...") / sizeof(char) - 1)));
		}
		memcpy(out, "\"]", ((sizeof("\"]") / sizeof(char) - 1) + 1) * sizeof(char));
	}
}
