/* $XConsortium: ScrollingList.C /main/3 1995/11/06 16:02:12 rswiston $ */
/*
 *+SNOTICE
 *
 *	RESTRICTED CONFIDENTIAL INFORMATION:
 *	
 *	The information in this document is subject to special
 *	restrictions in a confidential disclosure agreement bertween
 *	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *	document outside HP, IBM, Sun, USL, SCO, or Univel wihtout
 *	Sun's specific written approval.  This documment and all copies
 *	and derivative works thereof must be returned or destroyed at
 *	Sun's request.
 *
 *	Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 *+ENOTICE
 */
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//         This example code is from the book:
//
//           Object-Oriented Programming with C++ and OSF/Motif
//         by
//           Douglas Young
//           Prentice Hall, 1992
//           ISBN 0-13-630252-1	
//
//         Copyright 1991 by Prentice Hall
//         All Rights Reserved
//
//  Permission to use, copy, modify, and distribute this software for 
//  any purpose except publication and without fee is hereby granted, provided 
//  that the above copyright notice appear in all copies of the software.
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// ScrollingList.C: 
////////////////////////////////////////////////////////////

#include "ScrollingList.h"
#include "Help.hh"


ScrollingList::ScrollingList( Widget parent, char *name ) : UIComponent( name )
{

#if defined(aix_bidi)
  //This is a temporary solution for defect 179364 and 179532
  // the resource "textMode should be dropped off after 179364 gets fixed 
  Arg args[1];
  XtSetArg(args[0],"textMode",XmTEXT_MODE_EXPLICIT);
  _w = XmCreateScrolledList( parent, name, args, 1 );
#else
  _w = XmCreateScrolledList( parent, name, NULL, 0 );
#endif

  printHelpId("_w", _w);
  /* add help callback */
  // XtAddCallback(_w, XmNhelpCallback, HelpCB, helpId);

  XtAddCallback( _w,
		 XmNdefaultActionCallback,
		 (XtCallbackProc) &ScrollingList::defaultActionCallback,
		 this ); 
  installDestroyHandler();
}

ScrollingList::~ScrollingList () 
{
}

void
ScrollingList::defaultActionCallback( Widget w,
			      XtPointer clientData,
			      XmListCallbackStruct *cbs )
{
  ScrollingList *obj = ( ScrollingList *) clientData;
  obj->defaultAction( w, clientData, cbs );
}




