#include <stdio.h>

int main()
{
	float a, b; //���������� ������ ��� ���������� ������� �����
	
	printf("a = ");
	scanf_s("%f", &a); //��� a
	
	printf("b = ");
	scanf_s("%f", &b); //��� b
	
	float s; //���������� ����� ��� ���������� �����
	
	s = b * (2 * a - b); //���������� �����
	printf("s = %f", s); //���� ����������
}