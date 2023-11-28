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
                // for (vector<Person*>::iterator i = vec.begin(); i != vec.end(); ++i) {
                //         delete *i;
                // }
                vec.clear();
                // delete[] newp;
                cout<<"Deconstructed secretary"<<endl;
        }

        void Secretary::add(Person &p) {
                Person* newp = new Person(p);
                // newp = &p;
                vec.push_back(newp);
                cout<<"Added Person in vector"<<endl;
        }

        // bool Secretary::find_person(Secretary sec, string fn, string ln) {
        //         for (int i = 0; i<sec.vec.size(); i++) {

        //         }
        // }



        ostream &operator<<(ostream &ostr, Secretary &secretary) {
                ostr << "All people: " << endl;
                for (int i = 0; i<secretary.vec.size(); i++) {
                     cout<< *secretary.vec.at(i)<< endl;
                }
                return ostr;
        }

        Secretary Secretary::operator+(Person &person) {
                add(person);
        }
