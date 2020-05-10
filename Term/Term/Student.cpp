#include <iostream>
#include "Student.h"
#define FORMS "1-A 2-A 3-A 4-A 5-A 6-A 7-A 8-A 9-A 10-A 11-A 1-B 2-B 3-B 4-B 5-B 6-B 7-B 8-B 9-B 10-B 11-B 1-C 2-C 3-C 4-C 5-C 6-C 7-C 8-C 9-C 10-C 11-C\
1A 2A 3A 4A 5A 6A 7A 8A 9A 10A 11A 1B 2B 3B 4B 5B 6B 7B 8B 9B 10B 11B 1C 2C 3C 4C 5C 6C 7C 8C 9C 10C 11C\
1-a 2 3-a 4-a 5-a 6-a 7-a 8-a 9-a 10-a 11-a 1-b 2-b 3-b 4-b 5-b 6-b 7-b 8-b 9-b 10-b 11-b 1-c 2-c 3-c 4-c 5-c 6-c 7-c 8-c 9-c 10-c 11-c 1a 2a 3a 4a 5a 6a 7a 8a 9a 10a 11a\
1b 2b 3b 4b 5b 6b 7b 8b 9b 10b 11b 1c 2c 3c 4c 5c 6c 7c 8c 9c 10c 11c"

using namespace std;

void StudentsSubMenu(Student arr[], int* size)
{
	int menuOption;
	do
	{
		system("cls");
		cout << "          Students\n";
		cout << "==================================\n";
		cout << "|1. Show all students            |\n";
		cout << "|2. Show students in current form|\n";
		cout << "|3. Add new student              |\n";
		cout << "|4. Delete student               |\n";
		cout << "|5. Sort students in current form|\n";
		cout << "|6. Edit current student         |\n";
		cout << "|7. Exit                         |\n";
		cout << "==================================\n";
		cout << "Input option: ";
		cin >> menuOption;
		switch (menuOption)
		{
		case 1:
			system("cls");
			ShowAllStudents(arr, *size);
			system("pause");
			break;
		case 2:
			system("cls");
			ShowStudentsForm(arr, *size);
			system("pause");
			break;
		case 3:
			system("cls");
			*size = *size + 1;
			arr = AddStudent(arr, *size);
			break;
		case 4:
			system("cls");
			arr = DeleteStudent(arr, size);
			system("cls");
			break;
		case 5:
			system("cls");
			SortStudents(arr, *size);
			system("cls");
			break;
		case 6:
			EditStudent(arr, *size);
			break;
		case 7:
			return;
		default:
			cout << "Error, input right option\n";
		}
	} while (menuOption != 7);
}

void ShowAllStudents(const Student const arr[], int size)
{
	if (size == 0)
	{
		cout << "There aren't students in your school\n";
		return;
	}

	cout << "Total: " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << arr[i].surname << "\t" << arr[i].name << " " << arr[i].form << endl;
	}
}

void ShowStudentsForm(const Student const arr[], int size)
{
	char form[5];
	GetForm(form);

	bool isFoundForm = false;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].form, form) == 0)
		{
			isFoundForm = true;
			cout << i + 1 << ". " << arr[i].surname << " ";
			cout << arr[i].name << "\t";
			cout << arr[i].mail << "\n";
			cout << "\t" << arr[i].perentsPhone << "\n";
			cout << "\t" << "Student's phone: " << arr[i].studentPhone << "\n\n";
		}
	}

	if (isFoundForm == false)
	{
		cout << "There aren't students in this form\n";
		return;
	}
}

