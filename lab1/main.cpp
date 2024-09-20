#include <iostream>
#include "findnum.h"

int main() {
    std::string str;

    std::cout << "enter : ";
    std::cin  >> str;
    std::cout << "result: " << findnum(str) << std::endl;

    return 0;
}
