

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
extern int(luaopen_base)(lua_State *L);

extern int(luaopen_coroutine)(lua_State *L);

extern int(luaopen_table)(lua_State *L);

extern int(luaopen_io)(lua_State *L);

extern int(luaopen_os)(lua_State *L);

extern int(luaopen_string)(lua_State *L);

extern int(luaopen_utf8)(lua_State *L);

extern int(luaopen_math)(lua_State *L);

extern int(luaopen_debug)(lua_State *L);

extern int(luaopen_package)(lua_State *L);

extern void(luaL_openlibs)(lua_State *L);

static int math_abs(lua_State *L)
{
	if (lua_isinteger(L, 1))
	{
		lua_Integer n = lua_tointegerx(L, (1), NULL);
		if (n < 0)
			n = (lua_Integer) (0u - (lua_Unsigned) n);
		lua_pushinteger(L, n);
	}
	else
		lua_pushnumber(L, fabs(luaL_checknumber(L, 1)));
	return 1;
}

static int math_sin(lua_State *L)
{
	lua_pushnumber(L, sin(luaL_checknumber(L, 1)));
	return 1;
}

static int math_cos(lua_State *L)
{
	lua_pushnumber(L, cos(luaL_checknumber(L, 1)));
	return 1;
}

static int math_tan(lua_State *L)
{
	lua_pushnumber(L, tan(luaL_checknumber(L, 1)));
	return 1;
}

static int math_asin(lua_State *L)
{
	lua_pushnumber(L, asin(luaL_checknumber(L, 1)));
	return 1;
}

static int math_acos(lua_State *L)
{
	lua_pushnumber(L, acos(luaL_checknumber(L, 1)));
	return 1;
}

static int math_atan(lua_State *L)
{
	lua_Number y = luaL_checknumber(L, 1);
	lua_Number x = luaL_optnumber(L, 2, 1);
	lua_pushnumber(L, atan2(y, x));
	return 1;
}

static int math_toint(lua_State *L)
{
	int valid;
	lua_Integer n = lua_tointegerx(L, 1, &valid);
	if (valid)
		lua_pushinteger(L, n);
	else
	{
		luaL_checkany(L, 1);
		lua_pushnil(L);
	}
	return 1;
}

static void pushnumint(lua_State *L, lua_Number d)
{
	lua_Integer n;
	if (((d) >= (double) (LUA_MININTEGER) && (d) < -(double) (LUA_MININTEGER) &&
		 (*(&n) = (LUA_INTEGER) (d), 1)))
		lua_pushinteger(L, n);
	else
		lua_pushnumber(L, d);
}

static int math_floor(lua_State *L)
{
	if (lua_isinteger(L, 1))
		lua_settop(L, 1);
	else
	{
		lua_Number d = floor(luaL_checknumber(L, 1));
		pushnumint(L, d);
	}
	return 1;
}

static int math_ceil(lua_State *L)
{
	if (lua_isinteger(L, 1))
		lua_settop(L, 1);
	else
	{
		lua_Number d = ceil(luaL_checknumber(L, 1));
		pushnumint(L, d);
	}
	return 1;
}

static int math_fmod(lua_State *L)
{
	if (lua_isinteger(L, 1) && lua_isinteger(L, 2))
	{
		lua_Integer d = lua_tointegerx(L, (2), NULL);
		if ((lua_Unsigned) d + 1u <= 1u)
		{
			((void) ((d != 0) || luaL_argerror(L, (2), ("zero"))));
			lua_pushinteger(L, 0);
		}
		else
			lua_pushinteger(L, lua_tointegerx(L, (1), NULL) % d);
	}
	else
		lua_pushnumber(L, fmod(luaL_checknumber(L, 1), luaL_checknumber(L, 2)));
	return 1;
}

static int math_modf(lua_State *L)
{
	if (lua_isinteger(L, 1))
	{
		lua_settop(L, 1);
		lua_pushnumber(L, 0);
	}
	else
	{
		lua_Number n = luaL_checknumber(L, 1);

		lua_Number ip = (n < 0) ? ceil(n) : floor(n);
		pushnumint(L, ip);

		lua_pushnumber(L, (n == ip) ? 0.0 : (n - ip));
	}
	return 2;
}

static int math_sqrt(lua_State *L)
{
	lua_pushnumber(L, sqrt(luaL_checknumber(L, 1)));
	return 1;
}

static int math_ult(lua_State *L)
{
	lua_Integer a = luaL_checkinteger(L, 1);
	lua_Integer b = luaL_checkinteger(L, 2);
	lua_pushboolean(L, (lua_Unsigned) a < (lua_Unsigned) b);
	return 1;
}

