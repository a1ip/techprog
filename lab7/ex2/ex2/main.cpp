// ��������� �������, ��-330801
// ������������ ������ �7.2. ������� � ���������� ������ ����������
// ������� - 5
/*
�������� ������������� ������� � �������� ���������, ������� �� ��������.

5. 	�������� ������� sum � ���������� ������ ����������, ������� ������� ����� ����� ���� int �� �������:
	S=a1*a2-a2*a3+a3*a4-. . . . .
	S=a1*a2-a3*a4+
	 �������� ���������� ������� main, ������� ���������� � ������� sum �� ����� ���� ��� � ����������� ���������� 5, 10, 12.

*/

#include <iostream>
#include <stdio.h> //��� gets()
#include <iomanip> //��� setw()
#include <locale>  //��� ���������
#include <string>  //��� ������ �� ��������

using namespace std;

int sum(int k, ...);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 7.2: ������� � ���������� ������ ����������" << endl;
	cout << "----------------------------------------------" << endl;

	int g = sum(4,1,1,1,1);

	cout << endl << g << endl;

	return 0;
}

int sum (int k, ...)
{
	int *p = &k; //��������� ��������� �� �������� k
	int sum = *(++p);
	int oper = 0;

	while(k!=1)
	{
		if (oper == 4)
			oper = 0;
		
		switch(oper)
		{
			case 0 : sum *= *(++p); break;
			case 1 : sum += *(++p); break;
			case 2 : sum *= *(++p); break;
			case 3 : sum -= *(++p); break;
			default: oper = 0; 
		}
		k--;
		oper++;
	}

	return sum;
}