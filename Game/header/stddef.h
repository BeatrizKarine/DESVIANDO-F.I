
#ifndef _STDDEF
#define _STDDEF
#ifndef _YVALS
 #include "yvals.h"
#endif 
_C_STD_BEGIN

#ifndef NULL
 #define NULL	_NULL
#endif

#ifndef offsetof
#define offsetof(T, member)	((_CSTD _Sizet)&(((T *)0)->member))
#endif 
 #if !defined(_PTRDIFF_T) && !defined(_PTRDIFFT)
  #define _PTRDIFF_T
  #define _PTRDIFFT
  #define _STD_USING_PTRDIFF_T
typedef _Ptrdifft ptrdiff_t;
 #endif 

 #if !defined(_SIZE_T) && !defined(_SIZET) \
	&& !defined(_BSD_SIZE_T_DEFINED_)
  #define _SIZE_T
  #define _SIZET
  #define _BSD_SIZE_T_DEFINED_
  #define _STD_USING_SIZE_T
typedef _Sizet size_t;
 #endif 

#ifndef _WCHART
 #define _WCHART
typedef _Wchart wchar_t;
#endif 
_C_STD_END
#endif

 #if defined(_STD_USING) && defined(__cplusplus)
  #ifdef _STD_USING_PTRDIFF_T
using _CSTD ptrdiff_t;
  #endif 

  #ifdef _STD_USING_SIZE_T
using _CSTD size_t;
  #endif 
 #endif 

/*
 * Copyright (c) 1992-2002 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V3.13:1332 */
