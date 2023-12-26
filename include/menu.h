#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Secretary;
class Student;
class Professor;

Student* find_student_fromAM(Secretary &sec);
void deleteStudent(Secretary &sec);
void editStudent(Secretary &sec);
void secretaryMenu(Secretary &sec);
void professorMenu();
void studentMenu();


#endif