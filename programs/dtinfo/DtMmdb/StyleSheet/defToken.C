/* A lexical scanner generated by flex */

/* scanner skeleton version:
 * $XConsortium: defToken.C /main/5 1996/08/21 15:57:31 drk $
 */

#define FLEX_SCANNER

#include <stdio.h>


/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif


#ifdef __cplusplus

#include <stdlib.h>

#if !defined(__osf__) && !defined(USL)
#include <osfcn.h>
#endif

/* use prototypes in function declarations */
#define defParser_USE_PROTOS

/* the "const" storage-class-modifier is valid */
#define defParser_USE_CONST

#else	/* ! __cplusplus */

#ifdef __STDC__

#ifdef __GNUC__
#include <stddef.h>
void *malloc( size_t );
void free( void* );
#else
#include <stdlib.h>
#endif	/* __GNUC__ */

#define defParser_USE_PROTOS
#define defParser_USE_CONST

#endif	/* __STDC__ */
#endif	/* ! __cplusplus */


#ifdef __TURBOC__
#define defParser_USE_CONST
#endif


#ifndef defParser_USE_CONST
#define const
#endif


#ifdef defParser_USE_PROTOS
#define defParser_PROTO(proto) proto
#else
#define defParser_PROTO(proto) ()
/* we can't get here if it's an ANSI C compiler, or a C++ compiler,
 * so it's got to be a K&R compiler, and therefore there's no standard
 * place from which to include these definitions
 */
char *malloc();
int free();
int read();
#endif


/* amount of stuff to slurp up with each read */
#ifndef defParser_READ_BUF_SIZE
#define defParser_READ_BUF_SIZE 8192
#endif

/* returned upon end-of-file */
#define defParser_END_TOK 0

/* copy whatever the last rule matched to the standard output */

/* cast to (char *) is because for 8-bit chars, defParsertext is (unsigned char *) */
/* this used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite()
 */
#define ECHO (void) fwrite( (char *) defParsertext, defParserleng, 1, defParserout )

/* gets input and stuffs it into "buf".  number of characters read, or defParser_NULL,
 * is returned in "result".
 */
#define defParser_INPUT(buf,result,max_size) \
	if ( (result = read( fileno(defParserin), (char *) buf, max_size )) < 0 ) \
	    defParser_FATAL_ERROR( "read() in flex scanner failed" );
#define defParser_NULL 0

/* no semi-colon after return; correct usage is to write "defParserterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#define defParserterminate() return ( defParser_NULL )

/* report a fatal error */

/* The funky do-while is used to turn this macro definition into
 * a single C statement (which needs a semi-colon terminator).
 * This avoids problems with code like:
 *
 * 	if ( something_happens )
 *		defParser_FATAL_ERROR( "oops, the something happened" );
 *	else
 *		everything_okay();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the defParser_FATAL_ERROR() call.
 */

#define defParser_FATAL_ERROR(msg) \
	do \
		{ \
		(void) fputs( msg, stderr ); \
		(void) putc( '\n', stderr ); \
		exit( 1 ); \
		} \
	while ( 0 )

/* default defParserwrap function - always treat EOF as an EOF */
#define defParserwrap() 1

/* enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN
 */
#define BEGIN defParser_start = 1 + 2 *

/* action number for EOF rule of a given start state */
#define defParser_STATE_EOF(state) (defParser_END_OF_BUFFER + state + 1)

/* special action meaning "start processing a new file" */
#define defParser_NEW_FILE \
	do \
		{ \
		defParser_init_buffer( defParser_current_buffer, defParserin ); \
		defParser_load_buffer_state(); \
		} \
	while ( 0 )

/* default declaration of generated scanner - a define so the user can
 * easily add parameters
 */
#define defParser_DECL int defParserlex defParser_PROTO(( void )) 

/* code executed at the end of each rule */
#define defParser_BREAK break;

#define defParser_END_OF_BUFFER_CHAR 0

#ifndef defParser_BUF_SIZE
#define defParser_BUF_SIZE (defParser_READ_BUF_SIZE * 2) /* size of default input buffer */
#endif

typedef struct defParser_buffer_state *defParser_BUFFER_STATE;

#define defParser_CHAR unsigned char
# line 1 "defToken.l"
#define INITIAL 0
# line 10 "defToken.l"
#include <string.h>
#include "FeatureDefDictionary.h"
#include "defParser.tab.h"
#include "Debug.h"
#include <iostream.h>

extern istream *g_defParserin;

#undef defParser_INPUT
#define defParser_INPUT(buf,result,max_size)\
  {\
     if (g_defParserin -> eof()) {\
        result=0;\
     } else {\
        g_defParserin -> read((char *)buf, max_size-1); \
        result = g_defParserin -> gcount(); \
        buf[result] = 0; \
     }\
  }

