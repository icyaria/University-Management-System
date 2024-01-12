#include "person.h"

using namespace std;

    Person::Person() {
        first_name = "";
        last_name = "";
        email = "";
        phone = 0;
        count++;
    }

    Person::Person(string f, string l, string e) {
        first_name = f;
        last_name = l;
        email = e;
        phone = 0;
        count++;
    }

    Person::Person(string f, string l, string e, long int ph) {
        first_name = f;
        last_name = l;
        email = e;
        phone = ph;
        count++;
    }

    Person::Person(const Person &person) {
        first_name = person.first_name;
        last_name = person.last_name;
        email = person.email;
        phone = person.phone;
    }

    Person::~Person() {
        count--;
    }

    // getters and setters
    string Person::getFirstName() const {
        return first_name;
    }

    void Person::setFirstName(string newFName) {
        first_name = newFName;
    }

    string Person::getLastName() const {
        return last_name;
    }

    void Person::setLastName(string newLName) {
        last_name = newLName;
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

    // Operators overloading
    istream &operator>>(istream &istr, Person &person) {
        cout << "Enter first name: ";
        istr >> person.first_name;
        cout << "Enter last name: ";
        istr >> person.last_name;
        cout << "Enter email: ";
        istr >> person.email;
        try {
            cout << "Enter phone: ";
            istr >> person.phone;
            if (istr.fail()) {
                throw runtime_error("Invalid input for phone number.");
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            istr.clear();
            istr.ignore(numeric_limits<streamsize>::max(), '\n');
            return operator>>(istr, person);
        }
        return istr;
    }

    ostream &operator<<(ostream &ostr, Person &person) {
        ostr << "First name: " << person.first_name << endl << "Last name: " << person.last_name << endl << "Email: " << person.email << endl << "Phone: " << person.phone << endl;
        return ostr;
    }

    int Person::getCount() {
        return count;
    }