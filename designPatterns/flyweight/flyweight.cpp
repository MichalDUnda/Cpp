#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>
using namespace std;
using namespace boost;

// The Flyweight design pattern
// space optimization technique that let us use less memory by storing data
// Motivation .. avoid redundancy in data storing

//Handmade flyweight pattern

using key = uint32_t;

struct User
{
    User(string firstName, string lastName)
        : m_firstName(add(std::move(firstName)))
        , m_lastName(add(std::move(lastName)))
    {
    }

protected:
    key m_firstName, m_lastName;
    static bimap<key, string> names;
    static key seed;

    const string& getFirstName() const
    {
        return names.left.find(m_firstName)->second;
    }

    const string& getLastName() const
    {
        return names.left.find(m_lastName)->second;
    }

    static key add(const string& s)
    {
        auto it = names.right.find(s);
        if(it == names.right.end())
        {
            const auto id = ++seed;
            names.insert({seed, s});
            return id;
        }
        return it->second;
    }

    friend ostream& operator<<(ostream& os, const User& obj)
    {
        return os
               << "first_name: " << obj.m_firstName << " " << obj.getFirstName()
               << " last_name: " << obj.m_lastName << " " << obj.getLastName();
    }
};

key User::seed{0};
bimap<key, string> User::names{};

//use boost flyweight
/*
struct User2
{
    // users share names! e.g., John Smith
    flyweight<string> m_firstName, m_lastName;
    //string first_name, last_name;
    // ...

    User2(const string& first_name, const string& last_name)
        : m_firstName(first_name)
        , m_lastName(last_name)
    {
    }
};

void boost_flyweight()
{
    User2 john_doe{"John", "Doe"};
    User2 jane_doe{"Jane", "Doe"};

    cout << boolalpha << (&jane_doe.m_firstName.get() == &john_doe.m_lastName.get());
    //cout << (&jane_doe.last_name == &john_doe.last_name);
}
*/

int main()
{
    User user1{"Joe", "Smith"};
    User user2{"Jane", "Smith"};

    cout << "here " << endl;

    cout << user1 << endl
         << user2 << endl;

    //    User2 first{"Joe", "Smith"};
    //   User2 second{"Jane", "Smith"};

    //   cout << first.m_firstName << endl
    //   << second.m_firstName << endl;
    return 0;
}