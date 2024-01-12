#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Secretary;
class Student;
class Professor;
class Course;

void secretaryMenu(Secretary &sec);
void professorMenu(Secretary &sec, Professor* &professor);
void studentMenu(Secretary &sec, Student* &student);

Student* find_student_fromAM(Secretary &sec); //gets AM from user
Student* find_student_withAM(Secretary &sec, long int AM); //gets AM as input in the function
Professor* find_professor_from_email(Secretary &sec);
Course* find_course_from_code(Secretary &sec);
Course* find_course_with_code(Secretary &sec, string code);

void editStudent(Secretary &sec);
void deleteStudent(Secretary &sec);
void editProfessor(Secretary &sec);
void deleteProfessor(Secretary &sec);
void editCourse(Secretary &sec);
void deleteCourse(Secretary &sec);

Professor* login_p(Secretary &sec);
Student* login_s(Secretary &sec);

#endif