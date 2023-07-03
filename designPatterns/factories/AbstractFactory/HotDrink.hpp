#pragma once
#include <memory>
#include <map>
#include <iostream>
#include <string>

using namespace std;

enum class HotDrinkType
{
    Tea,
    Coffee
};

struct HotDrink
{
    virtual ~HotDrink() = default;

    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{

    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << endl;
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Grind some beans, boil water, pour " << volume << "ml, add cream, enjoy!" << endl;
    }
};

struct Cap
{
    virtual ~Cap() = default;

    virtual void type() = 0;
};

struct TeaCap : Cap
{

    virtual void type() override
    {
        cout << "This is tea cap " << endl;
    }
};

struct CoffeeCap : Cap
{

    virtual void type() override
    {
        cout << "This is coffee cap " << endl;
    }
};