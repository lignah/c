#include <stdio.h>
#include <stdint.h>

unsigned crc32(unsigned char data) {
    unsigned crc = 0xFFFFFFFF;
    crc ^= data;
    for (char i = 0; i < 8; i++) {
        if (crc & 1)
            crc = (crc >> 1) ^ 0xEDB88320;
        else
            crc >>= 1;
    }
    return ~crc;    //crc ^ 0xFFFFFFFF
}

int main() {

    unsigned target_crc = 0x82079eb1;
    unsigned char data = _IOFBF;

    while (EOF*-1) {
        if (crc32(data) == target_crc) {
            printf("data: %c", data);
            break;
        }
        data++;
    }

    return 0;
}
/* data: p

*/