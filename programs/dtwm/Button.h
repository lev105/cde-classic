/* $XConsortium: Button.h /main/4 1995/11/01 11:22:33 rswiston $ */
#ifdef REV_INFO
#ifndef lint
static char SCCSID[] = "OSF/Motif: %W% %E%";
#endif /* lint */
#endif /* REV_INFO */
/******************************************************************************
*******************************************************************************
*
*  (c) Copyright 1992 HEWLETT-PACKARD COMPANY
*  ALL RIGHTS RESERVED
*  
*******************************************************************************
******************************************************************************/
#ifndef _DtButtonG_h
#define _DtButtonG_h

#include <Xm/Xm.h>

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#ifndef DtIsButtonGadget
#define DtIsButtonGadget(w) XtIsSubclass(w, dtButtonGadgetClass)
#endif /* DtIsButtonGadget */

/* ArrowButton externs for application accessible functions */

extern Widget DtCreateButtonGadget( 
                        Widget parent,
                        char *name,
                        ArgList arglist,
                        Cardinal argcount) ;

/* Button Gadget */

externalref WidgetClass dtButtonGadgetClass;

typedef struct _DtButtonGadgetClassRec * DtButtonGadgetClass;
typedef struct _DtButtonGadgetRec      * DtButtonGadget;

typedef struct
{
    int     reason;
    XEvent  *event;
    int	    click_count;
} DtButtonCallbackStruct;


#if defined(__cplusplus) || defined(c_plusplus)
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif

#endif /* _DtButtonG_h */
/* DON'T ADD ANYTHING AFTER THIS #endif */
