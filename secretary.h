#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Secretary {
private:
    vector<Person*> vec;
    
public:

    // default constructor 
    Secretary();

    // destructor
    ~Secretary();

    void add(Person &p);

    bool find_person(Secretary &sec, Person &person);
    
    // Υπερφόρτωση τελεστών << και >> για είσοδο και έξοδο

    friend istream &operator>>(istream &istr, Secretary &secretary);

    friend ostream &operator<<(ostream &ostr, Secretary &secretary);

    Secretary& operator+(Person &person);

    Secretary(const Secretary &sec);

    Secretary operator=(const Secretary &sec);

    
};