

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
static void reallymarkobject(global_State *g, GCObject *o);
static lu_mem atomic(lua_State *L);
static void entersweep(lua_State *L);
static GCObject **getgclist(GCObject *o)
{
	switch (o->tt)
	{
	case ((5) | ((0) << 4)):
		return &(&((((union GCUnion *) ((o))))->h))->gclist;
	case ((6) | ((0) << 4)):
		return &(&((((union GCUnion *) ((o))))->cl.l))->gclist;
	case ((6) | ((2) << 4)):
		return &(&((((union GCUnion *) ((o))))->cl.c))->gclist;
	case ((8) | ((0) << 4)):
		return &(&((((union GCUnion *) ((o))))->th))->gclist;
	case (((9 + 1)) | ((0) << 4)):
		return &(&((((union GCUnion *) ((o))))->p))->gclist;
	case ((7) | ((0) << 4)):
	{
		Udata *u = (&((((union GCUnion *) ((o))))->u));
		((void) 0);
		return &u->gclist;
	}
	default:
		((void) 0);
		return 0;
	}
}
static void linkgclist_(GCObject *o, GCObject **pnext, GCObject **list)
{
	((void) 0);
	*pnext = *list;
	*list = o;
	((o->marked) &= ((lu_byte) ((~(((1 << (5)) | ((1 << (3)) | (1 << (4)))))))));
}
static void clearkey(Node *n)
{
	((void) 0);
	if ((((n)->u.key_tt) & (1 << 6)))
		(((n)->u.key_tt) = (9 + 2));
}
static int iscleared(global_State *g, const GCObject *o)
{
	if (o == NULL)
		return 0;
	else if (((o->tt) & 0x0F) == 4)
	{
		{
			if ((((o)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((o)))->gc)));
		};
		return 0;
	}
	else
		return (((o)->marked) & (((1 << (3)) | (1 << (4)))));
}
void luaC_barrier_(lua_State *L, GCObject *o, GCObject *v)
{
	global_State *g = (L->l_G);
	((void) 0);
	if (((g)->gcstate <= 2))
	{
		reallymarkobject(g, v);
		if ((((o)->marked & 7) > 1))
		{
			((void) 0);
			((v)->marked = ((lu_byte) ((((v)->marked & (~7)) | 2))));
		}
	}
	else
	{
		((void) 0);
		if (g->gckind == 0)
			(o->marked =
				 ((lu_byte) (((o->marked & ~((1 << (5)) | ((1 << (3)) | (1 << (4))))) |
							  ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))))))));
	}
}

void luaC_barrierback_(lua_State *L, GCObject *o)
{
	global_State *g = (L->l_G);
	((void) 0);
	((void) 0);
	if (((o)->marked & 7) == 6)
		((o->marked) &= ((lu_byte) ((~(((1 << (5)) | ((1 << (3)) | (1 << (4)))))))));
	else
		linkgclist_((&(((union GCUnion *) ((o)))->gc)), getgclist(o), &(g->grayagain));
	if ((((o)->marked & 7) > 1))
		((o)->marked = ((lu_byte) ((((o)->marked & (~7)) | 5))));
}

void luaC_fix(lua_State *L, GCObject *o)
{
	global_State *g = (L->l_G);
	((void) 0);
	((o->marked) &= ((lu_byte) ((~(((1 << (5)) | ((1 << (3)) | (1 << (4)))))))));
	((o)->marked = ((lu_byte) ((((o)->marked & (~7)) | 4))));
	g->allgc = o->next;
	o->next = g->fixedgc;
	g->fixedgc = o;
}

