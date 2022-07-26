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
static int l_checkmode(const char *mode)
{
	return (*mode != '\0' && strchr("rwa", *(mode++)) != NULL &&
			(*mode != '+' || ((void) (++mode), 1)) && (strspn(mode, "b") == strlen(mode)));
}
typedef luaL_Stream LStream;

static int io_type(lua_State *L)
{
	LStream *p;
	luaL_checkany(L, 1);
	p = (LStream *) luaL_testudata(L, 1, "FILE*");
	if (p == NULL)
		lua_pushnil(L);
	else if (((p)->closef == NULL))
		lua_pushstring(L, ""
						  "closed file");
	else
		lua_pushstring(L, ""
						  "file");
	return 1;
}

static int f_tostring(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	if (((p)->closef == NULL))
		lua_pushstring(L, ""
						  "file (closed)");
	else
		lua_pushfstring(L, "file (%p)", p->f);
	return 1;
}

static FILE *tofile(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	if (((p)->closef == NULL))
		luaL_error(L, "attempt to use a closed file");
	((void) 0);
	return p->f;
}

static LStream *newprefile(lua_State *L)
{
	LStream *p = (LStream *) lua_newuserdatauv(L, sizeof(LStream), 0);
	p->closef = NULL;
	luaL_setmetatable(L, "FILE*");
	return p;
}

static int aux_close(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	volatile lua_CFunction cf = p->closef;
	p->closef = NULL;
	return (*cf)(L);
}

static int f_close(lua_State *L)
{
	tofile(L);
	return aux_close(L);
}

static int io_close(lua_State *L)
{
	if ((lua_type(L, (1)) == (-1)))
		lua_getfield(L, (-15000 - 1000),
					 ("_IO_"
					  "output"));
	return f_close(L);
}

static int f_gc(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	if (!((p)->closef == NULL) && p->f != NULL)
		aux_close(L);
	return 0;
}

static int io_fclose(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	int res = fclose(p->f);
	return luaL_fileresult(L, (res == 0), NULL);
}

static LStream *newfile(lua_State *L)
{
	LStream *p = newprefile(L);
	p->f = NULL;
	p->closef = &io_fclose;
	return p;
}

static void opencheck(lua_State *L, const char *fname, const char *mode)
{
	LStream *p = newfile(L);
	p->f = fopen(fname, mode);
	if (p->f == NULL)
		luaL_error(L, "cannot open file '%s' (%s)", fname, strerror(errno));
}

static int io_open(lua_State *L)
{
	const char *filename = (luaL_checklstring(L, (1), NULL));
	const char *mode = (luaL_optlstring(L, (2), ("r"), NULL));
	LStream *p = newfile(L);
	const char *md = mode;
	((void) ((l_checkmode(md)) || luaL_argerror(L, (2), ("invalid mode"))));
	p->f = fopen(filename, mode);
	return (p->f == NULL) ? luaL_fileresult(L, 0, filename) : 1;
}

static int io_pclose(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	errno = 0;
	return luaL_execresult(L, ((void) L, (void) p->f, -1));
}

static int io_popen(lua_State *L)
{
	const char *filename = (luaL_checklstring(L, (1), NULL));
	const char *mode = (luaL_optlstring(L, (2), ("r"), NULL));
	LStream *p = newprefile(L);
	((void) ((((mode[0] == 'r' || mode[0] == 'w') && mode[1] == '\0')) ||
			 luaL_argerror(L, (2), ("invalid mode"))));
	p->f = ((void) filename, (void) mode, luaL_error(L, "'popen' not supported"), (FILE *) 0);
	p->closef = &io_pclose;
	return (p->f == NULL) ? luaL_fileresult(L, 0, filename) : 1;
}

static int io_tmpfile(lua_State *L)
{
	LStream *p = newfile(L);
	p->f = tmpfile();
	return (p->f == NULL) ? luaL_fileresult(L, 0, NULL) : 1;
}

static FILE *getiofile(lua_State *L, const char *findex)
{
	LStream *p;
	lua_getfield(L, (-15000 - 1000), findex);
	p = (LStream *) lua_touserdata(L, -1);
	if (((p)->closef == NULL))
		luaL_error(L, "default %s file is closed", findex + (sizeof("_IO_") / sizeof(char) - 1));
	return p->f;
}

