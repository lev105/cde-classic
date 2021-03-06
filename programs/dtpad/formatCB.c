/* $TOG: formatCB.c /main/5 1999/09/15 14:29:27 mgreess $ */
/**********************************<+>*************************************
***************************************************************************
**
**  File:	 formatCB.c
**
**  Project:	 DT dtpad, a memo maker type editor based on the Dt Editor
**		 widget.
**
**  Description:
**  -----------
**
**	 This file contains the callbacks for the [Format] menu items.
**
*******************************************************************
**  (c) Copyright Hewlett-Packard Company, 1991, 1992.  All rights are
**  reserved.  Copying or other reproduction of this program
**  except for archival purposes is prohibited without prior
**  written consent of Hewlett-Packard Company.
********************************************************************
**
********************************************************************
**  (c) Copyright 1993, 1994 Hewlett-Packard Company
**  (c) Copyright 1993, 1994 International Business Machines Corp.
**  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
**  (c) Copyright 1993, 1994 Novell, Inc.
********************************************************************
**
**
**************************************************************************
**********************************<+>*************************************/
#include "dtpad.h"
/* #include <Dt/HourGlass.h> */

/************************************************************************
 * FormatCB - [Format] menu, [Settings...] button
 ************************************************************************/
/* ARGSUSED */
void
FormatCB(
        Widget w,
        caddr_t client_data,
        caddr_t call_data)
{
    Editor *pPad = (Editor *) client_data;
    DtEditorInvokeFormatDialog(pPad->editor);
}


/************************************************************************
 * FormatParaCB - [Format] menu, [Paragraph] button
 ************************************************************************/
/* ARGSUSED */
void
FormatParaCB(
        Widget w,
        caddr_t client_data,
        caddr_t call_data)
{
    Editor		*pPad = (Editor *) client_data;
    DtEditorErrorCode	 error = DtEDITOR_NO_ERRORS;

    error = DtEditorFormat(pPad->editor, NULL, DtEDITOR_FORMAT_PARAGRAPH);
    if (DtEDITOR_NO_ERRORS != error)
    {
        switch(error)
	{
	    case DtEDITOR_INSUFFICIENT_MEMORY:
	        Warning(
			pPad,
			(char *) GETMESSAGE(5, 47, "Operation failed due to insufficient memory.\nTry increasing swap space."),
		    	XmDIALOG_ERROR);
	        return;
	    default:
	        Warning(
			pPad,
			(char *) GETMESSAGE(5, 48, "Format operation failed."),
		    	XmDIALOG_ERROR);
	        return;
        }
    }
}


/************************************************************************
 * FormatAllCB - [Format] menu, [All] button
 ************************************************************************/
/* ARGSUSED */
void
FormatAllCB(
        Widget w,
        caddr_t client_data,
        caddr_t call_data)
{
    Editor		*pPad = (Editor *)client_data;
    DtEditorErrorCode	 error = DtEDITOR_NO_ERRORS;

    error = DtEditorFormat(pPad->editor, NULL, DtEDITOR_FORMAT_ALL);
    if (DtEDITOR_NO_ERRORS != error)
    {
        switch(error)
	{
	    case DtEDITOR_INSUFFICIENT_MEMORY:
	        Warning(
			pPad,
			(char *) GETMESSAGE(5, 47, "Operation failed due to insufficient memory.\nTry increasing swap space."),
		    	XmDIALOG_ERROR);
	        return;
	    default:
	        Warning(
			pPad,
			(char *) GETMESSAGE(5, 48, "Format operation failed."),
		    	XmDIALOG_ERROR);
	        return;
        }
    }
}
