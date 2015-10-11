// Александр Молодых, ФТ-330801
// Лабораторная работа №8. Блоковый ввод-вывод
// Вариант - 5
/*
Сформировать двоичный файл из элементов, заданной в варианте структуры, 
распечатать его содержимое, выполнить удаление и добавление элементов в 
соответствии со своим вариантом, используя для поиска удаляемых или 
добавляемых элементов функцию. Формирование, печать, добавление и 
удаление элементов оформить в виде функций. Предусмотреть сообщения об 
ошибках при открытии файла и выполнении операций ввода/вывода.

5.	 Структура "Человек":
	-	фамилия, имя, отчество;
	-	год рождения;
	-	рост;
	-	вес.
Удалить все элемент с указанным ростом и весом, добавить элемент после элемента с указанной фамилией.


*/

#include <iostream>
#include <stdio.h> //для gets()
#include <iomanip> //для setw()
#include <locale>  //для кириллицы
#include <string>  //для работы со строками
#include <conio.h>

using namespace std;

struct human
{
	char first_name[40];		//имя
	char last_name[40];			//фамилия
	char middle_name[40];		//отчество
	unsigned int year_of_birth; //год рождения
	unsigned short height;		//рост
	unsigned short weight;		//вес
	
public:
	human() : year_of_birth(0), height(0), weight(0)
	{ }
};

human setHuman();
void getHuman(human); 
int writeHuman(human, FILE*);
human readHuman(FILE*);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 8: Блоковый ввод-вывод" << endl;
	cout << "----------------------------------------------" << endl;

	FILE* f;	//указатель, связанный с файлом

	human arr[10];
	
	//Открытие файла
	f = fopen("f.dat", "w+b");
	if (f == NULL)	//если ошибка
		exit(1);

	int amount;

	cout << "Введите количество человек на добавление (макс. 10): ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Человек (ID = " << i << "): " << endl;
		cout << "----------------------------------------------";
		arr[i] = setHuman();
	}

	for (int i = 0; i < amount; i++)
	{
		if (!writeHuman(arr[i], f))
			exit(1);	
	}

	int i = 0;

	while(!feof(f) && i < amount)
	{
		arr[i] = readHuman(f);
		i++;
	}

	for (int i = 0; i < amount; i++)
	{
		cout << "Человек (ID = " << i << "): " << endl;
		cout << "----------------------------------------------";
		getHuman(arr[i]);
	}

	fclose(f);

	getch();

	return 0;
}

human setHuman()
{
	human obj;

	cout << "\nИмя: "; cin >> obj.first_name;
	cout << "Фамилия: "; cin >> obj.last_name;
	cout << "Отчество: "; cin >> obj.middle_name;
	cout << "Год рождения: "; cin >> obj.year_of_birth;
	cout << "Рост: "; cin >> obj.height;
	cout << "Вес: "; cin >> obj.weight;
	cout << endl;

	return obj;
}

void getHuman(human obj) 
{
	cout << "\nИмя: "; cout << obj.first_name;
	cout << "\nФамилия: "; cout << obj.last_name;
	cout << "\nОтчество: "; cout << obj.middle_name;
	cout << "\nГод рождения: "; cout << obj.year_of_birth;
	cout << "\nРост: "; cout << obj.height;
	cout << "\nВес: "; cout << obj.weight;
	cout << endl;
}

int writeHuman(human h, FILE* f)
{
	fwrite(&h, sizeof(human), 1, f);
	if (ferror(f) == NULL)
		return 1;
	return 0;
}

human readHuman(FILE* f)
{
	human h;
	
	if (f == NULL)
	{
		cout << "ERR: возникла ошибка при чтении файла\n";
		return human();
	}

	fread(&h, sizeof(human),1,f);
	
	return h;
}