// ��������� �������, ��-330801
// ������������ ������ �6. ������
// ������� - 5
/*
������ ������, ��������� �� ��������. ������� ������������ � �����. 
����� ���� �� ����� ����������  ��-��� ��� ����������� ���������. 
� ����� ������ �������� �����. ����� �������� �� ����� 255 ��������. 
��������� ���� ������, ��������� ������� Gets(s) � ��������� ������ 
� ������������ �� ����� ���������.

5. 	���������� ��� �����, ������� ��������� � �� ������ ������.
*/

#include <iostream>
#include <stdio.h> //��� gets()
#include <iomanip> //��� setw()
#include <locale>  //��� ���������
#include <string>  //��� ������ �� ��������

using namespace std;

void getWords (char* par);

int main()
{
	setlocale(LC_ALL,"Russian");

	char paragraph[256];

	cout << "������������ ������ 6: ������" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "������� ������: ";
	gets(paragraph);

	cout << "�� �����: " << paragraph << endl;
	cout << "----------------------------------------------" << endl;

	getWords(paragraph);

	return 0;
}

void getWords (char par[])
{
	char firstWord[50];
	char nextWord[50];

	for (int i = 1; par[i] != '\0'; i++)
	{
		if (par[i] == ' ' && par[i-1] != ' ')
		{
			strncpy(firstWord, par, i);
			firstWord[i] = '\0';
		}
	}

	for (int i = 1; par[i] != '.'; i++)
	{
		int x;
		if (par[i] == ' ' && par[i-1] != ' ')
		{
			strncpy(nextWord, par, i-x);
			nextWord[i] = '\0';
			x = i;
		}

		cout << "'" << nextWord << "'" << " cmps with " << "'" << firstWord << "'" << endl; 

		if (strcmp(firstWord, nextWord) == 0)
			cout << nextWord << endl;
	}

	//cout << firstWord;
}
