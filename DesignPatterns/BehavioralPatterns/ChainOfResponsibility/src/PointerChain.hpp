#include <iostream>


struct Creature
{
    std::string name;

    int attack, defense;

    // constructor and << here
};

std::ostream& operator<<(std::ostream& out, const Creature& creature)
{
    out << "Name: " << creature.name << ", attack: " << creature.attack << ", defense: " << creature.defense;
    return out;
}

class CreatureModifier
{
    CreatureModifier* next = nullptr;

protected:
    Creature& creature; // // alternative: pointer or shared_ptr

public:
    explicit CreatureModifier(Creature& creature) : creature(creature)
    {

    }

    void add(CreatureModifier* cm)
    {
        if (next)
        {
            next->add(cm);
        }
        else
        {
            next = cm;
        }
    }

    virtual void handle()
    {
        if (next)
        {
            next->handle(); // critical!
        }
    }
};

class DoubleAttackModifier : public CreatureModifier
{
public:
    explicit DoubleAttackModifier(Creature& creature)
        : CreatureModifier(creature)
    {

    }

    virtual void handle() override
    {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefenseModifier : public CreatureModifier
{
public:
    explicit IncreaseDefenseModifier(Creature& creature)
        : CreatureModifier(creature)
    {

    }

    virtual void handle() override
    {
        if (creature.attack <= 2)
        {
            creature.defense += 1;
        }

        CreatureModifier::handle();
    }
};

class NoBonusesModifier : public CreatureModifier
{
public:
    explicit NoBonusesModifier(Creature& creature)
        : CreatureModifier(creature)
    {

    }

    virtual void handle() override
    {

    }
};
