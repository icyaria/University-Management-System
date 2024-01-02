#ifndef SECRETARY_H
#define SECRETARY_H

#include <iostream>
#include <string>
#include <vector>

#include "student.h"
#include "professor.h"
#include "course.h"

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

    // Getters
    vector<Professor*> getProfessors() const;
    vector<Student*> getStudents() const;

    // Function to add new professor or student to secretary
    void add(Professor &p);
    void add(Student &s);

    // Function to delete a professor or student from secretary
    void remove(Professor &p);
    void remove(Student &s);

    // Searches for a professor from the professor vector
    bool find_professor(Secretary &sec, Person &professor);

    // Searches for a student from the student vector
    bool find_student(Secretary &sec, Person &student);

    //Searches for a person in all secretary either professor or student
    bool find_person(Secretary &sec, Person &person);
    
    // Overloading operator >> and << for output and input
    friend istream &operator>>(istream &istr, Secretary &secretary);

    friend ostream &operator<<(ostream &ostr, Secretary &secretary);

    // print professors or students
    ostream &printProfessors(ostream &ostr);
    ostream &printStudents(ostream &ostr);

    // Overloading operator + for adding person to secretary
    Secretary& operator+(Professor &professor);
    Secretary& operator+(Student &student);

    // Overloading operator = for assignment
    Secretary operator=(const Secretary &sec);
 
    // sets up a new semester
    void new_semester(Secretary &sec);

    // calls assignCourse of professor which calls assignProfessor of course
    void assignProfessorToCourse(Professor& professor, Course& course);

    void assignStudentToCourse(Student& student, Course& course);
};

#endif