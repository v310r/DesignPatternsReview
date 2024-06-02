#pragma once

#include <iostream>

struct Foo;
struct Bar;

void func(Foo* foo)
{
    std::cout << "func(Foo* foo)" << std::endl;
}

void func(Bar* bar)
{
    std::cout << "func(Bar* bar)" << std::endl;
}

struct Stuff 
{
    virtual void call() = 0;
};

struct Foo : Stuff 
{
    void call() override
    {
        func(this);
    }
};

struct Bar : Stuff 
{
    void call() override
    {
        func(this);
    }
};
