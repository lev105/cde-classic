/* $XConsortium: getopt.h /main/3 1996/06/19 17:15:18 drk $ */
/* Declare getopt() and associated variables. */

/* Don't use prototypes in case some system header file has a
conflicting definition.  Systems differ on how they declare the second
parameter. */

extern int getopt();

extern char *optarg;
extern int optind;
extern int opterr;
