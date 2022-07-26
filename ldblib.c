

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

static const char *const HOOKKEY = "_HOOKKEY";

static void checkstack(lua_State *L, lua_State *L1, int n)
{
	if (L != L1 && !lua_checkstack(L1, n))
		luaL_error(L, "stack overflow");
}

static int db_getregistry(lua_State *L)
{
	lua_pushvalue(L, (-15000 - 1000));
	return 1;
}

static int db_getmetatable(lua_State *L)
{
	luaL_checkany(L, 1);
	if (!lua_getmetatable(L, 1))
	{
		lua_pushnil(L);
	}
	return 1;
}

static int db_setmetatable(lua_State *L)
{
	int t = lua_type(L, 2);
	((void) ((t == 0 || t == 5) || luaL_typeerror(L, (2), ("nil or table"))));
	lua_settop(L, 2);
	lua_setmetatable(L, 1);
	return 1;
}

static int db_getuservalue(lua_State *L)
{
	int n = (int) luaL_optinteger(L, 2, 1);
	if (lua_type(L, 1) != 7)
		lua_pushnil(L);
	else if (lua_getiuservalue(L, 1, n) != (-1))
	{
		lua_pushboolean(L, 1);
		return 2;
	}
	return 1;
}

static int db_setuservalue(lua_State *L)
{
	int n = (int) luaL_optinteger(L, 3, 1);
	luaL_checktype(L, 1, 7);
	luaL_checkany(L, 2);
	lua_settop(L, 2);
	if (!lua_setiuservalue(L, 1, n))
		lua_pushnil(L);
	return 1;
}
static lua_State *getthread(lua_State *L, int *arg)
{
	if ((lua_type(L, (1)) == 8))
	{
		*arg = 1;
		return lua_tothread(L, 1);
	}
	else
	{
		*arg = 0;
		return L;
	}
}

static void settabss(lua_State *L, const char *k, const char *v)
{
	lua_pushstring(L, v);
	lua_setfield(L, -2, k);
}

static void settabsi(lua_State *L, const char *k, int v)
{
	lua_pushinteger(L, v);
	lua_setfield(L, -2, k);
}

static void settabsb(lua_State *L, const char *k, int v)
{
	lua_pushboolean(L, v);
	lua_setfield(L, -2, k);
}
static void treatstackoption(lua_State *L, lua_State *L1, const char *fname)
{
	if (L == L1)
		lua_rotate(L, -2, 1);
	else
		lua_xmove(L1, L, 1);
	lua_setfield(L, -2, fname);
}
static int db_getinfo(lua_State *L)
{
	lua_Debug ar;
	int arg;
	lua_State *L1 = getthread(L, &arg);
	const char *options = (luaL_optlstring(L, (arg + 2), ("flnSrtu"), NULL));
	checkstack(L, L1, 3);
	if ((lua_type(L, (arg + 1)) == 6))
	{
		options = lua_pushfstring(L, ">%s", options);
		lua_pushvalue(L, arg + 1);
		lua_xmove(L, L1, 1);
	}
	else
	{
		if (!lua_getstack(L1, (int) luaL_checkinteger(L, arg + 1), &ar))
		{
			lua_pushnil(L);
			return 1;
		}
	}
	if (!lua_getinfo(L1, options, &ar))
		return luaL_argerror(L, arg + 2, "invalid option");
	lua_createtable(L, 0, 0);
	if (strchr(options, 'S'))
	{
		lua_pushlstring(L, ar.source, ar.srclen);
		lua_setfield(L, -2, "source");
		settabss(L, "short_src", ar.short_src);
		settabsi(L, "linedefined", ar.linedefined);
		settabsi(L, "lastlinedefined", ar.lastlinedefined);
		settabss(L, "what", ar.what);
	}
	if (strchr(options, 'l'))
		settabsi(L, "currentline", ar.currentline);
	if (strchr(options, 'u'))
	{
		settabsi(L, "nups", ar.nups);
		settabsi(L, "nparams", ar.nparams);
		settabsb(L, "isvararg", ar.isvararg);
	}
	if (strchr(options, 'n'))
	{
		settabss(L, "name", ar.name);
		settabss(L, "namewhat", ar.namewhat);
	}
	if (strchr(options, 'r'))
	{
		settabsi(L, "ftransfer", ar.ftransfer);
		settabsi(L, "ntransfer", ar.ntransfer);
	}
	if (strchr(options, 't'))
		settabsb(L, "istailcall", ar.istailcall);
	if (strchr(options, 'L'))
		treatstackoption(L, L1, "activelines");
	if (strchr(options, 'f'))
		treatstackoption(L, L1, "func");
	return 1;
}

