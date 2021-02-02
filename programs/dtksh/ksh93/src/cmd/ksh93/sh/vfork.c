/* $XConsortium: vfork.c /main/3 1995/11/01 16:53:06 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*          Copyright (c) 1994 AT&T Bell Laboratories           *
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
*                    {ulysses,attmail}!dgk                     *
*                     dgk@ulysses.att.com                      *
*                   David Korn 908-582-7975                    *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#line 1

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
#define __VOID__	__V_
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif

#line 6
#include	"defs.h"
#include	"jobs.h"

/*
 * This module is provided to allow the Shell to work with vfork instead
 * of fork.  With vfork the data area is shared by parent and child.
 * Save state variables at fork and make Shell variables copy on write.
 * Restore everything to previous state when fork_exit is called and
 * terminate process.
 */

/* The following structure contains the variables that must be saved */
struct f_save
{
	struct	f_save		*f_save_fork;
	struct dolnod		*f_savearg;
	char			*f_staksave;
	int			f_stakoff;
	struct sh_scoped	f_sh;
	struct jobs		f_jobstat;
};

static struct f_save *save_fork;	/* most recently saved data */

/*
 * Save state on fork
 * returns 1 if vfork state has been saved
 */
int	sh_vforksave __PARAM__((void), ())
#line 35
{
	register struct f_save *fp;
	if(!(fp = new_of(struct f_save,0)))
		return(0);
	fp->f_save_fork = save_fork;
	save_fork = fp;
	fp->f_stakoff = staktell();
	fp->f_staksave = stakfreeze(0);
	fp->f_sh = sh.st;
	fp->f_jobstat = job;
	job.pwlist = 0;
	fp->f_savearg = sh_arguse();
	sh_onstate(SH_VFORKED);
	return(1);
}

/*
 * Restore state and exit
 */
void	sh_vforkrestore __PARAM__((void), ())
#line 55
{
	register struct f_save *fp = save_fork;

	if(!sh_isstate(SH_VFORKED))
		return;
	sh.st = fp->f_sh;
	job = fp->f_jobstat;
	sh_argfree(fp->f_savearg,0);
	save_fork = fp->f_save_fork;
	stakset(fp->f_staksave,fp->f_stakoff);
	free((__V_*)fp);
}