static int g_iofile(lua_State *L, const char *f, const char *mode)
{
	if (!(lua_type(L, (1)) <= 0))
	{
		const char *filename = lua_tolstring(L, (1), NULL);
		if (filename)
			opencheck(L, filename, mode);
		else
		{
			tofile(L);
			lua_pushvalue(L, 1);
		}
		lua_setfield(L, (-15000 - 1000), f);
	}

	lua_getfield(L, (-15000 - 1000), f);
	return 1;
}

static int io_input(lua_State *L)
{
	return g_iofile(L,
					("_IO_"
					 "input"),
					"r");
}

static int io_output(lua_State *L)
{
	return g_iofile(L,
					("_IO_"
					 "output"),
					"w");
}

static int io_readline(lua_State *L);
static void aux_lines(lua_State *L, int toclose)
{
	int n = lua_gettop(L) - 1;
	((void) ((n <= 250) || luaL_argerror(L, (250 + 2), ("too many arguments"))));
	lua_pushvalue(L, 1);
	lua_pushinteger(L, n);
	lua_pushboolean(L, toclose);
	lua_rotate(L, 2, 3);
	lua_pushcclosure(L, io_readline, 3 + n);
}

static int f_lines(lua_State *L)
{
	tofile(L);
	aux_lines(L, 0);
	return 1;
}

static int io_lines(lua_State *L)
{
	int toclose;
	if ((lua_type(L, (1)) == (-1)))
		lua_pushnil(L);
	if ((lua_type(L, (1)) == 0))
	{
		lua_getfield(L, (-15000 - 1000),
					 ("_IO_"
					  "input"));
		(lua_copy(L, -1, (1)), lua_settop(L, -(1) - 1));
		tofile(L);
		toclose = 0;
	}
	else
	{
		const char *filename = (luaL_checklstring(L, (1), NULL));
		opencheck(L, filename, "r");
		(lua_copy(L, -1, (1)), lua_settop(L, -(1) - 1));
		toclose = 1;
	}
	aux_lines(L, toclose);
	if (toclose)
	{
		lua_pushnil(L);
		lua_pushnil(L);
		lua_pushvalue(L, 1);
		return 4;
	}
	else
		return 1;
}
typedef struct
{
	FILE *f;
	int c;
	int n;
	char buff[200 + 1];
} RN;

static int nextc(RN *rn)
{
	if (rn->n >= 200)
	{
		rn->buff[0] = '\0';
		return 0;
	}
	else
	{
		rn->buff[rn->n++] = rn->c;
		rn->c = getc(rn->f);
		return 1;
	}
}

static int test2(RN *rn, const char *set)
{
	if (rn->c == set[0] || rn->c == set[1])
		return nextc(rn);
	else
		return 0;
}

static int readdigits(RN *rn, int hex)
{
	int count = 0;
	while ((hex ? isxdigit(rn->c) : isdigit(rn->c)) && nextc(rn))
		count++;
	return count;
}

static int read_number(lua_State *L, FILE *f)
{
	RN rn;
	int count = 0;
	int hex = 0;
	char decp[2];
	rn.f = f;
	rn.n = 0;
	decp[0] = (localeconv()->decimal_point[0]);
	decp[1] = '.';
	((void) 0);
	do
	{
		rn.c = getc(rn.f);
	} while (isspace(rn.c));
	test2(&rn, "-+");
	if (test2(&rn, "00"))
	{
		if (test2(&rn, "xX"))
			hex = 1;
		else
			count = 1;
	}
	count += readdigits(&rn, hex);
	if (test2(&rn, decp))
		count += readdigits(&rn, hex);
	if (count > 0 && test2(&rn, (hex ? "pP" : "eE")))
	{
		test2(&rn, "-+");
		readdigits(&rn, 0);
	}
	ungetc(rn.c, rn.f);
	((void) 0);
	rn.buff[rn.n] = '\0';
	if (lua_stringtonumber(L, rn.buff))
		return 1;
	else
	{
		lua_pushnil(L);
		return 0;
	}
}

static int test_eof(lua_State *L, FILE *f)
{
	int c = getc(f);
	ungetc(c, f);
	lua_pushstring(L, ""
					  "");
	return (c != EOF);
}

static int read_line(lua_State *L, FILE *f, int chop)
{
	luaL_Buffer b;
	int c;
	luaL_buffinit(L, &b);
	do
	{
		char *buff = luaL_prepbuffsize(&b, ((int) (16 * sizeof(void *) * sizeof(lua_Number))));
		int i = 0;
		((void) 0);
		while (i < ((int) (16 * sizeof(void *) * sizeof(lua_Number))) && (c = getc(f)) != EOF &&
			   c != '\n')
			buff[i++] = c;
		((void) 0);
		((&b)->n += (i));
	} while (c != EOF && c != '\n');
	if (!chop && c == '\n')
		((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (c)));
	luaL_pushresult(&b);

	return (c == '\n' || lua_rawlen(L, -1) > 0);
}