int defParserlineno=1;

unsigned char* defToken_string_buf = new unsigned char[1024];
int defToken_string_buf_size = 1024;
int defToken_string_buf_content_size = 0;

unsigned char* new_copy(const unsigned char* str, int size)
{
   unsigned char* x = new unsigned char[ ( size <= 0 ) ? 1 : size + 1];
   memcpy(x, str, size);
   x[size] = 0;
   return x;
}

void addToDefTokenStringBuf(const unsigned char* str, int size)
{
   if ( size <= 0 ) return;

   if ( defToken_string_buf_size - defToken_string_buf_content_size < size ) {
      defToken_string_buf_size = 2*(size+defToken_string_buf_content_size);
      unsigned char* x = new unsigned char[defToken_string_buf_size];
      memcpy(x, defToken_string_buf, defToken_string_buf_content_size);
      delete defToken_string_buf;
      defToken_string_buf = x;
   }

   memcpy(defToken_string_buf + defToken_string_buf_content_size, str, size);
   defToken_string_buf_content_size += size;
   defToken_string_buf[defToken_string_buf_content_size] = 0;
}



#define quoted_string 1
# line 74 "defToken.l"

/* done after the current pattern has been matched and before the
 * corresponding action - sets up defParsertext
 */
#define defParser_DO_BEFORE_ACTION \
	defParsertext = defParser_bp; \
	defParserleng = defParser_cp - defParser_bp; \
	defParser_hold_char = *defParser_cp; \
	*defParser_cp = '\0'; \
	defParser_c_buf_p = defParser_cp;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* return all but the first 'n' matched characters back to the input stream */
#define defParserless(n) \
	do \
		{ \
		/* undo effects of setting up defParsertext */ \
		*defParser_cp = defParser_hold_char; \
		defParser_c_buf_p = defParser_cp = defParser_bp + n; \
		defParser_DO_BEFORE_ACTION; /* set up defParsertext again */ \
		} \
	while ( 0 )

#define unput(c) defParserunput( c, defParsertext )


struct defParser_buffer_state
    {
    FILE *defParser_input_file;

    defParser_CHAR *defParser_ch_buf;		/* input buffer */
    defParser_CHAR *defParser_buf_pos;	/* current position in input buffer */

    /* size of input buffer in bytes, not including room for EOB characters*/
    int defParser_buf_size;	

    /* number of characters read into defParser_ch_buf, not including EOB characters */
    int defParser_n_chars;

    int defParser_eof_status;		/* whether we've seen an EOF on this buffer */
#define EOF_NOT_SEEN 0
    /* "pending" happens when the EOF has been seen but there's still
     * some text process
     */
#define EOF_PENDING 1
#define EOF_DONE 2
    };

static defParser_BUFFER_STATE defParser_current_buffer;

/* we provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state"
 */
#define defParser_CURRENT_BUFFER defParser_current_buffer


/* defParser_hold_char holds the character lost when defParsertext is formed */
static defParser_CHAR defParser_hold_char;

static int defParser_n_chars;		/* number of characters read into defParser_ch_buf */



#ifndef defParser_USER_ACTION
#define defParser_USER_ACTION
#endif

#ifndef defParser_USER_INIT
#define defParser_USER_INIT
#endif

extern defParser_CHAR *defParsertext;
extern int defParserleng;
extern FILE *defParserin, *defParserout;

defParser_CHAR *defParsertext;
int defParserleng;

FILE *defParserin = (FILE *) 0, *defParserout = (FILE *) 0;

#define defParser_END_OF_BUFFER 29
typedef int defParser_state_type;
static const short int defParser_accept[84] =
    {   0,
        0,    0,    0,    0,   29,   24,   25,   26,   27,   20,
       24,    8,    9,    3,    2,   18,    5,    4,   24,   24,
       24,   24,   24,   24,    6,    7,    1,   22,   28,   21,
       24,   23,    0,   18,   24,   24,   24,   24,   24,   24,
        1,    1,   19,   24,   24,   24,   24,   24,   24,   24,
       24,   24,   24,   13,   24,   16,   24,   24,   24,   24,
       24,   24,   24,   11,   17,   24,   12,   24,   24,   24,
       14,   24,   24,   24,   24,   24,   24,   24,   24,   10,
       24,   15,    0
    } ;

static const defParser_CHAR defParser_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    4,    1,    5,    6,    1,    1,    7,    1,    8,
        9,   10,    4,   11,    1,   12,    4,   13,   13,   13,
       13,   13,   13,   13,   13,   13,   13,   14,   15,    1,
        4,    1,    4,    4,   16,   17,    1,   18,   19,   20,
       21,    1,   22,    1,    1,   23,   24,   25,   26,   27,
        1,   28,   29,   30,    1,    1,    1,   31,   32,    1,
        4,    1,    4,    4,   33,    1,   16,   17,    1,   18,

       19,   20,   21,    1,   22,    1,    1,   23,   24,   25,
       26,   27,    1,   28,   29,   30,    1,    1,    1,   31,
       32,    1,   34,    1,   35,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static const defParser_CHAR defParser_meta[36] =
    {   0,
        1,    2,    3,    2,    2,    1,    1,    2,    2,    2,
        2,    2,    1,    2,    2,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    2,    2
    } ;

