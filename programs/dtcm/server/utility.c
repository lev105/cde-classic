/* $XConsortium: utility.c /main/4 1995/11/09 12:54:25 rswiston $ */
/*
 *  (c) Copyright 1993, 1994 Hewlett-Packard Company
 *  (c) Copyright 1993, 1994 International Business Machines Corp.
 *  (c) Copyright 1993, 1994 Novell, Inc.
 *  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 */

#include <EUSCompat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>
#if defined(SunOS) || defined(USL) || defined(__uxp__)
#include <netdb.h>
#include <sys/systeminfo.h>
#endif

#include "utility.h"
#include "lutil.h"

extern char * strdup(const char *);

/*
 * calendar_name@host[.domain] -> calendar_name
 */
extern char *
_DtCmsTarget2Name(char *target)
{
        return(_DtCmGetPrefix(target, '@'));
}
 
/*
 * calendar_name@host[.domain] -> host[.domain]
 */
extern char *
_DtCmsTarget2Location(char *target)
{
	char *ptr;

	if (target == NULL)
		return (NULL);

	if (ptr = strchr(target, '@')) {
		return (strdup(++ptr));
	} else
		return (NULL);
}
 
/*
 * calendar_name@host[.domain] -> host
 */
extern char *
_DtCmsTarget2Host(char *target)
{
        char *location, *host;
 
        if ((location = _DtCmsTarget2Location(target)) != NULL) {
                host = _DtCmGetPrefix(location, '.');
                free(location);
                return(host);
        } else
                return(NULL);
}

/*
 * calendar_name@host[.domain] -> domain
 */
extern char *
_DtCmsTarget2Domain(char *target)
{
        char *location, *domain, *ptr;
 
        if ((location = _DtCmsTarget2Location(target)) != NULL) {
		if (ptr = strchr(location, '.'))
			domain = strdup(++ptr);
		else
			domain = NULL;
                free(location);
                return(domain);
        } else
                return(NULL);
}
