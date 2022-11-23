#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RANGE 20

struct marriage
{
	char name[RANGE];
	int age;
	char sex;
	double height;
};

struct marriage m1 = { "Andy", 22, 'm', 187.5 };
struct marriage* pm = &m1;

int main()
{
	printf("name : %s\n", pm->name);
	printf("age : %d\n", pm->age);
	printf("sex : %c\n", pm->sex);
	printf("height : %lf\n", pm->height);

	return 0;
}