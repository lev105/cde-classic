/* $XConsortium: eltdef.h /main/3 1995/11/08 10:44:51 rswiston $ */
/*
              Copyright 1986 Tandem Computers Incorporated.
This product and information is proprietary of Tandem Computers Incorporated.
                   Copyright (c) 1986, 1987, 1988, 1989 Hewlett-Packard Co.
*/

/* Eltdef.h is the include file for allocating global variables in ELTDEF */

#if defined(ELTDEF)
#define ELTEXTERN
#define ELTINIT(a) = a
#else
#define ELTEXTERN extern
#define ELTINIT(a)
#endif

#include "common.h"

/* Error recovery status */
#define RENTITY 0
#define RSIGNON 1
#define RGLOBDEC 2
#define RGLOBDEF 3
#define RELEMENT 4

/* State transition network generated by CONTEXT */
#include "sparse.h"

/* Indicates whether, and if so where, each character can appear in
   a name */
#if defined(ELTDEF)
#include "chartype.h"
#else
extern M_CHARTYPE m_ctarray[M_CHARSETLEN] ;
#endif

/* Scanned name or literal */
ELTEXTERN M_WCHAR name[M_NAMELEN + 1] ;
ELTEXTERN M_WCHAR literal[M_LITLEN + 1] ;

/* Associates a C variable with a particular parameter */
typedef struct cvarstruct CVARSTRUCT ;
struct cvarstruct {
  int param ;
  M_WCHAR *cvarptr ;
  CVARSTRUCT *next ;
  } ;
ELTEXTERN CVARSTRUCT *cvarlist ;
/* Current and previous context (state) of transition system 
   controlling ELTDEF */
ELTEXTERN int curcon ELTINIT(START) ;
ELTEXTERN int m_prevcon ;

/* Character read-ahead buffer */
ELTEXTERN int toundo ELTINIT(0) ;
ELTEXTERN int maxundo ELTINIT(0) ;
#define SAVECHAR 50
ELTEXTERN int savechar[SAVECHAR] ;

/* Chain of elements named in pseudo-tag */
typedef struct chain CHAIN ;
struct chain {
  M_ELEMENT elt ;
  CHAIN *next ;
  } ;
ELTEXTERN CHAIN *firstchain ELTINIT(NULL) ;
ELTEXTERN CHAIN **nextchain ELTINIT(&firstchain) ;

/* Text character returned from scanner */
ELTEXTERN M_WCHAR textchar ;

/* Identifying index of element currently being processed */
ELTEXTERN M_ELEMENT openelt ELTINIT(M_NULLVAL) ;

/* Output files */
ELTEXTERN FILE *globdec, *globdef, *string,
  *pfile, *tfile, *sfile, *efile, *entfile, *ifile, *stfile, *ifh, *pvalh ;

/* Flags indicating whether currently in the middle of processing 
   an action */
ELTEXTERN LOGICAL intext ELTINIT(FALSE),
                  inent ELTINIT(FALSE),
                  inpc ELTINIT(FALSE),
                  insc ELTINIT(FALSE),
                  inec ELTINIT(FALSE),
                  instc ELTINIT(FALSE),
                  instring ELTINIT(FALSE) ;

/* Location of global start-string and end-string, if any */
ELTEXTERN int gss ELTINIT(0), 
              ges ELTINIT(0) ;

/* Flags indicating whether default code setments are to be used */
ELTEXTERN LOGICAL finitext ELTINIT(TRUE), 
                  finipi ELTINIT(TRUE),
                  finistc ELTINIT(TRUE) ;

/* Whether have finished the sign-on message */
ELTEXTERN LOGICAL signonend ELTINIT(FALSE) ;
        
/* Whether errors have occurred */
ELTEXTERN LOGICAL errexit ELTINIT(FALSE) ;

/* Number of characters currently written to stext.h and etext.h */
ELTEXTERN int stringcnt ELTINIT(1) ;

/* Number of actions so far written to code files */
ELTEXTERN int sactions ELTINIT(1), 
              eactions ELTINIT(1), 
              tactions ELTINIT(1), 
              pactions ELTINIT(1),
              stactions ELTINIT(1) ;

