#include "mem_r.hpp"
#include "bilist.hpp"

struct ComplexType {
    int id;
    std::string name;
    double value;

    ComplexType(int i, std::string n, double v)
        : id(i), name(std::move(n)), value(v) {}
};

int main() {
    FixBlockM resource(1024);

    Bilist<int> int_list =
        Bilist<int>(std::pmr::polymorphic_allocator<int>(&resource));

    int_list.push_back(10);
    int_list.push_back(20);

    for (int val : int_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    Bilist<ComplexType> complex_list = Bilist<ComplexType>(
        std::pmr::polymorphic_allocator<ComplexType>(&resource));

    complex_list.push_back(ComplexType{1, "First", 100.5});
    complex_list.push_back(ComplexType{2, "Second", 200.75});

    for (const auto &val : complex_list) {
        std::cout << "ID: " << val.id << ", Name: " << val.name
                  << ", Value: " << val.value << std::endl;
    }

    return 0;
}