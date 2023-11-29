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
                         cout<< "deleted something" <<endl;
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
                for (int i = 0; i<sec.vec.size(); i++) {
                        //cout << "Comparing: " << sec.vec.at(i)->getFirstName() << " with " << person.getFirstName() << endl;
                        if (sec.vec.at(i)->getFirstName() == person.getFirstName() &&
                            sec.vec.at(i)->getLastName() == person.getLastName() &&
                            sec.vec.at(i)->getEmail() == person.getEmail() &&
                            sec.vec.at(i)->getPhone() == person.getPhone()) {
                                return true;
                        }
                }
                return false;
        }



        ostream &operator<<(ostream &ostr, Secretary &secretary) {
                ostr << "All people: " << endl;
                for (int i = 0; i<secretary.vec.size(); i++) {
                     cout<< *secretary.vec.at(i)<< endl;
                }
                return ostr;
        }

        Secretary Secretary::operator+(Person &person) {
                Secretary newsec(*this);
                newsec.add(person);
                return newsec;
        }
