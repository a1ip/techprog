// Лабораторная работа №10. Динамические массивы
// Вариант - 5
/*
Создать текстовый файл F1 не менее, тем из 10 строк и записать в него информацию.

5.
	1) 	Скопировать из файла F1 в файл F2 строки, начина┐ с К до К+5.
	2) 	Подсчитать количество гласных букв в файле F2.
*/

#include <iostream>
#include <stdlib.h> //для rand()
#include <locale>  //для кириллицы

using namespace std;

int* form(int);
int* delFrom(int*, int, int, int);
int* addFrom(int*, int, int, int);
void print(int*, int);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 10: Динамические массивы" << endl;
	cout << "----------------------------------------------" << endl;
	
	int size;

	cout << "Введите начальный размер массива";

	cin >> size;

	int* arr = form(size);
	print(arr, size);

	int n, k;

	cout << "----------------------------------------------" << endl;
	cout << "Введите номер элемента, с которого начать удаление:";
	cin >> n;
	cout << "Введите количество элементов на удаление:";
	cin >> k;
	
	arr = delFrom(arr, size, n, k); 
	size -=k;
	print(arr, size);

	cout << "Введите номер элемента, с которого начать добавление:";
	cin >> n;
	cout << "Введите количество элементов на добавление:";
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
	cout << "Текущий массив: " << endl;
	cout << "------------------------------\n";
	for (int i = 0; i < s; i++)
	{
		cout << i << ": " << arr[i] << endl;
	}
}