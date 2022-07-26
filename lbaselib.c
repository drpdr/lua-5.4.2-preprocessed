

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

static int luaB_print(lua_State *L)
{
	int n = lua_gettop(L);
	int i;
	for (i = 1; i <= n; i++)
	{
		size_t l;
		const char *s = luaL_tolstring(L, i, &l);
		if (i > 1)
			fwrite(("\t"), sizeof(char), (1), stdout);
		fwrite((s), sizeof(char), (l), stdout);
		lua_settop(L, -(1) - 1);
	}
	(fwrite(("\n"), sizeof(char), (1), stdout), fflush(stdout));
	return 0;
}

static int luaB_warn(lua_State *L)
{
	int n = lua_gettop(L);
	int i;
	(luaL_checklstring(L, (1), NULL));
	for (i = 2; i <= n; i++)
		(luaL_checklstring(L, (i), NULL));
	for (i = 1; i < n; i++)
		lua_warning(L, lua_tolstring(L, (i), NULL), 1);
	lua_warning(L, lua_tolstring(L, (n), NULL), 0);
	return 0;
}

static const char *b_str2int(const char *s, int base, lua_Integer *pn)
{
	lua_Unsigned n = 0;
	int neg = 0;
	s += strspn(s, " \f\n\r\t\v");
	if (*s == '-')
	{
		s++;
		neg = 1;
	}
	else if (*s == '+')
		s++;
	if (!isalnum((unsigned char) *s))
		return NULL;
	do
	{
		int digit =
			(isdigit((unsigned char) *s)) ? *s - '0' : (toupper((unsigned char) *s) - 'A') + 10;
		if (digit >= base)
			return NULL;
		n = n * base + digit;
		s++;
	} while (isalnum((unsigned char) *s));
	s += strspn(s, " \f\n\r\t\v");
	*pn = (lua_Integer) ((neg) ? (0u - n) : n);
	return s;
}

static int luaB_tonumber(lua_State *L)
{
	if ((lua_type(L, (2)) <= 0))
	{
		if (lua_type(L, 1) == 3)
		{
			lua_settop(L, 1);
			return 1;
		}
		else
		{
			size_t l;
			const char *s = lua_tolstring(L, 1, &l);
			if (s != NULL && lua_stringtonumber(L, s) == l + 1)
				return 1;

			luaL_checkany(L, 1);
		}
	}
	else
	{
		size_t l;
		const char *s;
		lua_Integer n = 0;
		lua_Integer base = luaL_checkinteger(L, 2);
		luaL_checktype(L, 1, 4);
		s = lua_tolstring(L, 1, &l);
		((void) ((2 <= base && base <= 36) || luaL_argerror(L, (2), ("base out of range"))));
		if (b_str2int(s, (int) base, &n) == s + l)
		{
			lua_pushinteger(L, n);
			return 1;
		}
	}
	lua_pushnil(L);
	return 1;
}

static int luaB_error(lua_State *L)
{
	int level = (int) luaL_optinteger(L, 2, 1);
	lua_settop(L, 1);
	if (lua_type(L, 1) == 4 && level > 0)
	{
		luaL_where(L, level);
		lua_pushvalue(L, 1);
		lua_concat(L, 2);
	}
	return lua_error(L);
}

static int luaB_getmetatable(lua_State *L)
{
	luaL_checkany(L, 1);
	if (!lua_getmetatable(L, 1))
	{
		lua_pushnil(L);
		return 1;
	}
	luaL_getmetafield(L, 1, "__metatable");
	return 1;
}

static int luaB_setmetatable(lua_State *L)
{
	int t = lua_type(L, 2);
	luaL_checktype(L, 1, 5);
	((void) ((t == 0 || t == 5) || luaL_typeerror(L, (2), ("nil or table"))));
	if (luaL_getmetafield(L, 1, "__metatable") != 0)
		return luaL_error(L, "cannot change a protected metatable");
	lua_settop(L, 2);
	lua_setmetatable(L, 1);
	return 1;
}

static int luaB_rawequal(lua_State *L)
{
	luaL_checkany(L, 1);
	luaL_checkany(L, 2);
	lua_pushboolean(L, lua_rawequal(L, 1, 2));
	return 1;
}

static int luaB_rawlen(lua_State *L)
{
	int t = lua_type(L, 1);
	((void) ((t == 5 || t == 4) || luaL_typeerror(L, (1), ("table or string"))));

	lua_pushinteger(L, lua_rawlen(L, 1));
	return 1;
}

static int luaB_rawget(lua_State *L)
{
	luaL_checktype(L, 1, 5);
	luaL_checkany(L, 2);
	lua_settop(L, 2);
	lua_rawget(L, 1);
	return 1;
}

static int luaB_rawset(lua_State *L)
{
	luaL_checktype(L, 1, 5);
	luaL_checkany(L, 2);
	luaL_checkany(L, 3);
	lua_settop(L, 3);
	lua_rawset(L, 1);
	return 1;
}

