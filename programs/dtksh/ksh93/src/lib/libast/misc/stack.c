/* $XConsortium: stack.c /main/3 1995/11/01 18:04:55 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
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
static const char id_stack[] = "\n@(#)stack (AT&T Bell Laboratories) 05/01/84\0\n";

#include <ast.h>
#include <stack.h>

/*
 * create a new stack
 */

STACK
stackalloc __PARAM__((register int size, __V_* error), (size, error)) __OTORP__(register int size; __V_* error;){
	register STACK			stack;
	register struct stackblock	*b;

	if (size <= 0) size = 100;
	if (!(stack = newof(0, struct stacktable, 1, 0))) return(0);
	if (!(b = newof(0, struct stackblock, 1, 0)))
	{
		free(stack);
		return(0);
	}
	if (!(b->stack = newof(0, __V_*, size, 0)))
	{
		free(b);
		free(stack);
		return(0);
	}
	stack->blocks = b;
	stack->size = size;
	stack->error = error;
	stack->position.block = b;
	stack->position.index = -1;
	b->next = 0;
	b->prev = 0;
	return(stack);
}

/*
 * remove a stack
 */

void
stackfree __PARAM__((register STACK stack), (stack)) __OTORP__(register STACK stack;){
	register struct stackblock*	b;
	register struct stackblock*	p;

	b = stack->blocks;
	while (p = b)
	{
		b = p->next;
		free(p->stack);
		free(p);
	}
	free(stack);
}

/*
 * clear stack
 */

void
stackclear __PARAM__((register STACK stack), (stack)) __OTORP__(register STACK stack;){
	stack->position.block = stack->blocks;
	stack->position.index = -1;
}

/*
 * get value on top of stack
 */

__V_*
stackget __PARAM__((register STACK stack), (stack)) __OTORP__(register STACK stack;){
	if (stack->position.index < 0) return(stack->error);
	else return(stack->position.block->stack[stack->position.index]);
}

/*
 * push value on to stack
 */

int
stackpush __PARAM__((register STACK stack, __V_* value), (stack, value)) __OTORP__(register STACK stack; __V_* value;){
	register struct stackblock	*b;

	if (++stack->position.index >= stack->size)
	{
		b = stack->position.block;
		if (b->next) b = b->next;
		else
		{
			if (!(b->next = newof(0, struct stackblock, 1, 0)))
				return(-1);
			b = b->next;
			if (!(b->stack = newof(0, __V_*, stack->size, 0)))
				return(-1);
			b->prev = stack->position.block;
			b->next = 0;
		}
		stack->position.block = b;
		stack->position.index = 0;
	}
	stack->position.block->stack[stack->position.index] = value;
	return(0);
}

/*
 * pop value off stack
 */

int
stackpop __PARAM__((register STACK stack), (stack)) __OTORP__(register STACK stack;){
	/*
	 * return:
	 *
	 *	-1	if stack empty before pop
	 *	 0	if stack empty after pop
	 *	 1	if stack not empty before & after pop
	 */

	if (stack->position.index < 0) return(-1);
	else if (--stack->position.index < 0)
	{
		if (!stack->position.block->prev) return(0);
		stack->position.block = stack->position.block->prev;
		stack->position.index = stack->size - 1;
		return(1);
	}
	else return(1);
}

/*
 * set|get stack position
 */

void
stacktell __PARAM__((register STACK stack, int set, STACKPOS* position), (stack, set, position)) __OTORP__(register STACK stack; int set; STACKPOS* position;){
	if (set) stack->position = *position;
	else *position = stack->position;
}