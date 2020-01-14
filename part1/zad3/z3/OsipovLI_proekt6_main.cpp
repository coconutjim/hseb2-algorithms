/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 6-7. Реализации различных рекурсивных сортировок на языке С++
Среда разработки: Microsoft Visual Studio 2012 
Дата: 18.10.2013
*/


#include <iostream>
#include <fstream>
#include <ctime>
#include "OsipovLI_proekt6_main.h"
#include "OsipovLI_proekt6_sort.h"
using namespace std;

ofstream ofile;
ifstream ifile;

void main() 
{
	setlocale(LC_ALL,"Russian");
	int N, NT, min, max, result;
	int *newarray, *oldarray;
	bool flag = true;
	bool insideflag = true;
	srand(time(NULL));
	newarray = new int[1];
	oldarray = new int[1];
	while (flag)
	{
		cout << "Для ввода данных с клавиатуры нажмите 1" << endl;
		cout << "Для чтения данных из файла нажмите 2" << endl;
		cout << "Для выхода нажмите 3" << endl;
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
				input(NT, N, min, max);
				oldarray = new int[N];
				newarray = new int[N];
				for (int i = 0; i < NT; ++ i)
				{
					generate(newarray, N, min, max);
					copy(newarray, oldarray, N);
					//слияние
					merge_sort(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка слиянием" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка слиянием" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//пирамидальная
					heap_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: пирамидальная сортировка" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: пирамидальная сортировка" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//Хоара_1
					Hoare_sort_1(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка Хоара (разделительный элемент - средний)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка Хоара (разделительный элемент - средний)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//Хоара_2
					Hoare_sort_2(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка Хоара (разделительный элемент - второй слева)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка Хоара (разделительный элемент - второй слева)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//Хоара_3
					Hoare_sort_3(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка Хоара (разделительный элемент - случайный)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка Хоара (разделительный элемент - случайный)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
				}
				break;
			}
		case 2: 
			{
				insideflag = true;
				ifile.open("input_proekt6.txt", ios :: in);
				if (!ifile)
				{
					ifile.clear();
					ifile.close();
					cout << "Ошибка в расположении или имени файла!" << endl;
					cout << "Требуемое имя файла: input_proekt6.txt" << endl;
					cout << endl;
					continue;
				}
				ifile >> NT;
				if (!ifile || ifile.eof() || NT < 1)
				{
					ifile.clear();
					ifile.close();
					cout << "Ошибка в данных внутри файла!" << endl;
					cout << "Проверьте корректность данных. Количество тестов и размеры массивов" << endl;
					cout << "должны быть целыми и положительными числами, а члены массивов - целыми числами." << endl;
					cout << endl;
					continue;
				}
				for (int i = 0; i < NT; ++ i)
				{
					ifile >> N;
					if (!ifile || N < 1)
					{
						ifile.clear();
						ifile.close();
						cout << "Ошибка в данных внутри файла!" << endl;
						cout << "Проверьте корректность данных. Количество тестов и размеры массивов" << endl;
						cout << "должны быть целыми и положительными числами, а члены массивов - целыми числами." << endl;
						cout << endl;
						break;
					}
					oldarray = new int[N];
					newarray = new int[N];
					for (int j = 0; j < N; ++ j)
					{
						ifile >> newarray[j];
						if (!ifile)
						{
							ifile.clear();
							ifile.close();
							cout << "Ошибка в данных внутри файла!" << endl;
							cout << "Проверьте корректность данных. Количество тестов и размеры массивов" << endl;
							cout << "должны быть целыми и положительными числами, а члены массивов - целыми числами." << endl;
							cout << endl;
							insideflag = false;
							break;
						}
					}
					if (! insideflag)
					{
						break;
					}
					copy(newarray, oldarray, N);
					//слияние
					merge_sort(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка слиянием" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка слиянием" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//пирамидальная
					heap_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: пирамидальная сортировка" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: пирамидальная сортировка" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//Хоара_1
					Hoare_sort_1(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка Хоара (разделительный элемент - средний)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка Хоара (разделительный элемент - средний)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//Хоара_2
					Hoare_sort_2(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка Хоара (разделительный элемент - второй слева)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка Хоара (разделительный элемент - второй слева)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//Хоара_3
					Hoare_sort_3(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка Хоара (разделительный элемент - случайный)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка Хоара (разделительный элемент - случайный)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
				}
				ifile.close();
				break;
			}
		case 3: 
			{
				flag = false;
				break;
			}
		default:
			{
				break;
			}
		}
	}
	delete [] oldarray;
	delete [] newarray;
}

void generate(int *arr, int n, int min, int max)
{
	for (int i = 0; i < n; ++ i)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void input_fail()
{
	cin.clear();
	_flushall();
	cout << "Ошибка входных данных!" << endl;
	cout << endl;
}

void input (int &nt, int &n, int &min, int &max)
{
	while (true)
	{
		cout << "Введите количество тестов (целочисленное положительное значение): ";
		cin >> nt;
		if (cin.fail() || nt < 1)
		{
			input_fail();
			continue;
		}
		cout << "Введите длину массива (целочисленное положительное значение): ";
		cin >> n;
		if (cin.fail()  || n < 1)
		{
			input_fail();
			continue;
		}
		cout << "Введите нижнюю границу разброса (целочисленное значение): ";
		cin >> min;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		cout << "Введите верххнюю границу разброса (целочисленное значение): ";
		cin >> max;
		if (cin.fail() || max < min)
		{
			input_fail();
			continue;
		}
		break;
	}
}

void copy(int *srcarr, int *outarr, int n)
{
	for (int i = 0; i < n; ++ i)
	{
		outarr[i] = srcarr[i];
	}
}

bool check_array(int *arr, int n)
{
	for (int i = 1; i < n; ++ i)
	{
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}

void output(int *oldarr, int *newarr, int n)
{
	cout << "Старый массив:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		cout << oldarr[i] << " ";
	}
	cout << endl;
	cout << "Отсортированный массив:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		cout << newarr[i] << " ";
	}
	cout << endl;
	cout << endl;
}

void output_file(int *oldarr, int *newarr, int n)
{
	ofile.open("output_proekt6.txt", ios :: app);
	ofile << "Старый массив:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		ofile << oldarr[i] << " ";
	}
	ofile << endl;
	ofile << "Отсортированный массив:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		ofile << newarr[i] << " ";
	}
	ofile << endl;
	ofile << endl;
	ofile.close();
}