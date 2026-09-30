#pragma once
#include <string>

/**
 * @brief Набор характеристик игрового персонажа.
 *
 * Структура, содержащая основные характеристики персонажа.
 */
struct CharacterStats
{
    int vitality;       ///< Живучесть персонажа.
    int attunement;    ///< Настройка / концентрация персонажа.
    int endurance;      ///< Выносливость персонажа.
    int strength;       ///< Сила персонажа.
    int dexterity;     ///< Ловкость персонажа.
    int resistance;    ///< Сопротивление персонажа.
    int intelligence;  ///< Интеллект персонажа.
    int faith;         ///< Вера персонажа.
};


/**
 * @brief Класс, представляющий игрового персонажа.
 *
 * GameCharacter хранит основную информацию о персонаже:
 * имя, уровень, здоровье, опыт и характеристики.
 *
 * Класс предоставляет методы для изменения здоровья,
 * получения опыта и увеличения характеристик.
 *
 * Также класс ведёт статический счётчик количества
 * существующих объектов GameCharacter.
 */
class GameCharacter
{
    private:
        std::string name;       ///< Имя персонажа.
        int level;              ///< Текущий уровень персонажа.
        int CurrentHealth;      ///< Текущее количество здоровья.
        int MaxHealth;          ///< Максимальное количество здоровья.
        double experience;      ///< Текущее количество опыта.
        bool alive;             ///< Состояние персонажа: жив или мёртв.
        CharacterStats stats;   ///< Набор характеристик персонажа.
        static int objectCount; ///< Количество существующих объектов класса.
    
    public:
    /**
     * @brief Создаёт персонажа со стандартными параметрами.
     *
     * Персонаж получает имя "Deprived", уровень 6,
     * 100 единиц текущего и максимального здоровья,
     * а также по 11 единиц каждой характеристики.
     */
    GameCharacter();

    /**
     * @brief Создаёт персонажа с указанными параметрами.
     *
     * @param name Имя персонажа.
     * @param level Начальный уровень персонажа.
     * @param MaxHealth Максимальное количество здоровья.
     * @param experience Начальное количество опыта.
     * @param stats Набор характеристик персонажа.
     *
     * @throw std::invalid_argument Если имя пустое, уровень меньше 1,
     * максимальное здоровье не положительное, опыт отрицательный
     * или одна из характеристик отрицательная.
     */
    GameCharacter(const std::string& name, int level, int MaxHealth, double experience, const CharacterStats& stats);

    /**
     * @brief Создаёт копию существующего персонажа.
     *
     * @param other Персонаж, состояние которого необходимо скопировать.
     */
    GameCharacter(const GameCharacter& other);

    /**
     * @brief Уничтожает объект персонажа.
     *
     * Уменьшает статический счётчик количества существующих объектов.
     */    
    ~GameCharacter();

    /**
     * @brief Возвращает имя персонажа.
     *
     * @return Имя персонажа.
     */
    std::string getName() const;

    /**
     * @brief Возвращает текущий уровень персонажа.
     *
     * @return Уровень персонажа.
     */    
    int getLevel() const;

    /**
     * @brief Возвращает текущее количество здоровья.
     *
     * @return Текущее здоровье персонажа.
     */    
    int getCurrentHealth() const;

    /**
     * @brief Возвращает максимальное количество здоровья.
     *
     * @return Максимальное здоровье персонажа.
     */    
    int getMaxHealth() const;

    /**
     * @brief Возвращает текущее количество опыта.
     *
     * @return Количество опыта.
     */    
    double getExperience() const;

    /**
     * @brief Проверяет, жив ли персонаж.
     *
     * @return true, если персонаж жив, иначе false.
     */    
    bool isAlive() const;

    /**
     * @brief Возвращает характеристики персонажа.
     *
     * @return Структура CharacterStats с характеристиками персонажа.
     */    
    CharacterStats getStats() const;

    /**
     * @brief Наносит персонажу урон.
     *
     * Уменьшает текущее здоровье на указанное количество.
     * Если здоровье становится равным нулю или меньше, персонаж считается мёртвым.
     *
     * @param damage Количество наносимого урона.
     *
     * @throw std::invalid_argument Если значение урона отрицательное.
     * @throw std::logic_error Если персонаж уже мёртв.
     */
    void takeDamage(int damage);

    /**
     * @brief Восстанавливает здоровье персонажа.
     *
     * Здоровье не может превышать максимальное значение.
     *
     * @param amount Количество восстанавливаемого здоровья.
     *
     * @throw std::invalid_argument Если количество лечения
     * не является положительным.
     * @throw std::logic_error Если персонаж мёртв.
     */    
    void heal(int amount);

    /**
     * @brief Добавляет персонажу опыт.
     *
     * За каждые 100 единиц опыта персонаж получает новый уровень.
     * При повышении уровня максимальное здоровье увеличивается
     * на 10 единиц.
     *
     * @param amount Количество получаемого опыта.
     *
     * @throw std::invalid_argument Если количество опыта
     * не является положительным.
     */    
    void gainExperience(double amount);

    /**
     * @brief Увеличивает живучесть персонажа.
     *
     * @param amount Количество добавляемой живучести.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseVitality(int amount);

    /**
     * @brief Увеличивает настройку персонажа.
     *
     * @param amount Количество добавляемой настройки.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseAttunement(int amount);

    /**
     * @brief Увеличивает выносливость персонажа.
     *
     * @param amount Количество добавляемой выносливости.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseEndurance(int amount);

    /**
     * @brief Увеличивает силу персонажа.
     *
     * @param amount Количество добавляемой силы.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseStrength(int amount);

    /**
     * @brief Увеличивает ловкость персонажа.
     *
     * @param amount Количество добавляемой ловкости.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseDexterity(int amount);

    /**
     * @brief Увеличивает сопротивление персонажа.
     *
     * @param amount Количество добавляемого сопротивления.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseResistance(int amount);

    /**
     * @brief Увеличивает интеллект персонажа.
     *
     * @param amount Количество добавляемого интеллекта.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseIntelligence(int amount);

    /**
     * @brief Увеличивает веру персонажа.
     *
     * @param amount Количество добавляемой веры.
     *
     * @throw std::invalid_argument Если значение не положительное.
     */
    void increaseFaith(int amount);

    /**
     * @brief Выводит информацию о персонаже в консоль.
     *
     * Выводятся имя, уровень, здоровье, опыт,
     * состояние персонажа и все его характеристики.
     */    
    void printInfo() const;

    /**
     * @brief Возвращает количество существующих объектов.
     *
     * @return Количество существующих объектов GameCharacter.
     */    
    static int getObjectCount();
};