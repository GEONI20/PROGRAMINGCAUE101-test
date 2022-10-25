#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_COND 999
#define Range 10
#define Randon_Number_0_to_99 99


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

void ascending(int list[]);

void descending(int list[]);

int main()
{
	GenRandSeed();

	int nRange = Randon_Number_0_to_99;
	int list[Range] = { 0 };
	int* pa, * pb;
	int tmp, select;
	
	for (int i = 0; i < Range; i++)
	{
		list[i] = GenRandNum(nRange);
	}

	printf("Enter number 1 for ascending order, number 2 for descending order : ");
	scanf_s("%d", &select);


	switch (select)
	{
	case 1:

		ascending(list);
		break;

	case 2:

		descending(list);
		break;

	default:
		printf("worng number, re-typing the number...");
		break;
	}

	printf("Result : ");
	for (int i = 0; i < Range; i++)
	{
		printf("%3d", list[i]);
	}
	printf("\n");

	return 0;
	}


void ascending(int list[])
{
	int* pa, * pb;
	int tmp;

	for (int i = 0; i < Range; i++)
	{
		for (int j = 0; j < Range; j++)
		{
			pa = &list[i];
			pb = &list[j];

			if (list[i] > list[j])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void descending(int list[])
{
	int* pa, * pb;
	int tmp;

	for (int i = 0; i < Range; i++)
	{
		for (int j = 0; j < Range; j++)
		{
			pa = &list[i];
			pb = &list[j];

			if (list[i] > list[j])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}