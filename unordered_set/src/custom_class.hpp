
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iostream>
#include <boost/functional/hash.hpp>

namespace project {

// when we wants to use our class into unordered_set(map), we needs to provide hash functionality
struct CustomClass
{
    int m_value;
    std::string m_string;

    // A comparison function for equality; this is required because the hash cannot rely on
    // the fact that the hash function will always provide a unique hash value for every
    // distinct key (i.e., it needs to be able to deal with collisions),
    // so it needs a way to compare two given keys for an exact match.
    // You can implement this either as a class that overrides operator(), or as a specialization of std::equal,
    // or – easiest of all – by overloading operator==() for your key type (as you did already).
    bool operator==(const CustomClass& other) const
    {
        return (m_value == other.m_value && m_string == other.m_string);
    }
};

// one way is to define own hash function and put it directly to unordered map declaration
struct CustomClassHash
{
    std::size_t operator()(const CustomClass& key) const
    {
        using boost::hash_value;
        using boost::hash_combine;

        // Start with a hash value of 0    .
        std::size_t seed = 0;

        // Modify 'seed' by XORing and bit-shifting in
        // one member of 'Key' after the other:
        hash_combine(seed, hash_value(key.m_value));
        hash_combine(seed, hash_value(key.m_string));

        // Return the result.
        return seed;
    }
};

// custom specialization of std::hash can be injected in namespace std
} // namespace project
namespace std {

template <>
struct hash<project::CustomClass>
{
    std::size_t operator()(project::CustomClass const& s) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(s.m_value);
        std::size_t h2 = std::hash<std::string>{}(s.m_string);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

} // namespace std

#endif