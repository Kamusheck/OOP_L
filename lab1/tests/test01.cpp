#include <gtest/gtest.h>
#include "findnum.h"

TEST(test_01, basic_test_set)
{
    std::string str = "123dddf2fff56";
    std::string result = findnum(str);
    ASSERT_TRUE(result == "123 2 56");
}

TEST(test_02, basic_test_set)
{
    std::string str = "ffhhhf";
    std::string result = findnum(str);
    ASSERT_TRUE(result =="");
}

TEST(test_03, basic_test_set)
{
    std::string str = "d3fr22ff";
    std::string result = findnum(str);
    ASSERT_TRUE(result =="3 22 ");
}

TEST(test_04, basic_test_set)
{
    std::string str = "1456";
    std::string result = findnum(str);
    ASSERT_TRUE(result =="1456");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}