#pragma once

struct Subject
{
	char name[25] = " ";
	char* forms[4];
	char* teachers[25];
};

void ShowAllSubjects(Subject subject[], size_t size);
Subject AddSubject();

int SubjectsSubMenu();

