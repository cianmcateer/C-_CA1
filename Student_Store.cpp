#include "Student_Store.h"

Student_Store::Student_Store() {
    school_data = Student_Store::read_file();
    save_path = "data.txt";
}

Student_Store::~Student_Store() {}

std::map<std::string,std::vector<Student> > Student_Store::back_up_data() {

    std::map<std::string,std::vector<Student> > map;

    Student s1("Cian McAteer",13,15,44,"Good");
    Student s2("Matthew Fitzsimons",14,77,44,"Excellent");
    Student s3("Greg Hughes",16,11,33,"Bad attitude");
    std::vector<Student> vec1;
    vec1.push_back(s1);
    vec1.push_back(s2);
    vec1.push_back(s3);

    Student s4("Jamie samuel",10,13,22,"Excellent");
    Student s5("micky samuel",11,23,52,"good effort");
    Student s6("Jamie jones",12,12,11,"Wonderful");
    std::vector<Student> vec2;
    vec2.push_back(s4);
    vec2.push_back(s5);
    vec2.push_back(s6);

    map["Barbara Jones"] = vec1;
    map["John McDonald"] = vec2;

    return map;

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

void Student_Store::print_index(std::string& teacher) {

    for(unsigned int i = 0;i < school_data[teacher].size();++i) {
        std::cout << "INDEX: " << i << " " << school_data[teacher].at(i) << std::endl;
    }
}

void Student_Store::update(std::string& teacher,int index,std::string name, int age, int attendance, float gpa, std::string comment) {


    if(name != "s") {
        school_data[teacher].at(index).set_name(name);
    }

    if(age != -1) {
        school_data[teacher].at(index).set_age(age);
    }

    if(attendance != -1) {
        school_data[teacher].at(index).set_attendance(attendance);
    }

    if(gpa != -1) {
        school_data[teacher].at(index).set_gpa(gpa);
    }

    if(comment != "s") {
        school_data[teacher].at(index).set_comment(comment);
    }

}

bool Student_Store::is_full(std::string& teacher) {
    if(school_data[teacher].size() > 30) {
        return true;
    }
    return false;
}

std::vector<Student> Student_Store::get_students() {
    std::vector<Student> students;
    for(const auto& key : school_data) {
        for(const auto& s : key.second) {
            students.push_back(s);
        }
    }
    return students;
}

void Student_Store::print(std::vector<Student>& students) {
    std::cout << "Total number of students: " << students.size() << std::endl;
    for(auto& s : students) {
        std::cout << s << std::endl;
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
        map = back_up_data();
        std::cerr << "Error: Could access file, Backup data has been implemented." << std::endl;
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

bool Student_Store::teacher_exists(std::string teacher) {
    std::string lower_teacher = lower_case(teacher);
    for(auto& key : school_data) {
        std::string lower_key = lower_case(key.first);
        if(lower_key == lower_teacher) {
            return true;
        }
    }

    return false;
}

std::string Student_Store::lower_case(std::string word) {
    for(char& c : word) {
        c = tolower(c);
    }
    return word;
}

void Student_Store::create_group(std::string& teacher) {

    if(teacher_exists(teacher)) {
        std::cout << teacher << " has already been added." << std::endl;
    } else {
        std::vector<Student> new_group;
        school_data[teacher] = new_group;
        std::cout << teacher.substr(0,teacher.find(' ')) << " class has been created" << std::endl;
    }

}

void Student_Store::remove_group(std::string& teacher) {

    // Create iterator of map
    std::map<std::string,std::vector<Student> >::iterator iter;
    // Find matching key and delete
    iter = school_data.find(teacher);

    if(iter != school_data.end()) {
        school_data.erase(iter);
    } else {
        std::cout << "Teacher not found" << std::endl;
    }
}

bool Student_Store::class_empty(std::string& teacher) {
    return school_data[teacher].size() == 0;
}

bool Student_Store::in_range(std::string& teacher, int& index) {
    return index <= (school_data[teacher].size()-1);
}

void Student_Store::remove_student(std::string& teacher, int& index) {

    for(int i = 0;i < school_data[teacher].size();++i) {
        if(index == i) {
            school_data[teacher].erase(school_data[teacher].begin() + i);
        }
    }

}

void Student_Store::save() {

    std::ofstream save_file(save_path);

    if(save_file.is_open()) {
        for(auto& str : school_data) {
            std::string teacher = str.first;
            // Replace spaces with spaces before sending to file
            std::replace(teacher.begin(), teacher.end(), ' ', '-');
            save_file << teacher << " ";
            for(auto& s : str.second) {
                replace_characters(s,' ','-');

                save_file << s.get_name() << " " << s.get_age() << " "
                << s.get_attendance() << " " << s.get_gpa()
                << " " << s.get_comment() << " ";
            }
            save_file << std::endl;
        }
        save_file.close();
    } else {
        std::cerr << "Save file could not open" << std::endl;
    }

}

void Student_Store::create_webpage() {
    std::ofstream html_page("e-school.html");
    // HTML header tags
    html_page << "<!DOCTYPE html><html><head>"; // Header tags
    html_page << "<link href=\"school_page.css\" rel=\"stylesheet\">"; // Style sheet link
    html_page << "</head><body>";
    html_page << "<h1>E-School.ie</h1>";
    html_page << "<table border='1'>";
    html_page << "<tr><td>Teacher</td><td>Student name</td><td>Age</td><td>Attendance</td><td>GPA</td><td>Comment</td></tr>";
    for(auto& key : school_data) {
        for(auto& s : key.second) {
            html_page << "<tr>";
            html_page << "<td>" << key.first << "</td>" << s.to_html();
            html_page << "</tr>";
        }
    }
    html_page << "</table>";
    // Close off page and end connection
    html_page << "</body></html>";
    html_page.close();
}

void Student_Store::top_ten() {

    // Use to sort priority queue
    struct by_gpa {
        bool operator()(const Student& s1, const Student& s2) {
            return s1.get_gpa() < s2.get_gpa();
        }
    };

    std::priority_queue<Student,std::vector<Student>, by_gpa> pq; // Initialise priority queue sorted by gpa
    for(auto& key : school_data) {
        for(const auto& s : key.second) {
            pq.push(s); // Fill students
        }
    }

    int top_students = 10;
    // Print Ten highest scoring students
    if(pq.size() < top_students) {
        top_students = pq.size();
    }
    for(int i = 0;i < top_students;++i) {
        // Print highest priority object
        std::cout << "Name: " << pq.top().get_name() << " GPA: " << pq.top().get_gpa() << std::endl;
        pq.pop(); // Take off highest priority so we can print the next highest priority student
    }

}

void Student_Store::has_failed(std::vector<Student>& students) {
    const unsigned int pass = 40;
    for(auto& s : students) {
        if(s.get_gpa() < pass) {
            std::cout << "Name: " << s.get_name() << " Result: " << s.get_gpa() << std::endl;
        }
    }
}

void Student_Store::get_count(int& i) {
    if(i == 0) {
        std::cout << "No results" << std::endl;
    } else if(i == 1) {
        std::cout << "1 result found" << std::endl;
    } else {
        std::cout << i << " results found" << std::endl;
    }
}

void Student_Store::search_age(int& age) {

    int count = 0;

    for(auto& key : school_data) {
        for(const auto& s : key.second) {
            if(s.get_age() == age) {
                std::cout << s << std::endl;
                ++count;
            }
        }
    }
    get_count(count);
}

void Student_Store::search_text(std::string& text, int choice) {
    int count = 0;

    if(choice == 0) {
        int count = 0;
        for(auto& key : school_data) {
            for(const auto& s : key.second) {
                if(s.get_name().find(text) != std::string::npos) {
                    std::cout << s << std::endl;
                    ++count;
                }
            }
        }
        get_count(count);

    } else {
        for(auto& key : school_data) {
            for(const auto& s : key.second) {
                if(s.get_comment().find(text) != std::string::npos) {
                    std::cout << s << std::endl;
                    ++count;
                }
            }
        }
        get_count(count);
    }

}

void Student_Store::search_gpa(float& higher_than) {

    int count = 0;
    for(auto& key : school_data) {
        for(const auto& s : key.second) {
            if(s.get_gpa() >= higher_than) {
                std::cout << s << std::endl;
                ++count;
            }
        }
    }
    get_count(count);
}

std::ostream& operator<<(std::ostream& output_stream, Student_Store& st) {
    output_stream << "Number of current teachers " << st.get_map().size() << "." << std::endl;

    for(auto& key : st.get_map()) {
        output_stream << key.first << std::endl;
        std::vector<Student> students = key.second;
        std::sort(students.begin(), students.end());

        for(const auto& s : students) {
            output_stream << s << std::endl;
        }

    }

    return output_stream;
}