Student* AddStudent(Student arr[], int size)
{
	Student student;

	cout << "Input student name: ";
	cin.ignore();
	cin.getline(student.name, 25);
	if (student.name[0] >= 97 && student.name[0] <= 122)
		student.name[0] = int(student.name[0]) - 32;


	cout << "Input student surname: ";
	cin.getline(student.surname, 25);
	if (student.surname[0] >= 97 && student.surname[0] <= 122)
		student.surname[0] = int(student.surname[0]) - 32;

	GetForm(student.form);

	GetMailS(student.mail);

	cout << "Input student parents phone: ";
	do
	{
		cout << "\nInput h to show example: ";
		cin.ignore();
		cin.getline(student.perentsPhone, 90);
		if (strcmp(student.perentsPhone, "h") == 0)
			cout << "Mother: Name - +380*********; Father: Name - +380*********\n";
	} while (strlen(student.perentsPhone) == 1);

	GetNumber(student.studentPhone);
	//cout << "Input student phone: \n";
	//cin.getline(student.studentPhone, 15);

	//arr = (student*)realloc(arr, size);
	Student* newArr = new Student[size];

	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = nullptr;

	cout << "Student are succesfully added\n";
	system("pause");

	newArr[size - 1] = student;
	return newArr;

}

Student* DeleteStudent(Student arr[], int* size)
{
	int IndexToDelete = FoundStudent(arr, *size);

	if (IndexToDelete != -1)
	{
		*size = *size - 1;
		Student* newArr = new Student[*size];

		for (int i = 0; i < *size + 1; i++)
		{
			if (i < IndexToDelete)
				newArr[i] = arr[i];

			else if (i > IndexToDelete)
				newArr[i - 1] = arr[i];
		}
		delete[] arr;
		arr = nullptr;

		cout << "\nStudent are succesfully deleted\n";
		system("pause");
		return newArr;
	}
	else
	{
		cout << "Student not indefined\n";
		return arr;
	}

}

int FoundStudent(const Student const arr[], int size)
{
	if (arr[0].name[0] < 65 || arr[0].name[0] > 90 || arr[0].surname[0] < 65 || arr[0].surname[0] > 90)
	{
		cout << "You haven't any student!\n";
		return -2;
	}

	Student student;

	char form[5];
	GetForm(form);

	cout << "Input student name: \n";
	cin >> student.name;
	if (student.name[0] >= 97 && student.name[0] <= 122)
		student.name[0] = int(student.name[0]) - 32;
	cout << "Input student surname: \n";
	cin >> student.surname;
	if (student.surname[0] >= 97 && student.surname[0] <= 122)
		student.surname[0] = int(student.surname[0]) - 32;


	int IndexToEdit = -1;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(student.form, arr[i].form) == -1)
		{
			if (strstr(student.name, arr[i].name) != nullptr)
			{
				if (strstr(student.surname, arr[i].surname) != nullptr)
				{
					IndexToEdit = i;
					break;
				}
			}
		}
	}

	return IndexToEdit;
}

int ReturnLastFormIndex(const Student const arr[], int size, const char const form[5])
{
	int lastElement = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].form, form) == 0)
			lastElement = i;
	}
	return lastElement;
}

int ReturnFirstFormIndex(const Student const arr[], int size, const char const form[5])
{
	int lastElement = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].form, form) == 0)
			return i;
	}
}

