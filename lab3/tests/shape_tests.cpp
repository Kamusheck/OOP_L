#include <gtest/gtest.h>
#include "hexagon.h"
#include "shape.h"
#include "point.h"
#include "romb.h"

TEST(HexagonTest, Constructor_ValidPoints) {
    Hexagon hex({Point(0, 0), Point(1, 0), Point(1, 1),
                 Point(0, 1), Point(-1, 0.5), Point(-1, -0.5)});
    EXPECT_NO_THROW(hex); 
}

TEST(HexagonTest, Constructor_InvalidPointCount) {
    EXPECT_THROW(Hexagon({Point(0, 0), Point(1, 0)}), std::invalid_argument);
}

TEST(HexagonTest, Area_Calculation) {
    Hexagon hex({Point(0, 0), Point(4, 0), Point(6, 3),
                 Point(4, 6), Point(0, 6), Point(-2, 3)});
    double expected_area = 36.0;
    EXPECT_NEAR(static_cast<double>(hex), expected_area, 1e-6);
}

TEST(HexagonTest, geom_centr_Calculation) {
    Hexagon hex({Point(0, 0), Point(4, 0), Point(6, 3),
                 Point(4, 6), Point(0, 6), Point(-2, 3)});
    Point expected_geom_centr(2.0, 3.0);
    EXPECT_EQ(hex.geom_centr(), expected_geom_centr);
}

TEST(HexagonTest, OperatorEquality_SameHexagon) {
    Hexagon hex1({Point(0, 0), Point(4, 0), Point(6, 3),
                  Point(4, 6), Point(0, 6), Point(-2, 3)});
    Hexagon hex2({Point(0, 0), Point(4, 0), Point(6, 3),
                  Point(4, 6), Point(0, 6), Point(-2, 3)});
    EXPECT_EQ(hex1, hex2); 
}

TEST(HexagonTest, OperatorEquality_DifferentHexagons) {
    Hexagon hex1({Point(0, 0), Point(4, 0), Point(6, 3),
                  Point(4, 6), Point(0, 6), Point(-2, 3)});
    Hexagon hex2({Point(0, 0), Point(5, 0), Point(6, 3),
                  Point(4, 6), Point(0, 6), Point(-2, 3)});
    EXPECT_NE(hex1, hex2); 
}

TEST(RombTest, Constructor_ValidPoints) {
    Romb romb({Point(0, 0), Point(2, 2), Point(4, 0), Point(2, -2)});
    EXPECT_NO_THROW(romb);
}

TEST(RombTest, Constructor_InvalidPointCount) {
    EXPECT_THROW(Romb({Point(0, 0), Point(1, 1), Point(2, 0)}), std::invalid_argument);
}

TEST(RombTest, Constructor_UnequalSides) {
    EXPECT_THROW(Romb({Point(0, 0), Point(2, 2), Point(4, 1), Point(2, -2)}), std::logic_error);
}

TEST(RombTest, Area_Calculation) {
    Romb romb({Point(0, 0), Point(2, 2), Point(4, 0), Point(2, -2)});
    double expected_area = 8.0; 
    EXPECT_NEAR(static_cast<double>(romb), expected_area, 1e-6);
}

TEST(RombTest, geom_centr_Calculation) {
    Romb romb({Point(0, 0), Point(2, 2), Point(4, 0), Point(2, -2)});
    Point expected_geom_centr(2.0, 0.0); 
    EXPECT_EQ(romb.geom_centr(), expected_geom_centr);
}

TEST(RombTest, OperatorEquality_SameRomb) {
    Romb romb1({Point(0, 0), Point(2, 2), Point(4, 0), Point(2, -2)});
    Romb romb2({Point(0, 0), Point(2, 2), Point(4, 0), Point(2, -2)});
    EXPECT_EQ(romb1, romb2); 
}

TEST(RombTest, OperatorEquality_DifferentRombs) {
    Romb romb1({Point(0, 0), Point(2, 2), Point(4, 0), Point(2, -2)});
    Romb romb2({Point(1, 1), Point(3, 3), Point(5, 1), Point(3, -1)});
    EXPECT_NE(romb1, romb2); 
}
