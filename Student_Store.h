#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "Student.h"


class Student_Store{

private:
    // Local storage
    std::map<std::string,std::vector<Student> > school_data;
    std::map<std::string,std::vector<Student> > read_file();
    void load(std::map<std::string,std::vector<Student> >& school_data);

public:
    // Constructor / Destructor
    Student_Store(); // Done
    ~Student_Store(); // Done

    void add(std::string& teacher, const Student& s);  // Basic implementation finished
    void clear(); // Done
    void update(std::string& teacher ,std::string& name, int& age, int& attendance, int& gpa, std::string& comment);
    void remove(const std::string& teacher);

    void print();
    void display_group(std::string& teacher);
    void create_group(std::string& teacher);

    void save();

    bool is_full(std::string& teacher);


};
