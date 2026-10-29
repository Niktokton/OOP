#pragma once
#include "Warrior.h"
#include "Mage.h"

/**
 * @brief Класс, представляющий боевого мага (Battlemage) — гибридного персонажа.
 * 
 * Сочетает в себе черты воина и мага (множественное виртуальное наследование от LivingCharacter), 
 * используя как физическую силу, так и магию для усиленной атаки.
 */
class Battlemage : public Warrior, public Mage
{
public:
    /**
     * @brief Конструктор класса Battlemage.
     * @param name Имя персонажа.
     * @param level Уровень персонажа.
     * @param maxHealth Максимальное здоровье.
     * @param health Текущее здоровье.
     * @param strength Сила боевого мага.
     * @param mana Количество маны.
     * @param intelligence Показатель интеллекта.
     * @throw std::invalid_argument передается в конструкторы базовых классов при некорректных параметрах.
     */
    Battlemage(const std::string& name, int level, int maxHealth, int health, int strength, int mana, int intelligence);

    /**
     * @brief Конструктор копирования.
     * @param other Ссылка на копируемый объект Battlemage.
     */
    Battlemage(const Battlemage& other);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Ссылка на присваиваемый объект Battlemage.
     * @return Ссылка на текущий объект.
     */
    Battlemage& operator=(const Battlemage& other);

    /**
     * @brief Виртуальный деструктор.
     */
    ~Battlemage() override;

    /**
     * @brief Выполняет смешанную атаку цели (сила + интеллект), расходуя ману.
     * @param target Ссылка на целевого персонажа.
     * @throw std::runtime_error если у боевого мага недостаточно маны (меньше 5) или если он мертв.
     */
    void attack(Character& target) override;

    /**
     * @brief Выводит подробную информацию о боевом маге в стандартный поток вывода.
     */
    void printInfo() const override;
};