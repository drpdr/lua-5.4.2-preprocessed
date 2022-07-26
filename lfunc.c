

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

CClosure *luaF_newCclosure(lua_State *L, int nupvals)
{
	GCObject *o = luaC_newobj(
		L, ((6) | ((2) << 4)),
		(((int) ((offsetof(CClosure, upvalue)))) + ((int) ((sizeof(TValue)))) * (nupvals)));
	CClosure *c = (&((((union GCUnion *) ((o))))->cl.c));
	c->nupvalues = ((lu_byte) ((nupvals)));
	return c;
}

LClosure *luaF_newLclosure(lua_State *L, int nupvals)
{
	GCObject *o = luaC_newobj(
		L, ((6) | ((0) << 4)),
		(((int) ((offsetof(LClosure, upvals)))) + ((int) ((sizeof(TValue *)))) * (nupvals)));
	LClosure *c = (&((((union GCUnion *) ((o))))->cl.l));
	c->p = NULL;
	c->nupvalues = ((lu_byte) ((nupvals)));
	while (nupvals--)
		c->upvals[nupvals] = NULL;
	return c;
}

void luaF_initupvals(lua_State *L, LClosure *cl)
{
	int i;
	for (i = 0; i < cl->nupvalues; i++)
	{
		GCObject *o = luaC_newobj(L, ((9) | ((0) << 4)), sizeof(UpVal));
		UpVal *uv = (&((((union GCUnion *) ((o))))->upv));
		uv->v = &uv->u.value;
		((uv->v)->tt_ = (((0) | ((0) << 4))));
		cl->upvals[i] = uv;
		(((((cl)->marked) & ((1 << (5)))) && (((uv)->marked) & (((1 << (3)) | (1 << (4))))))
			 ? luaC_barrier_(L, (&(((union GCUnion *) ((cl)))->gc)),
							 (&(((union GCUnion *) ((uv)))->gc)))
			 : ((void) ((0))));
	}
}

static UpVal *newupval(lua_State *L, int tbc, StkId level, UpVal **prev)
{
	GCObject *o = luaC_newobj(L, ((9) | ((0) << 4)), sizeof(UpVal));
	UpVal *uv = (&((((union GCUnion *) ((o))))->upv));
	UpVal *next = *prev;
	uv->v = (&(level)->val);
	uv->tbc = tbc;
	uv->u.open.next = next;
	uv->u.open.previous = prev;
	if (next)
		next->u.open.previous = &uv->u.open.next;
	*prev = uv;
	if (!(L->twups != L))
	{
		L->twups = (L->l_G)->twups;
		(L->l_G)->twups = L;
	}
	return uv;
}

UpVal *luaF_findupval(lua_State *L, StkId level)
{
	UpVal **pp = &L->openupval;
	UpVal *p;
	((void) 0);
	while ((p = *pp) != NULL && (((StkId) ((p)->v))) >= level)
	{
		((void) 0);
		if ((((StkId) ((p)->v))) == level)
			return p;
		pp = &p->u.open.next;
	}

	return newupval(L, 0, level, pp);
}

static void callclose(lua_State *L, void *ud)
{
	((void) (ud));
	luaD_callnoyield(L, L->top - 3, 0);
}

static int prepclosingmethod(lua_State *L, TValue *obj, TValue *err)
{
	StkId top = L->top;
	const TValue *tm = luaT_gettmbyobj(L, obj, TM_CLOSE);
	if ((((((((tm))->tt_)) & 0x0F)) == (0)))
		return 0;
	{
		TValue *io1 = ((&(top)->val));
		const TValue *io2 = (tm);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(top + 1)->val));
		const TValue *io2 = (obj);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	{
		TValue *io1 = ((&(top + 2)->val));
		const TValue *io2 = (err);
		io1->value_ = io2->value_;
		((io1)->tt_ = (io2->tt_));
		((void) L, ((void) 0));
		((void) 0);
	};
	L->top = top + 3;
	return 1;
}

static void varerror(lua_State *L, StkId level, const char *msg)
{
	int idx = ((int) ((level - L->ci->func)));
	const char *vname = luaG_findlocal(L, L->ci, idx, NULL);
	if (vname == NULL)
		vname = "?";
	luaG_runerror(L, msg, vname);
}
static int callclosemth(lua_State *L, StkId level, int status)
{
	TValue *uv = (&(level)->val);
	if ((__builtin_expect(((status == 0) != 0), 1)))
	{
		if (prepclosingmethod(L, uv, &(L->l_G)->nilvalue))
			callclose(L, NULL);
		else if (!(((((uv))->tt_) == (((1) | ((0) << 4)))) || (((((((uv))->tt_)) & 0x0F)) == (0))))
			varerror(L, level, "attempt to close non-closable variable '%s'");
	}
	else
	{
		ptrdiff_t oldtop;
		level++;
		oldtop = ((char *) (level + 1) - (char *) L->stack);
		luaD_seterrorobj(L, status, level);
		if (prepclosingmethod(L, uv, (&(level)->val)))
		{
			int newstatus = luaD_pcall(L, callclose, NULL, oldtop, 0);
			if (newstatus != 0 && status == (-2))
				status = newstatus;
			else
			{
				if (newstatus != 0)
					luaE_warnerror(L, "__close metamethod");

				L->top = ((StkId) ((char *) L->stack + (oldtop)));
			}
		}
	}
	return status;
}

