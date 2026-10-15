#pragma once

/**
 * @file Vector3D.h
 * @brief Определение класса Vector3D для работы с трехмерными векторами.
 */

/**
 * @class Vector3D
 * @brief Класс, реализующий трехмерный вектор и операции над ним.
 * 
 * Класс предоставляет стандартные математические операции (сложение, вычитание, 
 * умножение, деление), унарные операции, операции сравнения по длине, 
 * а также отслеживает статистику создания объектов и подсчет обращений к методам.
 */
class Vector3D
{
private:
    double x; ///< Координата X вектора.
    double y; ///< Координата Y вектора.
    double z; ///< Координата Z вектора.

    mutable int accessCount; ///< Количество обращений к константным методам (mutable позволяет изменять в const-методах).
    static int createdCount; ///< Общее количество созданных экземпляров класса Vector3D.

public:
    /**
     * @brief Конструктор по умолчанию.
     * Создает нулевой вектор (0.0, 0.0, 0.0) и увеличивает счетчик созданных объектов.
     */
    Vector3D();

    /**
     * @brief Инициализирующий конструктор.
     * @param xValue Значение координаты X.
     * @param yValue Значение координаты Y.
     * @param zValue Значение координаты Z.
     */
    Vector3D(double xValue, double yValue, double zValue);

    /**
     * @brief Конструктор копирования.
     * @param other Ссылка на копируемый объект Vector3D.
     */
    Vector3D(const Vector3D& other);

    /**
     * @brief Конструктор с одним параметром (преобразующий).
     * @param value Значение, которое присваивается всем трем координатам (x, y, z).
     * @note Помечен как explicit для предотвращения неявного преобразования типов.
     */
    explicit Vector3D(double value);

    /**
     * @brief Деструктор.
     * Выводит информацию об уничтожении объекта в стандартный поток вывода.
     */
    ~Vector3D();

    /**
     * @brief Получить координату X.
     * @return Значение координаты X.
     * @note Увеличивает счетчик обращений accessCount (const-метод).
     */
    double getX() const;

    /**
     * @brief Получить координату Y.
     * @return Значение координаты Y.
     * @note Увеличивает счетчик обращений accessCount (const-метод).
     */
    double getY() const;

    /**
     * @brief Получить координату Z.
     * @return Значение координаты Z.
     * @note Увеличивает счетчик обращений accessCount (const-метод).
     */
    double getZ() const;

    /**
     * @brief Вычислить длину (модуль) вектора.
     * @return Евклидова длина вектора (sqrt(x^2 + y^2 + z^2)).
     * @note Увеличивает счетчик обращений accessCount (const-метод).
     */
    double length() const;

    /**
     * @brief Получить количество обращений к константным методам текущего объекта.
     * @return Число обращений.
     */
    int getAccessCount() const;

    /**
     * @brief Получить общее количество созданных объектов Vector3D.
     * @return Статическое число созданных объектов.
     */
    static int getCreatedCount();

    /**
     * @brief Вывести вектор в формате (x, y, z).
     */
    void print() const;

    /**
     * @brief Составной оператор сложения с присваиванием.
     * @param other Вектор для сложения.
     * @return Ссылка на измененный текущий объект.
     */
    Vector3D& operator+=(const Vector3D& other);

    /**
     * @brief Составной оператор вычитания с присваиванием.
     * @param other Вектор для вычитания.
     * @return Ссылка на измененный текущий объект.
     */
    Vector3D& operator-=(const Vector3D& other);

    /**
     * @brief Составной оператор поэлементного умножения с присваиванием.
     * @param other Вектор-множитель.
     * @return Ссылка на измененный текущий объект.
     */
    Vector3D& operator*=(const Vector3D& other);

    /**
     * @brief Составной оператор поэлементного деления с присваиванием.
     * @param other Вектор-делитель.
     * @return Ссылка на измененный текущий объект.
     * @throw std::invalid_argument Если хотя бы одна координата делящего вектора равна 0.0.
     */
    Vector3D& operator/=(const Vector3D& other);

    /**
     * @brief Умножение всех координат вектора на скаляр с присваиванием.
     * @param scalar Число (скаляр).
     * @return Ссылка на измененный текущий объект.
     */
    Vector3D& operator*=(double scalar);

