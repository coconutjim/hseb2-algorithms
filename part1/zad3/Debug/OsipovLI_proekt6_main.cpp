/*
* ФИО: Николаев Михаил
* Группа: 271ПИ
* Дата: 18/10/2013
* Проект: 6-7
* Название: рекурсивные сортировки
* Среда программирования: Visual Studio 2012
*/

#include "OsipovLI_proekt6_main.h"
#include "OsipovLI_proekt6_sort.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 10; //количество элементов (по умолчанию 10)
	int NT = 1; //количество тестов (по умолчанию 1)
	int count, key; //выбор пункта меню
	int low_bound = 1, high_bound = 10; //нижняя граница (по умолч. 1), верхняя граница (по умолч. 10)
	int a[100][100] = {0}; //массив для хранения значений из файла
	int arr[100] = {0}; //массив для хранения размера каждого массива в файле

	do 
	{
		count = 1;

		ofstream fout("output_proekt6.txt", ios::ate);

		if (!fout)
		{
			cout << "Невозможно открыть файл";
			fout.close();
		}
		fout.close();

		int *p = new int[N];
		int *p_temp = new int[N];

		key = 0;

		//цикл повтора меню
		do
		{
			do
			{
				cout << "Выберете действие: \n";
				cout << "1. Генерировать в программе\n";
				cout << "2. Считать из файла\n";
				cin >> key;

				if (cin.fail())
				{
					cin.clear();
					_flushall();
					cout << "Неверно" << endl;
				}

				if (key == 1 || key == 2)
				{
					break;
				}
			}while (true);

			ifstream fin;
			fin.open("input_proekt6.txt", ios::in);
			
			if (! fin) 
			{ 
				cerr << "\nОшибка! Не удалось найти файл!\n"; 
				system("PAUSE"); 
				exit(1); 
			} 

			switch (key)
			{
			case 1:
				enter_data(N, NT, low_bound, high_bound);

				p = new int[N];
				p_temp = new int[N];

				break;
			case 2:
				if (fin.is_open() && !fin.eof())
				{
					readFile(a, arr, NT);
				}
				else
				{
					cerr << "Невозможно считать из файла\n";
					return;
					key = 0;
				}
				break;
			default:
				break;
			}
			fin.close();
		} while(key < 1 && key > 2);

	srand(time(NULL));	
	if (key != 0)
	{
	for (int i = 0; i < NT; i++) //начало тестов
	{
		
		if (key == 1) //проверка на считывание данных
		{
			cout << "Генерация из программы";
			generate_arr(p, p_temp, low_bound, high_bound, N);
		}
		else
		{
			cout << "Считывание из файла";
			N = arr[i];
			for (int k = 0; k < N; k++)
			{
				p[k] = p_temp[k] = a[i][k];
			}
		}
		
			for (int j = 1; j < 6; j++) //запуск тестов
			{
			switch (j)
			{
			case 1:
				heapSort(p_temp, N);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "Проверка на сортированность: ";
				if (isSorted(p_temp, N))
					cout << "Отсортирован" << endl;
				else
					cout << "Не остортирован" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 2:
				MergeSort(p_temp, 0, N-1);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "Проверка на сортированность: ";
				if (isSorted(p_temp, N))
					cout << "Отсортирован" << endl;
				else
					cout << "Не остортирован" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 3:
				HoarSort_Middle(p_temp, 0, N-1);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "Проверка на сортированность: ";
				if (isSorted(p_temp, N))
					cout << "Отсортирован" << endl;
				else
					cout << "Не остортирован" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 4:
				HoarSort_SecondLeft(p_temp, 0, N-1);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "Проверка на сортированность: ";
				if (isSorted(p_temp, N))
					cout << "Отсортирован" << endl;
				else
					cout << "Не остортирован" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 5:
				HoarSort_Rand(p_temp, N);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "Проверка на сортированность: ";
				if (isSorted(p_temp, N))
					cout << "Отсортирован" << endl;
				else
					cout << "Не остортирован" << endl;

				reEnter_data(p, p_temp, N);

				break;
			default:
				break;
			}
		} 

	}
	}
		delete [] p;
		delete [] p_temp;

		high_bound = 10;
		low_bound = 1;
		N = 10;
		NT = 1;

		cout << "Выберете действие: \n";
		cout << "1. Продолжить\n";
		cout << "Любая клавиша, чтобы выйти\n";
		cin >> count;
		
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "Выход" << endl;
			system("Pause");
			return;
		}

		switch (count) //выход из программы
		{
		case 1:
			break;
		default:
			system("Pause");
			return;
		}

	} while (count == 1);
}

