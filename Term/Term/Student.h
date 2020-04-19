#pragma once

struct Student
{
	char surname[25] = " ";
	char name[25] = " ";
	char form[5] = " ";
	char mail[35] = " ";
	char perentsPhone[90] = " ";
	char studentPhone[15] = " ";
	//char* subject;

};


int StudentsSubMenu();
void ShowAllStudents(Student arr[], int size);
void ShowStudentsForm(Student arr[], int size);
Student* AddStudent(Student arr[], int size);
Student* DeleteStudent(Student arr[], int* size);
int FoundStudent(Student arr[], int size); 
void SortStudents(Student arr[], int size);
char* ConvertForm(char form[5]);
char* ReturnForm();