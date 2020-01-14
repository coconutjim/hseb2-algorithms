/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 10. Упаковка рюкзака
Среда разработки: Microsoft Visual Studio 2012 
Дата: 30.11.2013
*/

using namespace std;
#include <iostream>
#include <vector>
#include "OsipovLI_knap_alg.h"

Knap_recursive::Knap_recursive(int rW) {
	resW = rW;
}

void Knap_recursive::comeback(int w, int n, int *we, int *co, int itemInd, int tmpW, 
							  int tmpC, vector<int> &tmp, vector<int> &res) {
	if (w < tmpW) {
		return;
	}
	if (itemInd == n) {
		if (tmpC >= resC && tmpW <= resW) { // используем поля класса как "общие" между ветвями значения
			resC = tmpC;
			res.clear();
			for (size_t i = 0; i < tmp.size(); ++ i) {
				res.push_back(tmp[i]);
			}
		}
		return;
	}
	tmp.push_back(itemInd); // если положили предмет
	comeback(w, n, we, co, itemInd + 1, tmpW + we[itemInd], tmpC + co[itemInd], tmp, res);
	//
	tmp.pop_back(); // и если не положили
	comeback(w, n, we, co, itemInd + 1, tmpW, tmpC, tmp, res);
}

void Knap_recursive::knapsack_recursive_comebacks(int w, int n, int *we, 
												  int *co, vector<int> &result) {
	resC = 0;
	vector<int> temp;
	temp.push_back(0); // если положили предмет
	comeback(w, n, we, co, 1, we[0], co[0], temp, result);
	//
	temp.pop_back(); // и если не положили
	comeback(w, n, we, co, 1, 0, 0, temp, result);
}

void find(int **m, int w, int n, int *we, int *co, vector<int> &result) {
	if (m[w][n] == 0) {
		return;
	}
	if (m[w][n - 1] == m[w][n]) {
		
		find(m, w, n - 1, we, co, result);
	}
	else {
		find(m, w - we[n - 1], n - 1, we, co, result);
		result.push_back(n - 1);
	}
}

void knapsack_dynamic(int w, int n, int *we, int *co, vector<int> &result) {
    int** matr = new int*[w + 1];
	for (int i = 0; i <= w; ++ i) {
		matr[i] = new int[n + 1];
		for(int j = 0; j <= n; ++ j) {
				matr[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= w; ++ j) {
			// используем реккурентное соотношение
			if (we[i - 1] <= j) { 
				matr[j][i] = max(matr[j][i - 1], matr[j - we[i - 1]][i - 1] + co[i - 1]); 
			}
			else {
				matr[j][i] = matr[j][i - 1];
			}
		}
	}
	find(matr, w, n, we, co, result); // рекурсивно ищем предметы, которые были положены в рюкзак
}

void sort(double *arr, int *arrW, int *arrC, int* arrI, double min, double max)
{
	int mn = min, mx = max, mid = (int)arr[(mn + mx) / 2], temp;
	double tempD;
	do {
		while (arr[mn] < mid) ++ mn;
		while (arr[mx] > mid) -- mx;
		if (mn <= mx) {
			if (mn < mx)
			{
				tempD = arr[mn];
				arr[mn] = arr[mx];
				arr[mx] = tempD;
				//
				temp = arrW[mn];
				arrW[mn] = arrW[mx];
				arrW[mx] = temp;
				//
				temp = arrC[mn];
				arrC[mn] = arrC[mx];
				arrC[mx] = temp;
				//
				temp = arrI[mn];
				arrI[mn] = arrI[mx];
				arrI[mx] = temp;
			}
			++ mn; -- mx;
		}
	} while (mn <= mx);
	if (mn < max) sort(arr, arrW, arrC, arrI, mn, max);
	if (min < mx) sort(arr, arrW, arrC, arrI, min, mx);
}

void knapsack_greedy(int w, int n, int *we, int *co, vector<int> &res) {
	double *temparr = new double[n];
	int *temparrW = new int[n];
	int *temparrC = new int[n];
	int *temparrI = new int[n];
	for (int i = 0; i < n; ++ i) {
		temparrI[i] = i;
		temparrW[i] = we[i];
		temparrC[i] = co[i];
		temparr[i] = we[i] / co[i];
	}
	// сортируем все массивы по соотношению весов и стоимостей
	sort(temparr, temparrW, temparrC, temparrI, 0, n - 1);
	int sumW = 0;
	for (int i = 0, j = 0; i < n; ++ i) {
		if (sumW + temparrW[i] < w) {
			sumW += temparrW[i];
			res.push_back(temparrI[i]);
		}
	}
	delete [] temparr;
	delete [] temparrW;
	delete [] temparrC;
	delete [] temparrI;
}


