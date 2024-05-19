// The Flyweight pattern is fundamentally a space - saving technique.Its
// exact incarnations are diverse : sometimes you have the Flyweight being
// returned as an API token that allows you to perform modifications of
// whoever has spawned it, whereas at other times the Flyweight is implicit,
// hiding behind the scenes—as in the case of our User, where the client isn’t
// meant to know about the Flyweight actually being used.

#include <iostream>

#include "User.hpp"
#include "BetterFormattedText.hpp"


int main()
{
    // #1
    User user;


    // #2
    BetterFormattedText bft("This is a brave new world");
    bft.get_range(10, 15).capitalize = true;
    std::cout << bft << std::endl;
    // prints "This is a BRAVE new world"
}