static const short int defParser_base[89] =
    {   0,
        0,  119,   33,   34,  124,    0,  126,  126,  126,  126,
        0,  126,  126,  126,  126,   28,  126,  126,   95,   96,
       99,   95,  100,   88,  126,  126,   40,  126,  126,  126,
        0,    0,  104,   34,   79,   80,   81,   74,   87,   74,
       74,    0,   88,   84,   76,   79,   78,   73,   73,   62,
       74,   67,   70,    0,   65,    0,   71,   52,   61,   56,
       48,   50,   43,   37,    0,   43,    0,   41,   42,   38,
       32,   45,   36,   42,   39,   38,   28,   27,   38,    0,
       33,    0,  126,  109,   52,   42,  112,  114
    } ;

static const short int defParser_def[89] =
    {   0,
       83,    1,   84,   84,   83,   85,   83,   83,   83,   83,
       86,   83,   83,   83,   83,   85,   83,   83,   85,   85,
       85,   85,   85,   85,   83,   83,   87,   83,   83,   83,
       85,   86,   83,   85,   85,   85,   85,   85,   85,   85,
       87,   88,   83,   85,   85,   85,   85,   85,   85,   85,
       85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
       85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
       85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
       85,   85,    0,   83,   83,   83,   83,   83
    } ;

static const short int defParser_nxt[162] =
    {   0,
        6,    7,    8,    9,   10,    6,   11,   12,   13,   14,
       15,    9,   16,   17,   18,   19,   20,   21,    6,    6,
        6,   22,    6,    6,    6,    6,    6,   23,   24,    6,
        6,    6,    6,   25,   26,   29,   29,   30,   30,   33,
       34,   42,   32,   42,   42,   33,   34,   42,   42,   42,
       42,   42,   31,   42,   42,   82,   81,   80,   79,   78,
       77,   76,   75,   74,   73,   72,   71,   70,   69,   68,
       67,   66,   65,   42,   42,   42,   64,   42,   42,   63,
       62,   42,   42,   42,   42,   42,   61,   42,   42,   60,
       59,   58,   57,   56,   55,   54,   53,   52,   51,   50,

       43,   49,   48,   47,   46,   45,   44,   42,   42,   28,
       28,   28,   41,   41,   42,   42,   43,   40,   39,   38,
       37,   36,   35,   83,   27,    5,   83,   83,   83,   83,
       83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
       83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
       83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
       83
    } ;

static const short int defParser_chk[162] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    3,    4,    3,    4,   16,
       16,   27,   86,   27,   27,   34,   34,   27,   27,   27,
       27,   27,   85,   27,   27,   81,   79,   78,   77,   76,
       75,   74,   73,   72,   71,   70,   69,   68,   66,   64,
       63,   62,   61,   27,   27,   41,   60,   41,   41,   59,
       58,   41,   41,   41,   41,   41,   57,   41,   41,   55,
       53,   52,   51,   50,   49,   48,   47,   46,   45,   44,

       43,   40,   39,   38,   37,   36,   35,   41,   41,   84,
       84,   84,   87,   87,   88,   88,   33,   24,   23,   22,
       21,   20,   19,    5,    2,   83,   83,   83,   83,   83,
       83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
       83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
       83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
       83
    } ;

static defParser_state_type defParser_last_accepting_state;
static defParser_CHAR *defParser_last_accepting_cpos;

/* the intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed
 */
#define REJECT reject_used_but_not_detected
#define defParsermore() defParsermore_used_but_not_detected
#define defParser_MORE_ADJ 0

/* these variables are all declared out here so that section 3 code can
 * manipulate them
 */
/* points to current character in buffer */
static defParser_CHAR *defParser_c_buf_p = (defParser_CHAR *) 0;
static int defParser_init = 1;		/* whether we need to initialize */
static int defParser_start = 0;	/* start state number */

/* flag which is used to allow defParserwrap()'s to do buffer switches
 * instead of setting up a fresh defParserin.  A bit of a hack ...
 */
static int defParser_did_buffer_switch_on_eof;

