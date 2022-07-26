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
static int str_len(lua_State *L)
{
	size_t l;
	luaL_checklstring(L, 1, &l);
	lua_pushinteger(L, (lua_Integer) l);
	return 1;
}
static size_t posrelatI(lua_Integer pos, size_t len)
{
	if (pos > 0)
		return (size_t) pos;
	else if (pos == 0)
		return 1;
	else if (pos < -(lua_Integer) len)
		return 1;
	else
		return len + (size_t) pos + 1;
}

static size_t getendpos(lua_State *L, int arg, lua_Integer def, size_t len)
{
	lua_Integer pos = luaL_optinteger(L, arg, def);
	if (pos > (lua_Integer) len)
		return len;
	else if (pos >= 0)
		return (size_t) pos;
	else if (pos < -(lua_Integer) len)
		return 0;
	else
		return len + (size_t) pos + 1;
}

static int str_sub(lua_State *L)
{
	size_t l;
	const char *s = luaL_checklstring(L, 1, &l);
	size_t start = posrelatI(luaL_checkinteger(L, 2), l);
	size_t end = getendpos(L, 3, -1, l);
	if (start <= end)
		lua_pushlstring(L, s + start - 1, (end - start) + 1);
	else
		lua_pushstring(L, ""
						  "");
	return 1;
}

static int str_reverse(lua_State *L)
{
	size_t l, i;
	luaL_Buffer b;
	const char *s = luaL_checklstring(L, 1, &l);
	char *p = luaL_buffinitsize(L, &b, l);
	for (i = 0; i < l; i++)
		p[i] = s[l - i - 1];
	luaL_pushresultsize(&b, l);
	return 1;
}

static int str_lower(lua_State *L)
{
	size_t l;
	size_t i;
	luaL_Buffer b;
	const char *s = luaL_checklstring(L, 1, &l);
	char *p = luaL_buffinitsize(L, &b, l);
	for (i = 0; i < l; i++)
		p[i] = tolower(((unsigned char) (s[i])));
	luaL_pushresultsize(&b, l);
	return 1;
}

static int str_upper(lua_State *L)
{
	size_t l;
	size_t i;
	luaL_Buffer b;
	const char *s = luaL_checklstring(L, 1, &l);
	char *p = luaL_buffinitsize(L, &b, l);
	for (i = 0; i < l; i++)
		p[i] = toupper(((unsigned char) (s[i])));
	luaL_pushresultsize(&b, l);
	return 1;
}

static int str_rep(lua_State *L)
{
	size_t l, lsep;
	const char *s = luaL_checklstring(L, 1, &l);
	lua_Integer n = luaL_checkinteger(L, 2);
	const char *sep = luaL_optlstring(L, 3, "", &lsep);
	if (n <= 0)
		lua_pushstring(L, ""
						  "");
	else if (l + lsep < l ||
			 l + lsep >
				 (sizeof(size_t) < sizeof(int) ? ((size_t) (~(size_t) 0)) : (size_t) (INT_MAX)) / n)
		return luaL_error(L, "resulting string too large");
	else
	{
		size_t totallen = (size_t) n * l + (size_t) (n - 1) * lsep;
		luaL_Buffer b;
		char *p = luaL_buffinitsize(L, &b, totallen);
		while (n-- > 1)
		{
			memcpy(p, s, l * sizeof(char));
			p += l;
			if (lsep > 0)
			{
				memcpy(p, sep, lsep * sizeof(char));
				p += lsep;
			}
		}
		memcpy(p, s, l * sizeof(char));
		luaL_pushresultsize(&b, totallen);
	}
	return 1;
}

static int str_byte(lua_State *L)
{
	size_t l;
	const char *s = luaL_checklstring(L, 1, &l);
	lua_Integer pi = luaL_optinteger(L, 2, 1);
	size_t posi = posrelatI(pi, l);
	size_t pose = getendpos(L, 3, pi, l);
	int n, i;
	if (posi > pose)
		return 0;
	if (pose - posi >= (size_t) INT_MAX)
		return luaL_error(L, "string slice too long");
	n = (int) (pose - posi) + 1;
	luaL_checkstack(L, n, "string slice too long");
	for (i = 0; i < n; i++)
		lua_pushinteger(L, ((unsigned char) (s[posi + i - 1])));
	return n;
}

static int str_char(lua_State *L)
{
	int n = lua_gettop(L);
	int i;
	luaL_Buffer b;
	char *p = luaL_buffinitsize(L, &b, n);
	for (i = 1; i <= n; i++)
	{
		lua_Unsigned c = (lua_Unsigned) luaL_checkinteger(L, i);
		((void) ((c <= (lua_Unsigned) UCHAR_MAX) || luaL_argerror(L, (i), ("value out of range"))));
		p[i - 1] = ((unsigned char) (c));
	}
	luaL_pushresultsize(&b, n);
	return 1;
}
struct str_Writer
{
	int init;
	luaL_Buffer B;
};

static int writer(lua_State *L, const void *b, size_t size, void *ud)
{
	struct str_Writer *state = (struct str_Writer *) ud;
	if (!state->init)
	{
		state->init = 1;
		luaL_buffinit(L, &state->B);
	}
	luaL_addlstring(&state->B, (const char *) b, size);
	return 0;
}

static int str_dump(lua_State *L)
{
	struct str_Writer state;
	int strip = lua_toboolean(L, 2);
	luaL_checktype(L, 1, 6);
	lua_settop(L, 1);
	state.init = 0;
	if (lua_dump(L, writer, &state, strip) != 0)
		return luaL_error(L, "unable to dump given function");
	luaL_pushresult(&state.B);
	return 1;
}
static int tonum(lua_State *L, int arg)
{
	if (lua_type(L, arg) == 3)
	{
		lua_pushvalue(L, arg);
		return 1;
	}
	else
	{
		size_t len;
		const char *s = lua_tolstring(L, arg, &len);
		return (s != NULL && lua_stringtonumber(L, s) == len + 1);
	}
}

