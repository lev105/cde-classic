/* $XConsortium: misc.h /main/7 1996/04/08 15:58:10 cde-fuj $ */
/***********************************************************
Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Digital or MIT not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

(c) Copyright 1995 FUJITSU LIMITED
This is source code modified by FUJITSU LIMITED under the Joint
Development Agreement for the CDEnext PST.
This is unpublished proprietary source code of FUJITSU LIMITED

******************************************************************/
#ifndef MISC_H
#define MISC_H 1
/*
 *  X internal definitions 
 *
 */


extern unsigned long globalSerialNumber;
extern unsigned long serverGeneration;

#ifndef NULL
#if __STDC__ && !NOSTDHDRS
#include <stddef.h>
#else
#define NULL            0
#endif
#endif

#ifdef __uxp__
#define MAXSCREENS	5
#else /* !__uxp__ */
#define MAXSCREENS	3
#endif /* !__uxp__ */
#define MAXCLIENTS	128
#define MAXFORMATS	8
#define MAXVISUALS_PER_SCREEN 50

typedef unsigned char *pointer;
typedef int Bool;
typedef unsigned long PIXEL;
typedef unsigned long ATOM;


#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif
#include "os.h" 	/* for ALLOCATE_LOCAL and DEALLOCATE_LOCAL */

#define NullBox ((BoxPtr)0)
#define MILLI_PER_MIN (1000 * 60)
#define MILLI_PER_SECOND (1000)

    /* this next is used with None and ParentRelative to tell
       PaintWin() what to use to paint the background. Also used
       in the macro IS_VALID_PIXMAP */

#define USE_BACKGROUND_PIXEL 3
#define USE_BORDER_PIXEL 3


/* byte swap a long literal */
#define lswapl(x) ((((x) & 0xff) << 24) |\
		   (((x) & 0xff00) << 8) |\
		   (((x) & 0xff0000) >> 8) |\
		   (((x) >> 24) & 0xff))

/* byte swap a short literal */
#define lswaps(x) ((((x) & 0xff) << 8) | (((x) >> 8) & 0xff))

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#ifndef abs
#define abs(a) ((a) > 0 ? (a) : -(a))
#endif
#ifndef fabs
#define fabs(a) ((a) > 0.0 ? (a) : -(a))	/* floating absolute value */
#endif
#define sign(x) ((x) < 0 ? -1 : ((x) > 0 ? 1 : 0))
/* this assumes b > 0 */
#define modulus(a, b, d)    if (((d) = (a) % (b)) < 0) (d) += (b)
/*
 * return the least significant bit in x which is set
 *
 * This works on 1's complement and 2's complement machines.
 * If you care about the extra instruction on 2's complement
 * machines, change to ((x) & (-(x)))
 */
#define lowbit(x) ((x) & (~(x) + 1))

#define MAXSHORT 32767
#define MINSHORT -MAXSHORT 


/* some macros to help swap requests, replies, and events */

#define LengthRestB(stuff) \
    (((unsigned long)stuff->length << 2) - sizeof(*stuff))

#define LengthRestS(stuff) \
    (((unsigned long)stuff->length << 1) - (sizeof(*stuff) >> 1))

#define LengthRestL(stuff) \
    ((unsigned long)stuff->length - (sizeof(*stuff) >> 2))

#define SwapRestS(stuff) \
    SwapShorts((short *)(stuff + 1), LengthRestS(stuff))

#define SwapRestL(stuff) \
    SwapLongs((long *)(stuff + 1), LengthRestL(stuff))

/* byte swap a long */
#define swapl(x, n) n = ((char *) (x))[0];\
		 ((char *) (x))[0] = ((char *) (x))[3];\
		 ((char *) (x))[3] = n;\
		 n = ((char *) (x))[1];\
		 ((char *) (x))[1] = ((char *) (x))[2];\
		 ((char *) (x))[2] = n;

/* byte swap a short */
#define swaps(x, n) n = ((char *) (x))[0];\
		 ((char *) (x))[0] = ((char *) (x))[1];\
		 ((char *) (x))[1] = n

/* copy long from src to dst byteswapping on the way */
#define cpswapl(src, dst) \
                 ((char *)&(dst))[0] = ((char *) &(src))[3];\
                 ((char *)&(dst))[1] = ((char *) &(src))[2];\
                 ((char *)&(dst))[2] = ((char *) &(src))[1];\
                 ((char *)&(dst))[3] = ((char *) &(src))[0];

/* copy short from src to dst byteswapping on the way */
#define cpswaps(src, dst)\
		 ((char *) &(dst))[0] = ((char *) &(src))[1];\
		 ((char *) &(dst))[1] = ((char *) &(src))[0];

extern void SwapLongs();
extern void SwapShorts();

typedef struct _DDXPoint *DDXPointPtr;
typedef struct _Box *BoxPtr;

#endif /* MISC_H */
