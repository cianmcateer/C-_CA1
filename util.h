#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <fstream>

template <typename T> bool is_pos(T t) {
    return t >= 0;
}

bool is_correct(std::string text , const std::string regex);
void read_file(const std::string path);
bool is_password(std::string password);
