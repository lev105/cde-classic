// $XConsortium: feature.cc /main/3 1996/06/11 17:10:23 cde-hal $
#include "StyleSheetExceptions.h"
#include "SymTab.h"
#include "Feature.h"
#include "FeatureValue.h"
#include "StyleSheet.h"




#include <stdlib.h>

void
styleerror(char *errorstr)
{
  cerr << "Parse Error: " << errorstr << endl;
}

main(int argc, char **argv)
{
  INIT_EXCEPTIONS();

  Stack<FeatureSet*,dlist_array<FeatureSet> > *stack;
  Stack<FeatureSet*,dlist_array<FeatureSet> > stack1 ;
  Stack<FeatureSet*,dlist_array<FeatureSet> > stack2 ;

  stack1.push(new FeatureSet());
  stack2.push(new FeatureSet());

  stack = &stack1 ;

  StyleSheet ss ;

  // make sure args are balanced 

  /*
  if (!(argc & 1))
    cout << "feature  [<name> <value>]+" << endl;
    */

  for (int i = 1 ; i < argc ; )
    {
      switch (argv[i][0])
	{
	case '-':
	  // start a new feature set
	  stack = &stack2 ;
	  i++ ;
	  break;
	case '{':
	  {
	    i++ ;
	    FeatureSet *newset = new FeatureSet();
	    stack->top()->add(new Feature(gSymTab->intern(argv[i++]),
					  new FeatureValueFeatureSet(newset)));
	    stack->push(newset);
	  }
	  break;
	  
	case '}':
	  stack->pop();
	  i++;
	  break;

	default:
	  {
	    char c = argv[i+1][0] ;
	    FeatureValue *value = 0; 

	    if (c >= '0' && c <= '9')
	      value = new FeatureValueInt(atoi(argv[i+1]));
	    else if ( c == '\'')
	      value = new FeatureValueSymbol(gSymTab->intern(argv[i+1]));
	    else
	      value = new FeatureValueString(argv[i+1]);

	    stack->top()->add(new Feature(gSymTab->intern(argv[i++]),
					  value));
	    i++;
	  }
	  break;
	}
    }

  cout << "************** orig ****************" << endl;
  cout << *stack1.top() << endl;
  cout << "************** copy ****************" << endl;

  FeatureSet *copy = new FeatureSet(*stack1.top());

  cout << *copy << endl;
  delete copy;

  // now test merge 

  FeatureSet *merged = new FeatureSet(*stack1.top(), *stack2.top());
		      
  // delete these and check for memory leaks
  delete stack1.pop();
  delete stack2.pop();

  cout << "************** merged ****************" << endl;
  cout << *merged << endl;


  try {
    const Feature *f = merged->deep_lookup("font", "size", 0);
    cout << "deep_lookup(\"font\", \"size\"): " ;
    if (f)
      cout << *f << endl;
    else
      cout << "(nil)" << endl;
    
    // now try it with Symbols 
    Symbol font (gSymTab->intern("font"));
    Symbol size (gSymTab->intern("size"));
    f = merged->deep_lookup(&font,
			    &size, 0);
    cout << "deep_lookup(\"font\", \"size\"): " ;
    if (f)
      cout << *f << endl;
    else
      cout << "(nil)" << endl;
    
  }
  catch_any()
    {
      cout << "exception thrown" << endl;
    }
  end_try;

  delete merged ;

}
