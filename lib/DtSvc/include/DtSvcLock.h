/* $XConsortium: DtSvcLock.h /main/6 1996/08/28 17:58:14 rswiston $ */
/*                                                                      *
 * (c) Copyright 1996 Hewlett-Packard Company                           *
 * (c) Copyright 1996 International Business Machines Corp.             *
 * (c) Copyright 1996 Sun Microsystems, Inc.                            *
 * (c) Copyright 1996 Novell, Inc.                                      *
 * (c) Copyright 1996 Digital Equipment Corporation.			*
 * (c) Copyright 1996 FUJITSU LIMITED.					*
 * (c) Copyright 1996 Hitachi.						*
 */

#ifndef	_DtSvc_Lock_h
#define	_DtSvc_Lock_h

/********    Conditionally defined macros for thread_safe DtSvc ******/
#ifdef XTHREADS
#define _DtSvcWidgetToAppContext(w) \
        XtAppContext app = XtWidgetToApplicationContext(w)
#define _DtSvcDisplayToAppContext(d) \
        XtAppContext app = XtDisplayToApplicationContext(d)
#define _DtSvcAppLock(app) XtAppLock(app)
#define _DtSvcAppUnlock(app) XtAppUnlock(app)

/*
 * NOTE: To use _DtSvcApp{Lock,Unlock}Default(), your file
 * must either include <Dt/DtP.h> or declare _DtAppContext
 * as an external variable, i.e. "extern XtAppContext _DtAppContext;"
 */
#define _DtSvcAppLockDefault() \
	if (_DtAppContext != (XtAppContext)NULL) XtAppLock(_DtAppContext)
#define _DtSvcAppUnlockDefault() \
	if (_DtAppContext != (XtAppContext)NULL) XtAppUnlock(_DtAppContext)

#define _DtSvcProcessLock() XtProcessLock()
#define _DtSvcProcessUnlock() XtProcessUnlock()
#else /* XTHREADS */
#define _DtSvcWidgetToAppContext(w)
#define _DtSvcDisplayToAppContext(d)
#define _DtSvcAppLock(app)
#define _DtSvcAppUnlock(app)
#define _DtSvcAppLockDefault()
#define _DtSvcAppUnlockDefault()
#define _DtSvcProcessLock()
#define _DtSvcProcessUnlock()
#endif /* XTHREADS */

#endif	/* _DtSvc_Lock_h */
/* DON'T ADD ANYTHING AFTER THIS #endif... */
