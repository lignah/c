#include <stdio.h>

int main(void) {
	int list[] = { 2,5,1,4,3 };
	int __list_size = sizeof(list) / sizeof(list[0]) - 1;

	int j = -1;
	while (++j < __list_size) {
		int i = j;

		while (++i < __crt_countof(list)) {
			if (list[j] > list[i]) {
				int tmp = list[j];
				list[j] = list[i];
				list[i] = tmp;
			}
		}
	}

	return 0;
}