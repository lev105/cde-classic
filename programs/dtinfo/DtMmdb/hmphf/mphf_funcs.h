/*
 * $XConsortium: mphf_funcs.h /main/4 1996/08/21 15:52:10 drk $
 *
 * Copyright (c) 1993 HAL Computer Systems International, Ltd.
 * All rights reserved.  Unpublished -- rights reserved under
 * the Copyright Laws of the United States.  USE OF A COPYRIGHT
 * NOTICE IS PRECAUTIONARY ONLY AND DOES NOT IMPLY PUBLICATION
 * OR DISCLOSURE.
 * 
 * THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE
 * SECRETS OF HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.  USE,
 * DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE
 * PRIOR EXPRESS WRITTEN PERMISSION OF HAL COMPUTER SYSTEMS
 * INTERNATIONAL, LTD.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject
 * to the restrictions as set forth in subparagraph (c)(l)(ii)
 * of the Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013.
 *
 *          HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.
 *                  1315 Dell Avenue
 *                  Campbell, CA  95008
 * 
 */



#ifndef _mphf_funcs_h
#define _mphf_funcs_h 1

#ifdef C_API
#include "utility/c_strstream.h"
#else
#include <strstream.h>
#endif

#include "utility/funcs.h"
#include "utility/buffer.h"
#include "hmphf/buckets.h"
#include "utility/pm_random.h"
#include "hmphf/mphf_hash_table.h"
#include "hmphf/pattern.h"

int compute_a_mphf(char** keys, params& params_ptr, buffer& mphf_spec_buffer);

int search(buckets& bs, mphf_hash_table& ht, params& pms);
int verify(buckets& bs, mphf_hash_table& ht, params& pms);

int write_spec(buckets& bs, params& pms, buffer& mphf_spec_buffer);

int compact(buckets& bs, unsigned s[], int t, Boolean swap);

int wc(char* file_name, unsigned int& lines, unsigned int& max_length);


#endif

