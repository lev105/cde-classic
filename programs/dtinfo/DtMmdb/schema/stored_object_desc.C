/*
 * $XConsortium: stored_object_desc.cc /main/4 1996/07/18 14:51:31 drk $
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


#include "schema/stored_object_desc.h"

stored_object_desc::stored_object_desc(const char* name) : 
   desc(name), v_handler_ptr(0) 
{
      store_nm = strdup("");
}

stored_object_desc::stored_object_desc(int class_code, const char* _type) 
   : desc(class_code, _type), v_handler_ptr(0) 
{
      store_nm = strdup("");
}

stored_object_desc::~stored_object_desc() 
{ 
   delete store_nm; 
}

void stored_object_desc::set_store_nm(const char* str) 
{ 
     delete store_nm;
     store_nm = strdup(str); 
}

ostream& stored_object_desc::asciiOut(ostream& out, Boolean last)
{
   desc::asciiOut(out, false);

   if ( last == true )
      desc_print_end(out, store_nm);
   else
      desc_print(out, store_nm);

   if ( ! out )
     throw(stringException("stored_object_desc::asciiOut() failed"));

   return out;
}

void stored_object_desc::quit_handler()
{
   delete v_handler_ptr;
}

