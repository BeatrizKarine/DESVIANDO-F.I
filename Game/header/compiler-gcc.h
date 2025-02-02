#ifndef __LINUX_COMPILER_H
#error "Please don't include "compiler-gcc.h" directly, include "compiler.h" instead."
#endif

#define barrier() __asm__ __volatile__("": : :"memory")

#define RELOC_HIDE(ptr, off)					\
  ({ unsigned long __ptr;					\
    __asm__ ("" : "=r"(__ptr) : "0"(ptr));		\
    (typeof(ptr)) (__ptr + (off)); })

#define __must_be_array(a) \
  BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))


#if !defined(CONFIG_ARCH_SUPPORTS_OPTIMIZED_INLINING) || \
    !defined(CONFIG_OPTIMIZE_INLINING) || (__GNUC__ < 4)
# define inline		inline		__attribute__((always_inline))
# define __inline__	__inline__	__attribute__((always_inline))
# define __inline	__inline	__attribute__((always_inline))
#endif

#define __deprecated			__attribute__((deprecated))
#define __packed			__attribute__((packed))
#define __weak				__attribute__((weak))


#define __naked				__attribute__((naked)) notrace

#define __noreturn			__attribute__((noreturn))

#define __pure				__attribute__((pure))
#define __aligned(x)			__attribute__((aligned(x)))
#define __printf(a,b)			__attribute__((format(printf,a,b)))
#define  noinline			__attribute__((noinline))
#define __attribute_const__		__attribute__((__const__))
#define __maybe_unused			__attribute__((unused))

#define __gcc_header(x) #x
#define _gcc_header(x) __gcc_header(linux/compiler-gcc##x.h)
#define gcc_header(x) _gcc_header(x)
#include gcc_header(__GNUC__)
