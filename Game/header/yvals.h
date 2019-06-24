
#ifndef _YVALS
#define _YVALS
#include "stdarg.h" 
#define _CPPLIB_VER	402


#if defined(__TI_COMPILER_VERSION__)
 #define _C_IN_NS 1
 #define __EDG__  1
 #define __FPUTS_RETURN_NUM_BYTES__ 1
 #ifdef __EXCEPTIONS
    #undef _NO_EX 
 #else
    #define _NO_EX 1
 #endif 
 #if defined(__unsigned_chars__)
   #define __CHAR_UNSIGNED__ 1
 #else
   #undef __CHAR_UNSIGNED__
   #undef _CHAR_UNSIGNED
 #endif  
 #undef _32_BIT_DOUBLE

 
  #define _HAS_C9X 0
#endif  

 #ifndef __STDC_HOSTED__
  #define __STDC_HOSTED__	1
 #endif 

 #ifndef __STDC_IEC_559__
  #define __STDC_IEC_559__	1
 #endif  

 #ifndef __STDC_IEC_559_COMPLEX__
  #define __STDC_IEC_559_COMPLEX__	1
 #endif  

 #ifndef __STDC_ISO_10646__
  #define __STDC_ISO_10646__	200009L	 
 #endif  
		 

 #if defined(i386) || defined(__i386) \
	|| defined(__i386__) || defined(_M_IX86)	 
  #define _D0		3	 

  #if defined(__BORLANDC__) && !__EDG__
   #pragma warn -inl
   #define _DLONG	1	 
   #define _LBIAS	0x3ffe	 
   #define _LOFF	15	 
  #elif defined(__MINGW32__)
   #define _DLONG	1	 
   #define _LBIAS	0x3ffe	 
   #define _LOFF	15	 

  #elif defined(_M_IX86)
   #define _DLONG	0	 
   #define _LBIAS	0x3fe	 
   #define _LOFF	4	 
  #else  
   #define _DLONG	1	 
   #define _LBIAS	0x3ffe 
   #define _LOFF	15	 
  #endif 

  #define _FPP_TYPE	_FPP_X86	 

 #elif defined(sparc) || defined(__sparc)	 
  #define _D0		0	 
  #define _DLONG	2	 
  #define _LBIAS	0x3ffe	 
  #define _LOFF		15	 
  #define _FPP_TYPE	_FPP_SPARC	 

  #if defined(__arch64__)
   #define _MACH_PDT	long
   #define _MACH_SZT	unsigned long
  #endif  

 #elif defined(_MIPS) || defined(_MIPS_) || defined(_M_MRX000)		
  #define _D0		0	 
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #define _FPP_TYPE	_FPP_MIPS	 

  #define _MACH_PDT	long
  #define _MACH_SZT	unsigned long

 #elif defined(__s390__)	 
  #define _D0		0	 
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #define _FPP_TYPE	_FPP_S390	 

  #define _MACH_PDT	long
  #define _MACH_SZT	unsigned long

 #elif defined(__ppc__) || defined(_POWER) || defined(_M_PPC) 
  #define _D0		0	 
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #define _FPP_TYPE	_FPP_PPC	 

  #if defined(__APPLE__)
   #define _MACH_I32	int
   #define _MACH_PDT	int
   #define _MACH_SZT	unsigned long
  #endif 

 #elif defined(__hppa)	 
  #define _D0		0	 
  #define _DLONG	2	 
  #define _LBIAS	0x3ffe	 
  #define _LOFF		15	 
  #define _FPP_TYPE	_FPP_HPPA	 

 #elif defined(_M_ALPHA)	 
  #define _D0		3	 
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #define _FPP_TYPE	_FPP_ALPHA	 

 #elif defined(_ARM_)	 
  #define _D0		3	 
  #define _DLONG	0	
  #define _LBIAS	0x3fe	
  #define _LOFF		4	
  #define _FPP_TYPE	_FPP_ARM	 

 #elif defined(_M68K) 
  #define _D0		0	 
  #define _DLONG	1	 
  #define _LBIAS	0x3ffe	
  #define _LOFF		15	 
  #define _FPP_TYPE	_FPP_M68K	 

 #elif defined(_SH4_)	 
  #define _D0		0	 
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #define _FPP_TYPE	_FPP_SH4	 

 #elif defined(_M_IA64)	 
  #define _D0		3	 
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #define _FPP_TYPE	_FPP_IA64	 

 #else
   #if defined(__big_endian__)
       #define _D0	0	 
   #elif defined(__little_endian__)
       #define _D0      3        
   #endif
  #define _DLONG	0	 
  #define _LBIAS	0x3fe	 
  #define _LOFF		4	 
  #if defined(_TMS320C6700)
    #define _FPP_TYPE	_FPP_C67  
  #else
    #define _FPP_TYPE	_FPP_NONE 
  #endif

 #endif  

 #if defined(_MACH_I32)
