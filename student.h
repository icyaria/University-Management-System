#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class Student: public Person {
private:
    int sem_s;
    int ects_s;
public:
    Student();
    Student(string f, string l, string e, long int ph, int sem, int ects);
};