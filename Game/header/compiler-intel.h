#ifndef __LINUX_COMPILER_H
#error "Please don't include "compiler-intel.h" directly, include "compiler.h" instead."
#endif

#ifdef __ECC

#include "intrinsics.h"

#undef barrier
#undef RELOC_HIDE

#define barrier() __memory_barrier()

#define RELOC_HIDE(ptr, off)					
  ({ unsigned long __ptr;					
     __ptr = (unsigned long) (ptr);				
    (typeof(ptr)) (__ptr + (off)); })

#define __must_be_array(a) 0

#endif

#define uninitialized_var(x) x
