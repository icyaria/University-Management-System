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

        int Student::getSem() const {
            return sem_s;
        }

        void Student::setSem(int newSem) {
            cout << "Semester changed to: " << newSem << endl;
            cout << "\n" << endl;
            sem_s = newSem;
        }

        int Student::getEcts() const {
            return ects_s;
        }

        void Student::setEcts(int newEcts) {
            cout << "ECTS changed to: " << newEcts << endl;
            cout << "\n" << endl;
            ects_s = newEcts;
        }