#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data = nullptr;
    size_t size;
    size_t capacity;

    void destroydata(){
        for(size_t i = 0; i < size; ++i){ // освобождает память под каждый объект внутри массива
            data[i].~T();
        }
        delete[] reinterpret_cast<int8_t*>(data);//освобождает память, выделенную именно под массив
    }

public:
    // Конструктор по умолчанию
    Vector(): data(nullptr), size(0), capacity(0) {};

    // Конструктор с параметром size
    Vector(size_t n, const T& value = T()): size(n), capacity(n) {
        try {
            data = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
            for (size_t i = 0; i < n; ++i) {
                new(data + i) T(value);
            }
        }
        catch(const std::bad_alloc& e) {
            throw std::runtime_error("Проблемка с выделением памяти");
        }
    }

    // Конструктор копирования
    Vector(const Vector& other): size(other.size), capacity(other.capacity) {
        try {
            data = reinterpret_cast<T*>(new int8_t[other.capacity * sizeof(T)]);
            for (size_t i = 0; i < size; ++i) {
                new(data + i) T(other.data[i]);
            }
        }
        catch(const std::bad_alloc& e) {
            throw std::runtime_error("Проблемка с выделением памяти");
        }
    }

    // Конструктор перемещения
    Vector(Vector&& other): data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Оператор копирования
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            destroydata();
            try {
                data = reinterpret_cast<T*>(new int8_t[other.capacity * sizeof(T)]);
                size = other.size;
                capacity = other.capacity;
                for (size_t i = 0; i < size; ++i) {
                    new(data + i) T(other.data[i]);
                }
            }
            catch(const std::bad_alloc& e) {
                throw std::runtime_error("Проблемка с выделением памяти(область оператор копирования)");
            }
        }
        return *this;
    }

    // Оператор перемещения
    Vector& operator=(Vector&& other) {
        if (this != &other) {
            destroydata();
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        destroydata();
    }

    void reserve(size_t sz) {
        if (sz <= capacity) {
            return;
        }
        T* newdata = reinterpret_cast<T*>(new int8_t[sz * sizeof(T)]);
        size_t i = 0;
        try {
            for (i = 0; i < size; ++i) {
                new(newdata + i) T(data[i]);
            }
        } catch (...) {
            for (size_t j = 0; j < i; --j) {  // грубо говоря - откат изменений
                (newdata + j)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(newdata);
            throw;
        }
        for (i = 0; i < size; ++i) { // явный вызов деструктора
            (data + i)->~T();
        }
        delete[] reinterpret_cast<int8_t*>(data);
        data = newdata;
        capacity = sz;
    }

    void resize(size_t sz, const T& value = T()) {
        if (sz > capacity) {
            reserve(sz);
        }
        if(sz >size){
            for (size_t i = size; i < sz; ++i) {
            new(data + i) T(value);
        }
        }
        else if (sz < size) {
          for (size_t i = sz; i < size; ++i) {
            data[i].~T();  // Вызываем деструктор для лишних элементов
            }
        }
        size = sz;
    }

    void pushback(const T& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : 2 * capacity); // увеличиваем вместимость в 2 раза
        }
        new(data + size) T(value); // добавляем новый элемент
        ++size;
    }

    void popback() {
        if (size == 0) {
            throw std::out_of_range("Упс, уже пустенько");
        }
        --size;
        (data + size)->~T();
    }

    T& operator[](size_t ind) {
        return data[ind];
    }

    const T& operator[](size_t ind) const {
        return data[ind];
    }

    T& at(size_t ind) {
        if (ind >= size) {
            throw std::out_of_range("Проблемка с индексом");
        }
        return data[ind];
    }

    size_t getsize() const {
        return size;
    }
};
