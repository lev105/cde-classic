//%%  (c) Copyright 1993, 1994 Hewlett-Packard Company			
//%%  (c) Copyright 1993, 1994 International Business Machines Corp.	
//%%  (c) Copyright 1993, 1994 Sun Microsystems, Inc.			
//%%  (c) Copyright 1993, 1994 Novell, Inc. 				
//%%  $XConsortium: CoEdTextBuffer.C /main/3 1995/10/20 17:04:13 rswiston $ 			 				
/*
 * CoEdTextBuffer.c
 *
 * Copyright (c) 1991 by Sun Microsystems.  All Rights Reserved.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the names of Sun
 * Microsystems and its subsidiaries not be used in advertising or
 * publicity pertaining to distribution of the software without
 * specific, written prior permission.  Sun Microsystems and its
 * subsidiaries make no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 *
 * Sun Microsystems and its subsidiaries disclaim all warranties with
 * regard to this software, including all implied warranties of
 * merchantability and fitness.  In no event shall Sun Microsystems or
 * its subsidiaries be liable for any special, indirect or
 * consequential damages or any damages whatsoever resulting from loss
 * of use, data or profits, whether in an action of contract,
 * negligence or other tortious action, arising out of or in
 * connection with the use or performance of this software.
 */

#include "CoEdTextBuffer.h"

CoEdTextBuffer::
CoEdTextBuffer( XmTextBlock *textBuffer )
{
	_textBuffer = textBuffer;
	_insertingText = 0;
}

CoEdStatus CoEdTextBuffer::
insertText( long start, long end, const char *text )
{
#ifdef FIXUP
	TextLocation _start = LocationOfPosition( _textBuffer,
						  (TextPosition)start );
	TextLocation _end   = LocationOfPosition( _textBuffer,
						  (TextPosition)end );
	if (    (start == 0) && (end != 0) && (text == 0)
	     && (end == LastTextBufferPosition( _textBuffer )))
	{
		fprintf( stderr, "CoEd: warning: deleting all the text "
			 "in an OLIT TextBuffer may exercise OLIT bug "
			 "#1071428\n" );
	}
	_insertingText = 1;
	EditResult err = ReplaceBlockInTextBuffer( _textBuffer, &_start, &_end,
						   (char *)text,
						   (TextUpdateFunction)0, 0 );
	_insertingText = 0;
	if (err == EDIT_SUCCESS) {
		return CoEdOK;
	} else {
		return CoEdErrFailure;
	}
#endif /*FIXUP*/
	return CoEdOK;
}

CoEdStatus CoEdTextBuffer::
save()
{
	return CoEdOK;
}

CoEdStatus CoEdTextBuffer::
revert()
{
	return CoEdOK;
}

CoEdStatus CoEdTextBuffer::
rename( const char * /* newPath */ )
{
	return CoEdOK;
}
