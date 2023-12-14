#include <iostream>
#include <string>
#include "course.h"

using namespace std;

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

    bool Course::getOpt() const {
        return opt;
    }

    //setter
    void Course::setSem(int newSem) {
        sem = newSem;
    }



