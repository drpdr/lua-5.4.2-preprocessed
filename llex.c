

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
const lu_byte luai_ctype_[UCHAR_MAX + 2] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04,
	0x05, 0x04, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00};

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
static const char *const luaX_tokens[] = {"and",	"break",   "do",	 "else",	 "elseif",
										  "end",	"false",   "for",	 "function", "goto",
										  "if",		"in",	   "local",	 "nil",		 "not",
										  "or",		"repeat",  "return", "then",	 "true",
										  "until",	"while",   "//",	 "..",		 "...",
										  "==",		">=",	   "<=",	 "~=",		 "<<",
										  ">>",		"::",	   "<eof>",	 "<number>", "<integer>",
										  "<name>", "<string>"};

static void __attribute__((noreturn)) lexerror(LexState *ls, const char *msg, int token);

static void save(LexState *ls, int c)
{
	Mbuffer *b = ls->buff;
	if (((b)->n) + 1 > ((b)->buffsize))
	{
		size_t newsize;
		if (((b)->buffsize) >= (sizeof(size_t) < sizeof(lua_Integer) ? ((size_t) (~(size_t) 0))
																	 : (size_t) (LUA_MAXINTEGER)) /
								   2)
			lexerror(ls, "lexical element too long", 0);
		newsize = ((b)->buffsize) * 2;
		((b)->buffer = ((char *) ((luaM_saferealloc_(
			 ls->L, ((b)->buffer), ((b)->buffsize) * sizeof(char), (newsize) * sizeof(char))))),
		 (b)->buffsize = newsize);
	}
	b->buffer[((b)->n)++] = ((char) ((c)));
}

void luaX_init(lua_State *L)
{
	int i;
	TString *e = (luaS_newlstr(L,
							   ""
							   "_ENV",
							   (sizeof("_ENV") / sizeof(char)) - 1));
	luaC_fix(L, (&(((union GCUnion *) ((e)))->gc)));
	for (i = 0; i < (((int) ((TK_WHILE - (UCHAR_MAX + 1) + 1)))); i++)
	{
		TString *ts = luaS_new(L, luaX_tokens[i]);
		luaC_fix(L, (&(((union GCUnion *) ((ts)))->gc)));
		ts->extra = ((lu_byte) ((i + 1)));
	}
}

const char *luaX_token2str(LexState *ls, int token)
{
	if (token < (UCHAR_MAX + 1))
	{
		if ((luai_ctype_[(token) + 1] & ((1 << (2)))))
			return luaO_pushfstring(ls->L, "'%c'", token);
		else
			return luaO_pushfstring(ls->L, "'<\\%d>'", token);
	}
	else
	{
		const char *s = luaX_tokens[token - (UCHAR_MAX + 1)];
		if (token < TK_EOS)
			return luaO_pushfstring(ls->L, "'%s'", s);
		else
			return s;
	}
}

static const char *txtToken(LexState *ls, int token)
{
	switch (token)
	{
	case TK_NAME:
	case TK_STRING:
	case TK_FLT:
	case TK_INT:
		save(ls, '\0');
		return luaO_pushfstring(ls->L, "'%s'", ((ls->buff)->buffer));
	default:
		return luaX_token2str(ls, token);
	}
}

static void __attribute__((noreturn)) lexerror(LexState *ls, const char *msg, int token)
{
	msg = luaG_addinfo(ls->L, msg, ls->source, ls->linenumber);
	if (token)
		luaO_pushfstring(ls->L, "%s near %s", msg, txtToken(ls, token));
	luaD_throw(ls->L, 3);
}

void __attribute__((noreturn)) luaX_syntaxerror(LexState *ls, const char *msg)
{
	lexerror(ls, msg, ls->t.token);
}

TString *luaX_newstring(LexState *ls, const char *str, size_t l)
{
	lua_State *L = ls->L;
	TValue *o;
	TString *ts = luaS_newlstr(L, str, l);
	{
		TValue *io = ((&(L->top++)->val));
		TString *x_ = (ts);
		((io)->value_).gc = (&(((union GCUnion *) ((x_)))->gc));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void) L, ((void) 0));
	};
	o = luaH_set(L, ls->h, (&(L->top - 1)->val));
	if ((((((((o))->tt_)) & 0x0F)) == (0)))
	{

		((o)->tt_ = (((1) | ((1) << 4))));
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
	else
	{
		ts = ((&((((union GCUnion *) ((((((Node *) ((o))))->u.key_val).gc))))->ts)));
	}
	L->top--;
	return ts;
}

