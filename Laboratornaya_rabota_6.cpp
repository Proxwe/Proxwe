// Лабораторная работа 6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <iomanip>
#include "statlib.h"
#include "dynlib.h"
using namespace std;

void ind_1()
{
	int i, j, k;
	float S_c_main = 0, S_d_main = 0, S_c_sec = 0, S_d_sec = 0;
	cout << "Enter the size of matrix: ";
	cin >> k;
	cout << "------------------------------------------------------------" << endl;

	double **c = new double*[k];
	double **d = new double*[k];
	for (i = 0; i < k; i++)
	{
		c[i] = new double[k];
		d[i] = new double[k];
	}

	for(i = 0; i < k; i++)
		for (j = 0; j < k; j++)
		{
			c[i][j] = value_c(i, j);
			d[i][j] = value_d(i, j);
		}

	for (i = 0, j = 0; i < k; i++, j++)
	{
		S_c_main += c[i][j];
		S_d_main += d[i][j];
	}

	for (i = k - 1, j = 0; j < k; j++, i--)
	{
		S_c_sec += c[i][j];
		S_d_sec += d[i][j];
	}
	cout << "The matrix C: " << endl;
	cout << "------------------------------------------------------------" << endl;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			cout << setprecision(4) << c[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------" << endl;
	cout << "The sum of elements on main diagonal: " << S_c_main << "; on the secondary diagonal: " << S_c_sec << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "The matrix D: " << endl;
	cout << "------------------------------------------------------------" << endl;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			cout << setprecision(4) << d[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------" << endl;
	cout << "The sum of elements on main diagonal: " << S_d_main << "; on the secondary diagonal: " << S_d_sec << endl;
	for (int i = 0; i < k; i++)
		delete[] c[i], d[i];
	system("pause");
}

void ind_2()
{
	int n, i, third, one_third, two_third, all;
	cout << "Enter the size of array: ";
	cin >> n;
	double *a = new double[n];
	cout << "Enter the elements: ";
	for (i = 0; i < n; i++)
		cin >> a[i];
	third = n / 3;

	one_third = condition(a, 0, third - 1);
	two_third = condition(a, third, n - 1);

	all = one_third + two_third;
	if (!all) cout << "Elements that meet the condition does not exist." << endl;
	else cout << "Elements that meet the condition exist" << endl;
	delete[] a;
	system("pause");
}

void ind_3()
{
	int n;
	double integr_1, integr_2, integr_3, integr_4;
	cout << "Enter the number of steps: ";
	cin >> n;
	integr_1 = integral_1(n);
	integr_2 = integral_2(n);
	integr_3 = integral_3(n);
	integr_4 = integral_4(n);
	cout << "The value of the integral 1: " << integr_1 << endl;
	cout << "The value of the integral 2: " << integr_2 << endl;
	cout << "The value of the integral 3: " << integr_3 << endl;
	cout << "The value of the integral 4: " << integr_4 << endl;
	system("pause");
}

void dop_1_1()
{
	int n, i, m, p, j, k = 0, multiply;
	cout << "Enter the sizes of array: ";
	cin >> p;
	cin >> m;
	n = min(p, m);
	
	int **a = new int*[p];
	for (i = 0; i < n; i++)
		a[i] = new int[m];
	int *b = new int[n];

	cout << "Enter the elements: ";
	for (i = 0; i < p; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];

	cout << "------------------------------------------------------------" << endl;
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
	cout << "------------------------------------------------------------" << endl;
	
	for (int i = 0, j = 0; i < n; i++, j++)
	{
		if (test_odd(a[i][j]))
		{
			b[k] = a[i][j];
			k++;
		}
	}

	multiply = multpl(b, k);

	cout << "------------------------------------------------------------" << endl;
	cout << "The obtained array: " << endl;
	cout << "------------------------------------------------------------" << endl;
	for (i = 0; i < k; i++)
		cout << b[i] << ' ' << endl;

	cout << "------------------------------------------------------------" << endl;
	cout << "The product of the array elements: " << multiply;
	system("pause");
}

void dop_1_2()
{
	int n, i, j, m, number = 0;
	cout << "Enter the sizes of array: ";
	cin >> n >> m;

	double **a = new double*[n];
	for (i = 0; i < n; i++)
		a[i] = new double[m];

	double **b = new double*[m];
	for (i = 0; i < m; i++)
		b[i] = new double[n];

	cout << "Enter the elements: ";
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		cin >> a[i][j];
	cout << "----------------------------------------------------------------" << endl;
	cout << "Typed array :" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << "The elements with zero value: ";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				cout << "(" << i << ", " << j << "), ";
				number++;
			}
			b[j][i] = a[i][j];
		}
	}
	if (number == 0) cout << "none";
	cout << endl;
	cout << "The number of the elements with zero value: " << number << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Obtained array: " << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
			cout << b[j][i] << '\t';
		cout << endl;
	}
	cout << "----------------------------------------------------------------" << endl;
	system("pause");
}

