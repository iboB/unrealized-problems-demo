#include <iostream>
#include <memory>
#include <functional>

#include <itlib/ufunction.hpp>

int main()
{
    auto sptr = std::make_unique<std::string>("foo");

    auto lambda = [p = std::move(sptr)]() {
        std::cout << *p;
    };

    itlib::ufunction<void()> f = std::move(lambda);

    return 0;
}