static void inclinenumber(LexState *ls)
{
	int old = ls->current;
	((void) 0);
	(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
	if ((ls->current == '\n' || ls->current == '\r') && ls->current != old)
		(ls->current =
			 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
	if (++ls->linenumber >= INT_MAX)
		lexerror(ls, "chunk has too many lines", 0);
}

void luaX_setinput(lua_State *L, LexState *ls, ZIO *z, TString *source, int firstchar)
{
	ls->t.token = 0;
	ls->L = L;
	ls->current = firstchar;
	ls->lookahead.token = TK_EOS;
	ls->z = z;
	ls->fs = NULL;
	ls->linenumber = 1;
	ls->lastline = 1;
	ls->source = source;
	ls->envn = (luaS_newlstr(L,
							 ""
							 "_ENV",
							 (sizeof("_ENV") / sizeof(char)) - 1));
	((ls->buff)->buffer = ((
		 char *) ((luaM_saferealloc_(ls->L, ((ls->buff)->buffer),
									 ((ls->buff)->buffsize) * sizeof(char), (32) * sizeof(char))))),
	 (ls->buff)->buffsize = 32);
}
static int check_next1(LexState *ls, int c)
{
	if (ls->current == c)
	{
		(ls->current =
			 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
		return 1;
	}
	else
		return 0;
}

static int check_next2(LexState *ls, const char *set)
{
	((void) 0);
	if (ls->current == set[0] || ls->current == set[1])
	{
		(save(ls, ls->current),
		 (ls->current =
			  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		return 1;
	}
	else
		return 0;
}
static int read_numeral(LexState *ls, SemInfo *seminfo)
{
	TValue obj;
	const char *expo = "Ee";
	int first = ls->current;
	((void) 0);
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	if (first == '0' && check_next2(ls, "xX"))
		expo = "Pp";
	for (;;)
	{
		if (check_next2(ls, expo))
			check_next2(ls, "-+");
		else if ((luai_ctype_[(ls->current) + 1] & ((1 << (4)))) || ls->current == '.')
			(save(ls, ls->current),
			 (ls->current =
				  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		else
			break;
	}
	if ((luai_ctype_[(ls->current) + 1] & ((1 << (0)))))
		(save(ls, ls->current),
		 (ls->current =
			  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	save(ls, '\0');
	if (luaO_str2num(((ls->buff)->buffer), &obj) == 0)
		lexerror(ls, "malformed number", TK_FLT);
	if (((((&obj))->tt_) == (((3) | ((0) << 4)))))
	{
		seminfo->i = (((&obj)->value_).i);
		return TK_INT;
	}
	else
	{
		((void) 0);
		seminfo->r = (((&obj)->value_).n);
		return TK_FLT;
	}
}
static size_t skip_sep(LexState *ls)
{
	size_t count = 0;
	int s = ls->current;
	((void) 0);
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	while (ls->current == '=')
	{
		(save(ls, ls->current),
		 (ls->current =
			  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		count++;
	}
	return (ls->current == s) ? count + 2 : (count == 0) ? 1 : 0;
}

static void read_long_string(LexState *ls, SemInfo *seminfo, size_t sep)
{
	int line = ls->linenumber;
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	if ((ls->current == '\n' || ls->current == '\r'))
		inclinenumber(ls);
	for (;;)
	{
		switch (ls->current)
		{
		case (-1):
		{
			const char *what = (seminfo ? "string" : "comment");
			const char *msg =
				luaO_pushfstring(ls->L, "unfinished long %s (starting at line %d)", what, line);
			lexerror(ls, msg, TK_EOS);
			break;
		}
		case ']':
		{
			if (skip_sep(ls) == sep)
			{
				(save(ls, ls->current),
				 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++)))
													: luaZ_fill(ls->z))));
				goto endloop;
			}
			break;
		}
		case '\n':
		case '\r':
		{
			save(ls, '\n');
			inclinenumber(ls);
			if (!seminfo)
				((ls->buff)->n = 0);
			break;
		}
		default:
		{
			if (seminfo)
				(save(ls, ls->current),
				 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++)))
													: luaZ_fill(ls->z))));
			else
				(ls->current =
					 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
		}
		}
	}
endloop:
	if (seminfo)
		seminfo->ts = luaX_newstring(ls, ((ls->buff)->buffer) + sep, ((ls->buff)->n) - 2 * sep);
}

static void esccheck(LexState *ls, int c, const char *msg)
{
	if (!c)
	{
		if (ls->current != (-1))
			(save(ls, ls->current),
			 (ls->current =
				  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		lexerror(ls, msg, TK_STRING);
	}
}

static int gethexa(LexState *ls)
{
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	esccheck(ls, (luai_ctype_[(ls->current) + 1] & ((1 << (4)))), "hexadecimal digit expected");
	return luaO_hexavalue(ls->current);
}

static int readhexaesc(LexState *ls)
{
	int r = gethexa(ls);
	r = (r << 4) + gethexa(ls);
	((ls->buff)->n -= (2));
	return r;
}

static unsigned long readutf8esc(LexState *ls)
{
	unsigned long r;
	int i = 4;
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	esccheck(ls, ls->current == '{', "missing '{'");
	r = gethexa(ls);
	while (((void) (((save(ls, ls->current),
					  (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++)))
														 : luaZ_fill(ls->z))))))),
		   (luai_ctype_[(ls->current) + 1] & ((1 << (4)))))
	{
		i++;
		esccheck(ls, r <= (0x7FFFFFFFu >> 4), "UTF-8 value too large");
		r = (r << 4) + luaO_hexavalue(ls->current);
	}
	esccheck(ls, ls->current == '}', "missing '}'");
	(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
	((ls->buff)->n -= (i));
	return r;
}

static void utf8esc(LexState *ls)
{
	char buff[8];
	int n = luaO_utf8esc(buff, readutf8esc(ls));
	for (; n > 0; n--)
		save(ls, buff[8 - n]);
}

static int readdecesc(LexState *ls)
{
	int i;
	int r = 0;
	for (i = 0; i < 3 && (luai_ctype_[(ls->current) + 1] & ((1 << (1)))); i++)
	{
		r = 10 * r + ls->current - '0';
		(save(ls, ls->current),
		 (ls->current =
			  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	}
	esccheck(ls, r <= UCHAR_MAX, "decimal escape too large");
	((ls->buff)->n -= (i));
	return r;
}

static void read_string(LexState *ls, int del, SemInfo *seminfo)
{
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	while (ls->current != del)
	{
		switch (ls->current)
		{
		case (-1):
			lexerror(ls, "unfinished string", TK_EOS);
			break;
		case '\n':
		case '\r':
			lexerror(ls, "unfinished string", TK_STRING);
			break;
		case '\\':
		{
			int c;
			(save(ls, ls->current),
			 (ls->current =
				  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
			switch (ls->current)
			{
			case 'a':
				c = '\a';
				goto read_save;
			case 'b':
				c = '\b';
				goto read_save;
			case 'f':
				c = '\f';
				goto read_save;
			case 'n':
				c = '\n';
				goto read_save;
			case 'r':
				c = '\r';
				goto read_save;
			case 't':
				c = '\t';
				goto read_save;
			case 'v':
				c = '\v';
				goto read_save;
			case 'x':
				c = readhexaesc(ls);
				goto read_save;
			case 'u':
				utf8esc(ls);
				goto no_save;
			case '\n':
			case '\r':
				inclinenumber(ls);
				c = '\n';
				goto only_save;
			case '\\':
			case '\"':
			case '\'':
				c = ls->current;
				goto read_save;
			case (-1):
				goto no_save;
			case 'z':
			{
				((ls->buff)->n -= (1));
				(ls->current =
					 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
				while ((luai_ctype_[(ls->current) + 1] & ((1 << (3)))))
				{
					if ((ls->current == '\n' || ls->current == '\r'))
						inclinenumber(ls);
					else
						(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++)))
														   : luaZ_fill(ls->z)));
				}
				goto no_save;
			}
			default:
			{
				esccheck(ls, (luai_ctype_[(ls->current) + 1] & ((1 << (1)))),
						 "invalid escape sequence");
				c = readdecesc(ls);
				goto only_save;
			}
			}
		read_save:
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));

		only_save:
			((ls->buff)->n -= (1));
			save(ls, c);

		no_save:
			break;
		}
		default:
			(save(ls, ls->current),
			 (ls->current =
				  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		}
	}
	(save(ls, ls->current),
	 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	seminfo->ts = luaX_newstring(ls, ((ls->buff)->buffer) + 1, ((ls->buff)->n) - 2);
}
static int llex(LexState *ls, SemInfo *seminfo)
{
	((ls->buff)->n = 0);
	for (;;)
	{
		switch (ls->current)
		{
		case '\n':
		case '\r':
		{
			inclinenumber(ls);
			break;
		}
		case ' ':
		case '\f':
		case '\t':
		case '\v':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			break;
		}
		case '-':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (ls->current != '-')
				return '-';

			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (ls->current == '[')
			{
				size_t sep = skip_sep(ls);
				((ls->buff)->n = 0);
				if (sep >= 2)
				{
					read_long_string(ls, ((void *) 0), sep);
					((ls->buff)->n = 0);
					break;
				}
			}

			while (!(ls->current == '\n' || ls->current == '\r') && ls->current != (-1))
				(ls->current =
					 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			break;
		}
		case '[':
		{
			size_t sep = skip_sep(ls);
			if (sep >= 2)
			{
				read_long_string(ls, seminfo, sep);
				return TK_STRING;
			}
			else if (sep == 0)
				lexerror(ls, "invalid long string delimiter", TK_STRING);
			return '[';
		}
		case '=':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_EQ;
			else
				return '=';
		}
		case '<':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_LE;
			else if (check_next1(ls, '<'))
				return TK_SHL;
			else
				return '<';
		}
		case '>':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_GE;
			else if (check_next1(ls, '>'))
				return TK_SHR;
			else
				return '>';
		}
		case '/':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '/'))
				return TK_IDIV;
			else
				return '/';
		}
		case '~':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_NE;
			else
				return '~';
		}
		case ':':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, ':'))
				return TK_DBCOLON;
			else
				return ':';
		}
		case '"':
		case '\'':
		{
			read_string(ls, ls->current, seminfo);
			return TK_STRING;
		}
		case '.':
		{
			(save(ls, ls->current),
			 (ls->current =
				  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
			if (check_next1(ls, '.'))
			{
				if (check_next1(ls, '.'))
					return TK_DOTS;
				else
					return TK_CONCAT;
			}
			else if (!(luai_ctype_[(ls->current) + 1] & ((1 << (1)))))
				return '.';
			else
				return read_numeral(ls, seminfo);
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			return read_numeral(ls, seminfo);
		}
		case (-1):
		{
			return TK_EOS;
		}
		default:
		{

			pp_cap(luai_ctype_);
			lu_byte luai_ctype_arg = (ls->current) + 1;
			printf("luai_ctype_arg: %u\n", luai_ctype_arg);

			lu_byte luai_ctype_access = luai_ctype_[luai_ctype_arg];
			if ((luai_ctype_access & ((1 << (0)))))
			{
				TString *ts;
				do
				{
					(save(ls, ls->current),
					 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++)))
														: luaZ_fill(ls->z))));
				} while ((luai_ctype_[(ls->current) + 1] & (((1 << (0)) | (1 << (1))))));
				ts = luaX_newstring(ls, ((ls->buff)->buffer), ((ls->buff)->n));
				seminfo->ts = ts;
				if (((ts)->tt == ((4) | ((0) << 4)) && (ts)->extra > 0))
					return ts->extra - 1 + ((127 * 2 + 1) + 1);
				else
				{
					return TK_NAME;
				}
			}
			else
			{
				int c = ls->current;
				(ls->current =
					 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
				return c;
			}
		}
		}
	}
}

void luaX_next(LexState *ls)
{
	ls->lastline = ls->linenumber;
	if (ls->lookahead.token != TK_EOS)
	{
		ls->t = ls->lookahead;
		ls->lookahead.token = TK_EOS;
	}
	else
		ls->t.token = llex(ls, &ls->t.seminfo);
}

int luaX_lookahead(LexState *ls)
{
	((void) 0);
	ls->lookahead.token = llex(ls, &ls->lookahead.seminfo);
	return ls->lookahead.token;
}
unsigned char custom_lislalpha(int c)
{

	return testprop2(c, mask2(0));
}

int custom_lislalnum(int c)
{

	return testprop2(c, (mask2(0) | mask2(1)));
}

int custom_lisdigit(int c)
{

	return testprop2(c, mask2(1));
}

int mask2(int B)
{
	return (1 << (B));
}

int testprop2(int c, int p)
{
	return luai_ctype_[(c) + 1] & (p);
}
