#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <ostream>


using std::string;
using std::map;
using std::cout;
using std::endl;
using std::vector;

class Student {
private:
    string name;
    int age;
    float gpa;
    int attendance;
    string comment;

public:
    Student(string name, int age, int attendance, float gpa, string comment);
    ~Student();
    bool has_passed();

    inline string get_name() const{
        return name;
    }

    inline int get_age() const{
        return age;
    }

    inline int get_attendance() const{
        return attendance;
    }

    inline float get_gpa() const{
        return gpa;
    }

    inline string get_comment() const{
        return comment;
    }

    inline void set_name(string name) {
        this->name = name;
    }

    inline void set_age(int age) {
        this->age = age;
    }

    inline void set_attendance(int attendance) {
        this->attendance = attendance;
    }

    inline void set_gpa(float gpa) {
        this->gpa = gpa;
    }

    inline void set_comment(string comment) {
        this->comment = comment;
    }

};

inline std::ostream& operator<<(std::ostream& output_stream, Student& s) {
    output_stream << "NAME: " << s.get_name() << " AGE: " << s.get_age()
    << " ATTENDANCE: " << s.get_attendance() << " GPA: " << s.get_gpa()
    << " COMMENT: " << s.get_comment() << endl;

    return output_stream;
}

inline std::istream& operator>>(std::istream& input_stream, Student& s) {

    return input_stream;
}
