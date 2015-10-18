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
#include <fstream>  //��� ������ � ���������

#define LS 100
#define MAX_BUF 200

using namespace std;

int form(char*);
int show(char*);
int copy(char*, char*, int);
////////////////////////////////////////////////////////
char** merge(char**, char**, int, int);

class File
{
	private:
		int k;
		char** lines;
	public:
		File() : k(0) 
		{
			k = 0;
			lines = new char* [0];
		}
		
		int put(char*);
		char* operator[](int) const;
		int write(char*) const;
		static File read(char*);
		int size()
		{
			return k;
		}
};
////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 9: ��������� ����-�����" << endl;
	cout << "----------------------------------------------" << endl;

	char* filename = "f1.txt";

	form(filename);

	show(filename);

	copy("f1.txt", "f2.txt");


	
	return 0;
}
//////////////////////////////////////////////////////////////////////////
int form (char* fn)
{
	File f;

	cout << "----------------------------------------------\n";
	cout << "������� �������� ������� ��� ����� F1: \n";
	cout << "----------------------------------------------\n";
	
	char data[MAX_BUF][LS];

	int i = 0;
	char confirm;
	do 
	{
		cout << i++ << ": ";
		cin >> data[i];

		f.put(data[i]);

		cout << "����������(y/n)?";
		cin >> confirm;
	} while (confirm != 'n');

	//delete [] data;

	f.write(fn);

	return 0;
}
int show (char* fn)
{
	File f;
	f = File::read(fn);

	cout << "----------------------------------------------\n";
	cout << "�������� ������� �� ����� F1: \n";
	cout << "----------------------------------------------\n";

	for (int i = 0; i < f.size() - 1; i++)
	{
		cout << i << ": " << f[i] << endl;
	}

	return 0;
}
int copy (char* fn1, char* fn2, int K)
{
	File f;

	f = File::read(fn1);


	f.write(fn2);

	return 0;
}
//////////////////////////////////////////////////////////////////////////
int File::put(char* str)
{
	char** new_line = new char* [1];
	new_line[0] = new char [LS];
	new_line[0] = str;

	char** new_lines = new char* [k+1];
	new_lines = merge(lines, new_line, k, 1);

	delete [] lines;

	lines = new char* [k++];
	
	lines = new_lines;

	return 0;
}
char* File::operator[](int n) const
{
	if (n < 0 || n >= k)
	{
		return "������: �������� ������";
	}
	return lines[n];
}
int File::write(char* fn) const
{
	ofstream fileout(fn);

	if (fileout.fail())
	{
		cout << "������ ������!";
		exit(1);
	}

	for (int i = 0; i < k; i++)
		if(lines[i] != "")
			fileout << lines[i] << endl;

	fileout.close();
	return 0;
}
File File::read(char* fn)
{
	fn = "f1.txt";
	ifstream filein(fn);
	
	if (filein.fail())
	{
		cout << "������ ������!";
		exit(1);
	}

	File f;
	char line[MAX_BUF][LS];
	
	for (int i = 0; !filein.eof(); i++)
	{
		filein.getline(line[i], LS);
		if (line[i] != "")
			f.put(line[i]);
	}

	filein.close();

	return f;
}
//////////////////////////////////////////////////////////////////////////

char** merge(char** A, char** B, int sA, int sB)
{
	int sM = sA + sB;
	char** merged = new char* [sM];
	for (int i = 0; i < sM; i++)
	{
		merged[i] = new char [LS];
	}
	for (int i = 0; i < sA; i++)
	{
		merged[i] = A[i];
	}
	for (int i = sA; i < sM; i++)
	{
		merged[i] = B[i-sA];
	}

	return merged;
}