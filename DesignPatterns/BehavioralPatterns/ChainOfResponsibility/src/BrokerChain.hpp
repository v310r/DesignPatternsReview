#include <iostream>


struct Game // mediator
{
    // needs boost's signal
    //signal<void(Query&) queries;
};

struct Query
{
    std::string creatureName;

    enum class Argument
    {
        attack,
        defense
    } argument;

    int result;
};

class Creature2
{
    Game& game;

    int attack, defense;
public:
    std::string name;

    Creature2(Game& game, int attack, int defense, const std::string& name) 
        :game(game), attack(attack), defense(defense), name(name)
    {

    }

    int getAttack() const
    {
        Query q{ name, Query::Argument::attack, attack };
        //game.queries(q);
        return q.result;
    }


};

class CreatureModifier2
{
    Game& game;

    Creature& creature;
public:
    CreatureModifier2(Game& game, Creature& creature)
        :game(game), creature(creature)
    {

    }
};

class DoubleAttackModifier2 : public CreatureModifier2
{
    //connection conn;
public:
    DoubleAttackModifier2(Game& game, Creature& creature)
        :CreatureModifier2(game, creature)
    {
        //conn = game.queries.connect([&](Query& q)
        //{
        //    if (q.creatureName == creature.name && q.argument == Query::Argument::attack)
        //    {
        //        q.result *= 2;
        //    }
        //});
    }

    ~DoubleAttackModifier2()
    {
        //conn.disconnect();
    }
};

