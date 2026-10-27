#pragma once
#include <string>

class Character
{
    private:
        std::string name;
        int level;

        static int totalDamage;
        static int topDamage;
        static std::string topDamageDealer;

    protected:
        void registerDamage(int damage);

    public:
        Character(const std::string& name, int level);

        Character(const Character& other);

        Character& operator=(const Character& other);

        virtual ~Character();

        std::string getName() const;

        int getLevel() const;

        virtual void attack(Character& target) = 0;

        virtual void takeDamage(int damage) = 0;

        virtual bool isAlive() const = 0;

        virtual void printInfo() const = 0;

        static int getTotalDamage();

        static std::string getTopDamageDealer();

        friend std::ostream& operator<<(std::ostream& out, const Character& character);
};
