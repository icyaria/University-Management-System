#include "professor.h"

using namespace std;

        Professor::Professor() {
        } // the constructor calls the constructor of Person

        Professor::Professor(string f, string l, string e, long int ph) : Person(f, l, e, ph) {
        } 