// $XConsortium: c_api_graphic.cc /main/3 1996/06/11 17:27:16 cde-hal $

#include "oliasdb/c_api_common.h"

static graphic_smart_ptr*
getGraphicUsingLocAndProid(DtMmdbInfoRequest* request, Boolean checkLocOnly = false)
{
   try {
      info_base* x = getBookCase(request -> bookcase_descriptor);
      if ( x == 0 ) return 0;

      const char* str = getLocator(request);

      if ( str ) {
         return new graphic_smart_ptr(x, str);
      }

      if ( checkLocOnly == true ) return 0;

      oid_t * id = getPrimiaryOid(request);

      if ( id == 0 ) return 0;

      return new graphic_smart_ptr(x, *id);
   }

   catch (mmdbException &,e)
   {
     return 0;
   } end_try;
     return 0;
}

const char*
DtMmdbGraphicGetData(DtMmdbInfoRequest* request, unsigned int* data_length)
{
   try {
      graphic_smart_ptr* x = getGraphicUsingLocAndProid(request, true);

      if ( x == 0 ) return 0;

#ifdef DEBUG
      fprintf(stderr, " graphicInfo: mmdb_oid = %d.%d\n", (*x).its_oid().ccode(), (*x).its_oid().icode());
#endif

      const char* y = x -> data();
      if ( data_length ) *data_length = x -> data_size();

      delete x;
      return y;
   }

   catch (mmdbException &,e)
   {
     return 0;
   } end_try;
     return 0;
}

DtMmdbGraphicInfo*
DtMmdbGraphicGetInfo(DtMmdbInfoRequest* request)
{

   try {
      graphic_smart_ptr* x = getGraphicUsingLocAndProid(request, true);

      if ( x == 0 ) return 0;



      DtMmdbGraphicInfo* z = newDtMmdbGraphicInfo();

      if ( z == 0 ) return 0;

      z -> type =  x -> coding();
      z -> width = x -> width();
      z -> height = x -> height();
      z -> llx =  x -> llx();
      z -> lly =  x -> lly();
      z -> urx =  x -> urx();
      z -> ury =  x -> ury();

      delete x;

      return z;
   }

   catch (mmdbException &,e)
   {
     return 0;
   } end_try;
     return 0;
}

const char* DtMmdbGraphicGetLoc(DtMmdbInfoRequest* request)
{
   try {
      graphic_smart_ptr* x = getGraphicUsingLocAndProid(request, true);

      if ( x == 0 ) return 0;

      const char* y = x -> locator();

      delete x;
      return y;
   }

   catch (mmdbException &,e)
   {
     return 0;
   } end_try;
     return 0;
}

void DtMmdbFreeGraphicInfo(DtMmdbGraphicInfo* x)
{
   free((void*)x);
}
