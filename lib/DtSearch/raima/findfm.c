/* $XConsortium: findfm.c /main/2 1996/05/09 04:06:14 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_findfm
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   findfm.c -- db_VISTA find first member module

   (C) Copyright 1987 by Raima Corp.
-----------------------------------------------------------------------*/

/* ********************** EDIT HISTORY *******************************

 SCR    DATE    INI                   DESCRIPTION
----- --------- --- -----------------------------------------------------
      04-Aug-88 RTK MULTI_TASK changes
*/

#include <stdio.h>
#include "vista.h"
#include "dbtype.h"

/* Find first member of set
*/
d_findfm(nset TASK_PARM DBN_PARM)
int nset;
TASK_DECL
DBN_DECL
{
   char setp[SETPSIZE];
   DB_ADDR mem;
   char FAR *recp;
   int set;
   SET_ENTRY FAR *set_ptr;

   DB_ENTER(DB_ID TASK_ID LOCK_SET(SET_IO));

   if (nset_check(nset, &set, (SET_ENTRY FAR * FAR *)&set_ptr) != S_OKAY)
      RETURN( db_status );

   /* make sure we have a current owner */
   if ( ! curr_own[set] )
      RETURN( dberr(S_NOCO) );

   /* read current owner of set */
   if ( dio_read(curr_own[set], (char FAR * FAR *)&recp, NOPGHOLD) != S_OKAY )
      RETURN( db_status );

   /* get set pointer from record */
   if ( r_gset(set, recp, setp) != S_OKAY )
      RETURN( db_status == S_INVOWN? dberr(S_SYSERR): db_status );

   /* extract address of first member */
   bytecpy(&mem, setp+SP_FIRST, DB_ADDR_SIZE);

   /* set current record and member */
   curr_mem[set] = mem;

   if ( ! mem ) /* end of set if no first member */
      RETURN( db_status = S_EOS );

   curr_rec  = mem;
#ifndef	 NO_TIMESTAMP
   /* set timestamps */
   if ( db_tsrecs ) {
      d_utscr( &cr_time TASK_PARM );
      cm_time[set] = cr_time;
   }
   if ( db_tssets )
      /* only needed for system record support */
      d_utscs(nset, &cs_time[set] TASK_PARM DBN_PARM);
#endif
   RETURN( db_status = S_OKAY );
}
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin findfm.c */
