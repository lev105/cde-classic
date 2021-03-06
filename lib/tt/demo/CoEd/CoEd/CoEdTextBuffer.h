/*%%  (c) Copyright 1993, 1994 Hewlett-Packard Company			 */
/*%%  (c) Copyright 1993, 1994 International Business Machines Corp.	 */
/*%%  (c) Copyright 1993, 1994 Sun Microsystems, Inc.			 */
/*%%  (c) Copyright 1993, 1994 Novell, Inc. 				 */
/*%%  $XConsortium: CoEdTextBuffer.h /main/3 1995/10/20 17:04:22 rswiston $ 			 				 */
/* -*-C++-*-
 *
 * CoEd_TextBuffer.h
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

#ifndef CoEd_TextBuffer_h
#define CoEd_TextBuffer_h

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <Xm/Xm.h>
#include <Xm/Text.h>
#include <CoEd.h>

class CoEdTextBuffer {
    public:
	CoEdTextBuffer( XmTextBlock *textBuffer );

	CoEdStatus	insertText( long start, long end,
					    const char *text );
	CoEdStatus	save();
	CoEdStatus	revert();
	CoEdStatus	rename( const char *newPath );
	int		insertingText() const { return _insertingText; }
	
    private:
	XmTextBlock	       *_textBuffer;
	int			_insertingText;
};

#endif CoEd_TextBuffer_h
