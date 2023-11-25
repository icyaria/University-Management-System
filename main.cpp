#include <iostream>
#include <string>
#include "person.h"
#include "secretary.h"


int main() {
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

    cout << "Name A is: "<<nameA <<endl;
    cout << "Name B is: "<<nameB <<endl;
    cout << "Phone B is: "<<phoneB <<endl;
    cout << "Count A is: "<<countA <<endl;
    cout << "Count B is: "<<countB <<endl;

    return 0;
}