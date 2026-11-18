
#include <iostream>
#include <fstream>
#include <iomanip>

#include "MathVector.cpp"

using namespace std;

int main() {
    const int COUNT = 10;

    MathVector<double, 2> vectors[COUNT];

    ifstream file("vectors.txt");

    if (!file) {
        cout << "File opening error!\n";
        return 1;
    }

    for (int i = 0; i < COUNT; i++) {
        int n;

        if (!(file >> n)) {
            cout << "File reading error!\n";
            return 1;
        }

        for (int j = 0; j < n; j++) {
            double value;

            if (!(file >> value)) {
                cout << "File reading error!\n";
                return 1;
            }

            vectors[i].pushBack(value);
        }
    }

    file.close();

    cout << "Initial vectors:\n";

    for (int i = 0; i < COUNT; i++) {
        cout << "Vector " << i + 1 << ": ";
        printVector(vectors[i]);
    }

    cout << "\nAddition:\n";

    MathVector<double, 2> sum =
        vectors[0] + vectors[1];

    printVector(sum);

    cout << "\nSubtraction:\n";

    MathVector<double, 2> difference =
        vectors[0] - vectors[1];

    printVector(difference);

    cout << "\nDot product:\n";

    double result = dotProduct(vectors[0], vectors[1]);

    cout << result << "\n";

    cout << "\nInteger vector:\n";

    MathVector<int, 3> intVector;

    intVector.pushBack(10);
    intVector.pushBack(20);
    intVector.pushBack(30);

    printVector(intVector);

    cout << "\nAllocated memory:\n";

    cout << "Double vectors: "
         << MathVector<double, 2>::getTotalMemory()
         << " bytes\n";

    cout << "Integer vectors: "
         << MathVector<int, 3>::getTotalMemory()
         << " bytes\n";

    return 0;
}
