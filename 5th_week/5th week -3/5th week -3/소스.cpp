#include <stdio.h>

int sum(int x, int y);

int sub(int x, int y);

int mul(int x, int y);

int div(int x, int y);

int rem(int x, int y);

int main(void)
{
	int nA = 0;
	int nB = 0;
	int res;
	char chOper;

	printf("Enter the desired arithmetic operation : ");
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);

	if (chOper == '+')
	{
		res = sum(nA, nB);
	}
	else if (chOper == '-')
	{
		res = sub(nA, nB);
	}
	else if (chOper == '*')
	{
		res = mul(nA, nB);
	}
	else if (chOper == '/')
	{
		res = div(nA, nB);
	}
	else if(chOper == '%')
	{
		res = rem(nA, nB);
	}
	else
	{
		printf("You enter the wrong type of arithmetic operation");
		printf("Restrat the program");
	}

	printf("%d%c%d =  %d", nA, chOper, nB, res);

	return 0;
}

int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int rem(int x, int y)
{
	return x % y;
}