static void trymt(lua_State *L, const char *mtname)
{
	lua_settop(L, 2);
	if (lua_type(L, 2) == 4 || !luaL_getmetafield(L, 2, mtname))
		luaL_error(L, "attempt to %s a '%s' with a '%s'", mtname + 2,
				   lua_typename(L, lua_type(L, (-2))), lua_typename(L, lua_type(L, (-1))));
	lua_rotate(L, (-3), 1);
	lua_callk(L, (2), (1), 0, NULL);
}

static int arith(lua_State *L, int op, const char *mtname)
{
	if (tonum(L, 1) && tonum(L, 2))
		lua_arith(L, op);
	else
		trymt(L, mtname);
	return 1;
}

static int arith_add(lua_State *L)
{
	return arith(L, 0, "__add");
}

static int arith_sub(lua_State *L)
{
	return arith(L, 1, "__sub");
}

static int arith_mul(lua_State *L)
{
	return arith(L, 2, "__mul");
}

static int arith_mod(lua_State *L)
{
	return arith(L, 3, "__mod");
}

static int arith_pow(lua_State *L)
{
	return arith(L, 4, "__pow");
}

static int arith_div(lua_State *L)
{
	return arith(L, 5, "__div");
}

static int arith_idiv(lua_State *L)
{
	return arith(L, 6, "__idiv");
}

static int arith_unm(lua_State *L)
{
	return arith(L, 12, "__unm");
}

static const luaL_Reg stringmetamethods[] = {
	{"__add", arith_add}, {"__sub", arith_sub}, {"__mul", arith_mul},	{"__mod", arith_mod},
	{"__pow", arith_pow}, {"__div", arith_div}, {"__idiv", arith_idiv}, {"__unm", arith_unm},
	{"__index", NULL},	  {NULL, NULL}};
typedef struct MatchState
{
	const char *src_init;
	const char *src_end;
	const char *p_end;
	lua_State *L;
	int matchdepth;
	unsigned char level;
	struct
	{
		const char *init;
		ptrdiff_t len;
	} capture[32];
} MatchState;

static const char *match(MatchState *ms, const char *s, const char *p);
static int check_capture(MatchState *ms, int l)
{
	l -= '1';
	if (l < 0 || l >= ms->level || ms->capture[l].len == (-1))
		return luaL_error(ms->L, "invalid capture index %%%d", l + 1);
	return l;
}

static int capture_to_close(MatchState *ms)
{
	int level = ms->level;
	for (level--; level >= 0; level--)
		if (ms->capture[level].len == (-1))
			return level;
	return luaL_error(ms->L, "invalid pattern capture");
}

static const char *classend(MatchState *ms, const char *p)
{
	switch (*p++)
	{
	case '%':
	{
		if (p == ms->p_end)
			luaL_error(ms->L, "malformed pattern (ends with '%%')");
		return p + 1;
	}
	case '[':
	{
		if (*p == '^')
			p++;
		do
		{
			if (p == ms->p_end)
				luaL_error(ms->L, "malformed pattern (missing ']')");
			if (*(p++) == '%' && p < ms->p_end)
				p++;
		} while (*p != ']');
		return p + 1;
	}
	default:
	{
		return p;
	}
	}
}

static int match_class(int c, int cl)
{
	int res;
	switch (tolower(cl))
	{
	case 'a':
		res = isalpha(c);
		break;
	case 'c':
		res = iscntrl(c);
		break;
	case 'd':
		res = isdigit(c);
		break;
	case 'g':
		res = isgraph(c);
		break;
	case 'l':
		res = islower(c);
		break;
	case 'p':
		res = ispunct(c);
		break;
	case 's':
		res = isspace(c);
		break;
	case 'u':
		res = isupper(c);
		break;
	case 'w':
		res = isalnum(c);
		break;
	case 'x':
		res = isxdigit(c);
		break;
	case 'z':
		res = (c == 0);
		break;
	default:
		return (cl == c);
	}
	return (islower(cl) ? res : !res);
}

static int matchbracketclass(int c, const char *p, const char *ec)
{
	int sig = 1;
	if (*(p + 1) == '^')
	{
		sig = 0;
		p++;
	}
	while (++p < ec)
	{
		if (*p == '%')
		{
			p++;
			if (match_class(c, ((unsigned char) (*p))))
				return sig;
		}
		else if ((*(p + 1) == '-') && (p + 2 < ec))
		{
			p += 2;
			if (((unsigned char) (*(p - 2))) <= c && c <= ((unsigned char) (*p)))
				return sig;
		}
		else if (((unsigned char) (*p)) == c)
			return sig;
	}
	return !sig;
}

static int singlematch(MatchState *ms, const char *s, const char *p, const char *ep)
{
	if (s >= ms->src_end)
		return 0;
	else
	{
		int c = ((unsigned char) (*s));
		switch (*p)
		{
		case '.':
			return 1;
		case '%':
			return match_class(c, ((unsigned char) (*(p + 1))));
		case '[':
			return matchbracketclass(c, p, ep - 1);
		default:
			return (((unsigned char) (*p)) == c);
		}
	}
}

static const char *matchbalance(MatchState *ms, const char *s, const char *p)
{
	if (p >= ms->p_end - 1)
		luaL_error(ms->L, "malformed pattern (missing arguments to '%%b')");
	if (*s != *p)
		return NULL;
	else
	{
		int b = *p;
		int e = *(p + 1);
		int cont = 1;
		while (++s < ms->src_end)
		{
			if (*s == e)
			{
				if (--cont == 0)
					return s + 1;
			}
			else if (*s == b)
				cont++;
		}
	}
	return NULL;
}

