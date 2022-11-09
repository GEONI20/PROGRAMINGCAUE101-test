#include <stdio.h>
#include <string.h>

#define MAXWORDLENGTH 80
#define LimitOmittedLength 5

int main()
{
	char str[MAXWORDLENGTH];
	char res_str[MAXWORDLENGTH];
	char star[MAXWORDLENGTH] = "**************";
	int len;


	printf("Enter the words : ");
	gets_s(str);
	printf("Entered words : ");
	puts(str);
	

	len = strlen(str);

	if (len <= LimitOmittedLength)
	{
		strcmp(res_str, str);
	}
	else
	{
		strcmp(res_str, star);
		strncpy_s(res_str, str, LimitOmittedLength);
		strncat_s(res_str,star, len-LimitOmittedLength);
	}

	printf("omitted word : ");
	puts(res_str);

	return 0;
}