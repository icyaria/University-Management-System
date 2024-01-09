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

        #include "secretary.h" // Include the header file for the Secretary class

        void Professor::printCourseStatistics(Secretary &sec) const {  
                cout << "Course statistics for: " << endl;
                for (size_t i = 0; i < coursesTeaching.size(); i++) {
                        double sum = 0;
                        int students = 0;
                        int passed = 0;
                        for (size_t j = 0; j < sec.getGrades().size(); j++) {
                                if (sec.getGrades().at(j)->getCourseCode() == coursesTeaching.at(i)->getCode()) {
                                        sum += sec.getGrades().at(j)->getGrade();
                                        students++;
                                        if (sec.getGrades().at(j)->getGrade() >= 5) {
                                                passed++;
                                        }
                                }
                                else {
                                        continue;
                                }
                        }
                        int percentage = 0;
                        double average = 0.0;
                        if (students != 0) {
                                cout << coursesTeaching.at(i)->getCourseName()  << endl;
                                // percentage of students that passed
                                percentage = (passed * 100) / students;
                                // average grade
                                average = sum / students;
                                // prints average grade if there are students
                                cout << "Average grade: " << average << endl;
                                // prints percentage of students that passed
                                cout << "Percentage of students that passed: " << percentage << "%" << endl;
                        }
                }
        }

        void Professor::assignCourse(Course& course) {
                coursesTeaching.push_back(&course);
        }

        vector<Course*>& Professor::getCoursesTeaching() {
                return coursesTeaching;
        }