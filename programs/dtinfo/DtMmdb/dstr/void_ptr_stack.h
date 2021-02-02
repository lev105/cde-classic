/*
 * $XConsortium: void_ptr_stack.h /main/3 1996/06/11 17:18:40 cde-hal $
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



#ifndef _void_ptr_stack_h
#define _void_ptr_stack_h 1

#include  "dstr/void_ptr_array.h"

//**************************************************************
//
// A void_ptr_stack class
//
//**************************************************************

class void_ptr_stack : public void_ptr_array
{

public:
   void_ptr_stack(int exp_size) ;
   virtual ~void_ptr_stack();

   void push(void*);
   void* pop();
   void* peep(int i);

   friend ostream& operator <<(ostream&, void_ptr_stack&);

protected:
};

#endif
