/*
 * $XConsortium: list_test.cc /main/3 1996/06/11 16:35:51 cde-hal $
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

#define C_xList
#define L_Support

#include "Prelude.h"

#include <stdio.h>
#include <string.h>

void
main()
{
  INIT_EXCEPTIONS();

  xList<const char *> l;

  l.insert ("Rich");
  l.insert ("Dave");
  l.insert ("Rich");
  l.insert ("Brad");
  l.insert ("Rich");

  puts ("Initial list:");
  List_Iterator<const char *> i;
  for (i = l; i != NULL; i++)
    puts (i.item());

  puts ("Removing Rich:");
  i.reset();
  while (i)
    {
      printf ("Checking <%s>\n", i.item());
      if (strcmp ("Rich", i.item()) == 0)
	l.remove (i);
      else
	i++;
    }

  puts ("Revised list:");
  for (i.reset(); i; i++)
    puts (i.item());

  puts ("iter check");
  List_Iterator<const char *> x;
  for (x = l; x; x++)
    puts (x.item());

#if 0
  try
    {
      i.reset();
    }
  catch_any()
    {
      puts ("woops!");
    }
  end_try;
#endif  
}