static int pushmode(lua_State *L, int oldmode)
{
	lua_pushstring(L, (oldmode == 11) ? "incremental" : "generational");
	return 1;
}

static int luaB_collectgarbage(lua_State *L)
{
	static const char *const opts[] = {"stop",		   "restart",	  "collect",	"count",
									   "step",		   "setpause",	  "setstepmul", "isrunning",
									   "generational", "incremental", NULL};
	static const int optsnum[] = {0, 1, 2, 3, 5, 6, 7, 9, 10, 11};
	int o = optsnum[luaL_checkoption(L, 1, "collect", opts)];
	switch (o)
	{
	case 3:
	{
		int k = lua_gc(L, o);
		int b = lua_gc(L, 4);
		lua_pushnumber(L, (lua_Number) k + ((lua_Number) b / 1024));
		return 1;
	}
	case 5:
	{
		int step = (int) luaL_optinteger(L, 2, 0);
		int res = lua_gc(L, o, step);
		lua_pushboolean(L, res);
		return 1;
	}
	case 6:
	case 7:
	{
		int p = (int) luaL_optinteger(L, 2, 0);
		int previous = lua_gc(L, o, p);
		lua_pushinteger(L, previous);
		return 1;
	}
	case 9:
	{
		int res = lua_gc(L, o);
		lua_pushboolean(L, res);
		return 1;
	}
	case 10:
	{
		int minormul = (int) luaL_optinteger(L, 2, 0);
		int majormul = (int) luaL_optinteger(L, 3, 0);
		return pushmode(L, lua_gc(L, o, minormul, majormul));
	}
	case 11:
	{
		int pause = (int) luaL_optinteger(L, 2, 0);
		int stepmul = (int) luaL_optinteger(L, 3, 0);
		int stepsize = (int) luaL_optinteger(L, 4, 0);
		return pushmode(L, lua_gc(L, o, pause, stepmul, stepsize));
	}
	default:
	{
		int res = lua_gc(L, o);
		lua_pushinteger(L, res);
		return 1;
	}
	}
}

static int luaB_type(lua_State *L)
{
	int t = lua_type(L, 1);
	((void) ((t != (-1)) || luaL_argerror(L, (1), ("value expected"))));
	lua_pushstring(L, lua_typename(L, t));
	return 1;
}

static int luaB_next(lua_State *L)
{
	luaL_checktype(L, 1, 5);
	lua_settop(L, 2);
	if (lua_next(L, 1))
		return 2;
	else
	{
		lua_pushnil(L);
		return 1;
	}
}

static int luaB_pairs(lua_State *L)
{
	luaL_checkany(L, 1);
	if (luaL_getmetafield(L, 1, "__pairs") == 0)
	{
		lua_pushcclosure(L, (luaB_next), 0);
		lua_pushvalue(L, 1);
		lua_pushnil(L);
	}
	else
	{
		lua_pushvalue(L, 1);
		lua_callk(L, (1), (3), 0, NULL);
	}
	return 3;
}

static int ipairsaux(lua_State *L)
{
	lua_Integer i = luaL_checkinteger(L, 2) + 1;
	lua_pushinteger(L, i);
	return (lua_geti(L, 1, i) == 0) ? 1 : 2;
}

static int luaB_ipairs(lua_State *L)
{
	luaL_checkany(L, 1);
	lua_pushcclosure(L, (ipairsaux), 0);
	lua_pushvalue(L, 1);
	lua_pushinteger(L, 0);
	return 3;
}

static int load_aux(lua_State *L, int status, int envidx)
{
	if (status == 0)
	{
		if (envidx != 0)
		{
			lua_pushvalue(L, envidx);
			if (!lua_setupvalue(L, -2, 1))
				lua_settop(L, -(1) - 1);
		}
		return 1;
	}
	else
	{
		lua_pushnil(L);
		lua_rotate(L, (-2), 1);
		return 2;
	}
}

static int luaB_loadfile(lua_State *L)
{
	const char *fname = (luaL_optlstring(L, (1), (NULL), NULL));
	const char *mode = (luaL_optlstring(L, (2), (NULL), NULL));
	int env = (!(lua_type(L, (3)) == (-1)) ? 3 : 0);
	int status = luaL_loadfilex(L, fname, mode);
	return load_aux(L, status, env);
}
static const char *generic_reader(lua_State *L, void *ud, size_t *size)
{
	(void) (ud);
	luaL_checkstack(L, 2, "too many nested functions");
	lua_pushvalue(L, 1);
	lua_callk(L, (0), (1), 0, NULL);
	if ((lua_type(L, (-1)) == 0))
	{
		lua_settop(L, -(1) - 1);
		*size = 0;
		return NULL;
	}
	else if (!lua_isstring(L, -1))
		luaL_error(L, "reader function must return a string");
	(lua_copy(L, -1, (5)), lua_settop(L, -(1) - 1));
	return lua_tolstring(L, 5, size);
}

