#include "push_front.hpp"
#include <itlib/small_vector.hpp>
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
    itlib::small_vector<person, 3> people;
    people.emplace_back("alice");

    person bob("bob");
    push_front(people, std::move(bob));

    return 0;
}
