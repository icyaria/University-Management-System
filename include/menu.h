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
void studentMenu();

Student* find_student_fromAM(Secretary &sec);
Professor* find_professor_from_email(Secretary &sec);
Course* findCourseFromCode(Professor &prof);

void editStudent(Secretary &sec);
void deleteStudent(Secretary &sec);
void editProfessor(Secretary &sec);
void deleteProfessor(Secretary &sec);

Professor* loginn(Secretary &sec);

#endif