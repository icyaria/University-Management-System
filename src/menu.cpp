#include "menu.h"
#include "secretary.h"

using namespace std;

void secretaryMenu() {
    int choice = 0;
    while (choice != 8) {
        cout << "Secretary Menu" << endl;
        cout << "*****************" << endl;
        cout << "1. Edit students" << endl;
        cout << "2. Edit professors" << endl;
        cout << "3. Edit courses" << endl;
        cout << "4. New semester" << endl;
        cout << "5. Assign courses to professors" << endl;
        cout << "6. Get a list of students that passed a course" << endl;
        cout << "7. See students that can graduate" << endl;
        cout << "8. Logout" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                //blabla
                cout << "edited students" << endl;
                cout << "*****************" << endl;
                break;
            case 2:
                // blabla
                cout << "edited professors" << endl;
                cout << "*****************" << endl;
                break;
            case 3:
                //blabla
                cout << "edited courses" << endl;
                cout << "*****************" << endl;
                break;
            case 4:
                //blabla
                cout << "new semester" << endl;
                cout << "*****************" << endl;
                break;
            case 5:
                //blabla
                cout << "assigned courses to professors" << endl;
                break;
            case 6:
                // blabla
                cout << "list of students that passed a course:" << endl;
                cout << "*****************" << endl;
                break;
            case 7:
                // blabla
                cout << "students that can graduate:" << endl;
                cout << "*****************" << endl;
                break;
            case 8:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
}

void professorMenu() {
    int choice = 0;
    while (choice != 3) {
        cout << "Professor Menu: " << endl;
        cout << "*****************" << endl;
        cout << "1. See semester statistics" << endl;
        cout << "2. Grade students" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                //blabla
                cout << "semester statistics" << endl;
                cout << "*****************" << endl;
                break;
            case 2:
                // blabla
                cout << "graded students" << endl;
                cout << "*****************" << endl;
                break;
            case 3:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
}

void studentMenu() {
    int choice = 0;
    while (choice != 3) {
        cout << "Student Menu" << endl;
        cout << "****************" << endl;
        cout << "1. Enroll in classes" << endl;
        cout << "2. See my grades" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                //blabla
                cout << "enrolled in classes" << endl;
                cout << "*****************" << endl;
                break;
            case 2:
                // blabla
                cout << "my grades:" << endl;
                cout << "*****************" << endl;
                break;
            case 3:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
}
