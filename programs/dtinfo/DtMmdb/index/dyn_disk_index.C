/*
 * $XConsortium: dyn_disk_index.cc /main/4 1996/06/11 17:21:12 cde-hal $
 *
 * Copyright (c) 1993 HAL Computer Systems International, Ltd.
 * All rights reserved.  Unpublished -- rights reserved under
 * the Copyright Laws of the United States.  USE OF A COPYRIGHT
 * NOTICE IS PRECAUTIONARY ONLY AND DOES NOT IMPLY PUBLICATION
 * OR DISCLOSURE.
 * 
 * THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE
 * SECRETS OF HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.  USE,
 * DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE
 * PRIOR EXPRESS WRITTEN PERMISSION OF HAL COMPUTER SYSTEMS
 * INTERNATIONAL, LTD.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject
 * to the restrictions as set forth in subparagraph (c)(l)(ii)
 * of the Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013.
 *
 *          HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.
 *                  1315 Dell Avenue
 *                  Campbell, CA  95008
 * 
 */




#include "index/dyn_disk_index.h"


dyn_disk_index::dyn_disk_index() : dyn_index(DYN_DISK_INDEX_CODE) 
{
}

dyn_disk_index::~dyn_disk_index()
{
   delete v_idx_agent_ptr;
}
 
Boolean
dyn_disk_index::init_data_member(inv_lists_handler* y, abs_storage* store) 
{
   v_inv_lists_hd = y;
   v_idx_agent_ptr = new disk_hash((page_storage*)store);

   set_mode(HEALTH, true);
   return true;
}

int dyn_disk_index::handler_to_inv_idx(const handler&)
{
   throw(stringException("handler_to_int() not implemented"));
   return 0;
}

MMDB_BODIES(dyn_disk_index)
HANDLER_BODIES(dyn_disk_index)
