

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
static const char *const CLIBS = "_CLIBS";
typedef void (*voidf)(void);
static void lsys_unloadlib(void *lib);

static void *lsys_load(lua_State *L, const char *path, int seeglb);

static lua_CFunction lsys_sym(lua_State *L, void *lib, const char *sym);
static void lsys_unloadlib(void *lib)
{
	(void) (lib);
}

static void *lsys_load(lua_State *L, const char *path, int seeglb)
{
	(void) (path);
	(void) (seeglb);
	lua_pushstring(L, ""
					  "dynamic libraries not enabled; check your Lua installation");
	return NULL;
}

static lua_CFunction lsys_sym(lua_State *L, void *lib, const char *sym)
{
	(void) (lib);
	(void) (sym);
	lua_pushstring(L, ""
					  "dynamic libraries not enabled; check your Lua installation");
	return NULL;
}
static int noenv(lua_State *L)
{
	int b;
	lua_getfield(L, (-15000 - 1000), "LUA_NOENV");
	b = lua_toboolean(L, -1);
	lua_settop(L, -(1) - 1);
	return b;
}

static void setpath(lua_State *L, const char *fieldname, const char *envname, const char *dft)
{
	const char *dftmark;
	const char *nver = lua_pushfstring(L, "%s%s", envname,
									   "_"
									   "5"
									   "_"
									   "4");
	const char *path = getenv(nver);
	if (path == NULL)
		path = getenv(envname);
	if (path == NULL || noenv(L))
		lua_pushstring(L, dft);
	else if ((dftmark = strstr(path, ";"
									 ";")) == NULL)
		lua_pushstring(L, path);
	else
	{
		size_t len = strlen(path);
		luaL_Buffer b;
		luaL_buffinit(L, &b);
		if (path < dftmark)
		{
			luaL_addlstring(&b, path, dftmark - path);
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (*";")));
		}
		luaL_addstring(&b, dft);
		if (dftmark < path + len - 2)
		{
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (*";")));
			luaL_addlstring(&b, dftmark + 2, (path + len - 2) - dftmark);
		}
		luaL_pushresult(&b);
	}
	((void) 0);
	lua_setfield(L, -3, fieldname);
	lua_settop(L, -(1) - 1);
}

static void *checkclib(lua_State *L, const char *path)
{
	void *plib;
	lua_getfield(L, (-15000 - 1000), CLIBS);
	lua_getfield(L, -1, path);
	plib = lua_touserdata(L, -1);
	lua_settop(L, -(2) - 1);
	return plib;
}

static void addtoclib(lua_State *L, const char *path, void *plib)
{
	lua_getfield(L, (-15000 - 1000), CLIBS);
	lua_pushlightuserdata(L, plib);
	lua_pushvalue(L, -1);
	lua_setfield(L, -3, path);
	lua_rawseti(L, -2, luaL_len(L, -2) + 1);
	lua_settop(L, -(1) - 1);
}

static int gctm(lua_State *L)
{
	lua_Integer n = luaL_len(L, 1);
	for (; n >= 1; n--)
	{
		lua_rawgeti(L, 1, n);
		lsys_unloadlib(lua_touserdata(L, -1));
		lua_settop(L, -(1) - 1);
	}
	return 0;
}
static int lookforfunc(lua_State *L, const char *path, const char *sym)
{
	void *reg = checkclib(L, path);
	if (reg == NULL)
	{
		reg = lsys_load(L, path, *sym == '*');
		if (reg == NULL)
			return 1;
		addtoclib(L, path, reg);
	}
	if (*sym == '*')
	{
		lua_pushboolean(L, 1);
		return 0;
	}
	else
	{
		lua_CFunction f = lsys_sym(L, reg, sym);
		if (f == NULL)
			return 2;
		lua_pushcclosure(L, (f), 0);
		return 0;
	}
}

static int ll_loadlib(lua_State *L)
{
	const char *path = (luaL_checklstring(L, (1), NULL));
	const char *init = (luaL_checklstring(L, (2), NULL));
	int stat = lookforfunc(L, path, init);
	if (stat == 0)
		return 1;
	else
	{
		lua_pushnil(L);
		lua_rotate(L, (-2), 1);
		lua_pushstring(L, (stat == 1) ? "absent" : "init");
		return 3;
	}
}
static int readable(const char *filename)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
		return 0;
	fclose(f);
	return 1;
}

static const char *getnextfilename(char **path, char *end)
{
	char *sep;
	char *name = *path;
	if (name == end)
		return NULL;
	else if (*name == '\0')
	{
		*name = *";";
		name++;
	}
	sep = strchr(name, *";");
	if (sep == NULL)
		sep = end;
	*sep = '\0';
	*path = sep;
	return name;
}
static void pusherrornotfound(lua_State *L, const char *path)
{
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	luaL_addstring(&b, "no file '");
	luaL_addgsub(&b, path, ";", "'\n\tno file '");
	luaL_addstring(&b, "'");
	luaL_pushresult(&b);
}

