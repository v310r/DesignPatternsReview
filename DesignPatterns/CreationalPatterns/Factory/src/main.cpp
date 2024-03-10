// Let’s recap the terminology :
// • A factory method is a class member that acts as a way of
// creating object.It typically replaces a constructor.
// • A factory is typically a separate class that knows how to
// construct objects, though if you pass a function(as in
//     std::function or similar) that constructs objects, this
//     argument is also called a factory.
//     • An abstract factory is, as its name suggests, an abstract
//     class that can be inherited by concrete classes that offer
//     a family of types.Abstract factories are rare in the wild.
//     A factory has several critical advantages over a constructor call,
//     namely :
//     • A factory can say no, meaning that instead of actually
//     returning an object it can return, for example, a
//     nullptr.
//     • Naming is better and unconstrained, unlike
//     constructor name.
//     • A single factory can make objects of many different
//     types.
//     • A factory can exhibit polymorphic behavior,
//     instantiating a class and returning it through its base
//     class’ reference or pointer.
//     • A factory can implement caching and other storage
//     optimizations; it is also a natural choice for approaches
//     such as pooling or the Singleton pattern(more on
//         this in Chapter 5).
//     Factory is different from Builder in that, with a Factory, you typically
//     create an object in one go, whereas with Builder, you construct the object
//     piecewise by providing information in parts.

#include <iostream>

#include "Factory.hpp"
#include "InnerFactory.hpp"
#include "AbstractFactory.hpp"
//#include "FunctionalFactory.hpp"

int main()
{
    auto myPoint = PointFactory::NewCartesian(3, 4);

    auto pp = Point2::Factory.NewCartesian(2, 3);

    DrinkFactory df;
    std::unique_ptr<Tea> tea;
    tea.reset(static_cast<Tea*>(df.makeDrink("tea").release()));

    tea->prepare(200);
}

