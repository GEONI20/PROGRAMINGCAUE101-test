#include <stdio.h>
#include <stdlib.h>
#define ACUT 90
#define BCUT 80
#define CCUT 70

struct profile //구조체 선언
{
    int stunum;
    char name[1000];
    int kor;
    int math;
    int eng;
};

int main(void)
{
    struct profile Student[5];

    for (int i = 0; i < 5; i++)
    {
        printf("학번 : ");
        scanf_s("%d", &Student[i].stunum);

        printf("이름: ");
        scanf_s("%s", &Student[i].name, 1000);

        printf("국어, 영어, 수학 점수 : ");
        scanf_s("%d%d%d", &Student[i].kor, &Student[i].math, &Student[i].eng);
    }
    int bignum;
    int total[5];
    float aver[5];
    char grade[5];

    for (int i = 0; i < 5; i++)
    {
        total[i] = (Student[i].kor) + (Student[i].math) + (Student[i].eng);
        aver[i] = total[i] / 3;

        if (aver[i] >= ACUT)
        {
            grade[i] = 'A';
        }
        else if (aver[i] < ACUT && aver[i] >= BCUT)
        {
            grade[i] = 'B';
        }
        else if (aver[i] < BCUT && aver[i] >= CCUT)
        {
            grade[i] = 'c';
        }
        grade[i] = 'F';
        if (i == 0)
            printf("# 정렬 전 데이터...\n");
        printf("\t%d \t%s \t%d \t%d \t%d \t%d \t%lf \t%c\n", Student[i].stunum, Student[i].name, Student[i].kor, Student[i].math, Student[i].eng, total[i], aver[i]);
    }

    int selectednum[5];

    for (int i = 0; i < 5; i++)
    {
        bignum = 0;
        for (int j = 0; j < 5; j++)
        {
            int check = 0;
            for (int k = 0; k < 5;)
            {
                if (j == selectednum[k])
                {
                    check = 1;
                    break;
                }
            }

            if (check == 0)
            {
                if (total[j] > bignum)
                {
                    bignum = total[j];
                    selectednum[i] = j;
                }
            }

        }
        if (i == 0)
            printf("# 정렬 후 데이터...\n");
        printf("\t%d \t%s \t%d \t%d \t%d \t%d \t%lf \t%c\n", Student[i].stunum, Student[i].name, Student[i].kor, Student[i].math, Student[i].eng, total[i], aver[i]);
    }

    return 0;
}