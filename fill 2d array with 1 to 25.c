#include <stdio.h>

int main() {
	int cList[5][5] = { 0 };
	int sum = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cList[i][j] = sum++;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%-2d ", cList[i][j]);
		}
		puts("");
	}

	return 0;
}

/**
 * 1  2  3  4  5
 * 6  7  8  9  10
 * 11 12 13 14 15
 * 16 17 18 19 20
 * 21 22 23 24 25
 */