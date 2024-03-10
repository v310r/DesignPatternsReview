/*
    The Builder pattern is concerned with the creation of complicated objects, 
    that is, objects that cannot be built up in a single-line constructor call. 
    These types of objects may themselves be composed of other objects and 
    might involve less-than-obvious logic, necessitating a separate component 
    specifically dedicated to object construction.

    I suppose it’s worth noting beforehand that, while I said the Builder is 
    concerned with complicated objects, we’ll be taking a look at a rather trivial 
    example. This is done purely for the purposes of space optimization, so 
    that the complexity of the domain logic doesn’t interfere with the reader’s 
    ability to appreciate the actual implementation of the pattern.
*/

//  The goal of the Builder pattern is to define a component dedicated entirely
//  to piecewise construction of a complicated object or set of objects.We
//  have observed the following key characteristics of a Builder :
//  • Builders can have a fluent interface that is usable for
//  complicated construction using a single invocation
//  chain.To support this, builder functions should return
//  this or *this.
//  • To force the user of the API to use a Builder, we can
//  make the target object’s constructors inaccessible and
//  then define a static create() function that returns the
//  builder.
//  • A builder can be coerced to the object itself by defining
//  the appropriate operator.
//  • Groovy - style builders are possible in C++ thanks
//  to uniform initializer syntax.This approach is very
//  general, and allows for the creation of diverse DSLs.
//  • A single builder interface can expose multiple
//  subbuilders.Through clever use of inheritance and
//  fluent interfaces, one can jump from one builder to
//  another with ease.
//  Just to reiterate something that I’ve already mentioned, the use of
//  the Builder pattern makes sense when the construction of the object is a
//  nontrivial process.Simple objects that are unambiguously constructed
//  from a limited number of sensibly named constructor parameters
//  should probably use a constructor(or dependency injection) without
//  necessitating a Builder as such.

#include <iostream>

#include "FluentBuilder.hpp"
#include "GroovyStyleBuilder.hpp"
#include "CompositeBuilder.hpp"

int main()
{
    // #1
    HtmlElement e = HtmlBuilder::build("ul")->addChild("li", "hello").addChild("li", "world");

    // #2
    std::cout <<
        P{
            IMG{"url"}
        } 
    << std::endl;

    // #3
    Person p = PersonBuilder::create()
        .lives().at("Yakub. street").withPostcode("30168").in("Kyiv")
        .works().at("GodCompany").asA("God").earning(100000);
}


