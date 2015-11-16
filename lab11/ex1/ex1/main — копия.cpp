// Àëåêñàíäð Ìîëîäûõ, ÔÒ-330801
// Ëàáîðàòîðíàÿ ðàáîòà ¹11. Èíôîðìàöèîííûå äèíàìè÷åñêèå ñòðóêòóðû
// Âàðèàíò - 5
/*
1.	Íàïèñàòü ôóíêöèþ äëÿ ñîçäàíèÿ ñïèñêà. Ôóíêöèÿ ìîæåò ñîçäàâàòü ïóñòîé ñïèñîê, à çàòåì äîáàâëÿòü â íåãî ýëåìåíòû.
2.	Íàïèñàòü ôóíêöèþ äëÿ ïå÷àòè ñïèñêà. Ôóíêöèÿ äîëæíà ïðåäóñìàòðèâàòü âûâîä ñîîáùåíèÿ, åñëè ñïèñîê ïóñòîé.
3.	Íàïèñàòü ôóíêöèè äëÿ óäàëåíèÿ è äîáàâëåíèÿ ýëåìåíòîâ ñïèñêà â ñîîòâåòñòâèè ñî ñâîèì âàðèàíòîì.
4.	Âûïîëíèòü èçìåíåíèÿ â ñïèñêå è ïå÷àòü ñïèñêà ïîñëå êàæäîãî èçìåíåíèÿ.
5.	Íàïèñàòü ôóíêöèþ äëÿ çàïèñè ñïèñêà â ôàéë.
6.	Íàïèñàòü ôóíêöèþ äëÿ óíè÷òîæåíèÿ ñïèñêà.
7.	Çàïèñàòü ñïèñîê â ôàéë, óíè÷òîæèòü åãî è âûïîëíèòü ïå÷àòü (ïðè ïå÷àòè äîëæíî áûòü âûäàíî ñîîáùåíèå "Ñïè-ñîê ïóñòîé").
8.	Íàïèñàòü ôóíêöèþ äëÿ âîññòàíîâëåíèÿ ñïèñêà èç ôàéëà.
9.	Âîññòàíîâèòü ñïèñîê è ðàñïå÷àòàòü åãî.
10.	Óíè÷òîæèòü ñïèñîê.

5).
	5.	Çàïèñè â ëèíåéíîì ñïèñêå ñîäåðæàò êëþ÷åâîå ïîëå òèïà int. 
		Ñôîðìèðîâàòü îäíîíàïðàâëåííûé ñïèñîê. Óäàëèòü èç íåãî Ê ýëåìåíòîâ, 
		íà÷èíàÿ ñ çàäàííîãî íîìåðà, äîáàâèòü Ê ýëåìåíòîâ, íà÷èíàÿ ñ 
		çàäàííîãî íîìåðà.
*/

#include <iostream>
#include <iomanip>
#include <locale>  //äëÿ êèðèëëèöû
#include <fstream>  //äëÿ ðàáîòû ñ ôàéëàìè
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
	
	//Item* current = findItem(n);

	//delete current;

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
		cout << "Ñïèñîê ïóñò.\n";
	else
	{
		cout << setw(8) << "+-------" << "+" << setw(8) << "--------" << "+" << setw(12) << "-----------+" << endl;
		cout << setw(8) << "| Íîìåð " << "|" << setw(8) << "  Çíà÷. " << "|" << setw(12) << "   Óê. íà  |" << endl;
		cout << setw(8) << "+-------" << "+" << setw(8) << "--------" << "+" << setw(12) << "-----------+" << endl;
	}

	while(current)
	{
		cout << "|" << setw(7) << i++ << "|" << setw(8) << current->key << "|" << setw(11) << current->ptr << "|" << endl;
		current = current->ptr;
	}

	cout << setw(8) << "+-------" << "-" << setw(8) << "--------" << "-" << setw(12) << "-----------+" << endl;
	cout << "|×èñëî ýëåìåíòîâ: " << setw(11) << size << '|' << endl;
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

	cout << "Ëàáîðàòîðíàÿ ðàáîòà ¹11: Èíôîðìàöèîííûå äèíàìè÷åñêèå ñòðóêòóðû" << endl;
	
	cout << "-----------------------------------------\n"
		 << "Ââåäèòå ðàçìåð ñïèñêà (0, åñëè íóæåí ïóñòîé):";

	cin >> length;

	ItemList il1(0);
	il1.addItemsFrom(0, length);

	clearScreen("Ñôîðìèðîâàííûé ñïèñîê:");

	il1.displayAll();

	cout << "Ââåäèòå ïîçèöèþ óäàëåíèÿ(âêëþ÷èòåëüíî): "; cin >> delPos;
	cout << "Ââåäèòå ÷èñëî ýëåìåíòîâ ê óäàëåíèþ: "; cin >> delNum;
	
	il1.delItems(delPos, delNum);

	clearScreen("Cïèñîê ïîñëå óäàëåíèÿ ýëåìåíòîâ: ");

	il1.displayAll();

	cout << "Ââåäèòå ïîçèöèþ äîáàâëåíèÿ: "; cin >> addPos;
	cout << "Ââåäèòå ÷èñëî ýëåìåíòîâ ê äîáàâëåíèþ: "; cin >> addNum;
	
	il1.addItemsFrom(addPos, addNum);

	clearScreen("Cïèñîê ïîñëå óäàëåíèÿ ýëåìåíòîâ: ");

	il1.displayAll();

	cout << "Çàïèñü ôàéëà â ñïèñîê...\n";
	il1.writeTo("file1.txt");
	cout << "Óíè÷òîæåíèå ñïèñêà...\n";
	il1.clear();
	
	clearScreen("Ñïèñîê óíè÷òîæåí:");

	il1.displayAll();

	cout << "×òåíèå ñïèñêà èç ôàéëà...";

	il1.readFrom("file1.txt");

	clearScreen("Cïèñîê ïðî÷èòàí:");

	il1.displayAll();

	il1.clear();
	
	clearScreen("Ñïèñîê óíè÷òîæåí:");

	il1.displayAll();

	return 0;
}

void clearScreen(char* title)
{
	system("pause");
	cout << "-----------------------------------------\n";
	cout << title << endl;
}