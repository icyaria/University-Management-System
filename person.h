#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string first_name;
    string last_name;
    string email;
    long int phone;
    static int count; //static γιατι αλλιώς θα ήταν μεταβλητή του κάθε αντικειμένου

public:


    // default constructor
    Person();

    // 1st constructor 
    Person(string f, string l, string e);

    // 2nd constructor
    Person(string f, string l, string e, long int ph);



    // destructor
    ~Person();


    // getters και setters

    string getFirstName() const;

    void setFirstName(string newFName);

    string getLastName() const;

    void setLastName(string newLName);

    string getEmail() const;

    void setEmail(string newEmail);

    long int getPhone() const;

    void setPhone(long int newPhone);



    // Υπερφόρτωση τελεστών << και >> για είσοδο και έξοδο

    friend istream &operator>>(istream &istr, Person &person);

    friend ostream &operator<<(ostream &ostr, Person &person);



    // Count of objects type Person
    static int getCount(); 
};
