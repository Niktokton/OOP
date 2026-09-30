#include "GameCharacter.h"


int GameCharacter::objectCount = 0;

GameCharacter::GameCharacter()
    : name("Anon"),
      level(1),
      CurrentHealth(100),
      MaxHealith(100),
      experience(0.0),
      alive(true),
      stats(10, 10, 10, 10, 10, 10, 10, 10)
{
    ++objectCount;
}

GameCharacter::GameCharacter(const std::string& name, int level, int MaxHealth, double experience, const CharacterStats& stats)()
    : name(name),
      level(level),
      CurrentHealth(MaxHealth),
      MaxHealith(MaxHealth),
      experience(experience),
      alive(true),
      stats(stats)
{
    if (name.empty())
        throw std::invalid_argument("Name cannot be empty");

    if (level < 1)
        throw std::invalid_argument("Level must be at least 1");

    if (maxHealth <= 0)
        throw std::invalid_argument("Max health must be greater than 0");

    if (experience < 0.0)
        throw std::invalid_argument("Experience must be at lest 0");

    if (stats.vitality < 0 ||
        stats.attunement < 0 ||
        stats.endurance < 0 ||
        stats.strength < 0 ||
        stats.dexterity < 0 ||
        stats.resistance < 0 ||
        stats.intelligence < 0 ||
        stats.faith < 0)
    {
        throw std::invalid_argument("Character stats cannot be negative");
    }

    ++objectCount;
}


GameCharacter::GameCharacter(const GameCharacter& other)
    : name(other.name),
      level(other.level),
      CurrentHealth(other.health),
      MaxHealith(other.maxHealth),
      experience(other.experience),
      alive(other.alive),
      stats(other.stats)
{
    ++objectCount;
}

GameCharacter::~GameCharacter()
{
    --objectCount;

    std::cout << "Character " << name << " has been destroyed." << std::endl;
}

std::string GameCharacter::getName() const
{
    return name;
}

int GameCharacter::getLevel() const
{
    return level;
}

int GameCharacter::getHealth() const
{
    return health;
}

int GameCharacter::getMaxHealth() const
{
    return maxHealth;
}

double GameCharacter::getExperience() const
{
    return experience;
}

bool GameCharacter::isAlive() const
{
    return alive;
}

CharacterStats GameCharacter::getStats() const
{
    return stats;
}

void GameCharacter::takeDamage(int damage)
{
    if (damage < 0)
        throw std::invalid_argument("Damage must at least 0");

    if (!alive)
        throw std::logic_error("Character is already dead");

    health -= damage;

    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}

void GameCharacter::heal(int amount)
{
    if (amount <= 0)
        throw std::invalid_argument("Heal amount must be at least 0");

    if (!alive)
        throw std::logic_error("Dead character cannot be healed");

    health += amount;

    if (health > maxHealth)
        health = maxHealth;
}

void GameCharacter::gainExperience(double amount)
{
    if (amount <= 0)
        throw std::invalid_argument("Experience amount must be greater than 0");

    experience += amount;

    while (experience >= 100.0)
    {
        experience -= 100.0;
        ++level;
        maxHealth += 10;
        health = maxHealth;
    }
}

void increaseVitality(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Vitality increase must be greater than 0"
        );

    stats.vitality += amount;
}

void increaseAttunement(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Attunement increase must be greater than 0"
        );

    stats.attunement += amount;
}

void increaseEndurance(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Endurance increase must be greater than 0"
        );

    stats.endurance += amount;
}

void increaseStrength(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Strength increase must be greater than 0"
        );

    stats.strength += amount;
}

void increaseDexterity(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Dexterity increase must be greater than 0"
        );

    stats.dexterity += amount;
}

void increaseResistance(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Resistance increase must be greater than 0"
        );

    stats.resistance += amount;
}

void increaseIntelligence(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Intelligence increase must be greater than 0"
        );

    stats.intelligence += amount;
}

void increaseFaith(int amount);
{
    if (amount <= 0)
        throw std::invalid_argument(
            "Faith increase must be greater than 0"
        );

    stats.faith += amount;
}

void GameCharacter::printInfo() const
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << "/" << maxHealth << std::endl;
    std::cout << "Experience: " << experience << std::endl;
    std::cout << "Alive: " << (alive ? "yes" : "no") << std::endl;
    std::cout << "Stats:" << std::endl;
    std::cout << "  Vitality: " << stats.vitality << std::endl;
    std::cout << "  Attunement: " << stats.attunement << std::endl;
    std::cout << "  Endurance: " << stats.endurance << std::endl;
    std::cout << "  Strength: " << stats.strength << std::endl;
    std::cout << "  Dexterity: " << stats.dexterity << std::endl;
    std::cout << "  Resistance: " << stats.resistance << std::endl;
    std::cout << "  Intelligence: " << stats.intelligence << std::endl;
    std::cout << "  Faith: " << stats.faith << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int GameCharacter::getObjectCount()
{
    return objectCount;
}