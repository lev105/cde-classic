/*
 * $XConsortium: WXmGadget.h /main/3 1996/06/11 17:00:19 cde-hal $
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
#ifndef WXmGadget_h
#define WXmGadget_h

#include "wwl.h"
#include <X11/Object.h>
#include "WObject.h"
#include <X11/RectObj.h>
#include "WRect.h"
#include <Xm/Xm.h>

class WXmGadget : public WRect {
public :
		DEFINE_INIT (WXmGadget, WRect, xmGadgetClass)
	DEFINE_GETTER_SETTER (BorderWidth,Dimension,"borderWidth")
	DEFINE_GETTER_SETTER (TraversalOn,Boolean,"traversalOn")
	DEFINE_GETTER_SETTER (HighlightOnEnter,Boolean,"highlightOnEnter")
	DEFINE_GETTER_SETTER (HighlightThickness,short,"highlightThickness")
	DEFINE_GETTER_SETTER (ShadowThickness,short,"shadowThickness")
	DEFINE_GETTER_SETTER (UnitType,unsigned char,"unitType")
	DEFINE_CALLBACK (HelpCallback,"helpCallback")
	DEFINE_GETTER_SETTER (UserData,void*,"userData")

// Constraint Resources -- Valid only in a form

	DEFINE_GETTER_SETTER (TopAttachment,unsigned char,"topAttachment")
	DEFINE_GETTER_SETTER (BottomAttachment,unsigned char,"bottomAttachment")
	DEFINE_GETTER_SETTER (LeftAttachment,unsigned char,"leftAttachment")
	DEFINE_GETTER_SETTER (RightAttachment,unsigned char,"rightAttachment")
	DEFINE_GETTER_SETTER (TopWidget,Widget,"topWidget")
	DEFINE_GETTER_SETTER (BottomWidget,Widget,"bottomWidget")
	DEFINE_GETTER_SETTER (LeftWidget,Widget,"leftWidget")
	DEFINE_GETTER_SETTER (RightWidget,Widget,"rightWidget")
	DEFINE_GETTER_SETTER (TopPosition,int,"topPosition")
	DEFINE_GETTER_SETTER (BottomPosition,int,"bottomPosition")
	DEFINE_GETTER_SETTER (LeftPosition,int,"leftPosition")
	DEFINE_GETTER_SETTER (RightPosition,int,"rightPosition")
	DEFINE_GETTER_SETTER (TopOffset,int,"topOffset")
	DEFINE_GETTER_SETTER (BottomOffset,int,"bottomOffset")
	DEFINE_GETTER_SETTER (LeftOffset,int,"leftOffset")
	DEFINE_GETTER_SETTER (RightOffset,int,"rightOffset")
	DEFINE_GETTER_SETTER (Resizable,Boolean,"resizable")

#if XmVersion >= 1002
// Constraint Resources -- Valid only in a frame

   DEFINE_GETTER_SETTER (ChildType,unsigned char,"childType")
   DEFINE_GETTER_SETTER (ChildHorizontalAlignment,unsigned char,"childHorizontalAlignment")
   DEFINE_GETTER_SETTER (ChildHorizontalSpacing,Dimension,"childHorizontalSpacing")
   DEFINE_GETTER_SETTER (ChildVerticalAlignment,unsigned char,"childVerticalAlignment")
#endif

// Constraint resources - valid only in a paned window

   DEFINE_GETTER_SETTER (AllowResize,        Boolean,        "allowResize")
   DEFINE_GETTER_SETTER (PaneMinimum,        Dimension,      "paneMinimum")
   DEFINE_GETTER_SETTER (PaneMaximum,        Dimension,      "paneMaximum")
   DEFINE_GETTER_SETTER (PositionIndex,      short,          "positionIndex")
   DEFINE_GETTER_SETTER (SkipAdjust,         Boolean,        "skipAdjust")

   inline void LeftAttachment( unsigned char to_what, Widget w ) {
      Arg a; a.name = "leftAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "leftWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void LeftAttachment( unsigned char to_what, Widget w, int offset ) {
      Arg a; a.name = "leftAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "leftOffset";     a.value = (XtArgVal)offset;  _Set(a);
       a.name = "leftWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void LeftAttachment( unsigned char to_what, int poffset ) {
      Arg a; a.name = "leftAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      if( to_what == XmATTACH_POSITION ) {
	 a.name = "leftPosition";
      } else {
	 a.name = "leftOffset";  
      }
      a.value = (XtArgVal)poffset;  _Set(a);
   }

   inline void LeftAttachment( unsigned char to_what, int position,
			      int offset ) {
      Arg a; a.name = "leftAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      a.name = "leftPosition"; a.value = (XtArgVal)position;  _Set(a);
      a.name = "leftOffset";   a.value = (XtArgVal)offset;  _Set(a);
   }

   inline void RightAttachment( unsigned char to_what, Widget w ) {
      Arg a; a.name = "rightAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "rightWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void RightAttachment( unsigned char to_what, Widget w, int offset ) {
      Arg a; a.name = "rightAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "rightOffset";     a.value = (XtArgVal)offset;  _Set(a);
       a.name = "rightWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void RightAttachment( unsigned char to_what, int poffset ) {
      Arg a; a.name = "rightAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      if( to_what == XmATTACH_POSITION ) {
	 a.name = "rightPosition";
      } else {
	 a.name = "rightOffset";  
      }
      a.value = (XtArgVal)poffset;  _Set(a);
   }

   inline void RightAttachment( unsigned char to_what, int position,
			      int offset ) {
      Arg a; a.name = "rightAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      a.name = "rightPosition"; a.value = (XtArgVal)position;  _Set(a);
      a.name = "rightOffset";   a.value = (XtArgVal)offset;  _Set(a);
   }
 
   inline void TopAttachment( unsigned char to_what, Widget w ) {
      Arg a; a.name = "topAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "topWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void TopAttachment( unsigned char to_what, Widget w, int offset ) {
      Arg a; a.name = "topAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "topOffset";     a.value = (XtArgVal)offset;  _Set(a);
       a.name = "topWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void TopAttachment( unsigned char to_what, int poffset ) {
      Arg a; a.name = "topAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      if( to_what == XmATTACH_POSITION ) {
	 a.name = "topPosition";
      } else {
	 a.name = "topOffset";  
      }
      a.value = (XtArgVal)poffset;  _Set(a);
   }

   inline void TopAttachment( unsigned char to_what, int position,
			      int offset ) {
      Arg a; a.name = "topAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      a.name = "topPosition"; a.value = (XtArgVal)position;  _Set(a);
      a.name = "topOffset";   a.value = (XtArgVal)offset;  _Set(a);
   }

   inline void BottomAttachment( unsigned char to_what, Widget w ) {
      Arg a; a.name = "bottomAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "bottomWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void BottomAttachment( unsigned char to_what, Widget w, int offset ) {
      Arg a; a.name = "bottomAttachment"; a.value = (XtArgVal)to_what; _Set(a);
       a.name = "bottomOffset";     a.value = (XtArgVal)offset;  _Set(a);
       a.name = "bottomWidget";     a.value = (XtArgVal)w;       _Set(a);
   }

   inline void BottomAttachment( unsigned char to_what, int poffset ) {
      Arg a; a.name = "bottomAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      if( to_what == XmATTACH_POSITION ) {
	 a.name = "bottomPosition";
      } else {
	 a.name = "bottomOffset";  
      }
      a.value = (XtArgVal)poffset;  _Set(a);
   }

   inline void BottomAttachment( unsigned char to_what, int position,
			      int offset ) {
      Arg a; a.name = "bottomAttachment"; a.value = (XtArgVal)to_what; _Set(a);
      a.name = "bottomPosition"; a.value = (XtArgVal)position;  _Set(a);
      a.name = "bottomOffset";   a.value = (XtArgVal)offset;  _Set(a);
   }

};

#define	NULLWXmGadget		WXmGadget((Widget)0)

#endif
