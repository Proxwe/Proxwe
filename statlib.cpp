#include "statlib.h"
#include<stdexcept>

using namespace std;

double value_c(double i, double j)
{
	return (pow(i, 2) + pow(j, 2)) / (i + j + 1);
}

double value_d(double i, double j)
{
	if (j > 8) return ((pow(i, 2) + pow(j, 2)) / 2);
	else return pow(i, 2) + pow(j, 2);
}

bool test_odd(int a)
{
	if (a % 2 == 0) return true;
	else return false;
}

int multpl(int *b, int k)
{
	int product = 1, i;
	for (int i = 0; i < k; i++)
		product *= b[i];
	return product;
}

double integral_1(int n)
{
	int i;
	double a = 1.2, b = 2.6, h, sum = 0, f_x, x;
	h = (b - a) / n;
	for (i = 0; i < n; i++)
	{
		x = a + i * h;
		f_x = pow(0.4 * x + 1.7, 0.5) / (1.5 * x + pow(pow(x, 2) + 1.3, 0.5));
		sum += f_x;
	}
	sum *= h;
	return sum;
}

double integral_2(int n)
{
	int i;
	double a = 0.3, b = 1.5, h, sum = 0, f_x, x;
	h = (b - a) / n;
	for (i = 1; i <= n; i++)
	{
		x = a + i * h;
		f_x = sin(0.3 * x + 1.2) / (1.3 + pow(cos(0.5 * x + 1), 2));
		sum += f_x;
	}
	sum *= h;
	return sum;
}

double integral_3(int n)
{
	int i;
	double a = 1.4, b = 2.1, h, sum = 0, f_x, x;
	h = (b - a) / n;
	for (i = 0; i < n; i++)
	{
		x = a + i * h + h / 2;
		f_x = 1 / pow(3 * pow(x, 2) - 1, 0.5);
		sum += f_x;
	}
	sum *= h;
	return sum;
}

double integral_4(int n)
{
	int i;
	double a = 0.8, b = 1.6, h, sum = 0, f_x, x;
	h = (b - a) / n;
	for (i = 1; i < n; i++)
	{
		x = a + i * h;
		f_x = log(pow(x, 2) + 1) / x;
		sum += f_x;
	}
	x = a;
	f_x = log(pow(x, 2) + 1) / x;
	sum += f_x / 2;
	x = a + n * h;
	f_x = log(pow(x, 2) + 1) / x;
	sum += f_x / 2;
	sum *= h;
	return sum;
}

double sr_arifm(int *b, int l)
{
	double sr_arifm = 0;
	for (int i = 0; i < l; i++)
	{
		sr_arifm += b[i];
	}
	sr_arifm /= l;
	return sr_arifm;
}

int F_n(int n)
{
	if (n == 0) return 0;
	else if (n % 10 > 0) return n % 10;
	else return F_n(n / 10);
}

unsigned long long int test(unsigned long long int k, unsigned long long int n, unsigned long long int t)
{
	unsigned long long int m, i, x = 0;
	m = pow(10, t);
	for (i = 0; i < n * (k - 1) + 1; i++)
	{
		x += f(n, i, k);
	}
	return (x % m);
}

unsigned long long int f(unsigned long long int n, unsigned long long int r, unsigned long long int k)
{
	unsigned long long int s = 0, j;
	if (n == 0 && r == 0) return 1;
	else if ((n > 0) && (r >= 0 && r < n*(k - 1) + 1))
	{
		for (j = 0; j < k; j++)
		{
			s += f(n - 1, r - j, k);
		}
		return s;
	}	
	else return 0;
}

long long int f_(int n)
{	
	if (n == 1) return 1;
	else if (n & 1) return pow((n + 1) / 2, 2) + f_((n - 1) / 2);
	else return pow(n / 2, 2) + f_(n / 2);
}