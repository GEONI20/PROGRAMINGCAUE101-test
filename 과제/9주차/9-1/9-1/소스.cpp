#include <stdio.h>
#include <string.h>

int main()
{
	char str[80];
	strcpy_s(str, "wine");
	printf("%s\n", str);
	strcat_s(str, "apple");
	printf("%s\n", str);
	strncpy_s(str, "pear", 1);
	printf("%s, %d\n", str, strlen(str));

	return 0;
}