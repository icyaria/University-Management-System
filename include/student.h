#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "person.h"
#include "course.h"

using namespace std;

class Course;

class Student: public Person {
private:
    int sem_s;
    int ects_s;
    long int AM;
    vector<Course*> my_courses;
    vector<Course*> passed_courses;
public:
    // constructors
    Student();
    Student(string f, string l, string e, long int ph, int sem, int ects, long int am);

    //copy constructor
    Student(const Student &student);

    //destructor
    ~Student();

    //getters and setters
    int getSem() const;
    void setSem(int newSem);
    int getEcts() const;
    void setEcts(int newEcts);
    long int getAM() const;
    void setAM(long int newAM);
    vector<Course*> &getMyCourses();
    vector<Course*> &getPassedCourses();

    //overloading operators
    friend istream &operator>>(istream &istr, Student &student);
    friend ostream &operator<<(ostream &ostr, Student &student);

    void assignCourse(Course& course);
    void assignPassedCourse(Course& course);
};

#endif