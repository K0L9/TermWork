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

	cout << "Input teacher surname: \n";
	//cin.ignore();
	cin.getline(teacher.surname, 25);

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

	newArr[size - 1] = teacher;
	//arr[size - 1] = teacher;
	//system("pause");
	return newArr;

}

Teacher* DeleteTeacher(Teacher arr[], int* size)
{
	Teacher teacher;

	cout << "Input teacher name: \n";
	cin >> teacher.name;
	cout << "Input teacher surname: \n";
	cin >> teacher.surname;


	Teacher* newArr = new Teacher[*size];
	int IndexToDelete;
	bool isFound = false;

	for (int i = 0; i < *size; i++)
	{
		if (strstr(teacher.name, arr[i].name) != nullptr)
		{
			if (strstr(teacher.surname, arr[i].surname) != nullptr)
			{
				isFound = true;
				IndexToDelete = i;
				break;
			}
		}
	}

	if (isFound == true)
	{
		*size = *size - 1;
		Teacher* newArr = new Teacher[*size];
	}
	else
	{
		cout << "Teacher not indefined\n";
		return arr;
	}

	for (int i = 0; i < *size + 1; i++)
	{
		if (i < IndexToDelete)
			newArr[i] = arr[i];

		else if (i > IndexToDelete)
			newArr[i - 1] = arr[i];
	}
	return newArr;
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

	for (size_t i = 0; i < size - 1; i++)
	{
		Teacher temp = arr[i];
		for (size_t j = i + 1; j < size; j++)
		{
			//for (int k = 0; k < strlen(arr[i].name) || k < strlen(arr[j].name); k++)
			//{
			if (arr[i].surname[0] > arr[j].surname[0])
			{
				swap(arr[i], arr[j]);
				//temp = arr[i];
				//arr[i] = arr[j];
				//arr[j] = temp;
			}
			/*else if (arr[i].name[k] == arr[j].name[k])
			{
				if (arr[i].name[k+1] > arr[j].name[k+1])
				{
					swap(arr[i], arr[j]);
				}*/
				//}
			//}
		}
	}
}
