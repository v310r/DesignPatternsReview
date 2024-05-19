//    The Command design pattern is simple : what it basically suggests is that
//    objects can communicate with one another using special objects that
//    encapsulate instructions, rather than specifying those same instructions as
//    arguments to a method.
//    Sometimes, you don’t want such an object to mutate the target or
//    cause it to do something specific; instead you want to use such an object
//    to inquire a value from the target, in which case we typically call such an
//    object a Query.While, in most cases, a query is an immutable object that
//    relies on the return type of the method, there are situations(see, e.g., the
//    Chain of Responsibility Broker Chain example; Chapter 13) when you want
//    the result that’s being returned to be modified by other components.But
//    the components themselves are still not modified, only the result is.
//    Commands are used a lot in UI systems to encapsulate typical actions
//    (e.g., Copy or Paste) and then allow a single command to be invoked by
//    several different means.For example, you can Copy by using the top - level
//    application menu, a button on the toolbar, or a keyboard shortcut.Finally,
//    these actions can be combined into macros—sequences of actions that can
//    be recorded and then replayed at will.


#include <iostream>

#include "CommandSimpleExample.hpp"
#include "CommandQuerySeparation.hpp"


int main()
{
    BankAccount ba;
    BankAccountCommand cmd{ba, BankAccountCommand::deposit, 100};
    cmd.call();
}

