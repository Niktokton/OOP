#pragma once
#include "Character.h"

class LivingCharacter : public Character
{
    protected:
        int health;
        int maxHealth;
        int damageDealt;

        void dealDamage(Character& target, int damage);

    public:
        LivingCharacter(const std::string& name, int level, int maxHealth, int health);

        LivingCharacter(const LivingCharacter& other);

        LivingCharacter& operator=(const LivingCharacter& other);

        ~LivingCharacter() override;

        void takeDamage(int damage) override;

        bool isAlive() const override;

        void printInfo() const override;

        int getHealth() const;

        int getMaxHealth() const;

        int getDamageDealt() const;
};
