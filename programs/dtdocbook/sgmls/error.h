/* $XConsortium: error.h /main/3 1996/06/19 17:14:57 drk $ */
/* ERROR.H: Symbols for SGML error codes (start with 'E_').
            Numbers 46 - 56 are generated by ERROR.C.
            Later numbers are coded directly.
*/
/* SGMLERR.C: General errors and syntax errors.
*/
#define E_CONTEXT   1   /* W  GI not allowed at this point in structure. */
#define E_MDNAME    2   /* E  Invalid markup declaration name. */
/*efine E_LEN       3      E  Syntax error: length exceeded. */
#define E_SYS       4   /* W  Illegal system character. */
#define E_ETAG      5   /* E  End-tag does not match any open start-tag. */
#define E_STAGMAX   6   /* E  Maximum number of open elements exceeded. */
/*      E_ALLNULL   7      W  Start- and end-tag omitted with null content. */
#define E_EOF       8   /* E/W Illegal entity end in markup or delimited text. */
/* fine E_INV       9      E  Markup error: invalid character. */
#define E_CHARS    10   /* W  Data found in content that doesn't allow it. */
/* fine E_NOETDE   11      E  End-tag GI not defined by element declaration. */
#define E_BADNM    12   /* E  Name is not syntactically valid. */
#define E_BADATT   13   /* E  Attribute was not defined by element declaration. */
#define E_VALINV   14   /* W  Att value/declaration conflict: invalid char. */
#define E_VALLEN   15   /* W  Att value/declaration conflict: token too long. */
#define E_VALCNT   16   /* W  Att value/declaration conflict: too many tokens. */
#define E_VALTYPE  17   /* W  Att value/declaration conflict: wrong token type.*/
#define E_VALGRP   18   /* W  Att value/declaration conflict: token not in grp.*/
#define E_VALREQ   19   /* W  Att value/declaration conflict: req unspecified. */
/*      E_EMIN     20      W  End-tag implied by end-tag; not minimizable. */
/*      E_SMIN     21      W  Omitted start-tag was not minimizable. */
#define E_POSSATT  22   /* E  Possible att found but not defined; used as data.*/
/* Late additions numbered out of order to avoid recompilation. */
/*efine E_ENTSYNC  37      E  Entity and group nesting levels out of sync. */
#define E_BADVAL   25   /* W  Att value omitted (null); default used. */
/*      E_ECONTXT  30      W  Element ended prematurely (some content omitted).*/
/*      E_EMINST   39      W  End-tag implied by start-tag; not minimizable. */
/*      E_MEXTAG   40      W  *** In Use ***                               */
#define E_MEXERR   41   /* W  Attempt to exclude contextually required element.*/
#define E_DOCTYPE  42   /* W  No document type defined; *DOCTYPE assumed. */
/*      E_NOETDS   43      E  Start-tag GI not defined by element declaration. */
#define E_RESTART  44   /* E  Invalid chars ignored; trying to restart parse. */

/* MDERROR.C: Errors in markup declarations.
*/
/*efine E_DUP      23      E  Duplicate specification. */
/*efine E_KEY      24      E  Incorrect keyword for parameter. */
/*efine E_MSE      26      E  MSE occurred with no corresponding MS. */
/*efine E_MSS      27      E  MSS exceeded maximum nesting level. */
/*efine E_NUM      28      E  Incorrect number of parameters. */
#define E_TYPE     29   /* E  Incorrect parameter type. */
/* Late additions numbered out of order to avoid recompilation. */
/*efine E_VAL      38      W  Incorrect parameter value. */

/* RESERROR.C: Errors in resource routines.
*/
/* Unused                 I  End of primary source entity. */
/* fine E_FILBUF   31      E  Could not read next buffer. */
/* fine E_ERFILE   32      E  Could not open file. */
/* fine E_MALLOC   33      T  Could not obtain required main storage. */
/* fine E_ERMAX    34      E  Maximum number of open entities exceeded. */
/* fine E_ERNAME   35      E  Referenced entity undeclared. */
/* fine E_ERLOOP   36      E  Entity referenced within itself: ref ignored. */
/* Late additions numbered out of order to avoid recompilation. */
/*      E_ERDEF    45      E  Referenced entity undeclared; SYSTEM assumed. */