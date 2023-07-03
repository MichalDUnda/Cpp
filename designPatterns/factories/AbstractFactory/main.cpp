#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"

unique_ptr<HotDrink> make_drink(HotDrinkType type)
{
    unique_ptr<HotDrink> drink;
    switch(type)
    {
        case HotDrinkType::Tea:
            drink = make_unique<Tea>();
            drink->prepare(200);
            return std::move(drink);
        case HotDrinkType::Coffee:
            drink = make_unique<Coffee>();
            drink->prepare(50);
            return std::move(drink);

        default:
            break;
    }
    std::move(drink);
}

int main(int argc, char* argv[])
{
    // factory method
    auto drink = make_drink(HotDrinkType::Tea);
    DrinkWithVolumeFactory volumeFactory{};
    volumeFactory.make_cap(HotDrinkType::Tea)->type();
    return 0;
}