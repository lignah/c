#include <stdio.h>

int main() {
	// If you use brace initialization when declaring an array, the remaining elements are automatically initialized to 0.
	int aList[3][4] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	int i = -1;
	while (++i < 3) {
		aList[2][i] += aList[0][i] + aList[1][i];
		int j = -1;
		while (++j < 4 - 1) {
			aList[i][3] += aList[i][j];
		}
	}

	i = -1;
	while (++i < 3) {
		int j = -1;
		while (++j < 4) {
			printf("%d ", aList[i][j]);
		}
		puts("");
	}

	return 0;
}

/**
 * 1 2 3 6
 * 4 5 6 15
 * 5 7 9 21
 */