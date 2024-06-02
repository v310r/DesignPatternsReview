#pragma once

#include <vector>
#include <string>
#include <mutex>

#include "TestData.h"


template<typename T>
struct Observer
{
    virtual void FieldChanged(T& source, const std::string& fieldName) = 0;
};

template<typename T>
struct Observable
{
    std::mutex mtx;

    void Notify(T& source, const std::string& name)
    {
        // reentrancy problem - similar to deadlock, but when the same thread block itself
        //std::scoped_lock<std::mutex> lock {mtx};
        for (auto obs : observers)
        {
            obs->FieldChanged(source, name);
        }
    }

    void Subscribe(Observer<T>* f)
    {
        // reentrancy problem - similar to deadlock, but when the same thread block itself
        //std::scoped_lock<std::mutex> lock{ mtx };
        observers.emplace_back(f);
    }

    void Unsubscribe(Observer<T>* observer)
    {
        // reentrancy problem - similar to deadlock, but when the same thread block itself
        //std::scoped_lock<std::mutex> lock{ mtx };
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

private:
    std::vector<Observer<T>*> observers;
};
