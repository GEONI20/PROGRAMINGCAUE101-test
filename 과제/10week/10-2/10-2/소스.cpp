#include <stdio.h>
#include <stdlib.h>

struct book_information
{
	char title[80];
	char author[80];
	int page;
	int price;
};


int main()
{


	struct book_information list[3] = {
		{"Harry Porter and the Philosopher's Stone", "J.K. Rowling", 239 ,16200},
		{"Harry Porter and the secret room        ", "J.K. Rowling", 251, 18900},
		{"Harry Porter and the Prisoner of Azkaban", "J.K Rowling", 293, 22500}
	};

	for (int i = 0; i < 3; i++)
		printf("%s\t%s\t%d\t%d\n", list[i].title, list[i].author, list[i].page, list[i].price);

	return 0;
}