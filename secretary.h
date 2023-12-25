#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "student.h"
#include "professor.h"
#pragma once

using namespace std;

class Secretary {
private:
    vector<Student*> vecs;
    vector<Professor*> vecp;
    
public:

    // constructor 
    Secretary();

    // Copy constructor
    Secretary(const Secretary &sec);

    // destructor
    ~Secretary();

    // Function to add new professor or student to secretary
    void add(Professor &p);
    void add(Student &s);

    // Searches for professor or student in secretary
    bool find_professor(Secretary &sec, Professor &professor);
    bool find_student(Secretary &sec, Student &student);
    
    // Overloading operator >> and << for output and input
    friend istream &operator>>(istream &istr, Secretary &secretary);

    friend ostream &operator<<(ostream &ostr, Secretary &secretary);

    // Overloading operator + for adding person to secretary
    Secretary& operator+(Professor &professor);
    Secretary& operator+(Student &student);

    // Overloading operator = for assignment
    Secretary operator=(const Secretary &sec);
 
};