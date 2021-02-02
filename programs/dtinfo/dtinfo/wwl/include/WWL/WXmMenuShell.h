/*
 * $XConsortium: WXmMenuShell.h /main/3 1996/06/11 17:01:10 cde-hal $
 *
 * Copyright (c) 1991 HaL Computer Systems, Inc.  All rights reserved.
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

// This code is automatically generated in -*- C++ -*-
#ifndef WXmMenuShell_h
#define WXmMenuShell_h

#include "WOverrideShell.h"
#include <Xm/MenuShell.h>

class WXmMenuShell : public WOverrideShell {
public :
   DEFINE_INIT (WXmMenuShell, WOverrideShell, xmMenuShellWidgetClass)
   DEFINE_POPUP_INIT (WXmMenuShell, WOverrideShell, xmMenuShellWidgetClass)
   DEFINE_GETTER_SETTER (SaveUnder,Boolean,"saveUnder")
   DEFINE_GETTER_SETTER (AllowShellResize,Boolean,"allowShellResize")
};

#define	NULLWXmMenuShell		WXmMenuShell((Widget)0)

#endif
