#include <iostream>
#include <string>
#include "course.h"

using namespace std;

    // default constructor
    Course::Course() {
        course_name = "";
        code = "";
        sem = 0;
        ects = 0;
        comp = false;
    }

    Course::Course(string cn, string c, int s, int e, bool co) {
        course_name = cn;
        code = c;
        sem = s;
        ects = e;
        comp = co;
    }

    // destructor
    Course::~Course() {
    }

    //getters
    string Course::getCourseName() const {
        return course_name;
    }

    string Course::getCode() const {
        return code;
    }

    int Course::getSem() const {
        return sem;
    }

    int Course::getEcts() const {
        return ects;
    }

    bool Course::getComp() const {
        return comp;
    }

    //setter (θα πρέπει να δίνεται η δυνατότητα να μετακινηθούν μεταξύ semesters)
    void Course::setSem(int newSem) {
        sem = newSem;
    }



