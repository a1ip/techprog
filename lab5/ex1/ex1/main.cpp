// ��������� �������, ��-330801
// ������������ ������ �5. ������� � �������
// ������� - 5
#include <iostream>
#include <locale>  //��� ���������

using namespace std;

#define SX 3
#define SY 3

void clearScreen();

void arrPrint(int* arr);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr);


//���������� �������� �� ������� �����������������, �. �. �����, ��� ��������� ������������ ������ ���� 
//��������� ����� ����� 0, � ��������� ������������ ������ ����� �� ���� ����� 1.
int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 5: ������� � �������" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "�������� �������: " << endl;

	int a[SX][SY] =	{
		{1,0,0},
		{0,1,0},
		{0,0,2}
	};

	//�����
	arrPrint(&a[0][0]);
	
	//�������� �� �������������������
	cout << endl << isOrthonormal(&a[0][0]) << endl;

	return 0;
}

/*
	�������� ������� �� �������������������.
	��������� dotProduct - ��������� ������������ ��� ����� ������� arr
	���������� 1 � ������, ����� ������� ���������������.
*/
bool isOrthonormal(int* arr)
{
	//���������, ������� ����� ���� ����������� ������ �������
	bool res = 1;

	//��� ����� ��� 2 �����
	for (int i = 0; i < SX; i++)
		for (int j = 0; j < SY; j++)
		{
			//��� ������������ 2-� ������ �����
			if (i != j)
				{
					if (dotProduct(&arr[0], i, j) != 0)
						res = 0;	//������������ ����������
				}
			//��� ������������ ������ ����� �� ����
			else
				{
					if (dotProduct(&arr[0], i, j) != 1)
						res = 0;	//������������ ����������
				}
		}

	return res;
}

/*
	���������� ���������� ������������ ��� ��� ����� - A � B
	���������� ����� �����
*/
int dotProduct(int* arr, int A, int B)
{
	//���������
	int res = 0;

	for (int i = 0; i < SX; i++) //��� ���� ��������� ������
		res += *(arr + A*SX + i) * *(arr + B*SX + i); //���������� �� ������������
	
	//��������� - ����� ������������ ���� ��������� ������
	return res;
}

/*
	����� ������� arr �� ������
*/
void arrPrint(int* arr) 
{
	for (int i = 0; i < SX; i++) {
		for (int j = 0; j < SY; j++) {
			cout << *(arr + i*SY + j) << ' ';
		}
		cout << endl;
	}
}

//������� ������� ������ � ������������ ��� ����������� ������
void clearScreen()
{
	cout << "������� ����� ������..." << endl;
	system("pause>nul");
	system("cls");
}