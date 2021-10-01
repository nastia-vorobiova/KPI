#include <iostream>
using namespace std;

int main()
{
float a, b, c; //довжини сторін
cout << "Enter a" << endl; //вводимо довжину a
cin >> a;
cout << "Enter b" << endl; //вводимо довжину b
cin >> b;
cout << "Enter c" << endl; //вводимо довжину c
cin >> c;

float cosa, cosb, cosc; //косинуси кутів навпроти сторін
//знаходимо косинуси та визначаємо типи кутів 
//за розрахованим значенням
cosa = (b * b + c * c - a * a) / (2 * b * c);
if (cosa < 0) {
	cout << "A - obtuse angle\n"; //A - тупий кут
}
else if (cosa > 0) {
	cout << "A - acute angle\n"; //A - гострий кут
	}
else {
	cout << "A - right angle\n"; //A - прямий кут
		}

cosb = (a * a + c * c - b * b) / (2 * a * c);
if (cosb < 0) {
	cout << "B - obtuse angle\n"; //B - тупий кут
}
else if (cosb > 0) {
	cout << "B - acute angle\n"; //B - гострий кут
}
else {
	cout << "B - right angle\n"; //B - прямий кут
}

cosc = (b * b + a * a - c * c) / (2 * a * b);
if (cosc < 0) {
	cout << "C - obtuse angle\n"; //C - тупий кут
}
else if (cosc > 0) {
	cout << "C - acute angle\n"; //C - гострий кут
}
else {
	cout << "C - right angle\n"; //C - прямий кут
}
}
