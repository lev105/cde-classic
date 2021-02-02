/*%%  (c) Copyright 1993, 1994 Hewlett-Packard Company			 */
/*%%  (c) Copyright 1993, 1994 International Business Machines Corp.	 */
/*%%  (c) Copyright 1993, 1994 Sun Microsystems, Inc.			 */
/*%%  (c) Copyright 1993, 1994 Novell, Inc. 				 */
/*%%  $XConsortium: CoEdChangeHistory.h /main/3 1995/10/20 17:06:20 rswiston $ 			 				 */
/* -*-C++-*-
 *
 * CoEdChangeHistory.h
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

#ifndef CoEdChangeHistory_h
#define CoEdChangeHistory_h

#include "CoEdTextChange.h"

class CoEdChangeHistory : private CoEdTextChangeList {
    public:
	CoEdChangeHistory();

	void		insert( CoEdTextChange *change );
	CoEdTextChange *translate( CoEdTextChange &change );

    private:
	void		_translateOverEarlierChgs( CoEdTextChange &change );
	CoEdTextChange *_translateOverLaterChgs( const CoEdTextChange &change);
};

#endif CoEdChangeHistory_h