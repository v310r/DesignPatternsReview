// The Façade design pattern is a way of putting a simple interface in front
// of one or more complicated subsystems.In our example, a complicated
// set - up involving many buffers and viewports can be used directly or , if you
// just want a simple console with a single buffer and associated viewport,
// you can get it through a very accessible and intuitive API.


#include <iostream>

#include "Console.hpp"


int main()
{
    std::cout << "Hello World!\n";

    Console console;
}

