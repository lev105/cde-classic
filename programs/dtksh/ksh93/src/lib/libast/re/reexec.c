/* $XConsortium: reexec.c /main/3 1995/11/01 18:22:33 rswiston $ */
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
#include "relib.h"

#include <ctype.h>

#define LISTINCREMENT	8

typedef struct
{
	Inst_t*		inst;	/* instruction of the thread		*/
	Subexp_t	se;	/* matched sub-expressions this thread	*/
} List_t;

/*
 * note optimization in addinst:
 * 	*p must be pending when addinst called; if *l has been looked
 *	at already, the optimization is a bug.
 */

static List_t*
newthread __PARAM__((register List_t* p, register Inst_t* ip, register Subexp_t* sep), (p, ip, sep)) __OTORP__(register List_t* p; register Inst_t* ip; register Subexp_t* sep;){
	for (; p->inst; p++)
		if (p->inst == ip)
		{
			if (sep->m[0].sp < p->se.m[0].sp) p->se = *sep;
			return(0);
		}
	p->inst = ip;
	p->se = *sep;
	(++p)->inst = 0;
	return(p);
}

static void
newmatch __PARAM__((register Subexp_t* mp, register Subexp_t* np), (mp, np)) __OTORP__(register Subexp_t* mp; register Subexp_t* np;){
	if (!mp->m[0].sp || np->m[0].sp < mp->m[0].sp || np->m[0].sp == mp->m[0].sp && np->m[0].ep > mp->m[0].ep)
		*mp = *np;
}

int
reexec __PARAM__((Re_program_t* aprogp, const char* starts), (aprogp, starts)) __OTORP__(Re_program_t* aprogp; const char* starts;){
	Re_program_t*		progp = (Re_program_t*)aprogp;
	register int		flag = 0;
	register Inst_t*	inst;
	register List_t*	tlp;
	register const char*	s;
	Subexp_t*		mp;
	int			checkstart;
	int			startchar;

	List_t*		tl;	/* this list, next list			*/
	List_t*		nl;	/* this list, next list			*/
	List_t*		tle;	/* ends of this and next list		*/
	List_t*		nle;	/* ends of this and next list		*/
	List_t*		list[2];
	List_t*		liste[2];
	int		match = 0;

	static int	listsize = LISTINCREMENT;
	static Subexp_t	sempty;	/* empty set of matches			*/


	startchar = progp->startinst->type < TOKEN ? progp->startinst->type : 0;
	mp = (progp->flags & RE_MATCH) ? &progp->subexp : 0;
	list[0] = 0;
 Restart:
	match = 0;
	checkstart = startchar;
	sempty.m[0].sp = 0;
	if (mp) mp->m[0].sp = mp->m[0].ep = 0;
	if (!list[0])
	{
		if (!(list[0] = newof(0, List_t, 2 * listsize, 0)))
			reerror("list overflow");
		list[1] = list[0] + listsize;
		liste[0] = list[0] + listsize - 1;
		liste[1] = list[1] + listsize - 1;
	}
	list[0][0].inst = list[1][0].inst = 0;

	/*
	 * execute machine once for each character, including terminal '\0'
	 */

	s = starts;
	do
	{
		/*
		 * fast check for first char
		 */

		if (checkstart && *s != startchar) continue;
		tl = list[flag];
		tle = liste[flag];
		nl = list[flag ^= 1];
		nle = liste[flag];
		nl->inst = 0;

		/*
		 * add first instruction to this list
		 */

		sempty.m[0].sp = (char*)s;
		newthread(tl, progp->startinst, &sempty);

		/*
		 * execute machine until this list is empty
		 */

		for (tlp = tl; inst = tlp->inst; tlp++)
		{
			/*
			 * assignment =
			 */
 Switchstmt:
			switch (inst->type)
			{
			case LBRA:
				tlp->se.m[inst->subid].sp = (char*)s;
				inst = inst->next;
				goto Switchstmt;
			case RBRA:
				tlp->se.m[inst->subid].ep = (char*)s;
				inst = inst->next;
				goto Switchstmt;
			case ANY:
				goto Addinst;
			case BOL:
				if (s == starts)
				{
					inst = inst->next;
					goto Switchstmt;
				}
				break;
			case EOL:
				if (!*s)
				{
					inst = inst->next;
					goto Switchstmt;
				}
				break;
			case BID:
				if (s == starts || !isalnum(*(s - 1)) && *(s - 1) != '_')
				{
					inst = inst->next;
					goto Switchstmt;
				}
				break;
			case EID:
				if (!*s || !isalnum(*s) && *s != '_')
				{
					inst = inst->next;
					goto Switchstmt;
				}
				break;
			case CCLASS:
				if (tstbit(inst->cclass, *s)) goto Addinst;
				break;
			case OR:
				/*
				 * evaluate right choice later
				 */

				if (newthread(tlp, inst->right, &tlp->se) == tle)
					goto Realloc;

				/*
				 * efficiency: advance and re-evaluate
				 */

				inst = inst->left;
				goto Switchstmt;
			case SUBEXPR:
				{
					const char*	ss;
					const char*	ms = (char*)tlp->se.m[inst->subid].sp;
					const char*	me = (char*)tlp->se.m[inst->subid].ep;

#if DEBUG
					{
						int	c;

						c = *me;
						*me = 0;
						error(-1, "subexpression %d ref=\"%s\"", inst->subid, ms);
						*me = c;
						error(-1, "subexpression %d src=\"%s\"", inst->subid, s);
					}
#endif
					if (ms == me)
					{
						inst = inst->next;
						goto Switchstmt;
					}
					for (ss = s; ms < me && *ss++ == *ms; ms++);
					if (ms == me)
					{
						s = ss - 1;
						goto Addinst;
					}
				}
				break;
			case END:
				/*
				 * match!
				 */

				match = 1;
				tlp->se.m[0].ep = (char*)s;
				if (mp) newmatch(mp, &tlp->se);
				break;
			default:
				/*
				 * regular character
				 */

				if (inst->type == *s)
				{
 Addinst:
					if (newthread(nl, inst->next, &tlp->se) == nle)
						goto Realloc;
				}
				break;
			}
		}
		checkstart = startchar && !nl->inst;
	} while (*s++);
	if (list[0]) free(list[0]);
	return(match);
 Realloc:
	free(list[0]);
	list[0] = 0;
	listsize += LISTINCREMENT;
	goto Restart;
}
