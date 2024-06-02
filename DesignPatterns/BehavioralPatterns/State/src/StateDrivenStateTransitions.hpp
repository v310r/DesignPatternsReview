#pragma once

#include <iostream>


class LightSwitch;

struct State
{
    virtual void On(LightSwitch* ls)
    {
        std::cout << "Light is already on\n";
    }

    virtual void Off(LightSwitch* ls)
    {
        std::cout << "Light is already off\n";
    }
};


struct OnState : State 
{
    OnState()
    {
        std::cout << "Light turned on\n";
    }

    virtual void Off(LightSwitch* ls) override;
};

struct OffState : State
{
    OffState()
    {
        std::cout << "Light turned off\n";
    }

    virtual void On(LightSwitch* ls) override;
};

class LightSwitch
{
public:
    LightSwitch()
    {
        state = new OffState();
    }

    void On()
    {
        state->On(this);
    }
    void Off()
    {
        state->Off(this);
    }


    void SetState(State* state)
    {
        this->state = state;
    }

private:
    State* state;
};


void OnState::Off(LightSwitch* ls)
{
    std::cout << "Switching light off...\n";
    ls->SetState(new OffState());
    delete this;
}

void OffState::On(LightSwitch* ls)
{
    std::cout << "Switching light on...\n";
    ls->SetState(new OnState());
    delete this;
}
