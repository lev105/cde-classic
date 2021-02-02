/* $XConsortium: keyfrst.c /main/2 1996/05/09 04:09:59 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_keyfrst
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   keyfrst.c -- db_VISTA first key find module.

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


/* Find first key 
*/
d_keyfrst(field TASK_PARM DBN_PARM)
long field;   /* field constant */
TASK_DECL
DBN_DECL      /* database number */
{
   int fld, rec;
   DB_ADDR dba;
   RECORD_ENTRY FAR *rec_ptr;
   FIELD_ENTRY FAR *fld_ptr;

   DB_ENTER(DB_ID TASK_ID LOCK_SET(RECORD_IO));

   if ((nfld_check(field, &rec, &fld, (RECORD_ENTRY FAR * FAR *)&rec_ptr, (FIELD_ENTRY FAR * FAR *)&fld_ptr) != S_OKAY) ||
       /* initialize key function operation */
       (key_init(fld) != S_OKAY))
      RETURN( db_status );

   if ( key_boundary(KEYFRST, &dba) == S_OKAY ) {
      curr_rec = dba;
#ifndef	 NO_TIMESTAMP
      /* set timestamp */
      if ( db_tsrecs )
	 d_utscr( &cr_time TASK_PARM );
#endif
   }
   RETURN( db_status );
}
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin keyfrst.c */