static const char *searchpath(lua_State *L, const char *name, const char *path, const char *sep,
							  const char *dirsep)
{
	luaL_Buffer buff;
	char *pathname;
	char *endpathname;
	const char *filename;

	if (*sep != '\0' && strchr(name, *sep) != NULL)
		name = luaL_gsub(L, name, sep, dirsep);
	luaL_buffinit(L, &buff);

	luaL_addgsub(&buff, path, "?", name);
	((void) ((&buff)->n < (&buff)->size || luaL_prepbuffsize((&buff), 1)),
	 ((&buff)->b[(&buff)->n++] = ('\0')));
	pathname = ((&buff)->b);
	endpathname = pathname + ((&buff)->n) - 1;
	while ((filename = getnextfilename(&pathname, endpathname)) != NULL)
	{
		if (readable(filename))
			return lua_pushstring(L, filename);
	}
	luaL_pushresult(&buff);
	pusherrornotfound(L, lua_tolstring(L, (-1), NULL));
	return NULL;
}

static int ll_searchpath(lua_State *L)
{
	const char *f =
		searchpath(L, (luaL_checklstring(L, (1), NULL)), (luaL_checklstring(L, (2), NULL)),
				   (luaL_optlstring(L, (3), ("."), NULL)), (luaL_optlstring(L, (4), ("/"), NULL)));
	if (f != NULL)
		return 1;
	else
	{
		lua_pushnil(L);
		lua_rotate(L, (-2), 1);
		return 2;
	}
}

static const char *findfile(lua_State *L, const char *name, const char *pname, const char *dirsep)
{
	const char *path;
	lua_getfield(L, ((-15000 - 1000) - (1)), pname);
	path = lua_tolstring(L, (-1), NULL);
	if (path == NULL)
		luaL_error(L, "'package.%s' must be a string", pname);
	return searchpath(L, name, path, ".", dirsep);
}

static int checkload(lua_State *L, int stat, const char *filename)
{
	if (stat)
	{
		lua_pushstring(L, filename);
		return 2;
	}
	else
		return luaL_error(L, "error loading module '%s' from file '%s':\n\t%s",
						  lua_tolstring(L, (1), NULL), filename, lua_tolstring(L, (-1), NULL));
}

static int searcher_Lua(lua_State *L)
{
	const char *filename;
	const char *name = (luaL_checklstring(L, (1), NULL));
	filename = findfile(L, name, "path", "/");
	if (filename == NULL)
		return 1;
	return checkload(L, (luaL_loadfilex(L, filename, NULL) == 0), filename);
}
static int loadfunc(lua_State *L, const char *filename, const char *modname)
{
	const char *openfunc;
	const char *mark;
	modname = luaL_gsub(L, modname, ".", "_");
	mark = strchr(modname, *"-");
	if (mark)
	{
		int stat;
		openfunc = lua_pushlstring(L, modname, mark - modname);
		openfunc = lua_pushfstring(L,
								   "luaopen_"
								   "%s",
								   openfunc);
		stat = lookforfunc(L, filename, openfunc);
		if (stat != 2)
			return stat;
		modname = mark + 1;
	}
	openfunc = lua_pushfstring(L,
							   "luaopen_"
							   "%s",
							   modname);
	return lookforfunc(L, filename, openfunc);
}

static int searcher_C(lua_State *L)
{
	const char *name = (luaL_checklstring(L, (1), NULL));
	const char *filename = findfile(L, name, "cpath", "/");
	if (filename == NULL)
		return 1;
	return checkload(L, (loadfunc(L, filename, name) == 0), filename);
}

static int searcher_Croot(lua_State *L)
{
	const char *filename;
	const char *name = (luaL_checklstring(L, (1), NULL));
	const char *p = strchr(name, '.');
	int stat;
	if (p == NULL)
		return 0;
	lua_pushlstring(L, name, p - name);
	filename = findfile(L, lua_tolstring(L, (-1), NULL), "cpath", "/");
	if (filename == NULL)
		return 1;
	if ((stat = loadfunc(L, filename, name)) != 0)
	{
		if (stat != 2)
			return checkload(L, 0, filename);
		else
		{
			lua_pushfstring(L, "no module '%s' in file '%s'", name, filename);
			return 1;
		}
	}
	lua_pushstring(L, filename);
	return 2;
}

static int searcher_preload(lua_State *L)
{
	const char *name = (luaL_checklstring(L, (1), NULL));
	lua_getfield(L, (-15000 - 1000), "_PRELOAD");
	if (lua_getfield(L, -1, name) == 0)
	{
		lua_pushfstring(L, "no field package.preload['%s']", name);
		return 1;
	}
	else
	{
		lua_pushstring(L, ""
						  ":preload:");
		return 2;
	}
}

