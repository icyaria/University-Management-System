#include <iostream>
#include <string>
#include "person.h"
#include "secretary.h"

// Αρχικοποίηση του count
int Person::count = 0;

int main() {

    // Μπορούμε να έχουμε πρόσβαση στo count χωρίς
    // να έχει δημιουργηθεί κάποιο αντικείμενο επειδή
    // η getCount είναι static
    cout << "Count of Person is: "<<Person::getCount()<<endl;

    string name = "John";
    string email = "john@gmail.com";
    long int phone = 6980336000;
    Person A (name, email, phone);
    Person B (name, email);


    string nameA;
    string nameB;
    long int phoneB;

    B.setName("Bob");

    nameA = A.getName();
    nameB = B.getName();
    phoneB = B.getPhone();

    int countA, countB;
    countA = A.getCount();
    countB = B.getCount();

    cout << "Name of Person A is: "<<nameA <<endl;
    cout << "Name of Person B is: "<<nameB <<endl;
    cout << "Phone of Person B is: "<<phoneB <<endl;
    cout << "Count of Person is: "<<countA <<endl;
    cout << "Count of Person is: "<<countB <<endl;


    Person C;
    cin >> C;
    cout << C;

    return 0;
}