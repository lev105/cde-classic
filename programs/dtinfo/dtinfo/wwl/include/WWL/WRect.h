/*
 * $XConsortium: WRect.h /main/3 1996/06/11 16:58:33 cde-hal $
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
#ifndef WRect_h
#define WRect_h

#include "wwl.h"
#include <X11/Object.h>
#include "WObject.h"
#include <X11/RectObj.h>

class WRect : public WObject {
public :
		DEFINE_INIT (WRect, WObject, rectObjClass)
		DEFINE_POPUP_INIT (WRect, WObject, rectObjClass)
inline	void	Manage () const	{ XtManageChild (widget); }
inline	void	Unmanage () const { XtUnmanageChild (widget); }
inline	Boolean	IsManaged () const	{ return XtIsManaged (widget); }
/*
  inline  void	SetSensitive (Boolean o) const { XtSetSensitive (widget, o); }
 while a bug exists in Motif 
 */
inline	void	SetSensitive (Boolean o, Boolean remanage = False) const
{ 
    Boolean sensitive = IsSensitive();
    
    // only if values differ 
    
    if ((sensitive && !o) ||
	(!sensitive && o)) {
	XtSetSensitive (widget, o);
	if (remanage)
	  {
	    Unmanage();
	    Manage();
	  }
    }
}

inline	Boolean	IsSensitive () const	{ return XtIsSensitive (widget); }
		DEFINE_GETTER_SETTER (AncestorSensitive,Boolean,"ancestorSensitive")
		DEFINE_GETTER_SETTER (X,Position,"x")
		DEFINE_GETTER_SETTER (Y,Position,"y")
		DEFINE_GETTER_SETTER (Width,Dimension,"width")
		DEFINE_GETTER_SETTER (Height,Dimension,"height")
		DEFINE_GETTER_SETTER (BorderWidth,Dimension,"borderWidth")
		DEFINE_GETTER_SETTER (Sensitive,Boolean,"sensitive")
};

#define	NULLWRect		WRect((Widget)0)

#endif // WRect_h
