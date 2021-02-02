/* $XConsortium: streval.h /main/3 1995/11/01 16:43:32 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Advanced Software Technology Department            *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                    {research,attmail}!dgk                    *
*                                                              *
***************************************************************/

/* : : generated by proto : : */
                  
#ifndef SEQPOINT
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

/*
 * G. S. Fowler
 * D. G. Korn
 * AT&T Bell Laboratories
 *
 * long integer arithmetic expression evaluator
 */

/* The following only is needed for const */
#include	<ast.h>
#include	<math.h>

struct lval
{
	char	*value;
	double	(*fun) __PROTO__((double));
	short	flag;
	char	isfloat;
};

struct mathtab
{
	char	fname[4];
	double	(*fnptr) __PROTO__((double));
};

#define MAXPREC		15	/* maximum precision level */
#define SEQPOINT	0200	/* sequence point */
#define NOASSIGN	0100	/* assignment legal with this operator */
#define RASSOC		040	/* right associative */
#define NOFLOAT		020	/* illegal with floating point */
#define PRECMASK	017	/* precision bit mask */

#define A_EOF		1
#define A_NEQ		2
#define A_NOT		3
#define A_MOD		4
#define A_ANDAND	5
#define A_AND		6
#define A_LPAR		7
#define A_RPAR		8
#define A_TIMES		9
#define A_PLUSPLUS	10
#define A_PLUS		11
#define A_COMMA		12
#define A_MINUSMINUS	13
#define A_MINUS		14
#define A_DIV		15
#define A_LSHIFT	16
#define A_LE		17
#define A_LT		18
#define A_EQ		19
#define A_ASSIGN	20
#define A_COLON		21
#define A_RSHIFT	22
#define A_GE		23
#define A_GT		24
#define A_QCOLON	25
#define A_QUEST		26
#define A_XOR		27
#define A_OROR		28
#define A_OR		29
#define A_REG		30
#define A_DIG		31
#define A_DOT		32


/* define error messages */
extern __MANGLE__ const unsigned char	strval_precedence[33];
extern __MANGLE__ const char		strval_states[64];
extern __MANGLE__ const char		e_moretokens[];
extern __MANGLE__ const char		e_paren[];
extern __MANGLE__ const char		e_badnum[];
extern __MANGLE__ const char		e_badcolon[];
extern __MANGLE__ const char		e_recursive[];
extern __MANGLE__ const char		e_divzero[];
extern __MANGLE__ const char		e_synbad[];
extern __MANGLE__ const char		e_notlvalue[];
extern __MANGLE__ const char		e_function[];
extern __MANGLE__ const char		e_questcolon[];
extern __MANGLE__ const char		e_incompatible[];
extern __MANGLE__ const char		e_domain[];
extern __MANGLE__ const char		e_overflow[];
extern __MANGLE__ const char		e_singularity[];
extern __MANGLE__ const struct 		mathtab shtab_math[];

/* function code for the convert function */

#define LOOKUP	0
#define ASSIGN	1
#define VALUE	2
#define ERRMSG	3

extern __MANGLE__ double strval __PROTO__((const char*,char**,double(*)(const char**,struct lval*,int,double)));

#endif /* !SEQPOINT */
