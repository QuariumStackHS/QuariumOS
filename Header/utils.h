#ifndef UTILS_H
#define UTILS_H

#include "types.h"
#include "utils-struct.h"

#define TRUE  1
#define FALSE 0

extern uint32 strlen(const char*);
extern uint32 digit_count(int);
extern void itoa(int, char *);
extern int exp(int, int);
extern float modulus(float, float);
extern void strcpystruct(char* structt, char* str);
extern int str2int(char* number);
extern void split(char*str,char sep,struct splitter splited);
#endif

