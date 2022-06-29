#include <itlib/poly_span.hpp>
#include <iostream>
#include <string>
#include <vector>

void print_ints(itlib::poly_span<int> ints) {
    for (auto i : ints) std::cout << i << ", ";
    std::cout << '\n';
}

int main() {
    std::vector<std::string> strings = {"hello", "my", "darling"};

    itlib::poly_span<int> lengths(strings.data(), strings.size(), [](std::string& s) -> int {
        return int(s.length());
    });

    print_ints(lengths);
}
