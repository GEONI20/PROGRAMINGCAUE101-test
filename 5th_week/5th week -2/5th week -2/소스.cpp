#include <stdio.h>

int main()
{
	int input;
	int i, j;
	int pn;
	int cnt = 0;

	printf("Enter something greater than 2 : ");
	scanf_s("%d", &input);

	for (i = 2; i <= input; i++)
	{
		pn = 1;
		for (j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				pn = 0;
				break;
			}
		}


		if (pn == 1)
		{
			printf("%5d", i);
			cnt++;
			if ((cnt % 5) == 0)
			{
				printf("\n");
			}

		}
	}

	return 0;
}