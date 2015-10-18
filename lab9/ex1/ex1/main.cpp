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
#include <vector>		//��� ������ � ���������
#include <conio.h>	 //��� getche()
#include <locale>  //��� ���������
#include <fstream>  //��� ������ � �������
#include <string>

using namespace std;

int form (string);
int display (string);
int copy_K (string, string, int);
int score (string);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 9: ��������� ����-�����" << endl;
	cout << "----------------------------------------------" << endl;

	form("f1.txt");

	cout << "----------------------------------------------" << endl;
	
	display("f1.txt");

	cout << "----------------------------------------------" << endl;
	
	int K;
	cout << "������� ����� K: "; 
	cin >> K;
	
	if (copy_K("f1.txt", "f2.txt", K))
		{cout << "����������� �� �������: ������� ���� ��������� ��� �������� ����� K.\n";}
	
	cout << "----------------------------------------------" << endl;

	cout << "����� ������� ���� � ����� F2: " << score("f2.txt") << endl;


	return 0;
}

//////////////////////////////////////////////////////////////////////////
int form (string fn)
{
	cout << "----------------------------------------------\n";
	cout << "������� �������� ������� ��� ����� F1: \n";
	cout << "----------------------------------------------\n";
	
	vector<string> lines;

	char confirm = '\0';
	
	int i = 0;
	for (int i = 0; confirm != 'n'; i++)
	{
		string data;
		cout << i << ": ";
		cin >> data;

		lines.push_back(data);

		cout << "����������(y/n)?";
		cin >> confirm;
	}

	ofstream fout(fn);

	for (int i = 0; i < lines.size(); i++)
		fout << lines[i] << '\n';
	
	fout.close();

	return 0;
}
int display (string fn)
{
	cout << "----------------------------------------------\n";
	cout << "�������� ������� �� ����� F1: \n";
	cout << "----------------------------------------------\n";

	ifstream fin(fn);

	vector<string> lines;

	string data;
	

	while(!fin.eof())
	{
		getline(fin, data);
		if (data != "\0")
			lines.push_back(data);
	}

	for (int i = 0; i < lines.size(); i++)
		cout << i << ": " << lines[i] << '\n';

	fin.close();

	return 0;
}
int copy_K (string fn1, string fn2, int k)
{
	ifstream fin  (fn1);
	ofstream fout (fn2);

	vector<string> lines;

	string data;
	
	while(!fin.eof())
	{
		getline(fin, data);
		if (data != "\0")
			lines.push_back(data);
	}

	fin.close();

	if (k + 5 >= lines.size() && k >= 0)
		return 1;

	for (int i = k; i < k + 5; i++)
		fout << lines[i] << '\n';
	
	fout.close();

	return 0;
}

int score(string fn)
{
	char* vowels = "aeiouyAEIOUY���������������ߨ���";

	ifstream fin (fn);

	vector<string> lines;

	int counter = 0;

	while(!fin.eof())
	{
		string data;
		getline(fin, data);
		if (data != "\0")
			lines.push_back(data);
	}

	for (int k = 0; k < lines.size(); k++)
	{
		string data = lines[k];
		for (int i = 0; i < strlen(data.c_str()); i++)
			for (int j = 0; j < strlen(vowels); j++)
				if (data.c_str()[i] == vowels[j])
					counter++;
	}

	return counter;
}