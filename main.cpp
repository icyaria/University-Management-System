#include <iostream>
#include <string>
#include <vector>
#include "secretary.h"

using namespace std;


// Αρχικοποίηση του count
int Person::count = 0;

int main() {

    Secretary sec;

    cout << "Count of people is: "<<Person::getCount() << endl;
    cout << "\n" << endl;
    cout << "Default people out of secretary are: "<< endl;

    Person A ("John", "Smith", "john@gmail.com", 6980336000);

    Person B ("Bob", "Williams", "bobwill@gmail.com");
    cout << A << endl;
    cout << B << endl;

    cout << "Enter Bob's phone number:";  //έλεγχος προσθήκης στοιχείου στη κλάση
    long int phoneB;
    cin >> phoneB;
    B.setPhone(phoneB);

    cout << "Add new person:" << endl;
    Person C; //Creates new person out of secretary
    cin >> C;

    cout << "\nIn main Secretary: " << endl;
    sec + A;
    sec + C;


    sec.find_person(sec, A);
    sec.find_person(sec, B);

    cin >> sec; // Adds new person directly to secretary
    cout<< sec;

    Secretary second_sec(sec); //Copy constructor
    cout << "In second secretary:" << endl;
    cout << second_sec;
    Secretary third_sec = sec; //Assignment operator
    cout << "In third secretary:" << endl;
    third_sec + B;
    cout << third_sec;

    cout << "Count of people is: "<<Person::getCount()<<endl;

    return 0;
}