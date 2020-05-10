#include <iostream>
#include "Teachers.h"
#include "Subject.h"

using namespace std;

void TeachersSubMenu(Teacher teachersArr[], int* size, int sizeSubject, char* arrSubject[])
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
		//cin.ignore();
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
			*size = *size + 1;
			teachersArr = AddTeacher(teachersArr, *size, sizeSubject, arrSubject);
			//teachersArr = AddTeacher(teachersArr, sizeTeacher);
			break;
		case 3:
			system("cls");
			teachersArr = DeleteTeacher(teachersArr, size);
			break;
		case 4:
			SortTeachers(teachersArr, *size);
			break;
		case 5:
			EditTeacher(teachersArr, *size, sizeSubject, arrSubject);
			break;
		default:
			cout << "You input invalid value, try again\n";
			//	system("pause");
			//	system("cls");
		}
	} while (menuOption != 6);

}

void ShowAllTeachers(Teacher teacher[], int size)
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
		cout << teacher[i].name << "\t  ";
		cout << teacher[i].age << "\t";
		cout << teacher[i].mail << "\t";
		if (teacher[i].subject != nullptr)// != nullptr)// > 65 || *teacher[i].subject < 90)
			cout << teacher[i].subject << "|\n";
		cout << endl;
	}
	
}

Teacher* AddTeacher(Teacher arr[], int size, int sizeSubject, char* arrSubject[])
{
	Teacher teacher;

	cout << "Input teacher name: ";
	cin.ignore();
	cin.getline(teacher.name, 25);
	if (teacher.name[0] >= 97 && teacher.name[0] <= 122)
		teacher.name[0] = int(teacher.name[0]) - 32;

	cout << "Input teacher surname: ";
	//cin.ignore();
	cin.getline(teacher.surname, 25);
	if (teacher.surname[0] >= 97 && teacher.surname[0] <= 122)
		teacher.surname[0] = int(teacher.surname[0]) - 32;

	do
	{
		cout << "Input teacher age: ";
		scanf_s("%d", &teacher.age);
		//cin >> teacher.age;
		cin.ignore();
		if (teacher.age <= 17 || teacher.age >= 75)
			cout << "Error, input right age\n";
	} while (teacher.age <= 17 || teacher.age >= 75);

	GetMail(teacher.mail);

	if (arrSubject[0])
	{
		teacher.subject = nullptr;
		cout << "You haven't subject's, add subject and edit teacher soon\n";
	}
	else
	{

		bool isFoundSubject = false;
		do {
			cout << "Input teacher's subject: ";
			char subject[20] = " ";
			//cin.ignore();
			cin.getline(subject, 20);

			if (subject[0] >= 97 && subject[0] <= 122)
				subject[0] = int(subject[0]) - 32;

			int subjectIndex;
			for (int i = 0; i < sizeSubject; i++)
			{
				if (strcmp(arrSubject[i], subject) == 0)
				{
					isFoundSubject = true;
					subjectIndex = i;
					break;
				}
			}

			if (isFoundSubject == true)
			{
				*teacher.subject = arrSubject[subjectIndex];
			}

			else
				cout << "Error, input right subject\n";

		} while (isFoundSubject == false);
	}
	Teacher* newArr = new Teacher[size];

	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = nullptr;

	newArr[size - 1] = teacher;

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

void EditTeacher(Teacher arr[], int size, int sizeSubject, char* arrSubject[])
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
				cin >> age;
				if (age <= 17 || age >= 75)
					cout << "Error, input right age\n";

			} while (age <= 17 || age >= 75);

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
		{
			system("cls");
			if (arrSubject[0])
			{
				cout << "You haven't subject's, add subject and edit teacher soon\n ";
			}
			else
			{
				bool isFoundSubject = false;
				do {
					cout << "Input new teacher's subject: \n";
					char subject[20] = " ";
					cin.ignore();
					cin.getline(subject, 20);

					if (subject[0] >= 97 && subject[0] <= 122)
						subject[0] = int(subject[0]) - 32;

					int subjectIndex;
					for (int i = 0; i < sizeSubject; i++)
					{
						if (strcmp(arrSubject[i], subject) == 0)
						{
							isFoundSubject = true;
							subjectIndex = i;
							break;
						}
					}

					if (isFoundSubject == true)
					{
						*arr[indexToEdit].subject = arrSubject[subjectIndex];
					}

					else
						cout << "Error, input right subject\n";

				} while (isFoundSubject == false);
				break;
			}
			break;
		}

		case 6:
			system("cls");
			cout << "Changes are succesfully added\n";
			system("pause");
			system("cls");
			return;
		default:
			system("cls");
			cout << "Input right number please\n";
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
	cout << "|5. Edit subject |\n";
	cout << "|6. Exit         |\n";
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

int FoundTeacher(Teacher arr[], int size)
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