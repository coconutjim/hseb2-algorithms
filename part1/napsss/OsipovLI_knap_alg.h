/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 10. Упаковка рюкзака
Среда разработки: Microsoft Visual Studio 2012 
Дата: 30.11.2013
*/

#include <vector>


class Knap_recursive { 
public:
	int resC;
	int resW;
	Knap_recursive(int rW);
	void comeback(int, int, int*, int*, int, int, int, vector<int>&, vector<int>&);
	void knapsack_recursive_comebacks(int, int, int*, int*, vector<int>&);
};
void find(int**, int, int, int*, int*, vector<int>&);
void knapsack_dynamic(int, int, int*, int*, vector<int>&);
void sort(int*, int*, int*, int*, int, int);
void knapsack_greedy(int, int, int*, int*, vector<int>&);
