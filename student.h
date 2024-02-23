#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using std::string;

class Student {
public:
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeprogram);
    // Getters for each instance variable from part D1
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string getEmailAddress() const;
    DegreeProgram getDegreeProgram() const;
    int GetAge() const;
    const int* GetDaysToComplete() const; // returns a pointer to the array of daysToComplete

    // Setters for each instance variable from part D1
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysToComplete(const int daysToComplete[3]); // Takes array of 3 integers
    void SetDegreeProgram(DegreeProgram degreeProgram);

    // Print Student Information
    void Print() const;
    
private:
// Student data
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
// Array that holds the days to complete 3 courses
    int daysInCourse[3];
    DegreeProgram degreeProgram;
};

#endif