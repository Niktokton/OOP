#pragma once
#include <string>

struct CharacterStats
{
    int vitality;
    int attunement;
    int endurance;
    int strength;
    int dexterity;
    int resistance;
    int intelligence;
    int faith;
};

class GameCharacter
{
    private:
        std::string name;
        int level;
        int CurrentHealth;
        int MaxHealith;
        double expirience;
        bool IsAlive;
        CharacterStats stats;
        static int objectCount;
    
    public:
    GameCharacter();

    GameCharacter(const std::string& name, int level, int MaxHealth, double experience, const CharacterStats& stats);

    GameCharacter(const GameCharacter& other);

    ~GameCharacter();

    std::string getName() const;
    int getLevel() const;
    int getCurrentHealth() const;
    int getMaxHealth() const;
    double getExperience() const;
    bool isAlive() const;
    CharacterStats getStats() const;

    void takeDamage(int damage);
    void heal(int amount);
    void gainExperience(double amount);

    void increaseStrength(int amount);
    void increaseVitality(int amount);
    void increaseAttunement(int amount);
    void increaseEendurance(int amount);
    void increaseStrength(int amount);
    void increaseDexterity(int amount);
    void increaseResistance(int amount);
    void increaseIntelligence(int amount);
    void increaseFaith(int amount);

    void printInfo() const;

    static int getObjectCount();
};