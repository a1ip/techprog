// Александр Молодых, ФТ-330801
// Лабораторная работа №3. Вычисление функций с использованием их разложения в степенной ряд
// Вариант - 5
#include <iostream>
#include <iomanip> //для setw()
#include <locale>  //для кириллицы
#include <math.h>  //для pow() и abs()

using namespace std;

#define EPS 0.0001
#define N 15

#define k 10

double calcExpAriphm(double);
double calcExpIter(double);

/*Для х изменяющегося от a до b с шагом (b-a)/k, где (k=10), вычислить функцию f(x), 
  используя ее разложение в степенной ряд в двух случаях:
  а) для заданного n;
  б) для заданной точности epsilon (epsilon=0.0001).
Для сравнения найти точное значение функции.
*/

int main()
{
	setlocale(LC_ALL,"Russian");

	double a = 1;
	double b = 2;

	cout << "Лабораторная работа 3: Вычисление функций с использованием их разложения в степенной ряд" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "Результат вычислений:" << endl;
	
	for (double x = a; x <= b + 0.001; x += (b-a)/k) //b+0.001 связано с ошибкой при округлении
	{
		cout << "X=" << setw(3) << x << " SN=" << setw(8) << calcExpAriphm(x) << " SE=" << setw(8) << calcExpIter(x) << " Y=" << setw(8) << exp(x) <<endl;
	}

	cout << "----------------------------------------------" << endl;

	return 0;
}

double calcExpAriphm(double x)
{
	int i = 0; //счётчик

	double resAriphm = 0; //результат арифметического цикла
	double summand = 1;	//первый член ряда, указан в условии

//Цикл арифметический:
	do 
	{
		resAriphm += summand;
		summand *= x / (i + 1); //рекуррентное соотношение
		i++;
	} while (i < N);

	return resAriphm;
}

double calcExpIter(double x)
{
	int i = 0; //счётчик

	double resIter = 0;   //результат итерационного цикла
	double summand = 1;	//первый член ряда, указан в условии

//Цикл итерационный:
	do 
	{
		resIter += summand;
		summand *= x / (i + 1); //рекуррентное соотношение
		i++;
	} while (summand > EPS);

	return resIter;
}