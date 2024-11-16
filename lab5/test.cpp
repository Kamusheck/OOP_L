#include "mem_r.hpp"
#include "bilist.hpp"
#include <gtest/gtest.h>

struct ComplexType {
    int id;
    std::string name;
    double value;

    ComplexType(int i, std::string n, double v)
        : id(i), name(std::move(n)), value(v) {}
};

TEST(FixBlockMTest, AllocateAndDeallocate) {
    FixBlockM resource(256);
    void *block = resource.allocate(128);
    ASSERT_NE(block, nullptr); 

    resource.deallocate(block, 128);
}

TEST(FixBlockMTest, AllocationFailure) {
    FixBlockM resource(64);

    void *block1 = resource.allocate(32);
    ASSERT_NE(block1, nullptr);
    void *block2 = resource.allocate(32);
    ASSERT_NE(block2, nullptr);

    void *failingAllocation = nullptr;
    EXPECT_THROW(failingAllocation = resource.allocate(64), std::bad_alloc);
    EXPECT_EQ(failingAllocation, nullptr);
}


TEST(BilistTest, PushBack) {
    Bilist<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 3);
}

TEST(BilistTest, PushFront) {
    Bilist<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.at(0), 3);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 1);
}

TEST(BilistTest, PopBack) {
    Bilist<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 2);

    list.pop_back();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.at(0), 1);

    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(BilistTest, PopFront) {
    Bilist<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.at(0), 2);
    EXPECT_EQ(list.at(1), 3);

    list.pop_front();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.at(0), 3);

    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(BilistTest, At) {
    Bilist<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.at(0), 10);
    EXPECT_EQ(list.at(1), 20);
    EXPECT_EQ(list.at(2), 30);

    EXPECT_THROW(list.at(3), std::out_of_range);
}

TEST(BilistTest, Insert) {
    Bilist<int> list;

    list.push_back(1);
    list.push_back(3);
    list.insert(1, 2); // Вставляем 2 между 1 и 3

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 3);

    list.insert(0, 0);  // Вставляем 0 в начало( индеекс принят с 0)
    EXPECT_EQ(list.at(0), 0);

    list.insert(4, 4); 
    EXPECT_EQ(list.at(4), 4);
}

TEST(BilistTest, Erase) {
    Bilist<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.erase(1); // Удаляем элемент с индексом 1
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 3);

    list.erase(1); // Удаляем последний элемент
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.at(0), 1);

    list.erase(0); // Удаляем оставшийся элемент
    EXPECT_TRUE(list.empty());
}

TEST(BilistTest, ComplexTypeHandling) {
    Bilist<ComplexType> list;

    list.push_back(ComplexType{1, "First", 100.5});
    list.push_back(ComplexType{2, "Second", 200.75});

    EXPECT_EQ(list.size(), 2);

    auto &item1 = list.at(0);
    EXPECT_EQ(item1.id, 1);
    EXPECT_EQ(item1.name, "First");
    EXPECT_DOUBLE_EQ(item1.value, 100.5);

    auto &item2 = list.at(1);
    EXPECT_EQ(item2.id, 2);
    EXPECT_EQ(item2.name, "Second");
    EXPECT_DOUBLE_EQ(item2.value, 200.75);
}

TEST(BilistTest, GeneralUsage) {
    FixBlockM resource(1024);
    Bilist<int> list =
        Bilist<int>(std::pmr::polymorphic_allocator<int>(&resource));

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 3);

    list.pop_front();
    EXPECT_EQ(list.at(0), 2);

    list.insert(1, 5);
    EXPECT_EQ(list.at(1), 5);

    list.erase(1);
    EXPECT_EQ(list.at(1), 3);
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}