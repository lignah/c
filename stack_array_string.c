#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define column 20	// count of element
#define row 10		// strlen(data)

typedef struct {
	char data[column][row];
	//char* data[column]; //array of pointers
	char top;
} Stack;

Stack* stack;

void push(char* s) {
	if (stack->top == column - 1) {
		puts("stack is full");
		return;
	}
	stack->top++;
	strcpy_s(stack->data[stack->top], sizeof(stack->data[stack->top]), s);
	//stack->data[stack->top] = s; //array of pointers
}

void pop() {
	if (stack->top == -1) {
		printf("stack is empty\12");
		return;
	}
	stack->top--;
}

void print_stack() {
	if (stack->top == -1) {
		printf("stack is empty\12");
		return;
	}
	printf("stack:\12\12");
	
	char top = stack->top;
	while (top != -1) {
		printf("%s\12", stack->data[top]);
		top--;
	}
}

void main() {

	stack = malloc(sizeof(Stack));
	if(!stack) return;
	stack->top = -1;

	push("stack, 1");
	push("stack, 2");
	push("stack, 3");
	push("stack, 4");
	push("stack, 5");
	push("stack, 6");
	push("stack, 7");
	push("LIFO   *");
	pop();
	++stack->top;

	print_stack();

	free(stack);
}
/* stack:
 * 
 * LIFO   *
 * stack, 7
 * stack, 6
 * stack, 5
 * stack, 4
 * stack, 3
 * stack, 2
 * stack, 1 */
