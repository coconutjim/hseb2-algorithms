#include <iostream>
#include <string>
#include <windows.h>
// ��� ������ ����� #include "filename.XXX"

using namespace std;

int main (int argc, char* ragv[]) {
	//Set code page

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Output code page
	cout << "Code Page		" << GetConsoleCP() << "/" << GetConsoleOutputCP() << endl;
	cout << "������� ��������		" << GetConsoleCP() << "/" << GetConsoleOutputCP() << endl;
	// ����� ��������� ����� �������� �� ������ (SetConsoleCP() ������ �� ������ �������)

	for (unsigned char c = 128; c; ++ c) {
		if (c % 16 == 0) cout << endl;
		cout << c;
	}

	cout << "\n\n";
	cout << "Hello world!" << endl;
	cout << "������ ���!" << endl;
	string s;

	// getline() ��������� ������ ������, � cin - ����� �� ����������� (�������)

	cout << "\n ���������� ������� ���� ���\n";
	getline(cin, s); 

	cout << "������������ " << s << '!' << endl;
	cout << "\n ���������� ������� ���� ���\n";
	
	cin >> s;
	cout << "������������ " << s << '!' << endl;

	/* indicate normal termination */
	system("pause"); // ��� ���� ����� ���� �� ��������� ����� ���������

	return EXIT_SUCCESS;
}