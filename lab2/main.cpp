#include <iostream>
#include <string>
#include "elevenclass.hpp"

void print_menu() {
    std::cout << "\n=== Меню программы ===" << std::endl;
    std::cout << "1. Ввести первое число" << std::endl;
    std::cout << "2. Ввести второе число" << std::endl;
    std::cout << "3. Сложить числа" << std::endl;
    std::cout << "4. Вычесть второе число из первого" << std::endl;
    std::cout << "5. Сравнить числа" << std::endl;
    std::cout << "6. Вывести числа" << std::endl;
    std::cout << "7. Выйти" << std::endl;
    std::cout << "Введите ваш выбор: ";
}

int main() {
    Eleven num1, num2;
    std::string input;
    bool running = true;

    while (running) {
        print_menu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Введите первое число в 11-й системе счисления: ";
                std::cin >> input;
                try {
                    num1 = Eleven(input);
                    std::cout << "Первое число успешно введено!" << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Введите второе число в 11-й системе счисления: ";
                std::cin >> input;
                try {
                    num2 = Eleven(input);
                    std::cout << "Второе число успешно введено!" << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    Eleven sum = num1 + num2;
                    std::cout << "Сумма чисел: ";
                    sum.print();
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                try {
                    Eleven diff = num1 - num2;
                    std::cout << "Разность чисел: ";
                    diff.print();
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 5: {
                if (num1 == num2) {
                    std::cout << "Числа равны." << std::endl;
                } else if (num1 > num2) {
                    std::cout << "Первое число больше второго." << std::endl;
                } else {
                    std::cout << "Второе число больше первого." << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << "Первое число: ";
                num1.print();
                std::cout << "Второе число: ";
                num2.print();
                break;
            }
            case 7: {
                std::cout << "Завершение программы." << std::endl;
                running = false;
                break;
            }
            default: {
                std::cerr << "Неверный выбор. Попробуйте снова." << std::endl;
            }
        }
    }

    return 0;
}
