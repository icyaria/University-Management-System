#include <iostream>
#include <string>
#include "professor.h"
#include "student.h"

using namespace std;

class Course {
private:
    string course_name;
    string code;
    int sem;
    int ects;
    bool comp;
public:
    // default constructor
    Course();

    Course(string cn, string c, int s, int e, bool co);

    // destructor
    ~Course();

    // getters και setters
    string getCourseName() const;
    //void setCourseName(string newCN);

    string getCode() const;
    //void setCode(string newCode);

    int getSem() const;
    void setSem(int newSem);

    int getEcts() const;
    //void setEcts(int newEcts);

    bool getComp() const;
    //void setComp(bool newComp); 

};