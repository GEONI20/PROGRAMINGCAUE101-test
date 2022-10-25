#include <stdio.h>
#include <stdlib.h>



int main()
{
	int i, j, k;

	int A[4][4] = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
	int B[4][4] = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
	int C[4][4] = {0};

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("c[%d][%d] = %d\t", i, j, C[i][j]);
		}
		printf("\n");
	}

	return 0;
}