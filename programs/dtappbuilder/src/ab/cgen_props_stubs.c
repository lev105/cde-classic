/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
/*
 *      $XConsortium: cgen_props_stubs.c /main/4 1996/04/18 13:17:49 drk $
 *
 * @(#)cgen_props_stubs.c	1.24 21 Mar 1995 cde_app_builder/src/ab
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
 * File: cgen_props_stubs.c
 * Contains: Module callbacks and connection functions
 *
 * This file was generated by dtcodegen, from module cgen_props
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
#include "cgen_props_ui.h"


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All necessary header files have been included.
 ***
 *** Add include files, types, macros, externs, and user functions here.
 ***/


#include <Xm/List.h>
#include <Xm/TextF.h>
#include <Xm/RowColumn.h>

#include "dtbuilder.h"
#include "cgen_props_ui.h"
#include "palette_ui.h"

#include <ab_private/objxm.h>
#include <ab_private/proj.h>
#include <ab_private/util.h>
#include <ab_private/cgen.h>
#include <ab_private/strlist.h>
#include "dtb_utils.h"

/*
 * Definition of global widgets used by callbacks.
 */
CGenOptions	CodeGenOptions = {
			CG_GEN_PROJ_FLAG, 
			False, 
			CG_VERBOSITY_NORMAL,
			NULL, 
			NULL, 
			NULL};
CG_GEN_FLAG	CodeGenCmd = CG_GEN_PROJ_FLAG;
CG_VERBOSITY	CodeGenVerbosityLevel = CG_VERBOSITY_NORMAL;


void 
cgenP_update_mod_listCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    STRING		    module_name = NULL;
    int			    pos = 0;
    XmListCallbackStruct    *list_info = (XmListCallbackStruct *)callData;

    module_name = objxm_xmstr_to_str(list_info->item);
    pos = XmListItemPos(widget, list_info->item);

    /* Check if the list item has been selected or de-selected */
    if (XmListPosSelected(widget, pos))
    {
	/* If it has been selected, add it to the module_list */
	strlist_add_str(module_list, module_name, (void *)NULL);
     }
     else
     {
        /* If it has been de-selected, remove it from the module_list */
	strlist_remove_str(module_list, module_name);
     }
}



/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/



