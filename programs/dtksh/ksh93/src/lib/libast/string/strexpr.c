/* $XConsortium: strexpr.c /main/2 1996/05/08 19:59:30 drk $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif
#include <ast.h>
#include <ctype.h>

#define getchr(ex)	(*(ex)->nextchr++)
#define peekchr(ex)	(*(ex)->nextchr)
#define ungetchr(ex)	((ex)->nextchr--)

#define error(ex,msg)	return(seterror(ex,msg))

typedef struct				/* expression handle		*/
{
	char*		nextchr;	/* next expression char		*/
	char*		errchr;		/* next char after error	*/
	char*		errmsg;		/* error message text		*/
	long		(*convert) __PROTO__((const char*, char**, __V_*));
	__V_*		handle;		/* user convert handle		*/
} Expr_t;

/*
 * set error message string
 */

static long
seterror __PARAM__((register Expr_t* ex, char* msg), (ex, msg)) __OTORP__(register Expr_t* ex; char* msg;){
	if (!ex->errmsg) ex->errmsg = msg;
	ex->errchr = ex->nextchr;
	ex->nextchr = "";
	return(0);
}

/*   
 * evaluate a subexpression with precedence
 */

static long
expr __PARAM__((register Expr_t* ex, register int precedence), (ex, precedence)) __OTORP__(register Expr_t* ex; register int precedence;){
	register int	c;
	register long	n;
	register long	x;
	char*		pos;
	int		operand = 1;

	while (c = getchr(ex), isspace(c));
	switch (c)
	{
	case 0:
		ungetchr(ex);
		if (!precedence) return(0);
		error(ex, "more tokens expected");
	case '-':
		n = -expr(ex, 13);
		break;
	case '+':
		n = expr(ex, 13);
		break;
	case '!':
		n = !expr(ex, 13);
		break;
	case '~':
		n = ~expr(ex, 13);
		break;
	default:
		ungetchr(ex);
		n = 0;
		operand = 0;
		break;
	}
	for (;;)
	{
		switch (c = getchr(ex))
		{
		case 0:
			goto done;
		case ')':
			if (!precedence) error(ex, "too many )'s");
			goto done;
		case '(':
			n = expr(ex, 1);
			if (getchr(ex) != ')')
			{
				ungetchr(ex);
				error(ex, "closing ) expected");
			}
		gotoperand:
			if (operand) error(ex, "operator expected");
			operand = 1;
			continue;
		case '?':
			if (precedence > 1) goto done;
			if (peekchr(ex) == ':')
			{
				getchr(ex);
				x = expr(ex, 2);
				if (!n) n = x;
			}
			else
			{
				x = expr(ex, 2);
				if (getchr(ex) != ':')
				{
					ungetchr(ex);
					error(ex, ": expected for ? operator");
				}
				if (n)
				{
					n = x;
					expr(ex, 2);
				}
				else n = expr(ex, 2);
			}
			break;
		case ':':
			goto done;
		case '|':
			if (peekchr(ex) == '|')
			{
				if (precedence > 2) goto done;
				getchr(ex);
				x = expr(ex, 3);
				n = n || x;
			}
			else
			{
				if (precedence > 4) goto done;
				x = expr(ex, 5);
				n |= x;
			}
			break;
		case '^':
			if (precedence > 5) goto done;
			x = expr(ex, 6);
			n ^= x;
			break;
		case '&':
			if (peekchr(ex) == '&')
			{
				if (precedence > 3) goto done;
				getchr(ex);
				x = expr(ex, 4);
				n = n && x;
			}
			else
			{
				if (precedence > 6) goto done;
				x = expr(ex, 7);
				n &= x;
			}
			break;
		case '=':
		case '!':
			if (peekchr(ex) != '=') error(ex, "operator syntax error");
			if (precedence > 7) goto done;
			getchr(ex);
			x = expr(ex, 8);
			if (c == '=') n = n == x;
			else n = n != x;
			break;
		case '<':
		case '>':
			if (peekchr(ex) == c)
			{
				if (precedence > 9) goto done;
				getchr(ex);
				x = expr(ex, 10);
				if (c == '<') n <<= x;
				else n >>= x;
			}
			else
			{
				if (precedence > 8) goto done;
				if (peekchr(ex) == '=')
				{
					getchr(ex);
					x = expr(ex, 9);
					if (c == '<') n = n <= x;
					else n = n >= x;
				}
				else
				{
					x = expr(ex, 9);
					if (c == '<') n = n < x;
					else n = n > x;
				}
			}
			break;
		case '+':
		case '-':
			if (precedence > 10) goto done;
			x = expr(ex, 11);
			if (c == '+') n +=  x;
			else n -= x;
			break;
		case '*':
		case '/':
		case '%':
			if (precedence > 11) goto done;
			x = expr(ex, 12);
			if (c == '*') n *= x;
			else if (x == 0) error(ex, "divide by zero");
			else if (c == '/') n /= x;
			else n %= x;
			break;
		default:
			if (isspace(c)) continue;
			pos = --ex->nextchr;
			if (isdigit(c)) n = strton(ex->nextchr, &ex->nextchr, NiL, 0);
			else if (ex->convert) n = (*ex->convert)(ex->nextchr, &ex->nextchr, ex->handle);
			if (ex->nextchr == pos) error(ex, "syntax error");
			goto gotoperand;
		}
		if (ex->errmsg) return(0);
		if (!operand) error(ex, "operand expected");
	}
 done:
	ungetchr(ex);
	if (!operand) error(ex, "operand expected");
	return(n);
}

/*
 * evaluate an integer arithmetic expression in s
 *
 * (long)(*convert)(const char* string, char** end, void* handle)
 * is a user supplied conversion routine that is called when unknown
 * chars are encountered * in s string points to the part to be
 * converted and end is adjusted to point to the next non-converted
 * character; if string is 0 then end points to an error message string
 *
 * NOTE: (*convert)() may call strexpr(ex, )
 */

long
strexpr __PARAM__((const char* s, char** end, long(*convert)(const char*, char**, __V_*), __V_* handle), (s, end, convert, handle)) __OTORP__(const char* s; char** end; long(*convert)(); __V_* handle;){
	long	n;
	Expr_t	ex;

	ex.nextchr = (char*)s;
	ex.errmsg = 0;
	ex.convert = convert;
	ex.handle = handle;
	n = expr(&ex, 0);
	if (peekchr(&ex) == ':')
		seterror(&ex, "invalid use of :");
	if (ex.errmsg)
	{
		if (convert) (*convert)(NiL, &ex.errmsg, handle);
		ex.nextchr = ex.errchr;
		n = 0;
	}
	if (end) *end = ex.nextchr;
	return(n);
}
