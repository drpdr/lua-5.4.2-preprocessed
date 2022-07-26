

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
static int checkfield(lua_State *L, const char *key, int n)
{
	lua_pushstring(L, key);
	return (lua_rawget(L, -n) != 0);
}

static void checktab(lua_State *L, int arg, int what)
{
	if (lua_type(L, arg) != 5)
	{
		int n = 1;
		if (lua_getmetatable(L, arg) && (!(what & 1) || checkfield(L, "__index", ++n)) &&
			(!(what & 2) || checkfield(L, "__newindex", ++n)) &&
			(!(what & 4) || checkfield(L, "__len", ++n)))
		{
			lua_settop(L, -(n) -1);
		}
		else
			luaL_checktype(L, arg, 5);
	}
}

static int tinsert(lua_State *L)
{
	lua_Integer e = (checktab(L, 1, ((1 | 2)) | 4), luaL_len(L, 1)) + 1;
	lua_Integer pos;
	switch (lua_gettop(L))
	{
	case 2:
	{
		pos = e;
		break;
	}
	case 3:
	{
		lua_Integer i;
		pos = luaL_checkinteger(L, 2);

		((void) (((lua_Unsigned) pos - 1u < (lua_Unsigned) e) ||
				 luaL_argerror(L, (2), ("position out of bounds"))));

		for (i = e; i > pos; i--)
		{
			lua_geti(L, 1, i - 1);
			lua_seti(L, 1, i);
		}
		break;
	}
	default:
	{
		return luaL_error(L, "wrong number of arguments to 'insert'");
	}
	}
	lua_seti(L, 1, pos);
	return 0;
}

static int tremove(lua_State *L)
{
	lua_Integer size = (checktab(L, 1, ((1 | 2)) | 4), luaL_len(L, 1));
	lua_Integer pos = luaL_optinteger(L, 2, size);
	if (pos != size)

		((void) (((lua_Unsigned) pos - 1u <= (lua_Unsigned) size) ||
				 luaL_argerror(L, (1), ("position out of bounds"))));

	lua_geti(L, 1, pos);
	for (; pos < size; pos++)
	{
		lua_geti(L, 1, pos + 1);
		lua_seti(L, 1, pos);
	}
	lua_pushnil(L);
	lua_seti(L, 1, pos);
	return 1;
}
static int tmove(lua_State *L)
{
	lua_Integer f = luaL_checkinteger(L, 2);
	lua_Integer e = luaL_checkinteger(L, 3);
	lua_Integer t = luaL_checkinteger(L, 4);
	int tt = !(lua_type(L, (5)) <= 0) ? 5 : 1;
	checktab(L, 1, 1);
	checktab(L, tt, 2);
	if (e >= f)
	{
		lua_Integer n, i;
		((void) ((f > 0 || e < LUA_MAXINTEGER + f) ||
				 luaL_argerror(L, (3), ("too many elements to move"))));

		n = e - f + 1;
		((void) ((t <= LUA_MAXINTEGER - n + 1) ||
				 luaL_argerror(L, (4), ("destination wrap around"))));

		if (t > e || t <= f || (tt != 1 && !lua_compare(L, 1, tt, 0)))
		{
			for (i = 0; i < n; i++)
			{
				lua_geti(L, 1, f + i);
				lua_seti(L, tt, t + i);
			}
		}
		else
		{
			for (i = n - 1; i >= 0; i--)
			{
				lua_geti(L, 1, f + i);
				lua_seti(L, tt, t + i);
			}
		}
	}
	lua_pushvalue(L, tt);
	return 1;
}

static void addfield(lua_State *L, luaL_Buffer *b, lua_Integer i)
{
	lua_geti(L, 1, i);
	if (!lua_isstring(L, -1))
		luaL_error(L, "invalid value (%s) at index %d in table for 'concat'",
				   lua_typename(L, lua_type(L, (-1))), i);
	luaL_addvalue(b);
}

static int tconcat(lua_State *L)
{
	luaL_Buffer b;
	lua_Integer last = (checktab(L, 1, (1) | 4), luaL_len(L, 1));
	size_t lsep;
	const char *sep = luaL_optlstring(L, 2, "", &lsep);
	lua_Integer i = luaL_optinteger(L, 3, 1);
	last = luaL_optinteger(L, 4, last);
	luaL_buffinit(L, &b);
	for (; i < last; i++)
	{
		addfield(L, &b, i);
		luaL_addlstring(&b, sep, lsep);
	}
	if (i == last)
		addfield(L, &b, i);
	luaL_pushresult(&b);
	return 1;
}
static int tpack(lua_State *L)
{
	int i;
	int n = lua_gettop(L);
	lua_createtable(L, n, 1);
	lua_rotate(L, (1), 1);
	for (i = n; i >= 1; i--)
		lua_seti(L, 1, i);
	lua_pushinteger(L, n);
	lua_setfield(L, 1, "n");
	return 1;
}

