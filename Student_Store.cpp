#include "Student_Store.h"

Student_Store::Student_Store() {
//    Student_Store::load(school_data);
    school_data = Student_Store::read_file();
    save_path = "data.txt";
}

Student_Store::~Student_Store() {}

void Student_Store::load(std::map<std::string,std::vector<Student> >& school_data) {

    Student s1("Cian McAteer",21,15,44,"Good");
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

void Student_Store::replace_characters(Student& s, char old_char, char new_char) {
    std::string new_name = s.get_name();
    std::string new_comment = s.get_comment();

    replace(new_name.begin(),new_name.end(),old_char,new_char);
    replace(new_comment.begin(),new_comment.end(),old_char,new_char);

    s.set_name(new_name);
    s.set_comment(new_comment);
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

    std::string read_path = "data.txt";

    std::ifstream student_file(read_path);
    std::vector<Student> students;

    std::map<std::string,std::vector<Student> > map;
    if(student_file.is_open()) {

        std::vector<std::string> student_lines;
        std::string student_line;
        while(getline(student_file,student_line)) {
            student_lines.push_back(student_line);
        }
        for(unsigned int i = 0;i < student_lines.size();++i) {
            std::stringstream student_stream(student_lines[i]);

            std::string teacher;
            Student s;

            while(student_stream >> teacher) {
                replace(teacher.begin(), teacher.end(), '-', ' ');
                while(student_stream >> s) {
                    replace_characters(s,'-',' ');
                    students.push_back(s);
                }
                map[teacher] = students;
                students.clear();
            }
        }

        student_file.close();
    } else {
        std::cerr << "error" << std::endl;
    }
    return map;
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

void Student_Store::create_group(std::string& teacher) {
    std::vector<Student> new_group;
    school_data[teacher] = new_group;
}

void Student_Store::remove_group(const std::string& teacher) {
    std::map<std::string,std::vector<Student> >::iterator iter;
    iter = school_data.find(teacher);
    school_data.erase(iter);
}

void Student_Store::save() {

    std::ofstream save_file(save_path);

    if(save_file.is_open()) {
        for(auto& str : school_data) {
            std::string teacher = str.first;
            std::replace(teacher.begin(), teacher.end(), ' ', '-');
            save_file << teacher << " ";
            for(auto& s : str.second) {
                replace_characters(s,' ','-');
                save_file << s.get_name() << " " << s.get_age() << " " << s.get_attendance()
                << " " << s.get_gpa() << " " << s.get_comment() << " ";
            }
            save_file << std::endl;
        }
        save_file.close();
    } else {
        std::cerr << "Save file could not open" << std::endl;
    }

}
