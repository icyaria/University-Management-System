#include "secretary.h"

using namespace std;

        Secretary::Secretary() {
                semester_type = 0;
        }

        Secretary::Secretary(const Secretary &sec) { //copy constructor
                for (size_t i = 0; i<sec.vecp.size(); i++) {
                        Professor* newProfessor = new Professor(*sec.vecp.at(i));  
                        vecp.push_back(newProfessor);
                }
                for (size_t i = 0; i<sec.vecs.size(); i++) {
                        Student* newStudent = new Student(*sec.vecs.at(i));  
                        vecs.push_back(newStudent);
                }
                for (size_t i = 0; i<sec.vecc.size(); i++) {
                        Course* newCourse = new Course(*sec.vecc.at(i));  
                        vecc.push_back(newCourse);
                }
                for (size_t i = 0; i<sec.vecg.size(); i++) {
                        Grade* newGrade = new Grade(*sec.vecg.at(i));  
                        vecg.push_back(newGrade);
                }
                semester_type = sec.semester_type;
        }

        Secretary::~Secretary() {
                vecp.clear();  
                vecs.clear();
                vecc.clear();
                vecg.clear();
        }

        vector<Professor*> Secretary::getProfessors() const {
                return vecp;
        }

        vector<Student*> Secretary::getStudents() const {
                return vecs;
        }

        vector<Course*> Secretary::getCourses() const {
                return vecc;
        }

        vector<Grade*> Secretary::getGrades() const {
                return vecg;
        }

        bool Secretary::getSemester() const {
                return semester_type;
        }

        void Secretary::add(Professor &p) {
                vecp.push_back(&p);

        }
        
        void Secretary::add(Student &s) {
                vecs.push_back(&s);
        }

        void Secretary::add(Course &c) {
                vecc.push_back(&c);
        }

        void Secretary::remove(Professor &p) {
                size_t size = vecp.size();
                for (size_t i = 0; i<size; i++) {
                        if (vecp.at(i)->getFirstName() == p.getFirstName() &&
                            vecp.at(i)->getLastName() == p.getLastName() &&
                            vecp.at(i)->getEmail() == p.getEmail() &&
                            vecp.at(i)->getPhone() == p.getPhone()) {
                                cout<<"\nRemoved "<<p.getFirstName()<<" "<<p.getLastName() <<" from Secretary"<<endl;
                                delete vecp.at(i);
                                
                                // Shift all elements after the erased one to the left
                                for (size_t j = i; j < vecp.size() - 1; j++) {
                                        vecp.at(j) = vecp.at(j + 1);
                                }
                                //remove the last element
                                vecp.pop_back();

                                return;
                        }
                }
        }

        void Secretary::remove(Student &s) {
                size_t size = vecs.size();
                for (size_t i = 0; i<size; i++) {
                        if (vecs.at(i)->getFirstName() == s.getFirstName() &&
                            vecs.at(i)->getLastName() == s.getLastName() &&
                            vecs.at(i)->getEmail() == s.getEmail() &&
                            vecs.at(i)->getPhone() == s.getPhone()) {
                                cout<<"\nRemoved "<<s.getFirstName()<<" "<<s.getLastName() <<" from Secretary"<<endl;
                                delete vecs.at(i);
                                
                                // Shift all elements after the erased one to the left
                                for (size_t j = i; j < vecs.size() - 1; j++) {
                                        vecs.at(j) = vecs.at(j + 1);
                                }
                                //remove the last element
                                vecs.pop_back();

                                return;
                        }
                }
        }

        void Secretary::remove(Course &c) {
                size_t size = vecc.size();
                for (size_t i = 0; i<size; i++) {
                        if (vecc.at(i)->getCourseName() == c.getCourseName() &&
                            vecc.at(i)->getCode() == c.getCode() &&
                            vecc.at(i)->getSem() == c.getSem() &&
                            vecc.at(i)->getEcts() == c.getEcts() &&
                            vecc.at(i)->getComp() == c.getComp()) {
                                cout<<"\nRemoved "<<c.getCourseName()<<" from Secretary"<<endl;
                                delete vecc.at(i);
                                
                                // Shift all elements after the erased one to the left
                                for (size_t j = i; j < vecc.size() - 1; j++) {
                                        vecc.at(j) = vecc.at(j + 1);
                                }
                                //remove the last element
                                vecc.pop_back();

                                return;
                        }
                }
        }


        bool Secretary::find_professor(Secretary &sec, Person &professor) {
                int size = sec.vecp.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecp.at(i)->getFirstName() == professor.getFirstName() &&
                            sec.vecp.at(i)->getLastName() == professor.getLastName() &&
                            sec.vecp.at(i)->getEmail() == professor.getEmail() &&
                            sec.vecp.at(i)->getPhone() == professor.getPhone()) {
                                cout << "\n" << endl;
                                return true;
                        }
                }
                cout << "\n" << endl;
                return false;
        }

        bool Secretary::find_student(Secretary &sec, Person &student) {
                int size = sec.vecs.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecs.at(i)->getFirstName() == student.getFirstName() &&
                            sec.vecs.at(i)->getLastName() == student.getLastName() &&
                            sec.vecs.at(i)->getEmail() == student.getEmail() &&
                            sec.vecs.at(i)->getPhone() == student.getPhone()) {
                                return true;
                        }
                }
                return false;
        }

        bool Secretary::find_person(Secretary &sec, Person &person) {
                cout << "\nSearching for "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                int sizep = sec.vecp.size();
                int sizes = sec.vecs.size();
                for (int i = 0; i<sizep; i++) {
                        if (sec.vecp.at(i)->getFirstName() == person.getFirstName() &&
                            sec.vecp.at(i)->getLastName() == person.getLastName() &&
                            sec.vecp.at(i)->getEmail() == person.getEmail() &&
                            sec.vecp.at(i)->getPhone() == person.getPhone()) {
                                cout << "Found "<< person.getFirstName() << " " << person.getLastName() << " in Secretary. They are a Professor" << endl;
                                cout << "\n" << endl;
                                return true;
                        }
                }
                for (int i = 0; i<sizes; i++) {
                        if (sec.vecs.at(i)->getFirstName() == person.getFirstName() &&
                            sec.vecs.at(i)->getLastName() == person.getLastName() &&
                            sec.vecs.at(i)->getEmail() == person.getEmail() &&
                            sec.vecs.at(i)->getPhone() == person.getPhone()) {
                                cout << "Found "<< person.getFirstName() << " " << person.getLastName() << " in Secretary. They are a student" << endl;
                                cout << "\n" << endl;
                                return true;
                        }
                }
                cout << "Couldn't find "<< person.getFirstName() << " " << person.getLastName() << " in Secretary" << endl;
                cout << "\n" << endl;
                return false;
        }

        bool Secretary::find_course(Secretary &sec, Course &course) {
                int size = sec.vecc.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecc.at(i)->getCourseName() == course.getCourseName() &&
                            sec.vecc.at(i)->getCode() == course.getCode() &&
                            sec.vecc.at(i)->getSem() == course.getSem() &&
                            sec.vecc.at(i)->getEcts() == course.getEcts() &&
                            sec.vecc.at(i)->getComp() == course.getComp()) {
                                cout << "\n" << endl;
                                return true;
                        }
                }
                cout << "\n" << endl;
                return false;
        }

        //Operators overloading
        ostream &operator<<(ostream &ostr, Secretary &secretary) {
                ostr << "\nProfessors in secretary are: " << endl;
                for (size_t i = 0; i<secretary.vecp.size(); i++) {
                     cout<< *secretary.vecp.at(i)<< endl; // prints all professors in secretary
                }
                ostr << "\nStudents in secretary are:" << endl;
                for (size_t i = 0; i<secretary.vecs.size(); i++) {
                     cout<< *secretary.vecs.at(i)<< endl; // prints all students in secretary
                }
                return ostr;
        }

        Secretary& Secretary::operator+(Professor &professor) {
                add(professor);
                return *this;                 
        }

        Secretary& Secretary::operator+(Student &student) {
                add(student);
                return *this;                 
        }

        Secretary& Secretary::operator+(Course &course) {
                add(course);
                return *this;                 
        }

        Secretary Secretary::operator=(const Secretary &sec) {
                for (size_t i = 0; i<sec.vecp.size(); i++) {
                        Professor* newProfessor = new Professor(*sec.vecp.at(i));  
                        vecp.push_back(newProfessor);
                }
                for (size_t i = 0; i<sec.vecs.size(); i++) {
                        Student* newStudent = new Student(*sec.vecs.at(i));  
                        vecs.push_back(newStudent);
                }
                return *this;
        }

        ostream& Secretary::printProfessors(ostream &ostr) {
                ostr << "\nProfessors in secretary are: " << endl;
                for (size_t i = 0; i< vecp.size(); i++) {
                     cout<< *vecp.at(i)<< endl; // prints all professors in secretary
                }
                return ostr;
        }

        ostream& Secretary::printStudents(ostream &ostr) {
                ostr << "\nStudents in secretary are:" << endl;
                for (size_t i = 0; i<vecs.size(); i++) {
                     cout<< *vecs.at(i)<< endl; // prints all students in secretary
                }
                return ostr;
        }

        ostream& Secretary::printCourses(ostream &ostr) {
                ostr << "\nCourses in secretary are:" << endl;
                for (size_t i = 0; i<vecc.size(); i++) {
                     cout<< *vecc.at(i)<< endl; // prints all courses in secretary
                }
                return ostr;
        }

        void Secretary::new_semester() {
                //changes the students' semester to the next one
                int size = vecs.size();
                for (int i = 0; i<size; i++) {
                        int sem = vecs.at(i)->getSem();
                        sem++;
                        vecs.at(i)->setSem(sem);
                }
                // clears the courses a professor teaches and the teaching professors of a course
                size = vecp.size();
                for (int i = 0; i<size; i++) {
                        vecp.at(i)->getCoursesTeaching().clear();
                }
                size = vecc.size();
                for (int i = 0; i<size; i++) {
                        vecc.at(i)->getProfessorsTeaching().clear();
                }
                // clears the students enrolled in a course
                size = vecc.size();
                for (int i = 0; i<size; i++) {
                        vecc.at(i)->getEnrolledStudents().clear();
                }
                size = vecs.size();
                for (int i = 0; i<size; i++) {
                        vecs.at(i)->getMyCourses().clear();
                }

                // changes the semester of the secretary
                semester_type = !semester_type;
        }

        void Secretary::assignProfessorToCourse(Professor& professor, Course& course) {
                //checks if professor already teaches the course
                int size = professor.getCoursesTeaching().size();
                for (int i = 0; i<size; i++) {
                        if (professor.getCoursesTeaching().at(i)->getCode() == course.getCode()) {
                                cout << "Professor already teaches this course" << endl;
                                return;
                        }
                }
                course.assignProfessor(professor);
                professor.assignCourse(course);
                cout << "Professor assigned successfully" << endl;
        }

        void Secretary::assignStudentToCourse(Student& student, Course& course) {
                course.assignStudent(student);
                student.assignCourse(course);
        }

        void Secretary::assignGradeToStudent(Student& student, Course& course, int g) {
                //checks if student has already been graded
                int size = vecg.size();
                for (int i = 0; i<size; i++) {
                        if (vecg.at(i)->getStudentAM() == student.getAM() &&
                            vecg.at(i)->getCourseCode() == course.getCode()) {
                                cout << "Student has already been graded" << endl;
                                return;
                        }
                }
                Grade* grade = new Grade(g, student.getAM(), course.getCode());
                vecg.push_back(grade);
                cout << "Graded successfully" << endl;
        }

        void Secretary::assignStudentToPassedStudents(Student& student, Course& course) {
                course.assignPassedStudent(student);
                student.assignPassedCourse(course);
        }



