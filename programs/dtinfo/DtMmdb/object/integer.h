/*
 * $XConsortium: integer.h /main/5 1996/07/18 14:42:16 drk $
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


#ifndef _integer_h
#define _integer_h 1

#include "object/primitive.h"

/***************************************
* Integer class.
****************************************/

class integer: public primitive
{

public:
   integer(c_code_t c_id = INTEGER_CODE);
   integer(const integer&);
   virtual ~integer();

   MMDB_SIGNATURES(integer);

/*
// value comparison functions
   virtual Boolean value_EQ(root&, Boolean safe = true) const ;
   virtual Boolean value_LS(root&, Boolean safe = true) const ;
*/

// ascii IO function
   virtual io_status asciiOut(ostream& s) ;
   virtual io_status asciiIn(istream&) ;

// compacted disk representation In and Out functions
   virtual int cdr_sizeof();
   virtual io_status cdrOut(buffer&);
   virtual io_status cdrIn(buffer&);


// set/retrieval integer functions
   void set(const int x);
   int get();


protected:
   int v_intRep; // int representation

};
   
HANDLER_SIGNATURES(integer)

#endif
