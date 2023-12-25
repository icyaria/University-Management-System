#include "student.h"

using namespace std;

        Student::Student() {
            sem_s = 0;
            ects_s = 0;
        }

        Student::Student(string f, string l, string e, long int ph, int sem, int ects) : Person(f, l, e, ph) {
            sem_s = sem;
            ects_s = ects;
        }