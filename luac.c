

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
typedef struct luaL_Buffer luaL_Buffer;
typedef struct luaL_Reg
{
	const char *name;
	lua_CFunction func;
} luaL_Reg;

extern void(luaL_checkversion_)(lua_State *L, lua_Number ver, size_t sz);

extern int(luaL_getmetafield)(lua_State *L, int obj, const char *e);
extern int(luaL_callmeta)(lua_State *L, int obj, const char *e);
extern const char *(luaL_tolstring) (lua_State *L, int idx, size_t *len);
extern int(luaL_argerror)(lua_State *L, int arg, const char *extramsg);
extern int(luaL_typeerror)(lua_State *L, int arg, const char *tname);
extern const char *(luaL_checklstring) (lua_State *L, int arg, size_t *l);
extern const char *(luaL_optlstring) (lua_State *L, int arg, const char *def, size_t *l);
extern lua_Number(luaL_checknumber)(lua_State *L, int arg);
extern lua_Number(luaL_optnumber)(lua_State *L, int arg, lua_Number def);

extern lua_Integer(luaL_checkinteger)(lua_State *L, int arg);
extern lua_Integer(luaL_optinteger)(lua_State *L, int arg, lua_Integer def);

extern void(luaL_checkstack)(lua_State *L, int sz, const char *msg);
extern void(luaL_checktype)(lua_State *L, int arg, int t);
extern void(luaL_checkany)(lua_State *L, int arg);

extern int(luaL_newmetatable)(lua_State *L, const char *tname);
extern void(luaL_setmetatable)(lua_State *L, const char *tname);
extern void *(luaL_testudata) (lua_State *L, int ud, const char *tname);
extern void *(luaL_checkudata) (lua_State *L, int ud, const char *tname);

extern void(luaL_where)(lua_State *L, int lvl);
extern int(luaL_error)(lua_State *L, const char *fmt, ...);

extern int(luaL_checkoption)(lua_State *L, int arg, const char *def, const char *const lst[]);

extern int(luaL_fileresult)(lua_State *L, int stat, const char *fname);
extern int(luaL_execresult)(lua_State *L, int stat);

extern int(luaL_ref)(lua_State *L, int t);
extern void(luaL_unref)(lua_State *L, int t, int ref);

extern int(luaL_loadfilex)(lua_State *L, const char *filename, const char *mode);

extern int(luaL_loadbufferx)(lua_State *L, const char *buff, size_t sz, const char *name,
							 const char *mode);
extern int(luaL_loadstring)(lua_State *L, const char *s);

extern lua_State *(luaL_newstate) (void);

extern lua_Integer(luaL_len)(lua_State *L, int idx);

extern void luaL_addgsub(luaL_Buffer *b, const char *s, const char *p, const char *r);
extern const char *(luaL_gsub) (lua_State *L, const char *s, const char *p, const char *r);

extern void(luaL_setfuncs)(lua_State *L, const luaL_Reg *l, int nup);

extern int(luaL_getsubtable)(lua_State *L, int idx, const char *fname);

extern void(luaL_traceback)(lua_State *L, lua_State *L1, const char *msg, int level);

