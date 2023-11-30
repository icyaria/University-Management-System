#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Secretary {
private:
    vector<Person*> vec;
    
public:

    // constructor 
    Secretary();

    // Copy constructor
    Secretary(const Secretary &sec);

    // destructor
    ~Secretary();

    // Function to add new person
    void add(Person &p);

    // Searches for person in secretary
    bool find_person(Secretary &sec, Person &person);
    
    // Overloading operator >> and << for output and input
    friend istream &operator>>(istream &istr, Secretary &secretary);

    friend ostream &operator<<(ostream &ostr, Secretary &secretary);

    // Overloading operator + for adding person to secretary
    Secretary& operator+(Person &person);

    // Overloading operator = for assignment
    Secretary operator=(const Secretary &sec);
 
};