#pragma once
#include <iostream>
#include <cstdarg>
#include <string>
using namespace std;


class Ring
{
    int x; //coordinates of the centre
    int y;
    int inner;  //inner and outter radius
    int outter;
    int size;  //size = outter r - inner r

public:
    Ring();
    Ring(int in, int out);
    Ring(int a, int b, int in, int out);
    void SetSize(double in, double out);
    int GetX();
    int GetY();
    double GetInner();
    double GetOutter();
    int GetSize();
    Ring operator ++ ();
    Ring operator ++ (int z);
    Ring operator *= (int z);
};


Ring CreateRing();

void PrintRing(Ring V);

int FindBiggestRing(Ring* R);