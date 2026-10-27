#include "Warrior.h"
#include "Mage.h"
#include <iostream>
#include <string>

int main()
{
    Warrior original("TestWarrior", 2, 100, 100, 12);
    Warrior copy(original);
    original.printInfo();
    copy.printInfo();

    original.takeDamage(40);
    std::cout << "Original health after damage: " << original.getHealth() << '\n';
    std::cout << "Copy health: " << copy.getHealth() << '\n';

    std::cout << "\nFIGHT TEST\n";
    std::cout << "Before fight:\n";
    Mage gandalf("Gandalf", 1000, 8000, 8000, 10000, 1000);
    gandalf.printInfo();
    Warrior balrog("Balrog", 1000, 10000, 10000, 1500);
    balrog.printInfo();
    gandalf.attack(balrog);
    balrog.attack(gandalf);
    std::cout << "After fight:\n";
    gandalf.printInfo();
    balrog.printInfo();

    std::cout << "\n";
    return 0;
}
