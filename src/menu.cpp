#include "menu.h"
#include "secretary.h"
#include "student.h"
#include "professor.h"
#include "course.h"

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

        switch (choice) {
            case 1:
                while (ch != 5) {
                    Student* student = new Student;
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
                            cin >> *student;
                            if(sec.find_student(sec, *student)) {
                                cout << "\nStudent already exists\n" << endl;
                                break;
                            }
                            sec + *student;
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
                            sec.printStudents(cout);
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
                while (ch != 5) {
                    Professor* professor = new Professor;
                    cout << "Edit Professors" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new professor" << endl;
                    cout << "2. Edit a professor" << endl;
                    cout << "3. Delete a professor" << endl;
                    cout << "4. View professor list" << endl;
                    cout << "5. Back" << endl;
                    cin >> ch;

                    switch (ch) {
                        case 1: {
                            cout << "Enter the new Professor's information:" << endl;    
                            cin >> *professor;
                            if(sec.find_professor(sec, *professor)) {
                                cout << "\nProfessor already exists\n" << endl;
                                break;
                            }
                            sec + *professor;
                            cout << "\n" << endl;
                        }
                            break;
                        case 2: 
                            editProfessor(sec);
                            cout << "*****************" << endl;
                            break;
                        case 3:
                            deleteProfessor(sec);
                            cout << "*****************" << endl;
                            break;
                        case 4:
                            sec.printProfessors(cout);
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
                while (ch != 6) {
                    Course* course = new Course;
                    cout << "Edit Courses" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new course" << endl;
                    cout << "2. Edit a course" << endl;
                    cout << "3. Delete a course" << endl;
                    cout << "4. View course list" << endl;
                    cout << "5. View professors that teach a course" << endl;
                    cout << "6. Back" << endl;
                    cin >> ch;

                    switch (ch) {
                        case 1: {
                            cout << "Enter the new Professor's information:" << endl;    
                            cin >> *course;
                            if(sec.find_course(sec, *course)) {
                                cout << "\nProfessor already exists\n" << endl;
                                break;
                            }
                            sec + *course;
                            cout << "\n" << endl;
                            }
                            break;
                        case 2:
                            editCourse(sec);
                            cout << "*****************" << endl;
                            break;
                        case 3:
                            deleteCourse(sec);
                            cout << "*****************" << endl;
                            break;
                        case 4:
                            sec.printCourses(cout);
                            cout << "*****************" << endl;
                            break;
                        case 5:
                            {
                            cout << "Enter the code of the course you want to see the professors of:" << endl;
                            Course* foundCourse = find_course_from_code(sec);
                            if (foundCourse) {
                                foundCourse->printProfessorsTeaching();
                            } else {
                                cout << "Course not found!" << endl;
                            }
                            cout << "*****************" << endl;
                            }
                            break;
                        case 6:
                            break;
                        default:
                            cout << "Wrong input" << endl;
                            break;
                    }
                }
                break;
            case 4: {
                cout << "Do you want to change the semester to the next one? (y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'n') {
                    break;
                }
                else if (choice == 'y') {
                    sec.new_semester();
                    cout << "Semester changed successfully!" << endl;
                    cout << "Please proceed to assign professors to courses!" << endl;
                }
                else {
                    cout << "Wrong input" << endl;
                }
                cout << "*****************" << endl;
            }
                break;
            case 5: {
                cout << "Do you want to assign one professor for each course of the semester or the professor(s) for a specific course? (1 for all, 2 for specific)" << endl;
                int choice;
                cin >> choice;
                if (choice == 1) {
                    for (size_t i = 0; i < sec.getCourses().size(); i++) {
                        if (sec.getCourses()[i]->getSem()%2 == sec.getSemester() + 1) {
                            bool validInput = false;
                            while (!validInput) {
                                if (sec.getCourses()[i]->getSem()%2 == sec.getSemester() + 1) {
                                    cout << "Choose a professor to assign to " << sec.getCourses()[i]->getCourseName() << endl;
                                    Professor* professor = find_professor_from_email(sec);
                                    if (professor) {
                                        sec.assignProfessorToCourse(*professor, *sec.getCourses()[i]);
                                        cout << "Course assigned successfully!" << endl;
                                        validInput = true;
                                    } 
                                    else {
                                        cout << "Wrong professor, try again!" << endl;    
                                    }
                                }
                            }
                        }
                    } 
                }
                else if (choice == 2) {
                    cout << "Choose a course to assign:" << endl;
                    Course* course = find_course_from_code(sec);
                    if (course) {
                        bool doneAssigning = false;
                        while (!doneAssigning) {
                            cout << "Choose a professor to assign to " << course->getCourseName() << endl;
                            Professor* professor = find_professor_from_email(sec);
                            if (professor) {
                                sec.assignProfessorToCourse(*professor, *course);
                                cout << "Course assigned successfully!" << endl;
                                cout << "Do you want to assign another professor to this course? (y/n)" << endl;
                                char choice;
                                cin >> choice;
                                if (choice != 'y' && choice != 'Y') {
                                    doneAssigning = true;
                                }
                            } 
                            else {
                                cout << "Wrong professor!" << endl;
                            }
                        }
                    } 
                    else {
                        cout << "Wrong course!" << endl;
                    }
                } 
                else {
                    cout << "Wrong input" << endl;
                }
                cout << "*****************" << endl;
            }
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

void professorMenu(Secretary &sec, Professor* &professor) {

    int choice = 0;

    cout << "Logged in successfully!" << endl;
    cout << "Welcome " << professor->getFirstName() << " " << professor->getLastName() << endl;


    while (choice != 4) {
        cout << "Professor Menu: " << endl;
        cout << "*****************" << endl;
        cout << "1. My courses" << endl;
        cout << "2. Grade students" << endl;
        cout << "3. View semester statistics" << endl;
        cout << "4. Logout" << endl;
        cin >> choice;

        string code;

        switch (choice) {
            case 1:
                professor->printCoursesTeaching(cout);
                cout << "*****************" << endl;
                break;
            case 2:
                cout << "\n" << endl;
                cout << professor;
                cout << "Type the code of the course you want to grade: " << endl;
                cin >> code;
                find_course_from_code(sec);
                //blabla
                cout << "*****************" << endl;
                break;
            case 3:
                //not ready yet
                professor->printCourseStatistics();
                break;
            case 4:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
}

void studentMenu(Secretary &sec, Student* &student) {

    int choice = 0;

    cout << "Logged in successfully!" << endl;
    cout << "Welcome " << student->getFirstName() << " " << student->getLastName() << endl;

    while (choice != 3) {
        cout << "Student Menu" << endl;
        cout << "****************" << endl;
        cout << "1. Enroll in classes" << endl;
        cout << "2. See my grades" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your available courses:" << endl;
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

Professor* find_professor_from_email(Secretary &sec) {
    string targetEmail;
    cin >> targetEmail;

    Professor* foundProfessor = nullptr;
    vector<Professor*> const &professors = sec.getProfessors();

    for (size_t i = 0; i < professors.size(); i++) {
        if (professors[i]->getEmail() == targetEmail) {
            foundProfessor = professors[i];
            break;
        }
    }
    return foundProfessor;
}

Course* find_course_from_code(Secretary &sec) {
    string targetCode = " ";
    cin >> targetCode;

    Course* foundCourse = nullptr;
    vector<Course*> const &courses = sec.getCourses();

    for (size_t i = 0; i < courses.size(); i++) {
        if (courses.at(i)->getCode() == targetCode) {
            foundCourse = courses[i];
            break;
        }
    }
    return foundCourse;
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
        else if (choice == 'y') {
            cout << "Enter new student information:" << endl;
            cin >> *foundStudent;
            cout << "Edited Successfully!" << endl;
        }
        else {
            cout << "Student not found!" << endl;
        }
    }
}

void editProfessor(Secretary &sec) {
    cout << "Enter the email of the professor you want to edit:" << endl;

    Professor* foundProfessor = find_professor_from_email(sec);

    if (foundProfessor) {
        cout << "Professor Info: \n" << *foundProfessor << endl;
        cout << "Proceed with editing? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        else if (choice == 'y') {
            cout << "Enter new professor information:" << endl;
            cin >> *foundProfessor;
            cout << "Edited Successfully!" << endl;
        }
        else {
            cout << "Professor not found!" << endl;
        }
    }
}

void editCourse(Secretary &sec) {
    cout << "Enter the code of the course you want to edit:" << endl;

    Course* foundCourse = find_course_from_code(sec);

    if (foundCourse) {
        cout << "Course Info: \n" << *foundCourse << endl;
        cout << "Proceed with editing? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        else if (choice == 'y') {
            cout << "Enter new course information:" << endl;
            cin >> *foundCourse;
            cout << "Edited Successfully!" << endl;
        } 
        else {
            cout << "Course not found!" << endl;
        }
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
        else if (choice == 'y') {
            sec.remove(*foundStudent);
            cout << "Deleted Successfully!" << endl;
        } 
        else {
            cout << "Student not found!" << endl;
        }
    }
}

void deleteProfessor(Secretary &sec) {
    if (sec.getProfessors().size() == 0) {
        cout << "No professors to delete!" << endl;
        return;
    }
    cout << "Enter the email of the professor you want to delete:" << endl;

    Professor* foundProfessor = find_professor_from_email(sec);

    if (foundProfessor) {
        cout << "Professor Info: \n" << *foundProfessor << endl;
        cout << "Proceed with deleting? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        else if (choice == 'y') {
            sec.remove(*foundProfessor);
            cout << "Deleted Successfully!" << endl;
        } 
        else {
            cout << "Professor not found!" << endl;
        }
    }
}

void deleteCourse(Secretary &sec) {
    if (sec.getCourses().size() == 0) {
        cout << "No courses to delete!" << endl;
        return;
    }
    cout << "Enter the code of the course you want to delete:" << endl;

    Course* foundCourse = find_course_from_code(sec);

    if (foundCourse) {
        cout << "Course Info: \n" << *foundCourse << endl;
        cout << "Proceed with deleting? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        else if (choice == 'y') {
            sec.remove(*foundCourse);
            cout << "Deleted Successfully!" << endl;
        } 
        else {
            cout << "Course not found!" << endl;
        }
    }
}

Student* login_s(Secretary &sec) {

    cout << "Enter your AM:" << endl; 
    Student* foundStudent = find_student_fromAM(sec);

    return foundStudent; // Returns nullptr if no match is found
}

Professor* login_p(Secretary &sec) {
   
    cout << "Enter your email:" << endl;
    Professor* foundProfessor = find_professor_from_email(sec);

    return foundProfessor; // Returns nullptr if no match is found
}