GCObject *luaC_newobj(lua_State *L, int tt, size_t sz)
{
	global_State *g = (L->l_G);
	GCObject *o = ((GCObject *) (luaM_malloc_(L, (sz), ((tt) &0x0F))));
	o->marked = ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))));
	o->tt = tt;
	o->next = g->allgc;
	g->allgc = o;
	return o;
}
static void reallymarkobject(global_State *g, GCObject *o)
{
	switch (o->tt)
	{
	case ((4) | ((0) << 4)):
	case ((4) | ((1) << 4)):
	{
		(o->marked = ((lu_byte) (((o->marked & ~((1 << (3)) | (1 << (4)))) | (1 << (5))))));
		break;
	}
	case ((9) | ((0) << 4)):
	{
		UpVal *uv = (&((((union GCUnion *) ((o))))->upv));
		if (((uv)->v != &(uv)->u.value))
			((uv->marked) &= ((lu_byte) ((~(((1 << (5)) | ((1 << (3)) | (1 << (4)))))))));
		else
			(uv->marked = ((lu_byte) (((uv->marked & ~((1 << (3)) | (1 << (4)))) | (1 << (5))))));
		{
			((void) g->mainthread, ((void) 0));
			if (((((uv->v)->tt_) & (1 << 6)) &&
				 ((((((uv->v)->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
				reallymarkobject(g, (((uv->v)->value_).gc));
		};
		break;
	}
	case ((7) | ((0) << 4)):
	{
		Udata *u = (&((((union GCUnion *) ((o))))->u));
		if (u->nuvalue == 0)
		{
			{
				if (u->metatable)
				{
					if ((((u->metatable)->marked) & (((1 << (3)) | (1 << (4))))))
						reallymarkobject(g, (&(((union GCUnion *) ((u->metatable)))->gc)));
				};
			};
			(u->marked = ((lu_byte) (((u->marked & ~((1 << (3)) | (1 << (4)))) | (1 << (5))))));
			break;
		}
	}
	case ((6) | ((0) << 4)):
	case ((6) | ((2) << 4)):
	case ((5) | ((0) << 4)):
	case ((8) | ((0) << 4)):
	case (((9 + 1)) | ((0) << 4)):
	{
		linkgclist_((&(((union GCUnion *) ((o)))->gc)), getgclist(o), &(g->gray));
		break;
	}
	default:
		((void) 0);
		break;
	}
}

static void markmt(global_State *g)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (g->mt[i])
		{
			if ((((g->mt[i])->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((g->mt[i])))->gc)));
		};
	};
}

static lu_mem markbeingfnz(global_State *g)
{
	GCObject *o;
	lu_mem count = 0;
	for (o = g->tobefnz; o != NULL; o = o->next)
	{
		count++;
		{
			if ((((o)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((o)))->gc)));
		};
	}
	return count;
}
static int remarkupvals(global_State *g)
{
	lua_State *thread;
	lua_State **p = &g->twups;
	int work = 0;
	while ((thread = *p) != NULL)
	{
		work++;
		if (!(((thread)->marked) & (((1 << (3)) | (1 << (4))))) && thread->openupval != NULL)
			p = &thread->twups;
		else
		{
			UpVal *uv;
			((void) 0);
			*p = thread->twups;
			thread->twups = thread;
			for (uv = thread->openupval; uv != NULL; uv = uv->u.open.next)
			{
				((void) 0);
				work++;
				if (!(((uv)->marked) & (((1 << (3)) | (1 << (4))))))
				{
					((void) 0);
					{
						((void) g->mainthread, ((void) 0));
						if (((((uv->v)->tt_) & (1 << 6)) &&
							 ((((((uv->v)->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
							reallymarkobject(g, (((uv->v)->value_).gc));
					};
				}
			}
		}
	}
	return work;
}

static void cleargraylists(global_State *g)
{
	g->gray = g->grayagain = NULL;
	g->weak = g->allweak = g->ephemeron = NULL;
}

static void restartcollection(global_State *g)
{
	cleargraylists(g);
	{
		if ((((g->mainthread)->marked) & (((1 << (3)) | (1 << (4))))))
			reallymarkobject(g, (&(((union GCUnion *) ((g->mainthread)))->gc)));
	};
	{
		((void) g->mainthread, ((void) 0));
		if (((((&g->l_registry)->tt_) & (1 << 6)) &&
			 ((((((&g->l_registry)->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, (((&g->l_registry)->value_).gc));
	};
	markmt(g);
	markbeingfnz(g);
}
static void genlink(global_State *g, GCObject *o)
{
	((void) 0);
	if (((o)->marked & 7) == 5)
	{
		linkgclist_((&(((union GCUnion *) ((o)))->gc)), getgclist(o), &(g->grayagain));
	}
	else if (((o)->marked & 7) == 6)
		((o)->marked ^= ((6) ^ (4)));
}
static void traverseweakvalue(global_State *g, Table *h)
{
	Node *n, *limit = (&(h)->node[((size_t) ((((1 << ((h)->lsizenode))))))]);

	int hasclears = (h->alimit > 0);
	for (n = (&(h)->node[0]); n < limit; n++)
	{
		if (((((((((&(n)->i_val)))->tt_)) & 0x0F)) == (0)))
			clearkey(n);
		else
		{
			((void) 0);
			{
				if ((((n)->u.key_tt) & (1 << 6)) &&
					((((((n)->u.key_val).gc))->marked) & (((1 << (3)) | (1 << (4))))))
					reallymarkobject(g, (((n)->u.key_val).gc));
			};
			if (!hasclears &&
				iscleared(g, (((((&(n)->i_val))->tt_) & (1 << 6)) ? ((((&(n)->i_val))->value_).gc)
																  : NULL)))
				hasclears = 1;
		}
	}
	if (g->gcstate == 2 && hasclears)
		linkgclist_((&(((union GCUnion *) ((h)))->gc)), &(h)->gclist, &(g->weak));
	else
		linkgclist_((&(((union GCUnion *) ((h)))->gc)), &(h)->gclist, &(g->grayagain));
}
static int traverseephemeron(global_State *g, Table *h, int inv)
{
	int marked = 0;
	int hasclears = 0;
	int hasww = 0;
	unsigned int i;
	unsigned int asize = luaH_realasize(h);
	unsigned int nsize = ((1 << ((h)->lsizenode)));

	for (i = 0; i < asize; i++)
	{
		if (((((&h->array[i])->tt_) & (1 << 6)) &&
			 ((((((&h->array[i])->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
		{
			marked = 1;
			reallymarkobject(g, (((&h->array[i])->value_).gc));
		}
	}

	for (i = 0; i < nsize; i++)
	{
		Node *n = inv ? (&(h)->node[nsize - 1 - i]) : (&(h)->node[i]);
		if (((((((((&(n)->i_val)))->tt_)) & 0x0F)) == (0)))
			clearkey(n);
		else if (iscleared(g, ((((n)->u.key_tt) & (1 << 6)) ? (((n)->u.key_val).gc) : NULL)))
		{
			hasclears = 1;
			if ((((((&(n)->i_val))->tt_) & (1 << 6)) &&
				 (((((((&(n)->i_val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
				hasww = 1;
		}
		else if ((((((&(n)->i_val))->tt_) & (1 << 6)) &&
				  (((((((&(n)->i_val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
		{
			marked = 1;
			reallymarkobject(g, ((((&(n)->i_val))->value_).gc));
		}
	}

	if (g->gcstate == 0)
		linkgclist_((&(((union GCUnion *) ((h)))->gc)), &(h)->gclist, &(g->grayagain));
	else if (hasww)
		linkgclist_((&(((union GCUnion *) ((h)))->gc)), &(h)->gclist, &(g->ephemeron));
	else if (hasclears)
		linkgclist_((&(((union GCUnion *) ((h)))->gc)), &(h)->gclist, &(g->allweak));
	else
		genlink(g, (&(((union GCUnion *) ((h)))->gc)));
	return marked;
}

static void traversestrongtable(global_State *g, Table *h)
{
	Node *n, *limit = (&(h)->node[((size_t) ((((1 << ((h)->lsizenode))))))]);
	unsigned int i;
	unsigned int asize = luaH_realasize(h);
	for (i = 0; i < asize; i++)
	{
		((void) g->mainthread, ((void) 0));
		if (((((&h->array[i])->tt_) & (1 << 6)) &&
			 ((((((&h->array[i])->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, (((&h->array[i])->value_).gc));
	};
	for (n = (&(h)->node[0]); n < limit; n++)
	{
		if (((((((((&(n)->i_val)))->tt_)) & 0x0F)) == (0)))
			clearkey(n);
		else
		{
			((void) 0);
			{
				if ((((n)->u.key_tt) & (1 << 6)) &&
					((((((n)->u.key_val).gc))->marked) & (((1 << (3)) | (1 << (4))))))
					reallymarkobject(g, (((n)->u.key_val).gc));
			};
			{
				((void) g->mainthread, ((void) 0));
				if ((((((&(n)->i_val))->tt_) & (1 << 6)) &&
					 (((((((&(n)->i_val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
					reallymarkobject(g, ((((&(n)->i_val))->value_).gc));
			};
		}
	}
	genlink(g, (&(((union GCUnion *) ((h)))->gc)));
}

static lu_mem traversetable(global_State *g, Table *h)
{
	const char *weakkey, *weakvalue;
	const TValue *mode = ((h->metatable) == NULL ? NULL
						  : ((h->metatable)->flags & (1u << (TM_MODE)))
							  ? NULL
							  : luaT_gettm(h->metatable, TM_MODE, (g)->tmname[TM_MODE]));
	{
		if (h->metatable)
		{
			if ((((h->metatable)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((h->metatable)))->gc)));
		};
	};
	if (mode && (((((((mode))->tt_)) & 0x0F)) == (4)) &&
		(((void) ((
			 weakkey = strchr(
				 ((((&((((union GCUnion *) ((((mode)->value_).gc))))->ts))))->contents), 'k')))),
		 ((void) ((
			 weakvalue = strchr(
				 ((((&((((union GCUnion *) ((((mode)->value_).gc))))->ts))))->contents), 'v')))),
		 (weakkey || weakvalue)))
	{
		if (!weakkey)
			traverseweakvalue(g, h);
		else if (!weakvalue)
			traverseephemeron(g, h, 0);
		else
			linkgclist_((&(((union GCUnion *) ((h)))->gc)), &(h)->gclist, &(g->allweak));
	}
	else
		traversestrongtable(g, h);
	return 1 + h->alimit + 2 * (((h)->lastfree == NULL) ? 0 : ((1 << ((h)->lsizenode))));
}

static int traverseudata(global_State *g, Udata *u)
{
	int i;
	{
		if (u->metatable)
		{
			if ((((u->metatable)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((u->metatable)))->gc)));
		};
	};
	for (i = 0; i < u->nuvalue; i++)
	{
		((void) g->mainthread, ((void) 0));
		if (((((&u->uv[i].uv)->tt_) & (1 << 6)) &&
			 ((((((&u->uv[i].uv)->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, (((&u->uv[i].uv)->value_).gc));
	};
	genlink(g, (&(((union GCUnion *) ((u)))->gc)));
	return 1 + u->nuvalue;
}

static int traverseproto(global_State *g, Proto *f)
{
	int i;
	{
		if (f->source)
		{
			if ((((f->source)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((f->source)))->gc)));
		};
	};
	for (i = 0; i < f->sizek; i++)
	{
		((void) g->mainthread, ((void) 0));
		if (((((&f->k[i])->tt_) & (1 << 6)) &&
			 ((((((&f->k[i])->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, (((&f->k[i])->value_).gc));
	};
	for (i = 0; i < f->sizeupvalues; i++)
	{
		if (f->upvalues[i].name)
		{
			if ((((f->upvalues[i].name)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((f->upvalues[i].name)))->gc)));
		};
	};
	for (i = 0; i < f->sizep; i++)
	{
		if (f->p[i])
		{
			if ((((f->p[i])->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((f->p[i])))->gc)));
		};
	};
	for (i = 0; i < f->sizelocvars; i++)
	{
		if (f->locvars[i].varname)
		{
			if ((((f->locvars[i].varname)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((f->locvars[i].varname)))->gc)));
		};
	};
	return 1 + f->sizek + f->sizeupvalues + f->sizep + f->sizelocvars;
}

static int traverseCclosure(global_State *g, CClosure *cl)
{
	int i;
	for (i = 0; i < cl->nupvalues; i++)
	{
		((void) g->mainthread, ((void) 0));
		if (((((&cl->upvalue[i])->tt_) & (1 << 6)) &&
			 ((((((&cl->upvalue[i])->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, (((&cl->upvalue[i])->value_).gc));
	};
	return 1 + cl->nupvalues;
}

static int traverseLclosure(global_State *g, LClosure *cl)
{
	int i;
	{
		if (cl->p)
		{
			if ((((cl->p)->marked) & (((1 << (3)) | (1 << (4))))))
				reallymarkobject(g, (&(((union GCUnion *) ((cl->p)))->gc)));
		};
	};
	for (i = 0; i < cl->nupvalues; i++)
	{
		UpVal *uv = cl->upvals[i];
		{
			if (uv)
			{
				if ((((uv)->marked) & (((1 << (3)) | (1 << (4))))))
					reallymarkobject(g, (&(((union GCUnion *) ((uv)))->gc)));
			};
		};
	}
	return 1 + cl->nupvalues;
}
static int traversethread(global_State *g, lua_State *th)
{
	UpVal *uv;
	StkId o = th->stack;
	if ((((th)->marked & 7) > 1) || g->gcstate == 0)
		linkgclist_((&(((union GCUnion *) ((th)))->gc)), &(th)->gclist, &(g->grayagain));
	if (o == NULL)
		return 1;
	((void) 0);

	for (; o < th->top; o++)
	{
		((void) g->mainthread, ((void) 0));
		if ((((((&(o)->val))->tt_) & (1 << 6)) &&
			 (((((((&(o)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, ((((&(o)->val))->value_).gc));
	};
	for (uv = th->openupval; uv != NULL; uv = uv->u.open.next)
	{
		if ((((uv)->marked) & (((1 << (3)) | (1 << (4))))))
			reallymarkobject(g, (&(((union GCUnion *) ((uv)))->gc)));
	};
	if (g->gcstate == 2)
	{
		for (; o < th->stack_last + 5; o++)
			(((&(o)->val))->tt_ = (((0) | ((0) << 4))));

		if (!(th->twups != th) && th->openupval != NULL)
		{
			th->twups = g->twups;
			g->twups = th;
		}
	}
	else if (!g->gcemergency)
		luaD_shrinkstack(th);
	return 1 + ((int) (((th)->stack_last - (th)->stack)));
}

static lu_mem propagatemark(global_State *g)
{
	GCObject *o = g->gray;
	((((o)->marked) |= ((1 << (5)))));
	g->gray = *getgclist(o);
	switch (o->tt)
	{
	case ((5) | ((0) << 4)):
		return traversetable(g, (&((((union GCUnion *) ((o))))->h)));
	case ((7) | ((0) << 4)):
		return traverseudata(g, (&((((union GCUnion *) ((o))))->u)));
	case ((6) | ((0) << 4)):
		return traverseLclosure(g, (&((((union GCUnion *) ((o))))->cl.l)));
	case ((6) | ((2) << 4)):
		return traverseCclosure(g, (&((((union GCUnion *) ((o))))->cl.c)));
	case (((9 + 1)) | ((0) << 4)):
		return traverseproto(g, (&((((union GCUnion *) ((o))))->p)));
	case ((8) | ((0) << 4)):
		return traversethread(g, (&((((union GCUnion *) ((o))))->th)));
	default:
		((void) 0);
		return 0;
	}
}

static lu_mem propagateall(global_State *g)
{
	lu_mem tot = 0;
	while (g->gray)
		tot += propagatemark(g);
	return tot;
}
static void convergeephemerons(global_State *g)
{
	int changed;
	int dir = 0;
	do
	{
		GCObject *w;
		GCObject *next = g->ephemeron;
		g->ephemeron = NULL;
		changed = 0;
		while ((w = next) != NULL)
		{
			Table *h = (&((((union GCUnion *) ((w))))->h));
			next = h->gclist;
			((((h)->marked) |= ((1 << (5)))));
			if (traverseephemeron(g, h, dir))
			{
				propagateall(g);
				changed = 1;
			}
		}
		dir = !dir;
	} while (changed);
}
static void clearbykeys(global_State *g, GCObject *l)
{
	for (; l; l = (&((((union GCUnion *) ((l))))->h))->gclist)
	{
		Table *h = (&((((union GCUnion *) ((l))))->h));
		Node *limit = (&(h)->node[((size_t) ((((1 << ((h)->lsizenode))))))]);
		Node *n;
		for (n = (&(h)->node[0]); n < limit; n++)
		{
			if (iscleared(g, ((((n)->u.key_tt) & (1 << 6)) ? (((n)->u.key_val).gc) : NULL)))
				(((&(n)->i_val))->tt_ = (((0) | ((1) << 4))));
			if (((((((((&(n)->i_val)))->tt_)) & 0x0F)) == (0)))
				clearkey(n);
		}
	}
}

static void clearbyvalues(global_State *g, GCObject *l, GCObject *f)
{
	for (; l != f; l = (&((((union GCUnion *) ((l))))->h))->gclist)
	{
		Table *h = (&((((union GCUnion *) ((l))))->h));
		Node *n, *limit = (&(h)->node[((size_t) ((((1 << ((h)->lsizenode))))))]);
		unsigned int i;
		unsigned int asize = luaH_realasize(h);
		for (i = 0; i < asize; i++)
		{
			TValue *o = &h->array[i];
			if (iscleared(g, ((((o)->tt_) & (1 << 6)) ? (((o)->value_).gc) : NULL)))
				((o)->tt_ = (((0) | ((1) << 4))));
		}
		for (n = (&(h)->node[0]); n < limit; n++)
		{
			if (iscleared(g, (((((&(n)->i_val))->tt_) & (1 << 6)) ? ((((&(n)->i_val))->value_).gc)
																  : NULL)))
				(((&(n)->i_val))->tt_ = (((0) | ((1) << 4))));
			if (((((((((&(n)->i_val)))->tt_)) & 0x0F)) == (0)))
				clearkey(n);
		}
	}
}

static void freeupval(lua_State *L, UpVal *uv)
{
	if (((uv)->v != &(uv)->u.value))
		luaF_unlinkupval(uv);
	luaM_free_(L, (uv), sizeof(*(uv)));
}

static void freeobj(lua_State *L, GCObject *o)
{
	switch (o->tt)
	{
	case (((9 + 1)) | ((0) << 4)):
		luaF_freeproto(L, (&((((union GCUnion *) ((o))))->p)));
		break;
	case ((9) | ((0) << 4)):
		freeupval(L, (&((((union GCUnion *) ((o))))->upv)));
		break;
	case ((6) | ((0) << 4)):
	{
		LClosure *cl = (&((((union GCUnion *) ((o))))->cl.l));
		luaM_free_(L, (cl),
				   ((((int) ((offsetof(LClosure, upvals)))) +
					 ((int) ((sizeof(TValue *)))) * (cl->nupvalues))));
		break;
	}
	case ((6) | ((2) << 4)):
	{
		CClosure *cl = (&((((union GCUnion *) ((o))))->cl.c));
		luaM_free_(L, (cl),
				   ((((int) ((offsetof(CClosure, upvalue)))) +
					 ((int) ((sizeof(TValue)))) * (cl->nupvalues))));
		break;
	}
	case ((5) | ((0) << 4)):
		luaH_free(L, (&((((union GCUnion *) ((o))))->h)));
		break;
	case ((8) | ((0) << 4)):
		luaE_freethread(L, (&((((union GCUnion *) ((o))))->th)));
		break;
	case ((7) | ((0) << 4)):
	{
		Udata *u = (&((((union GCUnion *) ((o))))->u));
		luaM_free_(L, (o),
				   ((((u->nuvalue) == 0 ? offsetof(Udata0, bindata)
										: offsetof(Udata, uv) + (sizeof(UValue) * (u->nuvalue))) +
					 (u->len))));
		break;
	}
	case ((4) | ((0) << 4)):
	{
		TString *ts = (&((((union GCUnion *) ((o))))->ts));
		luaS_remove(L, ts);
		luaM_free_(L, (ts), ((offsetof(TString, contents) + ((ts->shrlen) + 1) * sizeof(char))));
		break;
	}
	case ((4) | ((1) << 4)):
	{
		TString *ts = (&((((union GCUnion *) ((o))))->ts));
		luaM_free_(L, (ts), ((offsetof(TString, contents) + ((ts->u.lnglen) + 1) * sizeof(char))));
		break;
	}
	default:
		((void) 0);
	}
}
static GCObject **sweeplist(lua_State *L, GCObject **p, int countin, int *countout)
{
	global_State *g = (L->l_G);
	int ow = ((g)->currentwhite ^ ((1 << (3)) | (1 << (4))));
	int i;
	int white = ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))));
	for (i = 0; *p != NULL && i < countin; i++)
	{
		GCObject *curr = *p;
		int marked = curr->marked;
		if (((marked) & (ow)))
		{
			*p = curr->next;
			freeobj(L, curr);
		}
		else
		{
			curr->marked =
				((lu_byte) (((marked & ~(((1 << (5)) | ((1 << (3)) | (1 << (4)))) | 7)) | white)));
			p = &curr->next;
		}
	}
	if (countout)
		*countout = i;
	return (*p == NULL) ? NULL : p;
}

static GCObject **sweeptolive(lua_State *L, GCObject **p)
{
	GCObject **old = p;
	do
	{
		p = sweeplist(L, p, 1, NULL);
	} while (p == old);
	return p;
}
static void checkSizes(lua_State *L, global_State *g)
{
	if (!g->gcemergency)
	{
		if (g->strt.nuse < g->strt.size / 4)
		{
			l_mem olddebt = g->GCdebt;
			luaS_resize(L, g->strt.size / 2);
			g->GCestimate += g->GCdebt - olddebt;
		}
	}
}

static GCObject *udata2finalize(global_State *g)
{
	GCObject *o = g->tobefnz;
	((void) 0);
	g->tobefnz = o->next;
	o->next = g->allgc;
	g->allgc = o;
	((o->marked) &= ((lu_byte) ((~((1 << (6)))))));
	if ((3 <= (g)->gcstate && (g)->gcstate <= 6))
		(o->marked = ((lu_byte) (((o->marked & ~((1 << (5)) | ((1 << (3)) | (1 << (4))))) |
								  ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))))))));
	else if (((o)->marked & 7) == 3)
		g->firstold1 = o;
	return o;
}

static void dothecall(lua_State *L, void *ud)
{
	((void) (ud));
	luaD_callnoyield(L, L->top - 2, 0);
}

static void GCTM(lua_State *L)
{
	global_State *g = (L->l_G);
	const TValue *tm;
	TValue v;
	((void) 0);
	{
		TValue *io = (&v);
		GCObject *i_g = (udata2finalize(g));
		((io)->value_).gc = i_g;
		((io)->tt_ = (((i_g->tt) | (1 << 6))));
	};
	tm = luaT_gettmbyobj(L, &v, TM_GC);
	if (!(((((((tm))->tt_)) & 0x0F)) == (0)))
	{
		int status;
		lu_byte oldah = L->allowhook;
		int running = g->gcrunning;
		L->allowhook = 0;
		g->gcrunning = 0;
		{
			TValue *io1 = ((&(L->top++)->val));
			const TValue *io2 = (tm);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		{
			TValue *io1 = ((&(L->top++)->val));
			const TValue *io2 = (&v);
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		L->ci->callstatus |= (1 << 7);
		status = luaD_pcall(L, dothecall, NULL, ((char *) (L->top - 2) - (char *) L->stack), 0);
		L->ci->callstatus &= ~(1 << 7);
		L->allowhook = oldah;
		g->gcrunning = running;
		if ((__builtin_expect(((status != 0) != 0), 0)))
		{
			luaE_warnerror(L, "__gc metamethod");
			L->top--;
		}
	}
}

static int runafewfinalizers(lua_State *L, int n)
{
	global_State *g = (L->l_G);
	int i;
	for (i = 0; i < n && g->tobefnz; i++)
		GCTM(L);
	return i;
}

static void callallpendingfinalizers(lua_State *L)
{
	global_State *g = (L->l_G);
	while (g->tobefnz)
		GCTM(L);
}

static GCObject **findlast(GCObject **p)
{
	while (*p != NULL)
		p = &(*p)->next;
	return p;
}
static void separatetobefnz(global_State *g, int all)
{
	GCObject *curr;
	GCObject **p = &g->finobj;
	GCObject **lastnext = findlast(&g->tobefnz);
	while ((curr = *p) != g->finobjold1)
	{
		((void) 0);
		if (!((((curr)->marked) & (((1 << (3)) | (1 << (4))))) || all))
			p = &curr->next;
		else
		{
			if (curr == g->finobjsur)
				g->finobjsur = curr->next;
			*p = curr->next;
			curr->next = *lastnext;
			*lastnext = curr;
			lastnext = &curr->next;
		}
	}
}

static void checkpointer(GCObject **p, GCObject *o)
{
	if (o == *p)
		*p = o->next;
}

static void correctpointers(global_State *g, GCObject *o)
{
	checkpointer(&g->survival, o);
	checkpointer(&g->old1, o);
	checkpointer(&g->reallyold, o);
	checkpointer(&g->firstold1, o);
}

void luaC_checkfinalizer(lua_State *L, GCObject *o, Table *mt)
{
	global_State *g = (L->l_G);
	if ((((o)->marked) & ((1 << (6)))) ||
		((mt) == NULL					   ? NULL
		 : ((mt)->flags & (1u << (TM_GC))) ? NULL
										   : luaT_gettm(mt, TM_GC, (g)->tmname[TM_GC])) == NULL)
		return;
	else
	{
		GCObject **p;
		if ((3 <= (g)->gcstate && (g)->gcstate <= 6))
		{
			(o->marked =
				 ((lu_byte) (((o->marked & ~((1 << (5)) | ((1 << (3)) | (1 << (4))))) |
							  ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))))))));
			if (g->sweepgc == &o->next)
				g->sweepgc = sweeptolive(L, g->sweepgc);
		}
		else
			correctpointers(g, o);

		for (p = &g->allgc; *p != o; p = &(*p)->next)
		{
		}
		*p = o->next;
		o->next = g->finobj;
		g->finobj = o;
		((o->marked) |= ((1 << (6))));
	}
}
static void setpause(global_State *g);
static void sweep2old(lua_State *L, GCObject **p)
{
	GCObject *curr;
	global_State *g = (L->l_G);
	while ((curr = *p) != NULL)
	{
		if ((((curr)->marked) & (((1 << (3)) | (1 << (4))))))
		{
			((void) 0);
			*p = curr->next;
			freeobj(L, curr);
		}
		else
		{
			((curr)->marked = ((lu_byte) ((((curr)->marked & (~7)) | 4))));
			if (curr->tt == ((8) | ((0) << 4)))
			{
				lua_State *th = (&((((union GCUnion *) ((curr))))->th));
				linkgclist_((&(((union GCUnion *) ((th)))->gc)), &(th)->gclist, &(g->grayagain));
			}
			else if (curr->tt == ((9) | ((0) << 4)) &&
					 (((&((((union GCUnion *) ((curr))))->upv)))->v !=
					  &((&((((union GCUnion *) ((curr))))->upv)))->u.value))
				((curr->marked) &= ((lu_byte) ((~(((1 << (5)) | ((1 << (3)) | (1 << (4)))))))));
			else
				((((curr)->marked) |= ((1 << (5)))));
			p = &curr->next;
		}
	}
}
static GCObject **sweepgen(lua_State *L, global_State *g, GCObject **p, GCObject *limit,
						   GCObject **pfirstold1)
{
	static const lu_byte nextage[] = {1, 3, 3, 4, 4, 5, 6};
	int white = ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))));
	GCObject *curr;
	while ((curr = *p) != limit)
	{
		if ((((curr)->marked) & (((1 << (3)) | (1 << (4))))))
		{
			((void) 0);
			*p = curr->next;
			freeobj(L, curr);
		}
		else
		{
			if (((curr)->marked & 7) == 0)
			{
				int marked = curr->marked & ~(((1 << (5)) | ((1 << (3)) | (1 << (4)))) | 7);
				curr->marked = ((lu_byte) ((marked | 1 | white)));
			}
			else
			{
				((curr)->marked =
					 ((lu_byte) ((((curr)->marked & (~7)) | nextage[((curr)->marked & 7)]))));
				if (((curr)->marked & 7) == 3 && *pfirstold1 == NULL)
					*pfirstold1 = curr;
			}
			p = &curr->next;
		}
	}
	return p;
}

static void whitelist(global_State *g, GCObject *p)
{
	int white = ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))));
	for (; p != NULL; p = p->next)
		p->marked =
			((lu_byte) (((p->marked & ~(((1 << (5)) | ((1 << (3)) | (1 << (4)))) | 7)) | white)));
}
static GCObject **correctgraylist(GCObject **p)
{
	GCObject *curr;
	while ((curr = *p) != NULL)
	{
		GCObject **next = getgclist(curr);
		if ((((curr)->marked) & (((1 << (3)) | (1 << (4))))))
			goto remove;
		else if (((curr)->marked & 7) == 5)
		{
			((void) 0);
			((((curr)->marked) |= ((1 << (5)))));
			((curr)->marked ^= ((5) ^ (6)));
			goto remain;
		}
		else if (curr->tt == ((8) | ((0) << 4)))
		{
			((void) 0);
			goto remain;
		}
		else
		{
			((void) 0);
			if (((curr)->marked & 7) == 6)
				((curr)->marked ^= ((6) ^ (4)));
			((((curr)->marked) |= ((1 << (5)))));
			goto remove;
		}
	remove:
		*p = *next;
		continue;
	remain:
		p = next;
		continue;
	}
	return p;
}

static void correctgraylists(global_State *g)
{
	GCObject **list = correctgraylist(&g->grayagain);
	*list = g->weak;
	g->weak = NULL;
	list = correctgraylist(list);
	*list = g->allweak;
	g->allweak = NULL;
	list = correctgraylist(list);
	*list = g->ephemeron;
	g->ephemeron = NULL;
	correctgraylist(list);
}

static void markold(global_State *g, GCObject *from, GCObject *to)
{
	GCObject *p;
	for (p = from; p != to; p = p->next)
	{
		if (((p)->marked & 7) == 3)
		{
			((void) 0);
			((p)->marked ^= ((3) ^ (4)));
			if ((((p)->marked) & ((1 << (5)))))
				reallymarkobject(g, p);
		}
	}
}

static void finishgencycle(lua_State *L, global_State *g)
{
	correctgraylists(g);
	checkSizes(L, g);
	g->gcstate = 0;
	if (!g->gcemergency)
		callallpendingfinalizers(L);
}

static void youngcollection(lua_State *L, global_State *g)
{
	GCObject **psurvival;
	GCObject *dummy;
	((void) 0);
	if (g->firstold1)
	{
		markold(g, g->firstold1, g->reallyold);
		g->firstold1 = NULL;
	}
	markold(g, g->finobj, g->finobjrold);
	markold(g, g->tobefnz, NULL);
	atomic(L);

	g->gcstate = 3;
	psurvival = sweepgen(L, g, &g->allgc, g->survival, &g->firstold1);

	sweepgen(L, g, psurvival, g->old1, &g->firstold1);
	g->reallyold = g->old1;
	g->old1 = *psurvival;
	g->survival = g->allgc;

	dummy = NULL;
	psurvival = sweepgen(L, g, &g->finobj, g->finobjsur, &dummy);

	sweepgen(L, g, psurvival, g->finobjold1, &dummy);
	g->finobjrold = g->finobjold1;
	g->finobjold1 = *psurvival;
	g->finobjsur = g->finobj;

	sweepgen(L, g, &g->tobefnz, NULL, &dummy);
	finishgencycle(L, g);
}
static void atomic2gen(lua_State *L, global_State *g)
{
	cleargraylists(g);

	g->gcstate = 3;
	sweep2old(L, &g->allgc);

	g->reallyold = g->old1 = g->survival = g->allgc;
	g->firstold1 = NULL;

	sweep2old(L, &g->finobj);
	g->finobjrold = g->finobjold1 = g->finobjsur = g->finobj;

	sweep2old(L, &g->tobefnz);

	g->gckind = 1;
	g->lastatomic = 0;
	g->GCestimate = ((lu_mem) ((g)->totalbytes + (g)->GCdebt));
	finishgencycle(L, g);
}
static lu_mem entergen(lua_State *L, global_State *g)
{
	lu_mem numobjs;
	luaC_runtilstate(L, (1 << (8)));
	luaC_runtilstate(L, (1 << (0)));
	numobjs = atomic(L);
	atomic2gen(L, g);
	return numobjs;
}

static void enterinc(global_State *g)
{
	whitelist(g, g->allgc);
	g->reallyold = g->old1 = g->survival = NULL;
	whitelist(g, g->finobj);
	whitelist(g, g->tobefnz);
	g->finobjrold = g->finobjold1 = g->finobjsur = NULL;
	g->gcstate = 8;
	g->gckind = 0;
	g->lastatomic = 0;
}

void luaC_changemode(lua_State *L, int newmode)
{
	global_State *g = (L->l_G);
	if (newmode != g->gckind)
	{
		if (newmode == 1)
			entergen(L, g);
		else
			enterinc(g);
	}
	g->lastatomic = 0;
}

static lu_mem fullgen(lua_State *L, global_State *g)
{
	enterinc(g);
	return entergen(L, g);
}

static void setminordebt(global_State *g)
{
	luaE_setdebt(
		g, -(((l_mem) ((((lu_mem) ((g)->totalbytes + (g)->GCdebt)) / 100))) * g->genminormul));
}
static void stepgenfull(lua_State *L, global_State *g)
{
	lu_mem newatomic;
	lu_mem lastatomic = g->lastatomic;
	if (g->gckind == 1)
		enterinc(g);
	luaC_runtilstate(L, (1 << (0)));
	newatomic = atomic(L);
	if (newatomic < lastatomic + (lastatomic >> 3))
	{
		atomic2gen(L, g);
		setminordebt(g);
	}
	else
	{
		g->GCestimate = ((lu_mem) ((g)->totalbytes + (g)->GCdebt));
		;
		entersweep(L);
		luaC_runtilstate(L, (1 << (8)));
		setpause(g);
		g->lastatomic = newatomic;
	}
}
static void genstep(lua_State *L, global_State *g)
{
	if (g->lastatomic != 0)
		stepgenfull(L, g);
	else
	{
		lu_mem majorbase = g->GCestimate;
		lu_mem majorinc = (majorbase / 100) * ((g->genmajormul) * 4);
		if (g->GCdebt > 0 && ((lu_mem) ((g)->totalbytes + (g)->GCdebt)) > majorbase + majorinc)
		{
			lu_mem numobjs = fullgen(L, g);
			if (((lu_mem) ((g)->totalbytes + (g)->GCdebt)) < majorbase + (majorinc / 2))
			{

				setminordebt(g);
			}
			else
			{
				g->lastatomic = numobjs;
				setpause(g);
			}
		}
		else
		{
			youngcollection(L, g);
			setminordebt(g);
			g->GCestimate = majorbase;
		}
	}
	((void) 0);
}
static void setpause(global_State *g)
{
	l_mem threshold, debt;
	int pause = ((g->gcpause) * 4);
	l_mem estimate = g->GCestimate / 100;
	((void) 0);
	threshold = (pause < ((l_mem) (((lu_mem) (~(lu_mem) 0)) >> 1)) / estimate)
					? estimate * pause
					: ((l_mem) (((lu_mem) (~(lu_mem) 0)) >> 1));
	debt = ((lu_mem) ((g)->totalbytes + (g)->GCdebt)) - threshold;
	if (debt > 0)
		debt = 0;
	luaE_setdebt(g, debt);
}
static void entersweep(lua_State *L)
{
	global_State *g = (L->l_G);
	g->gcstate = 3;
	((void) 0);
	g->sweepgc = sweeptolive(L, &g->allgc);
}

static void deletelist(lua_State *L, GCObject *p, GCObject *limit)
{
	while (p != limit)
	{
		GCObject *next = p->next;
		freeobj(L, p);
		p = next;
	}
}

void luaC_freeallobjects(lua_State *L)
{
	global_State *g = (L->l_G);
	luaC_changemode(L, 0);
	separatetobefnz(g, 1);
	((void) 0);
	callallpendingfinalizers(L);
	deletelist(L, g->allgc, (&(((union GCUnion *) ((g->mainthread)))->gc)));
	deletelist(L, g->finobj, NULL);
	deletelist(L, g->fixedgc, NULL);
	((void) 0);
}

static lu_mem atomic(lua_State *L)
{
	global_State *g = (L->l_G);
	lu_mem work = 0;
	GCObject *origweak, *origall;
	GCObject *grayagain = g->grayagain;
	g->grayagain = NULL;
	((void) 0);
	((void) 0);
	g->gcstate = 2;
	{
		if ((((L)->marked) & (((1 << (3)) | (1 << (4))))))
			reallymarkobject(g, (&(((union GCUnion *) ((L)))->gc)));
	};

	{
		((void) g->mainthread, ((void) 0));
		if (((((&g->l_registry)->tt_) & (1 << 6)) &&
			 ((((((&g->l_registry)->value_).gc))->marked) & (((1 << (3)) | (1 << (4)))))))
			reallymarkobject(g, (((&g->l_registry)->value_).gc));
	};
	markmt(g);
	work += propagateall(g);

	work += remarkupvals(g);
	work += propagateall(g);
	g->gray = grayagain;
	work += propagateall(g);
	convergeephemerons(g);

	clearbyvalues(g, g->weak, NULL);
	clearbyvalues(g, g->allweak, NULL);
	origweak = g->weak;
	origall = g->allweak;
	separatetobefnz(g, 0);
	work += markbeingfnz(g);
	work += propagateall(g);
	convergeephemerons(g);

	clearbykeys(g, g->ephemeron);
	clearbykeys(g, g->allweak);

	clearbyvalues(g, g->weak, origweak);
	clearbyvalues(g, g->allweak, origall);
	luaS_clearcache(g);
	g->currentwhite = ((lu_byte) ((((g)->currentwhite ^ ((1 << (3)) | (1 << (4)))))));
	((void) 0);
	return work;
}

static int sweepstep(lua_State *L, global_State *g, int nextstate, GCObject **nextlist)
{
	if (g->sweepgc)
	{
		l_mem olddebt = g->GCdebt;
		int count;
		g->sweepgc = sweeplist(L, g->sweepgc, 100, &count);
		g->GCestimate += g->GCdebt - olddebt;
		return count;
	}
	else
	{
		g->gcstate = nextstate;
		g->sweepgc = nextlist;
		return 0;
	}
}

static lu_mem singlestep(lua_State *L)
{
	global_State *g = (L->l_G);
	switch (g->gcstate)
	{
	case 8:
	{
		restartcollection(g);
		g->gcstate = 0;
		return 1;
	}
	case 0:
	{
		if (g->gray == NULL)
		{
			g->gcstate = 1;
			return 0;
		}
		else
			return propagatemark(g);
	}
	case 1:
	{
		lu_mem work = atomic(L);
		entersweep(L);
		g->GCestimate = ((lu_mem) ((g)->totalbytes + (g)->GCdebt));
		;
		return work;
	}
	case 3:
	{
		return sweepstep(L, g, 4, &g->finobj);
	}
	case 4:
	{
		return sweepstep(L, g, 5, &g->tobefnz);
	}
	case 5:
	{
		return sweepstep(L, g, 6, NULL);
	}
	case 6:
	{
		checkSizes(L, g);
		g->gcstate = 7;
		return 0;
	}
	case 7:
	{
		if (g->tobefnz && !g->gcemergency)
		{
			int n = runafewfinalizers(L, 10);
			return n * 50;
		}
		else
		{
			g->gcstate = 8;
			return 0;
		}
	}
	default:
		((void) 0);
		return 0;
	}
}

void luaC_runtilstate(lua_State *L, int statesmask)
{
	global_State *g = (L->l_G);
	while (!((statesmask) & ((1 << (g->gcstate)))))
		singlestep(L);
}
static void incstep(lua_State *L, global_State *g)
{
	int stepmul = (((g->gcstepmul) * 4) | 1);
	l_mem debt = (g->GCdebt / sizeof(TValue)) * stepmul;
	l_mem stepsize = (g->gcstepsize <= (sizeof(l_mem) * 8 - 2))
						 ? ((((l_mem) (1)) << g->gcstepsize) / sizeof(TValue)) * stepmul
						 : ((l_mem) (((lu_mem) (~(lu_mem) 0)) >> 1));
	do
	{
		lu_mem work = singlestep(L);
		debt -= work;
	} while (debt > -stepsize && g->gcstate != 8);
	if (g->gcstate == 8)
		setpause(g);
	else
	{
		debt = (debt / stepmul) * sizeof(TValue);
		luaE_setdebt(g, debt);
	}
}

void luaC_step(lua_State *L)
{
	global_State *g = (L->l_G);
	((void) 0);
	if (g->gcrunning)
	{
		if ((g->gckind == 1 || g->lastatomic != 0))
			genstep(L, g);
		else
			incstep(L, g);
	}
}
static void fullinc(lua_State *L, global_State *g)
{
	if (((g)->gcstate <= 2))
		entersweep(L);

	luaC_runtilstate(L, (1 << (8)));
	luaC_runtilstate(L, (1 << (7)));

	((void) 0);
	luaC_runtilstate(L, (1 << (8)));
	setpause(g);
}

void luaC_fullgc(lua_State *L, int isemergency)
{
	global_State *g = (L->l_G);
	((void) 0);
	g->gcemergency = isemergency;
	if (g->gckind == 0)
		fullinc(L, g);
	else
		fullgen(L, g);
	g->gcemergency = 0;
}
