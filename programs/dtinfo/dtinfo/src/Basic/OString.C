/*
 * $XConsortium: OString.cc /main/3 1996/06/11 16:20:52 cde-hal $
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

#define C_OString
#define L_Basic

#include "Prelude.h"

void
OString::string (const char *s, copy_t copy)
{
  if (f_delete_string)
    delete [] (char *) f_string;

  if (s != NULL && copy == COPY)
    {
      f_string = new char [strlen(s) + 1];
      strcpy ((char *) f_string, (char *) s);
      f_delete_string = TRUE;
    }
  else
    {
      f_string = s;
      f_delete_string = FALSE;
    }
}
