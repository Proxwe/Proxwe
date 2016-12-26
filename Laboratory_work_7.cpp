#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include <string>

using namespace std;

void ind_1()
{
	char str[80], substr[80];
	int i, flag = 0, l = 0, k = 0;
	cin.getline(str, 79);
	while (!isdigit(str[k]) && k < strlen(str)) k++;
	if (k < strlen(str))
	{
		if (str[k - 1] == '-')
		{
			substr[l] = '-';
			l++;
		}
		for (i = k; isdigit(str[i]) || (str[i] == '.' && flag == 0); i++)
		{
			substr[l] = str[i];
			l++;
			if (str[i] == '.') flag++;
		}
		if (substr[l - 1] == '.')
		{
			substr[l - 1] = '\0';
		}
		else substr[l] = '\0';
		cout << substr << endl;
	}
	else
	{
		system("cls");
		cout << "WTF? Write NORMAL string (with some numbers)!" << endl;
		fflush(stdin);
		ind_1();
	}
	system("pause");
}

void ind_2()
{
	char text[80], newtext[80];
	int i, l = 0;
	cin.getline(text, 40);
	for (i = 0; text[i]; i++)
	{
		if (isalpha(text[i]) || text[i] == ' ')
		{
			newtext[l] = text[i];
			l++;
		}
	}
	newtext[l] = '\0';
	cout << newtext << endl;
	system("pause");
}

void str_copy(char* str1, char* str2)
{
	int i;
	for (i = 0; i < strlen(str1); i++)
	{
		str2[i] = str1[i];
	}
	str2[i] = '\0';
	cout << "String 1: " << str1 << endl;
	cout << "String 2: " << str2 << endl;
}

void str_isequal(char* str1, char* str2)
{
	int i = 0, flag = 0;
	if (strlen(str1) != strlen(str2)) flag++;
	else while (i < strlen(str1) && flag == 0)
	{
		if (str1[i] != str2[i]) flag++;
		else i++;
	}
	if (flag == 0) cout << "The strings are the same" << endl;
	else cout << "The strings aren't the same" << endl;
}

void str_together(char* str1, char* str2)
{
	int i, k = strlen(str1);
	for (i = 0; str2[i] != '\0'; i++)
	{
		str1[i + k] = str2[i];
	}
	str1[i + k] = '\0';
	cout << "After combination: " << str1 << endl;
}

void ind_3()
{
	char str1[80], str2[80];
	int choice;
	cout << "Enter the strings: ";
	cin.getline(str1, 79);
	cin.getline(str2, 79);
	do
	{
		cout << "----------------------------------------------------------------" << endl;
		cout << "What do you want to do witn this strings?" << endl;
		cout << "1 - Copy 1 to 2" << endl;
		cout << "2 - Copy 2 to 1" << endl;
		cout << "3 - Compare" << endl;
		cout << "4 - Combine" << endl;
		cout << "5 - Exit" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
		cin.get();
		cout << "----------------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			str_copy(str1, str2);
			break;
		case 2:
			str_copy(str2, str1);
			break;
		case 3:
			str_isequal(str1, str2);
			break;
		case 4:
			str_together(str1, str2);
			break;
		case 5: break;
		default:
			cout << "Error" << endl;
			ind_3();
			break;
		}
		system("pause");
	} while (choice != 5);
}

void toright(char** a, int numStr, int numOn, int numFrom)
{
	for (int i = strlen(a[numStr]); i > numFrom; i--)
	{
		a[numStr][i + numOn] = a[numStr][i];
	}
}

void toleft(char** a, int numStr, int numOn, int numFrom)
{
	int i;
	for (i = numFrom; a[numStr][i]; i++)
	{
		a[numStr][i - numOn] = a[numStr][i];
	}
	a[numStr][i - numOn] = '\0';
}

int reform(char** a, int numStr)
{
	int check = 0;
	for (int j = 0; a[numStr][j]; j++)
	{
		switch (a[numStr][j])
		{
		case 'c':
		{
			if (a[numStr][j + 1] == 'e' || a[numStr][j + 1] == 'i' || a[numStr][j + 1] == 'y')
				a[numStr][j] = 's';
			else a[numStr][j] = 'k';
			check++;
			break;
		}
		case 'C':
		{
			if (a[numStr][j + 1] == 'e' || a[numStr][j + 1] == 'i' || a[numStr][j + 1] == 'y')
				a[numStr][j] = 'S';
			else a[numStr][j] = 'K';
			check++;
			break;
		}
		case 'q':
		{
			a[numStr][j] = 'k';
			check++;
			if (a[numStr][j + 1] == 'u') a[numStr][j + 1] = 'v';
			break;
		}
		case 'Q':
		{
			a[numStr][j] = 'K';
			check++;
			if (a[numStr][j + 1] == 'u') a[numStr][j + 1] = 'v';
			break;
		}
		case 'w':
		{
			a[numStr][j] = 'v';
			check++;
			break;
		}
		case 'W':
		{
			a[numStr][j] = 'V';
			check++;
			break;
		}
		case 'x':
		{
			toright(a, numStr, 1, j);
			a[numStr][j] = 'k';
			a[numStr][j + 1] = 's';
			check++;
			break;
		}
		case 'X':
		{
			toright(a, numStr, 1, j);
			a[numStr][j] = 'K';
			a[numStr][j + 1] = 's';
			check++;
			break;
		}
		case 'p':
		{
			if (a[numStr][j + 1] == 'h')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'f';
				check++;
			}
			break;
		}
		case 'P':
		{
			if (a[numStr][j + 1] == 'h')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'F';
				check++;
			}
			break;
		}
		case 'y':
		{
			if (a[numStr][j + 1] == 'o' && a[numStr][j + 2] == 'u')
			{
				toleft(a, numStr, 2, j + 2);
				check++;
			}
			break;
		}
		case 'Y':
		{
			if (a[numStr][j + 1] == 'o' && a[numStr][j + 2] == 'u')
			{
				toleft(a, numStr, 2, j + 2);
				a[numStr][j] = 'U';
				check++;
			}
			break;
		}
		case 'o':
		{
			if (a[numStr][j + 1] == 'o')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'u';
				check++;
			}
			break;
		}
		case 'O':
		{
			if (a[numStr][j + 1] == 'o')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'U';
				check++;
			}
			break;
		}
		case 'e':
		{
			if (a[numStr][j + 1] == 'e')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'i';
				check++;
			}
			break;
		}
		case 'E':
		{
			if (a[numStr][j + 1] == 'e')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'I';
				check++;
			}
			break;
		}
		case 't':
		{
			if (a[numStr][j + 1] == 'h')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'z';
				check++;
			}
			break;
		}
		case 'T':
		{
			if (a[numStr][j + 1] == 'h')
			{
				toleft(a, numStr, 1, j + 1);
				a[numStr][j] = 'Z';
				check++;
			}
			break;
		}
		}
	}
	return check;
}

