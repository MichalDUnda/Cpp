#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#include "Vehicle.h"
#include "Builder.hpp"

int main(int argc, char* argv[])
{

    //auto car = MainBuilder::createCar().setBrand("porshe").withEnginePower("900").setColor("red").setPrice("1000").build();
    auto car = BuildCar().withEnginePower("900").withColor("red").ofBrand("porshe").withPrice("900 000 euros").build();
    std::cout << car << std::endl;
    return 0;
}