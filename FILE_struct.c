#include <stdio.h>

typedef struct IOBUF {
	char* base_offset;
	char* current_offset;
	int pageSize;
} IOBUF;

void print_iobuf(IOBUF* pBuf) {
	printf("Base Offset   : %p\n", pBuf->base_offset);
	printf("Current Offset: %p\n", pBuf->current_offset);
	printf("Buffer size   : %dbyte\n", pBuf->pageSize);
	printf("Written size  : %zdbyte\n\12", pBuf->base_offset - pBuf->current_offset);
}

int main() {
	FILE* fp = NULL;

	fopen_s(&fp, "CON", "w");
	if (!fp) return 1;

	// debug code
	IOBUF* debug = (IOBUF*)fp;

	print_iobuf(debug);

	fputs("Hello", fp);
	print_iobuf(debug);


	fputs("World", fp);
	print_iobuf(debug);
	//"CON" --> fflush(stdout)

	fclose(fp);
	return 0;
}