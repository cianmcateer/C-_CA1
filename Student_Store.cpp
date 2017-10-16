#include "Student_Store.h"

Student_Store::Student_Store() {
    Student_Store::load(school_data);
    school_data = read_file();
}

Student_Store::~Student_Store() {}

void Student_Store::load(map<string,vector<Student> >& school_data) {

    Student s1("CianMcAteer",21,15,44,"Good");
    Student s2("Jp mcdoug",15,77,44,"shite");
    Student s3("sam sung",44,11,33,"grand");
    vector<Student> vec1;
    vec1.push_back(s1);
    vec1.push_back(s2);
    vec1.push_back(s3);

    Student s4("Jamie samuel",22,13,22,"Excellent");
    Student s5("micky samuel",12,23,52,"good effort");
    Student s6("Jamie jones",11,12,11,"Wonderful");
    vector<Student> vec2;
    vec2.push_back(s4);
    vec2.push_back(s5);
    vec2.push_back(s6);

    school_data["Barbara"] = vec1;
    school_data["John"] = vec2;

}

bool Student_Store::is_full(string& teacher) {
    if(school_data[teacher].size() > 30) {
        return true;
    }
    return false;
}

void Student_Store::clear() {
    school_data.clear();
}

void Student_Store::print() {
    for(auto& sd : school_data) {
        cout << sd.first << ":" << endl;
        for(auto& s : sd.second) {
            cout << "\t" << s << endl;
        }
    }
}

map<string,vector<Student> > Student_Store::read_file() {
    
}

void Student_Store::update(string& teacher, string& name, int& age, int& attendance, int& gpa, string& comment) {



}

void Student_Store::display_group(string& teacher) {
    if(school_data[teacher].empty()) {
        cout << "No students have been assigned to "
        << teacher << " yet" << endl;
    } else {
        for(auto& s : school_data[teacher]) {
            cout << s << endl;
        }
    }
}

void Student_Store::save() {
    const string file_path = "data.txt";
    std::ofstream save_file(file_path);
    if(save_file.is_open()) {
        for(auto& sd : school_data) {
            save_file << sd.first << "," << sd.second.size() << endl;
            for(auto& s : sd.second) {
                save_file << s.get_name() << "," << s.get_age() <<
                "," << s.get_gpa() << "," << s.get_attendance() <<
                s.get_comment() << endl;
            }
        }
    } else {
        std::cerr << "File not open" << endl;
    }

}
