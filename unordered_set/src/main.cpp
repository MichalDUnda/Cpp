#include <iostream>
#include <string>
#include <unordered_set>

#include "custom_class.hpp"

int main(int argc, char* argv[])
{
    std::unordered_set<int> supprotedSet;
    supprotedSet.insert(5);
    supprotedSet.insert(1);
    supprotedSet.insert(7);

    using Custom = project::CustomClass;

    std::unordered_set<Custom, project::CustomClassHash> customSet;

    customSet.insert({1, "first"});
    customSet.insert({2, "second"});
    customSet.insert({3, "third"});

    std::unordered_set<Custom> customSetWithHashInStdNamespace;

    customSetWithHashInStdNamespace.insert({1, "first"});
    customSetWithHashInStdNamespace.insert({2, "second"});
    customSetWithHashInStdNamespace.insert({3, "third"});

    std::cout << "done" << std::endl;

    return 0;
}