extern void(luaL_requiref)(lua_State *L, const char *modname, lua_CFunction openf, int glb);
struct luaL_Buffer
{
	char *b;
	size_t size;
	size_t n;
	lua_State *L;
	union
	{
		lua_Number n;
		double u;
		void *s;
		lua_Integer i;
		long l;
		char b[((int) (16 * sizeof(void *) * sizeof(lua_Number)))];
	} init;
};
extern void(luaL_buffinit)(lua_State *L, luaL_Buffer *B);
extern char *(luaL_prepbuffsize) (luaL_Buffer *B, size_t sz);
extern void(luaL_addlstring)(luaL_Buffer *B, const char *s, size_t l);
extern void(luaL_addstring)(luaL_Buffer *B, const char *s);
extern void(luaL_addvalue)(luaL_Buffer *B);
extern void(luaL_pushresult)(luaL_Buffer *B);
extern void(luaL_pushresultsize)(luaL_Buffer *B, size_t sz);
extern char *(luaL_buffinitsize) (lua_State *L, luaL_Buffer *B, size_t sz);
typedef struct luaL_Stream
{
	FILE *f;
	lua_CFunction closef;
} luaL_Stream;

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
static const char *const opnames[] = {
	"MOVE",		"LOADI",	"LOADF",	"LOADK",	"LOADKX",	  "LOADFALSE", "LFALSESKIP",
	"LOADTRUE", "LOADNIL",	"GETUPVAL", "SETUPVAL", "GETTABUP",	  "GETTABLE",  "GETI",
	"GETFIELD", "SETTABUP", "SETTABLE", "SETI",		"SETFIELD",	  "NEWTABLE",  "SELF",
	"ADDI",		"ADDK",		"SUBK",		"MULK",		"MODK",		  "POWK",	   "DIVK",
	"IDIVK",	"BANDK",	"BORK",		"BXORK",	"SHRI",		  "SHLI",	   "ADD",
	"SUB",		"MUL",		"MOD",		"POW",		"DIV",		  "IDIV",	   "BAND",
	"BOR",		"BXOR",		"SHL",		"SHR",		"MMBIN",	  "MMBINI",	   "MMBINK",
	"UNM",		"BNOT",		"NOT",		"LEN",		"CONCAT",	  "CLOSE",	   "TBC",
	"JMP",		"EQ",		"LT",		"LE",		"EQK",		  "EQI",	   "LTI",
	"LEI",		"GTI",		"GEI",		"TEST",		"TESTSET",	  "CALL",	   "TAILCALL",
	"RETURN",	"RETURN0",	"RETURN1",	"FORLOOP",	"FORPREP",	  "TFORPREP",  "TFORCALL",
	"TFORLOOP", "SETLIST",	"CLOSURE",	"VARARG",	"VARARGPREP", "EXTRAARG",  NULL};

__attribute__((visibility("internal"))) extern LClosure *luaU_undump(lua_State *L, ZIO *Z,
																	 const char *name);

__attribute__((visibility("internal"))) extern int luaU_dump(lua_State *L, const Proto *f,
															 lua_Writer w, void *data, int strip);

static void PrintFunction(const Proto *f, int full);

static int listing = 0;
static int dumping = 1;
static int stripping = 0;
static char Output[] = {"luac"
						".out"};
static const char *output = Output;
static const char *progname = "luac";
static TString **tmname;

static void fatal(const char *message)
{
	fprintf(stderr, "%s: %s\n", progname, message);
	exit(EXIT_FAILURE);
}

static void cannot(const char *what)
{
	fprintf(stderr, "%s: cannot %s %s: %s\n", progname, what, output, strerror(errno));
	exit(EXIT_FAILURE);
}

static void usage(const char *message)
{
	if (*message == '-')
		fprintf(stderr, "%s: unrecognized option '%s'\n", progname, message);
	else
		fprintf(stderr, "%s: %s\n", progname, message);
	fprintf(stderr,
			"usage: %s [options] [filenames]\n"
			"Available options are:\n"
			"  -l       list (use -l -l for full listing)\n"
			"  -o name  output to file 'name' (default is \"%s\")\n"
			"  -p       parse only\n"
			"  -s       strip debug information\n"
			"  -v       show version information\n"
			"  --       stop handling options\n"
			"  -        stop handling options and process stdin\n",
			progname, Output);
	exit(EXIT_FAILURE);
}

static int doargs(int argc, char *argv[])
{
	int i;
	int version = 0;
	if (argv[0] != NULL && *argv[0] != 0)
		progname = argv[0];
	for (i = 1; i < argc; i++)
	{
		if (*argv[i] != '-')
			break;
		else if ((strcmp(argv[i], "--") == 0))
		{
			++i;
			if (version)
				++version;
			break;
		}
		else if ((strcmp(argv[i], "-") == 0))
			break;
		else if ((strcmp(argv[i], "-l") == 0))
			++listing;
		else if ((strcmp(argv[i], "-o") == 0))
		{
			output = argv[++i];
			if (output == NULL || *output == 0 || (*output == '-' && output[1] != 0))
				usage("'-o' needs argument");
			if ((strcmp(argv[i], "-") == 0))
				output = NULL;
		}
		else if ((strcmp(argv[i], "-p") == 0))
			dumping = 0;
		else if ((strcmp(argv[i], "-s") == 0))
			stripping = 1;
		else if ((strcmp(argv[i], "-v") == 0))
			++version;
		else
			usage(argv[i]);
	}
	if (i == argc && (listing || !dumping))
	{
		dumping = 0;
		argv[--i] = Output;
	}
	if (version)
	{
		printf("%s\n", "Lua "
					   "5"
					   "."
					   "4"
					   "."
					   "2"
					   "  Copyright (C) 1994-2020 Lua.org, PUC-Rio");
		if (version == argc - 1)
			exit(EXIT_SUCCESS);
	}
	return i;
}

