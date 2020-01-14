/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 10. �������� �������
����� ����������: Microsoft Visual Studio 2012 
����: 30.11.2013
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
		cout << "������ � ������������ ��� ����� �����!" << endl;
		cout << "��������� ��� �����: input_knap.txt" << endl;
		cout << endl;
		system("pause");
		return;
	}
	ifile >> NT;
	if (!ifile || ifile.eof() || NT < 1) { // ���������� ���������� ������
		data_fail();
		return;
	}
	for (int i = 0; i < NT; ++ i) { // ���������� ������������� ����
		ifile >> W;
		if (!ifile || W < 1) {
			data_fail();
			return;
		}
		ifile >> N;
		if (!ifile || N < 1) { // ���������� ���������� ���������; ��� ����������� �������� �������� ��������
			data_fail();
			return;
		}
		weights = new int[N];
		costs = new int[N];
		for (int j = 0; j < N; ++ j) { // ���������� ����� ���������
			ifile >> weights[j];
			if (!ifile || weights[j] < 1) {
				data_fail();
				return;
			}
		}
		for (int j = 0; j < N; ++ j) { // ���������� ���������� ��������
			ifile >> costs[j];
			if (!ifile || costs[j] < 1) {
				data_fail();
				return;
			}
		}
		// �������� � ���������
		result.clear();
		QueryPerformanceFrequency(&frequency); // ��������� �������
		QueryPerformanceCounter(&startTime);
		Knap_recursive obj = Knap_recursive(W);
		obj.knapsack_recursive_comebacks(W, N, weights, costs, result);
		QueryPerformanceCounter(&elapsedTime);
		resTime.QuadPart = (elapsedTime.QuadPart - startTime.QuadPart) *
			1000000000 / frequency.QuadPart; // ��������� ���������
		cout << "����� �����: " << i + 1 << endl;
		cout << "��� �������: �������� � ���������" << endl;
		output(resTime, weights, costs, result);
		ofile.open("output_knap.txt", ios :: app);
		ofile << "����� �����: " << i + 1 << endl;
		ofile << "��� �������: �������� � ���������" << endl;
		ofile.close();
		output_file(resTime, weights, costs, result);
		// ������������ ���������������� 
		result.clear();
		QueryPerformanceFrequency(&frequency); // ��������� �������
		QueryPerformanceCounter(&startTime);
		knapsack_dynamic(W, N, weights, costs, result);
		QueryPerformanceCounter(&elapsedTime);
		resTime.QuadPart = (elapsedTime.QuadPart - startTime.QuadPart) *
			1000000000 / frequency.QuadPart; // ��������� ���������
		cout << "����� �����: " << i + 1 << endl;
		cout << "��� �������: ������������ ����������������" << endl;
		output(resTime, weights, costs, result);
		ofile.open("output_knap.txt", ios :: app);
		ofile << "����� �����: " << i + 1 << endl;
		ofile << "��� �������: ������������ ����������������" << endl;
		ofile.close();
		output_file(resTime, weights, costs, result); 
		// ������ �������� 
		result.clear();
		QueryPerformanceFrequency(&frequency); // ��������� �������
		QueryPerformanceCounter(&startTime);
		knapsack_greedy(W, N, weights, costs, result);
		QueryPerformanceCounter(&elapsedTime);
		resTime.QuadPart = (elapsedTime.QuadPart - startTime.QuadPart) *
			1000000000 / frequency.QuadPart; // ��������� ���������
		cout << "����� �����: " << i + 1 << endl;
		cout << "��� �������: ������ ��������" << endl;
		output(resTime, weights, costs, result);
		ofile.open("output_knap.txt", ios :: app);
		ofile << "����� �����: " << i + 1 << endl;
		ofile << "��� �������: ������ ��������" << endl;
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
	cout << "������ � ������ ������ �����!" << endl;
	cout << "��� ������ ������ ���� �������������� ������ �������." << endl;
	cout << endl;
	system("pause");
}

void output(LARGE_INTEGER t, int *we, int *co, vector<int> &r) {
	cout << "����� ������ ���������: " << t.QuadPart << " ��" << endl;
	int rW = 0;
	int rC = 0;
	for (size_t i = 0; i < r.size(); ++ i) {
		rW += we[r[i]];
		rC += co[r[i]];
	}
	cout << "��� �������: " << rW << endl;
	cout << "��������� �������: " << rC << endl;
	cout << "������ ��������� � ������� (���������� � 1): ";
	for (size_t i = 0; i < r.size(); ++ i) {
		cout << r[i] + 1 << " ";
	}
	cout << endl;
	cout << endl;
}

void output_file(LARGE_INTEGER t, int *we, int *co, vector<int> &r) {
	ofile.open("output_knap.txt", ios :: app);
	ofile << "����� ������ ���������: " << t.QuadPart << " ��" << endl;
	int rW = 0;
	int rC = 0;
	for (size_t i = 0; i < r.size(); ++ i) { // ������� �������� ��������� � ����
		rW += we[r[i]];
		rC += co[r[i]];
	}
	ofile << "��� �������: " << rW << endl;
	ofile << "��������� �������: " << rC << endl;
	ofile << "������ ��������� � ������� (���������� � 1): ";
	for (size_t i = 0; i < r.size(); ++ i) { // ������� �������� ��������� � ����
		ofile << r[i] + 1 << " ";
	}
	ofile << endl;
	ofile << endl;
	ofile.close();
}