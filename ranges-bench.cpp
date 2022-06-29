#include <picobench/picobench.hpp>
#include <ranges>
#include <span>
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

void bench(picobench::state& s) {
    auto func = reinterpret_cast<int(*)(std::span<int>)>(s.user_data());
    std::vector<int> ints(size_t(s.iterations()));
    srand(134);
    for (auto& i : ints) i = rand();
    picobench::scope _(s);
    int val = func(ints);
    s.set_result(uintptr_t(val));
}

PICOBENCH(bench).label("classic").user_data(reinterpret_cast<uintptr_t>(sum_squared_evens_classic));
PICOBENCH(bench).label("range").user_data(reinterpret_cast<uintptr_t>(sum_squared_evens_range));
