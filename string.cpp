#include "string.hpp"

char charstore[STRING_MAX];
char Tbuff[64];
int bufftrack = 0;

void stringstore(const char input) {
    charstore[bufftrack] = input;
    bufftrack++;
}

void stringstoreN(const char input) {
    charstore[bufftrack] = input;
    bufftrack--;
}

void bufferclear() {
    bufftrack = 0;
}

char* returnstringBuffer() { 
    charstore[bufftrack] = '\0';
    return charstore;
}

char* returnstringBuffer(int newtrack, char ascii) {
    //printdebug(charstore[newtrack]);
    int i = 0;
    for(; charstore[newtrack] != ascii; newtrack++) {            //charstore[newtrack] != ascii
        Tbuff[i] = charstore[newtrack];
        i++;
    }
    //Tbuff[i] = '\0';
    return Tbuff;
}

// not in use
void clearline() {
    //char input[2] = {(static_cast<char>(sizeof(*str)), '\0')};                // to be diddled later, when print character issue is resolved
    //print(input);
    for (int i; i <= bufftrack; i++) {
    charstore[i] = {};
    }
}

int strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int numlen(int input) {
    int i = 0;
    while (input > 0) {
        input /=10;
        i++;
    }
    return i;
}

int strcmp(const char* a, const char* b) {
    int i = 0;
    int lena = (strlen(a)-1);
    int lenb = strlen(b);
    
    for (int i = 0; i < lena; i++){
        //if (a[i] != b[i]) return 10;
        if (*a != *b) return 1;
        //print("passed");
        a++;
        b++;
    }
    return 0;
}

char sinttochar(int input) {
    char output = {};
    switch (input)
    {
    case 1:
        output = scancode_to_ascii(0x02);
        break;
    case 2:
        output = scancode_to_ascii(0x03);
        break;
    case 3:
        output = scancode_to_ascii(0x04);
        break;
    case 4:
        output = scancode_to_ascii(0x05);
        break;
    case 5:
        output = scancode_to_ascii(0x06);
        break;
    case 6:
        output = scancode_to_ascii(0x07);
        break;
    case 7:
        output = scancode_to_ascii(0x08);
        break;
    case 8:
        output = scancode_to_ascii(0x09);
        break;
    case 9:
        output = scancode_to_ascii(0x0A);
        break;
    case 0:
        output = scancode_to_ascii(0x0B);
        break;
    default:
        output = '\0';
    }
    return output;
}

char inttochar(int input) {
    int len = numlen(input);
    int i = 0;
    int p10 = 1;
    uint8_t output = {};
    while (len > i) {
        output = (input/p10) %10;
        bufftrack = (len - 1) - i;
        p10 *= 10;
        stringstoreN(sinttochar(output));
        //print("\n");
        //printdebug(sinttochar(output));
        //print("\n");
        //printdebug(sinttochar(bufftrack));
        i++;
    }
    bufftrack = len;
    //printdebug(sinttochar(bufftrack));
    //printdebug(charstore[]);
    return '\0';
}