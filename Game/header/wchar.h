/* Copyright (C) 1995-2008, 2009 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */



#ifndef _WCHAR_H

#if !defined __need_mbstate_t && !defined __need_wint_t
# define _WCHAR_H 1
# include <features.h>
#endif

#ifdef _WCHAR_H

# define __need___FILE
# if defined __USE_UNIX98 || defined __USE_XOPEN2K
#  define __need_FILE
# endif
# include <stdio.h>
 
# define __need___va_list
# include <stdarg.h>

# include <bits/wchar.h>


# define __need_size_t
# define __need_wchar_t
# define __need_NULL
#endif
#if defined _WCHAR_H || defined __need_wint_t || !defined __WINT_TYPE__
# undef __need_wint_t
# define __need_wint_t
# include <stddef.h>

 
#if defined __cplusplus && __GNUC_PREREQ (4, 4)
# define __CORRECT_ISO_CPP_WCHAR_H_PROTO
#endif

 
# ifndef _WINT_T
 
#  define _WINT_T
typedef unsigned int wint_t;
# else
 
#  if defined __cplusplus && defined _GLIBCPP_USE_NAMESPACES \
      && defined __WINT_TYPE__
__BEGIN_NAMESPACE_STD
typedef __WINT_TYPE__ wint_t;
__END_NAMESPACE_STD
#  endif
# endif
#endif

#if (defined _WCHAR_H || defined __need_mbstate_t) && !defined __mbstate_t_defined
# define __mbstate_t_defined        1

typedef struct
{
  int __count;
  union
  {
# ifdef __WINT_TYPE__
    __WINT_TYPE__ __wch;
# else
    wint_t __wch;
# endif
    char __wchb[4];
  } __value;               
} __mbstate_t;
#endif
#undef __need_mbstate_t


 
#ifdef _WCHAR_H

__BEGIN_NAMESPACE_C99
 
typedef __mbstate_t mbstate_t;
__END_NAMESPACE_C99
#ifdef __USE_GNU
__USING_NAMESPACE_C99(mbstate_t)
#endif

#ifndef WCHAR_MIN
 
# define WCHAR_MIN __WCHAR_MIN
# define WCHAR_MAX __WCHAR_MAX
#endif

#ifndef WEOF
# define WEOF (0xffffffffu)
#endif

 
#if defined __USE_XOPEN && !defined __USE_UNIX98
# include <wctype.h>
#endif


__BEGIN_DECLS

__BEGIN_NAMESPACE_STD
 
struct tm;
__END_NAMESPACE_STD
 
__USING_NAMESPACE_STD(tm)


__BEGIN_NAMESPACE_STD
 
extern wchar_t *wcscpy (wchar_t *__restrict __dest,
                        __const wchar_t *__restrict __src) __THROW;
 
extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
                         __const wchar_t *__restrict __src, size_t __n)
     __THROW;

 
extern wchar_t *wcscat (wchar_t *__restrict __dest,
                        __const wchar_t *__restrict __src) __THROW;
 
extern wchar_t *wcsncat (wchar_t *__restrict __dest,
                         __const wchar_t *__restrict __src, size_t __n)
     __THROW;

 
extern int wcscmp (__const wchar_t *__s1, __const wchar_t *__s2)
     __THROW __attribute_pure__;
 
extern int wcsncmp (__const wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     __THROW __attribute_pure__;
__END_NAMESPACE_STD

#ifdef __USE_XOPEN2K8
 
extern int wcscasecmp (__const wchar_t *__s1, __const wchar_t *__s2) __THROW;

 
extern int wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2,
                        size_t __n) __THROW;

 
# include <xlocale.h>

extern int wcscasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
                         __locale_t __loc) __THROW;

extern int wcsncasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
                          size_t __n, __locale_t __loc) __THROW;
#endif

__BEGIN_NAMESPACE_STD
 
extern int wcscoll (__const wchar_t *__s1, __const wchar_t *__s2) __THROW;
 
extern size_t wcsxfrm (wchar_t *__restrict __s1,
                       __const wchar_t *__restrict __s2, size_t __n) __THROW;
__END_NAMESPACE_STD

#ifdef __USE_XOPEN2K8
 

 
extern int wcscoll_l (__const wchar_t *__s1, __const wchar_t *__s2,
                      __locale_t __loc) __THROW;

 
