/**
 * @file MathVector.cpp
 * @brief Реализация шаблонного класса динамического математического вектора и связанных операций.
 */

#include <iostream>
#include <fstream>
#include <type_traits>
#include <stdexcept>

// Предварительное объявление класса и функций для Doxygen
template <typename T, size_t InitialCapacity>
class MathVector;

template <typename T, size_t N>
void printVector(const MathVector<T, N>& v);


/**
 * @class MathVector
 * @brief Шаблонный класс динамического массива для хранения координат точек или векторов.
 * 
 * Класс предназначен для использования в вычислительных задачах. Поддерживает динамическое 
 * изменение размера, арифметические операции (сложение, вычитание), подсчет выделенной памяти 
 * и статическую проверку типов.
 * 
 * @tparam T Тип данных элементов вектора (должен быть арифметическим типом).
 * @tparam InitialCapacity Начальный размер внутреннего буфера (нетиповой параметр).
 */
template <typename T, size_t InitialCapacity>
class MathVector {
private:
    /// Статическая проверка: разрешено использовать только арифметические типы (int, float, double и т.д.)
    static_assert(std::is_arithmetic<T>::value,
        "MathVector supports only arithmetic types!");

    /// Статическая проверка: начальная емкость должна быть строго больше нуля
    static_assert(InitialCapacity > 0,
        "InitialCapacity must be greater than zero!");

    T* data;          ///< Указатель на динамический массив элементов
    size_t size;      ///< Текущее количество элементов в векторе
    size_t capacity;  ///< Текущая емкость (выделенная память) буфера

    /**
     * @brief Суммарный объем памяти (в байтах), выделенный всеми созданными векторами типа T.
     */
    static size_t totalMemory;

    /**
     * @brief Увеличивает емкость буфера вектора до нового значения.
     * @param newCapacity Новая емкость буфера (должна быть больше текущей).
     */
    void reserve(size_t newCapacity) {
        if (newCapacity <= capacity)
            return;

        T* newData = new T[newCapacity];

        for (size_t i = 0; i < size; i++)
            newData[i] = data[i];

        delete[] data;

        totalMemory -= capacity * sizeof(T);
        capacity = newCapacity;
        totalMemory += capacity * sizeof(T);

        data = newData;
    }

public:
    /**
     * @brief Конструктор по умолчанию.
     * Создает пустой вектор с начальной емкостью, заданной параметром InitialCapacity.
     */
    MathVector() {
        size = 0;
        capacity = InitialCapacity;
        data = new T[capacity];

        totalMemory += capacity * sizeof(T);
    }

    /**
     * @brief Конструктор копирования.
     * @param other Другой объект класса MathVector, данные которого копируются.
     */
    MathVector(const MathVector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];

        totalMemory += capacity * sizeof(T);
    }

    /**
     * @brief Оператор присваивания копированием.
     * @param other Другой объект класса MathVector.
     * @return Ссылка на текущий объект.
     */
    MathVector& operator=(const MathVector& other) {
        if (this != &other) {
            delete[] data;
            totalMemory -= capacity * sizeof(T);

            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];

            for (size_t i = 0; i < size; i++)
                data[i] = other.data[i];

            totalMemory += capacity * sizeof(T);
        }

        return *this;
    }

    /**
     * @brief Деструктор.
     * Освобождает динамически выделенную память под буфер вектора.
     */
    ~MathVector() {
        delete[] data;
        totalMemory -= capacity * sizeof(T);
    }

    /**
     * @brief Добавляет элемент в конец вектора.
     * При необходимости автоматически увеличивает емкость буфера.
     * @value Значение элемента для добавления.
     */
    void pushBack(T value) {
        if (size == capacity)
            reserve(capacity * 2);

        data[size] = value;
        size++;
    }

    /**
     * @brief Доступ по индексу (для чтения и записи).
     * @param index Индекс элемента.
     * @return Ссылка на элемент вектора.
     */
    T& operator[](size_t index) {
        return data[index];
    }

    /**
     * @brief Доступ по индексу (только для чтения).
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент вектора.
     */
    const T& operator[](size_t index) const {
        return data[index];
    }

    /**
     * @brief Возвращает текущее количество элементов в векторе.
     * @return Текущий размер (size).
     */
    size_t getSize() const {
        return size;
    }

    /**
     * @brief Операция сложения двух векторов.
     * @param other Вектор, прибавляемый к текущему.
     * @return Новый объект MathVector, содержащий поэлементную сумму.
     * @throw std::invalid_argument Если размеры векторов не совпадают.
     */
    MathVector operator+(const MathVector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Different vector sizes!");

        MathVector result;

        for (size_t i = 0; i < size; i++)
            result.pushBack(data[i] + other.data[i]);

        return result;
    }

    /**
     * @brief Операция вычитания двух векторов.
     * @param other Вектор, вычитаемый из текущего.
     * @return Новый объект MathVector, содержащий поэлементную разность.
     * @throw std::invalid_argument Если размеры векторов не совпадают.
     */
    MathVector operator-(const MathVector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Different vector sizes!");

        MathVector result;

        for (size_t i = 0; i < size; i++)
            result.pushBack(data[i] - other.data[i]);

        return result;
    }

    /**
     * @brief Возвращает общий объем памяти, выделенный под все векторы типа T.
     * @return Объем памяти в байтах.
     */
    static size_t getTotalMemory() {
        return totalMemory;
    }

    /// Дружественная функция вывода вектора на экран
    template <typename U, size_t N>
    friend void printVector(const MathVector<U, N>& v);
};

// Инициализация статического члена класса
template <typename T, size_t InitialCapacity>
size_t MathVector<T, InitialCapacity>::totalMemory = 0;


/**
 * @brief Выводит содержимое вектора в стандартный поток вывода.
 * @tparam T Тип элементов вектора.
 * @tparam N Емкость вектора.
 * @param v Ссылка на выводимый вектор.
 */
template <typename T, size_t N>
void printVector(const MathVector<T, N>& v) {
    std::cout << "[ ";

    for (size_t i = 0; i < v.size; i++)
        std::cout << v.data[i] << " ";

    std::cout << "]\n";
}


/**
 * @brief Вычисляет скалярное произведение двух векторов.
 * @tparam T Тип элементов векторов.
 * @tparam N Размерность векторов.
 * @param a Первый вектор.
 * @param b Второй вектор.
 * @return Значение скалярного произведения.
 * @throw std::invalid_argument Если размеры векторов не совпадают.
 */
template <typename T, size_t N>
T dotProduct(const MathVector<T, N>& a,
             const MathVector<T, N>& b) {

    if (a.getSize() != b.getSize())
        throw std::invalid_argument("Different vector sizes!");

    T result = 0;

    for (size_t i = 0; i < a.getSize(); i++)
        result += a[i] * b[i];

    return result;
}


/**
 * @brief Специализация функции скалярного произведения для векторов типа double и размера 2.
 * Использует повышенную точность (long double) для уменьшения погрешности вычислений.
 * @param a Первый вектор (double, размер 2).
 * @param b Второй вектор (double, размер 2).
 * @return Скалярное произведение с повышенной точностью.
 */
template <>
double dotProduct<double, 2>(
    const MathVector<double, 2>& a,
    const MathVector<double, 2>& b) {

    if (a.getSize() != b.getSize())
        throw std::invalid_argument("Different vector sizes!");

    long double result = 0;

    for (size_t i = 0; i < a.getSize(); i++)
        result += static_cast<long double>(a[i]) *
                  static_cast<long double>(b[i]);

    return static_cast<double>(result);
}