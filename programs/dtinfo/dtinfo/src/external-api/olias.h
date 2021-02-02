/*
 * $XConsortium: olias.h /main/4 1996/06/11 16:47:50 cde-hal $
 *
 * Copyright (c) 1992 HaL Computer Systems, Inc.  All rights reserved.
 * UNPUBLISHED -- rights reserved under the Copyright Laws of the United
 * States.  Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 * 
 * This software contains confidential information and trade secrets of HaL
 * Computer Systems, Inc.  Use, disclosure, or reproduction is prohibited
 * without the prior express written permission of HaL Computer Systems, Inc.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(l)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 *                        HaL Computer Systems, Inc.
 *                  1315 Dell Avenue, Campbell, CA  95008
 * 
 */


#ifndef _olias_h
#define _olias_h

#include <X11/Intrinsic.h>

typedef enum
{
  OLIAS_NOOP_EVENT = 0, OLIAS_DISPLAY_EVENT = 1
} OliasEventType;

typedef struct
{
  OliasEventType    type;
  char             *infobase;
  char             *locator;
} OliasDisplayEvent;

typedef union
{
  OliasEventType     type;
  OliasDisplayEvent  display_event;
} OliasEvent;

typedef enum
{
  OLIAS_SUCCESS = 1, OLIAS_TIMEOUT = 2, OLIAS_LOCATOR_NOT_FOUND = 3
} OliasStatus;

_XFUNCPROTOBEGIN

extern OliasStatus olias_send_event (
#if NeedFunctionPrototypes
    Widget			/* toplevel */,
    OliasEvent * 		/* olias command */
#endif
);

_XFUNCPROTOEND

#endif /* _olias_h */
/* DO NOT ADD ANY LINES AFTER THIS #endif */
