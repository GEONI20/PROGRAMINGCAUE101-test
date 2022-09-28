#include <stdio.h>

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
		res = nA + nB;
	}
	else if (chOper == '-')
	{
		res = nA - nB;
	}
	else if (chOper == '*')
	{
		res = nA * nB;
	}
	else if (chOper == '/')
	{
		res = nA / nB;
	}
	else
	{
		printf("You enter the wrong type of arithmetic operation");
		printf("Restrat the program");
	}

	printf("%d%c%d =  %d", nA, chOper, nB, res);

	return 0;
}