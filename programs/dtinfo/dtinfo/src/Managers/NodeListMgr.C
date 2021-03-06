/*
 * $XConsortium: NodeListMgr.cc /main/5 1996/06/11 16:27:01 cde-hal $
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

#define C_NodeListMgr
#define L_Managers

#define C_NodeListAgent
#define L_Agents

#include "Prelude.h"

// /////////////////////////////////////////////////////////////////
// class constructor
// /////////////////////////////////////////////////////////////////

NodeListMgr::NodeListMgr()
{
}


// /////////////////////////////////////////////////////////////////
// activate - make entry active
// /////////////////////////////////////////////////////////////////

void
NodeListMgr::activate (ListEntry *le)
{
  f_active_agents.add (le, addHead);
}


// /////////////////////////////////////////////////////////////////
// deactivate - move entry from active to inactive list
// /////////////////////////////////////////////////////////////////

void
NodeListMgr::deactivate (ListEntry *le)
{
  f_active_agents.set_cursor (le);
  f_inactive_agents.add (f_active_agents.extract(), addHead);
}


// /////////////////////////////////////////////////////////////////
// next_inactive - return the next agent from the inactive list
// /////////////////////////////////////////////////////////////////

ListEntry *
NodeListMgr::next_inactive ()
{
  f_inactive_agents.head ();
  ListEntry *le = f_inactive_agents.extract ();

  // Place it on the active list if we got one
  if (le != NULL)
    f_active_agents.add (le, addHead);

  return (le);
}
