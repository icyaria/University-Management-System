#include <iostream>
#include <string>
#include <vector>
#include "secretary.h"

using namespace std;


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

    cout << A;


    Person B ("Bob", "Williams", "bobwill@gmail.com");
    cout << "enter phone number:";  //έλεγχος προσθήκης στοιχείου στη κλάση
    long int phoneB;
    cin >> phoneB;
    B.setPhone(phoneB);

    string first_nameB = B.getFirstName();
    string last_nameB = B.getLastName();
    string emailB = B.getEmail();
    long int getphoneB = B.getPhone();

    // cout << "Name of Person B is: "<<first_nameB <<" "<< last_nameB <<endl;
    // cout << "Email of Person B is: "<<emailB <<endl;
    // cout << "Phone of Person B is: "<<phoneB <<endl;




    Person C;
    cin >> C;
    //cout << C;



    Secretary sec;
    sec + A;
    sec + C;
    sec.find_person(sec, A);
    sec.find_person(sec, B);

    cin >> sec;
    cout << "Count of Person is: "<<Person::getCount()<<endl;
    cout<< sec;


    return 0;
}