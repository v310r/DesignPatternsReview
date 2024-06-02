
#include <iostream>

#include "Memento.hpp"


void memento()
{
    BankAccount ba{100};
    auto m1 = ba.deposit(50);
    auto m2 = ba.deposit(25);

    std::cout << ba << "\n"; // Balance: 175;

    ba.restore(m1);
    std::cout << ba << "\n"; // Balance: 150;

    ba.restore(m2);
    std::cout << ba << "\n"; // Balance: 175;
}


int main()
{
    memento();

    std::cout << "\n" << "undo/redo" << "\n";

    BankAccount2 ba{ 100 };
    ba.deposit(50);
    ba.deposit(25); // 175
    std::cout << ba << "\n";
    
    ba.undo();
    std::cout << "Undo 1: " << ba << "\n"; // Undo 1: 150
    ba.undo();
    std::cout << "Undo 2: " << ba << "\n"; // Undo 2: 100
    ba.redo();
    std::cout << "Redo 2: " << ba << "\n"; // Redo 2: 150
    ba.undo(); // back to 100 again
    std::cout << "Undo 3: " << ba << "\n";
}

