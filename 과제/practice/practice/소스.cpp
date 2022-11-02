#include <stdio.h>

int Determinant(int ary [3][4]);

int main()
{
	int DetA[4] = { 1,2,3,4 };

	int(*ary)[4];

	ary = &DetA;

	printf("%dX+%dY+%dZ=%d", Determinant(ary));


}

int Det(int ary[4])
{
	return 2, 3, 4, 5;
}