/*
 * $XConsortium: WRestraint.h /main/3 1996/06/11 16:46:24 cde-hal $
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

// This code is automatically generated by hand in -*- C++ -*-

#ifndef _WRestraint_h
#define _WRestraint_h

#include <WWL/WXmManager.h>
#include "Restraint.h"

class WRestraint : public WXmManager {
public :
	DEFINE_INIT (WRestraint, WXmManager, restraintWidgetClass)
};

#define	NULLWRestraint		WRestraint((Widget)NULL)

#endif /* _WRestraint_h */
/* DO NOT ADD ANY LINES AFTER THIS #endif */
