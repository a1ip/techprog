// Александр Молодых, ФТ-330801
// Лабораторная работа №5. Функции и массивы
// Вариант - 5
#include <iostream>
#include <iomanip> //для setw()
#include <locale>  //для кириллицы
#include <math.h>  //для pow()

using namespace std;

#define SX 3
#define SY 3

void clearScreen();
bool isOrthonormal(int* arr);


//Определить является ли матрица ортонормированной, т. е. такой, что скалярное произведение каждой пары 
//различных строк равно 0, а скалярное произведение строки самой на себя равно 1.
int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 5: Функции и массивы" << endl;
	cout << "----------------------------------------------" << endl;

	int arr[SX][SY] = {
						{1,1,1},
						{0,1,0},
						{0,0,1},
					};

	cout << isOrthonormal(&arr[0][0]);

	return 0;
}

bool isOrthonormal(int* arr)
{
	bool result = 1; //результат

	//Перебор матрицы по строкам
	for (int j = 0; j < SY; j++) // для каждой строки
	{
		cout << "iter1: " << setw(10) << j << ": " << endl;
		//сравнение
		for (int jj = 0; jj < SY; jj++) //с каждой строкой
		{	
			cout << "iter2: " << setw(10) << jj << ": ";
			if (jj !=j) //кроме самой себя
			{
				int scal = 0;
				for (int i = 0; i < SX; i++)
				{
					scal += *(arr + i) + SY;
				}
				cout << "scal " << " on " << j << " = " << scal << " | ";
				if (scal != 0)
					result *= 0;
			}
			else //и с собой
			{
				int scal = 0;
				for (int i = 0; i < SX; i++)
				{
					scal += *(arr + i) + SY;
				}
				if (scal != 1)
					result *= 0;
			}
			cout << endl;
		}
	}
	return result;
}

//Функция очистки экрана с приглашением для продолжения работы
void clearScreen()
{
	cout << "Нажмите любую кнопку..." << endl;
	system("pause>nul");
	system("cls");
}