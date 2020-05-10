#include <iostream>
#include "Teachers.h"

using namespace std;

void TeachersSubMenu(Teacher teachersArr[], int* size)
{
	int menuOption;
	do
	{
		system("cls");
		cout << "\tTEACHERS\n";
		cout << "=======================\n";
		cout << "|1. Show all teachers |\n";
		cout << "|2. Add new teacher   |\n";
		cout << "|3. Remove teacher    |\n";
		cout << "|4. Sort teachers     |\n";
		cout << "|5. Edit teacher      |\n";
		cout << "|6. Exit              |\n";
		cout << "=======================\n";
		cout << "Input option: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			system("cls");
			ShowAllTeachers(teachersArr, *size);
			system("pause");
			break;
		case 2:
			system("cls");
			teachersArr = AddTeacher(teachersArr, size);
			break;
		case 3:
			system("cls");
			teachersArr = DeleteTeacher(teachersArr, size);
			break;
		case 4:
			SortTeachers(teachersArr, *size);
			break;
		case 5:
			EditTeacher(teachersArr, *size);
			break;
		case 6: 
			return; 
		default:
			cout << "You input invalid value, try again\n";
			system("pause");
			system("cls");
		}
	} while (menuOption != 6);

}

void ShowAllTeachers(const Teacher const teacher[], int size)
{
	if (teacher[0].name[0] < 65 || teacher[0].name[0] > 90 || teacher[0].surname[0] < 65 || teacher[0].surname[0] > 90)
	{
		cout << "You haven't any teacher\n";
		return;
	}

	cout << "¹  Surname  Name\tAge\t  Mail\n";
	cout << "------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << teacher[i].surname << "  ";
		cout << teacher[i].name << "\t\t";
		cout << teacher[i].age << "\t";
		cout << teacher[i].mail << "\t";
		cout << endl;
	}

}

Teacher* AddTeacher(Teacher arr[], int* size)
{
	Teacher teacher;

	*size = *size + 1;

	cout << "Input teacher name: ";
	cin.ignore();
	cin.getline(teacher.name, 25);
	if (teacher.name[0] >= 97 && teacher.name[0] <= 122)
		teacher.name[0] = int(teacher.name[0]) - 32;

	cout << "Input teacher surname: ";
	cin.getline(teacher.surname, 25);
	if (teacher.surname[0] >= 97 && teacher.surname[0] <= 122)
		teacher.surname[0] = int(teacher.surname[0]) - 32;

	do
	{
		cout << "Input teacher age: ";
		scanf_s("%d", &teacher.age);
		cin.ignore();
		if (teacher.age <= 17 || teacher.age >= 75)
			cout << "Error, input right age\n";
	} while (teacher.age <= 17 || teacher.age >= 75);

	GetMail(teacher.mail);

	Teacher* newArr = new Teacher[*size];

	for (int i = 0; i < *size - 1; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = nullptr;

	newArr[*size - 1] = teacher;

	cout << "\nTeacher are succesfully added\n";
	system("pause");

	return newArr;

}

Teacher* DeleteTeacher(Teacher arr[], int* size)
{
	int IndexToDelete = FoundTeacher(arr, *size);

	if (IndexToDelete != -1)
	{
		*size = *size - 1;
		Teacher* newArr = new Teacher[*size];

		for (int i = 0; i < *size + 1; i++)
		{
			if (i < IndexToDelete)
				newArr[i] = arr[i];

			else if (i > IndexToDelete)
				newArr[i - 1] = arr[i];
		}
		delete[] arr;
		arr = nullptr;
		cout << "\nTeacher are succesfully removed\n";
		system("pause");
		return newArr;
	}
	else
	{
		cout << "Teacher not indefined\n";
		return arr;
	}

}

void SortTeachers(Teacher arr[], int size)
{
	if (arr[0].name[0] < 65 || arr[0].name[0] > 90 || arr[0].surname[0] < 65 || arr[0].surname[0] > 90)
	{
		cout << "You haven't any teacher!\n";
		return;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{

			if (strcmp(arr[i].surname, arr[j].surname) > 0)
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].surname, arr[i + 1].surname) == 0)
		{
			if (strcmp(arr[i].name, arr[i + 1].name) > 0)
			{
				swap(arr[i], arr[i + 1]);
			}

		}
	}

	cout << "\nTeacher are succesfully sorted\n";
	system("pause");
}

