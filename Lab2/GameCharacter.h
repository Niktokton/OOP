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
};