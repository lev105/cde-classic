/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
/*
 *      $XConsortium: group_stubs.c /main/3 1995/11/06 17:30:21 rswiston $
 *
 * @(#)group_stubs.c	1.6 27 Sep 1994 cde_app_builder/src/ab
 *
 *      RESTRICTED CONFIDENTIAL INFORMATION:
 *
 *      The information in this document is subject to special
 *      restrictions in a confidential disclosure agreement between
 *      HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *      document outside HP, IBM, Sun, USL, SCO, or Univel without
 *      Sun's specific written approval.  This document and all copies
 *      and derivative works thereof must be returned or destroyed at
 *      Sun's request.
 *
 *      Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 */

/*** DTB_USER_CODE_END   ^^^ Add file header above ^^^ ***/

/*
 * File: group_stubs.c
 * Contains: Module callbacks and connection functions
 *
 * This file was generated by dtcodegen, from module group
 *
 * Any text may be added between the DTB_USER_CODE_START and
 * DTB_USER_CODE_END comments (even non-C code). Descriptive comments
 * are provided only as an aid.
 *
 *  ** EDIT ONLY WITHIN SECTIONS MARKED WITH DTB_USER_CODE COMMENTS.  **
 *  ** ALL OTHER MODIFICATIONS WILL BE OVERWRITTEN. DO NOT MODIFY OR  **
 *  ** DELETE THE GENERATED COMMENTS!                                 **
 */

#include <stdio.h>
#include <Xm/Xm.h>
#include "dtb_utils.h"
#include "dtbuilder.h"
#include "group_ui.h"

/*
 * Header files for cross-module connections
 */
#include "palette_ui.h"


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All necessary header files have been included.
 ***
 *** Add include files, types, macros, externs, and user functions here.
 ***/

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/



void 
group_layout_rbox_bitmaps_ggp_as_is_xbm_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->grid_rowcol_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_as_is_xbm_item_CB2(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->valign_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_as_is_xbm_item_CB3(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->halign_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_col_xbm_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->grid_rowcol_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_col_xbm_item_CB2(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->valign_grp, True);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_col_xbm_item_CB3(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->halign_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_row_xbm_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->grid_rowcol_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_row_xbm_item_CB2(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->valign_grp, False);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_row_xbm_item_CB3(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->halign_grp, True);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_rowcol_xbm_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->grid_rowcol_grp, True);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_rowcol_xbm_item_CB2(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->valign_grp, True);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
group_layout_rbox_bitmaps_ggp_rowcol_xbm_item_CB3(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbGroupPropDialogInfo	instance = (DtbGroupPropDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_group_prop_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }

    XtSetSensitive(instance->halign_grp, True);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}



/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All automatically-generated data and functions have been defined.
 ***
 *** Add new functions here, or at the top of the file.
 ***/

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/