int doublesymbol(char** a, int numStr)
{
	int check = 0;
	for (int i = 0; a[numStr][i]; i++)
	{
		if (a[numStr][i] == a[numStr][i + 1])
		{
			toleft(a, numStr, 1, i + 1);
			check++;
		}	
	}
	return check;
}

void dop_1()
{
	int l;
	int numberOfStrings = 0;

	char** a = new char*[100];
	for (int i = 0; i < 100; i++)
		a[i] = new char[100];

	cout << "Write text. To finish enter \"end input\"." << endl;
	strcpy_s(a[0], 20, "begin input");

	for (int i = 1; strcmp("end input", a[i-1]); i++) 
	{
		cin.getline(a[i], 99);
		numberOfStrings++;
	}

	for (int i = 1; i < numberOfStrings; i++)
	{
		do {
			l = reform(a, i);
			l += doublesymbol(a, i);
		} while (l != 0);
	}

	for (int i = 1; i < numberOfStrings; i++)
		cout << a[i] << endl;

	system("pause");

	for (int i = 0; i < 100; i++)
		delete[] a[i];
}

void dop_2()
{
	int t, L, res1, res2, m, k, res = 1;
	cin >> t;
	char* S1 = new char[200];
	char* S2 = new char[200];
	for (int i = 0; i < t; i++)
	{
		cin >> L >> m;
		cin >> S1;
		cin >> S2;
		if (L >= strlen(S1) + strlen(S2))
		{
			k = L - (strlen(S1) + strlen(S2));
			for (int j = 0; j < k; j++)
			{
				res = (res * 26) % m;
			}
			res *= 2;
		}
		else if (strlen(S1) > L || strlen(S2) > L)
			res = 0;
		else
		{
			res1 = 1;
			for (int j = L - strlen(S2), l = 0; S1[j] && res1; j++, l++)
			{
				if (S1[j] != S2[l]) res1 = 0;
			}
			res2 = 1;
			for (int j = L - strlen(S1), l = 0; S2[j] && res2; j++, l++)
			{
				if (S2[j] != S1[l]) res2 = 0;
			}
			res = res1 + res2;
		}
		cout << res << endl;
	}
	system("pause");
	delete[] S1, S2;
}

long long int factorial(int n)
{
	long long int f = 1;
	if ((n == 0) || (n == 1))
		f = 1;
	else for (int i = 1; i <= n; i++)
			f *= i;
	return f;
}

void dop_3()
{
	int k = 0, check, res, dev = 1;
	char* word = new char[14];
	char* difflet = new char[14];
	int* b = new int[14];
	for (int i = 0; i < 14; i++) b[i] = 1;

	cin >> word;

	for (int i = 0; i < strlen(word); i++)
	{
		check = 0;
		for (int j = 0; j < k; j++)
		{
			if (word[i] == difflet[j])
			{
				b[j]++;
				check++;
			}
		}
		if (check == 0)
		{
			difflet[k] = word[i];
			k++;
		}
	}

	for (int i = 0; i < k; i++)
	{
		dev *= factorial(b[i]);
	}

	res = factorial(strlen(word)) / dev;

	cout << res;
	system("pause");
}

int main()
{
	int a, all;
	cout << "Lab #7." << endl;
	Sleep(1000);
	do
	{
		system("cls");
		cout << "1. Individual tasks" << endl;
		cout << "2. Additional* tasks" << endl;
		cout << "3. Exit the program" << endl;
		do {
			cout << "Choose the variant: ";
			(cin >> a).get();
		} while (a<1 || a>3);
		switch (a)
		{
		case 1:
		{
			do
			{
				system("cls");
				cout << "Choose the task (1 - 3): ";
				(cin >> all).get();
				switch (all)
				{
				case 1:
				{
					system("cls");
					ind_1();
					break;
				}
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
				(cin >> all).get();
				switch (all)
				{
				case 1:
					system("cls");
					dop_1();
					break;

				case 2:
					system("cls");
					dop_2();
					break;

				case 3:
					system("cls");
					dop_3();
					break;

				default:
					break;
				}
			} while (all < 1 || all > 3);
			break;
		}
		}
	} while (a != 3);

	return 0;
}
