// The Singleton is the most hated design pattern in the(rather limited)
// history of design patterns.Just stating that, however, doesn’t mean you
// shouldn’t use the singleton : a toilet brush is not the most pleasant device
// either, but sometimes it’s simply necessary.
// The Singleton design pattern grew out of a very simple idea that
// you should only have one instance of a particular component in your
// application.For example, a component that loads a database into memory
// and offers a read - only interface is a prime candidate for a Singleton, since
// it really doesn’t make sense to waste memory storing several identical
// datasets.In fact, your application might have constraints such that two or
// more instances of the database simply won’t fit into memory, or will result
// in such a lack of memory as to cause the program to malfunction.

// Singletons aren’t totally evil but, when used carelessly, they’ll mess up the
// testability and refactorability of your application.If you really must use
// a singleton, try avoiding using it directly(as in, writing SomeComponent.
// getInstance().foo()) and instead keep specifying it as a dependency
// (e.g., a constructor argument) where all dependencies are satisfied from a
// single location in your application(e.g., an inversion of control container).

#include <iostream>

#include "Singleton.hpp"
#include "Monostate.hpp"


int main()
{
    std::cout << "Hello World!\n";
}
