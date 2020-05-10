#include <iostream>
#include "Subject.h"
using namespace std;

void SubjectsSubMenu(char* arr[], int* size)
{
	system("cls");
	int menuOption;
	do
	{
		system("cls");
		cout << "\tSUBJECTS\n";
		cout << "===========================\n";
		cout << "|1. Show all subjects     |\n";
		cout << "|2. Show current subjects |\n";
		cout << "|3. Add new subject       |\n";
		cout << "|4. Remove subject        |\n";
		cout << "|5. Sort subjects         |\n";
		cout << "|6. Edit subjects         |\n";
		cout << "|7. Exit                  |\n";
		cout << "===========================\n";
		cout << "Input option: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			system("cls");
			ShowAllSubject(arr, *size);
			break;

		case 2:
			system("cls");
			cout << "Will be soon\n";
			system("pause");
			break;

		case 3:
			system("cls");
			*arr = AddSubject(*arr, size);
			break;

		case 4:
			system("cls");
			DeleteSubject(*arr, size);
			system("pause");
			system("cls");
			break;

		case 5:
			system("cls");
			cout << "Will be soon\n";
			system("pause");
			break;

		case 6:
			system("cls");
			cout << "Will be soon\n";
			system("pause");
			break;

		case 7:
			return;
		}
	} while (menuOption != 7);
}

void ShowAllSubject(char* arr[], int size)
{
	if (size == 0)
	{
		cout << "You haven't any subject!\n";
		system("pause");
		return;
	}

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << arr[i] << endl;
	}
	system("pause");
	system("cls");
}

char* AddSubject(char arr[], int* size)
{
	if (*size >= 1)
	{
		cout << "You can add one more subjects soon\n";
		system("pause");
		return arr;
	}

	*size = *size + 1;

	char subject[25];

	cout << "Input name of new subject: ";
	cin.ignore();
	cin.getline(subject, 25);

	if (subject[0] >= 97 && subject[0] <= 122)
		subject[0] = int(subject[0]) - 32;

	char* newArr = new char[25];

	strcpy_s(newArr, 25, subject);

	return newArr;
}

void DeleteSubject(char arr[], int* size)
{
	if (*size == 0)
	{
		cout << "You haven't subject\n";
		system("pause");
		return;
	}

	*size = *size - 1;

	arr = nullptr;

	cout << "Subject are succesfully deleted\n";
}

