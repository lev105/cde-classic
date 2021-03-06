/* $XConsortium: rhosts_auth.c /main/5 1996/05/09 04:29:04 drk $ */

/*
 * Copyright (c) 1992-1995, by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ident  "@(#)rhosts_auth.c 1.19     96/02/02 SMI"

#include "unix_headers.h"

/*
 * pam_sm_auth_netuser	- Checks if the user is allowed remote access
 */

int
pam_sm_authenticate(
	pam_handle_t	*pamh,
	int	flags,
	int	argc,
	const char	**argv)
{
	char *host = NULL, *lusername = NULL;
	struct passwd pwd;
	char pwd_buffer[1024];
	int	is_superuser;
	char	*rusername;
	int	err;
	int	i;
	int	debug = 0;

	for (i = 0; i < argc; i++) {
		if (strcasecmp(argv[i], "debug") == 0)
			debug = 1;
		else
			syslog(LOG_DEBUG, "illegal option %s", argv[i]);
	}

	if (pam_get_item(pamh, PAM_USER, (void **) &lusername) != PAM_SUCCESS)
		return (PAM_SERVICE_ERR);
	if (pam_get_item(pamh, PAM_RHOST, (void **) &host) != PAM_SUCCESS)
		return (PAM_SERVICE_ERR);
	if (pam_get_item(pamh, PAM_RUSER, (void **)&rusername) != PAM_SUCCESS)
		return (PAM_SERVICE_ERR);

	if (debug) {
		syslog(LOG_DEBUG,
			"rhosts authenticate: user = %s, host = %s",
			lusername, host);
	}

	if (getpwnam_r(lusername, &pwd, pwd_buffer, sizeof (pwd_buffer))
								== NULL)
		return (PAM_USER_UNKNOWN);

	/*
	 * RHOST may not be set due to unknown USER or reset by previous
	 * authentication failure.
	 */
	if ((rusername == NULL) || (rusername[0] == '\0'))
		return (PAM_AUTH_ERR);

	if (pwd.pw_uid == 0)
		is_superuser = 1;
	else
		is_superuser = 0;

	return (ruserok(host, is_superuser, rusername, lusername)
		== -1 ? PAM_AUTH_ERR : PAM_SUCCESS);

}

/*
 * dummy pam_sm_setcred - does nothing
 */
pam_sm_setcred(
	pam_handle_t	*pamh,
	int	flags,
	int	argc,
	const char	**argv)
{
	return (PAM_SUCCESS);
}
