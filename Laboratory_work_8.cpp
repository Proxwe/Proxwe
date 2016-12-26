#include<iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;

int amount = 0;

struct sport_inf {
	char lastname[20]; 
	char name[20];
	char fathername[20];
	char country[20];
	char team[20];
	int number;
	int age;
	double weight;
	double height;
};

sport_inf* addstruct(sport_inf* part);
void input(sport_inf* part, int i);
int menu();
void oldest(sport_inf* part);
sport_inf* enter(sport_inf* part);
void update(sport_inf* part);
void display(const sport_inf* part);
void sort_shell(sport_inf* part);

sport_inf* addstruct(sport_inf* part)
{
	if (amount == 0)
	{
		part = new sport_inf[amount + 1];
	}
	else
	{
		sport_inf* temppart = new sport_inf[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			temppart[i] = part[i];
		}
		delete[] part;

		part = temppart;
	}
	return part;
}

void input(sport_inf* part, int i)
{
	cout << "Last name: ";
	cin >> part[i].lastname;
	cout << "Name: ";
	cin >> part[i].name;
	cout << "Father name: ";
	cin >> part[i].fathername;
	cout << "Country: ";
	cin >> part[i].country;
	cout << "Team: ";
	cin >> part[i].team;
	cout << "Number: ";
	cin >> part[i].number;
	cout << "Age: ";
	cin >> part[i].age;
	cout << "Weight: ";
	cin >> part[i].weight;
	cout << "Height: ";
	cin >> part[i].height;
}

int menu()
{
	system("cls");
	char ch;
	do {
		cout << "Information of competitors\n\n";
		cout << "(E)nter\n"; 
		cout << "(D)isplay\n"; 
		cout << "(U)pdate\n";
		cout << "(O)ldest\n";
		cout << "(S)earch\n";
		cout << "(Q)uit\n\n";
		cout << "Select instruction: ";
		cin >> ch;
	} while (!strchr("eduosq", tolower(ch)));
	return tolower(ch);
}

sport_inf* enter(sport_inf* part)
{
	system("cls");
	char YesOrNot;
	do
	{
		part = addstruct(part);
		input(part, amount);
		amount++;

		cout << "Do you want to continue the entering of data: Y/N: ";
		(cin >> YesOrNot).get();
	} while (YesOrNot != 'N' && YesOrNot != 'n');
	return part;
}

void update(sport_inf* part)
{
	system("cls");
	int i;
	char lastname[40];
	cout << "Enter the lastname of the participant: ";
	cin >> lastname;
	for (i = 0; i < amount; i++)
		if (!strcmp(lastname, part[i].lastname)) break;
	if (i == amount) 
	{
		cout << "The participant isn't found.\n";
		system("pause");
		return;
	}
	cout << "Enter the new information\n";
	input(part, i);
}

void display(sport_inf* part)
{
	system("cls");
	int j, i, k;
	cout << setw(15) << "Lastname:" << '|';
	cout << setw(15) << "Name:" << '|';
	cout << setw(15) << "Fathername:" << '|';
	cout << setw(15) << "Country:" << '|';
	cout << setw(15) << "Team:" << '|';
	cout << setw(15) << "Number:" << '|';
	cout << setw(15) << "Age:" << '|';
	cout << setw(15) << "Weight:" << '|';
	cout << setw(15) << "Growth:" << '|';
	cout << '\n';
	for (j = 0; j < 9; j++)
	{
		for (k = 0; k < 15; k++) cout << '=';
		cout << '|';
	}
	cout << '\n';
	for (i = 0; i < amount; i++) 
	{
		cout << setw(15) << part[i].lastname << '|';
		cout << setw(15) << part[i].name << '|';
		cout << setw(15) << part[i].fathername << '|';
		cout << setw(15) << part[i].country << '|';
		cout << setw(15) << part[i].team << '|';
		cout << setw(15) << part[i].number << '|';
		cout << setw(15) << part[i].age << '|';
		cout << setw(15) << part[i].weight << '|';
		cout << setw(15) << part[i].height << '|';
		cout << '\n';
		for (j = 0; j < 9; j++)
		{
			for (k = 0; k < 15; k++) cout << '-';
			cout << '|';
		}
		cout << '\n';
	}
	system("pause");
}

void oldest(sport_inf* part)
{
	int i;
	system("cls");
	cout << "The lastnames of sportsmen over 20 years old: \n";
	sort_shell(part);
	for (i = 0; part[i].age > 20; i++)
		cout << part[i].lastname <<  " - " << part[i].age << "years old\n";
	if(i == 0) cout << "Those participants aren't found.\n";
	system("pause");
}

void sort_shell(sport_inf* part)
{
	int step = amount;
	int j, i;
	sport_inf temp;
	while (step > 0)
	{
		for (i = 0; i < (amount - step); i++)
		{
			j = i;
			while (j >= 0 && part[j].age < part[j + step].age)
			{
				temp = part[j];
				part[j] = part[j + step];
				part[j + step] = temp;
				j--;
			}
		}
		step = step / 2;
	}
}

void search(sport_inf* part)
{
	system("cls");
	int i, flag = 0;
	char country[40];
	cout << "Enter a country: \n";
	cin >> country;
	for (i = 0; i < amount; i++)
		if (!strcmp(country, part[i].country))
		{
			cout << part[i].lastname << ' ' << part[i].name <<  " from " << part[i].country << '\n';
			flag++;
		}
	if (i == amount && flag == 0) 
	{
		cout << "Those participants aren't found.\n";
		system("pause");
		return;
	}
	system("pause");
}

int main()
{
	cout << "Lab#8 by Glotov Artem";
	Sleep(1000);
	int amount = 0;
	char choice;
	sport_inf* part = 0;
	for (;;) 
	{
		choice = menu();
		switch (choice) 
		{
		case 'e': part = enter(part);
			break;
		case 'd': display(part);
			break;
		case 'u': update(part);
			break;
		case 'o': oldest(part);
			break;
		case 's': search(part);
			break;
		case 'q': return 0;
		}
	}
	delete[] part;
}