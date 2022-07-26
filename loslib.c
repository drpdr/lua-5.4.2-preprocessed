

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
static int os_execute(lua_State *L)
{
	const char *cmd = (luaL_optlstring(L, (1), (NULL), NULL));
	int stat;
	errno = 0;
	stat = system(cmd);
	if (cmd != NULL)
		return luaL_execresult(L, stat);
	else
	{
		lua_pushboolean(L, stat);
		return 1;
	}
}

static int os_remove(lua_State *L)
{
	const char *filename = (luaL_checklstring(L, (1), NULL));
	return luaL_fileresult(L, remove(filename) == 0, filename);
}

static int os_rename(lua_State *L)
{
	const char *fromname = (luaL_checklstring(L, (1), NULL));
	const char *toname = (luaL_checklstring(L, (2), NULL));
	return luaL_fileresult(L, rename(fromname, toname) == 0, NULL);
}

static int os_tmpname(lua_State *L)
{
	char buff[L_tmpnam];
	int err;
	{
		err = (tmpnam(buff) == NULL);
	};
	if (err)
		return luaL_error(L, "unable to generate a unique filename");
	lua_pushstring(L, buff);
	return 1;
}

static int os_getenv(lua_State *L)
{
	lua_pushstring(L, getenv((luaL_checklstring(L, (1), NULL))));
	return 1;
}

static int os_clock(lua_State *L)
{
	lua_pushnumber(L, ((lua_Number) clock()) / (lua_Number) CLOCKS_PER_SEC);
	return 1;
}
static void setfield(lua_State *L, const char *key, int value, int delta)
{

	lua_pushinteger(L, (lua_Integer) value + delta);
	lua_setfield(L, -2, key);
}

static void setboolfield(lua_State *L, const char *key, int value)
{
	if (value < 0)
		return;
	lua_pushboolean(L, value);
	lua_setfield(L, -2, key);
}

static void setallfields(lua_State *L, struct tm *stm)
{
	setfield(L, "year", stm->tm_year, 1900);
	setfield(L, "month", stm->tm_mon, 1);
	setfield(L, "day", stm->tm_mday, 0);
	setfield(L, "hour", stm->tm_hour, 0);
	setfield(L, "min", stm->tm_min, 0);
	setfield(L, "sec", stm->tm_sec, 0);
	setfield(L, "yday", stm->tm_yday, 1);
	setfield(L, "wday", stm->tm_wday, 1);
	setboolfield(L, "isdst", stm->tm_isdst);
}

static int getboolfield(lua_State *L, const char *key)
{
	int res;
	res = (lua_getfield(L, -1, key) == 0) ? -1 : lua_toboolean(L, -1);
	lua_settop(L, -(1) - 1);
	return res;
}

static int getfield(lua_State *L, const char *key, int d, int delta)
{
	int isnum;
	int t = lua_getfield(L, -1, key);
	lua_Integer res = lua_tointegerx(L, -1, &isnum);
	if (!isnum)
	{
		if (t != 0)
			return luaL_error(L, "field '%s' is not an integer", key);
		else if (d < 0)
			return luaL_error(L, "field '%s' missing in date table", key);
		res = d;
	}
	else
	{

		if (!(res >= 0 ? (lua_Unsigned) res <= (lua_Unsigned) INT_MAX + delta
					   : (lua_Integer) INT_MIN + delta <= res))
			return luaL_error(L, "field '%s' is out-of-bound", key);
		res -= delta;
	}
	lua_settop(L, -(1) - 1);
	return (int) res;
}

static const char *checkoption(lua_State *L, const char *conv, ptrdiff_t convlen, char *buff)
{
	const char *option = "aAbBcCdDeFgGhHIjmMnprRStTuUVwWxXyYzZ%"
						 "||"
						 "EcECExEXEyEY"
						 "OdOeOHOIOmOMOSOuOUOVOwOWOy";
	int oplen = 1;
	for (; *option != '\0' && oplen <= convlen; option += oplen)
	{
		if (*option == '|')
			oplen++;
		else if (memcmp(conv, option, oplen) == 0)
		{
			memcpy(buff, conv, oplen);
			buff[oplen] = '\0';
			return conv + oplen;
		}
	}
	luaL_argerror(L, 1, lua_pushfstring(L, "invalid conversion specifier '%%%s'", conv));
	return conv;
}

