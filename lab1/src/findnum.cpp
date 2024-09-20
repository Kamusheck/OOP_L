#include "../include/findnum.h"

std::string findnum(const std::string& str) {
    std::string result;
    std::string number;

    for (char symbol : str) {
        if (isdigit(symbol)) { 
            number += symbol;
        } else {
            if (!number.empty()) {
                result += number + " ";
                number.clear();
            }
        }
    }
    if (!number.empty()) {
        result += number;
    }
    return result;
}
