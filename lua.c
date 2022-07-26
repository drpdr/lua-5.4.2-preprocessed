

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
static lua_State *globalL = NULL;

static const char *progname = "lua";

static void lstop(lua_State *L, lua_Debug *ar)
{
	(void) ar;
	lua_sethook(L, NULL, 0, 0);
	luaL_error(L, "interrupted!");
}
static void laction(int i)
{
	int flag = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
	signal(i, SIG_DFL);
	lua_sethook(globalL, lstop, flag, 1);
}

static void print_usage(const char *badoption)
{
	(fprintf(stderr, ("%s: "), (progname)), fflush(stderr));
	if (badoption[1] == 'e' || badoption[1] == 'l')
		(fprintf(stderr, ("'%s' needs argument\n"), (badoption)), fflush(stderr));
	else
		(fprintf(stderr, ("unrecognized option '%s'\n"), (badoption)), fflush(stderr));
	(fprintf(stderr,
			 ("usage: %s [options] [script [args]]\n"
			  "Available options are:\n"
			  "  -e stat  execute string 'stat'\n"
			  "  -i       enter interactive mode after executing 'script'\n"
			  "  -l name  require library 'name' into global 'name'\n"
			  "  -v       show version information\n"
			  "  -E       ignore environment variables\n"
			  "  -W       turn warnings on\n"
			  "  --       stop handling options\n"
			  "  -        stop handling options and execute stdin\n"),
			 (progname)),
	 fflush(stderr));
}

static void l_message(const char *pname, const char *msg)
{
	if (pname)
		(fprintf(stderr, ("%s: "), (pname)), fflush(stderr));
	(fprintf(stderr, ("%s\n"), (msg)), fflush(stderr));
}

static int report(lua_State *L, int status)
{
	if (status != 0)
	{
		const char *msg = lua_tolstring(L, (-1), NULL);
		l_message(progname, msg);
		lua_settop(L, -(1) - 1);
	}
	return status;
}

static int msghandler(lua_State *L)
{
	const char *msg = lua_tolstring(L, (1), NULL);
	if (msg == NULL)
	{
		if (luaL_callmeta(L, 1, "__tostring") && lua_type(L, -1) == 4)
			return 1;
		else
			msg = lua_pushfstring(L, "(error object is a %s value)",
								  lua_typename(L, lua_type(L, (1))));
	}
	luaL_traceback(L, L, msg, 1);
	return 1;
}

static int docall(lua_State *L, int narg, int nres)
{
	int status;
	int base = lua_gettop(L) - narg;
	lua_pushcclosure(L, (msghandler), 0);
	lua_rotate(L, (base), 1);
	globalL = L;
	signal(SIGINT, laction);
	status = lua_pcallk(L, (narg), (nres), (base), 0, NULL);
	signal(SIGINT, SIG_DFL);
	(lua_rotate(L, (base), -1), lua_settop(L, -(1) - 1));
	return status;
}

static void print_version(void)
{
	fwrite(("Lua "
			"5"
			"."
			"4"
			"."
			"2"
			"  Copyright (C) 1994-2020 Lua.org, PUC-Rio"),
		   sizeof(char),
		   (strlen("Lua "
				   "5"
				   "."
				   "4"
				   "."
				   "2"
				   "  Copyright (C) 1994-2020 Lua.org, PUC-Rio")),
		   stdout);
	(fwrite(("\n"), sizeof(char), (1), stdout), fflush(stdout));
}
static void createargtable(lua_State *L, char **argv, int argc, int script)
{
	int i, narg;
	if (script == argc)
		script = 0;
	narg = argc - (script + 1);
	lua_createtable(L, narg, script + 1);
	for (i = 0; i < argc; i++)
	{
		lua_pushstring(L, argv[i]);
		lua_rawseti(L, -2, i - script);
	}
	lua_setglobal(L, "arg");
}

static int dochunk(lua_State *L, int status)
{
	if (status == 0)
		status = docall(L, 0, 0);
	return report(L, status);
}

static int dofile(lua_State *L, const char *name)
{
	return dochunk(L, luaL_loadfilex(L, name, NULL));
}

static int dostring(lua_State *L, const char *s, const char *name)
{
	return dochunk(L, luaL_loadbufferx(L, s, strlen(s), name, NULL));
}

