/* $XConsortium: container_desc.h /main/4 1996/06/11 17:31:53 cde-hal $ */

#ifndef _container_desc_h
#define _container_desc_h 1

#include "schema/stored_object_desc.h"
#include "schema/object_dict.h"
#include "dstr/void_ptr_array.h"
#include "object/dl_list.h"
#include "object/cset.h"
#include "index/index.h"

class container_desc : public stored_object_desc {

public:
   container_desc(int class_code, const char* comment = "");
   virtual ~container_desc();

   void set_index_nm(const char*);
   virtual ostream& asciiOut(ostream& out, Boolean last = true);

   void init_index_array(object_dict&, c_index_handlerPtr*&, int& sz) ;

protected:
   void_ptr_array index_nms;
};

class set_desc : public container_desc {

public:
   set_desc();
   virtual ~set_desc() {};

   handler* init_handler(object_dict&) ;

protected:
};

class list_desc : public container_desc {

public:
   list_desc();
   virtual ~list_desc() {};

   handler* init_handler(object_dict&) ;

protected:
};


#endif
