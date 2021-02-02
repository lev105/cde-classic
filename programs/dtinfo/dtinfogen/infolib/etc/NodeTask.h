/* $XConsortium: NodeTask.h /main/3 1996/07/18 15:16:53 drk $ */

#ifndef __NodeTask_h
#define __NodeTask_h

#include "Task.h"

class LcfTask;
class SearchStorage;
class BookCaseTask;
class BookTask;
class OL_Data;
class NodeData;

class NodeTask : public ComplexTask{
  /*
   * The NodeTask builds the NodeMeta table:
   *
   *  Table name: NodeMeta
   *   Fields:
   *    STRING node contents ("balanced tag" string) -- "" on first pass
   *    STRING book/toc locator
   *    STRING node locator
   *    STRING node "ordinal", e.g. 2.3.1
   *    STRING node title
   *    STRING node stitle
   */
  
public:
  
  NodeTask(BookTask *book, class NodeTask *parent);

  
  ~NodeTask();
  void markup(const Token& t);
  void data( const char *, size_t);

  const char *locator(); /* throw(Unexpected) if no locator yet */
  BookTask   *book()     { return ( f_book ); }


  const char *styleName();
  const char *title();   /* throw(Unexpected) if no title available yet */
  int   start_node_level() const { return(f_base); }

protected:
  void write_record();

  void reset();

  void endSubNode(const Token& t);

  int checkNodeAF(const Token& t);

  int formatOrd(char * buf, int max);  /* for TOC gen, debugging */

private:
  int f_base;
  char *section_element_name;
  int ord; /* for TOC gen, debugging */

  BookTask *f_book;
  LcfTask  *f_lcf;

  OL_Data *f_shortTitle;
  OL_Data *f_title;
  OL_Data *f_locator;

  int        subnode_pending;
  NodeTask  *f_subnode;
  NodeTask  *f_parent;
  NodeData  *f_data;

  OL_Data   *f_style;
};

#endif /* __NodeTask_h */
