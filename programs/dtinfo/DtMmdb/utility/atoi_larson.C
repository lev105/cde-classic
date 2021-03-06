/*
 * $XConsortium: atoi_larson.cc /main/3 1996/06/11 17:35:35 cde-hal $
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



#include "utility/atoi_larson.h"

atoi_larson::atoi_larson(int _range) : v_range(_range)
{
}

atoi_larson::~atoi_larson()
{
}

int 
atoi_larson::atoi(const char* str, int offset, int rang) const
{
   return atoi(str, strlen(str), offset, rang);
}

int 
atoi_larson::atoi(const char* str, int sz, int, int rang) const
{
   unsigned int sum = 0;
   for ( int i=0; i<sz; i++ ) {
      sum *= 37;
      sum += str[i];
   }
   return sum % ((rang == 0) ? v_range : rang);
}

int 
atoi_larson::atoi(const key_type& k, int) const
{
   char* string = k.get();
   int l = k.size();

   unsigned int sum = 0;
   for ( int i=0; i<l; i++ ) {
      //sum *= 37;
      sum <<= 7;
      sum |= string[i];
   }
   return sum % v_range;
}