typedef _MACH_I32 _Int32t;
typedef unsigned _MACH_I32 _Uint32t;

 #else  
typedef long _Int32t;
typedef unsigned long _Uint32t;
 #endif  

 #if defined(_MACH_PDT)
typedef _MACH_PDT _Ptrdifft;
 #elif defined(__TI_COMPILER_VERSION__)
typedef  __PTRDIFF_T_TYPE__  _Ptrdifft;
 #else  
typedef int _Ptrdifft;
 #endif  
 #if defined(_MACH_SZT)
typedef _MACH_SZT _Sizet;
 #elif defined(__TI_COMPILER_VERSION__)
typedef  __SIZE_T_TYPE__ _Sizet;
 #else  
typedef unsigned int _Sizet;
 #endif 
 #if defined(__linux)
  #define _LINUX_C_LIB	1	 
 #endif  

 #if defined(_M_IX86) || defined(_M_MRX000) || defined(_M_PPC) \
	|| defined(_M_ALPHA) || defined(_M_IA64) || defined(_WIN32_WCE)
  #define _WIN32_C_LIB	1	 
 #elif defined(__TI_COMPILER_VERSION__)
   #undef _POSIX_C_LIB
 #else  
  #define _POSIX_C_LIB	1	 
 #endif 

 #if !defined(_HAS_C9X) && defined(_C99)
  #define _HAS_C9X	1
 #endif  

 #define _HAS_C9X_IMAGINARY_TYPE	(_HAS_C9X && __EDG__ \
	&& !defined(__cplusplus))

 #if !defined(_ECPP) && defined(_ABRCPP)
  #define _ECPP
 #endif  

 #if !defined(_IS_EMBEDDED) && defined(_ECPP)
  #define _IS_EMBEDDED	1	 
 #endif 
 
 #ifndef _HAS_EXCEPTIONS
  #ifndef _NO_EX	 
   #define _HAS_EXCEPTIONS	1	 

  #else	 
   #define _HAS_EXCEPTIONS	0
  #endif 
 #endif  


 #ifndef _HAS_NAMESPACE
  #ifndef _NO_NS	 
   #define _HAS_NAMESPACE	1	 

  #else	 
   #define _HAS_NAMESPACE	0
  #endif 

 #endif 
 
 #if !defined(_STD_USING) && defined(__cplusplus) \
	&& defined(_C_IN_NS)
  #define _STD_USING	 

 #elif defined(_STD_USING) && !defined(__cplusplus)
  #undef _STD_USING	 
 #endif  

 #if !defined(_HAS_STRICT_LINKAGE) \
	&& __EDG__ && !defined(_WIN32_C_LIB)
  #define _HAS_STRICT_LINKAGE __TI_STRICT_ANSI_MODE__    
 #endif  

		 
#if defined(__TI_COMPILER_VERSION__)
  #define _NO_MT 1
  #define _MULTI_THREAD	0
#else
 #ifndef _MULTI_THREAD

  #ifdef __CYGWIN__
   #define _MULTI_THREAD	0	 

  #else 
   #ifndef _NO_MT
    #define _MULTI_THREAD	1	 
   #else
    #define _MULTI_THREAD	0
   #endif	 
  #endif 
 #endif  
#endif 
 
