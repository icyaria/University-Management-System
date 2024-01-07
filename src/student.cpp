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
            cout << "Enter phone: ";
            istr >> ph;
            student.setPhone(ph);

            // Input additional Student information
            cout << "Enter student ID: ";
            istr >> student.AM;
            cout << "Enter semester: ";
            istr >> student.sem_s;
            cout << "Enter ECTS: ";
            istr >> student.ects_s;

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
            //course.assignStudent(*this);
        }