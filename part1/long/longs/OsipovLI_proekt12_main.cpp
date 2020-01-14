/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 12. Длинные целые
Среда разработки: Microsoft Visual Studio 2012 
Дата: 10.12.2013
*/

#include<iostream>
#include<fstream>
#include<string>
#include"OsipovLI_proekt12_class.h"
#include"OsipovLI_proekt12_main.h"
using namespace std;

ofstream ofile;
ifstream ifile;

void main() {
	setlocale(LC_ALL,"Russian");
	bool flag = true;
	int result;
	int NT;
	int N;
	string num1;
	string num2;
	//string r[] =  {"g"};
	while (flag)
	{
		//system("pause");
		cout << "Для задания 2 введите 2 и нажмите ENTER" << endl;
		cout << "Для задания 3 введите 3 и нажмите ENTER" << endl;
		cout << "Для выхода введите 4 и нажмите ENTER" << endl;
		cin >> result;
		if (cin.fail()) {
			input_fail();
			continue;
		}
		switch (result) {
		case 2: {
			ifile.open("input12.txt", ios :: in);
			if (!ifile) {
				ifile.clear();
				ifile.close();
				cout << "Ошибка в расположении или имени файла!" << endl;
				cout << "Требуемое имя файла: input_knap.txt" << endl;
				cout << endl;
				continue;
			}
			ifile >> NT;
			if (!ifile || ifile.eof() || NT < 1) { // считывание количества тестов
				data_fail();
				continue;
			}
			ifile >> N;
			if (!ifile || ifile.eof() || NT < 1) { // считывание основания
				data_fail();
				continue;
			}
			for (int i = 0; i < NT; ++ i) {
				ifile >> num1; // считываем первое число
				for (char& c: num1) { // проверка
					if (c <'0' || c > '9') {
						data_fail();
						continue;
					}
				}
				LongInteger *number1 = LongInteger::read(num1, N); // первое число
				ifile >> num2; // считываем второе число
				for (char& c: num2) { // проверка
					if (c <'0' || c > '9') {
						data_fail();
						continue;
					}
				}
				LongInteger *number2 = LongInteger::read(num2, N); // второе число
				number1->printConsole();
				switch (LongInteger::compare(number1, number2)) { // сравнение
				case -1: {
					cout << " меньше ";
					break;
						 }
				case 0: {
					cout << " равно ";
					break;
						}
				case 1: {
					cout << " больше ";
					break;
						}
				}
				number2->printConsole();
				cout << endl;
				cout << endl;
			}
			ifile.close();
			break;
			}
		case 3: {
			cout << "Введите целое N (51 <= N <= 100): ";
			cin >> N;
			if (cin.fail() || N < 51 || N > 100) {
			input_fail();
			continue;
			}
			cout << "Число Фибоначчи" << endl;
			fibon(N, 1000)->printConsole(); // подсчет и вывод числа Фибоначчи
			cout << endl;
			cout << endl;
			break;
			}
		case 4: {
			flag = false;
			break;
			}
		}
	}
}

void input_fail() {
	cin.clear();
	_flushall();
	cout << "Ошибка входных данных!" << endl;
	cout << endl;
	cout << endl;
}

void data_fail() {
	ifile.clear();
	ifile.close();
	cout << "Ошибка в данных внутри файла!" << endl;
	cout << "Все данные должны быть положительными целыми числами." << endl;
	cout << endl;
	cout << endl;
}