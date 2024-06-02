#pragma once

#include <iostream>
#include <string>
#include <memory>


struct ILogger
{
    virtual ~ILogger() = default;

    virtual void info(const std::string& s) = 0;

    virtual void warn(const std::string& s) = 0;
};

struct BankAccount
{
    //BankAccount(const std::string& name, int balance, const std::shared_ptr<ILogger>& logger = noLogging)
    //    : logger{ std::make_shared<OptionalLogger>(logger) }, name{ name }, balance{ balance }
    //{

    //}

    BankAccount(const std::shared_ptr<ILogger>& logger, const std::string& name, int balance)
        : logger{ logger }, name{ name }, balance{ balance }
    {

    }

    void deposit(int amount)
    {
        balance += amount;
        logger->info("Deposited $" + std::to_string(amount) + " to " + name + ", balance is now $" + std::to_string(balance));
    }

    std::shared_ptr<ILogger> logger;

    std::string name;

    int balance = 0;
};

struct ConsoleLogger : ILogger
{
    virtual void info(const std::string& s) override
    {
        std::cout << "INFO: " << s << std::endl;
    }

    virtual void warn(const std::string& s) override
    {
        std::cout << "WARNING!!! " << s << std::endl;
    }
};

struct NullLogger : ILogger
{
    virtual void info(const std::string& s) override
    {

    }

    virtual void warn(const std::string& s) override
    {

    }
};

struct OptionalLogger : ILogger
{
    OptionalLogger(const std::shared_ptr<ILogger>& logger) :impl{ logger }
    {

    }

    virtual void info(const std::string& s) override
    {
        if (impl)
        {
            impl->info(s);
        }
    }

    virtual void warn(const std::string& s) override
    {
        if (impl)
        {
            impl->warn(s);
        }
    }

    std::shared_ptr<ILogger> impl;

    static std::shared_ptr<ILogger> noLogging;

};

std::shared_ptr<ILogger> OptionalLogger::noLogging{};

