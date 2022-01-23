#include <iostream>
#include <vector>

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

    person(person&& other)
        : m_name(std::move(other.m_name))
    {
        std::cout << "move-constructed " << m_name << '\n';
    }

    person& operator=(person&& other)
    {
        m_name = std::move(other.m_name);
        std::cout << "move-assigned " << m_name << '\n';
        return *this;
    }

private:
    std::string m_name;
};

struct pair
{
    person a, b;
};

int main()
{
    std::vector<person> people;
    people.emplace_back("alice");

    person bob("bob");
    people.insert(people.begin(), std::move(bob));

    // std::vector<pair> pairs;
    // pairs.push_back({person("alice"), person("bob")});

    // pair cd = {person("charlie"), person("donna")};
    // pairs.insert(pairs.begin(), std::move(cd));

    return 0;
}
