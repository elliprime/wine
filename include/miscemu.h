#ifndef __WINE_MISCEMU_H
#define __WINE_MISCEMU_H

extern int do_int10(struct sigcontext_struct *);
extern int do_int13(struct sigcontext_struct *);
extern int do_int15(struct sigcontext_struct *);
extern int do_int16(struct sigcontext_struct *);
extern int do_int1a(struct sigcontext_struct *);
extern int do_int21(struct sigcontext_struct *);
extern int do_int25(struct sigcontext_struct *);
extern int do_int26(struct sigcontext_struct *);
extern int do_int2a(struct sigcontext_struct *);
extern int do_int2f(struct sigcontext_struct *);
extern int do_int31(struct sigcontext_struct *);

extern void inportb(struct sigcontext_struct *context);
extern void inport(struct sigcontext_struct *context);
extern void outportb(struct sigcontext_struct *context);
extern void outport(struct sigcontext_struct *context);

extern void IntBarf(int i, struct sigcontext_struct *context);

extern void INT21_Init(void);

#endif /* __WINE_MISCEMU_H */
