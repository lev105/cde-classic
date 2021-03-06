/*
 * $XConsortium: graphic_hd.h /main/5 1996/06/11 17:29:02 cde-hal $
 * $XConsortium: graphic_hd.h /main/5 1996/06/11 17:29:02 cde-hal $
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


#ifndef _graphic_hd_h
#define _graphic_hd_h 1

#include "object/tuple.h"
#include "object/pstring.h"
#include "object/compressed_pstring.h"
#include "oliasdb/olias_consts.h"
#include "api/smart_ptr.h"

/*************************************/
// The graphic class
/*************************************/

class graphic : public tuple
{

public:
   graphic() : tuple(NUM_GRAPHIC_FIELDS, GRAPHIC_CODE) {};
   virtual ~graphic() {};

   MMDB_SIGNATURES(graphic);

protected:
};

typedef graphic* graphicPtr;

/*************************************/
// The graphic_smart_ptr class
/*************************************/
class graphic_smart_ptr : public smart_ptr
{
public:

   graphic_smart_ptr(info_lib* lib_ptr, const char* ibase_name, const char* locator);
   graphic_smart_ptr(info_base* ibase_ptr, const char* locator);
   graphic_smart_ptr(info_base* ibase_ptr, const oid_t& id);
   virtual ~graphic_smart_ptr() {};

   const char* locator();
   const char* file_name();
   const char* version();

   int type() const;
   unsigned short coding();
   unsigned short width();
   unsigned short height();
   int data_size();
   const char* data();
   const char* title();

   unsigned int llx() ;
   unsigned int lly() ;
   unsigned int urx() ;
   unsigned int ury() ;

protected:

   int f_type;
   unsigned short f_width, f_height, f_coding;
   unsigned int f_llx, f_lly, f_urx, f_ury;
   Boolean _converted;

   Boolean _convert_to_ints();

   void init ();

#ifdef C_API
   static buffer* local_graphic_buffer_ptr;
   friend void initialize_MMDB();
   friend void quit_MMDB();
#endif
};


typedef graphic_smart_ptr* graphic_smart_ptrPtr;

#endif
