/* $XConsortium: vgversion.c /main/6 1996/08/30 15:34:13 drk $
 *
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1993,1994,1996 Hewlett-Packard Company.
 * (c) Copyright 1993,1994,1996 International Business Machines Corp.
 * (c) Copyright 1993,1994,1996 Sun Microsystems, Inc.
 * (c) Copyright 1993,1994,1996 Novell, Inc. 
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 */

/********************************************************

Copyright (c) 1988, 1990 by Hewlett-Packard Company
Copyright (c) 1988 by the Massachusetts Institute of Technology

Permission to use, copy, modify, and distribute this software 
and its documentation for any purpose and without fee is hereby 
granted, provided that the above copyright notice appear in all 
copies and that both that copyright notice and this permission 
notice appear in supporting documentation, and that the names of 
Hewlett-Packard or  M.I.T.  not be used in advertising or publicity 
pertaining to distribution of the software without specific, written 
prior permission.

********************************************************/

#include <include/hpversion.h>

#ifndef	lint
version_tag("dtgreet:       $XConsortium: vgversion.c /main/6 1996/08/30 15:34:13 drk $")

#ifdef __AFS
static char _afs_version[] = "@(#)AFS 3 Authentication";
#endif

#ifdef __KERBEROS
static char _krb_version[] = "@(#)Kerberos Authentication";
#endif

#ifdef __PASSWD_ETC
static char _rgy_version[] = "@(#)Passwd Etc. - Domain Registry Authentication";
#endif

#ifdef BLS
static char _bls_version[] = "@(#)HP BLS Authentication";
#endif

#endif	/* lint */







