#include "classes.h"

Ring::Ring() {
    x = 0;
    y = 0;
    inner = 0;
    outter = 0;
    SetSize(inner, outter);
}
Ring::Ring(int in, int out) {
    x = 0;
    y = 0;
    inner = in;
    outter = out;
    SetSize(inner, outter);
}
Ring::Ring(int a, int b, int in, int out) {
    x = a;
    y = b;
    inner = in;
    outter = out;
    SetSize(inner, outter);
}

void Ring::SetSize(double in, double out)
{
    size = out - in;
}

int Ring::GetX()
{
    return x;
}

int Ring::GetY()
{
    return y;
}

double Ring::GetInner()
{
    return inner;
}

double Ring::GetOutter()
{
    return outter;
}

int Ring::GetSize()
{
    return size;
}

Ring Ring::operator ++ ()
{
    inner++;
    SetSize(inner, outter);
    return *this;
}

Ring Ring::operator ++ (int z)
{
    outter++;
    SetSize(inner, outter);
    return *this;
}

Ring Ring::operator *= (int z)
{
    outter *= z;
    SetSize(inner, outter);
    return *this;
}