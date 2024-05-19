#pragma once

#include <functional>
#include <string>


template <typename R, typename... Args>
struct Logger3 //<R(Args...)>
{
    Logger3(std::function<R(Args...)> func, const std::string& name)
        : func{ func }, name{ name }
    {

    }

    R operator() (Args ...args)
    {
        std::cout << "Entering " << name << std::endl;
        R result = func(args...);
        std::cout << "Exiting " << name << std::endl;
        return result;
    }

    std::function<R(Args ...)> func;
    std::string name;
};

template <typename R, typename... Args>
auto make_logger3(R(*func)(Args...), const std::string& name)
{
    return Logger3<R(Args...)>(std::function<R(Args...)>(func), name);
}