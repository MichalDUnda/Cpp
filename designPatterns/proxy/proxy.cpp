#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// The Proxy design pattern
// real example is the smart pointer
// hide real implementation, but also still provides real implementation
// wrap the real class

// simple proxy

template <typename T>
struct Property
{
    T value;
    Property(T value)
        : value(value)
    {
    }

    operator T()
    {
        return value;
    }

    T operator=(T newValue)
    {
        cout << "assignment" << endl;
        return value = newValue;
    }
};

struct Creature
{
    int agility, strength;
};

// still have a acces to previous functionality
struct CreatureWithProxy
{
    Property<int> strength{10};
    Property<int> agility{15};
};

int main()
{
    // usage without proxy
    Creature c;
    c.agility = 15;

    // proxy use
    CreatureWithProxy proxyCreature;
    return 0;
}