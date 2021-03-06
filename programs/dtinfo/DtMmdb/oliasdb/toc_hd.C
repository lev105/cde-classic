/*
 * $XConsortium: toc_hd.cc /main/4 1996/06/11 17:30:57 cde-hal $
 *
 * Copyright (c) 1992 HAL Computer Systems International, Ltd.
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


#include "oliasdb/toc_hd.h"

MMDB_BODIES(toc)

toc_smart_ptr::toc_smart_ptr(info_lib* lib_ptr, 
                             const char* info_base_name,
                             const oid_t& node_id
                            ) :
smart_ptr(lib_ptr, info_base_name, TOC_SET_POS,
                 managers::query_mgr -> 
                   form_oid_handler(
/*
                   ( node_id.ccode() == OLIAS_NODE_CODE ) ?
                    node_id  : oid_t(OLIAS_NODE_CODE, node_id.icode())
*/
                    oid_t(OLIAS_NODE_CODE, node_id.icode())
                                   ),
                 BASE_COMPONENT_INDEX, smart_ptr::SET
                )
{
}

toc_smart_ptr::toc_smart_ptr(info_base* base_ptr, 
                             const oid_t& node_id) :
smart_ptr(base_ptr, TOC_SET_POS,
                 managers::query_mgr -> 
                   form_oid_handler(
/*
                   ( node_id.ccode() == OLIAS_NODE_CODE ) ?
                    node_id  : oid_t(OLIAS_NODE_CODE, node_id.icode())
*/
                    oid_t(OLIAS_NODE_CODE, node_id.icode())
                                   ),
                 BASE_COMPONENT_INDEX, smart_ptr::SET
                )
{
}

oid_t toc_smart_ptr::toc_node_oid()
{
  return get_oid(BASE_COMPONENT_INDEX);
}

oid_t toc_smart_ptr::parent()
{
  return get_oid(BASE_COMPONENT_INDEX+1);
}

oid_list_handler* toc_smart_ptr::children()
{
  return (oid_list_handler*)
      get_handler(BASE_COMPONENT_INDEX+3, OID_LIST_CODE);
}

int toc_smart_ptr::subtree_size()
{
  return get_int(BASE_COMPONENT_INDEX+2);
}

