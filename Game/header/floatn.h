#ifndef _IN_UPCR_BITS_FLOATN_H
#define _IN_UPCR_BITS_FLOATN_H

@UPCR_INCLUDE_NEXT_BITS_FLOATN_H@

#ifndef _UPCR_BITS_FLOATN_H
#define _UPCR_BITS_FLOATN_H

#if __BERKELEY_UPC_FIRST_PREPROCESS__ && defined(__GLIBC__)
  #if __GLIBC_PREREQ(2,26)
    #undef __HAVE_FLOAT16
    #undef __HAVE_FLOAT32
    #undef __HAVE_FLOAT64
    #undef __HAVE_FLOAT128
    #undef __HAVE_FLOAT16X
    #undef __HAVE_FLOAT32X
    #undef __HAVE_FLOAT64X
    #undef __HAVE_FLOAT128X
  #endif
#endif

#endif

#undef _IN_UPCR_BITS_FLOATN_H
#elif !defined(_IN_UPCR_BITS_FLOATN_H_AGAIN)
 
  #define _IN_UPCR_BITS_FLOATN_H_AGAIN
@UPCR_INCLUDE_NEXT_BITS_FLOATN_H@
#endif