#define _GLOBAL_LOCALE	0	 
#define _FILE_OP_LOCKS	0	 
#define _IOSTREAM_OP_LOCKS	0	 
		

#define _COMPILER_TLS	0	 
#define _TLS_QUAL	 

 #define _HAS_IMMUTABLE_SETS	1
 #define _HAS_IMMUTABLE_SETS	1
 #define _HAS_TRADITIONAL_IOSTREAMS	0
 #define _HAS_TRADITIONAL_ITERATORS	0
 #define _HAS_TRADITIONAL_POS_TYPE	0
 #define _HAS_TRADITIONAL_STL	1
 #define _HAS_TRADITIONAL_IOSTREAMS	0
 #define _HAS_TRADITIONAL_ITERATORS	0
 #define _HAS_TRADITIONAL_POS_TYPE	0
 #define _HAS_TRADITIONAL_STL	1

 #define _ADDED_C_LIB	1
 #define _USE_EXISTING_SYSTEM_NAMES	1  

 #if !defined(_HAS_STRICT_CONFORMANCE)
  #define _HAS_STRICT_CONFORMANCE	0	 
 #endif

 #if !defined(_HAS_ITERATOR_DEBUGGING) \
	&& (defined(_STL_DB) || defined(_STLP_DEBUG))
  #define _HAS_ITERATOR_DEBUGGING	1	
 #endif 

		

 #if defined(__cplusplus)

 #if _HAS_NAMESPACE
namespace std {}

 #if defined(_C_AS_CPP)
  #define _NO_CPP_INLINES	
 #endif 

 #if defined(_STD_USING)
  #if defined(_C_AS_CPP)	
   #define _STD_BEGIN	namespace std {_C_LIB_DECL
   #define _STD_END		_END_C_LIB_DECL }

  #else 
   #define _STD_BEGIN	namespace std {
   #define _STD_END		}
  #endif

   #define _C_STD_BEGIN	namespace std {
   #define _C_STD_END	}
   #define _CSTD	        ::std::
   #define _STD			::std::

 #else  

  #if defined(_C_AS_CPP)	 
   #define _STD_BEGIN	_C_LIB_DECL
   #define _STD_END		_END_C_LIB_DECL

  #else 
   #define _STD_BEGIN	namespace std {
   #define _STD_END		}
  #endif 

   #define _C_STD_BEGIN	
   #define _C_STD_END	
   #define _CSTD		::
   #define _STD			::std::
 #endif  

  #define _X_STD_BEGIN	namespace std {
  #define _X_STD_END	}
  #define _XSTD			::std::

  #if defined(_STD_USING)
   #undef _GLOBAL_USING		 

  #else
   #define _GLOBAL_USING	 
  #endif  
  #if defined(_STD_LINKAGE)
   #define _C_LIB_DECL		extern "C++" { 
  #else 
   #define _C_LIB_DECL		extern "C" {	
  #endif  

  #define _END_C_LIB_DECL	}
  #define _EXTERN_C			extern "C" {
  #define _END_EXTERN_C		}

 #else  

  #define _STD_BEGIN
  #define _STD_END
  #define _STD	::

  #define _X_STD_BEGIN
  #define _X_STD_END
  #define _XSTD	::

  #define _C_STD_BEGIN
  #define _C_STD_END
  #define _CSTD	::

  #define _C_LIB_DECL		extern "C" {
  #define _END_C_LIB_DECL	}
  #define _EXTERN_C			extern "C" {
  #define _END_EXTERN_C		}
 #endif  

 #else  
  #define _STD_BEGIN
  #define _STD_END
  #define _STD

  #define _X_STD_BEGIN
  #define _X_STD_END
  #define _XSTD

  #define _C_STD_BEGIN
  #define _C_STD_END
  #define _CSTD

  #define _C_LIB_DECL
  #define _END_C_LIB_DECL
  #define _EXTERN_C
  #define _END_EXTERN_C
 #endif  

 #if 199901L <= __STDC_VERSION__

 #if defined(__GNUC__) || defined(__cplusplus)
  #define _Restrict

 #else 
  #define _Restrict restrict
 #endif  

 #else  
 #define _Restrict
 #endif  

 #ifdef __cplusplus
