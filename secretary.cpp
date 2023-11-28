#include <iostream>
#include <string>
#include <vector>

#include "secretary.h"

using namespace std;

        Secretary::Secretary() {
                
        }

        Secretary::~Secretary() {                
                for (vector<Person*>::iterator pObj = vec.begin(); pObj != vec.end(); ++pObj) {
                        delete *pObj;
                }
                vec.clear();
                cout<<"Deconstructed secretary"<<endl;
        }

        void Secretary::add(Person p) {
                Person* newp;
                newp = new Person;
                newp = &p;
                vec.push_back(newp);
                cout<<"Added Person in vector"<<endl;
        }
