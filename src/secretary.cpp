#include "secretary.h"

using namespace std;

        Secretary::Secretary() {
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
        }

        Secretary::~Secretary() {
                int sizep = vecp.size();
                int sizes = vecs.size();              
                 for (int i = 0; i < sizep; i++) {
                        delete vecp.at(i);
                }
                for (int i = 0; i < sizes; i++) {
                        delete vecs.at(i);
                }
                vecp.clear();  
                vecs.clear();// Clear the vector after deleting its elements
        }

        vector<Professor*> Secretary::getProfessors() const {
                return vecp;
        }

        vector<Student*> Secretary::getStudents() const {
                return vecs;
        }

        void Secretary::add(Professor &p) {
                Professor* newp = new Professor(p);
                vecp.push_back(newp);
                cout<<"\nAdded "<<p.getFirstName()<<" "<<p.getLastName() <<" in Secretary"<<endl;
        }
        
        void Secretary::add(Student &s) {
                Student* news = new Student(s);
                vecs.push_back(news);
                cout<<"\nAdded "<<s.getFirstName()<<" "<<s.getLastName() <<" in Secretary"<<endl;
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


        bool Secretary::find_professor(Secretary &sec, Person &professor) {
                //cout << "\nSearching for "<< professor.getFirstName() << " " << professor.getLastName() << " in professors" << endl;
                int size = sec.vecp.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecp.at(i)->getFirstName() == professor.getFirstName() &&
                            sec.vecp.at(i)->getLastName() == professor.getLastName() &&
                            sec.vecp.at(i)->getEmail() == professor.getEmail() &&
                            sec.vecp.at(i)->getPhone() == professor.getPhone()) {
                                //cout << "Found Professor "<< professor.getFirstName() << " " << professor.getLastName() << " in Secretary" << endl;
                                cout << "\n" << endl;
                                return true;
                        }
                }
                //cout << "Couldn't find Professor "<< professor.getFirstName() << " " << professor.getLastName() << " in Secretary" << endl;
                cout << "\n" << endl;
                return false;
        }

        bool Secretary::find_student(Secretary &sec, Person &student) {
                //cout << "\nSearching for "<< student.getFirstName() << " " << student.getLastName() << " in students" << endl;
                int size = sec.vecs.size();
                for (int i = 0; i<size; i++) {
                        if (sec.vecs.at(i)->getFirstName() == student.getFirstName() &&
                            sec.vecs.at(i)->getLastName() == student.getLastName() &&
                            sec.vecs.at(i)->getEmail() == student.getEmail() &&
                            sec.vecs.at(i)->getPhone() == student.getPhone()) {
                                //cout << "Found Student "<< student.getFirstName() << " " << student.getLastName() << " in Secretary" << endl;
                                //cout << "\n" << endl;
                                return true;
                        }
                }
                //cout << "Couldn't find Student "<< student.getFirstName() << " " << student.getLastName() << " in Secretary" << endl;
                //cout << "\n" << endl;
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

        //Operators overloading
        istream &operator>>(istream &istr, Secretary &secretary) {
                cout << "Enter professor or student? (p/s)" << endl;
                string choice;
                istr >> choice;
                if (choice == "p") {
                        cout << "Enter professor's details to add to secretary: " << endl;
                        Professor* newProfessor = new Professor;  
                        istr >> *newProfessor; // inputs information from user           
                        secretary.add(*newProfessor);
                        return istr;
                }
                else if (choice == "s") {
                        cout << "Enter student's details to add to secretary: " << endl;
                        Student* newStudent = new Student;  
                        istr >> *newStudent; // inputs information from user           
                        secretary.add(*newStudent);
                        return istr;
                }
                else {
                        cout << "Wrong input" << endl;
                        return istr;
                }
        }

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

        ostream &printProfessors(ostream &ostr, Secretary &secretary) {
                ostr << "\nProfessors in secretary are: " << endl;
                for (size_t i = 0; i<secretary.vecp.size(); i++) {
                     cout<< *secretary.vecp.at(i)<< endl; // prints all professors in secretary
                }
                return ostr;
        }

        ostream &printStudents(ostream &ostr, Secretary &secretary) {
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

        void Secretary::new_semester(Secretary &sec) {
                //changes the students' semester to the next one
                int size = sec.vecs.size();
                for (int i = 0; i<size; i++) {
                        int sem = sec.vecs.at(i)->getSem();
                        sem++;
                        sec.vecs.at(i)->setSem(sem);
                }
        }

        void Secretary::assignProfessorToCourse(Professor& professor, Course& course) {
                course.assignProfessor(professor);
        }