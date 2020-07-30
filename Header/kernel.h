#ifndef KERNEL_H
#define KERNEL_H

#include "types.h"

#define NULL 0



extern byte get_input_keycodemath();
extern char get_char(byte c);
extern void clear_screen(uint8, uint8);
extern void print_new_line();
extern void print_char(char);
extern void print_string(char *);
extern void print_color_string(char *, uint8, uint8);
extern void print_int(int);
extern uint8 inb(uint16);
extern void outb(uint16, uint8);
extern byte get_input_keycode();
extern void sleep(uint32);
extern void gotoxy(uint16, uint16);

#endif
