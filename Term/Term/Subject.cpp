#include <iostream>
#include "Student.h"
#include "Teachers.h"

#define FORMS "1-A 2-A 3-A 4-A 5-A 6-A 7-A 8-A 9-A 10-A 11-A 1-B 2-B 3-B 4-B 5-B 6-B 7-B 8-B 9-B 10-B 11-B 1-C 2-C 3-C 4-C 5-C 6-C 7-C 8-C 9-C 10-C 11-C\
1A 2A 3A 4A 5A 6A 7A 8A 9A 10A 11A 1B 2B 3B 4B 5B 6B 7B 8B 9B 10B 11B 1C 2C 3C 4C 5C 6C 7C 8C 9C 10C 11C\
1-a 2 3-a 4-a 5-a 6-a 7-a 8-a 9-a 10-a 11-a 1-b 2-b 3-b 4-b 5-b 6-b 7-b 8-b 9-b 10-b 11-b 1-c 2-c 3-c 4-c 5-c 6-c 7-c 8-c 9-c 10-c 11-c 1a 2a 3a 4a 5a 6a 7a 8a 9a 10a 11a\
1b 2b 3b 4b 5b 6b 7b 8b 9b 10b 11b 1c 2c 3c 4c 5c 6c 7c 8c 9c 10c 11c e"

using namespace std;

int SubjectsSubMenu()
{
	system("cls");
	int menuOption;
	cout << "\tSUBJECTS\n";
	cout << "===========================\n";
	cout << "|1. Show all subjects     |\n";
	cout << "|2. Show current subjects |\n";
	cout << "|3. Add new subject       |\n";
	cout << "|4. Remove subject        |\n";
	cout << "===========================\n";
	cin >> menuOption;
	return menuOption;
}

void ShowCurrentSubject(char* arr[], int size, int sizeTeachers, Teacher teacherArr[], int sizeStudents, Student studentArr[])
{

	char subject[25];
	cout << "Input subject that you want to see\n";
	cin.ignore();
	cin.getline(subject, 25);

	int lastIndex;
	char isShow[300] = " ";

	for (int i = 0; i < sizeStudents; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (studentArr[i].subject[j] == NULL)
			{
				lastIndex = j;
				break;
			}
		}

		for (int j = 0; j < lastIndex; j++)
		{
			if (strcmp(studentArr[i].subject[j], subject) == 0)
			{
				if (strstr(isShow, studentArr[i].form) == nullptr)
				{
					cout << studentArr[i].form << " ";
					strcat_s(isShow, 300, studentArr[i].form);
					break;
				}
			}
		}

	}
	cout << endl;

	/*for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n  Teachers: ";
		for (int j = 0; j < sizeTeachers; j++)
		{
			if (strcmp(teacherArr[j].subject, arr[i]) == 0)
				cout << teacherArr[j].surname << " ";
		}
		cout << "\n";

		int lastIndex;

		for (int j = 0; j < 20; j++)
		{
			if (studentArr[j].subject[i] != NULL)
			{
				lastIndex = j;
				break;
			}
		}

		cout << "\tForms: ";
		for (int j = 0; j <= lastIndex; j++)
		{
			if (strcmp(studentArr[i].subject[j], arr[i]) == 0)
				cout << studentArr[j].form << " ";
		}

		cout << "\n\n";
	}*/
}

void ShowAllSubject(char* arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
}

char** AddSubject(char* arr[], int size, int sizeTeacher, Teacher arrTeacher[], int sizeStudents, Student studentsArr[])
{
	char subject[25];

	//Add new subject
	cout << "Input name of new subject: \n";
	cin.ignore();
	cin.getline(subject, 25);
	if (subject[0] >= 97 && subject[0] <= 122)
		subject[0] = int(subject[0]) - 32;

	//Add new form
	char form[5];
	do
	{
		cout << "Input e to exit and countine add subject\n";

		bool isE = false;

		do
		{
			cout << "Input form: ";
			cin >> form;

			if (form[0] == 'e')
			{
				isE = true;
				break;
			}

			if (strstr(FORMS, form) == nullptr)
				cout << "Input right form\n";

		} while (strstr(FORMS, form) == nullptr);

		if (isE == false)
		{
			ConvertForm(form);

			int indexToPaste;

			for (int i = 0; i < sizeStudents; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (studentsArr[i].subject[j] == NULL)
					{
						indexToPaste = j;
						break;
					}
				}
				if (strcmp(form, studentsArr[i].form) == 0)
					//strcpy_s(studentsArr[i].subject[indexToPaste], 25, subject);
					studentsArr[i].subject[indexToPaste] = subject;
			}
		}

	} while (form[0] != 'e');

	// Add new Teacher
	bool isFoundTeacher = false;
	do
	{
		cin.ignore();

		Teacher teacher;
		do
		{

			cout << "Input e to exit and countine add subject: \n";

			cout << "Input teacher name: \n";
			cin >> teacher.name;

			if (teacher.name[0] == 'e')
				break;

			cout << "Input teacher surname: \n";
			cin >> teacher.surname;

			if (teacher.surname[0] == 'e')
				break;

			int IndexToEdit = -1;



			for (int i = 0; i < size; i++)
			{
				if (strstr(teacher.name, arrTeacher[i].name) != nullptr)
				{
					if (strstr(teacher.surname, arrTeacher[i].surname) != nullptr)
					{
						IndexToEdit = i;
						break;
					}
				}
			}

			if (IndexToEdit != -1)
				isFoundTeacher = true;
			else
				cout << "Teacher isn't indefined\n";

			/*for (int i = 0; i < sizeTeacher; i++)
			{
				if (strstr(arrTeacher[i].surname, teacher) != 0)
				{
					isFoundSubject = true;
					teacherIndex = i;
					break;
				}
			}*/

			if (isFoundTeacher == true)
			{
				strcpy_s(arrTeacher[IndexToEdit].subject, 25, subject);
			}

		} while (teacher.name[0] != 'e' || teacher.surname[0] != 'e');

	} while (isFoundTeacher == false);

	//Create array
	//arr = (char**)realloc(arr, size);
	char** newArr = new char* [size];

	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];

	//arr[0] = subject;

	//strcpy_s(arr[size - 1], 25, subject);
	newArr[size - 1] = subject;

	delete[] arr;
	arr = nullptr;

	return newArr;

}

//char** DeleteSubject(char* arr[], int* size, int sizeTeacher, Teacher arrTeacher[], int sizeStudents, Student studentsArr[])
//{
//	char subjectToDelete[25];
//	cout << "Input subject that you want to remove: ";
//	cin.getline(subjectToDelete, 25);
//	int IndexToDelete = -1;
//	for (int i = 0; i < size; i++)
//	{
//		if (strcmp(arr[i], subjectToDelete) == 0)
//		{
//			IndexToDelete = i;
//			break;
//		}
//	}
//
//	if (IndexToDelete != -1)
//	{
//		*size = *size - 1;
//		char** newArr = new char* [*size];
//
//		for (int i = 0; i < *size + 1; i++)
//		{
//			if (i < IndexToDelete)
//				newArr[i] = arr[i];
//
//			else if (i > IndexToDelete)
//				newArr[i - 1] = arr[i];
//		}
//		delete[] arr;
//		arr = nullptr;
//		return newArr;
//	}
//	else
//	{
//		cout << "Subject not indefined\n";
//		return arr;
//	}
//}