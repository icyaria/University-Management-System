#include <iostream>
#include <string>
#include <vector>

#include "secretary.h"

using namespace std;

        Secretary::Secretary() {
        }

        Secretary::Secretary(const Secretary &sec) { //copy constructor
                for (int i = 0; i<sec.vec.size(); i++) {
                        Person* newPerson = new Person(*sec.vec.at(i));  
                        vec.push_back(newPerson);
                }
        }

        Secretary::~Secretary() {
                int size = vec.size();              
                 for (int i = 0; i < size; i++) {
                        delete vec.at(i);
                }
                vec.clear();  // Clear the vector after deleting its elements
        }

        void Secretary::add(Person &p) {
                Person* newp = new Person(p);
                vec.push_back(newp);
                cout<<"\nAdded "<<p.getFirstName()<<" "<<p.getLastName() <<" in Secretary"<<endl;
        }

        bool Secretary::find_person(Secretary &sec, Person &person) {
                cout << "\nSearching for "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                int size = sec.vec.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vec.at(i)->getFirstName() == person.getFirstName() &&
                            sec.vec.at(i)->getLastName() == person.getLastName() &&
                            sec.vec.at(i)->getEmail() == person.getEmail() &&
                            sec.vec.at(i)->getPhone() == person.getPhone()) {
                                cout << "Found Person "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                                cout << "\n" << endl;
                                return true;
                        }
                }
                cout << "Couldn't find Person "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                cout << "\n" << endl;
                return false;
        }

        //Operators overloading
        istream &operator>>(istream &istr, Secretary &secretary) {
                cout << "Enter person's details to add to secretary: " << endl;
                Person* newPerson = new Person;  
                istr >> *newPerson; // inputs information from user           
                secretary.add(*newPerson);
                return istr;
        }


        ostream &operator<<(ostream &ostr, Secretary &secretary) {
                ostr << "People in secretary are: " << endl;
                for (int i = 0; i<secretary.vec.size(); i++) {
                     cout<< *secretary.vec.at(i)<< endl; // prints all people in secretary
                }
                return ostr;
        }

        Secretary& Secretary::operator+(Person &person) {
                add(person);
                return *this;                 
        }

        Secretary Secretary::operator=(const Secretary &sec) {
                for (int i = 0; i<sec.vec.size(); i++) {
                        Person* newPerson = new Person(*sec.vec.at(i));  
                        vec.push_back(newPerson);
                }
                return *this;
        }
