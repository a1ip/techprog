// ��������� �������, ��-330801
// ������������ ������ �7.1. ���������� �������
// ������� - 5
/*
�������� ������������� ������� � �������� ���������, ������� �� ��������.

5. 	�) ��� ��������� ������������ �����;
	�) ��� ��������� ����������� �����.
*/

#include <iostream>
#include <stdio.h> //��� gets()
#include <locale>  //��� ���������
#include <string>  //��� ������ �� ��������

using namespace std;

struct Complex
{
	public:
		double re;
		double im;

	Complex() : re(0), im(0)
	{};

	Complex(double R, double I) : re(R), im(I)
	{};
};

void print(char* title, Complex digit);
void print(char* title, double digit);

Complex multiply(Complex x, Complex y);
double multiply(double x, double y);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 7: ���������� �������" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "������������ �����:" << endl;
	//������������:
	double d1 = 12;
	double d2 = 13;

	double d3 = multiply(d1, d2);

	print("d1", d1);
	print("d2", d2);
	print("d3", d3);

	cout << "����������� �����:" << endl;
	//�����������:
	Complex c1(12, 13);
	Complex c2(-5, -6);

	Complex c3 = multiply(c1, c2);

	
	print("c1", c1);
	print("c2", c2);
	print("c3", c3);

	return 0;
}

Complex multiply(Complex x, Complex y)
{
	Complex c;
	c.re = x.re * y.re;
	c.im = x.im * y.im;

	return c;
}

double multiply(double x, double y)
{
	return x * y;
}

void print(char* title, Complex digit)
{
	cout << title << " = " << digit.re << " + " << digit.im << "i" << endl;
}

void print(char* title, double digit)
{
	cout << title << " = " << digit << endl;
}