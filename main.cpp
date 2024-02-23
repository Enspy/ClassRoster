#include <iostream>
#include "roster.h"
#include "degree.h"
#include <sstream>
using namespace std;

// Given student data
const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
"A5,Santiago,Campos,scam588@wgu.edu,21,22,43,21,SOFTWARE"
};

// Helper function to convert DegreeProgram enum to a string
DegreeProgram stringToDegreeProgram(const string& str) {
    if (str == "SECURITY") return DegreeProgram::SECURITY;
    else if (str == "NETWORK") return DegreeProgram::NETWORK;
    else if (str == "SOFTWARE") return DegreeProgram::SOFTWARE;
    else throw invalid_argument("Invalid degree program: " + str);
}

int main() {
    cout << "Scripting and Applications, C++ Programming, Scam588, Santiago Campos\n";

    // Creating instance of the Roster Class
    Roster classRoster;

    // Add each student to classRoster using the add function
        for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); i++) {
        string input = studentData[i];
        istringstream ss(input);
        string token;
        vector<string> tokens;

        // Uses the getline method in a loop to extract tokens from the string stream until a comma is encountered
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        try {
            // Convert the string representation of the DegreeProgram to enum
            DegreeProgram dp = stringToDegreeProgram(tokens[8]);
            // Add student to the roster using extracted tokens
            classRoster.Add(tokens[0], tokens[1], tokens[2], tokens[3], stoi(tokens[4]), stoi(tokens[5]), stoi(tokens[6]), stoi(tokens[7]), dp);
        } catch (const invalid_argument& e) {
            // Print error message to standard error
            cerr << "Error adding student: " << e.what() << endl;
        }
    }
    
    // Print all function
    cout << "Printing all students: " << endl;
    classRoster.printAll();
    
    // Print invalid emails
    cout << "Printing invalid emails: " << endl;
    classRoster.printInvalidEmails();

    // Print average days in course
     cout << "Printing average days in course for each student: " << endl;
     
     // loop through classRosterArray and for each element 
     for (int i = 0; i <= classRoster.getLastIndex(); i++ ){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
     }
    
    // Print by degree program
    cout << "Printing students by degree program: " << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    cout << endl;

    // Remove a student and print all students
    cout << "Removing student with ID A3..." << endl;
    classRoster.Remove("A3");
    cout << "Printing all students after removal: " << endl;
    classRoster.printAll();

    // Attempt to remove a student that doesn't exist
    cout << "Attempting to remove student with ID A3 again: " << endl;
    classRoster.Remove("A3");


    return 0;
}
