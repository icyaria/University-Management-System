#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "student.h"

using namespace std;

// forward declaration
class Professor;
class Student; 
class Secretary;


class Course {
private:
    string course_name;
    string code;
    int sem;
    int ects;
    bool comp;
    vector<Professor*> professorsTeaching;
    vector<Student*> students;
    vector<Student*> studentsPassed;
public:
    // default constructor
    Course();

    Course(string cn, string c, int s, int e, bool co);

    // destructor
    ~Course();

    // getters και setters
    string getCourseName() const;

    string getCode() const;

    int getSem() const;

    int getEcts() const;

    bool getComp() const;

    vector<Professor*> &getProfessorsTeaching();

    vector<Student*> &getEnrolledStudents();

    vector<Student*> &getStudentsPassed();

    void setSem(int newSem);
    
    // assigns a professor to the course 
    void assignProfessor(Professor &professor);

    // enroll a student to the course
    void assignStudent(Student &student);

    // assign a student to the passed students vector
    void assignPassedStudent(Student &student);

    // prints the professors teaching the course
    void printProfessorsTeaching();

    // prints the students enrolled in the course
    void printEnrolledStudents();

    // overload operators for reading and writing
    friend istream &operator>>(istream &istr, Course &course);
    friend ostream &operator<<(ostream &ostr, Course &course);
};

#endif 