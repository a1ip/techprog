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

using namespace std;

//Структура "Человек"
struct human
{
	char first_name[40];		 //имя
	char last_name[40];		 //фамилия
	char middle_name[40];		 //отчество
	unsigned int year_of_birth; //год рождения
	unsigned short height;		 //рост
	unsigned short weight;		 //вес
	
public:
	human() 
	{ }
};

//ФУНКЦИИ ФОРМИРОВАНИЯ И ВЫВОДА

	//Формирование массива экземпляров структуры
	human* setHuman(int);
	//Формирование одного экземпляра структуры
	human setOneHuman(int a);
	//Вывод массива экземпляров стркутуры на печать
	int getHuman(human*, int); 

//ФУНКЦИИ ОБРАБОТКИ

	//Удаление экземпляра структуры по указанным свойствам "Рост" и "Вес"
	human* delHW(human*, int&, int, int);
	//Добавление одного экземпляра после указанного свойства "Фамилия"
	human* addAfter(human*, int&, char[]);

//ФУНКЦИИ РАБОТЫ С ДВОИЧНЫМИ ДАННЫМИ

	//Запись в файл массива экземпляров структуры в форме двоичных данных
	int writeHuman(human, FILE*);
	//Чтение из двоичного файла данных в массив эеземпляров структуры
	human readHuman(FILE*);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 8: Блоковый ввод-вывод" << endl;
	cout << "----------------------------------------------" << endl;

	FILE* f;	//указатель, связанный с файлом
	
	//Открытие файла
	f = fopen("f.dat", "w+b");
	if (f == NULL)	//если ошибка
		exit(1);

	int amount;

	cout << "Введите количество человек на добавление: ";
	cin >> amount;

	human* arr = new human [amount]; 
	
	//Запрашиваем данные
	arr = setHuman(amount); 

	//Запись в файл
	for (int i = 0; i < amount; i++)
	{
		if (!writeHuman(arr[i], f))
			exit(1);	
	}

	//Сброс указателя
	rewind(f);

	int i = 0;
	
	//Чтение из файла в массив
	while(!feof(f) && i < amount)
	{
		arr[i] = readHuman(f);
		i++;
	}

	//Вывод данных из массива
	getHuman(arr, amount);
	
	unsigned int height; //вес
	unsigned int weight; //рост

	cout << "----------------------------------------------" << endl;

	//Запрос роста и веса
	cout << "Укажите рост и вес человека, которого нужно удалить\n: " << endl;
	cout << "Рост: "; cin >> height;
	cout << "\nВес: "; cin >> weight;

	arr = delHW(arr, amount, height, weight);
	
	cout << "----------------------------------------------" << endl;

	//Вывод данных из массива
	getHuman(arr, amount);

	char last_name[40];

	//Запрос фамилии
	cout << "Укажите фамилию человека, после которого нужно добавить запись\n: " << endl;
	cin >> last_name;

	arr = addAfter(arr, amount, last_name);
	
	//Вывод данных из массива
	getHuman(arr, amount);

	//Закрываем файл
	fclose(f);

	return 0;
}

human setOneHuman(int i)
{
	human obj;

	cout << "----------------------------------------------\n";
	cout << "Человек (ID = " << i << "): " << endl;
	cout << "----------------------------------------------\n";

	cout << "\nИмя: "; cin >> obj.first_name;
	cout << "Фамилия: "; cin >> obj.last_name;
	cout << "Отчество: "; cin >> obj.middle_name;
	cout << "Год рождения: "; cin >> obj.year_of_birth;
	cout << "Рост: "; cin >> obj.height;
	cout << "Вес: "; cin >> obj.weight;
	cout << endl;
	return obj;
}

human* setHuman(int a)
{
	human* obj;

	for (int i = 0; i < a; i++)
	{
		cout << "----------------------------------------------\n";
		cout << "Человек (ID = " << i << "): " << endl;
		cout << "----------------------------------------------\n";

		cout << "\nИмя: "; cin >> obj[i].first_name;
		cout << "Фамилия: "; cin >> obj[i].last_name;
		cout << "Отчество: "; cin >> obj[i].middle_name;
		cout << "Год рождения: "; cin >> obj[i].year_of_birth;
		cout << "Рост: "; cin >> obj[i].height;
		cout << "Вес: "; cin >> obj[i].weight;
		cout << endl;
	}
	return obj;
}

int getHuman(human* obj, int a) 
{
	if (a == 0)
	{
		cout << "----------------------------------------------\n";
		cout << "Объектов нет" << endl;
		cout << "----------------------------------------------\n";
		return 0;
	}

	for (int i = 0; i < a; i++)
	{
		cout << "----------------------------------------------\n";
		cout << "Человек (ID = " << i << "): " << endl;
		cout << "----------------------------------------------\n";

		cout << "\nИмя: "; cout << obj[i].first_name;
		cout << "\nФамилия: "; cout << obj[i].last_name;
		cout << "\nОтчество: "; cout << obj[i].middle_name;
		cout << "\nГод рождения: "; cout << obj[i].year_of_birth;
		cout << "\nРост: "; cout << obj[i].height;
		cout << "\nВес: "; cout << obj[i].weight;
		cout << endl;
	}

	return 0;
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

human* delHW(human* arr, int& a, int h, int w)
{
	for (int i = 0; i < a; i++)
	{
		if (arr[i].weight == w && arr[i].height == h)
		{
			for (int j = i; j < a - 1; j++)
			{
				arr[j] = arr[j+1];
			}
			//delete [] arr[a];
			a--;
		}
	}
	
	return arr;
}

human* addAfter(human* arr, int& a, char ln[])
{
	human* res = new human [a+1];
	int j = 0;
	
	if (a == 0)
	{
		res[0] = setOneHuman(0);
		a++;
		return res;
	}

	for (int i = 1; i < a; i++)
	{
		if (strcmp(arr[i-1].last_name, ln) == 0)
		{
			res[i] = setOneHuman(i);
			a++;
			for (int j = i + 1; j < a; j++)
			{
				res[j] = arr[j - 1];
			}
			return res;
		}
		else
		{
			res[i] = arr[i]; 
		}
	}
	
	delete &res[a+1];
	return res;
}
