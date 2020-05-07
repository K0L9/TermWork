#pragma once

struct Teacher
{
	char name[25] = " ";
	char surname[25] = " ";
	int age;
	char mail[40] = " ";
	char* subject;
};

void ShowAllTeachers(Teacher teacher[], size_t size);

int TeachersSubMenu();

Teacher* AddTeacher(Teacher arr[], int size, int sizeSubject, char* arrSubject[]);
Teacher* DeleteTeacher(Teacher arr[], int* size);
void SortTeachers(Teacher arr[], int size);
void EditTeacher(Teacher arr[], int size, int sizeSubject, char* arrSubject[]);

int FoundTeacher(Teacher arr[], int size);

int ShowEditMenu();