_STD_BEGIN
typedef bool _Bool;
_STD_END
 #endif  

		 
 #define _CRTIMP
 #define _CDECL


 #ifdef __NO_LONG_LONG

 #else
        
  #define _LONGLONG	long long
  #define _ULONGLONG	unsigned long long
  #define _LLONG_MAX	0x7fffffffffffffffLL
  #define _ULLONG_MAX	0xffffffffffffffffULL
 #endif  

		

 #if defined(__MINGW32__)
  #define _WIN32_C_LIB	1
 #endif  


_C_STD_BEGIN
		 
#if (!defined(_32_BIT_DOUBLE))
#define _DBIAS	0x3fe	
#define _DOFF	4
#define _FBIAS	0x7e
#define _FOFF	7
#define _FRND	1
#endif  

	 
#define _BITS_BYTE	8
#define _C2		1	 
#define _MBMAX		8	 
#define _ILONG		1	 

 #if defined(__s390__) || defined(__CHAR_UNSIGNED__)  \
	|| defined(_CHAR_UNSIGNED) 
  #define _CSIGN	0	 
 #else  
  #define _CSIGN	1
 #endif  

#define _MAX_EXP_DIG	8	 
#define _MAX_INT_DIG	32
#define _MAX_SIG_DIG	36

 #if defined(_LONGLONG)
typedef _LONGLONG _Longlong;
typedef _ULONGLONG _ULonglong;

 #else  
     typedef long long _Longlong;
     typedef unsigned long long  _ULonglong;
     #define _LLONG_MAX  0x7fffffffffffffff
     #define _ULLONG_MAX 0xffffffffffffffff
 #endif 

		 
 #if defined(_WCHAR_T) || defined(_WCHAR_T_DEFINED) \
	|| defined (_MSL_WCHAR_T_TYPE)
  #define _WCHART
 #endif  

 #if defined(_WINT_T)
  #define _WINTT
 #endif 

 #ifdef __cplusplus
  #define _WCHART
typedef wchar_t _Wchart;
typedef wchar_t _Wintt;
 #endif 
 #if defined(_MSL_WCHAR_T_TYPE)
  #define _WCMIN	0
  #define _WCMAX	0xffff

  #ifndef __cplusplus
typedef wchar_t _Wchart;
typedef wint_t _Wintt;
  #endif  
  #define mbstate_t	_DNK_mbstate_t
  #define wctype_t	_DNK_wctype_t
  #define wint_t	_DNK_wint_t
  #define _MSC_VER	1

 #elif defined(__CYGWIN__)
  #define _WCMIN	(-_WCMAX - _C2)
  #define _WCMAX	0x7fff

  #ifndef __cplusplus
typedef short _Wchart;
typedef short _Wintt;
  #endif  

 #elif defined(__WCHAR_TYPE__)
  #define _WCMIN	(-_WCMAX - _C2)
  #define _WCMAX	0x7fffffff	 

  #ifndef __cplusplus
typedef __WCHAR_TYPE__ _Wchart;
typedef __WCHAR_TYPE__ _Wintt;
  #endif  
 #elif defined(__TI_COMPILER_VERSION__)
    #ifndef __cplusplus
       typedef __WCHAR_T_TYPE__ _Wchart;
       typedef __WCHAR_T_TYPE__ _Wintt;
    #endif  
    #define _WCMIN	0
    #define _WCMAX	0xffff
 #else  
  #define _WCMIN	(-_WCMAX - _C2)
  #define _WCMAX	0x7fffffff

  #ifndef __cplusplus
typedef long _Wchart;
typedef long _Wintt;
  #endif  

 #endif  

		 
#define _NULL		0	 

#define _SIGABRT	6
#define _SIGMAX		44

		 
typedef _CSTD va_list _Va_list;

 #if _HAS_C9X

 #if __EDG__
  #undef va_copy
 #endif  

 #ifndef va_copy
_EXTERN_C
void _Vacopy(va_list *, va_list);
_END_EXTERN_C
  #define va_copy(apd, aps)	_Vacopy(&(apd), aps)
 #endif  

 #endif  
