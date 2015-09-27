// ��������� �������, ��-330801
// ������������ ������ �5. ������� � �������
// ������� - 5
#include <iostream>
#include <iomanip> //��� setw()
#include <locale>  //��� ���������
#include <math.h>  //��� pow()

using namespace std;

#define SX 3
#define SY 3

void clearScreen();
bool isOrthonormal(int* arr);


//���������� �������� �� ������� �����������������, �. �. �����, ��� ��������� ������������ ������ ���� 
//��������� ����� ����� 0, � ��������� ������������ ������ ����� �� ���� ����� 1.
int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 5: ������� � �������" << endl;
	cout << "----------------------------------------------" << endl;

	int arr[SX][SY] = {
						{1,1,1},
						{0,1,0},
						{0,0,1},
					};

	cout << isOrthonormal(&arr[0][0]);

	return 0;
}

bool isOrthonormal(int* arr)
{
	bool result = 1; //���������

	//������� ������� �� �������
	for (int j = 0; j < SY; j++) // ��� ������ ������
	{
		cout << "iter1: " << setw(10) << j << ": " << endl;
		//���������
		for (int jj = 0; jj < SY; jj++) //� ������ �������
		{	
			cout << "iter2: " << setw(10) << jj << ": ";
			if (jj !=j) //����� ����� ����
			{
				int scal = 0;
				for (int i = 0; i < SX; i++)
				{
					scal += *(arr + i) + SY;
				}
				cout << "scal " << " on " << j << " = " << scal << " | ";
				if (scal != 0)
					result *= 0;
			}
			else //� � �����
			{
				int scal = 0;
				for (int i = 0; i < SX; i++)
				{
					scal += *(arr + i) + SY;
				}
				if (scal != 1)
					result *= 0;
			}
			cout << endl;
		}
	}
	return result;
}

//������� ������� ������ � ������������ ��� ����������� ������
void clearScreen()
{
	cout << "������� ����� ������..." << endl;
	system("pause>nul");
	system("cls");
}