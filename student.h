#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class Student: public Person {
private:
    int sem_s;
    int ects_s;
};