#include "Student.h"

Student::Student(std::string name, int age, int attendance, float gpa ,std::string comment)
: name(name) ,age(age) , attendance(attendance), gpa(gpa), comment(comment)  {}

Student::Student() : name("Default name") ,age(0) , attendance(0), gpa(0), comment("Default comment")  {}

Student::~Student(){}

std::string Student::to_html() {

    // ostringstream is used instead as we
    // don't need to convert floats and ints to strings
    std::ostringstream oss;

    oss << "<td>" << this->name << "</td>"
    << "<td>" << this->age << "</td>"
    << "<td>" << this->attendance << "</td>"
    << "<td>" << this->gpa << "</td>"
    << "<td>" << this->comment << "</td>";

    return oss.str();
}

std::ostream& operator<<(std::ostream& output_stream, const Student& s) {
    output_stream << "NAME: " << s.get_name() << " AGE: " <<
    s.get_age() << " ATTENDANCE: " <<
    s.get_attendance() << " GPA: " << s.get_gpa() << " COMMENT: " << s.get_comment() << std::endl;

    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Student& s) {

    std::string name;
    input_stream >> name;
    s.set_name(name);

    int age;
    input_stream >> age;
    s.set_age(age);

    int attendance;
    input_stream >> attendance;
    s.set_attendance(attendance);

    float gpa;
    input_stream >> gpa;
    s.set_gpa(gpa);

    std::string comment;
    input_stream >> comment;
    s.set_comment(comment);

    return input_stream;
}

bool operator<(const Student& s1, const Student& s2) {

    if(s1.get_name() < s2.get_name()) return true;
    if(s2.get_name() < s1.get_name()) return false;

    if(s1.get_age() < s2.get_age()) return true;
    if(s2.get_age() < s1.get_age()) return false;

    if(s1.get_gpa() < s2.get_gpa()) return true;
    if(s2.get_gpa() < s1.get_gpa()) return false;

    return false;

}
