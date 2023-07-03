#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Motivation
// Composition lets us make compound object

// So if you think about an application such as PowerPoint or any kind of vector drawing application you
// know that you can draw & drag individual shapes around.
// But you can also group shapes together. And when you group several shapes together you can
// treat them as if they were a single shape. So you can grab the entire thing and also drag it and resize it and whatnot.
// So, we're going to implement the Composite Design Pattern around this idea of several different shapes.

struct GraphicObject
{
    virtual void draw() = 0;
};

struct Circle : GraphicObject
{
    void draw() override
    {
        std::cout << "Circle" << std::endl;
    }
};

struct Group : GraphicObject
{
    explicit Group(const std::string& name)
        : name{name}
    {
    }

    void draw() override
    {
        std::cout << "Group " << name.c_str() << " contains:" << std::endl;
        for(auto&& o : objects)
            o->draw();
    }

    std::string name;
    std::vector<GraphicObject*> objects;
};

int main()
{
    Group root("root");
    Circle c1, c2;
    root.objects.push_back(&c1);

    Group subgroup("sub");
    subgroup.objects.push_back(&c2);

    root.objects.push_back(&subgroup);

    root.draw();

    return 0;
}