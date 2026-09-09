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
    cout << endl;
}

int main()
{
    int arr[10];
    fillArray(arr);
    printArray(arr);
    return 0;
}