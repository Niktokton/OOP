
#include <iostream>
#include <fstream>
#include <type_traits>
#include <iomanip>
#include <stdexcept>

template <typename T, size_t InitialCapacity>
class MathVector;

template <typename T, size_t N>
void printVector(const MathVector<T, N>& v);


template <typename T, size_t InitialCapacity>
class MathVector {
private:
    static_assert(std::is_arithmetic<T>::value,
        "MathVector supports only arithmetic types!");

    static_assert(InitialCapacity > 0,
        "InitialCapacity must be greater than zero!");

    T* data;
    size_t size;
    size_t capacity;

    static size_t totalMemory;

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
    MathVector() {
        size = 0;
        capacity = InitialCapacity;
        data = new T[capacity];

        totalMemory += capacity * sizeof(T);
    }

    MathVector(const MathVector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];

        totalMemory += capacity * sizeof(T);
    }

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

    ~MathVector() {
        delete[] data;
        totalMemory -= capacity * sizeof(T);
    }

    void pushBack(T value) {
        if (size == capacity)
            reserve(capacity * 2);

        data[size] = value;
        size++;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    MathVector operator+(const MathVector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Different vector sizes!");

        MathVector result;

        for (size_t i = 0; i < size; i++)
            result.pushBack(data[i] + other.data[i]);

        return result;
    }

    MathVector operator-(const MathVector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Different vector sizes!");

        MathVector result;

        for (size_t i = 0; i < size; i++)
            result.pushBack(data[i] - other.data[i]);

        return result;
    }

    static size_t getTotalMemory() {
        return totalMemory;
    }

    template <typename U, size_t N>
    friend void printVector(const MathVector<U, N>& v);
};


template <typename T, size_t InitialCapacity>
size_t MathVector<T, InitialCapacity>::totalMemory = 0;


template <typename T, size_t N>
void printVector(const MathVector<T, N>& v) {
    std::cout << "[ ";

    for (size_t i = 0; i < v.size; i++)
        std::cout << v.data[i] << " ";

    std::cout << "]\n";
}


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
