#include "hexagon.hpp"
#include "pentagon.hpp"
#include "romb.hpp"
#include "shapecollection.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(HexagonTest, ValidHexagonAreaAndCenter) {
    Hexagon hex;
    std::istringstream input("0 0 2 0 3 1 2 2 0 2 -1 1");
    input >> hex;

    ASSERT_NEAR(static_cast<double>(hex), 6.0, 1e-6);  // Check area
    auto center = hex.Center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);               // Check center x
    EXPECT_NEAR(center.second, 1.0, 1e-6);              // Check center y
}

TEST(HexagonTest, InvalidHexagonCollinearThrows) {
    Hexagon hex;
    std::istringstream input("0 0 1 1 2 2 3 3 4 4 5 5");
    EXPECT_THROW(input >> hex, std::logic_error);       // Invalid due to collinear points
}

TEST(HexagonTest, HexagonEquality) {
    Hexagon hex1, hex2;
    std::istringstream input1("0 0 1 0 2 1 1 2 0 2 -1 1");
    std::istringstream input2("0 0 1 0 2 1 1 2 0 2 -1 1");

    input1 >> hex1;
    input2 >> hex2;
    EXPECT_TRUE(hex1 == hex2);                          // Same vertices, should be equal
}

TEST(HexagonTest, HexagonInequality) {
    Hexagon hex1, hex2;
    std::istringstream input1("0 0 1 0 2 1 1 2 0 2 -1 1");
    std::istringstream input2("0 0 1 0 3 1 1 2 0 2 -1 1");

    input1 >> hex1;
    input2 >> hex2;
    EXPECT_FALSE(hex1 == hex2);                         // Different vertices, should not be equal
}

TEST(PentagonTest, ValidPentagonAreaAndCenter) {
    Pentagon pent;
    std::istringstream input("0 0 2 0 3 1 2 2 0 2");
    input >> pent;

    ASSERT_NEAR(static_cast<double>(pent), 4.0, 1e-6);  // Check area
    auto center = pent.Center();
    EXPECT_NEAR(center.first, 1.4, 1e-6);               // Check center x
    EXPECT_NEAR(center.second, 1.0, 1e-6);              // Check center y
}

TEST(PentagonTest, InvalidPentagonCollinearThrows) {
    Pentagon pent;
    std::istringstream input("0 0 1 1 2 2 3 3 4 4");
    EXPECT_THROW(input >> pent, std::logic_error);      // Invalid due to collinear points
}

TEST(PentagonTest, PentagonEquality) {
    Pentagon pent1, pent2;
    std::istringstream input1("0 0 2 0 3 1 2 2 0 2");
    std::istringstream input2("0 0 2 0 3 1 2 2 0 2");

    input1 >> pent1;
    input2 >> pent2;
    EXPECT_TRUE(pent1 == pent2);                        // Same vertices, should be equal
}

TEST(PentagonTest, PentagonInequality) {
    Pentagon pent1, pent2;
    std::istringstream input1("0 0 2 0 3 1 2 2 0 2");
    std::istringstream input2("0 0 2 0 4 1 2 2 0 2");

    input1 >> pent1;
    input2 >> pent2;
    EXPECT_FALSE(pent1 == pent2);                       // Different vertices, should not be equal
}

TEST(RombTest, ValidRombAreaAndCenter) {
    Romb romb;
    std::istringstream input("0 0 2 2 4 0 2 -2");
    input >> romb;

    ASSERT_NEAR(static_cast<double>(romb), 8.0, 1e-6);  // Check area
    auto center = romb.Center();
    EXPECT_NEAR(center.first, 2.0, 1e-6);               // Check center x
    EXPECT_NEAR(center.second, 0.0, 1e-6);              // Check center y
}

TEST(RombTest, InvalidRombUnequalSidesThrows) {
    Romb romb;
    std::istringstream input("0 0 2 2 5 0 2 -2");
    EXPECT_THROW(input >> romb, std::logic_error);      // Invalid due to unequal sides
}

TEST(ShapeCollectionTest, AddShapeAndComputeTotalArea) {
    ShapeCollection collection;
    auto hex = std::make_shared<Hexagon>();
    auto pent = std::make_shared<Pentagon>();
    auto romb = std::make_shared<Romb>();

    std::istringstream inputHex("0 0 2 0 3 1 2 2 0 2 -1 1");
    std::istringstream inputPent("0 0 2 0 3 1 2 2 0 2");
    std::istringstream inputRomb("0 0 2 2 4 0 2 -2");

    inputHex >> *hex;
    inputPent >> *pent;
    inputRomb >> *romb;

    collection.addShape(hex);
    collection.addShape(pent);
    collection.addShape(romb);

    ASSERT_NEAR(collection.totalArea(), 18.0, 1e-6);    // Check total area
}

TEST(ShapeCollectionTest, RemoveShapeByIndex) {
    ShapeCollection collection;
    auto hex = std::make_shared<Hexagon>();
    auto pent = std::make_shared<Pentagon>();

    std::istringstream inputHex("0 0 2 0 3 1 2 2 0 2 -1 1");
    std::istringstream inputPent("0 0 2 0 3 1 2 2 0 2");

    inputHex >> *hex;
    inputPent >> *pent;

    collection.addShape(hex);
    collection.addShape(pent);

    ASSERT_EQ(collection.totalArea(), 10.0);
    
    collection.removeShape(0);                          // Remove hexagon

    ASSERT_NEAR(collection.totalArea(), 4.0, 1e-6);     // Check remaining area (pentagon)
}

TEST(ShapeCollectionTest, PrintShapesInCollection) {
    ShapeCollection collection;
    auto romb = std::make_shared<Romb>();
    std::istringstream inputRomb("0 0 2 2 4 0 2 -2");

    inputRomb >> *romb;
    collection.addShape(romb);

    std::ostringstream output;
    collection.printAllShapes(output);

    std::string expected_output = "Romb vertices: (0, 0) (2, 2) (4, 0) (2, -2), center: (2, 0), area: 8\n";
    EXPECT_EQ(output.str(), expected_output);
}
