/* $XConsortium: SearchEng.h /main/2 1996/07/18 16:48:56 drk $ */
// SearchEngine.h - This serves as a base class for different search engine

#ifndef SRH_ENG_HEADER
#define SRH_ENG_HEADER

#include "FlexBuffer.h"

template <class Type> class Stack;

class ComplexTask;
class Token;
class NodeData;
class GraphicsTask;

class SearchEngine : public ComplexTask {

protected:

  const FlexBuffer *termsBuffer;
  int   f_base;
  int   hasTerms;
  int   CollectObject;
  NodeData     *f_parent;
  GraphicsTask *f_graphics;

protected:
  virtual void write_start_tag ( const Token & ) = 0;
  virtual void write_end_tag   ( const Token & ) = 0;
  virtual void write_terms ( FlexBuffer *termsbuf ) = 0;

  virtual void write_buffer() = 0; /*
				    * This corresponds to the 
				    * write_fulcrum_buffer, write_qsearch_buffer 
				    */
public:

  /* The following 2 are pure virtual, so that each derived class has to 
   * redefine them
   */
  virtual void markup( const Token &) = 0;
  virtual void data ( const char *, size_t ) = 0;

  /* default will be used if not redefined by the derived class
   */
  virtual int          HasSearchTerms() const;
  virtual const FlexBuffer   *DumpSearchTerms();
  virtual int          GraphicsIsDone() const;
  virtual NodeData     *node_data() { return f_parent; }


protected:
  SearchEngine( NodeData *, const Token &);  /* This is not intended to be
					      * used as a constructor for 
					      * instantiation an object
					      * but used as a common point
					      * of initialization of all the
					      * base classes for SearchEng
					      */

public:

  virtual ~SearchEngine() {}

};

inline
int
SearchEngine::HasSearchTerms() const
{
  return( hasTerms );
}

//---------------------------------------------------------------------
inline
const FlexBuffer *
SearchEngine::DumpSearchTerms()
{
  hasTerms = 0;
  return ( termsBuffer );
}

#endif

  

