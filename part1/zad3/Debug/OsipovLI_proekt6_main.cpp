/*
* ���: �������� ������
* ������: 271��
* ����: 18/10/2013
* ������: 6-7
* ��������: ����������� ����������
* ����� ����������������: Visual Studio 2012
*/

#include "OsipovLI_proekt6_main.h"
#include "OsipovLI_proekt6_sort.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 10; //���������� ��������� (�� ��������� 10)
	int NT = 1; //���������� ������ (�� ��������� 1)
	int count, key; //����� ������ ����
	int low_bound = 1, high_bound = 10; //������ ������� (�� �����. 1), ������� ������� (�� �����. 10)
	int a[100][100] = {0}; //������ ��� �������� �������� �� �����
	int arr[100] = {0}; //������ ��� �������� ������� ������� ������� � �����

	do 
	{
		count = 1;

		ofstream fout("output_proekt6.txt", ios::ate);

		if (!fout)
		{
			cout << "���������� ������� ����";
			fout.close();
		}
		fout.close();

		int *p = new int[N];
		int *p_temp = new int[N];

		key = 0;

		//���� ������� ����
		do
		{
			do
			{
				cout << "�������� ��������: \n";
				cout << "1. ������������ � ���������\n";
				cout << "2. ������� �� �����\n";
				cin >> key;

				if (cin.fail())
				{
					cin.clear();
					_flushall();
					cout << "�������" << endl;
				}

				if (key == 1 || key == 2)
				{
					break;
				}
			}while (true);

			ifstream fin;
			fin.open("input_proekt6.txt", ios::in);
			
			if (! fin) 
			{ 
				cerr << "\n������! �� ������� ����� ����!\n"; 
				system("PAUSE"); 
				exit(1); 
			} 

			switch (key)
			{
			case 1:
				enter_data(N, NT, low_bound, high_bound);

				p = new int[N];
				p_temp = new int[N];

				break;
			case 2:
				if (fin.is_open() && !fin.eof())
				{
					readFile(a, arr, NT);
				}
				else
				{
					cerr << "���������� ������� �� �����\n";
					return;
					key = 0;
				}
				break;
			default:
				break;
			}
			fin.close();
		} while(key < 1 && key > 2);

	srand(time(NULL));	
	if (key != 0)
	{
	for (int i = 0; i < NT; i++) //������ ������
	{
		
		if (key == 1) //�������� �� ���������� ������
		{
			cout << "��������� �� ���������";
			generate_arr(p, p_temp, low_bound, high_bound, N);
		}
		else
		{
			cout << "���������� �� �����";
			N = arr[i];
			for (int k = 0; k < N; k++)
			{
				p[k] = p_temp[k] = a[i][k];
			}
		}
		
			for (int j = 1; j < 6; j++) //������ ������
			{
			switch (j)
			{
			case 1:
				heapSort(p_temp, N);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "�������� �� ���������������: ";
				if (isSorted(p_temp, N))
					cout << "������������" << endl;
				else
					cout << "�� ������������" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 2:
				MergeSort(p_temp, 0, N-1);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "�������� �� ���������������: ";
				if (isSorted(p_temp, N))
					cout << "������������" << endl;
				else
					cout << "�� ������������" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 3:
				HoarSort_Middle(p_temp, 0, N-1);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "�������� �� ���������������: ";
				if (isSorted(p_temp, N))
					cout << "������������" << endl;
				else
					cout << "�� ������������" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 4:
				HoarSort_SecondLeft(p_temp, 0, N-1);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "�������� �� ���������������: ";
				if (isSorted(p_temp, N))
					cout << "������������" << endl;
				else
					cout << "�� ������������" << endl;

				reEnter_data(p, p_temp, N);

				break;
			case 5:
				HoarSort_Rand(p_temp, N);

				writeToFile(p, p_temp, N, i+1, j);

				cout << endl << "�������� �� ���������������: ";
				if (isSorted(p_temp, N))
					cout << "������������" << endl;
				else
					cout << "�� ������������" << endl;

				reEnter_data(p, p_temp, N);

				break;
			default:
				break;
			}
		} 

	}
	}
		delete [] p;
		delete [] p_temp;

		high_bound = 10;
		low_bound = 1;
		N = 10;
		NT = 1;

		cout << "�������� ��������: \n";
		cout << "1. ����������\n";
		cout << "����� �������, ����� �����\n";
		cin >> count;
		
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "�����" << endl;
			system("Pause");
			return;
		}

		switch (count) //����� �� ���������
		{
		case 1:
			break;
		default:
			system("Pause");
			return;
		}

	} while (count == 1);
}

