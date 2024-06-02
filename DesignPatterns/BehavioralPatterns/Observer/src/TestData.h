#pragma once

#include "PropertyObserver.h"

#include <iostream>


struct Person : Observable<Person>
{
    Person(int age);

    void SetAge(int age);

    int age;
};

struct Creature
{
    Creature(int age);

    int age;
};

struct ConsolePersonObserver : Observer<Person>
{
    virtual void FieldChanged(Person& source, const std::string& fieldName) override
    {
        std::cout << "Person's " << fieldName << " has changed to " << source.age << ",\n";
    }
};

struct ConsolePersonObserver2 : public Observer<Person>, public Observer<Creature>
{
    virtual void FieldChanged(Person& source, const std::string& fieldName) override
    {
        std::cout << "Person's " << fieldName << " has changed to " << source.age << ",\n";
    }

    virtual void FieldChanged(Creature& source, const std::string& fieldName) override
    {
        std::cout << "Creature's " << fieldName << " has changed to " << source.age << ",\n";
    }
};
