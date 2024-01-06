#include "course.h"
#include "professor.h"
#include "student.h"

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

    vector<Professor*> Course::getProfessorsTeaching() const {
        return professorsTeaching;
    }

    //setter (θα πρέπει να δίνεται η δυνατότητα να μετακινηθούν μεταξύ semesters)
    void Course::setSem(int newSem) {
        sem = newSem;
    }

    void Course::assignProfessor(Professor &professor) {
        cout << "Assigning " << professor.getFirstName() << " " << professor.getLastName() << " to " << course_name << endl;
        professorsTeaching.push_back(&professor);
    }

    void Course::assignStudent(Student &student) {
        cout << "Assigning " << student.getFirstName() << " " << student.getLastName() << " to " << course_name << endl;
        students.push_back(&student);
        student.assignCourse(*this);
    }

    void Course::printProfessorsTeaching() {
        cout << "\nProfessors teaching this course: " << endl;

        if(!professorsTeaching.empty()) {
            for (size_t i = 0; i < professorsTeaching.size(); i++) {
                cout << professorsTeaching.at(i)->getFirstName() << " "<< professorsTeaching.at(i)->getFirstName() << endl;
            }
        }
        else {
            cout << "No professors available." << std::endl;
        }
    }

    istream &operator>>(istream &istr, Course &course) {
        cout << "Course name: ";
        istr >> course.course_name;
        cout << "Code: ";
        istr >> course.code;
        cout << "Semester: ";
        istr >> course.sem;
        cout << "ECTS: ";
        istr >> course.ects;
        cout << "Compulsory (1 for yes, 0 for no): ";
        istr >> course.comp;
        return istr;
    }

    ostream &operator<<(ostream &ostr, Course &course) {
        ostr << "Course:" << course.course_name << endl << "Code: " << course.code << endl;
        return ostr;
    }