static defParser_state_type defParser_get_previous_state defParser_PROTO(( void ));
static defParser_state_type defParser_try_NUL_trans defParser_PROTO(( defParser_state_type current_state ));
static int defParser_get_next_buffer defParser_PROTO(( void ));
static void defParserunput defParser_PROTO(( defParser_CHAR c, defParser_CHAR *buf_ptr ));
void defParserrestart defParser_PROTO(( FILE *input_file ));
void defParser_switch_to_buffer defParser_PROTO(( defParser_BUFFER_STATE new_buffer ));
void defParser_load_buffer_state defParser_PROTO(( void ));
defParser_BUFFER_STATE defParser_create_buffer defParser_PROTO(( FILE *file, int size ));
void defParser_delete_buffer defParser_PROTO(( defParser_BUFFER_STATE b ));
void defParser_init_buffer defParser_PROTO(( defParser_BUFFER_STATE b, FILE *file ));

#define defParser_new_buffer defParser_create_buffer

#ifdef __cplusplus
static int defParserinput defParser_PROTO(( void ));
#else
static int input defParser_PROTO(( void ));
#endif

defParser_DECL
    {
    register defParser_state_type defParser_current_state;
    register defParser_CHAR *defParser_cp, *defParser_bp;
    register int defParser_act;




    if ( defParser_init )
	{
	defParser_USER_INIT;

	if ( ! defParser_start )
	    defParser_start = 1;	/* first start state */

	if ( ! defParserin )
	    defParserin = stdin;

	if ( ! defParserout )
	    defParserout = stdout;

	if ( defParser_current_buffer )
	    defParser_init_buffer( defParser_current_buffer, defParserin );
	else
	    defParser_current_buffer = defParser_create_buffer( defParserin, defParser_BUF_SIZE );

	defParser_load_buffer_state();

	defParser_init = 0;
	}

    while ( 1 )		/* loops until end-of-file is reached */
	{
	defParser_cp = defParser_c_buf_p;

	/* support of defParsertext */
	*defParser_cp = defParser_hold_char;

	/* defParser_bp points to the position in defParser_ch_buf of the start of the
	 * current run.
	 */
	defParser_bp = defParser_cp;

	defParser_current_state = defParser_start;
	if ( defParser_bp[-1] == '\n' )
	    ++defParser_current_state;
defParser_match:
	do
	    {
	    register defParser_CHAR defParser_c = defParser_ec[*defParser_cp];
	    if ( defParser_accept[defParser_current_state] )
		{
		defParser_last_accepting_state = defParser_current_state;
		defParser_last_accepting_cpos = defParser_cp;
		}
	    while ( defParser_chk[defParser_base[defParser_current_state] + defParser_c] != defParser_current_state )
		{
		defParser_current_state = defParser_def[defParser_current_state];
		if ( defParser_current_state >= 84 )
		    defParser_c = defParser_meta[defParser_c];
		}
	    defParser_current_state = defParser_nxt[defParser_base[defParser_current_state] + defParser_c];
	    ++defParser_cp;
	    }
	while ( defParser_current_state != 83 );
	defParser_cp = defParser_last_accepting_cpos;
	defParser_current_state = defParser_last_accepting_state;

defParser_find_action:
	defParser_act = defParser_accept[defParser_current_state];

	defParser_DO_BEFORE_ACTION;
	defParser_USER_ACTION;

do_action:	/* this label is used only to access EOF actions */


	switch ( defParser_act )
	    {
	    case 0: /* must backtrack */
	    /* undo the effects of defParser_DO_BEFORE_ACTION */
	    *defParser_cp = defParser_hold_char;
	    defParser_cp = defParser_last_accepting_cpos;
	    defParser_current_state = defParser_last_accepting_state;
	    goto defParser_find_action;

case 1:
# line 76 "defToken.l"
{
	}
	defParser_BREAK
case 2:
# line 79 "defToken.l"
{
           return(COMMA);
        }
	defParser_BREAK
case 3:
# line 83 "defToken.l"
{
           return(STAR);
        }
	defParser_BREAK
case 4:
# line 87 "defToken.l"
{
           return(SEMI_COLON);
        }
	defParser_BREAK
case 5:
# line 91 "defToken.l"
{
           return(COLON);
        }
	defParser_BREAK
case 6:
# line 95 "defToken.l"
{
           return(FSOPEN);
        }
	defParser_BREAK
case 7:
# line 99 "defToken.l"
{
           return(FSCLOSE);
        }
	defParser_BREAK
case 8:
# line 103 "defToken.l"
{
           return(OPER_parenopen);
        }
	defParser_BREAK
case 9:
# line 107 "defToken.l"
{
           return(OPER_parenclose);
        }
	defParser_BREAK
case 10:
# line 112 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
		return(TYPE);
	}
	defParser_BREAK
case 11:
# line 117 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
		return(TYPE);
	}
	defParser_BREAK
case 12:
# line 122 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
        	return(TYPE);
	}
	defParser_BREAK
case 13:
# line 127 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
		return(TYPE);
	}
	defParser_BREAK
case 14:
# line 132 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
		return(TYPE);
	}
	defParser_BREAK
