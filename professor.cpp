#include "professor.h"

using namespace std;

        Professor::Professor() {
        } // the constructor calls the constructor of Person

        Professor::Professor(string f, string l, string e, long int ph) : Person(f, l, e, ph) {
        } 

        void Professor::printCourseStatistics() const {
                cout << "Professor " << getFirstName() << " " << getLastName() << " teaches " << coursesTeaching.size() << " courses" << endl;
                for (int i = 0; i < coursesTeaching.size(); i++) {
                        cout << coursesTeaching.at(i)->getCourseName() << endl;
                        // οταν βαλουμε βαθμο κλπ να το προσθεσουμε
                }
                
        }

        void Professor::assignCourse(Course& course) {
                coursesTeaching.push_back(&course);
        }