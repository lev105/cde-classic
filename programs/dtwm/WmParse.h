/*
 * $XConsortium: WmParse.h /main/4 1995/11/01 11:46:40 rswiston $
 */
/******************************<+>*************************************
 **********************************************************************
 **
 **  File:        WmParse.h
 **
 **  Project:     HP/Motif Workspace Manager (dtwm)
 **
 **  Description:
 **  -----------
 **  This file contains function definitions for the corresponding .c
 **  file
 **
 **
 **********************************************************************
 **
 ** (c) Copyright 1987, 1988, 1989, 1990, 1991 HEWLETT-PACKARD COMPANY
 ** ALL RIGHTS RESERVED
 **
 **********************************************************************
 **********************************************************************
 **
 **
 **********************************************************************
 ******************************<+>*************************************/
#ifndef _Dt_WmParse_h
#define _Dt_WmParse_h
#include <stdio.h>
#include <string.h>

/*
 * Definitions
 */
typedef struct _DtWmpParseBuf
{

    FILE *		pFile;		/* FILE variable */
    unsigned char *	pchLine;	/* ptr to current line */
    int			cLineSize;	/* # of bytes in pchLine */
    unsigned char *	pchNext;	/* ptr to next char in pchLine */
    int			lineNumber;	/* # of current line being parsed */

} DtWmpParseBuf;

/********    Public Function Declarations    ********/

extern void _DtWmParseSkipWhitespace( 
                        DtWmpParseBuf *pWmPB) ;
extern void _DtWmParseSkipWhitespaceC( 
                        unsigned char **linePP) ;
extern unsigned char * _DtWmParseNextToken (
			DtWmpParseBuf *pWmPB) ;
extern unsigned char * _DtWmParseNextTokenC( 
			unsigned char **linePP, 
                        Boolean SmBehavior) ;
extern DtWmpParseBuf * _DtWmParseNewBuf( void ) ;
extern void _DtWmParseDestroyBuf( 
                        DtWmpParseBuf *pWmPB) ;
extern void _DtWmParseSetLine( 
                        DtWmpParseBuf *pWmPB,
                        unsigned char *pch) ;
extern void _DtWmParseSetFile( 
                        DtWmpParseBuf *pWmPB,
                        FILE *pFile) ;
extern unsigned char * _DtWmParseNextLine( 
                        DtWmpParseBuf *pWmPB) ;
extern unsigned char * _DtWmParseCurrentChar( 
                        DtWmpParseBuf *pWmPB) ;
extern unsigned char * _DtWmParseNextChar( 
                        DtWmpParseBuf *pWmPB) ;
extern int _DtWmParseLineNumber( 
                        DtWmpParseBuf *pWmPB) ;
extern void _DtWmParseToLower (
			unsigned char  *string);
extern unsigned int _DtWmParsePeekAhead(
			unsigned char *currentChar,
			unsigned int currentLev) ;
extern unsigned char * _DtWmParseBackUp ( 
			DtWmpParseBuf *pWmPB, 
			unsigned char *pchTok) ;
extern unsigned char * _DtWmParseFilenameExpand (
			unsigned char *pchFilename
			);
extern unsigned char * _DtWmParseMakeQuotedString(
			unsigned char *pchLine);
extern unsigned char * _DtWmParseExpandEnvironmentVariables (
			unsigned char *pch,
			unsigned char *pchBrk
			);
extern unsigned char * _DtWmParseNextTokenExpand (
			DtWmpParseBuf *pWmPB 
			);
#endif  /* _Dt_WmParse_h */