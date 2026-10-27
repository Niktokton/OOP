#include "Warrior.h"
#include <iostream>
#include <stdexcept>

Warrior::Warrior(const std::string& name, int level, int maxHealth, int health, int strength)
    : LivingCharacter(name, level, maxHealth, health), strength(strength)
{
    if (strength < 0)
        throw std::invalid_argument("Strength cannot be negative.");
}

Warrior::Warrior(const Warrior& other)
    : LivingCharacter(other), strength(other.strength)
{
}

Warrior& Warrior::operator=(const Warrior& other)
{
    if (this != &other)
    {
        LivingCharacter::operator=(other);
        strength = other.strength;
    }

    return *this;
}

Warrior::~Warrior()
{
    std::cout << "Character " << getName() << " with class Warrior has been destroyed" << std::endl;
}

void Warrior::attack(Character& target)
{
    dealDamage(target, strength);
}

void Warrior::printInfo() const
{
    LivingCharacter::printInfo();
    std::cout << " | type: Warrior | strength: " << strength << '\n';
}

int Warrior::getStrength() const
{
    return strength;
}
