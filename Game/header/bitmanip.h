/*  bitmanip.h

		Definitions for bit manipulations.

		Copyright (c) 2009 by Jose F. D'Silva
		All Rights Reserved.
*/
#ifndef BITMANIP_H
#define BITMANIP_H

#define MAKEWORD(lb, hb)      ((WORD)(((BYTE)(lb)) | (((WORD)((BYTE)(hb))) << 8)))
#define MAKELONG(lw, hw)      ((long)(((WORD)(lw)) | (((DWORD)((WORD)(hw))) << 16)))
#define LOWORD(dw)            ((WORD)(dw))
#define HIWORD(dw)            ((WORD)(((DWORD)(dw) >> 16) & 0xFFFF))
#define LOBYTE(w)             ((BYTE)(w))
#define HIBYTE(w)             ((BYTE)(((WORD)(w) >> 8) & 0xFF))

#endif //BITMANIP_H
