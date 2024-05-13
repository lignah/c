/* compile, ISO/IEC 9899:2011 */
#include <stdio.h>

#define print(x) _Generic((x),			\
    int: printf("int: %d\n", (int)x),		\
    float: printf("float: %f\n", (float)x),	\
    double: printf("double: %lf\n", (double)x)) \

#define type_name(x) _Generic((x),		\
    int: "int",					\
    char: "char",				\
    float: "float",				\
    double: "double",				\
    unsigned long long: "unsigned long long",	\
    default: "unknown")				\

void main() {

	int a = 30;
	float b = 3.14159f;
	double c = 7.124189;

	print(a);
	print(b);
	print(c);

	printf("type name: %s\n", type_name(0x123ull));
	printf("type name: %s\n", type_name(3.4e+38f));
	printf("type name: %s\n", type_name(3.4e+38 ));
	return;
}

/* int: 30
 * float: 3.141590
 * double: 7.124189
 * type name: unsigned long long
 * type name: float
 * type name: double */
