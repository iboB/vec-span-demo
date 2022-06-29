#include <itlib/span.hpp>
#include <itlib/static_vector.hpp>
#include <itlib/pod_vector.hpp>
#include <iostream>
#include <array>
#include <vector>

void print_ints(itlib::span<const int> ints)
{
    for (auto i : ints) std::cout << i << ", ";
    std::cout << '\n';
}

int main()
{
    {
        itlib::static_vector<int, 6> sv = { 1, 2, 3 };
        print_ints(sv);
    }
    {
        std::vector vec = { 6, 7, 8 };
        print_ints(vec);
    }
    {
        std::array ar = { 6, 3, 11 };
        print_ints(ar);
    }
    {
        itlib::pod_vector pv = { 9, 7, 5 };
        print_ints(pv);
    }
    return 0;
}