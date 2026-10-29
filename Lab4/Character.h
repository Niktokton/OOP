#pragma once
#include <string>

/**
 * @brief Абстрактный базовый класс, представляющий персонажа в игре.
 * 
 * Содержит базовые характеристики персонажа (имя, уровень), 
 * а также общую статическую статистику по нанесенному урону.
 */
class Character
{
private:
    std::string name;        ///< Имя персонажа
    int level;               ///< Уровень персонажа

    static int totalDamage;      ///< Суммарный урон, нанесенный всеми персонажами
    static int topDamage;        ///< Наибольший одиночный урон, нанесенный за всё время
    static std::string topDamageDealer; ///< Имя персонажа, нанесшего наибольший урон

protected:
    /**
     * @brief Регистрирует нанесенный урон для обновления общей статистики.
     * @param damage Количество нанесенного урона.
     */
    void registerDamage(int damage);

public:
    /**
     * @brief Конструктор класса Character.
     * @param name Имя персонажа (не может быть пустым).
     * @param level Уровень персонажа (должен быть положительным).
     * @throw std::invalid_argument если имя пустое или уровень меньше 1.
     */
    Character(const std::string& name, int level);

    /**
     * @brief Конструктор копирования.
     * @param other Ссылка на копируемый объект Character.
     */
    Character(const Character& other);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Ссылка на присваиваемый объект Character.
     * @return Ссылка на текущий объект.
     */
    Character& operator=(const Character& other);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Character();

    /**
     * @brief Возвращает имя персонажа.
     * @return Строка с именем персонажа.
     */
    std::string getName() const;

    /**
     * @brief Возвращает уровень персонажа.
     * @return Уровень персонажа (целое число).
     */
    int getLevel() const;

    /**
     * @brief Чисто виртуальная функция атаки другой цели.
     * @param target Ссылка на целевого персонажа.
     */
    virtual void attack(Character& target) = 0;

    /**
     * @brief Чисто виртуальная функция получения урона.
     * @param damage Количество получаемого урона.
     */
    virtual void takeDamage(int damage) = 0;

    /**
     * @brief Проверяет, жив ли персонаж.
     * @return true, если персонаж жив, иначе false.
     */
    virtual bool isAlive() const = 0;

    /**
     * @brief Выводит подробную информацию о персонаже.
     */
    virtual void printInfo() const = 0;

    /**
     * @brief Возвращает суммарный урон, нанесенный всеми персонажами.
     * @return Общий урон (статическое поле).
     */
    static int getTotalDamage();

    /**
     * @brief Возвращает имя персонажа, нанесшего наибольший урон.
     * @return Имя рекордсмена по урону.
     */
    static std::string getTopDamageDealer();

    /**
     * @brief Перегрузка оператора вывода в поток для класса Character.
     * @param out Поток вывода.
     * @param character Персонаж для вывода.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& out, const Character& character);
};