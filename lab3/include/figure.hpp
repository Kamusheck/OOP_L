#pragma once
#include <iostream>
#include <stdexcept>
#include "vector.hpp"
#include <utility> // для pair - координат

class Figure{//используем virual для полиморфизма, чтобы для каждой фишуры потом прописать свою логику
public:
    virtual ~Figure() = default; //устанавливаем на всякий случай деструктор
    virtual std::pair<double, double> Center() const=0;
    virtual double Space() const=0; //площадь
    virtual void Print(std::ostream& out) const = 0;
    virtual void Input(std::istream& in) =0;
    virtual Figure& operator==(const Figure& other)=0;
    virtual Figure& operator==(Figure&& other)=0;
    virtual bool operator ==(const Figure& other)const =0 ; //показывается явно что абстрактно и  виртуально, определить надо потом самому
};

std::ostream& operator<<(std::ostream& out, const Figure& obj){
    obj.Print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Figure& obj){ // & без копирования+ изменения
    obj.Input(in);
    return in;
}