void EditTeacher(Teacher arr[], int size)
{
	int indexToEdit = -1;
	do
	{
		indexToEdit = FoundTeacher(arr, size);
		if (indexToEdit == -1)
		{
			cout << "Teacher not indefined\n";
		}
	} while (indexToEdit == -1);

	int option = 0;
	do
	{
		system("cls");
		option = ShowEditMenu();

		switch (option)
		{
		case 1:
			system("cls");
			char name[25];
			cout << "Input new teacher name: ";
			cin >> name;
			strcpy_s(arr[indexToEdit].name, 25, name);
			break;
		case 2:
			system("cls");
			char surname[25];
			cout << "Input new teacher surname: ";
			cin >> surname;
			strcpy_s(arr[indexToEdit].surname, 25, surname);
			break;
		case 3:
			system("cls");
			int age;

			do {
				cout << "Input new teacher's age: ";
				cin.ignore();
				cin >> age;
				if (age <= 17 || age >= 75 || isalpha(age))
					cout << "Error, input right age\n";

			} while (age <= 17 || age >= 75 || isalpha(age));

			arr[indexToEdit].age = age;
			break;

		case 4:
			system("cls");
			char mail[25];
			cin.ignore();
			GetMail(mail);
			strcpy_s(arr[indexToEdit].mail, 25, mail);
			break;

		case 5:
			system("cls");
			cout << "Changes are succesfully added\n";
			system("pause");
			system("cls");
			return;

		default:
			system("cls");
			cout << "Input right number, please\n";
		}
	} while (option != 5);
}

int ShowEditMenu()
{
	cout << " Editing teacher\n";
	cout << "==================\n";
	cout << "|1. Edit name    |\n";
	cout << "|2. Edit surname |\n";
	cout << "|3. Edit age     |\n";
	cout << "|4. Edit mail    |\n";
	cout << "|5. Exit         |\n";
	cout << "==================\n";
	cout << "Input what you want to edit: ";
	int option;
	cin >> option;
	return option;
}

void GetMail(char arr[40])
{
	bool isMail = false;
	do
	{
		cout << "Input teacher mail: ";
		cin.getline(arr, 40);

		for (int i = 0; i < strlen(arr) || i < 40 || arr[i] == '\0'; i++)
			if (arr[i] == '@')
			{
				isMail = true;
				break;
			}

		if (isMail == false)
			cout << "Input right mail!!\n";

	} while (isMail == false);
}

int FoundTeacher(const Teacher const arr[], int size)
{
	Teacher teacher;

	if (arr[0].name[0] < 65 || arr[0].name[0] > 90 || arr[0].surname[0] < 65 || arr[0].surname[0] > 90)
	{
		system("cls");
		cout << "You haven't any teacher!\n";
	}
	else
	{
		system("cls");
		cout << "Input teacher name: ";
		cin >> teacher.name;
		if (teacher.name[0] >= 97 && teacher.name[0] <= 122)
			teacher.name[0] = int(teacher.name[0]) - 32;
		cout << "Input teacher surname: ";
		cin >> teacher.surname;
		if (teacher.surname[0] >= 97 && teacher.surname[0] <= 122)
			teacher.surname[0] = int(teacher.surname[0]) - 32;


		int IndexToEdit = -1;

		for (int i = 0; i < size; i++)
		{
			if (strcmp(teacher.name, arr[i].name) == 0)
			{
				if (strcmp(teacher.surname, arr[i].surname) == 0)
				{
					IndexToEdit = i;
					break;
				}
			}
		}

		return IndexToEdit;
	}

}