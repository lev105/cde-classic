/* $TOG: MenuWindow.h /main/5 1997/06/04 18:43:25 mgreess $
 *
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1996 Hewlett-Packard Company.
 * (c) Copyright 1996 International Business Machines Corp.
 * (c) Copyright 1996 Sun Microsystems, Inc.
 * (c) Copyright 1996 Novell, Inc. 
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 */
/*
 *+SNOTICE
 *
 *	RESTRICTED CONFIDENTIAL INFORMATION:
 *	
 *	The information in this document is subject to special
 *	restrictions in a confidential disclosure agreement between
 *	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *	document outside HP, IBM, Sun, USL, SCO, or Univel without
 *	Sun's specific written approval.  This document and all copies
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


//////////////////////////////////////////////////////////////
// MenuWindow.C: Add a menubar to the features of MainWindow
//////////////////////////////////////////////////////////////

#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "MainWindow.h"

class MenuBar;

class MenuWindow : public MainWindow {
private:

protected:
    
    MenuBar *_menuBar;
    
    virtual void initialize();           // Called by Application
    virtual void createMenuPanes() = 0;  // Defined by derived
                                         // classes to specify the
                                         // contents of the menu

#ifndef CPLUSPLUS2_1
    virtual Widget createWorkArea ( Widget ) = 0;
#endif

    virtual void getIconColors(Pixmap & fore, Pixmap & back);

  public:
    
  MenuWindow ( char *name, Boolean allowResize=FALSE ); 
  virtual ~MenuWindow();
};
#endif
