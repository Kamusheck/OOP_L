#include <iostream>
#include "elevenclass.hpp"

int main() {
    try {
        Eleven num1("A1"); 
        Eleven num2("A");

        num1.print(std::cout); 
        num2.print(std::cout); 

        Eleven sum = num1 + num2; 
        sum.print(std::cout);

        Eleven diff = num1 - num2; 
        diff.print(std::cout);

        std::cout << "Decimal of A1: " << num1.to_tencc() << std::endl; 

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}