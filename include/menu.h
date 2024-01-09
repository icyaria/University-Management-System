#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Secretary;
class Student;
class Professor;
class Course;

void secretaryMenu(Secretary &sec);
void professorMenu(Secretary &sec, Professor* &professor);
void studentMenu(Secretary &sec, Student* &student);

Student* find_student_fromAM(Secretary &sec);
Student* find_student_withAM(Secretary &sec, long int AM);
Professor* find_professor_from_email(Secretary &sec);
Course* find_course_from_code(Secretary &sec);

void editStudent(Secretary &sec);
void deleteStudent(Secretary &sec);
void editProfessor(Secretary &sec);
void deleteProfessor(Secretary &sec);
void editCourse(Secretary &sec);
void deleteCourse(Secretary &sec);

Professor* login_p(Secretary &sec);
Student* login_s(Secretary &sec);

#endif