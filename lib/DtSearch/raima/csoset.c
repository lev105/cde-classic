/* $XConsortium: csoset.c /main/2 1996/05/09 04:00:24 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_csoset
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   csoset.c -- db_VISTA current set owner database address set module.

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


/* Set current set owner
*/
d_csoset(set, dba TASK_PARM DBN_PARM)
int set;      /* Set table entry */
DB_ADDR FAR *dba; /* db address of record to become current */
TASK_DECL
DBN_DECL      /* database number */
{
   INT type;
   char FAR *ptr;
   SET_ENTRY FAR *set_ptr;

   DB_ENTER(DB_ID TASK_ID LOCK_SET(SET_IO));

   if (nset_check(set, &set, (SET_ENTRY FAR * FAR *)&set_ptr) != S_OKAY)
      RETURN( db_status );

   if ( dba == NULL ) {
      curr_own[set] = curr_mem[set] = NULL_DBA;
   }
   else if ( check_dba(*dba) == S_OKAY ) {
      /* get the record type */
      if ( dio_read( *dba, (char FAR * FAR *)&ptr , NOPGHOLD) ) RETURN( db_status );
      bytecpy( &type, ptr, sizeof(INT) );
      type &= ~RLBMASK;
#ifndef	 ONE_DB
      type += curr_db_table->rt_offset;
#endif

      if (set_ptr->st_own_rt != type)
	 RETURN( dberr( S_INVOWN ) );

      curr_own[set] = *dba;
      curr_mem[set] = NULL_DBA;
   }
   RETURN( db_status );
}
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin csoset.c */
