
// Composite pattern is used where we need to treat a group of objects in similar way as a single object.

// The Composite design pattern allows us to provide identical interfaces
// for individual objects and collections of objects.This can be done either
// through the explicit use of interface members or , alternatively, through
// duck typing—for example, range - based for loops don’t require you to
// inherit anything, and work on the basis of the typing having suitablelooking begin() / end() members.
// It is precisely these begin() / end() members that allow a scalar
// type to masquerade as a “collection.” It is also interesting to note
// that the nested for loops of our connect_to() function are able to
// connect the two constructs together despite them having different
// iterator types : Neuron returns a Neuron* whereas NeuronLayer returns
// vector<Neuron>::iterator—these two are not quite the same thing.Ahh,
// the magic of templates!
// Finally, I must admit that all of these jumps through hoops are
// necessary only if you want to have a single member function.If you are
// OK with calling a global function or if you are happy with having more
// than one connect_to() implementation, the base class SomeNeurons is
// unnecessary.

#include <iostream>

#include "SomePageExample.hpp"
#include "ArrayBackedProperties.hpp"
#include "GroupedGraphicObjects.hpp"
#include "NeuralNetworks.hpp"


int main()
{
    // begin SomePageExample part
    Page a;
    Page b;
    Copy allcopy;
    allcopy.AddElement(a);
    allcopy.AddElement(b);

    allcopy.Add(a);
    a.Add(b);

    allcopy.Remove();
    b.Remove();

    // end SomePageExample part
    std::cout << "\n";

    std::cout << "\n";
    // start ArrayBackedProperties part

    Creature c(5);

    std::cout << "Sum: " << c.Sum() << "; Average: " << c.Average() << "; Max: " << c.Max() << "\n";

    // end ArrayBackedProperties part
    std::cout << "\n";



    std::cout << "\n";
    // start GroupedGraphicObjects part

    Group root("root");

    Circle c1, c2;

    root.objects.push_back(&c1);

    Group subgroup("sub");
    subgroup.objects.push_back(&c2);

    root.objects.push_back(&subgroup);

    root.draw();

    // end GroupedGraphicObjects part
    std::cout << "\n";

    std::cout << "\n";
    // start NeuralNetworks part

    // the example in the book is just to read it, it does not work properly with memory, be careful :-)
    // if it were real world situation, we would never write everything in such a simple manner
    // and make something more robust
    Neuron neuron, neuron2;
    NeuronLayer layer(1), layer2(1);

    neuron.connect_to<Neuron>(neuron2);
    neuron.connect_to<NeuronLayer>(layer);
    layer.connect_to<Neuron>(neuron);
    layer.connect_to<NeuronLayer>(layer2);

    // end  NeuralNetworks part
    std::cout << "\n";

    return 0;
}

