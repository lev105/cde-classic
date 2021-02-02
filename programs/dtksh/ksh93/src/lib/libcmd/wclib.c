/* $XConsortium: wclib.c /main/3 1995/11/01 19:09:27 rswiston $ */
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
#include <cmdlib.h>
#include <wc.h>
#include <ctype.h>

#define endline(c)	(((signed char)-1)<0?(c)<0:(c)==((char)-1))

Wc_t *wc_init __PARAM__((char *space), (space)) __OTORP__(char *space;){
	register int  n;
	Wc_t *wp;

	if(!(wp = (Wc_t*)stakalloc(sizeof(Wc_t))))
		return(0);
	if(space)
		memcpy(wp->space, space, (1<<CHAR_BIT));
	else
	{
		for(n=(1<<CHAR_BIT);--n >=0;)
			wp->space[n] = (isspace(n)!=0);
		wp->space['\n'] = -1;
	}
	return(wp);
}

/*
 * compute the line, word, and character count for file <fd>
 */
wc_count __PARAM__((Wc_t *wp, Sfio_t *fd), (wp, fd)) __OTORP__(Wc_t *wp; Sfio_t *fd;){
	register signed char	*space = wp->space;
	register unsigned char	*cp;
	register long		nwords;
	register int		c;
	register unsigned char	*endbuff;
	register int		lasttype = 1;
	unsigned int		lastchar;
	unsigned char		*buff;
	wp->lines = nwords = wp->chars = 0;
	sfset(fd,SF_WRITE,1);
	while(1)
	{
		/* fill next buffer and check for end-of-file */
		if (!(buff = (unsigned char*)sfreserve(fd, 0, 0)) || (c = sfslen()) <= 0)
			break;
		sfread(fd,(char*)(cp=buff),c);
		wp->chars += c;
		/* check to see whether first character terminates word */
		if(!lasttype && space[*cp])
			nwords++;
		lastchar = cp[--c];
		cp[c] = '\n';
		endbuff = cp+c;
		c = lasttype;
		/* process each buffer */
		while(1)
		{
			/* process spaces and new-lines */
			do
			{
				if(endline(c))
				{
					/* check for end of buffer */
					if(cp>endbuff)
						goto eob;
					wp->lines++;
				}
			}
			while(c=space[*cp++]);
			/* skip over word characters */
			while(!(c=space[*cp++]));
			nwords++;
		}
	eob:
		if((cp -= 2) >= buff)
			c = space[*cp];
		else
			c  = lasttype;
		lasttype = space[lastchar];
		/* see if was in word */
		if(!c && !lasttype)
			nwords--;
	}
	wp->words = nwords;
	if(endline(lasttype))
		wp->lines++;
	else if(!lasttype)
		wp->words++;
	return(0);
}