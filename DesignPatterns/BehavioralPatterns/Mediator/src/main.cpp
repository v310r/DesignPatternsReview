//      The Mediator design pattern essentially proposes an introduction of an
//  in - between component that everyone in a system has a reference to and
//  can use to communicate with one another.Instead of direct memory
//  addresses, communication can happen through identifiers(usernames,
//  unique IDs, etc).
//  The simplest implementation of a mediator is a member list and a
//  function that goes through the list and does what it’s intended to do—
//  whether on every element of the list or selectively.
//      A more sophisticated implementation of Mediator can use events to
//  allow participants to subscribe(and unsubscribe) to things happening
//  in the system.This way, messages sent from one component to another
//  can be treated as events.In this set - up, it is also easy for participants to
//  unsubscribe to certain events if they are no longer interested in them or if
//  they are about to leave the system altogether


#include <iostream>

#include "ChatRoom.hpp"


int main()
{
    ChatRoom room;
    
    Person john{ "john" };
    Person jane{ "jane" };
    room.join(&john);
    room.join(&jane);
    john.say("hi room");
    jane.say("oh, hey john");
    
    Person simon("simon");
    room.join(&simon);
    simon.say("hi everyone!");
    
    jane.pm("simon", "glad you could join us, simon");
}