    /**
     * @brief Деление всех координат вектора на скаляр с присваиванием.
     * @param scalar Число (скаляр).
     * @return Ссылка на измененный текущий объект.
     * @throw std::invalid_argument Если scalar равен 0.0.
     */
    Vector3D& operator/=(double scalar);

    /**
     * @brief Бинарный оператор сложения векторов.
     * @param other Вектор для сложения.
     * @return Новый объект Vector3D — результат сложения.
     */
    Vector3D operator+(const Vector3D& other) const;

    /**
     * @brief Бинарный оператор вычитания векторов.
     * @param other Вектор для вычитания.
     * @return Новый объект Vector3D — результат вычитания.
     */
    Vector3D operator-(const Vector3D& other) const;

    /**
     * @brief Бинарный оператор поэлементного умножения векторов.
     * @param other Вектор-множитель.
     * @return Новый объект Vector3D.
     */
    Vector3D operator*(const Vector3D& other) const;

    /**
     * @brief Бинарный оператор поэлементного деления векторов.
     * @param other Вектор-делитель.
     * @return Новый объект Vector3D.
     */
    Vector3D operator/(const Vector3D& other) const;

    /**
     * @brief Умножение вектора на скаляр.
     * @param scalar Число (скаляр).
     * @return Новый объект Vector3D.
     */
    Vector3D operator*(double scalar) const;

    /**
     * @brief Деление вектора на скаляр.
     * @param scalar Число (скаляр).
     * @return Новый объект Vector3D.
     */
    Vector3D operator/(double scalar) const;

    /**
     * @brief Префиксный инкремент (++v).
     * Увеличивает значения координат (умножает на 1.01).
     * @return Ссылка на измененный объект.
     */
    Vector3D& operator++();

    /**
     * @brief Постфиксный инкремент (v++).
     * Увеличивает значения координат (умножает на 1.01).
     * @param Фиктивный параметр для отличия от префиксной формы.
     * @return Копия объекта до изменений (старое значение).
     */
    Vector3D operator++(int);

    /**
     * @brief Префиксный декремент (--v).
     * Уменьшает значения координат (умножает на 0.99).
     * @return Ссылка на измененный объект.
     */
    Vector3D& operator--();

    /**
     * @brief Постфиксный декремент (v--).
     * Уменьшает значения координат (умножает на 0.99).
     * @param Фиктивный параметр для отличия от префиксной формы.
     * @return Копия объекта до изменений (старое значение).
     */
    Vector3D operator--(int);

    /**
     * @brief Унарный плюс.
     * @return Новый вектор с теми же координатами.
     */
    Vector3D operator+() const;

    /**
     * @brief Унарный минус.
     * @return Новый вектор с противоположными координатами.
     */
    Vector3D operator-() const;

    /**
     * @brief Оператор "меньше" (<). Сравнивает длины векторов.
     * @param other Сравниваемый вектор.
     * @return true, если длина текущего меньше длины другого.
     */
    bool operator<(const Vector3D& other) const;

    /**
     * @brief Оператор "больше" (>). Сравнивает длины векторов.
     * @param other Сравниваемый вектор.
     * @return true, если длина текущего больше длины другого.
     */
    bool operator>(const Vector3D& other) const;

    /**
     * @brief Оператор "меньше или равно" (<=). Сравнивает длины векторов.
     * @param other Сравниваемый вектор.
     * @return true.
     */
    bool operator<=(const Vector3D& other) const;

    /**
     * @brief Оператор "больше или равно" (>=). Сравнивает длины векторов.
     * @param other Сравниваемый вектор.
     * @return true.
     */
    bool operator>=(const Vector3D& other) const;

    /**
     * @brief Оператор проверки на равенство (==). Сравнивает длины векторов.
     * @param other Сравниваемый вектор.
     * @return true, если длины равны.
     */
    bool operator==(const Vector3D& other) const;

    /**
     * @brief Оператор проверки на неравенство (!=). Сравнивает длины векторов.
     * @param other Сравниваемый вектор.
     * @return true, если длины не равны.
     */
    bool operator!=(const Vector3D& other) const;
};

/**
 * @brief Умножение скаляра на вектор (коммутативная операция: scalar * vector).
 * @param scalar Число (скаляр).
 * @param vector Ссылка на объект Vector3D.
 * @return Новый объект Vector3D — результат умножения.
 */
Vector3D operator*(double scalar, const Vector3D& vector);