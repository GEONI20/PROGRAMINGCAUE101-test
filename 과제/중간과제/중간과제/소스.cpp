#include <stdio.h>

int Two_by_Two_Det_function_α(int a, int b, int c, int d, int e, int f);
int Two_by_Two_Det_function_β(int a, int b, int c, int d, int e, int f);
int Three_by_Three_Det_Function_α(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
int Three_by_Three_Det_Function_β(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
int Three_by_Three_Det_Function_γ(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
int Four_by_Four_Det_Function_α(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);
int Four_by_Four_Det_Function_β(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);
int Four_by_Four_Det_Function_γ(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);
int Four_by_Four_Det_Function_δ(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);


int main(void)
{
	int Equation_degree;
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t;
	double res_α, res_β, res_γ, res_δ;


	printf("Enter the order of the system of equations you want(2~4) : ");
	scanf_s("%d", &Equation_degree);

	if (Equation_degree == 2)
	{
		printf("Enter each coefficient of ax+by=c : ");
		scanf_s("%d%d%d", &a, &b, &c);
		printf("Enter each coefficient of dx+ey=f : ");
		scanf_s("%d%d%d", &d, &e, &f);
		printf("%dX+%dY=%d\n", a, b, c);
		printf("%dX+%dY=%d\n", d, e, f);

		res_α = Two_by_Two_Det_function_α(a, b, c, d, e, f);
		res_β = Two_by_Two_Det_function_β(a, b, c, d, e, f);

		printf("X : %lf\n", res_α);
		printf("Y : %lf\n", res_β);
	}
	else if (Equation_degree == 3)
	{
		printf("Enter each coefficient of ax+by+cz=d : ");
		scanf_s("%d%d%d%d", &a, &b, &c, &d);
		printf("Enter each coefficient of ex+fy+gz=h : ");
		scanf_s("%d%d%d%d", &e, &f, &g, &h);
		printf("Enter each coefficient of ix+jy+kz=l : ");
		scanf_s("%d%d%d%d", &i, &j, &k, &l);
		printf("%dX+%dY+%dZ=%d\n", a, b, c, d);
		printf("%dX+%dY+%dZ=%d\n", e, f, g, h);
		printf("%dX+%dY+%dZ=%d\n", i, h, k, l);

		res_α = Three_by_Three_Det_Function_α(a, b, c, d, e, f, g, h, i, j, k, l);
		res_β = Three_by_Three_Det_Function_β(a, b, c, d, e, f, g, h, i, j, k, l);
		res_γ = Three_by_Three_Det_Function_γ(a, b, c, d, e, f, g, h, i, j, k, l);

		printf("X : %lf\n", res_α);
		printf("Y : %lf\n", res_β);
		printf("Z : %lf\n", res_γ);

	}
	else if (Equation_degree == 4)
	{
		printf("Enter each coefficient of first w+x+y+z =  : ");
		scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
		printf("Enter each coefficient of second w+x+y+z =  : ");
		scanf_s("%d%d%d%d%d", &f, &g, &h, &i, &j);
		printf("Enter each coefficient of third w+x+y+z =  : ");
		scanf_s("%d%d%d%d%d", &k, &l, &m, &n, &o);
		printf("Enter each coefficient of fourth w+x+y+z = ");
		scanf_s("%d%d%d%d%d", &p, &q, &r, &s, &t);
		printf("%dW+%dX+%dY+%dZ=%d\n", a, b, c, d, e);
		printf("%dW+%dX+%dY+%dZ=%d\n", f, g, h, i, j);
		printf("%dW+%dX+%dY+%dZ=%d\n", k, l, m, n, o);
		printf("%dW+%dX+%dY+%dz=%d\n", p, q, r, s, t);

		
		res_α = Four_by_Four_Det_Function_α(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);
		res_β = Four_by_Four_Det_Function_β(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);
		res_γ = Four_by_Four_Det_Function_γ(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);
		res_δ = Four_by_Four_Det_Function_δ(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);

		printf("W : %lf\n", res_α);
		printf("X : %lf\n", res_β);
		printf("Y : %lf\n", res_γ);
		printf("Z : %lf\n", res_δ);

	}
	else
	{
		printf("You enter the wrong number, restart the program.");
	}


	return 0;
}

//Coefficient of X in 2*2 determinant calculation
int Two_by_Two_Det_function_α(int a, int b, int c, int d, int e, int f)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * e - b * d;
	numerator = c * e - b * f;

	res = (numerator) / (denominator);
	
	return res;
}

//Coefficient of YS in 2*2 determinant calculation
int Two_by_Two_Det_function_β(int a, int b, int c, int d, int e, int f)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * e - b * d;
	numerator = a * f - c * d;

	res = (double)numerator / (double)denominator;

	return res;
}

//Coefficient of X in 3*3 determinant calculation
int Three_by_Three_Det_Function_α(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (f*k-g*j)-b*(e*k - g*j)+ c*(f*j - e*j);
	numerator = d*(f*k-g*j)- b*(h*k-g*l)+c*(h*j-f*l);

	res = (double)numerator / (double)denominator;

	return res;

}



//Coefficient of Y in 3*3 determinant calculation
int Three_by_Three_Det_Function_β(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (f * k - g * j) - b * (e * k - g * j) + c * (f * j - e * j);
	numerator = a * (h * k - g * l) - d * (e * k - g * i) + c * (e * l - h * i);

	res = (double)numerator / (double)denominator;

	return res;
}

//Coefficient of Z in 3*3 determinant calculation
int Three_by_Three_Det_Function_γ(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (f * k - g * j) - b * (e * k - g * j) + c * (f * j - e * j);
	numerator = a*(f*l-h*j)-b*(e*l-h*j)+d*(e*j-f*i);

	res = (double)numerator / (double)denominator;

	return res;
}

//Coefficient of W in 4*4 determinant calculation
int Four_by_Four_Det_Function_α(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l,int m, int n, int o, int p, int q, int r, int s, int t)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (g * (m * s - r * n) - h * (l * s - n * g) + i * (l * n - n * g)) - b * (f * (m * s - l * n) - h * (k * s - n * p) + i * (k * r - n * p)) + c * (f * (l * s - n * q) - g * (k * s - n * p) + i * (k * q - l * p)) - d * (f * (l * r - m * q) - g * (k * r - m * p) + h * (k * q - l * p));
	numerator = e * (g * (m * s - n * r) - h * (l * s - n * q) + i * (l * r - m * q)) - b * (j * (m * s - r * n) - h * (o * s - n * t) + i * (o * r - n * t)) + c * (j * (l * s - n * q) - g * (o * s - n * t) + i * (o * q - l * t)) - d * (j * (l * r - m * q) - g * (o * r - m * t) + h * (o * q - l * t));

	res = (double)numerator / (double)denominator;

	return res;
}

