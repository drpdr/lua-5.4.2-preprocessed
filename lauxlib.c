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
static int findfield(lua_State *L, int objidx, int level)
{
	if (level == 0 || !(lua_type(L, (-1)) == 5))
		return 0;
	lua_pushnil(L);
	while (lua_next(L, -2))
	{
		if (lua_type(L, -2) == 4)
		{
			if (lua_rawequal(L, objidx, -1))
			{
				lua_settop(L, -(1) - 1);
				return 1;
			}
			else if (findfield(L, objidx, level - 1))
			{

				lua_pushstring(L, ""
								  ".");
				(lua_copy(L, -1, (-3)), lua_settop(L, -(1) - 1));
				lua_concat(L, 3);
				return 1;
			}
		}
		lua_settop(L, -(1) - 1);
	}
	return 0;
}

static int pushglobalfuncname(lua_State *L, lua_Debug *ar)
{
	int top = lua_gettop(L);
	lua_getinfo(L, "f", ar);
	lua_getfield(L, (-15000 - 1000), "_LOADED");
	if (findfield(L, top + 1, 2))
	{
		const char *name = lua_tolstring(L, (-1), NULL);
		if (strncmp(name,
					"_G"
					".",
					3) == 0)
		{
			lua_pushstring(L, name + 3);
			(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
		}
		lua_copy(L, -1, top + 1);
		lua_settop(L, top + 1);
		return 1;
	}
	else
	{
		lua_settop(L, top);
		return 0;
	}
}

static void pushfuncname(lua_State *L, lua_Debug *ar)
{
	if (pushglobalfuncname(L, ar))
	{
		lua_pushfstring(L, "function '%s'", lua_tolstring(L, (-1), NULL));
		(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
	}
	else if (*ar->namewhat != '\0')
		lua_pushfstring(L, "%s '%s'", ar->namewhat, ar->name);
	else if (*ar->what == 'm')
		lua_pushstring(L, ""
						  "main chunk");
	else if (*ar->what != 'C')
		lua_pushfstring(L, "function <%s:%d>", ar->short_src, ar->linedefined);
	else
		lua_pushstring(L, ""
						  "?");
}

static int lastlevel(lua_State *L)
{
	lua_Debug ar;
	int li = 1, le = 1;

	while (lua_getstack(L, le, &ar))
	{
		li = le;
		le *= 2;
	}

	while (li < le)
	{
		int m = (li + le) / 2;
		if (lua_getstack(L, m, &ar))
			li = m + 1;
		else
			le = m;
	}
	return le - 1;
}

extern void luaL_traceback(lua_State *L, lua_State *L1, const char *msg, int level)
{
	luaL_Buffer b;
	lua_Debug ar;
	int last = lastlevel(L1);
	int limit2show = (last - level > 10 + 11) ? 10 : -1;
	luaL_buffinit(L, &b);
	if (msg)
	{
		luaL_addstring(&b, msg);
		((void) ((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)),
		 ((&b)->b[(&b)->n++] = ('\n')));
	}
	luaL_addstring(&b, "stack traceback:");
	while (lua_getstack(L1, level++, &ar))
	{
		if (limit2show-- == 0)
		{
			int n = last - level - 11 + 1;
			lua_pushfstring(L, "\n\t...\t(skipping %d levels)", n);
			luaL_addvalue(&b);
			level += n;
		}
		else
		{
			lua_getinfo(L1, "Slnt", &ar);
			if (ar.currentline <= 0)
				lua_pushfstring(L, "\n\t%s: in ", ar.short_src);
			else
				lua_pushfstring(L, "\n\t%s:%d: in ", ar.short_src, ar.currentline);
			luaL_addvalue(&b);
			pushfuncname(L, &ar);
			luaL_addvalue(&b);
			if (ar.istailcall)
				luaL_addstring(&b, "\n\t(...tail calls...)");
		}
	}
	luaL_pushresult(&b);
}
extern int luaL_argerror(lua_State *L, int arg, const char *extramsg)
{
	lua_Debug ar;
	if (!lua_getstack(L, 0, &ar))
		return luaL_error(L, "bad argument #%d (%s)", arg, extramsg);
	lua_getinfo(L, "n", &ar);
	if (strcmp(ar.namewhat, "method") == 0)
	{
		arg--;
		if (arg == 0)
			return luaL_error(L, "calling '%s' on bad self (%s)", ar.name, extramsg);
	}
	if (ar.name == NULL)
		ar.name = (pushglobalfuncname(L, &ar)) ? lua_tolstring(L, (-1), NULL) : "?";
	return luaL_error(L, "bad argument #%d to '%s' (%s)", arg, ar.name, extramsg);
}

int luaL_typeerror(lua_State *L, int arg, const char *tname)
{
	const char *msg;
	const char *typearg;
	if (luaL_getmetafield(L, arg, "__name") == 4)
		typearg = lua_tolstring(L, (-1), NULL);
	else if (lua_type(L, arg) == 2)
		typearg = "light userdata";
	else
		typearg = lua_typename(L, lua_type(L, (arg)));
	msg = lua_pushfstring(L, "%s expected, got %s", tname, typearg);
	return luaL_argerror(L, arg, msg);
}

static void tag_error(lua_State *L, int arg, int tag)
{
	luaL_typeerror(L, arg, lua_typename(L, tag));
}

extern void luaL_where(lua_State *L, int level)
{
	lua_Debug ar;
	if (lua_getstack(L, level, &ar))
	{
		lua_getinfo(L, "Sl", &ar);
		if (ar.currentline > 0)
		{
			lua_pushfstring(L, "%s:%d: ", ar.short_src, ar.currentline);
			return;
		}
	}
	lua_pushfstring(L, "");
}

extern int luaL_error(lua_State *L, const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	luaL_where(L, 1);
	lua_pushvfstring(L, fmt, argp);
	va_end(argp);
	lua_concat(L, 2);
	return lua_error(L);
}

extern int luaL_fileresult(lua_State *L, int stat, const char *fname)
{
	int en = errno;
	if (stat)
	{
		lua_pushboolean(L, 1);
		return 1;
	}
	else
	{
		lua_pushnil(L);
		if (fname)
			lua_pushfstring(L, "%s: %s", fname, strerror(en));
		else
			lua_pushstring(L, strerror(en));
		lua_pushinteger(L, en);
		return 3;
	}
}
extern int luaL_execresult(lua_State *L, int stat)
{
	if (stat != 0 && errno != 0)
		return luaL_fileresult(L, 0, NULL);
	else
	{
		const char *what = "exit";
		;
		if (*what == 'e' && stat == 0)
			lua_pushboolean(L, 1);
		else
			lua_pushnil(L);
		lua_pushstring(L, what);
		lua_pushinteger(L, stat);
		return 3;
	}
}
extern int luaL_newmetatable(lua_State *L, const char *tname)
{
	if ((lua_getfield(L, (-15000 - 1000), (tname))) != 0)
		return 0;
	lua_settop(L, -(1) - 1);
	lua_createtable(L, 0, 2);
	lua_pushstring(L, tname);
	lua_setfield(L, -2, "__name");
	lua_pushvalue(L, -1);
	lua_setfield(L, (-15000 - 1000), tname);
	return 1;
}

extern void luaL_setmetatable(lua_State *L, const char *tname)
{
	(lua_getfield(L, (-15000 - 1000), (tname)));
	lua_setmetatable(L, -2);
}

extern void *luaL_testudata(lua_State *L, int ud, const char *tname)
{
	void *p = lua_touserdata(L, ud);
	if (p != NULL)
	{
		if (lua_getmetatable(L, ud))
		{
			(lua_getfield(L, (-15000 - 1000), (tname)));
			if (!lua_rawequal(L, -1, -2))
				p = NULL;
			lua_settop(L, -(2) - 1);
			return p;
		}
	}
	return NULL;
}

extern void *luaL_checkudata(lua_State *L, int ud, const char *tname)
{
	void *p = luaL_testudata(L, ud, tname);
	((void) ((p != NULL) || luaL_typeerror(L, (ud), (tname))));
	return p;
}
extern int luaL_checkoption(lua_State *L, int arg, const char *def, const char *const lst[])
{
	const char *name =
		(def) ? (luaL_optlstring(L, (arg), (def), NULL)) : (luaL_checklstring(L, (arg), NULL));
	int i;
	for (i = 0; lst[i]; i++)
		if (strcmp(lst[i], name) == 0)
			return i;
	return luaL_argerror(L, arg, lua_pushfstring(L, "invalid option '%s'", name));
}
extern void luaL_checkstack(lua_State *L, int space, const char *msg)
{
	if (!lua_checkstack(L, space))
	{
		if (msg)
			luaL_error(L, "stack overflow (%s)", msg);
		else
			luaL_error(L, "stack overflow");
	}
}

extern void luaL_checktype(lua_State *L, int arg, int t)
{
	if (lua_type(L, arg) != t)
		tag_error(L, arg, t);
}

extern void luaL_checkany(lua_State *L, int arg)
{
	if (lua_type(L, arg) == (-1))
		luaL_argerror(L, arg, "value expected");
}

extern const char *luaL_checklstring(lua_State *L, int arg, size_t *len)
{
	const char *s = lua_tolstring(L, arg, len);
	if (!s)
		tag_error(L, arg, 4);
	return s;
}

extern const char *luaL_optlstring(lua_State *L, int arg, const char *def, size_t *len)
{
	if ((lua_type(L, (arg)) <= 0))
	{
		if (len)
			*len = (def ? strlen(def) : 0);
		return def;
	}
	else
		return luaL_checklstring(L, arg, len);
}

extern lua_Number luaL_checknumber(lua_State *L, int arg)
{
	int isnum;
	lua_Number d = lua_tonumberx(L, arg, &isnum);
	if (!isnum)
		tag_error(L, arg, 3);
	return d;
}

extern lua_Number luaL_optnumber(lua_State *L, int arg, lua_Number def)
{
	return ((lua_type(L, ((arg))) <= 0) ? (def) : luaL_checknumber(L, (arg)));
}

static void interror(lua_State *L, int arg)
{
	if (lua_isnumber(L, arg))
		luaL_argerror(L, arg, "number has no integer representation");
	else
		tag_error(L, arg, 3);
}

extern lua_Integer luaL_checkinteger(lua_State *L, int arg)
{
	int isnum;
	lua_Integer d = lua_tointegerx(L, arg, &isnum);
	if (!isnum)
	{
		interror(L, arg);
	}
	return d;
}

extern lua_Integer luaL_optinteger(lua_State *L, int arg, lua_Integer def)
{
	return ((lua_type(L, ((arg))) <= 0) ? (def) : luaL_checkinteger(L, (arg)));
}
typedef struct UBox
{
	void *box;
	size_t bsize;
} UBox;

static void *resizebox(lua_State *L, int idx, size_t newsize)
{
	void *ud;
	lua_Alloc allocf = lua_getallocf(L, &ud);
	UBox *box = (UBox *) lua_touserdata(L, idx);
	void *temp = allocf(ud, box->box, box->bsize, newsize);
	if (temp == NULL && newsize > 0)
	{
		lua_pushstring(L, ""
						  "not enough memory");
		lua_error(L);
	}
	box->box = temp;
	box->bsize = newsize;
	return temp;
}

static int boxgc(lua_State *L)
{
	resizebox(L, 1, 0);
	return 0;
}

static const luaL_Reg boxmt[] = {{"__gc", boxgc}, {"__close", boxgc}, {NULL, NULL}};

static void newbox(lua_State *L)
{
	UBox *box = (UBox *) lua_newuserdatauv(L, sizeof(UBox), 0);
	box->box = NULL;
	box->bsize = 0;
	if (luaL_newmetatable(L, "_UBOX*"))
		luaL_setfuncs(L, boxmt, 0);
	lua_setmetatable(L, -2);
}
static size_t newbuffsize(luaL_Buffer *B, size_t sz)
{
	size_t newsize = B->size * 2;
	if (((size_t) (~(size_t) 0)) - sz < B->n)
		return luaL_error(B->L, "buffer too large");
	if (newsize < B->n + sz)
		newsize = B->n + sz;
	return newsize;
}

static char *prepbuffsize(luaL_Buffer *B, size_t sz, int boxidx)
{
	if (B->size - B->n >= sz)
		return B->b + B->n;
	else
	{
		lua_State *L = B->L;
		char *newbuff;
		size_t newsize = newbuffsize(B, sz);

		if (((B)->b != (B)->init.b))
			newbuff = (char *) resizebox(L, boxidx, newsize);
		else
		{
			lua_pushnil(L);
			newbox(L);

			lua_rotate(L, boxidx - 1, 2);
			lua_toclose(L, boxidx);
			newbuff = (char *) resizebox(L, boxidx, newsize);
			memcpy(newbuff, B->b, B->n * sizeof(char));
		}
		B->b = newbuff;
		B->size = newsize;
		return newbuff + B->n;
	}
}

extern char *luaL_prepbuffsize(luaL_Buffer *B, size_t sz)
{
	return prepbuffsize(B, sz, -1);
}

extern void luaL_addlstring(luaL_Buffer *B, const char *s, size_t l)
{
	if (l > 0)
	{
		char *b = prepbuffsize(B, l, -1);
		memcpy(b, s, l * sizeof(char));
		((B)->n += (l));
	}
}

extern void luaL_addstring(luaL_Buffer *B, const char *s)
{
	luaL_addlstring(B, s, strlen(s));
}

extern void luaL_pushresult(luaL_Buffer *B)
{
	lua_State *L = B->L;
	lua_pushlstring(L, B->b, B->n);
	if (((B)->b != (B)->init.b))
	{
		lua_copy(L, -1, -3);
		lua_settop(L, -(2) - 1);
	}
}

extern void luaL_pushresultsize(luaL_Buffer *B, size_t sz)
{
	((B)->n += (sz));
	luaL_pushresult(B);
}
extern void luaL_addvalue(luaL_Buffer *B)
{
	lua_State *L = B->L;
	size_t len;
	const char *s = lua_tolstring(L, -1, &len);
	char *b = prepbuffsize(B, len, -2);
	memcpy(b, s, len * sizeof(char));
	((B)->n += (len));
	lua_settop(L, -(1) - 1);
}

extern void luaL_buffinit(lua_State *L, luaL_Buffer *B)
{
	B->L = L;
	B->b = B->init.b;
	B->n = 0;
	B->size = ((int) (16 * sizeof(void *) * sizeof(lua_Number)));
}

extern char *luaL_buffinitsize(lua_State *L, luaL_Buffer *B, size_t sz)
{
	luaL_buffinit(L, B);
	return prepbuffsize(B, sz, -1);
}
extern int luaL_ref(lua_State *L, int t)
{
	int ref;
	if ((lua_type(L, (-1)) == 0))
	{
		lua_settop(L, -(1) - 1);
		return (-1);
	}
	t = lua_absindex(L, t);
	lua_rawgeti(L, t, 0);
	ref = (int) lua_tointegerx(L, (-1), NULL);
	lua_settop(L, -(1) - 1);
	if (ref != 0)
	{
		lua_rawgeti(L, t, ref);
		lua_rawseti(L, t, 0);
	}
	else
		ref = (int) lua_rawlen(L, t) + 1;
	lua_rawseti(L, t, ref);
	return ref;
}

extern void luaL_unref(lua_State *L, int t, int ref)
{
	if (ref >= 0)
	{
		t = lua_absindex(L, t);
		lua_rawgeti(L, t, 0);
		lua_rawseti(L, t, ref);
		lua_pushinteger(L, ref);
		lua_rawseti(L, t, 0);
	}
}
typedef struct LoadF
{
	int n;
	FILE *f;
	char buff[BUFSIZ];
} LoadF;

static const char *getF(lua_State *L, void *ud, size_t *size)
{
	LoadF *lf = (LoadF *) ud;
	(void) L;
	if (lf->n > 0)
	{
		*size = lf->n;
		lf->n = 0;
	}
	else
	{

		if (feof(lf->f))
			return NULL;
		*size = fread(lf->buff, 1, sizeof(lf->buff), lf->f);
	}
	return lf->buff;
}

static int errfile(lua_State *L, const char *what, int fnameindex)
{
	const char *serr = strerror(errno);
	const char *filename = lua_tolstring(L, (fnameindex), NULL) + 1;
	lua_pushfstring(L, "cannot %s %s: %s", what, filename, serr);
	(lua_rotate(L, (fnameindex), -1), lua_settop(L, -(1) - 1));
	return (5 + 1);
}

static int skipBOM(LoadF *lf)
{
	const char *p = "\xEF\xBB\xBF";
	int c;
	lf->n = 0;
	do
	{
		c = getc(lf->f);
		if (c == EOF || c != *(const unsigned char *) p++)
			return c;
		lf->buff[lf->n++] = c;
	} while (*p != '\0');
	lf->n = 0;
	return getc(lf->f);
}
static int skipcomment(LoadF *lf, int *cp)
{
	int c = *cp = skipBOM(lf);
	if (c == '#')
	{
		do
		{
			c = getc(lf->f);
		} while (c != EOF && c != '\n');
		*cp = getc(lf->f);
		return 1;
	}
	else
		return 0;
}

extern int luaL_loadfilex(lua_State *L, const char *filename, const char *mode)
{
	LoadF lf;
	int status, readstatus;
	int c;
	int fnameindex = lua_gettop(L) + 1;
	if (filename == NULL)
	{
		lua_pushstring(L, ""
						  "=stdin");
		lf.f = stdin;
	}
	else
	{
		lua_pushfstring(L, "@%s", filename);
		lf.f = fopen(filename, "r");
		if (lf.f == NULL)
			return errfile(L, "open", fnameindex);
	}
	if (skipcomment(&lf, &c))
		lf.buff[lf.n++] = '\n';
	if (c == "\x1bLua"[0] && filename)
	{
		lf.f = freopen(filename, "rb", lf.f);
		if (lf.f == NULL)
			return errfile(L, "reopen", fnameindex);
		skipcomment(&lf, &c);
	}
	if (c != EOF)
		lf.buff[lf.n++] = c;
	status = lua_load(L, getF, &lf, lua_tolstring(L, (-1), NULL), mode);
	readstatus = ferror(lf.f);
	if (filename)
		fclose(lf.f);
	if (readstatus)
	{
		lua_settop(L, fnameindex);
		return errfile(L, "read", fnameindex);
	}
	(lua_rotate(L, (fnameindex), -1), lua_settop(L, -(1) - 1));
	return status;
}

typedef struct LoadS
{
	const char *s;
	size_t size;
} LoadS;

static const char *getS(lua_State *L, void *ud, size_t *size)
{
	LoadS *ls = (LoadS *) ud;
	(void) L;
	if (ls->size == 0)
		return NULL;
	*size = ls->size;
	ls->size = 0;
	return ls->s;
}

extern int luaL_loadbufferx(lua_State *L, const char *buff, size_t size, const char *name,
							const char *mode)
{
	LoadS ls;
	ls.s = buff;
	ls.size = size;
	return lua_load(L, getS, &ls, name, mode);
}

extern int luaL_loadstring(lua_State *L, const char *s)
{
	return luaL_loadbufferx(L, s, strlen(s), s, NULL);
}

extern int luaL_getmetafield(lua_State *L, int obj, const char *event)
{
	if (!lua_getmetatable(L, obj))
		return 0;
	else
	{
		int tt;
		lua_pushstring(L, event);
		tt = lua_rawget(L, -2);
		if (tt == 0)
			lua_settop(L, -(2) - 1);
		else
			(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
		return tt;
	}
}

extern int luaL_callmeta(lua_State *L, int obj, const char *event)
{
	obj = lua_absindex(L, obj);
	if (luaL_getmetafield(L, obj, event) == 0)
		return 0;
	lua_pushvalue(L, obj);
	lua_callk(L, (1), (1), 0, NULL);
	return 1;
}

extern lua_Integer luaL_len(lua_State *L, int idx)
{
	lua_Integer l;
	int isnum;
	lua_len(L, idx);
	l = lua_tointegerx(L, -1, &isnum);
	if (!isnum)
		luaL_error(L, "object length is not an integer");
	lua_settop(L, -(1) - 1);
	return l;
}

extern const char *luaL_tolstring(lua_State *L, int idx, size_t *len)
{
	if (luaL_callmeta(L, idx, "__tostring"))
	{
		if (!lua_isstring(L, -1))
			luaL_error(L, "'__tostring' must return a string");
	}
	else
	{
		switch (lua_type(L, idx))
		{
		case 3:
		{
			if (lua_isinteger(L, idx))
				lua_pushfstring(L, "%I", (LUA_INTEGER) lua_tointegerx(L, (idx), NULL));
			else
				lua_pushfstring(L, "%f", (double) lua_tonumberx(L, (idx), NULL));
			break;
		}
		case 4:
			lua_pushvalue(L, idx);
			break;
		case 1:
			lua_pushstring(L, (lua_toboolean(L, idx) ? "true" : "false"));
			break;
		case 0:
			lua_pushstring(L, ""
							  "nil");
			break;
		default:
		{
			int tt = luaL_getmetafield(L, idx, "__name");
			const char *kind =
				(tt == 4) ? lua_tolstring(L, (-1), NULL) : lua_typename(L, lua_type(L, (idx)));
			lua_pushfstring(L, "%s: %p", kind, lua_topointer(L, idx));
			if (tt != 0)
				(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
			break;
		}
		}
	}
	return lua_tolstring(L, -1, len);
}

extern void luaL_setfuncs(lua_State *L, const luaL_Reg *l, int nup)
{
	luaL_checkstack(L, nup, "too many upvalues");
	for (; l->name != NULL; l++)
	{
		if (l->func == NULL)
			lua_pushboolean(L, 0);
		else
		{
			int i;
			for (i = 0; i < nup; i++)
				lua_pushvalue(L, -nup);
			lua_pushcclosure(L, l->func, nup);
		}
		lua_setfield(L, -(nup + 2), l->name);
	}
	lua_settop(L, -(nup) -1);
}

extern int luaL_getsubtable(lua_State *L, int idx, const char *fname)
{
	if (lua_getfield(L, idx, fname) == 5)
		return 1;
	else
	{
		lua_settop(L, -(1) - 1);
		idx = lua_absindex(L, idx);
		lua_createtable(L, 0, 0);
		lua_pushvalue(L, -1);
		lua_setfield(L, idx, fname);
		return 0;
	}
}
extern void luaL_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb)
{
	luaL_getsubtable(L, (-15000 - 1000), "_LOADED");
	lua_getfield(L, -1, modname);
	if (!lua_toboolean(L, -1))
	{
		lua_settop(L, -(1) - 1);
		lua_pushcclosure(L, (openf), 0);
		lua_pushstring(L, modname);
		lua_callk(L, (1), (1), 0, NULL);
		lua_pushvalue(L, -1);
		lua_setfield(L, -3, modname);
	}
	(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
	if (glb)
	{
		lua_pushvalue(L, -1);
		lua_setglobal(L, modname);
	}
}

extern void luaL_addgsub(luaL_Buffer *b, const char *s, const char *p, const char *r)
{
	const char *wild;
	size_t l = strlen(p);
	while ((wild = strstr(s, p)) != NULL)
	{
		luaL_addlstring(b, s, wild - s);
		luaL_addstring(b, r);
		s = wild + l;
	}
	luaL_addstring(b, s);
}

extern const char *luaL_gsub(lua_State *L, const char *s, const char *p, const char *r)
{
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	luaL_addgsub(&b, s, p, r);
	luaL_pushresult(&b);
	return lua_tolstring(L, (-1), NULL);
}

static void *l_alloc(void *ud, void *ptr, size_t osize, size_t nsize)
{
	(void) ud;
	(void) osize;
	if (nsize == 0)
	{
		free(ptr);
		return NULL;
	}
	else
		return realloc(ptr, nsize);
}

static int panic(lua_State *L)
{
	const char *msg = lua_tolstring(L, (-1), NULL);
	if (msg == NULL)
		msg = "error object is not a string";
	(fprintf(stderr, ("PANIC: unprotected error in call to Lua API (%s)\n"), (msg)),
	 fflush(stderr));

	return 0;
}
static void warnfoff(void *ud, const char *message, int tocont);
static void warnfon(void *ud, const char *message, int tocont);
static void warnfcont(void *ud, const char *message, int tocont);

static int checkcontrol(lua_State *L, const char *message, int tocont)
{
	if (tocont || *(message++) != '@')
		return 0;
	else
	{
		if (strcmp(message, "off") == 0)
			lua_setwarnf(L, warnfoff, L);
		else if (strcmp(message, "on") == 0)
			lua_setwarnf(L, warnfon, L);
		return 1;
	}
}

static void warnfoff(void *ud, const char *message, int tocont)
{
	checkcontrol((lua_State *) ud, message, tocont);
}

static void warnfcont(void *ud, const char *message, int tocont)
{
	lua_State *L = (lua_State *) ud;
	(fprintf(stderr, ("%s"), (message)), fflush(stderr));
	if (tocont)
		lua_setwarnf(L, warnfcont, L);
	else
	{
		(fprintf(stderr, ("%s"), ("\n")), fflush(stderr));
		lua_setwarnf(L, warnfon, L);
	}
}

static void warnfon(void *ud, const char *message, int tocont)
{
	if (checkcontrol((lua_State *) ud, message, tocont))
		return;
	(fprintf(stderr, ("%s"), ("Lua warning: ")), fflush(stderr));
	warnfcont(ud, message, tocont);
}

extern lua_State *luaL_newstate(void)
{
	lua_State *L = lua_newstate(l_alloc, NULL);
	if (L)
	{
		lua_atpanic(L, &panic);
		lua_setwarnf(L, warnfoff, L);
	}
	return L;
}

extern void luaL_checkversion_(lua_State *L, lua_Number ver, size_t sz)
{
	lua_Number v = lua_version(L);
	if (sz != (sizeof(lua_Integer) * 16 + sizeof(lua_Number)))
		luaL_error(L, "core and library have incompatible numeric types");
	else if (v != ver)
		luaL_error(L, "version mismatch: app. needs %f, Lua core provides %f", (double) ver,
				   (double) v);
}
