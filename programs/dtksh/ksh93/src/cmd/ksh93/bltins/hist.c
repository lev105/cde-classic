/* $XConsortium: hist.c /main/3 1995/11/01 16:28:36 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Advanced Software Technology Department            *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                    {research,attmail}!dgk                    *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif
#include	"defs.h"
#include	<stak.h>
#include	<ls.h>
#include	<error.h>
#include	<ctype.h>
#include	"variables.h"
#include	"io.h"
#include	"name.h"
#include	"history.h"
#include	"builtins.h"

static void hist_subst __PROTO__((const char*, int fd, char*));

int	b_hist __PARAM__((int argc,char *argv[], __V_ *extra), (argc, argv, extra)) __OTORP__(int argc;char *argv[]; __V_ *extra;){
	register History_t *hp;
	register char *arg;
	register int flag,fdo;
	struct stat statb;
	time_t before;
	Sfio_t *outfile;
	char *fname;
	int range[2], incr, index2, indx= -1;
	char *edit = 0;		/* name of editor */
	char *replace = 0;		/* replace old=new */
	int lflag = 0, nflag = 0, rflag = 0;
	Histloc_t location;
	NOT_USED(argc);
	NOT_USED(extra);
	if(!sh_histinit())
		error(ERROR_system(1),e_histopen);
	hp = sh.hist_ptr;
	while((flag = optget(argv,sh_opthist))) switch(flag)
	{
	    case 'e':
		edit = opt_arg;
		break;
	    case 'n':
		nflag++;
		break;
	    case 'l':
		lflag++;
		break;
	    case 'r':
		rflag++;
		break;
	    case 's':
		edit = "-";
		break;
	    case 'N':
		if(indx<=0)
		{
			if((flag = hist_max(hp) - opt_num-1) < 0)
				flag = 1;
			range[++indx] = flag;
			break;
		}
	    case ':':
		error(2, opt_arg);
		break;
	    case '?':
		error(ERROR_usage(2), opt_arg);
		break;
	}
	if(error_info.errors)
		error(ERROR_usage(2),optusage((char*)0));
	argv += (opt_index-1);
	flag = indx;
	while(flag<1 && (arg=argv[1]))
	{
		/* look for old=new argument */
		if(!replace && strchr(arg+1,'='))
		{
			replace = arg;
			argv++;
			continue;
		}
		else if(isdigit(*arg) || *arg == '-')
		{
			/* see if completely numeric */
			do	arg++;
			while(isdigit(*arg));
			if(*arg==0)
			{
				arg = argv[1];
				range[++flag] = atoi(arg);
				if(*arg == '-')
					range[flag] += (hist_max(hp)-1);
				argv++;
				continue;
			}
		}
		/* search for last line starting with string */
		location = hist_find(hp,argv[1],hist_max(hp)-1,0,-1);
		if((range[++flag] = location.hist_command) < 0)
			error(ERROR_exit(1),e_found,argv[1]);
		argv++;
	}
	if(flag <0)
	{
		/* set default starting range */
		if(lflag)
		{
			flag = hist_max(hp)-17;
			if(flag<1)
				flag = 1;
		}
		else
			flag = hist_max(hp)-2;
		range[0] = flag;
		flag = 0;
	}
	index2 = hist_min(hp);
	if(range[0]<index2)
		range[0] = index2;
	if(flag==0)
		/* set default termination range */
		range[1] = (lflag?hist_max(hp)-2:range[0]);
	if(range[1]>=(flag=(hist_max(hp) - 1)))
		range[1] = flag;
	/* check for valid ranges */
	if(range[1]<index2 || range[0]>=flag)
		error(ERROR_exit(1),e_badrange,range[0],range[1]);
	if(edit && *edit=='-' && range[0]!=range[1])
		error(ERROR_exit(1),e_eneedsarg);
	/* now list commands from range[rflag] to range[1-rflag] */
	incr = 1;
	flag = rflag>0;
	if(range[1-flag] < range[flag])
		incr = -1;
	if(lflag)
	{
		outfile = sfstdout;
		arg = "\n\t";
	}
	else
	{
		if(!(fname=pathtemp(NIL(char*),0,0)))
			error(ERROR_exit(1),e_create,"");
		if((fdo=open(fname,O_CREAT|O_RDWR,S_IRUSR|S_IWUSR)) < 0)
			error(ERROR_system(1),e_create,fname);
		outfile= sfnew(NIL(Sfio_t*),sh.outbuff,IOBSIZE,fdo,SF_WRITE);
		arg = "\n";
		nflag++;
	}
	while(1)
	{
		if(nflag==0)
			sfprintf(outfile,"%d\t",range[flag]);
		else if(lflag)
			sfputc(outfile,'\t');
		hist_list(sh.hist_ptr,outfile,hist_tell(sh.hist_ptr,range[flag]),0,arg);
		if(lflag)
			sh_sigcheck();
		if(range[flag] == range[1-flag])
			break;
		range[flag] += incr;
	}
	if(lflag)
		return(0);
	if(fstat(sffileno(outfile),&statb)>=0)
		before = statb.st_mtime;
	sfclose(outfile);
	hist_eof(hp);
	arg = edit;
	if(!arg && !(arg=nv_getval(nv_scoped(HISTEDIT))) && !(arg=nv_getval(nv_scoped(FCEDNOD))))
		arg = (char*)e_defedit;
