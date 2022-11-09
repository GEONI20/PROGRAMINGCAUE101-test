#include <stdio.h>
#include <stdlib.h>

#define Second_Simultaneous_Equations 2
#define Thrid_Simultaneous_Equations 3
#define Fourth_Simultaneous_Equations 4
#define ERR_PRN printf("There is no solution to that equation. please restart the program...\n")

int Determinant_Function(int x, int ary[4][5]);//Cramer's rule 계산 함수

int main()
{
	int Equation_degree = 0;//미지수가 몇개인지 확인하는 변수
	int Det[4][5] = { { 0,0,0,0,0 }, { 0,0,0,0,0 }, { 0,0,0,0,0 }, { 0,0,0,0,0 } };//최대 미지수가 4개인 연립방정식 정의

	printf("Enter the order of the system of equations you want(2~4) : ");
	scanf_s("%d", &Equation_degree);
	
	switch (Equation_degree)
	{

	case Second_Simultaneous_Equations://미지수 2개인 연립방정식을 행렬에 저장
		printf("Enter each coefficient of ax+by=c : ");
		for (int i = 0; i < 3; i++)
		{
			scanf_s("%d", &Det[0][i]);
		}
		printf("Enter each coefficient of dx+ey=f : ");
		for (int i = 0; i < 3; i++)
		{
			scanf_s("%d", &Det[1][i]);
		}
		printf("%dX+%dY=%d\n", Det[0][0], Det[0][1],Det[0][2]);
		printf("%dX+%dY=%d\n", Det[1][0], Det[1][1], Det[1][2]);
		//연립방정식 출력

		Determinant_Function(Equation_degree, Det);
		break;

	case Thrid_Simultaneous_Equations://미지수가 3개인 연립방정식을 행렬에 저장

		printf("Enter each coefficient of ax+by+cz=d : ");
		for (int i = 0; i < 4; i++)
		{
			scanf_s("%d", &Det[0][i]);
		}
		printf("Enter each coefficient of ex+fy+gz=h : ");
		for (int i = 0; i < 4; i++)
		{
			scanf_s("%d", &Det[1][i]);
		}
		printf("Enter each coefficient of ex+fy+gz=h : ");
		for (int i = 0; i < 4; i++)
		{
			scanf_s("%d", &Det[2][i]);
		}
		
		printf("%dX+%dY+%dZ=%d\n", Det[0][0], Det[0][1], Det[0][2], Det[0][3]);
		printf("%dX+%dY+%dZ=%d\n", Det[1][0], Det[1][1], Det[1][2], Det[1][3]);
		printf("%dX+%dY+%dZ=%d\n", Det[2][0], Det[2][1], Det[2][2], Det[2][3]);
		//연립방정식 출력

		Determinant_Function(Equation_degree,Det);
		
		break;

	case Fourth_Simultaneous_Equations://미지수가 4개인 연립방정식을 행렬에 저장

		printf("Enter each coefficient of aw+bx+cy+dz=e : ");
		for (int i = 0; i < 5; i++)
		{
			scanf_s("%d", &Det[0][i]);
		}
		printf("Enter each coefficient of fw+gx+hy+iz=j : ");
		for (int i = 0; i < 5; i++)
		{
			scanf_s("%d", &Det[1][i]);
		}
		printf("Enter each coefficient of kw+lx+my+nz=o : ");
		for (int i = 0; i < 5; i++)
		{
			scanf_s("%d", &Det[2][i]);
		}
		printf("Enter each coefficient of pw+qx+ry+sz=t : ");
		for (int i = 0; i < 5; i++)
		{
			scanf_s("%d", &Det[3][i]);
		}

		printf("%dW+%dX+%dY+%dZ=%d\n", Det[0][0], Det[0][1], Det[0][2], Det[0][3], Det[0][4]);
		printf("%dW+%dX+%dY+%dZ=%d\n", Det[1][0], Det[1][1], Det[1][2], Det[1][3], Det[1][4]);
		printf("%dW+%dX+%dY+%dZ=%d\n", Det[2][0], Det[2][1], Det[2][2], Det[2][3], Det[2][4]);
		printf("%dW+%dX+%dY+%dZ=%d\n", Det[3][0], Det[3][1], Det[3][2], Det[3][3], Det[3][4]);
		//연립방정식 출력

		Determinant_Function(Equation_degree,Det);

		break;

	default:

		printf("You enter the wrong number...restart the program...");
		break;
	}

	return 0;
}

