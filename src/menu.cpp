#include "menu.h"
#include "secretary.h"
#include "student.h"
#include "professor.h"

using namespace std;

void secretaryMenu(Secretary &sec) {
    int choice = 0;
    while (choice != 8) {
        cout << "Secretary Menu" << endl;
        cout << "*****************" << endl;
        cout << "1. Edit student list" << endl;
        cout << "2. Edit professor list" << endl;
        cout << "3. Edit courses" << endl;
        cout << "4. New semester" << endl;
        cout << "5. Assign courses to professors" << endl;
        cout << "6. Get a list of students that passed a course" << endl;
        cout << "7. See students that can graduate" << endl;
        cout << "8. Logout" << endl;
        cin >> choice;

        int ch = 0;
        Student student;
        Professor professor;

        switch (choice) {
            case 1:
                while (ch != 5) {
                    cout << "Edit Students" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new student" << endl;
                    cout << "2. Edit a student" << endl;
                    cout << "3. Delete a student" << endl;
                    cout << "4. View student list" << endl;
                    cout << "5. Back" << endl;
                    cin >> ch;

                    switch (ch) {
                        case 1:
                            cout << "Enter new student information:" << endl;    
                            cin >> student;
                            if(sec.find_student(sec, student)) {
                                cout << "\nStudent already exists\n" << endl;
                                break;
                            }
                            sec + student;
                            cout << "\n" << endl;
                            break;
                        case 2:
                            editStudent(sec);
                            cout << "*****************" << endl;
                            break;
                        case 3:
                            deleteStudent(sec);
                            cout << "*****************" << endl;
                            break;
                        case 4:
                            printStudents(cout, sec);
                            cout << "*****************" << endl;
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Wrong input" << endl;
                            break;
                    }
                }
                break;
            case 2:
                while (ch != 4) {
                    cout << "Edit Professors" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new professor" << endl;
                    cout << "2. Edit a professor" << endl;
                    cout << "3. Delete a professor" << endl;
                    cout << "4. View professor list" << endl;
                    cout << "5. Back" << endl;
                    cin >> ch;

                    switch (ch) {
                        case 1:
                            cout << "Enter the new Professor's information:" << endl;    
                            cin >> professor;
                            if(sec.find_professor(sec, professor)) {
                                cout << "\nProfessor already exists\n" << endl;
                                break;
                            }
                            sec + professor;
                            cout << "\n" << endl;
                            break;
                        case 2:
                            cout << "edited professor" << endl;
                            cout << "*****************" << endl;
                            break;
                        case 3:
                            cout << "deleted professor" << endl;
                            cout << "*****************" << endl;
                            break;
                        case 4:
                            printProfessors(cout, sec);
                            cout << "*****************" << endl;
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Wrong input" << endl;
                            break;
                    }
                }
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


Student* find_student_fromAM(Secretary &sec) {
    long int targetAM = 0;
    cin >> targetAM;

    Student* foundStudent = nullptr;
    vector<Student*> const &students = sec.getStudents();

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getAM() == targetAM) {
            foundStudent = students[i];
            break;
        }
    }
    return foundStudent;
}

void editStudent(Secretary &sec) {
    cout << "Enter the AM of the student you want to edit:" << endl;

    Student* foundStudent = find_student_fromAM(sec);

    if (foundStudent) {
        cout << "Student Info: \n" << *foundStudent << endl;
        cout << "Proceed with editing? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        cout << "Enter new student information:" << endl;
        cin >> *foundStudent;
        cout << "Edited Successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void deleteStudent(Secretary &sec) {
    if (sec.getStudents().size() == 0) {
        cout << "No students to delete!" << endl;
        return;
    }
    cout << "Enter the AM of the student you want to delete:" << endl;

    Student* foundStudent = find_student_fromAM(sec);

    if (foundStudent) {
        cout << "Student Info: \n" << *foundStudent << endl;
        cout << "Proceed with deleting? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        sec.remove(*foundStudent);
        cout << "Deleted Successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}
