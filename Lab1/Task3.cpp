#include <iostream>
using namespace std;

/**
 * @brief Безопасный динамический массив.
 */
struct SafeArray 
{
    int* data;
    int size;
};

/**
* @brief Выделяет память и возвращает структуру по значению.
* @param size Размер массива.
*/
SafeArray createArray(int size) 
{
    SafeArray arr;
    arr.data = new int[size] {};
    arr.size = size;
    return arr;
}

/**
* @brief Обеспечивает доступ к элементам.
* Проверяет корректность индекса.
* @param arr Безопасный массив.
* @param index Индекс элемента.
* @return Ссылка на элемент массива или переменную-заглушку при ошибке.
*/
int& getElement(SafeArray& arr, int index) 
{
    if (index < 0 || index >= arr.size)
    {
        cout << "Ошибка! Выход за пределы массива\n";
        static int dummy = 0;
        return dummy;
    }
    return arr.data[index];
}

/**
* @brief Выводит массив.
* @param arr Безопасный массив.
*/
void printSafe(const SafeArray& arr) 
{
    for (int i = 0; i < arr.size; ++i)
    {
        cout << arr.data[i] << " ";
    }
    cout << "\n";
}

/**
* @brief Изменяет размер массива.
* Если элементов в массиве стало меньше на экран выводятся удаленные элементы.
* Если элементов в массиве стало больше, новые элементы будут равны 0.
* @param arr Безопасный массив.
* @param N Изначальная длина массива.
* @param M Новая длина массива.
*/
void reSizeArray(SafeArray& arr, int N, int M)
{
    if (M < N)
    {
        cout << "Удалённые элементы: ";

        for (int i = M; i < N; ++i)
        {
            cout << arr.data[i] << " ";
        }

        cout << endl;
    }

    int* newData = new int[M] {};
    int elementsToCopy;

    if (N < M)
    {
        elementsToCopy = N;
    }
    else
    {
        elementsToCopy = M;
    }

    for (int i = 0; i < elementsToCopy; ++i)
    {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;
    arr.data = newData;
    arr.size = M;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));
    int N;
    cout << "Введите число N размер массива: ";
    cin >> N;
    SafeArray myArr = createArray(N);

    for (int i = 0; i < myArr.size; ++i)
    {
        myArr.data[i] = rand() % 100;
    }

    cout << "Созданный Массив: ";
    printSafe(myArr);

    getElement(myArr, 2) = 999;

    cout << "Изменённый Массив: ";
    printSafe(myArr);

    getElement(myArr, myArr.size);

    cout << "\nИзменение размера с N до N - 1\n";

    reSizeArray(myArr, myArr.size, myArr.size - 1);
    printSafe(myArr);

    cout << "\nИзменение размера с N - 1 до N\n";

    reSizeArray(myArr, myArr.size, myArr.size + 1);
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;
    myArr.size = 0;
    return 0;
}