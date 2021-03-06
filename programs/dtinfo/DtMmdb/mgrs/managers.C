/*
 * $XConsortium: managers.cc /main/4 1996/06/11 17:22:39 cde-hal $
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


#include "mgrs/managers.h"

#include "dstr/void_ptr_array.h"

#include "utility/xtime.h"
#include "utility/debug.h"
#include "mgrs/misc.h"
#include "mgrs/template_mgr.h"
#include "mgrs/query_mgr.h"


template_mgr_t*		managers::template_mgr = 0;
query_mgr_t*		managers::query_mgr = 0;
int 			managers::reference_count = 0;

managers::managers()
{
//   fprintf(stderr, "managers::managers() begins");

   reference_count++;

   if ( reference_count > 1 ) {
      return;
   } 

/************************************/
// init managers
/************************************/
   //obj_dict = new object_dict;

   template_mgr = new template_mgr_t;
   query_mgr = new query_mgr_t;
   //object_cache = new obj_cache;
 
//  fprintf(stderr, "managers::managers() done");
}

managers::~managers()
{
   reference_count--;


   if ( reference_count > 0 ) 
      return;

   //MESSAGE(cerr, "~managers()");
   //delete object_cache;

   //delete obj_dict;

   delete query_mgr ;
   delete template_mgr ;
}
