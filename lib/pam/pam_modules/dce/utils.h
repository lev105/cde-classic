/* $XConsortium: utils.h /main/5 1996/05/09 04:27:45 drk $ */

/*
 * Copyright (c) 1992-1995, by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _UTILS_H
#define	_UTILS_H

#ident  "@(#)utils.h 1.17     96/01/10 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <security/pam_appl.h>
#include <dce/sec_login.h>

#define	DCE_DATA "SUNW-DCE-AUTH-DATA"

/*
 * PAM_MSG macro for return of internationalized text
 */

#define	PAM_MSG(pamh, number, string)\
	(char *) __pam_get_i18n_msg(pamh, "pam_dce", 1, number, string)

typedef struct {
	sec_login_handle_t	login_context;
	int			debug;
	int			warn;
	int			auth_status;
	boolean32		reset_passwd;
	boolean32		passwd_expired;
	sec_login_auth_src_t	auth_src;
} dce_module_data_t;

void
pam_sec_login_free_context(
	int			pam_status,
	sec_login_handle_t	*login_context,
	error_status_t		*st);

unsigned char *
get_dce_error_message(
	error_status_t	status,
	unsigned char	*buffer
);

int
get_pw_uid(char *user, uid_t *uid);

#ifdef	__cplusplus
}
#endif

#endif /* _DCE_UTILS_H */
