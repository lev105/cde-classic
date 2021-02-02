/* $XConsortium: fmtls.c /main/3 1995/11/01 18:43:43 rswiston $ */
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
#include <ls.h>
#include <tm.h>

#ifndef LS_W_MAX
#define LS_W_MAX	128
#endif

/*
 * ls formatter
 *
 *	buf	results placed here
 *	name	file name
 *	st	file stat buffer
 *	info	optional info
 *	link	link text if != 0
 *	flags	LS_* flags
 *
 *	return	end of formatted buf
 */

char*
fmtls __PARAM__((char* buf, const char* name, register struct stat* st, const char* info, const char* link, register int flags), (buf, name, st, info, link, flags)) __OTORP__(char* buf; const char* name; register struct stat* st; const char* info; const char* link; register int flags;){
	register char*		s;
	time_t			tm;

	s = buf;
	if (flags & LS_INUMBER)
		s += sfsprintf(s, LS_W_MAX, "%*lu ", LS_W_INUMBER - 1, (unsigned long)st->st_ino);
	if (flags & LS_BLOCKS)
		s += sfsprintf(s, LS_W_MAX, "%*lu ", LS_W_BLOCKS - 1, (unsigned long)iblocks(st));
	if (flags & LS_LONG)
	{
		s += sfsprintf(s, LS_W_MAX, "%s%3u", fmtmode(st->st_mode, flags & LS_EXTERNAL), (unsigned int)st->st_nlink);
		if (!(flags & LS_NOUSER))
		{
			if (flags & LS_NUMBER) s += sfsprintf(s, LS_W_MAX, " %-*d", LS_W_NAME - 1, st->st_uid);
			else s += sfsprintf(s, LS_W_MAX, " %-*s", LS_W_NAME - 1, fmtuid(st->st_uid));
		}
		if (!(flags & LS_NOGROUP))
		{
			if (flags & LS_NUMBER) s += sfsprintf(s, LS_W_MAX, " %-*d", LS_W_NAME - 1, st->st_gid);
			else s += sfsprintf(s, LS_W_MAX, " %-*s", LS_W_NAME - 1, fmtgid(st->st_gid));
		}
		if (S_ISBLK(st->st_mode) || S_ISCHR(st->st_mode)) s += sfsprintf(s, LS_W_MAX, "%8s ", fmtdev(st));
		else s += sfsprintf(s, LS_W_MAX, "%8lu ", (unsigned long)st->st_size);
		tm = (flags & LS_ATIME) ? st->st_atime : (flags & LS_CTIME) ? st->st_ctime : st->st_mtime;
		s = tmform(s, "%?%l", &tm);
		*s++ = ' ';
	}
	if (info)
	{
		while (*s = *info++) s++;
		*s++ = ' ';
	}
	while (*s = *name++) s++;
	if (flags & LS_MARK)
	{
		if (S_ISDIR(st->st_mode)) *s++ = '/';
#ifdef S_ISLNK
		else if (S_ISLNK(st->st_mode)) *s++ = '@';
#endif
		else if (st->st_mode & (S_IXUSR|S_IXGRP|S_IXOTH)) *s++ = '*';
	}
	if (link)
	{
		s += sfsprintf(s, LS_W_MAX, " %s %s",
#ifdef S_ISLNK
			S_ISLNK(st->st_mode) ? "->" :
#endif
				"==", link);
	}
	*s = 0;
	return(s);
}
