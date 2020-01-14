/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 3. Реализации различных сортировок на языке С++
Среда разработки: Microsoft Visual Studio 2012 
Дата: 03.10.2013
*/

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void insertion_sort(int*, int); 
void binary_insertion_sort(int*, int); 
void counting_sort(int*, int*, int, int); 
void radix_sort_10(int*, int);
void radix_sort_256(int*, int);
void generate(int*, int, int, int);
void input_fail();
void input (int&, int&, int&, int&);
void copy(int*, int*, int);
bool check_array(int*, int);
int find_max(int*, int);
void output(int*, int*, int);
void output_file(int*, int*, int);

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
					//вставка
					insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка вставками" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка вставками" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//бинарная_вставка
					binary_insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка бинарными вставками" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка бинарными вставками" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//подсчет
					counting_sort(newarray, oldarray, N, max);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка подсчётом" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка подсчётом" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					//цифровая10
					radix_sort_10(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: цифровая сортировка по основанию 10" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: цифровая сортировка по основанию 10" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//цифровая256
					radix_sort_256(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: цифровая сортировка по основанию 256" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: цифровая сортировка по основанию 256" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
				}
				break;
			}
		case 2: 
			{
				insideflag = true;
				ifile.open("input_proekt3.txt", ios :: in);
				if (!ifile)
				{
					ifile.clear();
					ifile.close();
					cout << "Ошибка в расположении или имени файла!" << endl;
					cout << "Требуемое имя файла: input_proekt3.txt" << endl;
					cout << endl;
					continue;
				}
				ifile >> NT;
				if (!ifile || ifile.eof() || NT < 1)
				{
					ifile.clear();
					ifile.close();
					cout << "Ошибка в данных внутри файла!" << endl;
					cout << "Все данные должны быть положительными целыми числами." << endl;
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
						cout << "Все данные должны быть положительными целыми числами." << endl;
						cout << endl;
						break;
					}
					oldarray = new int[N];
					newarray = new int[N];
					for (int j = 0; j < N; ++ j)
					{
						ifile >> newarray[j];
						if (!ifile || newarray[j] < 1)
						{
							ifile.clear();
							ifile.close();
							cout << "Ошибка в данных внутри файла!" << endl;
							cout << "Все данные должны быть положительными целыми числами." << endl;
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
					max = find_max(newarray, N);
					copy(newarray, oldarray, N);
					//вставка
					insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка вставками" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка вставками" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//бинарная_вставка
					binary_insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка бинарными вставками" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка бинарными вставками" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//подсчет
					counting_sort(newarray, oldarray, N, max);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: сортировка подсчётом" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: сортировка подсчётом" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					//цифровая10
					radix_sort_10(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: цифровая сортировка по основанию 10" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: цифровая сортировка по основанию 10" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//цифровая256
					radix_sort_256(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "Ошибка в сортировке! Попробуйте еще раз." << endl;
						break;
					}
					cout << "Номер теста: " << i + 1 << endl;
					cout << "Тип сортировки: цифровая сортировка по основанию 256" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "Номер теста: " << i + 1 << endl;
					ofile << "Тип сортировки: цифровая сортировка по основанию 256" << endl;
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

void insertion_sort(int *arr, int n)
{
	int temp, j;
	for (int i = 1; i < n; ++ i)
	{
		temp = arr[i];
		for (j = i - 1; temp < arr[j] && j >= 0; -- j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void binary_insertion_sort(int *arr, int n)
{
	int min, mid, max, temp;
	for (int i = 1; i < n; ++ i)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			min = 0;
			max = i - 1;
			do
			{
				mid = (min + max) / 2;
				if (arr[mid] < temp)
				{
					min = mid + 1;
				}
				else
				{
					max = mid - 1;
				}
			} while (min <= max);
			for (int j = i - 1; j >= min; -- j)
			{
				arr[j + 1] = arr[j];
			}
			arr[min] = temp;
		}
	}
}

void counting_sort(int *arr, int *oldarr, int n, int k)
{
	int *helparr = new int[k + 1];
	for (int i = 0; i <= k; ++ i)
	{
		helparr[i] = 0;
	}
	for (int i = 0; i < n; ++ i)
	{
		++ helparr[oldarr[i]];
	}
	for (int i = 1; i <= k; ++ i)
	{
		helparr[i] += helparr[i - 1];
	}
	for (int i = n - 1; i >= 0; -- i)
	{
		arr[helparr[oldarr[i]] - 1] = oldarr[i];
		-- helparr[oldarr[i]];
	}
	delete [] helparr;
}

void radix_sort_10(int *arr, int n)
{
	int *helparr = new int[n];
	int max = find_max(arr, n);
	int length = 0;
	while (max != 0)
	{
		max /= 10;
		++ length;
	}
	for (int i = 0; i < length; ++ i)
	{
		int temp[10] = {0};
		for (int j = 0; j < n; ++ j)
		{
			++ temp[arr[j] / (int)pow(10, i) % 10];
		}
		for (int j = 1; j < 10; ++ j)
		{
			temp[j] += temp[j - 1];
		}
		for (int j = n - 1; j >= 0; -- j)
		{
			helparr[-- temp[arr[j] / (int)pow(10, i) % 10]] = arr[j];
		}
		for (int j = 0; j < n; ++j)
		{
			arr[j] = helparr[j];
		}
	}
	delete [] helparr;
}

void radix_sort_256(int *arr, int n)
{
	int *helparr = new int[n];
	int length = sizeof(int);
	for (int i = 0; i < length; ++ i)
	{
		int temp[256] = {0};
		for (int j = 0; j < n; ++ j)
		{
			++ temp[arr[j] >> (8 * i) & 255];
		}
		for (int j = 1; j < 256; ++ j)
		{
			temp[j] += temp[j - 1];
		}
		for (int j = n - 1; j >= 0; -- j)
		{
			helparr[-- temp[arr[j] >> (8 * i) & 255]] = arr[j];
		}
		for (int j = 0; j < n; ++j)
		{
			arr[j] = helparr[j];
		}
	}
	delete [] helparr;
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
		cout << "Введите нижнюю границу разброса (целочисленное положительное значение): ";
		cin >> min;
		if (cin.fail() || min < 1)
		{
			input_fail();
			continue;
		}
		cout << "Введите верххнюю границу разброса (целочисленное положительное значение): ";
		cin >> max;
		if (cin.fail() || max < 1 || max < min)
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

int find_max(int* arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; ++ i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
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
	ofile.open("output_proekt3.txt", ios :: app);
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
