/* $XConsortium: lookup.h /main/4 1995/11/09 12:46:47 rswiston $ */
/*
 *  (c) Copyright 1993, 1994 Hewlett-Packard Company
 *  (c) Copyright 1993, 1994 International Business Machines Corp.
 *  (c) Copyright 1993, 1994 Novell, Inc.
 *  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 */

#ifndef _LOOKUP_H
#define _LOOKUP_H

#include "ansi_c.h"
#include "cm.h"
#include "cmscalendar.h"

extern _DtCmsComparisonResult _DtCmsCompareEntry P((
				cms_key *key,
				caddr_t data));

extern _DtCmsComparisonResult _DtCmsCompareRptEntry P((
				cms_key *key,
				caddr_t data));

extern caddr_t _DtCmsGetEntryKey P((caddr_t data));

extern CSA_return_code _DtCmsLookupEntries P((
			_DtCmsCalendar	*cal,
			char		*sender,
			uint		access,
			time_t		start1,
			time_t		start2,
			boolean_t	no_end_time_range,
			time_t		end1,
			time_t		end2,
			CSA_uint32	num_attrs,
			cms_attribute	*attrs,
			CSA_enum	*ops,
			cms_entry	**entries));

extern CSA_return_code _DtCmsLookupEntriesById P((
			_DtCmsCalendar	*cal,
			char		*sender,
			uint		access,
			boolean_t	no_start_time_range,
			boolean_t	no_end_time_range,
			time_t		start1,
			time_t		start2,
			time_t		end1,
			time_t		end2,
			long		id,
			CSA_uint32	num_attrs,
			cms_attribute	*attrs,
			CSA_enum	*ops,
			cms_entry	**entries));

extern CSA_return_code _DtCmsEnumerateSequenceById P((
			_DtCmsCalendar	*cal,
			char		*sender,
			uint		access,
			boolean_t	no_start_time_range,
			boolean_t	no_end_time_range,
			time_t		start1,
			time_t		start2,
			time_t		end1,
			time_t		end2,
			long		id,
			CSA_uint32	num_attrs,
			cms_attribute	*attrs,
			CSA_enum	*ops,
			cms_entry	**entries));

extern CSA_return_code _DtCmsLookupEntriesByKey P((
			_DtCmsCalendar	*cal,
			char		*sender,
			uint		access,
			uint		num_keys,
			cms_key		*keys,
			uint		num_names,
			cms_attr_name	*names,
			cms_get_entry_attr_res_item **res));


extern CSA_return_code _DtCmsGetEntryAttrByKey P((
			_DtCmsCalendar	*cal,
			char		*sender,
			uint		access,
			cms_key		key,
			uint		num_names,
			cms_attr_name	*names,
			cms_entry	**entry_r,
			cms_get_entry_attr_res_item **res_r));

#endif
