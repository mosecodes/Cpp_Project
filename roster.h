// Class definition, data members, and member functions for class Roster

#pragma once

#include "student.h"
// Roster Class def, members, functions go here

class Roster {
public:
	Roster();
	~Roster();

	void PrintAll();
	void PrintInvalidEmails();
	void PrintAverageDaysInCourse(string studentIdP);
	void PrintByDegreeProgram(DegreeProgram degreeProgramP);
	void Remove(string studentId);
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgramP);

	void Parse(string studentString);		// parse each string, comma deliniated 
	const static int numStudents = 5;
//private: 
	Student* classRosterArray[numStudents];
private:
	int counter = 0;							// counter for how many students have been added to classRosterArray

	// How many other private members do I need?	<<	NONE AS OF CALLING WITH MICHELLE  >>
	// Shouldn't the rest of the class have to do with editing individual Students?

};

