// Member function definitions for class Student
// Don't forget to use a full constructor/set of constructors!!!!


#include "student.h"

using namespace std;



Student::Student() 
{
	studentId = "MAN0516";
	nameFirst = "Mose";
	nameLast = "Norman";
	emailAddress = "mnorm70@wgu.edu";
	age = 24;
	degreeProgram = DegreeProgram::NETWORK;
	//numDaysToComplete = new int[daysArraySize];

	for (int i = 0; i < daysArraySize; i++)
	{
		numDaysToComplete[i] = i + 1;
	}

}

Student::~Student()
{

}

Student::Student(string studentIdP, string nameFirstP, string nameLastP, string emailAddressP, int ageP, int numDaysToCompleteP[daysArraySize], DegreeProgram degreeProgramP) 
{
	studentId = studentIdP;
	nameFirst = nameFirstP;
	nameLast = nameLastP;
	emailAddress = emailAddressP;
	age = ageP;
	degreeProgram = degreeProgramP;

	this->numDaysToComplete[0] = numDaysToCompleteP[0];
	this->numDaysToComplete[1] = numDaysToCompleteP[1];
	this->numDaysToComplete[2] = numDaysToCompleteP[2];

}



// DEFINE SETTERS

void Student::setId(string newId) 
{
	studentId = newId;
}

void Student::setNameFirst(string newFirstName) 
{
	nameFirst = newFirstName;
}

void Student::setNameLast(string newLastName) 
{
	nameLast = newLastName;
}

void Student::setEmail(string newEmail) 
{
	emailAddress = newEmail;
}

void Student::setAge(int newAge) {
	age = newAge;
}

void Student::setDaysToComplete(int numOfDays[])
{
	for (int i = 0; i < daysArraySize; i++)
	{
		numDaysToComplete[i] = numOfDays[i];
	}
}

void Student::setDegreeProgram(DegreeProgram newProgram) 
{
	degreeProgram = newProgram;
}

// DEFINE GETTERS

string Student::getId() 
{
	return studentId;
}

string Student::getNameFirst() 
{
	return nameFirst;
}

string Student::getNameLast() 
{
	return nameLast;
}

string Student::getEmail() 
{
	return emailAddress;
}

int Student::getAge() 
{
	return age;
}

const int* Student::getNumDaysToComplete() 
{
	return numDaysToComplete;
}

DegreeProgram Student::getDegreeProgram() 
{
	return degreeProgram;
}

// DEFINE PRINT() //		FIXME: how to print the degreeProgramString appropriate to the DegreeProgram (FIXED??) ((FIXED!!))

void Student::print()
{
	string programToPrint = "";
	if (this->degreeProgram == 0)
	{
		programToPrint = "SECURITY";
	}
	else if (this->degreeProgram == 1)
	{
		programToPrint = "NETWORK";
	}
	else if (this->degreeProgram == 2)
	{
		programToPrint = "SOFTWARE";
	}

	int numDaysArr[daysArraySize] = {0,0,0};

	for (int i = 0; i < daysArraySize; i++) numDaysArr[i] = getNumDaysToComplete()[i];

	cout << studentId << "\t";
	cout << nameFirst << '\t';
	cout << setw(12) << nameLast << '\t';
	cout << age << '\t';
	cout << "{ " << numDaysArr[0] << " " << numDaysArr[1] << " " << numDaysArr[2] << " }" << '\t';
	cout << programToPrint << endl;
}