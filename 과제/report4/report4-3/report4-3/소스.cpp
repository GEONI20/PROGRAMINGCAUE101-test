#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_COND 999
#define n 4
#define m 4
#define randon_0_to_99 99

void GenRandSeed()
{
	srand((unsigned int)(time(NULL)));
	return;
}

unsigned int GenRandNum(unsigned int nRange)
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}

int main()
{
	GenRandSeed();

	printf("A program to find the product of matrices.\n");
	printf("The matrix contains random numbers(0~99).\n\n");

	int nRange = GenRandNum(randon_0_to_99);
	int DetA[n][m] = { { 1,1,1,1 }, { 1, 1, 1, 1 }, { 1,1,1,1 }, { 1,1,1,1 } };
	int DetB[m][n] = { { 1,1,1,1 }, { 1, 1, 1, 1 }, { 1,1,1,1 }, { 1,1,1,1 } };
	int DetC[n][m] = { 0 };


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			DetA[i][j] = GenRandNum(nRange), GenRandNum(nRange);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			DetB[i][j] = GenRandNum(nRange), GenRandNum(nRange);
		}
	}


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				DetC[i][j] += DetA[i][k] * DetB[k][j];
			}
		}
	}

	printf("Determinant A\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("[%d][%d] = %d\t", i, j, DetA[i][j]);
		}
		printf("\n\n");

	}
	
	printf("Determinant B\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("[%d][%d] = %d\t", i, j, DetB[i][j]);
		}
		printf("\n\n");
	}

	printf("Result Determinant\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("DetC[%d][%d] = %d\t", i, j, DetC[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}