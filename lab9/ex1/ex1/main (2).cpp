// ��������� �������, ��-330801
// ������������ ������ �9. ��������� ����-�����
// ������� - 5
/*
������� ��������� ���� F1 �� �����, ��� �� 10 ����� � �������� � ���� ����������.

5.
	1) 	����������� �� ����� F1 � ���� F2 ������, ������� � � �� �+5.
	2) 	���������� ���������� ������� ���� � ����� F2.
*/

#include <iostream>
#include <stdio.h> //��� gets()
#include <conio.h>	 //��� getche()
#include <locale>  //��� ���������
#include <vector>  //��� ������ � ���������

using namespace std;



int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 9: ��������� ����-�����" << endl;
	cout << "----------------------------------------------" << endl;

	vector<char*> lines;
	char yn;
	char str[50];

	do 
	{
		cout << "������� ������: ";
		cin >> str;

		lines.push_back(str);

		cout << "���������� (y/n)?";
		cin >> yn;
	} 
	while (yn != 'n');



	return 0;
}

