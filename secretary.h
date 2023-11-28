#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Secretary {
private:
    vector<Person*> vec;
    // vec.push_back();
    
public:

    // default constructor 
    Secretary();

    // destructor
    ~Secretary();

    void add(Person p);
    

};