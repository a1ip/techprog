// Àëåêñàíäð Ìîëîäûõ, ÔÒ-330801
// Ëàáîðàòîðíàÿ ðàáîòà ¹10. Äèíàìè÷åñêèå ìàññèâû
// Âàðèàíò - 5
/*
Ñîçäàòü òåêñòîâûé ôàéë F1 íå ìåíåå, ÷åì èç 10 ñòðîê è çàïèñàòü â íåãî èíôîðìàöèþ.

5.
	1) 	Ñêîïèðîâàòü èç ôàéëà F1 â ôàéë F2 ñòðîêè, íà÷èíàÿ ñ Ê äî Ê+5.
	2) 	Ïîäñ÷èòàòü êîëè÷åñòâî ãëàñíûõ áóêâ â ôàéëå F2.
*/

#include <iostream>
#include <stdlib.h> //äëÿ rand()
#include <locale>  //äëÿ êèðèëëèöû

using namespace std;

int* form(int);
int* delFrom(int*, int, int, int);
int* addFrom(int*, int, int, int);
void print(int*, int);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Ëàáîðàòîðíàÿ ðàáîòà 10: Äèíàìè÷åñêèå ìàññèâû" << endl;
	cout << "----------------------------------------------" << endl;
	
	int size;

	cout << "Ââåäèòå íà÷àëüíûé ðàçìåð ìàññèâà: ";

	cin >> size;

	int* arr = form(size);
	print(arr, size);

	int n, k;

	cout << "----------------------------------------------" << endl;
	cout << "Ââåäèòå íîìåð ýëåìåíòà, ñ êîòîðîãî íà÷àòü óäàëåíèå:";
	cin >> n;
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ íà óäàëåíèå:";
	cin >> k;
	
	arr = delFrom(arr, size, n, k); 
	size -=k;
	print(arr, size);

	cout << "Ââåäèòå íîìåð ýëåìåíòà, ñ êîòîðîãî íà÷àòü äîáàâëåíèå:";
	cin >> n;
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ íà äîáàâëåíèå:";
	cin >> k;

	arr = addFrom(arr, size, n, k); 
	size +=k;
	print(arr, size);

	return 0;
}

int* form(int s)
{
	int* arr = new int [s];

	for (int i = 0; i < s; i++)
		arr[i] = rand() % 100;

	return arr;
}

int* delFrom(int* a, int s, int n, int k)
{
	if (s - n <= k)
		return NULL;
	
	int *arr = new int [s - k];

	for (int i = 0; i < n; i++)
		{arr[i] = a[i];}
	for (int i = n; i < s - k; i++)
		{arr[i] = a[i+k];}

	return arr;
}

int* addFrom(int* a, int s, int n, int k)
{
	if (n >= k)
		return NULL;
	
	int *arr = new int [s + k];

	for (int i = 0; i < n; i++)
		{arr[i] = a[i];}
	for (int i = n; i < n + k; i++)
		{arr[i] = 0;}
	for (int i = n + k; i < s; i++)
		{arr[i] = 12;}

	return arr;
}

void print (int* arr, int s)
{
	system("cls");
	cout << "------------------------------\n";
	cout << "Òåêóùèé ìàññèâ: " << endl;
	cout << "------------------------------\n";
	for (int i = 0; i < s; i++)
	{
		cout << i << ": " << arr[i] << endl;
	}
}