static const char *max_expand(MatchState *ms, const char *s, const char *p, const char *ep)
{
	ptrdiff_t i = 0;
	while (singlematch(ms, s + i, p, ep))
		i++;

	while (i >= 0)
	{
		const char *res = match(ms, (s + i), ep + 1);
		if (res)
			return res;
		i--;
	}
	return NULL;
}

static const char *min_expand(MatchState *ms, const char *s, const char *p, const char *ep)
{
	for (;;)
	{
		const char *res = match(ms, s, ep + 1);
		if (res != NULL)
			return res;
		else if (singlematch(ms, s, p, ep))
			s++;
		else
			return NULL;
	}
}

static const char *start_capture(MatchState *ms, const char *s, const char *p, int what)
{
	const char *res;
	int level = ms->level;
	if (level >= 32)
		luaL_error(ms->L, "too many captures");
	ms->capture[level].init = s;
	ms->capture[level].len = what;
	ms->level = level + 1;
	if ((res = match(ms, s, p)) == NULL)
		ms->level--;
	return res;
}

static const char *end_capture(MatchState *ms, const char *s, const char *p)
{
	int l = capture_to_close(ms);
	const char *res;
	ms->capture[l].len = s - ms->capture[l].init;
	if ((res = match(ms, s, p)) == NULL)
		ms->capture[l].len = (-1);
	return res;
}

static const char *match_capture(MatchState *ms, const char *s, int l)
{
	size_t len;
	l = check_capture(ms, l);
	len = ms->capture[l].len;
	if ((size_t) (ms->src_end - s) >= len && memcmp(ms->capture[l].init, s, len) == 0)
		return s + len;
	else
		return NULL;
}

static const char *match(MatchState *ms, const char *s, const char *p)
{
	if (ms->matchdepth-- == 0)
		luaL_error(ms->L, "pattern too complex");
init:
	if (p != ms->p_end)
	{
		switch (*p)
		{
		case '(':
		{
			if (*(p + 1) == ')')
				s = start_capture(ms, s, p + 2, (-2));
			else
				s = start_capture(ms, s, p + 1, (-1));
			break;
		}
		case ')':
		{
			s = end_capture(ms, s, p + 1);
			break;
		}
		case '$':
		{
			if ((p + 1) != ms->p_end)
				goto dflt;
			s = (s == ms->src_end) ? s : NULL;
			break;
		}
		case '%':
		{
			switch (*(p + 1))
			{
			case 'b':
			{
				s = matchbalance(ms, s, p + 2);
				if (s != NULL)
				{
					p += 4;
					goto init;
				}
				break;
			}
			case 'f':
			{
				const char *ep;
				char previous;
				p += 2;
				if (*p != '[')
					luaL_error(ms->L, "missing '[' after '%%f' in pattern");
				ep = classend(ms, p);
				previous = (s == ms->src_init) ? '\0' : *(s - 1);
				if (!matchbracketclass(((unsigned char) (previous)), p, ep - 1) &&
					matchbracketclass(((unsigned char) (*s)), p, ep - 1))
				{
					p = ep;
					goto init;
				}
				s = NULL;
				break;
			}
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				s = match_capture(ms, s, ((unsigned char) (*(p + 1))));
				if (s != NULL)
				{
					p += 2;
					goto init;
				}
				break;
			}
			default:
				goto dflt;
			}
			break;
		}
		default:
		dflt:
		{
			const char *ep = classend(ms, p);

			if (!singlematch(ms, s, p, ep))
			{
				if (*ep == '*' || *ep == '?' || *ep == '-')
				{
					p = ep + 1;
					goto init;
				}
				else
					s = NULL;
			}
			else
			{
				switch (*ep)
				{
				case '?':
				{
					const char *res;
					if ((res = match(ms, s + 1, ep + 1)) != NULL)
						s = res;
					else
					{
						p = ep + 1;
						goto init;
					}
					break;
				}
				case '+':
					s++;

				case '*':
					s = max_expand(ms, s, p, ep);
					break;
				case '-':
					s = min_expand(ms, s, p, ep);
					break;
				default:
					s++;
					p = ep;
					goto init;
				}
			}
			break;
		}
		}
	}
	ms->matchdepth++;
	return s;
}

static const char *lmemfind(const char *s1, size_t l1, const char *s2, size_t l2)
{
	if (l2 == 0)
		return s1;
	else if (l2 > l1)
		return NULL;
	else
	{
		const char *init;
		l2--;
		l1 = l1 - l2;
		while (l1 > 0 && (init = (const char *) memchr(s1, *s2, l1)) != NULL)
		{
			init++;
			if (memcmp(init, s2 + 1, l2) == 0)
				return init - 1;
			else
			{
				l1 -= init - s1;
				s1 = init;
			}
		}
		return NULL;
	}
}
static size_t get_onecapture(MatchState *ms, int i, const char *s, const char *e, const char **cap)
{
	if (i >= ms->level)
	{
		if (i != 0)
			luaL_error(ms->L, "invalid capture index %%%d", i + 1);
		*cap = s;
		return e - s;
	}
	else
	{
		ptrdiff_t capl = ms->capture[i].len;
		*cap = ms->capture[i].init;
		if (capl == (-1))
			luaL_error(ms->L, "unfinished capture");
		else if (capl == (-2))
			lua_pushinteger(ms->L, (ms->capture[i].init - ms->src_init) + 1);
		return capl;
	}
}

static void push_onecapture(MatchState *ms, int i, const char *s, const char *e)
{
	const char *cap;
	ptrdiff_t l = get_onecapture(ms, i, s, e, &cap);
	if (l != (-2))
		lua_pushlstring(ms->L, cap, l);
}

