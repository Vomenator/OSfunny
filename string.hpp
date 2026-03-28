#include "kernelforward.hpp"
#include "screen.hpp"

#ifndef IO_HPP
#define IO_HPP
#include "io.hpp"
#endif

#define STRING_MAX 256

extern char buffer[STRING_MAX];
extern int bufftrack;



//forward declarations
void stringstore(const char input);
void bufferclear();
char* returnstringBuffer();
char* returnstringBuffer(int newtrack, char ascii);
void clearline();
int strcmp(const char* a, const char* b);
int strlen(const char* str);
char inttochar(int input);