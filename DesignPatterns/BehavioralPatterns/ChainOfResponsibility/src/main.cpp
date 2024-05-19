//  Chain of Responsibility is a very simple design pattern that lets
//  components process a command(or a query) in turn.The simplest
//  implementation of CoR is one where you simply make a pointer chain and,
//  in theory, you could replace it with just an ordinary vector or , perhaps, a
//  list if you wanted fast removal as well.
//  A more sophisticated Broker Chain implementation that also leverages
//  the Mediator and Observer patterns allows us to process queries on
//  an event(signal), letting each subscriber perform modifications of the
//  originally passed object(it’s a single reference that goes through the entire
//  chain) before the final values are returned to the client.

// reminds GAS handling of gameplay effects and tags in Unreal Engine

#include <iostream>

#include "PointerChain.hpp"
#include "BrokerChain.hpp"


int main()
{
    Creature goblin{ "Goblin", 1, 1 };
    CreatureModifier root{ goblin };
    DoubleAttackModifier r1{ goblin };
    DoubleAttackModifier r1_2{ goblin };
    IncreaseDefenseModifier r2{ goblin };
    
    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);
    
    root.handle();
    
    std::cout << goblin << std::endl;
    // name: Goblin attack: 4 defense: 1

    // Doesn't work due to lack of boost library
    //
    //          Game game;
    //          Creature goblin{ game, "Strong Goblin", 2, 2 };
    //          std::cout << goblin << std::endl;
    //          // name: Strong Goblin attack: 2 defense: 2

    //          {
    //              DoubleAttackModifier dam{ game, goblin };
    //              std::cout << goblin << std::endl;
    //              // name: Strong Goblin attack: 4 defense: 2
    //          }

    //           std::cout << goblin << std::endl;
    //           // name: Strong Goblin attack: 2 defense: 2
        
}

