#pragma once


class Game
{

public:

    explicit Game(int numberOfPlayers) : numberOfPlayers(numberOfPlayers)
    {

    }

    void run()
    {
        start();

        while (!haveWinner())
        {
            takeTurn();
        }

        std::cout << "Player " << getWinner() << " wins.\n";
    }

protected:
    virtual bool haveWinner() = 0;

    virtual void start() = 0;

    virtual void takeTurn() = 0;

    virtual int getWinner() = 0;

    int currentPlayer = 0;

    int numberOfPlayers;
};

class Chess : public Game 
{
public:
    explicit Chess() : Game(2)
    {

    }

protected:
    virtual void start() override
    {

    }

    virtual bool haveWinner() override
    {
        return turns == maxTurns;
    }

    virtual void takeTurn()
    {
        ++turns;
        currentPlayer = (currentPlayer + 1) % numberOfPlayers;
    }

    virtual int getWinner()
    {
        return currentPlayer;
    }

private:
    int turns = 0, maxTurns = 0;
};