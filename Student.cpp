#include "Student.h"


Student::Student(std::string name, int age, int attendance, float gpa ,std::string comment)
: name(name) , age(age) , attendance(attendance), gpa(gpa), comment(comment)  {

}

Student::Student(){}

Student::~Student(){}

bool Student::has_passed()  {
    return gpa >= 40;
}
