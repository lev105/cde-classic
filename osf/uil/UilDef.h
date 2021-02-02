/* 
 *  @OSF_COPYRIGHT@
 *  COPYRIGHT NOTICE
 *  Copyright (c) 1990, 1991, 1992, 1993 Open Software Foundation, Inc.
 *  ALL RIGHTS RESERVED (MOTIF). See the file named COPYRIGHT.MOTIF for
 *  the full copyright text.
*/ 
/* 
 * HISTORY
*/ 
/*   $XConsortium: UilDef.h /main/13 1995/07/14 09:33:37 drk $ */

/*
*  (c) Copyright 1989, 1990, DIGITAL EQUIPMENT CORPORATION, MAYNARD, MASS. */

/*
**++
**  FACILITY:
**
**      User Interface Language Compiler (UIL)
**
**  ABSTRACT:
**
**      This include file defines the set of definitions used by the public
**	access routines Uil and UilDumpSymbolTable.
**
**--
**/

#ifndef UilDef_h
#define UilDef_h

#if    !defined(__STDC__) && !defined(__cplusplus) && !defined(c_plusplus) \
    && !defined(FUNCPROTO) && !defined(XTFUNCPROTO) && !defined(XMFUNCPROTO)
#define _NO_PROTO
#endif /* __STDC__ */


/*
**
**  INCLUDE FILES
**
**/

/*
** Includes needed by other include files.
*/
#include <X11/Intrinsic.h>	

/*
**
** Common includes needed by public functions.
**
*/
#include <uil/Uil.h>
#include <uil/UilDBDef.h> 	/* This has to be loaded first. */
#include <uil/UilSymGl.h>
#include <uil/UilSymDef.h>

/*
** Function declarations not defined elsewhere
*/
#define _ARGUMENTS(arglist) arglist

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/* uilmain.c */
extern Uil_status_type Uil _ARGUMENTS((Uil_command_type
*comand_desc,Uil_compile_desc_type *compile_desc,Uil_continue_type
(*message_cb)(), char *message_data, Uil_continue_type (*status_cb)(),
char *status_data));

/* uilsymstor.c */
extern void UilDumpSymbolTable  _ARGUMENTS(( sym_entry_type *node_entry ));

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif /* UilDef_h */
/* DON'T ADD STUFF AFTER THIS #endif */