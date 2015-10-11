// ��������� �������, ��-330801
// ������������ ������ �8. �������� ����-�����
// ������� - 5
/*
������������ �������� ���� �� ���������, �������� � �������� ���������, 
����������� ��� ����������, ��������� �������� � ���������� ��������� � 
������������ �� ����� ���������, ��������� ��� ������ ��������� ��� 
����������� ��������� �������. ������������, ������, ���������� � 
�������� ��������� �������� � ���� �������. ������������� ��������� �� 
������� ��� �������� ����� � ���������� �������� �����/������.

5.	 ��������� "�������":
	-	�������, ���, ��������;
	-	��� ��������;
	-	����;
	-	���.
������� ��� ������� � ��������� ������ � �����, �������� ������� ����� �������� � ��������� ��������.


*/

#include <iostream>
#include <stdio.h> //��� gets()
#include <iomanip> //��� setw()
#include <locale>  //��� ���������
#include <string>  //��� ������ �� ��������
#include <conio.h>

using namespace std;

struct human
{
	char first_name[40];		//���
	char last_name[40];			//�������
	char middle_name[40];		//��������
	unsigned int year_of_birth; //��� ��������
	unsigned short height;		//����
	unsigned short weight;		//���
	
public:
	human() : year_of_birth(0), height(0), weight(0)
	{ }
};

human setHuman();
void getHuman(human); 
int writeHuman(human, FILE*);
human readHuman(FILE*);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 8: �������� ����-�����" << endl;
	cout << "----------------------------------------------" << endl;

	FILE* f;	//���������, ��������� � ������

	human arr[10];
	
	//�������� �����
	f = fopen("f.dat", "w+b");
	if (f == NULL)	//���� ������
		exit(1);

	int amount;

	cout << "������� ���������� ������� �� ���������� (����. 10): ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "������� (ID = " << i << "): " << endl;
		cout << "----------------------------------------------";
		arr[i] = setHuman();
	}

	for (int i = 0; i < amount; i++)
	{
		if (!writeHuman(arr[i], f))
			exit(1);	
	}

	int i = 0;

	while(!feof(f) && i < amount)
	{
		arr[i] = readHuman(f);
		i++;
	}

	for (int i = 0; i < amount; i++)
	{
		cout << "������� (ID = " << i << "): " << endl;
		cout << "----------------------------------------------";
		getHuman(arr[i]);
	}

	fclose(f);

	getch();

	return 0;
}

human setHuman()
{
	human obj;

	cout << "\n���: "; cin >> obj.first_name;
	cout << "�������: "; cin >> obj.last_name;
	cout << "��������: "; cin >> obj.middle_name;
	cout << "��� ��������: "; cin >> obj.year_of_birth;
	cout << "����: "; cin >> obj.height;
	cout << "���: "; cin >> obj.weight;
	cout << endl;

	return obj;
}

void getHuman(human obj) 
{
	cout << "\n���: "; cout << obj.first_name;
	cout << "\n�������: "; cout << obj.last_name;
	cout << "\n��������: "; cout << obj.middle_name;
	cout << "\n��� ��������: "; cout << obj.year_of_birth;
	cout << "\n����: "; cout << obj.height;
	cout << "\n���: "; cout << obj.weight;
	cout << endl;
}

int writeHuman(human h, FILE* f)
{
	fwrite(&h, sizeof(human), 1, f);
	if (ferror(f) == NULL)
		return 1;
	return 0;
}

human readHuman(FILE* f)
{
	human h;
	
	if (f == NULL)
	{
		cout << "ERR: �������� ������ ��� ������ �����\n";
		return human();
	}

	fread(&h, sizeof(human),1,f);
	
	return h;
}