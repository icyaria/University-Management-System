#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string first_name;
    string last_name;
    string email;
    long int phone;
    static int count; //static, or else it would be a variable of each object

public:

    // default constructor
    Person();

    // 1st constructor, without phone number
    Person(string f, string l, string e);

    // 2nd constructor, with all parameters
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
