#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "secretary.h"

// Αρχικοποίηση του count
int Person::count = 0;

int main() {

    // Μπορούμε να έχουμε πρόσβαση στo count χωρίς
    // να έχει δημιουργηθεί κάποιο αντικείμενο επειδή
    // η getCount είναι static
    cout << "Count of Person is: "<<Person::getCount()<<endl;

    string first_name = "John";
    string last_name = "Smith";
    string email = "john@gmail.com";
    long int phone = 6980336000;

    Person A (first_name, last_name, email, phone);

    cout << "Name of Person A is: "<<A.getFirstName() <<" "<< A.getLastName() <<endl;


    Person B ("Bob", "William", "bobwill@gmail.com");
    B.setLastName("Williams");
    cout << "enter phone number:";
    long int phoneB;
    cin >> phoneB;
    B.setPhone(phoneB);

    string first_nameB = B.getFirstName();
    string last_nameB = B.getLastName();
    long int getphoneB;
    getphoneB = B.getPhone();

    cout << "Name of Person B is: "<<first_nameB <<" "<< last_nameB <<endl;
    cout << "Phone of Person B is: "<<phoneB <<endl;

    int count;
    count = A.getCount();
    cout << "Count of Person is: "<<count <<endl;


    Person C;
    cin >> C;
    cout << C;

    return 0;
}