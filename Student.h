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

    inline void set_name(std::string name) {
        this->name = name;
    }

    inline void set_age(int age) {

        this->age = age;
    }

    inline void set_attendance(int attendance) {
        if(attendance > 100) {
            throw std::logic_error("Attendance is marked out 100");
        } else {
            this->attendance = attendance;
        }

    }

    inline void set_gpa(float gpa) {
        if(gpa > 100) {
            throw std::logic_error("GPA is marked out 100");
        }
        this->gpa = gpa;

    }

    inline void set_comment(std::string comment) {
        this->comment = comment;
    }

    friend std::ostream& operator<<(std::ostream& output_stream, const Student& s);
    friend std::istream& operator>>(std::istream& input_stream, Student& s);
    friend bool operator<(const Student& s1, const Student& s2);


};
