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
                cout<<"Deconstructed secretary"<<endl;
        }

        void Secretary::add(Person p) {
                Person* newp = new Person;
                newp = &p;
                vec.push_back(newp);
                cout<<"Added Person in vector"<<endl;
        }
