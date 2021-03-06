/* $XConsortium: c_iostream.h /main/4 1996/08/21 15:54:57 drk $ */

#ifndef _xostream_h
#define _xostream_h

#include "utility/c_ios.h"

class istream : public virtual ios
{
protected:
   istream&   _getline(char* b, int lim, int delim, int fill_zero);
   int        eatw(); // return EOF if no char available.
                      // Otherwise, return the first no white char.
		      // The char is still in the buffer.

public:
   istream(streambuf* sb);
   virtual ~istream() {};

   istream&        seekg(streampos delta, ios::seek_dir d) ;

   int get();
   istream&        get(char& c);

   istream&        putback(char c);

   istream&        getline(char* b, int lim, char delim='\n');

   istream&        read(char*  s,int n);

   int             gcount() ;

   istream&        operator>>(unsigned short& c);
   istream&        operator>>(unsigned int& c);
   istream&        operator>>(int& c);
   istream&        operator>>(long& c);
   istream&        operator>>(char* s);
   istream&        operator>>(char& c);
};

class ostream : virtual public ios
{
public:

   ostream(streambuf* sb);
   virtual ~ostream() {};

   ostream&        operator<<(void*);
   ostream&        operator<<(const char*);
   ostream&        operator<<(char c);
   ostream&        operator<<(int);
   ostream&        operator<<(unsigned int);
   ostream&        operator<<(long);
    ostream&        operator<< (ostream& (*f)(ostream&));

   ostream& put(char);

   ostream&        flush() ;

   ostream&        write(const char*  s,int n);
};

//class iostream : public istream, public ostream
class iostream : public istream, public ostream
{
public:
   iostream(streambuf* sb);
   virtual ~iostream() {};
};

ostream&        endl(ostream& i) ;

#ifndef STREAM_DEBUG
#define cout (*cout_ptr)
#define cin  (*cin_ptr)
#define cerr (*cerr_ptr)
extern ostream *cout_ptr;
extern istream *cin_ptr;
extern ostream *cerr_ptr;
#endif

#endif
