// Àëåêñàíäð Ìîëîäûõ, ÔÒ-330801
// Ëàáîðàòîðíàÿ ðàáîòà ¹5. Ôóíêöèè è ìàññèâû
// Âàðèàíò - 5
#include <iostream>
#include <locale>  //äëÿ êèðèëëèöû

using namespace std;

#define SX 3
#define SY 3

void clearScreen();

void arrPrint(int* arr, int sx, int sy);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr, int sx, int sy);

//Îïðåäåëèòü ÿâëÿåòñÿ ëè ìàòðèöà îðòîíîðìèðîâàííîé, ò. å. òàêîé, ÷òî ñêàëÿðíîå ïðîèçâåäåíèå êàæäîé ïàðû 
//ðàçëè÷íûõ ñòðîê ðàâíî 0, à ñêàëÿðíîå ïðîèçâåäåíèå ñòðîêè ñàìîé íà ñåáÿ ðàâíî 1.
int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Ëàáîðàòîðíàÿ ðàáîòà 5: Ôóíêöèè è ìàññèâû" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "Èñõîäíàÿ ìàòðèöà: " << endl;

	int a[SX][SY] =	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	int* ptr = reinterpret_cast<int*>(a);

	//Âûâîä
	arrPrint(ptr, SX, SY);
	
	//Ïðîâåðêà íà îðòîíîðìèðîâàííîñòü
	if (isOrthonormal(ptr, SX, SY))
		cout << "Ìàòðèöà îðòîíîðìèðîâàíà" << endl;
	else
		cout << "Ìàòðèöà íå îðòîíîðìèðîâàíà" << endl;

	return 0;
}

/*
	Ïðîâåðêà ìàññèâà íà îðòîíîðìèðîâàííîñòü.
	Âû÷èñëÿåò dotProduct - ñêàëÿðíîå ïðîèçâåäåíèå ïàð ñòðîê ìàññèâà arr
	Âîçâðàùàåò 1 â ñëó÷àå, êîãäà ìàòðèöà îðòîíîðìèðîâàíà.
*/
bool isOrthonormal(int* arr, int sx, int sy)
{
	//Ðåçóëüòàò, êîòîðûé ìîæåò áûòü îïðîâåðãíóò öèêëîì óñëîâèé
	bool res = 1;

	//Äâà öèêëà äëÿ 2 ñòðîê
	for (int i = 0; i < sx; i++)
		for (int j = 0; j < sy; j++)
		{
			//äëÿ ïðîèçâåäåíèé 2-õ ðàçíûõ ñòðîê
			if (i != j)
				{
					if (dotProduct(arr, i, j) != 0)
						res = 0;	//îïðîâåðæåíèå ðåçóëüòàòà
				}
			//äëÿ ïðîèçâåäåíèé ñòðîêè ñàìîé íà ñåáÿ
			else
				{
					if (dotProduct(arr, i, j) != 1)
						res = 0;	//îïðîâåðæåíèå ðåçóëüòàòà
				}
		}

	return res;
}

/*
	Âû÷èñëåíèå ñêàëÿðíîãî ïðîèçâåäåíèÿ äëÿ ïàð ñòðîê - A è B
	Âîçâðàùàåò öåëîå ÷èñëî
*/
int dotProduct(int* arr, int A, int B)
{
	//Ðåçóëüòàò
	int res = 0;

	for (int i = 0; i < SX; i++) //äëÿ âñåõ ýëåìåíòîâ ñòðîêè
		res += *(arr + A*SX + i) * *(arr + B*SX + i); //ñêëàäûâàòü èõ ïðîèçâåäåíèÿ
	
	//Ðåçóëüòàò - ñóììà ïðîèçâåäåíèé âñåõ ýëåìåíòîâ ñòðîêè
	return res;
}

/*
	Âûâîä ìàññèâà arr íà ïå÷àòü
*/
void arrPrint(int* arr, int sx, int sy) 
{
	for (int i = 0; i < SX; i++) {
		for (int j = 0; j < SY; j++) {
			cout << *(arr + i*SY + j) << ' ';
		}
		cout << endl;
	}
}

//Ôóíêöèÿ î÷èñòêè ýêðàíà ñ ïðèãëàøåíèåì äëÿ ïðîäîëæåíèÿ ðàáîòû
void clearScreen()
{
	cout << "Íàæìèòå ëþáóþ êíîïêó..." << endl;
	system("pause>nul");
	system("cls");
}