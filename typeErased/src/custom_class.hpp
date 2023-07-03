
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iostream>
#include <vector>
#include <memory>

struct Circle
{
};

struct Square
{
};

// External polymorphism

struct ShapeConcept
{
    virtual ~ShapeConcept() = default;
    virtual void serialize() const = 0;
    virtual void draw() const = 0;
};

void serializeGlob(const Circle& circle)
{
    std::cout << "circle serialize" << std::endl;
}

void drawGlob(const Circle& circle)
{
    std::cout << "circle draw" << std::endl;
}

void serializeGlob(const Square& circle)
{
    std::cout << "square serialize" << std::endl;
}

void drawGlob(const Square& circle)
{
    std::cout << "square draw" << std::endl;
}

template <typename T>
struct ShapeModel : ShapeConcept
{
    template <typename... Args>
    ShapeModel(Args&&... args)
        : object(std::forward<Args>(args)...)
    {
    }

    ~ShapeModel() override = default;

    void serialize() const override
    {
        serializeGlob(object);
    }

    void draw() const override
    {
        drawGlob(object);
    }

    T object;
};

void drawAllShapes(const std::vector<std::unique_ptr<ShapeConcept>>& shapes)
{
    for(const auto& item : shapes)
    {
        item->draw();
    }
}

#endif