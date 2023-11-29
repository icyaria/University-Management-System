#include <iostream>
#include <string>
#include <vector>

#include "secretary.h"

using namespace std;

        Secretary::Secretary() {
                
        }

        Secretary::~Secretary() {
                int size = vec.size();              
                 for (int i = 0; i < size; i++) {
                        delete vec.at(i);
                         cout<< "deleted pointer" <<endl;
                }
                cout << "Deconstructed secretary" << endl;
                vec.clear();  // Clear the vector after deleting its elements
        }

        void Secretary::add(Person &p) {
                Person* newp = new Person(p);
                vec.push_back(newp);
                cout<<"Added Person in vector"<<endl;
        }

        bool Secretary::find_person(Secretary &sec, Person &person) {
                int size = sec.vec.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vec.at(i)->getFirstName() == person.getFirstName() &&
                            sec.vec.at(i)->getLastName() == person.getLastName() &&
                            sec.vec.at(i)->getEmail() == person.getEmail() &&
                            sec.vec.at(i)->getPhone() == person.getPhone()) {
                                cout << "Found Person "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                                return true;
                        }
                }
                cout << "Couldn't find Person "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                return false;
        }

        istream &operator>>(istream &istr, Secretary &secretary) {
                cout << "Enter person's details to add to secretary: " << endl;
                Person* newPerson = new Person;  
                istr >> *newPerson;           
                secretary.add(*newPerson);
                return istr;
        }


        ostream &operator<<(ostream &ostr, Secretary &secretary) {
                ostr << "People in secretary are: " << endl;
                for (int i = 0; i<secretary.vec.size(); i++) {
                     cout<< *secretary.vec.at(i)<< endl;
                }
                return ostr;
        }

        Secretary& Secretary::operator+(Person &person) {
                add(person);
                return *this;                 
        }

        Secretary::Secretary(const Secretary &sec) {
                
        }

