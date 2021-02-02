/*
 *+SNOTICE
 *
 *	$XConsortium: ManageCmd.h /main/3 1995/11/06 16:31:48 rswiston $
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


/////////////////////////////////////////////////////////////
// ManageCmd.h: Manage all windows in a MotifApp application.
//////////////////////////////////////////////////////////////
#ifndef MANAGECMD_H
#define MANAGECMD_H

#ifndef I_HAVE_NO_IDENT
#endif

#include "NoUndoCmd.h"

class ManageCmd : public NoUndoCmd {
    
  protected:
    
    virtual void doit();      // Manage all windows
    
  public:
    
    ManageCmd ( char *, char *, int );
    virtual const char *const className () { return "ManageCmd"; }
};
#endif