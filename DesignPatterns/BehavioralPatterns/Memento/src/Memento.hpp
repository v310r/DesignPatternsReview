#pragma once

#include <vector>
#include <memory>


class Memento
{
public:
    Memento(int balance) : balance(balance)
    {

    }

    friend class BankAccount;
    friend class BankAccount2;

private:
    int balance;
};

class BankAccount
{
public:
    explicit BankAccount(int balance) : balance(balance)
    {

    }

    friend std::ostream& operator<<(std::ostream& out, const BankAccount& ba)
    {
        out << ba.balance;
        return out;
    }

    Memento deposit(int amount)
    {
        balance += amount;
        return {balance};
    }

    void restore(const Memento& m)
    {
        balance = m.balance;
    }

private:
    int balance = 0;
};


// undo/redo functionality
class BankAccount2
{
public:
    explicit BankAccount2(int balance) : balance(balance)
    {
        changes.emplace_back(std::make_shared<Memento>(balance));
    }

    std::shared_ptr<Memento> deposit(int amount)
    {
        balance += amount;
        auto m = std::make_shared<Memento>(balance);
        changes.emplace_back(m);
        ++current;
        return m;
    }

    void restore(const std::shared_ptr<Memento>& m)
    {
        if (m)
        {
            balance = m->balance;
            changes.emplace_back(m);
            current = changes.size() - 1;
        }
    }

    std::shared_ptr<Memento> undo()
    {
        if (current > 0)
        {
            --current;
            auto m = changes[current];
            balance = m->balance;
            return m;
        }

        return {};
    }

    std::shared_ptr<Memento> redo()
    {
        if (current + 1 < changes.size())
        {
            ++current;
            auto m = changes[current];
            balance = m->balance;
            return m;
        }

        return {};
    }

    friend std::ostream& operator<<(std::ostream& out, const BankAccount2& ba)
    {
        out << ba.balance;
        return out;
    }

private:
    int balance = 0;

    std::vector<std::shared_ptr<Memento>> changes;
    int current = 0;

};