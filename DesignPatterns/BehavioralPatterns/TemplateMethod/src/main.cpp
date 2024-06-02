//      Unlike the Strategy, which uses composition and thus branches into
//  static and dynamic variations, Template Method uses inheritance and,
//  as a consequence, it can only be static, since there is no way to fiddle the
//  inheritance characteristics of an object once it’s been constructed.
//      The only design decision in a Template Method is whether you want
//  the methods used by the Template Method to be pure virtual or actually
//  have a body, even if that body is empty.If you foresee some methods
//  unnecessary for all inheritors, go ahead and make them no - op ones.


#include <iostream>

#include "GameSimulation.hpp"


int main()
{   /*
        Starting a game of chess with 2 players
        Turn 0 taken by player 0
        Turn 1 taken by player 1
        ...
        Turn 8 taken by player 0
        Turn 9 taken by player 1
        Player 0 wins.
        
        And that’s pretty much all there is to it!
    */
}
