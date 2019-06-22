/*  

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

typedef UCHAR BYTE;
typedef USHORT WORD;
typedef ULONG DWORD;
typedef UCHAR bool_t, BOOL;
typedef UCHAR ASCH;

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

#endif 
