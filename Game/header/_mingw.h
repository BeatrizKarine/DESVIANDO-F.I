#ifndef __MINGW_H
#define __MINGW_H 
#undef __attribute__

#ifndef __GNUC__
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT  __declspec(dllimport)
# endif
# ifndef _CRTIMP
#  define _CRTIMP  __declspec(dllimport)
# endif
# define __DECLSPEC_SUPPORTED
# define __attribute__(x) 
#else
# ifdef __declspec
#  ifndef __MINGW_IMPORT
#   define __MINGW_IMPORT  extern __attribute__ ((dllimport))
#  endif
#  ifndef _CRTIMP
#   ifdef __USE_CRTIMP
#    define _CRTIMP  __attribute__ ((dllimport))
#   else  
#    define _CRTIMP
#   endif
#  endif
#  define __DECLSPEC_SUPPORTED
# else /* __declspec */
#  undef __DECLSPEC_SUPPORTED
#  undef __MINGW_IMPORT
#  ifndef _CRTIMP
#   define _CRTIMP
#  endif
# endif 
# ifndef __cdecl
#  define __cdecl __attribute__ ((__cdecl__))
# endif
# ifndef __stdcall
#  define __stdcall __attribute__ ((__stdcall__))
# endif
# ifndef __int64
#  define __int64 long long
# endif
# ifndef __int32
#  define __int32 long
# endif
# ifndef __int16
#  define __int16 short
# endif
# ifndef __int8
#  define __int8 char
# endif
# ifndef __small
#  define __small char
# endif
# ifndef __hyper
#  define __hyper long long
# endif
#endif 

#ifdef __cplusplus
#define __CRT_INLINE inline
#else
#define __CRT_INLINE extern __inline__
#endif

#ifdef __cplusplus
# define __UNUSED_PARAM(x) 
#else 
# ifdef __GNUC__
#  define __UNUSED_PARAM(x) x __attribute__ ((__unused__))
# else
#  define __UNUSED_PARAM(x) x
# endif
#endif

#ifdef __GNUC__
#define __MINGW_ATTRIB_NORETURN __attribute__ ((__noreturn__))
#define __MINGW_ATTRIB_CONST __attribute__ ((__const__))
#else
#define __MINGW_ATTRIB_NORETURN
#define __MINGW_ATTRIB_CONST
#endif

#if ( __GNUC__ >= 3)
#define __MINGW_ATTRIB_MALLOC __attribute__ ((__malloc__))
#define __MINGW_ATTRIB_PURE __attribute__ ((__pure__))
#else
#define __MINGW_ATTRIB_MALLOC
#define __MINGW_ATTRIB_PURE
#endif

#ifndef __MSVCRT_VERSION__
# define __MSVCRT_VERSION__ 0x0600
#endif

#define __MINGW32_VERSION 3.7
#define __MINGW32_MAJOR_VERSION 3
#define __MINGW32_MINOR_VERSION 7

#endif
