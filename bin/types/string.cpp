#include "string.hpp"

char charstore[STRING_MAX];
char Tbuff[64];
int bufftrack = 0;
char* outputinttochar;

void stringstore(const char input) {
    if (input != 0x08) {
        charstore[bufftrack] = input;
        bufftrack++;
    }
    else {
        bufftrack--;
        charstore[bufftrack] = '\0';
    }
}

void stringstoreN(const char input) {
    charstore[bufftrack] = input;
    bufftrack--;
}

void bufferclear() {
    bufftrack = 0;
    int i = 0;

    while (i < 63) {
        Tbuff[i] = {'\0'};
        i++;
    }
}

char* returnstringBuffer() { 
    charstore[bufftrack] = '\0';
    return charstore;
}

char* returnDstringBuffer(int newtrack, char ascii) {
    int i = 0;
    int lopi = 1;
    for(; (charstore[newtrack] != ascii && charstore[newtrack] != '\0' && charstore[newtrack] != '\n') && i < 64; newtrack++) {            //charstore[newtrack] != ascii
        //print("_");
        Tbuff[i] = charstore[newtrack];
        i++;
        lopi++;
    }
    Tbuff[newtrack] = '\0';
    //if (lopi == 1) {
    //    Tbuff[0] = 'f';
    //    Tbuff[1] = '\0';
    //}
    //print(returnstringBuffer());
    //kernel::print(Tbuff);
    return Tbuff;
}

char* returnstringBuffer(int newtrack, char ascii) {
    bufferclear();
    char* output = returnDstringBuffer(newtrack, ascii);
    return output;
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
    //int i = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    if (lena == lenb) {
        for (int i = 0;i < lena; i++){
            //if (a[i] != b[i]) return 10;
            if (*a != *b) return 1;
            a++;
            b++; 
        }
        return 0;
    }
    //kernel::print(inttochar(lena));
    //kernel::print("\n");
    //kernel::print(inttochar(lenb));
    //kernel_panic(0);
    return 1;
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
        output;
    }
    return output;
}


char* inttochar(int input) {
    int len = numlen(input);
    int i = 0;
    int p10 = 1;
    uint8_t result = {};
    while (i < len) {
        result = (input/p10) %10;
        p10 *= 10;
        outputinttochar[(len - 1) - i] = sinttochar(result);
        i++;
    }
    outputinttochar[i] = '\0';
    return outputinttochar;
}