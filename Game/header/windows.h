/* 
		Definitions for AWTK window types, variables and routines.

		Copyright (c) 2009 by Jose F. D'Silva
		All Rights Reserved.
*/
#ifndef AWTK_WINDOWS_H
#define AWTK_WINDOWS_H
#include "conio.h"
#include "mem.h"
#include "awtk.h"

#define WND_DEFLAYERPATTERN                      (219)
#define GET_WND_FG(attribute)                    GET_ATTRIBUTE_FG(attribute)
#define GET_WND_BG(attribute)                    GET_ATTRIBUTE_BG(attribute)
#define ATTRIBUTE_SHADOW											   MK_ATTRIBUTE(LIGHTGRAY, BLACK)
#define CLRWND(pr, attribute)                    window_clear((pr), (attribute), WND_DEFLAYERPATTERN)
#define CLRSCRP(attribute, pattern)              {                                                                  \
																									 RECT r = GET_ACTIVECONTEXT()->viewport;                              \
																									 r.x = r.y = 0;                                                      \
																									 window_clear(&r, (attribute), (pattern));                            \
																								 }
#define CLRSCR(attribute)                        CLRSCRP(attribute, WND_DEFLAYERPATTERN)
#define GET_WND_BUFFERSIZE(w, h)                 ((((w)*(h)) << 1) * sizeof(BYTE))
#define GET_WNDTXT_BUFFERSIZE(w, h)              (GET_WND_BUFFERSIZE(w, h) >> 1)

#define SET_GRID_DIMENSIONS(rows, columns)       MAKELONG(rows, columns)
#define GET_GRID_ROWS(dw)                        LOWORD(dw)
#define GET_GRID_COLUMNS(dw)                     HIWORD(dw)
#define GET_GRID_WIDTH(cw, c)                    ((cw)*(c)+1)
#define GET_GRID_HEIGHT(ch, r)                   ((ch)*(r)+1)

 
#define WND_SHSV                    WND_SVSH
#define WND_DHDV                    WND_DVDH
#define WND_DHSV                    WND_SVDH
#define WND_SHDV                    WND_DVSH
 
#define GRD_SHSVSC                  GRD_SVSHSC
#define GRD_SHSVDC                  GRD_SVSHDC
#define GRD_DHDVSC                  GRD_DVDHSC
#define GRD_DHDVDC                  GRD_DVDHDC

 
typedef enum {
	WND_LAYER=0,   
	WND_CELL,       
	WND_SVSH,      
	WND_DVDH,      
	WND_SVDH,       
	WND_DVSH,       
	WND_CUST,       

	WND_NTYPES     
} WNDTYPE;

 
typedef enum {
	GRD_SVSHSC=0,   
	GRD_SVSHDC,    
	GRD_DVDHSC,    
	GRD_DVDHDC,    
	GRD_CUST,      

	GRD_NTYPES      
} GRDTYPE;

 
typedef struct {
	ASCH hb;     
	ASCH vb;      
	ASCH lt;    
	ASCH rt;    
	ASCH lb;      
	ASCH rb;      
} WNDBORDERSTYLE;

 
typedef struct {
	ASCH chb;     
	ASCH cvb;    
	ASCH cl;      
	ASCH cr;     
	ASCH ct;      
	ASCH cb;     
	ASCH cm;     
} CELLBORDERSTYLE;

 
typedef struct {
	ASCH            layer_pattern;      
	ATTRIBUTE       layer_attribute;     
	bool_t          islayertransparent;   
	ATTRIBUTE       border_attribute;     
	WNDBORDERSTYLE  cbs;                 
	CELLBORDERSTYLE ccs;                 
	int             type;                
} WNDSTYLE;

 
typedef struct{
	RECT      r;           
	WNDSTYLE  style;       
	DWORD     reserved;   
} window_t,
	grid_t;

typedef struct {
	POINT xy;
	int cols;
	int rows;
	int *colw;  
	int *rowh;  
	WNDSTYLE style;
	DWORD reserved;  
} gridex_t;

typedef window_t  *HWND;
typedef grid_t    *HGRD;
typedef gridex_t  *HGRDEX;

 
WNDBORDERSTYLE*   window_get_systemborderstyle(void);
CELLBORDERSTYLE*  grid_get_systemcellstyle(void);
int               window_draw(const window_t *pwnd);
void              window_clear(const RECT *pr, ATTRIBUTE attribute, ASCH layer_pattern);
void              window_grab(const RECT *pr, BYTE far *buffer);
void              window_put(const RECT *pr, const BYTE far *buffer);
void              window_grab_text(const RECT *pr, BYTE far *buffer);
void              window_put_text(const RECT *pr, const BYTE far *buffer);
void              grid_draw(const grid_t *pwnd);
void              gridex_draw(const gridex_t *pgrdex);

#endif  
