#pragma once
#include "LivingCharacter.h"

class Mage : virtual public LivingCharacter
{
    protected:
        int mana;
        int intelligence;

    public:
        Mage(const std::string& name, int level, int maxHealth, int health, int mana, int intelligence);

        Mage(const Mage& other);

        Mage& operator=(const Mage& other);

        ~Mage() override;

        void attack(Character& target) override;

        void printInfo() const override;

        int getMana() const;

        int getIntelligence() const;
};
