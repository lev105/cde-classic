/*
 *  Copyright 1993 Open Software Foundation, Inc., Cambridge, Massachusetts.
 *  All rights reserved.
 */
/*
 * Copyright (c) 1994  
 * Open Software Foundation, Inc. 
 *  
 * Permission is hereby granted to use, copy, modify and freely distribute 
 * the software in this file and its documentation for any purpose without 
 * fee, provided that the above copyright notice appears in all copies and 
 * that both the copyright notice and this permission notice appear in 
 * supporting documentation.  Further, provided that the name of Open 
 * Software Foundation, Inc. ("OSF") not be used in advertising or 
 * publicity pertaining to distribution of the software without prior 
 * written permission from OSF.  OSF makes no representations about the 
 * suitability of this software for any purpose.  It is provided "as is" 
 * without express or implied warranty. 
 */
/* ________________________________________________________________________
 *
 *  Hypermedia-related facilities.
 *
 *  Entry points for this module:
 *	AddID(elem, idval)		add elem-id pair to list of known ids
 *	FindElemByID(idval)		find elem by id
 * ________________________________________________________________________
 */

#ifndef lint
static char *RCSid =
  "$XConsortium: hyper.c /main/3 1996/06/19 17:13:07 drk $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <sys/types.h>

#include "general.h"


/* ______________________________________________________________________ */

void
AddID(Element *e, char *idval)
{
    static ID *id_last;
    if (!IDList) {
	Calloc(1, id_last, ID);
	IDList = id_last;
    }
    else {
	Calloc(1, id_last->next, ID);
	id_last = id_last->next;
    }
    id_last->elem = e;
    id_last->id   = idval;
}

Element	*
FindElemByID(char *idval)
{
    ID *id;
    for (id=IDList; id; id=id->next)
	if (!strcmp(id->id, idval)) return id->elem;
    return 0;
}

/* ______________________________________________________________________ */

