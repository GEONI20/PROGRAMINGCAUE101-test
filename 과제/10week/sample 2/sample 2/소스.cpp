#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define ACUT 90.0
#define BCUT 80.0
#define CCUT 70.0


typedef struct

{

    int stdnum;                  

    char name[20];         

    int kor, eng, mat;        

    int tot;                 

    double avg;            

    char grade;              

} Student;




void input_data(Student* pary);

void calc_data(Student* pary);

void sort_data(Student* pary);

void print_data(Student* pary);




int main(void)

{

    Student ary[5];        

    printf("Enter the grade for five student...\n");




    input_data(ary);         

    calc_data(ary);           




    printf("# 정렬 전 데이터...\n");

    print_data(ary);         

    sort_data(ary);         

    printf("\n# 정렬 후 데이터...\n");

    print_data(ary);        




    return 0;

}




void input_data(Student* pary)

{

    int i;




    for (i = 0; i < 5; i++)

    {

        printf("Student Number : ");

        scanf_s("%d", &pary->stdnum);

        printf("Name : ");

        scanf_s("%s", pary->name, 20);

        printf("Korean, English, Math's grades : ");

        scanf_s("%d%d%d", &pary->kor, &pary->eng, &pary->mat);

        pary++;

    }

}




void calc_data(Student* pary)

{

    int i;




    for (i = 0; i < 5; i++)

    {

        pary->tot = pary->kor + pary->eng + pary->mat;

        pary->avg = pary->tot / 3.0;

        if (pary->avg >= ACUT) pary->grade = 'A';

        else if (pary->avg >= BCUT) pary->grade = 'B';

        else if (pary->avg >= CCUT) pary->grade = 'C';

        else pary->grade = 'F';

        pary++;

    }

}




void sort_data(Student* pary)

{

    Student temp;

    int i, j;

    int max;




    for (i = 0; i < 4; i++)

    {

        max = i;

        for (j = i + 1; j < 5; j++)

        {

            if (pary[max].tot < pary[j].tot)

            {

                max = j;

            }

        }

        if (max != i)

        {

            temp = pary[max];

            pary[max] = pary[i];

            pary[i] = temp;

        }

    }

}




void print_data(Student* pary)

{

    int i;




    for (i = 0; i < 5; i++)

    {

        printf("%5d%7s%5d%5d%5d%5d%7.1lf%5c\n",

            pary->stdnum, pary->name, pary->kor, pary->eng,

            pary->mat, pary->tot, pary->avg, pary->grade);

        pary++;

    }

}