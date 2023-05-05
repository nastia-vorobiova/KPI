#include "classes.h"

int main()
{
    Ring* R = new Ring[3];

    cout << "Create three rings: " << endl;
    for (int i = 0; i < 3; i++)
        R[i] = CreateRing();

    cout << "\n\nYour rings:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\nRing " << i << ":";
        PrintRing(R[i]);
    }

    cout << "\n\nChanged rings:" << endl;

    cout << "\n\nIncrement inner radius of R1:" << endl;
    ++R[0];
    PrintRing(R[0]);

    cout << "\n\nIncrement outter radius of R2:" << endl;
    R[1]++;
    PrintRing(R[1]);

    cout << "\n\nDouble outter radius of R3:" << endl;
    R[2]*=2;
    PrintRing(R[2]);

    int biggest = FindBiggestRing(R);
    cout << "\n\nThe thickest ring is R" << biggest + 1;
}
