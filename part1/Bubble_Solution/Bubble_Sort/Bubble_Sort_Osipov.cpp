/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 2. Реализации сортировки методом пузырька на языке С++
Среда разработки: Microsoft Visual Studio 2012 
Дата: 26.09.2013
*/

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
void simple_sort(int*, int, int&);
void sort_condition_1(int*, int, int&);
void sort_condition_2(int*, int, int&);
void generate(int*, int, int, int);
void input_fail();
void input (int&, int&, int&);
void copy(int*, int*, int);
bool check_array(int*, int);
void output(int*, int);
void main()
{
	setlocale(LC_ALL,"Russian");
	int n, min, max;
	int k = 0;
	int result;
	bool flag = true;
	bool firsttime = true;
	int *newarray = new int[];
	int *oldarray = new int[];
	while (flag)
	{
		if (firsttime)
		{
			input(n, min, max);
			oldarray = new int[n];
			newarray = new int[n];
			generate(newarray, n, min, max);
			//--
			//Sleep(200);
			generate(oldarray, n, min, max);
			output(oldarray, n);
			output(newarray, n);
			//--
			copy(newarray, oldarray, n);
			cout << "Сгенерированный массив:" << endl;
			output(oldarray, n);
		}
		firsttime = false;
		k = 0;
		cout << endl;
		cout << "Для простой сортировки пузырьком нажмите 1" << endl;
		cout << "Для сортировки пузырьком с первым условием Айверсона нажмите 2" << endl;
		cout << "Для сортировки пузырьком со вторым условием Айверсона нажмите 3" << endl;
		cout << "Для ввода других данных нажмите 4" << endl;
		cout << "Для выхода нажмите 5" << endl;
		cin >> result;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		switch (result)
		{
		case 1:
			{
				copy(oldarray, newarray, n);
				simple_sort(newarray, n, k);
				break;
			}
		case 2:
			{
				copy(oldarray, newarray, n);
				sort_condition_1(newarray, n, k);
				break;
			}
		case 3:
			{
				copy(oldarray, newarray, n);
				sort_condition_2(newarray, n, k);
				break;
			}
		case 4:
			{
				input(n, min, max);
				oldarray = new int[n];
				newarray = new int[n];
				generate(newarray, n, min, max);
				copy(newarray, oldarray, n);
				cout << "Сгенерированный массив:" << endl;
				output(oldarray, n);
				continue;
				break;
			}
		case 5:
			{
				flag = false;
				delete [] oldarray;
				delete [] newarray;
				break;
			}
		default:
			{
				continue;
				break;
			}
		}
		if (flag)
		{
			if (check_array)
			{
				cout << "Сортировка завершена успешно (количество всех итераций: " << k << ")!" << endl;
				cout << "Старый массив:" << endl;
				output(oldarray, n);
				cout << "Отсортированный массив:" << endl;
				output(newarray, n);
			}
			else
			{
				cout << "Что-то пошло не так! Попробуйте еще раз." << endl;
			}
		}
	}
}
void simple_sort(int* arr, int n, int &k)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			k++;
		}
	}
}
void sort_condition_1(int *arr, int n, int &k) 
{
	int temp;
	bool flag = false;
	for (int i = 1; i < n && !flag; i++)
	{
		flag = true;
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = false;
			}
			k++;
		}
	}
}
void sort_condition_2(int *arr, int n, int &k)
{
	int temp, bound, t = n - 1;
	while (t != 0)
	{
		bound = t;
		t = 0;
		for (int j = 0; j < bound; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				t = j;
			}
			k++;
		} 
}
void generate(int *arr, int n, int min, int max)
{
	//srand(time(0));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}
void input_fail()
{
	cin.clear();
	_flushall();
	cout << "Ошибка входных данных!" << endl;
}
void input (int &n, int &min, int &max)
{
	while (true)
	{
		cout << "Введите длину массива(целочисленное значение): ";
		cin >> n;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		cout << "Введите нижнюю границу разброса(целочисленное значение): ";
		cin >> min;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		cout << "Введите верххнюю границу разброса (целочисленное значение): ";
		cin >> max;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		break;
	}
}
void copy(int *srcarr1, int n, int *outarr)
{
	for (int i = 0; i < n; i++)
		outarr[i] = srcarr1[i];
}
bool check_array(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i-1])
		{
			return false;
		}
	}
	return true;
}
void output(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}