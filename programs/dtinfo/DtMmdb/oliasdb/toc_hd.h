/*
 * $XConsortium: toc_hd.h /main/4 1996/06/11 17:31:03 cde-hal $
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


#ifndef _toc_hd_h
#define _toc_hd_h 1

#include "object/oid_list.h"
#include "object/oid.h"
#include "object/integer.h"
#include "object/tuple.h"
#include "object/oid_t.h"
#include "oliasdb/olias_consts.h"
#include "api/smart_ptr.h"

/*************************************/
// The toc class
/*************************************/

class toc : public tuple
{

public:
   toc() : tuple(NUM_TOC_FIELDS, TOC_CODE) {};
   virtual ~toc() {};

   MMDB_SIGNATURES(toc);

protected:
};

typedef toc* tocPtr;


class toc_smart_ptr : public smart_ptr
{
public:
   toc_smart_ptr(info_lib* lib_ptr, 
                 const char* ibase_name, const oid_t& node_id);
   toc_smart_ptr(info_base* ibase_ptr, const oid_t& node_id);
   virtual ~toc_smart_ptr() {};

   oid_t toc_node_oid();
   oid_t parent();
   oid_list_handler* children();
   int subtree_size();
};


typedef toc_smart_ptr* toc_smart_ptrPtr;

#endif