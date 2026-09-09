#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    cout << "Введите число N степеней двойки ";
    cin >> number;
    for (int i = 1; i < number + 1; i++) {
        cout << pow(2, i) << " ";
    }
    return 0;
}