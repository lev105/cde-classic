/*
 * $XConsortium: WindowGeometryPref.cc /main/4 1996/06/11 16:31:36 cde-hal $
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
#define C_List

#define C_TOC_Element
#define L_Basic

#define C_WindowSystem
#define L_Other

#define C_WindowGeometryPref
#define L_Preferences

#include <Prelude.h>


void
WindowGeometryPref::save()
{
  sprintf (g_buffer, "%dx%d+%d+%d",
	   f_value.width, f_value.height, f_value.ulx, f_value.uly);
  set_value (g_buffer);
}

void 
WindowGeometryPref::restore()
{
  // If no data, fetch default from resource db.
  if (*(UserPreference::value()) == '\0')
    f_value = window_system().get_geometry_default (key());
  else
    sscanf (UserPreference::value(), "%dx%d+%d+%d",
	    &f_value.width, &f_value.height, &f_value.ulx, &f_value.uly);
}
