#include <iostream>
#include <string>
#include <itlib/pod_vector.hpp>

int main()
{
    itlib::pod_vector<int> ix = { 1, 2, 3 };

    itlib::pod_vector<unsigned> ux;
    ux.recast_take_from(std::move(ix));

    std::cout << ix.size() << '\n';

    for (auto u : ux) std::cout << u << ", ";
    std::cout << '\n';

    //itlib::pod_vector<std::string> s;

    return 0;
}