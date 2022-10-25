#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define END_COND 999
#define MAX_COUNT 10

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

int main(void)
{
	GenRandSeed();

	int nRange = 0;
	int sum = 0;
	int list[MAX_COUNT];
	double avg = 0;
	double var = 0;
	double std = 0;
	

	while (1)
	{
		printf("Input a single number, for generating the random number related to your input:\n");
		printf("Then, the mean, variance, and standard deviation of 10 random numbers are calculated.\n");
		printf("if you want to end the loop, please input 999\n");
		scanf_s("%d", &nRange);

		if (nRange == END_COND)
		{
			printf("end of the infinite while loop...\n");
			break;
		}
		else
		{
			for (int i = 0; i < MAX_COUNT; i++)
			{
				list[i] = GenRandNum(nRange);
			}
			for (int i = 0; i < MAX_COUNT; i++) sum = sum + list[i];

			avg = (double)sum / MAX_COUNT;

			for (int i = 0; i < MAX_COUNT; i++)
			{
				var = var + pow(list[i] - avg, 2);
			}
			var = var / MAX_COUNT;
			std = sqrt(var);
			
			for (int i = 0; i < MAX_COUNT; i++)
			{
				printf("%3d", list[i]);
			}
			
			printf("\n");
			printf("Result average : %lf\n", avg);
			printf("Result variance : %lf\n", var);
			printf("Result standard deviation : %lf\n\n", std);
		}
	}

	system("pause");
	return 0;
}