#include <iostream>
#include <string>
#include <fstream>

#include "Student.h"
#include "Student_Store.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


void read_file();
void init();
void menu();
bool login();
bool is_password(string password);

int main(void) {

    init();
    return 0;
}

void init() {
    cout << "Welcome to e-school.com" << endl;

    /*cout << "Please enter you're name" << endl;
    string user_name;
    cin >> user_name;


    string user_password = "password";
    cout << "Please enter password" << endl;
    string password_attempt;
    cin >> password_attempt;

    int attempt = 4;
    while(!is_password(password_attempt)) {
        if(attempt < 1) {
            cout << "Access Denied, system has shut down!" << endl;
            exit(0);
        }
        --attempt;
        cout << "Incorrect Password, try again" << endl;

        cout << "Enter password (attempts left = " << attempt << ")" << endl;
        cin >> password_attempt;
    }

    cout << "Welcome " << user_name << "..." << endl;*/
    menu();

}

void read_help_file() {
    // Fix file path problem
    const string help_path = "files/help.txt";
    std::ifstream help_menu(help_path);
    string line;
    if(help_menu.is_open()) {
        // Will read line until new line is detected
        while(std::getline(help_menu,line)) {
            cout << line << endl;
        }
    } else {
        std::cerr << "Error opening file" << endl;
    }

}

void menu() {

    int choice;
    Student_Store st;

    while(true) {
        read_help_file(); // Help menu
        cin >> choice;

        switch(choice) {
            case 0: {
                cout << "Goodbye!" << endl;
                exit(0);
                break;
            }
            case 1: {
                st.print_map();
                break;
            }
            case 2: {
                cout << "Display students" << endl;
                // Standard sort using the '<' operator
                std::vector<Student> students = st.get_students();
                std::sort(students.begin(),students.end());

                st.print(students);
                break;
            }
            case 3: {
                cout << "Display by grade" << endl;

                std::vector<Student> students = st.get_students();
                std::sort(students.begin(),students.end(),[](const Student& s1, const Student& s2) -> bool {
                    return s1.get_gpa() > s2.get_gpa();
                });

                st.print(students);
                break;
            }
            case 4:{
                std::cout << "Print by name" << endl;
                std::vector<Student> students = st.get_students();

                std::sort(students.begin(),students.end(),[](const Student s1, const Student s2) -> bool {
                    return s1.get_name() < s2.get_name();
                });

                st.print(students);
                break;
            }
            case 5: {
                std::cout << "Students from oldest to youngest" << endl;
                std::vector<Student> students = st.get_students();

                std::sort(students.begin(),students.end(),[](const Student s1, const Student s2) -> bool {
                    return s1.get_age() > s2.get_age();
                });

                st.print(students);
                break;
            }
            case 6: {

                // Clear 'cin' of data
                cin.ignore();
                string add_teacher;
                cout << "Add students teacher" << endl;
                std::getline(cin,add_teacher); // Allow to read white spaces

                cout << "Student name" << endl;
                string add_student_name;
                std::getline(cin,add_student_name);

                cout << "Age" << endl;
                int add_age;
                cin >> add_age;

                cout << "Attendance" << endl;
                int add_attendance;
                cin >> add_attendance;

                cout << "GPA" << endl;
                float add_gpa;
                cin >> add_gpa;

                cout << "Comment" << endl;
                string add_comment;
                cin.ignore();
                std::getline(cin,add_comment);

                const Student new_student(add_student_name,add_age,add_attendance,add_gpa,add_comment);

                st.add(add_teacher,new_student);

                // print students first name only
                cout << add_student_name.substr(0,add_student_name.find(' ')) << " has been added!" << endl;

                break;
            }

            case 7: {
                cin.ignore();
                cout << "Create new Group" << endl;
                cout << endl;

                cout << "Please enter teacher name" << endl;
                string new_teacher;
                std::getline(cin,new_teacher);
                st.create_group(new_teacher);
                cout << new_teacher.substr(0,new_teacher.find(' ')) << " class has been created" << endl;

                break;
            }

            case 8: {
                break;
            }

            case 9: {
                break;
            }

            case 10: {
                st.create_webpage();
                cout << "Your webpage has been created" << endl;
                break;
            }

            case 11:
                st.save();
                cout << "Data has been saved!" << endl;
                break;

            default:
                cout << "Invalid input please try again." << endl;
        }
    }
}

bool is_password(string password) {
    const string user_password = "password";
    return user_password == password;
}
