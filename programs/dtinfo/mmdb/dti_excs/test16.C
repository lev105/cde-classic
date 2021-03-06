// $XConsortium: test16.cc /main/3 1996/06/11 16:53:06 cde-hal $
#include <stdio.h>
#include "Exceptions.hh"
#include <signal.h>

void
catch_abort (int, ...)
{
  puts ("Abort (core not dumped)");
  // Exit normally so Purify can report.
  exit (1);
}

static int serial;

class AClass : public Destructable
{
public:
  int id;
  AClass()
    { id = serial++; printf ("Constructing AClass %d\n", id); }
  ~AClass()
    { printf ("Destructing AClass %d\n", id); }
};

class AnotherClass : public Destructable
{
public:
  int id;
  AnotherClass()
    { id = serial++; printf ("Constructing AnotherClass %d\n", id); }
  ~AnotherClass()
    { printf ("Destructing AnotherClass %d\n", id); }
};


class SomeOtherClass : public AClass, public AnotherClass
{
public:
  int id;
  SomeOtherClass()
    { id = serial++; printf ("Constructing SomeOtherClass %d\n", id); }
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
  //  SomeClass some_class;

  throw (ErrorString ("Tossed my cookies in do_something"));
}


int
main()
{
  INIT_EXCEPTIONS();

  puts ("Testing clean up of non-virtual multiply inherited destructable.");

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
      puts ("This will never be printed.");
    }
  end_try;
}