case 15:
# line 137 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
		return(TYPE);
	}
	defParser_BREAK
case 16:
# line 142 "defToken.l"
{
		defParserlval.charPtrData = new_copy((unsigned char*)defParsertext, defParserleng);
		return(TYPE);
	}
	defParser_BREAK
case 17:
# line 147 "defToken.l"
{
		defParserlval.charPtrData =
                      new_copy((unsigned char*)"INTEGER", strlen("INTEGER"));
		return(TYPE);
	}
	defParser_BREAK
case 18:
# line 153 "defToken.l"
{
		defParserlval.intData = atoi((char*)defParsertext);
		return(INTEGER);
		}
	defParser_BREAK
case 19:
# line 158 "defToken.l"
{
		defParserlval.realData = atof((char*)defParsertext);
		return(REAL);
		}
	defParser_BREAK
case 20:
# line 163 "defToken.l"
{
		BEGIN quoted_string;
		}
	defParser_BREAK
case 21:
# line 167 "defToken.l"
{

		defParserlval.charPtrData = 
			new unsigned char[defToken_string_buf_content_size+1];
		memcpy( defParserlval.charPtrData, 
			defToken_string_buf, 
			defToken_string_buf_content_size+1
		      );

   		defToken_string_buf_content_size = 0;
		BEGIN 0;

		return(QUOTED_STRING);
		}
	defParser_BREAK
case 22:
# line 182 "defToken.l"
{
		addToDefTokenStringBuf((const unsigned char *)defParsertext, defParserleng);
		}
	defParser_BREAK
case 23:
# line 186 "defToken.l"
{
		defParserlval.charPtrData = 
                  (unsigned char*)strdup((const char*)(defParsertext+1));
		return(REF_NAME);
		}
	defParser_BREAK
case 24:
# line 192 "defToken.l"
{
		defParserlval.charPtrData = 
                  (unsigned char*)strdup((const char*)defParsertext);
		return(NORMAL_STRING);
		}
	defParser_BREAK
case 25:
# line 198 "defToken.l"
{
	}
	defParser_BREAK
case 26:
# line 201 "defToken.l"
{
	   defParserlineno++;
	}
	defParser_BREAK
case 27:
# line 205 "defToken.l"
{
	}
	defParser_BREAK
case 28:
# line 210 "defToken.l"
defParser_FATAL_ERROR( "flex scanner jammed" );
	defParser_BREAK
case defParser_STATE_EOF(INITIAL):
case defParser_STATE_EOF(quoted_string):
    defParserterminate();

	    case defParser_END_OF_BUFFER:
		{
		/* amount of text matched not including the EOB char */
		int defParser_amount_of_matched_text = defParser_cp - defParsertext - 1;

		/* undo the effects of defParser_DO_BEFORE_ACTION */
		*defParser_cp = defParser_hold_char;

		/* note that here we test for defParser_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since defParser_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the end-
		 * of-buffer state).  Contrast this with the test in defParserinput().
		 */
		if ( defParser_c_buf_p <= &defParser_current_buffer->defParser_ch_buf[defParser_n_chars] )
		    /* this was really a NUL */
		    {
		    defParser_state_type defParser_next_state;

		    defParser_c_buf_p = defParsertext + defParser_amount_of_matched_text;

		    defParser_current_state = defParser_get_previous_state();

		    /* okay, we're now positioned to make the
		     * NUL transition.  We couldn't have
		     * defParser_get_previous_state() go ahead and do it
		     * for us because it doesn't know how to deal
		     * with the possibility of jamming (and we
		     * don't want to build jamming into it because
		     * then it will run more slowly)
		     */

		    defParser_next_state = defParser_try_NUL_trans( defParser_current_state );

		    defParser_bp = defParsertext + defParser_MORE_ADJ;

		    if ( defParser_next_state )
			{
			/* consume the NUL */
			defParser_cp = ++defParser_c_buf_p;
			defParser_current_state = defParser_next_state;
			goto defParser_match;
			}

		    else
			{
			    defParser_cp = defParser_last_accepting_cpos;
			    defParser_current_state = defParser_last_accepting_state;
			goto defParser_find_action;
			}
		    }

		else switch ( defParser_get_next_buffer() )
		    {
		    case EOB_ACT_END_OF_FILE:
			{
			defParser_did_buffer_switch_on_eof = 0;

			if ( defParserwrap() )
			    {
			    /* note: because we've taken care in
			     * defParser_get_next_buffer() to have set up defParsertext,
			     * we can now set up defParser_c_buf_p so that if some
			     * total hoser (like flex itself) wants
			     * to call the scanner after we return the
			     * defParser_NULL, it'll still work - another defParser_NULL
			     * will get returned.
			     */
			    defParser_c_buf_p = defParsertext + defParser_MORE_ADJ;

			    defParser_act = defParser_STATE_EOF((defParser_start - 1) / 2);
			    goto do_action;
			    }

			else
			    {
			    if ( ! defParser_did_buffer_switch_on_eof )
				defParser_NEW_FILE;
			    }
			}
			break;

		    case EOB_ACT_CONTINUE_SCAN:
			defParser_c_buf_p = defParsertext + defParser_amount_of_matched_text;

			defParser_current_state = defParser_get_previous_state();

			defParser_cp = defParser_c_buf_p;
			defParser_bp = defParsertext + defParser_MORE_ADJ;
			goto defParser_match;

		    case EOB_ACT_LAST_MATCH:
			defParser_c_buf_p =
			    &defParser_current_buffer->defParser_ch_buf[defParser_n_chars];

			defParser_current_state = defParser_get_previous_state();

			defParser_cp = defParser_c_buf_p;
			defParser_bp = defParsertext + defParser_MORE_ADJ;
			goto defParser_find_action;
		    }
		break;
		}

	    default:
