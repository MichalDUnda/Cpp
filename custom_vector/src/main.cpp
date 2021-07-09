#include <iostream>
#include <string>
#include <vector>

#include "container.hpp"

template <typename T>
void printInLoop(const T& container)
{
    for(const auto& i : container)
    {
        std::cout << i << "\n";
    }
}

template <typename T>
void printInLoopWithAddress(const T& container)
{
    container.printAddressOfFirstElement();
    for(const auto& i : container)
    {
        std::cout << "value" << i << "\n";
    }
}

int main(int argc, char* argv[])

{
    container::Vector<int> c(3);
    std::cout << "main end" << std::endl;

    std::fill(c.begin(), c.end(), 3);

    printInLoopWithAddress(c);

    container::Vector<int> vec2(c);
    printInLoopWithAddress(vec2);
    container::Vector<int> vec3(std::move(vec2));

    std::cout << "print full vec 3" << std::endl;
    printInLoopWithAddress(vec3);

    container::Vector<int> vec4;

    std::cout << "print empty vec 4" << std::endl;
    printInLoopWithAddress(vec4);
    vec4 = vec3;
    std::cout << "print full vec 4" << std::endl;
    printInLoopWithAddress(vec4);

    std::fill(vec3.begin(), vec3.end(), 5);
    std::cout << "after 5 assign" << std::endl;
    std::cout << "print full vec 3" << std::endl;
    printInLoopWithAddress(vec3);

    std::cout << "print empty vec 4" << std::endl;
    printInLoopWithAddress(vec4);

    return 0;
}