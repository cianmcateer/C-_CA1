#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cerr;
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

    cout << "Please enter you're name" << endl;
    string user_name;
    cin >> user_name;


    string user_password = "password";
    cout << "Please enter password" << endl;
    string password_attempt;
    cin >> password_attempt;

    int attempt = 4;
    while(!is_password(password_attempt)) {
        if(attempt < 1) {
            exit(0);
        }
        --attempt;
        cout << "Incorrect Password, try again" << endl;

        cout << "Enter password (attempts left = " << attempt << ")" << endl;
        cin >> password_attempt;
    }

    cout << "Welcome " << user_name << "..." << endl;
    menu();

}

void read_file() {
    const string path = "/Users/CianMcAteer/Desktop/year_3/semester_1/C++/C++_CA1/files/help.txt";
    std::ifstream help_menu(path);
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
    read_file();
}

bool is_password(string password) {
    const string user_password = "password";
    return user_password == password;
}
