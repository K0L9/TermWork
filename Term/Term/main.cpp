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

	//subjects
	//Subject history, pe, math, english, ukrainian, art;


	int sizeSubject = 0;

	//Subjects
	//char history[25] = "History";
	//char pe[25] = "Pe";
	//char math[25] = "Math";
	//char english[25] = "English";
	//char ukrainian[25] = "Ukrainian";
	//char art[25] = "Art";

	//char** subjectArr = nullptr;
	char** subjectArr = new char* [sizeSubject];// { history, pe, math, english, ukrainian, art };
	//string* subjectArr = new string [sizeSubject];// { history, pe, math, english, ukrainian, art };

	//Teachers
	int sizeTeacher = 0;

	/*Teacher stelmah = { "Lyudmyla", "Stelmah", 40, "stelmahlyda@gmail.com", history };
	Teacher shevchenko = { "Lydmyla", "Shevchenko", 35, "shevchenkolyda@gmail.com", ukrainian };
	Teacher stepanenko = { "Nadiya", "Stepanenko", 56, "stepanenkonadiya@gmail.com", art };
	Teacher avramenko = { "Oleksandr", "Avramenko", 31, "avramenkosasha@gmail.com", ukrainian };
	Teacher verhova = { "Inna", "Verhova", 49, "verhovainna@gmail.com", history };
	Teacher kovalchyk = { "Myroslava", "Kovalchyk", 49, "myrosyakovalchyk@gmail.com", pe };
	Teacher oliinuk = { "Olena", "Oliinuk", 49, "olenkaoliinyk@gmail.com", english };
	Teacher rychka = { "Halyna", "Rychka", 49, "rychkahalka@gmail.com", math };*/

	Teacher* teachersArr = new Teacher[sizeTeacher];// { stelmah, stepanenko, oliinuk, rychka, shevchenko, verhova, kovalchyk, avramenko };


	/*history = { "History", "5-A 6-C", (stelmah.surname, verhova.surname) };
	pe = { "Pe", "5-A 5-B", shevchenko.surname };
	math = { "Math", "5-A 11-A", stepanenko.surname };
	english = { "English", "5-A 9-C", avramenko.surname };
	ukrainian = { "Ukrainian", "5-A 1-B", verhova.surname };
	art = { "Art", "5-A 7-A", oliinuk.surname };

	//Subject* subjectArr = new Subject[sizeSubject]{ history, pe, math, english, ukrainian, art };

		//for (int i = 0; i < sizeSubject; i++)
	//	subjectArr[i] = new char[25];

	//subjectArr[0] = new char[25];

	//Subjects

	int size = 5;
	char* subjects = new char[size];
	subjects[1] = '4';




	char* m[12] ;
	*m ("ad";
	subjectArr[1] = m;
	cout << subjectArr[1];

	*/

	//Students

	int sizeStudent = 0;

	//Student kravchenko = { "Kravchenko", "Ivan", "1-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student kramarchyk = { "Kramarchyk", "Vladislav", "2-A", "kramarchykvlad@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student zaharchyk = { "Zaharchyk", "Valerii", "3-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student pavlyk = { "Pavlyk", "Daryna", "4-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student melnychenko = { "Melnychenko", "Evgen", "5-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student shevchyk = { "Shevchyk", "Anna", "5-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student shunkarenko = { "Shunkarenko", "Bohdan", "6-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student vasylenko = { "Vasylenko", "Oleksandra", "7-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student brovarenko = { "Brovarenko", "Grigorii", "8-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416"};
	//Student bondarenko = { "Bondarenko", "Maksym", "9-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	//Student mykytuk = { "Mykytuk", "Oleh", "9-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	//Student romanchenko = { "Romanchenko", "Evhen", "10-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };
	//Student sereda = { "Sereda", "Denys", "11-A", "ivankravchenko@gmail.com", "Mother: Natasha - 0989621546; Father: Valentin - 0987561257", "0698795416" };

	Student* studentsArr = new Student[sizeStudent];// { kravchenko, kramarchyk, zaharchyk, pavlyk, shevchyk, melnychenko, shunkarenko, vasylenko,
		//brovarenko, bondarenko, mykytuk, romanchenko, sereda };


	int mainOption;
	do
	{

		system("cls");
		mainOption = ShowMenu();
		switch (mainOption)
		{
		case 1:
			system("cls");
			TeachersSubMenu(teachersArr, &sizeTeacher, sizeSubject, subjectArr);
			break;
			//case 1:
			//	//system("cls");
			//	ShowAllTeachers(teachersArr, sizeTeacher);
			//	//system("pause");
			//	//system("cls");
			//	break;
			//case 2:
			//	sizeTeacher++;
			//	teachersArr = AddTeacher(teachersArr, sizeTeacher, sizeSubject, subjectArr);
			//	//teachersArr = AddTeacher(teachersArr, sizeTeacher);
			//	break;
			//case 3:
			//	teachersArr = DeleteTeacher(teachersArr, &sizeTeacher);
			//	break;
			//case 4:
			//	SortTeachers(teachersArr, sizeTeacher);
			//	break;
			//case 5:
			//	EditTeacher(teachersArr, sizeTeacher, sizeSubject, subjectArr);
			//	break;
			//default:
			//	cout << "You input invalid value, try again\n";
			//	//	system("pause");
			//	//	system("cls");
			//}
			//break;


		case 2:
			system("cls");
			SubjectsSubMenu(subjectArr, &sizeSubject);
			break;
		case 3:
			system("cls");
			StudentsSubMenu(studentsArr, &sizeStudent);
			/*switch ()
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
				break;*/
			//}
			break;

		case 4:
			cout << "Good bye\n";
			return 0;
			break;
		default:
			cout << "You input not right value, good bye\n";
			return 0;
			//system("pause");
			//system("cls");
		}
	} while (mainOption != 4);

	//do
	//{

	//	//system("cls");
	//	switch (ShowMenu())
	//	{
	//	case 1:
	//		//system("cls");
	//		switch (TeachersSubMenu())
	//		{
	//		case 1:
	//			//system("cls");
	//			ShowAllTeachers(teachersArr, sizeTeacher);
	//			//system("pause");
	//			//system("cls");
	//			break;
	//		case 2:
	//			sizeTeacher++;
	//			teachersArr = AddTeacher(teachersArr, sizeTeacher, sizeSubject, subjectArr);
	//			//teachersArr = AddTeacher(teachersArr, sizeTeacher);
	//			break;
	//		case 3:
	//			teachersArr = DeleteTeacher(teachersArr, &sizeTeacher);
	//			break;
	//		case 4:
	//			SortTeachers(teachersArr, sizeTeacher);
	//			break;
	//		case 5:
	//			EditTeacher(teachersArr, sizeTeacher, sizeSubject, subjectArr);
	//			break;
	//		default:
	//			cout << "You input invalid value, try again\n";
	//			//	system("pause");
	//			//	system("cls");
	//		}
	//		break;

	//	case 2:
	//		switch (SubjectsSubMenu())
	//		{
	//		case 1:
	//			ShowAllSubject(subjectArr, sizeSubject);
	//			break;
	//		case 2:
	//			ShowCurrentSubject(subjectArr, sizeSubject, sizeTeacher, teachersArr, sizeStudent, studentsArr);
	//			break;
	//		case 3:
	//			sizeSubject++;
	//			subjectArr = AddSubject(subjectArr, sizeSubject, sizeTeacher, teachersArr, sizeStudent, studentsArr);
	//			break;
	//		case 4:
	//			subjectArr = DeleteSubject(subjectArr, &sizeSubject, sizeTeacher, teachersArr, sizeStudent, studentsArr);
	//			break;
	//		}
	//		break;
	//	case 3:
	//		switch (StudentsSubMenu())
	//		{
	//		case 1:
	//			ShowAllStudents(studentsArr, sizeStudent);
	//			break;
	//		case 2:
	//			ShowStudentsForm(studentsArr, sizeStudent);
	//			break;
	//		case 3:
	//			sizeStudent++;
	//			studentsArr = AddStudent(studentsArr, sizeStudent);
	//			break;
	//		case 4:
	//			studentsArr = DeleteStudent(studentsArr, &sizeStudent);
	//			break;
	//		case 5:
	//			SortStudents(studentsArr, sizeStudent);
	//			break;
	//		case 6:
	//			EditStudent(studentsArr, sizeStudent);
	//			break;
	//		}
	//		break;

	//	case 4:
	//		//system("cls");
	//		cout << "Good bye\n";
	//		return 0;
	//		break;
	//	default:
	//		cout << "You input not right value, good bye\n";
	//		return 0;
	//		//system("pause");
	//		//system("cls");
	//	}
	//} while (1);
	return 0;
}