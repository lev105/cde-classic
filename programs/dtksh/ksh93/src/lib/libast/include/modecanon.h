/* $XConsortium: modecanon.h /main/3 1995/11/01 17:37:38 rswiston $ */
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
                  
/*
 * Glenn Fowler
 * AT&T Bell Laboratories
 *
 * canonical mode_t representation
 */

#ifndef _MODECANON_H
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

#define _MODECANON_H

#define X_ITYPE(m)	((m)&X_IFMT)

#define	X_IFMT		0170000
#define	X_IFSOCK	0140000
#define	X_IFLNK		0120000
#define	X_IFCTG		0110000
#define	X_IFREG		0100000
#define	X_IFBLK		0060000
#define	X_IFDIR		0040000
#define	X_IFCHR		0020000
#define	X_IFIFO		0010000

#define X_IPERM		0007777
#define	X_ISUID		0004000
#define	X_ISGID		0002000
#define	X_ISVTX		0001000
#define	X_IRUSR		0000400
#define	X_IWUSR		0000200
#define	X_IXUSR		0000100
#define	X_IRGRP		0000040
#define	X_IWGRP		0000020
#define	X_IXGRP		0000010
#define	X_IROTH		0000004
#define	X_IWOTH		0000002
#define	X_IXOTH		0000001

#define X_IRWXU		(X_IRUSR|X_IWUSR|X_IXUSR)
#define X_IRWXG		(X_IRGRP|X_IWGRP|X_IXGRP)
#define X_IRWXO		(X_IROTH|X_IWOTH|X_IXOTH)

#endif
