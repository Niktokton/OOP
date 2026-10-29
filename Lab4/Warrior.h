#pragma once
#include "LivingCharacter.h"

/**
 * @brief Класс, представляющий воина — боевого персонажа ближнего боя.
 * 
 * Наследуется виртуально от LivingCharacter и добавляет характеристику силы (@p strength), 
 * которая определяет наносимый урон при атаке.
 */
class Warrior : virtual public LivingCharacter
{
protected:
    int strength; ///< Показатель силы воина, определяющий урон

public:
    /**
     * @brief Конструктор класса Warrior.
     * @param name Имя персонажа.
     * @param level Уровень персонажа.
     * @param maxHealth Максимальное здоровье.
     * @param health Текущее здоровье.
     * @param strength Сила воина (не может быть отрицательной).
     * @throw std::invalid_argument если сила (@p strength) меньше 0.
     */
    Warrior(const std::string& name, int level, int maxHealth, int health, int strength);

    /**
     * @brief Конструктор копирования.
     * @param other Ссылка на копируемый объект Warrior.
     */
    Warrior(const Warrior& other);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Ссылка на присваиваемый объект Warrior.
     * @return Ссылка на текущий объект.
     */
    Warrior& operator=(const Warrior& other);

    /**
     * @brief Виртуальный деструктор.
     */
    ~Warrior() override;

    /**
     * @brief Выполняет атаку целевого персонажа, нанося урон на основе силы (@p strength).
     * @param target Ссылка на целевого персонажа.
     * @throw std::runtime_error если воин мертв.
     */
    void attack(Character& target) override;

    /**
     * @brief Выводит подробную информацию о воине в стандартный поток вывода.
     */
    void printInfo() const override;

    /**
     * @brief Возвращает показатель силы воина.
     * @return Значение силы.
     */
    int getStrength() const;
};