/* $XConsortium: initct.c /main/3 1995/11/08 11:05:54 rswiston $ */
/* Copyright (c) 1987, 1988 Hewlett-Packard Co. */
/* M_initctype initializes the array used to indicate which ASCII
   characters can appear within SGML names */

#include "basic.h"
#include "common.h"
extern char m_chartype[M_CHARSETLEN] ;

void m_initctype(
#if defined(M_PROTO)
  M_NOPAR
#endif
  ) ;

void m_initctype(M_NOPAR)
  {
    int i ;

/* ****************************** NOTE: **********************************
   If the set of name characters is ever modified, make appropriate changes
   in ELTDEF's scanner for testing for valid C identifiers as parameter
   names */
    for (i = 0 ; i < M_CHARSETLEN ; i++) m_chartype[i] = M_NONNAME ;
    for (i = 'A' ; i <= 'Z' ; i++) m_chartype[i] = M_NMSTART ;
    for (i = 'a' ; i <= 'z' ; i++) m_chartype[i] = M_NMSTART ;
    for (i = '0' ; i <= '9' ; i++) m_chartype[i] = M_DIGIT ;
    m_chartype['.'] = m_chartype['-'] = M_NAMECHAR ;
    }