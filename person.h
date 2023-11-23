#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string email;
    long int phone;
    static int count;

public:

    // 1st constructor 
    Person(string n, string e);

    // 2nd constructor 
    Person(string n, string e, long int ph);


    // destructor
    ~Person();

    // getters και setters
    string getName() const;

    void setName(string newName);

    string getEmail() const;

    void setEmail(string newEmail);

    long int getPhone() const;

    void setPhone(long int newPhone);
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
    static int getCount(); 
};
