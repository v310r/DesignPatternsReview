#pragma once

#include <string>
#include <sstream>
#include <type_traits>


struct Shape2
{
    virtual std::string str() const = 0;
};

struct Circle2 : Shape2
{
    float radius;

    Circle2() = default;

    Circle2(float ) : radius(radius)
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

struct Square2 : Shape2
{
    float size;

    Square2() = default;

    Square2(float size) : size(size)
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

template <typename T> 
struct ColoredShape2 : T
{
    ColoredShape2() = default;

    template<typename...Args>
    ColoredShape2(const std::string& color, Args ...args) : T(std::forward<Args>(args)...), color{ color }
    {
    }
    //ColoredShape2(const std::string& color) : color(color)
    //{
    //    static_assert(is_base_of<Shape2, T>::value, "Template argument must be a Shape");
    //}

    std::string color;


    virtual std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

template <typename T> 
struct TransparentShape2 : T
{
    TransparentShape2() = default;

    template<typename...Args>
    TransparentShape2(const uint8_t transparency, Args ...args) : T(std::forward<Args>(args)...), transparency{ transparency }
    {
    }

    //TransparentShape2()
    //{
    //    static_assert(is_base_of<Shape2, T>::value, "Template argument must be a Shape");
    //}

    uint8_t transparency;
    std::string color;


    virtual std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};