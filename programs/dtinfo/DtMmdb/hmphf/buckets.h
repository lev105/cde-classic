/*
 * $XConsortium: buckets.h /main/3 1996/06/11 17:19:58 cde-hal $
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



#ifndef _buckets_h
#define _buckets_h 1

#include <stdio.h>
#include "utility/atoi_pearson.h"
#include "dstr/slist_void_ptr_cell.h"
#include "hmphf/params.h"
#include "hmphf/pattern.h"

class bucket 
{

public:
   bucket(char*, int orig_pos = 0, Boolean copy = true);
   ~bucket();
   int add_key(char*, Boolean copy = true);

   short no_keys() { return v_no_keys; };
   int g_value() { return v_g_value; };
   int control_bit() { return v_control_bit; };
   int orig_pos() { return v_orig_pos; };

   void set_count(int i) { v_count = i; };
   void set_control_bit(int cb) { v_control_bit = cb; };
   void set_g_value(int gv) { v_g_value = gv; };

   friend ostream& operator<<(ostream&, bucket&);

protected:
   short v_no_keys;
   int v_orig_pos;
   int v_control_bit;
   int v_g_value;
   int v_count;
   slist_void_ptr_cell* key_ptr;

   friend class buckets;
   friend class sorter;
};

typedef bucket* bucketPtr;

class buckets 
{

public:
   //buckets(char* key_file, params& params);
   buckets(char** keys, params& params);
   ~buckets();

   void set_control_bit(int cb);

   int get_pattern(int i, int_pattern&, params&);
   int use_current_params(int i, int_pattern&, params& pms, 
                          Boolean use_g_value = false);

   int no_buckets() { return v_no_buckets; };
   int max_bucket_sz() { return v_max_bucket_sz; };

   bucket* operator[](int i) { return v_bucket_array[i]; };

   friend ostream& operator<<(ostream&, buckets&);

protected:
   void sort_by_size();
   int bucket_num(char* k, params& pms);

   inline int hash_value(char* k, int offset, int range)
   {
      return h_convertor.atoi(k, strlen(k), offset+1, range);
   };

protected:
   bucket** v_bucket_array;
   int v_no_buckets;
   int v_max_bucket_sz;

   pm_random rnd;
   atoi_pearson b_convertor;
   atoi_pearson h_convertor;
};

#endif
