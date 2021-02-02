/* $XConsortium: autoNumber.h /main/6 1996/10/08 19:24:51 cde-hal $ */

#ifndef _autoNumber_h
#define _autoNumber_h 1

#ifndef CDE_NEXT

#else
#include "dti_cc/CC_Slist.h"
#include "dti_cc/CC_Stack.h"
#endif

#include "utility/buffer.h"
#include "FPExceptions.h"


class autoNumber : public Destructable
{
public:
   enum autoNumberType { NUMERIC, ALPHABETIC, ROMAN };

   autoNumber(const char* nm, enum autoNumberType, int delta, const char* prefix, const char* postfix);
   ~autoNumber();

   void setNumTagsSeen();

   virtual const char* getValue() = 0;
   virtual void  setNextValue() = 0;
   virtual void reset();

   void push();
   void pop();

   unsigned int operator==(const autoNumber&);

   friend ostream& operator<<(ostream&, const autoNumber&) ;

protected:
   static buffer f_buf;
   int f_delta;
   char* f_prefix;
   char* f_postfix;
   char* f_name;
   enum autoNumberType f_type;

   int f_initialValue;
   Stack<int> f_values;
   Stack<int> f_serial_nums;
};

class autoNumberNumeric : public autoNumber
{
public:
   autoNumberNumeric (const char* name, int delta, int initialValue, const char* prefix, const char* postfix);
   ~autoNumberNumeric();

   void setNextValue() ;
   const char* getValue() ;
};

class autoNumberCased : public autoNumber
{
public:
   enum CaseType { UPPER, LOWER}; 

   autoNumberCased(const char* name, 
		   enum autoNumberType, 
		   int delta, 
		   CaseType,
		   const char* prefix,
		   const char* postfix
		  );
   ~autoNumberCased();

protected:
   CaseType f_case;

};

//////////////////////////////////////////////////////
// Sequence example:
//   a, b, ..., z,
//   aa, ab,    az,
//   ba, bb,    bz,
//   ...       ...
//////////////////////////////////////////////////////
class autoNumberAlphabetic : public autoNumberCased
{
private:
   static const int f_base;

   static char f_lowerCaseLetters[26];
   static char f_upperCaseLetters[26];

public:
   autoNumberAlphabetic
		  (const char* name, 
		   int delta, 
		   CaseType,
		   const char* initialValue,
		   const char* prefix,
		   const char* postfix
		  );
   ~autoNumberAlphabetic();

   void setNextValue() ;
   const char* getValue() ;

// convert an integer to an alphabetic autonumber
// Example
// a <- 0, b <- 1, ..., z <- 25
// aa <- 26, ab <- 27, ..., az <- 51
   static const char* intToAlpha(int, enum CaseType);

// convert an alphabetic autonumber to an integer
// Example
// a -> 0, b -> 1, ..., z -> 25
// aa -> 26, ab -> 27, ..., az -> 51
   static int alphaToInt(const char*, enum CaseType);

};

class autoNumberRoman : public autoNumberCased
{
private:
   static char RomanNumberBuf[256];

private:
   static int getDigit(const char*&);

public:
   autoNumberRoman
		  (const char* name, 
		   int delta, 
		   CaseType,
		   const char* initialValue,
		   const char* prefix,
		   const char* postfix
	          );
   ~autoNumberRoman();

   void setNextValue() ;
   const char* getValue() ;

   static int RomanToArabic(const char*);
   // ArabicToRoman needs to be non-static because of the requirement of
   // case sensitiveness
   const char* ArabicToRoman(int);
   
};

#ifndef CDE_NEXT
class autoNumberListT : public CC_TPtrSlist<autoNumber>
#else
class autoNumberListT : public CC_TPtrSlist<autoNumber>
#endif
{
public:
   autoNumberListT() {};
   ~autoNumberListT() {};
   unsigned int operator==(const autoNumberListT&);
} ;

#endif
