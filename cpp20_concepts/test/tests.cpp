#include <gtest/gtest.h>

#include <hashable.h>

struct meow
{
};

// Constrained C++20 function template:
template <Hashable T>
T hashable_func1(T t) { return t; }

// Alternative ways to apply the same constraint:
template <typename T>
requires Hashable<T>
    T hashable_func2(T t) { return t; }

template <typename T>
T hashable_func3(T t) requires Hashable<T> { return t; }

int main()
{
    auto const result = hashable_func1(1) + hashable_func2(2) + hashable_func3(3);
    return !(6ULL == result);
}