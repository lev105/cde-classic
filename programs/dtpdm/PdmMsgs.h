/* $XConsortium: PdmMsgs.h /main/3 1996/08/12 18:42:31 cde-hp $ */
/*
 * dtpdm/PrintMsgsP.h
 */
/*
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1996 Hewlett-Packard Company.
 * (c) Copyright 1996 International Business Machines Corp.
 * (c) Copyright 1996 Sun Microsystems, Inc.
 * (c) Copyright 1996 Novell, Inc. 
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 */
#ifndef _PdmMsgs_h
#define _PdmMsgs_h

#ifdef I18N_MSG
#include <nl_types.h>
#define DTPDM_GETMESSAGE(set, number, string) \
    DtPdmGetMessage(set, number, string)

#else /* I18N_MSG */
#define DTPDM_GETMESSAGE(set, number, string) (string)
#endif /* I18N_MSG */

/*** const causes the HP compiler to complain.  Remove reference until   ***
 *** the build and integration people can figure out how to get this to  ***
 *** work.                                                               ***/

/* #define CONST	const */
#define CONST

#define PDM_MSG_ERR_X_LOCALE DTPDM_GETMESSAGE(MS_DtPdmMsg, 1, DtPdmMsg_0001)
#define PDM_MSG_TRAY_AUTO_SELECT DTPDM_GETMESSAGE(MS_DtPdmMsg, 2, DtPdmMsg_0002)
#define PDM_MSG_SIZE_DEFAULT DTPDM_GETMESSAGE(MS_DtPdmMsg, 3, DtPdmMsg_0003)
#define PDM_MSG_WARN_MSS DTPDM_GETMESSAGE(MS_DtPdmMsg, 4, DtPdmMsg_0004)
#define PDM_MSG_WARN_ITM DTPDM_GETMESSAGE(MS_DtPdmMsg, 5, DtPdmMsg_0005)
#define PDM_MSG_WARN_DOC_FMT DTPDM_GETMESSAGE(MS_DtPdmMsg, 6, DtPdmMsg_0006)

extern CONST char DtPdmMsg_0001[];
extern CONST char DtPdmMsg_0002[];
extern CONST char DtPdmMsg_0003[];
extern CONST char DtPdmMsg_0004[];
extern CONST char DtPdmMsg_0005[];
extern CONST char DtPdmMsg_0006[];

/* 
 * Message sets
 */
#define	MS_DtPdmOid		1
#define	MS_DtPdmMsg		2

#ifdef I18N_MSG

/* Message IDs */

extern const char * DtPdmGetMessage(
				    int set,
				    int n,
				    const char * s);

#endif /* I18N_MSG */

#endif /* _PdmMsgs_h */
