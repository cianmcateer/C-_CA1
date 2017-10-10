#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void init();
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


}

bool is_password(string password) {
    const string user_password = "password";
    return user_password == password;
}
