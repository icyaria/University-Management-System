#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "secretary.h"
#include "student.h"
#include "menu.h"

using namespace std;

// Αρχικοποίηση του count
int Person::count = 0;

int main() {

    Secretary sec;

    //Input

        // Open the file
        ifstream fin("txt/students.txt");
        if (!fin) {
            cout << "Failed to open the file students." << endl;
            return 1;
        }

        // Read the file
        string line;
        string first_name;
        string last_name;
        string email;
        long int phone;
        int sem;
        int ects;
        long int am;
        while (getline(fin, line)) {
            first_name = line.substr(0, line.find(" "));
            line.erase(0, line.find(" ") + 1);
            
            last_name = line.substr(0, line.find(" "));
            line.erase(0, line.find(" ") + 1);

            email = line.substr(0, line.find(" "));
            line.erase(0, line.find(" ") + 1);

            phone = stol(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);

            sem = stoi(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);

            ects = stoi(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);

            am = stol(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
            
            // Creates a student
            Student student(first_name, last_name, email, phone, sem, ects, am);

            //Adds student to secretary
            sec + student;

        }

        // Close the file
        fin.close();

    cout << "Welcome to University Management System" << endl;
    cout << "***************************************" << endl;

    Professor A = Professor("A", "A", "A", 123);
    sec.add(A);
    Course course = Course("Math", "MATH", 1, 5, true);
    Course course2 = Course("Math2", "MATH2", 1, 5, true);
    sec.assignProfessorToCourse(A, course);
    sec.assignProfessorToCourse(A, course2);
    printProfessors(cout, sec);
    cout << A;
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
                professorMenu(sec);
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
    //Professor A = Professor("A", "A", "A", 123);

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

    //Course course = Course("Math", "MATH", 1, 5, true);

    //sec.assignProfessorToCourse(A, course);
    //cout << A;
    // A.printCourseStatistics();

    return 0;
}