/*
 * $XConsortium: dyn_disk_index.h /main/5 1996/07/18 14:34:14 drk $
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



#ifndef _dyn_disk_index_h
#define _dyn_disk_index_h 1

#include "index/dyn_index.h"
#include "diskhash/disk_hash.h"

class dyn_disk_index : public dyn_index
{

public:
   dyn_disk_index();
   virtual ~dyn_disk_index();

//init run time data components
   Boolean init_data_member( inv_lists_handler*, abs_storage* );

   int handler_to_inv_idx(const handler&);

   MMDB_SIGNATURES(dyn_disk_index);
};

HANDLER_SIGNATURES(dyn_disk_index)

#endif
