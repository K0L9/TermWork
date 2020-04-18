//#include <iostream>
//#include <string>
//#include "Teachers.h"
//#include "Subject.h"
//#include "Student.h"


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
		cout << "Enter Login: ";
		cin >> userlogin;
		cout << "Enter Password: ";
		cin >> userpass;
		if (strstr(userlogin, login) && strstr(userpass, pass))
			return true;
		else
		{
			cout << "Invalid login or pass, left " << i - 1 << " try more\n";
			//system("pause");
			//system("cls");
		}
	}
	return false;
}

int ShowMenu()
{
	int menuOption;
	cout << "=============\n";
	cout << "|1.Teachers |\n";
	cout << "|2.Subjects |\n";
	cout << "|3.Students |\n";
	cout << "|4.Exit     |\n";
	cout << "=============\n";
	cout << "Input option\n";
	cin >> menuOption;
	return menuOption;
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	cout << "WELCOME DIRECTOR\n";
	//system("pause");
	//system("cls");


	char login[9] = "Director";
	char pass[14] = "i_am_director";

	//if (CheckPass(login, pass) == false)
	//{
	//	cout << "You input invalid login or password 3 times, good bye\n";
	//	return 0;
	//}

	int size = 8;

	Teacher stelmah = { "Lyudmyla", "Stelmah", 40, "stelmahlyda@gmail.com" };
	Teacher veritianikova = { "Lydmyla", "Veritianikova", 35, "veritianikovalyda@gmail.com" };
	Teacher stepanenko = { "Nadiya", "Stepanenko", 56, "stepanenkonadiya@gmail.com" };
	Teacher avramenko = { "Oleksandr", "Avramenko", 31, "avramenkosasha@gmail.com" };
	Teacher verhova = { "Inna", "Verhova", 49, "verhovainna@gmail.com" };
	Teacher kovalchyk = { "Myroslava", "Kovalchyk", 49, "myrosyakovalchyk@gmail.com" };
	Teacher oliinuk = { "Olena", "Oliinuk", 49, "olenkaoliinyk@gmail.com" };
	Teacher rychka = { "Halyna", "Rychka", 49, "rychkahalka@gmail.com" };

	Teacher* teachersArr = new Teacher[size]{ stelmah, stepanenko, oliinuk, rychka, veritianikova, verhova, kovalchyk, avramenko };

	do
	{

		//system("cls");
		switch (ShowMenu())
		{
		case 1:
			//system("cls");
			switch (TeachersSubMenu())
			{
			case 1:
				//system("cls");
				ShowAllTeachers(teachersArr, size);
				//system("pause");
				//system("cls");
				break;
			case 2:
				size++;
				teachersArr = AddTeacher(teachersArr, size);
				//teachersArr = AddTeacher(teachersArr, size);
				break;
			case 3:
				teachersArr = DeleteTeacher(teachersArr, &size);
				break;
			case 4:
				SortTeachers(teachersArr, size);
				break;
			case 5:
				EditTeacher(teachersArr, size);
				break;
			default:
				cout << "You input invalid value, try again\n";
				//	system("pause");
				//	system("cls");
			}
			break;

		case 2:
			switch (SubjectsSubMenu())
			{
			case 1:
				break;
			}

		case 3:
			switch (StudentsSubMenu())
			{
			case 1:
				break;
			}

		case 4:
			//system("cls");
			cout << "Good bye\n";
			return 0;
			break;
		default:
			cout << "You input not right value, try again\n";
			//system("pause");
			//system("cls");
		}
	} while (1);
	return 0;
}