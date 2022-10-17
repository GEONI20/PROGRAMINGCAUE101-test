#include <stdio.h>
#include <string.h>

#define password 20

int main()
{
	char pas[password] = "rlarjsgml03";
	char input[password];

	while (1)
	{
		printf("Enter the password : ");
		gets_s(input);

		if (strcmp(pas, input))
		{
			printf("not matchd, retry..\n\n");
		}
		else
		{
			printf("normal termination..");
			break;
		}
	}

	return 0;
}
