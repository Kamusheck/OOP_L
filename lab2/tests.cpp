#include "elevenclass.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

// Тест для конструктора по умолчанию
TEST(ElevenTest, DefaultConstructor) {
    Eleven num;
    // Ожидаем, что число равно 0, т.е. пустой Eleven эквивалентен "0"
    std::ostringstream oss;
    num.print();
    EXPECT_EQ(oss.str(), "0");
}

// Тест для конструктора из строки
TEST(ElevenTest, ConstructorFromString) {
    Eleven num("A1B");  // 11-ричное число A1B (где A = 10, B = 11)
    std::ostringstream oss;
    num.print();
    EXPECT_EQ(oss.str(), "A1B");
}

// Тест на исключение для некорректной строки
TEST(ElevenTest, InvalidStringConstructor) {
    EXPECT_THROW(Eleven num("A1G"), std::invalid_argument);  // G не является 11-ричной цифрой
}

// Тест для сложения
TEST(ElevenTest, Addition) {
    Eleven num1("A1B");
    Eleven num2("2");
    Eleven result = num1 + num2;
    std::ostringstream oss;
    result.print();
    EXPECT_EQ(oss.str(), "A1D");  // Проверяем, что результат сложения "A1B" + "2" будет "A1D"
}

// Тест для вычитания
TEST(ElevenTest, Subtraction) {
    Eleven num1("A1B");
    Eleven num2("2");
    Eleven result = num1 - num2;
    std::ostringstream oss;
    result.print();
    EXPECT_EQ(oss.str(), "A19");  // Проверяем, что результат вычитания "A1B" - "2" будет "A19"
}

// Тест на исключение для вычитания, которое приводит к отрицательному результату
TEST(ElevenTest, SubtractionNegativeResult) {
    Eleven num1("2");
    Eleven num2("A1B");
    EXPECT_THROW(num1 - num2, std::underflow_error);  // Результат отрицательный, ожидаем исключение
}

// Тест на равенство
TEST(ElevenTest, Equality) {
    Eleven num1("A1B");
    Eleven num2("A1B");
    EXPECT_TRUE(num1 == num2);  // Проверяем, что два одинаковых числа равны
}

// Тест на неравенство (меньше)
TEST(ElevenTest, LessThan) {
    Eleven num1("A1B");
    Eleven num2("B1A");
    EXPECT_TRUE(num1 < num2);  // Проверяем, что "A1B" меньше "B1A"
}

// Тест на неравенство (больше)
TEST(ElevenTest, GreaterThan) {
    Eleven num1("B1A");
    Eleven num2("A1B");
    EXPECT_TRUE(num1 > num2);  // Проверяем, что "B1A" больше "A1B"
}

// Тест для конвертации из десятичного числа
TEST(ElevenTest, FromDecimal) {
    Eleven num;
    num.from_tencc(1210);  // 1210 в 11-ричной системе это "A1B"
    std::ostringstream oss;
    num.print();
    EXPECT_EQ(oss.str(), "A1B");
}

// Тест для конвертации в десятичное число
TEST(ElevenTest, ToDecimal) {
    Eleven num("A1B");
    unsigned long long dec = num.to_tencc();
    EXPECT_EQ(dec, 1210);  // Проверяем, что число "A1B" в 11-ричной системе — это 1210 в 10-ричной
}

// Тест для проверки pushback в Vector
TEST(VectorTest, PushBack) {
    Vector<int> vec;
    vec.pushback(1);
    vec.pushback(2);
    vec.pushback(3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Тест для проверки выхода за пределы массива в Vector (оператор [])
TEST(VectorTest, AccessOutOfBounds) {
    Vector<int> vec;
    vec.pushback(1);
    vec.pushback(2);
    vec.pushback(3);
    EXPECT_THROW(vec[3], std::out_of_range);  // Вектор имеет только 3 элемента, доступ к 3-му индексу вызывает исключение
}

// Тест для проверки resize в Vector
TEST(VectorTest, Resize) {
    Vector<int> vec;
    vec.resize(5, 10);  // Изменяем размер на 5 элементов, заполняем их значением 10
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 10);
    EXPECT_EQ(vec[4], 10);
    EXPECT_EQ(vec.getsize(), 5);
}

// Тест для проверки reserve в Vector
TEST(VectorTest, Reserve) {
    Vector<int> vec;
    vec.reserve(10);  // Зарезервировать память для 10 элементов
    EXPECT_EQ(vec.getsize(), 0);  // Проверяем, что размер вектора не изменился
}

// Тест для popback в Vector
TEST(VectorTest, PopBack) {
    Vector<int> vec;
    vec.pushback(1);
    vec.pushback(2);
    vec.popback();
    EXPECT_EQ(vec.getsize(), 1);  // Проверяем, что после удаления одного элемента, размер стал 1
    EXPECT_EQ(vec[0], 1);
}

// Тест на исключение при popback из пустого вектора
TEST(VectorTest, PopBackEmpty) {
    Vector<int> vec;
    EXPECT_THROW(vec.popback(), std::out_of_range);  // Ожидаем исключение при попытке удалить элемент из пустого вектора
}

// Тест на использование at() с выходом за границы массива
TEST(VectorTest, AtOutOfBounds) {
    Vector<int> vec;
    vec.pushback(1);
    EXPECT_THROW(vec.at(1), std::out_of_range);  // Вектор имеет только 1 элемент, доступ ко 2-му вызывает исключение
}