static int db_getlocal(lua_State *L)
{
	int arg;
	lua_State *L1 = getthread(L, &arg);
	int nvar = (int) luaL_checkinteger(L, arg + 2);
	if ((lua_type(L, (arg + 1)) == 6))
	{
		lua_pushvalue(L, arg + 1);
		lua_pushstring(L, lua_getlocal(L, NULL, nvar));
		return 1;
	}
	else
	{
		lua_Debug ar;
		const char *name;
		int level = (int) luaL_checkinteger(L, arg + 1);
		if (!lua_getstack(L1, level, &ar))
			return luaL_argerror(L, arg + 1, "level out of range");
		checkstack(L, L1, 1);
		name = lua_getlocal(L1, &ar, nvar);
		if (name)
		{
			lua_xmove(L1, L, 1);
			lua_pushstring(L, name);
			lua_rotate(L, -2, 1);
			return 2;
		}
		else
		{
			lua_pushnil(L);
			return 1;
		}
	}
}

static int db_setlocal(lua_State *L)
{
	int arg;
	const char *name;
	lua_State *L1 = getthread(L, &arg);
	lua_Debug ar;
	int level = (int) luaL_checkinteger(L, arg + 1);
	int nvar = (int) luaL_checkinteger(L, arg + 2);
	if (!lua_getstack(L1, level, &ar))
		return luaL_argerror(L, arg + 1, "level out of range");
	luaL_checkany(L, arg + 3);
	lua_settop(L, arg + 3);
	checkstack(L, L1, 1);
	lua_xmove(L, L1, 1);
	name = lua_setlocal(L1, &ar, nvar);
	if (name == NULL)
		lua_settop(L1, -(1) - 1);
	lua_pushstring(L, name);
	return 1;
}

static int auxupvalue(lua_State *L, int get)
{
	const char *name;
	int n = (int) luaL_checkinteger(L, 2);
	luaL_checktype(L, 1, 6);
	name = get ? lua_getupvalue(L, 1, n) : lua_setupvalue(L, 1, n);
	if (name == NULL)
		return 0;
	lua_pushstring(L, name);
	lua_rotate(L, (-(get + 1)), 1);
	return get + 1;
}

static int db_getupvalue(lua_State *L)
{
	return auxupvalue(L, 1);
}

static int db_setupvalue(lua_State *L)
{
	luaL_checkany(L, 3);
	return auxupvalue(L, 0);
}

static void *checkupval(lua_State *L, int argf, int argnup, int *pnup)
{
	void *id;
	int nup = (int) luaL_checkinteger(L, argnup);
	luaL_checktype(L, argf, 6);
	id = lua_upvalueid(L, argf, nup);
	if (pnup)
	{
		((void) ((id != NULL) || luaL_argerror(L, (argnup), ("invalid upvalue index"))));
		*pnup = nup;
	}
	return id;
}

static int db_upvalueid(lua_State *L)
{
	void *id = checkupval(L, 1, 2, NULL);
	if (id != NULL)
		lua_pushlightuserdata(L, id);
	else
		lua_pushnil(L);
	return 1;
}

static int db_upvaluejoin(lua_State *L)
{
	int n1, n2;
	checkupval(L, 1, 2, &n1);
	checkupval(L, 3, 4, &n2);
	((void) ((!lua_iscfunction(L, 1)) || luaL_argerror(L, (1), ("Lua function expected"))));
	((void) ((!lua_iscfunction(L, 3)) || luaL_argerror(L, (3), ("Lua function expected"))));
	lua_upvaluejoin(L, 1, n1, 3, n2);
	return 0;
}

static void hookf(lua_State *L, lua_Debug *ar)
{
	static const char *const hooknames[] = {"call", "return", "line", "count", "tail call"};
	lua_getfield(L, (-15000 - 1000), HOOKKEY);
	lua_pushthread(L);
	if (lua_rawget(L, -2) == 6)
	{
		lua_pushstring(L, hooknames[(int) ar->event]);
		if (ar->currentline >= 0)
			lua_pushinteger(L, ar->currentline);
		else
			lua_pushnil(L);
		((void) 0);
		lua_callk(L, (2), (0), 0, NULL);
	}
}

static int makemask(const char *smask, int count)
{
	int mask = 0;
	if (strchr(smask, 'c'))
		mask |= (1 << 0);
	if (strchr(smask, 'r'))
		mask |= (1 << 1);
	if (strchr(smask, 'l'))
		mask |= (1 << 2);
	if (count > 0)
		mask |= (1 << 3);
	return mask;
}

