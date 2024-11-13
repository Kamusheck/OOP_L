#pragma once

#include <iostream>
#include <stdexcept>
#include "vector.hpp"
#include <utility> // для pair - координат
#include <set>
#include <cmath>

class Figure{   //используем virual для полиморфизма, чтобы для каждой фишуры потом прописать свою логику

public:
    Vector<std::pair<double, double>> ups; // ups-вершины
    virtual ~Figure() = default; //устанавливаем на всякий случай деструктор
    virtual std::pair<double, double> Center() const=0;
    virtual void Print(std::ostream& out) const = 0;
    virtual void Input(std::istream& in) =0;//показывается явно что абстрактно и  виртуально, определить надо потом самому
    
    template <typename T>
    T& operator=(const T& other) {
        if (this != &other) {
            ups = other.ups;
        }
        return static_cast<T&>(*this);
    }
 

    template <typename T>
    T& operator=(T&& other) {
        if (this != &other) {
            ups.resize(0);
            ups = std::move(other.ups);
            other.ups.resize(0);
    }
        return static_cast<T&>(*this);
    }

    
    bool operator==(const T& other) const {
        return ups == other.ups;
    }


};

std::ostream& operator<<(std::ostream& out, const Figure& obj){
    obj.Print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Figure& obj){ // & без копирования+ изменения
    obj.Input(in);
    return in;
}

