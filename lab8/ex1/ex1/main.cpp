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

using namespace std;

//��������� "�������"
struct human
{
	char first_name[40];		 //���
	char last_name[40];		 //�������
	char middle_name[40];		 //��������
	unsigned int year_of_birth; //��� ��������
	unsigned short height;		 //����
	unsigned short weight;		 //���
	
public:
	human() 
	{ }
};

//������� ������������ � ������

	//������������ ������� ����������� ���������
	human* setHuman(int);
	//������������ ������ ���������� ���������
	human setOneHuman(int a);
	//����� ������� ����������� ��������� �� ������
	int getHuman(human*, int); 

//������� ���������

	//�������� ���������� ��������� �� ��������� ��������� "����" � "���"
	human* delHW(human*, int&, int, int);
	//���������� ������ ���������� ����� ���������� �������� "�������"
	human* addAfter(human*, int&, char[]);

//������� ������ � ��������� �������

	//������ � ���� ������� ����������� ��������� � ����� �������� ������
	int writeHuman(human, FILE*);
	//������ �� ��������� ����� ������ � ������ ����������� ���������
	human readHuman(FILE*);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 8: �������� ����-�����" << endl;
	cout << "----------------------------------------------" << endl;

	FILE* f;	//���������, ��������� � ������
	
	//�������� �����
	f = fopen("f.dat", "w+b");
	if (f == NULL)	//���� ������
		exit(1);

	int amount;

	cout << "������� ���������� ������� �� ����������: ";
	cin >> amount;

	human* arr = new human [amount]; 
	
	//����������� ������
	arr = setHuman(amount); 

	//������ � ����
	for (int i = 0; i < amount; i++)
	{
		if (!writeHuman(arr[i], f))
			exit(1);	
	}

	//����� ���������
	rewind(f);

	int i = 0;
	
	//������ �� ����� � ������
	while(!feof(f) && i < amount)
	{
		arr[i] = readHuman(f);
		i++;
	}

	//����� ������ �� �������
	getHuman(arr, amount);
	
	unsigned int height; //���
	unsigned int weight; //����

	cout << "----------------------------------------------" << endl;

	//������ ����� � ����
	cout << "������� ���� � ��� ��������, �������� ����� �������\n: " << endl;
	cout << "����: "; cin >> height;
	cout << "\n���: "; cin >> weight;

	arr = delHW(arr, amount, height, weight);
	
	cout << "----------------------------------------------" << endl;

	//����� ������ �� �������
	getHuman(arr, amount);

	char last_name[40];

	//������ �������
	cout << "������� ������� ��������, ����� �������� ����� �������� ������\n: " << endl;
	cin >> last_name;

	arr = addAfter(arr, amount, last_name);
	
	//����� ������ �� �������
	getHuman(arr, amount);

	//��������� ����
	fclose(f);

	return 0;
}

human setOneHuman(int i)
{
	human obj;

	cout << "----------------------------------------------\n";
	cout << "������� (ID = " << i << "): " << endl;
	cout << "----------------------------------------------\n";

	cout << "\n���: "; cin >> obj.first_name;
	cout << "�������: "; cin >> obj.last_name;
	cout << "��������: "; cin >> obj.middle_name;
	cout << "��� ��������: "; cin >> obj.year_of_birth;
	cout << "����: "; cin >> obj.height;
	cout << "���: "; cin >> obj.weight;
	cout << endl;
	return obj;
}

human* setHuman(int a)
{
	human* obj;

	for (int i = 0; i < a; i++)
	{
		cout << "----------------------------------------------\n";
		cout << "������� (ID = " << i << "): " << endl;
		cout << "----------------------------------------------\n";

		cout << "\n���: "; cin >> obj[i].first_name;
		cout << "�������: "; cin >> obj[i].last_name;
		cout << "��������: "; cin >> obj[i].middle_name;
		cout << "��� ��������: "; cin >> obj[i].year_of_birth;
		cout << "����: "; cin >> obj[i].height;
		cout << "���: "; cin >> obj[i].weight;
		cout << endl;
	}
	return obj;
}

int getHuman(human* obj, int a) 
{
	if (a == 0)
	{
		cout << "----------------------------------------------\n";
		cout << "�������� ���" << endl;
		cout << "----------------------------------------------\n";
		return 0;
	}

	for (int i = 0; i < a; i++)
	{
		cout << "----------------------------------------------\n";
		cout << "������� (ID = " << i << "): " << endl;
		cout << "----------------------------------------------\n";

		cout << "\n���: "; cout << obj[i].first_name;
		cout << "\n�������: "; cout << obj[i].last_name;
		cout << "\n��������: "; cout << obj[i].middle_name;
		cout << "\n��� ��������: "; cout << obj[i].year_of_birth;
		cout << "\n����: "; cout << obj[i].height;
		cout << "\n���: "; cout << obj[i].weight;
		cout << endl;
	}

	return 0;
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

human* delHW(human* arr, int& a, int h, int w)
{
	for (int i = 0; i < a; i++)
	{
		if (arr[i].weight == w && arr[i].height == h)
		{
			for (int j = i; j < a - 1; j++)
			{
				arr[j] = arr[j+1];
			}
			//delete [] arr[a];
			a--;
		}
	}
	
	return arr;
}

human* addAfter(human* arr, int& a, char ln[])
{
	human* res = new human [a+1];
	int j = 0;
	
	if (a == 0)
	{
		res[0] = setOneHuman(0);
		a++;
		return res;
	}

	for (int i = 0; i < a; i++)
	{
		if (strcmp(arr[i].last_name, ln) == 0)
		{
			res[i] = setOneHuman(i);
			a++;
			for (int j = i + 1; j < a; j++)
			{
				res[j] = arr[j - 1];
			}
			return res;
		}
		else
		{
			res[i] = arr[i]; 
		}
	}
	
	delete &res[a+1];
	return res;
}