static int luaB_load(lua_State *L)
{
	int status;
	size_t l;
	const char *s = lua_tolstring(L, 1, &l);
	const char *mode = (luaL_optlstring(L, (3), ("bt"), NULL));
	int env = (!(lua_type(L, (4)) == (-1)) ? 4 : 0);
	if (s != NULL)
	{
		const char *chunkname = (luaL_optlstring(L, (2), (s), NULL));
		status = luaL_loadbufferx(L, s, l, chunkname, mode);
	}
	else
	{
		const char *chunkname = (luaL_optlstring(L, (2), ("=(load)"), NULL));
		luaL_checktype(L, 1, 6);
		lua_settop(L, 5);
		status = lua_load(L, generic_reader, NULL, chunkname, mode);
	}
	return load_aux(L, status, env);
}

static int dofilecont(lua_State *L, int d1, lua_KContext d2)
{
	(void) d1;
	(void) d2;
	return lua_gettop(L) - 1;
}

static int luaB_dofile(lua_State *L)
{
	const char *fname = (luaL_optlstring(L, (1), (NULL), NULL));
	lua_settop(L, 1);
	if (luaL_loadfilex(L, fname, NULL) != 0)
		return lua_error(L);
	lua_callk(L, 0, (-1), 0, dofilecont);
	return dofilecont(L, 0, 0);
}

static int luaB_assert(lua_State *L)
{
	if (lua_toboolean(L, 1))
		return lua_gettop(L);
	else
	{
		luaL_checkany(L, 1);
		(lua_rotate(L, (1), -1), lua_settop(L, -(1) - 1));
		lua_pushstring(L, ""
						  "assertion failed!");
		lua_settop(L, 1);
		return luaB_error(L);
	}
}

static int luaB_select(lua_State *L)
{
	int n = lua_gettop(L);
	if (lua_type(L, 1) == 4 && *lua_tolstring(L, (1), NULL) == '#')
	{
		lua_pushinteger(L, n - 1);
		return 1;
	}
	else
	{
		lua_Integer i = luaL_checkinteger(L, 1);
		if (i < 0)
			i = n + i;
		else if (i > n)
			i = n;
		((void) ((1 <= i) || luaL_argerror(L, (1), ("index out of range"))));
		return n - (int) i;
	}
}
static int finishpcall(lua_State *L, int status, lua_KContext extra)
{
	if (status != 0 && status != 1)
	{
		lua_pushboolean(L, 0);
		lua_pushvalue(L, -2);
		return 2;
	}
	else
		return lua_gettop(L) - (int) extra;
}

static int luaB_pcall(lua_State *L)
{
	int status;
	luaL_checkany(L, 1);
	lua_pushboolean(L, 1);
	lua_rotate(L, (1), 1);
	status = lua_pcallk(L, lua_gettop(L) - 2, (-1), 0, 0, finishpcall);
	return finishpcall(L, status, 0);
}

static int luaB_xpcall(lua_State *L)
{
	int status;
	int n = lua_gettop(L);
	luaL_checktype(L, 2, 6);
	lua_pushboolean(L, 1);
	lua_pushvalue(L, 1);
	lua_rotate(L, 3, 2);
	status = lua_pcallk(L, n - 2, (-1), 2, 2, finishpcall);
	return finishpcall(L, status, 2);
}

static int luaB_tostring(lua_State *L)
{
	luaL_checkany(L, 1);
	luaL_tolstring(L, 1, NULL);
	return 1;
}

static const luaL_Reg base_funcs[] = {{"assert", luaB_assert},
									  {"collectgarbage", luaB_collectgarbage},
									  {"dofile", luaB_dofile},
									  {"error", luaB_error},
									  {"getmetatable", luaB_getmetatable},
									  {"ipairs", luaB_ipairs},
									  {"loadfile", luaB_loadfile},
									  {"load", luaB_load},
									  {"next", luaB_next},
									  {"pairs", luaB_pairs},
									  {"pcall", luaB_pcall},
									  {"print", luaB_print},
									  {"warn", luaB_warn},
									  {"rawequal", luaB_rawequal},
									  {"rawlen", luaB_rawlen},
									  {"rawget", luaB_rawget},
									  {"rawset", luaB_rawset},
									  {"select", luaB_select},
									  {"setmetatable", luaB_setmetatable},
									  {"tonumber", luaB_tonumber},
									  {"tostring", luaB_tostring},
									  {"type", luaB_type},
									  {"xpcall", luaB_xpcall},

									  {"_G", NULL},
									  {"_VERSION", NULL},
									  {NULL, NULL}};

extern int luaopen_base(lua_State *L)
{

	((void) lua_rawgeti(L, (-15000 - 1000), 2));
	luaL_setfuncs(L, base_funcs, 0);

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "_G");

	lua_pushstring(L, ""
					  "Lua "
					  "5"
					  "."
					  "4");
	lua_setfield(L, -2, "_VERSION");
	return 1;
}
