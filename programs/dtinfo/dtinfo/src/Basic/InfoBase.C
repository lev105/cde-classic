/*
 * $XConsortium: InfoBase.cc /main/3 1996/06/11 16:19:21 cde-hal $
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

#define C_ObjectId
#define L_Odb

#define C_OutlineList
#define C_InfoBase
#define C_Book
#define C_Database
#define L_Basic

#define C_DatabaseMgr
#define L_Managers

#include "Prelude.h"

INIT_CLASS (InfoBase);

// /////////////////////////////////////////////////////////////////
// has_children
// /////////////////////////////////////////////////////////////////

bool
InfoBase::has_children_internal()
{
  if (children_valid())
    return (f_children != NULL);
  else
    return (f_infobase->num_of_docs() > 0);
}


// /////////////////////////////////////////////////////////////////
// create_children
// /////////////////////////////////////////////////////////////////

void
InfoBase::create_children()
{
  int count = f_infobase->num_of_docs();
  f_children = new OutlineList (count);

  for (int i = 1; i <= count; i++)
    {
      doc_smart_ptr d (f_infobase, i);
      node_smart_ptr n (f_infobase, d.locator_id());
      f_children->append (new Book (ObjectId (f_infobase, n.locator())));
    }
}


// /////////////////////////////////////////////////////////////////
// display
// /////////////////////////////////////////////////////////////////

void
InfoBase::display()
{
}
