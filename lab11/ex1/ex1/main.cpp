// Александр Молодых, ФТ-330801
// Лабораторная работа №11. Информационные динамические структуры
// Вариант - 5
/*
1.	Написать функцию для создания списка. Функция может создавать пустой список, а затем добавлять в него элементы.
2.	Написать функцию для печати списка. Функция должна предусматривать вывод сообщения, если список пустой.
3.	Написать функции для удаления и добавления элементов списка в соответствии со своим вариантом.
4.	Выполнить изменения в списке и печать списка после каждого изменения.
5.	Написать функцию для записи списка в файл.
6.	Написать функцию для уничтожения списка.
7.	Записать список в файл, уничтожить его и выполнить печать (при печати должно быть выдано сообщение "Спи-сок пустой").
8.	Написать функцию для восстановления списка из файла.
9.	Восстановить список и распечатать его.
10.	Уничтожить список.

5).
	5.	Записи в линейном списке содержат ключевое поле типа int. 
		Сформировать однонаправленный список. Удалить из него К элементов, 
		начиная с заданного номера, добавить К элементов, начиная с 
		заданного номера.
*/

#include <iostream>
#include <iomanip>
#include <locale>  //для кириллицы
#include <fstream>  //для работы с файлами
#include <string>

using namespace std;

struct Item
{
	int key;
	Item* ptr;
};

class ItemList
{
	private:
		Item* first;
		unsigned int size;
	public:
		ItemList() : size(0)
		{ first = NULL; }
		
		ItemList(int n) : size(n)
		{
			first = NULL;
			for (int i = 0; i < n; i++)
				addItem(0);
		}

		int addItem(int k);
		int addItem(int, int);
		int delItems(int, int);

		int clear();

		int writeTo(char[]);
		int readFrom(char[]);
		int addItemsFrom(int, int);

		Item* findItem(int);
		void displayAll();
};
//////////////////////////////////////////////////////////////////////////
int ItemList::addItem(int k)
{
	Item* newItem = new Item;
	newItem->key = k;
	newItem->ptr = first;
	first = newItem;
	size++;

	return 0;
}
int ItemList::addItem(int n, int k)
{
	if (n == 0)
	{
		return addItem(k);
	}
	
	Item* leftItem = findItem(n);
	Item* rightItem = findItem(n-1);

	if (leftItem == NULL || rightItem == NULL)
		return 1;

	Item* newItem = new Item;
	newItem->key = k;
	newItem->ptr = leftItem;
	rightItem->ptr = newItem;
	size++;

	return 0;
}
int ItemList::delItems(int n, int k)
{
	if (n + k > size) 
		return 1;

	Item* leftItem = findItem(n-1);
	Item* rightItem = findItem(n+k);

	if (n == 0)
	{
		first = rightItem;
	}
	else
		leftItem->ptr = rightItem;

	size -= k;
	
	//удаление объектов???

	return 0;
}
Item* ItemList::findItem(int n)
{
	Item* current = first;

	if (n > size || n < 0)
		return NULL;

	for (int i = 0; i < n; i++)
	{
		current = current->ptr;
	}

	return current;
}
//////////////////////////////////////////////////////////////////////////
int ItemList::clear()
{
	this->delItems(0, this->size);
	return 0;
}
//////////////////////////////////////////////////////////////////////////
int ItemList::writeTo(char* fn)
{
	Item* current = first;
	int i = 0;
	
	ofstream fout(fn);

	while(current)
	{
		fout << current->key << endl;
		current = current->ptr;
	}

	fout.close();

	return 0;
}
int ItemList::readFrom(char* fn)
{
	ifstream fin(fn);
	
	string data;

	while(!fin.eof())
	{
		getline(fin, data);
		if (data != "\0")
			addItem(atoi(data.c_str()));
	}

	fin.close();

	return 0;
}
int ItemList::addItemsFrom(int n, int k)
{
	if (n > size)
		return 1;

	for (int i = k-1; i >= 0; i--)
	{
		int x = 1 + rand() % 100;
		addItem(n, i);
	}

	return 0;
}
void ItemList::displayAll()
{
	Item* current = first;
	int i = 0;
	
	if(first == NULL)
		cout << "Список пуст.\n";
	else
	{
		cout << setw(8) << "+-------" << "+" << setw(8) << "--------" << "+" << setw(12) << "-----------+" << endl;
		cout << setw(8) << "| Номер " << "|" << setw(8) << "  Знач. " << "|" << setw(12) << "   Ук. на  |" << endl;
		cout << setw(8) << "+-------" << "+" << setw(8) << "--------" << "+" << setw(12) << "-----------+" << endl;
	}

	while(current)
	{
		cout << "|" << setw(7) << i++ << "|" << setw(8) << current->key << "|" << setw(11) << current->ptr << "|" << endl;
		current = current->ptr;
	}

	cout << setw(8) << "+-------" << "-" << setw(8) << "--------" << "-" << setw(12) << "-----------+" << endl;
	cout << "|Число элементов: " << setw(11) << size << '|' << endl;
	cout << setw(8) << "+-------" << "-" << setw(8) << "--------" << "-" << setw(12) << "-----------+" << endl;
}
//////////////////////////////////////////////////////////////////////////
void clearScreen(char* title);
//////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Russian");

	int length, delNum, delPos,
				addNum, addPos;

	cout << "Лабораторная работа №11: Информационные динамические структуры" << endl;
	
	cout << "-----------------------------------------\n"
		 << "Введите размер списка (0, если нужен пустой):";

	cin >> length;

	ItemList il1(0);
	il1.addItemsFrom(0, length);

	clearScreen("Сформированный список:");

	il1.displayAll();

	cout << "Введите позицию удаления(включительно): "; cin >> delPos;
	cout << "Введите число элементов к удалению: "; cin >> delNum;
	
	il1.delItems(delPos, delNum);

	clearScreen("Cписок после удаления элементов: ");

	il1.displayAll();

	cout << "Введите позицию добавления: "; cin >> addPos;
	cout << "Введите число элементов к добавлению: "; cin >> addNum;
	
	il1.addItemsFrom(addPos, addNum);

	clearScreen("Cписок после удаления элементов: ");

	il1.displayAll();

	cout << "Запись файла в список...\n";
	il1.writeTo("file1.txt");
	cout << "Уничтожение списка...\n";
	il1.clear();
	
	clearScreen("Список уничтожен:");

	il1.displayAll();

	cout << "Чтение списка из файла...";

	il1.readFrom("file1.txt");

	clearScreen("Cписок прочитан:");

	il1.displayAll();

	il1.clear();
	
	clearScreen("Список уничтожен:");

	il1.displayAll();

	return 0;
}

void clearScreen(char* title)
{
	system("pause");
	cout << "-----------------------------------------\n";
	cout << title << endl;
}