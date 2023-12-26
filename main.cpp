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

    //idea: διαφορετικο μενου για καθε χρηστη γιατι δεν βγαζει νοημα αλλιως
    //(δεν γινεται ο φοιτητης να βλεπει ολα τα options που εχει και η γραμματεια πχ)
    //cout << "Login as: " << endl;

    //for secretary:

    // int choice=0;

    // while (choice != 7) {
    //     cout << "1. Edit students" << endl;
    //     cout << "2. Edit professors" << endl;
    //     cout << "3. Edit courses" << endl;
    //     cout << "4. New semester (Assign courses to professors)" << endl;
    //     cout << "5. Get a list of students that passed a course" << endl;
    //     cout << "6. See students that can graduate" << endl;
    //     cout << "7. Exit" << endl;
    
    //     cin >> choice;
    //}



    //for professor:

    // int choice=0;

    // while (choice != 2) {
    //     cout << "1. See semester statistics" << endl;
    //     cout << "2. Exit" << endl;
    
    //     cin >> choice;
    // }



    //for student:
    // int choice=0;

    // while (choice != 3) {
    //     cout << "1. Enroll in classes" << endl;
    //     cout << "2. See my grades " << endl;
    //     cout << "3. Exit" << endl;

    //     cin >> choice;
    // }

    Professor A = Professor("A", "A", "A", 123);
    Student B = Student("B", "B", "B", 123, 1, 1);
    sec.add(A);
    sec.add(B);
    sec.find_person(sec, A);
    sec.find_professor(sec, A);
    sec.find_student(sec, A);
    cin >> sec;
    cout << sec;    

    Course course = Course("Math", "MATH", 1, 5, true);

    // Assign professor to course through the secretary
    sec.assignProfessorToCourse(A, course);

    // Print statistics for the professor
    A.printCourseStatistics();

    return 0;
}