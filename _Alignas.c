/* msvc */
#include <stdio.h>

void main(void) {

	int e = 7;
	int a = 3;

	// std:c11 _Alignas(16)
	__declspec(align(16)) int b = 4;

	int c = 5;
	int d = 6;

	printf("address of 'a': 0x%p\n", (void*)&a);
	printf("address of 'b': 0x%p\n", (void*)&b);
	printf("address of 'c': 0x%p\n", (void*)&c);
	printf("address of 'd': 0x%p\n", (void*)&d);
	printf("address of 'e': 0x%p\n", (void*)&e);

	return;
}

/* memory_dump
 * 
 * address of 'a': 0x00AFF6F8
 * address of 'b': 0x00AFF6E0
 * address of 'c': 0x00AFF6D4
 * address of 'd': 0x00AFF6C8
 * address of 'e': 0x00AFF704
 *
 * 0x00AFF6C8  06 00 00 00 cc cc cc cc cc cc cc cc 05 00 00 00  ....????????....
 * 0x00AFF6D8  cc cc cc cc cc cc cc cc 04 00 00 00 cc cc cc cc  ????????....????
 * 0x00AFF6E8  cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc  ????????????????
 * 0x00AFF6F8  03 00 00 00 cc cc cc cc cc cc cc cc 07 00 00 00  ....????????....

*/
