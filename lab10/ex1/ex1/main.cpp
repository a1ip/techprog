// ��������� �������, ��-330801
// ������������ ������ �10. ������������ �������
// ������� - 5
/*
������� ��������� ���� F1 �� �����, ��� �� 10 ����� � �������� � ���� ����������.

5.
	1) 	����������� �� ����� F1 � ���� F2 ������, ������� � � �� �+5.
	2) 	���������� ���������� ������� ���� � ����� F2.
*/

#include <iostream>
#include <stdlib.h> //��� rand()
#include <locale>  //��� ���������

using namespace std;

int* form(int);
int* delFrom(int*, int, int, int);
int* addFrom(int*, int, int, int);
void print(int*, int);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 10: ������������ �������" << endl;
	cout << "----------------------------------------------" << endl;
	
	int size;

	cout << "������� ��������� ������ �������: ";

	cin >> size;

	int* arr = form(size);
	print(arr, size);

	int n, k;

	cout << "----------------------------------------------" << endl;
	cout << "������� ����� ��������, � �������� ������ ��������:";
	cin >> n;
	cout << "������� ���������� ��������� �� ��������:";
	cin >> k;
	
	arr = delFrom(arr, size, n, k); 
	size -=k;
	print(arr, size);

	cout << "������� ����� ��������, � �������� ������ ����������:";
	cin >> n;
	cout << "������� ���������� ��������� �� ����������:";
	cin >> k;

	arr = addFrom(arr, size, n, k); 
	size +=k;
	print(arr, size);

	return 0;
}

int* form(int s)
{
	int* arr = new int [s];

	for (int i = 0; i < s; i++)
		arr[i] = rand() % 100;

	return arr;
}

int* delFrom(int* a, int s, int n, int k)
{
	if (s - n <= k)
		return NULL;
	
	int *arr = new int [s - k];

	for (int i = 0; i < n; i++)
		{arr[i] = a[i];}
	for (int i = n; i < s - k; i++)
		{arr[i] = a[i+k];}

	return arr;
}

int* addFrom(int* a, int s, int n, int k)
{
	if (n >= k)
		return NULL;
	
	int *arr = new int [s + k];

	for (int i = 0; i < n; i++)
		{arr[i] = a[i];}
	for (int i = n; i < n + k; i++)
		{arr[i] = 0;}
	for (int i = n + k; i < s; i++)
		{arr[i] = 12;}

	return arr;
}

void print (int* arr, int s)
{
	system("cls");
	cout << "------------------------------\n";
	cout << "������� ������: " << endl;
	cout << "------------------------------\n";
	for (int i = 0; i < s; i++)
	{
		cout << i << ": " << arr[i] << endl;
	}
}