static int dolibrary(lua_State *L, const char *name)
{
	int status;
	lua_getglobal(L, "require");
	lua_pushstring(L, name);
	status = docall(L, 1, 1);
	if (status == 0)
		lua_setglobal(L, name);
	return report(L, status);
}

static int pushargs(lua_State *L)
{
	int i, n;
	if (lua_getglobal(L, "arg") != 5)
		luaL_error(L, "'arg' is not a table");
	n = (int) luaL_len(L, -1);
	luaL_checkstack(L, n + 3, "too many arguments to script");
	for (i = 1; i <= n; i++)
		lua_rawgeti(L, -i, i);
	(lua_rotate(L, (-i), -1), lua_settop(L, -(1) - 1));
	return n;
}

static int handle_script(lua_State *L, char **argv)
{
	int status;
	const char *fname = argv[0];
	if (strcmp(fname, "-") == 0 && strcmp(argv[-1], "--") != 0)
		fname = NULL;
	status = luaL_loadfilex(L, fname, NULL);
	if (status == 0)
	{
		int n = pushargs(L);
		status = docall(L, n, (-1));
	}
	return report(L, status);
}
static int collectargs(char **argv, int *first)
{
	int args = 0;
	int i;
	for (i = 1; argv[i] != NULL; i++)
	{
		*first = i;
		if (argv[i][0] != '-')
			return args;
		switch (argv[i][1])
		{
		case '-':
			if (argv[i][2] != '\0')
				return 1;
			*first = i + 1;
			return args;
		case '\0':
			return args;
		case 'E':
			if (argv[i][2] != '\0')
				return 1;
			args |= 16;
			break;
		case 'W':
			if (argv[i][2] != '\0')
				return 1;
			break;
		case 'i':
			args |= 2;
		case 'v':
			if (argv[i][2] != '\0')
				return 1;
			args |= 4;
			break;
		case 'e':
			args |= 8;
		case 'l':
			if (argv[i][2] == '\0')
			{
				i++;
				if (argv[i] == NULL || argv[i][0] == '-')
					return 1;
			}
			break;
		default:
			return 1;
		}
	}
	*first = i;
	return args;
}

static int runargs(lua_State *L, char **argv, int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		int option = argv[i][1];
		((void) 0);
		switch (option)
		{
		case 'e':
		case 'l':
		{
			int status;
			const char *extra = argv[i] + 2;
			if (*extra == '\0')
				extra = argv[++i];
			((void) 0);
			status = (option == 'e') ? dostring(L, extra, "=(command line)") : dolibrary(L, extra);
			if (status != 0)
				return 0;
			break;
		}
		case 'W':
			lua_warning(L, "@on", 0);
			break;
		}
	}
	return 1;
}

