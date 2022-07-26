static int llex(LexState *ls, SemInfo *seminfo)
{
	((ls->buff)->n = 0);
	for (;;)
	{
		switch (ls->current)
		{
		case '\n':
		case '\r':
		{
			inclinenumber(ls);
			break;
		}
		case ' ':
		case '\f':
		case '\t':
		case '\v':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			break;
		}
		case '-':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (ls->current != '-')
				return '-';

			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (ls->current == '[')
			{
				size_t sep = skip_sep(ls);
				((ls->buff)->n = 0);
				if (sep >= 2)
				{
					read_long_string(ls, ((void *) 0), sep);
					((ls->buff)->n = 0);
					break;
				}
			}

			while (!(ls->current == '\n' || ls->current == '\r') && ls->current != (-1))
				(ls->current =
					 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			break;
		}
		case '[':
		{
			size_t sep = skip_sep(ls);
			if (sep >= 2)
			{
				read_long_string(ls, seminfo, sep);
				return TK_STRING;
			}
			else if (sep == 0)
				lexerror(ls, "invalid long string delimiter", TK_STRING);
			return '[';
		}
		case '=':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_EQ;
			else
				return '=';
		}
		case '<':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_LE;
			else if (check_next1(ls, '<'))
				return TK_SHL;
			else
				return '<';
		}
		case '>':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_GE;
			else if (check_next1(ls, '>'))
				return TK_SHR;
			else
				return '>';
		}
		case '/':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '/'))
				return TK_IDIV;
			else
				return '/';
		}
		case '~':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '='))
				return TK_NE;
			else
				return '~';
		}
		case ':':
		{
			(ls->current =
				 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, ':'))
				return TK_DBCOLON;
			else
				return ':';
		}
		case '"':
		case '\'':
		{
			read_string(ls, ls->current, seminfo);
			return TK_STRING;
		}
		case '.':
		{
			(save(ls, ls->current),
			 (ls->current =
				  (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z))));
			if (check_next1(ls, '.'))
			{
				if (check_next1(ls, '.'))
					return TK_DOTS;
				else
					return TK_CONCAT;
			}
			else if (!(luai_ctype_[(ls->current) + 1] & ((1 << (1)))))
				return '.';
			else
				return read_numeral(ls, seminfo);
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
			return read_numeral(ls, seminfo);
		}
		case (-1):
		{
			return TK_EOS;
		}
		default:
		{
			if ((luai_ctype_[(ls->current) + 1] & ((1 << (0)))))
			{
				TString *ts;
				do
				{
					(save(ls, ls->current),
					 (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++)))
														: luaZ_fill(ls->z))));
				} while ((luai_ctype_[(ls->current) + 1] & (((1 << (0)) | (1 << (1))))));
				ts = luaX_newstring(ls, ((ls->buff)->buffer), ((ls->buff)->n));
				seminfo->ts = ts;
				if (((ts)->tt == ((4) | ((0) << 4)) && (ts)->extra > 0))
					return ts->extra - 1 + ((127 * 2 + 1) + 1);
				else
				{
					return TK_NAME;
				}
			}
			else
			{
				int c = ls->current;
				(ls->current =
					 (((ls->z)->n--) > 0 ? ((unsigned char) ((*(ls->z)->p++))) : luaZ_fill(ls->z)));
				return c;
			}
		}
		}
	}
}
