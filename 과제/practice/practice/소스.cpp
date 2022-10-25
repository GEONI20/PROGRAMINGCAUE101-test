#include <stdio.h>

int get_func();

int main(void)
{
	int	result;

	result = get_func();

	printf("%d", result);

	return 0;
}

int get_func()
{
	int input;

	printf("Enter the number : ");
	scanf_s("%d", &input);

	return input;
}