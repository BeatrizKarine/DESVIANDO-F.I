 
/*-
 * Copyright (c) 1982, 1986, 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)types.h	8.4 (Berkeley) 1/21/94
 */

#ifndef _SYS_TYPES_H_
#define	_SYS_TYPES_H_

#include "cdefs.h"
#if __BSD_VISIBLE
#include "endian"
#else
#include "endian.h"
#endif

#if __BSD_VISIBLE
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;

typedef unsigned char	unchar;		 
typedef	unsigned short	ushort;		 
typedef	unsigned int	uint;		 
typedef unsigned long	ulong;		 

typedef	__cpuid_t	cpuid_t;	 
typedef	__register_t	register_t;	 
#endif 

 
#ifndef	__BIT_TYPES_DEFINED__
#define	__BIT_TYPES_DEFINED__
#endif

#ifndef	_INT8_T_DEFINED_
#define	_INT8_T_DEFINED_
typedef	__int8_t		int8_t;
#endif

#ifndef	_UINT8_T_DEFINED_
#define	_UINT8_T_DEFINED_
typedef	__uint8_t		uint8_t;
#endif

#ifndef	_INT16_T_DEFINED_
#define	_INT16_T_DEFINED_
typedef	__int16_t		int16_t;
#endif

#ifndef	_UINT16_T_DEFINED_
#define	_UINT16_T_DEFINED_
typedef	__uint16_t		uint16_t;
#endif

#ifndef	_INT32_T_DEFINED_
#define	_INT32_T_DEFINED_
typedef	__int32_t		int32_t;
#endif

#ifndef	_UINT32_T_DEFINED_
#define	_UINT32_T_DEFINED_
typedef	__uint32_t		uint32_t;
#endif

#ifndef	_INT64_T_DEFINED_
#define	_INT64_T_DEFINED_
typedef	__int64_t		int64_t;
#endif

#ifndef	_UINT64_T_DEFINED_
#define	_UINT64_T_DEFINED_
typedef	__uint64_t		uint64_t;
#endif

 
typedef	__uint8_t	u_int8_t;
typedef	__uint16_t	u_int16_t;
typedef	__uint32_t	u_int32_t;
typedef	__uint64_t	u_int64_t;

 
typedef	__int64_t	quad_t;
typedef	__uint64_t	u_quad_t;

#if __BSD_VISIBLE
 
typedef __vaddr_t	vaddr_t;
typedef __paddr_t	paddr_t;
typedef __vsize_t	vsize_t;
typedef __psize_t	psize_t;
#endif 

typedef __blkcnt_t	blkcnt_t;	 
typedef __blksize_t	blksize_t;	 
typedef	char *		caddr_t;	 
typedef	__int32_t	daddr32_t;	 
typedef	__int64_t	daddr_t;	 
typedef	__dev_t		dev_t;		 
typedef	__fixpt_t	fixpt_t;	 
typedef	__gid_t		gid_t;		 
typedef	__id_t		id_t;		 
typedef	__ino_t		ino_t;		 
typedef	__key_t		key_t;		 
typedef	__mode_t	mode_t;		 
typedef	__nlink_t	nlink_t;	
typedef	__rlim_t	rlim_t;		 
typedef	__segsz_t	segsz_t;	 
typedef	__swblk_t	swblk_t;	 
typedef	__uid_t		uid_t;		 
typedef	__useconds_t	useconds_t;	 
typedef	__suseconds_t	suseconds_t;	 
typedef	__fsblkcnt_t	fsblkcnt_t;	 
typedef	__fsfilcnt_t	fsfilcnt_t;	 

 
#ifndef	_CLOCK_T_DEFINED_
#define	_CLOCK_T_DEFINED_
typedef	__clock_t	clock_t;
#endif

#ifndef	_CLOCKID_T_DEFINED_
#define	_CLOCKID_T_DEFINED_
typedef	__clockid_t	clockid_t;
#endif

#ifndef	_PID_T_DEFINED_
#define	_PID_T_DEFINED_
typedef	__pid_t		pid_t;
#endif

#ifndef	_SIZE_T_DEFINED_
#define	_SIZE_T_DEFINED_
typedef	__size_t	size_t;
#endif

#ifndef	_SSIZE_T_DEFINED_
#define	_SSIZE_T_DEFINED_
typedef	__ssize_t	ssize_t;
#endif

#ifndef	_TIME_T_DEFINED_
#define	_TIME_T_DEFINED_
typedef	__time_t	time_t;
#endif

#ifndef	_TIMER_T_DEFINED_
#define	_TIMER_T_DEFINED_
typedef	__timer_t	timer_t;
#endif

#ifndef	_OFF_T_DEFINED_
#define	_OFF_T_DEFINED_
typedef	__off_t		off_t;
#endif

 
#if __BSD_VISIBLE && !defined(_KERNEL)
__BEGIN_DECLS
off_t	 lseek(int, off_t, int);
int	 ftruncate(int, off_t);
int	 truncate(const char *, off_t);
__END_DECLS
#endif  
#if __BSD_VISIBLE
 
#define	major(x)	(((unsigned)(x) >> 8) & 0xff)
#define	minor(x)	((unsigned)((x) & 0xff) | (((x) & 0xffff0000) >> 8))
#define	makedev(x,y)	((dev_t)((((x) & 0xff) << 8) | ((y) & 0xff) | (((y) & 0xffff00) << 8)))
#endif

#if defined(__STDC__) && defined(_KERNEL)
 
struct	proc;
struct	pgrp;
struct	ucred;
struct	rusage;
struct	file;
struct	buf;
struct	tty;
struct	uio;
#endif

#ifdef _KERNEL
#if defined(__GNUC__) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901)

#define false	0
#define true	1

#else
 
typedef enum {
	false = 0,
	true = 1
} _Bool;

 
#define	false	false
#define	true	true

#endif

 
#define bool _Bool

 
#define __bool_true_false_are_defined 1

#endif 

#endif  
