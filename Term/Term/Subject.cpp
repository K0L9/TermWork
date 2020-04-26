#include <iostream>
#include "Teachers.h"

using namespace std;

int SubjectsSubMenu()
{
	system("cls");
	int menuOption;
	cout << "\tSUBJECTS\n";
	cout << "=======================\n";
	cout << "|1. Show all subjects |\n";
	cout << "|2. Add new subject   |\n";
	cout << "|3. Remove subject    |\n";
	cout << "=======================\n";
	cin >> menuOption;
	return menuOption;
}

void ShowAllSubject(Subject arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].name << " ";
		cout << arr[i].forms << " ";
		cout << arr[i].teacher << endl;
	}
}

Subject* AddSubject(Subject arr[], int size, int sizeTeacher, Teacher arrTeacher[])
{
	Subject subject;

	cout << "Input subject: \n";
	cin.ignore();
	cin.getline(subject.name, 25);
	if (subject.name[0] >= 97 && subject.name[0] <= 122)
		subject.name[0] = int(subject.name[0]) - 32;


	cout << "Input subject form: \n";
	cin.getline(subject.forms, 25);

	bool isFoundSubject = false;
	do {
		cout << "Input subject's teacher: \n";
		char teacher[20] = " ";
		cin.ignore();
		cin.getline(teacher, 20);
		int teacherIndex;
		for (int i = 0; i < sizeTeacher; i++)
		{
			if (strstr(arrTeacher[i].surname, teacher) != 0)
			{
				isFoundSubject = true;
				teacherIndex = i;
				break;
			}
		}

		if (isFoundSubject == true)
		{
			*subject.teacher = arrTeacher[teacherIndex].surname;
		}
		else
			cout << "Error, input right subject\n";
	} while (isFoundSubject == false);

	//arr = (subject*)realloc(arr, size);
	Subject* newArr = new Subject[size];

	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = nullptr;

	newArr[size - 1] = subject;
	return newArr;

}