#include <iostream>
#include <string>
#include "person.h"

using namespace std;


    // default constructor
    Person::Person() {
        name = "";
        email = "";
        phone = 0;
        count++;
        cout << "Constructed person without parameters" <<endl;
    }

    // 1st constructor 
    Person::Person(string n, string e) {
        name = n;
        email = e;
        phone = 0;
        count++;
        cout << "Constructed person without phone number" <<endl;
    }

    // 2nd constructor
    Person::Person(string n, string e, long int ph) {
        name = n;
        email = e;
        phone = ph;
        count++;
        cout << "Constructed person with all information" <<endl;
    }



    Person::~Person() {
        cout << "Deconstructed person" <<endl;
        count--;
    }



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




    istream &operator>>(istream &istr, Person &person) {
        cout << "Enter name: ";
        istr >> person.name;
        cout << "Enter email: ";
        istr >> person.email;
        cout << "Enter phone: ";
        istr >> person.phone;
        return istr;
    }

    ostream &operator<<(ostream &ostr, Person &person) {
        ostr << "Name: " << person.name << ", Email: " << person.email << ", Phone: " << person.phone << endl;
        return ostr;
    }



    int Person::getCount() {
        return count;
    }
    

