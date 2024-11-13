#include <iostream>
#include <memory>
#include "figure.hpp"
#include "romb.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "shapecollection.hpp"

int main() {
    ShapeCollection collection;
    bool running = true;

    while (running) {
        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Add Shape\n";
        std::cout << "2. Show All Shapes\n";
        std::cout << "3. Total Area\n";
        std::cout << "4. Remove Shape by Index\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                try {
                    std::cin >> collection;
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 2: {
                collection.printShapesInfo();
                break;
            }
            case 3: {
                double totalArea = collection.totalArea();
                std::cout << "Total area of all shapes: " << totalArea << '\n';
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                try {
                    collection.removeShape(index);
                    std::cout << "Shape at index " << index << " removed.\n";
                } catch (const std::out_of_range& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 5:
                running = false;
                break;
            default:
                std::cerr << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
