#include <stdio.h>
#include <stdint.h>

#define CRC_POLY 0xEDB88320L
#define POLYNOMIAL 0x04C11DB7

uint32_t crc32(const unsigned char* data, uint32_t length);
unsigned int crc32_0x04C11DB7(const unsigned char* data, unsigned int length);

int main() {

    const unsigned char data[4] = { 0xA4, 0xA4, 0x00, 0x00 };
    long crc = crc32(data, strlen(data));
    printf("%s_CRC-32(0xEDB88320): 0x%X\12", data, crc);

    uint32_t result = crc32(data, strlen(data));
    printf("%s_CRC-32(0x04C11DB7): 0x%X\n", data, result);

    return 0;
}

uint32_t crc32(const unsigned char* data, uint32_t length) {
    uint32_t crc = 0xFFFFFFFFL;

    for (uint32_t i = 0; i < length; i++) {
        uint32_t j;
        uint8_t byte = data[i];
        for (j = 0; j < 8; j++) {
            if ((crc ^ byte) & 1) {
                crc = (crc >> 1) ^ CRC_POLY;
            }
            else {
                crc >>= 1;
            }
            byte >>= 1;
        }
    }
    return ~crc;
}

unsigned int crc32_0x04C11DB7(const unsigned char* data, unsigned int length) {
    unsigned int crc = 0xFFFFFFFF;

    for (unsigned int i = 0; i < length; i++) {
        crc ^= (data[i] << 24);
        for (int j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ POLYNOMIAL;
            }
            else {
                crc = crc << 1;
            }
        }
    }
    return crc ^ 0xFFFFFFFF;
}
/* ¤¤_CRC-32(0xEDB88320): 0x5A090CE3
 * ¤¤_CRC-32(0x04C11DB7): 0x5A090CE3

*/