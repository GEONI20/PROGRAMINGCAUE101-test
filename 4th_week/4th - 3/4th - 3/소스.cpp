#include <stdio.h>

int main(void)
{
	int nA = 0;
	int nB = 0;
	int res;
	char chOper;

	printf("Enter the desired arithmetic operation : ");
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);

	switch (chOper)
	{
	case '+':
		res = nA + nB;
		break;
	case '-':
		res = nA - nB;
		break;
	case '*':
		res = nA * nB;
		break;
	case '/':
		res = nA / nB;
		break;
	}

	printf("%d%c%d = %d", nA, chOper, nB, res);

	return 0;
}