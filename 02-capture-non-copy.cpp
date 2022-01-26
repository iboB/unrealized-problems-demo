#include <iostream>
#include <memory>
#include <functional>

int main()
{
    auto sptr = std::make_unique<std::string>("foo");

    auto lambda = [p = std::move(sptr)]() {
        std::cout << *p;
    };

    //std::function<void()> f = std::move(lambda);

    return 0;
}
