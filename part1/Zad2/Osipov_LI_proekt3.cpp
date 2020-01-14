/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 3. ���������� ��������� ���������� �� ����� �++
����� ����������: Microsoft Visual Studio 2012 
����: 03.10.2013
*/

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void insertion_sort(int*, int); 
void binary_insertion_sort(int*, int); 
void counting_sort(int*, int*, int, int); 
void radix_sort_10(int*, int);
void radix_sort_256(int*, int);
void generate(int*, int, int, int);
void input_fail();
void input (int&, int&, int&, int&);
void copy(int*, int*, int);
bool check_array(int*, int);
int find_max(int*, int);
void output(int*, int*, int);
void output_file(int*, int*, int);

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
					insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ���������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ���������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//��������_�������
					binary_insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ��������� ���������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ��������� ���������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�������
					counting_sort(newarray, oldarray, N, max);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ���������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ���������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					//��������10
					radix_sort_10(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: �������� ���������� �� ��������� 10" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: �������� ���������� �� ��������� 10" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//��������256
					radix_sort_256(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: �������� ���������� �� ��������� 256" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: �������� ���������� �� ��������� 256" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
				}
				break;
			}
		case 2: 
			{
				insideflag = true;
				ifile.open("input_proekt3.txt", ios :: in);
				if (!ifile)
				{
					ifile.clear();
					ifile.close();
					cout << "������ � ������������ ��� ����� �����!" << endl;
					cout << "��������� ��� �����: input_proekt3.txt" << endl;
					cout << endl;
					continue;
				}
				ifile >> NT;
				if (!ifile || ifile.eof() || NT < 1)
				{
					ifile.clear();
					ifile.close();
					cout << "������ � ������ ������ �����!" << endl;
					cout << "��� ������ ������ ���� �������������� ������ �������." << endl;
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
						cout << "��� ������ ������ ���� �������������� ������ �������." << endl;
						cout << endl;
						break;
					}
					oldarray = new int[N];
					newarray = new int[N];
					for (int j = 0; j < N; ++ j)
					{
						ifile >> newarray[j];
						if (!ifile || newarray[j] < 1)
						{
							ifile.clear();
							ifile.close();
							cout << "������ � ������ ������ �����!" << endl;
							cout << "��� ������ ������ ���� �������������� ������ �������." << endl;
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
					max = find_max(newarray, N);
					copy(newarray, oldarray, N);
					//�������
					insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ���������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ���������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//��������_�������
					binary_insertion_sort(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ��������� ���������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ��������� ���������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//�������
					counting_sort(newarray, oldarray, N, max);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: ���������� ���������" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: ���������� ���������" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					//��������10
					radix_sort_10(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: �������� ���������� �� ��������� 10" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: �������� ���������� �� ��������� 10" << endl;
					ofile.close();
					output_file(oldarray, newarray, N);
					copy(oldarray, newarray, N);
					//��������256
					radix_sort_256(newarray, N);
					if (! check_array(newarray, N))
					{
						cout << "������ � ����������! ���������� ��� ���." << endl;
						break;
					}
					cout << "����� �����: " << i + 1 << endl;
					cout << "��� ����������: �������� ���������� �� ��������� 256" << endl;
					output(oldarray, newarray, N);
					ofile.open("output_proekt3.txt", ios :: app);
					ofile << "����� �����: " << i + 1 << endl;
					ofile << "��� ����������: �������� ���������� �� ��������� 256" << endl;
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

void insertion_sort(int *arr, int n)
{
	int temp, j;
	for (int i = 1; i < n; ++ i)
	{
		temp = arr[i];
		for (j = i - 1; temp < arr[j] && j >= 0; -- j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void binary_insertion_sort(int *arr, int n)
{
	int min, mid, max, temp;
	for (int i = 1; i < n; ++ i)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			min = 0;
			max = i - 1;
			do
			{
				mid = (min + max) / 2;
				if (arr[mid] < temp)
				{
					min = mid + 1;
				}
				else
				{
					max = mid - 1;
				}
			} while (min <= max);
			for (int j = i - 1; j >= min; -- j)
			{
				arr[j + 1] = arr[j];
			}
			arr[min] = temp;
		}
	}
}

void counting_sort(int *arr, int *oldarr, int n, int k)
{
	int *helparr = new int[k + 1];
	for (int i = 0; i <= k; ++ i)
	{
		helparr[i] = 0;
	}
	for (int i = 0; i < n; ++ i)
	{
		++ helparr[oldarr[i]];
	}
	for (int i = 1; i <= k; ++ i)
	{
		helparr[i] += helparr[i - 1];
	}
	for (int i = n - 1; i >= 0; -- i)
	{
		arr[helparr[oldarr[i]] - 1] = oldarr[i];
		-- helparr[oldarr[i]];
	}
	delete [] helparr;
}

void radix_sort_10(int *arr, int n)
{
	int *helparr = new int[n];
	int max = find_max(arr, n);
	int length = 0;
	while (max != 0)
	{
		max /= 10;
		++ length;
	}
	for (int i = 0; i < length; ++ i)
	{
		int temp[10] = {0};
		for (int j = 0; j < n; ++ j)
		{
			++ temp[arr[j] / (int)pow(10, i) % 10];
		}
		for (int j = 1; j < 10; ++ j)
		{
			temp[j] += temp[j - 1];
		}
		for (int j = n - 1; j >= 0; -- j)
		{
			helparr[-- temp[arr[j] / (int)pow(10, i) % 10]] = arr[j];
		}
		for (int j = 0; j < n; ++j)
		{
			arr[j] = helparr[j];
		}
	}
	delete [] helparr;
}

void radix_sort_256(int *arr, int n)
{
	int *helparr = new int[n];
	int length = sizeof(int);
	for (int i = 0; i < length; ++ i)
	{
		int temp[256] = {0};
		for (int j = 0; j < n; ++ j)
		{
			++ temp[arr[j] >> (8 * i) & 255];
		}
		for (int j = 1; j < 256; ++ j)
		{
			temp[j] += temp[j - 1];
		}
		for (int j = n - 1; j >= 0; -- j)
		{
			helparr[-- temp[arr[j] >> (8 * i) & 255]] = arr[j];
		}
		for (int j = 0; j < n; ++j)
		{
			arr[j] = helparr[j];
		}
	}
	delete [] helparr;
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
		cout << "������� ������ ������� �������� (������������� ������������� ��������): ";
		cin >> min;
		if (cin.fail() || min < 1)
		{
			input_fail();
			continue;
		}
		cout << "������� �������� ������� �������� (������������� ������������� ��������): ";
		cin >> max;
		if (cin.fail() || max < 1 || max < min)
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

int find_max(int* arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; ++ i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
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
	ofile.open("output_proekt3.txt", ios :: app);
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