/* Pool of ponters for associating a chain of elements with an action string
   or code */
typedef struct action ACTION ;
struct action {
  int data ;
  M_ELEMENT element ;
  int count ;
  ACTION *son ;
  ACTION *next ;
  ACTION *nextact ;
  } ;
ELTEXTERN int actlen ELTINIT(0) ;
ELTEXTERN ACTION *firstact ELTINIT(NULL) ;
ELTEXTERN ACTION **nextact ELTINIT(&firstact) ;

/* Number of elements defined in the document type */
#if defined(M_DTDDEF)
#define ELCOUNT sizeof(m_element)/sizeof(m_element[0])
#else
#define ELCOUNT
#endif

/* Action arrays, indexed by the element in which they occur.  Each element
   is a linked list for actions qualified by the context in which they
   occur. */
ELTEXTERN ACTION *starray[ELCOUNT], 
                 *etarray[ELCOUNT], 
                 *scarray[ELCOUNT],
                 *ecarray[ELCOUNT], 
                 *tcarray[ELCOUNT], 
                 *pcarray[ELCOUNT],
                 *stcarray[ELCOUNT] ;

/* Store the sign-on message */
#define SOCHAR 512
ELTEXTERN char signonmsg[SOCHAR] ;
ELTEXTERN int sochar ELTINIT(0) ;

/* Indicates which elements have been processed at a particular time */
ELTEXTERN LOGICAL processed[ELCOUNT] ;

/* Flags to indicate whether data has yet been written to various files */
ELTEXTERN LOGICAL stringstart ELTINIT(TRUE) ;

/* Flag indicating whether a carriage return was the last character of
   the signon message */
ELTEXTERN LOGICAL socr ELTINIT(FALSE) ;

/* Number of current input line */
ELTEXTERN int m_line ELTINIT(1) ;

/* Pointer to file error for error messages */
ELTEXTERN FILE *m_errfile ;

/* Name of interface file */
#define IFLEN 512
ELTEXTERN char iffile[IFLEN] ; 

/* Pointer to current entity */
ELTEXTERN M_ENTITY *entity ;

/* Count of code entities defined */
ELTEXTERN int codeent ELTINIT(0) ;

/* Content of entity being defined */
ELTEXTERN int entclen ;
ELTEXTERN M_WCHAR entcontent[M_LITLEN + 1] ;

/* Error recovery status */
ELTEXTERN int restart ELTINIT(RENTITY) ;

/* Strings to write to generated files */
#define pproto "M_WCHAR *m_pi, M_WCHAR *m_entname, int m_enttype"
#define pformal "m_pi, m_entname, m_enttype"
#define pftype "  M_WCHAR *m_pi ;\n  M_WCHAR *m_entname ;\n  int m_enttype ;"
#define tproto "M_WCHAR m_textchar"
#define tformal "m_textchar"
#define tftype "  M_WCHAR m_textchar ;\n"
#define stproto "M_WCHAR *m_string, LOGICAL M_START, LOGICAL M_END"
#define stformal "m_string, M_START, M_END"
#define stft "  M_WCHAR *m_string ;\n  LOGICAL M_START ;\n  LOGICAL M_END ;\n"
#define nopar "M_NOPAR"

/* Structures for generating defines for parameter values */
ELTEXTERN M_TRIE parval ;
typedef struct {
  M_WCHAR *cname ;
  M_WCHAR *value ;
  int line ;
  } PARVAL ;
ELTEXTERN PARVAL *pval ;

/* Function prototypes */
#include "proto.h"

/* Flag to open fewer files for convenience of debugging with
   CodeView */
ELTEXTERN LOGICAL debug ELTINIT(FALSE) ;
/* Scanner trace for debugging */
ELTEXTERN LOGICAL scantrace ELTINIT(FALSE) ;
/* Test validity of heap in calls to malloc/free */
ELTEXTERN LOGICAL m_heapchk ELTINIT(FALSE) ;
/* Trace calls to malloc/free */
ELTEXTERN LOGICAL m_malftrace ELTINIT(FALSE) ;

