//      First of all, it’s worth highlighting that Boost.MSM is one of two
//  alternative state machine implemenetations in Boost, the other being
//  Boost.Statechart.I’m pretty sure there are plenty of other state machine
//  implementations out there.
//      Second, there’s a lot more to state machines than that.For example,
//  many libraries support the idea of hierarchical state machines : for
//  example, a state of Sick can contain many different substates such as Flu
//  or Chickenpox.If you are in state Flu, you are also assumed to be in the
//  state Sick.
//      Finally, it’s worth highlighting again how far modern state machines
//  are from the State design pattern in its original form.The existence of
//  duplicate APIs(e.g., LightSwitch::on / off vs.State::on / off) as well as
//  the presence of self - deletion are definite code smells in my book.Don’t get
//  me wrong—the approach works, but it’s unintuitive and cumbersome.

#include <iostream>

#include "StateDrivenStateTransitions.hpp"
#include "HandmadeStateMachine.hpp"


int main()
{
    LightSwitch ls; // Light turned off
    ls.On(); // Switching light on...
    // Light turned on
    ls.Off(); // Switching light off...
    // Light turned off
    ls.Off(); // Light is already off

    //second example
    // processExample();
}

