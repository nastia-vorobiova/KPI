#include "classes.h"

Ring CreateRing()
{
    Ring R;
    char ans;
    cout << "\nCreate a ring: " << endl;
    cout << "Does a ring starts at (0,0)? (y/n) "; cin >> ans;
    if (ans == 'y' or ans == 'Y')
    {
        int i, o;
        cout << "Enter inner radius: "; cin >> i;
        cout << "Enter outter radius: "; cin >> o;
        R = Ring(i, o);
    }
    else
    {
        int x, y;
        int i, o;
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter inner radius: "; cin >> i;
        cout << "Enter outter radius: "; cin >> o;
        R = Ring(x, y, i, o);

    }

    return R;
}

void PrintRing(Ring V)
{
    cout << "\nCentre: (" << V.GetX() << ", " << V.GetY() << ") ";
    cout << "\nInner Circle: " << V.GetInner();
    cout << "\nOutter Circle: " << V.GetOutter();
    cout << "\nSize: " << V.GetSize();
}

int FindBiggestRing(Ring* R)
{
    int biggest = 0;
    for (int i = 1; i < 3; i++)
        if (R[i].GetSize() > R[biggest].GetSize())
            biggest = i;
    return biggest;
}