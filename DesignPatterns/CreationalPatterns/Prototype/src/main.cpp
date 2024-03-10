/*
        Think about something you use every day, like a car or a mobile phone.
    Chances are, it wasn’t designed from scratch; instead, the manufacturer
    chose an existing design, made some improvements, made it visually
    distintive from the old design (so people could show off), and started
    selling it, retiring the old product. It’s a natural state of affairs, and in the
    software world, we get a similar situation: sometimes, instead of creating
    an entire object from scratch (the Factory and Builder patterns can help
    here), you want to take a preconstructed object and either use a copy of it
    (which is easy) or, alternatively, customize it a little.
        And this leads us to the idea of having a Prototype: a model object that
    we can make copies of, customize those copies, and then use them. The
    challenge of the Prototype pattern is really the copying part; everything
    else is easy
*/

/* 1) Duplication via Copy Construction - main points are constructors and copy constructors

    Contact worker{"", (new) Address{"123 East Dr", "London", 0}}; <- it's a prototype

    Contact john = worker;   (in case Address is member pointer, proper copy constructor should be implemented)
    john.name = "John Doe";
    john.address.suite = 10;

    2) Serialization/Deserialization - instead of writing a lot of constructors to copy object, just use already implemented serialization 
       (e.g. use boost library for this).
*/

// The Prototype design pattern embodies the notion of deep copying of
// objects so that, instead of doing full initialization each time, you can take a
// premade object, copy it, fiddle it a little bit, and then use it independently
// of the original.
// There are really only two ways of implementing the Prototype pattern
// in C++, and both of them require manual manipulation.They are :
// • Writing code that correctly duplicates your object, that
// is, performs a deep copy.This can be done in a copy
// constructor / copy assignment operator or in a separate
// member function.
// • Write code for the support of serialization /
// deserialization and then use this mechanism to
// implement cloning as serialization immediately
// followed by deserialization.This carries the extra
// computational cost; its significance depends on how
// often you need to do the copying.The only advantage
// of this approach, compared with using, say, copy
// constructors, is that you get serialization for free.
// Whichever approach you choose, some work will be required.Code
// generation tools(e.g., ReSharper, CLion) can help here if you decide to
// choose either of these two approaches.Finally, don’t forget that if you store
// data by value, you don’t really have a problem

#include <iostream>
#include "PrototypeFactory.hpp"

int main()
{
    std::unique_ptr<Contact> john(EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123));
    std::unique_ptr<Contact> jane(EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125));
}