//������ ������
void enter_data(int &N, int &NT, int &low_bound, int &high_bound)
{
	do
	{
		cout << "NT = ";
		cin >> NT;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "NT ����� �� ������ �������� (����� �������������� �������� �� ��������� ������ 1)" << endl;
		}
		cout << "N = ";
		cin >> N;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "N ����� �� ������ �������� (����� �������������� �������� �� ��������� ������ 10)" << endl;
		}
		cout << "Low bound = ";
		cin >> low_bound;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "������ ������� ����� �� ������ �������� (����� �������������� �������� �� ��������� ������ 1)" << endl;
		}
		cout << "High bound = ";
		cin >> high_bound;
		if (cin.fail())
		{
			cin.clear();
			_flushall();
			cout << "������� ������� ����� �� ������ �������� (����� �������������� �������� �� ��������� ������ 10)" << endl;
		}
	} while (low_bound > high_bound || N <= 0 || NT <= 0 || low_bound <= 0 || high_bound <= 0);
}

//�������� �� ��������� ������
void reEnter_data(int *p, int *p_temp, int N)
{
	for (int i = 0; i < N; i++)
	{
		p_temp[i] = p[i];
	}
}

//������������� ������
void generate_arr(int *p, int *p_temp, int low_bound, int high_bound, int N)
{
	cout << endl << "New array:" << endl;
	for (int i = 0; i < N; i++)
	{
		p[i] = low_bound + rand() % (high_bound - low_bound + 1);
		p_temp[i] = p[i];
		cout << p_temp[i] << " ";
	}
	cout << endl;
}

//���������� ������
void print_arr(int *p, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

//�������� �� ������������ ����������
bool isSorted(int *p_temp, int N)
{
	for (int i = 0; i < N-1; i++)
	{
		if (p_temp[i] > p_temp[i+1])
			return false;
	}
	return true;
}

//�������� � ����
void writeToFile(int *p, int *p_temp, int N, int NT, int i)
{
	ofstream fout("output_proekt6.txt", ios::app);

	if (!fout)
	{
		cout << "���������� ������� ����";
		fout.close();
		return;
	}
	fout << " ���� ����� " << NT << "\n";

	switch (i)
	{
	case 1:
		fout << "������������� ����������\n";
		break;
	case 2:
		fout << "���������� ��������\n";
		break;
	case 3:
		fout << "���������� ����� � ������������ �� �������� �������\n";
		break;
	case 4:
		fout << "���������� ����� �� ������ ����������� ���������\n";
		break;
	case 5:
		fout << "���������� ����� �� ��������� ����������� ���������\n";
		break;
	default:
		break;
	}

	fout << "�� ����������\n";
	for (int i = 0; i < N; i++)
	{
		fout << p[i] << " ";
	}

	fout << "\n����� ����������\n";
	for (int i = 0; i < N; i++)
	{
		fout << p_temp[i] << " ";
	}
	fout << "\n--------------------------\n";
	fout.close(); 
}

//������� �� �����
void readFile(int a[100][100], int arr[100], int &NT)
{
	ifstream fin;
	fin.open("input_proekt6.txt", ios::in);
	if (! fin)
	{ 
		cerr << "\n������! �� ������� ����� ����!\n";
		system("PAUSE");
		exit(1);
	}
	fin >> NT;
	cout << "������� ���������� ������ " << NT << "\n";
	for (int j = 0; j < NT; j++)
	{
		fin >> arr[j];
		for (int i = 0; i < arr[j]; i++) {
			fin >> a[j][i];	
		}
	}
		
	fin.close();
	cout << "������� ��������";
}