#include <stdio.h>
#include <stdlib.h>

void binary_stupid(unsigned char num);
void binary_solution(unsigned char num);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <number>\12", argv[0]);
        return 1;
    }

    unsigned char a = (unsigned char)atoi(argv[1]);
    binary_stupid(a);
    binary_solution(a);

    return 0;
}

void binary_stupid(unsigned char num) {
    int zeroflag = 0;
    for (int i = 8; i > 0; i--) {
        int bit = (num >> i - 1) & 1;
        if (bit) {
            zeroflag = 1;
        }
        if (zeroflag) {
            printf("%d", bit);
        }
    }
    if (!zeroflag) {
        printf("0");
    }
    printf("\n");
}

void binary_solution(unsigned char num) {
    for (int i = 7; i >= 0; i--) 
        printf("%d", (num >> i) & 1);
    
    printf("\n");
}