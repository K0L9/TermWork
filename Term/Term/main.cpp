#include <iostream>
#include "Teachers.h"
#include "Subject.h"
#include "Student.h"

using namespace std;

bool CheckPass(char login[], char pass[])
{
	char userlogin[9];
	char userpass[14];
	for (int i = 3; i > 0; i--)
	{
		cout << "Enter Login (admin): ";
		cin >> userlogin;
		cout << "Enter Password (admin): ";
		cin >> userpass;
		if (strstr(userlogin, login) && strstr(userpass, pass))
			return true;
		else
		{
			cout << "Invalid login or pass, left " << i - 1 << " try more\n";
			system("pause");
			system("cls");
		}
	}
	return false;
}

int ShowMenu()
{
	int menuOption;
	cout << "  MAIN MENU \n";
	cout << "=============\n";
	cout << "|1.Teachers |\n";
	cout << "|2.Subjects |\n";
	cout << "|3.Students |\n";
	cout << "|4.Exit     |\n";
	cout << "=============\n";
	cout << "Input option: ";
	cin >> menuOption;
	return menuOption;
}

int main()
{
	char login[9] = "admin";
	char pass[14] = "admin";

	if (CheckPass(login, pass) == false)
	{
		cout << "You input invalid login or password 3 times, good bye\n";
		return 0;
	}

	system("cls");
	cout << "WELCOME DIRECTOR\n";
	system("pause");
	system("cls");

	int sizeSubject = 0;
	char** subjectArr = new char* [sizeSubject];

	int sizeTeacher = 0;
	Teacher* teachersArr = new Teacher[sizeTeacher];

	int sizeStudent = 0;
	Student* studentsArr = new Student[sizeStudent];


	int mainOption;
	do
	{

		system("cls");
		mainOption = ShowMenu();
		switch (mainOption)
		{
		case 1:
			system("cls");
			TeachersSubMenu(teachersArr, &sizeTeacher);
			break;

		case 2:
			system("cls");
			cout << "WARNING! This part is demo, some functions can be unavailable\n";
			cout << "You can have only 1 subject\n";
			system("pause");
			SubjectsSubMenu(subjectArr, &sizeSubject);
			break;

		case 3:
			system("cls");
			StudentsSubMenu(studentsArr, &sizeStudent);
			break;
			
		case 4:
			cout << "Good bye\n";
			return 0;
			break;
		default:
			cout << "You input not right value\n";
			return 0;
			system("pause");
			system("cls");
		}
	} while (mainOption != 4);

	return 0;
}