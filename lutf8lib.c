

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
typedef unsigned long utfint;
static lua_Integer u_posrelat(lua_Integer pos, size_t len)
{
	if (pos >= 0)
		return pos;
	else if (0u - (size_t) pos > len)
		return 0;
	else
		return (lua_Integer) len + pos + 1;
}
static const char *utf8_decode(const char *s, utfint *val, int strict)
{
	static const utfint limits[] = {~(utfint) 0, 0x80, 0x800, 0x10000u, 0x200000u, 0x4000000u};
	unsigned int c = (unsigned char) s[0];
	utfint res = 0;
	if (c < 0x80)
		res = c;
	else
	{
		int count = 0;
		for (; c & 0x40; c <<= 1)
		{
			unsigned int cc = (unsigned char) s[++count];
			if ((cc & 0xC0) != 0x80)
				return NULL;
			res = (res << 6) | (cc & 0x3F);
		}
		res |= ((utfint) (c & 0x7F) << (count * 5));
		if (count > 5 || res > 0x7FFFFFFFu || res < limits[count])
			return NULL;
		s += count;
	}
	if (strict)
	{

		if (res > 0x10FFFFu || (0xD800u <= res && res <= 0xDFFFu))
			return NULL;
	}
	if (val)
		*val = res;
	return s + 1;
}

static int utflen(lua_State *L)
{
	lua_Integer n = 0;
	size_t len;
	const char *s = luaL_checklstring(L, 1, &len);
	lua_Integer posi = u_posrelat(luaL_optinteger(L, 2, 1), len);
	lua_Integer posj = u_posrelat(luaL_optinteger(L, 3, -1), len);
	int lax = lua_toboolean(L, 4);
	((void) ((1 <= posi && --posi <= (lua_Integer) len) ||
			 luaL_argerror(L, (2), ("initial position out of bounds"))));

	((void) ((--posj < (lua_Integer) len) ||
			 luaL_argerror(L, (3), ("final position out of bounds"))));

	while (posi <= posj)
	{
		const char *s1 = utf8_decode(s + posi, NULL, !lax);
		if (s1 == NULL)
		{
			lua_pushnil(L);
			lua_pushinteger(L, posi + 1);
			return 2;
		}
		posi = s1 - s;
		n++;
	}
	lua_pushinteger(L, n);
	return 1;
}

static int codepoint(lua_State *L)
{
	size_t len;
	const char *s = luaL_checklstring(L, 1, &len);
	lua_Integer posi = u_posrelat(luaL_optinteger(L, 2, 1), len);
	lua_Integer pose = u_posrelat(luaL_optinteger(L, 3, posi), len);
	int lax = lua_toboolean(L, 4);
	int n;
	const char *se;
	((void) ((posi >= 1) || luaL_argerror(L, (2), ("out of bounds"))));
	((void) ((pose <= (lua_Integer) len) || luaL_argerror(L, (3), ("out of bounds"))));
	if (posi > pose)
		return 0;
	if (pose - posi >= INT_MAX)
		return luaL_error(L, "string slice too long");
	n = (int) (pose - posi) + 1;
	luaL_checkstack(L, n, "string slice too long");
	n = 0;
	se = s + pose;
	for (s += posi - 1; s < se;)
	{
		utfint code;
		s = utf8_decode(s, &code, !lax);
		if (s == NULL)
			return luaL_error(L, "invalid UTF-8 code");
		lua_pushinteger(L, code);
		n++;
	}
	return n;
}

static void pushutfchar(lua_State *L, int arg)
{
	lua_Unsigned code = (lua_Unsigned) luaL_checkinteger(L, arg);
	((void) ((code <= 0x7FFFFFFFu) || luaL_argerror(L, (arg), ("value out of range"))));
	lua_pushfstring(L, "%U", (long) code);
}

static int utfchar(lua_State *L)
{
	int n = lua_gettop(L);
	if (n == 1)
		pushutfchar(L, 1);
	else
	{
		int i;
		luaL_Buffer b;
		luaL_buffinit(L, &b);
		for (i = 1; i <= n; i++)
		{
			pushutfchar(L, i);
			luaL_addvalue(&b);
		}
		luaL_pushresult(&b);
	}
	return 1;
}

static int byteoffset(lua_State *L)
{
	size_t len;
	const char *s = luaL_checklstring(L, 1, &len);
	lua_Integer n = luaL_checkinteger(L, 2);
	lua_Integer posi = (n >= 0) ? 1 : len + 1;
	posi = u_posrelat(luaL_optinteger(L, 3, posi), len);
	((void) ((1 <= posi && --posi <= (lua_Integer) len) ||
			 luaL_argerror(L, (3), ("position out of bounds"))));

	if (n == 0)
	{

		while (posi > 0 && ((*(s + posi) & 0xC0) == 0x80))
			posi--;
	}
	else
	{
		if (((*(s + posi) & 0xC0) == 0x80))
			return luaL_error(L, "initial position is a continuation byte");
		if (n < 0)
		{
			while (n < 0 && posi > 0)
			{
				do
				{
					posi--;
				} while (posi > 0 && ((*(s + posi) & 0xC0) == 0x80));
				n++;
			}
		}
		else
		{
			n--;
			while (n > 0 && posi < (lua_Integer) len)
			{
				do
				{
					posi++;
				} while (((*(s + posi) & 0xC0) == 0x80));
				n--;
			}
		}
	}
	if (n == 0)
		lua_pushinteger(L, posi + 1);
	else
		lua_pushnil(L);
	return 1;
}

static int iter_aux(lua_State *L, int strict)
{
	size_t len;
	const char *s = luaL_checklstring(L, 1, &len);
	lua_Integer n = lua_tointegerx(L, (2), NULL) - 1;
	if (n < 0)
		n = 0;
	else if (n < (lua_Integer) len)
	{
		n++;
		while (((*(s + n) & 0xC0) == 0x80))
			n++;
	}
	if (n >= (lua_Integer) len)
		return 0;
	else
	{
		utfint code;
		const char *next = utf8_decode(s + n, &code, strict);
		if (next == NULL)
			return luaL_error(L, "invalid UTF-8 code");
		lua_pushinteger(L, n + 1);
		lua_pushinteger(L, code);
		return 2;
	}
}

static int iter_auxstrict(lua_State *L)
{
	return iter_aux(L, 1);
}

static int iter_auxlax(lua_State *L)
{
	return iter_aux(L, 0);
}

static int iter_codes(lua_State *L)
{
	int lax = lua_toboolean(L, 2);
	(luaL_checklstring(L, (1), NULL));
	lua_pushcclosure(L, (lax ? iter_auxlax : iter_auxstrict), 0);
	lua_pushvalue(L, 1);
	lua_pushinteger(L, 0);
	return 3;
}

static const luaL_Reg funcs[] = {{"offset", byteoffset}, {"codepoint", codepoint},
								 {"char", utfchar},		 {"len", utflen},
								 {"codes", iter_codes},

								 {"charpattern", NULL},	 {NULL, NULL}};

extern int luaopen_utf8(lua_State *L)
{
	(luaL_checkversion_(L, 504, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))),
	 lua_createtable(L, 0, sizeof(funcs) / sizeof((funcs)[0]) - 1), luaL_setfuncs(L, funcs, 0));
	lua_pushlstring(L, "[\0-\x7F\xC2-\xFD][\x80-\xBF]*",
					sizeof("[\0-\x7F\xC2-\xFD][\x80-\xBF]*") / sizeof(char) - 1);
	lua_setfield(L, -2, "charpattern");
	return 1;
}
