#include <iostream>
#include <string>

// Shapes - circle, square
// Rendered - raster, vector

// solving cartesean explosion

// 2x2x CircleVector, CircleRaster, SquareVector, SquareRaster

struct Renderer
{
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : public Renderer
{
    virtual void render_circle(float x, float y, float radius) override
    {
        std::cout << "Rasterizing a circle of radius " << radius << std::endl;
    }
};

struct RasterRenderer : public Renderer
{
    virtual void render_circle(float x, float y, float radius) override
    {
        std::cout << "Drawing a vector a circle of radius " << radius << std::endl;
    }
};

struct Shape
{
protected:
    Renderer& renderer;

public:
    Shape(Renderer& renderer)
        : renderer(renderer)
    {
    }

    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : public Shape
{

private:
    float x, y, radius;

public:
    Circle(Renderer& renderer, float x, float y, float radius)
        : Shape(renderer)
        , x(x)
        , y(y)
        , radius(radius)
    {
    }

    void draw() override
    {
        renderer.render_circle(x, y, radius);
    }
    void resize(float factor) override
    {
        radius *= factor;
    }
};

int main()
{
    RasterRenderer rr;
    Circle circle{rr, 5, 5, 5};
    circle.draw();
    circle.resize(2);
    circle.draw();
    return 0;
}