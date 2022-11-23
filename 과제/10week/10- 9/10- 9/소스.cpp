#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char line[999];

	FILE* file_1 = fopen("c:\\c_programing\\yolo_bbox_data.txt", "r");
	if (file_1 == NULL)
	{
		printf("파일열기 실패\n");
		return 1;
	}
	FILE* file_2 = fopen("c:\\c_programing\\yolo_label_data.txt", "r");
	if (file_2 == NULL) 
	{
		printf("파일열기 실패\n");
		return 1;
	}


	while (fgets(line, sizeof(line), file_1) != NULL)
	{
		printf("%s", line);
	}

	while (fgets(line, sizeof(line), file_2) != NULL)
	{
		printf("%s", line);
	}

	

	fclose(file_1);
	fclose(file_2);

	return 0;

}