static time_t l_checktime(lua_State *L, int arg)
{
	lua_Integer t = luaL_checkinteger(L, arg);
	((void) (((time_t) t == t) || luaL_argerror(L, (arg), ("time out-of-bounds"))));
	return (time_t) t;
}

static int os_date(lua_State *L)
{
	size_t slen;
	const char *s = luaL_optlstring(L, 1, "%c", &slen);
	time_t t = ((lua_type(L, ((2))) <= 0) ? (time(NULL)) : l_checktime(L, (2)));
	const char *se = s + slen;
	struct tm tmr, *stm;
	if (*s == '!')
	{
		stm = ((void) (&tmr)->tm_sec, gmtime(&t));
		s++;
	}
	else
		stm = ((void) (&tmr)->tm_sec, localtime(&t));
	if (stm == NULL)
		return luaL_error(L, "date result cannot be represented in this installation");
	if (strcmp(s, "*t") == 0)
	{
		lua_createtable(L, 0, 9);
		setallfields(L, stm);
	}
	else
	{
		char cc[4];
		luaL_Buffer b;
		cc[0] = '%';
		luaL_buffinit(L, &b);
		while (s < se)
		{
			if (*s != '%')
				((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
				 ((&b)->b[(&b)->n++] = (*s++)));
			else
			{
				size_t reslen;
				char *buff = luaL_prepbuffsize(&b, 250);
				s++;
				s = checkoption(L, s, se - s, cc + 1);
				reslen = strftime(buff, 250, cc, stm);
				((&b)->n += (reslen));
			}
		}
		luaL_pushresult(&b);
	}
	return 1;
}

static int os_time(lua_State *L)
{
	time_t t;
	if ((lua_type(L, (1)) <= 0))
		t = time(NULL);
	else
	{
		struct tm ts;
		luaL_checktype(L, 1, 5);
		lua_settop(L, 1);
		ts.tm_year = getfield(L, "year", -1, 1900);
		ts.tm_mon = getfield(L, "month", -1, 1);
		ts.tm_mday = getfield(L, "day", -1, 0);
		ts.tm_hour = getfield(L, "hour", 12, 0);
		ts.tm_min = getfield(L, "min", 0, 0);
		ts.tm_sec = getfield(L, "sec", 0, 0);
		ts.tm_isdst = getboolfield(L, "isdst");
		t = mktime(&ts);
		setallfields(L, &ts);
	}
	if (t != (time_t) (lua_Integer) t || t == (time_t) (-1))
		return luaL_error(L, "time result cannot be represented in this installation");
	lua_pushinteger(L, (lua_Integer) (t));
	return 1;
}

static int os_difftime(lua_State *L)
{
	time_t t1 = l_checktime(L, 1);
	time_t t2 = l_checktime(L, 2);
	lua_pushnumber(L, (lua_Number) difftime(t1, t2));
	return 1;
}

static int os_setlocale(lua_State *L)
{
	static const int cat[] = {LC_ALL, LC_COLLATE, LC_CTYPE, LC_MONETARY, LC_NUMERIC, LC_TIME};
	static const char *const catnames[] = {"all",	  "collate", "ctype", "monetary",
										   "numeric", "time",	 NULL};
	const char *l = (luaL_optlstring(L, (1), (NULL), NULL));
	int op = luaL_checkoption(L, 2, "all", catnames);
	lua_pushstring(L, setlocale(cat[op], l));
	return 1;
}

static int os_exit(lua_State *L)
{
	int status;
	if ((lua_type(L, (1)) == 1))
		status = (lua_toboolean(L, 1) ? EXIT_SUCCESS : EXIT_FAILURE);
	else
		status = (int) luaL_optinteger(L, 1, EXIT_SUCCESS);
	if (lua_toboolean(L, 2))
		lua_close(L);
	if (L)
		exit(status);
	return 0;
}

static const luaL_Reg syslib[] = {
	{"clock", os_clock},	 {"date", os_date},		  {"difftime", os_difftime},
	{"execute", os_execute}, {"exit", os_exit},		  {"getenv", os_getenv},
	{"remove", os_remove},	 {"rename", os_rename},	  {"setlocale", os_setlocale},
	{"time", os_time},		 {"tmpname", os_tmpname}, {NULL, NULL}};

extern int luaopen_os(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(syslib) / sizeof((syslib)[0]) - 1), luaL_setfuncs(L, syslib, 0));
	return 1;
}
