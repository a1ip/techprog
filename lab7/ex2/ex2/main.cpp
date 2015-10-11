// Александр Молодых, ФТ-330801
// Лабораторная работа №7.2. Функции с переменным числом параметров
// Вариант - 5
/*
Написать перегруженные функции и основную программу, которая их вызывает.

5. 	Написать функцию sum с переменным числом параметров, которая находит сумму чисел типа int по формуле:
	S=a1*a2-a2*a3+a3*a4-. . . . .
	 Написать вызывающую функцию main, которая обращается к функции sum не менее трех раз с количеством параметров 5, 10, 12.

*/

#include <iostream>
#include <stdio.h> //для gets()
#include <iomanip> //для setw()
#include <locale>  //для кириллицы
#include <string>  //для работы со строками

using namespace std;

int sum(int k, ...);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 7.2: Функции с переменным числом параметров" << endl;
	cout << "----------------------------------------------" << endl;

	int g = sum(4,12,13,14,15);

	cout << endl << g;

	return 0;
}

int sum (int k, ...)
{
	int *p = &k; //настроили указатель на параметр k
	int sum = *(++p);
	int oper = 0;

	while(k!=1)
	{
		switch(oper)
		{
			case 0 : sum *= *(++p); break;
			case 1 : sum += *(++p); break;
			case 2 : sum *= *(++p); break;
			case 3 : sum -= *(++p); break;
			case 4: oper = 0; break;
			default: oper = 0; 
		}
		cout << sum << endl;
		k--;
		oper++;
	}

	return sum;
}