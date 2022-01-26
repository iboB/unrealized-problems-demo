#include "push_front.hpp"
#include <functional>
#include <vector>
#include <string>
#include <iostream>

class person
{
public:
    explicit person(std::string name)
        : m_name(std::move(name))
    {}

    person(const person& other)
        : m_name(other.m_name)
    {
        std::cout << "copy-constructed " << m_name << '\n';
    }

    person& operator=(const person& other)
    {
        m_name = other.m_name;
        std::cout << "copy-assigned " << m_name << '\n';
        return *this;
    }

    person(person&& other) noexcept
        : m_name(std::move(other.m_name))
    {
        std::cout << "move-constructed " << m_name << '\n';
    }

    person& operator=(person&& other) noexcept
    {
        m_name = std::move(other.m_name);
        std::cout << "move-assigned " << m_name << '\n';
        return *this;
    }

    void speak() const
    {
        std::cout << "I am " << m_name << '\n';
    }

private:
    std::string m_name;
};

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

    // person c("charlie");
    // std::function<void()> func = [c]() { c.speak(); };
    // auto f2 = std::move(func);

    return 0;
}
