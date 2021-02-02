/* $XConsortium: ansi_c.c /main/1 1996/04/21 19:25:03 drk $
 *
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1996 Hewlett-Packard Company.
 * (c) Copyright 1996 International Business Machines Corp.
 * (c) Copyright 1993-1996 Sun Microsystems, Inc.
 * (c) Copyright 1996 Novell, Inc. 
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 */

#include <ctype.h>
#include "ansi_c.h"

#ifdef NEED_STRCASECMP
/*
 * In case strcasecmp and strncasecmp are not provided by the system
 * here are ones which do the trick.
 */

int
strcasecmp(register const char *s1,
	   register const char *s2)
{
    register int c1, c2;

    while (*s1 && *s2) {
	c1 = isupper(*s1) ? tolower(*s1) : *s1;
	c2 = isupper(*s2) ? tolower(*s2) : *s2;
	if (c1 != c2)
	    return (c1 - c2);
	s1++;
	s2++;
    }
    return (int) (*s1 - *s2);
}


int
strncasecmp(register const char *s1,
	    register const char *s2,
	    register size_t count)
{
    register int c1, c2;

    if (!count)
      return 0;

    while (*s1 && *s2) {
	c1 = isupper(*s1) ? tolower(*s1) : *s1;
	c2 = isupper(*s2) ? tolower(*s2) : *s2;
	if ((c1 != c2) || (! --count))
	    return (c1 - c2);
	s1++;
	s2++;
    }
    return (int) (*s1 - *s2);
}
#else
static int unused = 0;		/* Make the compiler happy. */
#endif
