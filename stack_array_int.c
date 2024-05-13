#include <stdio.h>
#include <stdlib.h>

#define data_max 4

typedef struct {
	int data[data_max];
	char top;
} stack;

stack* s;

void init() {
	s = malloc(sizeof(stack));
	if (!s) {
		puts("malloc failed");
		return ;
	}
	s->top = -1;
}

void push(int data) {
	if (s->top == data_max - 1) {
		puts("\12\t\tbuffer overflow");
		return ;
	}
	s->data[++s->top] = data;
}

void pop() {
	if (s->top == -1) {
		puts("\12\t\tbuffer underflow");
		return ;
	}
	(s->top)--;
}

void printing() {
	char top = s->top;
	puts("");
	while (top != -1) {
		printf("\t\tstack: %d\12", s->data[top]);
		(top)--;
	}
}

void main() {

	int select, value;
	init();
	while (1) {
		system("cls");
		printf("\12\12\t\t*** stack with array ***\12\12");
		printf("\t\t1.push    2.pop    3.print    4.clear    5.exit");
		printf("\12\t\tselect : [ ]\b\b");
		scanf_s("%d", &select);

		while (getchar() != '\n');

		switch (select) {
			case 1:
				printf("\12\12\t\tpush : ");
				scanf_s("%d", &value);
				push(value);
				break;

			case 2:
				pop();
				break;

			case 3:
				printing();
				break;

			case 4:
				init();
				break;

			case 5:
				exit(0);
		}
		printf("\12\12\t\t");
		system("pause");
	}
	free(s);
}