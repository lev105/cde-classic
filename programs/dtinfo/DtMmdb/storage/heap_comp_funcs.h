/*
 * $XConsortium: heap_comp_funcs.h /main/3 1996/06/11 17:33:41 cde-hal $
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


#ifndef _heap_comp_funcs
#define _heap_comp_funcs 1

#include "utility/types.h"
#include "utility/debug.h"
#include "dstr/memory_pool.h"

/**************************************/
// struct for managing free page bytes 
/**************************************/
class fbytes_t 
{

public:
   fbytes_t(int fbytes, int pnum) {
      free_bytes = fbytes;
      page_num = pnum; 
   };
   virtual ~fbytes_t() {};

   void* operator new( size_t );
   void operator delete( void* );

public:
   int free_bytes;
   int page_num;

protected:
    //static memory_pool heap_cell_space_pool;
};

Boolean fbytes_t_ls(const void*x, const void* y);
Boolean fbytes_t_eq(const void*x, const void* y);

#endif
