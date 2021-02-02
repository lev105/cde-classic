/*
 * $XConsortium: dl_list_cell.h /main/5 1996/07/18 14:41:01 drk $
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


#ifndef _dl_list_cell_h
#define _dl_list_cell_h 1

#include "object/composite.h"
#include "object/oid_t.h"

/***************************************
* Integer class.
****************************************/

class dl_list_cell: public composite
{

public:
   dl_list_cell(c_code_t c_id = DL_LIST_CELL_CODE);
   dl_list_cell(const dl_list_cell&);
   virtual ~dl_list_cell();

   MMDB_SIGNATURES(dl_list_cell);

/*
// value comparison functions
   virtual Boolean value_EQ(root&, Boolean safe = true) const ;
   virtual Boolean value_LS(root&, Boolean safe = true) const ;
*/

// ascii IO function
   virtual io_status asciiOut(ostream& s) ;
   virtual io_status asciiIn(istream&) ;

// set/retrieval dl_list_cell functions
   void set_backward_ptr(const oid_t&);
   void set_forward_ptr(const oid_t&);

   oid_t& get_backward_ptr();
   oid_t& get_forward_ptr();

// compacted disk representation In and Out functions
   virtual int cdr_sizeof();
   virtual io_status cdrOut(buffer&);
   virtual io_status cdrIn(buffer&);


protected:
   oid_t v_backward_ptr; // backward ptr
   oid_t v_forward_ptr;  // forward ptr

};

   
HANDLER_SIGNATURES(dl_list_cell)

#endif
