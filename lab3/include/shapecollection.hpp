#pragma once
#include <iostream>
#include <memory>
#include "method.hpp"
#include "vector.hpp"

class ShapeCollection {
private:
    Vector<std::shared_ptr<Method>> shapes; // Используем пользовательский Vector для хранения фигур

public:
    ShapeCollection() = default;

    // Добавление новой фигуры в коллекцию
    void addShape(const std::shared_ptr<Method>& shape) {
        shapes.pushback(shape);
    }

    // Удаление фигуры по индексу
    void removeShape(size_t index) {
        if (index >= shapes.getsize()) {
            throw std::out_of_range("Index out of range");
        }
        shapes.erase(index); // Метод erase должен быть реализован в вашем векторе
    }

    // Общая площадь всех фигур
    double totalArea() {
        double total_area = 0.0;
        for (size_t i = 0; i < shapes.getsize(); ++i) {
            if (shapes[i] != nullptr) { // Проверка на нулевой указатель
                total_area += static_cast<double>(shapes[i]->Space()); 
            }
        }
        return total_area;
}
    void printShapesInfo() const {
    for (size_t i = 0; i < shapes.getsize(); ++i) {
        std::cout << "Shape " << i + 1 << ":n";
        std::cout << "Center: (" << shapes[i]->Center().first << ", " << shapes[i]->Center().second << ")n";
        std::cout << "Area: " << shapes[i]->Space() << "n"; // Предположим, что у вас есть метод Area()
        std::cout << *shapes[i] << "n"; // Используем перегруженный оператор <<
    }
}


    // Вывод информации о фигурах в коллекции
    
    // Оператор вывода для всей коллекции
    friend std::ostream& operator<<(std::ostream& out, const ShapeCollection& collection) {
        for (size_t i = 0; i < collection.shapes.getsize(); ++i) {
            out << "Shape " << i + 1 << ":\n";
            out << *collection.shapes[i] << "\n"; // Используем перегруженный оператор <<
        }
        return out;
    }

    // Оператор ввода для добавления фигуры в коллекцию
    friend std::istream& operator>>(std::istream& in, ShapeCollection& collection) {
        std::shared_ptr<Method> newShape;
        in >> *newShape; // Используем перегруженный оператор >>
        collection.addShape(newShape);
        return in;
    }
};
