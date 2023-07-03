#pragma once
#include "HotDrink.hpp"

//Abstract factory
struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> make() const = 0;
    virtual unique_ptr<Cap> cap() const = 0;
};

struct TeaFactory : public HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Tea>();
    }

    virtual unique_ptr<Cap> cap() const override
    {
        return std::make_unique<TeaCap>();
    }
};
struct CoffeeFactory : public HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Coffee>();
    }

    virtual unique_ptr<Cap> cap() const override
    {
        return std::make_unique<CoffeeCap>();
    }
};