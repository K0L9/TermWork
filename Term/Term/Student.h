#pragma once

struct Student
{
	char surname[25] = " ";
	char name[25] = " ";
	char form[5] = " ";
	char mail[35] = " ";
	char perentsPhone[90] = " ";
	char studentPhone[15] = " ";
	char** subject;
	int sizeSubject = 20;
};


void StudentsSubMenu(Student arr[], int* size);
void ShowAllStudents(const Student const arr[], int size);
void ShowStudentsForm(const Student const arr[], int size);
Student* AddStudent(Student arr[], int size);
Student* DeleteStudent(Student arr[], int* size);
int FoundStudent(const Student const arr[], int size);
void SortStudents(Student arr[], int size);
void ConvertForm(char form[5]);
void GetForm(char form[5]);
int ReturnLastFormIndex(const Student const arr[], int size, const char const form[5]);
int ReturnFirstFormIndex(const Student const arr[], int size, const char const form[5]);
void EditStudent(Student arr[], int size);
int ShowEditStudentMenu();
void GetNumber(char number[15]);
void GetMailS(char arr[40]);