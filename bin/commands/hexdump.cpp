#include "../types/string.hpp"
#include "../types/kerneltypes.hpp"
#include "../mem/memB.hpp"

char* inttohex(uint32_t value) {
    static char hexBuffer[3]; // 2 characters for hex + null terminator
    const char* hexDigits = "0123456789ABCDEF";
    for (int i = 1; i >= 0; --i) {
        hexBuffer[i] = hexDigits[value & 0xF];
        value >>= 4;
    }
    hexBuffer[2] = '\0';
    return hexBuffer;
}

char* inttohexAddr(uint32_t value, uint32_t startaddress) {
    value += startaddress;
    static char hexBuffer[9]; // 8 characters for hex + null terminator
    const char* hexDigits = "0123456789ABCDEF";
    for (int i = 7; i >= 0; --i) {
        hexBuffer[i] = hexDigits[value & 0xF];
        value >>= 4;
    }
    hexBuffer[8] = '\0';
    return hexBuffer;
}

void hexdump(const void* data, size_t size, int width = 2) {
    uint32_t startaddress = reinterpret_cast<uint32_t>(data);
    //uint16_t* ptr = static_cast<uint16_t*>(const_cast<void*>(data));
    const uint8_t* byteData = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; i += 16) {
        // Print the offset
        kernel::print(inttohexAddr(i, startaddress));
        kernel::print(": ");

        // Print the hex values
        for (size_t j = 0; j < 16*width && i + j < size; ++j) {
            char* out = inttohex(byteData[i + j]);
            //if (strcmp(out, "00") != 0) {
                kernel::print(out);
                kernel::print(" ");
           // }
        }
        kernel::print("\n");

        /*// Print the ASCII representation
        kernel::print(" ");
        for (size_t j = 0; j < 16 && i + j < size; ++j) {
            char c = byteData[i + j];
            kernel::print((c >= 32 && c <= 126) ? &c : ".");
        }
        kernel::print("\n");*/
    }
}