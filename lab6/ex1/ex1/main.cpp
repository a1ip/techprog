// Александр Молодых, ФТ-330801
// Лабораторная работа №6. Строки
// Вариант - 5
/*
Задана строка, состоящая из символов. Символы объединяются в слова. 
Слова друг от друга отделяются  од-ним или несколькими пробелами. 
В конце текста ставится точка. Текст содержит не более 255 символов. 
Выполнить ввод строки, используя функцию Gets(s) и обработку строки 
в соответствии со своим вариантом.

5. 	Напечатать все слова, которые совпадают с ее первым словом.
*/

#include <iostream>
#include <stdio.h> //для gets()
#include <iomanip> //для setw()
#include <locale>  //для кириллицы
#include <string>  //для работы со строками

using namespace std;

void getWords (char* par);

int main()
{
	setlocale(LC_ALL,"Russian");

	char paragraph[256];

	cout << "Лабораторная работа 6: Строки" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "Введите строку: ";
	gets(paragraph);

	cout << "Вы ввели: " << paragraph << endl;
	cout << "----------------------------------------------" << endl;

	getWords(paragraph);

	return 0;
}

void getWords (char par[])
{
	char firstWord[50];
	char nextWord[50];

	for (int i = 1; par[i] != '\0'; i++)
	{
		if (par[i] == ' ' && par[i-1] != ' ')
		{
			strncpy(firstWord, par, i);
			firstWord[i] = '\0';
		}
	}

	for (int i = 1; par[i] != '.'; i++)
	{
		int x;
		if (par[i] == ' ' && par[i-1] != ' ')
		{
			strncpy(nextWord, par, i-x);
			nextWord[i] = '\0';
			x = i;
		}

		cout << "'" << nextWord << "'" << " cmps with " << "'" << firstWord << "'" << endl; 

		if (strcmp(firstWord, nextWord) == 0)
			cout << nextWord << endl;
	}

	//cout << firstWord;
}
