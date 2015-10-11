// ��������� �������, ��-330801
// ������������ ������ �5. ������� � �������
// ������� - 5
#include <iostream>
#include <locale>  //��� ���������

using namespace std;

#define SX 3
#define SY 3

void clearScreen();

<<<<<<< HEAD
void arrPrint(int* arr, int sx, int sy);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr, int sx, int sy);
=======
void arrPrint(int* arr);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr);
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2


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
<<<<<<< HEAD
		{0,0,1}
	};

	//�����
	arrPrint(a, SX, SY);
	
	//�������� �� �������������������
	if (isOrthonormal(a, SX, SY))
		cout << "������� ���������������" << endl;
	else
		cout << "������� �� ���������������" << endl;
=======
		{0,0,2}
	};

	//�����
	arrPrint(&a[0][0]);
	
	//�������� �� �������������������
	cout << endl << isOrthonormal(&a[0][0]) << endl;
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2

	return 0;
}

/*
	�������� ������� �� �������������������.
	��������� dotProduct - ��������� ������������ ��� ����� ������� arr
	���������� 1 � ������, ����� ������� ���������������.
*/
<<<<<<< HEAD
bool isOrthonormal(int* arr, int sx, int sy)
=======
bool isOrthonormal(int* arr)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
{
	//���������, ������� ����� ���� ����������� ������ �������
	bool res = 1;

	//��� ����� ��� 2 �����
<<<<<<< HEAD
	for (int i = 0; i < sx; i++)
		for (int j = 0; j < sy; j++)
=======
	for (int i = 0; i < SX; i++)
		for (int j = 0; j < SY; j++)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
		{
			//��� ������������ 2-� ������ �����
			if (i != j)
				{
<<<<<<< HEAD
					if (dotProduct(arr, i, j) != 0)
=======
					if (dotProduct(&arr[0], i, j) != 0)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
						res = 0;	//������������ ����������
				}
			//��� ������������ ������ ����� �� ����
			else
				{
<<<<<<< HEAD
					if (dotProduct(arr, i, j) != 1)
=======
					if (dotProduct(&arr[0], i, j) != 1)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
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
<<<<<<< HEAD
void arrPrint(int* arr, int sx, int sy) 
=======
void arrPrint(int* arr) 
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
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