//Coefficient of X in 4*4 determinant calculation
int Four_by_Four_Det_Function_β(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (g * (m * s - r * n) - h * (l * s - n * g) + i * (l * n - n * g)) - b * (f * (m * s - l * n) - h * (k * s - n * p) + i * (k * r - n * p)) + c * (f * (l * s - n * q) - g * (k * s - n * p) + i * (k * q - l * p)) - d * (f * (l * r - m * q) - g * (k * r - m * p) + h * (k * q - l * p));
	numerator = a * (j * (m * s - r * n) - j * (o * s - n * t) + i * (l * r - m * q)) - e * (f * (m * s - n * r) - h * (k * s - n * p) + i * (k * r - m * p)) + c * (f * (o * s - n * t) - j * (k * s - n * p) + i * (k * t - o * p)) - d * (f * (o * r - n * t) - j * (k * r - m * p) + h * (k * t - o * p));

	res = (double)numerator / (double)denominator;

	return res;
}

//Coefficient of Y in 4*4 determinant calculation
int Four_by_Four_Det_Function_γ(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (g * (m * s - r * n) - h * (l * s - n * g) + i * (l * n - n * g)) - b * (f * (m * s - l * n) - h * (k * s - n * p) + i * (k * r - n * p)) + c * (f * (l * s - n * q) - g * (k * s - n * p) + i * (k * q - l * p)) - d * (f * (l * r - m * q) - g * (k * r - m * p) + h * (k * q - l * p));
	numerator = a * (g * (o * s - n * t) - j * (l * s - n * q) + i * (l * t - o * q)) - b * (f * (o * s - n * t) - j * (k * s - n * p) + i * (k * t - o * p)) + e * (f * (l * s - n * q) - g * (k * s - n * p) + i * (k * q - l * p)) - d * (f * (l * t - o * q) - g * (k * t - o * p) + j * (k * q - l * o));

	res = (double)numerator / (double)denominator;

	return res;
}

//Coefficient of Z in 4*4 determinant calculation
int Four_by_Four_Det_Function_δ(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
	int denominator = 0;
	int numerator = 0;
	double res;

	denominator = a * (g * (m * s - r * n) - h * (l * s - n * g) + i * (l * n - n * g)) - b * (f * (m * s - l * n) - h * (k * s - n * p) + i * (k * r - n * p)) + c * (f * (l * s - n * q) - g * (k * s - n * p) + i * (k * q - l * p)) - d * (f * (l * r - m * q) - g * (k * r - m * p) + h * (k * q - l * p));
	numerator = a * (g * (m * t - o * r) - h * (l * t - o * q) + j * (l * r - m * q)) - b * (f * (m * t - o * r) - h * (k * t - o * p) + j * (k * r - m * p)) + c * (f * (l * t - o * q) - g * (k * t - o * p) + j * (k * q - l * p)) - e * (f * (l * r - m * q) - g * (k * r - m * p) + h * (k * q - l * p));

	res = (double)numerator / (double)denominator;

	return res;
}