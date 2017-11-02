#include "Student.h"

Student::Student(std::string name, int age, int attendance, float gpa ,std::string comment)
: name(name) ,age(age) , attendance(attendance), gpa(gpa), comment(comment)  {}

Student::Student() : name("Default name") ,age(0) , attendance(0), gpa(0), comment("Default comment")  {}

Student::~Student(){}

std::string Student::to_html() {

    std::ostringstream oss;

    oss << "<td>" << this->name << "</td>"
    << "<td>" << this->age << "</td>"
    << "<td>" << this->attendance << "</td>"
    << "<td>" << this->gpa << "</td>"
    << "<td>" << this->comment << "</td>";

    return oss.str();
}
