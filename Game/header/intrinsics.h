/* This is specific fix for a problem with the windows SDK headers when */
/* using MSVC with an x86 compilation target. On x64 the SDK would enable */
/* MSVC's _InterlockedSomething compiler intrinsics and use #define to make */
/* sure those are used instead of InterlockedSomething library calls. On */
/* x32 it doesn't even though MSVC does support many of those intrinsics. */
/* Including this header fixes that. */

#ifndef _MSVC_INTRINSICS_H
#define _MSVC_INTRINSICS_H

#if defined(_MSC_VER) && defined(_M_IX86)

#ifdef __cplusplus
extern "C" {
#endif

/* Need windows.h for SHORT, LONG, LONG64 etc. */
#include "windows.h"


#ifndef InterlockedAnd8
  char _InterlockedOr8(char volatile *Destination, char Value);
# pragma intrinsic (_InterlockedOr8)
# define InterlockedAnd8 _InterlockedAnd8
#endif

#ifndef InterlockedOr8
  char _InterlockedAnd8(char volatile *Destination, char Value);
# pragma intrinsic (_InterlockedAnd8)
# define InterlockedOr8 _InterlockedOr8
#endif

#ifndef InterlockedXor8
  char _InterlockedXor8(char volatile *Destination, char Value);
# pragma intrinsic (_InterlockedXor8)
# define InterlockedXor8 _InterlockedXor8
#endif

#ifndef InterlockedAnd16
  SHORT _InterlockedAnd16(SHORT volatile *Destination, SHORT Value);
# pragma intrinsic (_InterlockedAnd16)
# define InterlockedAnd16 _InterlockedAnd16
#endif

#ifndef InterlockedOr16
  SHORT _InterlockedOr16(SHORT volatile *Destination, SHORT Value);
# pragma intrinsic (_InterlockedOr16)
# define InterlockedOr16 _InterlockedOr16
#endif

#ifndef InterlockedXor16
  SHORT _InterlockedXor16(SHORT volatile *Destination, SHORT Value);
# pragma intrinsic (_InterlockedXor16)
# define InterlockedXor16 _InterlockedXor16
#endif

#ifndef InterlockedIncrement16
  SHORT _InterlockedIncrement16(SHORT volatile * Addend);
# pragma intrinsic(_InterlockedIncrement16)
# define InterlockedIncrement16 _InterlockedIncrement16
#endif

#ifndef InterlockedDecrement16
  SHORT _InterlockedDecrement16(SHORT volatile *Addend);
# pragma intrinsic(_InterlockedDecrement16)
# define InterlockedDecrement16 _InterlockedDecrement16
#endif

#ifndef InterlockedCompareExchange16
  SHORT _InterlockedCompareExchange16(SHORT volatile *Destination,
      SHORT ExChange, SHORT Comperand);
# pragma intrinsic(_InterlockedCompareExchange16)
# define InterlockedCompareExchange16 _InterlockedCompareExchange16
#endif

#ifndef InterlockedAnd
  LONG _InterlockedAnd(LONG volatile *Destination, LONG Value);
# pragma intrinsic(_InterlockedAnd)
# define InterlockedAnd _InterlockedAnd
#endif

#ifndef InterlockedOr
  LONG _InterlockedOr(LONG volatile *Destination, LONG Value);
# pragma intrinsic(_InterlockedOr)
# define InterlockedOr _InterlockedOr
#endif

#ifndef InterlockedXor
  LONG _InterlockedXor(LONG volatile *Destination, LONG Value);
# pragma intrinsic(_InterlockedXor)
# define InterlockedXor _InterlockedXor
#endif

#ifndef InterlockedIncrement
  LONG _InterlockedIncrement(LONG volatile *Addend);
# pragma intrinsic(_InterlockedIncrement)
# define InterlockedIncrement _InterlockedIncrement
#endif

#ifndef InterlockedDecrement
  LONG _InterlockedDecrement(LONG volatile *Addend);
# pragma intrinsic(_InterlockedDecrement)
# define InterlockedDecrement _InterlockedDecrement
#endif

#ifndef InterlockedExchange
  LONG _InterlockedExchange(LONG volatile *Target, LONG Value);
# pragma intrinsic(_InterlockedExchange)
# define InterlockedExchange _InterlockedExchange
#endif

#ifndef InterlockedCompareExchange
  LONG _InterlockedCompareExchange(LONG volatile *Destination, LONG ExChange,
      LONG Comperand);
# pragma intrinsic(_InterlockedCompareExchange)
# define InterlockedCompareExchange _InterlockedCompareExchange
#endif

#ifndef InterlockedExchangeAdd
  LONG _InterlockedExchangeAdd(LONG volatile *Addend, LONG Value);
# pragma intrinsic(_InterlockedExchangeAdd)
# define InterlockedExchangeAdd _InterlockedExchangeAdd
#endif

#ifndef InterlockedAdd
  /* Polyfill for _InterlockedAdd */
  __forceinline LONG _InterlockedAdd(LONG volatile *Addend, LONG Value) {
    return _InterlockedExchangeAdd(Addend, Value) + Value;
  }
# define InterlockedAdd _InterlockedAdd
#endif

#ifndef InterlockedCompareExchange64
  LONG64 _InterlockedCompareExchange64(LONG64 volatile *Destination,
      LONG64 ExChange, LONG64 Comperand);
# pragma intrinsic(_InterlockedCompareExchange64)
# define InterlockedCompareExchange64 _InterlockedCompareExchange64
#endif

#ifndef InterlockedExchangePointer
  /* Polyfill for _InterlockedExchangePointer, assumes 32-bit architecture. */
  __forceinline PVOID _InterlockedExchangePointer(PVOID volatile *Target,
      PVOID Value) {
    return (PVOID) InterlockedExchange((LONG volatile) Target, (LONG) Value);
  }
# define InterlockedExchangePointer _InterlockedExchangePointer
#endif

#ifndef InterlockedCompareExchangePointer
  /* Polyfill for _InterlockedCompareExchangePointer, assumes 32-bit */
  /* architecture. */
  __forceinline PVOID _InterlockedCompareExchangePointer(
      PVOID volatile *Destination, PVOID Exchange, PVOID Comperand) {
    return (PVOID) InterlockedCompareExchange((LONG volatile*) Destination, (LONG) Exchange, (LONG) Comperand);
  }
# define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif

#endif // _MSVC_INTRINSICS_H
