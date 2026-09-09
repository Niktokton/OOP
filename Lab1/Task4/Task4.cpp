#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = rand() % 4 + 2;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix")
{
    cout << title << "\n";
    if (showBorders)
    {
        for (int i = 0; i < cols * 2 + 3; i++) 
        {
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 0; i < rows; ++i)
    {
        if (showBorders)
        {
            cout << "* ";
        }

        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }

        if (showBorders)
        {
            cout << "*";
        }
        cout << "\n";
    }

    if (showBorders)
    {
        for (int i = 0; i < cols * 2 + 3; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void printMatrix(int** matrix, int rows, int cols, const char* title)
{
    printMatrix(matrix, rows, cols, true, string(title));
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));

    int rows;
    int cols;

    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** matrix = allocateMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    cout << "\n";

    printMatrix(matrix, rows, cols, "Оценки студентов");

    cout << "\n";

    printMatrix(matrix, rows, cols, false, "Оценки без рамки");


    freeMatrix(matrix, rows);

    return 0;
}