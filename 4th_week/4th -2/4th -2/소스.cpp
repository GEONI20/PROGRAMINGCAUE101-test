#include <stdio.h>

#define AGETHRESH	20

int main(void)
{
	int age, chestSize;
	char clothesSize;
	age = 0, chestSize = 0, clothesSize = 0;

	printf("Enter your age and chest size : ");
	scanf_s("%d%d", &age, &chestSize);

	if (age < AGETHRESH)
	{
		if (chestSize < 85)
		{
			clothesSize = 'S';
		}
		else if ((chestSize <= 85) && (chestSize < 95))
		{
			clothesSize = 'M';
		}
		else
		{
			clothesSize = 'L';
		}
	}
	else
	{
		if (chestSize < 90)
		{
			clothesSize = 'S';
		}
		else if ((chestSize <= 90) && (chestSize < 100))
		{
			clothesSize = 'M';
		}
		else
		{
			clothesSize = 'L';
		}
	}

		printf("Your clothe size is %c", clothesSize);

		return 0;
}