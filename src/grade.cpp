#include "grade.h"

Grade::Grade() {
    grade = 0;
    studentAM = 0;
    courseCode = "";
}

Grade::~Grade() {
}

int Grade::getGrade() const {
    return grade;
}

void Grade::setGrade(int newGrade) {
    grade = newGrade;
}

long int Grade::getStudentAM() const {
    return studentAM;
}

void Grade::setStudentAM(long int newStudentAM) {
    studentAM = newStudentAM;
}

string Grade::getCourseCode() const {
    return courseCode;
}

void Grade::setCourseCode(string newCourseCode) {
    courseCode = newCourseCode;
}
