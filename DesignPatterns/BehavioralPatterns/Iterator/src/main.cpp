//The Iterator design pattern is omnipresent in C++ in both explicit and
//implicit(e.g., range - based) forms.Different types of iterators exist for
//iterating different objects : for example, reverse iterators might apply to a
//vector, but not to a singly linked list.
//Implementing your own iterator is as simple as providing the++ and
//!= operators.Most iterators are simply pointer fa?ades and are meant to be
//used to traverse the collection once before they are thrown away.
//Coroutines fix some of the issues present in iterators : they allow state
//to be preserved between calls—something that other languages(e.g., C#)
//have implemented a long time ago.As a consequence, coroutines allow us
//to write recursive algorithms


#include <iostream>
#include <string>

#include "BinaryTree.hpp"



int main()
{
    BinaryTree<std::string> family
    {
        new Node<std::string>
        {
            "me", 
            new Node<std::string>
            {
                "mother", 
                new Node<std::string>
                {
                    "mother's mother"
                },
                new Node<std::string>
                {
                    "mother's father"
                }
            },
            new Node<std::string>
            {
                "father"
            }
        }
    };

    for (auto it = family.begin(); it != family.end(); ++it)
    {
        std::cout << (*it).value << "\n";
    }

    //for (const auto& it : family.pre_order)
    //{
    //    std::cout << it.value << "\n";
    //}
}

