#include <stdio.h>

typedef struct {
    unsigned char enabled  : 1;  // 0=off, 1=on
    unsigned char dir      : 2;  // 0=Left, 1=Right, 2=Up, 3=Down
    unsigned char level    : 3;  // 0~7
    unsigned char category : 2;  // 0~3 (values above 3 are truncated to 2 bits)
} DataFlags;

int main(void) {
    // category given as 6 -> stored as (6 & 0x3) = 2 because only 2 bits
    DataFlags bitField = { 0, 3, 7, 6 };

    // Read the struct's first storage unit as an unsigned char
    // Per C standard, any object can be accessed byte-wise via unsigned char
    unsigned char raw = 0;

    // &: address of struct
    // (unsigned char*): reinterpret pointer as byte pointer
    // *: read the first byte (implementation-defined bitfield layout)
    raw = *(unsigned char*)&bitField;      // Example packed bits (e.g. 10111110₂ on typical little-endian + GCC/Clang)

    // Shift amount aligns the target field to LSB, then mask
    // dir is 2 bits wide: value 3 => 0b11 => 0x3
    unsigned char Down = (raw >> 1) & 0x03;  // Extract 2 bits for dir
    printf("Extract dir bits (3: Down): %u\n", Down);

    printf("bitField = 0x%02X 0b", raw);
    for (int i = 7; i >= 0; --i)
        putchar((raw >> i) & 1 ? '1' : '0');
    putchar('\n');

    printf("enabled : %u\n", bitField.enabled);
    printf("dir     : %u\n", bitField.dir);
    printf("level   : %u\n", bitField.level);
    printf("category: %u\n", bitField.category);
    printf("sizeof bitField: %zu byte\n", sizeof bitField);

    return 0;
}