extern size_t wcsxfrm_l (wchar_t *__s1, __const wchar_t *__s2,
                         size_t __n, __locale_t __loc) __THROW;
 
extern wchar_t *wcsdup (__const wchar_t *__s) __THROW __attribute_malloc__;
#endif

__BEGIN_NAMESPACE_STD
 
#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" wchar_t *wcschr (wchar_t *__wcs, wchar_t __wc)
     __THROW __asm ("wcschr") __attribute_pure__;
extern "C++" __const wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc)
     __THROW __asm ("wcschr")  __attribute_pure__;
#else
extern wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc)
     __THROW __attribute_pure__;
#endif
 
#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" wchar_t *wcsrchr (wchar_t *__wcs, wchar_t __wc)
     __THROW __asm ("wcsrchr") __attribute_pure__;
extern "C++" __const wchar_t *wcsrchr (__const wchar_t *__wcs, wchar_t __wc)
     __THROW __asm ("wcsrchr") __attribute_pure__;
#else
extern wchar_t *wcsrchr (__const wchar_t *__wcs, wchar_t __wc)
     __THROW __attribute_pure__;
#endif
__END_NAMESPACE_STD

#ifdef __USE_GNU
 
extern wchar_t *wcschrnul (__const wchar_t *__s, wchar_t __wc)
     __THROW __attribute_pure__;
#endif

__BEGIN_NAMESPACE_STD

extern size_t wcscspn (__const wchar_t *__wcs, __const wchar_t *__reject)
     __THROW __attribute_pure__;

extern size_t wcsspn (__const wchar_t *__wcs, __const wchar_t *__accept)
     __THROW __attribute_pure__;
 
#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" wchar_t *wcspbrk (wchar_t *__wcs, __const wchar_t *__accept)
     __THROW __asm ("wcspbrk") __attribute_pure__;
extern "C++" __const wchar_t *wcspbrk (__const wchar_t *__wcs,
                                       __const wchar_t *__accept)
     __THROW __asm ("wcspbrk") __attribute_pure__;
#else
extern wchar_t *wcspbrk (__const wchar_t *__wcs, __const wchar_t *__accept)
     __THROW __attribute_pure__;
#endif
 
#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" wchar_t *wcsstr (wchar_t *__haystack, __const wchar_t *__needle)
     __THROW __asm ("wcsstr") __attribute_pure__;
extern "C++" __const wchar_t *wcsstr (__const wchar_t *__haystack,
                                      __const wchar_t *__needle)
     __THROW __asm ("wcsstr") __attribute_pure__;
#else
extern wchar_t *wcsstr (__const wchar_t *__haystack, __const wchar_t *__needle)
     __THROW __attribute_pure__;
#endif

 
extern wchar_t *wcstok (wchar_t *__restrict __s,
                        __const wchar_t *__restrict __delim,
                        wchar_t **__restrict __ptr) __THROW;

 
extern size_t wcslen (__const wchar_t *__s) __THROW __attribute_pure__;
__END_NAMESPACE_STD

#ifdef __USE_XOPEN
 
# ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" wchar_t *wcswcs (wchar_t *__haystack, __const wchar_t *__needle)
     __THROW __asm ("wcswcs") __attribute_pure__;
extern "C++" __const wchar_t *wcswcs (__const wchar_t *__haystack,
                                      __const wchar_t *__needle)
     __THROW __asm ("wcswcs") __attribute_pure__;
# else
extern wchar_t *wcswcs (__const wchar_t *__haystack, __const wchar_t *__needle)
     __THROW __attribute_pure__;
# endif
#endif

#ifdef __USE_XOPEN2K8
 
extern size_t wcsnlen (__const wchar_t *__s, size_t __maxlen)
     __THROW __attribute_pure__;
#endif


__BEGIN_NAMESPACE_STD
 
#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" wchar_t *wmemchr (wchar_t *__s, wchar_t __c, size_t __n)
     __THROW __asm ("wmemchr") __attribute_pure__;
extern "C++" __const wchar_t *wmemchr (__const wchar_t *__s, wchar_t __c,
                                       size_t __n)
     __THROW __asm ("wmemchr") __attribute_pure__;
#else
extern wchar_t *wmemchr (__const wchar_t *__s, wchar_t __c, size_t __n)
     __THROW __attribute_pure__;
