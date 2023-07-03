#pragma once
#include <string>
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <map>
#include <functional>

struct HotDrink;

class DrinkFactory
{
    map<HotDrinkType, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory()
    {
        hot_factories[HotDrinkType::Coffee] = make_unique<CoffeeFactory>();
        hot_factories[HotDrinkType::Tea] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(HotDrinkType name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200); // oops!
        return drink;
    }

    unique_ptr<Cap> cap(HotDrinkType name)
    {
        return hot_factories[name]->cap();
    }
};

class DrinkWithVolumeFactory
{
    // private inner structure
    struct DrinkLambdas
    {

        function<unique_ptr<HotDrink>()> hotDrink;
        function<unique_ptr<Cap>()> cap;
    };

    map<HotDrinkType, DrinkLambdas> factories;

public:
    // possibility to make public setters.
    // user can define his own lambda and store it to the map
    DrinkWithVolumeFactory()
    {

        DrinkLambdas teaLambdas;
        teaLambdas.cap = [] {
            return make_unique<TeaCap>();
        };

        teaLambdas.hotDrink = [] {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };

        factories[HotDrinkType::Tea] = teaLambdas;

        DrinkLambdas coffeeLambdas;
        coffeeLambdas.cap = [] {
            return make_unique<CoffeeCap>();
        };

        coffeeLambdas.hotDrink = [] {
            auto coffee = make_unique<Coffee>();
            coffee->prepare(200);
            return coffee;
        };

        factories[HotDrinkType::Coffee] = coffeeLambdas;
    }

    unique_ptr<HotDrink> make_drink(HotDrinkType name);
    unique_ptr<Cap> make_cap(HotDrinkType name);
};

inline unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(HotDrinkType name)
{
    return factories[name].hotDrink();
}

inline unique_ptr<Cap> DrinkWithVolumeFactory::make_cap(HotDrinkType name)
{
    return factories[name].cap();
}