static void read_all(lua_State *L, FILE *f)
{
	size_t nr;
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	do
	{
		char *p = luaL_prepbuffsize(&b, ((int) (16 * sizeof(void *) * sizeof(lua_Number))));
		nr = fread(p, sizeof(char), ((int) (16 * sizeof(void *) * sizeof(lua_Number))), f);
		((&b)->n += (nr));
	} while (nr == ((int) (16 * sizeof(void *) * sizeof(lua_Number))));
	luaL_pushresult(&b);
}

static int read_chars(lua_State *L, FILE *f, size_t n)
{
	size_t nr;
	char *p;
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	p = luaL_prepbuffsize(&b, n);
	nr = fread(p, sizeof(char), n, f);
	((&b)->n += (nr));
	luaL_pushresult(&b);
	return (nr > 0);
}

static int g_read(lua_State *L, FILE *f, int first)
{
	int nargs = lua_gettop(L) - 1;
	int n, success;
	clearerr(f);
	if (nargs == 0)
	{
		success = read_line(L, f, 1);
		n = first + 1;
	}
	else
	{

		luaL_checkstack(L, nargs + 20, "too many arguments");
		success = 1;
		for (n = first; nargs-- && success; n++)
		{
			if (lua_type(L, n) == 3)
			{
				size_t l = (size_t) luaL_checkinteger(L, n);
				success = (l == 0) ? test_eof(L, f) : read_chars(L, f, l);
			}
			else
			{
				const char *p = (luaL_checklstring(L, (n), NULL));
				if (*p == '*')
					p++;
				switch (*p)
				{
				case 'n':
					success = read_number(L, f);
					break;
				case 'l':
					success = read_line(L, f, 1);
					break;
				case 'L':
					success = read_line(L, f, 0);
					break;
				case 'a':
					read_all(L, f);
					success = 1;
					break;
				default:
					return luaL_argerror(L, n, "invalid format");
				}
			}
		}
	}
	if (ferror(f))
		return luaL_fileresult(L, 0, NULL);
	if (!success)
	{
		lua_settop(L, -(1) - 1);
		lua_pushnil(L);
	}
	return n - first;
}

static int io_read(lua_State *L)
{
	return g_read(L,
				  getiofile(L, ("_IO_"
								"input")),
				  1);
}

static int f_read(lua_State *L)
{
	return g_read(L, tofile(L), 2);
}

static int io_readline(lua_State *L)
{
	LStream *p = (LStream *) lua_touserdata(L, ((-15000 - 1000) - (1)));
	int i;
	int n = (int) lua_tointegerx(L, (((-15000 - 1000) - (2))), NULL);
	if (((p)->closef == NULL))
		return luaL_error(L, "file is already closed");
	lua_settop(L, 1);
	luaL_checkstack(L, n, "too many arguments");
	for (i = 1; i <= n; i++)
		lua_pushvalue(L, ((-15000 - 1000) - (3 + i)));
	n = g_read(L, p->f, 2);
	((void) 0);
	if (lua_toboolean(L, -n))
		return n;
	else
	{
		if (n > 1)
		{

			return luaL_error(L, "%s", lua_tolstring(L, (-n + 1), NULL));
		}
		if (lua_toboolean(L, ((-15000 - 1000) - (3))))
		{
			lua_settop(L, 0);
			lua_pushvalue(L, ((-15000 - 1000) - (1)));
			aux_close(L);
		}
		return 0;
	}
}

static int g_write(lua_State *L, FILE *f, int arg)
{
	int nargs = lua_gettop(L) - arg;
	int status = 1;
	for (; nargs--; arg++)
	{
		if (lua_type(L, arg) == 3)
		{

			int len = lua_isinteger(L, arg)
						  ? fprintf(f, "%" LUA_INTEGER_FRMLEN "d",
									(LUA_INTEGER) lua_tointegerx(L, (arg), NULL))
						  : fprintf(f, "%.14g", (double) lua_tonumberx(L, (arg), NULL));
			status = status && (len > 0);
		}
		else
		{
			size_t l;
			const char *s = luaL_checklstring(L, arg, &l);
			status = status && (fwrite(s, sizeof(char), l, f) == l);
		}
	}
	if (status)
		return 1;
	else
		return luaL_fileresult(L, status, NULL);
}

