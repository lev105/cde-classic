// $XConsortium: test23.cc /main/3 1996/06/11 16:53:52 cde-hal $
#include <stdio.h>
#include "Exceptions.hh"
#include <signal.h>
#include <string.h>

void
catch_abort(int, ...)
{
  puts ("Abort (core not dumped)");
  // Exit normally so Purify can report.
  exit (1);
}

// Test of throw in error handler. 

void
error_handler (const char *[], int)
{
  puts ("Throwing an exception from the error handler.");
  throw (Exception());
}

void terminator()
{
  puts ("I'll be back!");
  throw (Exception());
}

int
main()
{
  INIT_EXCEPTIONS();

  puts ("Testing throw from error handler AND terminate.");
  
#ifdef MUST_EXIT
  signal (SIGABRT, catch_abort);
#endif

  Exceptions::set_error_handler (error_handler);
  set_terminate (terminator);

  try
    {
      puts ("Trying something");
      throw (Exception());
    }
  end_try;

}
