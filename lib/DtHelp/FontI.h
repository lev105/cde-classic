/* $XConsortium: FontI.h /main/6 1995/12/08 13:00:51 cde-hal $ */
/************************************<+>*************************************
 ****************************************************************************
 **
 **   File:        FontI.h
 **
 **   Project:     TextGraphic Display routines
 **
 **   Description: Header file for Font.c
 **
 **
 **  (c) Copyright 1987, 1988, 1989, 1990, 1991, 1992 Hewlett-Packard Company
 **
 **  (c) Copyright 1993, 1994 Hewlett-Packard Company
 **  (c) Copyright 1993, 1994 International Business Machines Corp.
 **  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 **  (c) Copyright 1993, 1994 Novell, Inc.
 **
 **
 ****************************************************************************
 ************************************<+>*************************************/
#ifndef _DtFontI_h
#define _DtFontI_h

#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************************
 *			Semi Public Defines
 ****************************************************************************/
/*
 * resource database types
 */
#define _DtHelpXrmInt      0
#define _DtHelpXrmQuark    1

/*
 * font quarks
 */
#define _DT_HELP_FONT_CHAR_SET       6
#define _DT_HELP_FONT_LANG_TER       5
#define _DT_HELP_FONT_TYPE           4
#define _DT_HELP_FONT_WEIGHT         3
#define _DT_HELP_FONT_ANGLE          2
#define _DT_HELP_FONT_SIZE           1
#define _DT_HELP_FONT_SPACING        0

#define _DT_HELP_FONT_END            7

#define _DtHelpFontQuarkNumber     8

/****************************************************************************
 *			Semi Public Structures
 ****************************************************************************/
/****************************************************************************
 *			Semi Public Routines
 ****************************************************************************/
extern	void		 _DtHelpCopyDefaultList(XrmName *xrm_list);
extern	int		 __DtHelpDefaultFontIndexGet (
				DtHelpDispAreaStruct	*pDAS);
extern	void		 _DtHelpGetStringQuarks(XrmName *xrm_list);
extern	int		 __DtHelpFontCharSetQuarkGet(
				DtHelpDispAreaStruct	*pDAS,
				int			 font_index,
				XrmQuark		*ret_quark);
extern	void		 __DtHelpFontDatabaseInit (
				DtHelpDispAreaStruct	*pDAS,
				XtPointer		 default_font,
				XmFontType		 entry_type,
				XFontStruct		*user_font);
extern	int		 __DtHelpFontIndexGet (
				DtHelpDispAreaStruct	*pDAS,
				XrmQuarkList		 xrm_list,
				int			*ret_idx);
extern	int		 __DtHelpFontLangQuarkGet(
				DtHelpDispAreaStruct	*pDAS,
				int			 font_index,
				XrmQuark		*ret_quark);
extern	void		 __DtHelpFontMetrics (
				DtHelpDAFontInfo	 font_info,
				int			 font_index,
				_DtCvUnit		*ret_ascent,
				_DtCvUnit		*ret_descent,
				_DtCvUnit		*ret_char_width,
				_DtCvUnit		*ret_super,
				_DtCvUnit		*ret_sub);
extern	XFontSet	 __DtHelpFontSetGet (
				DtHelpDAFontInfo	 font_info,
				int			 font_index );
extern	XFontStruct	*__DtHelpFontStructGet (
				DtHelpDAFontInfo	 font_info,
				int			 font_index);
extern	int		 _DtHelpGetExactFontIndex(
				DtHelpDispAreaStruct	*pDAS,
				const char		*lang,
				const char		*char_set,
				char			*xlfd_spec,
				int			*ret_idx);

#ifdef __cplusplus
}
#endif
#endif /* _DtHelpFontI_h */
