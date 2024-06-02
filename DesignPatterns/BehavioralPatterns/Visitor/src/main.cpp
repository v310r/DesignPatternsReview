//    The Visitor design pattern allows us to add some behavior to every element
//    in a hierarchy of objects.The approaches we have seen include
//      • Intrusive : adding a virtual method to every single object
//        in the hierarchy.Possible(assuming you have access to
//        source code) but breaks OCP.
//      • Reflective : adding a separate visitor that requires no
//        changes to the objects; uses dynamic_cast whenever
//        runtime dispatch is needed.
//      • Classic(double dispatch) : the entire hierarchy does get
//        modified, but just once and in a very generic way.Each
//        element of the hierarchy learns to accept() a visitor.
//        We then subclass the visitor to enhance the hierarchy’s
//        functionality in all sorts of directions.
//    The Visitor appears quite often in tandem with the Interpreter
//      pattern : having interpreted some textual input and transformed it into
//      object - oriented structures, we need to, for example, render the abstract
//      syntax tree in a particular way.Visitor helps propagate an ostringstream
//      (or similar object) throughout the entire hierarchy and collate the data
//      together


#include <iostream>

#include "IntrusiveVisitor.hpp"
#include "ReflectivePrinter.hpp"
#include "DoubleDispatchExample.hpp"
#include "Visitor.hpp"
#include "AcyclicVisitor.hpp"


int main()
{
    auto e = new AdditionExpression
    {
        new DoubleExpression{1},
        new AdditionExpression
        {
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    std::ostringstream oss;
    e->print(oss);
    std::cout << oss.str() << std::endl; // prints (1+(2+3))

    auto e2 = new AdditionExpression2
    {
        new DoubleExpression2{1},
        new AdditionExpression2
        {
            new DoubleExpression2{2},
            new DoubleExpression2{3}
        }
    };

    ExpressionPrinter ep;
    ep.print(e2);

    std::cout << ep.str() << std::endl; // prints "(1+(2+3))"


    Stuff* stuff = new Foo();
    stuff->call();


    Stuff* stuff2 = new Bar();
    stuff2->call();

    auto e3 = new AdditionExpression3
    {
        new DoubleExpression3{1},
        new AdditionExpression3
        {
            new DoubleExpression3{2},
            new DoubleExpression3{3}
        }
    };

    std::ostringstream oss2;
    ExpressionPrinter3 ep3;
    ep3.visit(e3);
    std::cout << ep3.str() << std::endl; // (1+(2+3))

    auto e4 = new AdditionExpression3
    {
        new DoubleExpression3{1},
        new AdditionExpression3
        {
            new DoubleExpression3{2},
            new DoubleExpression3{3}
        }
    };

    std::ostringstream oss3;
    ExpressionPrinter3 ep4;
    ExpressionEvaluator ev;
    ep4.visit(e4);
    ev.visit(e4);
    std::cout << ep4.str() << " = " << ev.result << std::endl;
}
