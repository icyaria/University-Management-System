#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Grade {
private:
    int grade;
    long int studentAM;
    string courseCode;
public:
    //default constructor
    Grade();

    //constructor
    Grade(int newGrade, long int newStudentAM, string newCourseCode);

    //destructor
    ~Grade();

    //getters and setters
    int getGrade() const;
    void setGrade(int newGrade);
    
    long int getStudentAM() const;
    void setStudentAM(long int newStudentAM);

    string getCourseCode() const;
    void setCourseCode(string newCourseCode);
};

#endif