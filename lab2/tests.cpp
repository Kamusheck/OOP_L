#include <gtest/gtest.h>
#include "elevenclass.hpp"

TEST(ElevenTest, CopyConstructor) {
    Eleven original("7");
    Eleven copy(original); 
    EXPECT_EQ(copy.to_tencc(), original.to_tencc());
}

TEST(ElevenTest, MoveConstructor) {
    Eleven num1("A");
    Eleven num2(std::move(num1));
    EXPECT_EQ(num2.to_tencc(), 10);
}


TEST(ElevenTest, MoveAssignmentOperator) {
    Eleven num1("A");
    Eleven num2("1");
    num2 = std::move(num1);
    EXPECT_EQ(num2.to_tencc(), 10);
    EXPECT_EQ(num1.to_tencc(), 0);
}


TEST(ElevenTest, CopyAssignmentOperator) {
    Eleven num1("5");
    Eleven num2;
    num2 = num1;
    EXPECT_EQ(num2.to_tencc(), 5);
}

TEST(ElevenTest, ConstructorFromString) {
    Eleven num("123");
    EXPECT_EQ(num.to_tencc(), 1 * 11 * 11 + 2 * 11 + 3); 
}

TEST(ElevenTest, ConstructorFromStringWithA) {
    Eleven num("1A");
    EXPECT_EQ(num.to_tencc(), 1 * 11 + 10); 
}

TEST(ElevenTest, Addition) {
    Eleven num1("5");
    Eleven num2("6");
    Eleven result = num1 + num2;
    EXPECT_EQ(result.to_tencc(), 11); 
}

TEST(ElevenTest, Subtraction) {
    Eleven num1("A"); 
    Eleven num2("5"); 
    Eleven result = num1 - num2;
    EXPECT_EQ(result.to_tencc(), 5); 
}

TEST(ElevenTest, SubtractionUnderflow) {
    Eleven num1("5");
    Eleven num2("A"); 
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
    Eleven num("A1"); 
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