static void trynewtbcupval(lua_State *L, void *ud)
{
	newupval(L, 1, ((StkId) (ud)), &L->openupval);
}

void luaF_newtbcupval(lua_State *L, StkId level)
{
	TValue *obj = (&(level)->val);
	((void) 0);
	if (!(((((obj))->tt_) == (((1) | ((0) << 4)))) || (((((((obj))->tt_)) & 0x0F)) == (0))))
	{
		int status;
		const TValue *tm = luaT_gettmbyobj(L, obj, TM_CLOSE);
		if ((((((((tm))->tt_)) & 0x0F)) == (0)))
			varerror(L, level, "variable '%s' got a non-closable value");
		status = luaD_rawrunprotected(L, trynewtbcupval, level);
		if ((__builtin_expect(((status != 0) != 0), 0)))
		{
			((void) 0);
			luaD_seterrorobj(L, 4, level + 1);

			prepclosingmethod(L, (&(level)->val), (&(level + 1)->val));
			callclose(L, NULL);
			luaD_throw(L, 4);
		}
	}
}

void luaF_unlinkupval(UpVal *uv)
{
	((void) 0);
	*uv->u.open.previous = uv->u.open.next;
	if (uv->u.open.next)
		uv->u.open.next->u.open.previous = uv->u.open.previous;
}

int luaF_close(lua_State *L, StkId level, int status)
{
	UpVal *uv;
	while ((uv = L->openupval) != NULL && (((StkId) ((uv)->v))) >= level)
	{
		TValue *slot = &uv->u.value;
		((void) 0);
		if (uv->tbc && status != (-1))
		{

			ptrdiff_t levelrel = ((char *) (level) - (char *) L->stack);
			status = callclosemth(L, (((StkId) ((uv)->v))), status);
			level = ((StkId) ((char *) L->stack + (levelrel)));
		}
		luaF_unlinkupval(uv);
		{
			TValue *io1 = (slot);
			const TValue *io2 = (uv->v);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		uv->v = slot;
		if (!(((uv)->marked) & (((1 << (3)) | (1 << (4))))))
		{
			((((uv)->marked) |= ((1 << (5)))));
			(((((slot)->tt_) & (1 << 6)) && (((uv)->marked) & ((1 << (5)))) &&
			  ((((((slot)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrier_(L, (&(((union GCUnion *) ((uv)))->gc)), (((slot)->value_).gc))
				 : ((void) ((0))));
		}
	}
	return status;
}

Proto *luaF_newproto(lua_State *L)
{
	GCObject *o = luaC_newobj(L, (((9 + 1)) | ((0) << 4)), sizeof(Proto));
	Proto *f = (&((((union GCUnion *) ((o))))->p));
	f->k = NULL;
	f->sizek = 0;
	f->p = NULL;
	f->sizep = 0;
	f->code = NULL;
	f->sizecode = 0;
	f->lineinfo = NULL;
	f->sizelineinfo = 0;
	f->abslineinfo = NULL;
	f->sizeabslineinfo = 0;
	f->upvalues = NULL;
	f->sizeupvalues = 0;
	f->numparams = 0;
	f->is_vararg = 0;
	f->maxstacksize = 0;
	f->locvars = NULL;
	f->sizelocvars = 0;
	f->linedefined = 0;
	f->lastlinedefined = 0;
	f->source = NULL;
	return f;
}

void luaF_freeproto(lua_State *L, Proto *f)
{
	luaM_free_(L, (f->code), (f->sizecode) * sizeof(*(f->code)));
	luaM_free_(L, (f->p), (f->sizep) * sizeof(*(f->p)));
	luaM_free_(L, (f->k), (f->sizek) * sizeof(*(f->k)));
	luaM_free_(L, (f->lineinfo), (f->sizelineinfo) * sizeof(*(f->lineinfo)));
	luaM_free_(L, (f->abslineinfo), (f->sizeabslineinfo) * sizeof(*(f->abslineinfo)));
	luaM_free_(L, (f->locvars), (f->sizelocvars) * sizeof(*(f->locvars)));
	luaM_free_(L, (f->upvalues), (f->sizeupvalues) * sizeof(*(f->upvalues)));
	luaM_free_(L, (f), sizeof(*(f)));
}

const char *luaF_getlocalname(const Proto *f, int local_number, int pc)
{
	int i;
	for (i = 0; i < f->sizelocvars && f->locvars[i].startpc <= pc; i++)
	{
		if (pc < f->locvars[i].endpc)
		{
			local_number--;
			if (local_number == 0)
				return ((f->locvars[i].varname)->contents);
		}
	}
	return NULL;
}
