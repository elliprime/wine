/*
 * structure definitions for CURSOR
 *
 * Copyright  Martin Ayotte, 1993
 *
 */
#ifndef __WINE_CURSOR_H
#define __WINE_CURSOR_H

typedef struct {
	BYTE	Width;
	BYTE	Reserved1;
	BYTE	Height;
	BYTE	Reserved2;
	WORD	curXHotspot;
	WORD	curYHotspot;
	DWORD	curDIBSize;
	DWORD	curDIBOffset;
	} CURSORDESCRIP;

typedef struct {
	CURSORDESCRIP	descriptor;
	HBITMAP		hBitmap;
	Display		*display;
	Pixmap		pixshape;
	Pixmap		pixmask;
	Cursor		xcursor;
	} CURSORALLOC;

extern void CURSOR_SetWinCursor( HWND hwnd, HCURSOR hcursor );   /* cursor.c */

#endif /* __WINE_CURSOR_H */
