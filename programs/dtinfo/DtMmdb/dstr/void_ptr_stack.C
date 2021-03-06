/*
 * $XConsortium: void_ptr_stack.cc /main/3 1996/06/11 17:18:35 cde-hal $
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


#include  "dstr/void_ptr_stack.h"

void_ptr_stack::void_ptr_stack(int exp_size) :
	void_ptr_array(exp_size)
{
}

void_ptr_stack::~void_ptr_stack()
{
}

void void_ptr_stack::push(void* new_elmt)
{
   insert(new_elmt, v_elmts++);
}

void* void_ptr_stack::pop()
{
   if ( v_elmts == 0 ) 
       throw(stringException("empty stack"));

   return operator[](--v_elmts);
}

void* void_ptr_stack::peep(int i)
{
   if INRANGE(i, -(v_elmts-1), 0) {
      return operator[](v_elmts-i-1);
   } else {
      debug(cerr, i);
      debug(cerr, v_elmts);
      throw(stringException("invalid peep index"));
   }
}

ostream& operator <<(ostream& out, void_ptr_stack& stk)
{
   for ( int i=stk.no_elmts(); i>0; i-- )
     debug(cerr, (char*)stk.operator[](i-1));
   return out;
}

