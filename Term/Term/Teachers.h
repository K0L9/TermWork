#pragma once

#include "Subject.h"

//struct Subject
//{
//	char name[25] = " ";
//	char forms[60] = " ";
//	char* teacher[5];
//};

//struct Teacher
//{
//	char name[25] = " ";
//	char surname[25] = " ";
//	int age;
//	char mail[40] = " ";
//	Subject* subject;
//};



void ShowAllTeachers(Teacher teacher[], size_t size);

int TeachersSubMenu();

Teacher* AddTeacher(Teacher arr[], int size, int sizeSubject, Subject arrSubject[]);
Teacher* DeleteTeacher(Teacher arr[], int* size);
void SortTeachers(Teacher arr[], int size);
void EditTeacher(Teacher arr[], size_t size);

int FoundTeacher(Teacher arr[], int size);

int ShowEditMenu();