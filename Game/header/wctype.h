/**
 * @file wctype.h
 * @copy 2012 MinGW.org project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef _WCTYPE_H
#define _WCTYPE_H
#pragma GCC system_header
#include "_mingw.h"

#define	__need_wchar_t
#define	__need_wint_t

#ifndef RC_INVOKED
#include "stddef.h"
#endif	

#define	_UPPER		0x0001
#define	_LOWER		0x0002
#define	_DIGIT		0x0004
#define	_SPACE		0x0008
#define	_PUNCT		0x0010
#define	_CONTROL	0x0020
#define	_BLANK		0x0040
#define	_HEX		0x0080
#define	_LEADBYTE	0x8000

#define	_ALPHA		0x0103

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WEOF
#define	WEOF	(wchar_t)(0xFFFF)
#endif

#ifndef _WCTYPE_T_DEFINED
typedef wchar_t wctype_t;
#define _WCTYPE_T_DEFINED
#endif


_CRTIMP int __cdecl __MINGW_NOTHROW	iswalnum(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswalpha(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswascii(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswcntrl(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswctype(wint_t, wctype_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	is_wctype(wint_t, wctype_t);	
_CRTIMP int __cdecl __MINGW_NOTHROW	iswdigit(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswgraph(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswlower(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswprint(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswpunct(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswspace(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswupper(wint_t);
_CRTIMP int __cdecl __MINGW_NOTHROW	iswxdigit(wint_t);

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
     || !defined __STRICT_ANSI__ || defined __cplusplus
int __cdecl __MINGW_NOTHROW iswblank (wint_t);
#endif


_CRTIMP wint_t __cdecl __MINGW_NOTHROW	towlower (wint_t);
_CRTIMP wint_t __cdecl __MINGW_NOTHROW	towupper (wint_t);

_CRTIMP int __cdecl __MINGW_NOTHROW	isleadbyte (int);



  __MINGW_IMPORT unsigned short _ctype[];
__MINGW_IMPORT unsigned short* _pctype;


#if !(defined (__NO_INLINE__) || defined(__NO_CTYPE_INLINES) \
      || defined(__WCTYPE_INLINES_DEFINED))
#define __WCTYPE_INLINES_DEFINED
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswalnum(wint_t wc) {return (iswctype(wc,_ALPHA|_DIGIT));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswalpha(wint_t wc) {return (iswctype(wc,_ALPHA));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswascii(wint_t wc) {return ((wc & ~0x7F) ==0);}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswcntrl(wint_t wc) {return (iswctype(wc,_CONTROL));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswdigit(wint_t wc) {return (iswctype(wc,_DIGIT));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswgraph(wint_t wc) {return (iswctype(wc,_PUNCT|_ALPHA|_DIGIT));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswlower(wint_t wc) {return (iswctype(wc,_LOWER));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswprint(wint_t wc) {return (iswctype(wc,_BLANK|_PUNCT|_ALPHA|_DIGIT));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswpunct(wint_t wc) {return (iswctype(wc,_PUNCT));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswspace(wint_t wc) {return (iswctype(wc,_SPACE));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswupper(wint_t wc) {return (iswctype(wc,_UPPER));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswxdigit(wint_t wc) {return (iswctype(wc,_HEX));}
__CRT_INLINE int __cdecl __MINGW_NOTHROW isleadbyte(int c) {return (_pctype[(unsigned char)(c)] & _LEADBYTE);}

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
     || !defined __STRICT_ANSI__ || defined __cplusplus
__CRT_INLINE int __cdecl __MINGW_NOTHROW iswblank (wint_t wc)
  {return (iswctype(wc, _BLANK) || wc == L'\t');}
#endif

#endif 

typedef wchar_t wctrans_t;



wint_t __cdecl __MINGW_NOTHROW		towctrans(wint_t, wctrans_t);
wctrans_t __cdecl __MINGW_NOTHROW	wctrans(const char*);
wctype_t __cdecl __MINGW_NOTHROW	wctype(const char*);

#ifdef __cplusplus
}
#endif

#endif	

#endif	
