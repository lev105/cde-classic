/* $XConsortium: streambuf.h /main/4 1996/06/11 17:39:15 cde-hal $ */


#ifndef _x_streambuf_h
#define _x_streambuf_h

#ifdef EOF
#if EOF!=-1
#define EOF (-1)
#endif
#else
#define EOF (-1)
#endif


typedef long streampos;


#ifdef STREAM_DEBUG
#define form x_form 
#define streambuf x_streambuf
#define filebuf x_filebuf
#define ios x_ios
#define iostream x_iostream
#define istream x_istream
#define ostream x_ostream
#define fstream x_fstream
#define istrstream x_istrstream
#define ostrstream x_ostrstream
#endif


class streambuf
{
protected:
   char* base;
   char* end;
   char* get_ptr;
   char* put_ptr;

   int _gcount;
   int _pcount;

   int _capacity;
   int _size;
   int _alloc;

protected:
   enum notify_action_t { GET, PUT };
   virtual void notify(int) {}; 

   virtual int overflow() { return EOF;};
   virtual int underflow() { return EOF; };

   int full() { return ( _size == _capacity ) ? 1 : 0 ; };
   int empty() { return ( _size == 0 ) ? 1 : 0 ; };

   void empty_buffer() {
      _size = 0;
      put_ptr = get_ptr = base;
   };

   int move_get_ptr(int);
   int move_put_ptr(int);

public:
   streambuf();
   streambuf(char* p, int l, int pHasContent = 0);
   virtual ~streambuf();

   virtual int examine() ; // EOF: no char available. Otherwise, 
                                  // return 0.The get_ptr pointer does 
				  // not move.

   virtual int get() ; // EOF: can't get a char. Otherwise, 
                              // return 0. The get_ptr pointer does move.

   virtual int putback(char c) ; // EOF: can't put back. Otherwise, 
			        // putback operation is ok.
   virtual int put(char c) ; // EOF: can't put. Otherwise, 
			    // put operation is ok.

   int gcount() { return _gcount; };
   void clear_gcount() { _gcount = 0; };

   int pcount() { return _pcount; };
   void clear_pcount() { _pcount = 0; };

   virtual int flush() { return EOF; };
   virtual int seekg(streampos) { return EOF; };

   char* get_buf() { return base; };
};

#endif
