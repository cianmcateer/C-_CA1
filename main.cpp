#include <iostream>
#include <string>
#include <fstream>
#include <iterator>


#include "Student.h"
#include "Student_Store.h"
#include "util.h"

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
        std::cerr << "Error opening menu file" << endl;
    }

}

void menu() {

    int choice;
    Student_Store st;

    while(true) {
        read_help_file(); // Help menu
        while(!(cin >> choice)) { // Input validation only accepts integers
            cout << "Sorry please enter a number" << endl;
            cin.clear();
            cin.ignore(100,'\n'); // Stops message from printing more than once if user enters more than one character
        }

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
                // Default sort using the '<' operator
                std::vector<Student> students = st.get_students();
                std::sort(students.begin(),students.end());

                st.print(students);
                break;
            }
            case 3: {
                cout << "Display by grade" << endl;

                std::vector<Student> students = st.get_students();
                // Third argument allows us to custom sort our vector
                std::sort(students.begin(),students.end(),[](const Student& s1, const Student& s2) -> bool {
                    return s1.get_gpa() > s2.get_gpa();
                });

                st.print(students);
                break;
            }
            case 4:{
                std::cout << "Display by name" << endl;
                std::vector<Student> students = st.get_students();

                std::sort(students.begin(),students.end(),[](const Student& s1, const Student& s2) -> bool {
                    return s1.get_name() < s2.get_name();
                });

                st.print(students);
                break;
            }
            case 5: {
                std::cout << "Students from oldest to youngest" << endl;
                std::vector<Student> students = st.get_students();

                std::sort(students.begin(),students.end(),[](const Student& s1, const Student& s2) -> bool {
                    return s1.get_age() > s2.get_age();
                });

                st.print(students);
                break;
            }

            case 6: {
                cout << "Top students" << endl;
                st.top_ten();
                break;
            }

            case 7: {
                cout << "Display failing students" << endl;
                std::vector<Student> students = st.get_students();
                st.has_failed(students);
                break;
            }

            case 8: {
                cout << "Search by age" << endl;
                int age;

                do {
                    cout << "Enter age" << endl;
                    cin >> age;

                    if(cin.fail()) {
                        cout << "Please enter a number (No characters)" << endl;
                        cin.clear();
                        cin.ignore(256, '\n');
                    } else if(age > 18) {
                        cout << "Students can't be older than 18" << endl;
                    } else if(age < 12) {
                        if(!is_pos(age)) {
                            cout << "Input must be a positive value" << endl;
                        } else {
                            cout << "Student is too young to attend this school" << endl;
                        }
                    } else {
                        cout << "Students aged " << age << endl;
                        break;
                    }
                } while(!cin.fail() || age > 18 || age < 12);

                st.search_age(age);
                break;
            }

            case 9: {

                cout << "Search by name" << endl;
                cout << "Enter search" << endl;
                string search;
                cin.ignore();
                std::getline(cin, search);

                // No special character, digits or spaces
                const string regex = "^[a-zA-Z]*$)";

                while(!is_correct(search, regex)) {
                    cout << "Input mismatch please enter again" << endl;
                    cin.clear();
                    std::getline(cin, search);

                    if(is_correct(search,"^[a-zA-Z]*$)")) {
                        break;
                    }
                }
                cout << "Results for " << search << endl;
                st.search_text(search, 0);
                break;
            }

            case 10: {
                cout << "Search by comment" << endl;
                string search;
                cout << "Enter search" << endl;
                cin.ignore();
                std::getline(cin, search);
                st.search_text(search, 1);
                break;
            }

            case 11: {
                cout << "Search by grade" << endl;
                float grade;
                do {
                    cout << "Enter grade" << endl;
                    cin >> grade;

                    if(cin.fail()) {
                        cout << "Please enter a number (No characters)" << endl;
                        cin.clear();
                        cin.ignore(256, '\n'); // Clear and ignore last line to prevent statement to be consta
                    }
                    else if(grade > 100) {
                        cout << "Grades can only be marked to 100" << endl;
                    }
                    else if(!is_pos(grade)){
                        cout << "Enter a positive value" << endl;
                    } else {
                        cout << "Students with a grade greater or equal to " << grade << endl;
                        break; // Exit loop
                    }

                } while(!is_pos(grade) || grade > 100 || !cin.fail());

                st.search_gpa(grade);
                break;
            }

            case 12: {

                char repeat = 'Y';
                while(repeat == 'Y' || repeat == 'y') {
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

                    cout << "Would you like to add another student? (Y/y: yes : N/n no)" << endl;
                    cin >> repeat;
                    break;
                }
            }

            case 13: {
                cin.ignore();
                cout << "Update student" << endl;
                cout << "Enter teacher name" << endl;
                string teacher;
                std::getline(cin, teacher);

                cout << "Enter student index" << endl;
                st.print_index(teacher);

                int student_at;
                cin >> student_at;

                cin.ignore();

                cout << "Enter new student name (leave empty to stay same)" << endl;
                string name;
                std::getline(cin, name);

                cout << "Change student age (enter -1 to leave the same)" << endl;
                int age;
                cin >> age;

                cout << "Change student attendance (enter -1 to leave the same)" << endl;
                int attendance;
                cin >> attendance;

                cout << "Change student gpa (enter -1 to leave the same)" << endl;
                float gpa;
                cin >> gpa;

                cin.ignore();
                cout << "Change comment (leave empty to stay same)" << endl;
                std::string comment;
                std::getline(cin, comment);

                st.update(teacher, student_at,name,age,attendance,gpa,comment);

                break;

            }

            case 14: {
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

            case 15: {
                st.create_webpage();
                cout << "Your webpage has been created" << endl;
                break;
            }

            case 16: {
                st.save();
                cout << "Data has been saved!" << endl;
                break;
            }
            case 17: {

                st.clear();
                cout << "All data has been cleared" << endl;
                break;

            }

            case 18: {
                st.save();
                cout << "Your data has been saved" << endl;
                cout << "Goodbye!" << endl;
                exit(0);
            }

            default:
                cout << "Invalid input please try again." << endl;
                break;
        }
    }
}

bool is_password(string password) {
    const string user_password = "password";
    return user_password == password;
}