static int math_log(lua_State *L)
{
	lua_Number x = luaL_checknumber(L, 1);
	lua_Number res;
	if ((lua_type(L, (2)) <= 0))
		res = log(x);
	else
	{
		lua_Number base = luaL_checknumber(L, 2);

		if (base == 2.0)
			res = log2(x);
		else

			if (base == 10.0)
			res = log10(x);
		else
			res = log(x) / log(base);
	}
	lua_pushnumber(L, res);
	return 1;
}

static int math_exp(lua_State *L)
{
	lua_pushnumber(L, exp(luaL_checknumber(L, 1)));
	return 1;
}

static int math_deg(lua_State *L)
{
	lua_pushnumber(L, luaL_checknumber(L, 1) * (180.0 / (3.141592653589793238462643383279502884)));
	return 1;
}

static int math_rad(lua_State *L)
{
	lua_pushnumber(L, luaL_checknumber(L, 1) * ((3.141592653589793238462643383279502884) / 180.0));
	return 1;
}

static int math_min(lua_State *L)
{
	int n = lua_gettop(L);
	int imin = 1;
	int i;
	((void) ((n >= 1) || luaL_argerror(L, (1), ("value expected"))));
	for (i = 2; i <= n; i++)
	{
		if (lua_compare(L, i, imin, 1))
			imin = i;
	}
	lua_pushvalue(L, imin);
	return 1;
}

static int math_max(lua_State *L)
{
	int n = lua_gettop(L);
	int imax = 1;
	int i;
	((void) ((n >= 1) || luaL_argerror(L, (1), ("value expected"))));
	for (i = 2; i <= n; i++)
	{
		if (lua_compare(L, imax, i, 1))
			imax = i;
	}
	lua_pushvalue(L, imax);
	return 1;
}

static int math_type(lua_State *L)
{
	if (lua_type(L, 1) == 3)
		lua_pushstring(L, (lua_isinteger(L, 1)) ? "integer" : "float");
	else
	{
		luaL_checkany(L, 1);
		lua_pushnil(L);
	}
	return 1;
}
typedef unsigned long lu_int32;

typedef struct Rand64
{
	lu_int32 h;
	lu_int32 l;
} Rand64;
static Rand64 packI(lu_int32 h, lu_int32 l)
{
	Rand64 result;
	result.h = h;
	result.l = l;
	return result;
}

static Rand64 Ishl(Rand64 i, int n)
{
	((void) 0);
	return packI((i.h << n) | (((i.l) & 0xffffffffu) >> (32 - n)), i.l << n);
}

static void Ixor(Rand64 *i1, Rand64 i2)
{
	i1->h ^= i2.h;
	i1->l ^= i2.l;
}

static Rand64 Iadd(Rand64 i1, Rand64 i2)
{
	Rand64 result = packI(i1.h + i2.h, i1.l + i2.l);
	if (((result.l) & 0xffffffffu) < ((i1.l) & 0xffffffffu))
		result.h++;
	return result;
}

static Rand64 times5(Rand64 i)
{
	return Iadd(Ishl(i, 2), i);
}

static Rand64 times9(Rand64 i)
{
	return Iadd(Ishl(i, 3), i);
}

static Rand64 rotl(Rand64 i, int n)
{
	((void) 0);
	return packI((i.h << n) | (((i.l) & 0xffffffffu) >> (32 - n)),
				 (((i.h) & 0xffffffffu) >> (32 - n)) | (i.l << n));
}

static Rand64 rotl1(Rand64 i, int n)
{
	((void) 0);
	n = 64 - n;
	return packI((((i.h) & 0xffffffffu) >> n) | (i.l << (32 - n)),
				 (i.h << (32 - n)) | (((i.l) & 0xffffffffu) >> n));
}

static Rand64 nextrand(Rand64 *state)
{
	Rand64 res = times9(rotl(times5(state[1]), 7));
	Rand64 t = Ishl(state[1], 17);
	Ixor(&state[2], state[0]);
	Ixor(&state[3], state[1]);
	Ixor(&state[1], state[2]);
	Ixor(&state[0], state[3]);
	Ixor(&state[2], t);
	state[3] = rotl1(state[3], 45);
	return res;
}
static lua_Number I2d(Rand64 x)
{
	lua_Number h = (lua_Number) (((x.h) & 0xffffffffu) >> (32 - (DBL_MANT_DIG)));
	return h * (0.5 / (((lu_int32) 1) << ((DBL_MANT_DIG) -1)));
}
static lua_Unsigned I2UInt(Rand64 x)
{
	return ((lua_Unsigned) ((x.h) & 0xffffffffu) << 31 << 1) | (lua_Unsigned) ((x.l) & 0xffffffffu);
}

static Rand64 Int2I(lua_Unsigned n)
{
	return packI((lu_int32) (n >> 31 >> 1), (lu_int32) n);
}