#endif

 
extern int wmemcmp (__const wchar_t *__restrict __s1,
                    __const wchar_t *__restrict __s2, size_t __n)
     __THROW __attribute_pure__;

 
extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
                         __const wchar_t *__restrict __s2, size_t __n) __THROW;

 
extern wchar_t *wmemmove (wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     __THROW;

 
extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) __THROW;
__END_NAMESPACE_STD

#ifdef __USE_GNU
 
extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
                          __const wchar_t *__restrict __s2, size_t __n)
     __THROW;
#endif


__BEGIN_NAMESPACE_STD
 
extern wint_t btowc (int __c) __THROW;

 
extern int wctob (wint_t __c) __THROW;

 
extern int mbsinit (__const mbstate_t *__ps) __THROW __attribute_pure__;

 
extern size_t mbrtowc (wchar_t *__restrict __pwc,
                       __const char *__restrict __s, size_t __n,
                       mbstate_t *__p) __THROW;

 
extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
                       mbstate_t *__restrict __ps) __THROW;

 
extern size_t __mbrlen (__const char *__restrict __s, size_t __n,
                        mbstate_t *__restrict __ps) __THROW;
extern size_t mbrlen (__const char *__restrict __s, size_t __n,
                      mbstate_t *__restrict __ps) __THROW;
__END_NAMESPACE_STD

#ifdef __USE_EXTERN_INLINES
 
extern wint_t __btowc_alias (int __c) __asm ("btowc");
__extern_inline wint_t
__NTH (btowc (int __c))
{ return (__builtin_constant_p (__c) && __c >= '\0' && __c <= '\x7f'
          ? (wint_t) __c : __btowc_alias (__c)); }

extern int __wctob_alias (wint_t __c) __asm ("wctob");
__extern_inline int
__NTH (wctob (wint_t __wc))
{ return (__builtin_constant_p (__wc) && __wc >= L'\0' && __wc <= L'\x7f'
          ? (int) __wc : __wctob_alias (__wc)); }

__extern_inline size_t
__NTH (mbrlen (__const char *__restrict __s, size_t __n,
               mbstate_t *__restrict __ps))
{ return (__ps != NULL
          ? mbrtowc (NULL, __s, __n, __ps) : __mbrlen (__s, __n, NULL)); }
#endif

__BEGIN_NAMESPACE_STD
 
extern size_t mbsrtowcs (wchar_t *__restrict __dst,
                         __const char **__restrict __src, size_t __len,
                         mbstate_t *__restrict __ps) __THROW;

 
extern size_t wcsrtombs (char *__restrict __dst,
                         __const wchar_t **__restrict __src, size_t __len,
                         mbstate_t *__restrict __ps) __THROW;
__END_NAMESPACE_STD


#ifdef        __USE_XOPEN2K8
 
extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
                          __const char **__restrict __src, size_t __nmc,
                          size_t __len, mbstate_t *__restrict __ps) __THROW;

 
extern size_t wcsnrtombs (char *__restrict __dst,
                          __const wchar_t **__restrict __src,
                          size_t __nwc, size_t __len,
                          mbstate_t *__restrict __ps) __THROW;
#endif       
#ifdef __USE_XOPEN
 
extern int wcwidth (wchar_t __c) __THROW;


extern int wcswidth (__const wchar_t *__s, size_t __n) __THROW;
#endif      


__BEGIN_NAMESPACE_STD

extern double wcstod (__const wchar_t *__restrict __nptr,
                      wchar_t **__restrict __endptr) __THROW;
__END_NAMESPACE_STD

#ifdef __USE_ISOC99
__BEGIN_NAMESPACE_C99

extern float wcstof (__const wchar_t *__restrict __nptr,
                     wchar_t **__restrict __endptr) __THROW;
extern long double wcstold (__const wchar_t *__restrict __nptr,
                            wchar_t **__restrict __endptr) __THROW;
__END_NAMESPACE_C99
#endif 


__BEGIN_NAMESPACE_STD

extern long int wcstol (__const wchar_t *__restrict __nptr,
                        wchar_t **__restrict __endptr, int __base) __THROW;


extern unsigned long int wcstoul (__const wchar_t *__restrict __nptr,
                                  wchar_t **__restrict __endptr, int __base)
     __THROW;
__END_NAMESPACE_STD

#if defined __USE_ISOC99 || (defined __GNUC__ && defined __USE_GNU)
__BEGIN_NAMESPACE_C99