static const char *reader(lua_State *L, void *ud, size_t *size)
{
	((void) (L));
	if ((*(int *) ud)--)
	{
		*size = sizeof("(function()end)();") - 1;
		return "(function()end)();";
	}
	else
	{
		*size = 0;
		return NULL;
	}
}

static const Proto *combine(lua_State *L, int n)
{
	if (n == 1)
		return (((&((((union GCUnion *) (((((&(L->top + (-1))->val))->value_).gc))))->cl.l)))->p);
	else
	{
		Proto *f;
		int i = n;
		if (lua_load(L, reader, &i,
					 "=("
					 "luac"
					 ")",
					 NULL) != 0)
			fatal(lua_tolstring(L, (-1), NULL));
		f = (((&((((union GCUnion *) (((((&(L->top + (-1))->val))->value_).gc))))->cl.l)))->p);
		for (i = 0; i < n; i++)
		{
			f->p[i] = (((&((((union GCUnion *) (((((&(L->top + (i - n - 1))->val))->value_).gc))))
							   ->cl.l)))
						   ->p);
			if (f->p[i]->sizeupvalues > 0)
				f->p[i]->upvalues[0].instack = 0;
		}
		f->sizelineinfo = 0;
		return f;
	}
}

static int writer(lua_State *L, const void *p, size_t size, void *u)
{
	((void) (L));
	return (fwrite(p, size, 1, (FILE *) u) != 1) && (size != 0);
}

static int pmain(lua_State *L)
{
	int argc = (int) lua_tointegerx(L, (1), NULL);
	char **argv = (char **) lua_touserdata(L, 2);
	const Proto *f;
	int i;
	tmname = (L->l_G)->tmname;
	if (!lua_checkstack(L, argc))
		fatal("too many input files");
	for (i = 0; i < argc; i++)
	{
		const char *filename = (strcmp(argv[i], "-") == 0) ? NULL : argv[i];
		if (luaL_loadfilex(L, filename, NULL) != 0)
			fatal(lua_tolstring(L, (-1), NULL));
	}
	f = combine(L, argc);
	if (listing)
		PrintFunction(f, listing > 1);
	if (dumping)
	{
		FILE *D = (output == NULL) ? stdout : fopen(output, "wb");
		if (D == NULL)
			cannot("open");
		((void) 0);
		luaU_dump(L, f, writer, D, stripping);
		((void) 0);
		if (ferror(D))
			cannot("write");
		if (fclose(D))
			cannot("close");
	}
	return 0;
}

int main(int argc, char *argv[])
{
	lua_State *L;
	int i = doargs(argc, argv);
	argc -= i;
	argv += i;
	if (argc <= 0)
		usage("no input files given");
	L = luaL_newstate();
	if (L == NULL)
		fatal("cannot create state: not enough memory");
	lua_pushcclosure(L, (&pmain), 0);
	lua_pushinteger(L, argc);
	lua_pushlightuserdata(L, argv);
	if (lua_pcallk(L, (2), (0), (0), 0, NULL) != 0)
		fatal(lua_tolstring(L, (-1), NULL));
	lua_close(L);
	return EXIT_SUCCESS;
}
static void PrintString(const TString *ts)
{
	const char *s = ((ts)->contents);
	size_t i, n = ((ts)->tt == ((4) | ((0) << 4)) ? (ts)->shrlen : (ts)->u.lnglen);
	printf("\"");
	for (i = 0; i < n; i++)
	{
		int c = (int) (unsigned char) s[i];
		switch (c)
		{
		case '"':
			printf("\\\"");
			break;
		case '\\':
			printf("\\\\");
			break;
		case '\a':
			printf("\\a");
			break;
		case '\b':
			printf("\\b");
			break;
		case '\f':
			printf("\\f");
			break;
		case '\n':
			printf("\\n");
			break;
		case '\r':
			printf("\\r");
			break;
		case '\t':
			printf("\\t");
			break;
		case '\v':
			printf("\\v");
			break;
		default:
			if (isprint(c))
				printf("%c", c);
			else
				printf("\\%03d", c);
			break;
		}
	}
	printf("\"");
}

