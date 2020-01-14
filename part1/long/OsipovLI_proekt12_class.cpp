/*
ФИО: Осипов Лев Игоревич
Группа: 271(1)ПИ
Тема работы: Проект 12. Длинные целые
Среда разработки: Microsoft Visual Studio 2012 
Дата: 10.12.2013
*/

#include"OsipovLI_proekt12_class.h"
#include<iostream>
#include<fstream>
using namespace std;

LongInteger::LongInteger(int n, int k) {
	N = n;
	number = new int[k];
}

LongInteger::LongInteger(string src, int n) {
	N = n;
	int k;
	if (src.length() % (int)log10(N) == 0) {
		k = 0;
	}
	else {
		k = 1;
	}
	int len = src.length() / (int)log10(N) + k;
	number = new int[len + 1];
	number[0] = len;
	for (int i = 1; i <= len; ++ i) {
		if (i == len && k == 1) {
			number[i] = stoi(src.erase(src.length() - (int)log10(N) * (i - 1), (int)log10(N) * (i - 1))); 
			break;
		}
		number[i] = stoi(src.substr(src.length() - (int)log10(N) * i, (int)log10(N)));
	}
}

LongInteger* LongInteger::read(string src, int N) {
	return new LongInteger(src, N);
}

void LongInteger::printConsole() {
	int base;
	for (int i = number[0]; i > 0; -- i) { // дописывание необходимых нулей
		if (i < number[0]) {
			base = N / 10;
			while(base > number[i] && base!= 1)	{
				cout << '0';
				base /= 10;
			}
		}
		cout << number[i];
	}
}

void LongInteger::printFile(const char* fileName) {
	ofstream ofile;
	int base;
	ofile.open(fileName, ios :: app);
	for (int i = number[0]; i > 0; -- i) { // дописывание необходимых нулей
		if (i < number[0] && number[i + 1] != 0) {
			base = N / 10;
			while(base > number[i] && base!= 1)	{
				cout << '0';
				base /= 10;
			}
		}
		ofile << number[i];
	}
	ofile.close();
}

void LongInteger::clear() {
	for (int i = number[0]; i >= 0; -- i) {
		number[i] = 0;
	}
}

LongInteger* LongInteger::add(LongInteger *op) {
	if (N != op->N) {
		throw new exception("impossible operation");
	}
	int k;
	if (number[0] > op->number[0]) {
		k = number[0];
	}
	else {
		k = op->number[0];
	}
	LongInteger *sum =  new LongInteger(N, k);
	sum->number = new int[k + 2];
	for (int i = 1; i <= k; ++ i) {
		sum->number[i + 1] = (number[i] + op->number[i]) / N;
		sum->number[i] = (number[i] + op->number[i]) % N;
	}
	if (sum->number[k + 1] == 0) {
		sum->number[0] = k;
	}
	else {
		sum->number[0] = k + 1;
	}
	return sum;
}

LongInteger* LongInteger::sub(LongInteger *op) {
	if (N != op->N || number[0] < op->number[0]) {
		throw new exception("impossible operation");
	}
	LongInteger *dif =  new LongInteger(N, number[0] + 2);
	int temp;
	int i;
	int carry = 0;
	for (i = 1; i <= op->number[0]; ++ i) {
		temp = number[i] - op->number[i] + carry;
		if (temp < 0) {
			dif->number[i] = temp + N;
			carry = -1;
		}
		else {
			dif->number[i] = temp;
			carry = 0;
		}
	}
	for (; i <= number[0]; ++ i) {
		temp = number[i] + carry;
		if (temp < 0) {
			dif->number[i] = temp + N;
			carry = -1;
		}
		else {
			dif->number[i] = temp;
			carry = 0;
		}
	}
	i = number[0];
	while ((i > 0) && (dif->number[i] == 0)) {
		-- i;
	}
	dif->number[0] = i;
	/*if (carry == -1) {
		throw string("impossible operation");
	}*/
	return dif;
}

int LongInteger::compare(LongInteger *op1, LongInteger *op2) {
	if (op1->N != op2->N) {
		throw new exception("impossible operation");
	}
	if (op1->number[0] < op2->number[0]) {
		return -1;
	}
	else if (op1->number[0] > op2->number[0]) {
		return 1;
	}
	else {
		for (int i = op1->number[0]; i > 0; -- i) {
			if (op1->number[i] < op2->number[i]) {
				return -1;
			}
			if (op1->number[i] > op2->number[i]) {
				return 1;
			}
		}
		return 0;
	}
}

LongInteger::~LongInteger() {
	delete [] number;
}

LongInteger* fibon(int n , int N)  {
	LongInteger* sum1 = new LongInteger("1", N);
	LongInteger* sum2 = new LongInteger("1", N);
	LongInteger* sum = new LongInteger("0", N);
	for (int i = 0; i < n; ++ i) {
		sum = sum1->add(sum2);
		sum2 = sum1;
		sum1 = sum;
	}
	return sum;
}
