#include "Mage.h"
#include <iostream>
#include <stdexcept>

Mage::Mage(const std::string& name, int level, int maxHealth, int health, int mana, int intelligence)
    : LivingCharacter(name, level, maxHealth, health), mana(mana), intelligence(intelligence)
{
    if (mana < 0 || intelligence < 0)
        throw std::invalid_argument("Mana and intelligence cannot be negative.");
}

Mage::Mage(const Mage& other)
    : LivingCharacter(other), mana(other.mana), intelligence(other.intelligence)
{
}

Mage& Mage::operator=(const Mage& other)
{
    if (this != &other)
    {
        LivingCharacter::operator=(other);
        mana = other.mana;
        intelligence = other.intelligence;
    }

    return *this;
}

Mage::~Mage()
{
    std::cout << "Character " << getName() << " with class Mage has been destroyed" << std::endl;
}

void Mage::attack(Character& target)
{
    if (mana < 5)
        throw std::runtime_error(getName() + " does not have enough mana.");

    int damage = intelligence;
    mana -= 5;
    dealDamage(target, damage);
}

void Mage::printInfo() const
{
    LivingCharacter::printInfo();
    std::cout << " | type: Mage | mana: " << mana << " | intelligence: " << intelligence << '\n';
}

int Mage::getMana() const
{
    return mana;
}

int Mage::getIntelligence() const
{
    return intelligence;
}
