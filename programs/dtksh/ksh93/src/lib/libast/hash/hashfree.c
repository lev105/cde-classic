/* $XConsortium: hashfree.c /main/3 1995/11/01 17:32:20 rswiston $ */
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
#include "hashlib.h"

/*
 * free (remove) a hash table
 * can be called for partially constructed tables
 * scope covered table pointer is returned
 * root info freed when last reference freed
 */

Hash_table_t*
hashfree __PARAM__((register Hash_table_t* tab), (tab)) __OTORP__(register Hash_table_t* tab;){
	register Hash_bucket_t**	sp;
	register Hash_bucket_t*		b;
	register Hash_bucket_t*		p;
	Hash_bucket_t**			sx;
	Hash_root_t*			rp;
	Hash_table_t*			tp;
	HASHfree			freevalue;
	HASHfree			freebucket;
	HASHregion			region;
	__V_*				handle;

	if (!tab) return(0);
	if (tab->table)
	{
		freebucket = 0;
		freevalue = 0;
		if (tab->root->local->free)
		{
			if (tab->root->flags & HASH_BUCKET) freebucket = tab->root->local->free;
			else freevalue = tab->root->local->free;
		}
		if (region = tab->root->local->region)
			handle = tab->root->local->handle;
		sx = &tab->table[tab->size];
		sp = &tab->table[0];
		while (sp < sx)
		{
			b = *sp++;
			while (b)
			{
				p = b;
				b = b->next;
				if (freebucket) (*freebucket)((char*)p);
				else if (freevalue && p->value) (*freevalue)(p->value);
				if (!(p->hash & HASH_KEEP))
				{
					if (region) (*region)(handle, p, 0, 0);
					else free(p);
				}
				else if (p->hash & HASH_HIDES)
				{
					p->hash &= ~HASH_HIDES;
					p->name = ((Hash_bucket_t*)p->name)->name;
				}
			}
		}
		if ((tab->flags & (HASH_RESIZE|HASH_STATIC)) != HASH_STATIC)
		{
			if (region) (*region)(handle, tab->table, 0, 0);
			else free(tab->table);
		}
	}
	else region = 0;
	if (tab->root)
	{
		if (!region)
		{
			/*
			 * remove from the table lists
			 */

			if ((tp = tab->root->references) != tab)
			{
				for (; tp; tp = tp->next)
					if (tp->next == tab)
					{
						tp->next = tab->next;
						break;
					}
			}
			else if (!(tab->root->references = tp->next))
			{
				if ((rp = hash_info.list) != tab->root)
				{
					for (; rp; rp = rp->next)
						if (rp->next == tab->root)
						{
							rp->next = tab->root->next;
							break;
						}
				}
				else hash_info.list = rp->next;
			}
		}
		if (!(tab->root->references))
		{
			if (tab->root->local)
				free(tab->root->local);
			if (region) (*region)(handle, tab->root, 0, 0);
			else free(tab->root);
		}
	}
	if (tp = tab->scope) tp->frozen--;
	if (region) (*region)(handle, tab, 0, 0);
	else free(tab);
	return(tp);
}