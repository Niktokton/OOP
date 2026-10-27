#include "LivingCharacter.h"
#include <iostream>
#include <stdexcept>

LivingCharacter::LivingCharacter(const std::string& name, int level, int maxHealth, int health)
    : Character(name, level), health(health), maxHealth(maxHealth), damageDealt(0)
{
    if (maxHealth <= 0)
        throw std::invalid_argument("Maximum health must be positive.");

    if (health < 0 || health > maxHealth)
        throw std::invalid_argument("Health must be between zero and maximum health.");
}

LivingCharacter::LivingCharacter(const LivingCharacter& other)
    : Character(other), health(other.health), maxHealth(other.maxHealth),
      damageDealt(other.damageDealt)
{
}

LivingCharacter& LivingCharacter::operator=(const LivingCharacter& other)
{
    if (this != &other)
    {
        Character::operator=(other);
        health = other.health;
        maxHealth = other.maxHealth;
        damageDealt = other.damageDealt;
    }

    return *this;
}

LivingCharacter::~LivingCharacter()
{
}

void LivingCharacter::takeDamage(int damage)
{
    if (damage < 0)
        throw std::invalid_argument("Damage cannot be negative.");

    health -= damage;

    if (health < 0)
        health = 0;
}

bool LivingCharacter::isAlive() const
{
    return health > 0;
}

void LivingCharacter::printInfo() const
{
    std::cout << getName() << " | level: " << getLevel() << " | health: " << health << "/" << maxHealth << " | damage dealt: " << damageDealt;
}

int LivingCharacter::getHealth() const
{
    return health;
}

int LivingCharacter::getMaxHealth() const
{
    return maxHealth;
}

int LivingCharacter::getDamageDealt() const
{
    return damageDealt;
}

void LivingCharacter::dealDamage(Character& target, int damage)
{
    if (!isAlive())
        throw std::runtime_error(getName() + " cannot attack because they are defeated.");

    if (damage < 0)
        throw std::invalid_argument("Damage cannot be negative.");

    target.takeDamage(damage);
    damageDealt += damage;
    registerDamage(damage);
}
