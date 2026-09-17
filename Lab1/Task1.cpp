#include <iostream>
using namespace std;

/**
 * @brief Заполняет массив случайными числами.
 * @param arr Массив из 10 элементов.
 */
void fillArray(int(&arr)[10])
{
    for (int& x : arr)
    {
        x = rand() % 100;
    }
}

/**
 * @brief Выводит массив на экран.
 * @param arr Массив из 10 элементов.
 */
void printArray(int(&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
}

/**
 * @brief Меняет местами два элемента массива.
 * @param arr Массив из 10 элементов.
 * @param index1 Индекс первого элемента.
 * @param index2 Индекс второго элемента.
 */
void swapElements(int(&arr)[10], int& index1, int& index2)
{
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

/**
 * @brief Умножает каждый элемент массива на два.
 * @param arr Массив из 10 элементов.
 */
void multiplyByTwo(int(&arr)[10])
{
    for (int &x : arr)
    {
        x *= 2;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int arr[10];

    fillArray(arr);

    printArray(arr);

    int index1 = 25;
    int index2 = 23;

    swapElements(arr, index1, index2);

    printArray(arr);

    multiplyByTwo(arr);

    printArray(arr);

    return 0;
}