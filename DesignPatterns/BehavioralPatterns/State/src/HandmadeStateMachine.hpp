#pragma once

#include <vector>
#include <utility>
#include <map>
#include <iostream>


enum class State2
{
    OffHook,
    Connecting,
    Connected,
    OnHold,
    OnHook
};

enum class Trigger2
{
    CallDialed,
    HungUp,
    CallConnected,
    PlacedOnHold,
    TakenOffHold,
    LeftMessage,
    StopUsingPhone
};

std::map<State2, std::vector<std::pair<Trigger2, State2>>> rules;

State2 g_CurrentState {State2::OffHook}, g_ExitState{State2::OnHook};

void InitRules()
{
    rules[State2::OffHook] = 
    {
        {Trigger2::CallDialed, State2::Connecting},
        {Trigger2::StopUsingPhone, State2::OnHook}
    };

    rules[State2::Connecting] =
    {
        {Trigger2::HungUp, State2::OffHook},
        {Trigger2::CallConnected, State2::Connected}
    };

    // more rules here
}

void processExample()
{
    while (true)
    {
        std::cout << "The phone is currently " << static_cast<int>(g_CurrentState) << std::endl;
        select_trigger:
        std::cout << "Select a trigger:" << "\n";

        int i = 0;
        for (auto item : rules[g_CurrentState])
        {
            std::cout << i++ << ". " << static_cast<int>(item.first) << "\n";
        }

        int input;
        std::cin >> input;
        if (input < 0 || (input + 1) > rules[g_CurrentState].size())
        {
            std::cout << "Incorrect option. Please try again." << "\n";
            goto select_trigger;
        }

        g_CurrentState = rules[g_CurrentState][input].second;
        if (g_CurrentState == g_ExitState)
        {
            break;
        }
    }
}