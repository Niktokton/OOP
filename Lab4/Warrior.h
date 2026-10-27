#pragma once
#include "LivingCharacter.h"

class Warrior : virtual public LivingCharacter
{
    protected:
        int strength;

    public:
        Warrior(const std::string& name, int level, int maxHealth, int health, int strength);

        Warrior(const Warrior& other);

        Warrior& operator=(const Warrior& other);

        ~Warrior() override;

        void attack(Character& target) override;

        void printInfo() const override;

        int getStrength() const;
};
