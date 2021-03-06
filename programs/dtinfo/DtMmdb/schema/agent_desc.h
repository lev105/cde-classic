/*
 * $XConsortium: agent_desc.h /main/3 1996/06/11 17:31:41 cde-hal $
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


#ifndef _agent_desc_h
#define _agent_desc_h 1

#include "schema/stored_object_desc.h"
#include "schema/object_dict.h"

class mphf_desc : public stored_object_desc {

public:
   mphf_desc();
   ~mphf_desc() {};

   handler* init_handler(object_dict&) ;

protected:
};

class btree_desc : public stored_object_desc {

public:
   btree_desc();
   ~btree_desc() {};

   handler* init_handler(object_dict&) ;
protected:
};

class smphf_desc : public stored_object_desc {

public:
   smphf_desc();
   ~smphf_desc() {};

   handler* init_handler(object_dict&) ;
protected:
};


class huffman_desc : public stored_object_desc {

public:
   huffman_desc();
   ~huffman_desc() {};

   handler* init_handler(object_dict&) ;
protected:
};


class dict_desc : public stored_object_desc {

public:
   dict_desc();
   ~dict_desc() {};

   handler* init_handler(object_dict&) ;
protected:
};


#endif