static int push_captures(MatchState *ms, const char *s, const char *e)
{
	int i;
	int nlevels = (ms->level == 0 && s) ? 1 : ms->level;
	luaL_checkstack(ms->L, nlevels, "too many captures");
	for (i = 0; i < nlevels; i++)
		push_onecapture(ms, i, s, e);
	return nlevels;
}

static int nospecials(const char *p, size_t l)
{
	size_t upto = 0;
	do
	{
		if (strpbrk(p + upto, "^$*+?.([%-"))
			return 0;
		upto += strlen(p + upto) + 1;
	} while (upto <= l);
	return 1;
}

static void prepstate(MatchState *ms, lua_State *L, const char *s, size_t ls, const char *p,
					  size_t lp)
{
	ms->L = L;
	ms->matchdepth = 200;
	ms->src_init = s;
	ms->src_end = s + ls;
	ms->p_end = p + lp;
}

static void reprepstate(MatchState *ms)
{
	ms->level = 0;
	((void) 0);
}

static int str_find_aux(lua_State *L, int find)
{
	size_t ls, lp;
	const char *s = luaL_checklstring(L, 1, &ls);
	const char *p = luaL_checklstring(L, 2, &lp);
	size_t init = posrelatI(luaL_optinteger(L, 3, 1), ls) - 1;
	if (init > ls)
	{
		lua_pushnil(L);
		return 1;
	}

	if (find && (lua_toboolean(L, 4) || nospecials(p, lp)))
	{

		const char *s2 = lmemfind(s + init, ls - init, p, lp);
		if (s2)
		{
			lua_pushinteger(L, (s2 - s) + 1);
			lua_pushinteger(L, (s2 - s) + lp);
			return 2;
		}
	}
	else
	{
		MatchState ms;
		const char *s1 = s + init;
		int anchor = (*p == '^');
		if (anchor)
		{
			p++;
			lp--;
		}
		prepstate(&ms, L, s, ls, p, lp);
		do
		{
			const char *res;
			reprepstate(&ms);
			if ((res = match(&ms, s1, p)) != NULL)
			{
				if (find)
				{
					lua_pushinteger(L, (s1 - s) + 1);
					lua_pushinteger(L, res - s);
					return push_captures(&ms, NULL, 0) + 2;
				}
				else
					return push_captures(&ms, s1, res);
			}
		} while (s1++ < ms.src_end && !anchor);
	}
	lua_pushnil(L);
	return 1;
}

static int str_find(lua_State *L)
{
	return str_find_aux(L, 1);
}

static int str_match(lua_State *L)
{
	return str_find_aux(L, 0);
}

typedef struct GMatchState
{
	const char *src;
	const char *p;
	const char *lastmatch;
	MatchState ms;
} GMatchState;

static int gmatch_aux(lua_State *L)
{
	GMatchState *gm = (GMatchState *) lua_touserdata(L, ((-15000 - 1000) - (3)));
	const char *src;
	gm->ms.L = L;
	for (src = gm->src; src <= gm->ms.src_end; src++)
	{
		const char *e;
		reprepstate(&gm->ms);
		if ((e = match(&gm->ms, src, gm->p)) != NULL && e != gm->lastmatch)
		{
			gm->src = gm->lastmatch = e;
			return push_captures(&gm->ms, src, e);
		}
	}
	return 0;
}

static int gmatch(lua_State *L)
{
	size_t ls, lp;
	const char *s = luaL_checklstring(L, 1, &ls);
	const char *p = luaL_checklstring(L, 2, &lp);
	size_t init = posrelatI(luaL_optinteger(L, 3, 1), ls) - 1;
	GMatchState *gm;
	lua_settop(L, 2);
	gm = (GMatchState *) lua_newuserdatauv(L, sizeof(GMatchState), 0);
	if (init > ls)
		init = ls + 1;
	prepstate(&gm->ms, L, s, ls, p, lp);
	gm->src = s + init;
	gm->p = p;
	gm->lastmatch = NULL;
	lua_pushcclosure(L, gmatch_aux, 3);
	return 1;
}

