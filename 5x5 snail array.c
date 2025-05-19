#include <stdio.h>

int main() {

	int array[5][5] = { 0 };
	int row[] = { 0, 1, 0, -1 };	// direction of movement (y-axis)
	int col[] = { 1, 0, -1, 0 };	//			``			 (x-axis)

	int x = 0, y = 0, dir = 0;		// current facing direction

	int i = 0;
	while (++i <= 25) {
		array[y][x] = i;

		int ny = y + row[dir];		// next coordinate(y)
		int nx = x + col[dir];		//		``		  (x)

		// if: determining the next coordinate <scopes, overwriting>
		if (0 <= ny && ny < 5 && 0 <= nx && nx < 5 && array[ny][nx] == 0) {
			y = ny;
			x = nx;
		}
		else {
			dir = (dir + 1) % 4;
			y += row[dir];
			x += col[dir];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%-2d ", array[i][j]);
		}
		puts("");
	}

	return 0;
}
/**
 * 1  2  3  4  5
 * 16 17 18 19 6
 * 15 24 25 20 7
 * 14 23 22 21 8
 * 13 12 11 10 9
 */