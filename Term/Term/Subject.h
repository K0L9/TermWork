#pragma once

#include "Student.h"

//struct Teacher
//{
//	char name[25] = " ";
//	char surname[25] = " ";
//	int age;
//	char mail[40] = " ";
//	char* subject;
//};

//struct Student
//{
//	char surname[25] = " ";
//	char name[25] = " ";
//	char form[5] = " ";
//	char mail[35] = " ";
//	char perentsPhone[90] = " ";
//	char studentPhone[15] = " ";
//	char* subject;
//};

int SubjectsSubMenu();

void ShowAllSubject(char* arr[], int size);
void ShowCurrentSubject(char* arr[], int size, int sizeTeachers, Teacher teacherArr[], int sizeStudents, Student studentArr[]);

char** AddSubject(char* arr[], int size, int sizeTeacher, Teacher arrTeacher[], int sizeStudents, Student studentsArr[]);
//char** DeleteSubject(char* arr[], int size, int sizeTeacher, Teacher arrTeacher[], int sizeStudents, Student studentsArr[]);
//void AddSubject();
