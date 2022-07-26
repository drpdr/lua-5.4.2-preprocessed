

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

typedef struct LX
{
	lu_byte extra_[(sizeof(void *))];
	lua_State l;
} LX;

typedef struct LG
{
	LX l;
	global_State g;
} LG;
static unsigned int luai_makeseed(lua_State *L)
{
	char buff[3 * sizeof(size_t)];
	unsigned int h = ((unsigned int) ((time(NULL))));
	int p = 0;
	{
		size_t t = ((size_t) ((L)));
		memcpy(buff + p, &t, sizeof(t));
		p += sizeof(t);
	};
	{
		size_t t = ((size_t) ((&h)));
		memcpy(buff + p, &t, sizeof(t));
		p += sizeof(t);
	};
	{
		size_t t = ((size_t) ((&lua_newstate)));
		memcpy(buff + p, &t, sizeof(t));
		p += sizeof(t);
	};
	((void) 0);
	return luaS_hash(buff, p, h);
}
void luaE_setdebt(global_State *g, l_mem debt)
{
	l_mem tb = ((lu_mem) ((g)->totalbytes + (g)->GCdebt));
	((void) 0);
	if (debt < tb - ((l_mem) (((lu_mem) (~(lu_mem) 0)) >> 1)))
		debt = tb - ((l_mem) (((lu_mem) (~(lu_mem) 0)) >> 1));
	g->totalbytes = tb - debt;
	g->GCdebt = debt;
}

extern int lua_setcstacklimit(lua_State *L, unsigned int limit)
{
	((void) (L));
	((void) (limit));
	return 200;
}

CallInfo *luaE_extendCI(lua_State *L)
{
	CallInfo *ci;
	((void) 0);
	ci = ((CallInfo *) (luaM_malloc_(L, sizeof(CallInfo), 0)));
	((void) 0);
	L->ci->next = ci;
	ci->previous = L->ci;
	ci->next = NULL;
	ci->u.l.trap = 0;
	L->nci++;
	return ci;
}

void luaE_freeCI(lua_State *L)
{
	CallInfo *ci = L->ci;
	CallInfo *next = ci->next;
	ci->next = NULL;
	while ((ci = next) != NULL)
	{
		next = ci->next;
		luaM_free_(L, (ci), sizeof(*(ci)));
		L->nci--;
	}
}

void luaE_shrinkCI(lua_State *L)
{
	CallInfo *ci = L->ci->next;
	CallInfo *next;
	if (ci == NULL)
		return;
	while ((next = ci->next) != NULL)
	{
		CallInfo *next2 = next->next;
		ci->next = next2;
		L->nci--;
		luaM_free_(L, (next), sizeof(*(next)));
		if (next2 == NULL)
			break;
		else
		{
			next2->previous = ci;
			ci = next2;
		}
	}
}
void luaE_checkcstack(lua_State *L)
{
	if (((L)->nCcalls & 0xffff) == 200)
		luaG_runerror(L, "C stack overflow");
	else if (((L)->nCcalls & 0xffff) >= (200 / 10 * 11))
		luaD_throw(L, 5);
}

__attribute__((visibility("internal"))) extern void luaE_incCstack(lua_State *L)
{
	L->nCcalls++;
	if ((__builtin_expect(((((L)->nCcalls & 0xffff) >= 200) != 0), 0)))
		luaE_checkcstack(L);
}

static void stack_init(lua_State *L1, lua_State *L)
{
	int i;
	CallInfo *ci;

	L1->stack = ((StackValue *) (luaM_malloc_(L, ((2 * 20) + 5) * sizeof(StackValue), 0)));
	for (i = 0; i < (2 * 20) + 5; i++)
		(((&(L1->stack + i)->val))->tt_ = (((0) | ((0) << 4))));
	L1->top = L1->stack;
	L1->stack_last = L1->stack + (2 * 20);

	ci = &L1->base_ci;
	ci->next = ci->previous = NULL;
	ci->callstatus = (1 << 1);
	ci->func = L1->top;
	ci->u.c.k = NULL;
	ci->nresults = 0;
	(((&(L1->top)->val))->tt_ = (((0) | ((0) << 4))));
	L1->top++;
	ci->top = L1->top + 20;
	L1->ci = ci;
}

