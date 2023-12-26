#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "secretary.h"
#include "menu.h"

using namespace std;

// Αρχικοποίηση του count
int Person::count = 0;

int main() {

    Secretary sec;

    cout << "Welcome to University Management System" << endl;
    cout << "***************************************" << endl;

    // Student B = Student("B", "B", "B", 123, 1, 1, 123);
    // sec.add(B);


    int login = 0; 

    while (login != 4) {
        cout << "Login as: " << endl;
        cout << "1. Secretary" << endl;
        cout << "2. Professor" << endl;
        cout << "3. Student" << endl;
        cout << "4. Exit" << endl;
        cout << "(Type 1, 2, 3 or 4):" << endl;
        cin >> login;

        switch (login) {
            case 1:
                secretaryMenu(sec);
                break;
            case 2:
                professorMenu();
                break;
            case 3:
                studentMenu();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }


    // // TESTS
    // Professor A = Professor("A", "A", "A", 123);
    // // Student B = Student("B", "B", "B", 123, 1, 1);
    // sec.add(A);
    // // sec.add(B);
    // sec.find_person(sec, A);
    // sec.find_professor(sec, A);
    // sec.find_student(sec, B);
    // cin >> sec;
    // cout << sec;    

    // //οι νεες συναρτησεις σιγουρα εχουν leaks, δεν εχω κανει delete
    // //τιποτα στα courses & professors :')

    // Course course = Course("Math", "MATH", 1, 5, true);

    // sec.assignProfessorToCourse(A, course);
    // A.printCourseStatistics();

    return 0;
}