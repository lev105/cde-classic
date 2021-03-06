/* $XConsortium: c_api_bookcase.cc /main/5 1996/07/18 16:00:51 drk $ */

#include "oliasdb/c_api_common.h"

//extern void_ptr_array* infolib_array;
extern void_ptr_array* bookcase_array;
//extern olias_server* oserver_ptr;
extern OLIAS_DB* mmdb_ptr;


///////////////////////////////////////////////////////////////

int
DtMmdbGetBookCaseByName(int infolib_descriptor, const char* name)
{
   try {
      info_lib* x = mmdb_ptr -> getInfoLib(infolib_descriptor);

      if ( x == 0 ) return -1;

      info_base* base = x -> get_info_base(name);

      if ( base == 0 ) 
         return -1;
      else
         return base -> index_id();
   }

   catch (mmdbException &,e)
   {
      return -1;
   } end_try;
   return -1;
}

int
DtMmdbGetBookCaseByIndex(int infolib_descriptor, int index)
{
   try {
      info_lib* x = mmdb_ptr -> getInfoLib(infolib_descriptor);

      if ( x == 0 ) return -1;

      if ( 0 <= index && index < x -> num_of_bases() ) {

         info_base* base;

         long ind = x -> first();
         for ( int i=0; i<index; i++ )
            x -> next(ind);

         base = (*x)(ind);

         if ( base == 0 ) 
            return -1;
         else
            return base -> index_id();

      } else
        return -1;
   }
   catch (mmdbException &,e)
   {
      return -1;
   } end_try;
   return -1;
}

int
DtMmdbGetBookCaseByLoc(int infolib_descriptor, const char* locator)
{
   try {
      info_lib* x = mmdb_ptr -> getInfoLib(infolib_descriptor);

      if ( x == 0 ) return -1;

      //info_base* base = oserver_ptr -> get_infobase(locator, olias_server::LOC);
      info_base* base = x -> getInfobaseByComponent(locator, info_lib::LOC);

      if ( base == 0 ) 
            return -1;
      else
            return base -> index_id();
      
   }
   catch (mmdbException &,e)
   {
      return -1;
   } end_try;

   return -1;
}

int*
DtMmdbGetBookCaseByLocs(int infolib_descriptor, const char** locators, 
	int* count_ptr)
{

    try {
      info_lib* x = mmdb_ptr -> getInfoLib(infolib_descriptor);

      if ( x == 0 ) return 0;

      int count = 0;
      while ( locators[count] )
         count++;

      info_base** bases = 
         x -> getInfobasesByComponent((char**)locators, count, info_lib::LOC);

      count = 0;
      while ( bases[count] )
         count++;

      int* ds = (int*) malloc(sizeof(int)*(count+1));

      for ( int i=0; i<count; i++ )
         ds[i] = bases[i] -> index_id();

      delete bases;

      if (count_ptr) *count_ptr = count;

      return ds;

   }
   catch (mmdbException &,e)
   {
      if (count_ptr) *count_ptr = 0;
      return 0;
   } end_try;

   return 0;
}


DtMmdbBookCaseInfo* 
DtMmdbBookCaseGetInfo(int bookcase_descriptor)
{
   try {
        info_base* x = getBookCase(bookcase_descriptor);
  
        if ( x == 0 ) return 0;
  
        DtMmdbBookCaseInfo *y =
            (DtMmdbBookCaseInfo*)malloc(sizeof(DtMmdbBookCaseInfo));
  
        if ( y == 0 ) return 0;

        y -> name = x -> get_base_name();
        y -> num_books = x -> num_of_docs();

        return y;

   }
   catch (mmdbException &,e)
   {
      return 0;
   } end_try;

   return 0;
}

void DtMmdbBookCaseFreeInfo(DtMmdbBookCaseInfo* x)
{
   free((void*)x);
}

