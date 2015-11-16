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

#define BUF_SIZE 256

int wordCount(char* sentence);

char** wordList(char* sentence, int itemsNum);

int wordEntry(char** list, char* word, int itemsNum);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 6: Строки" << endl;
	cout << "----------------------------------------------" << endl;

	//Исходное предложение:
	char* paragraph = "   трижды  два - шесть, трижды   три - девять, трижды Герой Советского Союза .";

	cout << "Вы ввели: " << paragraph << endl;
	cout << "----------------------------------------------" << endl;

	//Подсчёт количества слов:
	int words = wordCount(paragraph);

	//Форирование списка слов:
	char** list = wordList(paragraph, words);

	//Число совпадений слов списка с первым словом из него:
	int entries = wordEntry(list, list[0], words);

	cout << "Число слов, совпадающих с первым словом '" << list[0] << "' строки: " << entries << endl;

	return 0;
}

/*
Подсчитывает число слов в предложении
*/
int wordCount(char* sentence)
{
	int count = 0;	//счётчик слов
	
	//Цикл по всему предложению:
	int i = 0;	//счётчик цикла
	do 
	{	
		//Условие проверки конца слова:
		if ((sentence[i+1] == ' ' && (sentence[i] != '.') && (sentence[i] != ' ')) || (sentence[i+1] == '.' && (sentence[i] != '.') && (sentence[i] != ' ')))
		{
			count++;
		}
		i++;

	} while (sentence[i] != '.' && sentence[i+1] != '\0' );

	return count;
}

/*
Формирует список слов из одного преложения
*/
char** wordList(char* sentence, int itemsNum)
{
	char** list;	//список результатов

	list = new char* [itemsNum];	//выделяем память под сам список
	
	//Цикл по всему предложению:
	int i = 0;		//счётчик цикла
	int count = 0;	//счётчик слов
	char* buf = new char [BUF_SIZE];	//выделяем буфер для слова
	do 
	{		
		//Если слово началось:
		if (sentence[i] != ' ' && sentence[i] != '.')
		{	
			int j = i;	//фиксируем позицию начала слова
			//Цикл по одному слову:
			do 
			{
				buf[j-i] = sentence[j];	//заполняем буфер посимвольно
				j++;					//смещаем позицию
			} while (sentence[j] != ' ' && sentence[j] != '.');

			buf[j - i] = 0;				//j-i - последняя позиция в слове
			list[count] = new char [j - i + 1];	//выделяем память для слова в списке: 
												//j-i+1 - длина слова с учётом терминального нуля
			strcpy(list[count++], buf);	//копируем из буфера в список

			i = j;	//"проматываем" счётчик на следующий последний символ слова
		}
		i++;
	} while (sentence[i] != '.' && sentence[i+1] != '\0' );

	//возврат указателя на список
	return list;
}

/*
Подсчитывает количество совпадений слова в списке
*/
int wordEntry(char** list, char* word, int itemsNum)
{
	int entryCount = 0;	//счётчик количества совпадений

	//Цикл по всему списку:
	for (int i = 0; i < itemsNum; i++)
	{
		//Если слова равны
		if (!strcmp(list[i], word))
		{
			entryCount++;	//увеличить счётчик
		}
	}

	return entryCount;
}