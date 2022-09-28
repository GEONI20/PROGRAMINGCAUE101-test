#include <stdio.h>

#define MINSIZE	90
#define MAXSIZE	100

int main(void)
{
	int chest;
	char size;

	printf("Enter your chest size :");
	scanf_s("%d", &chest);

	if (chest <= MINSIZE)
	{
		size = 'S';
	}
	else if ((chest > MINSIZE) && (chest <= MAXSIZE))
	{
		size = 'M';
	}
	else
	{
		size = 'L';
	}

	printf("Your clothes size is %c", size);

	return 0;
}