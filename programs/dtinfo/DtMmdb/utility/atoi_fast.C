/*
 * $XConsortium: atoi_fast.cc /main/3 1996/06/11 17:35:24 cde-hal $
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



#include "utility/atoi_fast.h"

#define MASK 0xff

atoi_fast::atoi_fast(int r, int l)
{
   pm_random rdm_generator;
   init(r, l, rdm_generator);
}

atoi_fast::atoi_fast(int r, int l, pm_random& rdm_generator) 
{
   init(r, l, rdm_generator);
}

void atoi_fast::init(int r, int, pm_random& rdm_generator) 
{
   v_entries = 256;
   v_range = r; 
   v_mask = 0;

   v_tbl = new char[v_entries];

   for ( int i = 0; i < v_entries; i++ )
     v_tbl[i] = i;

   for ( i = 0; i < v_entries - 1;  i++ ) {
      char_swap(v_tbl[rdm_generator.rand() % ( v_entries - i ) + i], 
                v_tbl[i]
               );
   }

   v_no_bytes = 4;
}

atoi_fast::~atoi_fast()
{
   delete v_tbl;
}

struct reg_t {
   unsigned b4: 8;
   unsigned b3: 8;
   unsigned b2: 8;
   unsigned b1: 8;
};

union u_tag {
   struct reg_t chars_val;
   unsigned int hash_val;
};

int atoi_fast::atoi(const key_type& k, int offset) const
{
   char* string = k.get();
   int l = k.size();
   return atoi((const char*)string, l, offset, 0);
}

int atoi_fast::atoi(const char* string, int l, int , int rang ) const 
{
   u_tag reg ;
  
   reg.hash_val = 0;

   switch (l) {
     case 0:
         break;
     case 1:
         reg.chars_val.b1 = v_tbl[string[0]] ;
         break;
     case 2:
         reg.chars_val.b1 = v_tbl[string[0]] ;
         reg.chars_val.b2 = v_tbl[string[1]] ;
         break;
     case 3:
         reg.chars_val.b1 = v_tbl[string[0]] ;
         reg.chars_val.b2 = v_tbl[string[1]] ;
         reg.chars_val.b3 = v_tbl[string[2]] ;
         break;
     default:
         reg.chars_val.b1 = v_tbl[string[0]] ;
         reg.chars_val.b2 = v_tbl[string[1]] ;
         reg.chars_val.b3 = v_tbl[string[2]] ;
         reg.chars_val.b4 = v_tbl[string[3]] ;
   }

   int x = 0;
   for ( int j=1; j<l; j++ ) {
      x ^= string[j];
   }

   reg.chars_val.b1 |= x;
   reg.chars_val.b2 |= x;

      reg.chars_val.b3 |= x;
      reg.chars_val.b4 |= x;
/*
   if ( ( rang == 0 && v_range > 65535 ) ||
        ( rang > 65535 ) 
      )
   {
      reg.chars_val.b3 |= x;
      reg.chars_val.b4 |= x;
   }
*/

/*
   int x = string[0]+offset;
   reg.chars_val.b1 = x ;
   reg.chars_val.b2 = x + 1;

   if ( v_range > 65535 ) {
      reg.chars_val.b3 = x+2;
      reg.chars_val.b4 = x+3;
   }

   for ( int j=1; j<l; j++ ) {

      reg.chars_val.b1 += string[j];
      reg.chars_val.b2 += string[j];

      if ( v_range > 65535 ) {
         reg.chars_val.b3 += string[j];
         reg.chars_val.b4 += string[j];
      }
   }
*/

   return (rang == 0 ) ? 
             ( reg.hash_val % v_range ) 
           : 
             ( reg.hash_val % rang );

}

int atoi_fast::atoi(const char* str, int offset, int rang ) const 
{
   return atoi(str, strlen(str), offset, rang);
}

ostream& operator<<(ostream& s, atoi_fast& p)
{
   for ( int i = 0; i < p.v_entries ; i++ )
      s << int(p.v_tbl[i]) << " ";
   return s;
}

