#include <itlib/memory_view.hpp>
#include <itlib/static_vector.hpp>
#include <itlib/pod_vector.hpp>
#include <iostream>
#include <array>
#include <vector>

void print_ints(itlib::const_memory_view<int> ints)
{
    for (auto i : ints) std::cout << i << ", ";
    std::cout << '\n';
}

int main()
{
    {
        itlib::static_vector<int, 6> sv = {1, 2, 3};
        print_ints(itlib::make_memory_view(sv));
    }
    {
        std::vector<int> vec = {6, 7, 8};
        print_ints(itlib::make_memory_view(vec));
    }
    {
        std::array ar = {6, 3, 11};
        print_ints(itlib::make_memory_view(ar));
    }
    {
        itlib::pod_vector<int> pv = {9, 7, 5};
        print_ints(itlib::make_memory_view(pv));
    }
    return 0;
}
