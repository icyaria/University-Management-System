#include <iostream>
#include <string>
#include <vector>

#include "secretary.h"

using namespace std;

        Secretary::Secretary() {
        }

        Secretary::Secretary(const Secretary &sec) { //copy constructor
                for (int i = 0; i<sec.vecp.size(); i++) {
                        Professor* newProfessor = new Professor(*sec.vecp.at(i));  
                        vecp.push_back(newProfessor);
                }
                for (int i = 0; i<sec.vecs.size(); i++) {
                        Student* newStudent = new Student(*sec.vecs.at(i));  
                        vecs.push_back(newStudent);
                }
        }

        Secretary::~Secretary() {
                int sizep = vecp.size();
                int sizes = vecs.size();              
                 for (int i = 0; i < sizep; i++) {
                        delete vecp.at(i);
                }
                for (int i = 0; i < sizes; i++) {
                        delete vecs.at(i);
                }
                vecp.clear();  
                vecs.clear();// Clear the vector after deleting its elements
        }

        void Secretary::add(Professor &p) {
                Professor* newp = new Professor(p);
                vecp.push_back(newp);
                cout<<"\nAdded "<<p.getFirstName()<<" "<<p.getLastName() <<" in Secretary"<<endl;
        }
        
        void Secretary::add(Student &s) {
                Student* news = new Student(s);
                vecs.push_back(news);
                cout<<"\nAdded "<<s.getFirstName()<<" "<<s.getLastName() <<" in Secretary"<<endl;
        }


        bool Secretary::find_professor(Secretary &sec, Professor &professor) {
                cout << "\nSearching for "<< professor.getFirstName() << " " << professor.getLastName() << " in Secretary" << endl;
                int size = sec.vecp.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecp.at(i)->getFirstName() == professor.getFirstName() &&
                            sec.vecp.at(i)->getLastName() == professor.getLastName() &&
                            sec.vecp.at(i)->getEmail() == professor.getEmail() &&
                            sec.vecp.at(i)->getPhone() == professor.getPhone()) {
                                cout << "Found Professor "<< professor.getFirstName() << " " << professor.getLastName() << " in Secretary" << endl;
                                cout << "\n" << endl;
                                return true;
                        }
                }
                cout << "Couldn't find Professor "<< professor.getFirstName() << " " << professor.getLastName() << " in Secretary" << endl;
                cout << "\n" << endl;
                return false;
        }

        bool Secretary::find_student(Secretary &sec, Student &student) {
                cout << "\nSearching for "<< student.getFirstName() << " " << student.getLastName() << " in Secretary" << endl;
                int size = sec.vecs.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecs.at(i)->getFirstName() == student.getFirstName() &&
                            sec.vecs.at(i)->getLastName() == student.getLastName() &&
                            sec.vecs.at(i)->getEmail() == student.getEmail() &&
                            sec.vecs.at(i)->getPhone() == student.getPhone() &&
                            sec.vecs.at(i)->getSem() == student.getSem() &&
                            sec.vecs.at(i)->getEcts() == student.getEcts()) {
                                cout << "Found Student "<< student.getFirstName() << " " << student.getLastName() << " in Secretary" << endl;
                                cout << "\n" << endl;
                                return true;
                        }
                }
                cout << "Couldn't find Student "<< student.getFirstName() << " " << student.getLastName() << " in Secretary" << endl;
                cout << "\n" << endl;
                return false;
        }

        //Operators overloading
        istream &operator>>(istream &istr, Secretary &secretary) {
                cout << "Enter professor or student? (p/s)" << endl;
                string choice;
                istr >> choice;
                if (choice == "p") {
                        cout << "Enter professor's details to add to secretary: " << endl;
                        Professor* newProfessor = new Professor;  
                        istr >> *newProfessor; // inputs information from user           
                        secretary.add(*newProfessor);
                        return istr;
                }
                else if (choice == "s") {
                        cout << "Enter student's details to add to secretary: " << endl;
                        Student* newStudent = new Student;  
                        istr >> *newStudent; // inputs information from user           
                        secretary.add(*newStudent);
                        return istr;
                }
                else {
                        cout << "Wrong input" << endl;
                        return istr;
                }
        }


        ostream &operator<<(ostream &ostr, Secretary &secretary) {
                ostr << "Professors in secretary are: " << endl;
                for (int i = 0; i<secretary.vecp.size(); i++) {
                     cout<< *secretary.vecp.at(i)<< endl; // prints all professors in secretary
                }
                ostr << "Students in secretary are: " << endl;
                for (int i = 0; i<secretary.vecs.size(); i++) {
                     cout<< *secretary.vecs.at(i)<< endl; // prints all students in secretary
                }
                return ostr;
        }

        Secretary& Secretary::operator+(Professor &professor) {
                add(professor);
                return *this;                 
        }

        Secretary& Secretary::operator+(Student &student) {
                add(student);
                return *this;                 
        }

        Secretary Secretary::operator=(const Secretary &sec) {
                for (int i = 0; i<sec.vecp.size(); i++) {
                        Professor* newProfessor = new Professor(*sec.vecp.at(i));  
                        vecp.push_back(newProfessor);
                }
                for (int i = 0; i<sec.vecs.size(); i++) {
                        Student* newStudent = new Student(*sec.vecs.at(i));  
                        vecs.push_back(newStudent);
                }
                return *this;
        }
