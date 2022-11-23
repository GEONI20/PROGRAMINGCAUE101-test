#include <stdio.h>
#include <stdlib.h>
#include < string.h>

struct cracker_information
{
	int price;
	int calories;
};



void print_list(struct cracker_information *pl);

int main()
{
	struct cracker_information cookies = { 0 };

	printf("Enter the 바바삭's price and calories : ");
	
	scanf_s("%d%d",&cookies.price, &cookies.calories);

	struct cracker_information* pl = &cookies;

	print_list(pl);

	return 0;
}

void print_list(struct cracker_information *pl)
{
		printf("price : %d\ncalories : %d", (pl)->price, (pl)->calories);	
}