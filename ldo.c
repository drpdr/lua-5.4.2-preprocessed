

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
struct lua_longjmp
{
	struct lua_longjmp *previous;
	jmp_buf b;
	volatile int status;
};

void luaD_seterrorobj(lua_State *L, int errcode, StkId oldtop)
{
	switch (errcode)
	{
	case 4:
	{
		{
			TValue *io = ((&(oldtop)->val));
			TString *x_ = ((L->l_G)->memerrmsg);
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) L, ((void) 0));
		};
		break;
	}
	case 5:
	{
		{
			TValue *io = ((&(oldtop)->val));
			TString *x_ = ((luaS_newlstr(L,
										 ""
										 "error in error handling",
										 (sizeof("error in error handling") / sizeof(char)) - 1)));
			((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void) L, ((void) 0));
		};
		break;
	}
	case (-2):
	{
		(((&(oldtop)->val))->tt_ = (((0) | ((0) << 4))));
		break;
	}
	default:
	{
		{
			TValue *io1 = ((&(oldtop)->val));
			const TValue *io2 = ((&(L->top - 1)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		break;
	}
	}
	L->top = oldtop + 1;
}

void __attribute__((noreturn)) luaD_throw(lua_State *L, int errcode)
{
	if (L->errorJmp)
	{
		L->errorJmp->status = errcode;
		longjmp((L->errorJmp)->b, 1);
	}
	else
	{
		global_State *g = (L->l_G);
		errcode = luaF_close(L, L->stack, errcode);
		L->status = ((lu_byte) ((errcode)));
		if (g->mainthread->errorJmp)
		{
			{
				TValue *io1 = ((&(g->mainthread->top++)->val));
				const TValue *io2 = ((&(L->top - 1)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			luaD_throw(g->mainthread, errcode);
		}
		else
		{
			if (g->panic)
			{
				luaD_seterrorobj(L, errcode, L->top);
				if (L->ci->top < L->top)
					L->ci->top = L->top;
				((void) 0);
				g->panic(L);
			}
			abort();
		}
	}
}

int luaD_rawrunprotected(lua_State *L, Pfunc f, void *ud)
{
	l_uint32 oldnCcalls = L->nCcalls;
	struct lua_longjmp lj;
	lj.status = 0;
	lj.previous = L->errorJmp;
	L->errorJmp = &lj;
	if (setjmp((&lj)->b) == 0)
	{
		(*f)(L, ud);
	};

	L->errorJmp = lj.previous;
	L->nCcalls = oldnCcalls;
	return lj.status;
}
static void correctstack(lua_State *L, StkId oldstack, StkId newstack)
{
	CallInfo *ci;
	UpVal *up;
	if (oldstack == newstack)
		return;
	L->top = (L->top - oldstack) + newstack;
	for (up = L->openupval; up != NULL; up = up->u.open.next)
		up->v = (&(((((StkId) ((up)->v))) - oldstack) + newstack)->val);
	for (ci = L->ci; ci != NULL; ci = ci->previous)
	{
		ci->top = (ci->top - oldstack) + newstack;
		ci->func = (ci->func - oldstack) + newstack;
		if ((!((ci)->callstatus & (1 << 1))))
			ci->u.l.trap = 1;
	}
}

int luaD_reallocstack(lua_State *L, int newsize, int raiseerror)
{
	int lim = ((int) (((L)->stack_last - (L)->stack)));
	StkId newstack =
		(((StackValue *) (luaM_realloc_(L, L->stack, ((size_t) ((lim + 5))) * sizeof(StackValue),
										((size_t) ((newsize + 5))) * sizeof(StackValue)))));

	((void) 0);
	if ((__builtin_expect(((newstack == NULL) != 0), 0)))
	{
		if (raiseerror)
			luaD_throw(L, 4);
		else
			return 0;
	}
	for (; lim < newsize; lim++)
		(((&(newstack + lim + 5)->val))->tt_ = (((0) | ((0) << 4))));
	correctstack(L, L->stack, newstack);
	L->stack = newstack;
	L->stack_last = L->stack + newsize;
	return 1;
}

int luaD_growstack(lua_State *L, int n, int raiseerror)
{
	int size = ((int) (((L)->stack_last - (L)->stack)));
	if ((__builtin_expect(((size > 15000) != 0), 0)))
	{

		((void) 0);
		if (raiseerror)
			luaD_throw(L, 5);
		return 0;
	}
	else
	{
		int newsize = 2 * size;
		int needed = ((int) ((L->top - L->stack))) + n;
		if (newsize > 15000)
			newsize = 15000;
		if (newsize < needed)
			newsize = needed;
		if ((__builtin_expect(((newsize <= 15000) != 0), 1)))
			return luaD_reallocstack(L, newsize, raiseerror);
		else
		{

			luaD_reallocstack(L, (15000 + 200), raiseerror);
			if (raiseerror)
				luaG_runerror(L, "stack overflow");
			return 0;
		}
	}
}

static int stackinuse(lua_State *L)
{
	CallInfo *ci;
	int res;
	StkId lim = L->top;
	for (ci = L->ci; ci != NULL; ci = ci->previous)
	{
		if (lim < ci->top)
			lim = ci->top;
	}
	((void) 0);
	res = ((int) ((lim - L->stack))) + 1;
	if (res < 20)
		res = 20;
	return res;
}
void luaD_shrinkstack(lua_State *L)
{
	int inuse = stackinuse(L);
	int nsize = inuse * 2;
	int max = inuse * 3;
	if (max > 15000)
	{
		max = 15000;
		if (nsize > 15000)
			nsize = 15000;
	}

	if (inuse <= 15000 && ((int) (((L)->stack_last - (L)->stack))) > max)
		luaD_reallocstack(L, nsize, 0);
	else
		((void) 0);
	luaE_shrinkCI(L);
}

void luaD_inctop(lua_State *L)
{
	if (L->stack_last - L->top <= (1))
	{
		(void) 0;
		luaD_growstack(L, 1, 1);
		(void) 0;
	}
	else
	{
		((void) 0);
	};
	L->top++;
}
void luaD_hook(lua_State *L, int event, int line, int ftransfer, int ntransfer)
{
	lua_Hook hook = L->hook;
	if (hook && L->allowhook)
	{
		int mask = (1 << 3);
		CallInfo *ci = L->ci;
		ptrdiff_t top = ((char *) (L->top) - (char *) L->stack);
		ptrdiff_t ci_top = ((char *) (ci->top) - (char *) L->stack);
		lua_Debug ar;
		ar.event = event;
		ar.currentline = line;
		ar.i_ci = ci;
		if (ntransfer != 0)
		{
			mask |= (1 << 8);
			ci->u2.transferinfo.ftransfer = ftransfer;
			ci->u2.transferinfo.ntransfer = ntransfer;
		}
		if (L->stack_last - L->top <= (20))
		{
			(void) 0;
			luaD_growstack(L, 20, 1);
			(void) 0;
		}
		else
		{
			((void) 0);
		};
		if (L->top + 20 > ci->top)
			ci->top = L->top + 20;
		L->allowhook = 0;
		ci->callstatus |= mask;
		((void) 0);
		(*hook)(L, &ar);
		((void) 0);
		((void) 0);
		L->allowhook = 1;
		ci->top = ((StkId) ((char *) L->stack + (ci_top)));
		L->top = ((StkId) ((char *) L->stack + (top)));
		ci->callstatus &= ~mask;
	}
}

void luaD_hookcall(lua_State *L, CallInfo *ci)
{
	int hook = (ci->callstatus & (1 << 5)) ? 4 : 0;
	Proto *p;
	if (!(L->hookmask & (1 << 0)))
		return;
	p = ((&((((union GCUnion *) (((((&(ci->func)->val))->value_).gc))))->cl.l)))->p;
	L->top = ci->top;
	ci->u.l.savedpc++;
	luaD_hook(L, hook, -1, 1, p->numparams);
	ci->u.l.savedpc--;
}

static StkId rethook(lua_State *L, CallInfo *ci, StkId firstres, int nres)
{
	ptrdiff_t oldtop = ((char *) (L->top) - (char *) L->stack);
	int delta = 0;
	if ((!((ci)->callstatus & ((1 << 1) | (1 << 3)))))
	{
		Proto *p = (((&((((union GCUnion *) (((((&((ci)->func)->val))->value_).gc))))->cl.l))))->p;
		if (p->is_vararg)
			delta = ci->u.l.nextraargs + p->numparams + 1;
		if (L->top < ci->top)
			L->top = ci->top;
	}
	if (L->hookmask & (1 << 1))
	{
		int ftransfer;
		ci->func += delta;
		ftransfer = ((unsigned short) (firstres - ci->func));
		luaD_hook(L, 1, -1, ftransfer, nres);
		ci->func -= delta;
	}
	if ((!((ci = ci->previous)->callstatus & (1 << 1))))
		L->oldpc =
			(((int) ((
				 (ci->u.l.savedpc) -
				 ((((&((((union GCUnion *) (((((&((ci)->func)->val))->value_).gc))))->cl.l))))->p)
					 ->code))) -
			 1);
	return ((StkId) ((char *) L->stack + (oldtop)));
}

void luaD_tryfuncTM(lua_State *L, StkId func)
{
	const TValue *tm = luaT_gettmbyobj(L, (&(func)->val), TM_CALL);
	StkId p;
	if ((__builtin_expect((((((((((tm))->tt_)) & 0x0F)) == (0))) != 0), 0)))
		luaG_typeerror(L, (&(func)->val), "call");
	for (p = L->top; p > func; p--)
	{
		TValue *io1 = ((&(p)->val));
		const TValue *io2 = ((&(p - 1)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	L->top++;
	{
		TValue *io1 = ((&(func)->val));
		const TValue *io2 = (tm);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
}
static void moveresults(lua_State *L, StkId res, int nres, int wanted)
{
	StkId firstresult;
	int i;
	switch (wanted)
	{
	case 0:
		L->top = res;
		return;
	case 1:
		if (nres == 0)
			(((&(res)->val))->tt_ = (((0) | ((0) << 4))));
		else
		{
			TValue *io1 = ((&(res)->val));
			const TValue *io2 = ((&(L->top - nres)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		L->top = res + 1;
		return;
	case (-1):
		wanted = nres;
		break;
	default:
		if (((wanted) < (-1)))
		{
			ptrdiff_t savedres = ((char *) (res) - (char *) L->stack);
			luaF_close(L, res, 0);
			res = ((StkId) ((char *) L->stack + (savedres)));
			wanted = (-(wanted) -3);
			if (wanted == (-1))
				wanted = nres;
		}
		break;
	}
	firstresult = L->top - nres;

	for (i = 0; i < nres && i < wanted; i++)
	{
		TValue *io1 = ((&(res + i)->val));
		const TValue *io2 = ((&(firstresult + i)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	for (; i < wanted; i++)
		(((&(res + i)->val))->tt_ = (((0) | ((0) << 4))));
	L->top = res + wanted;
}

void luaD_poscall(lua_State *L, CallInfo *ci, int nres)
{
	if (L->hookmask)
		L->top = rethook(L, ci, L->top - nres, nres);
	L->ci = ci->previous;

	moveresults(L, ci->func, nres, ci->nresults);
}
void luaD_pretailcall(lua_State *L, CallInfo *ci, StkId func, int narg1)
{
	Proto *p = ((&((((union GCUnion *) (((((&(func)->val))->value_).gc))))->cl.l)))->p;
	int fsize = p->maxstacksize;
	int nfixparams = p->numparams;
	int i;
	for (i = 0; i < narg1; i++)
	{
		TValue *io1 = ((&(ci->func + i)->val));
		const TValue *io2 = ((&(func + i)->val));
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	if (L->stack_last - L->top <= ((fsize)))
	{
		{
			if ((L->l_G)->GCdebt > 0)
			{
				(void) 0;
				luaC_step(L);
				(void) 0;
			};
			((void) 0);
		};
		luaD_growstack(L, (fsize), 1);
		(void) 0;
	}
	else
	{
		((void) 0);
	};
	func = ci->func;
	for (; narg1 <= nfixparams; narg1++)
		(((&(func + narg1)->val))->tt_ = (((0) | ((0) << 4))));
	ci->top = func + 1 + fsize;
	((void) 0);
	ci->u.l.savedpc = p->code;
	ci->callstatus |= (1 << 5);
	L->top = func + narg1;
}
CallInfo *luaD_precall(lua_State *L, StkId func, int nresults)
{
	lua_CFunction f;
retry:
	switch ((((((&(func)->val))->tt_)) & 0x3F))
	{
	case ((6) | ((2) << 4)):
		f = ((&((((union GCUnion *) (((((&(func)->val))->value_).gc))))->cl.c)))->f;
		goto Cfunc;
	case ((6) | ((1) << 4)):
		f = ((((&(func)->val))->value_).f);
	Cfunc:
	{
		int n;
		CallInfo *ci;
		if (L->stack_last - L->top <= (20))
		{
			ptrdiff_t t__ = ((char *) (func) - (char *) L->stack);
			{
				if ((L->l_G)->GCdebt > 0)
				{
					(void) 0;
					luaC_step(L);
					(void) 0;
				};
				((void) 0);
			};
			luaD_growstack(L, 20, 1);
			func = ((StkId) ((char *) L->stack + (t__)));
		}
		else
		{
			((void) 0);
		};
		L->ci = ci = (L->ci->next ? L->ci->next : luaE_extendCI(L));
		ci->nresults = nresults;
		ci->callstatus = (1 << 1);
		ci->top = L->top + 20;
		ci->func = func;
		((void) 0);
		if (L->hookmask & (1 << 0))
		{
			int narg = ((int) ((L->top - func))) - 1;
			luaD_hook(L, 0, -1, 1, narg);
		}
		((void) 0);
		n = (*f)(L);
		((void) 0);
		((void) L, ((void) 0));
		luaD_poscall(L, ci, n);
		return NULL;
	}
	case ((6) | ((0) << 4)):
	{
		CallInfo *ci;
		Proto *p = ((&((((union GCUnion *) (((((&(func)->val))->value_).gc))))->cl.l)))->p;
		int narg = ((int) ((L->top - func))) - 1;
		int nfixparams = p->numparams;
		int fsize = p->maxstacksize;
		if (L->stack_last - L->top <= (fsize))
		{
			ptrdiff_t t__ = ((char *) (func) - (char *) L->stack);
			{
				if ((L->l_G)->GCdebt > 0)
				{
					(void) 0;
					luaC_step(L);
					(void) 0;
				};
				((void) 0);
			};
			luaD_growstack(L, fsize, 1);
			func = ((StkId) ((char *) L->stack + (t__)));
		}
		else
		{
			((void) 0);
		};
		L->ci = ci = (L->ci->next ? L->ci->next : luaE_extendCI(L));
		ci->nresults = nresults;
		ci->u.l.savedpc = p->code;
		ci->top = func + 1 + fsize;
		ci->func = func;
		L->ci = ci;
		for (; narg < nfixparams; narg++)
			(((&(L->top++)->val))->tt_ = (((0) | ((0) << 4))));
		((void) 0);
		return ci;
	}
	default:
	{
		if (L->stack_last - L->top <= (1))
		{
			ptrdiff_t t__ = ((char *) (func) - (char *) L->stack);
			{
				if ((L->l_G)->GCdebt > 0)
				{
					(void) 0;
					luaC_step(L);
					(void) 0;
				};
				((void) 0);
			};
			luaD_growstack(L, 1, 1);
			func = ((StkId) ((char *) L->stack + (t__)));
		}
		else
		{
			((void) 0);
		};
		luaD_tryfuncTM(L, func);
		goto retry;
	}
	}
}

static void ccall(lua_State *L, StkId func, int nResults, int inc)
{
	CallInfo *ci;
	L->nCcalls += inc;
	if ((__builtin_expect(((((L)->nCcalls & 0xffff) >= 200) != 0), 0)))
		luaE_checkcstack(L);
	if ((ci = luaD_precall(L, func, nResults)) != NULL)
	{
		ci->callstatus = (1 << 2);
		luaV_execute(L, ci);
	}
	L->nCcalls -= inc;
}

void luaD_call(lua_State *L, StkId func, int nResults)
{
	ccall(L, func, nResults, 1);
}

void luaD_callnoyield(lua_State *L, StkId func, int nResults)
{
	ccall(L, func, nResults, (0x10000 | 1));
}

static void finishCcall(lua_State *L, int status)
{
	CallInfo *ci = L->ci;
	int n;

	((void) 0);

	((void) 0);
	if (ci->callstatus & (1 << 4))
	{
		ci->callstatus &= ~(1 << 4);
		L->errfunc = ci->u.c.old_errfunc;
	}

	{
		if ((ci->nresults) <= (-1) && L->ci->top < L->top)
			L->ci->top = L->top;
	};
	((void) 0);
	n = (*ci->u.c.k)(L, status, ci->u.c.ctx);
	((void) 0);
	((void) L, ((void) 0));
	luaD_poscall(L, ci, n);
}
static void unroll(lua_State *L, void *ud)
{
	CallInfo *ci;
	if (ud != NULL)
		finishCcall(L, *(int *) ud);
	while ((ci = L->ci) != &L->base_ci)
	{
		if (!(!((ci)->callstatus & (1 << 1))))
			finishCcall(L, 1);
		else
		{
			luaV_finishOp(L);
			luaV_execute(L, ci);
		}
	}
}

static CallInfo *findpcall(lua_State *L)
{
	CallInfo *ci;
	for (ci = L->ci; ci != NULL; ci = ci->previous)
	{
		if (ci->callstatus & (1 << 4))
			return ci;
	}
	return NULL;
}

static int recover(lua_State *L, int status)
{
	StkId oldtop;
	CallInfo *ci = findpcall(L);
	if (ci == NULL)
		return 0;

	oldtop = ((StkId) ((char *) L->stack + (ci->u2.funcidx)));
	L->ci = ci;
	L->allowhook = ((ci->callstatus) & (1 << 0));
	status = luaF_close(L, oldtop, status);
	oldtop = ((StkId) ((char *) L->stack + (ci->u2.funcidx)));
	luaD_seterrorobj(L, status, oldtop);
	luaD_shrinkstack(L);
	L->errfunc = ci->u.c.old_errfunc;
	return 1;
}

static int resume_error(lua_State *L, const char *msg, int narg)
{
	L->top -= narg;
	{
		TValue *io = ((&(L->top)->val));
		TString *x_ = (luaS_new(L, msg));
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void) L, ((void) 0));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	((void) 0);
	return 2;
}
static void resume(lua_State *L, void *ud)
{
	int n = *(((int *) (ud)));
	StkId firstArg = L->top - n;
	CallInfo *ci = L->ci;
	if (L->status == 0)
		ccall(L, firstArg - 1, (-1), 1);
	else
	{
		((void) 0);
		L->status = 0;
		luaE_incCstack(L);
		if ((!((ci)->callstatus & (1 << 1))))
			luaV_execute(L, ci);
		else
		{
			if (ci->u.c.k != NULL)
			{
				((void) 0);
				n = (*ci->u.c.k)(L, 1, ci->u.c.ctx);
				((void) 0);
				((void) L, ((void) 0));
			}
			luaD_poscall(L, ci, n);
		}
		unroll(L, NULL);
	}
}

extern int lua_resume(lua_State *L, lua_State *from, int nargs, int *nresults)
{
	int status;
	((void) 0);
	if (L->status == 0)
	{
		if (L->ci != &L->base_ci)
			return resume_error(L, "cannot resume non-suspended coroutine", nargs);
		else if (L->top - (L->ci->func + 1) == nargs)
			return resume_error(L, "cannot resume dead coroutine", nargs);
	}
	else if (L->status != 1)
		return resume_error(L, "cannot resume dead coroutine", nargs);
	L->nCcalls = (from) ? ((from)->nCcalls & 0xffff) : 0;
	((void) L);
	((void) L, ((void) 0));
	status = luaD_rawrunprotected(L, resume, &nargs);

	while (((status) > 1) && recover(L, status))
	{

		status = luaD_rawrunprotected(L, unroll, &status);
	}
	if ((__builtin_expect(((!((status) > 1)) != 0), 1)))
		((void) 0);
	else
	{
		L->status = ((lu_byte) ((status)));
		luaD_seterrorobj(L, status, L->top);
		L->ci->top = L->top;
	}
	*nresults = (status == 1) ? L->ci->u2.nyield : ((int) ((L->top - (L->ci->func + 1))));
	((void) 0);
	return status;
}

extern int lua_isyieldable(lua_State *L)
{
	return (((L)->nCcalls & 0xffff0000) == 0);
}

extern int lua_yieldk(lua_State *L, int nresults, lua_KContext ctx, lua_KFunction k)
{
	CallInfo *ci;
	((void) L);
	((void) 0);
	ci = L->ci;
	((void) L, ((void) 0));
	if ((__builtin_expect(((!(((L)->nCcalls & 0xffff0000) == 0)) != 0), 0)))
	{
		if (L != (L->l_G)->mainthread)
			luaG_runerror(L, "attempt to yield across a C-call boundary");
		else
			luaG_runerror(L, "attempt to yield from outside a coroutine");
	}
	L->status = 1;
	if ((!((ci)->callstatus & (1 << 1))))
	{
		((void) 0);
		((void) L, ((void) 0));
		ci->u2.nyield = 0;
	}
	else
	{
		if ((ci->u.c.k = k) != NULL)
			ci->u.c.ctx = ctx;
		ci->u2.nyield = nresults;
		luaD_throw(L, 1);
	}
	((void) 0);
	((void) 0);
	return 0;
}

int luaD_pcall(lua_State *L, Pfunc func, void *u, ptrdiff_t old_top, ptrdiff_t ef)
{
	int status;
	CallInfo *old_ci = L->ci;
	lu_byte old_allowhooks = L->allowhook;
	ptrdiff_t old_errfunc = L->errfunc;
	L->errfunc = ef;
	status = luaD_rawrunprotected(L, func, u);
	if ((__builtin_expect(((status != 0) != 0), 0)))
	{
		StkId oldtop = ((StkId) ((char *) L->stack + (old_top)));
		L->ci = old_ci;
		L->allowhook = old_allowhooks;
		status = luaF_close(L, oldtop, status);
		oldtop = ((StkId) ((char *) L->stack + (old_top)));
		luaD_seterrorobj(L, status, oldtop);
		luaD_shrinkstack(L);
	}
	L->errfunc = old_errfunc;
	return status;
}

struct SParser
{
	ZIO *z;
	Mbuffer buff;
	Dyndata dyd;
	const char *mode;
	const char *name;
};

static void checkmode(lua_State *L, const char *mode, const char *x)
{
	if (mode && strchr(mode, x[0]) == NULL)
	{
		luaO_pushfstring(L, "attempt to load a %s chunk (mode is '%s')", x, mode);
		luaD_throw(L, 3);
	}
}

static void f_parser(lua_State *L, void *ud)
{
	LClosure *cl;
	struct SParser *p = ((struct SParser *) (ud));
	int c = (((p->z)->n--) > 0 ? ((unsigned char) ((*(p->z)->p++))) : luaZ_fill(p->z));
	if (c == "\x1bLua"[0])
	{
		checkmode(L, p->mode, "binary");
		cl = luaU_undump(L, p->z, p->name);
	}
	else
	{
		checkmode(L, p->mode, "text");
		cl = luaY_parser(L, p->z, &p->buff, &p->dyd, p->name, c);
	}
	((void) 0);
	luaF_initupvals(L, cl);
}

int luaD_protectedparser(lua_State *L, ZIO *z, const char *name, const char *mode)
{
	struct SParser p;
	int status;
	((L)->nCcalls += 0x10000);
	p.z = z;
	p.name = name;
	p.mode = mode;
	p.dyd.actvar.arr = NULL;
	p.dyd.actvar.size = 0;
	p.dyd.gt.arr = NULL;
	p.dyd.gt.size = 0;
	p.dyd.label.arr = NULL;
	p.dyd.label.size = 0;
	((&p.buff)->buffer = NULL, (&p.buff)->buffsize = 0);
	status = luaD_pcall(L, f_parser, &p, ((char *) (L->top) - (char *) L->stack), L->errfunc);
	((&p.buff)->buffer = ((char *) ((luaM_saferealloc_(
		 L, ((&p.buff)->buffer), ((&p.buff)->buffsize) * sizeof(char), (0) * sizeof(char))))),
	 (&p.buff)->buffsize = 0);
	luaM_free_(L, (p.dyd.actvar.arr), (p.dyd.actvar.size) * sizeof(*(p.dyd.actvar.arr)));
	luaM_free_(L, (p.dyd.gt.arr), (p.dyd.gt.size) * sizeof(*(p.dyd.gt.arr)));
	luaM_free_(L, (p.dyd.label.arr), (p.dyd.label.size) * sizeof(*(p.dyd.label.arr)));
	((L)->nCcalls -= 0x10000);
	return status;
}
