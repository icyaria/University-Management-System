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
Professor* login_p(Secretary &sec);
Student* login_s(Secretary &sec);

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
            Student* student = new Student(first_name, last_name, email, phone, sem, ects, am);

            //Adds student to secretary
            sec + *student;

    }

    // Close the file
    fin.close();

    //Input for professors

    // Open the file
    ifstream finp("txt/professors.txt");
    if (!finp) {
        cout << "Failed to open the file professors." << endl;
        return 1;
    }

    // Read the file

    while (getline(finp, line)) {
        first_name = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
            
        last_name = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);

        email = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);

        phone = stol(line.substr(0, line.find(" ")));
        line.erase(0, line.find(" ") + 1);

        // Creates a professor
        Professor* professor = new Professor(first_name, last_name, email, phone);

        //Adds professor to secretary
        sec + *professor;

    }

    // Close the file
    finp.close();

    cout << "Welcome to University Management System" << endl;
    cout << "***************************************" << endl;

    //tests
    Professor* A = new Professor("A", "A", "a@a", 123);
    Professor* B = new Professor("B", "B", "b@b", 123);
    sec + *A;
    sec.add(*B);
    Course course = Course("Math", "MATH", 1, 5, true);
    Course course2 = Course("Math2", "MATH2", 1, 5, true);
    sec.assignProfessorToCourse(*A, course);
    sec.assignProfessorToCourse(*A, course2);
    sec.assignProfessorToCourse(*B, course);
    


    int login = 0; 

    while (login != 4) {
        cout << "Login as: " << endl;
        cout << "1. Secretary" << endl;
        cout << "2. Professor" << endl;
        cout << "3. Student" << endl;
        cout << "4. Exit" << endl;
        cout << "(Type 1, 2, 3 or 4):" << endl;
        cin >> login;
        Professor* loggedInProfessor;
        Student* loggedInStudent;

        switch (login) {
            case 1:
                secretaryMenu(sec);
                break;
            case 2:
                loggedInProfessor = login_p(sec);
                if (loggedInProfessor) {
                    professorMenu(sec, loggedInProfessor);
                } else {
                    cout << "Wrong email!" << endl;
                }
                break;
            case 3:
                loggedInStudent = login_s(sec);
                if (loggedInStudent) {
                    studentMenu(sec, loggedInStudent);
                } else {
                    cout << "Wrong AM!" << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }

    return 0;
}