#include <iostream>
#include <string>
#pragma once
#include "person.h"
#include "course.h"

using namespace std;

class Professor: public Person {
private:
    vector<Course*> coursesTeaching;
public:
    Professor();
    Professor(string f, string l, string e, long int ph);

    void printCourseStatistics() const; //const beacause it does not change the object it is called on (it is a getter)

    // Function to assign a course to the professor
    void assignCourse(Course& course);
};