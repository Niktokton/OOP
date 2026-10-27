#include "Character.h"
#include <iostream>
#include <stdexcept>

int Character::totalDamage = 0;
int Character::topDamage = 0;
std::string Character::topDamageDealer = "None";

Character::Character(const std::string& name, int level)
    : name(name), level(level)
{
    if (name.empty())
        throw std::invalid_argument("Character name cannot be empty.");

    if (level < 1)
        throw std::invalid_argument("Character level must be positive.");
}

Character::Character(const Character& other)
    : name(other.name), level(other.level)
{
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        level = other.level;
    }

    return *this;
}

Character::~Character()
{
}

std::string Character::getName() const
{
    return name;
}

int Character::getLevel() const
{
    return level;
}

void Character::registerDamage(int damage)
{
    if (damage <= 0)
        return;

    totalDamage += damage;

    if (damage > topDamage)
    {
        topDamage = damage;
        topDamageDealer = name;
    }
}

int Character::getTotalDamage()
{
    return totalDamage;
}

std::string Character::getTopDamageDealer()
{
    return topDamageDealer;
}

std::ostream& operator<<(std::ostream& out, const Character& character)
{
    out << character.name << " | level: " << character.level;
    return out;
}
