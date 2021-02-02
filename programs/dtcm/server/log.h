/* $XConsortium: log.h /main/5 1996/10/03 10:26:46 drk $ */
/*
 *  (c) Copyright 1993, 1994 Hewlett-Packard Company
 *  (c) Copyright 1993, 1994 International Business Machines Corp.
 *  (c) Copyright 1993, 1994 Novell, Inc.
 *  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 */

#ifndef _LOG_H
#define _LOG_H

#include "ansi_c.h"
#include "cm.h"
#include "rtable4.h"

#define _DtCMS_VERSION1	1
#define _DtCMS_VERSION4	4
#define _DtCMS_DEFAULT_LOG	"callog"
#define _DtCMS_DEFAULT_BAK	".calbak"
#define _DtCMS_DEFAULT_TMP	".caltmp"
#define _DtCMS_DEFAULT_DEL	".caldel"
#define	_DtCMS_DEFAULT_DIR	"/usr/spool/calendar"
#define	_DtCMS_DEFAULT_MODE	(S_IRUSR|S_IRGRP|S_IWGRP)

typedef enum {
	_DtCmsLogAdd, _DtCmsLogRemove
} _DtCmsLogOps; 

extern CSA_return_code	_DtCmsAppendAppt4ByFN P((char*, Appt_4*, _DtCmsLogOps));
extern CSA_return_code	_DtCmsAppendAppt4ByFD P((int, Appt_4*, _DtCmsLogOps));

extern CSA_return_code	_DtCmsAppendCalAttrsByFN P((char *file,
						  int size,
						  cms_attribute * attrs));
extern CSA_return_code	_DtCmsAppendCalAttrsByFD P((int f,
						  int size,
						  cms_attribute * attrs));

extern CSA_return_code	_DtCmsAppendEntryByFN P((char *,
						cms_entry *,
						_DtCmsLogOps));
extern CSA_return_code	_DtCmsAppendEntryByFD P((int,
						cms_entry *,
						_DtCmsLogOps));

extern CSA_return_code _DtCmsAppendHTableByFN P((char *file,
						uint size,
						char **names,
						int *types));

extern CSA_return_code _DtCmsAppendHTableByFD P((int fd,
						uint size,
						char **names,
						int *types));

extern CSA_return_code	_DtCmsAppendAccessByFN P((char*,
						int,
						Access_Entry_4 *));
extern CSA_return_code	_DtCmsAppendAccessByFD P((int, int, Access_Entry_4 *));

extern CSA_return_code	_DtCmsCreateLogV1 P((char*, char *));

extern CSA_return_code	_DtCmsCreateLogV2 P((char *owner, char *file));

extern CSA_return_code _DtCmsWriteVersionString P((char *file, int version));

extern int _DtCmsSetFileMode P((char *file,
				uid_t uid,
				gid_t gid,
				mode_t mode,
				boolean_t changeeuid,
				boolean_t printerr));

extern CSA_return_code	_DtCmsRemoveLog P((char *calendar, char *user));

extern char	*_DtCmsGetBakFN		P((char*));
extern char	*_DtCmsGetLogFN		P((char*));
extern char	*_DtCmsGetTmpFN		P((char*));
extern char	*_DtCmsGetDelFN		P((char*));

extern boolean_t _DtCmsPrintAppt4	P((caddr_t data));
extern void	_DtCmsPrintExceptions	P((int len, int *exceptions));

extern CSA_return_code	_DtCmsGetFileSize P((char *calendar, int *size));

extern void	_DtCmsTruncateFile	P((char *calendar, int size));

#endif
