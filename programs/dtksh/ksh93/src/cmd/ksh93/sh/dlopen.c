/* $XConsortium: dlopen.c /main/3 1995/11/01 16:46:38 rswiston $ */
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
#include	<ast.h>
#include	<error.h>
#include	<nval.h>
#include	"FEATURE/dynamic"

#if	defined(_hdr_dlfcn) && defined(_lib_dlopen)
    int __STUB_dlopen;
#else
#   ifdef _hdr_dl /* HP-UX style interface */
#	include	<dl.h>
#	ifndef BIND_FIRST
#	    define BIND_FIRST	0x4
#	endif /* BIND_FIRST */
#	ifndef BIND_NOSTART
#	    define BIND_NOSTART	0x10
#	endif /* BIND_NOSTART */
	__V_ *dlopen __PARAM__((const char *path,int mode), (path, mode)) __OTORP__(const char *path;int mode;){
		if(mode)
			mode = (BIND_IMMEDIATE|BIND_FIRST|BIND_NOSTART);
		return((__V_*)shl_load(path,mode,0L));
	}
	__V_ *dlsym __PARAM__((__V_ *handle, const char *name), (handle, name)) __OTORP__(__V_ *handle; const char *name;){
		long addr;
		shl_findsym(&handle,name,TYPE_PROCEDURE,&addr);
		return((__V_*)addr);
	}
	char *dlerror __PARAM__((void), ()){
		return(fmterror(errno));
	}
#   else  /* try rs6000 style */
#	if  defined(_sys_ldr) && defined(_lib_loadbind)
#	    include <sys/ldr.h>
#	    include <xcoff.h>
	    /* xcoff module header */
	    struct hdr
	    {
		struct filehdr f;
		struct aouthdr a;
		struct scnhdr s[1];
	    };
	    static struct ld_info *ld_info;
	    static unsigned int ld_info_size=1024;
	    static __V_ *last_module;
	    __V_ *dlopen __PARAM__((const char *path,int mode), (path, mode)) __OTORP__(const char *path;int mode;){
		return((__V_*)load((char*)path,mode,getenv("LIBPATH")));
	    }
	    static int getquery __PARAM__((void), ()){
		if(!ld_info)
			ld_info=(struct ld_info *)malloc(ld_info_size);
		while(1)
		{
			if(!ld_info)
				return(1);
			if(loadquery(L_GETINFO,(void *)ld_info,ld_info_size)==0)
				return(0);
			if(errno != ENOMEM)
				return(1);
			ld_info = (struct ld_info *)realloc(ld_info,ld_info_size*=2);
		}
 	    }
	    /* find the loaded module whose data area contains the
	     * address passed in.  Remember that procedure pointers
	     * are implemented as pointers to descriptors in the
	     * data area of the module defining the procedure
	     */
	    static struct ld_info *getinfo __PARAM__((__V_ *module), (module)) __OTORP__(__V_ *module;){
	    	struct ld_info *info=ld_info;
		register int n=1;
		if (!ld_info || module != last_module)
		{
			last_module = module;
			if(getquery())
				return((struct ld_info *)0);
			info=ld_info;
		}
		while(n)
		{
			if((char*)(info->ldinfo_dataorg) <= (char*)module &&
				(char*)module <= ((char*)(info->ldinfo_dataorg)
				+ (unsigned)(info->ldinfo_datasize)))
				return(info);
			if(n=info->ldinfo_next)
				info = (struct ld_info *)((char*)info +n);
		}
		return((struct ld_info *)0);
	    }
	    static char *getloc __PARAM__((struct hdr *hdr,char * data,char *name), (hdr, data, name)) __OTORP__(struct hdr *hdr;char * data;char *name;){
		struct ldhdr *ldhdr;
		struct ldsym *ldsym;
		ulong datareloc,textreloc;
		int i;
		/* data is relocated by the difference between
		 * its virtual origin and where it was
		 * actually placed
		 */
		/*N.B. o_sndata etc. are one based */
		datareloc = (ulong)data - hdr->s[hdr->a.o_sndata-1].s_vaddr;
		/*hdr is address of header, not text, so add text s_scnptr */
		textreloc = (ulong)hdr + hdr->s[hdr->a.o_sntext-1].s_scnptr
			- hdr->s[hdr->a.o_sntext-1].s_vaddr;
		ldhdr = (struct ldhdr *)((char*)hdr+ hdr->s[hdr->a.o_snloader-1].s_scnptr);
		ldsym = (struct ldsym *) (ldhdr+1);
		/* search the exports symbols */
		for(i=0; i < ldhdr->l_nsyms;ldsym++,i++)
		{
			char *symname,symbuf[9];
			char *loc;
			/* the symbol name representation is a nuisance since
			 * 8 character names appear in l_name but may
			 * not be null terminated.  This code works around
			 * that by brute force
			 */
			if (ldsym->l_zeroes)
			{
				symname = symbuf;
				memcpy(symbuf,ldsym->l_name,8);
				symbuf[8] = 0;
			}
			else
				symname = (__V_*)(ldsym->l_offset + (ulong)ldhdr + ldhdr->l_stoff);
			if(strcmp(symname,name))
				continue;
			loc = (char*)ldsym->l_value;
			if  ((ldsym->l_scnum==hdr->a.o_sndata) ||
				(ldsym->l_scnum==hdr->a.o_snbss))
				loc += datareloc;
			else if  (ldsym->l_scnum==hdr->a.o_sntext)
				loc += textreloc;
			return(loc);
		}
		return((char*)0);
	    }
	    __V_ *dlsym __PARAM__((__V_ *handle, const char *name), (handle, name)) __OTORP__(__V_ *handle; const char *name;){
		struct ld_info *info;
		if(info=getinfo(handle))
			return(getloc(info->ldinfo_textorg,info->ldinfo_dataorg,(char*)name));
		return((__V_*)0);
	    }
	    char *dlerror __PARAM__((void), ()){
		return(fmterror(errno));
	    }
#	else
		__V_ *dlopen __PARAM__((const char *path,int mode), (path, mode)) __OTORP__(const char *path;int mode;){
			return((__V_*)0);
		}
		__V_ *dlsym __PARAM__((__V_ *handle, const char *name), (handle, name)) __OTORP__(__V_ *handle; const char *name;){
			return((__V_*)0);
		}
		char *dlerror __PARAM__((void), ()){
			return("dynamic linking not supported");
		}
#	endif /* _sys_ldr */
#   endif /* _hdr_dl */
#endif /* _hdr_dlfcn */