void dop_1_3()
{
	int n, i, j, m, k, l = 0, number = 0;
	double sr_a;
	cout << "Enter the sizes of array: ";
	cin >> n >> m;

	int **a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[m];

	k = (m + 1) / 2 * n;
	int *b = new int[k];

	cout << "Enter the elements: ";
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	cout << "----------------------------------------------------------------" << endl;
	cout << "Typed array :" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
	for(j = 1; j < m; j += 2)
		for (i = 0; i < n; i++)
			if (a[i][j] % 2 == 1)
			{
				b[l] = a[i][j];
				l++;
			}
	cout << "----------------------------------------------------------------" << endl;
	cout << "Dynamic array: " << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (i = 0; i < l; i++)
	{
		cout << b[i] << '\t';
	}
	sr_a = sr_arifm(b, l);
	cout << endl << "----------------------------------------------------------------" << endl;
	cout << "Arithmetical mean: " << sr_a << endl;
	system("pause");
}

void dop_2_1()
{
	int p, S = 0, i, q;
	cin >> p >> q;
	if (p >= 0 && q >= 0)
	{
		
		for (i = p; i < q + 1; i++)
		{
			S += F_n(i);
		}
		cout << S << endl;
		dop_2_1();
	}
	else system("pause");
}

void dop_2_2()
{

	unsigned long long int k = 1, n = 1, t = 1, temp = 1;
	
	while (k != 0 && n != 0 && t != 0)
	{
		cin >> k >> n >> t;
		if (k != 0 && n != 0 && t != 0)
		{
			cout << "Case #" << temp << ": " << test(k, n, t) << endl;
			temp++;
		}
		else system("pause");
	}
}

void dop_2_3()
{
	int n;
	cin >> n;
	cout << f_(n) << endl;
	system("pause");
}

int main()
{
	int a, all;
	cout << "Lab #6." << endl;
	Sleep(1000);
	do
	{
		system("cls");
		cout << "1. Individual tasks" << endl;
		cout << "2. Additional tasks" << endl;
		cout << "3. Additional* tasks" << endl;
		cout << "4. Exit the program" << endl;
		do {
			cout << "Choose the variant: ";
			cin >> a;
		} while (a<1 || a>4);
		switch (a)
		{
		case 1:
		{
			do
			{
				system("cls");
				cout << "Choose the task (1 - 3): ";
				cin >> all;
				switch (all)
				{
				case 1:
					system("cls");
					ind_1();
					break;
				case 2:
					system("cls");
					ind_2();
					break;
				case 3:
					system("cls");
					ind_3();
					break;
				default:
					break;
				}
			} while (all < 1 || all > 3);
			break;
		}
		case 2:
		{
			do
			{
				system("cls");
				cout << "Choose the task (1 - 3): ";
				cin >> all;
				switch (all)
				{
				case 1:
					system("cls");
					dop_1_1();
					break;

				case 2:
					system("cls");
					dop_1_2();
					break;

				case 3:
					system("cls");
					dop_1_3();
					break;

				default:
					break;
				}
			} while (all < 1 || all > 3);
			break;
		}
		case 3:
		{
			do
			{
				system("cls");
				cout << "Choose the task (1 - 3): ";
				cin >> all;
				switch (all)
				{
				case 1:
					system("cls");
					dop_2_1();
					break;

				case 2:
					system("cls");
					dop_2_2();
					break;

				case 3:
					system("cls");
					dop_2_3();
					break;

				default:
					break;
				}
			} while (all < 1 || all > 3);
			break;
		}
		}
	} while (a != 4);

	return 0;
}


