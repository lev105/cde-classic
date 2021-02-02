/*
 * $XConsortium: info_lib.h /main/5 1996/09/04 01:37:43 cde-hal $
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


#ifndef _info_lib_h
#define _info_lib_h 1

#include "dstr/dlist.h"
#include "dstr/dlist_void_ptr_cell.h"
#include "api/info_base.h"
#include "utility/funcs.h"

/*************************************/
// The info_lib class
/*************************************/

class info_lib : public primitive
{

public:
   info_lib(char** set_name_array, char** list_name_array,
            char* info_lib_dir = 0, char* selected_base_name = 0, 
            char* info_lib_name = "", int descriptor = -1); 

   virtual ~info_lib();

// define a base 
   Boolean define_info_base( char* base_name, 
                             char* base_desc,
                             char* spec_file_path
                           );


// get a base (the manager of a collection of documents)
   info_base* get_info_base(const char* info_base_name);

// get number of info bases in the lib
   int num_of_bases() { return info_base_list.count(); };

// info_lib path/name 
   const char* get_info_lib_path() { return info_lib_path; };
   const char* get_info_lib_name() { return info_lib_name; };
   const char* get_info_lib_uid() { return info_lib_uid; };

// iterator. 0 is the termination value
// can be used to get all base names
   long first() { return info_base_list.first(); };  
   info_base* operator()(long ind) {
     return (info_base*)(((dlist_void_ptr_cell*)ind)->void_ptr());
   };
   void next(long& ind) { info_base_list.next(ind); };


   enum TestSelector { LOC, GRA };
   info_base* getInfobaseByComponent( const char *locator_string, 
			   enum TestSelector sel);
   info_base** getInfobasesByComponent( char **locator_strings, 
			     int count, enum TestSelector sel);

   int bad_infobases();
   const char* get_bad_infobase_path(int);
   const char* get_bad_infobase_name(int);

   int descriptor() { return f_descriptor; };

protected:
   char info_lib_path[PATHSIZ];
   char info_lib_name[PATHSIZ];
   char info_lib_uid[UIDSIZ];
   dlist info_base_list;

   char** set_nm_list;
   char** list_nm_list;

   object_dict *f_obj_dict;

   info_base* _init_info_base( const char* new_db_path, 
                              const char* base_name,
                              const char* base_desc,
                              const char* base_uid,
                              const char* base_locale,
                              const mm_version& v
                             );


   int   f_bad_base_array_size;
   int   f_bad_info_bases;
   char** f_bad_info_base_paths;
   char** f_bad_info_base_names;

   int f_descriptor;

/*
   void define_composites(composite_mgr_t* mgr_ptr,
                          char* new_db_path,
                          char** def_strings,
                          Boolean& base_exist);
*/
};

typedef info_lib* info_libPtr;


#endif
