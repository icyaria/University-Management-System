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

    // Searches for a professor from the professor vector
    bool find_professor(Secretary &sec, Professor &professor);

    // Searches for a student from the student vector
    bool find_student(Secretary &sec, Student &student);

    //Searches for a person in all secretary either professor or student
    bool find_person(Secretary &sec, Person &person);
    
    // Overloading operator >> and << for output and input
    friend istream &operator>>(istream &istr, Secretary &secretary);

    friend ostream &operator<<(ostream &ostr, Secretary &secretary);

    // Overloading operator + for adding person to secretary
    Secretary& operator+(Professor &professor);
    Secretary& operator+(Student &student);

    // Overloading operator = for assignment
    Secretary operator=(const Secretary &sec);
 
};