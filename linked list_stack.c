#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
	char data[10];
	struct NODE* next;
} node;

node* stack;

void node_print(void) {

	node* head = stack;
	while (head != NULL) {
		printf("[%p] : %s, next:[%p]\12", head, head->data, head->next);
		head = head->next;
	}
	puts("\12");
}

void node_push(char* p_data) {

	node* new_node = malloc(sizeof(node));
	if (new_node == NULL) return;
	memset(new_node, 0, sizeof(node));
	strcpy_s(new_node->data, sizeof(new_node->data), p_data);

	if (stack == NULL)
		stack = new_node;
	else {
		new_node->next = stack;
		stack = new_node;
	}
}

void node_pop() {
	
	node* del_node = stack;
	if (stack == NULL) {
		printf("stack is empty.\n");
		return;
	}
	stack = stack->next;
	
	printf("popped data: %s\n", del_node->data);
	free(del_node);
}

void main() {

	node_push("node[0]");
	node_print();
	node_push("node[1]");
	node_print();
	node_push("node[2]");
	node_print();
	node_push("node[3]");
	node_print();
	node_push("node[4]");
	node_print();

	node_pop();
	node_pop();
	node_pop();
	node_pop();
	node_pop();
	node_pop();
	node_print();
}
/* [000001E28ADDBE80] : node[0], next:[0000000000000000]
 * 
 *
 * [000001E28ADDC000] : node[1], next:[000001E28ADDBE80]
 * [000001E28ADDBE80] : node[0], next:[0000000000000000]
 *
 *
 * [000001E28ADE1800] : node[2], next:[000001E28ADDC000]
 * [000001E28ADDC000] : node[1], next:[000001E28ADDBE80]
 * [000001E28ADDBE80] : node[0], next:[0000000000000000]
 *
 *
 * [000001E28ADE1920] : node[3], next:[000001E28ADE1800]
 * [000001E28ADE1800] : node[2], next:[000001E28ADDC000]
 * [000001E28ADDC000] : node[1], next:[000001E28ADDBE80]
 * [000001E28ADDBE80] : node[0], next:[0000000000000000]
 *
 *
 * [000001E28ADE0AE0] : node[4], next:[000001E28ADE1920]
 * [000001E28ADE1920] : node[3], next:[000001E28ADE1800]
 * [000001E28ADE1800] : node[2], next:[000001E28ADDC000]
 * [000001E28ADDC000] : node[1], next:[000001E28ADDBE80]
 * [000001E28ADDBE80] : node[0], next:[0000000000000000]
 *
 *
 * popped data: node[4]
 * popped data: node[3]
 * popped data: node[2]
 * popped data: node[1]
 * popped data: node[0]
 * stack is empty.
 
*/