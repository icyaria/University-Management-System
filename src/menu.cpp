#include "menu.h"
#include "secretary.h"
#include "student.h"
#include "professor.h"
#include "course.h"

using namespace std;

void secretaryMenu(Secretary &sec) {
    int choice = 0;
    while (choice != 9) {
        cout << "Secretary Menu" << endl;
        cout << "*****************" << endl;
        cout << "1. Students" << endl;
        cout << "2. Professors" << endl;
        cout << "3. Courses" << endl;
        cout << "4. New semester" << endl;
        cout << "5. Assign courses to professors" << endl;
        cout << "6. Get a list of students that passed a course" << endl;
        cout << "7. Get a list of all the courses, with all the students' grades in each one" << endl;
        cout << "8. See students that can graduate" << endl;
        cout << "9. Logout" << endl;

        try {
            cin >> choice;
            if (cin.fail()) {
                throw runtime_error("Invalid input type. Please enter a valid integer.");
            }
        } 
        catch (const exception& mes) {
            cout << "Error: " << mes.what() << endl;
            cin.clear();
            // ignores all characters in the input stream until it reaches a newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int ch = 0;

        switch (choice) {
            case 1:
                while (ch != 5) {
                    Student* student = new Student;
                    cout << "Students" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new student" << endl;
                    cout << "2. Edit a student" << endl;
                    cout << "3. Delete a student" << endl;
                    cout << "4. View student list" << endl;
                    cout << "5. Back" << endl;
                    
                    try {
                        cin >> ch;
                        if (cin.fail()) {
                            throw runtime_error("Invalid input type. Please enter a valid integer.");
                        }
                    } 
                    catch (const exception& mes) {
                        cout << "Error: " << mes.what() << endl;
                        cin.clear();
                        // ignores all characters in the input stream until it reaches a newline
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

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
                    cout << "Professors" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new professor" << endl;
                    cout << "2. Edit a professor" << endl;
                    cout << "3. Delete a professor" << endl;
                    cout << "4. View professor list" << endl;
                    cout << "5. Back" << endl;
                    
                    try {
                        cin >> ch;
                        if (cin.fail()) {
                            throw runtime_error("Invalid input type. Please enter a valid integer.");
                        }
                    } 
                    catch (const exception& mes) {
                        cout << "Error: " << mes.what() << endl;
                        cin.clear();
                        // ignores all characters in the input stream until it reaches a newline
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

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
                while (ch != 7) {
                    Course* course = new Course;
                    cout << "Courses" << endl;
                    cout << "*****************" << endl;
                    cout << "1. Add a new course" << endl;
                    cout << "2. Edit a course" << endl;
                    cout << "3. Delete a course" << endl;
                    cout << "4. View all courses" << endl;
                    cout << "5. View professors that teach a course" << endl;
                    cout << "6. View students that are enrolled in a course" << endl;
                    cout << "7. Back" << endl;
                    
                    try {
                        cin >> ch;
                        if (cin.fail()) {
                            throw runtime_error("Invalid input type. Please enter a valid integer.");
                        }
                    } 
                    catch (const exception& mes) {
                        cout << "Error: " << mes.what() << endl;
                        cin.clear();
                        // ignores all characters in the input stream until it reaches a newline
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    switch (ch) {
                        case 1: {
                            cout << "Enter the new Course's information:" << endl;    
                            cin >> *course;
                            if(sec.find_course(sec, *course)) {
                                cout << "\nCourse already exists\n" << endl;
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
                            if (foundCourse != nullptr) {
                                foundCourse->printProfessorsTeaching();
                            } else {
                                cout << "Course not found!" << endl;
                            }
                            cout << "*****************" << endl;
                            }
                            break;
                        case 6:
                            {
                            cout << "Enter the code of the course you want to see the students of:" << endl;
                            Course* foundCourse = find_course_from_code(sec);
                            if (foundCourse != nullptr) {
                                foundCourse->printEnrolledStudents();
                            } else {
                                cout << "Course not found!" << endl;
                            }
                            }
                            break;
                        case 7:
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

                try {
                    cin >> choice;
                    if (cin.fail()) {
                        throw runtime_error("Invalid input type. Please enter a valid integer.");
                    }
                } 
                catch (const exception& mes) {
                    cout << "Error: " << mes.what() << endl;
                    cin.clear();
                    // ignores all characters in the input stream until it reaches a newline
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                if (choice == 1) {
                    for (size_t i = 0; i < sec.getCourses().size(); i++) {
                        if ((sec.getCourses()[i]->getSem()%2 == 1 && sec.getSemester() == 0)
                            || (sec.getCourses()[i]->getSem()%2 == 0 && sec.getSemester() == 1)) {
                            bool validInput = false;
                            while (!validInput) {
                                cout << "Choose a professor to assign to " << sec.getCourses()[i]->getCourseName() << " (enter professor's email):" << endl;
                                Professor* professor = find_professor_from_email(sec);
                                if (professor) {
                                    sec.assignProfessorToCourse(*professor, *sec.getCourses()[i]);
                                    validInput = true;
                                } 
                                else {
                                    cout << "Wrong professor, try again!" << endl;    
                                }
                            }
                        }
                    } 
                }
                else if (choice == 2) {
                    cout << "Choose a course to assign (enter course's code):" << endl;
                    Course* course = find_course_from_code(sec);
                    if (course == nullptr) {
                        cout << "Course not found!" << endl;
                        break;
                    }
                    if ((course->getSem()%2 == 1 && sec.getSemester() == 0)
                        || (course->getSem()%2 == 0 && sec.getSemester() == 1)) {
                        bool doneAssigning = false;
                        while (!doneAssigning) {
                            cout << "Choose a professor to assign to " << course->getCourseName() << " (enter professor's email):" << endl;
                            Professor* professor = find_professor_from_email(sec);
                            if (professor) {
                                sec.assignProfessorToCourse(*professor, *course);
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
                    else if ((course->getSem()%2 == 0 && sec.getSemester() == 0)
                        || (course->getSem()%2 == 1 && sec.getSemester() == 1)) {
                        cout << "You can't assign a professor to this course this semester!" << endl;
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
            case 6: {
                string courseCode;
                cout << "Choose a course to see the students that have passed it (enter course's code):" << endl;
                cin >> courseCode;
                // Creates a new txt file to save the students who passed a lesson in a semester
                ofstream foutPassed("txt/passed_students.txt");
                foutPassed << "List of students who passed " << courseCode << " " << "are:" << endl;
                foutPassed << " " << endl;
                for (std::size_t i = 0; i < sec.getGrades().size(); i++) {
                    if ( (sec.getGrades()[i]->getCourseCode() == courseCode) && (sec.getGrades()[i]->getGrade() >= 5) ) {
                        Student* foundStudent = find_student_withAM(sec, sec.getGrades()[i]->getStudentAM());
                        foutPassed << foundStudent->getFirstName() << " " << foundStudent->getLastName() << " " << " AM: " << sec.getGrades()[i]->getStudentAM() << endl;
                    }  
                }
                foutPassed.close();
                cout << "Your text file is ready! File name: passed_students.txt" << endl; 
                cout << "*****************" << endl;
            }
                break;
            case 7: {
                // Creates a new txt file to save the students who passed a lesson in a semester
                ofstream foutPassed("txt/allGrades.txt");
                foutPassed << "List of courses and students' grades" << endl;
                for (std::size_t w = 0; w < sec.getCourses().size(); w++) {
                    foutPassed << " " << endl;
                    foutPassed << sec.getCourses()[w]->getCourseName() << " " << " Semester: " << sec.getCourses()[w]->getSem() << " " << endl;
                    string courseCode = sec.getCourses()[w]->getCode();
                    for (std::size_t i = 0; i < sec.getGrades().size(); i++) {
                        if ( sec.getGrades()[i]->getCourseCode() == courseCode ) {
                            Student* foundStudent = find_student_withAM(sec, sec.getGrades()[i]->getStudentAM());
                            foutPassed << foundStudent->getFirstName() << " " << foundStudent->getLastName() << " " << " AM: " << sec.getGrades()[i]->getStudentAM() << " Grade: " << sec.getGrades()[i]->getGrade() << " " << endl;
                        }  
                    }
                }
                foutPassed.close();
                cout << "Your text file is ready! File name: allGrades.txt" << endl; 
                cout << "*****************" << endl;
            }
                break;
            case 8:
                cout << "students that can graduate:" << endl;
                // checks if ects 
                for (size_t i = 0; i < sec.getStudents().size(); i++) {
                    if (sec.getStudents()[i]->getEcts() >= 105) {
                        int found = 0;
                        for (size_t j = 0; j < sec.getCourses().size(); j++) {
                            if (sec.getCourses()[j]->getComp() == 1) {
                                for (size_t k = 0; k < sec.getStudents()[i]->getPassedCourses().size(); k++) {
                                    if (sec.getCourses()[j]->getCode() == sec.getStudents()[i]->getPassedCourses()[k]->getCode()) {
                                        found = 1;
                                        break;
                                    }
                                }
                                if (found == 0) {
                                    break;
                                }
                            }
                            if (found == 0) {
                                break;
                            }
                        }
                        if (found == 1) {
                            cout << sec.getStudents()[i]->getFirstName() << " " << sec.getStudents()[i]->getLastName() << endl;
                        }
                    }
                }
                cout << "*****************" << endl;
                break;
            case 9:
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
        
        try {
            cin >> choice;
            if (cin.fail()) {
                throw runtime_error("Invalid input type. Please enter a valid integer.");
            }
        } 
        catch (const exception& mes) {
            cout << "Error: " << mes.what() << endl;
            cin.clear();
            // ignores all characters in the input stream until it reaches a newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string code;

        switch (choice) {
            case 1:
                professor->printCoursesTeaching(cout);
                cout << "*****************" << endl;
                break;
            case 2:
                {
                cout << "Type the code of the course you want to grade: " << endl;
                Course* foundCourse = find_course_from_code(sec);

                if (foundCourse == nullptr) {
                    cout << "Course not found!" << endl;
                    break;
                }

                //Check if the professor teaches the course
                if (foundCourse->getProfessorsTeaching().size() == 0) {
                    cout << "You don't teach this course!" << endl;
                    break;
                }
                int found = 0;
                for (size_t i = 0; i < foundCourse->getProfessorsTeaching().size(); i++) {
                    if (foundCourse->getProfessorsTeaching()[i] == professor) {
                        found = 1;
                        break;
                    }
                }
                // if they don't
                if (found == 0) {
                    cout << "You don't teach this course!" << endl;
                    break;
                }
                
                //Print the students of the course and grade them
                if (foundCourse->getEnrolledStudents().size() == 0) {
                    cout << "No students enrolled in this course!" << endl;
                    break;
                }
                for (size_t i = 0; i < foundCourse->getEnrolledStudents().size(); i++) {
                    cout << foundCourse->getEnrolledStudents()[i]->getFirstName() << " "  
                        << foundCourse->getEnrolledStudents()[i]->getLastName() << "\nAM:"
                        << foundCourse->getEnrolledStudents()[i]->getAM() << endl;
                    cout << "Enter grade: " << endl;
                    int grade;
                    
                    try {
                        cin >> grade;
                        if (cin.fail()) {
                            throw runtime_error("Invalid input type. Please enter a valid integer.");
                        }
                    } 
                    catch (const exception& mes) {
                        cout << "Error: " << mes.what() << endl;
                        cin.clear();
                        // ignores all characters in the input stream until it reaches a newline
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    //checks if grade is valid
                    while (grade < 0 || grade > 10) {
                        cout << "Wrong input, enter number between 1-10 !" << endl;
                        
                        try {
                            cin >> grade;
                            if (cin.fail()) {
                                throw runtime_error("Invalid input type. Please enter a valid integer.");
                            }
                        } 
                        catch (const exception& mes) {
                            cout << "Error: " << mes.what() << endl;
                            cin.clear();
                            // ignores all characters in the input stream until it reaches a newline
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    }
                    sec.assignGradeToStudent(*foundCourse->getEnrolledStudents()[i], *foundCourse, grade);
                    if (grade >= 5) {
                        // add student to passed students
                        sec.assignStudentToPassedStudents(*foundCourse->getEnrolledStudents()[i], *foundCourse);
                        // adds ects to student
                        int current_ects = foundCourse->getEnrolledStudents()[i]->getEcts();
                        foundCourse->getEnrolledStudents()[i]->setEcts(current_ects + foundCourse->getEcts());
                    }
                }
                cout << "*****************" << endl;
                }
                break;
            case 3:
                professor->printCourseStatistics(sec);
                cout << "*****************" << endl;
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

    while (choice != 4) {
        cout << "Student Menu" << endl;
        cout << "****************" << endl;
        cout << "1. Enroll in classes" << endl;
        cout << "2. See my grades" << endl;
        cout << "3. See my courses" << endl;
        cout << "4. Logout" << endl;
        
        try {
            cin >> choice;
            if (cin.fail()) {
                throw runtime_error("Invalid input type. Please enter a valid integer.");
            }
        } 
        catch (const exception& mes) {
            cout << "Error: " << mes.what() << endl;
            cin.clear();
            // ignores all characters in the input stream until it reaches a newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:{
                cout << "Your available courses:" << endl;
                //only prints the available courses for the current semester
                for (size_t i = 0; i < sec.getCourses().size(); i++) {
                    // correct semester
                    if ((sec.getCourses()[i]->getSem()%2 == 0 && sec.getSemester() == 1)
                        || (sec.getCourses()[i]->getSem()%2 == 1 && sec.getSemester() == 0)) {
                        // is student eligible to enroll (sem >= course sem)
                        if (student->getSem() >= sec.getCourses()[i]->getSem()) {
                            // is student already enrolled
                            int found = 0;
                            for (size_t j = 0; j < student->getMyCourses().size(); j++) {
                                if (student->getMyCourses()[j]->getCode() == sec.getCourses()[i]->getCode()) {
                                    found = 1;
                                    break;
                                }
                            }
                            // has student already passed
                            for (size_t j = 0; j < student->getPassedCourses().size(); j++) {
                                if (student->getPassedCourses()[j]->getCode() == sec.getCourses()[i]->getCode()) {
                                    found = 1;
                                    break;
                                }
                            }
                            if (found == 0) {
                                cout << *sec.getCourses()[i] << endl;
                            }
                        }
                    }
                }
                cout << "Enter the code of the course you want to enroll in:" << endl;
                Course* foundCourse = find_course_from_code(sec);
                if (foundCourse) {
                    if (student->getSem() >= foundCourse->getSem()) {
                        if ((foundCourse->getSem()%2 == 0 && sec.getSemester() == 1)
                            || (foundCourse->getSem()%2 == 1 && sec.getSemester() == 0)) {
                            int found = 0;
                            // is student already enrolled
                            for (size_t j = 0; j < student->getMyCourses().size(); j++) {
                                if (student->getMyCourses()[j]->getCode() == foundCourse->getCode()) {
                                    found = 1;
                                    break;
                                }
                            }
                            // has student already passed
                            for (size_t j = 0; j < student->getPassedCourses().size(); j++) {
                                if (student->getPassedCourses()[j]->getCode() == foundCourse->getCode()) {
                                    found = 1;
                                    break;
                                }
                            }
                            if (found == 0) {
                                sec.assignStudentToCourse(*student, *foundCourse);
                            }
                            else {
                                cout << "You are already enrolled or have already passed this course!" << endl;
                            }
                        }
                        else {
                            cout << "You can't enroll in this course this semester!" << endl;
                        }
                    }
                    else {
                        cout << "You can't enroll in this course!" << endl;
                    }
                }
                else {
                    cout << "Course not found!" << endl;
                }
                cout << "*****************" << endl;
            }
                break;
            case 2: {
                int choice_g = 0;
                while (choice_g != 3) {
                    cout << "My grades" << endl;
                    cout << "****************" << endl;
                    cout << "1. View my grades for the current semester" << endl;
                    cout << "2. View my grades for all semesters" << endl;
                    cout << "3. Back" << endl;
                    
                    try {
                        cin >> choice_g;
                        if (cin.fail()) {
                            throw runtime_error("Invalid input type. Please enter a valid integer.");
                        }
                    } 
                    catch (const exception& mes) {
                        cout << "Error: " << mes.what() << endl;
                        cin.clear();
                        // ignores all characters in the input stream until it reaches a newline
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    switch (choice_g) {
                        case 1: {
                            cout << "Current semester:" << endl;
                            cout << student->getSem() << endl;
                            cout << "My grades for the current semester are:" << endl;
                            for (size_t i = 0; i < sec.getGrades().size(); i++) { 
                                if (sec.getGrades()[i]->getStudentAM() == student->getAM()) {
                                    Course* foundCourse = find_course_with_code(sec, sec.getGrades()[i]->getCourseCode());
                                    cout << foundCourse->getCourseName() << ": " << sec.getGrades()[i]->getGrade() << endl;
                                }
                            }
                        }
                        break;
                        case 2: {
                            cout << "My grades for all the semesters are:" << endl;
                            for (size_t i = 0; i < sec.getGrades().size(); i++) { 
                                Course* foundCourse = find_course_with_code(sec, sec.getGrades()[i]->getCourseCode());
                                if (sec.getGrades()[i]->getStudentAM() == student->getAM()) {
                                    cout << foundCourse->getCourseName() << ": " << sec.getGrades()[i]->getGrade() << endl;
                                }
                            }
                            cout << "Total ECTS: " << student->getEcts() << endl;
                        }
                        break;
                        case 3:
                            break;
                        default:
                            cout << "Wrong input" << endl;
                            break;

                    }
                }
                cout << "*****************" << endl;
            }
            break;
            case 3: {
                //prints courses that student is enrolled in
                cout << "Enrolled this semester:" << endl;
                if (student->getMyCourses().size() == 0) {
                    cout << "No courses enrolled!" << endl;
                }
                for (size_t i = 0; i < student->getMyCourses().size(); i++) {
                    cout << student->getMyCourses()[i]->getCourseName() << " " << student->getMyCourses()[i]->getCode() << endl;
                }
                cout << "****************" << endl;
                //prints courses that student has passed
                cout << "My passed courses:" << endl;
                if (student->getPassedCourses().size() == 0) {
                    cout << "No courses passed!" << endl;
                }
                for (size_t i = 0; i < student->getPassedCourses().size(); i++) {
                    cout << student->getPassedCourses()[i]->getCourseName() << " " << student->getPassedCourses()[i]->getCode() << endl;
                }
                cout << "****************" << endl;
            }
            break;
            case 4: {
                cout << "Logging out..." << endl;
            }
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
}

Student* find_student_fromAM(Secretary &sec) {
    long int targetAM = 0;

    try {
        cin >> targetAM;
        if (cin.fail()) {
            throw runtime_error("Invalid input type. Please enter a valid integer.");
        }
    } 
    catch (const exception& mes) {
        cout << "Error: " << mes.what() << endl;
        cin.clear();
        // ignores all characters in the input stream until it reaches a newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


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
    string targetCode;
    cin >> targetCode;
    
    Course* foundCourse = nullptr;
    vector<Course*> const &courses = sec.getCourses();

    for (size_t i = 0; i < courses.size(); i++) {
        if (courses.at(i)->getCode() == targetCode) {
            foundCourse = courses[i];
            break;
        }
    }

    if (foundCourse == nullptr) {
        return nullptr;
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
        cout << "Course Info: \n" << *foundCourse << 
        "Semester: " << foundCourse->getSem() << "\n" <<
        "ECTS: " << foundCourse->getEcts() << endl;
        if (foundCourse->getComp() == true) {
            cout << "Compulsory: Yes" << endl;
        }
        else {
            cout << "Compulsory: No" << endl;
        }
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

// Function to find a student with a specific AM
Student* find_student_withAM(Secretary &sec, long int AM) {
    
    Student* foundStudent = nullptr;
    vector<Student*> const &students = sec.getStudents();

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getAM() == AM) {
            foundStudent = students[i];
            break;
        }
    }
    return foundStudent;
}

//Function to find a course with a specific code
Course* find_course_with_code(Secretary &sec, string code) {

    Course* foundCourse = nullptr;
    vector<Course*> const &courses = sec.getCourses();

    for (size_t i = 0; i < courses.size(); i++) {
        if (courses[i]->getCode() == code) {
            foundCourse = courses[i];
            break;
        }
    }
    return foundCourse;
}

