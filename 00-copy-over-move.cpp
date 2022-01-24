#include "person.hpp"
#include "push_front.hpp"
#include <vector>

struct pair
{
    person a, b;
};

int main()
{
    std::vector<person> people;
    people.emplace_back("alice");

    person bob("bob");
    push_front(people, std::move(bob));

    // std::vector<pair> pairs;
    // pairs.push_back({person("alice"), person("bob")});

    // pair cd = {person("charlie"), person("donna")};
    // pairs.insert(pairs.begin(), std::move(cd));

    return 0;
}