#define _EXFAIL	1	 

_EXTERN_C
void _Atexit(void (*)(void));
_END_EXTERN_C

		 
#define _FNAMAX	256            
#define _FOPMAX	10      
#define _TNAMAX	16

 #define _FD_TYPE	signed char
  #define _FD_NO(str) ((str)->_Handle)
 #define _FD_VALID(fd)	(0 <= (fd))	 
 #define _FD_INVALID	(-1)
 #define _SYSCH(x)	x
typedef char _Sysch_t;

		 
#define _MEMBND	3U  
		 
  #define _CPS 200000000 
  #define _TBIAS	0
_C_STD_END
 
 #if _MULTI_THREAD
_EXTERN_C
void _Locksyslock(int);
void _Unlocksyslock(int);
_END_EXTERN_C

 #else  
   #if defined(__TI_COMPILER_VERSION__)
     #define _Locksyslock(x)   _lock()
     #define _Unlocksyslock(x) _unlock()
   #else 
     #define _Locksyslock(x)	(void)0
     #define _Unlocksyslock(x)	(void)0
   #endif  
 #endif  

		 
 #define _LOCK_LOCALE	0
 #define _LOCK_MALLOC	1
 #define _LOCK_STREAM	2
 #define _LOCK_DEBUG	3
 #define _MAX_LOCK		4	 

 #if _IOSTREAM_OP_LOCKS
  #define _MAYBE_LOCK

 #else  
  #define _MAYBE_LOCK	\
	if (_Locktype == _LOCK_MALLOC || _Locktype == _LOCK_DEBUG)
 #endif  
 #ifdef __cplusplus
_STD_BEGIN
extern "C++" {	 
class _Lockit
	{	 
public:

  #if !_MULTI_THREAD
   #define _LOCKIT(x)

	explicit _Lockit()
		{	 
		}

	explicit _Lockit(int)
		{	 
		}

	~_Lockit()
		{	 
		}

  #elif defined(_WIN32_WCE) || defined(_MSC_VER)
   #define _LOCKIT(x)	lockit x

	explicit _Lockit();		 
	explicit _Lockit(int);	 
	~_Lockit();	 

private:
	int _Locktype;

  #else  
   #define _LOCKIT(x)	lockit x

	explicit _Lockit()
		: _Locktype(_LOCK_MALLOC)
		{	 
		_MAYBE_LOCK
			_Locksyslock(_Locktype);
		}

	explicit _Lockit(int _Type)
		: _Locktype(_Type)
		{	 
		_MAYBE_LOCK
			_Locksyslock(_Locktype);
		}

	~_Lockit()
		{	 
		_MAYBE_LOCK
			_Unlocksyslock(_Locktype);
		}

private:
	int _Locktype;
  #endif  

private:
	_Lockit(const _Lockit&);			 
	_Lockit& operator=(const _Lockit&);	 
	};

class _Mutex
	{	 

  #if !_MULTI_THREAD || !_IOSTREAM_OP_LOCKS
    void _Lock()
		{	 
		}

	void _Unlock()
		{	 
	}

  #else  
	_Mutex();
	~_Mutex();
	void _Lock();
	void _Unlock();

private:
	_Mutex(const _Mutex&);				 
	_Mutex& operator=(const _Mutex&);	 
	void *_Mtx;
  #endif  

	};
}	 
_STD_END
 #endif  

		 
#define _ATEXIT_T	void

#define _MAX	max
#define _MIN	min

#define _TEMPLATE_STAT

  #define _NO_RETURN(fun)	void fun

 #if _HAS_NAMESPACE

 #ifdef __cplusplus
  #ifndef _STDARG
  #if defined(_STD_USING)
_STD_BEGIN
using _CSTD va_list;
_STD_END
  #endif  
  #endif  
 #endif 
 #endif 

#if defined(__TI_COMPILER_VERSION__)
#include "linkage.h"
#ifndef __LOCK_H
#include "_lock.h"
#endif 
#endif 

#endif 

/*
 * Copyright (c) 1992-2004 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:1476 */
