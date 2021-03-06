#include "push_front.hpp"
#include <string>
#include <iostream>
#include <itlib/static_vector.hpp>

class person
{
public:
    person()
        : m_name("<nobody>")
    {}

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

    person(person&& other) //noexcept
        : m_name(std::move(other.m_name))
    {
        std::cout << "move-constructed " << m_name << '\n';
    }

    person& operator=(person&& other) //noexcept
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

int main()
{
    itlib::static_vector<person, 5> vec;
    vec.emplace_back("alice");
    vec.emplace_back("bob");
    auto vec2 = vec;
}