static void freestack(lua_State *L)
{
	if (L->stack == NULL)
		return;
	L->ci = &L->base_ci;
	luaE_freeCI(L);
	((void) 0);
	luaM_free_(L, (L->stack), (((int) (((L)->stack_last - (L)->stack))) + 5) * sizeof(*(L->stack)));
}

static void init_registry(lua_State *L, global_State *g)
{
	TValue temp;

	Table *registry = luaH_new(L);
	{
		TValue *io = (&g->l_registry);
		Table *x_ = (registry);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	luaH_resize(L, registry, 2, 0);

	{
		TValue *io = (&temp);
		lua_State *x_ = (L);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((8) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	luaH_setint(L, registry, 1, &temp);

	{
		TValue *io = (&temp);
		Table *x_ = (luaH_new(L));
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	luaH_setint(L, registry, 2, &temp);
}

static void f_luaopen(lua_State *L, void *ud)
{
	global_State *g = (L->l_G);
	((void) (ud));
	stack_init(L, L);
	init_registry(L, g);
	luaS_init(L);
	luaT_init(L);
	luaX_init(L);
	g->gcrunning = 1;
	((&g->nilvalue)->tt_ = (((0) | ((0) << 4))));
	((void) L);
}

static void preinit_thread(lua_State *L, global_State *g)
{
	(L->l_G) = g;
	L->stack = NULL;
	L->ci = NULL;
	L->nci = 0;
	L->twups = L;
	L->errorJmp = NULL;
	L->hook = NULL;
	L->hookmask = 0;
	L->basehookcount = 0;
	L->allowhook = 1;
	(L->hookcount = L->basehookcount);
	L->openupval = NULL;
	L->status = 0;
	L->errfunc = 0;
	L->oldpc = 0;
}

static void close_state(lua_State *L)
{
	global_State *g = (L->l_G);
	luaF_close(L, L->stack, (-2));
	luaC_freeallobjects(L);
	if ((((((((&g->nilvalue))->tt_)) & 0x0F)) == (0)))
		((void) L);
	luaM_free_(L, ((L->l_G)->strt.hash), ((L->l_G)->strt.size) * sizeof(*((L->l_G)->strt.hash)));
	freestack(L);
	((void) 0);
	(*g->frealloc)(g->ud, (((LX *) (((lu_byte *) ((L))) - offsetof(LX, l)))), sizeof(LG), 0);
}

extern lua_State *lua_newthread(lua_State *L)
{
	global_State *g;
	lua_State *L1;
	((void) 0);
	g = (L->l_G);
	{
		if ((L->l_G)->GCdebt > 0)
		{
			(void) 0;
			luaC_step(L);
			(void) 0;
		};
		((void) 0);
	};

	L1 = &((LX *) (luaM_malloc_(L, (sizeof(LX)), 8)))->l;
	L1->marked = ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))));
	L1->tt = ((8) | ((0) << 4));

	L1->next = g->allgc;
	g->allgc = (&(((union GCUnion *) ((L1)))->gc));

	{
		TValue *io = ((&(L->top)->val));
		lua_State *x_ = (L1);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((8) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	{
		L->top++;
		((void) L, ((void) 0));
	};
	preinit_thread(L1, g);
	L1->nCcalls = 0;
	L1->hookmask = L->hookmask;
	L1->basehookcount = L->basehookcount;
	L1->hook = L->hook;
	(L1->hookcount = L1->basehookcount);

	memcpy(((void *) ((char *) (L1) - (sizeof(void *)))),
		   ((void *) ((char *) (g->mainthread) - (sizeof(void *)))), (sizeof(void *)));
	((void) L);
	stack_init(L1, L);
	((void) 0);
	return L1;
}

void luaE_freethread(lua_State *L, lua_State *L1)
{
	LX *l = (((LX *) (((lu_byte *) ((L1))) - offsetof(LX, l))));
	luaF_close(L1, L1->stack, (-1));
	((void) 0);
	((void) L);
	freestack(L1);
	luaM_free_(L, (l), sizeof(*(l)));
}

int lua_resetthread(lua_State *L)
{
	CallInfo *ci;
	int status;
	((void) 0);
	L->ci = ci = &L->base_ci;
	(((&(L->stack)->val))->tt_ = (((0) | ((0) << 4))));
	ci->func = L->stack;
	ci->callstatus = (1 << 1);
	status = luaF_close(L, L->stack, (-2));
	if (status != (-2))
		luaD_seterrorobj(L, status, L->stack + 1);
	else
	{
		status = 0;
		L->top = L->stack + 1;
	}
	ci->top = L->top + 20;
	L->status = status;
	((void) 0);
	return status;
}

extern lua_State *lua_newstate(lua_Alloc f, void *ud)
{
	int i;
	lua_State *L;
	global_State *g;
	LG *l = ((LG *) ((*f)(ud, NULL, 8, sizeof(LG))));
	if (l == NULL)
		return NULL;
	L = &l->l.l;
	g = &l->g;
	L->tt = ((8) | ((0) << 4));
	g->currentwhite = (1 << (3));
	L->marked = ((lu_byte) (((g)->currentwhite & ((1 << (3)) | (1 << (4))))));
	preinit_thread(L, g);
	g->allgc = (&(((union GCUnion *) ((L)))->gc));
	L->next = NULL;
	L->nCcalls = 0;
	((L)->nCcalls += 0x10000);
	g->frealloc = f;
	g->ud = ud;
	g->warnf = NULL;
	g->ud_warn = NULL;
	g->mainthread = L;
	g->seed = luai_makeseed(L);
	g->gcrunning = 0;
	g->strt.size = g->strt.nuse = 0;
	g->strt.hash = NULL;
	((&g->l_registry)->tt_ = (((0) | ((0) << 4))));
	g->panic = NULL;
	g->gcstate = 8;
	g->gckind = 0;
	g->gcemergency = 0;
	g->finobj = g->tobefnz = g->fixedgc = NULL;
	g->firstold1 = g->survival = g->old1 = g->reallyold = NULL;
	g->finobjsur = g->finobjold1 = g->finobjrold = NULL;
	g->sweepgc = NULL;
	g->gray = g->grayagain = NULL;
	g->weak = g->ephemeron = g->allweak = NULL;
	g->twups = NULL;
	g->totalbytes = sizeof(LG);
	g->GCdebt = 0;
	g->lastatomic = 0;
	{
		TValue *io = (&g->nilvalue);
		((io)->value_).i = (0);
		((io)->tt_ = (((3) | ((0) << 4))));
	};
	((g->gcpause) = (200) / 4);
	((g->gcstepmul) = (100) / 4);
	g->gcstepsize = 13;
	((g->genmajormul) = (100) / 4);
	g->genminormul = 20;
	for (i = 0; i < 9; i++)
		g->mt[i] = NULL;
	if (luaD_rawrunprotected(L, f_luaopen, NULL) != 0)
	{

		close_state(L);
		L = NULL;
	}
	return L;
}

extern void lua_close(lua_State *L)
{
	((void) 0);
	L = (L->l_G)->mainthread;
	close_state(L);
}

void luaE_warning(lua_State *L, const char *msg, int tocont)
{
	lua_WarnFunction wf = (L->l_G)->warnf;
	if (wf != NULL)
		wf((L->l_G)->ud_warn, msg, tocont);
}

void luaE_warnerror(lua_State *L, const char *where)
{
	TValue *errobj = (&(L->top - 1)->val);
	const char *msg = ((((((((errobj))->tt_)) & 0x0F)) == (4)))
						  ? ((((&((((union GCUnion *) ((((errobj)->value_).gc))))->ts))))->contents)
						  : "error object is not a string";

	luaE_warning(L, "error in ", 1);
	luaE_warning(L, where, 1);
	luaE_warning(L, " (", 1);
	luaE_warning(L, msg, 1);
	luaE_warning(L, ")", 0);
}