static int tunpack(lua_State *L)
{
	lua_Unsigned n;
	lua_Integer i = luaL_optinteger(L, 2, 1);
	lua_Integer e = ((lua_type(L, ((3))) <= 0) ? (luaL_len(L, 1)) : luaL_checkinteger(L, (3)));
	if (i > e)
		return 0;
	n = (lua_Unsigned) e - i;
	if (n >= (unsigned int) INT_MAX || !lua_checkstack(L, (int) (++n)))
		return luaL_error(L, "too many results to unpack");
	for (; i < e; i++)
	{
		lua_geti(L, 1, i);
	}
	lua_geti(L, 1, e);
	return (int) n;
}
typedef unsigned int IdxT;
static unsigned int l_randomizePivot(void)
{
	clock_t c = clock();
	time_t t = time(NULL);
	unsigned int buff[(sizeof(c) / sizeof(unsigned int)) + (sizeof(t) / sizeof(unsigned int))];
	unsigned int i, rnd = 0;
	memcpy(buff, &c, (sizeof(c) / sizeof(unsigned int)) * sizeof(unsigned int));
	memcpy(buff + (sizeof(c) / sizeof(unsigned int)), &t,
		   (sizeof(t) / sizeof(unsigned int)) * sizeof(unsigned int));
	for (i = 0; i < (sizeof(buff) / sizeof(unsigned int)); i++)
		rnd += buff[i];
	return rnd;
}
static void set2(lua_State *L, IdxT i, IdxT j)
{
	lua_seti(L, 1, i);
	lua_seti(L, 1, j);
}

static int sort_comp(lua_State *L, int a, int b)
{
	if ((lua_type(L, (2)) == 0))
		return lua_compare(L, a, b, 1);
	else
	{
		int res;
		lua_pushvalue(L, 2);
		lua_pushvalue(L, a - 1);
		lua_pushvalue(L, b - 2);
		lua_callk(L, (2), (1), 0, NULL);
		res = lua_toboolean(L, -1);
		lua_settop(L, -(1) - 1);
		return res;
	}
}
static IdxT partition(lua_State *L, IdxT lo, IdxT up)
{
	IdxT i = lo;
	IdxT j = up - 1;

	for (;;)
	{

		while ((void) lua_geti(L, 1, ++i), sort_comp(L, -1, -2))
		{
			if (i == up - 1)
				luaL_error(L, "invalid order function for sorting");
			lua_settop(L, -(1) - 1);
		}

		while ((void) lua_geti(L, 1, --j), sort_comp(L, -3, -1))
		{
			if (j < i)
				luaL_error(L, "invalid order function for sorting");
			lua_settop(L, -(1) - 1);
		}

		if (j < i)
		{

			lua_settop(L, -(1) - 1);

			set2(L, up - 1, i);
			return i;
		}

		set2(L, i, j);
	}
}

static IdxT choosePivot(IdxT lo, IdxT up, unsigned int rnd)
{
	IdxT r4 = (up - lo) / 4;
	IdxT p = rnd % (r4 * 2) + (lo + r4);
	((void) 0);
	return p;
}

static void auxsort(lua_State *L, IdxT lo, IdxT up, unsigned int rnd)
{
	while (lo < up)
	{
		IdxT p;
		IdxT n;

		lua_geti(L, 1, lo);
		lua_geti(L, 1, up);
		if (sort_comp(L, -1, -2))
			set2(L, lo, up);
		else
			lua_settop(L, -(2) - 1);
		if (up - lo == 1)
			return;
		if (up - lo < 100u || rnd == 0)
			p = (lo + up) / 2;
		else
			p = choosePivot(lo, up, rnd);
		lua_geti(L, 1, p);
		lua_geti(L, 1, lo);
		if (sort_comp(L, -2, -1))
			set2(L, p, lo);
		else
		{
			lua_settop(L, -(1) - 1);
			lua_geti(L, 1, up);
			if (sort_comp(L, -1, -2))
				set2(L, p, up);
			else
				lua_settop(L, -(2) - 1);
		}
		if (up - lo == 2)
			return;
		lua_geti(L, 1, p);
		lua_pushvalue(L, -1);
		lua_geti(L, 1, up - 1);
		set2(L, p, up - 1);
		p = partition(L, lo, up);

		if (p - lo < up - p)
		{
			auxsort(L, lo, p - 1, rnd);
			n = p - lo;
			lo = p + 1;
		}
		else
		{
			auxsort(L, p + 1, up, rnd);
			n = up - p;
			up = p - 1;
		}
		if ((up - lo) / 128 > n)
			rnd = l_randomizePivot();
	}
}

static int sort(lua_State *L)
{
	lua_Integer n = (checktab(L, 1, ((1 | 2)) | 4), luaL_len(L, 1));
	if (n > 1)
	{
		((void) ((n < INT_MAX) || luaL_argerror(L, (1), ("array too big"))));
		if (!(lua_type(L, (2)) <= 0))
			luaL_checktype(L, 2, 6);
		lua_settop(L, 2);
		auxsort(L, 1, (IdxT) n, 0);
	}
	return 0;
}

static const luaL_Reg tab_funcs[] = {{"concat", tconcat}, {"insert", tinsert}, {"pack", tpack},
									 {"unpack", tunpack}, {"remove", tremove}, {"move", tmove},
									 {"sort", sort},	  {NULL, NULL}};

extern int luaopen_table(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(tab_funcs) / sizeof((tab_funcs)[0]) - 1),
	 luaL_setfuncs(L, tab_funcs, 0));
	return 1;
}
