#include <iostream>
using namespace std;

int main()
{
float a, b, c; //������� �����
cout << "Enter a" << endl; //������� ������� a
cin >> a;
cout << "Enter b" << endl; //������� ������� b
cin >> b;
cout << "Enter c" << endl; //������� ������� c
cin >> c;

float cosa, cosb, cosc; //�������� ���� �������� �����
//��������� �������� �� ��������� ���� ���� 
//�� ������������ ���������
cosa = (b * b + c * c - a * a) / (2 * b * c);
if (cosa < 0) {
	cout << "A - obtuse angle\n"; //A - ����� ���
}
else if (cosa > 0) {
	cout << "A - acute angle\n"; //A - ������� ���
	}
else {
	cout << "A - right angle\n"; //A - ������ ���
		}

cosb = (a * a + c * c - b * b) / (2 * a * c);
if (cosb < 0) {
	cout << "B - obtuse angle\n"; //B - ����� ���
}
else if (cosb > 0) {
	cout << "B - acute angle\n"; //B - ������� ���
}
else {
	cout << "B - right angle\n"; //B - ������ ���
}

cosc = (b * b + a * a - c * c) / (2 * a * b);
if (cosc < 0) {
	cout << "C - obtuse angle\n"; //C - ����� ���
}
else if (cosc > 0) {
	cout << "C - acute angle\n"; //C - ������� ���
}
else {
	cout << "C - right angle\n"; //C - ������ ���
}
}
