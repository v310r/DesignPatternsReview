//    Without a doubt, the code presented in this chapter is a clear example
//  of overthinking and overengineering a problem way beyond what most
//  people would want to achieve
//    Let’s recap the main design decisions when implementing Observer :
//    • Decide what information you want your observable to
//      communicate.For example, if you are handling field /
//      property changes, you can include the name of the
//      property.You can also specify old / new values, but
//      passing the type could be problematic.
//    • Do you want your observers to been tire classes, or are
//      you OK with just having a list of virtual functions ?
//    • How do you want to handle observers unsubscribing ?
//    • If you don’t plan to support unsubscription—
//      congratulations, you’ll save a lot of effort implementing
//      the Observer, since there are no removal issues in
//      reentrancy scenarios.
//    • If you plan to support an explicit unsubscribe()
//      function, you probably don’t want to erase - remove
//      right in the function, but instead mark your elements
//      for removal and remove them later.
//    • If you don’t like the idea of dispatching on a(posibly
//      null) raw pointer, consider using a weak_ptr instead.
//      • Is it likely that the functions of an Observer<T> will be
//      invoked from several different threads ? If they are, you
//      need to protect your subscription list :
//    • You can put a scoped_lock on all relevant functions; or
//    • You can use a thread - safe collection such as the TBB / PPL
//      concurrent_vector.You lose ordering guarantees.
//    • Are multiple subscriptions from the same source
//      allowed ? If they are, you cannot use an std::set.
//    There is, sadly, no ideal implementation of Observer that ticks all the boxes.
//  Whichever implementation you go for, some compromises are expected

#include <iostream>

#include "TestData.h"


int main()
{
    Person p{ 20 };
    ConsolePersonObserver cpo;
    p.Subscribe(&cpo);
    p.SetAge(21); // Person's age has changed to 21.
    p.SetAge(22); // Person's age has changed to 22.
}

