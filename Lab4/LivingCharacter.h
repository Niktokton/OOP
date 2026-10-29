#pragma once
#include "Character.h"

/**
 * @brief Класс, представляющий живого персонажа, у которого есть показатели здоровья и наносимого урона.
 * 
 * Наследуется от абстрактного класса Character и реализует базовую механику 
 * получения урона, проверки состояния жизни, а также нанесения урона другим целям.
 */
class LivingCharacter : public Character
{
protected:
    int health;       ///< Текущее здоровье персонажа
    int maxHealth;    ///< Максимальное здоровье персонажа
    int damageDealt;  ///< Суммарный урон, нанесенный этим персонажем за всё время

    /**
     * @brief Наносит урон указанной цели и обновляет статистику.
     * @param target Ссылка на целевого персонажа, которому наносится урон.
     * @param damage Количество наносимого урона.
     * @throw std::runtime_error если персонаж мертв и не может атаковать.
     * @throw std::invalid_argument если значение урона отрицательное.
     */
    void dealDamage(Character& target, int damage);

public:
    /**
     * @brief Конструктор класса LivingCharacter.
     * @param name Имя персонажа.
     * @param level Уровень персонажа.
     * @param maxHealth Максимальное здоровье (должно быть положительным).
     * @param health Текущее здоровье (в диапазоне от 0 до maxHealth).
     * @throw std::invalid_argument если maxHealth <= 0 или health выходит за допустимые пределы.
     */
    LivingCharacter(const std::string& name, int level, int maxHealth, int health);

    /**
     * @brief Конструктор копирования.
     * @param other Ссылка на копируемый объект LivingCharacter.
     */
    LivingCharacter(const LivingCharacter& other);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Ссылка на присваиваемый объект LivingCharacter.
     * @return Ссылка на текущий объект.
     */
    LivingCharacter& operator=(const LivingCharacter& other);

    /**
     * @brief Виртуальный деструктор.
     */
    ~LivingCharacter() override;

    /**
     * @brief Уменьшает текущее здоровье персонажа на величину полученного урона.
     * @param damage Количество получаемого урона.
     * @throw std::invalid_argument если передан отрицательный урон.
     */
    void takeDamage(int damage) override;

    /**
     * @brief Проверяет, жив ли персонаж (здоровье больше 0).
     * @return true, если персонаж жив, иначе false.
     */
    bool isAlive() const override;

    /**
     * @brief Выводит подробную информацию о живом персонаже в стандартный поток вывода.
     */
    void printInfo() const override;

    /**
     * @brief Возвращает текущее здоровье персонажа.
     * @return Значение текущего здоровья.
     */
    int getHealth() const;

    /**
     * @brief Возвращает максимальное здоровье персонажа.
     * @return Значение максимального здоровья.
     */
    int getMaxHealth() const;

    /**
     * @brief Возвращает суммарный урон, нанесенный данным персонажем.
     * @return Общее количество нанесенного урона.
     */
    int getDamageDealt() const;
};