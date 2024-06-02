#include "TestData.h"


Person::Person(int age)
    : age{age}
{

}

void Person::SetAge(int age)
{
    if (this->age == age)
    {
        return;
    }

    this->age = age;
    Notify(*this, "age");
}

Creature::Creature(int age)
    : age{age}
{

}
