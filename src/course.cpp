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
        professorsTeaching.clear();
        students.clear();
        studentsPassed.clear();
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

    vector<Professor*> &Course::getProfessorsTeaching() {
        return professorsTeaching;
    }

    vector<Student*> &Course::getEnrolledStudents() {
        return students;
    }

    vector<Student*> &Course::getStudentsPassed() {
        return studentsPassed;
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
        cout << "Enrolled to " << course_name << endl;
        students.push_back(&student);
    }

    void Course::assignPassedStudent(Student &student) {
        studentsPassed.push_back(&student);
    }

    void Course::printProfessorsTeaching() {
        cout << "\nProfessors teaching this course: " << endl;

        if(!professorsTeaching.empty()) {
            for (size_t i = 0; i < professorsTeaching.size(); i++) {
                cout << professorsTeaching.at(i)->getFirstName() << " "<< professorsTeaching.at(i)->getLastName() << endl;
            }
        }
        else {
            cout << "No professors available." << std::endl;
        }
    }

    void Course::printEnrolledStudents() {
        cout << "\nStudents enrolled to this course: " << endl;

        if(!students.empty()) {
            for (size_t i = 0; i < students.size(); i++) {
                cout << students.at(i)->getFirstName() << " "<< students.at(i)->getLastName() << endl;
            }
        }
        else {
            cout << "No students available." << std::endl;
        }
    }

    istream &operator>>(istream &istr, Course &course) {
        cout << "Course name: ";
        istr >> course.course_name;
        cout << "Code: ";
        istr >> course.code;
        try {
            cout << "Semester: ";
            istr >> course.sem;
            if (istr.fail()) {
                throw runtime_error("Invalid input for semester.");
            }

            cout << "ECTS: ";
            istr >> course.ects;
            if (istr.fail()) {
                throw runtime_error("Invalid input for ECTS.");
            }

            cout << "Compulsory (1 for yes, 0 for no): ";
            istr >> course.comp;
            if (istr.fail()) {
                throw runtime_error("Invalid input for compulsory.");
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            istr.clear();
            istr.ignore(numeric_limits<streamsize>::max(), '\n');
            return operator>>(istr, course);
        }
        return istr;
    }

    ostream &operator<<(ostream &ostr, Course &course) {
        ostr << "Course:" << course.course_name << endl << "Code: " << course.code << endl;
        return ostr;
    }



