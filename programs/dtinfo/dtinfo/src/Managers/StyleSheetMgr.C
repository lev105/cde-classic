/*
 * $XConsortium: StyleSheetMgr.C /main/8 1996/10/07 09:02:45 rcs $
 *
 * Copyright (c) 1992 HAL Computer Systems International, Ltd.
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

#include <stream.h>

// NOTE: this is just for the Xassert
#define C_MessageMgr

#define C_StyleSheetMgr
#define C_NodeMgr
#define L_Managers

#include "Prelude.h"

#include "oliasdb/locator_hd.h"
#include "oliasdb/stylesheet_hd.h"
#include "StyleSheet/StyleSheet.h"
#include "StyleSheet/StyleSheetExceptions.h"

LONG_LIVED_CC(StyleSheetMgr,style_sheet_mgr);

// set to true when we are updating only for purposes of changed style sheet
bool g_style_sheet_update = FALSE ;

//
//  Silly hack. There should be a routine that wraps styleparse and
//  takes an istream * as an arg.
//
extern istream *g_stylein;

//
//  Another silly hack.
//
#include <stdio.h>
extern int styleparse();
extern void stylerestart(FILE *);


StyleSheetMgr::StyleSheetMgr(): fLastSS(0), fCurrent(0), fStyleSheetRead(0) {
}

StyleSheetMgr::~StyleSheetMgr()
{
    delete fCurrent;
}



void
StyleSheetMgr::font_preference_modified()
{
#ifdef JBM
  // 12/27/95 - this is no longer needed because we are not doing live
  // updates to the nodes when font scale changes. Instead, the font
  // scale is only updated when a new node is displayed. This is
  // managed by having NodeMgr create a CanvasRenderer and passing in
  // the current font scale value
  try
    {
      g_style_sheet_update = TRUE;
      // load new style sheet
      node_mgr().re_display_all();
      g_style_sheet_update = FALSE;
    }
  catch_any()
    {
      Xassert(0 == "StyleSheetMgr::font_preference_modified()");
      g_style_sheet_update = FALSE ;
      rethrow;
    }
  end_try;
#endif
}

//
//  SWM: Note: This is my plagarism of the code that exists
//  in Doc/Node_mmdb.C. I'm trying to not have any mmdb
//  dependencies here. However, the style sheet parsing routines
//  exist today in the mmdb, so they'll have to be moved soon.
//
void
StyleSheetMgr::initOnlineStyleSheet (UAS_Pointer<UAS_Common> &doc) {
    UAS_List<UAS_StyleSheet> ssList = doc->style_sheet_list ();
    UAS_Pointer<UAS_StyleSheet> onlineSS;
    for (int i = 0; i < ssList.length(); i ++) {
	if (ssList[i]->style_sheet_type() == SS_ONLINE) {
	    onlineSS = ssList[i];
	    break;
	}
    }
    if (onlineSS == 0) {
	//  SWM -- THROW EXCEPTION HERE OR USE A DEFAULT SS.
    }
    if ((fLastSS == onlineSS) &&
	(fLastSS->style_sheet_type() == onlineSS->style_sheet_type())) {
	fCurrent->use();
	return;
    }
    delete fCurrent;
    fLastSS = onlineSS;
    fCurrent = new StyleSheet;
    UAS_String sstextStr = fLastSS->data();
    istrstream input ((char *) sstextStr);
    g_stylein = &input;
#ifdef DUMP_STYLESHEETS
  {
    ofstream output("stylesheet.dmp");
    output << (char *) sstextStr;
  }
#endif

    if (fStyleSheetRead)
	stylerestart (0);
    fStyleSheetRead = 1;

    try {
	styleparse ();
    }
    catch_noarg (StyleSheetSyntaxError) {
	fLastSS = 0;
	delete fCurrent;
	{ //  Don't remove these curlies. For destructors before rethrow
	fCurrent = new StyleSheet;
	const char *def =
	"* { wrap: \"word\", break: \"line\", margin: { left: 20, right: 20} }";
	istrstream definput(def);
	input.unsetf (ios::skipws);
	g_stylein = &definput;
	stylerestart(0);
	styleparse();
	}
	rethrow;
    } end_try;
}


//  rcs: Note: This is my plagarism of the above code for print.

void
StyleSheetMgr::initPrintStyleSheet (UAS_Pointer<UAS_Common> &doc) {
    UAS_List<UAS_StyleSheet> ssList = doc->style_sheet_list ();
    UAS_Pointer<UAS_StyleSheet> printSS;
    for (int i = 0; i < ssList.length(); i ++) {
	if (ssList[i]->style_sheet_type() == SS_HARDCOPY) {
	    printSS = ssList[i];
	    break;
	}
    }
    if (printSS == 0) {
	//  SWM -- THROW EXCEPTION HERE OR USE A DEFAULT SS.
    }
    if ((fLastSS == printSS) &&
	(fLastSS->style_sheet_type() == printSS->style_sheet_type())) {
	fCurrent->use();
	return;
    }
    delete fCurrent;
    fLastSS = printSS;
    fCurrent = new StyleSheet;
    UAS_String sstextStr = fLastSS->data();
    istrstream input ((char *) sstextStr);
    g_stylein = &input;
#ifdef DUMP_STYLESHEETS
  {
    ofstream output("stylesheet.dmp");
    output << (char *) sstextStr;
  }
#endif

    if (fStyleSheetRead)
	stylerestart (0);
    fStyleSheetRead = 1;

    try {
	styleparse ();
    }
    catch_noarg (StyleSheetSyntaxError) {
	fLastSS = 0;
	delete fCurrent;
	{ //  Don't remove these curlies. For destructors before rethrow
	fCurrent = new StyleSheet;
	const char *def =
	"* { wrap: \"word\", break: \"line\", margin: { left: 20, right: 20} }";
	istrstream definput(def);
	input.unsetf (ios::skipws);
	g_stylein = &definput;
	stylerestart(0);
	styleparse();
	}
	rethrow;
    } end_try;
}
