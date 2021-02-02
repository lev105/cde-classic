/* $XConsortium: limits.c /main/3 1995/11/01 16:32:55 rswiston $ */
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
#include	<ast.h>
#include	"ulimit.h"

#define size_resource(a,b) ((a)|((b)<<11))	

/*
 * This is the list of resouce limits controlled by ulimit
 * This command requires getrlimit(), vlimit(), or ulimit()
 */

#ifndef _no_ulimit 
const Shtable_t shtab_limits[] =
{
	{"time(seconds)       ",	size_resource(1,RLIMIT_CPU)},
#   ifdef RLIMIT_FSIZE
	{"file(blocks)        ",	size_resource(512,RLIMIT_FSIZE)},
#   else
	{"file(blocks)        ",	size_resource(1,2)},
#   endif /* RLIMIT_FSIZE */
	{"data(kbytes)        ",	size_resource(1024,RLIMIT_DATA)},
	{"stack(kbytes)       ",	size_resource(1024,RLIMIT_STACK)},
	{"memory(kbytes)      ",	size_resource(1024,RLIMIT_RSS)},
	{"coredump(blocks)    ",	size_resource(512,RLIMIT_CORE)},
	{"nofiles(descriptors)",	size_resource(1,RLIMIT_NOFILE)},
	{"vmemory(kbytes)     ",	size_resource(1024,RLIMIT_VMEM)}
};

const char e_unlimited[] = "unlimited";

#endif