static int handle_luainit(lua_State *L)
{
	const char *name = "="
					   "LUA_INIT"
					   "_"
					   "5"
					   "_"
					   "4";
	const char *init = getenv(name + 1);
	if (init == NULL)
	{
		name = "="
			   "LUA_INIT";
		init = getenv(name + 1);
	}
	if (init == NULL)
		return 0;
	else if (init[0] == '@')
		return dofile(L, init + 1);
	else
		return dostring(L, init, name);
}
static const char *get_prompt(lua_State *L, int firstline)
{
	if (lua_getglobal(L, firstline ? "_PROMPT" : "_PROMPT2") == 0)
		return (firstline ? "> " : ">> ");
	else
	{
		const char *p = luaL_tolstring(L, -1, NULL);
		(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
		return p;
	}
}
static int incomplete(lua_State *L, int status)
{
	if (status == 3)
	{
		size_t lmsg;
		const char *msg = lua_tolstring(L, -1, &lmsg);
		if (lmsg >= (sizeof("<eof>") / sizeof(char) - 1) &&
			strcmp(msg + lmsg - (sizeof("<eof>") / sizeof(char) - 1), "<eof>") == 0)
		{
			lua_settop(L, -(1) - 1);
			return 1;
		}
	}
	return 0;
}

static int pushline(lua_State *L, int firstline)
{
	char buffer[512];
	char *b = buffer;
	size_t l;
	const char *prmt = get_prompt(L, firstline);
	int readstatus = ((void) L, fputs(prmt, stdout), fflush(stdout), fgets(b, 512, stdin) != NULL);
	if (readstatus == 0)
		return 0;
	lua_settop(L, -(1) - 1);
	l = strlen(b);
	if (l > 0 && b[l - 1] == '\n')
		b[--l] = '\0';
	if (firstline && b[0] == '=')
		lua_pushfstring(L, "return %s", b + 1);
	else
		lua_pushlstring(L, b, l);
	{
		(void) L;
		(void) b;
	};
	return 1;
}

static int addreturn(lua_State *L)
{
	const char *line = lua_tolstring(L, (-1), NULL);
	const char *retline = lua_pushfstring(L, "return %s;", line);
	int status = luaL_loadbufferx(L, retline, strlen(retline), "=stdin", NULL);
	if (status == 0)
	{
		(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
		if (line[0] != '\0')
		{
			(void) L;
			(void) line;
		};
	}
	else
		lua_settop(L, -(2) - 1);
	return status;
}

static int multiline(lua_State *L)
{
	for (;;)
	{
		size_t len;
		const char *line = lua_tolstring(L, 1, &len);
		int status = luaL_loadbufferx(L, line, len, "=stdin", NULL);
		if (!incomplete(L, status) || !pushline(L, 0))
		{
			{
				(void) L;
				(void) line;
			};
			return status;
		}
		lua_pushstring(L, ""
						  "\n");
		lua_rotate(L, (-2), 1);
		lua_concat(L, 3);
	}
}
static int loadline(lua_State *L)
{
	int status;
	lua_settop(L, 0);
	if (!pushline(L, 1))
		return -1;
	if ((status = addreturn(L)) != 0)
		status = multiline(L);
	(lua_rotate(L, (1), -1), lua_settop(L, -(1) - 1));
	((void) 0);
	return status;
}

static void l_print(lua_State *L)
{
	int n = lua_gettop(L);
	if (n > 0)
	{
		luaL_checkstack(L, 20, "too many results to print");
		lua_getglobal(L, "print");
		lua_rotate(L, (1), 1);
		if (lua_pcallk(L, (n), (0), (0), 0, NULL) != 0)
			l_message(progname, lua_pushfstring(L, "error calling 'print' (%s)",
												lua_tolstring(L, (-1), NULL)));
	}
}

static void doREPL(lua_State *L)
{
	int status;
	const char *oldprogname = progname;
	progname = NULL;
	((void) L);
	while ((status = loadline(L)) != -1)
	{
		if (status == 0)
			status = docall(L, 0, (-1));
		if (status == 0)
			l_print(L);
		else
			report(L, status);
	}
	lua_settop(L, 0);
	(fwrite(("\n"), sizeof(char), (1), stdout), fflush(stdout));
	progname = oldprogname;
}
static int pmain(lua_State *L)
{
	int argc = (int) lua_tointegerx(L, (1), NULL);
	char **argv = (char **) lua_touserdata(L, 2);
	int script;
	int args = collectargs(argv, &script);
	luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number)));
	if (argv[0] && argv[0][0])
		progname = argv[0];
	if (args == 1)
	{
		print_usage(argv[script]);
		return 0;
	}
	if (args & 4)
		print_version();
	if (args & 16)
	{
		lua_pushboolean(L, 1);
		lua_setfield(L, (-15000 - 1000), "LUA_NOENV");
	}
	luaL_openlibs(L);
	createargtable(L, argv, argc, script);
	lua_gc(L, 10, 0, 0);
	if (!(args & 16))
	{
		if (handle_luainit(L) != 0)
			return 0;
	}
	if (!runargs(L, argv, script))
		return 0;
	if (script < argc && handle_script(L, argv + script) != 0)
		return 0;
	if (args & 2)
		doREPL(L);
	else if (script == argc && !(args & (8 | 4)))
	{
		if (1)
		{
			print_version();
			doREPL(L);
		}
		else
			dofile(L, NULL);
	}
	lua_pushboolean(L, 1);
	return 1;
}

int main(int argc, char **argv)
{
	int status, result;
	lua_State *L = luaL_newstate();
	if (L == NULL)
	{
		l_message(argv[0], "cannot create state: not enough memory");
		return EXIT_FAILURE;
	}
	lua_pushcclosure(L, (&pmain), 0);
	lua_pushinteger(L, argc);
	lua_pushlightuserdata(L, argv);
	status = lua_pcallk(L, (2), (1), (0), 0, NULL);
	result = lua_toboolean(L, -1);
	report(L, status);
	lua_close(L);
	return (result && status == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
