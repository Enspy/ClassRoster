#include "student.h"
#include "degree.h"
#include <iostream>
using std::cout;
using std::endl;



// Constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    // Loop through each element of the daysToComplete array
    for (int i = 0; i < 3; ++i) {
    // Copy the value from daysToComplete array to the corresponding element in the daysInCourse array
        this->daysInCourse[i] = daysToComplete[i];
    }
}

// Destructor Student::~Student() {}

// Getters

string Student::GetStudentID() const {
    return studentID;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

const int* Student::GetDaysToComplete() const {
    return daysInCourse;
}

// Setters

void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
    this->age = age;
}

void Student::SetDaysToComplete(const int daysToComplete[3]) {
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysToComplete[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Print Student Information

void Student::Print() const {
    cout << GetStudentID() << "\t";
    cout << "First Name: " << GetFirstName() << "\t";
    cout << "Last Name: " << GetLastName() << "\t";
    cout << "Age: " << GetAge() << "\t";
    cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} ";
    cout << "Degree Program: ";

 if (degreeProgram == DegreeProgram::SECURITY) {
    cout << "SECURITY ";
} else if (degreeProgram == DegreeProgram::NETWORK) {
    cout << "NETWORK ";
} else if (degreeProgram == DegreeProgram::SOFTWARE) {
   cout << "SOFTWARE ";
} else {
    cout << "Degree program not found.";
}
}
