#pragma once

struct Teacher
{
	char name[25] = " ";
	char surname[25] = " ";
	int age;
	char mail[40] = " ";
};

void TeachersSubMenu(Teacher arr[], int* size);
void ShowAllTeachers(const Teacher const teacher[], int size);

Teacher* AddTeacher(Teacher arr[], int* size);
Teacher* DeleteTeacher(Teacher arr[], int* size);
void SortTeachers(Teacher arr[], int size);
void EditTeacher(Teacher arr[], int size);

int FoundTeacher(const Teacher const arr[], int size);

int ShowEditMenu();

void GetMail(char arr[40]);