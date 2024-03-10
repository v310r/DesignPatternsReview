#pragma once

#include <array>
#include <algorithm>
#include <numeric>


class Creature
{
public:
    enum Abilities
    { 
        str = 0,
        agl = 1,
        intl = 2,
        count
    };

    Creature(int modifier)
    {
        for (int i = 0; i < count; ++i)
        {
            abilities[i] = modifier * i;
        }
    }

    int GetStrength() const { return abilities[str]; }
    void SetStrength(int value) {abilities[str] = value; }

    int GetAgility() const { return abilities[agl]; }
    void SetAgility(int value) { abilities[agl] = value; }

    int GetIntelligence() const { return abilities[intl]; }
    void SetIntelligence(int value) { abilities[intl] = value; }

    int Sum() const 
    {
       return std::accumulate(abilities.begin(), abilities.end(), 0);
    }

    float Average() const 
    {
        return Sum() / (float)count;
    }
    
    int Max() const 
    {
         return *std::max_element(abilities.begin(), abilities.end());
    }


    std::array<int, count> abilities;
};