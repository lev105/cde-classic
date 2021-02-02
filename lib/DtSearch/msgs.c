/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: DtSearchAddMessage
 *		DtSearchFreeMessages
 *		DtSearchGetMessages
 *		DtSearchHasMessages
 *
 *   ORIGINS: 27
 *
 *
 *   (C) COPYRIGHT International Business Machines Corp. 1995
 *   All Rights Reserved
 *   Licensed Materials - Property of IBM
 *   US Government Users Restricted Rights - Use, duplication or
 *   disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */
/********************** MSGS.C *****************************
 * $XConsortium: msgs.c /main/4 1996/05/07 13:40:27 drk $
 * August 1995.
 * Handles access to global ausapi_msglist for DtSearch.
 *
 * $Log$
 * Revision 2.2  1995/10/26  14:35:04  miker
 * Added prolog.
 *
 * Revision 2.1  1995/09/22  21:19:23  miker
 * Freeze DtSearch 0.1, AusText 2.1.8
 */
#include "SearchP.h"
#define PROGNAME	"MSGS"

/****************************************/
/*					*/
/*          DtSearchHasMessages		*/
/*					*/
/****************************************/
int	DtSearchHasMessages (void)
{ return (ausapi_msglist != NULL); }


/****************************************/
/*					*/
/*          DtSearchFreeMessages	*/
/*					*/
/****************************************/
void	DtSearchFreeMessages (void)
{ free_llist (&ausapi_msglist); }


/****************************************/
/*					*/
/*          DtSearchAddMessage		*/
/*					*/
/****************************************/
/* Mallocs space for new message and appends copy of passed msg
 * to end of global msglist.  This function allocates memory
 * for the messages--THE CALLER MUST FREE THE MESSAGES,
 * preferably using DtSearchFreeMessages() (free_llist()).
 * DtSearchAddMessage() was formerly called append_msglist() in msgutil.c.
 */
void	DtSearchAddMessage (char *msg)
{
    LLIST	*new;
    LLIST	**pp;
    new = austext_malloc (strlen(msg) + sizeof(LLIST) + 2,
	PROGNAME"47", NULL);
    new->link = NULL;
    new->data = new + 1;	/* hop over exactly 1 LLIST structure */
    strcpy (new->data, msg);
    for ( pp = &ausapi_msglist;  *pp != NULL;  pp = &((*pp)->link) ) ;
    *pp = new;
    return;
} /* DtSearchAddMessage() */


/****************************************/
/*					*/
/*          DtSearchGetMessages		*/
/*					*/
/****************************************/
/* July 1994,
 * DtSearchGetMessages was formerly flatmessages().
 * Copies all msgs in ausapi_msglist into single, flat text buffer.
 */
char	*DtSearchGetMessages (void)
{
    char		*targ, *src;
    size_t		totlen = 0L;
    LLIST		*llptr;
    static char		*flatbuf = NULL;
    static size_t	flatbufsz = 0L;

    /* Since function is often used as an arg in printf,
     * be sure to return something safe when there are no msgs.
     */
    if (ausapi_msglist == NULL)
	return "";

    /* First Pass: Get the total length.
     * including room for inserted \n's.
     */
    for (llptr = ausapi_msglist;  llptr != NULL;  llptr = llptr->link)
        totlen += strlen(llptr->data) + 2;
    if (totlen > flatbufsz) {
	if (flatbuf)
	    free (flatbuf);
	flatbuf = austext_malloc (totlen + 4, PROGNAME"73", NULL);
	flatbufsz = totlen;
    }

    /* Second Pass: Copy the messages into the flat buffer.
     * Make sure there are no less than 2 \n's at end of each msg--
     * one to terminate msg (it may already be in the original
     * msg string) and an added one to separate from the next msg.
     */
    targ = flatbuf;
    for (llptr = ausapi_msglist;  llptr != NULL;  llptr = llptr->link) {
	src = (char *) llptr->data;
	while (*src != 0)
	    *targ++ = *src++;
	*targ++ = '\n';
	if (*(--src) != '\n')
	    *targ++ = '\n';
    }

    /* Overlay the last two \n so the whole string won't end.
     * This prevents ugly spacing problems when function
     * is used directly in information dialog boxes.  It also
     * means regular writes to stdout etc will usually have to
     * insert their own final \n.
     */
    targ[-2] = 0;
    return flatbuf;
}  /* DtSearchGetMessages() */

/********************** MSGS.C *****************************/

