/* $XConsortium: csmwrite.c /main/2 1996/05/09 03:59:37 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_csmwrite
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   csmwrite.c -- db_VISTA current set member field write module.

   (C) Copyright 1987 by Raima Corporation.
-----------------------------------------------------------------------*/

/* ********************** EDIT HISTORY *******************************

 SCR    DATE    INI                   DESCRIPTION
----- --------- --- -----------------------------------------------------
      04-Aug-88 RTK MULTI_TASK changes
*/

#include <stdio.h>
#include "vista.h"
#include "dbtype.h"


/* Write data to a field in the current set member
*/
d_csmwrite(set, field, data TASK_PARM DBN_PARM)
int set;    /* Set constant */
long field; /* Field constant */
CONST char FAR *data; /* Data area to contain field contents */
TASK_DECL
DBN_DECL    /* database number */
{
#ifndef	 NO_TIMESTAMP
   ULONG timestamp;
#endif
   int stat, fld, rec;
   char FAR *recp;
   SET_ENTRY FAR *set_ptr;
   RECORD_ENTRY FAR *rec_ptr;
   FIELD_ENTRY FAR *fld_ptr;
   DB_ADDR FAR *cm_ptr;

   DB_ENTER(DB_ID TASK_ID LOCK_SET(SET_IO));

   if ((nset_check(set, &set, (SET_ENTRY FAR * FAR *)&set_ptr) != S_OKAY) ||
       (nfld_check(field, &rec, &fld, (RECORD_ENTRY FAR * FAR *)&rec_ptr, (FIELD_ENTRY FAR * FAR *)&fld_ptr) != S_OKAY))
      RETURN( db_status );

   /* compound keys cannot be updated directly */
   if ( fld_ptr->fd_type == COMKEY )
      RETURN( dberr(S_ISCOMKEY) );

   /* field used in compound keys cannot be updated directly */
   if ( fld_ptr->fd_flags & COMKEYED )
      RETURN( dberr(S_COMKEY) );

   /* Make sure we have a current member */
   if ( ! *(cm_ptr = &curr_mem[set]) )
      RETURN( dberr(S_NOCM) );

   /* Read current member */
   if ( dio_read( *cm_ptr, (char FAR * FAR *)&recp , PGHOLD) != S_OKAY )
      RETURN( db_status );
  
   /* check out the field */
   if ( (stat = r_chkfld(fld, fld_ptr, recp, data)) != S_OKAY ) {
      dio_release(*cm_ptr);
      RETURN( db_status = stat );
   }
   /* Put data into record */
   if ( r_pfld(fld, fld_ptr, recp, data, cm_ptr) != S_OKAY )
      RETURN( db_status );
#ifndef	 NO_TIMESTAMP
   /* check for timestamp */
   if ( rec_ptr->rt_flags & TIMESTAMPED ) {
      timestamp = dio_pzgetts(rec_ptr->rt_file);
      bytecpy( recp + RECUPTIME, &timestamp, sizeof(LONG));
   }
#endif
   dio_write(*cm_ptr, NULL, PGFREE);
#ifndef	 NO_TIMESTAMP
   if (( db_status == S_OKAY ) && ( rec_ptr->rt_flags & TIMESTAMPED ))
      cm_time[set] = timestamp;
#endif
   RETURN( db_status );
}
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin csmwrite.c */
