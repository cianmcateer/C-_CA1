#pragma once

#include <iostream>
#include <string>
#include <regex>


template <typename T> bool is_pos(T t) {
    return t >= 0;
}

bool is_correct(std::string text , const std::string regex);

bool age_range(int x);
