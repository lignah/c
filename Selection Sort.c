#include <stdio.h>
#define __list_size(x) __crt_countof(x)

int main(void) {
	int list[] = { 3, 2, 5, 1, 2, 4 };
	int list_size = sizeof(list) / sizeof(list[0]);
	int j = -1;

	while (++j < __list_size(list) - 1) {
		int i = j;
		int index = j;

		while (++i < list_size) {
			if (list[index] > list[i]) {
				index = i;
			}
		}
		if (index != j) {
			int tmp = list[j];
			list[j] = list[index];
			list[index] = tmp;
		}
	}

	int i = -1;
	while (++i < 6) {
		printf("%d ", list[i]);
	}

	puts("");

	return 0;
}