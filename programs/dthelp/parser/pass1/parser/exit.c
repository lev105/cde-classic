/* $XConsortium: exit.c /main/3 1995/11/08 10:18:43 rswiston $ */
/*
Copyright 1988, 1989 Hewlett-Packard Co.
*/

#include "userinc.h"
#include "globdec.h"
#if defined(MSDOS)
#include <process.h>
#endif

/* Default version of PARSER m_exit().  Allows interface control if
   internal error causes PARSER to halt. */
void m_exit(status)
  int status ;
  {
    exit(status) ;
    }

