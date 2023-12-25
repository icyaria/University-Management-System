#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class Professor: public Person {
public:
    Professor();
    Professor(string f, string l, string e, long int ph);
};