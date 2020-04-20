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

	int sizeTeacher = 8;

	Teacher stelmah = { "Lyudmyla", "Stelmah", 40, "stelmahlyda@gmail.com" };
	Teacher shevchenko = { "Lydmyla", "Shevchenko", 35, "shevchenkolyda@gmail.com" };
	Teacher stepanenko = { "Nadiya", "Stepanenko", 56, "stepanenkonadiya@gmail.com" };
	Teacher avramenko = { "Oleksandr", "Avramenko", 31, "avramenkosasha@gmail.com" };
	Teacher verhova = { "Inna", "Verhova", 49, "verhovainna@gmail.com" };
	Teacher kovalchyk = { "Myroslava", "Kovalchyk", 49, "myrosyakovalchyk@gmail.com" };
	Teacher oliinuk = { "Olena", "Oliinuk", 49, "olenkaoliinyk@gmail.com" };
	Teacher rychka = { "Halyna", "Rychka", 49, "rychkahalka@gmail.com" };

	Teacher* teachersArr = new Teacher[sizeTeacher]{ stelmah, stepanenko, oliinuk, rychka, shevchenko, verhova, kovalchyk, avramenko };



	//Subjects

	/*//int size = 5;
	//char* subjects = new char[size];
	//subjects[1] = " asd";

	int size = 5;
	char** arr = new char* [size];
	for (int i = 0; i < size; i++)
		arr[i] = new char[25];
	*/


	//Students

	int sizeStudent = 13;

	Student kravchenko = { "Kravchenko", "Ivan", "1-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student kramarchyk = { "Kramarchyk", "Vladislav", "2-A", "kramarchykvlad@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student zaharchyk = { "Zaharchyk", "Valerii", "3-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student pavlyk = { "Pavlyk", "Daryna", "4-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student melnychenko = { "Melnychenko", "Evgen", "5-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student shevchyk = { "Shevchyk", "Anna", "5-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student shunkarenko = { "Shunkarenko", "Bohdan", "6-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student vasylenko = { "Vasylenko", "Oleksandra", "7-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student brovarenko = { "Brovarenko", "Grigorii", "8-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student bondarenko = { "Bondarenko", "Maksym", "9-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student mykytuk = { "Mykytuk", "Oleh", "9-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student romanchenko = { "Romanchenko", "Evhen", "10-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	Student sereda = { "Sereda", "Denys", "11-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };

	Student* studentsArr = new Student[sizeStudent]{ kravchenko, kramarchyk, zaharchyk, pavlyk, shevchyk, melnychenko, shunkarenko, vasylenko,
		brovarenko, bondarenko, mykytuk, romanchenko, sereda };

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
				ShowAllTeachers(teachersArr, sizeTeacher);
				//system("pause");
				//system("cls");
				break;
			case 2:
				sizeTeacher++;
				teachersArr = AddTeacher(teachersArr, sizeTeacher);
				//teachersArr = AddTeacher(teachersArr, sizeTeacher);
				break;
			case 3:
				teachersArr = DeleteTeacher(teachersArr, &sizeTeacher);
				break;
			case 4:
				SortTeachers(teachersArr, sizeTeacher);
				break;
			case 5:
				EditTeacher(teachersArr, sizeTeacher);
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
				ShowAllStudents(studentsArr, sizeStudent);
				break;
			case 2: 
				ShowStudentsForm(studentsArr, sizeStudent);
				break;
			case 3: 
				sizeStudent++;
				studentsArr = AddStudent(studentsArr, sizeStudent);
				break;
			case 4: 
				studentsArr = DeleteStudent(studentsArr, &sizeStudent);
				break;
			case 5: 
				SortStudents(studentsArr, sizeStudent);
				break;
			case 6:
				EditStudent(studentsArr, sizeStudent);
				break;
			}
			break;

		case 4:
			//system("cls");
			cout << "Good bye\n";
			return 0;
			break;
		default:
			cout << "You input not right value, good bye\n";
			return 0;
			//system("pause");
			//system("cls");
		}
	} while (1);
	return 0;
}