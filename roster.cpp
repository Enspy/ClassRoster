#include "roster.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;


// Constructor
Roster::Roster() : lastIndex(-1), capacity(5) {
    // Initialize the classRosterArray with nullptrs
    for (int i = 0; i < capacity; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor to release allocated memory
Roster::~Roster() {
    for (int i = 0; i < 5; i++) { // Clean up allocated memory
        delete classRosterArray[i];
    }
}



// Add function
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3}; // Aggregate days into an array
    // Increment lastIndex before using it to ensure the student is added at the correct index
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}

// Remove function
void Roster::Remove(std::string studentID) { 
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID){
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex]; // Move the last element to the removed spot
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            break;
        } 
    }
    
    // Error message if Student ID is not found
    if(!found) {
        cout << "Error: Student with ID " << studentID << " not found." << endl;
    }
}

// Print all function
// Added custom widths to columns for better organization
void Roster::printAll() const {
    cout << left << setw(12) << "Student ID";
    cout << left << setw(12) << "First Name";
    cout << left << setw(12) << "Last Name";
    cout << left << setw(6) << "Age";
    cout << left << setw(22) << "Days in Course";
    cout << left << setw(6) << "Degree Program" << endl;

    for (int i = 0; i <= lastIndex; i++) {
        cout << left << setw(12) << classRosterArray[i]->GetStudentID();
        cout << left << setw(12) << classRosterArray[i]->GetFirstName();
        cout << left << setw(12) << classRosterArray[i]->GetLastName();
        cout << left << setw(6) << classRosterArray[i]->GetAge();
        const int* days = classRosterArray[i]->GetDaysToComplete();
        cout << "{" << days[0] << ", " << days[1] << ", " << days[2] << "}" << right << setw(18);
        DegreeProgram degreeProgram = classRosterArray[i]->getDegreeProgram();
        if (degreeProgram == DegreeProgram::SECURITY) {
            cout << "SECURITY";
        } else if (degreeProgram == DegreeProgram::NETWORK) {
            cout << "NETWORK";
        } else if (degreeProgram == DegreeProgram::SOFTWARE) {
            cout << "SOFTWARE";
        }
        cout << endl;
    }
}

// Print Average Days in Course

void Roster::printAverageDaysInCourse(string studentID) const{
    for (int i = 0; i <= lastIndex; i++){
        if (classRosterArray[i]->GetStudentID() == studentID){
            auto* days = classRosterArray[i]->GetDaysToComplete();
            cout << "Average days for student ID " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
}

// Print invalid email function
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++ ) {
        string email = classRosterArray[i]->getEmailAddress();

        // Check for '@' and '.' and ' ' in the email address
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << email << endl;
        }
    }
}

// print by degree program function
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}

int Roster::getLastIndex() const {
    return lastIndex;
}