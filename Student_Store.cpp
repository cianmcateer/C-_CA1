#include "Student_Store.h"

Student_Store::Student_Store() {
    Student_Store::load(school_data);
//    school_data = read_file();
}

Student_Store::~Student_Store() {}

void Student_Store::load(std::map<std::string,std::vector<Student> >& school_data) {

    Student s1("CianMcAteer",21,15,44,"Good");
    Student s2("Jp mcdoug",15,77,44,"shite");
    Student s3("sam sung",44,11,33,"grand");
    std::vector<Student> vec1;
    vec1.push_back(s1);
    vec1.push_back(s2);
    vec1.push_back(s3);

    Student s4("Jamie samuel",22,13,22,"Excellent");
    Student s5("micky samuel",12,23,52,"good effort");
    Student s6("Jamie jones",11,12,11,"Wonderful");
    std::vector<Student> vec2;
    vec2.push_back(s4);
    vec2.push_back(s5);
    vec2.push_back(s6);

    school_data["Barbara Jones"] = vec1;
    school_data["John McDonald"] = vec2;

}

void Student_Store::add(std::string& teacher, const Student& s) {
    school_data[teacher].push_back(s);
}

void Student_Store::clear() {
    school_data.clear();
}

void Student_Store::update(std::string& teacher, std::string& name, int& age, int& attendance, int& gpa, std::string& comment) {

}



bool Student_Store::is_full(std::string& teacher) {
    if(school_data[teacher].size() > 30) {
        return true;
    }
    return false;
}

void Student_Store::print() {
    for(auto& sd : school_data) {
        std::cout << sd.first << ":" << std::endl;
        for(auto& s : sd.second) {
            std::cout << "\t" << s << std::endl;
        }
    }
}



std::map<std::string,std::vector<Student> > Student_Store::read_file() {
/*    const string file_path = "data.txt";
    std::ifstream read_file(file_path);

    map<string,vector<Student> > file_data;

    string teacher;
    string student_name;
    int age;
    float gpa;
    int attendance;
    string comment;

    vector<Student> students;
    Student s;

    if(!read_file.is_open()) {
        std::cerr << "Error opening file" << endl;
    } else {
        while(!read_file.eof()) {
            read_file >> teacher;
            while(read_file >> s.get_name() >> s.get_age() >> s.get_gpa() >> s.get_attendance() >> s.get_comment()) {
                students.push_back(s);
            }
            file_data[teacher] = students;
        }
        read_file.close();
    }

    return file_data;*/
}

void Student_Store::display_group(std::string& teacher) {
    if(school_data[teacher].empty()) {
        std::cout << "No students have been assigned to "
        << teacher << " yet" << std::endl;
    } else {
        for(auto& s : school_data[teacher]) {
            std::cout << s << std::endl;
        }
    }
}

void create_group(std::string& teacher) {
//    vector<Student> new_group;
//    school_data.insert(teacher,new_group);
}

void remove(const std::string& teacher) {
    school_data.erase(teacher);
}

void Student_Store::save() {
    const std::string file_path = "data.txt";
    std::ofstream save_file(file_path);
    if(save_file.is_open()) {
        for(auto& sd : school_data) {
            save_file << sd.first << "," << sd.second.size() << std::endl;
            for(auto& s : sd.second) {
                save_file << s.get_name() << "," << s.get_age() <<
                "," << s.get_gpa() << "," << s.get_attendance() <<
                s.get_comment() << std::endl;
            }
        }
    } else {
        std::cerr << "File not open" << std::endl;
    }

}
