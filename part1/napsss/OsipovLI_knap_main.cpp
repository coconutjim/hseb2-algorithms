/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 10. Упаковка рюкзака
Среда разработки: Microsoft Visual Studio 2012 
Дата: 30.11.2013
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <Windows.h>
#include "OsipovLI_knap_main.h"
#include "OsipovLI_knap_alg.h"
using namespace std;

ofstream ofile;
ifstream ifile;

void main() 
{
	setlocale(LC_ALL,"Russian");
	//int N, NT, min, max, result;
	int NT;
	int W;
	int N;
	int *weights;
	int *costs;
	vector<int> result;
	LARGE_INTEGER frequency;
	LARGE_INTEGER startTime;
	LARGE_INTEGER elapsedTime;
	LARGE_INTEGER resTime;
	srand(time(NULL));
	weights = new int[1];
	costs = new int[1];
	ifile.open("input_knap.txt", ios :: in);
	if (!ifile) {
		ifile.clear();
		ifile.close();
		cout << "Ошибка в расположении или имени файла!" << endl;
		cout << "Требуемое имя файла: input_knap.txt" << endl;
		cout << endl;
		system("pause");
		return;
	}
	ifile >> NT;
	if (!ifile || ifile.eof() || NT < 1) { // считывание количества тестов
		data_fail();
		return;
	}
	for (int i = 0; i < NT; ++ i) { // считывание максимального веса
		ifile >> W;
		if (!ifile || W < 1) {
			data_fail();
			return;
		}
		ifile >> N;
		if (!ifile || N < 1) { // считывание количества предметов; при несколькоих десятках возможны проблемы
			data_fail();
			return;
		}
		weights = new int[N];
		costs = new int[N];
		for (int j = 0; j < N; ++ j) { // считывание весов предметов
			ifile >> weights[j];
			if (!ifile || weights[j] < 1) {
				data_fail();
				return;
			}
		}
		for (int j = 0; j < N; ++ j) { // считывание стоимостей прдметов
			ifile >> costs[j];
			if (!ifile || costs[j] < 1) {
				data_fail();
				return;
			}
		}
		// рекурсия с возвратом
		result.clear();
		QueryPerformanceFrequency(&frequency); // измерение частоты
		QueryPerformanceCounter(&startTime);
		Knap_recursive obj = Knap_recursive(W);
		obj.knapsack_recursive_comebacks(W, N, weights, costs, result);
		QueryPerformanceCounter(&elapsedTime);
		resTime.QuadPart = (elapsedTime.QuadPart - startTime.QuadPart) *
			1000000000 / frequency.QuadPart; // измерение интервала
		cout << "Номер теста: " << i + 1 << endl;
		cout << "Тип решения: рекурсия с возвратом" << endl;
		output(resTime, weights, costs, result);
		ofile.open("output_knap.txt", ios :: app);
		ofile << "Номер теста: " << i + 1 << endl;
		ofile << "Тип решения: рекурсия с возвратом" << endl;
		ofile.close();
		output_file(resTime, weights, costs, result);
		// динамическое программирование 
		result.clear();
		QueryPerformanceFrequency(&frequency); // измерение частоты
		QueryPerformanceCounter(&startTime);
		knapsack_dynamic(W, N, weights, costs, result);
		QueryPerformanceCounter(&elapsedTime);
		resTime.QuadPart = (elapsedTime.QuadPart - startTime.QuadPart) *
			1000000000 / frequency.QuadPart; // измерение интервала
		cout << "Номер теста: " << i + 1 << endl;
		cout << "Тип решения: динамическое программирование" << endl;
		output(resTime, weights, costs, result);
		ofile.open("output_knap.txt", ios :: app);
		ofile << "Номер теста: " << i + 1 << endl;
		ofile << "Тип решения: динамическое программирование" << endl;
		ofile.close();
		output_file(resTime, weights, costs, result); 
		// жадный алгоритм 
		result.clear();
		QueryPerformanceFrequency(&frequency); // измерение частоты
		QueryPerformanceCounter(&startTime);
		knapsack_greedy(W, N, weights, costs, result);
		QueryPerformanceCounter(&elapsedTime);
		resTime.QuadPart = (elapsedTime.QuadPart - startTime.QuadPart) *
			1000000000 / frequency.QuadPart; // измерение интервала
		cout << "Номер теста: " << i + 1 << endl;
		cout << "Тип решения: жадный алгоритм" << endl;
		output(resTime, weights, costs, result);
		ofile.open("output_knap.txt", ios :: app);
		ofile << "Номер теста: " << i + 1 << endl;
		ofile << "Тип решения: жадный алгоритм" << endl;
		ofile.close();
		output_file(resTime, weights, costs, result); 
	}
	ifile.close();
	delete [] weights;
	delete [] costs;
	system("pause");
}

void data_fail() {
	ifile.clear();
	ifile.close();
	cout << "Ошибка в данных внутри файла!" << endl;
	cout << "Все данные должны быть положительными целыми числами." << endl;
	cout << endl;
	system("pause");
}

void output(LARGE_INTEGER t, int *we, int *co, vector<int> &r) {
	cout << "Время работы алгоритма: " << t.QuadPart << " нс" << endl;
	int rW = 0;
	int rC = 0;
	for (size_t i = 0; i < r.size(); ++ i) {
		rW += we[r[i]];
		rC += co[r[i]];
	}
	cout << "Вес рюкзака: " << rW << endl;
	cout << "Стоимость рюкзака: " << rC << endl;
	cout << "Номера предметов в рюкзаке (индексация с 1): ";
	for (size_t i = 0; i < r.size(); ++ i) {
		cout << r[i] + 1 << " ";
	}
	cout << endl;
	cout << endl;
}

void output_file(LARGE_INTEGER t, int *we, int *co, vector<int> &r) {
	ofile.open("output_knap.txt", ios :: app);
	ofile << "Время работы алгоритма: " << t.QuadPart << " нс" << endl;
	int rW = 0;
	int rC = 0;
	for (size_t i = 0; i < r.size(); ++ i) { // подсчет итоговой стоимости и веса
		rW += we[r[i]];
		rC += co[r[i]];
	}
	ofile << "Вес рюкзака: " << rW << endl;
	ofile << "Стоимость рюкзака: " << rC << endl;
	ofile << "Номера предметов в рюкзаке (индексация с 1): ";
	for (size_t i = 0; i < r.size(); ++ i) { // подсчет итоговой стоимости и веса
		ofile << r[i] + 1 << " ";
	}
	ofile << endl;
	ofile << endl;
	ofile.close();
}