static char *unmakemask(int mask, char *smask)
{
	int i = 0;
	if (mask & (1 << 0))
		smask[i++] = 'c';
	if (mask & (1 << 1))
		smask[i++] = 'r';
	if (mask & (1 << 2))
		smask[i++] = 'l';
	smask[i] = '\0';
	return smask;
}

static int db_sethook(lua_State *L)
{
	int arg, mask, count;
	lua_Hook func;
	lua_State *L1 = getthread(L, &arg);
	if ((lua_type(L, (arg + 1)) <= 0))
	{
		lua_settop(L, arg + 1);
		func = NULL;
		mask = 0;
		count = 0;
	}
	else
	{
		const char *smask = (luaL_checklstring(L, (arg + 2), NULL));
		luaL_checktype(L, arg + 1, 6);
		count = (int) luaL_optinteger(L, arg + 3, 0);
		func = hookf;
		mask = makemask(smask, count);
	}
	if (!luaL_getsubtable(L, (-15000 - 1000), HOOKKEY))
	{

		lua_pushstring(L, "k");
		lua_setfield(L, -2, "__mode");
		lua_pushvalue(L, -1);
		lua_setmetatable(L, -2);
	}
	checkstack(L, L1, 1);
	lua_pushthread(L1);
	lua_xmove(L1, L, 1);
	lua_pushvalue(L, arg + 1);
	lua_rawset(L, -3);
	lua_sethook(L1, func, mask, count);
	return 0;
}

static int db_gethook(lua_State *L)
{
	int arg;
	lua_State *L1 = getthread(L, &arg);
	char buff[5];
	int mask = lua_gethookmask(L1);
	lua_Hook hook = lua_gethook(L1);
	if (hook == NULL)
	{
		lua_pushnil(L);
		return 1;
	}
	else if (hook != hookf)
		lua_pushstring(L, ""
						  "external hook");
	else
	{
		lua_getfield(L, (-15000 - 1000), HOOKKEY);
		checkstack(L, L1, 1);
		lua_pushthread(L1);
		lua_xmove(L1, L, 1);
		lua_rawget(L, -2);
		(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
	}
	lua_pushstring(L, unmakemask(mask, buff));
	lua_pushinteger(L, lua_gethookcount(L1));
	return 3;
}

static int db_debug(lua_State *L)
{
	for (;;)
	{
		char buffer[250];
		(fprintf(stderr, ("%s"), ("lua_debug> ")), fflush(stderr));
		if (fgets(buffer, sizeof(buffer), stdin) == 0 || strcmp(buffer, "cont\n") == 0)
			return 0;
		if (luaL_loadbufferx(L, buffer, strlen(buffer), "=(debug command)", NULL) ||
			lua_pcallk(L, (0), (0), (0), 0, NULL))
			(fprintf(stderr, ("%s\n"), (luaL_tolstring(L, -1, NULL))), fflush(stderr));
		lua_settop(L, 0);
	}
}

static int db_traceback(lua_State *L)
{
	int arg;
	lua_State *L1 = getthread(L, &arg);
	const char *msg = lua_tolstring(L, (arg + 1), NULL);
	if (msg == NULL && !(lua_type(L, (arg + 1)) <= 0))
		lua_pushvalue(L, arg + 1);
	else
	{
		int level = (int) luaL_optinteger(L, arg + 2, (L == L1) ? 1 : 0);
		luaL_traceback(L, L1, msg, level);
	}
	return 1;
}

static int db_setcstacklimit(lua_State *L)
{
	int limit = (int) luaL_checkinteger(L, 1);
	int res = lua_setcstacklimit(L, limit);
	lua_pushinteger(L, res);
	return 1;
}

static const luaL_Reg dblib[] = {{"debug", db_debug},
								 {"getuservalue", db_getuservalue},
								 {"gethook", db_gethook},
								 {"getinfo", db_getinfo},
								 {"getlocal", db_getlocal},
								 {"getregistry", db_getregistry},
								 {"getmetatable", db_getmetatable},
								 {"getupvalue", db_getupvalue},
								 {"upvaluejoin", db_upvaluejoin},
								 {"upvalueid", db_upvalueid},
								 {"setuservalue", db_setuservalue},
								 {"sethook", db_sethook},
								 {"setlocal", db_setlocal},
								 {"setmetatable", db_setmetatable},
								 {"setupvalue", db_setupvalue},
								 {"traceback", db_traceback},
								 {"setcstacklimit", db_setcstacklimit},
								 {NULL, NULL}};

extern int luaopen_debug(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(dblib) / sizeof((dblib)[0]) - 1), luaL_setfuncs(L, dblib, 0));
	return 1;
}