static int io_write(lua_State *L)
{
	return g_write(L,
				   getiofile(L, ("_IO_"
								 "output")),
				   1);
}

static int f_write(lua_State *L)
{
	FILE *f = tofile(L);
	lua_pushvalue(L, 1);
	return g_write(L, f, 2);
}

static int f_seek(lua_State *L)
{
	static const int mode[] = {SEEK_SET, SEEK_CUR, SEEK_END};
	static const char *const modenames[] = {"set", "cur", "end", NULL};
	FILE *f = tofile(L);
	int op = luaL_checkoption(L, 2, "cur", modenames);
	lua_Integer p3 = luaL_optinteger(L, 3, 0);
	long offset = (long) p3;
	((void) (((lua_Integer) offset == p3) ||
			 luaL_argerror(L, (3), ("not an integer in proper range"))));

	op = fseek(f, offset, mode[op]);
	if (op)
		return luaL_fileresult(L, 0, NULL);
	else
	{
		lua_pushinteger(L, (lua_Integer) ftell(f));
		return 1;
	}
}

static int f_setvbuf(lua_State *L)
{
	static const int mode[] = {_IONBF, _IOFBF, _IOLBF};
	static const char *const modenames[] = {"no", "full", "line", NULL};
	FILE *f = tofile(L);
	int op = luaL_checkoption(L, 2, NULL, modenames);
	lua_Integer sz = luaL_optinteger(L, 3, ((int) (16 * sizeof(void *) * sizeof(lua_Number))));
	int res = setvbuf(f, NULL, mode[op], (size_t) sz);
	return luaL_fileresult(L, res == 0, NULL);
}

static int io_flush(lua_State *L)
{
	return luaL_fileresult(L,
						   fflush(getiofile(L, ("_IO_"
												"output"))) == 0,
						   NULL);
}

static int f_flush(lua_State *L)
{
	return luaL_fileresult(L, fflush(tofile(L)) == 0, NULL);
}

static const luaL_Reg iolib[] = {{"close", io_close}, {"flush", io_flush}, {"input", io_input},
								 {"lines", io_lines}, {"open", io_open},   {"output", io_output},
								 {"popen", io_popen}, {"read", io_read},   {"tmpfile", io_tmpfile},
								 {"type", io_type},	  {"write", io_write}, {NULL, NULL}};

static const luaL_Reg meth[] = {{"read", f_read},		{"write", f_write}, {"lines", f_lines},
								{"flush", f_flush},		{"seek", f_seek},	{"close", f_close},
								{"setvbuf", f_setvbuf}, {NULL, NULL}};

static const luaL_Reg metameth[] = {
	{"__index", NULL}, {"__gc", f_gc}, {"__close", f_gc}, {"__tostring", f_tostring}, {NULL, NULL}};

static void createmeta(lua_State *L)
{
	luaL_newmetatable(L, "FILE*");
	luaL_setfuncs(L, metameth, 0);
	lua_createtable(L, 0, sizeof(meth) / sizeof((meth)[0]) - 1);
	luaL_setfuncs(L, meth, 0);
	lua_setfield(L, -2, "__index");
	lua_settop(L, -(1) - 1);
}

static int io_noclose(lua_State *L)
{
	LStream *p = ((LStream *) luaL_checkudata(L, 1, "FILE*"));
	p->closef = &io_noclose;
	lua_pushnil(L);
	lua_pushstring(L, ""
					  "cannot close standard file");
	return 2;
}

static void createstdfile(lua_State *L, FILE *f, const char *k, const char *fname)
{
	LStream *p = newprefile(L);
	p->f = f;
	p->closef = &io_noclose;
	if (k != NULL)
	{
		lua_pushvalue(L, -1);
		lua_setfield(L, (-15000 - 1000), k);
	}
	lua_setfield(L, -2, fname);
}

extern int luaopen_io(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(iolib) / sizeof((iolib)[0]) - 1), luaL_setfuncs(L, iolib, 0));
	createmeta(L);

	createstdfile(L, stdin,
				  ("_IO_"
				   "input"),
				  "stdin");
	createstdfile(L, stdout,
				  ("_IO_"
				   "output"),
				  "stdout");
	createstdfile(L, stderr, NULL, "stderr");
	return 1;
}
