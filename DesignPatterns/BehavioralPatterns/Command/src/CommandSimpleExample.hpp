#pragma once

#include <iostream>


struct BankAccountCommand;

class BankAccount
{
    friend struct BankAccountCommand;

protected:
    void deposit(int amount)
    {
        balance += amount;
        std::cout << "deposited " << amount << ", balance is now " << balance << "\n";
    }

    bool withdraw(int amount)
    {
        if (balance - amount >= overdraft_limit)
        {
            balance -= amount;
            std::cout << "withdrew " << amount << ", balance is now " << balance << "\n";
            return true;
        }

        return false;
    }

    int balance = 0;
    int overdraft_limit = -500;
};

struct ICommand
{
    virtual void call() = 0;

    // might be better to move to another interface
    // basically create Callable command interface and Undoable Command interface
    virtual void undo() = 0;


    bool bSucceeded = false;
};

struct BankAccountCommand : public ICommand
{
    enum EAction
    {
        deposit,
        withdraw
    };

    BankAccountCommand(BankAccount& account, EAction action, int amount)
        : account(account), action(action), amount(amount)
    {

    }

    virtual void call() override
    {
        switch (action)
        {
        case deposit:
        {
            account.deposit(amount);
            break;
        }
        case withdraw:
        {
            bSucceeded = account.withdraw(amount);
            break;
        }
        }
    }

    virtual void undo() override
    {
        switch (action)
        {
        case deposit:
        {
            account.withdraw(amount);
            break;
        }
        case withdraw:
        {
            if (bSucceeded)
            {
                account.deposit(amount);
            }

            break;
        }
        }
    }

    EAction action;

    BankAccount& account;

    int amount;
};
