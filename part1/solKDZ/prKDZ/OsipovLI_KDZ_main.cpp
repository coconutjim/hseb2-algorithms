/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Контрольное домашнее задание
Среда разработки: Microsoft Visual Studio 2012 
Дата: 15.12.2013
*/


#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include<Windows.h>
#include "OsipovLI_KDZ_main.h"
#include "OsipovLI_KDZ_sort.h"
using namespace std;
typedef void (*Sort) (int*, int);
typedef void (*Gen) (int*, int);

ofstream f;

void main() {
	setlocale(LC_ALL,"Russian");
	LARGE_INTEGER frequency;
	LARGE_INTEGER startTime;
	LARGE_INTEGER elapsedTime;
	double min;
	double max;
	double average;
	double temp;
	int *starray; // эталоный массив
	int *wrkarray; // рабочий массив
	Sort sorts[12] = { simple_bubble_sort, bubble_sort_condition_1, bubble_sort_condition_2, // массив сортировок
		insertion_sort, binary_insertion_sort, countingS_adapter, radix_sort_16, 
		mergeS_adapter, heap_sort, Hoare1S_adapter, Hoare2S_adapter, Hoare3S_adapter };
	Gen generators[5] = { generate2to2, generate0toMax, sorted, close_to_sorted, reversed_sort }; // виды генерации  массивов
	string sText[12] = { "Сортировка пузырьком", "Сортировка пузырьком c первым условием Айверсона", "Сортировка пузырьком cо вторым условием Айверсона", 
	"Сортировка вставками", "Сортировка бинарными вставками", "Сортировка подсчетом", "Цифровая сортировка (основание 16)",
	"Сортировка слиянием", "Пирамидальная сортировка", "Сортировка Хоара по среднему элементу", 
	"Сортировка Хоара по второму элементу", "Сортировка Хоара по случайному элементу" };
	string gText[5] = { "Массив с элементами от -2 до 2", "Массив с элементами от 0 до INT_MAX", "Сортированный массив (элементы от 0 до 1000)",
	"Почти отсортированный массив (элементы от 0 до 1000)", "Обратно сортированный массив (элементы от 0 до 1000)" };
	double t1, t2;
	cout << "Работа началась. Пожалуйста, подождите. Нужно около четырех-семи минут." << endl;
	t1 = clock();
	f.open("OsipovLI_output_KDZ.txt", ios :: app);
	for (int i = 0; i < 12; ++ i) { // цикл по видам сортировок
		for (int j = 0; j < 5; ++ j) { // цикл по видам массивов
			if (  ! ( (i == 5 && (j == 0 || j == 1)) || (i == 6 && j == 0) ) ) { // случаи, не требующие рассмотрения
				for (int k = 1000; k <= 8000; k += 1000) { // цикл по длинам массивов
					starray = new int[k];
					wrkarray = new int[k];
					min = INT_MAX;
					max = 0;
					average = 0;
					generators[j](starray, k); // генерация нужного массива
					f << "Длина массива: " << k << endl;
					f << gText[j] << endl;
					f << sText[i] << endl;
					/* Проверка на работоспособность сортировки и прогонка функции для оптимизации */
					copy(starray, wrkarray, k);
					sorts[i](wrkarray, k);
					if (! test_arr(wrkarray, k)) { // проверка на отсортированность
						cout << endl;
						cout << sText[i] << endl;
						cout << " при типе массива " << gText[i] << endl;
						cout << " и длине массива " << k << " не работает. Программа завершится." << endl;
						system("pause"); 
						return; 
						f.close();
					}
					f << "Работоспособность сортировки проверена." << cout << endl;
					for (int x = 0; x < 3; ++ x) { // прогонка функции для оптимизации
						copy(starray, wrkarray, k);
						sorts[i](wrkarray, k); 
					}
					/* Замеры времени */
					for (int x = 0; x < 20; ++ x) {
						copy(starray, wrkarray, k); // копирование эталонного массива в рабочий
						QueryPerformanceFrequency(&frequency); // измерение частоты
							QueryPerformanceCounter(&startTime); 
						sorts[i](wrkarray, k); // непосредственно сортировка
						QueryPerformanceCounter(&elapsedTime); 
						temp = (double)(elapsedTime.QuadPart - startTime.QuadPart) * 1000000000 
							/ frequency.QuadPart; // нахождение текущего интервала
						if (temp > max) {
							max = temp; // поиск максимального интервала
						}
						if (temp < min) {
							min = temp; // поиск минимального интервала
						}
						average += temp;
					}
					average /= 20; // нахождение среднего интервала
					f << endl;
					f << fixed << "Минимальное время выполнения: " << min << endl;
					f << fixed <<  "Максимальное время выполнения: " << max << endl;
					f << fixed <<  "Среднее время выполнения: " << average << endl;
					f << endl;
					f << endl;
					f << endl; 
				}
			}
		}
	}
	/*------------------------------------------ВАРИАНТ ВЫВОДА ДЛЯ ЕКСЕЛЯ (для графиков)
	f.open("OsipovLI_output_KDZ_for_Excel.csv", ios :: app); // вывод для графиков
	for (int j = 0; j < 5; ++ j) { // цикл по видам массивов 
		f << endl;
		f << endl;
		f << endl;
		f << gText[j] << endl;
		for (int k = 1000; k <= 8000; k += 1000) { // цикл по длинам массивов
			f << k << ";";
			for (int i = 0; i < 12; ++ i) { // цикл по видам сортировок
				if ( ( (i == 5 && (j == 0 || j == 1)) || (i == 6 && j == 0) ) ) {
					f << ";";
					continue;
				}
					starray = new int[k];
					wrkarray = new int[k];
					min = INT_MAX;
					max = 0;
					average = 0;
					generators[j](starray, k); // генерация нужного массива
					copy(starray, wrkarray, k);
					sorts[i](wrkarray, k);
					if (! test_arr(wrkarray, k)) { // проверка на отсортированность
						cout << endl;
						cout << sText[i] << endl;
						cout << " при типе массива " << gText[i] << endl;
						cout << " и длине массива " << k << " не работает. Программа завершится." << endl;
						system("pause"); 
						return; 
						f.close();
					}
					for (int x = 0; x < 3; ++ x) { // прогонка функции для оптимизации
						copy(starray, wrkarray, k);
						sorts[i](wrkarray, k); 
					}
					for (int x = 0; x < 20; ++ x) {
						copy(starray, wrkarray, k); // копирование эталонного массива в рабочий
						QueryPerformanceFrequency(&frequency); // измерение частоты
							QueryPerformanceCounter(&startTime); 
						sorts[i](wrkarray, k); // непосредственно сортировка
						QueryPerformanceCounter(&elapsedTime); 
						temp = (double)(elapsedTime.QuadPart - startTime.QuadPart) * 1000000000 
							/ frequency.QuadPart; // нахождение текущего интервала
						if (temp > max) {
							max = temp; // поиск максимального интервала
						}
						if (temp < min) {
							min = temp; // поиск минимального интервала
						}
						average += temp;
					}
					average /= 20; // нахождение среднего интервала
					f << average << ";";
				}
			f << endl;
			}
	}
	//-----------------------------------------------для графиков
	*/
	f.close();
	t2 = clock() - t1;
	cout << "Работа завершена. Прошло " << t2 / 60000 << "минут" << endl;
	system("pause");
	delete [] starray;
	delete [] wrkarray;
}
bool test_arr(int *arr, int n) {
	for (int i = 1; i < n; ++ i) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

void generate(int *arr, int n, int min, int max) {
	for (int i = 0; i < n; ++ i) {
		arr[i] = rand() % (max - min + 1) + min; 
	}
}

void generate2to2(int *arr, int n) {
	generate(arr, n, -2, 2);
}

void generate0toMax(int *arr, int n) {
	generate(arr, n, 0, INT_MAX);
}

void sorted(int *arr, int n) {
	generate(arr, n, 0, 1000);
	simple_bubble_sort(arr, n);
}

void close_to_sorted(int *arr, int n) {
	generate(arr, n, 0, 1000);
	sorted(arr, n);
	int i1;
	int i2;
	int temp;
	for (int i = 0; i < 5; ++ i) {
		i1 = rand() % n;
		do {
			i2 = rand() % n;
		} while (i1 == i2);
		temp = arr[i1];
		arr[i1] = arr[i2];
		arr[i2] = temp;
	}
}

void reversed_sort(int *arr, int n) {
	generate(arr, n, 0, 1000);
	sorted(arr, n);
	int *temparr = new int[n];
	for (int i = 0; i < n; ++ i) {
		temparr[i] = arr[n - i - 1];
	}
	for (int i = 0; i < n; ++ i) {
		arr[i] = temparr[i];
	}
	delete [] temparr;
}

void copy(int *srcarr, int *outarr, int n) {
	for (int i = 0; i < n; ++ i) {
		outarr[i] = srcarr[i];
	}
}

/* Адаптеры для некоторых сортировок */
void countingS_adapter(int* arr, int n) {
	counting_sort(arr, n, 1000); // так как везде, где будет использоваться сортировка подсчетом, будут числа от 0 до 1000
}
void mergeS_adapter(int* arr, int n) {
	merge_sort(arr, 0, n - 1);
}

void Hoare1S_adapter(int* arr, int n) {
	Hoare_sort_1(arr, 0, n - 1);
}

void Hoare2S_adapter(int* arr, int n) {
	Hoare_sort_2(arr, 0, n - 1);
}

void Hoare3S_adapter(int* arr, int n) {
	Hoare_sort_3(arr, 0, n - 1);
}