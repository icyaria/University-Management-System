#include <iostream>
#include <string>
#include "person.h"

using namespace std;

    // 1st constructor 
    Person::Person(string n, string e) {
        name = n;
        email = e;
        count++;
        cout << "Constructed person without phone number" <<endl;
    }

    // 2nd constructor 
    Person::Person(string n, string e, long int ph) {
        name = n;
        email = e;
        phone = ph;
        count++;
        cout << "Constructed person with phone number" <<endl;
    }


    // deconstructor
    Person::~Person() {
        cout << "Deconstructed person" <<endl;
        count--;
    }
  
    // getters και setters
    string Person::getName() const {
        return name;
    }

    void Person::setName(string newName) {
        name = newName;
    }

    string Person::getEmail() const {
        return email;
    }

    void Person::setEmail(string newEmail) {
        email = newEmail;
    }

    long int Person::getPhone() const {
        return phone;
    }

    void Person::setPhone(long int newPhone) {
        phone = newPhone;
    }

/*
    // Υπερφόρτωση τελεστών << και >> για είσοδο και έξοδο
    friend istream& operator>>(istream& is, Person& person) {
        is >> person.name >> person.email;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Email: " << person.email;
        return os;
    }
*/
    // # person objects που δημιουργήθηκαν
    int Person::getCount() {
        return count;
    }
    
// Αρχικοποίηση του count
int Person::count = 0;
