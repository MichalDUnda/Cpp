#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType
{
    cartesian,
    polar
};

class Point
{
public:
    Point(const float x, const float y)
        : x{x}
        , y{y}
    {
    }

public:
    float x, y;

    friend std::ostream& operator<<(std::ostream& os, const Point& obj)
    {
        return os
               << "x: " << obj.x
               << " y: " << obj.y;
    }

    // one way to factory is to create simple factory methods
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }
    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

// alternative is to create factory class
// also possibility to hide constructor and than make a friend classs.
// this leads to break open close principles
struct PointFactory
{
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }
    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

// example of inner factory:

class PointWithInnerFactory
{
    // all data members are private
    // force to use factory for creation
    PointWithInnerFactory(const float x, const float y)
        : x{x}
        , y{y}
    {
    }

public:
    float x, y;

    friend std::ostream& operator<<(std::ostream& os, const PointWithInnerFactory& obj)
    {
        return os
               << "x: " << obj.x
               << " y: " << obj.y;
    }

    // alternative is to create factory class
    // also possibility to hide constructor and than make a friend classs.
    // this leads to break open close principles
    struct PointFactory
    {
        static PointWithInnerFactory NewCartesian(float x, float y)
        {
            return {x, y};
        }
        static PointWithInnerFactory NewPolar(float r, float theta)
        {
            return {r * cos(theta), r * sin(theta)};
        }
    };
};

/// FActory method.
/// create function method which return proper object.
/// this should be done via function parameters. or via call of concrete factory function like here.
/// difference between factory and builder :
///
/// Builder pattern is an object creational software design pattern.
/// This pattern is often compared with “Factory” method pattern because factory method is also an object creational
/// DP. The key difference is how the object is being created though. For example with the factory DP, createCar might return Honda or Audi.
/// To add attributes, you will need to make additional calls such as setColor, setEngine etc on the object returned.
/// Now with the Builder pattern, you could be specific about the object all in one statement,
/// such as 4 all-wheel drive red Honda with v6 engine etc. Basically, factory method pattern would create an object via
/// createCar VS Builder pattern has the ability to create an object by adding granularity to the object by applying chains
/// of function calls to the object being created.
int main(int argc, char* argv[])
{
    auto p = Point::NewPolar(5.F, M_PI_4);
    auto pointFromFActory = PointFactory::NewPolar(5.F, M_PI_4);
    std::cout << p << std::endl;

    auto pointFromInnerFActory = PointWithInnerFactory::PointFactory::NewPolar(5.F, M_PI_4);

    getchar();
    return 0;
}