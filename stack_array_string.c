#include <stdio.h>
#include <string.h>

#define column 100
#define row 40

typedef struct {
	char data[column][row];
	char top; // data[top][ ]
} Stack;

void push(Stack* stack, char* s) {
	if (stack->top == column - 1) {
		puts("stack is full");
		return;
	}
	stack->top++;
	strcpy_s(stack->data[stack->top], sizeof(stack->data[stack->top]), s);
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
		printf("%s\12", stack->data[stack->top]);
		stack->top--;
	}
}

void main(void) {

	Stack stack = { {0},-1 };

	push(&stack, "This is about the abstract concept.");
	push(&stack, "Additionally,");
	push(&stack, "a peek operation can");
	push(&stack, ", without modifying the stack,");
	push(&stack, "return the value ");
	push(&stack, "of the last element added.");
	push(&stack, " LIFO");
	pop(&stack);

	print_stack(&stack);
}
/* stack:
 * 
 * of the last element added.
 * return the value
 * , without modifying the stack,
 * a peek operation can
 * Additionally,
 * This is about the abstract concept.

*/