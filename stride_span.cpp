#include <itlib/stride_span.hpp>
#include <vector>
#include <iostream>
#include <numeric>

void print_ints(itlib::stride_span<const int> ints) {
    for (auto i : ints) std::cout << i << ", ";
    std::cout << '\n';
}

struct point { int x, y; };

int main() {
    std::vector<int> ints(15);
    std::iota(ints.begin(), ints.end(), 1);

    print_ints(itlib::make_stride_span_from_array(ints.data(), ints.size(), 1, 3));

    std::vector<point> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    print_ints(itlib::make_stride_span_member_view(points.data(), points.size(), &point::x));
    print_ints(itlib::make_stride_span_member_view(points.data(), points.size(), &point::y));
}

