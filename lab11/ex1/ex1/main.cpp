// ��������� �������, ��-330801
// ������������ ������ �11. �������������� ������������ ���������
// ������� - 5
/*
1.	�������� ������� ��� �������� ������. ������� ����� ��������� ������ ������, � ����� ��������� � ���� ��������.
2.	�������� ������� ��� ������ ������. ������� ������ ��������������� ����� ���������, ���� ������ ������.
3.	�������� ������� ��� �������� � ���������� ��������� ������ � ������������ �� ����� ���������.
4.	��������� ��������� � ������ � ������ ������ ����� ������� ���������.
5.	�������� ������� ��� ������ ������ � ����.
6.	�������� ������� ��� ����������� ������.
7.	�������� ������ � ����, ���������� ��� � ��������� ������ (��� ������ ������ ���� ������ ��������� "���-��� ������").
8.	�������� ������� ��� �������������� ������ �� �����.
9.	������������ ������ � ����������� ���.
10.	���������� ������.

5).
	5.	������ � �������� ������ �������� �������� ���� ���� int. 
		������������ ���������������� ������. ������� �� ���� � ���������, 
		������� � ��������� ������, �������� � ���������, ������� � 
		��������� ������.
*/

#include <iostream>
#include <iomanip>
#include <locale>  //��� ���������
#include <fstream>  //��� ������ � �������
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
	
	//�������� ��������???

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
		cout << "������ ����.\n";
	else
	{
		cout << setw(8) << "+-------" << "+" << setw(8) << "--------" << "+" << setw(12) << "-----------+" << endl;
		cout << setw(8) << "| ����� " << "|" << setw(8) << "  ����. " << "|" << setw(12) << "   ��. ��  |" << endl;
		cout << setw(8) << "+-------" << "+" << setw(8) << "--------" << "+" << setw(12) << "-----------+" << endl;
	}

	while(current)
	{
		cout << "|" << setw(7) << i++ << "|" << setw(8) << current->key << "|" << setw(11) << current->ptr << "|" << endl;
		current = current->ptr;
	}

	cout << setw(8) << "+-------" << "-" << setw(8) << "--------" << "-" << setw(12) << "-----------+" << endl;
	cout << "|����� ���������: " << setw(11) << size << '|' << endl;
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

	cout << "������������ ������ �11: �������������� ������������ ���������" << endl;
	
	cout << "-----------------------------------------\n"
		 << "������� ������ ������ (0, ���� ����� ������):";

	cin >> length;

	ItemList il1(0);
	il1.addItemsFrom(0, length);

	clearScreen("�������������� ������:");

	il1.displayAll();

	cout << "������� ������� ��������(������������): "; cin >> delPos;
	cout << "������� ����� ��������� � ��������: "; cin >> delNum;
	
	il1.delItems(delPos, delNum);

	clearScreen("C����� ����� �������� ���������: ");

	il1.displayAll();

	cout << "������� ������� ����������: "; cin >> addPos;
	cout << "������� ����� ��������� � ����������: "; cin >> addNum;
	
	il1.addItemsFrom(addPos, addNum);

	clearScreen("C����� ����� �������� ���������: ");

	il1.displayAll();

	cout << "������ ����� � ������...\n";
	il1.writeTo("file1.txt");
	cout << "����������� ������...\n";
	il1.clear();
	
	clearScreen("������ ���������:");

	il1.displayAll();

	cout << "������ ������ �� �����...";

	il1.readFrom("file1.txt");

	clearScreen("C����� ��������:");

	il1.displayAll();

	il1.clear();
	
	clearScreen("������ ���������:");

	il1.displayAll();

	return 0;
}

void clearScreen(char* title)
{
	system("pause");
	cout << "-----------------------------------------\n";
	cout << title << endl;
}