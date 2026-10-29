#pragma once
#include "LivingCharacter.h"

/**
 * @brief Класс, представляющий мага — персонажа дальнего боя, использующего магическую энергию.
 * 
 * Наследуется виртуально от LivingCharacter и добавляет характеристики маны (@p mana) 
 * и интеллекта (@p intelligence), который определяет наносимый урон заклинаниями.
 */
class Mage : virtual public LivingCharacter
{
protected:
    int mana;         ///< Количество текущей маны у мага
    int intelligence; ///< Показатель интеллекта, определяющий силу магической атаки

public:
    /**
     * @brief Конструктор класса Mage.
     * @param name Имя персонажа.
     * @param level Уровень персонажа.
     * @param maxHealth Максимальное здоровье.
     * @param health Текущее здоровье.
     * @param mana Количество маны (не может быть отрицательным).
     * @param intelligence Показатель интеллекта (не может быть отрицательным).
     * @throw std::invalid_argument если мана или интеллект меньше 0.
     */
    Mage(const std::string& name, int level, int maxHealth, int health, int mana, int intelligence);

    /**
     * @brief Конструктор копирования.
     * @param other Ссылка на копируемый объект Mage.
     */
    Mage(const Mage& other);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Ссылка на присваиваемый объект Mage.
     * @return Ссылка на текущий объект.
     */
    Mage& operator=(const Mage& other);

    /**
     * @brief Виртуальный деструктор.
     */
    ~Mage() override;

    /**
     * @brief Выполняет магическую атаку цели, расходуя ману и нанося урон на основе интеллекта.
     * @param target Ссылка на целевого персонажа.
     * @throw std::runtime_error если у мага недостаточно маны (меньше 5) или если он мертв.
     */
    void attack(Character& target) override;

    /**
     * @brief Выводит подробную информацию о маге в стандартный поток вывода.
     */
    void printInfo() const override;

    /**
     * @brief Возвращает текущее количество маны мага.
     * @return Значение маны.
     */
    int getMana() const;

    /**
     * @brief Возвращает показатель интеллекта мага.
     * @return Значение интеллекта.
     */
    int getIntelligence() const;
};