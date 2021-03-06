// $XConsortium: test15.C /main/4 1996/08/21 15:48:27 drk $
#include <stdio.h>
#include "Exceptions.hh"
#include <signal.h>

/* This test contains a throw in a constructor which is officially not
   supported by the exceptions library.  Throws in the constructor will
   tend to work when the object that throws is not the last destructable
   object in another destructable because the destructors of later
   destructable members will be called.  See test18.C.

   17:50 22-May-93 DJB
*/

void
catch_abort (int, ...)
{
  puts ("Abort (core not dumped)");
  // Exit normally so Purify can report.
  exit (1);
}

static int serial;

class SomeClass : public Destructable
{
public:
  int id;
  SomeClass()
    { id = serial++; printf ("Constructing SomeClass %d\n", id); }
  ~SomeClass()
    { printf ("Destructing SomeClass %d\n", id); }
};


class SomeOtherClass : public Destructable
{
public:
  SomeClass some_class;
  int id;

  SomeOtherClass()
    { id = serial++;
      throw (Exception());
      printf ("Constructing SomeOtherClass %d\n", id); }
  ~SomeOtherClass()
    { printf ("Destructing SomeOtherClass %d\n", id); }
};


class ErrorString : public Exception
{
public:
  DECLARE_EXCEPTION (ErrorString, Exception);

  ErrorString (char *s)
    { msg = s; }
  char *msg;
};


void
do_something()
{
  SomeOtherClass some_other_class;

  throw (ErrorString ("Tossed my cookies in do_something"));
}


int
main()
{
  INIT_EXCEPTIONS();

  puts ("Testing descruction of object members.");

#ifdef MUST_EXIT
  signal (SIGABRT, catch_abort);
#endif

  try
    {
      do_something();
    }
  // Do it right in this section. 
  catch (ErrorString &,e)
    {
      puts ("Caught exception back in main.");
      puts (e.msg);
    }
  catch (Exception &,e)
    {
      puts ("This will be printed.");
    }
  end_try;
}
