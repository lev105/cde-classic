/*
 * $XConsortium: new_delete.h /main/4 1996/06/11 17:24:51 cde-hal $
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


#ifndef _new_delete_h
#define _new_delete_h 1

#include "new_delete_simple.h"

#ifdef C_API
#include <stdlib.h>
#else
#include <new.h>
#endif

#define NEW_AND_DELETE_BODIES(class_name) \
\
void* class_name::operator new( size_t sz )\
{\
   return ::operator new(sz); \
}\
\
void* class_name::operator new( size_t sz, void* ptr )\
{\
   return (void*)ptr; \
}\
\
void class_name::operator delete( void* p )\
{\
      ::operator delete(p); \
}

#define MMDB_SIGNATURES(class_name) \
virtual root* cast_to(char* str); \
static int cdr_size; \
virtual int mem_sizeof() { return sizeof(class_name); }; \
virtual void set_cdr_size(int sz) { class_name::cdr_size = sz; }; \
virtual int get_cdr_size() { return class_name::cdr_size; } 

#define MMDB_BODIES(class_name) \
int class_name::cdr_size = 0; \
root* class_name::cast_to(char* str)\
{\
      return new (str) class_name;\
}

#endif


