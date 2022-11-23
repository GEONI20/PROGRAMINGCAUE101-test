#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE* file = fopen("c:\\c_programing\\test.1.txt", "w");
		if (file == NULL)
		{
			printf("failed...\n");
			return 1;
		}

	fputs("100\n10.024\nA\nAnt\n", file);

	fclose(file);

	return 0;

}