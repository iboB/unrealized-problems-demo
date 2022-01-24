#include "person.hpp"
#include "push_front.hpp"
#include <functional>
#include <vector>

struct foo
{
    std::function<void()> func;
    person p;
};

int main()
{
    std::vector<foo> foos;
    foos.push_back({{}, person("alice")});
    push_front(foos, foo{{}, person("bob")});

    person c("charlie");
    std::function<void()> func = [c]() { c.speak(); };
    auto f2 = std::move(func);

    return 0;
}
