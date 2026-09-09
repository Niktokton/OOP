#include <iostream>
using namespace std;

/**
 * @brief Заполняет массив случайными числами.
 * @param arr Ссылка на указатель массива.
 * @param size Размер массива.
 */
void fillArray(int*& arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 19 - 9;
    }
}

/**
 * @brief Выводит массив на экран.
 * @param arr Ссылка на указатель массива.
 * @param size Размер массива.
 */
void printArray(int*& arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/**
 * @brief Обрабатывает динамический массив.
 * Находит первый отрицательный элемент и удаляет его и все последующие элементы.
 * @param arr Ссылка на указатель массива.
 * @param size Размер массива.
 */
void process(int*& arr, int size)
{
    int firstNegative = -1;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            firstNegative = i;
            break;
        }
    }

    if (firstNegative != -1)
    {
        int* newArr = new int[firstNegative] {};
        for (int i = 0; i < firstNegative; ++i)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));
    int N;
    cout << "Введите число N размер массива: ";
    cin >> N;
    int* arr = new int[N] {};

    fillArray(arr, N);
    cout << "Созданный Массив: ";
    printArray(arr, N);

    process(arr, N);

    int newArrSize = 0;

    while (newArrSize < N && arr[newArrSize] >= 0)
    {
        ++newArrSize;
    }

    cout << "Новый Массив: ";
    printArray(arr, newArrSize);

    delete[] arr;

    arr = nullptr;
    if (arr == nullptr)
    {
        cout << "Указатель успешно обнулён\n";
    }

    return 0;
}
