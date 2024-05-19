#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

#include "CommandSimpleExample.hpp"


struct CompositeBankAccountCommand : public std::vector<BankAccountCommand>, public ICommand
{
    CompositeBankAccountCommand(const std::initializer_list<value_type>& items)
        :std::vector<BankAccountCommand>(items)
    {

    }

    virtual void call() override
    {
        bool bOk = true;
        for (auto& cmd : *this)
        {
            if (bOk)
            {
                cmd.call();
                bOk = cmd.bSucceeded;
            }
            else
            {
                cmd.bSucceeded = false;
            }
        }
    }

    virtual void undo() override
    {
        for (auto it = rbegin(); it != rend(); ++it)
        {
            it->undo();
        }
    }
    
};

struct MoneyTransferCommand : public CompositeBankAccountCommand
{
    MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount)
        : CompositeBankAccountCommand
          {
            BankAccountCommand{from, BankAccountCommand::withdraw, amount},
            BankAccountCommand{to, BankAccountCommand::deposit, amount}
          }
    {

    }
};
