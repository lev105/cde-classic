/*
 * $XConsortium: HashTbl.cc /main/3 1996/06/11 16:18:57 cde-hal $
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

#define C_HashTbl
#define L_Basic

#include "Prelude.h"

#include <memory.h>


class HashBucket : public List
{
public: // functions
  HashBucket()
    // NOTE: remove 3rd param after testing
    : List (10, 10, List::GROW_ADD) { };
  FolioObject *find (const FolioObject &);
  void remove (const FolioObject &);
};


// /////////////////////////////////////////////////////////////////
// bucket find
// /////////////////////////////////////////////////////////////////

FolioObject *
HashBucket::find (const FolioObject &element)
{
  register int i;

  for (i = 0; i < f_length; i++)
    {
      if (((Hashable *)f_list_element[i])->equals ((Hashable &) element))
	return ((Hashable *) f_list_element[i]);
    }

  return (NULL);
}


// /////////////////////////////////////////////////////////////////
// bucket remove
// /////////////////////////////////////////////////////////////////

void
HashBucket::remove (const FolioObject &element)
{
  register int i;

  for (i = 0; i < f_length; i++)
    {
      if (((Hashable *)f_list_element[i])->equals ((Hashable &) element))
	{
	  // Shift back the array and overwrite deleted element. 
	  memcpy (&f_list_element[i],
		  &f_list_element[i+1],
		 sizeof (Hashable *) * (f_length - i - 1));
	  f_length--;
	  break;
	}
    }
}


// /////////////////////////////////////////////////////////////////
// constructor
// /////////////////////////////////////////////////////////////////

HashTbl::HashTbl (u_int num_buckets)
{
  f_hash_bucket = (HashBucket **) calloc (num_buckets, sizeof (HashBucket *));
  f_num_buckets = num_buckets;
}


// /////////////////////////////////////////////////////////////////
// class destructor
// /////////////////////////////////////////////////////////////////

HashTbl::~HashTbl()
{
  remove_all(1);
  free ((char *) f_hash_bucket);
}


// /////////////////////////////////////////////////////////////////
// add - add an entry to the hash table
// /////////////////////////////////////////////////////////////////

void
HashTbl::add (Hashable &element)
{
  /* -------- Find the hash value for this element. -------- */
  u_int where = element.hash_code(0, f_num_buckets-1);

  /* -------- Create a bucket if it doesn't exist yet. -------- */
  if (f_hash_bucket[where] == NULL)
    f_hash_bucket[where] = new HashBucket();

  /* -------- See if it exists. -------- */
  if (f_hash_bucket[where]->find (element) == NULL)
    /* -------- Finally, add it. -------- */
    f_hash_bucket[where]->append (element);
}


// /////////////////////////////////////////////////////////////////
// find - find an entry in the hash table
// /////////////////////////////////////////////////////////////////

Hashable *
HashTbl::find (const Hashable &element) const
{
  u_int where = element.hash_code (0, f_num_buckets - 1);

  if (f_hash_bucket[where] != NULL)
    return ((Hashable *) f_hash_bucket[where]->find (element));
  else
    return (NULL);
}


// /////////////////////////////////////////////////////////////////
// remove - remove an entry from the hash table
// /////////////////////////////////////////////////////////////////

void
HashTbl::remove (const Hashable &element)
{
  u_int where = element.hash_code (0, f_num_buckets - 1);
  if (f_hash_bucket[where] != NULL)
    f_hash_bucket[where]->remove (element);
}


// /////////////////////////////////////////////////////////////////
// remove_all - delete all elements in the hash table
// /////////////////////////////////////////////////////////////////

void
HashTbl::remove_all (bool delete_elements)
{
  for (int i = 0; i < f_num_buckets; i++)
    if (f_hash_bucket[i] != NULL)
      {
	if (delete_elements)
	  f_hash_bucket[i]->remove_all (TRUE);
	delete f_hash_bucket[i];
	f_hash_bucket[i] = NULL;
      }
}
