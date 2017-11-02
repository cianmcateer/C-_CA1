#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <ostream>
#include <typeinfo>

class Student {
private:
    std::string name;
    int age;
    int attendance;
    float gpa;
    std::string comment;
    bool passed;

public:
    Student(std::string name, int age, int attendance, float gpa, std::string comment);
    Student();
    ~Student();
    std::string to_html();

    inline std::string get_name() const {
        return name;
    }

    inline int get_age() const {
        return age;
    }

    inline int get_attendance() const {
        return attendance;
    }

    inline float get_gpa() const {
        return gpa;
    }

    inline std::string get_comment() const {
        return comment;
    }

    inline bool has_passed() const {
        return passed;
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

inline std::ostream& operator<<(std::ostream& output_stream, const Student& s) {
    output_stream << "NAME: " << s.get_name() << " AGE: " <<
    s.get_age() << " ATTENDANCE: " <<
    s.get_attendance() << " GPA: " << s.get_gpa() << " COMMENT: " << s.get_comment() << std::endl;

    return output_stream;
}

inline std::istream& operator>>(std::istream& input_stream, Student& s) {

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

inline bool operator<(const Student s1, const Student s2) {

    if(s1.get_name() < s2.get_name()) return true;
    if(s2.get_name() < s1.get_name()) return false;

    if(s1.get_age() < s2.get_age()) return true;
    if(s2.get_age() < s1.get_age()) return false;

    if(s1.get_gpa() < s2.get_gpa()) return true;
    if(s2.get_gpa() < s1.get_gpa()) return false;

    return false;

}

inline bool operator==(const Student& s1, const Student& s2) {
    if(s1.get_name() == s2.get_name() && s1.get_age() == s2.get_age()) {
        return true;
    }
    return false;
}

inline bool operator!=(const Student& s1, const Student& s2) {
    return !(s1 == s2);
}
