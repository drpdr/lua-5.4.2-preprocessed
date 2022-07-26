

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
static int l_strton(const TValue *obj, TValue *result)
{
	((void) 0);
	if (!(((((((obj))->tt_)) & 0x0F)) == (4)))
		return 0;
	else
		return (luaO_str2num(((((&((((union GCUnion *) ((((obj)->value_).gc))))->ts))))->contents),
							 result) ==
				((((&((((union GCUnion *) ((((obj)->value_).gc))))->ts))))->tt == ((4) | ((0) << 4))
					 ? (((&((((union GCUnion *) ((((obj)->value_).gc))))->ts))))->shrlen
					 : (((&((((union GCUnion *) ((((obj)->value_).gc))))->ts))))->u.lnglen) +
					1);
}

int luaV_tonumber_(const TValue *obj, lua_Number *n)
{
	TValue v;
	if (((((obj))->tt_) == (((3) | ((0) << 4)))))
	{
		*n = ((lua_Number) (((((obj)->value_).i))));
		return 1;
	}
	else if (l_strton(obj, &v))
	{
		*n = ((((((&v))->tt_) == (((3) | ((0) << 4)))) ? ((lua_Number) (((((&v)->value_).i))))
													   : (((&v)->value_).n)));
		return 1;
	}
	else
		return 0;
}

int luaV_flttointeger(lua_Number n, lua_Integer *p, F2Imod mode)
{
	lua_Number f = (floor(n));
	if (n != f)
	{
		if (mode == F2Ieq)
			return 0;
		else if (mode == F2Iceil)
			f += 1;
	}
	return ((f) >= (double) (LUA_MININTEGER) && (f) < -(double) (LUA_MININTEGER) &&
			(*(p) = (LUA_INTEGER) (f), 1));
}

int luaV_tointegerns(const TValue *obj, lua_Integer *p, F2Imod mode)
{
	if (((((obj))->tt_) == (((3) | ((1) << 4)))))
		return luaV_flttointeger((((obj)->value_).n), p, mode);
	else if (((((obj))->tt_) == (((3) | ((0) << 4)))))
	{
		*p = (((obj)->value_).i);
		return 1;
	}
	else
		return 0;
}

