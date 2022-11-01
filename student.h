// Class definition, data members, and member functions for class Student

#include "degree.h"

#pragma once



// Student Class def, members, function declarations go here

class Student{
public:
	Student();

	Student(string studentIdP, string nameFirstP, string nameLastP, string emailAddressP, int ageP, int numDaysToCompleteP[3], DegreeProgram degreeProgramP);

	~Student();

	void setId(string newId);
	void setNameFirst(string newFirstName) ;
	void setNameLast(string newLastName) ;
	void setEmail(string newEmail) ;
	void setAge(int newAge) ;
	void setDaysToComplete(int numOfDays[]);
	void setDegreeProgram(DegreeProgram newProgram) ;
	string getId() ;
	string getNameFirst() ;
	string getNameLast() ;
	string getEmail() ;
	int getAge() ;
	const int* getNumDaysToComplete() ;
	DegreeProgram getDegreeProgram() ;
	void print() ;
	const static int daysArraySize = 3;
private:
	string studentId;
	string nameFirst;
	string nameLast;
	string emailAddress;
	int age;
	int numDaysToComplete[daysArraySize];
	DegreeProgram degreeProgram;
	
};

