#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>

#include "Student.h"


class Student_Store {

private:
    // Local storage
    std::map<std::string,std::vector<Student> > school_data;
    std::map<std::string,std::vector<Student> > read_file();
    void load(std::map<std::string,std::vector<Student> >& school_data);
    void replace_characters(Student& s, char old_char, char new_char);
    std::string save_path;


public:
    // Constructor / Destructor
    Student_Store(); // Done
    ~Student_Store(); // Done

    void add(std::string& teacher, const Student& s);  // Basic implementation finished
    void clear(); // Done
    void update(std::string& teacher ,std::string& name, int& age, int& attendance, int& gpa, std::string& comment); // Not implemented
    void remove_group(const std::string& teacher); // Not implemented

    void print_map(); // Need to sort

    std::vector<Student> get_students();
    void print(std::vector<Student>& students);

    void display_group(std::string& teacher); //
    void create_group(std::string& teacher);

    void save(); // Done

    bool is_full(std::string& teacher); // Done not implemented yet in main




};