static void findloader(lua_State *L, const char *name)
{
	int i;
	luaL_Buffer msg;

	if (lua_getfield(L, ((-15000 - 1000) - (1)), "searchers") != 5)
		luaL_error(L, "'package.searchers' must be a table");
	luaL_buffinit(L, &msg);

	for (i = 1;; i++)
	{
		luaL_addstring(&msg, "\n\t");
		if (lua_rawgeti(L, 3, i) == 0)
		{
			lua_settop(L, -(1) - 1);
			((&msg)->n -= (2));
			luaL_pushresult(&msg);
			luaL_error(L, "module '%s' not found:%s", name, lua_tolstring(L, (-1), NULL));
		}
		lua_pushstring(L, name);
		lua_callk(L, (1), (2), 0, NULL);
		if ((lua_type(L, (-2)) == 6))
			return;
		else if (lua_isstring(L, -2))
		{
			lua_settop(L, -(1) - 1);
			luaL_addvalue(&msg);
		}
		else
		{
			lua_settop(L, -(2) - 1);
			((&msg)->n -= (2));
		}
	}
}

static int ll_require(lua_State *L)
{
	const char *name = (luaL_checklstring(L, (1), NULL));
	lua_settop(L, 1);
	lua_getfield(L, (-15000 - 1000), "_LOADED");
	lua_getfield(L, 2, name);
	if (lua_toboolean(L, -1))
		return 1;

	lua_settop(L, -(1) - 1);
	findloader(L, name);
	lua_rotate(L, -2, 1);
	lua_pushvalue(L, 1);
	lua_pushvalue(L, -3);

	lua_callk(L, (2), (1), 0, NULL);

	if (!(lua_type(L, (-1)) == 0))
		lua_setfield(L, 2, name);
	else
		lua_settop(L, -(1) - 1);
	if (lua_getfield(L, 2, name) == 0)
	{
		lua_pushboolean(L, 1);
		lua_copy(L, -1, -2);
		lua_setfield(L, 2, name);
	}
	lua_rotate(L, -2, 1);
	return 2;
}

static const luaL_Reg pk_funcs[] = {{"loadlib", ll_loadlib}, {"searchpath", ll_searchpath},

									{"preload", NULL},		 {"cpath", NULL},
									{"path", NULL},			 {"searchers", NULL},
									{"loaded", NULL},		 {NULL, NULL}};

static const luaL_Reg ll_funcs[] = {{"require", ll_require}, {NULL, NULL}};

static void createsearcherstable(lua_State *L)
{
	static const lua_CFunction searchers[] = {searcher_preload, searcher_Lua, searcher_C,
											  searcher_Croot, NULL};
	int i;

	lua_createtable(L, sizeof(searchers) / sizeof(searchers[0]) - 1, 0);

	for (i = 0; searchers[i] != NULL; i++)
	{
		lua_pushvalue(L, -2);
		lua_pushcclosure(L, searchers[i], 1);
		lua_rawseti(L, -2, i + 1);
	}
	lua_setfield(L, -2, "searchers");
}

static void createclibstable(lua_State *L)
{
	luaL_getsubtable(L, (-15000 - 1000), CLIBS);
	lua_createtable(L, 0, 1);
	lua_pushcclosure(L, (gctm), 0);
	lua_setfield(L, -2, "__gc");
	lua_setmetatable(L, -2);
}

extern int luaopen_package(lua_State *L)
{
	createclibstable(L);
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(pk_funcs) / sizeof((pk_funcs)[0]) - 1),
	 luaL_setfuncs(L, pk_funcs, 0));
	createsearcherstable(L);

	setpath(L, "path", "LUA_PATH",
			"/usr/local/"
			"share/lua/"
			"5"
			"."
			"4"
			"/"
			"?.lua;"
			"/usr/local/"
			"share/lua/"
			"5"
			"."
			"4"
			"/"
			"?/init.lua;"
			"/usr/local/"
			"lib/lua/"
			"5"
			"."
			"4"
			"/"
			"?.lua;"
			"/usr/local/"
			"lib/lua/"
			"5"
			"."
			"4"
			"/"
			"?/init.lua;"
			"./?.lua;"
			"./?/init.lua");
	setpath(L, "cpath", "LUA_CPATH",
			"/usr/local/"
			"lib/lua/"
			"5"
			"."
			"4"
			"/"
			"?.so;"
			"/usr/local/"
			"lib/lua/"
			"5"
			"."
			"4"
			"/"
			"loadall.so;"
			"./?.so");

	lua_pushstring(L, ""
					  "/"
					  "\n"
					  ";"
					  "\n"
					  "?"
					  "\n"
					  "!"
					  "\n"
					  "-"
					  "\n");

	lua_setfield(L, -2, "config");

	luaL_getsubtable(L, (-15000 - 1000), "_LOADED");
	lua_setfield(L, -2, "loaded");

	luaL_getsubtable(L, (-15000 - 1000), "_PRELOAD");
	lua_setfield(L, -2, "preload");
	((void) lua_rawgeti(L, (-15000 - 1000), 2));
	lua_pushvalue(L, -2);
	luaL_setfuncs(L, ll_funcs, 1);
	lua_settop(L, -(1) - 1);
	return 1;
}
