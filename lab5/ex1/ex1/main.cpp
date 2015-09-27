// Александр Молодых, ФТ-330801
// Лабораторная работа №5. Функции и массивы
// Вариант - 5
#include <iostream>
#include <locale>  //для кириллицы

using namespace std;

#define SX 3
#define SY 3

void clearScreen();

void arrPrint(int* arr);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr);


//Определить является ли матрица ортонормированной, т. е. такой, что скалярное произведение каждой пары 
//различных строк равно 0, а скалярное произведение строки самой на себя равно 1.
int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "Лабораторная работа 5: Функции и массивы" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "Исходная матрица: " << endl;

	int a[SX][SY] =	{
		{1,0,0},
		{0,1,0},
		{0,0,2}
	};

	//Вывод
	arrPrint(&a[0][0]);
	
	//Проверка на ортонормированность
	cout << endl << isOrthonormal(&a[0][0]) << endl;

	return 0;
}

/*
	Проверка массива на ортонормированность.
	Вычисляет dotProduct - скалярное произведение пар строк массива arr
	Возвращает 1 в случае, когда матрица ортонормирована.
*/
bool isOrthonormal(int* arr)
{
	//Результат, который может быть опровергнут циклом условий
	bool res = 1;

	//Два цикла для 2 строк
	for (int i = 0; i < SX; i++)
		for (int j = 0; j < SY; j++)
		{
			//для произведений 2-х разных строк
			if (i != j)
				{
					if (dotProduct(&arr[0], i, j) != 0)
						res = 0;	//опровержение результата
				}
			//для произведений строки самой на себя
			else
				{
					if (dotProduct(&arr[0], i, j) != 1)
						res = 0;	//опровержение результата
				}
		}

	return res;
}

/*
	Вычисление скалярного произведения для пар строк - A и B
	Возвращает целое число
*/
int dotProduct(int* arr, int A, int B)
{
	//Результат
	int res = 0;

	for (int i = 0; i < SX; i++) //для всех элементов строки
		res += *(arr + A*SX + i) * *(arr + B*SX + i); //складывать их произведения
	
	//Результат - сумма произведений всех элементов строки
	return res;
}

/*
	Вывод массива arr на печать
*/
void arrPrint(int* arr) 
{
	for (int i = 0; i < SX; i++) {
		for (int j = 0; j < SY; j++) {
			cout << *(arr + i*SY + j) << ' ';
		}
		cout << endl;
	}
}

//Функция очистки экрана с приглашением для продолжения работы
void clearScreen()
{
	cout << "Нажмите любую кнопку..." << endl;
	system("pause>nul");
	system("cls");
}