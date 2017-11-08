#include "util.h"

bool is_correct(std::string text , const std::string regex) {
    std::regex syntax(regex);
    if(std::regex_match(text, syntax)) {
        return true;
    }
    return false;
}

bool age_range(int x) {
    return is_pos(x) && x < 18;
}
