/*
 * $XConsortium: pref.h /main/4 1996/06/11 17:30:32 cde-hal $
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



#ifndef _pref_h
#define _pref_h 1

#include "object/tuple.h"
#include "object/pstring.h"
#include "object/oid.h"

#include "oliasdb/olias_consts.h"
#include "oliasdb/pref_base.h"
#include "api/smart_ptr.h"


#ifdef A16_BROWSER
#define pref_smart_ptr user_config_smart_ptr
#define pref_value config_value
#endif


class pref : public tuple 
{
public:
   pref() : tuple(2, USER_CONFIG_CODE) {};
   virtual ~pref() {};

   MMDB_SIGNATURES(pref);

   friend class pref_smart_ptr;

protected:
   cset_handler* pref_set_hd_ptr;
};

class pref_smart_ptr : public smart_ptr
{

public:
   pref_smart_ptr(pref_base*, const char* name);
   virtual ~pref_smart_ptr();

   Boolean update_value(const pstring& new_value);
   Boolean update_value(const char* new_value, int new_value_sz);

   Boolean remove_from_db();

   char* name();
   pstring* pref_value();


protected:
   pref_base* pbase;
   cset_handler* pref_set_hd_ptr;

   pstring_handler* v_name_hd;
   pstring_handler* v_cnfg_hd;
};


#endif