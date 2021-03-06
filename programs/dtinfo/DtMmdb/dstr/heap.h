/*
 * $XConsortium: heap.h /main/3 1996/06/11 17:17:11 cde-hal $
 *
 * Copyright (c) 1992 HaL Computer Systems, Inc.  All rights reserved.
 * UNPUBLISHED -- rights reserved under the Copyright Laws of the United
 * States.  Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 * 
 * This software contains confidential information and trade secrets of HaL
 * Computer Systems, Inc.  Use, disclosure, or reproduction is prohibited
 * without the prior express written permission of HaL Computer Systems, Inc.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(l)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 *                        HaL Computer Systems, Inc.
 *                  1315 Dell Avenue, Campbell, CA  95008
 * 
 */


#ifndef _heap_h
#define _heap_h 1

#include "utility/funcs.h"
#include "utility/buffer.h"

typedef void (*call_back_func_ptr_t)(int, void*);

class heap : private buffer {


public:
   heap(cmp_func_ptr_t eq, cmp_func_ptr_t ls, int exp_elements = 1000);
   virtual ~heap();

// insert function, no heapifying action taken
   Boolean insert(voidPtr elm) ; 
   Boolean insert_heapify(voidPtr elm) ; 

// make a heap out of inserted elements
   void heapify();

// retrieve function
   void* max_elm() ; 
   void adjust_max_to(voidPtr new_max_item);

   void delete_max(call_back_func_ptr_t call_back_func_t = 0);
   void remove(); // remove all elements

// status function: number of elements in the heap
   int count() { 
     return buffer::content_sz() / sizeof(voidPtr) - 1; 
   };

   Boolean update() { return v_updated; };
   void adjust(int i, call_back_func_ptr_t call_back_func_t = 0);

// iterator
   int first();
   voidPtr operator()(int ind);
   void next(int& ind);

protected:
   void _delete_max(int i, voidPtr *heap_space);

protected:
   Boolean v_updated;

   cmp_func_ptr_t f_cmp_func_eq; 
   cmp_func_ptr_t f_cmp_func_ls;
};

typedef heap *heapPtr;

#endif

