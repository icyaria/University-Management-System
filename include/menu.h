#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Secretary;
class Student;
class Professor;

void editStudent(Secretary &sec);
void secretaryMenu(Secretary &sec);
void professorMenu();
void studentMenu();


#endif