#include <stdio.h>

int main(void)
{
	double weight, height;
	int BMI;
	
	printf("enter your weight(kg) and height(m) : ");
	scanf_s("%lf%lf", &weight, &height);

	BMI = weight / ((height / 100) * (height / 100));

	if (BMI >= 20 && BMI < 25)
	{
		printf("Your BMI is normal");
	}
	else
	{
		printf(" You just care your weight %d", BMI);

	}

	return 0;

}