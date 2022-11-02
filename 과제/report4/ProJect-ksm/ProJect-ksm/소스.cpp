#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	GenRandSeed;
	int nRange = 0;
	int RandomNumber = 0;
	int Answer = 0;
	int i;

	printf("Enter the range of numbers you want to match... : ");
	scanf_s("%d", &nRange);


	RandomNumber = GenRandNum(nRange);
	i = GenRandNum(10);

	while (1)
	{
		if (i < 3)
		{
			i = GenRandNum(10);
		}
		else break;
	}

	printf("You have the chane to match number for %d...\n\n", i);
	printf("What is the number? : ");
	scanf_s("%d", &Answer);

	for(int j = 0; j<i; j++)
	{
		if (Answer > RandomNumber)
		{
			printf("Down!\n\n");
			printf("What is the number? : ");
			scanf_s("%d", &Answer);
			
			continue;
		}
		else if (Answer < RandomNumber)
		{
			printf("Up!\n\n");
			printf("What is the number? : ");
			scanf_s("%d", &Answer);
		}
		else
		{
			break;
		}
	}

	if (Answer == RandomNumber)
	{
		printf("You enter the correct number~ congratulaion!\n");

		return 0;
	}
	else
	{
		printf(" You enter the wrong number...");

		return 0;
	}
}