#ifdef apollo
	/*
	 * Code to support the FC using the pad editor.
	 * Exampled of how to use: HISTEDIT=pad
	 */
	if (strcmp (arg, "pad") == 0)
	{
		extern __MANGLE__ int pad_create __PROTO__((char*));
		sh_close(fdo);
		fdo = pad_create(fname);
		pad_wait(fdo);
		unlink(fname);
		strcat(fname, ".bak");
		unlink(fname);
		lseek(fdo,(off_t)0,SEEK_SET);
	}
	else
	{
#endif /* apollo */
	if(*arg != '-')
	{
		char *com[3];
		com[0] =  arg;
		com[1] =  fname;
		com[2] = 0;
		error_info.errors = sh_eval(sh_sfeval(com),0);
	}
	fdo = sh_chkopen(fname);
	unlink(fname);
	free((__V_*)fname);
#ifdef apollo
	}
#endif /* apollo */
	/* don't history fc itself unless forked */
	error_info.flags |= ERROR_SILENT;
	if(!sh_isstate(SH_FORKED))
		hist_cancel(hp);
	sh_onstate(SH_VERBOSE|SH_HISTORY);	/* echo lines as read */
	if(replace)
		hist_subst(error_info.id,fdo,replace);
	else if(error_info.errors == 0)
	{
		char buff[IOBSIZE+1];
		Sfio_t *iop = sfnew(NIL(Sfio_t*),buff,IOBSIZE,fdo,SF_READ);
		/* read in and run the command */
		sh_eval(iop,1);
	}
	else
	{
		sh_close(fdo);
		if(!sh_isoption(SH_VERBOSE))
			sh_offstate(SH_VERBOSE|SH_HISTORY);
	}
	return(sh.exitval);
}


/*
 * given a file containing a command and a string of the form old=new,
 * execute the command with the string old replaced by new
 */

static void hist_subst __PARAM__((const char *command,int fd,char *replace), (command, fd, replace)) __OTORP__(const char *command;int fd;char *replace;){
	register char *newp=replace;
	register char *sp;
	register int c;
	off_t size;
	char *string;
	while(*++newp != '='); /* skip to '=' */
	if((size = lseek(fd,(off_t)0,SEEK_END)) < 0)
		return;
	lseek(fd,(off_t)0,SEEK_SET);
	c =  (int)size;
	string = stakalloc(c+1);
	if(read(fd,string,c)!=c)
		return;
	string[c] = 0;
	*newp++ =  0;
	if((sp=sh_substitute(string,replace,newp))==0)
		error(ERROR_exit(1),e_subst,command);
	*(newp-1) =  '=';
	sh_eval(sfopen(NIL(Sfio_t*),sp,"s"),1);
}

