#include <iostream>
#include <string>

#include "custom_class.hpp"

// compare to inheritance + strategy
// this approach is faster

int main(int argc, char* argv[])
{
    std::vector<std::unique_ptr<ShapeConcept>> shapes;
    shapes.emplace_back(std::make_unique<ShapeModel<Circle>>());
    shapes.emplace_back(std::make_unique<ShapeModel<Square>>());
    shapes.emplace_back(std::make_unique<ShapeModel<Circle>>());

    drawAllShapes(shapes);
    return 0;
}