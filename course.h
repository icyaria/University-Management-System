#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

#include "student.h"

using namespace std;

class Professor; // forward declaration
// it tells the compiler that the class Professor exists before the actual definition becomes available
// *ΓΙΑ ΕΜΑΣ ΜΟΝΟ*
// This is sufficient for the compiler to know that such a class exists, 
// which allows you to use pointers or references to that class in your 
// header file without requiring the full definition

class Course {
private:
    string course_name;
    string code;
    int sem;
    int ects;
    bool comp;
    vector<Professor*> professorsTeaching;
public:
    // default constructor
    Course();

    Course(string cn, string c, int s, int e, bool co);

    // destructor
    ~Course();

    // getters και setters
    string getCourseName() const;
    //void setCourseName(string newCN);

    string getCode() const;
    //void setCode(string newCode);

    int getSem() const;
    void setSem(int newSem);

    int getEcts() const;
    //void setEcts(int newEcts);

    bool getComp() const;
    //void setComp(bool newComp); 

    
    // assigns a professor to the course and calls function
    // to add the course to the professor's teaching courses 
    // (η secretary καλεί αυτή τη συνάρτηση)
    void assignProfessor(Professor &professor);

};

#endif 