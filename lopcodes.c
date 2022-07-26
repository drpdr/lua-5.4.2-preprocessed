

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

const lu_byte luaP_opmodes[((int) (OP_EXTRAARG) + 1)] = {

	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iAsBx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iAsBx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((1) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((1) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((1) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (isJ)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((1) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((1) << 6) | ((1) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((1) << 6) | ((1) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((1) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABx)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABx)),
	(((0) << 7) | ((0) << 6) | ((1) << 5) | ((0) << 4) | ((0) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABx)),
	(((0) << 7) | ((1) << 6) | ((0) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((1) << 5) | ((0) << 4) | ((1) << 3) | (iABC)),
	(((0) << 7) | ((0) << 6) | ((0) << 5) | ((0) << 4) | ((0) << 3) | (iAx))};
