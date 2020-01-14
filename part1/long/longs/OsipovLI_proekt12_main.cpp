/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 12. ������� �����
����� ����������: Microsoft Visual Studio 2012 
����: 10.12.2013
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
		cout << "��� ������� 2 ������� 2 � ������� ENTER" << endl;
		cout << "��� ������� 3 ������� 3 � ������� ENTER" << endl;
		cout << "��� ������ ������� 4 � ������� ENTER" << endl;
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
				cout << "������ � ������������ ��� ����� �����!" << endl;
				cout << "��������� ��� �����: input_knap.txt" << endl;
				cout << endl;
				continue;
			}
			ifile >> NT;
			if (!ifile || ifile.eof() || NT < 1) { // ���������� ���������� ������
				data_fail();
				continue;
			}
			ifile >> N;
			if (!ifile || ifile.eof() || NT < 1) { // ���������� ���������
				data_fail();
				continue;
			}
			for (int i = 0; i < NT; ++ i) {
				ifile >> num1; // ��������� ������ �����
				for (char& c: num1) { // ��������
					if (c <'0' || c > '9') {
						data_fail();
						continue;
					}
				}
				LongInteger *number1 = LongInteger::read(num1, N); // ������ �����
				ifile >> num2; // ��������� ������ �����
				for (char& c: num2) { // ��������
					if (c <'0' || c > '9') {
						data_fail();
						continue;
					}
				}
				LongInteger *number2 = LongInteger::read(num2, N); // ������ �����
				number1->printConsole();
				switch (LongInteger::compare(number1, number2)) { // ���������
				case -1: {
					cout << " ������ ";
					break;
						 }
				case 0: {
					cout << " ����� ";
					break;
						}
				case 1: {
					cout << " ������ ";
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
			cout << "������� ����� N (51 <= N <= 100): ";
			cin >> N;
			if (cin.fail() || N < 51 || N > 100) {
			input_fail();
			continue;
			}
			cout << "����� ���������" << endl;
			fibon(N, 1000)->printConsole(); // ������� � ����� ����� ���������
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
	cout << "������ ������� ������!" << endl;
	cout << endl;
	cout << endl;
}

void data_fail() {
	ifile.clear();
	ifile.close();
	cout << "������ � ������ ������ �����!" << endl;
	cout << "��� ������ ������ ���� �������������� ������ �������." << endl;
	cout << endl;
	cout << endl;
}