__extension__
extern long long int wcstoll (__const wchar_t *__restrict __nptr,
                              wchar_t **__restrict __endptr, int __base)
     __THROW;


__extension__
extern unsigned long long int wcstoull (__const wchar_t *__restrict __nptr,
                                        wchar_t **__restrict __endptr,
                                        int __base) __THROW;
__END_NAMESPACE_C99
#endif

#if defined __GNUC__ && defined __USE_GNU

__extension__
extern long long int wcstoq (__const wchar_t *__restrict __nptr,
                             wchar_t **__restrict __endptr, int __base)
     __THROW;


__extension__
extern unsigned long long int wcstouq (__const wchar_t *__restrict __nptr,
                                       wchar_t **__restrict __endptr,
                                       int __base) __THROW;
#endif 

#ifdef __USE_GNU
# include "xlocale.h"


extern long int wcstol_l (__const wchar_t *__restrict __nptr,
                          wchar_t **__restrict __endptr, int __base,
                          __locale_t __loc) __THROW;

extern unsigned long int wcstoul_l (__const wchar_t *__restrict __nptr,
                                    wchar_t **__restrict __endptr,
                                    int __base, __locale_t __loc) __THROW;

__extension__
extern long long int wcstoll_l (__const wchar_t *__restrict __nptr,
                                wchar_t **__restrict __endptr,
                                int __base, __locale_t __loc) __THROW;

__extension__
extern unsigned long long int wcstoull_l (__const wchar_t *__restrict __nptr,
                                          wchar_t **__restrict __endptr,
                                          int __base, __locale_t __loc)
     __THROW;

extern double wcstod_l (__const wchar_t *__restrict __nptr,
                        wchar_t **__restrict __endptr, __locale_t __loc)
     __THROW;

extern float wcstof_l (__const wchar_t *__restrict __nptr,
                       wchar_t **__restrict __endptr, __locale_t __loc)
     __THROW;

extern long double wcstold_l (__const wchar_t *__restrict __nptr,
                              wchar_t **__restrict __endptr,
                              __locale_t __loc) __THROW;
#endif 


#ifdef        __USE_XOPEN2K8

extern wchar_t *wcpcpy (wchar_t *__dest, __const wchar_t *__src) __THROW;


extern wchar_t *wcpncpy (wchar_t *__dest, __const wchar_t *__src, size_t __n)
     __THROW;
#endif       




#ifdef        __USE_XOPEN2K8

extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __THROW;
#endif

#if defined __USE_ISOC95 || defined __USE_UNIX98
__BEGIN_NAMESPACE_STD


extern int fwide (__FILE *__fp, int __mode) __THROW;


extern int fwprintf (__FILE *__restrict __stream,
                     __const wchar_t *__restrict __format, ...);
extern int wprintf (__const wchar_t *__restrict __format, ...);

extern int swprintf (wchar_t *__restrict __s, size_t __n,
                     __const wchar_t *__restrict __format, ...)
     __THROW ;

extern int vfwprintf (__FILE *__restrict __s,
                      __const wchar_t *__restrict __format,
                      __gnuc_va_list __arg)
   
extern int vwprintf (__const wchar_t *__restrict __format,
                     __gnuc_va_list __arg)
    
extern int vswprintf (wchar_t *__restrict __s, size_t __n,
                      __const wchar_t *__restrict __format,
                      __gnuc_va_list __arg)
     __THROW;



extern int fwscanf (__FILE *__restrict __stream,
                    __const wchar_t *__restrict __format, ...)
  
extern int wscanf (__const wchar_t *__restrict __format, ...)
   
extern int swscanf (__const wchar_t *__restrict __s,
                    __const wchar_t *__restrict __format, ...)
     __THROW ;

# if defined __USE_ISOC99 && !defined __USE_GNU \
     && (!defined __LDBL_COMPAT || !defined __REDIRECT) \
     && (defined __STRICT_ANSI__ || defined __USE_XOPEN2K)
#  ifdef __REDIRECT

extern int __REDIRECT (fwscanf, (__FILE *__restrict __stream,
                                 __const wchar_t *__restrict __format, ...),
                       __isoc99_fwscanf);
extern int __REDIRECT (wscanf, (__const wchar_t *__restrict __format, ...),
                       __isoc99_wscanf);
