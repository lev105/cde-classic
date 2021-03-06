// $XConsortium: test6.cc /main/3 1996/06/11 16:54:47 cde-hal $
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

// Test function to print the error in a cool box. 

void
error_handler (const char *line[], int nlines)
{
  int i, n, maxlen = 0;
  static char border[100];

  for (i = 0; i < nlines; i++)
    if (strlen (line[i]) > maxlen)
      maxlen = strlen (line[i]);

  maxlen += 6;
  border[0] = border[maxlen-1] = '+';
  border[maxlen] = '\n';
  border[maxlen+1] = '\0';

  for (i = 1; i < maxlen - 1; i++)
    border[i] = '-';
  fputs (border, stderr);

  border[0] = border[maxlen-1] = '|';
  for (n = 0; n < nlines; n++)
    {
      for (i = 1; i < maxlen - 1; i++)
	border[i] = ' ';

      for (i = 0; i < strlen (line[n]); i++)
	   border[i+3] = line[n][i];

      fputs (border, stderr);
    }

  for (i = 1; i < maxlen - 1; i++)
    border[i] = '-';
  border[0] = border[maxlen-1] = '+';
  fputs (border, stderr);
}

int
main()
{
  INIT_EXCEPTIONS();

  puts ("Testing the custom error handler functionality.");
  
#ifdef MUST_EXIT
  signal (SIGABRT, catch_abort);
#endif

  Exceptions::set_error_handler (error_handler);
  
  try
    {
      puts ("Trying something");
      throw (Exception());
    }
  end_try;

}
