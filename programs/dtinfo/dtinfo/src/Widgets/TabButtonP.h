/*
 * $XConsortium: TabButtonP.h /main/3 1996/06/11 16:46:15 cde-hal $
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

#ifndef _TabButtonP_h
#define _TabButtonP_h

#include <Xm/LabelP.h>
#include "TabButton.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TabButton class data. */
  
typedef struct _XyzTabButtonClassPart
{
  /* Need to have at least one member. */
  int dummy;
} XyzTabButtonClassPart;


/* Full TabButton class declaration */

typedef struct _XyzTabButtonClassRec {
  CoreClassPart          core_class;
  XmPrimitiveClassPart   primitive_class;
  XmLabelClassPart       label_class;
  XyzTabButtonClassPart  tab_button_class;
} XyzTabButtonClassRec;

/* TabButton instance data. */

typedef struct _XyzTabButtonPart
{
  /* Resource data memebers. */
  Boolean          fill_on_arm;
  Pixel            arm_color;
  Pixmap           arm_pixmap;
  Pixmap           unarm_pixmap;
  XtCallbackList   activate_callback;
  XtCallbackList   arm_callback;
  XtCallbackList   disarm_callback;
  unsigned char    multi_click;
  unsigned long    disarm_delay;
  Dimension        radius;

  /* Protected data members. */
  Dimension        min_size;
  Dimension        current_radius;
  Boolean          armed;
  GC               arm_gc;
  GC               background_gc;
  Pixel            parent_bg;
  GC               parent_bg_gc;
  int              click_count;
  Time             last_arm_time;
  XtIntervalId     timer;
} XyzTabButtonPart;


/* Full TabButton instance. */

typedef struct _XyzTabButtonRec {
  CorePart          core;
  XmPrimitivePart   primitive;
  XmLabelPart       label;
  XyzTabButtonPart  tab;
} XyzTabButtonRec;


#ifdef __cplusplus
}
#endif

#endif /* _TabButtonP_h */
/* DO NOT ADD ANY LINES AFTER THIS #endif */