#pragma once

#include <string>
#include <sstream>


struct Shape
{
    virtual std::string str() const = 0;
};

struct Circle : Shape
{
    float radius;

    explicit Circle(const float radius)
        : radius{ radius }
    {

    }

    void resize(float factor) { radius *= factor; }

    virtual std::string str() const override
    {
        std::ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }

}; 

struct Square : Shape
{
    float size;

    explicit Square(float size)
        : size{ size }
    {

    }

    void resize(float factor) { size *= factor; }

    virtual std::string str() const override
    {
        std::ostringstream oss;
        oss << "A square of size " << size;
        return oss.str();
    }

};

struct ColoredShape : Shape
{
    Shape& shape;
    std::string color;

    explicit ColoredShape(Shape& shape, const std::string& color)
        : shape{ shape }, color{ color } 
    {

    }

    virtual std::string str() const override
    {
        std::ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;

   explicit TransparentShape(Shape& shape, const uint8_t transparency)
       : shape{ shape }, transparency{ transparency }
   {

   }

    virtual std::string str() const override
    {
        std::ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
        return oss.str();
    }
};
