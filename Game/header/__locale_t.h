/* Definition of struct __locale_struct and __locale_t.
   Copyright (C) 1997-2019 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
#ifndef _BITS_TYPES___LOCALE_T_H
#define _BITS_TYPES___LOCALE_T_H 1

struct __locale_struct
{
 
  struct __locale_data *__locales[13]; 
 
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
 
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
#endif 