void SortStudents(Student arr[], int size)
{
	char form[5];
	GetForm(form);
	int firstIndex = ReturnFirstFormIndex(arr, size, form);
	int lastIndex = ReturnLastFormIndex(arr, size, form);

	if (firstIndex < 0 || lastIndex < 0)
	{
		cout << "Error, there aren't this form\n";
		return;
	}

	for (int i = firstIndex; i < lastIndex; i++)
	{
		for (int j = i + 1; j < lastIndex + 1; j++)
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

	cout << "Teachers are succesfully sorted\n";
	system("pause");

}

void GetForm(char form[5])
{
	do
	{
		cout << "Input form: ";
		cin >> form;
		if (strstr(FORMS, form) == nullptr || strlen(form) == 1)
			cout << "Input right form\n";

	} while (strstr(FORMS, form) == nullptr || strlen(form) == 1);
}

void ConvertForm(char form[5])
{
	bool isFound = false;
	int letter;
	for (int i = 0; i < 5; i++)
	{
		if (form[i] == '-')
		{
			isFound = true;
			if (form[i + 1] >= 97 && form[i + 1] <= 122)
				form[i + 1] -= 32;
			break;
		}

		if (isalpha(form[i]))
		{
			letter = i;
			break;
		}
	}

	if (isFound == false)
	{
		form[letter + 2] = '\0';
		form[letter + 1] = form[letter];
		form[letter] = '-';
		ConvertForm(form);
	}
	//Student temp;
	//return form;
}

void EditStudent(Student arr[], int size)
{


	int indexToEdit;
	do
	{
		indexToEdit = FoundStudent(arr, size);
		if (indexToEdit == -1)
			cout << "Student not indefined, try again\n";

		else if (indexToEdit == -2)
			return;

	} while (indexToEdit == -1);

	int option = 0;
	do
	{
		option = ShowEditStudentMenu();

		switch (option)
		{
		case 1:
			system("cls");
			char name[25];
			cout << "Input new student's name: ";
			cin >> name;
			strcpy_s(arr[indexToEdit].name, 25, name);
			break;
		case 2:
			system("cls");
			char surname[25];
			cout << "Input new student's surname: ";
			cin >> surname;
			strcpy_s(arr[indexToEdit].surname, 25, surname);
			break;
		case 3:
			system("cls");
			GetForm(arr[indexToEdit].form);
			break;

		case 4:
			system("cls");
			char mail[25];
			GetMailS(mail);
			strcpy_s(arr[indexToEdit].mail, 25, mail);
			break;
		case 5:
			system("cls");
			char studentPhone[15];
			GetNumber(studentPhone);
			/*cout << "Input new student's number\n";
			cin >> studentPhone;
			strcpy_s(arr[indexToEdit].studentPhone, 15, studentPhone);*/
			break;
		case 6:
			system("cls");
			char parentsPhone[90];
			do
			{
				cout << "\nInput student parents phone: \n";
				cout << "Input h to show example: \n";
				cin.ignore();
				cin.getline(parentsPhone, 90);
				if (strcmp(parentsPhone, "h") == 0)
					cout << "Mother: Name - +380*********; Father: Name - +380*********\n";
			} while (strlen(parentsPhone) == 1);

			strcpy_s(arr[indexToEdit].perentsPhone, 90, parentsPhone);

			break;

		case 7:
			system("cls");
			cout << "Changes are succesfully added\n";
			system("pause");
			return;

		default:
			cout << "Input right number please\n";
		}
	} while (option != 7);
}

int ShowEditStudentMenu()
{
	system("cls");
	cout << "      Edit Student\n";
	cout << "=========================\n";
	cout << "|1. Edit name           |\n";
	cout << "|2. Edit surname        |\n";
	cout << "|3. Edit form           |\n";
	cout << "|4. Edit mail           |\n";
	cout << "|5. Edit student number |\n";
	cout << "|6. Edit parents number |\n";
	cout << "|7. Exit                |\n";
	cout << "=========================\n";
	cout << "Input what you want to edit: ";
	int option;
	cin >> option;
	return option;
}

void GetNumber(char number[15])
{
	bool isFirst = false;
	for (int i = 0; i < 15; i++)
	{
		if (number[i] == '\0')
			break;
		do
		{

			if (isFirst == false)
			{
				cout << "Input student's phone: ";
				cin.ignore();
				cin.getline(number, 15);

				//for (int j = 0; j < 15; j++)
				//	if (!isdigit(number[j]) && number[j] != 43)
				//		break;
				isFirst = true;
			}
			if (!isdigit(number[i]) && number[i] != 43)
			{
				cout << "Error, input right number (0-9, +)\n";
				isFirst = false;
			}
		} while (!isdigit(number[i]) && number[i] != 43);
	}

	cout << endl;
}

void GetMailS(char arr[40])
{
	bool isMail = false;
	do
	{
		cout << "Input student mail: ";
		cin.ignore();
		cin >> arr;

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