static void PrintType(const Proto *f, int i)
{
	const TValue *o = &f->k[i];
	switch (((((o)->tt_)) & 0x3F))
	{
	case ((0) | ((0) << 4)):
		printf("N");
		break;
	case ((1) | ((0) << 4)):
	case ((1) | ((1) << 4)):
		printf("B");
		break;
	case ((3) | ((1) << 4)):
		printf("F");
		break;
	case ((3) | ((0) << 4)):
		printf("I");
		break;
	case ((4) | ((0) << 4)):
	case ((4) | ((1) << 4)):
		printf("S");
		break;
	default:
		printf("?%d", ((((o)->tt_)) & 0x3F));
		break;
	}
	printf("\t");
}

static void PrintConstant(const Proto *f, int i)
{
	const TValue *o = &f->k[i];
	switch (((((o)->tt_)) & 0x3F))
	{
	case ((0) | ((0) << 4)):
		printf("nil");
		break;
	case ((1) | ((0) << 4)):
		printf("false");
		break;
	case ((1) | ((1) << 4)):
		printf("true");
		break;
	case ((3) | ((1) << 4)):
	{
		char buff[100];
		sprintf(buff, "%.14g", (((o)->value_).n));
		printf("%s", buff);
		if (buff[strspn(buff, "-0123456789")] == '\0')
			printf(".0");
		break;
	}
	case ((3) | ((0) << 4)):
		printf("%" LUA_INTEGER_FRMLEN "d", (((o)->value_).i));
		break;
	case ((4) | ((0) << 4)):
	case ((4) | ((1) << 4)):
		PrintString(((&((((union GCUnion *) ((((o)->value_).gc))))->ts))));
		break;
	default:
		printf("?%d", ((((o)->tt_)) & 0x3F));
		break;
	}
}

