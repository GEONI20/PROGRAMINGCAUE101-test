#include <stdio.h>

int main(void)
{
	char ch;

	printf("input the any text : ");
	scanf_s("%c", &ch);
	printf("%c 's ascki code is	%d", ch, ch);

	return 0;
}