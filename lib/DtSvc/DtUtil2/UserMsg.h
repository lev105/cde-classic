/* $TOG: UserMsg.h /main/6 1998/04/09 17:50:49 mgreess $ */
/*
 * (c) Copyright 1995 Digital Equipment Corporation.
 * (c) Copyright 1988, 1993, 1994, 1995 Hewlett-Packard Company
 * (c) Copyright 1993, 1994, 1995 International Business Machines Corp.
 * (c) Copyright 1993, 1994, 1995 Sun Microsystems, Inc.
 * (c) Copyright 1993, 1994, 1995 Novell, Inc. 
 * (c) Copyright 1995 FUJITSU LIMITED.
 * (c) Copyright 1995 Hitachi.
 */

/* -*-C-*-
********************************************************************************
*
* File:         usermsg.h
* Description:  Header for error logging routines
* Status:       Experimental (Do Not Distribute)
*
********************************************************************************
*/

#ifndef _usermsg_h
#define _usermsg_h

#include <X11/Intrinsic.h>

#ifndef __STDC__
#  ifndef const
#    define const
#  endif
#endif

#include <bms/XeUserMsg.h>

typedef enum {
  DtIgnore,
  DtInformation,
  DtWarning,
  DtError,
  DtFatalError,
  DtInternalError
} DtSeverity;


extern void _DtSimpleError( 
                        char *progName,
                        DtSeverity severity,
                        char *help,
                        char *format,
                        ...) ;
extern void _DtSimpleErrnoError( 
                        char *progName,
                        DtSeverity severity,
                        char *help,
                        char *format,
                        ...) ;

#define DtProgName  XeProgName

extern _DtPrintDefaultError(
        Display *dpy,
        XErrorEvent *event,
        char *msg );

#define _DTPRINTDEFAULTERROR_BUFSIZE 1024

extern _DtPrintDefaultErrorSafe(
        Display *dpy,
        XErrorEvent *event,
        char *msg,
	int bytes);

/*
    DESCRIPTION:

        Supply the standard Xerror output to a buffer (instead of stederr)
        so client can do what it wants with it.  Also don't exit.  Allow
client to decide what to do. 

        An appropriate thing to do would be to pass the buffer to 
        DtSimpleError() and return. ie. In your error callback:

    {
    char errmsg[1024];
    int ret ;
    ret = _DtPrintDefaultError (style.display, rep, errmsg);
    DtSimpleError(DtWarning, "><An X Error has occurred...continuing" ,
                             errmsg, NULL);
    return ret;
    }

    SYNOPSIS:

        int _DtPrintDefaultError (dpy, event, msg)

        Display *dpy;       The application's display structure.

        XErrorEvent *event; Error event returned to error callback.

        char *msg;          Buffer returning the formatted text of 
                            the error message.  It won't be more than
                            1024 bytes.

*/

#endif /* _usermsg_h */
/* DON'T ADD STUFF AFTER THIS #endif */
