// Member function definitions for class Roster
#include "roster.h"

using namespace std;

// Default constructor
Roster::Roster() 
{
	Student * tempStudent = new Student;
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i] = tempStudent;
	}
}

// Default destructor
Roster::~Roster() 
{
	//delete classRosterArray;

	for (int i = 0; i < numStudents; i++) 
	{
		classRosterArray[i] = nullptr;
	}

}

void Roster::PrintAll()
{
	cout << "Displaying all students: " << endl;

	if (counter == 0)
	{
		cout << "No students loaded into Roster array." << endl;
	}

	for (int i = 0; i < counter; i++)
	{
		if (classRosterArray[i]->getId() != "")
		{
			classRosterArray[i]->print();
		}
	}

	cout << endl;
}

void Roster::PrintInvalidEmails()
{
	// 
	string emailString;

	cout << "Displaying invalid emails: \n" << endl;

	for (int i = 0; i < counter; i++)
	{
		size_t atSymbol = 0;
		size_t dotSymbol = 0;
		bool isEmail = false;
		Student tempStudent = *classRosterArray[i];
		//assign emailString with the email string for the student on the roster
		emailString = tempStudent.getEmail();
		
		//search the string for an '@' symbol, followed by a '.' symbol
		atSymbol = emailString.find('@');
		dotSymbol = emailString.find('.');

		//compare locations for appropriate placement in the email string  (both elements are present and in the correct order)
		if ((atSymbol != string::npos) && (dotSymbol != string::npos))
		{
			isEmail = true;
		}

		//check for any invalid characters in email
		if (emailString.find(' ') != string::npos)
		{
			isEmail = false;
		}

		//if not a good email, print
		if (!isEmail)
		{
			cout << emailString << " - is invalid." << endl;
		}

	}
	cout << endl;
}

void Roster::PrintAverageDaysInCourse(string studentIdP)
{
	bool success = false;
	for (int i = 0; i < counter; i++)
	{
		if (classRosterArray[i]->getId() == studentIdP)
		{
			success = true;
			int averagedays;
			averagedays = (classRosterArray[i]->getNumDaysToComplete()[0] + classRosterArray[i]->getNumDaysToComplete()[1] + classRosterArray[i]->getNumDaysToComplete()[2]) / 3;	// *************	LOOK OUT FOR ERRORS WITH INTEGER ROUNDING HERE		*************
			cout << "student id: " << studentIdP << ", ";
			cout << "average days in course is: " << averagedays << endl;
		}
	}
	if (!success) { cout << "Error in PrintAverageDaysInCourse in the Roster Class, could not find student ID." << endl; }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgramP)
{
	cout << endl;
	string programToPrint = "";
	if (degreeProgramP == 0)
	{
		programToPrint = "SECURITY";
	}
	else if (degreeProgramP == 1)
	{
		programToPrint = "NETWORK";
	}
	else if (degreeProgramP == 2)
	{
		programToPrint = "SOFTWARE";
	}
	cout << "Showing students in degree program: " << programToPrint << endl << endl;

	for (int i = 0; i < counter; i++)
	{
		Student tempStudent = *classRosterArray[i];
		if (tempStudent.getDegreeProgram() == degreeProgramP)
		{
			tempStudent.print();
		}
	}
	cout << endl;
} 


// Remove

void Roster::Remove(string studentId)
{
	// iterate through array
	bool success = false;
	for (int i = 0; i < counter; i++)
	{
		// search for required studentId
		if (classRosterArray[i]->getId() == studentId)
		{
			success = true;
			// if found, remove from print function
			// swap book with the last one
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
			//Decrement counter so the removed student doesn't show up in the printAll()
			this->counter--;
		}
	}
	if (success)
	{
		// print if successful
		cout << "Student " << studentId << " removed." << endl << endl;
	}
	else
	{
		// if not found, print exit message
		cout << "Removing " << studentId << " again" << endl << endl;
		cout << "The student with the ID: " << studentId << " was not found." << endl;
		cout << "DONE" << endl;
	}

}




void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgramP)
{
	// add the newly parsed student to the class roster array
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	// increment counter to add another student next time Add() is called
	classRosterArray[counter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgramP);

	counter++;
	//cout << "Add called " << counter << " times." << endl;
}

void Roster::Parse(string studentString)			// PARSE STRING INTO A NEW STUDENT OBJECT
{
	size_t rhs = 0;
	size_t lhs = 0;
	string tempString;
	DegreeProgram* tempDegreeProgram{};

	// parse studentId and erase string up to the ',' after it
	rhs = studentString.find(',');
	tempString = studentString.substr(0, rhs);			//  GET STUDENT ID string
	string ID = tempString;
	lhs = rhs + 1;
	// parse nameFirst and "" "" 
	rhs = studentString.find(',', lhs);
	tempString = studentString.substr(lhs, rhs - lhs);			// GET FIRST NAME string
	string nameFirst = tempString;
	lhs = rhs + 1;
	// parse nameLast and "" "" 
	rhs = studentString.find(',', lhs);
	tempString = studentString.substr(lhs, rhs - lhs);			// GET LAST NAME string
	string nameLast = tempString;
	lhs = rhs + 1;

	// parse email and "" "" 
	rhs = studentString.find(',', lhs);
	tempString = studentString.substr(lhs, rhs - lhs);			// GET EMAIL string
	string email = tempString;
	lhs = rhs + 1;

	// parse age and "" " 
	rhs = studentString.find(',', lhs);
	tempString = studentString.substr(lhs, rhs - lhs);			// GET AGE int
	int age = stoi(tempString);
	//*tempInt = stoi(tempString);
	lhs = rhs + 1;

	// parse each numDaysToComplete to their own array 

		rhs = studentString.find(',', lhs);
		tempString = studentString.substr(lhs, rhs - lhs);			// GET NUMDAYS[0] int
		int numDays[3] = { 0, 0, 0 };
		numDays[0]  = stoi(tempString);
		lhs = rhs + 1;

		rhs = studentString.find(',', lhs);
		tempString = studentString.substr(lhs, rhs - lhs);			// GET NUMDAYS[1] int
		numDays[1] = stoi(tempString);
		lhs = rhs + 1;

		rhs = studentString.find(',', lhs);
		tempString = studentString.substr(lhs, rhs - lhs);			// GET NUMDAYS[2] int
		numDays[2] = stoi(tempString);
		lhs = rhs + 1;

	// parse degreeProgram 

	rhs = studentString.find(',', lhs);
	tempString = studentString.substr(lhs, rhs - lhs);			// GET DEGREEPROGRAM DegreeProgram
	string degreeProgramString = tempString;
	DegreeProgram degreeProgram;

	if (degreeProgramString == "SECURITY")
	{
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeProgramString == "NETWORK")
	{
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE")
	{
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	// combine properties into a new student

	//cout << "Parse called " << counter << " times.";

	Add(ID, nameFirst, nameLast, email, age, numDays[0], numDays[1], numDays[2], degreeProgram);

}


/*
		TO DO:

		1) FINISH POLISHING PARSE		(DONE)
		2) FIX ADD
		3) FIX REMOVE (SET TO NULLPTR)
		4) DOUBLE CHECK STUDENT WILL WORK WITH NEW FUNCTIONS


*/