typedef struct
{
	Rand64 s[4];
} RanState;
static lua_Unsigned project(lua_Unsigned ran, lua_Unsigned n, RanState *state)
{
	if ((n & (n + 1)) == 0)
		return ran & n;
	else
	{
		lua_Unsigned lim = n;

		lim |= (lim >> 1);
		lim |= (lim >> 2);
		lim |= (lim >> 4);
		lim |= (lim >> 8);
		lim |= (lim >> 16);

		((void) 0);

		while ((ran &= lim) > n)
			ran = I2UInt(nextrand(state->s));
		return ran;
	}
}

static int math_random(lua_State *L)
{
	lua_Integer low, up;
	lua_Unsigned p;
	RanState *state = (RanState *) lua_touserdata(L, ((-15000 - 1000) - (1)));
	Rand64 rv = nextrand(state->s);
	switch (lua_gettop(L))
	{
	case 0:
	{
		lua_pushnumber(L, I2d(rv));
		return 1;
	}
	case 1:
	{
		low = 1;
		up = luaL_checkinteger(L, 1);
		if (up == 0)
		{
			lua_pushinteger(L, I2UInt(rv));
			return 1;
		}
		break;
	}
	case 2:
	{
		low = luaL_checkinteger(L, 1);
		up = luaL_checkinteger(L, 2);
		break;
	}
	default:
		return luaL_error(L, "wrong number of arguments");
	}

	((void) ((low <= up) || luaL_argerror(L, (1), ("interval is empty"))));

	p = project(I2UInt(rv), (lua_Unsigned) up - (lua_Unsigned) low, state);
	lua_pushinteger(L, p + (lua_Unsigned) low);
	return 1;
}

static void setseed(lua_State *L, Rand64 *state, lua_Unsigned n1, lua_Unsigned n2)
{
	int i;
	state[0] = Int2I(n1);
	state[1] = Int2I(0xff);
	state[2] = Int2I(n2);
	state[3] = Int2I(0);
	for (i = 0; i < 16; i++)
		nextrand(state);
	lua_pushinteger(L, n1);
	lua_pushinteger(L, n2);
}

static void randseed(lua_State *L, RanState *state)
{
	lua_Unsigned seed1 = (lua_Unsigned) time(NULL);
	lua_Unsigned seed2 = (lua_Unsigned) (size_t) L;
	setseed(L, state->s, seed1, seed2);
}

static int math_randomseed(lua_State *L)
{
	RanState *state = (RanState *) lua_touserdata(L, ((-15000 - 1000) - (1)));
	if ((lua_type(L, (1)) == (-1)))
	{
		randseed(L, state);
	}
	else
	{
		lua_Integer n1 = luaL_checkinteger(L, 1);
		lua_Integer n2 = luaL_optinteger(L, 2, 0);
		setseed(L, state->s, n1, n2);
	}
	return 2;
}

static const luaL_Reg randfuncs[] = {
	{"random", math_random}, {"randomseed", math_randomseed}, {NULL, NULL}};

static void setrandfunc(lua_State *L)
{
	RanState *state = (RanState *) lua_newuserdatauv(L, sizeof(RanState), 0);
	randseed(L, state);
	lua_settop(L, -(2) - 1);
	luaL_setfuncs(L, randfuncs, 1);
}
static const luaL_Reg mathlib[] = {
	{"abs", math_abs},	   {"acos", math_acos},	 {"asin", math_asin},
	{"atan", math_atan},   {"ceil", math_ceil},	 {"cos", math_cos},
	{"deg", math_deg},	   {"exp", math_exp},	 {"tointeger", math_toint},
	{"floor", math_floor}, {"fmod", math_fmod},	 {"ult", math_ult},
	{"log", math_log},	   {"max", math_max},	 {"min", math_min},
	{"modf", math_modf},   {"rad", math_rad},	 {"sin", math_sin},
	{"sqrt", math_sqrt},   {"tan", math_tan},	 {"type", math_type},
	{"random", NULL},	   {"randomseed", NULL}, {"pi", NULL},
	{"huge", NULL},		   {"maxinteger", NULL}, {"mininteger", NULL},
	{NULL, NULL}};

extern int luaopen_math(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(mathlib) / sizeof((mathlib)[0]) - 1),
	 luaL_setfuncs(L, mathlib, 0));
	lua_pushnumber(L, (3.141592653589793238462643383279502884));
	lua_setfield(L, -2, "pi");
	lua_pushnumber(L, (lua_Number) HUGE_VAL);
	lua_setfield(L, -2, "huge");
	lua_pushinteger(L, LUA_MAXINTEGER);
	lua_setfield(L, -2, "maxinteger");
	lua_pushinteger(L, LUA_MININTEGER);
	lua_setfield(L, -2, "mininteger");
	setrandfunc(L);
	return 1;
}