static void add_s(MatchState *ms, luaL_Buffer *b, const char *s, const char *e)
{
	size_t l;
	lua_State *L = ms->L;
	const char *news = lua_tolstring(L, 3, &l);
	const char *p;
	while ((p = (char *) memchr(news, '%', l)) != NULL)
	{
		luaL_addlstring(b, news, p - news);
		p++;
		if (*p == '%')
			((void) ((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (*p)));
		else if (*p == '0')
			luaL_addlstring(b, s, e - s);
		else if (isdigit(((unsigned char) (*p))))
		{
			const char *cap;
			ptrdiff_t resl = get_onecapture(ms, *p - '1', s, e, &cap);
			if (resl == (-2))
				luaL_addvalue(b);
			else
				luaL_addlstring(b, cap, resl);
		}
		else
			luaL_error(L, "invalid use of '%c' in replacement string", '%');
		l -= p + 1 - news;
		news = p + 1;
	}
	luaL_addlstring(b, news, l);
}

static int add_value(MatchState *ms, luaL_Buffer *b, const char *s, const char *e, int tr)
{
	lua_State *L = ms->L;
	switch (tr)
	{
	case 6:
	{
		int n;
		lua_pushvalue(L, 3);
		n = push_captures(ms, s, e);
		lua_callk(L, (n), (1), 0, NULL);
		break;
	}
	case 5:
	{
		push_onecapture(ms, 0, s, e);
		lua_gettable(L, 3);
		break;
	}
	default:
	{
		add_s(ms, b, s, e);
		return 1;
	}
	}
	if (!lua_toboolean(L, -1))
	{
		lua_settop(L, -(1) - 1);
		luaL_addlstring(b, s, e - s);
		return 0;
	}
	else if (!lua_isstring(L, -1))
		return luaL_error(L, "invalid replacement value (a %s)",
						  lua_typename(L, lua_type(L, (-1))));
	else
	{
		luaL_addvalue(b);
		return 1;
	}
}

static int str_gsub(lua_State *L)
{
	size_t srcl, lp;
	const char *src = luaL_checklstring(L, 1, &srcl);
	const char *p = luaL_checklstring(L, 2, &lp);
	const char *lastmatch = NULL;
	int tr = lua_type(L, 3);
	lua_Integer max_s = luaL_optinteger(L, 4, srcl + 1);
	int anchor = (*p == '^');
	lua_Integer n = 0;
	int changed = 0;
	MatchState ms;
	luaL_Buffer b;
	((void) ((tr == 3 || tr == 4 || tr == 6 || tr == 5) ||
			 luaL_typeerror(L, (3), ("string/function/table"))));

	luaL_buffinit(L, &b);
	if (anchor)
	{
		p++;
		lp--;
	}
	prepstate(&ms, L, src, srcl, p, lp);
	while (n < max_s)
	{
		const char *e;
		reprepstate(&ms);
		if ((e = match(&ms, src, p)) != NULL && e != lastmatch)
		{
			n++;
			changed = add_value(&ms, &b, src, e, tr) | changed;
			src = lastmatch = e;
		}
		else if (src < ms.src_end)
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (*src++)));
		else
			break;
		if (anchor)
			break;
	}
	if (!changed)
		lua_pushvalue(L, 1);
	else
	{
		luaL_addlstring(&b, src, ms.src_end - src);
		luaL_pushresult(&b);
	}
	lua_pushinteger(L, n);
	return 2;
}
static void addquoted(luaL_Buffer *b, const char *s, size_t len)
{
	((void) ((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = ('"')));
	while (len--)
	{
		if (*s == '"' || *s == '\\' || *s == '\n')
		{
			((void) ((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = ('\\')));
			((void) ((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (*s)));
		}
		else if (iscntrl(((unsigned char) (*s))))
		{
			char buff[10];
			if (!isdigit(((unsigned char) (*(s + 1)))))
				snprintf(buff, sizeof(buff), "\\%d", (int) ((unsigned char) (*s)));
			else
				snprintf(buff, sizeof(buff), "\\%03d", (int) ((unsigned char) (*s)));
			luaL_addstring(b, buff);
		}
		else
			((void) ((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (*s)));
		s++;
	}
	((void) ((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = ('"')));
}
static int quotefloat(lua_State *L, char *buff, lua_Number n)
{
	const char *s;
	if (n == (lua_Number) HUGE_VAL)
		s = "1e9999";
	else if (n == -(lua_Number) HUGE_VAL)
		s = "-1e9999";
	else if (n != n)
		s = "(0/0)";
	else
	{
		int nb = ((void) L, snprintf(buff, 120,
									 "%"
									 ""
									 "a",
									 (double) (n)));

		if (memchr(buff, '.', nb) == NULL)
		{
			char point = (localeconv()->decimal_point[0]);
			char *ppoint = (char *) memchr(buff, point, nb);
			if (ppoint)
				*ppoint = '.';
		}
		return nb;
	}

	return snprintf(buff, 120, "%s", s);
}

static void addliteral(lua_State *L, luaL_Buffer *b, int arg)
{
	switch (lua_type(L, arg))
	{
	case 4:
	{
		size_t len;
		const char *s = lua_tolstring(L, arg, &len);
		addquoted(b, s, len);
		break;
	}
	case 3:
	{
		char *buff = luaL_prepbuffsize(b, 120);
		int nb;
		if (!lua_isinteger(L, arg))
			nb = quotefloat(L, buff, lua_tonumberx(L, (arg), NULL));
		else
		{
			lua_Integer n = lua_tointegerx(L, (arg), NULL);
			const char *format =
				(n == LUA_MININTEGER) ? "0x%" LUA_INTEGER_FRMLEN "x" : "%" LUA_INTEGER_FRMLEN "d";
			nb = snprintf(buff, 120, format, (LUA_INTEGER) n);
		}
		((b)->n += (nb));
		break;
	}
	case 0:
	case 1:
	{
		luaL_tolstring(L, arg, NULL);
		luaL_addvalue(b);
		break;
	}
	default:
	{
		luaL_argerror(L, arg, "value has no literal form");
	}
	}
}

static const char *scanformat(lua_State *L, const char *strfrmt, char *form)
{
	const char *p = strfrmt;
	while (*p != '\0' && strchr("-+ #0", *p) != NULL)
		p++;
	if ((size_t) (p - strfrmt) >= sizeof("-+ #0") / sizeof(char))
		luaL_error(L, "invalid format (repeated flags)");
	if (isdigit(((unsigned char) (*p))))
		p++;
	if (isdigit(((unsigned char) (*p))))
		p++;
	if (*p == '.')
	{
		p++;
		if (isdigit(((unsigned char) (*p))))
			p++;
		if (isdigit(((unsigned char) (*p))))
			p++;
	}
	if (isdigit(((unsigned char) (*p))))
		luaL_error(L, "invalid format (width or precision too long)");
	*(form++) = '%';
	memcpy(form, strfrmt, ((p - strfrmt) + 1) * sizeof(char));
	form += (p - strfrmt) + 1;
	*form = '\0';
	return p;
}

static void addlenmod(char *form, const char *lenmod)
{
	size_t l = strlen(form);
	size_t lm = strlen(lenmod);
	char spec = form[l - 1];
	strcpy(form + l - 1, lenmod);
	form[l + lm - 1] = spec;
	form[l + lm] = '\0';
}

static int str_format(lua_State *L)
{
	int top = lua_gettop(L);
	int arg = 1;
	size_t sfl;
	const char *strfrmt = luaL_checklstring(L, arg, &sfl);
	const char *strfrmt_end = strfrmt + sfl;
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	while (strfrmt < strfrmt_end)
	{
		if (*strfrmt != '%')
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (*strfrmt++)));
		else if (*++strfrmt == '%')
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (*strfrmt++)));
		else
		{
			char form[32];
			int maxitem = 120;
			char *buff = luaL_prepbuffsize(&b, maxitem);
			int nb = 0;
			if (++arg > top)
				return luaL_argerror(L, arg, "no value");
			strfrmt = scanformat(L, strfrmt, form);
			switch (*strfrmt++)
			{
			case 'c':
			{
				nb = snprintf(buff, maxitem, form, (int) luaL_checkinteger(L, arg));
				break;
			}
			case 'd':
			case 'i':
			case 'o':
			case 'u':
			case 'x':
			case 'X':
			{
				lua_Integer n = luaL_checkinteger(L, arg);
				addlenmod(form, LUA_INTEGER_FRMLEN);
				nb = snprintf(buff, maxitem, form, (LUA_INTEGER) n);
				break;
			}
			case 'a':
			case 'A':
				addlenmod(form, "");
				nb = ((void) L, snprintf(buff, maxitem, form, (double) (luaL_checknumber(L, arg))));

				break;
			case 'f':
				maxitem = (110 + (DBL_MAX_10_EXP));
				buff = luaL_prepbuffsize(&b, maxitem);

			case 'e':
			case 'E':
			case 'g':
			case 'G':
			{
				lua_Number n = luaL_checknumber(L, arg);
				addlenmod(form, "");
				nb = snprintf(buff, maxitem, form, (double) n);
				break;
			}
			case 'p':
			{
				const void *p = lua_topointer(L, arg);
				if (p == NULL)
				{
					p = "(null)";
					form[strlen(form) - 1] = 's';
				}
				nb = snprintf(buff, maxitem, form, p);
				break;
			}
			case 'q':
			{
				if (form[2] != '\0')
					return luaL_error(L, "specifier '%%q' cannot have modifiers");
				addliteral(L, &b, arg);
				break;
			}
			case 's':
			{
				size_t l;
				const char *s = luaL_tolstring(L, arg, &l);
				if (form[2] == '\0')
					luaL_addvalue(&b);
				else
				{
					((void) ((l == strlen(s)) ||
							 luaL_argerror(L, (arg), ("string contains zeros"))));
					if (!strchr(form, '.') && l >= 100)
					{

						luaL_addvalue(&b);
					}
					else
					{
						nb = snprintf(buff, maxitem, form, s);
						lua_settop(L, -(1) - 1);
					}
				}
				break;
			}
			default:
			{
				return luaL_error(L, "invalid conversion '%s' to 'format'", form);
			}
			}
			((void) 0);
			((&b)->n += (nb));
		}
	}
	luaL_pushresult(&b);
	return 1;
}
static const union
{
	int dummy;
	char little;
} nativeendian = {1};

struct cD
{
	char c;
	union
	{
		double d;
		void *p;
		lua_Integer i;
		lua_Number n;
	} u;
};

typedef union Ftypes
{
	float f;
	double d;
	lua_Number n;
} Ftypes;

typedef struct Header
{
	lua_State *L;
	int islittle;
	int maxalign;
} Header;

typedef enum KOption
{
	Kint,
	Kuint,
	Kfloat,
	Kchar,
	Kstring,
	Kzstr,
	Kpadding,
	Kpaddalign,
	Knop
} KOption;

static int digit(int c)
{
	return '0' <= c && c <= '9';
}

static int getnum(const char **fmt, int df)
{
	if (!digit(**fmt))
		return df;
	else
	{
		int a = 0;
		do
		{
			a = a * 10 + (*((*fmt)++) - '0');
		} while (digit(**fmt) &&
				 a <= ((int) (sizeof(size_t) < sizeof(int) ? ((size_t) (~(size_t) 0))
														   : (size_t) (INT_MAX)) -
					   9) /
						  10);
		return a;
	}
}

static int getnumlimit(Header *h, const char **fmt, int df)
{
	int sz = getnum(fmt, df);
	if (sz > 16 || sz <= 0)
		return luaL_error(h->L, "integral size (%d) out of limits [1,%d]", sz, 16);
	return sz;
}

static void initheader(lua_State *L, Header *h)
{
	h->L = L;
	h->islittle = nativeendian.little;
	h->maxalign = 1;
}

static KOption getoption(Header *h, const char **fmt, int *size)
{
	int opt = *((*fmt)++);
	*size = 0;
	switch (opt)
	{
	case 'b':
		*size = sizeof(char);
		return Kint;
	case 'B':
		*size = sizeof(char);
		return Kuint;
	case 'h':
		*size = sizeof(short);
		return Kint;
	case 'H':
		*size = sizeof(short);
		return Kuint;
	case 'l':
		*size = sizeof(long);
		return Kint;
	case 'L':
		*size = sizeof(long);
		return Kuint;
	case 'j':
		*size = sizeof(lua_Integer);
		return Kint;
	case 'J':
		*size = sizeof(lua_Integer);
		return Kuint;
	case 'T':
		*size = sizeof(size_t);
		return Kuint;
	case 'f':
		*size = sizeof(float);
		return Kfloat;
	case 'd':
		*size = sizeof(double);
		return Kfloat;
	case 'n':
		*size = sizeof(lua_Number);
		return Kfloat;
	case 'i':
		*size = getnumlimit(h, fmt, sizeof(int));
		return Kint;
	case 'I':
		*size = getnumlimit(h, fmt, sizeof(int));
		return Kuint;
	case 's':
		*size = getnumlimit(h, fmt, sizeof(size_t));
		return Kstring;
	case 'c':
		*size = getnum(fmt, -1);
		if (*size == -1)
			luaL_error(h->L, "missing size for format option 'c'");
		return Kchar;
	case 'z':
		return Kzstr;
	case 'x':
		*size = 1;
		return Kpadding;
	case 'X':
		return Kpaddalign;
	case ' ':
		break;
	case '<':
		h->islittle = 1;
		break;
	case '>':
		h->islittle = 0;
		break;
	case '=':
		h->islittle = nativeendian.little;
		break;
	case '!':
		h->maxalign = getnumlimit(h, fmt, (offsetof(struct cD, u)));
		break;
	default:
		luaL_error(h->L, "invalid format option '%c'", opt);
	}
	return Knop;
}
static KOption getdetails(Header *h, size_t totalsize, const char **fmt, int *psize, int *ntoalign)
{
	KOption opt = getoption(h, fmt, psize);
	int align = *psize;
	if (opt == Kpaddalign)
	{
		if (**fmt == '\0' || getoption(h, fmt, &align) == Kchar || align == 0)
			luaL_argerror(h->L, 1, "invalid next option for option 'X'");
	}
	if (align <= 1 || opt == Kchar)
		*ntoalign = 0;
	else
	{
		if (align > h->maxalign)
			align = h->maxalign;
		if ((align & (align - 1)) != 0)
			luaL_argerror(h->L, 1, "format asks for alignment not power of 2");
		*ntoalign = (align - (int) (totalsize & (align - 1))) & (align - 1);
	}
	return opt;
}
static void packint(luaL_Buffer *b, lua_Unsigned n, int islittle, int size, int neg)
{
	char *buff = luaL_prepbuffsize(b, size);
	int i;
	buff[islittle ? 0 : size - 1] = (char) (n & ((1 << CHAR_BIT) - 1));
	for (i = 1; i < size; i++)
	{
		n >>= CHAR_BIT;
		buff[islittle ? i : size - 1 - i] = (char) (n & ((1 << CHAR_BIT) - 1));
	}
	if (neg && size > ((int) sizeof(lua_Integer)))
	{
		for (i = ((int) sizeof(lua_Integer)); i < size; i++)
			buff[islittle ? i : size - 1 - i] = (char) ((1 << CHAR_BIT) - 1);
	}
	((b)->n += (size));
}

static void copywithendian(char *dest, const char *src, int size, int islittle)
{
	if (islittle == nativeendian.little)
		memcpy(dest, src, size);
	else
	{
		dest += size - 1;
		while (size-- != 0)
			*(dest--) = *(src++);
	}
}

static int str_pack(lua_State *L)
{
	luaL_Buffer b;
	Header h;
	const char *fmt = (luaL_checklstring(L, (1), NULL));
	int arg = 1;
	size_t totalsize = 0;
	initheader(L, &h);
	lua_pushnil(L);
	luaL_buffinit(L, &b);
	while (*fmt != '\0')
	{
		int size, ntoalign;
		KOption opt = getdetails(&h, totalsize, &fmt, &size, &ntoalign);
		totalsize += ntoalign + size;
		while (ntoalign-- > 0)
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (0x00)));
		arg++;
		switch (opt)
		{
		case Kint:
		{
			lua_Integer n = luaL_checkinteger(L, arg);
			if (size < ((int) sizeof(lua_Integer)))
			{
				lua_Integer lim = (lua_Integer) 1 << ((size * CHAR_BIT) - 1);
				((void) ((-lim <= n && n < lim) || luaL_argerror(L, (arg), ("integer overflow"))));
			}
			packint(&b, (lua_Unsigned) n, h.islittle, size, (n < 0));
			break;
		}
		case Kuint:
		{
			lua_Integer n = luaL_checkinteger(L, arg);
			if (size < ((int) sizeof(lua_Integer)))
				((void) (((lua_Unsigned) n < ((lua_Unsigned) 1 << (size * CHAR_BIT))) ||
						 luaL_argerror(L, (arg), ("unsigned overflow"))));

			packint(&b, (lua_Unsigned) n, h.islittle, size, 0);
			break;
		}
		case Kfloat:
		{
			Ftypes u;
			char *buff = luaL_prepbuffsize(&b, size);
			lua_Number n = luaL_checknumber(L, arg);
			if (size == sizeof(u.f))
				u.f = (float) n;
			else if (size == sizeof(u.d))
				u.d = (double) n;
			else
				u.n = n;

			copywithendian(buff, (char *) &u, size, h.islittle);
			((&b)->n += (size));
			break;
		}
		case Kchar:
		{
			size_t len;
			const char *s = luaL_checklstring(L, arg, &len);
			((void) ((len <= (size_t) size) ||
					 luaL_argerror(L, (arg), ("string longer than given size"))));

			luaL_addlstring(&b, s, len);
			while (len++ < (size_t) size)
				((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
				 ((&b)->b[(&b)->n++] = (0x00)));
			break;
		}
		case Kstring:
		{
			size_t len;
			const char *s = luaL_checklstring(L, arg, &len);
			((void) ((size >= (int) sizeof(size_t) || len < ((size_t) 1 << (size * CHAR_BIT))) ||
					 luaL_argerror(L, (arg), ("string length does not fit in given size"))));

			packint(&b, (lua_Unsigned) len, h.islittle, size, 0);
			luaL_addlstring(&b, s, len);
			totalsize += len;
			break;
		}
		case Kzstr:
		{
			size_t len;
			const char *s = luaL_checklstring(L, arg, &len);
			((void) ((strlen(s) == len) || luaL_argerror(L, (arg), ("string contains zeros"))));
			luaL_addlstring(&b, s, len);
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = ('\0')));
			totalsize += len + 1;
			break;
		}
		case Kpadding:
			((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
			 ((&b)->b[(&b)->n++] = (0x00)));
		case Kpaddalign:
		case Knop:
			arg--;
			break;
		}
	}
	luaL_pushresult(&b);
	return 1;
}

