#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "degree.h"
#include <string>


class Roster {
public:
    
    Roster(); // Constructor
    ~Roster(); // Destructor
    void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove(string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    int getLastIndex() const; 
    Student* classRosterArray[5];
    

private:
    int lastIndex; // To Keep Track of the last student added
    int capacity; // Max number of students the roster can hold
};

#endif
