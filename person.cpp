#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string email;
    static int count;

public:
    // constructor 
    Person(const string& name, const string& email) : name(name), email(email) {
        count++;
    }
    //χρειαζεται κιαλλο(ους) constructor(s) αλλα γιατι?? τι διαφορετικές λειτουργίες θα εχουν?


    // destructor
    ~Person() {
        count--;
    }

    // getters και setters
    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    string getEmail() const {
        return email;
    }

    void setEmail(const string& newEmail) {
        email = newEmail;
    }

    // Υπερφόρτωση τελεστών << και >> για είσοδο και έξοδο
    friend istream& operator>>(istream& is, Person& person) {
        is >> person.name >> person.email;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Email: " << person.email;
        return os;
    }

    // # person objects που δημιουργήθηκαν
    static int getCount() {
        return count;
    }
};

// Αρχικοποίηση του count
int Person::count = 0;
