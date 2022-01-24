#pragma once
#include <utility>

template <typename Container, typename Val>
void push_front(Container& c, Val&& v)
{
    c.insert(c.begin(), std::forward<Val>(v));
}
