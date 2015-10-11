// Александр Молодых, ФТ-330801
// Лабораторная работа №5. Функции и массивы
// Вариант - 5
#include <iostream>
#include <locale>  //для кириллицы

using namespace std;

#define SX 3
#define SY 3

void clearScreen();

<<<<<<< HEAD
void arrPrint(int* arr, int sx, int sy);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr, int sx, int sy);
=======
void arrPrint(int* arr);
int dotProduct(int* arr, int A, int B);
bool isOrthonormal(int* arr);
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2


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
<<<<<<< HEAD
		{0,0,1}
	};

	//Вывод
	arrPrint(a, SX, SY);
	
	//Проверка на ортонормированность
	if (isOrthonormal(a, SX, SY))
		cout << "Матрица ортонормирована" << endl;
	else
		cout << "Матрица не ортонормирована" << endl;
=======
		{0,0,2}
	};

	//Вывод
	arrPrint(&a[0][0]);
	
	//Проверка на ортонормированность
	cout << endl << isOrthonormal(&a[0][0]) << endl;
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2

	return 0;
}

/*
	Проверка массива на ортонормированность.
	Вычисляет dotProduct - скалярное произведение пар строк массива arr
	Возвращает 1 в случае, когда матрица ортонормирована.
*/
<<<<<<< HEAD
bool isOrthonormal(int* arr, int sx, int sy)
=======
bool isOrthonormal(int* arr)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
{
	//Результат, который может быть опровергнут циклом условий
	bool res = 1;

	//Два цикла для 2 строк
<<<<<<< HEAD
	for (int i = 0; i < sx; i++)
		for (int j = 0; j < sy; j++)
=======
	for (int i = 0; i < SX; i++)
		for (int j = 0; j < SY; j++)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
		{
			//для произведений 2-х разных строк
			if (i != j)
				{
<<<<<<< HEAD
					if (dotProduct(arr, i, j) != 0)
=======
					if (dotProduct(&arr[0], i, j) != 0)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
						res = 0;	//опровержение результата
				}
			//для произведений строки самой на себя
			else
				{
<<<<<<< HEAD
					if (dotProduct(arr, i, j) != 1)
=======
					if (dotProduct(&arr[0], i, j) != 1)
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
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
<<<<<<< HEAD
void arrPrint(int* arr, int sx, int sy) 
=======
void arrPrint(int* arr) 
>>>>>>> 4fb4e41a6c650045df4380379c6112c3fa6c2df2
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