//ввести данные
void enter_data(int &N, int &NT, int &low_bound, int &high_bound)
{
	do
	{
		cout << "NT = ";
		cin >> NT;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "NT имело не верное значение (Будет использоваться значение по умолчанию равное 1)" << endl;
		}
		cout << "N = ";
		cin >> N;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "N имело не верное значение (Будет использоваться значение по умолчанию равное 10)" << endl;
		}
		cout << "Low bound = ";
		cin >> low_bound;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "Нижняя граница имела не верное значение (Будет использоваться значение по умолчанию равное 1)" << endl;
		}
		cout << "High bound = ";
		cin >> high_bound;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "Верхняя граница имела не верное значение (Будет использоваться значение по умолчанию равное 10)" << endl;
		}
	} while (low_bound > high_bound || N <= 0 || NT <= 0 || low_bound <= 0 || high_bound <= 0);
}

//записать во временный массив
void reEnter_data(int *p, int *p_temp, int N)
{
	for (int i = 0; i < N; i++)
	{
		p_temp[i] = p[i];
	}
}

//сгенерировать массив
void generate_arr(int *p, int *p_temp, int low_bound, int high_bound, int N)
{
	cout << endl << "New array:" << endl;
	for (int i = 0; i < N; i++)
	{
		p[i] = low_bound + rand() % (high_bound - low_bound + 1);
		p_temp[i] = p[i];
		cout << p_temp[i] << " ";
	}
	cout << endl;
}

//напечатать массив
void print_arr(int *p, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

//проверка на корректность сортировки
bool isSorted(int *p_temp, int N)
{
	for (int i = 0; i < N-1; i++)
	{
		if (p_temp[i] > p_temp[i+1])
			return false;
	}
	return true;
}

//записать в файл
void writeToFile(int *p, int *p_temp, int N, int NT, int i)
{
	ofstream fout("output_proekt6.txt", ios::app);

	if (!fout)
	{
		cout << "Невозможно открыть файл";
		fout.close();
		return;
	}
	fout << " Тест номер " << NT << "\n";

	switch (i)
	{
	case 1:
		fout << "Пирамидальная сортировка\n";
		break;
	case 2:
		fout << "Сортировка слиянием\n";
		break;
	case 3:
		fout << "Сортировка Хоара с разделителем по середине массива\n";
		break;
	case 4:
		fout << "Сортировка Хоара со вторым разделяющим элементом\n";
		break;
	case 5:
		fout << "Сортировка Хоара со случайным разделяющим элементом\n";
		break;
	default:
		break;
	}

	fout << "До сортировки\n";
	for (int i = 0; i < N; i++)
	{
		fout << p[i] << " ";
	}

	fout << "\nПосле сортировки\n";
	for (int i = 0; i < N; i++)
	{
		fout << p_temp[i] << " ";
	}
	fout << "\n--------------------------\n";
	fout.close(); 
}

//считать из файла
void readFile(int a[100][100], int arr[100], int &NT)
{
	ifstream fin;
	fin.open("input_proekt6.txt", ios::in);
	if (! fin)
	{ 
		cerr << "\nОшибка! Не удалось найти файл!\n";
		system("PAUSE");
		exit(1);
	}
	fin >> NT;
	cout << "Считано количество тестов " << NT << "\n";
	for (int j = 0; j < NT; j++)
	{
		fin >> arr[j];
		for (int i = 0; i < arr[j]; i++) {
			fin >> a[j][i];	
		}
	}
		
	fin.close();
	cout << "Считаны значения";
}