static int str_packsize(lua_State *L)
{
	Header h;
	const char *fmt = (luaL_checklstring(L, (1), NULL));
	size_t totalsize = 0;
	initheader(L, &h);
	while (*fmt != '\0')
	{
		int size, ntoalign;
		KOption opt = getdetails(&h, totalsize, &fmt, &size, &ntoalign);
		((void) ((opt != Kstring && opt != Kzstr) ||
				 luaL_argerror(L, (1), ("variable-length format"))));

		size += ntoalign;
		((void) ((totalsize <=
				  (sizeof(size_t) < sizeof(int) ? ((size_t) (~(size_t) 0)) : (size_t) (INT_MAX)) -
					  size) ||
				 luaL_argerror(L, (1), ("format result too large"))));

		totalsize += size;
	}
	lua_pushinteger(L, (lua_Integer) totalsize);
	return 1;
}
static lua_Integer unpackint(lua_State *L, const char *str, int islittle, int size, int issigned)
{
	lua_Unsigned res = 0;
	int i;
	int limit = (size <= ((int) sizeof(lua_Integer))) ? size : ((int) sizeof(lua_Integer));
	for (i = limit - 1; i >= 0; i--)
	{
		res <<= CHAR_BIT;
		res |= (lua_Unsigned) (unsigned char) str[islittle ? i : size - 1 - i];
	}
	if (size < ((int) sizeof(lua_Integer)))
	{
		if (issigned)
		{
			lua_Unsigned mask = (lua_Unsigned) 1 << (size * CHAR_BIT - 1);
			res = ((res ^ mask) - mask);
		}
	}
	else if (size > ((int) sizeof(lua_Integer)))
	{
		int mask = (!issigned || (lua_Integer) res >= 0) ? 0 : ((1 << CHAR_BIT) - 1);
		for (i = limit; i < size; i++)
		{
			if ((unsigned char) str[islittle ? i : size - 1 - i] != mask)
				luaL_error(L, "%d-byte integer does not fit into Lua Integer", size);
		}
	}
	return (lua_Integer) res;
}

