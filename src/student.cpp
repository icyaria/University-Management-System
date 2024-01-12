#include "student.h"

using namespace std;

        Student::Student() {
            sem_s = 1;
            ects_s = 0;
            AM = 0;
        }

        Student::Student(string f, string l, string e, long int ph, int sem, int ects, long int am) : Person(f, l, e, ph) {
            sem_s = sem;
            ects_s = ects;
            AM = am;
        }

        Student::Student(const Student &student) : Person(student) {
            sem_s = student.sem_s;
            ects_s = student.ects_s;
            AM = student.AM;
        }

        Student::~Student() {
            my_courses.clear();
            passed_courses.clear();
        }

        int Student::getSem() const {
            return sem_s;
        }

        void Student::setSem(int newSem) {
            sem_s = newSem;
        }

        int Student::getEcts() const {
            return ects_s;
        }

        void Student::setEcts(int newEcts) {
            ects_s = newEcts;
        }

        long int Student::getAM() const {
            return AM;
        }

        void Student::setAM(long int newAM) {
            cout << "\n" << endl;
            AM = newAM;
        }

        vector<Course*> &Student::getMyCourses() {
            return my_courses;
        }

        vector<Course*> &Student::getPassedCourses() {
            return passed_courses;
        }

        istream &operator>>(istream &istr, Student &student) {
            string f, l, e;
            long int ph;
            cout << "Enter first name: ";   
            istr >> f;
            student.setFirstName(f);
            cout << "Enter last name: ";
            istr >> l;
            student.setLastName(l);
            cout << "Enter email: ";
            istr >> e;
            student.setEmail(e);

            try {
                cout << "Enter phone: ";
                istr >> ph;
                if (istr.fail()) {
                    throw runtime_error("Invalid input for phone.");
                }
                student.setPhone(ph);
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                return operator>>(istr, student);
            }

            // Input additional Student information
            try {
                cout << "Enter student ID: ";
                istr >> student.AM;
                if (istr.fail()) {
                    throw runtime_error("Invalid input for student ID.");
                }

                cout << "Enter semester: ";
                istr >> student.sem_s;
                if (istr.fail()) {
                    throw runtime_error("Invalid input for semester.");
                }

                cout << "Enter ECTS: ";
                istr >> student.ects_s;
                if (istr.fail()) {
                    throw runtime_error("Invalid input for ECTS.");
                }
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                return operator>>(istr, student);
            }
            return istr;
        }

        ostream &operator<<(ostream &ostr, Student &student) {
            ostr << "First name: " << student.getFirstName() << endl
                << "Last name: " << student.getLastName() << endl
                << "Email: " << student.getEmail() << endl
                << "Phone: " << student.getPhone() << endl;

            // Output additional Student information
            ostr << "Student ID: " << student.AM << endl;
            ostr << "Semester: " << student.sem_s << endl;
            ostr << "ECTS: " << student.ects_s << endl;

            return ostr;
        }

        void Student::assignCourse(Course& course) {
            my_courses.push_back(&course);
        }

        void Student::assignPassedCourse(Course& course) {
            passed_courses.push_back(&course);
        }