void 
cgenP_set_gen_projCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    DtbCgenPropsCgenPropsDlgInfo props_dlg =
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;

    CodeGenCmd = CG_GEN_PROJ_FLAG;
    if (XtIsSensitive(props_dlg->module_list))
    {
        XtSetSensitive(props_dlg->module_list, False);
        XtSetSensitive(props_dlg->module_list_scrolledwin, False);
    }

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_set_gen_mainCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    DtbCgenPropsCgenPropsDlgInfo props_dlg =
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;

    CodeGenCmd = CG_GEN_MAIN_FLAG;
    if (XtIsSensitive(props_dlg->module_list))
    {
        XtSetSensitive(props_dlg->module_list, False);
        XtSetSensitive(props_dlg->module_list_scrolledwin, False);
    }

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_set_gen_specificCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    DtbCgenPropsCgenPropsDlgInfo props_dlg =
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;

    CodeGenCmd = CG_GEN_SPECIFIC_FILES_FLAG;
    if (!XtIsSensitive(props_dlg->module_list))
    {
        XtSetSensitive(props_dlg->module_list, True);
        XtSetSensitive(props_dlg->module_list_scrolledwin, True);
    }

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_set_gen_specific_and_mainCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    DtbCgenPropsCgenPropsDlgInfo props_dlg =
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;

    CodeGenCmd = CG_GEN_SPECIFIC_FILES_AND_MAIN_FLAG;
    if (!XtIsSensitive(props_dlg->module_list))
    {
        XtSetSensitive(props_dlg->module_list, True);
        XtSetSensitive(props_dlg->module_list_scrolledwin, True);
    }

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_set_normal_verbosityCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    CodeGenVerbosityLevel = CG_VERBOSITY_NORMAL;

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_set_silent_verbosityCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    CodeGenVerbosityLevel = CG_VERBOSITY_SILENT; 

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_set_verbose_verbosityCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    CodeGenVerbosityLevel = CG_VERBOSITY_VERBOSE;

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_reset_default_propsCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    DtbCgenPropsCgenPropsDlgInfo props_dlg =
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;
    int			num_selected_mods = 0, i;
    XmStringTable	gen_module_list   = NULL;
    Widget              opmenu_label      = NULL;
    XmString		lbl_str           = NULL;
    

    /* set the code generation flag */
    CodeGenCmd = CG_GEN_PROJ_FLAG;
    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Entire_Project_item,
	XmNset, True, NULL);
    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Main_Only_item, 
	XmNset, False, NULL);
    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Specific_Modules_Only_item,
	XmNset, False, NULL);
    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Specific_Modules_and_Main_item,
	XmNset, False, NULL);

    /* set the merge flag */
    XtVaSetValues(props_dlg->merge_checkbox_items.Don_t_Merge_item,
		  XmNset, False, NULL);

    /* set the verbosity */
    CodeGenVerbosityLevel = CG_VERBOSITY_NORMAL;
    XtVaSetValues(props_dlg->verbosity_opmenu_items.Report_Normal_Messages_item,
	XmNset, True, NULL);
    XtVaSetValues(props_dlg->verbosity_opmenu_items.Be_Silent_item, 
	XmNset, False, NULL);
    XtVaSetValues(props_dlg->verbosity_opmenu_items.Be_Verbose_item, 
	XmNset, False, NULL);
    opmenu_label = XmOptionButtonGadget(props_dlg->verbosity_opmenu);
    XtVaGetValues(props_dlg->verbosity_opmenu_items.Report_Normal_Messages_item,
	XmNlabelString, &lbl_str, NULL);
    XtVaSetValues(opmenu_label, XmNlabelString, lbl_str, NULL);
    
    /* deselect all in the module list */
    XmListDeselectAllItems(props_dlg->module_list);
    if (module_list != NULL)
    {
	strlist_destroy(module_list);
	module_list = strlist_create();
    }

    /* clear the make args */
    XmTextFieldSetString(props_dlg->make_textf, NULL);

    /* clear the run time args */
    XmTextFieldSetString(props_dlg->run_time_textf, NULL);
    
    /* set the sensitivity */
    if (XtIsSensitive(props_dlg->module_list))
    {
	XtSetSensitive(props_dlg->module_list, False);
	XtSetSensitive(props_dlg->module_list_scrolledwin, False);
    }

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_apply_propsCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    DtbCgenPropsCgenPropsDlgInfo props_dlg = 
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;
    int			i;
    int			num_selected_mods = 0;
    Widget		merge_toggle;
    Boolean		no_merge = False;
    STRING		make_args = NULL;
    STRING		run_args = NULL;

    
    if (CodeGenOptions.make_args != NULL)
    {
	free(CodeGenOptions.make_args);
	CodeGenOptions.make_args = NULL;
    }

    if (CodeGenOptions.run_args != NULL)
    {
	free(CodeGenOptions.run_args);
	CodeGenOptions.run_args = NULL;
    }

    if (CodeGenOptions.module_list != NULL)
    {
	strlist_destroy(CodeGenOptions.module_list);
	CodeGenOptions.module_list = NULL;
    }

    merge_toggle = props_dlg->merge_checkbox_items.Don_t_Merge_item; 
    XtVaGetValues(merge_toggle, XmNset, &no_merge, NULL);

    CodeGenOptions.cmd_flag = CodeGenCmd;
    CodeGenOptions.no_merge = no_merge;
    CodeGenOptions.verbosity = CodeGenVerbosityLevel;
    
    make_args = XmTextFieldGetString(props_dlg->make_textf);
    if (!util_strempty(make_args))
	CodeGenOptions.make_args = strdup(make_args);

    run_args = XmTextFieldGetString(props_dlg->run_time_textf);
    if (!util_strempty(run_args))
	CodeGenOptions.run_args = strdup(run_args);

    if (CodeGenCmd == CG_GEN_SPECIFIC_FILES_FLAG ||
	CodeGenCmd == CG_GEN_SPECIFIC_FILES_AND_MAIN_FLAG)
    {
	XtVaGetValues(props_dlg->module_list,
		XmNselectedItemCount, 	&num_selected_mods,
		NULL);
	if (num_selected_mods == 0)
	{
	    dtb_cgen_props_no_sel_mod_msg_initialize(
		&dtb_cgen_props_no_sel_mod_msg);
	    (void)dtb_show_modal_message(
		dtb_cgen_props_cgen_props_dlg.cgen_props_dlg_shellform,
		&dtb_cgen_props_no_sel_mod_msg, NULL, NULL,NULL);
	}
	else
	{
    	    CodeGenOptions.module_list = strlist_dup(module_list);
	}
    }
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_ok_propsCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    cgenP_apply_propsCB(widget, clientData, callData);
    ui_win_show(dtb_cgen_props_cgen_props_dlg.cgen_props_dlg_shellform,False,NULL);
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_reset_propsCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    DtbCgenPropsCgenPropsDlgInfo props_dlg =
                        (DtbCgenPropsCgenPropsDlgInfo)clientData;
    int			num_selected_mods = 0, i, pos;
    XmStringTable	gen_module_list = NULL;
    XmString		mod = NULL;
    Widget              opmenu_label = NULL;
    XmString		lbl_str = NULL;

    /* undo the user's generate code modifications */
    switch (CodeGenCmd)
    {
	case CG_GEN_PROJ_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Entire_Project_item,
		XmNset, False, NULL);
	    break;

	case CG_GEN_MAIN_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Main_Only_item, 
		XmNset, False, NULL);
	    break;

	case CG_GEN_SPECIFIC_FILES_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Specific_Modules_Only_item,
		XmNset, False, NULL);
	    XmListDeselectAllItems(props_dlg->module_list);
	    break;

	case CG_GEN_SPECIFIC_FILES_AND_MAIN_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Specific_Modules_and_Main_item,
		XmNset, False, NULL);
	    XmListDeselectAllItems(props_dlg->module_list);
	    break;
	
	default:
	    break;
    }
    
    /* set the generate code options back + field sensitivity */
    switch (CodeGenOptions.cmd_flag)
    {
	case CG_GEN_PROJ_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Entire_Project_item,
		XmNset, True, NULL);
	    CodeGenCmd = CG_GEN_PROJ_FLAG;
	    if (XtIsSensitive(props_dlg->module_list))
	    {
		XtSetSensitive(props_dlg->module_list, False);
		XtSetSensitive(props_dlg->module_list_scrolledwin, False);
	    }
	    break;

	case CG_GEN_MAIN_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Main_Only_item, 
			XmNset, True, NULL);
	    CodeGenCmd = CG_GEN_MAIN_FLAG;
	    if (XtIsSensitive(props_dlg->module_list))
	    {
		XtSetSensitive(props_dlg->module_list, False);
		XtSetSensitive(props_dlg->module_list_scrolledwin, False);
	    }
	    break;

	case CG_GEN_SPECIFIC_FILES_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Specific_Modules_Only_item,
		XmNset, True, NULL);
	    CodeGenCmd = CG_GEN_SPECIFIC_FILES_FLAG;
	    /* Select items that should be selected */
	    if (CodeGenOptions.module_list != NULL) 
	    {
		XmListDeselectAllItems(props_dlg->module_list);
		for (i=0; i<strlist_get_num_strs(CodeGenOptions.module_list); i++)
		{
		    mod = objxm_str_to_xmstr(props_dlg->module_list,
			strlist_get_str(CodeGenOptions.module_list, i, (void **)NULL));
		    pos = XmListItemPos(props_dlg->module_list, mod);
    		    if (!XmListPosSelected(props_dlg->module_list, pos)) 
		    {
			XmListSelectItem(props_dlg->module_list,
				mod, True); 
		    }
		}
	    }
	    if (!XtIsSensitive(props_dlg->module_list))
	    {
		XtSetSensitive(props_dlg->module_list, True);
		XtSetSensitive(props_dlg->module_list_scrolledwin, True);
	    }
	    break;

	case CG_GEN_SPECIFIC_FILES_AND_MAIN_FLAG:
	    XtVaSetValues(props_dlg->cgen_flags_radiobox_items.Specific_Modules_and_Main_item,
		XmNset, True, NULL);
	    CodeGenCmd = CG_GEN_SPECIFIC_FILES_AND_MAIN_FLAG;
	    /* Select items that should be selected */
	    if (CodeGenOptions.module_list != NULL) 
	    {
		XmListDeselectAllItems(props_dlg->module_list);
		for (i=0; i<strlist_get_num_strs(CodeGenOptions.module_list); i++)
		{
		    mod = objxm_str_to_xmstr(props_dlg->module_list,
			strlist_get_str(CodeGenOptions.module_list, i, (void **)NULL));
		    pos = XmListItemPos(props_dlg->module_list, mod);
    		    if (!XmListPosSelected(props_dlg->module_list, pos)) 
		    {
			XmListSelectItem(props_dlg->module_list,
				mod, True); 
		    }
		}
	    }
	    if (!XtIsSensitive(props_dlg->module_list))
	    {
		XtSetSensitive(props_dlg->module_list, True);
		XtSetSensitive(props_dlg->module_list_scrolledwin, True);
	    }
	    break;
	
	default:
	    break;
    }

    /* undo the user's verbosity changes */
    switch (CodeGenVerbosityLevel)
    {
	case CG_VERBOSITY_NORMAL:
	    XtVaSetValues(props_dlg->verbosity_opmenu_items.Report_Normal_Messages_item,
		XmNset, False, NULL);
	    break;

	case CG_VERBOSITY_SILENT:
	    XtVaSetValues(props_dlg->verbosity_opmenu_items.Be_Silent_item, 
			XmNset, False, NULL);
	    break;

	case CG_VERBOSITY_VERBOSE:
	    XtVaSetValues(props_dlg->verbosity_opmenu_items.Be_Verbose_item, 
			XmNset, False, NULL);
	    break;

	default:
	    break;
    }

    /* set the verbosity back */
    switch (CodeGenOptions.verbosity)
    {
	case CG_VERBOSITY_NORMAL:
	    CodeGenVerbosityLevel = CG_VERBOSITY_NORMAL;
	    XtVaSetValues(props_dlg->verbosity_opmenu_items.Report_Normal_Messages_item,
		XmNset, True, NULL);

	    /* set the option menu label string */
	    opmenu_label = XmOptionButtonGadget(props_dlg->verbosity_opmenu);
	    XtVaGetValues(props_dlg->verbosity_opmenu_items.Report_Normal_Messages_item,
		XmNlabelString, &lbl_str, NULL);
	    XtVaSetValues(opmenu_label, XmNlabelString, lbl_str, NULL);
	    break;

	case CG_VERBOSITY_SILENT:
	    CodeGenVerbosityLevel = CG_VERBOSITY_SILENT;
	    XtVaSetValues(props_dlg->verbosity_opmenu_items.Be_Silent_item, 
		XmNset, True, NULL);

	    /* set the option menu label string */
	    opmenu_label = XmOptionButtonGadget(props_dlg->verbosity_opmenu);
	    XtVaGetValues(props_dlg->verbosity_opmenu_items.Be_Silent_item,
		XmNlabelString, &lbl_str, NULL);
	    XtVaSetValues(opmenu_label, XmNlabelString, lbl_str, NULL);
	    break;

	case CG_VERBOSITY_VERBOSE:
	    CodeGenVerbosityLevel = CG_VERBOSITY_VERBOSE;
	    XtVaSetValues(props_dlg->verbosity_opmenu_items.Be_Verbose_item, 
		XmNset, True, NULL);

	    /* set the option menu label string */
	    opmenu_label = XmOptionButtonGadget(props_dlg->verbosity_opmenu);
	    XtVaGetValues(props_dlg->verbosity_opmenu_items.Be_Verbose_item,
		XmNlabelString, &lbl_str, NULL);
	    XtVaSetValues(opmenu_label, XmNlabelString, lbl_str, NULL);
	    break;

	default:
	    break;
    }

    /* reset the merge option */
    if (CodeGenOptions.no_merge)
	XtVaSetValues(props_dlg->merge_checkbox_items.Don_t_Merge_item,
			XmNset, True, NULL);
    else
	XtVaSetValues(props_dlg->merge_checkbox_items.Don_t_Merge_item,
			XmNset, False, NULL);

    /* reset the argument values */
    XmTextFieldSetString(props_dlg->make_textf, CodeGenOptions.make_args);
    XmTextFieldSetString(props_dlg->run_time_textf, CodeGenOptions.run_args);
    
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_add_update_list_cb(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbCgenPropsCgenPropsDlgInfo	dtbSource = (DtbCgenPropsCgenPropsDlgInfo)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    /* Work-around for not being able to add a ":select" callback
     * on a list object.
     */
    XtAddCallback(dtbSource->module_list,
                XmNmultipleSelectionCallback, cgenP_update_mod_listCB,
                NULL); 

    /* Initialize module_list global variable */
    module_list = strlist_create();

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
cgenP_cancel_propsCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    cgenP_reset_default_propsCB(widget, clientData, callData);
    XtPopdown(dtb_cgen_props_cgen_props_dlg.cgen_props_dlg);
    
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
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