#ifdef FLEX_DEBUG
		printf( "action # %d\n", defParser_act );
#endif
		defParser_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	    }
	}
    }


/* defParser_get_next_buffer - try to read in a new buffer
 *
 * synopsis
 *     int defParser_get_next_buffer();
 *     
 * returns a code representing an action
 *     EOB_ACT_LAST_MATCH - 
 *     EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *     EOB_ACT_END_OF_FILE - end of file
 */

static int defParser_get_next_buffer()

    {
    register defParser_CHAR *dest = defParser_current_buffer->defParser_ch_buf;
    register defParser_CHAR *source = defParsertext - 1; /* copy prev. char, too */
    register int number_to_move, i;
    int ret_val;

    if ( defParser_c_buf_p > &defParser_current_buffer->defParser_ch_buf[defParser_n_chars + 1] )
	defParser_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

    /* try to read more data */

    /* first move last chars to start of buffer */
    number_to_move = defParser_c_buf_p - defParsertext;

    for ( i = 0; i < number_to_move; ++i )
	*(dest++) = *(source++);

    if ( defParser_current_buffer->defParser_eof_status != EOF_NOT_SEEN )
	/* don't do the read, it's not guaranteed to return an EOF,
	 * just force an EOF
	 */
	defParser_n_chars = 0;

    else
	{
	int num_to_read = defParser_current_buffer->defParser_buf_size - number_to_move - 1;

	if ( num_to_read > defParser_READ_BUF_SIZE )
	    num_to_read = defParser_READ_BUF_SIZE;

	else if ( num_to_read <= 0 )
	    defParser_FATAL_ERROR( "fatal error - scanner input buffer overflow" );

	/* read in more data */
	defParser_INPUT( (&defParser_current_buffer->defParser_ch_buf[number_to_move]),
		  defParser_n_chars, num_to_read );
	}

    if ( defParser_n_chars == 0 )
	{
	if ( number_to_move == 1 )
	    {
	    ret_val = EOB_ACT_END_OF_FILE;
	    defParser_current_buffer->defParser_eof_status = EOF_DONE;
	    }

	else
	    {
	    ret_val = EOB_ACT_LAST_MATCH;
	    defParser_current_buffer->defParser_eof_status = EOF_PENDING;
	    }
	}

    else
	ret_val = EOB_ACT_CONTINUE_SCAN;

    defParser_n_chars += number_to_move;
    defParser_current_buffer->defParser_ch_buf[defParser_n_chars] = defParser_END_OF_BUFFER_CHAR;
    defParser_current_buffer->defParser_ch_buf[defParser_n_chars + 1] = defParser_END_OF_BUFFER_CHAR;

    /* defParsertext begins at the second character in defParser_ch_buf; the first
     * character is the one which preceded it before reading in the latest
     * buffer; it needs to be kept around in case it's a newline, so
     * defParser_get_previous_state() will have with '^' rules active
     */

    defParsertext = &defParser_current_buffer->defParser_ch_buf[1];

    return ( ret_val );
    }


/* defParser_get_previous_state - get the state just before the EOB char was reached
 *
 * synopsis
 *     defParser_state_type defParser_get_previous_state();
 */

static defParser_state_type defParser_get_previous_state()

    {
    register defParser_state_type defParser_current_state;
    register defParser_CHAR *defParser_cp;

    register defParser_CHAR *defParser_bp = defParsertext;

    defParser_current_state = defParser_start;
    if ( defParser_bp[-1] == '\n' )
	++defParser_current_state;

    for ( defParser_cp = defParsertext + defParser_MORE_ADJ; defParser_cp < defParser_c_buf_p; ++defParser_cp )
	{
	register defParser_CHAR defParser_c = (*defParser_cp ? defParser_ec[*defParser_cp] : 1);
	if ( defParser_accept[defParser_current_state] )
	    {
	    defParser_last_accepting_state = defParser_current_state;
	    defParser_last_accepting_cpos = defParser_cp;
	    }
	while ( defParser_chk[defParser_base[defParser_current_state] + defParser_c] != defParser_current_state )
	    {
	    defParser_current_state = defParser_def[defParser_current_state];
	    if ( defParser_current_state >= 84 )
		defParser_c = defParser_meta[defParser_c];
	    }
	defParser_current_state = defParser_nxt[defParser_base[defParser_current_state] + defParser_c];
	}

    return ( defParser_current_state );
    }


