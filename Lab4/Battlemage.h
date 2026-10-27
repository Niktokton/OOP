#pragma once
#include "Warrior.h"
#include "Mage.h"

class Battlemage : public Warrior, public Mage
{
    public:
        Battlemage(const std::string& name, int level, int maxHealth, int health, int strength, int mana, int intelligence);

        Battlemage(const Battlemage& other);

        Battlemage& operator=(const Battlemage& other);

        ~Battlemage() override;

        void attack(Character& target) override;

        void printInfo() const override;
};
