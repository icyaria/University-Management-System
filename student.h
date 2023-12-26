#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "person.h"

using namespace std;

class Student: public Person {
private:
    int sem_s;
    int ects_s;
    long int AM;
public:
    Student();
    Student(string f, string l, string e, long int ph, int sem, int ects, long int am);
    int getSem() const;
    void setSem(int newSem);
    int getEcts() const;
    void setEcts(int newEcts);
};

#endif