/* defParser_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *     next_state = defParser_try_NUL_trans( current_state );
 */

#ifdef defParser_USE_PROTOS
static defParser_state_type defParser_try_NUL_trans( register defParser_state_type defParser_current_state )
#else
static defParser_state_type defParser_try_NUL_trans( defParser_current_state )
register defParser_state_type defParser_current_state;
#endif

    {
    register int defParser_is_jam;
    register defParser_CHAR *defParser_cp = defParser_c_buf_p;

    register defParser_CHAR defParser_c = 1;
    if ( defParser_accept[defParser_current_state] )
	{
	defParser_last_accepting_state = defParser_current_state;
	defParser_last_accepting_cpos = defParser_cp;
	}
    while ( defParser_chk[defParser_base[defParser_current_state] + defParser_c] != defParser_current_state )
	{
	defParser_current_state = defParser_def[defParser_current_state];
	if ( defParser_current_state >= 84 )
	    defParser_c = defParser_meta[defParser_c];
	}
    defParser_current_state = defParser_nxt[defParser_base[defParser_current_state] + defParser_c];
    defParser_is_jam = (defParser_current_state == 83);

    return ( defParser_is_jam ? 0 : defParser_current_state );
    }


#ifdef defParser_USE_PROTOS
static void defParserunput( defParser_CHAR c, register defParser_CHAR *defParser_bp )
#else
static void defParserunput( c, defParser_bp )
defParser_CHAR c;
register defParser_CHAR *defParser_bp;
#endif

    {
    register defParser_CHAR *defParser_cp = defParser_c_buf_p;

    /* undo effects of setting up defParsertext */
    *defParser_cp = defParser_hold_char;

    if ( defParser_cp < defParser_current_buffer->defParser_ch_buf + 2 )
	{ /* need to shift things up to make room */
	register int number_to_move = defParser_n_chars + 2; /* +2 for EOB chars */
	register defParser_CHAR *dest =
	    &defParser_current_buffer->defParser_ch_buf[defParser_current_buffer->defParser_buf_size + 2];
	register defParser_CHAR *source =
	    &defParser_current_buffer->defParser_ch_buf[number_to_move];

	while ( source > defParser_current_buffer->defParser_ch_buf )
	    *--dest = *--source;

	defParser_cp += dest - source;
	defParser_bp += dest - source;
	defParser_n_chars = defParser_current_buffer->defParser_buf_size;

	if ( defParser_cp < defParser_current_buffer->defParser_ch_buf + 2 )
	    defParser_FATAL_ERROR( "flex scanner push-back overflow" );
	}

    if ( defParser_cp > defParser_bp && defParser_cp[-1] == '\n' )
	defParser_cp[-2] = '\n';

    *--defParser_cp = c;

    /* note: the formal parameter *must* be called "defParser_bp" for this
     *       macro to now work correctly
     */
    defParser_DO_BEFORE_ACTION; /* set up defParsertext again */
    }


#ifdef __cplusplus
static int defParserinput()
#else
static int input()
#endif

    {
    int c;
    defParser_CHAR *defParser_cp = defParser_c_buf_p;

    *defParser_cp = defParser_hold_char;

    if ( *defParser_c_buf_p == defParser_END_OF_BUFFER_CHAR )
	{
	/* defParser_c_buf_p now points to the character we want to return.
	 * If this occurs *before* the EOB characters, then it's a
	 * valid NUL; if not, then we've hit the end of the buffer.
	 */
	if ( defParser_c_buf_p < &defParser_current_buffer->defParser_ch_buf[defParser_n_chars] )
	    /* this was really a NUL */
	    *defParser_c_buf_p = '\0';

	else
	    { /* need more input */
	    defParsertext = defParser_c_buf_p;
	    ++defParser_c_buf_p;

	    switch ( defParser_get_next_buffer() )
		{
		case EOB_ACT_END_OF_FILE:
		    {
		    if ( defParserwrap() )
			{
			defParser_c_buf_p = defParsertext + defParser_MORE_ADJ;
			return ( EOF );
			}

		    defParser_NEW_FILE;

#ifdef __cplusplus
		    return ( defParserinput() );
#else
		    return ( input() );
#endif
		    }
		    break;

		case EOB_ACT_CONTINUE_SCAN:
		    defParser_c_buf_p = defParsertext + defParser_MORE_ADJ;
		    break;

		case EOB_ACT_LAST_MATCH:
#ifdef __cplusplus
		    defParser_FATAL_ERROR( "unexpected last match in defParserinput()" );
#else
		    defParser_FATAL_ERROR( "unexpected last match in input()" );
#endif
		}
	    }
	}

    c = *defParser_c_buf_p;
    defParser_hold_char = *++defParser_c_buf_p;

    return ( c );
    }


