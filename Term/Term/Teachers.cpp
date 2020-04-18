#include <iostream>
#include "Teachers.h"

using namespace std;

void ShowAllTeachers(Teacher teacher[], size_t size)
{
	//cout << "\tName\t Surnmame\t Age\t mail\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << teacher[i].surname;
		cout << "\t";
		cout << teacher[i].name;
		cout << "\t"; // << teacher[i].age << "\t" << teacher[i].mail << endl;
		cout << teacher[i].age;
		cout << "\t";
		cout << teacher[i].mail << endl;

		//cout << teacher[i].surname << "\t";
		//cout << teacher[i].age << "\t";
		//cout << teacher[i].mail << endl;
	}
}

Teacher* AddTeacher(Teacher arr[], int size)
{
	Teacher teacher;

	cout << "Input teacher name: \n";
	cin.ignore();
	cin.getline(teacher.name, 25);
	if (teacher.name[0] >= 97 && teacher.name[0] <= 122)
		teacher.name[0] = int(teacher.name[0]) - 32;


	cout << "Input teacher surname: \n";
	//cin.ignore();
	cin.getline(teacher.surname, 25);
	if (teacher.surname[0] >= 97 && teacher.surname[0] <= 122)
		teacher.surname[0] = int(teacher.surname[0]) - 32;

	do {
		cout << "Input teacher age: \n";
		//cin.ignore();
		cin >> teacher.age;
		if (teacher.age <= 17 || teacher.age >= 75)
			cout << "Error, input right age\n";
	} while (teacher.age <= 17 || teacher.age >= 75);

	cout << "Input teacher mail: \n";
	cin.ignore();
	cin.getline(teacher.mail, 40);

	//cout << "Input subject, that this teacher will be hold: \n";
	//cin >> teacher.subject;

	//arr = (Teacher*)realloc(arr, size);
	Teacher* newArr = new Teacher[size];

	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = nullptr;

	newArr[size - 1] = teacher;
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

		return newArr;
	}
	else
	{
		cout << "Teacher not indefined\n";
		return arr;
	}

}

int TeachersSubMenu()
{
	int menuOption;
	cout << "\tTEACHERS\n";
	cout << "=======================\n";
	cout << "|1. Show all teachers |\n";
	cout << "|2. Add new teacher   |\n";
	cout << "|3. Remove teacher    |\n";
	cout << "|4. Sort teachers     |\n";
	cout << "|5. Rename teacher    |\n";
	cout << "=======================\n";
	cin.ignore();
	cin >> menuOption;
	return menuOption;
}


void SortTeachers(Teacher arr[], int size)
{
	//for (int i = 0; i < size; i++)
	//{
	//	for (int j = size - 1; j > i; j--)
	//	{
	//		if (arr[i].name[j - 1] > arr[i+1].name[j])
	//		{
	//			swap(arr[i], arr[j]);
	//			//T temp = arr[j - 1];
	//			//arr[j - 1] = arr[j];
	//			//arr[j] = temp;
	//		}
	//	}
	//}

	/*for (int i = 0; i < size; i++)
	{
		if (strstr(arr[i].surname, arr[i+1].surname) != 0)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = size - 1; j > i; j--)
				{
					if (arr->surname[j - 1] < arr->surname[j])
					{
						swap(arr[i], arr[j]);
					}
				}
			}
		}
	}*/

	//for (size_t i = 0; i < size - 1; i++)
	//{
	//	//Teacher temp = arr[i];
	//	for (size_t j = i + 1; j < size; j++)
	//	{
	//		for (int k = 0; k < strlen(arr[i].surname) || k < strlen(arr[j].surname); )
	//		{
	//			if (arr[i].surname[0] > arr[j].surname[0])
	//			{
	//				swap(arr[i], arr[j]);
	//				break;
	//			}

	//			else if (arr[i].surname[k] == arr[j].surname[k])
	//			{
	//				k++;
	//				if (arr[i].surname[k] > arr[j].surname[k])
	//				{
	//					swap(arr[i], arr[j]);
	//				}
	//			}
	//		}
	//	}
	//}

	/*for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].surname, arr[i + 1].surname) < 0)
			swap(arr[i], arr[i + 1]);
	}*/

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{

			if (strcmp(arr[i].surname, arr[j].surname) > 0)
			{
				swap(arr[i], arr[j]);
			}

		}
	}
}




void EditTeacher(Teacher arr[], size_t size)
{
	int indexToEdit;
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
		option = ShowEditMenu();

		switch (option)
		{
		case 1:
			char name[25];
			cout << "Input new teacher name\n";
			cin >> name;
			strcpy_s(arr[indexToEdit].name, 25, name);
			break;
		case 2:
			char surname[25];
			cout << "Input new teacher surname\n";
			cin >> surname;
			strcpy_s(arr[indexToEdit].surname, 25, surname);
			break;
		case 3:
			int age;

			do {
				cout << "Input new teacher's age: \n";
				cin >> age;
				if (age <= 17 || age >= 75)
					cout << "Error, input right age\n";

			} while (age <= 17 || age >= 75);

			arr[indexToEdit].age = age;
			break;

		case 4:
			char mail[25];
			cout << "Input new teacher mail\n";
			cin >> mail;
			strcpy_s(arr[indexToEdit].mail, 25, mail);
			break;
		case 5:
			cout << "Changes are succesfully added\n";
			return;
		default:
			cout << "Input right number please\n";
		}
	} while (option != 5);
}

int ShowEditMenu()
{
	cout << "=================\n";
	cout << "|1. Edit name   |\n";
	cout << "|2. Edit surname|\n";
	cout << "|3. Edit age    |\n";
	cout << "|4. Edit mail   |\n";
	cout << "|5. Exit        |\n";
	cout << "=================\n";
	cout << "Input what you want to edit: ";
	int option;
	cin >> option;
	return option;
}

int FoundTeacher(Teacher arr[], int size)
{
	Teacher teacher;

	cout << "Input teacher name: \n";
	cin >> teacher.name;
	cout << "Input teacher surname: \n";
	cin >> teacher.surname;


	int IndexToEdit = -1;

	for (int i = 0; i < size; i++)
	{
		if (strstr(teacher.name, arr[i].name) != nullptr)
		{
			if (strstr(teacher.surname, arr[i].surname) != nullptr)
			{
				IndexToEdit = i;
				break;
			}
		}
	}

	return IndexToEdit;
}