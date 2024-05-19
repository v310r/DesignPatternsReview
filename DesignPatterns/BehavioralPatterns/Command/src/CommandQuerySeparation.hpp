#pragma once

enum class ECreatureAbility
{
    strength,
    agility
};

struct CreatureCommand
{
    enum EAction
    {
        set, 
        increaseBy,
        decreaseBy
    };



    EAction action;

    ECreatureAbility ability;

    int amount;
};

struct CreatureQuery
{
    ECreatureAbility ability;
};

class Creature
{
public:
    Creature(int strength, int agility)
        : strength{ strength }, agility{ agility }
    {

    }

    void processCommand(const CreatureCommand& cc)
    {
        int* ability;
        switch (cc.ability)
        {
            case ECreatureAbility::strength:
            {
                ability = &strength;
                break;
            }
            case ECreatureAbility::agility:
            {
                ability = &agility;
                break;
            }
        }

        switch (cc.action)
        {
        case CreatureCommand::set:
        {
            *ability = cc.amount;
            break;
        }
        case CreatureCommand::increaseBy:
        {
            *ability += cc.amount;
            break;
        }
        case CreatureCommand::decreaseBy:
        {
            *ability -= cc.amount;
            break;
        }
        }
    }

    int processQuery(const CreatureQuery& q) const
    {
        switch (q.ability)
        {
            case ECreatureAbility::strength:   return strength;
            case ECreatureAbility::agility:    return agility;
        }

        return 0;
    }

    void setStrength(int value)
    {
        processCommand(CreatureCommand{CreatureCommand::set, ECreatureAbility::strength, value});
    }

    int getStrength() const
    {
        return processQuery(CreatureQuery{ECreatureAbility::strength});
    }

private:
    int strength, agility;
};