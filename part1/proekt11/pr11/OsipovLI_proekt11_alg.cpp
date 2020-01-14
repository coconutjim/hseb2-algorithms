/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 11. Генерация комбинаторных объектов
Среда разработки: Microsoft Visual Studio 2012 
Дата: 06.12.2013
*/

#include <vector>
#include <iostream>
#include "OsipovLI_proekt11_alg.h"
using namespace std;

unsigned __int64 fact(int n) { // обычный факториал
	unsigned __int64 f = 1;
	for (int i = 2; i <= n; ++ i) {
		f *= i;
	}
	return f;
}

unsigned __int64 fact_down(int n1, int n2) { // факториал вниз
	unsigned __int64 f = 1;
	for (int i = n1; i >= n2; -- i) {
		f *= i;
	}
	return f;
}

unsigned __int64 count_permutations(int n) { // количество перестановок
	return fact(n);
}

unsigned __int64 count_placements(int n, int k) { // количество размещений
	return fact_down(n, n - k + 1);
}

unsigned __int64 count_combinations(int n, int k) { // количество сочетаний
	unsigned __int64 numerator = 1;
	for (int i = n - k + 1; i <= n; ++ i) { // более краткое вычисление числителя происходит за счет сокращения 
		numerator *= i;                 // совпадающих частей факториалов в числителе и знаменателе
	}
	return numerator / fact(k);
}

void permutations_iterations(int n) { // итерационная генерация перестановок
	int t1;
	int t2;
	int min;
	int temp;
	vector<int> results;
	for (int i = 1; i <= n; ++ i) {
		results.push_back(i);
	}
	while (true)
	{
		for (size_t i = 0; i < results.size(); ++ i) {
			cout << results[i] << " ";
		}
		t1 = 0;
		cout << endl;
		for (int i = n - 1; i >= 1; -- i) {
			if (results[i - 1] < results[i]) {
				t1 = i;
				break;
			}
		}
		if (t1 == 0) {
			return;
		}
		min = n + 1;
		t2 = 0;
		for (int j = t1; j < n; ++ j) {
			if (min > results[j] && (results[j] > results[t1 - 1])) {
				min = results[j];
				t2 = j;
			}
		}
		temp = results[t1 - 1];
		results[t1 - 1] = results[t2];
		results[t2] = temp;
		for(int j = t1; j < (n + t1) / 2; ++ j) {
			temp = results[j];
			results[j] = results[n + t1 - j - 1];
			results[n + t1 - j - 1] = temp;
		}
	}
}

void perm(int index, vector<int> &res) { // рекурсия для перестановок
	int temp;
	if (index == res.size()) {
		for (size_t i = 0; i < res.size(); ++ i) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	else {
		for (size_t i = index + 1; i < res.size(); ++ i) {
			perm(index + 1, res);
			temp = res[index];
			res[index] = res[i];
			res[i] = temp;
		}
		perm(index + 1, res);
		temp = res[index];
		for (size_t i = index; i < res.size() - 1; ++ i)
		{
			res[i] = res[i + 1];
		}
		res[res.size() - 1] = temp;
	}
}

void permutations_recursive(int n) { // рекурсивная генерация перестановок
	vector<int> results;
	for (int i = 1; i <= n; ++ i) {
		results.push_back(i);
	}
	perm(0, results);
    results.clear();
}

void place(int index, int n, int k, vector<int> &res) { // рекурсия для размещений
    for (int i = 1; i <= n; ++ i) { 
		bool flag = true;
		for (size_t j = 0; j < res.size(); ++ j) {
			if (i == res[j]) {
				flag = false;
			}
		}
		if (flag) {
			res.push_back(i);
            if (index < k) {
				place(index + 1, n, k, res);
            }
			else {
				for (size_t j = 0; j < res.size(); ++ j) {
					cout << res[j] << " ";
                }
                cout << endl;
			}
			res.pop_back();
		}
	}
}

void placements(int n, int k) { // генерация размещений 
	vector<int> results;
	place(1, n, k, results);
    results.clear();
}

void comb(int N, int k, int start, int index, vector<int> &res) { // рекурсия для сочетаний
        if (index > k) {
                for (size_t i = 0; i < res.size(); ++ i) {
                        cout << res[i] << " ";
                }
                cout << endl;
                return;
        }
        for (int i = start; i <= N - (k - index); ++ i) {
                res[index - 1] = i;
                comb(N, k, i + 1, index + 1, res);
        }
}
 
void combinations(int N, int k) { // генерация сочетаний
        vector<int> results (k);
        comb(N, k, 1, 1, results);
		results.clear();
}

void repres(int n, vector<int> &res) { // рекурсия для представлений
	if (n <= 0) {
		for (size_t i = 0; i < res.size(); ++ i) {
			cout << res[i] << " ";
		}
		cout << endl;
		return;
        }
	for (int i = n; i >= 1; -- i) {
		if (res.size() == 0 || (res.size() > 0 && 
				i < res[res.size() - 1])) { 
			res.push_back(i);
            repres(n - i, res);
            res.pop_back();
		}
	}
}

void representations(int n) { // генерация представлений
        vector<int> results;
        repres(n, results);
        results.clear();
}