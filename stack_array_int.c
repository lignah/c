#include <stdio.h>

#define STACK_SIZE 5

typedef struct {
	int data[STACK_SIZE];
	ptrdiff_t top; // data[top]
} Stack;

void push(Stack* stack, int d) {
	if (stack->top == STACK_SIZE - 1) {
		puts("stack is full");
		return;
	}
	stack->top++;
	stack->data[stack->top] = d;
}

void pop(Stack* stack) {
	if (stack->top == -1) {
		printf("stack is empty\12");
		return;
	}
	stack->data[stack->top];
	stack->top--;
}

void print_stack(Stack* stack) {
	if (stack->top == -1) {
		printf("stack is empty\12");
		return;
	}
	printf("stack:\n\12");

	while (stack->top != -1) {
		printf("%d\12", stack->data[stack->top]);
		stack->top--;
	}
}

void main(void) {

	Stack stack = { {0},-1 };

	push(&stack, 1);
	pop(&stack);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	push(&stack, 6);
	push(&stack, 7);

	print_stack(&stack);
}
/* stack is full
 * stack:
 *
 * 6
 * 5
 * 4
 * 3
 * 2
 
*/