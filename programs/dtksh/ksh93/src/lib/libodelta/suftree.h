/* $XConsortium: suftree.h /main/3 1995/11/01 19:11:36 rswiston $ */
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
                  
#ifndef _SUFTREE_H
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

#define _SUFTREE_H

#include <ast.h>

/* the type of list elements we play with */
typedef char	Element;

/* for suffix trees, a tree node looks like this */
typedef struct _ts_
{
	Element		*_label;	/* substring labeling the edge */
	long int	_length;	/* the length of the string */
	struct _ts_	*_child;	/* list of children */
	struct _ts_	*_sibling;	/* link for the child list */
	union
	{	/* these two fields are mutual exclusive */
		struct _ts_	*_link;		/* sub-link */
		Element		*_suffix;	/* suffix */
	}	_uls_;
}	Suftree;

/* short hand for various fields in a tree node */
#define	LABEL(n)	((n)->_label)
#define LENGTH(n)	((n)->_length)
#define CHILD(n)	((n)->_child)
#define SIBLING(n)	((n)->_sibling)
#define LINK(n)		((n)->_uls_._link)
#define SUFFIX(n)	((n)->_uls_._suffix)

/* the following definitions are not to be seen by users */
#ifdef _IN_SUF_TREE
#ifdef DEBUG
#define ASSERT(p)	if(!(p)) abort();
#else
#define ASSERT(p)
#endif /*DEBUG*/

#ifndef NULL
#define NULL	(0L)
#endif /*NULL*/

#define ALLOCSIZE	256	/* amount of nodes to allocate each time */
#define NEXT(n)		((n)->_sibling)

#endif /*_IN_SUF_TREE*/

extern __MANGLE__ Suftree*		bldsuftree __PROTO__((Element*, long));
extern __MANGLE__ void		delsuftree __PROTO__((Suftree*));
extern __MANGLE__ long		mtchsuftree __PROTO__((Suftree*, Element*, long, Element**));

#endif