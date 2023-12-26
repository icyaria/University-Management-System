#include "course.h"
#include "professor.h"

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

    void Course::assignProfessor(Professor &professor) {
        cout << "Assigning " << professor.getFirstName() << " " << professor.getLastName() << " to " << course_name << endl;
        professorsTeaching.push_back(&professor);
        professor.assignCourse(*this);
    }



