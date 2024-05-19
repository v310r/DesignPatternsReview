
#include <iostream>


#include "DynamicDecorator.hpp"
#include "StaticDecorator.hpp"
#include "FunctionalDecorator.hpp"

double add(double a, double b)
{
    std::cout << a << "+" << b << "=" << (a + b) << std::endl;
    return a + b;
}


int main()
{
    ///////// BEGIN dynamic decorator SECTION /////////

    // prints "A circle of radius 0.5 has the color red"
    Circle circle{ 0.5f };
    ColoredShape redCircle{ circle, "red" };
    std::cout << redCircle.str() << std::endl;

    std::cout << std::endl;
    
    // A square with side 3 has 33.333% transparency
    Square square{ 3 };
    TransparentShape demiSquare{ square, 85 };
    std::cout << demiSquare.str() << std::endl;

    std::cout << std::endl;

    // A circle of radius 23 has the color green has 25.098% transparency
    // 
    // TODO: fix compile error
    // 
    //TransparentShape myCircle{ColoredShape{Circle{ 23 }, "green"}, 64};
    //std::cout << myCircle.str();

    ///////// END dynamic decorator SECTION /////////

    std::cout << std::endl;

    ///////// BEGIN static decorator SECTION /////////

    ColoredShape2<TransparentShape2<Square2>> square2/*{ "blue" }*/;
    square2.color = "blue";
    square2.size = 2;
    square2.transparency = 0.5;
    std::cout << square2.str();
    // can call square's own members
    square2.resize(3);

    std::cout << std::endl;

    ColoredShape2<TransparentShape2<Square>> sq =
    { "red", 51, 5 };
    std::cout << sq.str() << std::endl;
    // A square with side 5 has 20% transparency has the color red

    ///////// END static decorator SECTION /////////

    std::cout << std::endl;

    ///////// BEGIN Functional decorator SECTION /////////

    // TODO: make it compile
    //auto logged_add = make_logger3(add, "Add");
    //auto result = logged_add(2, 3);

    ///////// END Functional decorator SECTION /////////
}
