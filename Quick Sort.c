#include <stdio.h>

void quicksort(int list[], int left, int right) {
	if (left >= right)
		return;

	int pivot = list[right];
	int i = left;
	int j = right - 1;
	while (i <= j) {
		while (list[i] < pivot) i++;
		while (list[j] > pivot) j--;
		if (i <= j) {
			int tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			i++;
			j--;
		}
	}

	list[right] = list[i];
	list[i] = pivot;

	quicksort(list, left, i - 1);
	quicksort(list, i + 1, right);
}

int main(void) {
	int list[] = { 5, 3, 7, 6, 2, 1, 4 };
	int size = sizeof(list)/sizeof(list[1]);

	quicksort(list, 0, size - 1);

	int i = -1;
	while (++i < size) {
		printf("%d ", list[i]);
	}

	return 0;
}