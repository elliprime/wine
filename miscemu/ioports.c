#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "registers.h"
#include "wine.h"
#include "stddebug.h"
/* #define DEBUG_INT */
#include "debug.h"

static BYTE cmosaddress;

static BYTE cmosimage[64] = {
	0x27, 0x34, 0x31, 0x47, 0x16, 0x15, 0x00, 0x01,
	0x04, 0x94, 0x26, 0x02, 0x50, 0x80, 0x00, 0x00,
	0x40, 0xb1, 0x00, 0x9c, 0x01, 0x80, 0x02, 0x00,
	0x1c, 0x00, 0x00, 0xad, 0x02, 0x10, 0x00, 0x00,
	0x08, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x03, 0x58,
	0x00, 0x1c, 0x19, 0x81, 0x00, 0x0e, 0x00, 0x80,
	0x1b, 0x7b, 0x21, 0x00, 0x00, 0x00, 0x05, 0x5f };

void inportb(struct sigcontext_struct *context)
{
	dprintf_int(stddeb, "IO: inb (%x)\n", DX);

	switch(DX) {
		case 0x70:
			AL = cmosaddress;
			break;
		case 0x71:
			AL = cmosimage[cmosaddress & 0x3f];
			break;
		default:
	}
}

void inport(struct sigcontext_struct *context)
{
	dprintf_int(stdnimp, "IO: in (%x)\n", DX);

	AX = 0xffff;
}

void inportb_abs(struct sigcontext_struct *context)
{
	dprintf_int(stdnimp, "IO: in (%x)\n", *(BYTE *)(EIP+1));
	AL = 0xff;
}

void inport_abs(struct sigcontext_struct *context)
{
	dprintf_int(stdnimp, "IO: in (%x)\n", *(BYTE *)(EIP+1));
	AX = 0xffff;
}

void outportb(struct sigcontext_struct *context)
{
	dprintf_int(stdnimp, "IO: outb (%x), %x\n", DX, AX);

	switch (EDX & 0xffff)
	{
		case 0x70:
			cmosaddress = AL & 0x7f;
			break;
		case 0x71:
			cmosimage[cmosaddress & 0x3f] = AL;
			break;
		default:
	}
}

void outport(struct sigcontext_struct *context)
{
	dprintf_int(stdnimp, "IO: out (%x), %x\n", DX, AX);
}

void outportb_abs(struct sigcontext_struct *context)
{
    dprintf_int(stdnimp, "IO: out (%x), %x\n", *(BYTE *)(EIP+1), AL);
}

void outport_abs(struct sigcontext_struct *context)
{
    dprintf_int(stdnimp, "IO: out (%x), %x\n", *(BYTE *)(EIP+1), AX);
}
