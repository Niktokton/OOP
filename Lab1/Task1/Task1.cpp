#include <iostream>
using namespace std;

void fillArray(int(&arr)[10])
{
    for (int& x : arr)
    {
        x = rand() % 100;
    }
}

void printArray(int(&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void swapElements(int(&arr)[10], int& index1, int& index2)
{
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

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

    int index1 = 1;
    int index2 = 2;

    swapElements(arr, index1, index2);

    printArray(arr);

    multiplyByTwo(arr);

    printArray(arr);

    return 0;
}