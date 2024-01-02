#include "professor.h"
#include "course.h"

using namespace std;

        Professor::Professor() {
        } // the constructor calls the constructor of Person

        Professor::Professor(string f, string l, string e, long int ph) : Person(f, l, e, ph) {
                coursesTeaching = {};
        } 

        Professor::Professor(const Professor &professor) : Person(professor) {
                coursesTeaching = professor.coursesTeaching;
        }

        void Professor::printCoursesTeaching(ostream& ostr) {
                ostr << "\nMy courses are: " << endl;

                cout << "Number of courses: " << getCoursesTeaching().size() << endl;
                
                if(!coursesTeaching.empty()) {
                        for (size_t i = 0; i < coursesTeaching.size(); i++) {
                                ostr << *(coursesTeaching.at(i)) << endl;
                        }
                }
                else {
                        cout << "No courses available." << std::endl;
                }
        }

        void Professor::printCourseStatistics() const {
                cout << "Professor " << getFirstName() << " " << getLastName() << " teaches " << coursesTeaching.size() << " courses" << endl;
                for (size_t i = 0; i < coursesTeaching.size(); i++) {
                        cout << coursesTeaching.at(i)->getCourseName() << endl;
                        // οταν βαλουμε βαθμο κλπ να το προσθεσουμε
                }        
        }

        void Professor::assignCourse(Course& course) {
                coursesTeaching.push_back(&course);
        }

        vector<Course*> Professor::getCoursesTeaching() const {
                return coursesTeaching;
        }
