#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>
#include <vector>

#include "person.h"
#include "course.h"
#include "secretary.h"

using namespace std;

class Course;

class Professor: public Person {
private:
    vector<Course*> coursesTeaching;
public:
    Professor();
    Professor(string f, string l, string e, long int ph);

    // copy constructor
    Professor(const Professor &professor);    

    // destructor
    ~Professor();

    // getter
    vector<Course*> &getCoursesTeaching();

    void printCoursesTeaching(ostream& ostr);

    void printCourseStatistics(Secretary &sec) const;

    // Function to assign a course to the professor
    void assignCourse(Course& course);

};

#endif