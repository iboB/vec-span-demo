#include <thread>
#include <ranges>
#include <span>
#include <iostream>
#include <vector>

inline int sq(int i) { return i * i; }

int sum_squared_evens_classic(std::span<int> ints) {
    int sum = 0;
    for (auto i : ints) {
        if (i % 2 == 0) {
            sum += sq(i);
        }
    }
    return sum;
}

int sum_squared_evens_range(std::span<int> ints) {
    using namespace std::ranges::views;
    int sum = 0;
    // TODO: fold in c++23
    auto even = [](int i) { return i % 2 == 0; };
    for (auto i : ints | filter(even) | transform(sq)) {
        sum += i;
    }
    return sum;
}

int main() {
    std::vector<int> ints = { 1, 10, 20, 3, 30, 5, 7, 6 };
    std::cout << sum_squared_evens_classic(ints) << '\n';
    std::cout << sum_squared_evens_range(ints) << '\n';
    return 0;
}
