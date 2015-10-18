// Александр Молодых, ФТ-330801
// Лабораторная работа №9. Строковый ввод-вывод
// Вариант - 5
/*
Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию.

5.
	1) 	Скопировать из файла F1 в файл F2 строки, начиная с К до К+5.
	2) 	Подсчитать количество гласных букв в файле F2.
*/

#include <iostream>
#include <stdio.h> //для gets()
#include <conio.h>	 //для getche()
#include <locale>  //для кириллицы
#include <vector>  //для работы с векторами

using namespace std;



int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 9: Строковый ввод-вывод" << endl;
	cout << "----------------------------------------------" << endl;

	vector<char*> lines;
	char yn;
	char str[50];

	do 
	{
		cout << "Введите строку: ";
		cin >> str;

		lines.push_back(str);

		cout << "Продолжить (y/n)?";
		cin >> yn;
	} 
	while (yn != 'n');



	return 0;
}