static int str_unpack(lua_State *L)
{
	Header h;
	const char *fmt = (luaL_checklstring(L, (1), NULL));
	size_t ld;
	const char *data = luaL_checklstring(L, 2, &ld);
	size_t pos = posrelatI(luaL_optinteger(L, 3, 1), ld) - 1;
	int n = 0;
	((void) ((pos <= ld) || luaL_argerror(L, (3), ("initial position out of string"))));
	initheader(L, &h);
	while (*fmt != '\0')
	{
		int size, ntoalign;
		KOption opt = getdetails(&h, pos, &fmt, &size, &ntoalign);
		((void) (((size_t) ntoalign + size <= ld - pos) ||
				 luaL_argerror(L, (2), ("data string too short"))));

		pos += ntoalign;

		luaL_checkstack(L, 2, "too many results");
		n++;
		switch (opt)
		{
		case Kint:
		case Kuint:
		{
			lua_Integer res = unpackint(L, data + pos, h.islittle, size, (opt == Kint));
			lua_pushinteger(L, res);
			break;
		}
		case Kfloat:
		{
			Ftypes u;
			lua_Number num;
			copywithendian((char *) &u, data + pos, size, h.islittle);
			if (size == sizeof(u.f))
				num = (lua_Number) u.f;
			else if (size == sizeof(u.d))
				num = (lua_Number) u.d;
			else
				num = u.n;
			lua_pushnumber(L, num);
			break;
		}
		case Kchar:
		{
			lua_pushlstring(L, data + pos, size);
			break;
		}
		case Kstring:
		{
			size_t len = (size_t) unpackint(L, data + pos, h.islittle, size, 0);
			((void) ((len <= ld - pos - size) || luaL_argerror(L, (2), ("data string too short"))));
			lua_pushlstring(L, data + pos + size, len);
			pos += len;
			break;
		}
		case Kzstr:
		{
			size_t len = strlen(data + pos);
			((void) ((pos + len < ld) ||
					 luaL_argerror(L, (2), ("unfinished string for format 'z'"))));

			lua_pushlstring(L, data + pos, len);
			pos += len + 1;
			break;
		}
		case Kpaddalign:
		case Kpadding:
		case Knop:
			n--;
			break;
		}
		pos += size;
	}
	lua_pushinteger(L, pos + 1);
	return n + 1;
}

static const luaL_Reg strlib[] = {
	{"byte", str_byte},		{"char", str_char},	  {"dump", str_dump}, {"find", str_find},
	{"format", str_format}, {"gmatch", gmatch},	  {"gsub", str_gsub}, {"len", str_len},
	{"lower", str_lower},	{"match", str_match}, {"rep", str_rep},	  {"reverse", str_reverse},
	{"sub", str_sub},		{"upper", str_upper}, {"pack", str_pack}, {"packsize", str_packsize},
	{"unpack", str_unpack}, {NULL, NULL}};

static void createmetatable(lua_State *L)
{

	lua_createtable(L, 0, sizeof(stringmetamethods) / sizeof((stringmetamethods)[0]) - 1);
	luaL_setfuncs(L, stringmetamethods, 0);
	lua_pushstring(L, ""
					  "");
	lua_pushvalue(L, -2);
	lua_setmetatable(L, -2);
	lua_settop(L, -(1) - 1);
	lua_pushvalue(L, -2);
	lua_setfield(L, -2, "__index");
	lua_settop(L, -(1) - 1);
}

extern int luaopen_string(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(strlib) / sizeof((strlib)[0]) - 1), luaL_setfuncs(L, strlib, 0));
	createmetatable(L);
	return 1;
}
