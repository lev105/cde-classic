/*
 * $XConsortium: WXmFrame.h /main/3 1996/06/11 17:00:13 cde-hal $
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
#ifndef WXmFrame_h
#define WXmFrame_h

#include "WXmManager.h"
#include <Xm/Frame.h>

class WXmFrame : public WXmManager {
public :
   DEFINE_INIT (WXmFrame, WXmManager, xmFrameWidgetClass)
   DEFINE_GETTER_SETTER (MarginWidth,short,"marginWidth")
   DEFINE_GETTER_SETTER (MarginHeight,short,"marginHeight")
   DEFINE_GETTER_SETTER (ShadowType,unsigned char,"shadowType")
};

#define	NULLWXmFrame		WXmFrame((Widget)0)

class CXmFrame : public CXmManager {
public :
   DEFINE_CINIT(CXmFrame, CXmManager, xmFrameWidgetClass)
};

#endif
