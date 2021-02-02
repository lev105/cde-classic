/*
 * $XConsortium: WXmScale.h /main/3 1996/06/11 17:01:56 cde-hal $
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
#ifndef WXmScale_h
#define WXmScale_h

#include "WXmManager.h"
#include <Xm/Scale.h>

class WXmScale : public WXmManager {
public :
		DEFINE_INIT (WXmScale, WXmManager, xmScaleWidgetClass)
	DEFINE_GETTER_SETTER (Value,int,"value")
	DEFINE_GETTER_SETTER (Maximum,int,"maximum")
	DEFINE_GETTER_SETTER (Minimum,int,"minimum")
	DEFINE_GETTER_SETTER (Orientation,unsigned char,"orientation")
	DEFINE_GETTER_SETTER (ProcessingDirection,unsigned char,"processingDirection")
	DEFINE_STRING_GETSET (TitleString,"titleString")
	DEFINE_GETTER_SETTER (FontList,XmFontList,"fontList")
	DEFINE_GETTER_SETTER (ShowValue,Boolean,"showValue")
	DEFINE_GETTER_SETTER (DecimalPoints,short,"decimalPoints")
	DEFINE_GETTER_SETTER (ScaleWidth,Dimension,"scaleWidth")
	DEFINE_GETTER_SETTER (ScaleHeight,Dimension,"scaleHeight")
	DEFINE_GETTER_SETTER (HighlightThickness,short,"highlightThickness")
	DEFINE_GETTER_SETTER (HighlightOnEnter,Boolean,"highlightOnEnter")
	DEFINE_GETTER_SETTER (TraversalOn,Boolean,"traversalOn")
	DEFINE_CALLBACK (ValueChangedCallback,"valueChangedCallback")
	DEFINE_CALLBACK (DragCallback,"dragCallback")
};

#define	NULLWXmScale		WXmScale((Widget)0)

class CXmScale : public CXmManager {
public :
		DEFINE_CINIT(CXmScale, CXmManager, xmScaleWidgetClass)
};

#endif