int luaV_tointeger(const TValue *obj, lua_Integer *p, F2Imod mode)
{
	TValue v;
	if (l_strton(obj, &v))
		obj = &v;
	return luaV_tointegerns(obj, p, mode);
}
static int forlimit(lua_State *L, lua_Integer init, const TValue *lim, lua_Integer *p,
					lua_Integer step)
{
	if (!luaV_tointeger(lim, p, (step < 0 ? F2Iceil : F2Ifloor)))
	{

		lua_Number flim;
		if (!(((((lim))->tt_) == (((3) | ((1) << 4)))) ? (*(&flim) = (((lim)->value_).n), 1)
													   : luaV_tonumber_(lim, &flim)))
			luaG_forerror(L, lim, "limit");

		if (((0) < (flim)))
		{
			if (step < 0)
				return 1;
			*p = LUA_MAXINTEGER;
		}
		else
		{
			if (step > 0)
				return 1;
			*p = LUA_MININTEGER;
		}
	}
	return (step > 0 ? init > *p : init < *p);
}
static int forprep(lua_State *L, StkId ra)
{
	TValue *pinit = (&(ra)->val);
	TValue *plimit = (&(ra + 1)->val);
	TValue *pstep = (&(ra + 2)->val);
	if (((((pinit))->tt_) == (((3) | ((0) << 4)))) && ((((pstep))->tt_) == (((3) | ((0) << 4)))))
	{
		lua_Integer init = (((pinit)->value_).i);
		lua_Integer step = (((pstep)->value_).i);
		lua_Integer limit;
		if (step == 0)
			luaG_runerror(L, "'for' step is zero");
		{
			TValue *io = ((&(ra + 3)->val));
			((io)->value_).i = (init);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		if (forlimit(L, init, plimit, &limit, step))
			return 1;
		else
		{
			lua_Unsigned count;
			if (step > 0)
			{
				count = ((lua_Unsigned) (limit)) - ((lua_Unsigned) (init));
				if (step != 1)
					count /= ((lua_Unsigned) (step));
			}
			else
			{
				count = ((lua_Unsigned) (init)) - ((lua_Unsigned) (limit));

				count /= ((lua_Unsigned) (-(step + 1))) + 1u;
			}

			{
				TValue *io = (plimit);
				((io)->value_).i = (((lua_Integer) (count)));
				((io)->tt_ = (((3) | ((0) << 4))));
			};
		}
	}
	else
	{
		lua_Number init;
		lua_Number limit;
		lua_Number step;
		if ((__builtin_expect(((!(((((plimit))->tt_) == (((3) | ((1) << 4))))
									  ? (*(&limit) = (((plimit)->value_).n), 1)
									  : luaV_tonumber_(plimit, &limit))) != 0),
							  0)))
			luaG_forerror(L, plimit, "limit");
		if ((__builtin_expect(((!(((((pstep))->tt_) == (((3) | ((1) << 4))))
									  ? (*(&step) = (((pstep)->value_).n), 1)
									  : luaV_tonumber_(pstep, &step))) != 0),
							  0)))
			luaG_forerror(L, pstep, "step");
		if ((__builtin_expect(((!(((((pinit))->tt_) == (((3) | ((1) << 4))))
									  ? (*(&init) = (((pinit)->value_).n), 1)
									  : luaV_tonumber_(pinit, &init))) != 0),
							  0)))
			luaG_forerror(L, pinit, "initial value");
		if (step == 0)
			luaG_runerror(L, "'for' step is zero");
		if (((0) < (step)) ? ((limit) < (init)) : ((init) < (limit)))
			return 1;
		else
		{

			{
				TValue *io = (plimit);
				((io)->value_).n = (limit);
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			{
				TValue *io = (pstep);
				((io)->value_).n = (step);
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			{
				TValue *io = ((&(ra)->val));
				((io)->value_).n = (init);
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			{
				TValue *io = ((&(ra + 3)->val));
				((io)->value_).n = (init);
				((io)->tt_ = (((3) | ((1) << 4))));
			};
		}
	}
	return 0;
}

static int floatforloop(StkId ra)
{
	lua_Number step = ((((&(ra + 2)->val))->value_).n);
	lua_Number limit = ((((&(ra + 1)->val))->value_).n);
	lua_Number idx = ((((&(ra)->val))->value_).n);
	idx = ((idx) + (step));
	if (((0) < (step)) ? ((idx) <= (limit)) : ((limit) <= (idx)))
	{
		{
			TValue *io = ((&(ra)->val));
			((void) 0);
			((io)->value_).n = (idx);
		};
		{
			TValue *io = ((&(ra + 3)->val));
			((io)->value_).n = (idx);
			((io)->tt_ = (((3) | ((1) << 4))));
		};
		return 1;
	}
	else
		return 0;
}

void luaV_finishget(lua_State *L, const TValue *t, TValue *key, StkId val, const TValue *slot)
{
	int loop;
	const TValue *tm;
	for (loop = 0; loop < 2000; loop++)
	{
		if (slot == NULL)
		{
			((void) 0);
			tm = luaT_gettmbyobj(L, t, TM_INDEX);
			if ((__builtin_expect((((((((((tm))->tt_)) & 0x0F)) == (0))) != 0), 0)))
				luaG_typeerror(L, t, "index");
		}
		else
		{
			((void) 0);
			tm = ((((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->metatable) == NULL ? NULL
				  : ((((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->metatable)->flags &
					 (1u << (TM_INDEX)))
					  ? NULL
					  : luaT_gettm(((&((((union GCUnion *) ((((t)->value_).gc))))->h)))->metatable,
								   TM_INDEX, ((L->l_G))->tmname[TM_INDEX]));
			if (tm == NULL)
			{
				(((&(val)->val))->tt_ = (((0) | ((0) << 4))));
				return;
			}
		}
		if (((((((tm)->tt_)) & 0x0F)) == (6)))
		{
			luaT_callTMres(L, tm, t, key, val);
			return;
		}
		t = tm;
		if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
				 ? (slot = NULL, 0)
				 : (slot = luaH_get(((&((((union GCUnion *) ((((t)->value_).gc))))->h))), key),
					!(((((((slot))->tt_)) & 0x0F)) == (0)))))
		{
			{
				TValue *io1 = ((&(val)->val));
				const TValue *io2 = (slot);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			return;
		}
	}
	luaG_runerror(L, "'__index' chain too long; possible loop");
}
void luaV_finishset(lua_State *L, const TValue *t, TValue *key, TValue *val, const TValue *slot)
{
	int loop;
	for (loop = 0; loop < 2000; loop++)
	{
		const TValue *tm;
		if (slot != NULL)
		{
			Table *h = ((&((((union GCUnion *) ((((t)->value_).gc))))->h)));
			((void) 0);
			tm = ((h->metatable) == NULL ? NULL
				  : ((h->metatable)->flags & (1u << (TM_NEWINDEX)))
					  ? NULL
					  : luaT_gettm(h->metatable, TM_NEWINDEX, ((L->l_G))->tmname[TM_NEWINDEX]));
			if (tm == NULL)
			{
				if (((((slot))->tt_) == (((0) | ((2) << 4)))))
					slot = luaH_newkey(L, h, key);

				{
					TValue *io1 = (((TValue *) (slot)));
					const TValue *io2 = (val);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
				((h)->flags &= ~(~(~0u << (TM_EQ + 1))));
				(((((val)->tt_) & (1 << 6)) &&
				  ((((&(((union GCUnion *) ((h)))->gc)))->marked) & ((1 << (5)))) &&
				  ((((((val)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
					 ? luaC_barrierback_(L, (&(((union GCUnion *) ((h)))->gc)))
					 : ((void) ((0))));
				return;
			}
		}
		else
		{
			tm = luaT_gettmbyobj(L, t, TM_NEWINDEX);
			if ((__builtin_expect((((((((((tm))->tt_)) & 0x0F)) == (0))) != 0), 0)))
				luaG_typeerror(L, t, "index");
		}

		if (((((((tm)->tt_)) & 0x0F)) == (6)))
		{
			luaT_callTM(L, tm, t, key, val);
			return;
		}
		t = tm;
		if ((!((((t))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
				 ? (slot = NULL, 0)
				 : (slot = luaH_get(((&((((union GCUnion *) ((((t)->value_).gc))))->h))), key),
					!(((((((slot))->tt_)) & 0x0F)) == (0)))))
		{
			{
				{
					TValue *io1 = (((TValue *) (slot)));
					const TValue *io2 = (val);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
				(((((val)->tt_) & (1 << 6)) && ((((((t)->value_).gc))->marked) & ((1 << (5)))) &&
				  ((((((val)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
					 ? luaC_barrierback_(L, (((t)->value_).gc))
					 : ((void) ((0))));
			};
			return;
		}
	}
	luaG_runerror(L, "'__newindex' chain too long; possible loop");
}
static int l_strcmp(const TString *ls, const TString *rs)
{
	const char *l = ((ls)->contents);
	size_t ll = ((ls)->tt == ((4) | ((0) << 4)) ? (ls)->shrlen : (ls)->u.lnglen);
	const char *r = ((rs)->contents);
	size_t lr = ((rs)->tt == ((4) | ((0) << 4)) ? (rs)->shrlen : (rs)->u.lnglen);
	for (;;)
	{
		int temp = strcoll(l, r);
		if (temp != 0)
			return temp;
		else
		{
			size_t len = strlen(l);
			if (len == lr)
				return (len == ll) ? 0 : 1;
			else if (len == ll)
				return -1;

			len++;
			l += len;
			ll -= len;
			r += len;
			lr -= len;
		}
	}
}
static int LTintfloat(lua_Integer i, lua_Number f)
{
	if (1)
		return ((((lua_Number) ((i)))) < (f));
	else
	{
		lua_Integer fi;
		if (luaV_flttointeger(f, &fi, F2Iceil))
			return i < fi;
		else
			return f > 0;
	}
}

static int LEintfloat(lua_Integer i, lua_Number f)
{
	if (1)
		return ((((lua_Number) ((i)))) <= (f));
	else
	{
		lua_Integer fi;
		if (luaV_flttointeger(f, &fi, F2Ifloor))
			return i <= fi;
		else
			return f > 0;
	}
}

static int LTfloatint(lua_Number f, lua_Integer i)
{
	if (1)
		return ((f) < (((lua_Number) ((i)))));
	else
	{
		lua_Integer fi;
		if (luaV_flttointeger(f, &fi, F2Ifloor))
			return fi < i;
		else
			return f < 0;
	}
}

static int LEfloatint(lua_Number f, lua_Integer i)
{
	if (1)
		return ((f) <= (((lua_Number) ((i)))));
	else
	{
		lua_Integer fi;
		if (luaV_flttointeger(f, &fi, F2Iceil))
			return fi <= i;
		else
			return f < 0;
	}
}

static int LTnum(const TValue *l, const TValue *r)
{
	((void) 0);
	if (((((l))->tt_) == (((3) | ((0) << 4)))))
	{
		lua_Integer li = (((l)->value_).i);
		if (((((r))->tt_) == (((3) | ((0) << 4)))))
			return li < (((r)->value_).i);
		else
			return LTintfloat(li, (((r)->value_).n));
	}
	else
	{
		lua_Number lf = (((l)->value_).n);
		if (((((r))->tt_) == (((3) | ((1) << 4)))))
			return ((lf) < ((((r)->value_).n)));
		else
			return LTfloatint(lf, (((r)->value_).i));
	}
}

static int LEnum(const TValue *l, const TValue *r)
{
	((void) 0);
	if (((((l))->tt_) == (((3) | ((0) << 4)))))
	{
		lua_Integer li = (((l)->value_).i);
		if (((((r))->tt_) == (((3) | ((0) << 4)))))
			return li <= (((r)->value_).i);
		else
			return LEintfloat(li, (((r)->value_).n));
	}
	else
	{
		lua_Number lf = (((l)->value_).n);
		if (((((r))->tt_) == (((3) | ((1) << 4)))))
			return ((lf) <= ((((r)->value_).n)));
		else
			return LEfloatint(lf, (((r)->value_).i));
	}
}

static int lessthanothers(lua_State *L, const TValue *l, const TValue *r)
{
	((void) 0);
	if ((((((((l))->tt_)) & 0x0F)) == (4)) && (((((((r))->tt_)) & 0x0F)) == (4)))
		return l_strcmp(((&((((union GCUnion *) ((((l)->value_).gc))))->ts))),
						((&((((union GCUnion *) ((((r)->value_).gc))))->ts)))) < 0;
	else
		return luaT_callorderTM(L, l, r, TM_LT);
}

int luaV_lessthan(lua_State *L, const TValue *l, const TValue *r)
{
	if ((((((((l))->tt_)) & 0x0F)) == (3)) && (((((((r))->tt_)) & 0x0F)) == (3)))
		return LTnum(l, r);
	else
		return lessthanothers(L, l, r);
}

static int lessequalothers(lua_State *L, const TValue *l, const TValue *r)
{
	((void) 0);
	if ((((((((l))->tt_)) & 0x0F)) == (4)) && (((((((r))->tt_)) & 0x0F)) == (4)))
		return l_strcmp(((&((((union GCUnion *) ((((l)->value_).gc))))->ts))),
						((&((((union GCUnion *) ((((r)->value_).gc))))->ts)))) <= 0;
	else
		return luaT_callorderTM(L, l, r, TM_LE);
}

int luaV_lessequal(lua_State *L, const TValue *l, const TValue *r)
{
	if ((((((((l))->tt_)) & 0x0F)) == (3)) && (((((((r))->tt_)) & 0x0F)) == (3)))
		return LEnum(l, r);
	else
		return lessequalothers(L, l, r);
}

int luaV_equalobj(lua_State *L, const TValue *t1, const TValue *t2)
{
	const TValue *tm;
	if (((((t1)->tt_)) & 0x3F) != ((((t2)->tt_)) & 0x3F))
	{
		if ((((((t1)->tt_)) & 0x0F)) != (((((t2)->tt_)) & 0x0F)) || (((((t1)->tt_)) & 0x0F)) != 3)
			return 0;
		else
		{
			lua_Integer i1, i2;
			return ((((((t1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((t1)->value_).i), 1)
															 : luaV_tointegerns(t1, &i1, F2Ieq)) &&
					(((((t2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((t2)->value_).i), 1)
															 : luaV_tointegerns(t2, &i2, F2Ieq)) &&
					i1 == i2);
		}
	}

	switch (((((t1)->tt_)) & 0x3F))
	{
	case ((0) | ((0) << 4)):
	case ((1) | ((0) << 4)):
	case ((1) | ((1) << 4)):
		return 1;
	case ((3) | ((0) << 4)):
		return ((((t1)->value_).i) == (((t2)->value_).i));
	case ((3) | ((1) << 4)):
		return (((((t1)->value_).n)) == ((((t2)->value_).n)));
	case ((2) | ((0) << 4)):
		return (((t1)->value_).p) == (((t2)->value_).p);
	case ((6) | ((1) << 4)):
		return (((t1)->value_).f) == (((t2)->value_).f);
	case ((4) | ((0) << 4)):
		return ((((&((((union GCUnion *) ((((t1)->value_).gc))))->ts)))) ==
				(((&((((union GCUnion *) ((((t2)->value_).gc))))->ts)))));
	case ((4) | ((1) << 4)):
		return luaS_eqlngstr(((&((((union GCUnion *) ((((t1)->value_).gc))))->ts))),
							 ((&((((union GCUnion *) ((((t2)->value_).gc))))->ts))));
	case ((7) | ((0) << 4)):
	{
		if (((&((((union GCUnion *) ((((t1)->value_).gc))))->u))) ==
			((&((((union GCUnion *) ((((t2)->value_).gc))))->u))))
			return 1;
		else if (L == NULL)
			return 0;
		tm = ((((&((((union GCUnion *) ((((t1)->value_).gc))))->u)))->metatable) == NULL ? NULL
			  : ((((&((((union GCUnion *) ((((t1)->value_).gc))))->u)))->metatable)->flags &
				 (1u << (TM_EQ)))
				  ? NULL
				  : luaT_gettm(((&((((union GCUnion *) ((((t1)->value_).gc))))->u)))->metatable,
							   TM_EQ, ((L->l_G))->tmname[TM_EQ]));
		if (tm == NULL)
			tm = ((((&((((union GCUnion *) ((((t2)->value_).gc))))->u)))->metatable) == NULL ? NULL
				  : ((((&((((union GCUnion *) ((((t2)->value_).gc))))->u)))->metatable)->flags &
					 (1u << (TM_EQ)))
					  ? NULL
					  : luaT_gettm(((&((((union GCUnion *) ((((t2)->value_).gc))))->u)))->metatable,
								   TM_EQ, ((L->l_G))->tmname[TM_EQ]));
		break;
	}
	case ((5) | ((0) << 4)):
	{
		if (((&((((union GCUnion *) ((((t1)->value_).gc))))->h))) ==
			((&((((union GCUnion *) ((((t2)->value_).gc))))->h))))
			return 1;
		else if (L == NULL)
			return 0;
		tm = ((((&((((union GCUnion *) ((((t1)->value_).gc))))->h)))->metatable) == NULL ? NULL
			  : ((((&((((union GCUnion *) ((((t1)->value_).gc))))->h)))->metatable)->flags &
				 (1u << (TM_EQ)))
				  ? NULL
				  : luaT_gettm(((&((((union GCUnion *) ((((t1)->value_).gc))))->h)))->metatable,
							   TM_EQ, ((L->l_G))->tmname[TM_EQ]));
		if (tm == NULL)
			tm = ((((&((((union GCUnion *) ((((t2)->value_).gc))))->h)))->metatable) == NULL ? NULL
				  : ((((&((((union GCUnion *) ((((t2)->value_).gc))))->h)))->metatable)->flags &
					 (1u << (TM_EQ)))
					  ? NULL
					  : luaT_gettm(((&((((union GCUnion *) ((((t2)->value_).gc))))->h)))->metatable,
								   TM_EQ, ((L->l_G))->tmname[TM_EQ]));
		break;
	}
	default:
		return (((t1)->value_).gc) == (((t2)->value_).gc);
	}
	if (tm == NULL)
		return 0;
	else
	{
		luaT_callTMres(L, tm, t1, t2, L->top);
		return !((((((&(L->top)->val)))->tt_) == (((1) | ((0) << 4)))) ||
				 ((((((((&(L->top)->val)))->tt_)) & 0x0F)) == (0)));
	}
}
static void copy2buff(StkId top, int n, char *buff)
{
	size_t tl = 0;
	do
	{
		size_t l =
			((((&((((union GCUnion *) (((((&(top - n)->val))->value_).gc))))->ts))))->tt ==
					 ((4) | ((0) << 4))
				 ? (((&((((union GCUnion *) (((((&(top - n)->val))->value_).gc))))->ts))))->shrlen
				 : (((&((((union GCUnion *) (((((&(top - n)->val))->value_).gc))))->ts))))
					   ->u.lnglen);
		memcpy(buff + tl,
			   ((((&((((union GCUnion *) (((((&(top - n)->val))->value_).gc))))->ts))))->contents),
			   l * sizeof(char));
		tl += l;
	} while (--n > 0);
}

void luaV_concat(lua_State *L, int total)
{
	if (total == 1)
		return;
	do
	{
		StkId top = L->top;
		int n = 2;
		if (!(((((((((&(top - 2)->val)))->tt_)) & 0x0F)) == (4)) ||
			  ((((((((&(top - 2)->val)))->tt_)) & 0x0F)) == (3))) ||
			!(((((((((&(top - 1)->val)))->tt_)) & 0x0F)) == (4)) ||
			  (((((((((&(top - 1)->val)))->tt_)) & 0x0F)) == (3)) &&
			   (luaO_tostring(L, (&(top - 1)->val)), 1))))
			luaT_tryconcatTM(L);
		else if (((((((&(top - 1)->val)))->tt_) == (((((4) | ((0) << 4))) | (1 << 6)))) &&
				  ((&((((union GCUnion *) (((((&(top - 1)->val))->value_).gc))))->ts)))->shrlen ==
					  0))
			((void) (((((((((((&(top - 2)->val)))->tt_)) & 0x0F)) == (4)) ||
					   (((((((((&(top - 2)->val)))->tt_)) & 0x0F)) == (3)) &&
						(luaO_tostring(L, (&(top - 2)->val)), 1))))));
		else if (((((((&(top - 2)->val)))->tt_) == (((((4) | ((0) << 4))) | (1 << 6)))) &&
				  ((&((((union GCUnion *) (((((&(top - 2)->val))->value_).gc))))->ts)))->shrlen ==
					  0))
		{
			{
				TValue *io1 = ((&(top - 2)->val));
				const TValue *io2 = ((&(top - 1)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
		}
		else
		{

			size_t tl =
				((((&((((union GCUnion *) (((((&(top - 1)->val))->value_).gc))))->ts))))->tt ==
						 ((4) | ((0) << 4))
					 ? (((&((((union GCUnion *) (((((&(top - 1)->val))->value_).gc))))->ts))))
						   ->shrlen
					 : (((&((((union GCUnion *) (((((&(top - 1)->val))->value_).gc))))->ts))))
						   ->u.lnglen);
			TString *ts;

			for (n = 1; n < total && (((((((((&(top - n - 1)->val)))->tt_)) & 0x0F)) == (4)) ||
									  (((((((((&(top - n - 1)->val)))->tt_)) & 0x0F)) == (3)) &&
									   (luaO_tostring(L, (&(top - n - 1)->val)), 1)));
				 n++)
			{
				size_t l =
					((((&((((union GCUnion *) (((((&(top - n - 1)->val))->value_).gc))))->ts))))
								 ->tt == ((4) | ((0) << 4))
						 ? (((&((((union GCUnion *) (((((&(top - n - 1)->val))->value_).gc))))
									->ts))))
							   ->shrlen
						 : (((&((((union GCUnion *) (((((&(top - n - 1)->val))->value_).gc))))
									->ts))))
							   ->u.lnglen);
				if ((__builtin_expect(
						((l >= ((sizeof(size_t) < sizeof(lua_Integer) ? ((size_t) (~(size_t) 0))
																	  : (size_t) (LUA_MAXINTEGER)) /
								sizeof(char)) -
								   tl) != 0),
						0)))
					luaG_runerror(L, "string length overflow");
				tl += l;
			}
			if (tl <= 40)
			{
				char buff[40];
				copy2buff(top, n, buff);
				ts = luaS_newlstr(L, buff, tl);
			}
			else
			{
				ts = luaS_createlngstrobj(L, tl);
				copy2buff(top, n, ((ts)->contents));
			}
			{
				TValue *io = ((&(top - n)->val));
				TString *x_ = (ts);
				((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
				((io)->tt_ = (((x_->tt) | (1 << 6))));
				((void) L, ((void) 0));
			};
		}
		total -= n - 1;
		L->top -= n - 1;
	} while (total > 1);
}

void luaV_objlen(lua_State *L, StkId ra, const TValue *rb)
{
	const TValue *tm;
	switch (((((rb)->tt_)) & 0x3F))
	{
	case ((5) | ((0) << 4)):
	{
		Table *h = ((&((((union GCUnion *) ((((rb)->value_).gc))))->h)));
		tm = ((h->metatable) == NULL ? NULL
			  : ((h->metatable)->flags & (1u << (TM_LEN)))
				  ? NULL
				  : luaT_gettm(h->metatable, TM_LEN, ((L->l_G))->tmname[TM_LEN]));
		if (tm)
			break;
		{
			TValue *io = ((&(ra)->val));
			((io)->value_).i = (luaH_getn(h));
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		return;
	}
	case ((4) | ((0) << 4)):
	{
		{
			TValue *io = ((&(ra)->val));
			((io)->value_).i = (((&((((union GCUnion *) ((((rb)->value_).gc))))->ts)))->shrlen);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		return;
	}
	case ((4) | ((1) << 4)):
	{
		{
			TValue *io = ((&(ra)->val));
			((io)->value_).i = (((&((((union GCUnion *) ((((rb)->value_).gc))))->ts)))->u.lnglen);
			((io)->tt_ = (((3) | ((0) << 4))));
		};
		return;
	}
	default:
	{
		tm = luaT_gettmbyobj(L, rb, TM_LEN);
		if ((__builtin_expect((((((((((tm))->tt_)) & 0x0F)) == (0))) != 0), 0)))
			luaG_typeerror(L, rb, "get length of");
		break;
	}
	}
	luaT_callTMres(L, tm, rb, rb, ra);
}
lua_Integer luaV_idiv(lua_State *L, lua_Integer m, lua_Integer n)
{
	if ((__builtin_expect(((((lua_Unsigned) (n)) + 1u <= 1u) != 0), 0)))
	{
		if (n == 0)
			luaG_runerror(L, "attempt to divide by zero");
		return ((lua_Integer) (((lua_Unsigned) (0)) - ((lua_Unsigned) (m))));
	}
	else
	{
		lua_Integer q = m / n;
		if ((m ^ n) < 0 && m % n != 0)
			q -= 1;
		return q;
	}
}

lua_Integer luaV_mod(lua_State *L, lua_Integer m, lua_Integer n)
{
	if ((__builtin_expect(((((lua_Unsigned) (n)) + 1u <= 1u) != 0), 0)))
	{
		if (n == 0)
			luaG_runerror(L, "attempt to perform 'n%%0'");
		return 0;
	}
	else
	{
		lua_Integer r = m % n;
		if (r != 0 && (r ^ n) < 0)
			r += n;
		return r;
	}
}

lua_Number luaV_modf(lua_State *L, lua_Number m, lua_Number n)
{
	lua_Number r;
	{
		(void) L;
		(r) = fmod(m, n);
		if (((r) > 0) ? (n) < 0 : ((r) < 0 && (n) > 0))
			(r) += (n);
	};
	return r;
}
lua_Integer luaV_shiftl(lua_Integer x, lua_Integer y)
{
	if (y < 0)
	{
		if (y <= -((int) ((sizeof(lua_Integer) * CHAR_BIT))))
			return 0;
		else
			return ((lua_Integer) (((lua_Unsigned) (x)) >> ((lua_Unsigned) (-y))));
	}
	else
	{
		if (y >= ((int) ((sizeof(lua_Integer) * CHAR_BIT))))
			return 0;
		else
			return ((lua_Integer) (((lua_Unsigned) (x)) << ((lua_Unsigned) (y))));
	}
}

static void pushclosure(lua_State *L, Proto *p, UpVal **encup, StkId base, StkId ra)
{
	int nup = p->sizeupvalues;
	Upvaldesc *uv = p->upvalues;
	int i;
	LClosure *ncl = luaF_newLclosure(L, nup);
	ncl->p = p;
	{
		TValue *io = ((&(ra)->val));
		LClosure *x_ = (ncl);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((((6) | ((0) << 4))) | (1 << 6))));
		((void) L, ((void) 0));
	};
	for (i = 0; i < nup; i++)
	{
		if (uv[i].instack)
			ncl->upvals[i] = luaF_findupval(L, base + uv[i].idx);
		else
			ncl->upvals[i] = encup[uv[i].idx];
		(((((ncl)->marked) & ((1 << (5)))) &&
		  (((ncl->upvals[i])->marked) & (((1 << (3)) | (1 << (4))))))
			 ? luaC_barrier_(L, (&(((union GCUnion *) ((ncl)))->gc)),
							 (&(((union GCUnion *) ((ncl->upvals[i])))->gc)))
			 : ((void) ((0))));
	}
}

void luaV_finishOp(lua_State *L)
{
	CallInfo *ci = L->ci;
	StkId base = ci->func + 1;
	Instruction inst = *(ci->u.l.savedpc - 1);
	OpCode op = (((OpCode) (((inst) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))));
	switch (op)
	{
	case OP_MMBIN:
	case OP_MMBINI:
	case OP_MMBINK:
	{
		{
			TValue *io1 = ((&(base + (((int) ((((*(ci->u.l.savedpc - 2)) >> ((0 + 7))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))
								 ->val));
			const TValue *io2 = ((&(--L->top)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		break;
	}
	case OP_UNM:
	case OP_BNOT:
	case OP_LEN:
	case OP_GETTABUP:
	case OP_GETTABLE:
	case OP_GETI:
	case OP_GETFIELD:
	case OP_SELF:
	{
		{
			TValue *io1 =
				((&(base +
					(((int) ((((inst) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))))
					   ->val));
			const TValue *io2 = ((&(--L->top)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		break;
	}
	case OP_LT:
	case OP_LE:
	case OP_LTI:
	case OP_LEI:
	case OP_GTI:
	case OP_GEI:
	case OP_EQ:
	{
		int res = !((((((&(L->top - 1)->val)))->tt_) == (((1) | ((0) << 4)))) ||
					((((((((&(L->top - 1)->val)))->tt_)) & 0x0F)) == (0)));
		L->top--;

		((void) 0);
		if (res !=
			((((int) ((((inst) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0))))))))
			ci->u.l.savedpc++;
		break;
	}
	case OP_CONCAT:
	{
		StkId top = L->top - 1;
		int a = (((int) ((((inst) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0))))));
		int total = ((int) ((top - 1 - (base + a))));
		{
			TValue *io1 = ((&(top - 2)->val));
			const TValue *io2 = ((&(top)->val));
			io1->value_ = io2->value_;
			((io1)->tt_ = (io2->tt_));
			((void) L, ((void) 0));
			((void) 0);
		};
		L->top = top - 1;
		luaV_concat(L, total);
		break;
	}
	default:
	{

		((void) 0);

		break;
	}
	}
}
void luaV_execute(lua_State *L, CallInfo *ci)
{
	LClosure *cl;
	TValue *k;
	StkId base;
	const Instruction *pc;
	int trap;

	static const void *const disptab[((int) (OP_EXTRAARG) + 1)] = {
		&&L_OP_MOVE,	  &&L_OP_LOADI,		 &&L_OP_LOADF,	  &&L_OP_LOADK,	   &&L_OP_LOADKX,
		&&L_OP_LOADFALSE, &&L_OP_LFALSESKIP, &&L_OP_LOADTRUE, &&L_OP_LOADNIL,  &&L_OP_GETUPVAL,
		&&L_OP_SETUPVAL,  &&L_OP_GETTABUP,	 &&L_OP_GETTABLE, &&L_OP_GETI,	   &&L_OP_GETFIELD,
		&&L_OP_SETTABUP,  &&L_OP_SETTABLE,	 &&L_OP_SETI,	  &&L_OP_SETFIELD, &&L_OP_NEWTABLE,
		&&L_OP_SELF,	  &&L_OP_ADDI,		 &&L_OP_ADDK,	  &&L_OP_SUBK,	   &&L_OP_MULK,
		&&L_OP_MODK,	  &&L_OP_POWK,		 &&L_OP_DIVK,	  &&L_OP_IDIVK,	   &&L_OP_BANDK,
		&&L_OP_BORK,	  &&L_OP_BXORK,		 &&L_OP_SHRI,	  &&L_OP_SHLI,	   &&L_OP_ADD,
		&&L_OP_SUB,		  &&L_OP_MUL,		 &&L_OP_MOD,	  &&L_OP_POW,	   &&L_OP_DIV,
		&&L_OP_IDIV,	  &&L_OP_BAND,		 &&L_OP_BOR,	  &&L_OP_BXOR,	   &&L_OP_SHL,
		&&L_OP_SHR,		  &&L_OP_MMBIN,		 &&L_OP_MMBINI,	  &&L_OP_MMBINK,   &&L_OP_UNM,
		&&L_OP_BNOT,	  &&L_OP_NOT,		 &&L_OP_LEN,	  &&L_OP_CONCAT,   &&L_OP_CLOSE,
		&&L_OP_TBC,		  &&L_OP_JMP,		 &&L_OP_EQ,		  &&L_OP_LT,	   &&L_OP_LE,
		&&L_OP_EQK,		  &&L_OP_EQI,		 &&L_OP_LTI,	  &&L_OP_LEI,	   &&L_OP_GTI,
		&&L_OP_GEI,		  &&L_OP_TEST,		 &&L_OP_TESTSET,  &&L_OP_CALL,	   &&L_OP_TAILCALL,
		&&L_OP_RETURN,	  &&L_OP_RETURN0,	 &&L_OP_RETURN1,  &&L_OP_FORLOOP,  &&L_OP_FORPREP,
		&&L_OP_TFORPREP,  &&L_OP_TFORCALL,	 &&L_OP_TFORLOOP, &&L_OP_SETLIST,  &&L_OP_CLOSURE,
		&&L_OP_VARARG,	  &&L_OP_VARARGPREP, &&L_OP_EXTRAARG

	};

startfunc:
	trap = L->hookmask;
returning:
	cl = ((&((((union GCUnion *) (((((&(ci->func)->val))->value_).gc))))->cl.l)));
	k = cl->p->k;
	pc = ci->u.l.savedpc;
	if (trap)
	{
		if (pc == cl->p->code)
		{
			if (cl->p->is_vararg)
				trap = 0;
			else
				luaD_hookcall(L, ci);
		}
		ci->u.l.trap = 1;
	}
	base = ci->func + 1;

	for (;;)
	{
		Instruction i;
		StkId ra;
		{
			if (trap)
			{
				trap = luaG_traceexec(L, pc);
				(base = ci->func + 1);
			}
			i = *(pc++);
			ra =
				(base + (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
		};
		((void) 0);
		((void) 0);

		((void) 0);
		goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
		{
		L_OP_MOVE:
		{
			{
				TValue *io1 = ((&(ra)->val));
				const TValue *io2 =
					((&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
										   ((~((~(Instruction) 0) << (8))) << (0)))))))))
						   ->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADI:
		{
			lua_Integer b = ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))) -
							 (INT_MAX >> 1));
			{
				TValue *io = ((&(ra)->val));
				((io)->value_).i = (b);
				((io)->tt_ = (((3) | ((0) << 4))));
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADF:
		{
			int b = ((((int) ((((i) >> (((0 + 7) + 8))) &
							   ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))) -
					 (INT_MAX >> 1));
			{
				TValue *io = ((&(ra)->val));
				((io)->value_).n = (((lua_Number) ((b))));
				((io)->tt_ = (((3) | ((1) << 4))));
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADK:
		{
			TValue *rb = k + ((((int) ((((i) >> (((0 + 7) + 8))) &
										((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))));
			{
				TValue *io1 = ((&(ra)->val));
				const TValue *io2 = (rb);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADKX:
		{
			TValue *rb;
			rb = k + ((((int) ((((*pc) >> ((0 + 7))) &
								((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))));
			pc++;
			{
				TValue *io1 = ((&(ra)->val));
				const TValue *io2 = (rb);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADFALSE:
		{
			(((&(ra)->val))->tt_ = (((1) | ((0) << 4))));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LFALSESKIP:
		{
			(((&(ra)->val))->tt_ = (((1) | ((0) << 4))));
			pc++;
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADTRUE:
		{
			(((&(ra)->val))->tt_ = (((1) | ((1) << 4))));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LOADNIL:
		{
			int b = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			do
			{
				(((&(ra++)->val))->tt_ = (((0) | ((0) << 4))));
			} while (b--);
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GETUPVAL:
		{
			int b = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			{
				TValue *io1 = ((&(ra)->val));
				const TValue *io2 = (cl->upvals[b]->v);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SETUPVAL:
		{
			UpVal *uv = cl->upvals[((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											  ((~((~(Instruction) 0) << (8))) << (0)))))))];
			{
				TValue *io1 = (uv->v);
				const TValue *io2 = ((&(ra)->val));
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			((((((&(ra)->val))->tt_) & (1 << 6)) && (((uv)->marked) & ((1 << (5)))) &&
			  (((((((&(ra)->val))->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
				 ? luaC_barrier_(L, (&(((union GCUnion *) ((uv)))->gc)),
								 ((((&(ra)->val))->value_).gc))
				 : ((void) ((0))));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GETTABUP:
		{
			const TValue *slot;
			TValue *upval = cl->upvals[((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												  ((~((~(Instruction) 0) << (8))) << (0)))))))]
								->v;
			TValue *rc = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										 ((~((~(Instruction) 0) << (8))) << (0))))))));
			TString *key = ((&((((union GCUnion *) ((((rc)->value_).gc))))->ts)));
			if ((!((((upval))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot = luaH_getshortstr(
							((&((((union GCUnion *) ((((upval)->value_).gc))))->h))), key),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					TValue *io1 = ((&(ra)->val));
					const TValue *io2 = (slot);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaV_finishget(L, upval, rc, ra, slot)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GETTABLE:
		{
			const TValue *slot;
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			TValue *rc = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			lua_Unsigned n;
			if (((((rc))->tt_) == (((3) | ((0) << 4))))
					? (((void) ((n = (((rc)->value_).i)))),
					   (!((((rb))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
							? (slot = NULL, 0)
							: (slot =
								   (((lua_Unsigned) (n)) - 1u <
									((&((((union GCUnion *) ((((rb)->value_).gc))))->h)))->alimit)
									   ? &((&((((union GCUnion *) ((((rb)->value_).gc))))->h)))
											  ->array[n - 1]
									   : luaH_getint(
											 ((&((((union GCUnion *) ((((rb)->value_).gc))))->h))),
											 n),
							   !(((((((slot))->tt_)) & 0x0F)) == (0)))))
					: (!((((rb))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
						   ? (slot = NULL, 0)
						   : (slot = luaH_get(((&((((union GCUnion *) ((((rb)->value_).gc))))->h))),
											  rc),
							  !(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					TValue *io1 = ((&(ra)->val));
					const TValue *io2 = (slot);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top), (luaV_finishget(L, rb, rc, ra, slot)),
				 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GETI:
		{
			const TValue *slot;
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			int c = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			if ((!((((rb))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot = (((lua_Unsigned) (c)) - 1u <
								((&((((union GCUnion *) ((((rb)->value_).gc))))->h)))->alimit)
								   ? &((&((((union GCUnion *) ((((rb)->value_).gc))))->h)))
										  ->array[c - 1]
								   : luaH_getint(
										 ((&((((union GCUnion *) ((((rb)->value_).gc))))->h))), c),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					TValue *io1 = ((&(ra)->val));
					const TValue *io2 = (slot);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
			}
			else
			{
				TValue key;
				{
					TValue *io = (&key);
					((io)->value_).i = (c);
					((io)->tt_ = (((3) | ((0) << 4))));
				};
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaV_finishget(L, rb, &key, ra, slot)), (trap = ci->u.l.trap));
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GETFIELD:
		{
			const TValue *slot;
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			TValue *rc = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										 ((~((~(Instruction) 0) << (8))) << (0))))))));
			TString *key = ((&((((union GCUnion *) ((((rc)->value_).gc))))->ts)));
			if ((!((((rb))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot = luaH_getshortstr(
							((&((((union GCUnion *) ((((rb)->value_).gc))))->h))), key),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					TValue *io1 = ((&(ra)->val));
					const TValue *io2 = (slot);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top), (luaV_finishget(L, rb, rc, ra, slot)),
				 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SETTABUP:
		{
			const TValue *slot;
			TValue *upval = cl->upvals[(((int) ((((i) >> ((0 + 7))) &
												 ((~((~(Instruction) 0) << (8))) << (0))))))]
								->v;
			TValue *rb = (k + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
										 ((~((~(Instruction) 0) << (8))) << (0))))))));
			TValue *rc = ((((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
							  ? k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))
							  : (&(base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
													 ((~((~(Instruction) 0) << (8))) << (0))))))))
									  ->val));
			TString *key = ((&((((union GCUnion *) ((((rb)->value_).gc))))->ts)));
			if ((!((((upval))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot = luaH_getshortstr(
							((&((((union GCUnion *) ((((upval)->value_).gc))))->h))), key),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					{
						TValue *io1 = (((TValue *) (slot)));
						const TValue *io2 = (rc);
						io1->value_ = io2->value_;
						((io1)->tt_ = (io2->tt_));
						((void) L, ((void) 0));
						((void) 0);
					};
					(((((rc)->tt_) & (1 << 6)) &&
					  ((((((upval)->value_).gc))->marked) & ((1 << (5)))) &&
					  ((((((rc)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
						 ? luaC_barrierback_(L, (((upval)->value_).gc))
						 : ((void) ((0))));
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaV_finishset(L, upval, rb, rc, slot)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SETTABLE:
		{
			const TValue *slot;
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			TValue *rc = ((((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
							  ? k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))
							  : (&(base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
													 ((~((~(Instruction) 0) << (8))) << (0))))))))
									  ->val));
			lua_Unsigned n;
			if (((((rb))->tt_) == (((3) | ((0) << 4))))
					? (((void) ((n = (((rb)->value_).i)))),
					   (!(((((&(ra)->val)))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
							? (slot = NULL, 0)
							: (slot =
								   (((lua_Unsigned) (n)) - 1u <
									((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))->h)))
										->alimit)
									   ? &((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))
												  ->h)))
											  ->array[n - 1]
									   : luaH_getint(((&((((union GCUnion *) ((
															  (((&(ra)->val))->value_).gc))))
															 ->h))),
													 n),
							   !(((((((slot))->tt_)) & 0x0F)) == (0)))))
					: (!(((((&(ra)->val)))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
						   ? (slot = NULL, 0)
						   : (slot = luaH_get(
								  ((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))->h))),
								  rb),
							  !(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					{
						TValue *io1 = (((TValue *) (slot)));
						const TValue *io2 = (rc);
						io1->value_ = io2->value_;
						((io1)->tt_ = (io2->tt_));
						((void) L, ((void) 0));
						((void) 0);
					};
					(((((rc)->tt_) & (1 << 6)) &&
					  (((((((&(ra)->val))->value_).gc))->marked) & ((1 << (5)))) &&
					  ((((((rc)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
						 ? luaC_barrierback_(L, ((((&(ra)->val))->value_).gc))
						 : ((void) ((0))));
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaV_finishset(L, (&(ra)->val), rb, rc, slot)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SETI:
		{
			const TValue *slot;
			int c = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			TValue *rc = ((((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
							  ? k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))
							  : (&(base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
													 ((~((~(Instruction) 0) << (8))) << (0))))))))
									  ->val));
			if ((!(((((&(ra)->val)))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot =
							(((lua_Unsigned) (c)) - 1u <
							 ((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))->h)))
								 ->alimit)
								? &((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))->h)))
									   ->array[c - 1]
								: luaH_getint(
									  ((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))
											  ->h))),
									  c),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					{
						TValue *io1 = (((TValue *) (slot)));
						const TValue *io2 = (rc);
						io1->value_ = io2->value_;
						((io1)->tt_ = (io2->tt_));
						((void) L, ((void) 0));
						((void) 0);
					};
					(((((rc)->tt_) & (1 << 6)) &&
					  (((((((&(ra)->val))->value_).gc))->marked) & ((1 << (5)))) &&
					  ((((((rc)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
						 ? luaC_barrierback_(L, ((((&(ra)->val))->value_).gc))
						 : ((void) ((0))));
				};
			}
			else
			{
				TValue key;
				{
					TValue *io = (&key);
					((io)->value_).i = (c);
					((io)->tt_ = (((3) | ((0) << 4))));
				};
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaV_finishset(L, (&(ra)->val), &key, rc, slot)), (trap = ci->u.l.trap));
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SETFIELD:
		{
			const TValue *slot;
			TValue *rb = (k + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
										 ((~((~(Instruction) 0) << (8))) << (0))))))));
			TValue *rc = ((((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
							  ? k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))
							  : (&(base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
													 ((~((~(Instruction) 0) << (8))) << (0))))))))
									  ->val));
			TString *key = ((&((((union GCUnion *) ((((rb)->value_).gc))))->ts)));
			if ((!(((((&(ra)->val)))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot = luaH_getshortstr(
							((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))->h))), key),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					{
						TValue *io1 = (((TValue *) (slot)));
						const TValue *io2 = (rc);
						io1->value_ = io2->value_;
						((io1)->tt_ = (io2->tt_));
						((void) L, ((void) 0));
						((void) 0);
					};
					(((((rc)->tt_) & (1 << 6)) &&
					  (((((((&(ra)->val))->value_).gc))->marked) & ((1 << (5)))) &&
					  ((((((rc)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
						 ? luaC_barrierback_(L, ((((&(ra)->val))->value_).gc))
						 : ((void) ((0))));
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaV_finishset(L, (&(ra)->val), rb, rc, slot)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_NEWTABLE:
		{
			int b = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			int c = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			Table *t;
			if (b > 0)
				b = 1 << (b - 1);
			((void) 0);
			if (((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
				c += ((((int) ((((*pc) >> ((0 + 7))) &
								((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0))))))) *
					 (((1 << 8) - 1) + 1);
			pc++;
			L->top = ra + 1;
			t = luaH_new(L);
			{
				TValue *io = ((&(ra)->val));
				Table *x_ = (t);
				((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
				((io)->tt_ = (((((5) | ((0) << 4))) | (1 << 6))));
				((void) L, ((void) 0));
			};
			if (b != 0 || c != 0)
				luaH_resize(L, t, c, b);
			{
				{
					if ((L->l_G)->GCdebt > 0)
					{
						((ci->u.l.savedpc = pc), L->top = (ra + 1));
						luaC_step(L);
						(trap = ci->u.l.trap);
					};
					((void) 0);
				};
				{
					((void) 0);
					((void) 0);
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SELF:
		{
			const TValue *slot;
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			TValue *rc = ((((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
							  ? k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))
							  : (&(base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
													 ((~((~(Instruction) 0) << (8))) << (0))))))))
									  ->val));
			TString *key = ((&((((union GCUnion *) ((((rc)->value_).gc))))->ts)));
			{
				TValue *io1 = ((&(ra + 1)->val));
				const TValue *io2 = (rb);
				io1->value_ = io2->value_;
				((io1)->tt_ = (io2->tt_));
				((void) L, ((void) 0));
				((void) 0);
			};
			if ((!((((rb))->tt_) == (((((5) | ((0) << 4))) | (1 << 6))))
					 ? (slot = NULL, 0)
					 : (slot =
							luaH_getstr(((&((((union GCUnion *) ((((rb)->value_).gc))))->h))), key),
						!(((((((slot))->tt_)) & 0x0F)) == (0)))))
			{
				{
					TValue *io1 = ((&(ra)->val));
					const TValue *io2 = (slot);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top), (luaV_finishget(L, rb, rc, ra, slot)),
				 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_ADDI:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				int imm = ((((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									   ((~((~(Instruction) 0) << (8))) << (0)))))))) -
						   (((1 << 8) - 1) >> 1));
				if (((((v1))->tt_) == (((3) | ((0) << 4)))))
				{
					lua_Integer iv1 = (((v1)->value_).i);
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (iv1)) + ((lua_Unsigned) (imm)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
				else if (((((v1))->tt_) == (((3) | ((1) << 4)))))
				{
					lua_Number nb = (((v1)->value_).n);
					lua_Number fimm = ((lua_Number) ((imm)));
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).n = (((nb) + (fimm)));
						((io)->tt_ = (((3) | ((1) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_ADDK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i =
								(((lua_Integer) (((lua_Unsigned) (i1)) + ((lua_Unsigned) (i2)))));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((n1) + (n2)));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SUBK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i =
								(((lua_Integer) (((lua_Unsigned) (i1)) - ((lua_Unsigned) (i2)))));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((n1) - (n2)));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MULK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i =
								(((lua_Integer) (((lua_Unsigned) (i1)) * ((lua_Unsigned) (i2)))));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((n1) * (n2)));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MODK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i = (luaV_mod(L, i1, i2));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (luaV_modf(L, n1, n2));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_POWK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					lua_Number n1;
					lua_Number n2;
					if ((((((v1))->tt_) == (((3) | ((1) << 4))))
							 ? ((n1) = (((v1)->value_).n), 1)
							 : (((((v1))->tt_) == (((3) | ((0) << 4))))
									? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
									: 0)) &&
						(((((v2))->tt_) == (((3) | ((1) << 4))))
							 ? ((n2) = (((v2)->value_).n), 1)
							 : (((((v2))->tt_) == (((3) | ((0) << 4))))
									? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
									: 0)))
					{
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).n = (((void) L, (n2 == 2) ? (n1) * (n1) : pow(n1, n2)));
							((io)->tt_ = (((3) | ((1) << 4))));
						};
					}
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_DIVK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					lua_Number n1;
					lua_Number n2;
					if ((((((v1))->tt_) == (((3) | ((1) << 4))))
							 ? ((n1) = (((v1)->value_).n), 1)
							 : (((((v1))->tt_) == (((3) | ((0) << 4))))
									? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
									: 0)) &&
						(((((v2))->tt_) == (((3) | ((1) << 4))))
							 ? ((n2) = (((v2)->value_).n), 1)
							 : (((((v2))->tt_) == (((3) | ((0) << 4))))
									? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
									: 0)))
					{
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).n = (((n1) / (n2)));
							((io)->tt_ = (((3) | ((1) << 4))));
						};
					}
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_IDIVK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i = (luaV_idiv(L, i1, i2));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((void) L, (floor(((n1) / (n2))))));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BANDK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				lua_Integer i1;
				lua_Integer i2 = (((v2)->value_).i);
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (i1)) & ((lua_Unsigned) (i2)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BORK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				lua_Integer i1;
				lua_Integer i2 = (((v2)->value_).i);
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (i1)) | ((lua_Unsigned) (i2)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BXORK:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (k + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
											 ((~((~(Instruction) 0) << (8))) << (0))))))));
				lua_Integer i1;
				lua_Integer i2 = (((v2)->value_).i);
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (i1)) ^ ((lua_Unsigned) (i2)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SHRI:
		{
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			int ic = ((((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
								  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
					  (((1 << 8) - 1) >> 1));
			lua_Integer ib;
			if ((((((rb))->tt_) == (((3) | ((0) << 4)))) ? (*(&ib) = (((rb)->value_).i), 1)
														 : luaV_tointegerns(rb, &ib, F2Ieq)))
			{
				pc++;
				{
					TValue *io = ((&(ra)->val));
					((io)->value_).i = (luaV_shiftl(ib, -ic));
					((io)->tt_ = (((3) | ((0) << 4))));
				};
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SHLI:
		{
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			int ic = ((((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
								  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
					  (((1 << 8) - 1) >> 1));
			lua_Integer ib;
			if ((((((rb))->tt_) == (((3) | ((0) << 4)))) ? (*(&ib) = (((rb)->value_).i), 1)
														 : luaV_tointegerns(rb, &ib, F2Ieq)))
			{
				pc++;
				{
					TValue *io = ((&(ra)->val));
					((io)->value_).i = (luaV_shiftl(ic, ib));
					((io)->tt_ = (((3) | ((0) << 4))));
				};
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_ADD:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i =
								(((lua_Integer) (((lua_Unsigned) (i1)) + ((lua_Unsigned) (i2)))));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((n1) + (n2)));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SUB:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i =
								(((lua_Integer) (((lua_Unsigned) (i1)) - ((lua_Unsigned) (i2)))));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((n1) - (n2)));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MUL:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i =
								(((lua_Integer) (((lua_Unsigned) (i1)) * ((lua_Unsigned) (i2)))));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((n1) * (n2)));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MOD:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i = (luaV_mod(L, i1, i2));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (luaV_modf(L, n1, n2));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_POW:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					lua_Number n1;
					lua_Number n2;
					if ((((((v1))->tt_) == (((3) | ((1) << 4))))
							 ? ((n1) = (((v1)->value_).n), 1)
							 : (((((v1))->tt_) == (((3) | ((0) << 4))))
									? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
									: 0)) &&
						(((((v2))->tt_) == (((3) | ((1) << 4))))
							 ? ((n2) = (((v2)->value_).n), 1)
							 : (((((v2))->tt_) == (((3) | ((0) << 4))))
									? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
									: 0)))
					{
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).n = (((void) L, (n2 == 2) ? (n1) * (n1) : pow(n1, n2)));
							((io)->tt_ = (((3) | ((1) << 4))));
						};
					}
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_DIV:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					lua_Number n1;
					lua_Number n2;
					if ((((((v1))->tt_) == (((3) | ((1) << 4))))
							 ? ((n1) = (((v1)->value_).n), 1)
							 : (((((v1))->tt_) == (((3) | ((0) << 4))))
									? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
									: 0)) &&
						(((((v2))->tt_) == (((3) | ((1) << 4))))
							 ? ((n2) = (((v2)->value_).n), 1)
							 : (((((v2))->tt_) == (((3) | ((0) << 4))))
									? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
									: 0)))
					{
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).n = (((n1) / (n2)));
							((io)->tt_ = (((3) | ((1) << 4))));
						};
					}
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_IDIV:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				{
					if (((((v1))->tt_) == (((3) | ((0) << 4)))) &&
						((((v2))->tt_) == (((3) | ((0) << 4)))))
					{
						lua_Integer i1 = (((v1)->value_).i);
						lua_Integer i2 = (((v2)->value_).i);
						pc++;
						{
							TValue *io = ((&(ra)->val));
							((io)->value_).i = (luaV_idiv(L, i1, i2));
							((io)->tt_ = (((3) | ((0) << 4))));
						};
					}
					else
					{
						lua_Number n1;
						lua_Number n2;
						if ((((((v1))->tt_) == (((3) | ((1) << 4))))
								 ? ((n1) = (((v1)->value_).n), 1)
								 : (((((v1))->tt_) == (((3) | ((0) << 4))))
										? ((n1) = ((lua_Number) (((((v1)->value_).i)))), 1)
										: 0)) &&
							(((((v2))->tt_) == (((3) | ((1) << 4))))
								 ? ((n2) = (((v2)->value_).n), 1)
								 : (((((v2))->tt_) == (((3) | ((0) << 4))))
										? ((n2) = ((lua_Number) (((((v2)->value_).i)))), 1)
										: 0)))
						{
							pc++;
							{
								TValue *io = ((&(ra)->val));
								((io)->value_).n = (((void) L, (floor(((n1) / (n2))))));
								((io)->tt_ = (((3) | ((1) << 4))));
							};
						}
					};
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BAND:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				lua_Integer i1;
				lua_Integer i2;
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)) &&
					(((((v2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((v2)->value_).i), 1)
															 : luaV_tointegerns(v2, &i2, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (i1)) & ((lua_Unsigned) (i2)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BOR:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				lua_Integer i1;
				lua_Integer i2;
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)) &&
					(((((v2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((v2)->value_).i), 1)
															 : luaV_tointegerns(v2, &i2, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (i1)) | ((lua_Unsigned) (i2)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BXOR:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				lua_Integer i1;
				lua_Integer i2;
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)) &&
					(((((v2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((v2)->value_).i), 1)
															 : luaV_tointegerns(v2, &i2, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i =
							(((lua_Integer) (((lua_Unsigned) (i1)) ^ ((lua_Unsigned) (i2)))));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SHR:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				lua_Integer i1;
				lua_Integer i2;
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)) &&
					(((((v2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((v2)->value_).i), 1)
															 : luaV_tointegerns(v2, &i2, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i = (luaV_shiftl(i1, -(i2)));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SHL:
		{
			{
				TValue *v1 = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				TValue *v2 = (&((base + ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				lua_Integer i1;
				lua_Integer i2;
				if ((((((v1))->tt_) == (((3) | ((0) << 4)))) ? (*(&i1) = (((v1)->value_).i), 1)
															 : luaV_tointegerns(v1, &i1, F2Ieq)) &&
					(((((v2))->tt_) == (((3) | ((0) << 4)))) ? (*(&i2) = (((v2)->value_).i), 1)
															 : luaV_tointegerns(v2, &i2, F2Ieq)))
				{
					pc++;
					{
						TValue *io = ((&(ra)->val));
						((io)->value_).i = (luaV_shiftl(i1, i2));
						((io)->tt_ = (((3) | ((0) << 4))));
					};
				}
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MMBIN:
		{
			Instruction pi = *(pc - 2);
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			TMS tm = (TMS) ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))));
			StkId result =
				(base +
				 (((int) ((((pi) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			((void) 0);
			(((ci->u.l.savedpc = pc), L->top = ci->top),
			 (luaT_trybinTM(L, (&(ra)->val), rb, result, tm)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MMBINI:
		{
			Instruction pi = *(pc - 2);
			int imm = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
								   ((~((~(Instruction) 0) << (8))) << (0)))))))) -
					   (((1 << 8) - 1) >> 1));
			TMS tm = (TMS) ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))));
			int flip =
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0)))))));
			StkId result =
				(base +
				 (((int) ((((pi) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			(((ci->u.l.savedpc = pc), L->top = ci->top),
			 (luaT_trybiniTM(L, (&(ra)->val), imm, flip, result, tm)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_MMBINK:
		{
			Instruction pi = *(pc - 2);
			TValue *imm = (k + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
										  ((~((~(Instruction) 0) << (8))) << (0))))))));
			TMS tm = (TMS) ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))));
			int flip =
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0)))))));
			StkId result =
				(base +
				 (((int) ((((pi) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			(((ci->u.l.savedpc = pc), L->top = ci->top),
			 (luaT_trybinassocTM(L, (&(ra)->val), imm, flip, result, tm)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_UNM:
		{
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			lua_Number nb;
			if (((((rb))->tt_) == (((3) | ((0) << 4)))))
			{
				lua_Integer ib = (((rb)->value_).i);
				{
					TValue *io = ((&(ra)->val));
					((io)->value_).i =
						(((lua_Integer) (((lua_Unsigned) (0)) - ((lua_Unsigned) (ib)))));
					((io)->tt_ = (((3) | ((0) << 4))));
				};
			}
			else if ((((((rb))->tt_) == (((3) | ((1) << 4))))
						  ? ((nb) = (((rb)->value_).n), 1)
						  : (((((rb))->tt_) == (((3) | ((0) << 4))))
								 ? ((nb) = ((lua_Number) (((((rb)->value_).i)))), 1)
								 : 0)))
			{
				{
					TValue *io = ((&(ra)->val));
					((io)->value_).n = ((-(nb)));
					((io)->tt_ = (((3) | ((1) << 4))));
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top), (luaT_trybinTM(L, rb, rb, ra, TM_UNM)),
				 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_BNOT:
		{
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			lua_Integer ib;
			if ((((((rb))->tt_) == (((3) | ((0) << 4)))) ? (*(&ib) = (((rb)->value_).i), 1)
														 : luaV_tointegerns(rb, &ib, F2Ieq)))
			{
				{
					TValue *io = ((&(ra)->val));
					((io)->value_).i = (((lua_Integer) (((lua_Unsigned) (~((lua_Unsigned) (0)))) ^
														((lua_Unsigned) (ib)))));
					((io)->tt_ = (((3) | ((0) << 4))));
				};
			}
			else
				(((ci->u.l.savedpc = pc), L->top = ci->top),
				 (luaT_trybinTM(L, rb, rb, ra, TM_BNOT)), (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_NOT:
		{
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			if ((((((rb))->tt_) == (((1) | ((0) << 4)))) || (((((((rb))->tt_)) & 0x0F)) == (0))))
				(((&(ra)->val))->tt_ = (((1) | ((1) << 4))));
			else
				(((&(ra)->val))->tt_ = (((1) | ((0) << 4))));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LEN:
		{
			(((ci->u.l.savedpc = pc), L->top = ci->top),
			 (luaV_objlen(L, ra,
						  (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												((~((~(Instruction) 0) << (8))) << (0)))))))))
								->val))),
			 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_CONCAT:
		{
			int n = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			L->top = ra + n;
			((ci->u.l.savedpc = pc), (luaV_concat(L, n)), (trap = ci->u.l.trap));
			{
				{
					if ((L->l_G)->GCdebt > 0)
					{
						((ci->u.l.savedpc = pc), L->top = (L->top));
						luaC_step(L);
						(trap = ci->u.l.trap);
					};
					((void) 0);
				};
				{
					((void) 0);
					((void) 0);
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_CLOSE:
		{
			(((ci->u.l.savedpc = pc), L->top = ci->top), (luaF_close(L, ra, 0)),
			 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_TBC:
		{

			(((ci->u.l.savedpc = pc), L->top = ci->top), (luaF_newtbcupval(L, ra)));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_JMP:
		{
			{
				pc += ((((int) ((((i) >> ((0 + 7))) &
								 ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
					   (INT_MAX >> 1)) +
					  0;
				(trap = ci->u.l.trap);
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_EQ:
		{
			int cond;
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			(((ci->u.l.savedpc = pc), L->top = ci->top),
			 (cond = luaV_equalobj(L, (&(ra)->val), rb)), (trap = ci->u.l.trap));
			if (cond !=
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0))))))))
				pc++;
			else
			{
				Instruction ni = *pc;
				{
					pc += ((((int) ((((ni) >> ((0 + 7))) &
									 ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
						   (INT_MAX >> 1)) +
						  1;
					(trap = ci->u.l.trap);
				};
			};
			;
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LT:
		{
			{
				int cond;
				TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))) &&
					((((rb))->tt_) == (((3) | ((0) << 4)))))
				{
					lua_Integer ia = ((((&(ra)->val))->value_).i);
					lua_Integer ib = (((rb)->value_).i);
					cond = (ia < ib);
				}
				else if (((((((((&(ra)->val)))->tt_)) & 0x0F)) == (3)) &&
						 (((((((rb))->tt_)) & 0x0F)) == (3)))
					cond = LTnum((&(ra)->val), rb);
				else
					(((ci->u.l.savedpc = pc), L->top = ci->top),
					 (cond = lessthanothers(L, (&(ra)->val), rb)), (trap = ci->u.l.trap));
				if (cond != ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << (1))) << (0))))))))
					pc++;
				else
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
				;
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LE:
		{
			{
				int cond;
				TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
												   ((~((~(Instruction) 0) << (8))) << (0)))))))))
								   ->val);
				if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))) &&
					((((rb))->tt_) == (((3) | ((0) << 4)))))
				{
					lua_Integer ia = ((((&(ra)->val))->value_).i);
					lua_Integer ib = (((rb)->value_).i);
					cond = (ia <= ib);
				}
				else if (((((((((&(ra)->val)))->tt_)) & 0x0F)) == (3)) &&
						 (((((((rb))->tt_)) & 0x0F)) == (3)))
					cond = LEnum((&(ra)->val), rb);
				else
					(((ci->u.l.savedpc = pc), L->top = ci->top),
					 (cond = lessequalothers(L, (&(ra)->val), rb)), (trap = ci->u.l.trap));
				if (cond != ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << (1))) << (0))))))))
					pc++;
				else
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
				;
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_EQK:
		{
			TValue *rb = (k + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
										 ((~((~(Instruction) 0) << (8))) << (0))))))));

			int cond = luaV_equalobj(NULL, (&(ra)->val), rb);
			if (cond !=
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0))))))))
				pc++;
			else
			{
				Instruction ni = *pc;
				{
					pc += ((((int) ((((ni) >> ((0 + 7))) &
									 ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
						   (INT_MAX >> 1)) +
						  1;
					(trap = ci->u.l.trap);
				};
			};
			;
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_EQI:
		{
			int cond;
			int im = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
								  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
					  (((1 << 8) - 1) >> 1));
			if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))))
				cond = (((((&(ra)->val))->value_).i) == im);
			else if ((((((&(ra)->val)))->tt_) == (((3) | ((1) << 4)))))
				cond = ((((((&(ra)->val))->value_).n)) == (((lua_Number) ((im)))));
			else
				cond = 0;
			if (cond !=
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0))))))))
				pc++;
			else
			{
				Instruction ni = *pc;
				{
					pc += ((((int) ((((ni) >> ((0 + 7))) &
									 ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
						   (INT_MAX >> 1)) +
						  1;
					(trap = ci->u.l.trap);
				};
			};
			;
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LTI:
		{
			{
				int cond;
				int im = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
						  (((1 << 8) - 1) >> 1));
				if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))))
					cond = (((((&(ra)->val))->value_).i) < im);
				else if ((((((&(ra)->val)))->tt_) == (((3) | ((1) << 4)))))
				{
					lua_Number fa = ((((&(ra)->val))->value_).n);
					lua_Number fim = ((lua_Number) ((im)));
					cond = ((fa) < (fim));
				}
				else
				{
					int isf = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										 ((~((~(Instruction) 0) << (8))) << (0)))))));
					(((ci->u.l.savedpc = pc), L->top = ci->top),
					 (cond = luaT_callorderiTM(L, (&(ra)->val), im, 0, isf, TM_LT)),
					 (trap = ci->u.l.trap));
				}
				if (cond != ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << (1))) << (0))))))))
					pc++;
				else
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
				;
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_LEI:
		{
			{
				int cond;
				int im = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
						  (((1 << 8) - 1) >> 1));
				if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))))
					cond = (((((&(ra)->val))->value_).i) <= im);
				else if ((((((&(ra)->val)))->tt_) == (((3) | ((1) << 4)))))
				{
					lua_Number fa = ((((&(ra)->val))->value_).n);
					lua_Number fim = ((lua_Number) ((im)));
					cond = ((fa) <= (fim));
				}
				else
				{
					int isf = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										 ((~((~(Instruction) 0) << (8))) << (0)))))));
					(((ci->u.l.savedpc = pc), L->top = ci->top),
					 (cond = luaT_callorderiTM(L, (&(ra)->val), im, 0, isf, TM_LE)),
					 (trap = ci->u.l.trap));
				}
				if (cond != ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << (1))) << (0))))))))
					pc++;
				else
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
				;
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GTI:
		{
			{
				int cond;
				int im = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
						  (((1 << 8) - 1) >> 1));
				if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))))
					cond = (((((&(ra)->val))->value_).i) > im);
				else if ((((((&(ra)->val)))->tt_) == (((3) | ((1) << 4)))))
				{
					lua_Number fa = ((((&(ra)->val))->value_).n);
					lua_Number fim = ((lua_Number) ((im)));
					cond = ((fa) > (fim));
				}
				else
				{
					int isf = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										 ((~((~(Instruction) 0) << (8))) << (0)))))));
					(((ci->u.l.savedpc = pc), L->top = ci->top),
					 (cond = luaT_callorderiTM(L, (&(ra)->val), im, 1, isf, TM_LT)),
					 (trap = ci->u.l.trap));
				}
				if (cond != ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << (1))) << (0))))))))
					pc++;
				else
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
				;
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_GEI:
		{
			{
				int cond;
				int im = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
						  (((1 << 8) - 1) >> 1));
				if ((((((&(ra)->val)))->tt_) == (((3) | ((0) << 4)))))
					cond = (((((&(ra)->val))->value_).i) >= im);
				else if ((((((&(ra)->val)))->tt_) == (((3) | ((1) << 4)))))
				{
					lua_Number fa = ((((&(ra)->val))->value_).n);
					lua_Number fim = ((lua_Number) ((im)));
					cond = ((fa) >= (fim));
				}
				else
				{
					int isf = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										 ((~((~(Instruction) 0) << (8))) << (0)))))));
					(((ci->u.l.savedpc = pc), L->top = ci->top),
					 (cond = luaT_callorderiTM(L, (&(ra)->val), im, 1, isf, TM_LE)),
					 (trap = ci->u.l.trap));
				}
				if (cond != ((((int) ((((i) >> (((0 + 7) + 8))) &
									   ((~((~(Instruction) 0) << (1))) << (0))))))))
					pc++;
				else
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
				;
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_TEST:
		{
			int cond = !((((((&(ra)->val)))->tt_) == (((1) | ((0) << 4)))) ||
						 ((((((((&(ra)->val)))->tt_)) & 0x0F)) == (0)));
			if (cond !=
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0))))))))
				pc++;
			else
			{
				Instruction ni = *pc;
				{
					pc += ((((int) ((((ni) >> ((0 + 7))) &
									 ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
						   (INT_MAX >> 1)) +
						  1;
					(trap = ci->u.l.trap);
				};
			};
			;
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_TESTSET:
		{
			TValue *rb = (&((base + ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))))))
							   ->val);
			if ((((((rb))->tt_) == (((1) | ((0) << 4)))) || (((((((rb))->tt_)) & 0x0F)) == (0))) ==
				((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0))))))))
				pc++;
			else
			{
				{
					TValue *io1 = ((&(ra)->val));
					const TValue *io2 = (rb);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
				{
					Instruction ni = *pc;
					{
						pc +=
							((((int) ((((ni) >> ((0 + 7))) &
									   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
							 (INT_MAX >> 1)) +
							1;
						(trap = ci->u.l.trap);
					};
				};
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_CALL:
		{
			CallInfo *newci;
			int b = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			int nresults = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									  ((~((~(Instruction) 0) << (8))) << (0))))))) -
						   1;
			if (b != 0)
				L->top = ra + b;

			(ci->u.l.savedpc = pc);
			if ((newci = luaD_precall(L, ra, nresults)) == NULL)
				(trap = ci->u.l.trap);
			else
			{
				ci = newci;
				ci->callstatus = 0;
				goto startfunc;
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_TAILCALL:
		{
			int b = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			int nparams1 = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))));

			int delta = (nparams1) ? ci->u.l.nextraargs + nparams1 : 0;
			if (b != 0)
				L->top = ra + b;
			else
				b = ((int) ((L->top - ra)));
			(ci->u.l.savedpc = pc);
			if (((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
			{

				luaF_close(L, base, (-1));
				((void) 0);
			}
			while (!(((((((&(ra)->val))->tt_)) & 0x0F)) == (6)))
			{
				luaD_tryfuncTM(L, ra);
				b++;
				if (L->stack_last - L->top <= (1))
				{
					ptrdiff_t t__ = ((char *) (ra) - (char *) L->stack);
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
					ra = ((StkId) ((char *) L->stack + (t__)));
				}
				else
				{
					((void) 0);
				};
			}
			if (!(((((&(ra)->val)))->tt_) == (((((6) | ((0) << 4))) | (1 << 6)))))
			{
				luaD_precall(L, ra, (-1));
				(trap = ci->u.l.trap);
				{
					if (trap)
					{
						(base = ci->func + 1);
						ra = (base + (((int) ((((i) >> ((0 + 7))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))));
					}
				};
				ci->func -= delta;
				luaD_poscall(L, ci, ((int) ((L->top - ra))));
				(trap = ci->u.l.trap);
				goto ret;
			}
			ci->func -= delta;
			luaD_pretailcall(L, ci, ra, b);
			goto startfunc;
		}
		L_OP_RETURN:
		{
			int n = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0))))))) -
					1;
			int nparams1 = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
									  ((~((~(Instruction) 0) << (8))) << (0)))))));
			if (n < 0)
				n = ((int) ((L->top - ra)));
			(ci->u.l.savedpc = pc);
			if (((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
			{
				if (L->top < ci->top)
					L->top = ci->top;
				luaF_close(L, base, 0);
				(trap = ci->u.l.trap);
				{
					if (trap)
					{
						(base = ci->func + 1);
						ra = (base + (((int) ((((i) >> ((0 + 7))) &
											   ((~((~(Instruction) 0) << (8))) << (0)))))));
					}
				};
			}
			if (nparams1)
				ci->func -= ci->u.l.nextraargs + nparams1;
			L->top = ra + n;
			luaD_poscall(L, ci, n);
			(trap = ci->u.l.trap);
			goto ret;
		}
		L_OP_RETURN0:
		{
			if (L->hookmask)
			{
				L->top = ra;
				(ci->u.l.savedpc = pc);
				luaD_poscall(L, ci, 0);
				trap = 1;
			}
			else
			{
				int nres = ci->nresults;
				L->ci = ci->previous;
				L->top = base - 1;
				while (nres-- > 0)
					(((&(L->top++)->val))->tt_ = (((0) | ((0) << 4))));
			}
			goto ret;
		}
		L_OP_RETURN1:
		{
			if (L->hookmask)
			{
				L->top = ra + 1;
				(ci->u.l.savedpc = pc);
				luaD_poscall(L, ci, 1);
				trap = 1;
			}
			else
			{
				int nres = ci->nresults;
				L->ci = ci->previous;
				if (nres == 0)
					L->top = base - 1;
				else
				{
					{
						TValue *io1 = ((&(base - 1)->val));
						const TValue *io2 = ((&(ra)->val));
						io1->value_ = io2->value_;
						((io1)->tt_ = (io2->tt_));
						((void) L, ((void) 0));
						((void) 0);
					};
					L->top = base;
					while (--nres > 0)
						(((&(L->top++)->val))->tt_ = (((0) | ((0) << 4))));
				}
			}
		ret:
			if (ci->callstatus & (1 << 2))
				return;
			else
			{
				ci = ci->previous;
				goto returning;
			}
		}
		L_OP_FORLOOP:
		{
			if ((((((&(ra + 2)->val)))->tt_) == (((3) | ((0) << 4)))))
			{
				lua_Unsigned count = ((lua_Unsigned) (((((&(ra + 1)->val))->value_).i)));
				if (count > 0)
				{
					lua_Integer step = ((((&(ra + 2)->val))->value_).i);
					lua_Integer idx = ((((&(ra)->val))->value_).i);
					{
						TValue *io = ((&(ra + 1)->val));
						((void) 0);
						((io)->value_).i = (count - 1);
					};
					idx = ((lua_Integer) (((lua_Unsigned) (idx)) + ((lua_Unsigned) (step))));
					{
						TValue *io = ((&(ra)->val));
						((void) 0);
						((io)->value_).i = (idx);
					};
					{
						TValue *io = ((&(ra + 3)->val));
						((io)->value_).i = (idx);
						((io)->tt_ = (((3) | ((0) << 4))));
					};
					pc -= ((((int) ((((i) >> (((0 + 7) + 8))) &
									 ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))));
				}
			}
			else if (floatforloop(ra))
				pc -= ((((int) ((((i) >> (((0 + 7) + 8))) &
								 ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))));
			(trap = ci->u.l.trap);
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_FORPREP:
		{
			((ci->u.l.savedpc = pc), L->top = ci->top);
			if (forprep(L, ra))
				pc += ((((int) ((((i) >> (((0 + 7) + 8))) &
								 ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0))))))) +
					  1;
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_TFORPREP:
		{

			(((ci->u.l.savedpc = pc), L->top = ci->top), (luaF_newtbcupval(L, ra + 3)));
			pc += ((((int) ((((i) >> (((0 + 7) + 8))) &
							 ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))));
			i = *(pc++);
			((void) 0);
			goto l_tforcall;
		}
		L_OP_TFORCALL:
		{
		l_tforcall:

			memcpy(ra + 4, ra, 3 * sizeof(*ra));
			L->top = ra + 4 + 3;
			((ci->u.l.savedpc = pc),
			 (luaD_call(L, ra + 4,
						((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
								   ((~((~(Instruction) 0) << (8))) << (0))))))))),
			 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					(base = ci->func + 1);
					ra = (base + (((int) ((((i) >> ((0 + 7))) &
										   ((~((~(Instruction) 0) << (8))) << (0)))))));
				}
			};
			i = *(pc++);
			((void) 0);
			goto l_tforloop;
		}
		L_OP_TFORLOOP:
		{
		l_tforloop:
			if (!((((((((&(ra + 4)->val)))->tt_)) & 0x0F)) == (0)))
			{
				{
					TValue *io1 = ((&(ra + 2)->val));
					const TValue *io2 = ((&(ra + 4)->val));
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
				pc -= ((((int) ((((i) >> (((0 + 7) + 8))) &
								 ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))));
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_SETLIST:
		{
			int n = ((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							   ((~((~(Instruction) 0) << (8))) << (0)))))));
			unsigned int last = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
										   ((~((~(Instruction) 0) << (8))) << (0)))))));
			Table *h = ((&((((union GCUnion *) (((((&(ra)->val))->value_).gc))))->h)));
			if (n == 0)
				n = ((int) ((L->top - ra))) - 1;
			else
				L->top = ci->top;
			last += n;
			if (((((int) ((((i) & (1u << ((0 + 7) + 8)))))))))
			{
				last += ((((int) ((((*pc) >> ((0 + 7))) &
								   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0))))))) *
						(((1 << 8) - 1) + 1);
				pc++;
			}
			if (last > luaH_realasize(h))
				luaH_resizearray(L, h, last);
			for (; n > 0; n--)
			{
				TValue *val = (&(ra + n)->val);
				{
					TValue *io1 = (&h->array[last - 1]);
					const TValue *io2 = (val);
					io1->value_ = io2->value_;
					((io1)->tt_ = (io2->tt_));
					((void) L, ((void) 0));
					((void) 0);
				};
				last--;
				(((((val)->tt_) & (1 << 6)) &&
				  ((((&(((union GCUnion *) ((h)))->gc)))->marked) & ((1 << (5)))) &&
				  ((((((val)->value_).gc))->marked) & (((1 << (3)) | (1 << (4))))))
					 ? luaC_barrierback_(L, (&(((union GCUnion *) ((h)))->gc)))
					 : ((void) ((0))));
			}
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_CLOSURE:
		{
			Proto *p = cl->p->p[((((int) ((((i) >> (((0 + 7) + 8))) &
										   ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))))];
			(((ci->u.l.savedpc = pc), L->top = ci->top), (pushclosure(L, p, cl->upvals, base, ra)));
			{
				{
					if ((L->l_G)->GCdebt > 0)
					{
						((ci->u.l.savedpc = pc), L->top = (ra + 1));
						luaC_step(L);
						(trap = ci->u.l.trap);
					};
					((void) 0);
				};
				{
					((void) 0);
					((void) 0);
				};
			};
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_VARARG:
		{
			int n = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
							   ((~((~(Instruction) 0) << (8))) << (0))))))) -
					1;
			(((ci->u.l.savedpc = pc), L->top = ci->top), (luaT_getvarargs(L, ci, ra, n)),
			 (trap = ci->u.l.trap));
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_VARARGPREP:
		{
			((ci->u.l.savedpc = pc),
			 (luaT_adjustvarargs(
				 L, (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))), ci,
				 cl->p)),
			 (trap = ci->u.l.trap));
			if (trap)
			{
				luaD_hookcall(L, ci);
				L->oldpc = 1;
			}
			(base = ci->func + 1);
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		L_OP_EXTRAARG:
		{
			((void) 0);
			{
				if (trap)
				{
					trap = luaG_traceexec(L, pc);
					(base = ci->func + 1);
				}
				i = *(pc++);
				ra = (base +
					  (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
			};
			goto *disptab[(((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))))];
			;
			;
		}
		}
	}
}
