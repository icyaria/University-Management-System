#include <iostream>
#include <string>
#pragma once
#include "person.h"

using namespace std;

class Student: public Person {
private:
    int sem_s;
    int ects_s;
public:
    Student();
    Student(string f, string l, string e, long int ph, int sem, int ects);
    int getSem() const;
    void setSem(int newSem);
    int getEcts() const;
    void setEcts(int newEcts);
};