#ifdef defParser_USE_PROTOS
void defParserrestart( FILE *input_file )
#else
void defParserrestart( input_file )
FILE *input_file;
#endif

    {
    defParser_init_buffer( defParser_current_buffer, input_file );
    defParser_load_buffer_state();
    }


#ifdef defParser_USE_PROTOS
void defParser_switch_to_buffer( defParser_BUFFER_STATE new_buffer )
#else
void defParser_switch_to_buffer( new_buffer )
defParser_BUFFER_STATE new_buffer;
#endif

    {
    if ( defParser_current_buffer == new_buffer )
	return;

    if ( defParser_current_buffer )
	{
	/* flush out information for old buffer */
	*defParser_c_buf_p = defParser_hold_char;
	defParser_current_buffer->defParser_buf_pos = defParser_c_buf_p;
	defParser_current_buffer->defParser_n_chars = defParser_n_chars;
	}

    defParser_current_buffer = new_buffer;
    defParser_load_buffer_state();

    /* we don't actually know whether we did this switch during
     * EOF (defParserwrap()) processing, but the only time this flag
     * is looked at is after defParserwrap() is called, so it's safe
     * to go ahead and always set it.
     */
    defParser_did_buffer_switch_on_eof = 1;
    }


#ifdef defParser_USE_PROTOS
void defParser_load_buffer_state( void )
#else
void defParser_load_buffer_state()
#endif

    {
    defParser_n_chars = defParser_current_buffer->defParser_n_chars;
    defParsertext = defParser_c_buf_p = defParser_current_buffer->defParser_buf_pos;
    defParserin = defParser_current_buffer->defParser_input_file;
    defParser_hold_char = *defParser_c_buf_p;
    }


#ifdef defParser_USE_PROTOS
defParser_BUFFER_STATE defParser_create_buffer( FILE *file, int size )
#else
defParser_BUFFER_STATE defParser_create_buffer( file, size )
FILE *file;
int size;
#endif

    {
    defParser_BUFFER_STATE b;

    b = (defParser_BUFFER_STATE) malloc( sizeof( struct defParser_buffer_state ) );

    if ( ! b )
	defParser_FATAL_ERROR( "out of dynamic memory in defParser_create_buffer()" );

    b->defParser_buf_size = size;

    /* defParser_ch_buf has to be 2 characters longer than the size given because
     * we need to put in 2 end-of-buffer characters.
     */
    b->defParser_ch_buf = (defParser_CHAR *) malloc( (unsigned) (b->defParser_buf_size + 2) );

    if ( ! b->defParser_ch_buf )
	defParser_FATAL_ERROR( "out of dynamic memory in defParser_create_buffer()" );

    defParser_init_buffer( b, file );

    return ( b );
    }


#ifdef defParser_USE_PROTOS
void defParser_delete_buffer( defParser_BUFFER_STATE b )
#else
void defParser_delete_buffer( b )
defParser_BUFFER_STATE b;
#endif

    {
    if ( b == defParser_current_buffer )
	defParser_current_buffer = (defParser_BUFFER_STATE) 0;

    free( (char *) b->defParser_ch_buf );
    free( (char *) b );
    }


#ifdef defParser_USE_PROTOS
void defParser_init_buffer( defParser_BUFFER_STATE b, FILE *file )
#else
void defParser_init_buffer( b, file )
defParser_BUFFER_STATE b;
FILE *file;
#endif

    {
    b->defParser_input_file = file;

    /* we put in the '\n' and start reading from [1] so that an
     * initial match-at-newline will be true.
     */

    b->defParser_ch_buf[0] = '\n';
    b->defParser_n_chars = 1;

    /* we always need two end-of-buffer characters.  The first causes
     * a transition to the end-of-buffer state.  The second causes
     * a jam in that state.
     */
    b->defParser_ch_buf[1] = defParser_END_OF_BUFFER_CHAR;
    b->defParser_ch_buf[2] = defParser_END_OF_BUFFER_CHAR;

    b->defParser_buf_pos = &b->defParser_ch_buf[1];

    b->defParser_eof_status = EOF_NOT_SEEN;
    }
# line 210 "defToken.l"


void defParsererror(char* msg)
{
   cerr << "line " << defParserlineno << ": " << msg;
}

