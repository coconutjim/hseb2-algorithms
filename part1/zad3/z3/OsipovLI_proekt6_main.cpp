/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 6-7. ���������� ��������� ����������� ���������� �� ����� �++
����� ����������: Microsoft Visual Studio 2012 
����: 18.10.2013
*/


#include <iostream>
#include <fstream>
#include <ctime>
#include "OsipovLI_proekt6_main.h"
#include "OsipovLI_proekt6_sort.h"
using namespace std;

ofstream ofile;
ifstream ifile;

void main() 
{
	setlocale(LC_ALL,"Russian");
	int N, NT, min, max, result;
	int *newarray, *oldarray;
	bool flag = true;
	bool insideflag = true;
	srand(time(NULL));
	newarray = new int[1];
	oldarray = new int[1];
	while (flag)
	{
		cout << "��� ����� ������ � ���������� ������� 1" << endl;
		cout << "��� ������ ������ �� ����� ������� 2" << endl;
		cout << "��� ������ ������� 3" << endl;
		cin >> result;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		switch (result)
		{
		case 1:
			{
				input(NT, N, min, max);
				oldarray = new int[N];
				newarray = new int[N];
				for (int i = 0; i < NT; ++ i)
				{
					generate(newarray, N, min, max);
					copy(newarray, oldarray, N);
					//�������
					merge_sort(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ��������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ��������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�������������
					heap_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ������������� ����������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ������������� ����������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�����_1
					Hoare_sort_1(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ����� (�������������� ������� - �������)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ����� (�������������� ������� - �������)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�����_2
					Hoare_sort_2(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ����� (�������������� ������� - ������ �����)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ����� (�������������� ������� - ������ �����)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�����_3
					Hoare_sort_3(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ����� (�������������� ������� - ���������)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ����� (�������������� ������� - ���������)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
				}
				break;
			}
		case 2: 
			{
				insideflag = true;
				ifile.open("input_proekt6.txt", ios :: in);
				if (!ifile)
				{
					ifile.clear();
					ifile.close();
					cout << "������ � ������������ ��� ����� �����!" << endl;
					cout << "��������� ��� �����: input_proekt6.txt" << endl;
					cout << endl;
					continue;
				}
				ifile >> NT;
				if (!ifile || ifile.eof() || NT < 1)
				{
					ifile.clear();
					ifile.close();
					cout << "������ � ������ ������ �����!" << endl;
					cout << "��������� ������������ ������. ���������� ������ � ������� ��������" << endl;
					cout << "������ ���� ������ � �������������� �������, � ����� �������� - ������ �������." << endl;
					cout << endl;
					continue;
				}
				for (int i = 0; i < NT; ++ i)
				{
					ifile >> N;
					if (!ifile || N < 1)
					{
						ifile.clear();
						ifile.close();
						cout << "������ � ������ ������ �����!" << endl;
						cout << "��������� ������������ ������. ���������� ������ � ������� ��������" << endl;
						cout << "������ ���� ������ � �������������� �������, � ����� �������� - ������ �������." << endl;
						cout << endl;
						break;
					}
					oldarray = new int[N];
					newarray = new int[N];
					for (int j = 0; j < N; ++ j)
					{
						ifile >> newarray[j];
						if (!ifile)
						{
							ifile.clear();
							ifile.close();
							cout << "������ � ������ ������ �����!" << endl;
							cout << "��������� ������������ ������. ���������� ������ � ������� ��������" << endl;
							cout << "������ ���� ������ � �������������� �������, � ����� �������� - ������ �������." << endl;
							cout << endl;
							insideflag = false;
							break;
						}
					}
					if (! insideflag)
					{
						break;
					}
					copy(newarray, oldarray, N);
					//�������
					merge_sort(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ��������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ��������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�������������
					heap_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ������������� ����������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ������������� ����������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�����_1
					Hoare_sort_1(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ����� (�������������� ������� - �������)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ����� (�������������� ������� - �������)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�����_2
					Hoare_sort_2(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ����� (�������������� ������� - ������ �����)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ����� (�������������� ������� - ������ �����)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�����_3
					Hoare_sort_3(newarray, 0, N - 1);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ����� (�������������� ������� - ���������)" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt6.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ����� (�������������� ������� - ���������)" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
				}
				ifile.close();
				break;
			}
		case 3: 
			{
				flag = false;
				break;
			}
		default:
			{
				break;
			}
		}
	}
	delete [] oldarray;
	delete [] newarray;
}

void generate(int *arr, int n, int min, int max)
{
	for (int i = 0; i < n; ++ i)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void input_fail()
{
	cin.clear();
	_flushall();
	cout << "������ ������� ������!" << endl;
	cout << endl;
}

void input (int &nt, int &n, int &min, int &max)
{
	while (true)
	{
		cout << "������� ���������� ������ (������������� ������������� ��������): ";
		cin >> nt;
		if (cin.fail() || nt < 1)
		{
			input_fail();
			continue;
		}
		cout << "������� ����� ������� (������������� ������������� ��������): ";
		cin >> n;
		if (cin.fail()  || n < 1)
		{
			input_fail();
			continue;
		}
		cout << "������� ������ ������� �������� (������������� ��������): ";
		cin >> min;
		if (cin.fail())
		{
			input_fail();
			continue;
		}
		cout << "������� �������� ������� �������� (������������� ��������): ";
		cin >> max;
		if (cin.fail() || max < min)
		{
			input_fail();
			continue;
		}
		break;
	}
}

void copy(int *srcarr, int *outarr, int n)
{
	for (int i = 0; i < n; ++ i)
	{
		outarr[i] = srcarr[i];
	}
}

bool check_array(int *arr, int n)
{
	for (int i = 1; i < n; ++ i)
	{
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}

void output(int *oldarr, int *newarr, int n)
{
	cout << "������ ������:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		cout << oldarr[i] << " ";
	}
	cout << endl;
	cout << "��������������� ������:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		cout << newarr[i] << " ";
	}
	cout << endl;
	cout << endl;
}

void output_file(int *oldarr, int *newarr, int n)
{
	ofile.open("output_proekt6.txt", ios :: app);
	ofile << "������ ������:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		ofile << oldarr[i] << " ";
	}
	ofile << endl;
	ofile << "��������������� ������:"<< endl;
	for (int i = 0; i < n; ++ i)
	{
		ofile << newarr[i] << " ";
	}
	ofile << endl;
	ofile << endl;
	ofile.close();
}