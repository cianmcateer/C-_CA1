#include "Student.h"


Student::Student(std::string name, int age, int attendance, float gpa ,std::string comment)
: name(name) , age(age) , attendance(attendance), gpa(gpa), comment(comment)  {

}

Student::Student(){
    this->name = "Default name";
    this->age = 0;
    this->attendance = 0;
    this->gpa = 0;
    this->comment = "Default comment";
}

Student::~Student(){}

bool Student::has_passed()  {
    return gpa >= 40;
}

std::string Student::to_html() {

    std::ostringstream oss;

    oss << "<td>" << this->name << "</td>"
    << "<td>" << this->age << "</td>"
    << "<td>" << this->attendance << "</td>"
    << "<td>" << this->gpa << "</td>"
    << "<td>" << this->comment << "</td>";

    return oss.str();
}
