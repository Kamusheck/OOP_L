#include <gtest/gtest.h>
#include "hexagon.h"
#include "shape.h"
#include "point.h"
#include "romb.h"


// Тесты для Rhombus
TEST(RhombusTest, ValidRhombusAreaAndCentroid) {
    // Создаем корректный ромб
    Rhombus<double> Rhombus({{0, 0}, {2.0, 2.0}, {4.0, 0}, {2.0, -2.0}});

    // Проверяем площадь
    EXPECT_NEAR(Rhombus.area(), 8.0, 1e-9);

    // Проверяем центр масс
    EXPECT_EQ(Rhombus.centroid(), Point<double>(2, 0));
}

TEST(RhombusTest, InvalidRhombusNonSymmetric) {
    // Создаем некорректный ромб (несимметричная фигура)
    EXPECT_THROW(Rhombus<double>({{0, 0}, {2, 0}, {1, 1.5}, {-1, 1.732}}), std::logic_error);
}

TEST(RhombusTest, InvalidRhombusTooFewPoints) {
    // Создаем некорректный ромб с недостаточным количеством точек
    EXPECT_THROW(Rhombus<double>({{0, 0}, {2, 0}, {1, 1.732}}), std::invalid_argument);
}

// Тесты для Hexagon
TEST(HexagonTest, ValidHexagonAreaAndCentroid) {
    // Создаем корректный шестиугольник
    Hexagon<double> hexagon({{0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}});

    // Проверяем площадь
    EXPECT_NEAR(hexagon.area(), 6.0, 1e-9);

    // Проверяем центр масс
    EXPECT_EQ(hexagon.centroid(), Point<double>(1.0, 1.0));
}

TEST(HexagonTest, InvalidHexagonTooFewPoints) {
    // Создаем некорректный шестиугольник с недостаточным количеством точек
    EXPECT_THROW(Hexagon<double>({{0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}}), std::invalid_argument);
}
