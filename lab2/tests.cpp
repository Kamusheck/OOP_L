#include <gtest/gtest.h>
#include "elevenclass.hpp"

TEST(ElevenTest, ConstructorFromString) {
    Eleven num("123");
    EXPECT_EQ(num.to_tencc(), 1 * 11 * 11 + 2 * 11 + 3); // 146
}

TEST(ElevenTest, ConstructorFromStringWithA) {
    Eleven num("1A");
    EXPECT_EQ(num.to_tencc(), 1 * 11 + 10); // 21
}

TEST(ElevenTest, Addition) {
    Eleven num1("5");
    Eleven num2("6");
    Eleven result = num1 + num2;
    EXPECT_EQ(result.to_tencc(), 11); // 5 + 6 = 11
}

TEST(ElevenTest, Subtraction) {
    Eleven num1("A"); // 10 in decimal
    Eleven num2("5"); // 5 in decimal
    Eleven result = num1 - num2;
    EXPECT_EQ(result.to_tencc(), 5); // 10 - 5 = 5
}

TEST(ElevenTest, SubtractionUnderflow) {
    Eleven num1("5");
    Eleven num2("A"); // Should throw an exception
    EXPECT_THROW(num1 - num2, std::underflow_error);
}

TEST(ElevenTest, Equality) {
    Eleven num1("7");
    Eleven num2("7");
    EXPECT_TRUE(num1 == num2);
}

TEST(ElevenTest, Inequality) {
    Eleven num1("8");
    Eleven num2("7");
    EXPECT_TRUE(num1 != num2);
}

TEST(ElevenTest, GreaterThan) {
    Eleven num1("9");
    Eleven num2("8");
    EXPECT_TRUE(num1 > num2);
}

TEST(ElevenTest, LessThan) {
    Eleven num1("8");
    Eleven num2("9");
    EXPECT_TRUE(num1 < num2);
}

TEST(ElevenTest, PrintFunction) {
    std::ostringstream os;
    Eleven num("A1"); // 11 in decimal
    num.print(os);
    EXPECT_EQ(os.str(), "A1\n");
}

TEST(ElevenTest, InvalidCharacterInConstructor) {
    EXPECT_THROW(Eleven num("12B"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