//연립방정식을 풀기 위한 함수
int Determinant_Function(int x, int ary[4][5])
{
	int denominator, numerator = 0;
	double res_w,res_x,res_y,res_z= 0;

	switch (x)
	{
	case Second_Simultaneous_Equations://미지수가 2개인 연립방정식

		res_z, res_w = 0, 0;
		denominator = (ary[0][0] * ary[1][1]) - (ary[0][1] * ary[1][0]);
		
		if (denominator != 0)
		{
		
			numerator = (ary[0][2] * ary[1][1]) - (ary[0][1] * ary[1][2]);

			res_x = (double)numerator / (double)denominator;

			numerator = (ary[0][0] * ary[1][2]) - (ary[0][2] * ary[1][0]);

			res_y = (double)numerator / (double)denominator;

			break;
		}
		else
		{
			ERR_PRN;

			return 0;
		}

		

	case Thrid_Simultaneous_Equations://미지수가 3개인 연립방정식

		res_w = 0;

		denominator = ary[0][0] * ((ary[1][1] * ary[2][2]) - (ary[1][2] * ary[2][1]))
					- ary[0][1] * ((ary[1][0] * ary[2][2]) - (ary[1][2] * ary[2][0]))
					+ ary[0][2] * ((ary[1][0] * ary[2][1]) - (ary[1][1] - ary[2][0]));
		
		if (denominator != 0)
		{
			numerator = ary[0][3] * ((ary[1][1] * ary[2][2]) - ary[1][2] - ary[2][1])
						- ary[0][1] * ((ary[1][3] * ary[2][2]) - (ary[1][2] * ary[2][0]))
						+ ary[0][2] * ((ary[1][3] * ary[2][1]) - (ary[1][1] - ary[2][3]));

			res_x = (double)numerator / (double)denominator;

			numerator = ary[0][0] * ((ary[1][3] * ary[2][2]) - ary[1][2] - ary[2][3])
						- ary[0][3] * ((ary[1][0] * ary[2][2]) - (ary[1][2] * ary[2][0]))
						+ ary[0][2] * ((ary[1][3] * ary[2][3]) - (ary[1][1] - ary[2][0]));

			res_y = (double)numerator / (double)denominator;

			numerator = ary[0][0] * ((ary[1][1] * ary[2][3]) - ary[1][3] - ary[2][1])
						- ary[0][1] * ((ary[1][0] * ary[2][3]) - (ary[1][3] * ary[2][0]))
						+ ary[0][3] * ((ary[1][0] * ary[2][1]) - (ary[1][1] - ary[2][0]));

			res_z = (double)numerator / (double)denominator;

			break;

		}

		else
		{
			ERR_PRN;

			return 0;
		}

	case Fourth_Simultaneous_Equations://미지수가 4개인 연립방정식

		denominator = ary[0][0] * (ary[1][1] * (ary[2][2] * ary[3][3] - ary[2][3] * ary[3][2]) - ary[1][2] * (ary[2][1] * ary[3][3] - ary[2][3] * ary[3][1]) + ary[1][3] * (ary[2][1] * ary[3][2] - ary[2][2] * ary[3][1]))
					- ary[0][1] * (ary[1][0] * (ary[2][2] * ary[3][3] - ary[2][3] * ary[3][2]) - ary[1][2] * (ary[2][0] * ary[3][3] - ary[2][3] * ary[3][0]) + ary[1][3] * (ary[2][0] * ary[3][2] - ary[2][2] * ary[3][0]))
					+ ary[0][2] * (ary[1][0] * (ary[2][1] * ary[3][3] - ary[2][3] * ary[3][1]) - ary[1][1] * (ary[2][0] * ary[3][3] - ary[2][3] * ary[3][0]) + ary[1][3] * (ary[2][0] * ary[3][1] - ary[2][1] * ary[3][0]))
					- ary[0][3] * (ary[1][0] * (ary[2][1] * ary[3][2] - ary[2][2] * ary[3][1]) - ary[1][1] * (ary[2][0] * ary[3][2] - ary[2][2] * ary[3][0]) + ary[1][2] * (ary[2][0] * ary[3][1] - ary[2][1] * ary[3][0]));
		
		if (denominator != 0)
		{
			numerator = ary[0][4] * (ary[1][1] * (ary[2][2] * ary[3][3] - ary[2][3] * ary[3][2]) - ary[1][2] * (ary[2][1] * ary[3][3] - ary[2][3] * ary[3][1]) + ary[1][3] * (ary[2][1] * ary[3][2] - ary[2][2] * ary[3][1]))
						- ary[0][1] * (ary[1][4] * (ary[2][2] * ary[3][3] - ary[2][3] * ary[3][2]) - ary[1][2] * (ary[2][4] * ary[3][3] - ary[2][3] * ary[3][4]) + ary[1][3] * (ary[2][4] * ary[3][2] - ary[2][2] * ary[3][4]))
						+ ary[0][2] * (ary[1][4] * (ary[2][1] * ary[3][3] - ary[2][3] * ary[3][1]) - ary[1][1] * (ary[2][4] * ary[3][3] - ary[2][3] * ary[3][4]) + ary[1][3] * (ary[2][4] * ary[3][1] - ary[2][1] * ary[3][4]))
						- ary[0][3] * (ary[1][4] * (ary[2][1] * ary[3][2] - ary[2][2] * ary[3][1]) - ary[1][1] * (ary[2][4] * ary[3][2] - ary[2][2] * ary[3][4]) + ary[1][2] * (ary[2][4] * ary[3][1] - ary[2][1] * ary[3][4]));

			res_w = (double)numerator / (double)denominator;//W의 계수를 구하는 식

			numerator = ary[0][0] * (ary[1][4] * (ary[2][2] * ary[3][3] - ary[2][3] * ary[3][2]) - ary[1][2] * (ary[2][4] * ary[3][3] - ary[2][3] * ary[3][4]) + ary[1][3] * (ary[2][4] * ary[3][2] - ary[2][2] * ary[3][4]))
						- ary[0][4] * (ary[1][0] * (ary[2][2] * ary[3][3] - ary[2][3] * ary[3][2]) - ary[1][2] * (ary[2][0] * ary[3][3] - ary[2][3] * ary[3][0]) + ary[1][3] * (ary[2][0] * ary[3][2] - ary[2][2] * ary[3][0]))
						+ ary[0][2] * (ary[1][0] * (ary[2][4] * ary[3][3] - ary[2][3] * ary[3][4]) - ary[1][4] * (ary[2][0] * ary[3][3] - ary[2][3] * ary[3][0]) + ary[1][3] * (ary[2][0] * ary[3][4] - ary[2][4] * ary[3][0]))
						- ary[0][3] * (ary[1][0] * (ary[2][4] * ary[3][2] - ary[2][2] * ary[3][4]) - ary[1][4] * (ary[2][0] * ary[3][2] - ary[2][2] * ary[3][0]) + ary[1][2] * (ary[2][0] * ary[3][4] - ary[2][4] * ary[3][0]));

			res_x = (double)numerator / (double)denominator;//X의 계수를 구하는 식

			numerator = ary[0][0] * (ary[1][1] * (ary[2][4] * ary[3][3] - ary[2][3] * ary[3][4]) - ary[1][4] * (ary[2][1] * ary[3][3] - ary[2][3] * ary[3][1]) + ary[1][3] * (ary[2][1] * ary[3][4] - ary[2][4] * ary[3][1]))
						- ary[0][1] * (ary[1][0] * (ary[2][4] * ary[3][3] - ary[2][3] * ary[3][4]) - ary[1][4] * (ary[2][0] * ary[3][3] - ary[2][3] * ary[3][0]) + ary[1][3] * (ary[2][0] * ary[3][4] - ary[2][4] * ary[3][0]))
						+ ary[0][4] * (ary[1][0] * (ary[2][1] * ary[3][3] - ary[2][3] * ary[3][1]) - ary[1][1] * (ary[2][0] * ary[3][3] - ary[2][3] * ary[3][0]) + ary[1][3] * (ary[2][0] * ary[3][1] - ary[2][1] * ary[3][0]))
						- ary[0][3] * (ary[1][0] * (ary[2][1] * ary[3][4] - ary[2][4] * ary[3][1]) - ary[1][1] * (ary[2][0] * ary[3][4] - ary[2][4] * ary[3][0]) + ary[1][4] * (ary[2][0] * ary[3][1] - ary[2][1] * ary[3][0]));

			res_y = (double)numerator / (double)denominator;//Y의 계수를 구하는 식

			numerator = ary[0][0] * (ary[1][1] * (ary[2][2] * ary[3][4] - ary[2][4] * ary[3][2]) - ary[1][2] * (ary[2][1] * ary[3][4] - ary[2][4] * ary[3][1]) + ary[1][4] * (ary[2][1] * ary[3][2] - ary[2][2] * ary[3][1]))
						- ary[0][1] * (ary[1][0] * (ary[2][2] * ary[3][4] - ary[2][4] * ary[3][2]) - ary[1][2] * (ary[2][0] * ary[3][4] - ary[2][4] * ary[3][0]) + ary[1][4] * (ary[2][0] * ary[3][2] - ary[2][2] * ary[3][0]))
						+ ary[0][2] * (ary[1][0] * (ary[2][1] * ary[3][4] - ary[2][4] * ary[3][1]) - ary[1][1] * (ary[2][0] * ary[3][4] - ary[2][4] * ary[3][0]) + ary[1][4] * (ary[2][0] * ary[3][1] - ary[2][1] * ary[3][0]))
						- ary[0][4] * (ary[1][0] * (ary[2][1] * ary[3][2] - ary[2][2] * ary[3][1]) - ary[1][1] * (ary[2][0] * ary[3][2] - ary[2][2] * ary[3][0]) + ary[1][2] * (ary[2][0] * ary[3][1] - ary[2][1] * ary[3][0]));

			res_z = (double)numerator / (double)denominator;//Z의 계수를 구하는 식

			break;

		}

		else
		{
			ERR_PRN;

			return 0;
		}

	default:
		break;
	}

	return printf("W : %lf\nX : %lf\nY : %lf\nZ : %lf\n", res_w, res_x, res_y, res_z);
}
