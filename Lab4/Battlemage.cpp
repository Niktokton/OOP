#include "Battlemage.h"
#include <iostream>
#include <stdexcept>

Battlemage::Battlemage(const std::string& name, int level, int maxHealth, int health, int strength, int mana, int intelligence)
    : LivingCharacter(name, level, maxHealth, health),
      Warrior(name, level, maxHealth, health, strength),
      Mage(name, level, maxHealth, health, mana, intelligence)
{
}

Battlemage::Battlemage(const Battlemage& other)
    : LivingCharacter(other), Warrior(other), Mage(other)
{
}

Battlemage& Battlemage::operator=(const Battlemage& other)
{
    if (this != &other)
    {
        LivingCharacter::operator=(other);
        strength = other.strength;
        mana = other.mana;
        intelligence = other.intelligence;
    }

    return *this;
}

Battlemage::~Battlemage()
{
    std::cout << "Character " << getName() << " with class Battlemage has been destroyed" << std::endl;
}

void Battlemage::attack(Character& target)
{
    if (mana < 5)
        throw std::runtime_error(getName() + " does not have enough mana.");

    int damage = strength + intelligence;
    mana -= 5;
    dealDamage(target, damage);
}

void Battlemage::printInfo() const
{
    LivingCharacter::printInfo();
    std::cout << " | type: Battlemage | strength: " << strength << " | mana: " << mana << " | intelligence: " << intelligence << '\n';
}
