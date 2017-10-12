#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Student.h"
#include "Student_Store.h"

using std::map;
using std::vector;
using std::string;

class Student_Store{

private:
    map<string,vector<Student> > school_data;

public:
    // Constructor / Destructor
    Student_Store();
    ~Student_Store();

    void add(string& teacher,Student& s);
    void clear();
    void update(string& name, int& age, int& attendance, int& gpa, string& comment);
    void remove();

    void print();
    void create_group(string& teacher);
    bool is_full(string& teacher);

    void read_file();
    void save();

    void load(map<string,vector<Student> >& school_data);

};
