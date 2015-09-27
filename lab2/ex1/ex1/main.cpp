// Александр Молодых, ФТ-330801
// Лабораторная работа №2. Использование основных операторов языка Си
// Вариант - 5
#include <iostream>
#include <math.h>
#include <locale>

using namespace std;

#define EPS 0.0001

//Найти сумму ряда с точностью epsilon=10-4, общий член которого  
//an = ((-1)^(n-1)) / (n^n)
int main()
{
	setlocale(LC_ALL, "Russian");
	double summand = 0,	//слагаемое
		   diff,	//разность
		   res = 0; //результат
	int n = 1;	//счётчик

	cout << "Лабраторная работа 2: Использование основных операторов языка Си" << endl;
	cout << "----------------------------------------------" << endl;

	do 
	{
		diff = summand;
		n % 2 ? res -= summand : res +=summand;
		summand = 1/pow(double(n),double(n));	
		n++;
		cout << abs(diff - summand) << endl;
		
	} while (abs(diff - summand) > EPS);	//пока значение n-го слагаемого больше точности

	cout << "Результат вычислений: " << res << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Итераций выполнено: " << n << endl;
	return 0;
}