static void PrintCode(const Proto *f)
{
	const Instruction *code = f->code;
	int pc, n = f->sizecode;
	for (pc = 0; pc < n; pc++)
	{
		Instruction i = code[pc];
		OpCode o = (((OpCode) (((i) >> 0) & ((~((~(Instruction) 0) << (7))) << (0)))));
		int a = (((int) ((((i) >> ((0 + 7))) & ((~((~(Instruction) 0) << (8))) << (0))))));
		int b = ((
			((int) ((((i) >> ((((0 + 7) + 8) + 1))) & ((~((~(Instruction) 0) << (8))) << (0)))))));
		int c = ((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
						   ((~((~(Instruction) 0) << (8))) << (0)))))));
		int ax = ((((int) ((((i) >> ((0 + 7))) &
							((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))));
		int bx = ((((int) ((((i) >> (((0 + 7) + 8))) &
							((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))));
		int sb = ((((((int) ((((i) >> ((((0 + 7) + 8) + 1))) &
							  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
				  (((1 << 8) - 1) >> 1));
		int sc = ((((((int) ((((i) >> (((((0 + 7) + 8) + 1) + 8))) &
							  ((~((~(Instruction) 0) << (8))) << (0)))))))) -
				  (((1 << 8) - 1) >> 1));
		int sbx = ((((int) ((((i) >> (((0 + 7) + 8))) &
							 ((~((~(Instruction) 0) << ((8 + 8 + 1)))) << (0)))))) -
				   (INT_MAX >> 1));
		int isk =
			((((int) ((((i) >> (((0 + 7) + 8))) & ((~((~(Instruction) 0) << (1))) << (0)))))));
		int line = luaG_getfuncline(f, pc);
		printf("\t%d\t", pc + 1);
		if (line > 0)
			printf("[%d]\t", line);
		else
			printf("[-]\t");
		printf("%-9s\t", opnames[o]);
		switch (o)
		{
		case OP_MOVE:
			printf("%d %d", a, b);
			break;
		case OP_LOADI:
			printf("%d %d", a, sbx);
			break;
		case OP_LOADF:
			printf("%d %d", a, sbx);
			break;
		case OP_LOADK:
			printf("%d %d", a, bx);
			printf("\t; ");
			PrintConstant(f, bx);
			break;
		case OP_LOADKX:
			printf("%d", a);
			printf("\t; ");
			PrintConstant(f,
						  ((((int) ((((code[pc + 1]) >> ((0 + 7))) &
									 ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0))))))));
			break;
		case OP_LOADFALSE:
			printf("%d", a);
			break;
		case OP_LFALSESKIP:
			printf("%d", a);
			break;
		case OP_LOADTRUE:
			printf("%d", a);
			break;
		case OP_LOADNIL:
			printf("%d %d", a, b);
			printf("\t; "
				   "%d out",
				   b + 1);
			break;
		case OP_GETUPVAL:
			printf("%d %d", a, b);
			printf("\t; "
				   "%s",
				   ((f->upvalues[b].name) ? ((f->upvalues[b].name)->contents) : "-"));
			break;
		case OP_SETUPVAL:
			printf("%d %d", a, b);
			printf("\t; "
				   "%s",
				   ((f->upvalues[b].name) ? ((f->upvalues[b].name)->contents) : "-"));
			break;
		case OP_GETTABUP:
			printf("%d %d %d", a, b, c);
			printf("\t; "
				   "%s",
				   ((f->upvalues[b].name) ? ((f->upvalues[b].name)->contents) : "-"));
			printf(" ");
			PrintConstant(f, c);
			break;
		case OP_GETTABLE:
			printf("%d %d %d", a, b, c);
			break;
		case OP_GETI:
			printf("%d %d %d", a, b, c);
			break;
		case OP_GETFIELD:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_SETTABUP:
			printf("%d %d %d%s", a, b, c, (isk ? "k" : ""));
			printf("\t; "
				   "%s",
				   ((f->upvalues[a].name) ? ((f->upvalues[a].name)->contents) : "-"));
			printf(" ");
			PrintConstant(f, b);
			if (isk)
			{
				printf(" ");
				PrintConstant(f, c);
			}
			break;
		case OP_SETTABLE:
			printf("%d %d %d%s", a, b, c, (isk ? "k" : ""));
			if (isk)
			{
				printf("\t; ");
				PrintConstant(f, c);
			}
			break;
		case OP_SETI:
			printf("%d %d %d%s", a, b, c, (isk ? "k" : ""));
			if (isk)
			{
				printf("\t; ");
				PrintConstant(f, c);
			}
			break;
		case OP_SETFIELD:
			printf("%d %d %d%s", a, b, c, (isk ? "k" : ""));
			printf("\t; ");
			PrintConstant(f, b);
			if (isk)
			{
				printf(" ");
				PrintConstant(f, c);
			}
			break;
		case OP_NEWTABLE:
			printf("%d %d %d", a, b, c);
			printf("\t; "
				   "%d",
				   c + (((((int) ((((code[pc + 1]) >> ((0 + 7))) &
								   ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0))))))) *
						(((1 << 8) - 1) + 1)));
			break;
		case OP_SELF:
			printf("%d %d %d%s", a, b, c, (isk ? "k" : ""));
			if (isk)
			{
				printf("\t; ");
				PrintConstant(f, c);
			}
			break;
		case OP_ADDI:
			printf("%d %d %d", a, b, sc);
			break;
		case OP_ADDK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_SUBK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_MULK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_MODK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_POWK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_DIVK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_IDIVK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_BANDK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_BORK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_BXORK:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			PrintConstant(f, c);
			break;
		case OP_SHRI:
			printf("%d %d %d", a, b, sc);
			break;
		case OP_SHLI:
			printf("%d %d %d", a, b, sc);
			break;
		case OP_ADD:
			printf("%d %d %d", a, b, c);
			break;
		case OP_SUB:
			printf("%d %d %d", a, b, c);
			break;
		case OP_MUL:
			printf("%d %d %d", a, b, c);
			break;
		case OP_MOD:
			printf("%d %d %d", a, b, c);
			break;
		case OP_POW:
			printf("%d %d %d", a, b, c);
			break;
		case OP_DIV:
			printf("%d %d %d", a, b, c);
			break;
		case OP_IDIV:
			printf("%d %d %d", a, b, c);
			break;
		case OP_BAND:
			printf("%d %d %d", a, b, c);
			break;
		case OP_BOR:
			printf("%d %d %d", a, b, c);
			break;
		case OP_BXOR:
			printf("%d %d %d", a, b, c);
			break;
		case OP_SHL:
			printf("%d %d %d", a, b, c);
			break;
		case OP_SHR:
			printf("%d %d %d", a, b, c);
			break;
		case OP_MMBIN:
			printf("%d %d %d", a, b, c);
			printf("\t; "
				   "%s",
				   (((tmname[c])->contents)));
			break;
		case OP_MMBINI:
			printf("%d %d %d %d", a, sb, c, isk);
			printf("\t; "
				   "%s",
				   (((tmname[c])->contents)));
			if (isk)
				printf(" flip");
			break;
		case OP_MMBINK:
			printf("%d %d %d %d", a, b, c, isk);
			printf("\t; "
				   "%s ",
				   (((tmname[c])->contents)));
			PrintConstant(f, b);
			if (isk)
				printf(" flip");
			break;
		case OP_UNM:
			printf("%d %d", a, b);
			break;
		case OP_BNOT:
			printf("%d %d", a, b);
			break;
		case OP_NOT:
			printf("%d %d", a, b);
			break;
		case OP_LEN:
			printf("%d %d", a, b);
			break;
		case OP_CONCAT:
			printf("%d %d", a, b);
			break;
		case OP_CLOSE:
			printf("%d", a);
			break;
		case OP_TBC:
			printf("%d", a);
			break;
		case OP_JMP:
			printf("%d", ((((int) ((((i) >> ((0 + 7))) &
									((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
						  (INT_MAX >> 1)));
			printf("\t; "
				   "to %d",
				   ((((int) ((((i) >> ((0 + 7))) &
							  ((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0)))))) -
					(INT_MAX >> 1)) +
					   pc + 2);
			break;
		case OP_EQ:
			printf("%d %d %d", a, b, isk);
			break;
		case OP_LT:
			printf("%d %d %d", a, b, isk);
			break;
		case OP_LE:
			printf("%d %d %d", a, b, isk);
			break;
		case OP_EQK:
			printf("%d %d %d", a, b, isk);
			printf("\t; ");
			PrintConstant(f, b);
			break;
		case OP_EQI:
			printf("%d %d %d", a, sb, isk);
			break;
		case OP_LTI:
			printf("%d %d %d", a, sb, isk);
			break;
		case OP_LEI:
			printf("%d %d %d", a, sb, isk);
			break;
		case OP_GTI:
			printf("%d %d %d", a, sb, isk);
			break;
		case OP_GEI:
			printf("%d %d %d", a, sb, isk);
			break;
		case OP_TEST:
			printf("%d %d", a, isk);
			break;
		case OP_TESTSET:
			printf("%d %d %d", a, b, isk);
			break;
		case OP_CALL:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			if (b == 0)
				printf("all in ");
			else
				printf("%d in ", b - 1);
			if (c == 0)
				printf("all out");
			else
				printf("%d out", c - 1);
			break;
		case OP_TAILCALL:
			printf("%d %d %d", a, b, c);
			printf("\t; "
				   "%d in",
				   b - 1);
			break;
		case OP_RETURN:
			printf("%d %d %d", a, b, c);
			printf("\t; ");
			if (b == 0)
				printf("all out");
			else
				printf("%d out", b - 1);
			break;
		case OP_RETURN0:
			break;
		case OP_RETURN1:
			printf("%d", a);
			break;
		case OP_FORLOOP:
			printf("%d %d", a, bx);
			printf("\t; "
				   "to %d",
				   pc - bx + 2);
			break;
		case OP_FORPREP:
			printf("%d %d", a, bx);
			printf("\t; "
				   "to %d",
				   pc + bx + 2);
			break;
		case OP_TFORPREP:
			printf("%d %d", a, bx);
			printf("\t; "
				   "to %d",
				   pc + bx + 2);
			break;
		case OP_TFORCALL:
			printf("%d %d", a, c);
			break;
		case OP_TFORLOOP:
			printf("%d %d", a, bx);
			printf("\t; "
				   "to %d",
				   pc - bx + 2);
			break;
		case OP_SETLIST:
			printf("%d %d %d", a, b, c);
			if (isk)
				printf(
					"\t; "
					"%d",
					c + (((((int) ((((code[pc + 1]) >> ((0 + 7))) &
									((~((~(Instruction) 0) << (((8 + 8 + 1) + 8)))) << (0))))))) *
						 (((1 << 8) - 1) + 1)));
			break;
		case OP_CLOSURE:
			printf("%d %d", a, bx);
			printf("\t; "
				   "%p",
				   ((const void *) (f->p[bx])));
			break;
		case OP_VARARG:
			printf("%d %d", a, c);
			printf("\t; ");
			if (c == 0)
				printf("all out");
			else
				printf("%d out", c - 1);
			break;
		case OP_VARARGPREP:
			printf("%d", a);
			break;
		case OP_EXTRAARG:
			printf("%d", ax);
			break;
		}
		printf("\n");
	}
}

static void PrintHeader(const Proto *f)
{
	const char *s = f->source ? ((f->source)->contents) : "=?";
	if (*s == '@' || *s == '=')
		s++;
	else if (*s == "\x1bLua"[0])
		s = "(bstring)";
	else
		s = "(string)";
	printf("\n%s <%s:%d,%d> (%d instruction%s at %p)\n",
		   (f->linedefined == 0) ? "main" : "function", s, f->linedefined, f->lastlinedefined,
		   (int) (f->sizecode), ((f->sizecode == 1) ? "" : "s"), ((const void *) (f)));
	printf("%d%s param%s, %d slot%s, %d upvalue%s, ", (int) (f->numparams), f->is_vararg ? "+" : "",
		   ((f->numparams == 1) ? "" : "s"), (int) (f->maxstacksize),
		   ((f->maxstacksize == 1) ? "" : "s"), (int) (f->sizeupvalues),
		   ((f->sizeupvalues == 1) ? "" : "s"));
	printf("%d local%s, %d constant%s, %d function%s\n", (int) (f->sizelocvars),
		   ((f->sizelocvars == 1) ? "" : "s"), (int) (f->sizek), ((f->sizek == 1) ? "" : "s"),
		   (int) (f->sizep), ((f->sizep == 1) ? "" : "s"));
}

static void PrintDebug(const Proto *f)
{
	int i, n;
	n = f->sizek;
	printf("constants (%d) for %p:\n", n, ((const void *) (f)));
	for (i = 0; i < n; i++)
	{
		printf("\t%d\t", i);
		PrintType(f, i);
		PrintConstant(f, i);
		printf("\n");
	}
	n = f->sizelocvars;
	printf("locals (%d) for %p:\n", n, ((const void *) (f)));
	for (i = 0; i < n; i++)
	{
		printf("\t%d\t%s\t%d\t%d\n", i, ((f->locvars[i].varname)->contents),
			   f->locvars[i].startpc + 1, f->locvars[i].endpc + 1);
	}
	n = f->sizeupvalues;
	printf("upvalues (%d) for %p:\n", n, ((const void *) (f)));
	for (i = 0; i < n; i++)
	{
		printf("\t%d\t%s\t%d\t%d\n", i,
			   ((f->upvalues[i].name) ? ((f->upvalues[i].name)->contents) : "-"),
			   f->upvalues[i].instack, f->upvalues[i].idx);
	}
}

static void PrintFunction(const Proto *f, int full)
{
	int i, n = f->sizep;
	PrintHeader(f);
	PrintCode(f);
	if (full)
		PrintDebug(f);
	for (i = 0; i < n; i++)
		PrintFunction(f->p[i], full);
}
