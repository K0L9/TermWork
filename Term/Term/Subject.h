#pragma once

//#include "Teachers.h"

struct Subject
{
	char name[25] = " ";
	char forms[60] = " ";
	char* teacher[2];
};

struct Teacher
{
	char name[25] = " ";
	char surname[25] = " ";
	int age;
	char mail[40] = " ";
	Subject* subject;
};

int SubjectsSubMenu();

void ShowAllSubject(Subject arr[], int size);

Subject* AddSubject(Subject arr[], int size, int sizeTeacher, Teacher arrTeacher[]);

