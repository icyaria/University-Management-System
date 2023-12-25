#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "secretary.h"

using namespace std;


// Αρχικοποίηση του count
int Person::count = 0;

int main() {

    Secretary sec;

    cout << "Welcome to University Management System" << endl;
    cout << "***************************************" << endl;

    cout << "Login as: " << endl;

    int choice=0;

    while (choice != 10) {
        cout << "1. Edit students" << endl;
        cout << "2. Edit professors" << endl;
        cout << "3. Edit courses" << endl;
        cout << "4. Assign courses to professors" << endl;
        cout << "5. Enroll student" << endl;
        cout << "6. Get a list of students that passed a course" << endl;
        cout << "7. See semester statistics (for professors)" << endl;
        cout << "8. See my grades (for students)" << endl;
        cout << "9. See students that can graduate" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

    }


    

    return 0;
}