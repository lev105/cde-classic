/*
 * $XConsortium: compressed_pstring.h /main/4 1996/06/11 17:23:49 cde-hal $
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


#ifndef _compressed_pstring_h
#define _compressed_pstring_h 1

#include "object/pstring.h"
#include "compression/abs_agent.h"

/***************************************
* compressed string class.
****************************************/

class compressed_pstring: public pstring
{

protected:

#ifdef C_API
   static buffer* v_cp_io_buf_ptr;
   static buffer* working_buffer_ptr;
#else
   static buffer v_cp_io_buf;
   static buffer working_buffer;
#endif

   oid_t compress_agent_id;

   unsigned int v_uncompressed_sz;
   
   compress_agent_handler* agent;

protected:
   void _compress();

public:
   compressed_pstring(c_code_t = COMPRESSED_STRING_CODE);
   virtual ~compressed_pstring();

// get uncompresed version
#ifdef C_API
   char* get(buffer& optional_buffer = *v_cp_io_buf_ptr); 
#else
   char* get(buffer& optional_buffer = v_cp_io_buf); 
#endif

   int size() const; // get uncompressed data size

   MMDB_SIGNATURES(compressed_pstring);

// asciiIn function
   virtual io_status _asciiIn(istream&) ; // read in string part
   virtual io_status _asciiIn(const char* buf, int size) ; 

   virtual io_status asciiIn(istream&) ;  // read in compress agent id and then
   virtual io_status asciiIn(const char* buf, int size, const oid_t&) ;  
   virtual io_status asciiIn(const char* buf, int size) ;  

// compacted disk representation In and Out functions
   virtual int cdr_sizeof();
   virtual io_status cdrOut(buffer&);
   virtual io_status cdrIn(buffer&);

   friend class compressed_pstring_handler;

#ifdef C_API
   friend void initialize_MMDB();
   friend void quit_MMDB();
#endif

private:

};

HANDLER_SIGNATURES(compressed_pstring)
   
#endif
