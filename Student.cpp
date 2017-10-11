#include "Student.h"


Student::Student(string name, int age, int attendance, float gpa ,string comment)
: name(name) , age(age) , attendance(attendance), gpa(gpa), comment(comment)  {

}

Student::~Student(){}

bool Student::has_passed()  {
    return gpa >= 40;
}
