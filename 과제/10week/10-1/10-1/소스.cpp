#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	int* pa;
	int i, j = 0;

	while (1)
	{
		printf("Need to enter data(for calculating the prime number from 2 to your data : ");

		scanf_s("%d", &num);

		if (num < 2)
		{
			printf("You enter the wrong number, try again...\n");
			continue;
		}
		else break;

	}

	pa = (int*)malloc((num - 1) * sizeof(int));

	if (pa == NULL)
	{
		printf("Out of Memory...");
		exit(1);
	}

	for (i = 0; i < (num - 1); i++)
	{
		pa[i] = i + 2;
	}
	i = 0;

	while (1)
	{
		while ((pa[i] == 0) && (i < (num - 2)))
		{
			i++;
		}

		if (i == (num - 2))
		{
			break;
		}

		for (j = i + 1; j < (num - 1); j++)
		{
			if ((pa[j] % pa[i]) == 0)
			{
				pa[j] = 0;
			}
		}
		i++;
	}

		for (i = 0; i < (num - 1); i++)
		{
			if (pa[i] != 0)
			{
				printf("%d\t", pa[i]);
			}
			else
			{
				printf("%c\t", 'X');
			}
			if ((i + 1) % 5 == 0)
			{
				printf("\n");
			}
		}
	

	free(pa);

	return 0;

	}
