#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "secretary.h"
#include "student.h"
#include "professor.h"
#include "course.h"
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

    //Input for courses

    // Open the file
    ifstream finc("txt/courses.txt");
    if (!finc) {
        cout << "Failed to open the file professors." << endl;
        return 1;
    }

    // Read the file
    string course_name;
    string code;
    bool comp; //μπορεί να θέλει int
    while (getline(finc, line)) {
        course_name = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
            
        code = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);

        sem = stoi(line.substr(0, line.find(" ")));
        line.erase(0, line.find(" ") + 1);

        ects = stoi(line.substr(0, line.find(" ")));
        line.erase(0, line.find(" ") + 1);

        comp = stoi(line.substr(0, line.find(" ")));
        line.erase(0, line.find(" ") + 1);

        // Creates a course
        Course* course = new Course(course_name, code, sem, ects, comp);

        //Adds course to secretary.....Αν θέλουμε να γίνεται add το course στο secretary
        //να φτιάξουμε overloading operator + στη secretary, course κλπ
        sec + *course;

    }

    // Close the file
    finc.close();

    cout << "Welcome to University Management System" << endl;
    cout << "***************************************" << endl;   


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

    //bring up to date students.txt file
    ofstream fout("txt/students.txt");
    if (!fout) {
        cout << "Failed to open the file students." << endl;
        return 1;
    }
    for (std::size_t i = 0; i < sec.getStudents().size(); i++) {
        fout << sec.getStudents()[i]->getFirstName() << " " << sec.getStudents()[i]->getLastName() << " " << sec.getStudents()[i]->getEmail() << " " << sec.getStudents()[i]->getPhone() << " " << sec.getStudents()[i]->getSem() << " " << sec.getStudents()[i]->getEcts() << " " << sec.getStudents()[i]->getAM() << endl;
    }
    fout.close();

    //bring up to date professors.txt file
    ofstream foutp("txt/professors.txt");
    if (!foutp) {
        cout << "Failed to open the file professors." << endl;
        return 1;
    }
    for (std::size_t i = 0; i < sec.getProfessors().size(); i++) {
        foutp << sec.getProfessors()[i]->getFirstName() << " " << sec.getProfessors()[i]->getLastName() << " " << sec.getProfessors()[i]->getEmail() << " " << sec.getProfessors()[i]->getPhone() << endl;
    }
    foutp.close();

    // bring up to date courses.txt file
    ofstream foutc("txt/courses.txt");
    if (!foutc) {
        cout << "Failed to open the file courses." << endl;
        return 1;
    }
    for (std::size_t i = 0; i < sec.getCourses().size(); i++) {
        foutc << sec.getCourses()[i]->getCourseName() << " " << sec.getCourses()[i]->getCode() << " " << sec.getCourses()[i]->getSem() << " " << sec.getCourses()[i]->getEcts() << " " << sec.getCourses()[i]->getComp() << endl;
    }
    foutc.close();

    return 0;
}