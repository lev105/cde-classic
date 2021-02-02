
/* $XConsortium: lutil.c /main/4 1996/11/21 20:00:35 drk $ */
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
#include <unistd.h>
#if defined(sun) || defined(USL) || defined(__uxp__)
#include <netdb.h>
#include <sys/systeminfo.h>
#endif
#define X_INCLUDE_PWD_H
#define XOS_USE_XT_LOCKING
#include <X11/Xos_r.h>

extern char * strdup(const char *);

extern char *
_DtCmGetPrefix(char *str, char sep)
{
        char buf[BUFSIZ];
        char *ptr;

        if (str == NULL)
                return(NULL);

        ptr = buf;
        while (*str && *str != sep)
                *ptr++ = *str++;
        if (ptr == buf)
                return(NULL);
        else {
                *ptr = NULL;
                return(strdup(buf));
        }
}

extern char *
_DtCmGetLocalHost()
{
	static char *host = NULL;

	if (host == NULL) {
		host = (char *)malloc(MAXHOSTNAMELEN+1);
#if defined(sun) || defined(USL) || defined(__uxp__)
		(void)sysinfo(SI_HOSTNAME, host, MAXHOSTNAMELEN);
#else
		(void)gethostname(host, MAXHOSTNAMELEN);
#endif /* sun || USL || __uxp__ */
	}

	return (host);
}

extern char *
_DtCmGetLocalDomain(char *hostname)
{
	static char	*domain = NULL;
	char		buf[BUFSIZ], *ptr;
	CLIENT		*cl;

	if (domain == NULL) {
		domain = (char *)malloc(BUFSIZ);
#if defined(sun) || defined(USL) || defined(__uxp__)
		sysinfo(SI_SRPC_DOMAIN, domain, BUFSIZ - 1);
#else
		getdomainname(domain, BUFSIZ - 1);
#endif /* sun || USL || __uxp__ */

		/* check domain name */
		/* this is a hack to find out the domain name that
		 * is acceptable to the rpc interface, e.g.
		 * DGDO.Eng.Sun.COM is returned by sysinfo but
		 * this name is not acceptable to the rpc interface
		 * hence we need to stripe out the first component
		 */
		ptr = domain;
		if (hostname == NULL) hostname = _DtCmGetLocalHost();
		while (1) {
			sprintf(buf, "%s.%s", hostname, ptr);
			if ((cl = clnt_create(buf, 100068, 5, "udp")) == NULL) {
				ptr = strchr(ptr, '.');
				if (ptr)
					ptr++;
				else
					break;
			} else {
				clnt_destroy(cl);
				break;
			}
		}
		if (ptr && ptr != domain)
			domain = ptr;
	}

	return (domain);
}

extern char *
_DtCmGetHostAtDomain()
{
	static char	*hostname = NULL;
	char		*host;

	if (hostname == NULL) {
		hostname = malloc(BUFSIZ);

		host = _DtCmGetLocalHost();
		if (strchr(host, '.') == NULL)
			sprintf(hostname, "%s.%s", host,
				_DtCmGetLocalDomain(host));
		else
			strcpy(hostname, host);
	}

	return (hostname);
}

extern char *
_DtCmGetUserName()
{
        static char *name = NULL;
	_Xgetpwparams	pwd_buf;
	struct passwd *	pwd_ret;

        if (name == NULL) {
	  name = malloc(BUFSIZ);

	  if ((pwd_ret = _XGetpwuid(geteuid(), pwd_buf)) == NULL)
	    strcpy(name, "nobody");
	  else
	    strcpy(name, pwd_ret->pw_name);
        }

	return name;
}

/*
 * this routine checks whether the given name is a valid user name
 */
extern boolean_t
_DtCmIsUserName(char *user)
{
	_Xgetpwparams	pwd_buf;
	struct passwd *	pwd_ret;

	pwd_ret = _XGetpwnam(user, pwd_buf);
	if (pwd_ret == NULL)
		return (B_FALSE);
	else
		return (B_TRUE);
}

