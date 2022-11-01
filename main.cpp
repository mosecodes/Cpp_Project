
#pragma once

#include "roster.h"

using namespace std;

void PrintIntro() {
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 9458589" << endl;
	cout << "Name: Mose Norman" << endl << endl;
}

int main() 
{

	PrintIntro();

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,31,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Mose,Norman,mnorm70@wgu.edu,24,28,20,30,SOFTWARE"
	};

	Roster classRoster;



	for (int i = 0; i < 5; i++)
	{
		//cout << studentData[i];
		classRoster.Parse(studentData[i]);
	}

	classRoster.PrintAll();

	classRoster.PrintInvalidEmails();

	for (int i = 0; i < 5; i++)
	{
		classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->getId());
	}

	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.Remove("A3");

	classRoster.PrintAll();

	classRoster.Remove("A3");
	
	return 0;
}