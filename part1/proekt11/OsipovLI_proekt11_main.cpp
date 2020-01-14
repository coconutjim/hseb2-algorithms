/*
���: ������ ��� ��������
������: 271(1)��
���� ������: ������ 11. ��������� ������������� ��������
����� ����������: Microsoft Visual Studio 2012 
����: 06.12.2013
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
	cout << "������� 1." << endl;
	cout << "����� ������������: " << count_permutations(N) << endl;
	cout << "����� ����������: " << count_placements(N, M) << endl;
	cout << "����� ���������: " << count_combinations(N, M) << endl;
	cout << endl;
	cout << endl;
	while (flag) {
		cout << "N = " << N << ", M = " << M << endl;
		cout << "��� ���������� ������ ���������� ������ ������������������� ������� 1" << endl;
		cout << "��� ��������� ������������ �� N (��������) ������� 2" << endl;
		cout << "��� ��������� ������������ �� N (��������) ������� 3" << endl;
		cout << "��� ��������� ���������� �� N �� M ������� 4" << endl;
		cout << "��� ��������� ��������� �� N �� M ������� 5" << endl;
		cout << "��� ��������� ������������� �� N � �������������� ������� ������� 6" << endl;
		cout << "��� ����� ����� ������ ������� 7" << endl;
		cout << "��� ������ ������� 8" << endl;
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
			cout << "������� 1." << endl;
			cout << "����� ������������: " << count_permutations(N) << endl;
			cout << "����� ����������: " << count_placements(N, M) << endl;
			cout << "����� ���������: " << count_combinations(N, M) << endl;
			cout << endl;
			cout << endl;
			break;
				}
		case 2: {
			cout << "������� 2 (�). ������������ ����������" << endl;
			cout << endl;
			cout << endl;
			permutations_iterations(N);
			cout << endl;
			cout << endl;
			break;
				}
		case 3: {
			cout << "������� 2 (�). ������������ ����������" << endl;
			cout << endl;
			cout << endl;
			permutations_recursive(N);
			cout << endl;
			cout << endl;
			break;
				}
		case 4: {

			cout << "������� 3. ����������" << endl;
			cout << endl;
			cout << endl;
			placements(N, M);
			cout << endl;
			cout << endl;
			break;
				}
		case 5: {
			cout << "������� 4. ���������" << endl;
			cout << endl;
			cout << endl;
			combinations(N, M);
			cout << endl;
			cout << endl;
			break;
				}
		case 6: {
			cout << "������� 5. ������������� � �������������� �������" << endl;
			cout << endl;
			cout << endl;
			representations(N);
			cout << endl;
			cout << endl;
			break;
				}
		case 7: {
			input(N, M);
			cout << "������� 1." << endl;
			cout << "����� ������������: " << count_permutations(N) << endl;
			cout << "����� ����������: " << count_placements(N, M) << endl;
			cout << "����� ���������: " << count_combinations(N, M) << endl;
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
	cout << "������ ������� ������!" << endl;
	cout << endl;
}

void input (int &n, int &m)
{
	while (true)
	{
		cout << "������� N (������������� ������������� ��������" << endl;
		cout <<	"�� ����� 20 �� ��������� ������������): ";
		cin >> n;
		if (cin.fail() || n < 1 || n > 20)
		{
			input_fail();
			continue;
		}
		cout << "������� M (������������� ������������� �������� ������ N): ";
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