#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>
#include <vector>

#include "person.h"
#include "course.h"

using namespace std;

class Course;

class Professor: public Person {
private:
    vector<Course*> coursesTeaching;
public:
    Professor();
    Professor(string f, string l, string e, long int ph);

    void printCourseStatistics() const; //const beacause it does not change the object it is called on (it is a getter)

    // Function to assign a course to the professor
    // (καλειται απο την assignProfessor της Course)
    void assignCourse(Course& course);

    // getter
    vector<Course*> getCoursesTeaching() const;

    friend ostream &operator<<(ostream &ostr, Professor &professor);
};

#endif