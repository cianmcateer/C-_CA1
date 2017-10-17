#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "Student.h"
#include "Student_Store.h"

using std::map;
using std::vector;
using std::string;

class Student_Store{

private:
    // Local storage
    map<string,vector<Student> > school_data;
    map<string,vector<Student> > read_file();
    void load(map<string,vector<Student> >& school_data);

public:
    // Constructor / Destructor
    Student_Store();
    ~Student_Store();

    void add(string& teacher, const Student& s);
    void clear();
    void update(string& teacher ,string& name, int& age, int& attendance, int& gpa, string& comment);
    void remove();

    void print();
    void display_group(string& teacher);
    void create_group(string& teacher);

    void save();

    bool is_full(string& teacher);


};