extern int __REDIRECT_NTH (swscanf, (__const wchar_t *__restrict __s,
                                     __const wchar_t *__restrict __format,
                                     ...), __isoc99_swscanf);
#  else
extern int __isoc99_fwscanf (__FILE *__restrict __stream,
                             __const wchar_t *__restrict __format, ...);
extern int __isoc99_wscanf (__const wchar_t *__restrict __format, ...);
extern int __isoc99_swscanf (__const wchar_t *__restrict __s,
                             __const wchar_t *__restrict __format, ...)
     __THROW;
#   define fwscanf __isoc99_fwscanf
#   define wscanf __isoc99_wscanf
#   define swscanf __isoc99_swscanf
#  endif
# endif

__END_NAMESPACE_STD
#endif 
#ifdef __USE_ISOC99
__BEGIN_NAMESPACE_C99

extern int vfwscanf (__FILE *__restrict __s,
                     __const wchar_t *__restrict __format,
                     __gnuc_va_list __arg)
    
extern int vwscanf (__const wchar_t *__restrict __format,
                    __gnuc_va_list __arg);

extern int vswscanf (__const wchar_t *__restrict __s,
                     __const wchar_t *__restrict __format,
                     __gnuc_va_list __arg)
     __THROW ;

# if !defined __USE_GNU \
     && (!defined __LDBL_COMPAT || !defined __REDIRECT) \
     && (defined __STRICT_ANSI__ || defined __USE_XOPEN2K)
#  ifdef __REDIRECT
extern int __REDIRECT (vfwscanf, (__FILE *__restrict __s,
                                  __const wchar_t *__restrict __format,
                                  __gnuc_va_list __arg), __isoc99_vfwscanf);
extern int __REDIRECT (vwscanf, (__const wchar_t *__restrict __format,
                                 __gnuc_va_list __arg), __isoc99_vwscanf);
extern int __REDIRECT_NTH (vswscanf, (__const wchar_t *__restrict __s,
                                      __const wchar_t *__restrict __format,
                                      __gnuc_va_list __arg), __isoc99_vswscanf);
#  else
extern int __isoc99_vfwscanf (__FILE *__restrict __s,
                              __const wchar_t *__restrict __format,
                              __gnuc_va_list __arg);
extern int __isoc99_vwscanf (__const wchar_t *__restrict __format,
                             __gnuc_va_list __arg);
extern int __isoc99_vswscanf (__const wchar_t *__restrict __s,
                              __const wchar_t *__restrict __format,
                              __gnuc_va_list __arg) __THROW;
#   define vfwscanf __isoc99_vfwscanf
#   define vwscanf __isoc99_vwscanf
#   define vswscanf __isoc99_vswscanf
#  endif
# endif

__END_NAMESPACE_C99
#endif 


__BEGIN_NAMESPACE_STD

extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);


extern wint_t getwchar (void);



extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);


extern wint_t putwchar (wchar_t __wc);


extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
                        __FILE *__restrict __stream);

extern int fputws (__const wchar_t *__restrict __ws,
                   __FILE *__restrict __stream);



extern wint_t ungetwc (wint_t __wc, __FILE *__stream);
__END_NAMESPACE_STD


#ifdef __USE_GNU

extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);

extern wint_t fgetwc_unlocked (__FILE *__stream);

extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);


extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);


extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
                                 __FILE *__restrict __stream);


extern int fputws_unlocked (__const wchar_t *__restrict __ws,
                            __FILE *__restrict __stream);
#endif


__BEGIN_NAMESPACE_C99

extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
                        __const wchar_t *__restrict __format,
                        __const struct tm *__restrict __tp) __THROW;
__END_NAMESPACE_C99

# ifdef __USE_GNU
# include "xlocale.h"


extern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize,
                          __const wchar_t *__restrict __format,
                          __const struct tm *__restrict __tp,
                          __locale_t __loc) __THROW;
# endif


#if defined __USE_UNIX98 && !defined __USE_GNU
# define __need_iswxxx
# include "wctype.h"
#endif


#if __USE_FORTIFY_LEVEL > 0 && defined __extern_always_inline
# include "wchar2.h"
#endif

#ifdef __LDBL_COMPAT
# include "wchar-ldbl.h"
#endif

__END_DECLS

#endif        

#endif 


#undef __need_mbstate_t
#undef __need_wint_t
