#include <gtest/gtest.h>
#include "../include/findnum.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(findnum("123dddf2fff56")=="123 2 56");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(findnum("ffhhhf")=="");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(findnum("d3fr22ff")=="3 22 ");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(findnum("1456")=="1456");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}