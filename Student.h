#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <ostream>



class Student {
private:
    std::string name;
    int age;
    int attendance;
    float gpa;
    std::string comment;

public:
    Student(std::string name, int age, int attendance, float gpa, std::string comment);
    Student();
    ~Student();
    bool has_passed();

    inline std::string get_name() const{
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

    inline std::string get_comment() const{
        return comment;
    }

    inline void set_name(std::string name) {
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

    inline void set_comment(std::string comment) {
        this->comment = comment;
    }

};

inline std::ostream& operator<<(std::ostream& output_stream, Student& s) {
    output_stream << "NAME: " << s.get_name() << " AGE: " << s.get_age()
    << " ATTENDANCE: " << s.get_attendance() << " GPA: " << s.get_gpa()
    << " COMMENT: " << s.get_comment() << std::endl;

    return output_stream;
}

inline std::istream& operator>>(std::istream& input_stream, const Student& s) {

    return input_stream;
}
