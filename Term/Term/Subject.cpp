#include <iostream>
using namespace std;

int SubjectsSubMenu()
{
	system("cls");
	int menuOption;
	cout << "\tSUBJECTS\n";
	cout << "=======================\n";
	cout << "|1. Show all subjects |\n";
	cout << "|2. Add new subject   |\n";
	cout << "|3. Remove subject    |\n";
	cout << "=======================\n";
	cin >> menuOption;
	return menuOption;
}