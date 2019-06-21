/*  awtypes.h

		Definitions for general AWTK data types.
		NOTE: More specific types are defined in respective AWTK modules.

		Copyright (c) 2009 by Jose F. D'Silva
		All Rights Reserved.
*/
#ifndef AWTK_TYPES_H
#define AWTK_TYPES_H

#define FALSE    (0)
#define TRUE     (1)
#define false  FALSE
#define true    TRUE

typedef unsigned __U;
typedef unsigned char UCHAR;
typedef unsigned int UINT;
typedef unsigned short USHORT;
typedef unsigned long ULONG;
// 1 BYTE = 8 bits
typedef UCHAR BYTE;
// 1 WORD = 16 bits = 2 BYTE
typedef USHORT WORD;
// 1 DWORD = 32 bits = 4 BYTE = 2 WORD
typedef ULONG DWORD;
typedef UCHAR bool_t, BOOL;
// ASCII character
typedef UCHAR ASCH;
// Flags (2 bytes == 16 flags)
typedef WORD FLAGS;

typedef struct {
	int x;
	int y;
} POINT;

typedef struct {
	int x;
	int y;
	int w;
	int h;
} RECT;

#endif //AWTK_TYPES_H
