
#include "Vector3D.h"

#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << fixed << setprecision(3);

    cout << "Constructors\n";

    Vector3D a(3.0, 4.0, 0.0);
    Vector3D b(1.0, 2.0, 3.0);
    Vector3D zero;

    cout << "a = ";
    a.print();

    cout << "\nb = ";
    b.print();

    cout << "\nzero = ";
    zero.print();

    Vector3D original(3.0, 4.0, 5.0);
    Vector3D copy(original);

    cout << "\nOriginal: ";
    original.print();

    cout << "\nCopy: ";
    copy.print();

    cout << "Created objects: " << Vector3D::getCreatedCount() << endl;

    cout << "\nLength of a = " << a.length() << "\n";

    cout << "\nUnary operators\n";

    cout << "Unary plus: ";
    (+a).print();

    cout << "\nUnary minus: ";
    (-a).print();

    Vector3D c(3.0, 4.0, 0.0);

    cout << "\nInitial c = ";
    c.print();

    cout << "\nPrefix ++c: ";
    (++c).print();

    cout << "\nPostfix c++ (old value): ";
    (c++).print();

    cout << "\nAfter c++: ";
    c.print();

    cout << "\nPrefix --c: ";
    (--c).print();

    cout << "\nPostfix c-- (old value): ";
    (c--).print();

    cout << "\nAfter c--: ";
    c.print();

    cout << "\n\nAssignment operators\n";

    Vector3D d(6.0, 8.0, 10.0);
    Vector3D e(2.0, 4.0, 5.0);

    d += e;
    cout << "d += e: ";
    d.print();

    d -= e;
    cout << "\nd -= e: ";
    d.print();

    d *= e;
    cout << "\nd *= e: ";
    d.print();

    d /= e;
    cout << "\nd /= e: ";
    d.print();

    d *= 2.0;
    cout << "\nd *= 2: ";
    d.print();

    d /= 2.0;
    cout << "\nd /= 2: ";
    d.print();

    cout << "\n\nBinary operators\n";

    cout << "a + b = ";
    (a + b).print();

    cout << "\na - b = ";
    (a - b).print();

    cout << "\na * b = ";
    (a * b).print();

    cout << "\na / b = ";
    (a / b).print();

    cout << "\na * 2 = ";
    (a * 2.0).print();

    cout << "\n2 * a = ";
    (2.0 * a).print();

    cout << "\na / 2 = ";
    (a / 2.0).print();

    cout << "\n\nComparison operators\n";

    cout << "a < b:  " << (a < b) << "\n";
    cout << "a > b:  " << (a > b) << "\n";
    cout << "a <= b: " << (a <= b) << "\n";
    cout << "a >= b: " << (a >= b) << "\n";
    cout << "a == b: " << (a == b) << "\n";
    cout << "a != b: " << (a != b) << "\n";

    cout << "\nExplicit constructor\n";

    Vector3D explicitVector(5.0);

    cout << "Explicit vector: ";
    explicitVector.print();

    // неявное преобразование числа в Vector3D.
    //Vector3D implicitVector = 5.0;

    Vector3D explicitVector2 = Vector3D(5.0);

    cout << "\nExplicit conversion: ";
    explicitVector2.print();

    cout << "\n\nConst object and mutable\n";

    const Vector3D constVector(3.0, 4.0, 0.0);

    cout << "Length: " << constVector.length() << "\n";
    cout << "X: " << constVector.getX() << "\n";
    cout << "Y: " << constVector.getY() << "\n";
    cout << "Z: " << constVector.getZ() << "\n";

    cout << "Number of accesses: "
         << constVector.getAccessCount() << "\n";

    cout << "\nCreated vectors\n";

    cout << "Number of created vectors: "
         << Vector3D::getCreatedCount() << "\n";

    return 0;
}
