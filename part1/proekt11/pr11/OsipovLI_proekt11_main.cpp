/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 11. Генерация комбинаторных объектов
Среда разработки: Microsoft Visual Studio 2012 
Дата: 06.12.2013
*/

#include <iostream>
#include "OsipovLI_proekt11_main.h"
#include "OsipovLI_proekt11_alg.h"
using namespace std;

void main() {
	int N;
	int M;
	int res;
	bool flag = true;
	setlocale(LC_ALL,"Russian");
	input(N, M);
	cout << "Задание 1." << endl;
	cout << "Всего перестановок: " << count_permutations(N) << endl;
	cout << "Всего размещений: " << count_placements(N, M) << endl;
	cout << "Всего сочетаний: " << count_combinations(N, M) << endl;
	cout << endl;
	cout << endl;
	while (flag) {
		cout << "N = " << N << ", M = " << M << endl;
		cout << "Для повторного вывода количества разных последовательностей нажмите 1" << endl;
		cout << "Для генерации перестановок из N (итерации) нажмите 2" << endl;
		cout << "Для генерации перестановок из N (рекурсия) нажмите 3" << endl;
		cout << "Для генерации размещений из N по M нажмите 4" << endl;
		cout << "Для генерации сочетаний из N по M нажмите 5" << endl;
		cout << "Для генерации представлений из N в невозрастающем порядке нажмите 6" << endl;
		cout << "Для ввода новых данных нажмите 7" << endl;
		cout << "Для выхода нажмите 8" << endl;
		cout << endl;
		cout << endl;
		cin >> res;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		switch (res) {
		case 1: {
			cout << "Задание 1." << endl;
			cout << "Всего перестановок: " << count_permutations(N) << endl;
			cout << "Всего размещений: " << count_placements(N, M) << endl;
			cout << "Всего сочетаний: " << count_combinations(N, M) << endl;
			cout << endl;
			cout << endl;
			break;
				}
		case 2: {
			cout << "Задание 2 (а). Перестановки итерациями" << endl;
			cout << endl;
			cout << endl;
			permutations_iterations(N);
			cout << endl;
			cout << endl;
			break;
				}
		case 3: {
			cout << "Задание 2 (б). Перестановки рекурсивно" << endl;
			cout << endl;
			cout << endl;
			permutations_recursive(N);
			cout << endl;
			cout << endl;
			break;
				}
		case 4: {

			cout << "Задание 3. Размещения" << endl;
			cout << endl;
			cout << endl;
			placements(N, M);
			cout << endl;
			cout << endl;
			break;
				}
		case 5: {
			cout << "Задание 4. Сочетания" << endl;
			cout << endl;
			cout << endl;
			combinations(N, M);
			cout << endl;
			cout << endl;
			break;
				}
		case 6: {
			cout << "Задание 5. Представления в невозрастающем порядке" << endl;
			cout << endl;
			cout << endl;
			representations(N);
			cout << endl;
			cout << endl;
			break;
				}
		case 7: {
			input(N, M);
			cout << "Задание 1." << endl;
			cout << "Всего перестановок: " << count_permutations(N) << endl;
			cout << "Всего размещений: " << count_placements(N, M) << endl;
			cout << "Всего сочетаний: " << count_combinations(N, M) << endl;
			cout << endl;
			cout << endl;
			break;
				}
		case 8: {
			flag = false;
			break;
				}
		}
	}
}

void input_fail()
{
	cin.clear();
	_flushall();
	cout << "Ошибка входных данных!" << endl;
	cout << endl;
}

void input (int &n, int &m)
{
	while (true)
	{
		cout << "Введите N (целочисленное положительное значение" << endl;
		cout <<	"не более 20 во избежание переполнения): ";
		cin >> n;
		if (cin.fail() || n < 1 || n > 20)
		{
			input_fail();
			continue;
		}
		cout << "Введите M (целочисленное положительное значение меньше N): ";
		cin >> m;
		if (cin.fail() || m < 1 || m >= n)
		{
			input_fail();
			continue;
		}
		cout << endl;
		cout << endl;
		break;
	}
}