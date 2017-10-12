#include "Student_Store.h"

Student_Store::Student_Store() {
    load(school_data);
}

Student_Store::~Student_Store() {}

void Student_Store::load(map<string,vector<Student> >& school_data) {

    Student s1("CianMcAteer",21,15,44,"Good");
    Student s2("Jp mcdoug",15,77,44,"shite");
    Student s3("sam sung",44,11,33,"grand");
    vector<Student> vec;
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);

    school_data["Barbara Kelly"] = vec;

}

bool Student_Store::is_full(string& teacher) {
    return true;
}

void Student_Store::clear() {
    school_data.clear();
}

void Student_Store::print() {
    
}
